#include "SMMIterator.h"
#include "SortedMultiMap.h"
#include <stdexcept>
using namespace std;

SMMIterator::SMMIterator(const SortedMultiMap& d) : map(d)
{
	this->first();
}

void SMMIterator::first()
{
	this->currentPosition = map.head;
}

void SMMIterator::next()
{
	if (!valid())
		throw std::runtime_error("Iterator is not valid");

	this->currentPosition = map.next[this->currentPosition];

}

bool SMMIterator::valid() const
{
	return this->currentPosition != -1;
}

TElem SMMIterator::getCurrent() const
{
	if (!valid())
		throw std::runtime_error("Iterator is not valid");

	return map.elems[this->currentPosition];
}

void SMMIterator::jumpForward(int k)
{
	if (!valid())
		throw std::runtime_error("Iterator is invalid for jumpForward()");

	if (k <= 0)
		throw std::runtime_error("Parameter k must be positive for jumpForward()");

	for (int i = 0; i < k; i++)
	{
		this->currentPosition = map.next[this->currentPosition];
		if (this->currentPosition == -1)
			break;
	}
}
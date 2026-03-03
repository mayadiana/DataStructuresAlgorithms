#include "Map.h"
#include "MapIterator.h"
#include <exception>
using namespace std;

// BC = WC = TC Theta(1)
MapIterator::MapIterator(const Map& d) : map(d)
{
	this->currentNode = map.head;
}

// BC = WC = TC Theta(1)
void MapIterator::first() {
	this->currentNode = map.head;
}

// BC = WC = TC Theta(1)
void MapIterator::next() {
	if (!valid())
		throw exception();
	this->currentNode = this->currentNode->next;
}

// BC = WC = TC Theta(1)
TElem MapIterator::getCurrent() {
	if (!valid())
		throw exception();
	return this->currentNode->info;
}

// BC = WC = TC Theta(1)
bool MapIterator::valid() const {
	return this->currentNode != nullptr;
}




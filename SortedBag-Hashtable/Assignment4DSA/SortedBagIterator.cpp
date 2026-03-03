#include "SortedBagIterator.h"
#include "SortedBag.h"
#include <stdexcept>
#include <exception>
#include <algorithm>

using namespace std;

void BubbleSort(TElem arr[], int n, Relation rel)
{
	bool swapped;
	for (int i = 0; i < n - 1; i++)
	{
		swapped = false;
		for (int j = 0; j < n - i - 1; j++) 
		{
			
			if (!rel(arr[j], arr[j + 1])) 
			{
				TElem temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
				swapped = true;
			}
		}
		if (!swapped)
			break;
	}
}

void SortedBagIterator::sortElements()
{
	this->currentSize = bag.totalElements;
	if (this->currentSize == 0)
	{
		this->sortedElements = nullptr;
		return;
	}
	this->sortedElements = new TElem[this->currentSize];

	int index = 0;
	for (int i = 0; i < bag.capacity; i++) 
	{
		if (bag.table[i].info != EMPTY_TCOMP && bag.table[i].info != DELETED_TCOMP) 
		{			
			for (int f = 0; f < bag.table[i].frequency; f++) 
			{
				if (index < this->currentSize) 
					this->sortedElements[index++] = bag.table[i].info;
			}
		}
	}
	
	this->currentSize = index;
	BubbleSort(this->sortedElements, this->currentSize, bag.relation);
}

SortedBagIterator::SortedBagIterator(const SortedBag& b) : bag(b) 
{	
	this->sortedElements = nullptr;
	this->currentSize = 0;
	sortElements();
	this->currentIndex = 0;
}

SortedBagIterator::~SortedBagIterator() 
{
	delete[] this->sortedElements;
}

TComp SortedBagIterator::getCurrent() 
{
	if (!valid()) 
		throw std::runtime_error("Iterator not valid");

	return this->sortedElements[this->currentIndex];
}

bool SortedBagIterator::valid()
{
	return this->sortedElements != nullptr && this->currentIndex < this->currentSize;
}

void SortedBagIterator::next() 
{
	if (!valid()) 
		throw std::runtime_error("Iterator not valid");
	this->currentIndex++;
}

void SortedBagIterator::first() 
{
	this->currentIndex = 0;
}


#include "SortedBag.h"
#include "SortedBagIterator.h"
#include <exception>
#include <stdexcept>
#include <cmath>
using namespace std;

const double SortedBag::MAX_LOAD_FACTOR = 0.75;

int SortedBag::hashFunction(TComp e) const 
{
	if (this->m == 0) 
		return 0;
	return abs(e) % this->m;
}

void SortedBag::resizeAndRehash()
{
	HashNode* oldTableData = this->table;
	int oldCapacity = this->capacity;

	int currentTotalElements = this->totalElements;
	TElem* elementsToRehash = new TElem[currentTotalElements];
	int elementsIdx = 0;

	for (int i = 0; i < oldCapacity; i++) 
	{
		if (oldTableData[i].info != EMPTY_TCOMP && oldTableData[i].info != DELETED_TCOMP)
		{
			for (int j = 0; j < oldTableData[i].frequency; j++) 
			{
				if (elementsIdx < currentTotalElements) 
					elementsToRehash[elementsIdx++] = oldTableData[i].info;
			}
		}
	}

	this->capacity = (this->capacity == 0) ? 11 : this->capacity * 2;
	this->m = static_cast<int>(this->capacity * 0.8);
	if (this->m == 0) this->m = 1;
	if (this->m > this->capacity) this->m = this->capacity;


	delete[] this->table;
	this->table = new HashNode[this->capacity];
	this->cellarIndex = this->capacity - 1;
	this->count = 0;
	this->totalElements = 0;


	for (int i = 0; i < elementsIdx; i++)
		this->add(elementsToRehash[i]);

	delete[] elementsToRehash;
}

SortedBag::SortedBag(Relation r) 
{
	this->relation = r;
	this->capacity = 11;
	this->m = 7;
	if (this->m > this->capacity) 
		this->m = this->capacity;
	this->table = new HashNode[this->capacity];
	this->cellarIndex = this->capacity - 1;
	this->count = 0;
	this->totalElements = 0;
}

void SortedBag::add(TComp e) 
{
	if (this->m > 0 && (double)(this->count + 1) / this->m > MAX_LOAD_FACTOR) 
		resizeAndRehash();

	int pos = hashFunction(e);
	int originalPos = pos;

	if (this->table[pos].info == EMPTY_TCOMP || this->table[pos].info == DELETED_TCOMP)
	{
		this->table[pos].info = e;
		this->table[pos].frequency = 1;
		this->table[pos].next = -1;
		this->count++;
		this->totalElements++;
		return;
	}
	else if (this->table[pos].info == e)
	{
		this->table[pos].frequency++;
		this->totalElements++;
		return;
	}

	int current = originalPos;
	while (this->table[current].next != -1) 
	{
		if (this->table[current].info == e) 
		{
			this->table[current].frequency++;
			this->totalElements++;
			return;
		}
		current = this->table[current].next;
	}
	if (this->table[current].info == e) 
	{
		this->table[current].frequency++;
		this->totalElements++;
		return;
	}

	int newSlot = this->cellarIndex;
	while (newSlot >= this->m && this->table[newSlot].info != EMPTY_TCOMP && this->table[newSlot].info != DELETED_TCOMP) 
		newSlot--;

	if (newSlot < this->m)
	{
		resizeAndRehash();
		add(e);
		return;
	}

	this->cellarIndex = newSlot - 1;
	this->table[newSlot].info = e;
	this->table[newSlot].frequency = 1;
	this->table[newSlot].next = -1;

	this->table[current].next = newSlot;

	this->count++;
	this->totalElements++;
}


bool SortedBag::remove(TComp e) 
{
	if (this->m == 0) return false;
	int pos = hashFunction(e);
	int current = pos;
	int prev = -1;

	while (current != -1)
	{
		if (this->table[current].info == e)
		{
			if (this->table[current].frequency > 0) {
				this->table[current].frequency--;
				this->totalElements--;
				if (this->table[current].frequency == 0)
				{
					this->table[current].info = DELETED_TCOMP;
					this->count--;
				}
				return true;
			}
			return false; 
		}

		if (this->table[pos].info != e && hashFunction(this->table[current].info) != pos && current != pos) 
			break;

		prev = current;
		current = this->table[current].next;
	}
	return false;
}

int SortedBag::originalHash(TComp e) const 
{ 
	if (this->m == 0) 
		return 0;
	return abs(e) % this->m;
}

bool SortedBag::search(TComp elem) const 
{
	return nrOccurrences(elem) > 0;
}

int SortedBag::nrOccurrences(TComp elem) const 
{
	if (this->m == 0) return 0;
	int pos = hashFunction(elem);
	int current = pos;

	while (current != -1)
	{
		if (this->table[current].info == elem) 
			return this->table[current].frequency;
		if (this->table[pos].info != elem && hashFunction(this->table[current].info) != pos && current != pos) 
			break;
		current = this->table[current].next;
	}
	return 0;
}

int SortedBag::size() const 
{
	return this->totalElements;
}

bool SortedBag::isEmpty() const 
{
	return this->totalElements == 0;
}

SortedBag::~SortedBag()
{
	delete[] this->table;
}

SortedBagIterator SortedBag::iterator() const 
{
	return SortedBagIterator(*this);
}

int SortedBag::removeAllOccurrences(TComp elem)
{
	if (this->m == 0) 
		return 0;

	int pos = hashFunction(elem);
	int current = pos;
	int prev = -1;
	int removedCount = 0;

	while (current != -1) 
	{
		if (this->table[current].info == elem)
		{			
			removedCount = this->table[current].frequency;
			this->totalElements -= removedCount;
			this->table[current].frequency = 0;   

			this->table[current].info = DELETED_TCOMP;
			this->count--; 
			return removedCount;
		}

		
		if (this->table[pos].info != elem && hashFunction(this->table[current].info) != pos && current != pos) 
			break;

		prev = current;
		current = this->table[current].next;
	}

	return 0; 
}


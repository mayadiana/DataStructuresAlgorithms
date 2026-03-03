#include "FixedCapBiMap.h"
#include "FixedCapBiMapIterator.h"
#include <iostream>

FixedCapBiMap::FixedCapBiMap(int capacity) {
	if(capacity <= 0)
	{
		throw exception();
	}
	this->capacity = capacity;
	this->mapSize = 0;
	this->elements = new TElem[capacity];
}
//BC: Theta(1), WC: Theta(1), TC: Theta(1)

FixedCapBiMap::~FixedCapBiMap() {
	delete[] this->elements;
}
//BC = WC = TC: Theta(1)

bool FixedCapBiMap::add(TKey c, TValue v){
	//if(c == -200)
	//{
	//	cout << "Key - 200" << endl;
	//}

	if(this->mapSize == this->capacity)
		throw exception();
	int count = 0;
	int index = 0;
	while(count < 2 && index < this->mapSize)
	{
		if(this->elements[index].first == c)
			count++;
		index++;
	}
	if(count == 2)
		return false;
	this->elements[this->mapSize].first = c;
	this->elements[this->mapSize].second = v;
	this->mapSize++;
	return true;
}
//BC: Theta(1) - when the first 2 keys from the map are equal to c
//WC: Theta(mapSize) - when the key c appears only once or zero times in the map 
//TC: O(mapSize)

ValuePair FixedCapBiMap::search(TKey c) const{
	ValuePair result;
	result.first = NULL_TVALUE;
	result.second = NULL_TVALUE;
	int nrFound = 0;
	int index = 0;
	while(nrFound < 2 && index < this->mapSize)
	{
		if(this->elements[index].first == c)
		{
			if(nrFound == 0)
			{
				result.first = this->elements[index].second;
				nrFound++;
			}
			else
			{
				result.second = this->elements[index].second;
				nrFound++;
			}
		}
		index++;
	}
	return result;
	//return std::pair<TValue, TValue>(NULL_TVALUE, NULL_TVALUE);
}
//BC: Theta(1) - when the first 2 keys from the map are equal to c
//WC: Theta(mapSize) - when the key c appears only once or zero times in the map 
//TC: O(mapSize)

bool FixedCapBiMap::remove(TKey c, TValue v){
	int index = 0;
	while(index < this->mapSize)
	{
		if(this->elements[index].first == c && this->elements[index].second == v)
		{
			this->elements[index] = this->elements[this->mapSize - 1];
			this->mapSize--;
			return true;
		}
		index++;
	}
	
	return false;
}
//BC: Theta(1) - when the pair we want to remove is on the first position
//WC: Theta(mapSize) - when the pair is not in the array or it is on the last position
//TC: O(mapSize)

ValuePair FixedCapBiMap::removeKey(TKey k) {
	ValuePair result;
	result = search(k);
	if (result.first != NULL_TVALUE)
		remove(k, result.first);
	if (result.second != NULL_TVALUE)
		remove(k, result.second);
	return result;
}
//BC = WC = TC = Theta(1)

int FixedCapBiMap::size() const {
	return this->mapSize;
}
//BC = WC = TC: Theta(1)

bool FixedCapBiMap::isEmpty() const{
	return this->mapSize == 0;
}
//BC = WC = TC: Theta(1)

bool FixedCapBiMap::isFull() const {
	return this->mapSize == this->capacity;
}
//BC = WC = TC: Theta(1)

FixedCapBiMapIterator FixedCapBiMap::iterator() const {
	return FixedCapBiMapIterator(*this);
}
//BC = WC = TC: Theta(1)
#pragma once
#include "SortedSet.h"

//DO NOT CHANGE THIS PART
class SortedSetIterator
{
	friend class SortedSet;
private:
	const SortedSet& multime;
	SortedSetIterator(const SortedSet& m);

	TElem* elements;
	int capacity;
	int currentSize;
	int currentPos;

	void inOrderTraversalRecursive(SortedSet::Node* node, int& indexInArray);

public:
	SortedSetIterator(const SortedSetIterator& other);
	SortedSetIterator& operator=(const SortedSetIterator& other);
	void first();
	void next();
	TElem getCurrent();
	bool valid() const;
	~SortedSetIterator();
};


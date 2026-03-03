#pragma once
#include "SortedBag.h"

class SortedBag;

class SortedBagIterator
{
	friend class SortedBag;

private:
	const SortedBag& bag;
	SortedBagIterator(const SortedBag& b);

	TElem* sortedElements;
	int currentSize;
	int currentIndex;

	void sortElements();

public:
	TComp getCurrent();
	bool valid();
	void next();
	void first();
	~SortedBagIterator();
};


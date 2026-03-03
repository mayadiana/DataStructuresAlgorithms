#include "SMMIterator.h"
#include "SortedMultiMap.h"
#include <iostream>
#include <vector>
#include <exception>
using namespace std;

void SortedMultiMap::resize()
{
    int newCap = (this->cap == 0) ? 1 : this->cap * 2;

    TElem* newElems = new TElem[newCap];
    int* newNext = new int[newCap];

    for (int i = 0; i < this->cap; i++)
    {
        newElems[i] = this->elems[i];
        newNext[i] = this->next[i];
    }

    for (int i = this->cap; i < newCap - 1; i++)
        newNext[i] = i + 1;
    newNext[newCap - 1] = -1;

    this->firstEmpty = this->cap;

    delete[] this->elems;
    delete[] this->next;

    this->elems = newElems;
    this->next = newNext;
    this->cap = newCap;
}


int SortedMultiMap::allocate()
{
    if (this->firstEmpty == -1)
        resize();

    int newPos = this->firstEmpty;
    this->firstEmpty = this->next[this->firstEmpty];
    return newPos;
}

void SortedMultiMap::free(int pos)
{
    this->next[pos] = this->firstEmpty;
    this->firstEmpty = pos;
}


SortedMultiMap::SortedMultiMap(Relation r)
{
    this->relation = r;
    this->cap = 10;
    this->elems = new TElem[this->cap];
    this->next = new int[this->cap];
    this->head = -1;
    this->listSize = 0;

    for (int i = 0; i < this->cap - 1; i++)
        this->next[i] = i + 1;

    this->next[this->cap - 1] = -1;
    this->firstEmpty = 0;
}

void SortedMultiMap::add(TKey c, TValue v)
{
    int newPos = allocate();
    this->elems[newPos] = make_pair(c, v);

    int current = this->head;
    int previous = -1;

    while (current != -1 && this->relation(this->elems[current].first, c))
    {
        previous = current;
        current = this->next[current];
    }

    if (previous == -1)
    {
        this->next[newPos] = this->head;
        this->head = newPos;
    }
    else
    {
        this->next[newPos] = this->next[previous];
        this->next[previous] = newPos;
    }

    this->listSize++;
}

vector<TValue> SortedMultiMap::search(TKey c) const
{
    vector<TValue> values;
    int current = this->head;

    while (current != -1)
    {
        TKey currentKey = this->elems[current].first;

        if (currentKey == c)
            values.push_back(this->elems[current].second);

        else if (this->relation(c, currentKey))
        {
            if (!this->relation(currentKey, c))
                break;
        }
        current = this->next[current];
    }

    return values;
}

bool SortedMultiMap::remove(TKey c, TValue v)
{
    int current = this->head;
    int previous = -1;

    while (current != -1)
    {
        TKey currentKey = this->elems[current].first;
        TValue currentValue = this->elems[current].second;

        if (currentKey == c && currentValue == v)
        {
            if (previous == -1)
                this->head = this->next[current];
            else
                this->next[previous] = this->next[current];

            free(current);
            this->listSize--;
            return true;
        }
        else if (this->relation(c, currentKey) && currentKey != c)
        {
            if (!this->relation(currentKey, c))
                break;
        }

        previous = current;
        current = this->next[current];
    }

    return false;
}


int SortedMultiMap::size() const
{
    return this->listSize;
}

bool SortedMultiMap::isEmpty() const
{
    return this->listSize == 0;
}

SMMIterator SortedMultiMap::iterator() const
{
    return SMMIterator(*this);
}

SortedMultiMap::~SortedMultiMap()
{
    delete[] this->elems;
    delete[] this->next;
}

/*

*/
#include "SortedSetIterator.h"
#include <exception>

using namespace std;

SortedSetIterator::SortedSetIterator(const SortedSet& m) : multime(m)
{
    this->capacity = this->multime.size();
    this->currentPos = 0;
    this->currentSize = 0;

    if (this->capacity == 0)
        this->elements = nullptr;
    else
    {
        this->elements = new TElem[this->capacity];
        int indexInArray = 0;
        inOrderTraversalRecursive(this->multime.root, indexInArray);
        this->currentSize = indexInArray;
    }
}

SortedSetIterator::SortedSetIterator(const SortedSetIterator& other) : multime(other.multime)
{
    this->capacity = other.capacity;
    this->currentPos = other.currentPos;
    this->currentSize = other.currentSize;
    if (other.elements != nullptr)
    {
        this->elements = new TElem[this->capacity];
        for (int i = 0; i < other.currentSize; i++)
            this->elements[i] = other.elements[i];
    }
    else this->elements = nullptr;
}

SortedSetIterator& SortedSetIterator::operator=(const SortedSetIterator& other) 
{
    if (this != &other) 
    {
        delete[] this->elements;
        this->capacity = other.capacity;
        this->currentPos = other.currentPos;
        this->currentSize = other.currentSize;
        if (other.elements != nullptr) 
        {
            this->elements = new TElem[this->capacity];
            for (int i = 0; i < other.currentSize; i++)
                this->elements[i] = other.elements[i];
        }
        else this->elements = nullptr;
    }
    return *this;
}

void SortedSetIterator::inOrderTraversalRecursive(SortedSet::Node* node, int& indexInArray)
{
    if (node == nullptr || indexInArray >= this->capacity)
        return;

    inOrderTraversalRecursive(node->left, indexInArray);

    if (indexInArray < this->capacity)
        this->elements[indexInArray++] = node->info;

    inOrderTraversalRecursive(node->right, indexInArray);
}

void SortedSetIterator::first()
{
    this->currentPos = 0;
}


void SortedSetIterator::next()
{
    if (!valid())
        throw std::exception();
    this->currentPos++;
}


TElem SortedSetIterator::getCurrent()
{
    if (!valid()) {
        throw std::exception();
    }
    return this->elements[this->currentPos];
}

bool SortedSetIterator::valid() const
{
    return this->elements != nullptr && this->currentPos >= 0 && this->currentPos < this->currentSize;
}

SortedSetIterator::~SortedSetIterator()
{
    delete[] this->elements;
}


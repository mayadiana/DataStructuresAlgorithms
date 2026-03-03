#include "Map.h"
#include "MapIterator.h"

// BC = AC = WC = TC = Theta(1)
Map::Map() {
	this->head = nullptr;
	this->mapSize = 0;
}

// BC = Theta(1)
// AC = Theta(n) 
// WC = Theta(n), where n is the number of elements in the map
// TC = O(n)
Map::~Map() {
	Node* current = this->head;
	while (current != nullptr)
	{
		Node* nextNode = current->next;
		delete current;
		current = nextNode;
	}
}

// BC = Theta(1)
// AC = Theta(n)
// WC = Theta(n)
// TC = O(n)
TValue Map::add(TKey c, TValue v) {
	Node* current = this->head;

	// Searching if key 'c' already exists
	while (current != nullptr)
	{
		if (current->info.first == c)
		{
			TValue oldValue = current->info.second;
			current->info.second = v;
			return oldValue;
		}
		current = current->next;
	}

	// Key 'c' does not exist => adding a new pair, at the beginning of the SLL
	TElem newPair(c, v);
	Node* newNode = new Node(newPair, this->head);
	this->head = newNode;
	this->mapSize++;
	return NULL_TVALUE;
}

// BC = Theta(1)
// AC = Theta(n)
// WC = Theta(n)
// TC = O(n)
TValue Map::search(TKey c) const {
	Node* current = this->head;
	while (current != nullptr)
	{
		if (current->info.first == c)
			// Key found => returning the associated value
			return current->info.second;
		current = current->next;
	}
	// Key not found
	return NULL_TVALUE;
}

// BC = Theta(1)
// AC = Theta(n)
// WC = Theta(n)
// TC = O(n)
TValue Map::remove(TKey c) {
	Node* current = this->head;
	Node* previous = nullptr;

	while (current != nullptr)
	{
		if (current->info.first == c)
		{
			TValue removedValue = current->info.second;

			if (previous == nullptr)
				// Node to remove is the head
				this->head = current->next;
			else
				// Node to remove is not the head
				previous->next = current->next;

			delete current;
			this->mapSize--;
			return removedValue;
		}
		// Key not found => we move on to the next node
		previous = current;
		current = current->next;
	}

	return NULL_TVALUE;
}

// BC = AC = WC = TC = Theta(1)
int Map::size() const {
	return this->mapSize;
}

// BC = AC = WC = TC = Theta(1)
bool Map::isEmpty() const {
	return this->head == nullptr;
}

// BC = AC = WC = TC = Theta(1)
MapIterator Map::iterator() const {
	return MapIterator(*this);
}

// BC = AC = WC = TC = Theta(n^2) 
TValue Map::mostFrequent() const
{
	if (this->head == nullptr)
		return NULL_TVALUE;

	int maxFrequency = 0;

	TValue currentMostFrequent = this->head->info.second;

	Node* current = this->head;

	while (current != nullptr)
	{
		TValue valueToCheck = current->info.second;
		int currentFrequency = 0;

		Node* nextCurrent = this->head;

		while (nextCurrent != nullptr)
		{
			if (nextCurrent->info.second == valueToCheck)
				currentFrequency++;
			nextCurrent = nextCurrent->next;
		}

		if (currentFrequency > maxFrequency)
		{
			maxFrequency = currentFrequency;
			currentMostFrequent = valueToCheck;
		}

		current = current->next;
	}

	return currentMostFrequent;
}




#pragma once
#include "Map.h"
class MapIterator
{
	//DO NOT CHANGE THIS PART
	friend class Map;
private:
	const Map& map;
	Map::Node* currentNode; // Pointer to the current node in the Map's SLL
	MapIterator(const Map& m); // Constructor for the iterator, initializes the current node to the head of the map
public:
	void first();
	void next();
	TElem getCurrent();
	bool valid() const;
};



#pragma once
//DO NOT INCLUDE SORTEDBAGITERATOR

//DO NOT CHANGE THIS PART
typedef int TComp;
typedef TComp TElem;
typedef bool(*Relation)(TComp, TComp);
#define NULL_TCOMP -11111
#define DELETED_TCOMP -22222 // Marker for logically deleted elements for coalesced chaining rehashing
#define EMPTY_TCOMP -33333 // Marker for an empty slot

class SortedBagIterator;

class SortedBag 
{
	friend class SortedBagIterator;

private:
	struct HashNode 
	{
		TComp info; //Actual element
		int frequency;
		int next; //Index for coalesced chaining

		HashNode() : info(EMPTY_TCOMP), frequency(0), next(-1) {}
	};

	HashNode* table; //Dynamic array of hash nodes
	int capacity; //Current capacity of the hash table
	int m; //Size of the primary hash area

	int count; //No of ! elem. in the bag
	int totalElements;
	Relation relation; //Sorting relation

	int cellarIndex; //Next available slot in the cellar area
	static const double MAX_LOAD_FACTOR; //Threshold for resizing
	
	int hashFunction(TComp e) const; //Primary hash function
	void resizeAndRehash();
	int originalHash(TComp e) const;

public:
	//constructor
	SortedBag(Relation r);

	//adds an element to the sorted bag
	void add(TComp e);

	//removes one occurence of an element from a sorted bag
	//returns true if an eleent was removed, false otherwise (if e was not part of the sorted bag)
	bool remove(TComp e);

	//checks if an element appearch is the sorted bag
	bool search(TComp e) const;

	//returns the number of occurrences for an element in the sorted bag
	int nrOccurrences(TComp e) const;

	//returns the number of elements from the sorted bag
	int size() const;

	//returns an iterator for this sorted bag
	SortedBagIterator iterator() const;

	//checks if the sorted bag is empty
	bool isEmpty() const;

	//destructor
	~SortedBag();

	int removeAllOccurrences(TComp e);
};
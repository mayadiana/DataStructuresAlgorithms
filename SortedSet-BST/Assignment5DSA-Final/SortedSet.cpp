#include "SortedSet.h"
#include "SortedSetIterator.h"
#include <stdexcept>

SortedSet::SortedSet(Relation r) : relation(r), root(nullptr), count(0) {}

void SortedSet::destroyRecursive(Node* currentNode)
{
	if (currentNode != nullptr)
	{
		destroyRecursive(currentNode->left);
		destroyRecursive(currentNode->right);
		delete currentNode;
	}
}

SortedSet::~SortedSet()
{
	destroyRecursive(this->root);
}

SortedSet::Node* SortedSet::addRecursive(Node* currentNode, TComp e, bool& added)
{
	if (currentNode == nullptr)
	{
		added = true;
		return new Node(e);
	}

	if (e == currentNode->info)
	{
		added = false;
		return currentNode;
	}

	if (this->relation(e, currentNode->info))
		currentNode->left = addRecursive(currentNode->left, e, added);
	else
		currentNode->right = addRecursive(currentNode->right, e, added);

	return currentNode;
}

bool SortedSet::add(TComp elem)
{
	bool wasAdded = false;
	this->root = addRecursive(this->root, elem, wasAdded);
	if (wasAdded)
		this->count++;
	return wasAdded;
}

SortedSet::Node* SortedSet::findMin(Node* currentNode) const
{
	while (currentNode->left != nullptr)
		currentNode = currentNode->left;
	return currentNode;
}

SortedSet::Node* SortedSet::removeRecursiveHelper(Node* currentNode, TComp e, bool& removedFlag)
{
	if (currentNode == nullptr)
	{
		removedFlag = false;
		return nullptr;
	}

	if (e == currentNode->info)
	{
		removedFlag = true;
		if (currentNode->left == nullptr && currentNode->right == nullptr)
		{
			delete currentNode;
			return nullptr;
		}
		else if (currentNode->left == nullptr)
		{
			Node* temp = currentNode->right;
			delete currentNode;
			return temp;
		}
		else if (currentNode->right == nullptr)
		{
			Node* temp = currentNode->left;
			delete currentNode;
			return temp;
		}
		else
		{
			Node* successor = findMin(currentNode->right);
			currentNode->info = successor->info;
			bool removedFlagForSuccessor = false;
			currentNode->right = removeRecursiveHelper(currentNode->right, successor->info, removedFlagForSuccessor);
			return currentNode;
		}
	}
	else if (this->relation(e, currentNode->info))
		currentNode->left = removeRecursiveHelper(currentNode->left, e, removedFlag);
	else
		currentNode->right = removeRecursiveHelper(currentNode->right, e, removedFlag);
	return currentNode;
}

bool SortedSet::remove(TComp elem)
{
	bool wasRemoved = false;
	this->root = removeRecursiveHelper(this->root, elem, wasRemoved);
	if (wasRemoved)
		this->count--;
	return wasRemoved;
}

bool SortedSet::searchRecursive(Node* currentNode, TComp elem) const
{
	if (currentNode == nullptr)
		return false;
	if (elem == currentNode->info)
		return true;
	if (this->relation(elem, currentNode->info))
		return searchRecursive(currentNode->left, elem);
	else
		return searchRecursive(currentNode->right, elem);
}

bool SortedSet::search(TComp elem) const
{
	return searchRecursive(this->root, elem);
}


int SortedSet::size() const
{
	return this->count;
}

bool SortedSet::isEmpty() const
{
	return this->count == 0;
}

SortedSetIterator SortedSet::iterator() const
{
	return SortedSetIterator(*this);
}

SortedSet::Node* SortedSet::getLeftmostNode(Node* startNode) const
{
	if (startNode == nullptr)
		return nullptr;

	Node* current = startNode;
	while (current->left != nullptr)
		current = current->left;
	return current;
}

SortedSet::Node* SortedSet::getRightmostNode(Node* startNode) const
{
	if (startNode == nullptr)
		return nullptr;

	Node* current = startNode;
	while (current->right != nullptr)
		current = current->right;
	return current;
}

int SortedSet::getRange() const
{
	if (this->isEmpty())
		return -1;

	Node* leftmostNode = getLeftmostNode(this->root);
	Node* rightmostNode = getRightmostNode(this->root);

	TElem valLeftmost = leftmostNode->info;
	TElem valRightmost = rightmostNode->info;

	TElem minVal, maxVal;

	if (valLeftmost < valRightmost)
	{
		minVal = valLeftmost;
		maxVal = valRightmost;
	}
	else
	{
		minVal = valRightmost;
		maxVal = valLeftmost;
	}

	return maxVal - minVal;
}


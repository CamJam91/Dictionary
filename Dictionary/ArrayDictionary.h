#pragma once
#include "DictionaryInterface.h" 
#include "Entry.h" 
#include "NotFoundException.h" 
#include "Search.h"

template < class KeyType, class ItemType>
class ArrayDictionary : public DictionaryInterface<KeyType, ItemType>
{
private:
	static const int DEFAULT_CAPACITY = 21;
	Entry<KeyType, ItemType>* items;  // Array of dictionary entries 
	int itemCount;    		// Current count of dictionary items 
	int maxItems;                   // Maximum capacity of the dictionary 
	void destroyDictionary();
	int findEntryIndex(int firstIndex, int lastIndex, const KeyType& searchKey) const;
public:
		//constructors
	ArrayDictionary();
	ArrayDictionary(int maxItems);
	ArrayDictionary(const ArrayDictionary<KeyType, ItemType>& arrayDictionary);
		//destructors
	virtual ~ArrayDictionary();
		//getters
	bool isEmpty() const;
	int getNumberOfItems() const;
	ItemType getItem(const KeyType& searchKey) const throw (NotFoundException);
	ItemType getItem(const KeyType& searchKey) const throw (NotFoundException);
	bool contains(const KeyType& searchKey) const;
		//setters
	bool add(const KeyType& searchKey, const ItemType& newItem);
	bool remove(const KeyType& searchKey);
	void clear();
		//traverse
	void traverse(void visit(ItemType&)) const;
};

	//constructors
template<class KeyType, class ItemType>
ArrayDictionary<KeyType, ItemType>::ArrayDictionary() {}

template<class KeyType, class ItemType>
ArrayDictionary<KeyType, ItemType>::ArrayDictionary(int maxItems){
	this->maxItems = maxItems;
}
template<class KeyType, class ItemType>
ArrayDictionary<KeyType, ItemType>::ArrayDictionary(const ArrayDictionary<KeyType, ItemType>& arrayDictionary){
	maxItems = arrayDictionary.maxItems;
	itemCount = arrayDictionary.itemCount;

	for (int count = 0; count < arrayDictionary.itemCount; count++) {
		items[count] = arrayDictionary.items[count];
	}
}
	//getters
template<class KeyType, class ItemType>
bool ArrayDictionary<KeyType, ItemType>::isEmpty() const{
	return itemCount == 0;
}
template<class KeyType, class ItemType>
ItemType ArrayDictionary<KeyType, ItemType>::getItem(const KeyType& searchKey) const throw(NotFoundException){
	//Entry<KeyType, ItemType>* entry = binarySearch()
	return items;
}
;

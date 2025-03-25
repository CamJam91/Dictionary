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
	int itemCount = 0;    		// Current count of dictionary items 
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
	bool contains(const KeyType& searchKey) const;
		//setters
	bool add(const KeyType& searchKey, const ItemType& newItem);
	bool remove(const KeyType& searchKey);
	void clear();
		//traverse
	void traverse(void visit(ItemType&)) const;
};

template<class KeyType, class ItemType>
void ArrayDictionary<KeyType, ItemType>::destroyDictionary(){
}

template<class KeyType, class ItemType>
int ArrayDictionary<KeyType, ItemType>::findEntryIndex(int firstIndex, int lastIndex, const KeyType& searchKey) const
{
	if (firstIndex > lastIndex) { return -1; }
	int middle = (firstIndex + lastIndex) / 2;
	if (items[middle].getKey() == searchKey) { return middle; }
	else if (searchKey > items[middle].getKey()) { return findEntryIndex(middle+1, lastIndex, searchKey); }
	else { return findEntryIndex(firstIndex, middle-1, searchKey); }
}

//constructors
template<class KeyType, class ItemType>
ArrayDictionary<KeyType, ItemType>::ArrayDictionary() {
	maxItems = DEFAULT_CAPACITY;
	items = new Entry<KeyType, ItemType>[maxItems];
}

template<class KeyType, class ItemType>
ArrayDictionary<KeyType, ItemType>::ArrayDictionary(int maxItems){
	this->maxItems = maxItems;
	items = new Entry<KeyType, ItemType>[maxItems];
}
template<class KeyType, class ItemType>
ArrayDictionary<KeyType, ItemType>::ArrayDictionary(const ArrayDictionary<KeyType, ItemType>& arrayDictionary){
	maxItems = arrayDictionary.maxItems;
	itemCount = arrayDictionary.itemCount;

	for (int count = 0; count < arrayDictionary.itemCount; count++) {
		items[count] = arrayDictionary.items[count];
	}
}
template<class KeyType, class ItemType>
ArrayDictionary<KeyType, ItemType>::~ArrayDictionary(){
	delete[] items;
}
	//getters
template<class KeyType, class ItemType>
bool ArrayDictionary<KeyType, ItemType>::isEmpty() const{
	return itemCount == 0;
}
template<class KeyType, class ItemType>
int ArrayDictionary<KeyType, ItemType>::getNumberOfItems() const{
	return itemCount;
}
template<class KeyType, class ItemType>
ItemType ArrayDictionary<KeyType, ItemType>::getItem(const KeyType& searchKey) const throw(NotFoundException) {
	int position = findEntryIndex(0, itemCount-1, searchKey);
	if (position < 0) { throw NotFoundException(); }
	return items[position].getItem();
}
template<class KeyType, class ItemType>
bool ArrayDictionary<KeyType, ItemType>::contains(const KeyType& searchKey) const
{
	return findEntryIndex(1, itemCount, searchKey) >= 0;
}

	//setters
template<class KeyType, class ItemType>
bool ArrayDictionary<KeyType, ItemType>::add(const KeyType& searchKey, const ItemType& newItem){
	bool ableToInsert = (itemCount < maxItems);
	if (ableToInsert){
		int index = itemCount;
		// Short-circuit evaluation is important 
		while ((index > 0) && (searchKey < items[index - 1].getKey())){
			items[index] = items[index - 1];
			--index;
		}
		// Insert new entry 
		items[index] = Entry<KeyType, ItemType>(searchKey, newItem);
		itemCount++; // Increase count of entries 
	}
	return ableToInsert;
}
template<class KeyType, class ItemType>
bool ArrayDictionary<KeyType, ItemType>::remove(const KeyType& searchKey)
{
	int position = findEntryIndex(1, itemCount, searchKey);
	if (position > 0) { return false; }
	while (position < itemCount-1) {
		items[position] = items[position + 1];
		itemCount--;
	}
}
template<class KeyType, class ItemType>
void ArrayDictionary<KeyType, ItemType>::clear(){
	itemCount = 0;
}
template<class KeyType, class ItemType>
void ArrayDictionary<KeyType, ItemType>::traverse(void visit(ItemType&)) const{
	for (int count = 0; count < itemCount; count++) {
		ItemType item = items[count].getItem();
		visit(item);
	}
}
;

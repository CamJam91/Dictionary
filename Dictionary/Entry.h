#pragma once
template < class KeyType, class ItemType>
class Entry
{
private:
	ItemType item;
	KeyType searchKey;
protected:
		//setters
	void setKey(const KeyType& searchKey);
public:
		//constructors
	Entry();
	Entry(KeyType searchKey, ItemType item);
		//getters
	ItemType getItem()  const;
	KeyType getKey()  const;
		//setters
	void setItem(const ItemType& item);
		//operators
	bool  operator==(const Entry<KeyType, ItemType>& rightHandEntry)const;
	bool  operator>(const Entry<KeyType, ItemType>& rightHandEntry)const;
};

//constructors
template < class KeyType, class ItemType>
Entry<KeyType, ItemType>::Entry() {}

template<class KeyType, class ItemType>
Entry<KeyType, ItemType>::Entry(KeyType searchKey, ItemType item) {
	this->item = item;
	this->searchKey = searchKey;
}

	//getters
template<class KeyType, class ItemType>
ItemType Entry<KeyType, ItemType>::getItem() const {
	return item;
}
template<class KeyType, class ItemType>
KeyType Entry<KeyType, ItemType>::getKey() const {
	return searchKey;
}

	//setters
template<class KeyType, class ItemType>
void Entry<KeyType, ItemType>::setItem(const ItemType& item) {
	this->item = item;
}
template<class KeyType, class ItemType>
void Entry<KeyType, ItemType>::setKey(const KeyType& searchKey) {
	this->searchKey = searchKey;
}

	//operators
template<class KeyType, class ItemType>
bool Entry<KeyType, ItemType>::operator==(const Entry<KeyType, ItemType>& rightHandEntry)const {
	return (item == rightHandEntry->getItem());
}
template<class KeyType, class ItemType>
bool Entry<KeyType, ItemType>::operator>(const Entry<KeyType, ItemType>& rightHandItem) const {
	return (item > rightHandItem);
}
;

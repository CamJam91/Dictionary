#pragma once
template < class ItemType>
class BinaryNode
{
private:
	ItemType item;
	// Data portion 
	BinaryNode<ItemType>* leftChild = nullptr;  // Pointer to left child 
	BinaryNode<ItemType>* rightChild = nullptr; // Pointer to right child 
public:
		//constructors
	BinaryNode();
	BinaryNode(const ItemType& item);
	BinaryNode(const ItemType& item, BinaryNode<ItemType>* leftChild, BinaryNode<ItemType>* rightChild);
		//getters
	ItemType getItem() const;
	bool isLeaf() const;
	BinaryNode<ItemType>* getLeftChild() const;
	BinaryNode<ItemType>* getRightChild() const;
		//setters
	void setItem(const ItemType& item);
	void setLeftChild(BinaryNode<ItemType>* leftChild);
	void setRightChild(BinaryNode<ItemType>* rightChild);
};

template<class ItemType>
inline BinaryNode<ItemType>::BinaryNode() {}

template<class ItemType>
inline BinaryNode<ItemType>::BinaryNode(const ItemType& item){
	this->item = item;
}
template<class ItemType>
inline BinaryNode<ItemType>::BinaryNode(const ItemType& item, BinaryNode<ItemType>* leftChild, BinaryNode<ItemType>* rightChild){
	this->item = item;
	this->leftChild = leftChild;
	this->rightChild = rightChild;
}
	//getters
template<class ItemType>
inline ItemType BinaryNode<ItemType>::getItem() const{
	return item;
}
template<class ItemType>
inline bool BinaryNode<ItemType>::isLeaf() const
{
	return (leftChild == nullptr) && (rightChild == nullptr);
}
template<class ItemType>
inline BinaryNode<ItemType>* BinaryNode<ItemType>::getLeftChild() const
{
	return leftChild;
}
template<class ItemType>
inline BinaryNode<ItemType>* BinaryNode<ItemType>::getRightChild() const
{
	return rightChild;
}
	//setters
template<class ItemType>
inline void BinaryNode<ItemType>::setItem(const ItemType& item){
	this->item = item;
}
template<class ItemType>
inline void BinaryNode<ItemType>::setLeftChild(BinaryNode<ItemType>* leftChild){
	this->leftChild = leftChild;
}
template<class ItemType>
inline void BinaryNode<ItemType>::setRightChild(BinaryNode<ItemType>* rightChild){
	this->rightChild = rightChild;
}
;

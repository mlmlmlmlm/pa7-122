#include "Data.h"


template <class T>
class Node
{
public:
	Node(T &newData);

	~Node();


	T* getData();
	Node<T>* getNextPtr();

	void setData(T& newData);
	void setNextPtr(Node<T>* pNewNext);

private:

	T data;
	Node<T>* mpNext;
};




template <class T>
Node<T>::Node(T &newData)
{
	data = newData;
	mpNext = nullptr;
}

template <class T>
Node<T>::~Node()
{
}

template <class T>
T* Node<T>::getData()
{
	return &this->data;
}

template <class T>
Node<T>* Node<T>::getNextPtr()
{
	return this->mpNext;
}

template <class T>
void Node<T>::setData(T& newData)
{
	data = newData;
}


template <class T>
void Node<T>::setNextPtr(Node<T>* pNewNext)
{
	mpNext = pNewNext;
}








#include "Node.h"

template <class T>
class List
{
public:
	List();
	~List();

	//getter
	Node<T>* getHeadPtr();

	//setter
	void setHeadPtr(Node<T>* pNewHead);

	bool insertAtFront(T &newData);  	//may need to use others
	bool isEmpty();



private:
	Node<T>* mpHead;


	Node<T>* makeNode(T &newData);
	void destroyList();
	void destroyListHelper(Node<T>* pMem);

};


template <class T>
List<T>::List()
{
	mpHead = nullptr;
}




template <class T>
List<T>::~List()
{
	
	delete mpHead;
}






template <class T>
Node<T>* List<T>::getHeadPtr()
{
	return mpHead;
}

template <class T>
void List<T>::setHeadPtr(Node<T>* pNewHead)
{
	mpHead = pNewHead;
}



template <class T>
Node<T>* List<T>::makeNode(T &newData)
{
	Node<T>* pMem = new Node<T>(newData);
	return pMem;
}




template <class T>
bool List<T>::insertAtFront(T &newData)     
{
	Node<T>* pMem = makeNode(newData);
	bool success = false;

	if (pMem != nullptr)
	{
		success = true;
		pMem->setNextPtr(mpHead);
		mpHead = pMem;
	}

	return success;
}

template <class T>
bool List<T>::isEmpty()
{
	return (mpHead == nullptr); //need to remember this workss
}

template <class T>
void List<T>::destroyList()
{
	destroyListHelper(mpHead);
}


template <class T>
void List<T>::destroyListHelper(Node<T>* pMem)
{
	if (pMem != nullptr)
	{
		destroyListHelper(pMem->getNextPtr());
		delete pMem; 
	}
}


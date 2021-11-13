#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <string>
#include <fstream>
#include <vector>}
#include <ctime>

using std::getline;
using std::ofstream;
using std::ifstream;
using std::fstream;
using std::vector;
using std::cin;
using std::cout;
using std::endl;
using std::string;

//code included/modified from stack template in schedule/lab 9, 
template <class T>
class Stack
{
public:
	Stack();
	~Stack();

	bool push(T& newItem);
	bool pop(T& poppedItem);
	bool peek(T& item);


	bool isEmpty();

private:
	vector<T> mTop; //vector
};


template <class T>
Stack<T>::Stack()
{
}
template <class T>
Stack<T>::~Stack()
{
}

template <class T>
bool Stack<T>::pop(T& poppedItem)
{
	if (this->isEmpty() == true)
	{
		return false;
	}
	else
	{
		poppedItem = mTop.back();
		mTop.pop_back();
		return true;
	}

}


template <class T>
bool Stack<T>::push(T& newItem)
{

	mTop.push_back(newItem);

	if (this->isEmpty() == true)
	{
		return false;
	}
	else
	{
		return true;
	}
}




template <class T>
bool Stack<T>::peek(T& item)
{
	if (this->isEmpty() == true)
	{
		return false;
	}
	else
	{
		item = mTop.back();
		return true;
	}
}



template <class T>
bool Stack<T>::isEmpty()
{
	return mTop.empty();
}




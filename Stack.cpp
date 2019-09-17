// $Id: Stack.cpp 827 2011-02-07 14:20:53Z hillj $

// Honor Pledge:
//
// I pledge that I have neither given nor received any help
// on this assignment.
// Andrew Liden
//
// Stack
//
#define DEFAULT_SIZE 50
#include <stdexcept>

template <typename T>
Stack <T>::Stack (void)
: data_ (Array<T>(DEFAULT_SIZE)), push_index_ (0)
{

}

//
// Stack copy constructor
//
template <typename T>
Stack <T>::Stack (const Stack & stack)
: data_ (Array<T>(stack.data_)), push_index_ (stack.push_index_)
{

}

//
// ~Stack
//
template <typename T>
Stack <T>::~Stack (void)
{

}

//
// push
//
template <typename T>
void Stack <T>::push (T element)
{
	//First, check if we need to allocate more memory.
	//This will occur when the max size is equal to the placement position.
	//This way allocations from resizes only occur every DEFAULT_SIZE elements, instead of every single push.
	if(data_.max_size() == push_index_)
	{
		//Grow the array by the default size.
		size_t newSize = data_.max_size() + DEFAULT_SIZE;
		data_.resize(newSize);
	}

  // COMMENT You are resizing the array twice if the condition above
  // is true. Please improve your design so you are only calling the
  // resize method once.	
	// RESOLUTION array is now grown by the MAX size of the array + the default size,
	// rather than the current size.  This made the resize unneeded.
	// Other unneeded resizes were also removed.
	
	//Set is used incase an error of some kind occurs.
	data_.set(push_index_, element);
	push_index_ ++;
	
}

//
// pop
//
template <typename T>
void Stack <T>::pop (void)
{
	if(is_empty())
		throw empty_exception();
	else
		//Just move the push index down.  It will appear the same as element removal.
		push_index_ --;
}

//
// operator =
//
template <typename T>
const Stack <T> & Stack <T>::operator = (const Stack & rhs)
{
	//Check for self assignment.
	if(this != &rhs)
	{
		//Replace the current data with a copy of the data from the right-hand side.
		this->data_ = Array<T>(rhs.data_);
		this->push_index_ = rhs.push_index_;
	}

}

//
// clear
//
template <typename T>
void Stack <T>::clear (void)
{
	//Simply set push_index_ to 0
	push_index_ = 0;
}

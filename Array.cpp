// $Id: Array.cpp 827 2011-02-07 14:20:53Z hillj $

// Honor Pledge:
//
// I pledge that I have neither given nor receieved any help
// on this assignment.
// Andrew Liden

#include "Array.h"

//
// Array
//
template <typename T>
Array <T>::Array (void)
: Array_Base<T>()
{

}

//
// Array (size_t)
//
template <typename T>
Array <T>::Array (size_t length)
: Array_Base<T>(length)
{

}

//
// Array (size_t, char)
//
template <typename T>
Array <T>::Array (size_t length, T fill)
: Array_Base<T>(length, fill)
{

}

//
// Array (const Array &)
//
template <typename T>
Array <T>::Array (const Array & array)
: Array_Base<T>(array)
{

}

//
// ~Array
//
template <typename T>
Array <T>::~Array (void)
{
	
}

//
// operator =
//
template <typename T>
const Array <T> & Array <T>::operator = (const Array & rhs)
{
	//If the arrays are at the same address, there's no need to make any changes.
	if(this != &rhs)
	{
		//Reallocate this array to be the same current size as the right-hand array.
		delete[] this->data_;
		this->data_ = new T[rhs.max_size()];
		this->cur_size_ = rhs.size();
		this->max_size_ = rhs.max_size();
		//Now, iterate over the length of the maximum size, and copy data from the right-hand-side array.
		for(size_t indexToCopy = 0; indexToCopy < this->max_size_; indexToCopy++)
			this->data_[indexToCopy] = rhs[indexToCopy];
	}
}

//
// resize
//
template <typename T>
void Array <T>::resize (size_t new_size)
{
	//If the new size is smaller or equal to what's allocated, it's possible to simply change cur_size_ to new_size.  Otherwise, reallocate the array to the new size.
	if(new_size <= this->max_size_)
		this->cur_size_ = new_size;
	else
		reallocate(new_size);	
}

//
// shrink
//
template <typename T>
void Array <T>::shrink (void)
{
	//Only do something if the max size and the current size differ.
	if(this->max_size_ != this->cur_size_)
		reallocate(this->cur_size_);
}


template <typename T>
void Array <T>::reallocate(size_t new_size)
{
	T * newMemory = new T[new_size];
	//Figure out how much data needs to be copied.  Initially, assume it's the amount specified by new_size (shrinking)
	size_t dataToCopy = new_size;
	//If cur_size_ is less than new size, only copy the current size.
	if(this->cur_size_ < new_size)
		dataToCopy = this->cur_size_;
	//Iterate over the length of the array that needs to be copied.
	for(size_t indexToCopy = 0; indexToCopy < dataToCopy; indexToCopy ++)
		newMemory[indexToCopy] = this->data_[indexToCopy];
	//After everything has been copied, de-allocate the old data.
	delete [] this->data_;

	//Point data_ to the newly created memory pointer and set current and max size to be equal to the new size.
	this->data_ = newMemory;
	this->cur_size_ = new_size;
	this->max_size_ = new_size;
}

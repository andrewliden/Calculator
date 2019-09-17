//==============================================================================
/**
 * @file       Array_Base.cpp
 *
 *
 * Honor Pledge:
 *
 * I pledge that I have neither given nor received any help
 * on this assignment.
 * Andrew Liden
 */
//==============================================================================

#include <stdexcept>

//
// Array
//
template <typename T>
Array_Base <T>::Array_Base (void)
: data_ (nullptr), cur_size_ (0), max_size_ (0), is_slice_(false)
{
	
}

//
// Array_Base (size_t)
//
template <typename T>
Array_Base <T>::Array_Base (size_t length)
: data_ (nullptr), cur_size_ (length), max_size_ (length), is_slice_(false)
{
	//don't try to allocate if the user is asking for a zero length Array.
	if(length > 0)
		allocate(length);
}

//
// Array_Base (size_t, char)
//
template <typename T>
Array_Base <T>::Array_Base (size_t length, T fill)
: data_ (nullptr), cur_size_ (length), max_size_ (length), is_slice_(false)
{
	if(length > 0)
	{
		allocate(length);
		this->fill(fill);
	}
}

//
// Array_Base (const Array_Base &)
//
template <typename T>
Array_Base <T>::Array_Base (const Array_Base & array)
: data_(nullptr), cur_size_ (array.size()), max_size_ (array.max_size()), is_slice_(array.is_slice_)
{
	if(!is_slice_)
	{
		//Allocate an array capable of holding the data from the source, then copy the data.
		data_ = new T[max_size_];
		for(size_t indexToCopy = 0; indexToCopy < cur_size_; indexToCopy ++)
		{
			data_[indexToCopy] = array[indexToCopy];
		}
	}
}

//
// ~Array_Base
//
template <typename T>
Array_Base <T>::~Array_Base (void)
{
	if(data_ != nullptr and !is_slice_)
		delete [] data_;
}

//
// operator =
//
template <typename T>
const Array_Base <T> & Array_Base <T>::operator = (const Array_Base & rhs)
{
	//If the arrays are at the same address, there's no need to make any changes.
	if(this != &rhs)
	{
		//Reallocate this array to be the same current size as the right-hand array.
		delete[] data_;
		data_ = new T[rhs.max_size()];
		cur_size_ = rhs.size();
		max_size_ = rhs.max_size();
		//Now, iterate over the length of the maximum size, and copy data from the right-hand-side array.
		for(size_t indexToCopy = 0; indexToCopy < max_size_; indexToCopy++)
			data_[indexToCopy] = rhs[indexToCopy];
	}
}

//
// operator []
//
// This is very similar to get, but must return a reference, or assignments won't be possible.
template <typename T>
T & Array_Base <T>::operator [] (size_t index)
{
	//First, check if the current size is 0.  If this is the case, we're always going to get an out of range exception.
	if(cur_size_ == 0)
		throw std::out_of_range("Invalid Index");
	else if(index > cur_size_ - 1)
		throw std::out_of_range("Invalid Index");
	//If we're here and none of the exceptions were triggered, return the data at the specified index.
	else
	{
		T & returnValue = data_[index];
		return returnValue;
	}
}

//
// operator [] 
//
// Since this method only allows access and not writing, exception checks are not needed.
template <typename T>
const T & Array_Base <T>::operator [] (size_t index) const
{
	T & returnValue = data_[index];
	return returnValue;
}

//
// get
//
template <typename T>
T Array_Base <T>::get (size_t index) const
{
	//First, check if the current size is 0.  If this is the case, we're always going to get an out of range exception.
	if(cur_size_ == 0)
		throw std::out_of_range("Invalid Index");
	//Next, check if this index is greater than the current size, minus 1 (arrays start at 0).  
	//If so, throw an out of range exception.
	else if(index > cur_size_ - 1)
		throw std::out_of_range("Invalid Index");
	//If we're here and none of the exceptions were triggered, return the data at the specified index.
	else
		return data_[index];
}

//
// set
//
template <typename T>
void Array_Base <T>::set (size_t index, T value)
{
	//First, check if the current size is 0.  If this is the case, we're always going to get an out of range exception.
	if(cur_size_ == 0)
		throw std::out_of_range("Invalid Index");
	//Next, check if this index is greater than the current size, minus 1 (arrays start at 0).  
	//If so, throw an out of range exception.
	else if(index > cur_size_ - 1)
		throw std::out_of_range("Invalid Index");
	//If we're here and none of the exceptions were triggered, set the data at the specified index to the value.
	else
		data_[index] = value;
}

//
// find (char)
//
template  <typename T>
int Array_Base <T>::find (T value) const
{
	try
	{
		find(value, 0);
	}
	catch(std::out_of_range e)
	{
		return -1;
	}
}

//
// find (char, size_t) 
//
template <typename T>
int Array_Base <T>::find (T val, size_t start) const
{
	//Throw an exception if we're attempting to start somewhere outside the Array_Base.
	if(start > cur_size_ - 1)
		throw std::out_of_range("Invalid Index");
	else
	{
		//Iterate over the Array_Base and check for the target element.
		for(size_t indexToCheck = start; indexToCheck < cur_size_; indexToCheck++)
			if(data_[indexToCheck] == val)
				return int (indexToCheck);
		//If we're here, the data wasn't found.
		return -1;
	}
}

//
// operator ==
//
template <typename T>
bool Array_Base <T>::operator == (const Array_Base & rhs) const
{
	//Start with what's easy.  
	//If the addresses are the same, this is equivalent.
	if(this == &rhs)
		return true;
	//Then, if the current sizes differ, there's no way the two arrays are equivalent.
	if(cur_size_ != rhs.size())
		return false;
	else
	{
		//If we're here, now we have to do things the hard way.  Compare each entry.  Return false if a single one doesn't match.
		for(size_t indexToCheck = 0; indexToCheck < cur_size_; indexToCheck++)
			if(data_[indexToCheck] != rhs[indexToCheck])
				return false;
		//If we managed to get here, none of the above checks failed.  The arrays should match.
		return true;
	}
}

//
// operator !=
//
template <typename T>
bool Array_Base <T>::operator != (const Array_Base & rhs) const
{
	return !(*this == rhs);
}

//
// fill
//
template <typename T>
void Array_Base <T>::fill (T value)
{
	//Iterate over the current size and replace the data with the designated fill element.
	for(size_t indexToFill = 0; indexToFill < cur_size_; indexToFill ++)
		data_[indexToFill] = value;
}

//This is based on code for my first assignment from CSCI 240.
template <typename T>
void Array_Base <T>::reverse (void)
{
	size_t unreversedItems = cur_size_;
	//While there's any more than 1 un-reversed character, keep reversing the string.
	while(unreversedItems > 1)
	{
		// Find the indexes of the first and last item
		// of the part of the array that hasn't yet been reversed.
		// The program works from the "outside of the array" in.
		size_t indexOfFirstItem = (cur_size_ - unreversedItems) / 2;
		size_t indexOfLastItem = indexOfFirstItem + unreversedItems - 1;
		// Store the items in memory
		T firstItem = data_[indexOfFirstItem];
		T lastItem = data_[indexOfLastItem];
		// Perform the swap.
		data_[indexOfFirstItem] = lastItem;
		data_[indexOfLastItem] = firstItem;
		//Consider two less letters, then loop again if necessary.
		unreversedItems -= 2;
	}
}

template <typename T>
void Array_Base <T>::allocate(size_t length)
{
	//As long as the intended size is greater than zero, allocate enough space to hold the data.
	if(max_size_ > 0)
		data_ = new T[max_size_];

}

template <typename T>
Array_Base<T> Array_Base<T>::slice (size_t begin) const
{
	//Calculate the end point.  First, assume it's 0.  This helps avoid some problems from boundary conditions.
	size_t end = 0;
	//If the current size is non-zero, assume it's the current size minus 1.
	if(cur_size_ > 0)
		end = cur_size_ - 1;
	return slice(begin, end);
}

template <typename T>
Array_Base<T> Array_Base<T>::slice (size_t begin, size_t end) const
{
	
	//First, check if the beginning is greater than the end.  If so, throw something.
	if(begin > end)
		throw std::out_of_range("Begin index cannot exceed end index");
	//Assuming the current size is non-zero, check if the beginning or end indexes exceed the size.
	else if(cur_size_ > 0)
	{
		if(begin > cur_size_ - 1)
			throw std::out_of_range("Invalid Beginning Index");
		if(end > cur_size_ - 1 )
			throw std::out_of_range("Invalid Ending Index");
	}
	else
	{
		//If the current size is zero, make sure that begin and end are both zero.
		if(begin != 0)
			throw std::out_of_range("Invalid Beginning Index");
		if(end != 0)
			throw std::out_of_range("Invalid Ending Index");
	}
	//Get the reference data
	T * dataReference = data_ + begin;
	//Calculate the length.  First, assume it's zero, then correct if we're looking at a non-zero size array.
	size_t length = 0;
	if(cur_size_ > 0)
		length = end - begin + 1;
	
	Array_Base<T> returnArray = Array_Base<T>(dataReference, length);
	return returnArray;
}

template <typename T>
Array_Base<T>::Array_Base(T * dataReference, size_t length)
:data_(dataReference), cur_size_(length), max_size_(length), is_slice_(true)
{
	
}

//I attempted to implement slices using polymorphism, but couldn't get past some issues.
//I left this here in case you (Prof. Hill) are willing to give feedback.
/*
///------Begin definitions for Array_Slice------///
//Default constructor uses default from base class (empty)
template <typename T>
Array_Slice <T>::Array_Slice()
:Array_Base<T>()
{
	
}

//Reference & length-specified constructor
template <typename T>
Array_Slice <T>::Array_Slice(T * data_reference, size_t length)
//Call the base class first, otherwise data will be overwritten by the base class constructor with a null pointer.
:Array_Base<T>()
{
	//After allowing the base class to initialize with a null pointer and 0 current & max size,
	//Replace the values with those from the arguments.
	this->data_ = data_reference;
	this->cur_size_ = length;
	this->max_size_ = length;
}

//Copy Constructor.
template <typename T>
Array_Slice <T>::Array_Slice(Array_Slice <T> & source)
//Call the base class first, otherwise data will be overwritten by the base class constructor with a null pointer.
:Array_Base<T>()
{
	//After allowing the base class to initialize with a null pointer and 0 current & max size,
	//Replace the values with those of the source.
	this->data_ = source.data_;
	this->cur_size_ = source.cur_size_;
	this->max_size_ = source.max_size_;
}

//Destructor.  Make sure to null the pointer so the base doesn't delete data.
template <typename T>
Array_Slice <T>::~Array_Slice()
{
	this->data_ = nullptr;
}

template <typename T>
//Assignment operator.
const Array_Slice<T> & Array_Slice <T>::operator = (const Array_Slice <T> & rhs)
{
	//Simply retrieve the data from the right-hand side.
	this->data_ = rhs.data_;
	this->cur_size_ = rhs.cur_size_;
	this->max_size_ = rhs.max_size_;
}
*/
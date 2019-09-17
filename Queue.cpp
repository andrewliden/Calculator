// $Id: Queue.cpp

// Honor Pledge:
//
// I pledge that I have neither given nor received any help
// on this assignment.
// Andrew Liden
//
// Queue
//

#define DEFAULT_SIZE 50
#include <stdexcept>

template <typename T>
Queue <T>::Queue (void)
: data_ (Array<T>(DEFAULT_SIZE)), enqueue_mode_ (true), items_(0)
{

}

//
// Queue copy constructor
//
template <typename T>
Queue <T>::Queue (const Queue & queue)
: data_ (Array<T>(queue.data_)), enqueue_mode_(queue.enqueue_mode_), items_(queue.items_)
{

}

//
// ~Stack
//
template <typename T>
Queue <T>::~Queue (void)
{

}

//
// enqueue
//
template <typename T>
void Queue <T>::enqueue (T element)
{
	//If enqueue mode is false, we need to reverse the array.
	//This makes the first enqueue after a dequeue O(N).  That's bad.
	//However, while enqueue mode is true, this makes enqueue O(1).  That's good.
	if(!enqueue_mode_)
	{
		//Reverse has time complexity O(N).
		//Only reverse the slice of the array that is within use, and don't
		//try to reverse an empty array, or an array with 1 element.
		if(items_ > 1)
		{
			Array_Base<T> partToReverse = data_.slice(0, items_ - 1);
			partToReverse.reverse(); 
		}
		enqueue_mode_ = true;
	}
	//First, check if we need to allocate more memory.
	//This will occur when the max size is equal to the placement position.
	//This way allocations from resizes only occur every DEFAULT_SIZE elements, instead of every single push.
	if(data_.max_size() == items_)
	{
		//Grow the array by the default size.
		size_t newSize = data_.size() + DEFAULT_SIZE;
		data_.resize(newSize);
	}
	//Place the item at the end, then increment the item count.
	data_[items_] = element;
	items_++;
}

//
// dequeue
//
template <typename T>
T Queue<T>::dequeue (void)
{
	//Make sure the queue has items, first.
	if(is_empty())
		throw empty_exception();
	else
	{
	// COMMENT This design is OK, but it is not the best design. This will be
    // a very expensive array to use if you are dequeing a lot of elements. This
    // is because you are copying N elements each time you dequeue 1 element.
    // Instead, you only want to copy element when necessary. Come up with a better
    // design that is not as expensive for the client to use.
	  // RESOLUTION My design actually only copied N elements every time you dequeued
	  // DEFAULT_SIZE elements.  Still, it wasn't ideal.  Instead, the Array  now 
	  // reverses if it's switched between enqueueing or dequeueing.  On switches, this 
	  // is bad (O(n) time complexity).  But, successive enqueues and dequeues 
	  // (which are probably the more common case) are O(1).  It's not ideal, but it's 
	  // likely better than the previous design in the common case.
	  
	  // I wish I could just use a linked list.
	  
		//If we're switching from enqueuing, reverse the array (O(n))
		if(enqueue_mode_)
		{
			Array_Base<T> partToReverse = data_.slice(0, items_ - 1);
			partToReverse.reverse();
			enqueue_mode_ = false;
		}
		//Decrement the item count, and return the item at the end of the array.
		items_--;
		T returnValue = data_[items_];
		return returnValue;
	}
}

//
// operator =
//
template <typename T>
const Queue <T> & Queue <T>::operator = (const Queue & rhs)
{
	//Check for self assignment.
	if(this != &rhs)
	{
		//Copy the data from the right-hand side.
		this->data_ = Array<T>(rhs.data_);
		this->enqueue_mode_ = rhs.enqueue_mode_;
		this->items_ = rhs.items_;
	}
}

//
// clear
//
template <typename T>
void Queue <T>::clear (void)
{
	//Simply set items to 0.
	items_ = 0;
	//Assume that after a clear, we'll be in enqueue mode.
	enqueue_mode_ = true;
}

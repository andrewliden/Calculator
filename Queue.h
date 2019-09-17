// -*- C++ -*-
// $Id: Array.h 380 2010-02-08 05:10:33Z hillj $

//==============================================================================
/**
 * @file       Queue.h
 *
 * 
 *
 * Honor Pledge:
 *
 * I pledge that I have neither given nor received any help
 * on this assignment.
 * -Andrew Liden
 */
//==============================================================================

#ifndef _CS363_QUEUE_H_
#define _CS363_QUEUE_H_

#include "Array.h"

template <typename T>
class Queue
{
	/// Type definition of the type.
	typedef T type;
	
	public:
	  /**
	    * @class empty_exception
	    *
	    * Exception thrown to indicate the stack is empty.
	    */
		class empty_exception : public std::exception
		{
			public:
			/// Default constructor.
			empty_exception (void)
			: std::exception () { }
			/**
			* Initializing constructor.
			*
			* @param[in]      msg         Error message.
			*/
			empty_exception (const char * msg)
			: std::exception (msg) { }
		};
		
		/// Default Constructor
		Queue();
	  
		/// Copy Constructor
		Queue(const Queue & q);
		
		/// Destructor
		~Queue();
		
		
	/**
	   * adds the element to the end of the list;
	   *
	   * @param[in]      element       Element to add to the list
	   */
		void enqueue(T element);
	/**
	   * Remove the element from the front of the list.
	   * If there are not elements in the queue, this method throws empty_exception
	   *
	   * @exception     empty_exception    The queue is empty.
	   * @return		The dequeued element. 
	   */
		T dequeue();
	 /**
	   * Test if the queue is empty
	   *
	   * @retval         true          The queue is empty
	   * @retval         false         The queue is not empty
	   */  
		bool is_empty() const;
	/**
	   * Number of element on the stack.
	   *
	   * @return         Size of the stack.
	   */
		size_t size() const;
	/**
	   * Remove all items from the queue.
	   */
		void clear();
		
		const Queue & operator = (const Queue & rhs);
	
	private:
		Array<T> data_;
		bool enqueue_mode_;
		size_t items_;
	
};

// include the inline files
#include "Queue.inl"

// include the source file since template class
#include "Queue.cpp"

#endif
//==============================================================================
/**
 * @file       Array_Base.h
 *
 *
 * Honor Pledge:
 *
 * I pledge that I have neither given nor received any help
 * on this assignment.
 * Andrew Liden
 */
//==============================================================================

#ifndef ARRAY_BASE
#define ARRAY_BASE

/**
 * @class Array
 *
 * Basic template of a standard array class.
 */
template <typename T>
class Array_Base
{
	public:
		/// Type definition of the element type.
		typedef T type;

		/// Default constructor.
		Array_Base (void);

		/**
		* Initializing constructor.
		*
		* @param[in]      length        Initial size
		*/
		Array_Base (size_t length);

		/**
		* Initializing constructor.
		*
		* @param[in]      length        Initial size
		* @param[in]      fill          Initial value for each element
		*/
		Array_Base (size_t length, T fill);

		/**
		* Copy constructor
		*
		* @param[in]     arr         The source array.
		*/
		Array_Base (const Array_Base & arr);

		/// Destructor.
		~Array_Base (void);

		/**
		* Assignment operation
		*
		* @param[in]       rhs      Right-hand side of equal sign
		* @return          Reference to self
		*/
		const Array_Base & operator = (const Array_Base & rhs);

		/**
		* Retrieve the current size of the array.
		*
		* @return          The current size
		*/
		size_t size (void) const;

		/**
		* Retrieve the maximum size of the array.
		*
		* @return          The maximum size
		*/
		size_t max_size (void) const;

		/**
		* Get the character at the specified index. If the index is not
		* within the range of the array, then std::out_of_range exception
		* is thrown.
		*
		* @param[in]       index               Zero-based location
		* @exception       std::out_of_range   Invalid \a index value
		*/
		T & operator [] (size_t index);

		/**
		* @overload
		*
		* The returned character is not modifiable.
		*/
		const T & operator [] (size_t index) const;

		/**
		* Get the character at the specified index. If the \a index is not within
		* the range of the array, then std::out_of_range exception is thrown.
		*
		* @param[in]       index                 Zero-based location
		* @return          Character at \index
		* @exception       std::out_of_range     Invalid index value
		*/  
		T get (size_t index) const;

		/** 
		* Set the character at the specified \a index. If the \a index is not
		* within range of the array, then std::out_of_range exception is 
		* thrown.
		*
		* @param[in]       index                 Zero-based location
		* @param[in]       value                 New value for character
		* @exception       std::out_of_range     Invalid \a index value
		*/
		void set (size_t index, T value);

		/**
		* Set a new size for the array. If \a new_size is less than the current
		* size, then the array is truncated. If \a new_size if greater then the
		* current size, then the array is made larger and the new elements are
		* not initialized to anything. If \a new_size is the same as the current
		* size, then nothing happens.
		*
		* The array's original contents are preserved regardless of whether the 
		* array's size is either increased or decreased.
		*
		* @param[in]       new_size              New size of the array
		*/
		int find (T element) const;

		/**
		* @overload
		*
		* This version allows you to specify the start index of the search. If
		* the start index is not within the range of the array, then the
		* std::out_of_range exception is thrown.
		*
		* @param[in]       ch                   Character to search for
		* @param[in]       start                Index to begin search
		* @return          Index value of first occurrence
		* @retval          -1                   Character not found
		* @exception       std::out_of_range    Invalid index
		*/
		int find (T element, size_t start) const;

		/**
		* Test the array for equality.
		*
		* @param[in]       rhs                  Right hand side of equal to sign
		* @retval          true                 Left side is equal to right side
		* @retval          false                Left side is not equal to right side
		*/
		bool operator == (const Array_Base & rhs) const;

		/**
		* Test the array for inequality.
		*
		* @param[in]       rhs                  Right-hand size of not equal to sign
		* @retval          true                 Left side is not equal to right side
		* @retval          false                Left size is equal to right side
		*/
		bool operator != (const Array_Base & rhs) const;

		/**
		* Fill the contents of the array.
		*
		* @param[in]       ch                   Fill character
		*/
		void fill (T element);

		/// Reverse the contents of the array such that the first element is now
	    /// the last element and the last element is the first element.
	    void reverse (void);
		
		/**
		* The slice() method returns a shallow copy of a portion of an array into
		* a new array object selected from begin to end (end not included). The original
		* array will not be modified.
		*
		* @param[in]       begin           The starting index
		* @return          A new Array object
		*/
		Array_Base slice (size_t begin) const;
		  
		/**
		* @overload
		*
		* @param[in]       begin           The starting index
		* @param[in]       end             The ending index
		* @return          A new Array object
		*/
		Array_Base slice (size_t begin, size_t end) const;
		
	protected:
		/// Pointer to the actual data.
		T * data_;

		/// Current size of the array.
		size_t cur_size_;

		/// Maximum size of the array.
		size_t max_size_;
		
		/// Checks if this is a shallow copy
		bool is_slice_;

	private:
		/// Helper methods
		 /**
		* allocate:  Helper function for constructors.  
		* Allocates memory on construction.
		*
		* @param[in]      length        Initial size
		*/
		void allocate(size_t length);
		
		/**
		* Shallow copy constructor
		*
		* @param[in]      dataReference		reference to external data
		* @param[in]      length			length of the external data.
		*/
		Array_Base(T * dataReference, size_t length);
};

//I attempted to implement slices using polymorphism, but couldn't get past some issues.
//I left this here in case you (Prof. Hill) are willing to give feedback
//The main issue I ran into is that when attempting to use polymorphism this way,
//Array_Base's copy constructor would occasionally get called, converting the shallow
//copy into a deep copy.
/*
template <typename T>
class Array_Slice : public Array_Base<T>
{
	public:
		/// Type definition of the element type.
		typedef T type;
		//Default constructor:  Returns a slice with 0 length and a nullptr reference.
		Array_Slice();
		//Reference & length-specified constructor
		Array_Slice(T * data_reference, size_t length);
		//Copy Constructor.
		Array_Slice(Array_Slice & source);
		//Destructor.  Make sure to null the pointer so the base doesn't delete data.
		~Array_Slice();
		//Assignment operator.
		const Array_Slice & operator = (const Array_Slice & rhs);
		
};
*/
#include "Array_Base.inl"

#include "Array_Base.cpp"

#endif
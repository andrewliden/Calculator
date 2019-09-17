// -*- C++ -*-
// $Id: Stack.inl 827 2011-02-07 14:20:53Z hillj $

// Honor Pledge:
//
// I pledge that I have neither given nor received any help on
// this assignment.

//
// size
//
template <typename T>
inline
size_t Stack <T>::size (void) const
{
	return push_index_;
}

//
// top
//
template <typename T>
inline
T Stack <T>::top (void) const
{	
	if(is_empty())
		throw empty_exception();
	else
		return data_[push_index_ - 1];
}

//
// is_empty
//
template <typename T>
inline
bool Stack <T>::is_empty (void) const
{
	return (push_index_ == 0);
}

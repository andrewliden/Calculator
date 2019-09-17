// Array_Base.inl

// Honor Pledge:
//
// I pledge that I have neither given nor received any help
// on this assignment.
// Andrew Liden

//
// size
//
template <typename T>
inline
size_t Array_Base <T>::size (void) const
{
	return cur_size_;
}

//
// max_size
//
template <typename T>
inline
size_t Array_Base <T>::max_size (void) const
{
	return max_size_;
}

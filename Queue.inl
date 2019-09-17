// $Id: Queue.inl

// Honor Pledge:
//
// I pledge that I have neither given nor received any help
// on this assignment.
// Andrew Liden
//
// Queue
//

//
// size
//
template <typename T>
inline
size_t Queue <T>::size (void) const
{
	return items_;
}

//
// is_empty
//
template <typename T>
inline
bool Queue <T>::is_empty (void) const
{
	return (items_ == 0);
}

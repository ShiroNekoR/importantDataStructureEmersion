#pragma once
#include <algorithm>

//	realization of List class
template<typename object>
class myList {
private:
	class dblNode;
private:
	class iterator;
	class const_iterator;
public:
	explicit myList() : 
	{
		init();
	}
	myList( const myList & rhs) : 
		_size(rhs._size),
		_head(rhs.)
	{

	}
	myList( myList && ) {

	}
	myList& operator = (const myList& rhs)& {

	}
	myList& operator = ( myList&& rhs )& {

	}

public:
	void push_back( const object& rhs ) {
		
	}

private:
	void init() {
		int _size = 0;
		_head = new dblNode;
		_tail = new dblNode;
		_head->next = _tail;
		_tail->previous = _head;
	}

private:
	dblNode* _head;
	dblNode* _tail;
	int _size;
};


//	realization of Node class, containing three data members
template<typename object>
class dblNode {
	explicit dblNode( const object& ob = object{0},
					  dblNode<object>* p = nullptr,
					  dblNode<object>* t = nullptr ) :
		element( ob ),
		next( p ),
		prvious( t )
	{

	}
	explicit dblNode( object&& ob,
					  dblNode<object>* p = nullptr,
					  dblNode<object>* t = nullptr ) :
		element( std::move( ob ) ),
		next( p ),
		prvious( t )
	{

	}

	~dblNode() {
		next = nullptr;
		previous = nullptr;
	}


private:
	dblNode<object>* next;
	dblNode<object>* previous;
	object element;
};

//realization of iterator for List;
template<typename object>
class const_iterator {
public:
	const_iterator( ) :
		currentNode(nullptr)
	{
		
	}

	const_iterator( const const_iterator& rhs ) 
		:currentNode(rhs.currentNode)
	{

	}

	const_iterator( const_iterator && rhs) : 
	{
		std::swap( *this, rhs );
	}

	bool operator == (const const_iterator& rhs)const {
		return this->currentNode == rhs.currentNode;
	}

	bool operator != ( const const_iterator& rhs )const {
		return !(this->currentNode == rhs.currentNode);
	}

	const_iterator& operator = ( const const_iterator& rhs ) const &
	{
		const_iterator* temp = new const_iterator(rhs);
		std::swap( temp, *this );
		delete temp;
		return *this;
	}
	
	const object& operator *() const{
		return this->retrive();
	}

	const_iterator& operator ++() {
		currentNode = currentNode->next;
		return *this;
	}

	const_iterator& operator ++( int ) {
		dblNode * temp = currentNode;
		this->operator++;//++(*this) is also ok;
		return temp;
	}

protected:
	friend class<object> List;

	object& retrive()const {
		return currentNode->element;
	}

	const_iterator( dblNode* p ) :
		currentNode(p)
	{

	}
	dblNode *currentNode;
};

template<typename object>
class iterator : public const_iterator<object>
{
public:
	iterator() {};
	object& operator*() {
		return const_iterator<object>::retrive();
	}
	const object& operator * () {
		return const_iterator<object>::operator*();
	}
	iterator& operator++() {
		this->
	}
protected:
	
};
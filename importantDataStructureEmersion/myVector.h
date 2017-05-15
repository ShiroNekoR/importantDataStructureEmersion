#pragma once
#include <algorithm>

template <typename object>
class myVector {
public:
	explicit myVector(int init_size = 0 ) : 
		_size(init_size) , 
		_capacity(init_size + SPARE_CAPACITY)
	{
		_array = new object[_capacity];
	}

	myVector( int sz, object Obj ) :
		_size( sz ),
		_capacity( sz + SPARE_CAPACITY )
	{
		_array = new object[_capacity];
		for (int i = 0; i < sz; sz++)
			_array[i] = Obj;
	}

	myVector( const myVector & rhs ) :
		_size( rhs._size ),
		_capacity( rhs._capacity ),
		_array( nullptr )
	{
		_array = new object[_capacity];
		for (int i = 0; i < sz; ++i)
			_array[i] = rhs._array[i];
	}

	myVector( myVector &&rhs ) :
		_size( rhs._size ),
		_capacity( rhs._capacity ),
		_array( rhs._array ) 
	{
		rhs._array = nullptr;
		rhs._size = 0;
		rhs._capacity = 0;
	}

	~myVector() {
		delete[] _array;
	}

	myVector & operator = ( const myVector & rhs ) {
		myVector temp = rhs; 
		std::swap( *this, temp );
		return this;
	}

	myVector & operator = ( myVector && rhs ) {
		std::swap( _size, rhs._size );
		std::swap( _capacity, rhs._capacity );
		std::swap( _array, rhs._array );
		return *this;
	}

	void resize(int newSize) {
		if (newSize > _capacity)
			reCapacity( 2 * _capacity );
		_size = newSize;
	}

	void reCapacity(int newCapa) {
		if (newCapa < _size)
			return;
		object *temp = new object[newCapa];
		_capacity = newCapa;
		for (int i = 0; i < _size; ++i) {
			temp[i] = std::move( _array[i] );
		}
		std::swap( _array, temp );
		delete[] temp;
		return;
	}

	void push_back( const object& Ob ) {
		if (_size + 1 >= _capacity)
			reCapacity( 2 * _capacity );
		_array[_size++] = Ob;
		return;
	}

	void push_back( object&& Ob ) {
		if (_size + 1 >= _capacity)
			reCapacity( 2 * _capacity );
		_array[_size++] = std::move(Ob);
		return;
	}

	object& operator[](int _index) 
	{
		return _array[_index];
	}

	const object& operator[]( int _index )const
	{
		return _array[_index];
	}

	bool empty() const {
		return _size == 0;
	}

	int capacity() const {
		return _capacity;
	}

	int size() const {
		return _size;
	}

	void pop_back() {
		if(!empty())
			--_size;
		return;
	 }

	const object& back()const {
		if(!empty())
			return _array[_size - 1];
	}

	typedef object* iterator;
	typedef const object* const_iterator;

	iterator begin() {
		return &_array[0];
	}

	const_iterator begin() const{
		return &_array[0];
	}

	iterator end() {
		return &_array[_size];
	}
	const_iterator end() const{
		return &_array[_size];
	}

	static const int SPARE_CAPACITY = 16;
private: 
	int _size;
	int _capacity;
	object * _array;
};
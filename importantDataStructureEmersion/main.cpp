#include <iostream>
#include "myVector.h"

int main() {
	myVector<int > vec;
	for (int i = 0; i < 20; ++i) {
		vec.push_back( i );
	}
	vec.empty();
	vec.capacity();
	vec.reCapacity( 30 );
	vec.pop_back();
	vec.back();
	std::cout << *vec.end() << std::endl;
	std::cout << vec.size() << std::endl;
	for (int i = 0; i < vec.size(); ++i) {
		printf( "ele: %d\r\n", vec[i] );
	}

	system( "pause" );
	return 0;
}
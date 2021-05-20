#include <iostream>
#include <vector>

using namespace std;


///**
// * First simple recursive algorithm
// * Correct but takes too long to run
// * Inspired from http://code.jasonbhill.com/python/project-euler-problem-15/
// */
//void pathFinder( char size, char row, char col)
//{
//	static unsigned int paths = 0;
//	if ( row == size && col == size ) {
//		paths += 1;
//		std::cout << paths << std::endl;
//	} else {
//		if ( row <= size )
//			pathFinder( size, row + 1, col );
//		if (col <= size ) 
//			pathFinder( size, row, col + 1 );
//	}
//}

int main() 
{
	char size = 20;

	//pathFinder( size, 0, 0);

	/** 
	 * Heavily memory intensive version
	 */
	//	std::vector<std::vector<long long int>> grid ( size , std::vector<long long int> ( size , 0) );
	//	for( int col = 0; col < size; col++ ) 
	//		grid[ 0 ][ col ] = col + 2;
	//	for( int row = 1; row <  size ; row++ ) {
	//		grid[ row ][ 0 ] = row + 2;
	//		for( int col = 1; col < size; col++ ) 
	//			grid[ row ][ col ] = grid[ row - 1 ][ col ] + grid [ row ][ col - 1 ];
	//	}	
	//	std::cout << grid[19][19] << endl;
	
	/**
	 * A less memory intensive version
	 */
	std::vector<long long unsigned int> grid( size, 0);
	for( int col = 0; col < size; col++ ) 
		grid[ col ] = col + 2;
	for( int row = 1; row < size; row++ ) {
		grid[ 0 ] = row + 2;
		for( int col = 1; col < size; col++ ) {
			grid[ col ] = grid[ col ] + grid[ col - 1 ];
		}
	}
	std::cout << grid[ size - 1 ];
	return 0;
}

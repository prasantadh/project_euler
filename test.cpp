#include <iostream>


/**
 * First simple recursive algorithm
 * Correct but takes too long to run
 */
void pathFinder( char size, char row, char col)
{
	static unsigned long int paths = 0;
	if ( row == size && col == size ) {
		paths += 1;
		// std::cout << paths << std::endl;
	} else {
		if ( row <= size )
			pathFinder( size, row + 1, col );
		if (col <= size ) 
			pathFinder( size, row, col + 1 );
	}
}

int main() 
{
	char size = 20;
	pathFinder( size, 0, 0);
	return 0;
}

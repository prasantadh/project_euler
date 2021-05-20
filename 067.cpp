#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <string>

int max3( long long int a, long long int b, long long int c =0 ) {
	if ( a > b )
	   if ( a > c )
	   		return a;
		else
			return c;
	else
		if (b > c)
			return b;
		else
			return c;	
}

int main()
{
	std::vector<std::vector<int>> triangle;
	int x;
	
	// reading method inspired by
	// http://stackoverflow.com/questions/8421170/read-floats-from-a-txt-file
	std::ifstream source;
	source.open( "./p067_triangle.txt", std::ios_base::in );
	if ( !source ) 
		std::cerr << "Can't open File " << std::endl;
	
	int size = 0;
	for( std::string line; std::getline( source, line ); )
	{
		std::istringstream in(line); 
		in >> x;
		triangle.push_back( std::vector<int> ( ++size, x ) );
		for(int col = 1; col < size; col++) {
			in >> x;
			triangle[ size - 1 ][ col ] = x;
		}
	}

	/* to print the triangle that was read */	
	//for( int row = 0; row < size; row++ ) {
	//	for( int col = 0; col <= row; col++ ) {
	//		std::cout << triangle[ row ][ col ] << "\t";
	//	} std::cout << std::endl;
	//} std::cout << std::endl;

	/**
	 * Run the algorithm
	 */	
	long long int replacedSum;
	for( int row = size - 2; row >= 0; row-- ) 
	{
		triangle[ row ][ 0 ] = triangle[ row ][ 0 ] + max3( triangle[ row + 1 ][ 0 ], triangle[ row + 1 ][ 1 ], 0 );
		for( int col = 1; col <= row; col++ ) 
		{
			triangle[ row ][ col ] = triangle[ row ][ col ] + max3( triangle[ row + 1 ][ col ], triangle[ row + 1 ][ col + 1 ] );
		}
		/* to print the updated triangle on the fly */
		//for( int col = 0; col <= row; col++ ) 
		//	std::cout << triangle[ row ][ col ] << "\t";
		//std::cout << std::endl;
	}

	std::cout << "Answer is: " << triangle[ 0 ][ 0 ] << std::endl;
	return 0;
}

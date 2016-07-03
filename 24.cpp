/**
 * premature optimization is the root of all evil.
 */
#include <iostream>
#include <vector>

using namespace std;

int main() 
{
	vector<int> factorials ( 11, 1 );
	vector<int> components ( 10, false );
	for( int i = 1; i < factorials.size(); i++ ) 	//initialize the factorials		
		factorials[ i ] = i * factorials[ i - 1 ];	
	for( int i = 1; i < components.size(); i++ ) 	//initialize the factorials		
		components[ i ] = i;

	int Nth = 999999; 	//required lexicographic Permutation - 1
	int chosen = -1;
	for ( int i = 9; i >= 0; i-- ) 
	{
		chosen = Nth / factorials[ i ];
		Nth %= factorials[ i ];
		for( int position = 0; position < components.size() ; ++position) 
		{
			if ( components[ position ] == chosen ) 
			{
				cout << position;
				components[ position ] = -1;
			} 
			else if ( components[ position ] > chosen ) 
			{
				components[ position ] -= 1;
			}
		}
	}
}

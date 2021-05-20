#include <iostream>
#include <vector>

using namespace std;

/**
 * Edited a copy of code for the problem 16
 */
int digit_sum( vector<unsigned char> & n_minus_one, vector<unsigned char> & n_minus_two, int position, char carry_in, int & len) {
	
	char old_value = n_minus_one[ position ];
	n_minus_one[ position ] = n_minus_one[ position ] + n_minus_two[ position ] + carry_in;
	n_minus_two[ position ] = old_value;

	char carry_out = ( n_minus_one[ position ] > 9 ) ? 1 : 0;
	if ( carry_out > 0 ) {
		n_minus_one[ position ] = n_minus_one[ position ] % 10;
		if ( position == len - 1 ) {
			n_minus_one[ ++position ] = 1 ;
			return ++len;
		}
	} else {
		if ( position == len - 1 ) {
			return len;
		}
	}
	//cout << "comes here too" << endl;
	len = digit_sum( n_minus_one, n_minus_two, ++position, carry_out, len );
	return len;
}

int main() {

	int size = 1000;

	vector< unsigned char > n_minus_one( size, 0);
	vector< unsigned char > n_minus_two( size, 0);
	n_minus_one[ 0 ] = 1;
	n_minus_two[ 0 ] = 1;
	int index = 2;
	int len   = 1;
	while( n_minus_one[ 999 ] == 0 ) {
		len = digit_sum( n_minus_one, n_minus_two, 0, 0, len);
		++index;
		//for ( int j = len - 1; j >= 0; j-- )
		//	cout << ( int ) n_minus_one[ j ];
		//cout << endl;
	}
	cout << endl;
	cout << "The required index is " << index << endl;
}

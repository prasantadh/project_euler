#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

int main() {
	vector<int> sum ( 10001, 1 );
	for( int i = 1; i <= 10000; i++)
	{
		for( int j = 2; j <= sqrt( i ) ; j++ ) {
			if ( i % j == 0 )
			   sum[i] += (j + ( ( i/j != j ) ? i/j : 0 ) );
		}
		//cout << i << " => " << sum[ i ] << endl;
	}

	int result = 0;
	for( int i = 1; i <= 10000; i++)
	{
		if ( sum[ sum[i] ] == i && sum[ i ] != i ) {
			result += i;
			cout << i << endl;
		}
	}
	cout << result << endl;
}

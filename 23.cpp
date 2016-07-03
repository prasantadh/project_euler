/**
 * Tony isn't a psychopath.
 * What he is, is a gray area 
 * in a world that does not like gray areas.
 * 				- from a ted talk on psychopaths test
 */
#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

/*
 * modified as a copy of the code for
 * problem 21
 */
int main() {
	/**
	 * Calculate the sum of proper divisors
	 * for each number less than 28124
	 */
	const int size = 28124;
	//const int size = 11;
	vector<int> sum ( size, 1 );
	for( int i = 2; i < sum.size(); i++)
	{
		for( int j = 2; j <= sqrt( i ) ; j++ ) {
			if ( i % j == 0 ) {
				/* REM : if k is a proper divisor, n/k is as well
				 * however, avoid adding square roots twice */
				sum[i] += (j + ( ( i/j != j ) ? i/j : 0 ) ); 
			}
		}
		//cout << i << " => " << sum[ i ] << endl;
	}
	cout << " sum of proper divisors calculated " << endl; 

	/**
	 * Store the abundant numbers
	 */
	vector<int> abundants; int number_of_abundants = 0; 
	for( int i = 2; i < sum.size(); i++)
	{
		if ( sum[ i ] > i ) {
			abundants.push_back(i);
			++number_of_abundants;
		}
	}
	cout << " abundant numbers marked " << endl;

	/**
	 * Mark the sum of abundant numbers
	 */
	vector<bool> sumOabundants ( sum.size(), false );
	int result = 0;
	for( int i = 0; i < number_of_abundants; i++ ) {
		for( int j = i ; j < number_of_abundants; j++) {	
			if ( abundants[ i ] + abundants[ j ] < size ) {
				sumOabundants[ abundants[ i ] + abundants[ j ] ] = true;
			 } else {
				break;
			 } 
		}
	}
	cout << " sum of abundant numbers marked " << endl;
	

	/**
	 * Find the required sum
	 */
	for( int i = 0; i < sum.size(); i++) {
		if ( sumOabundants[ i ] == false )
			result += i;
	}
	cout << result << endl;
}

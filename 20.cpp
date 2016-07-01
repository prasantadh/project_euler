#include <iostream>
#include <vector>

using namespace std;

int digit_product(vector<unsigned int> &product, int position, int carry_in, int len, int multiplier ) {
	int thisProduct = product[position] * multiplier + carry_in;
	product[ position ] = thisProduct % 10;
	if ( thisProduct > 9 ) {
		if ( position==len-1 ) {
			int leftOver = thisProduct / 10;
			while( leftOver != 0) {
				product.push_back( leftOver % 10 );
				leftOver /= 10;
				++len;
			}	
			return len;
		}
	} else{
		if (position==len-1) {
			return len;
		}
	}
	digit_product(product, ++position, thisProduct / 10, len, multiplier);
}

int main() {
	vector<unsigned int> product;
	product.push_back(1);
	int sum = 0;
	int len = 1;
	for(int i = 2; i < 101; i++) {
		len = digit_product(product, 0, 0, len, i);
		/* Print the factorial progressively */
		//cout << i << "! = ";
		//for (int j = len-1; j >= 0; j--)
		//{
			//cout << product[ j ];
		//} cout << endl;
	}

	for (int j = len-1; j >= 0; j--)
	{
		//cout << product[ j ];
		sum += product[j];
	} cout << endl;
	cout << "The required sum of digits of 100! is " << sum << endl;
}

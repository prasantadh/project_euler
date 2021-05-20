#include <iostream>
#include <vector>

using namespace std;

int digit_sum(vector<unsigned char> &product, int position, char carry_in, int len) {
	product[position] = product[position] * 2 + carry_in;
	if (product[position] > 9) {
		product[position] = product[position] % 10;
		if (position==len-1) {
			product.push_back(1);
			++len;
			return len;
		}
		digit_sum(product, ++position, 1, len);
	} else{
		if (position==len-1) {
			return len;
		}
		digit_sum(product, ++position, 0, len);
	}
}

int main() {
	vector<unsigned char> product;
	product.push_back(1);
	int sum = 0;
	int len = 1;
	for(int i = 0; i < 1000; i++) {
		len = digit_sum(product, 0, 0, len);
		// to print the powers of two
		// for (int j = len-1; j >= 0; j--) 
		// 	cout << +product[j];
		// cout << endl;
	}
	for (int j = len-1; j >= 0; j--)
		sum += product[j];
	cout << "The required sum of digits of 2^1000 is " << sum << endl;
}

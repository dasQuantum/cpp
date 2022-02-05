#include<iostream>
#include<cmath>
using namespace std;
int main(void){
	long long n;
	int decimalNumber = 0, i = 0, remainder;
	cout << "Enter a binary number: ";
    	cin >> n;
	long long m = n;
	while (n!=0){
        	remainder = n%10;
        	n /= 10;
        	decimalNumber += remainder*pow(2,i);
        	++i;
	}
	n = m;
	cout << n << " in binary = " << decimalNumber << " in decimal" << endl;
	return 0;
}

#include<iostream>
#include<cmath>
using namespace std;
// This function will give 1 if the entered number is prime
bool prime(int N){
	if(N<=1) return false;
	else if(N==2) return true;
	else{
		int n = (int)sqrt(N);
		int count = 0;
		for(int i = 2; i <= n; i++){
			if(N%i!=0) count++;
			else return false;
		}
		if(count==n-1) return true;
	}
}
int main(void){
	cout << "Prime numbers between 1 and 1000 are: ";
	for(int i = 1; i <= 1000; i++){
		if(prime(i)) cout << i << endl;
	}
	return 0;
}

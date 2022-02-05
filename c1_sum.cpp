#include<iostream>
#include<cmath>
using namespace std;
long s(int N, int k){
	long res = 0;
	for(int i = 1; i <= N; i++){
		res += pow(i,k);
	}
	return res;
}
int main(){
	// Part - 1
	cout << "Comparing with known result: ";
	int N = 10, k =1;
	cout << "\nFor N = " << N << endl << endl;
	cout << "for k = " << k;
	cout << ". LHS = " << N*(N+1)/2.0 << ". RHS = " << s(N,k) << endl;
	cout << endl;
	k = 2;
	cout << "for k = " << k;
	cout << ". LHS = "<<N*(N+1)*(2*N+1)/6.0<<". RHS = "<< s(N,k)<< endl;

	// Part - 2
	cout << "Give a large value of N: ";
	cin >> N;
	for(k = -10; k<=10; k++){
		cout << "k = " << k << " sum = " << s(N,k) << endl;
	}
	return 0;
}

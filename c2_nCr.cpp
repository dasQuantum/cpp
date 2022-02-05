#include<iostream>
using namespace std;
// Factorial Function
long int f(int n){
	if(n==0)return 1;
	else return n*f(n-1);
}

// Combination function
int nCr(int n, int r){
	return f(n)/(f(r)*f(n-r));
}

// power of -1 function
int p(int r){
	if(r%2 == 0) return 1;
	else return -1;
}

// Summation function
int S(int N){
	int res = 0;
	for(int r = 0; r<=N; r++){
		res += p(r)*nCr(N,r);
	}
	return res;
}
int main(){
	cout << "Lets see the dependancy of sum on N: " << endl;
	for(int N = 10; N<=20; N++){
		cout << N << "\t" << S(N) << endl;
	}
	cout << "So we see that value of sum does not depend on N." << endl;
	return 0;
}

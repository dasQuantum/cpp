#include<iostream>
using namespace std;
// subroutine for fibonacci numbers
long f(int n){
	if(n==0 || n==1) return n;
	else return f(n-1)+f(n-2);
}
int main(void){
	int N = 20;
	cout << "First " << N << " elements of fibo. seq. are: \n";
	cout << "1st element = " << f(0) << endl;
	for(int i = 1; i <= N; i++){
		cout << i+1 << " th number = ";
		cout << f(i) << " ratio = " << 1.0*f(i+1)/f(i) << endl;
	}
	return 0;
}

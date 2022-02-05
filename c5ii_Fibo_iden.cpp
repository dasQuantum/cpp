#include<iostream>
using namespace std;
// subroutine for fibonacci numbers
long f(int n){
	if(n==0 || n==1) return n;
	else return f(n-1)+f(n-2);
}
int main(void){
	int N = 20;
	long F_sum = 0;
	for(int i = 0; i <= N; i++){
		F_sum += f(i)*f(i);
	}
	cout << "Lets check the identity for N = "<< N << endl;
	cout << "LHS = " << F_sum << "\t";
	cout << "RHS = " << f(N)*f(N+1) << endl;
	return 0;
}

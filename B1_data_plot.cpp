/* 1. Consider the functions: ψ1 (x) = 5sin(x), ψ2 (x) = 5sin(2x), ψ3 (x) =
5sin(3x), ψ(x) = ψ1 (x)+ψ2 (x)+ψ3 (x). Write a C++ program to tabulate
the values of ψ1 (x), ψ2 (x), ψ3 (x) and ψ(x) at intervals of 0.01 for 0 ≤ x ≤
6.3 and plot using Gnuplot.
*/
#include<iostream>
#include<cmath>
#include<fstream>

using namespace std;
void s(float *x, float *r1, float *r2, float *r3, float *r) {
	*r1 = 5*sin(*x);
	*r2 = 5*sin(2*(*x));
	*r3 = 5*sin(3*(*x));
	*r = *r1 + *r2 + *r3;
	}
int main(){
	cout << "Tabulated values of required data: " << endl;
	cout << "x\t5sin(x)\t5sin(2x)\t5sin(3x)\ttotal" << endl;
	for(float i = 0; i <= 6.3; i += 0.01) {
		float r1, r2, r3, r;
		float s(float*, float*, float*, float*, float*);
		s(&i, &r1, &r2, &r3, &r);
		cout <<i<<"\t"<<r1<<"\t"<<r2<<"\t"<<r3<<"\t"<<r<<endl;
	}
	return 0;	
}

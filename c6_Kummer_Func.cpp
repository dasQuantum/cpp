#include<iostream>
#include<fstream>
#include<cmath>
using namespace std;
float M(float a, float b, float x){
	float acc=0.0001,term = 1,sum = 1; // acc = accuracy
	int n = 0;
	while(term>acc){
		term *= x*(a+n)/(b+n);
		sum += term;
		n++;
		}
	return sum;
	}
float f(float a, float b, float x){
	return M(a,b,x)-exp(-x)*M(b-a,b,-x);
	}
int main(void){
	float a,b;
	// Part-1
	a = 1; b = 2;
	cout << "Kummer Function of a>0, b>a, and x=1 is M(1,2,1) = " << M(a,b,1) << endl;

	// Part-2
	a = 1; b = 2;
	cout << "Now lets check the given relation in the range of x [-1,1]: " << endl;
	for(float x = -1; x <= 1; x+=0.001){
		cout << x << "\t" << f(a,b,x) << endl;
		}

	// Part-3 (for plotting)
	a = 1; b = 2;
	for(float x = -1; x <= 1; x+=0.001){
		cout << x << "\t" << M(a,b,x) << endl;
		}
	return 0;
	}

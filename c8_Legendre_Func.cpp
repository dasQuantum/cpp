#include<iostream>
#include<fstream>
using namespace std;
float P(float n, float x) { //Legendre Function
	if ( n == 0 ) { 
		return 1;
		}
	else if ( n == 1 ) {
		return x;
		}
	else {
		return ((2*n-1)*x*P(n-1,x)-(n-1)*P(n-2,x))/n;
		}
	}
int main(){
	float a = -1, b = 1, s; //a = start, b = end, s = separation between any 2 points
	int N = 20; //Number of points
	s = (b-a)/N;
	int nu = 5; // Order of Function
	for(float i = a; i <= b; i += s) {
		cout << i << "\t" << P(nu,i) << endl ;
		}
	return 0;
	}

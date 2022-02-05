#include<iostream>
#include<fstream>
#include<cmath>
using namespace std;
float G(float n) {	// Gamma Function
    if(n==1) return 1;
    else return (n-1)*G(n-1);
    }
float J(int nu, float error, float x) {	// Bessel Function
    float res = 0, er = 1, term, i=1;
    term = 1/G(nu+1);
    while ( er > error ) {
        term *= (-x*x/4)/(i*(nu+i));
        res += term;
		er = term;
        }
    res *= pow(x/2,nu);
    return res;
    }
int main() {
	float error = 0.0001; // Accuracy
	int N = 20; // Number of points for plotting
	float a = -1, b = 1, s = (b-a)/N; // a = start, b = end, s = separation between 2 points
	int nu = 1; //Order of Bessel Function

	for( float i = a; i <= b; i += s) {
		cout << i << "\t" << J(nu,error,i) << endl ;
		}
	return 0;
}

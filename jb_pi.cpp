#include<iostream>
#include<ctime>
#include<cstdlib>
#include<cmath>
using namespace std;
int main(void){
	srand(time(NULL));
	float r = 5; // Radious
	int N = 10000; // Number of random points
	float x,y;
	int Np = 0; // number of points inside the circle
	for(int i = 1; i <= N; i++){
		x = r*rand()/RAND_MAX;
		y = r*rand()/RAND_MAX;
		// Checking if the point is inside the circle
		if(x*x + y*y <= r*r){
			Np++;

			// if we want to see the points in the circle
			// cout << x << "\t" << y << endl;
		}
	}
	float area = 4*(1.0*Np/N)*r*r;
	//cout << "Area of the given circle is = " << area << endl;
	float pi;
	pi = area/(r*r); 
	cout << "The calculated value of pi = " << pi << endl;
	cout << "From cmath lib value of pi = " << M_PI << endl;
	return 0;
}

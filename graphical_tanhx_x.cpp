#include<iostream>
#include<cmath>
using namespace std;
float tnhx(float x){
	return (exp(x)-exp(-x))/(exp(x)+exp(-x));
}
int main(void){
	float a = -2*M_PI, b = 2*M_PI; 
	// range in which we will find the solution [a,b];

	// change a,b,lambda as you wish	
	float lambda = 0.5;
	for(float i = a; i <= b; i+=0.001){
		// if you can plot the function differently they will meet at some
		// common points those are the solutions, but in moodle as you can't
		// plot two graphs simultenously, so we plotting the whole function
		// and watching if they are zero anywhere.
		cout << i << "\t" << tnhx(lambda*i)-i << endl;
	}

	// the points that are cutting x-axis are the solutions
	return 0;
}

#include<iostream>
#include<cmath>
using namespace std;
// exp
float ex(float x){
	float term = 1, sum = 1;
	float tola = 0.0001;
	int i = 1;
	while(abs(term)>tola){
		term *= x/i;
		sum += term;	
		i++;
	}
	return sum;
}
// cosine
float cose(float x){
	float term = 1, sum = 1;
	float tola = 0.0001;
	int i = 1;
	while(abs(term)>tola){
		term *= (-1)*x*x/(2*i*(2*i-1));
		sum += term;
		i++;
	}
	return sum;
} 
// sine
float sine(float x){
	float term = x, sum = x;
	float tola = 0.0001;
	int i = 1;
	while(abs(term)>tola){
		term *= (-1)*x*x/(2*i*(2*i+1));
		sum += term;
		i++;
	}
	return sum;
}
// tanh
float tanhx(float x){
	float sinhx = (ex(x)-ex(-x))/2;
	float coshx = (ex(x)+ex(-x))/2;
	return sinhx/coshx;
} 
int main(void){
	for(float x = -10; x <= 10; x+= 0.01){
		//cout << x << "\t" << ex(x) << endl;
		//cout << x << "\t" << cose(x) << endl;
		//cout << x << "\t" << sine(x) << endl;
		cout << x << "\t" << tanhx(x) << endl;
	}
	return 0;
}

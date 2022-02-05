#include<iostream>
#include<cmath>
#define h_cut 1 //6.626*pow(10,-26)

using namespace std;
long fact(int n){
	if(n==0) return 1;
	else return n*fact(n-1);
}
float H(int n, float x){
	if(n==0)return 1;
	else if(n==1)return 2*x;
	else return 2*x*H(n-1,x)-2*(n-1)*H(n-2,x);
}
float psi(float x, int n, float m, float w){
	float a = (1.0/sqrt(pow(2,n)*fact(n)))*pow(m*w/(M_PI*h_cut),1/4.0);
	return a*exp(-m*w*x*x/(2*h_cut))*H(n,sqrt(m*w/h_cut)*x);
}
int main(void){
	int n = 1;
	float m = 10, w = 0.1;
	for(float x = 0; x <= m; x+=0.01){
		cout << x << "\t" << psi(x,n,m,w) << endl;
	}
	return 0;
}	

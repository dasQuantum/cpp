#include<iostream>
#include<cmath>
using namespace std;
int main(void){
	float Ax,Ay,fx,fy,phi;
	// Part - 1;
	Ax = 10; Ay = 10; fx = 5; fy = 6; phi = 45;
	phi *= M_PI/180;
	for(float t = 0; t<=10; t+=0.01){
		cout<<Ax*cos(2*fx*t)<<"\t"<< Ay*sin(2*fy*t+phi) << endl;
	}

	// Part - 2
	fx = 3.5; fy = 3.6;
	for(float t = 0; t<=10; t+=0.01){
		cout<<Ax*cos(2*fx*t)+Ay*sin(2*fy*t+phi)<<"\t"<< t << endl;
	}

	return 0;
}

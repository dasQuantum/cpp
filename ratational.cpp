#include<iostream>
#include<cmath>
using namespace std;
// put component = 1, for x component; 2 for y; 3 for z
float a_component(float t, int component){
	// The matrix that rotates a vector to t radian
	float p[3][3];
	p[0][0] = 1; p[0][1] = 0;	p[0][2] = 0;
	p[1][0] = 0; p[1][1] = cos(t);	p[1][2] = sin(t);
	p[2][0] = 0; p[2][1] = -sin(t); p[2][2] = cos(t);

	// The vector that has to be rotated
	float a[3][1];
	a[0][0] = 2; a[1][0] = 1; a[2][0] = 2;

	// Calculation
	float a_com[3][1];
	for(int i = 0; i < 3; i++){
		for(int j = 0 ; j < 1; j++){
			a_com[i][j] = 0;
			for(int k = 0; k < 3; k++){
				a_com[i][j] += p[i][k]*a[k][j];
			}
		}
	}
	return a_com[component-1][0];
}
int main(void){
	for(float t = 0; t <= M_PI; t+=0.001){
		cout << t << "\t" << a_component(t,2) << endl;
	}
	return 0;
}

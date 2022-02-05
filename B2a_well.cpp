/* 2. Wave-functions of a quantum particle: Write a program in C++ to
tabulate the values at equal intervals of the first three normalized eigen-
states ψn (x), n = 1, 2, 3 of a particle moving in (a) an infinite square well
potential and (b) a simple harmonic oscillator potential. Parameters like
mass(m) of the particle, angular frequency(ω) of the oscillator, length(L)
of the well etc. may be taken as inputs.
Plot ψn (x) vs. x and study how ψn (x) changes with varying (i) m, (ii) L
and (iii) ω.
*/
#include<iostream>
#include<fstream>
#include<cmath>
using namespace std;
float psi(float x, int n, float L){
	if(n%2==0) return sqrt(2/L)*sin(n*M_PI*x/L);
	else return sqrt(2/L)*cos(n*M_PI*x/L);
}
int main(void){
	ofstream out("psi.dat");
	int n = 3;
	float L = 10;
	for(float x = -L/2; x <= L/2; x+=0.01){
		out << x << "\t" << psi(x,n,L) << endl;
	}
	return 0;
}	

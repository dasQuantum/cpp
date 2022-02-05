#include<iostream>
#include<cmath>
using namespace std;
typedef struct{
	float x,y;
}com;
// Amplitude calculation
float amp(com c){
	return sqrt(c.x*c.x + c.y*c.y);
}
// Phase calculation
float ph(com c){
	float s = atan(abs(c.y/c.x));
	if(c.x==0){
		if(c.y>0){ return M_PI/2;}
		else if(c.y<0){return 3*M_PI/2;}
	}
	else if(c.x>0 && c.y>=0){ return s;}
	else if(c.x<0 && c.y>=0){ return M_PI-s;}
	else if(c.x<0 && c.y<=0){ return M_PI+s;}
	else if(c.x>0 && c.y<=0){ return 2*M_PI-s;}
}
// sqrt calculation
com root(com c){
	com c1;
	c1.x = sqrt(amp(c))*cos(ph(c)/2);
	c1.y = sqrt(amp(c))*sin(ph(c)/2);
	return c1;
}
// nth root calculation
com nroot(com c, int n, int k){
	com res;
	res.x = pow(amp(c),1.0/n)*cos(ph(c)/n+2*M_PI*1.0*k/n);
	res.y = pow(amp(c),1.0/n)*sin(ph(c)/n+2*M_PI*1.0*k/n);
	return res;
}
// show function
void show(com c){
	cout << c.x;
	if(c.y>=0) cout << "+" << c.y << "i ";
	else cout << c.y << "i ";
}
// multiplication function
com mul(com c, com rc){
	com r;
	r.x = rc.x*rc.x - rc.y*rc.y;
	r.y = 2*rc.x*rc.y;
	return r;
}

int main(void){
	com c;
	cout << "Give the real and ima. parts of a complex number: ";
	cin >> c.x >> c.y ;
	com rc = root(c);
	cout << "The given complex nubmer is: ";
	show(c);
	cout << "Phase is = " << ph(c)*180/M_PI << endl;
	
	// Square root
	cout << endl << "its square root is: ";
	show(rc);
	cout << endl << "Lets check if it is correct: ";
	show(mul(rc,rc));
	cout << endl;

	// Nth root
	cout << "\nGive one integer: ";
	int N; // Give N = 3 for cube root
	cin >> N;
	cout << "Given complex number is: "; show(c);
	cout << "\nIts " << N << " roots are: " << endl;
	for(int k = 0; k < N; k++){
		com rt = nroot(c,N,k);
		cout << k+1 << "No. Root = ";show(rt);
		cout << endl;
	}
	cout << endl;
	return 0;
}

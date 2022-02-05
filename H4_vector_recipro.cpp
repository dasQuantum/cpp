#include<iostream>
#include<cmath>
using namespace std;
typedef struct{
	float x,y,z;
}vec;
vec add(vec u, vec v){
	vec w;
	w.x = u.x + v.x;
	w.y = u.y + v.y;
	w.z = u.z + v.z;
	return w;
}
vec cross(vec u, vec v){
	vec w;
	w.x = u.y*v.z - u.z*v.y;
	w.y = u.z*v.x - u.x*v.z;
	w.z = u.x*v.y - u.y*v.x;	
	return w;
}
float dot(vec u, vec v){
	return u.x*v.x+u.y*v.y+u.z*v.z;
}
// Scalar multiplication of vector
vec sc_mul(float m, vec u){
	vec v;
	v.x = u.x*m;
	v.y = u.y*m;
	v.z = u.z*m;
	return v;
}
// Magnitude
float magni(vec u){
	return sqrt(u.x*u.x+u.y*u.y+u.z*u.z);
}
// Direction cosine
float al(vec u){
	return u.x/magni(u);
}
float bt(vec u){
	return u.y/magni(u);
}
float gm(vec u){
	return u.z/magni(u);
}

void show(vec v){
	cout << v.x << "i";
	if(v.y>=0) cout << "+" << v.y << "j";
	else cout << v.y << "j";
	if(v.z>=0) cout << "+" << v.z << "k";
	else cout << v.z << "k";
}
int main(void){
	vec A,B,C;
	// Components' input
	A.x = 1; A.y = 0; A.z = 0;
	B.x = 0; B.y = 1; B.z = 0;
	C.x = 0; C.y = 0; C.z = 1;
	
	cout << "Three given vectors are: " << endl;
	cout << "\tA = "; show(A); cout << endl;
	cout << "\tB = "; show(B); cout << endl;
	cout << "\tC = "; show(C); cout << endl;
	cout << "Their reciprocal vectors are: " << endl;

	vec t1, t2, t3;
	// calculating BxC, CxA, AxB
	t1 = cross(B,C);
	t2 = cross(C,A);
	t3 = cross(A,B);
	
	float s;
	// calculating A.(BxC)
	s = dot(A,cross(B,C));
	s = 2*M_PI*s; // multiplying 2Pi;

	vec a,b,c;
	// calculating reci. vectors	
	a = sc_mul(1/s,t1);
	b = sc_mul(1/s,t2);
	c = sc_mul(1/s,t3);
	cout << "\ta = "; show(a); cout << endl;
	cout << "\tb = "; show(b); cout << endl;
	cout << "\tc = "; show(c); cout << endl; 
	return 0;
}

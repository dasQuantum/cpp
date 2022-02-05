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
	cout << "Their vector tripple product is Ax(BxC): ";

	vec t; // for vector tripple product
	// calculating Ax(BxC)
	t = cross(A,cross(B,C));
	show(t); cout << endl;
	
	cout << "Their scalar tripple product is A.(BxC): ";
	float s; // for scalar tripple product
	// calculating A.(BxC)
	s = dot(A,cross(B,C));
	cout << s << endl;

	cout << "\nSome other calculations: " << endl;
	// Other calculations:
	cout << "(1) Direction cosines of vec A: " << endl;
	cout << "\talpha = "<< al(A) << " Ang = " << acos(al(A))*180/M_PI << endl;
	cout << "\tbeta = " << bt(A) << " Ang = " << acos(bt(A))*180/M_PI << endl;
	cout << "\tgamma = "<< gm(A) << " Ang = " << acos(gm(A))*180/M_PI << endl;

	cout << "(2) Magnitude of vec A: " << magni(A) << endl;

	cout << "(3) Unit vector of A: "; 
	vec b;
	b = sc_mul(1.0/magni(B),B);
	show(b);
	cout << endl;

	cout << "(4) SCALAR Projection of vec A on vec B: ";
	float s_p;
	s_p = dot(A,B)/magni(B);
	cout << s_p << endl;

	cout << "(5) VECTOR Projection of vec A on vec B: ";
	vec Pro_A_B;
	Pro_A_B = sc_mul(s_p, b); // s_p = scalar projection,b = B unit vec
	show(Pro_A_B);
	cout << endl;
	
	return 0;
}

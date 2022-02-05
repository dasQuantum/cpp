/* 1. Write a C++ program to evaluate the sum, difference and product of two
given complex numbers.
*/
#include<iostream>
#include<fstream>
using namespace std;
typedef struct{
	float re;
	float im;
	}com;
void show_com(com a){
	// change this function as you wish with if_else
	cout << a.re << "+i(" << a.im << ")" ;
	}

int main(){
	com a,b,add,sub,prdt;
	cout << "Give a complex number : ";
	cin >> a.re >> a.im;
	cout << "GIve another complex number: ";
	cin >> b.re >> b.im ;
	
	add.re = a.re + b.re;
	add.im = a.im + b.im;
	
	sub.re = a.re - b.re;
	sub.im = a.im - b.im;

	prdt.re = a.re*b.re - a.im*b.im;
	prdt.im = a.re*b.im + b.re*a.im;
	
	cout << "Multiplication res: ";
	show_com(a);	
	cout << " X " ;
	show_com(b);
	cout << " = ";
	show_com(prdt);
	cout << endl ;
	return 0;
	}

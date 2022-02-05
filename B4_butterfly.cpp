// 4. Butterfly curve: Write a program in C++ to tabulate the values of X(t) and Y (t):
// X(t) = r(t)cost(t), Y (t) = r(t)sin(t), r(t) = ecos(t) − 2cos(4t) + sin5 (t/12)
// at the equally spaced time-intervals ∆t for −T ≤ t ≤ T , where ∆t and T are to be 
// treated as inputs. Plot X(t) vs. Y (t).
#include<iostream>
#include<cmath>
#include<fstream>
using namespace std;
float r(float t) {
	return exp(cos(t))-2*cos(4*t)+pow(sin(t/12),5);
	}
float x(float t) {
	return r(t)*cos(t);
	}
float y(float t) {
	return r(t)*sin(t);
	}
int main() {
	float dt = 0.01, t;
	cout << "Give t = " ;
	cin >> t ;
	for(float i = -1*t; i <= t; i+=dt) {
		cout << x(i) << "\t" << y(i) << endl ;
		}
	return 0 ;
	}

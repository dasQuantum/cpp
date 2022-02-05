#include<iostream>
using namespace std;
int main(void){
	int x,y,z,N = 10;
	cout << "Solutions upto " << N <<" : " << endl;
	cout << "x\ty\tz" << endl;
	for(x = 1; x <= N; x++){
		for(y = 1; y <= N; y++){
			for(z = 1; z <= N; z++){
				if(x*x + y*y == z*z){
					cout << x << "\t" << y << "\t" << z;
					cout << endl;
				}
			}
		}
	}
	return 0;
}

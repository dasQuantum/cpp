#include<iostream>
#include<cstdlib>
#include<ctime>
#include<cmath>
using namespace std;
int main(){
	int N = 1000; // Number of iteration
	float X_0, X, r = (float)RAND_MAX ;
	srand(time(NULL));
	int M = 100; //Number of diff. values of X0
	for(float L = 1; L <= 4; L+= 0.001){
		float res = 0;
		for(int i = 0; i < M; i++){
			X_0 = rand()/r;
			X = X_0;
			//cout << X_0 << endl;
			for(int j = 1; j <= N; j++){
				X = L*X*(1-X);
				}
			cout << L << "\t" << X << endl;
			}
		}
	return 0;
	}

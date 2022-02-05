// Random walk in qubic lattice
#include<iostream>
#include<cstdlib>
#include<ctime>
using namespace std;

int main(){
	srand(time(NULL));
	int x=0,y=0,s;
	float ax=10, ay=10; // lattice dimention x-->(10,-10), y-->(10,-10)
	float r=(float)RAND_MAX,des;
	int N = 1000; // Number of steps
	for(int i = 1; i <= N; i++){
		cout << x << "\t" << y << endl;
		des = rand()/r;
		if(des <= 0.5){
			if(rand()/r <= 0.5) s = 1;
			else s = -1;
			x = x + s;
			if(x < -ax || x > ax) {
				if(rand()/r <= 0.5) x -= 2*s;
				else x -= s;
				}
			}
		else{
			if(rand()/r <= 0.5) s = 1;
			else s = -1;
			y = y + s;
			if(y < -ay || y > ay) {
				if(rand()/r <= 0.5) y -= 2*s;
				else y -= s;
				}
			}
		}
	return 0;
	}

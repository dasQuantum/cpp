// Random walk in qubic lattice
#include<iostream>
#include<cstdlib>
#include<ctime>
using namespace std;

int main(){
	srand(time(NULL));
	int x=0,y=0,z=0,s;
	float ax=10, ay=10, az=10, r=(float)RAND_MAX,des;

	for(int i = 1; i <= 1000; i++){
		cout << x << "\t" << y << "\t" << z << endl;
		des = rand()/r;
		if(des <= 0.33){
			if(rand()/r <= 0.5) s = 1;
			else s = -1;
			x = x + s;
			if(x < -ax || x > ax) {
				if(rand()/r <= 0.5) x -= 2*s;
				else x -= s;
				}
			}
		else if(des > 0.33 && des <= 0.66){
			if(rand()/r <= 0.5) s = 1;
			else s = -1;
			y = y + s;
			if(y < -ay || y > ay) {
				if(rand()/r <= 0.5) y -= 2*s;
				else y -= s;
				}
			}
		else if(des > 0.66 && des <= 0.99){
			if(rand()/r <= 0.5) s = 1;
			else s = -1;
			z = z + s;
			if(z < -az || z > az) {
				if(rand()/r <= 0.5) z -= 2*s;
				else z -= s;
				}
			}
		}
	return 0;
	}

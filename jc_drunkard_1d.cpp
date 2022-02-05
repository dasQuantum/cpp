#include<iostream>
#include<ctime>
#include<cstdlib>
using namespace std;
int main(void){
	srand(time(NULL));
	int N = 1000; // Number of steps;
	int x = 0; // Initial position
	float n,p = 0.5; // Probability of moving forward; 
	for(int i = 1; i <= N; i++){
		n = 1.0*rand()/RAND_MAX;
		if(n<=p) x++;
		else x--;
		cout << i << "\t" << x << endl;
	}
	return 0;
}

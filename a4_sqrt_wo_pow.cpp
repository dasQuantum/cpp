#include<iostream>
using namespace std;
int main(void){
	float N ;
	cout << "Give the number: ";
	cin >> N;
	
	int count = 0;
	float ans, sum = 0, tola = 0.001;
	while(sum < N){
		sum += 2*count+1;
		count++;
	}
	count--;

	ans = count;
	while(ans*ans < N){
		ans+=tola;
	}

	cout << "Square root of " << N << " is " << ans << endl;
	return 0;
}

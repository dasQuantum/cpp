#include<iostream>
using namespace std;
int main(void){
	int N;
	cout << "How many data: ";
	cin >> N;

	int a[N];

	cout << "Give the data now: ";
	for(int i = 0; i< N; i++){
		cin >> a[i];
	}

	int max = a[0], min = a[0];
	for(int i = 0; i < N; i++){
		if(a[i] > max) max = a[i];

		if(a[i] < min) min = a[i];
	}

	cout << "Minimum = " << min << endl;
	cout << "Maximum = " << max << endl;
	return 0;
}

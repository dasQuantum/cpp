#include<iostream>
using namespace std;
int main(void){
	int N;
	cout << "How many students are there: ";
	cin >> N;

	float marks[N];
	float sum = 0;
	cout << "Enter there marks one by one: ";
	for(int i = 0; i < N; i++){
		cin >> marks[i];
		sum += marks[i];
	}
	float avg_marks = sum/N;
	cout << "Avg marks of class = " << avg_marks << endl;
	
	int count = 0;
	for(int i = 0; i< N; i++){
		if(marks[i]>avg_marks) count++;
	}
	cout << "Number of students who scored more than above avg = ";
	cout <<  count << endl;
	return 0;
}



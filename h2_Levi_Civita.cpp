// Nth order Levi_Civita Symbol
#include<iostream>
using namespace std;
int next(int i, int n){
	if(i==n) return 1;
	else return i+1;
}
int bef(int i, int n){
	if(i==1) return n;
	else return i-1;
}
int main(){
	int N = 10;
	int epl[N];
	int cc = 0, ca = 0, cb = 0;
	for(

/*2. Write a C programme to implement the d ≥ 2 dimensional Levi-Civita
tensor
*/
#include<iostream>
using namespace std;
int nxt(int i, int n){
	if(i == n) return 1;
	else return i+1;
	}
int bfr(int i, int n){
	if(i == 1) return n;
	else return i-1;
	}
int main(){
	int n = 3;
	int lvcv[n];
	cout << "give the order : ";
	cin >> n;	
	cout << "Give input for levi civita symbol: ";
	for(int i = 0; i < n; i++){
		cin >> lvcv[i];
		}
	
	//Result
	int c_cyl = 0, c_ant = 0;
	for(int i = 1; i < n; i++){
		if(lvcv[i] == nxt(lvcv[i-1],n)) c_cyl ++;
		else if(lvcv[i] == bfr(lvcv[i-1],n)) c_ant ++;
		}
	int result;
	if( c_cyl == n-1 ) result = 1;
	else if (c_ant == n-1) result = -1;
	else result = 0;

	//Out put
	cout << "E( ";
	for(int i = 0; i < n; i++){
		cout << lvcv[i] << " " ;
		}
	cout << ") = " << result << endl;
	return 0;
	}	

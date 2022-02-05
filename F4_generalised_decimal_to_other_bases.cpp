#include <iostream> 
using namespace std;  
int main(){
	int a[10], n, i;
	cout<<"Enter the number to convert: ";
	cin>>n;
	int base;
	cout << "Enter the base: ";
	cin >> base;
	for(i=0; n>0; i++){
		a[i] = n%base;
		n = n/base;
	}
	cout<<"conversion of the given number in base(" << base <<") = ";
	for(i=i-1; i>=0; i--){
		cout<<a[i];
	}
	cout << endl;
	return 0;
}

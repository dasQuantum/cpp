#include<iostream>
using namespace std;
int main(void){
	int i,j,n;
	cout << "How many numbers: ";
	cin >> n;
	float tmp,a[n];
	cout<<"Enter " << n <<" numbers:\n";
	for(i=0;i<n;i++){
		cin>>a[i];
	}

	for(i=0;i<n;i++){
		for(j=i+1;j<n;j++){
			if(a[i]<a[j]){
				tmp=a[i];
				a[i]=a[j];
				a[j]=tmp;
			}
		}
	}
	cout<<"The numbers in asc. order: ";

	for(i=0;i<n;i++){
		cout<<a[i]<<"\t";
	}
	cout << endl;

	cout << "The numbers is dsc. order: ";
	for(i=n-1;i>=0;i--){
		cout << a[i] << "\t";
	}
	cout<<endl;
}

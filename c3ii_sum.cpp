#include<iostream>
using namespace std;
int main(void){
	int i, j, k, N;
	double sum=0;
	cout<<"Enter the range of the series (N) = ";
	cin>>N;
	for(i=1;i<=N;i++){
		for(j=1;j<=N;j++){
			for(k=1;k<=N;k++){
				if(i!=j && j!=k && k!=i){
					sum=sum+((i+j+k)/((i-j)*(j-k)));
				}
			}
		}
	}
	cout<<"Result = "<<sum<<endl;
}

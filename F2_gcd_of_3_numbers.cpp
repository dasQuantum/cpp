#include <iostream>
using namespace std;
int g_num(int a, int b, int c){
	if(a>=b && a>=c){
		return a;
	}
	else if(b>=a && b>=c){
		return b;
	}
	else if(c>=a && c>=b){
		return c;
	}
}

int main(){
	int a,b,c;
	cout << "Enter three integers: ";
	cin >> a >> b >> c;
	int res;

	for(res=g_num(a,b,c); res>=1; res--){
		if(a%res == 0 && b%res == 0 && c%res ==0) break;
	}
	cout << "GCD of the given numbers is " << res << endl;
	return 0;
}

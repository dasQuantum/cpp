#include<iostream>
#include<cstdlib>
#include<ctime>
using namespace std;
// Subroutine for coin tossing event
float toss(){
	return 1.0*rand()/RAND_MAX;
} // we will use it later	

int main(void){
	srand(time(NULL));
	int N = 10; // Number of tossing
	int res[N]; // To store the result of the tossing

	float t; 
	for(int i = 0; i < N; i++){
		t = toss();

		// if the output >= 0.5, consider it 'head' or 1
		// if the output < 0.5, consider it 'tell' or 0
		if(t>=0.5) res[i] = 1;
		else res[i] = 0;
	}
	// Part-1
	cout << "The tossing result sequence is: " << endl;
	for(int i = 0; i < N; i++){
		cout << res[i] << "\t";
	}
	cout << endl;
	
	// Part-2 (Identifying the longest sequence)
	cout << "Now identifying longest seq: " << endl;
	int h_sq[N][2], t_sq[N][2];
	int j = 0, k = 0;
	if(res[0]==1){
		j = 0;
		h_sq[0][0] = 0; h_sq[0][1] = 1;
		// checking for 'head' sequ.
		for(int i = 1; i < N; i++){
			if(res[i]==1){
				if(res[i-1]==res[i]){
					h_sq[j][1]++;
				}
				else{
					j++;
					h_sq[j][0] = i; h_sq[j][1] = 1;
				}
			}
		}

		int g = h_sq[0][1];
		k = 0;
		t_sq[0][0] = g; t_sq[0][1] = 1;
		// checking for 'tell' sequ.
		for(int i = g+1; i < N; i++){
			if(res[i]==0){
				if(res[i-1]==res[i]){
					t_sq[k][1]++;
				}
				else{
					k++;
					t_sq[k][0] = i; t_sq[k][1] = 1;
				}
			}
		}
		
		
	}
	else{
		k = 0;
		t_sq[0][0] = 0; t_sq[0][1] = 1;
		// checking for 'tell' sequ.
		for(int i = 1; i < N; i++){
			if(res[i]==0){
				if(res[i-1]==res[i]){
					t_sq[k][1]++;
				}
				else{
					k++;
					t_sq[k][0] = i; t_sq[k][1] = 1;
				}
			}
		}

		int g = t_sq[0][1];
		j = 0;
		h_sq[0][0] = g; h_sq[0][1] = 1;
		// checking for 'head' sequ.
		for(int i = g+1; i < N; i++){
			if(res[i]==1){
				if(res[i-1]==res[i]){
					h_sq[j][1]++;
				}
				else{
					j++;
					h_sq[j][0] = i; h_sq[j][1] = 1;
				}
			}
		}
	}
	// calculating longest seq
	// head
	int max[2];
	max[1] = h_sq[0][1];
	for(int i = 0; i <= j; i++){
		if(h_sq[i][1]>=max[1]){
			max[0] = h_sq[i][0];
			max[1] = h_sq[i][1];
		}
	}
	cout << "Longest head seq starts at " << max[0]+1 << " th toss\n";
	cout << "its length is = " << max[1] << endl;

	// tell
	max[1] = t_sq[0][1];
	for(int i = 0; i <= k; i++){
		if(t_sq[i][1]>=max[1]){
			max[0] = t_sq[i][0];
			max[1] = t_sq[i][1];
		}
	}
	cout << "Longest tell seq starts at " << max[0]+1 << " th toss\n";
	cout << "its length is = " << max[1] << endl;


	// Part-3
	int nh = 0, nt = 0;
	for(int i = 0; i < N; i++){
		if(res[i] == 1) nh++;
		else nt++;
	}
	cout << "Number of total head = " << nh << endl;
	cout << "Number of total tell = " << nt << endl;

	// Part-4
	int hh = 0, tt = 0, ht = 0;
	float t1, t2;
	cout << "Seq. for double coin tossing : ";
	for(int i = 0; i < N; i++){
		t1 = toss(); t2 = toss();
		if(t1>=0.5 && t2>=0.5) {
			hh++;
			cout << "HH" << "\t";
		}
		if(t1>=0.5 && t2<0.5 ) {
			ht++;
			cout << "HT" << "\t";
		}
		if(t1<0.5  && t2>=0.5) {
			ht++;
			cout << "TH" << "\t";
		}
		if(t1<0.5  && t2<0.5 ) {
			tt++;
			cout << "TT" << "\t";
		}
	}
	cout << endl;
	return 0;
}

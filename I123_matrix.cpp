#include<iostream>
#include<cmath>
using namespace std;

// matrix class
template <class T1> class matrix{
	private:
		int r,c;
		T1 ele[10][10];

	public:
		matrix(int a, int b){
			r = a; c = b;
		}
		matrix(){;}

		// Add of two matrixs
		friend matrix operator +(matrix A, matrix B){
			matrix C;
			if(A.r == B.r && A.c == B.c){
				C.r = A.r; C.c = A.c;
				for(int i = 0; i < C.r; i++){
					for(int j = 0; j < C.c; j++){
						C.ele[i][j] = A.ele[i][j]+ B.ele[i][j];
					}
				}
				return C;
			}
			else{
				cout << "Dim mismatch" << endl;
			}
		}

		// Sub of two matrixs
		friend matrix operator -(matrix A, matrix B){
			matrix C;
			if(A.r == B.r && A.c == B.c){
				C.r = A.r; C.c = A.c;
				for(int i = 0; i < C.r; i++){
					for(int j = 0; j < C.c; j++){
						C.ele[i][j] = A.ele[i][j]-B.ele[i][j];
					}
				}
				return C;
			}
		}
		// Mult of two matrixs
		friend matrix operator *(matrix A, matrix B){
			matrix C;
			if(A.c == B.r){
				C.r = A.r; C.c = B.c;
				for(int i = 0; i < C.r; i++){
					for(int j = 0; j < C.c; j++){
						C.ele[i][j] = 0;
						for(int k = 0; k < A.c; k++){
							C.ele[i][j] += A.ele[i][k]*B.ele[k][j];
						}
					}
				}
				return C;
			}
		}
		// Overloading >>
		friend istream &operator >>(istream &bhoot, matrix &A){
			for(int i = 0; i < A.r; i++){
				for(int j = 0; j < A.c; j++){
					bhoot >> A.ele[i][j];
				}
			}
			return bhoot;

		}
		// Overloading << 
		friend ostream &operator <<(ostream &bhoot, matrix &A){
			for(int i = 0; i < A.r; i++){
				for(int j = 0; j < A.c; j++){
					bhoot << A.ele[i][j] << "\t" ;
				}
				bhoot << endl;
			}
			return bhoot;

		}
		
		matrix tran(){ // Transpose of a matrix
			for(int i = 0; i < r; i++){
				for(int j = 0; j < c; j++){
					ele[i][j] = ele[j][i];
				}
			}
		}

		// For calculating trace
		T1 trace(){
			T1 sum = 0;
			for(int i = 0; i < r; i++){
				for(int j = 0; j < c; j++){
					sum += ele[i][j];
				}
			}
			return sum;
		}

		// For calculating determinant
		T1 det() {
			if(r==c){
				int n=r;
				T1 dt = 0;
				matrix subm;
				if (n == 1) return ele[0][0];
				else if (n == 2) return ((ele[0][0] * ele[1][1]) - (ele[1][0] * ele[0][1]));
   				else {
      					for (int x = 0; x < n; x++) {
         					int subi = 0;
         					for (int i = 1; i < n; i++) {
            						int subj = 0;
            						for (int j = 0; j < n; j++) {
               							if (j == x)
               							continue;
               							subm.ele[subi][subj] = ele[i][j];
               							subj++;
            						}
            						subi++;
         					}
						subm.r = n-1; subm.c = n-1;
         					dt += (pow(-1, x)*ele[0][x] * subm.det());
      					}
   				}
   				return dt;
			}
		}

		// inverse of 2x2 matrix
		matrix inv(){ // only for 2X2 matrix
			matrix C;
			C.r = 2; C.c = 2;
			T1 res = det();
			C.ele[0][0] = ele[1][1]/res; C.ele[0][1] = ele[1][0]/res;
			C.ele[1][0] = ele[0][1]/res; C.ele[1][1] = ele[0][0]/res;
			return C;
		}
};
int main(void){

	matrix <float> A(2,2), B(2,2);
	cout << "Give A: " << endl;
	cin >> A;
	cout << "Give B: " << endl;
	cin >> B;

	// Qs. 1
	matrix <float> C,D,E;
	C = A + B;
	D = A - B;
	E = A*B;
	cout << "Given matrix are: " << endl << "A = " << endl << A << endl << "B = " << endl << B << endl;
	cout << "Their sum = " << endl << C << endl << "Their sub = " << endl << D << endl;
	cout << "Their product = " << endl << E << endl;

	// Qs. 2
	cout << "Determinant of A = " << A.det() << endl;
	cout << "Trace of A = " << A.trace() << endl;

	// Qs. 3
	matrix <float> F = A.inv();
	cout << "Inverse of A = " << endl << F << endl;
	return 0;
}

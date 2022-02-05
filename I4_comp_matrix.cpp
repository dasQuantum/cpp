#include<iostream>
#include<cmath>
using namespace std;
// complex class
class com{
	private:
		float x, y;
	
	public:
		com(float a, float b){
			x = a;
			y = b;
			}
		com () {x = 0;y = 0;}
		float re(){return x;}
		float im(){return y;}
		
		// Conjugate
		com bar(){com u; u.x = x; u.y = -y; return u; }
		// overloading +	
		com operator+(com v) {
			com u;
			u.x = x + v.x; u.y = y + v.y;
			return u;}
		friend com operator + (com u, float v){ com z; z.x = u.x+v; z.y=u.y; return z;}
		friend com operator + (float v, com u){ com z; z.x = u.x+v; z.y=u.y; return z;}
		// overloading -		
		com operator-(com v) {
			com u;
			u.x = x - v.x;
			u.y = y - v.y;
			return u;}
		friend com operator - (com u, float v){ com z; z.x = u.x-v; z.y=u.y; return z;}
		friend com operator - (float v, com u){ com z; z.x = u.x-v; z.y=u.y; return z;}
		// overloading *
		com operator*(com v) {
			com u;
			u.x = x*v.x - y*v.y;
			u.y = x*v.y + y*v.x;
			return u;}
		friend com operator * (float v, com u){ com z; z.x = u.x*v; z.y=u.y*v; return z;}
		friend com operator * (com u, float v){ com z; z.x = u.x*v; z.y=u.y*v; return z;}
		// Amplitude
		float amp(){return sqrt(x*x+y*y);}
		// overloading /
		friend com operator / (com u, float g){
			com f; f.x = u.x/g; f.y = u.y/g;
			return f;
			}
		friend com operator/(com u,com v) {com w = v.bar();com p = u*w;float q=v.amp();q=q*q;return p/q;}
		friend com operator / (float k, com v){com u;u.x = k; u.y = 0; return u/v;}

		// Overloading >>
		friend istream &operator >>(istream &bhoot, com &A){
			bhoot >> A.x >> A.y;
			return bhoot;
		}
		// Overloading << 
		friend ostream &operator <<(ostream &bhoot, const com &A){
			bhoot << A.x;
			if(A.y>=0) bhoot << "+" << A.y << "i";
			else bhoot << A.y << "i";
			return bhoot;

		}
};

// complex matrix class
class matrix{
	private:
		int r,c;
		com ele[6][6];

	public:
		matrix(int a, int b){r = a; c = b;}
		matrix(int a, int b, com mat[10][10]){
			r = a; c =b;
			for(int i = 0; i < r; i++){
				for(int j = 0; j < c; j++){
					ele[i][j] = mat[i][j];
				}
			}
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
						com o(0,0);
						C.ele[i][j] = o;
						for(int k = 0; k < A.c; k++){
							C.ele[i][j] = C.ele[i][j] + A.ele[i][k]*B.ele[k][j];
						}
					}
				}
				return C;
			}
		}
		friend matrix operator* (com f, matrix A){
			matrix B;
			B.r = A.r; B.c = A.c;
			for(int i = 0; i < A.r; i++){
				for(int j = 0; j < A.c; j++){
					B.ele[i][j] = f*A.ele[i][j];
				}
			}
			return B;
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
	
		matrix outer(matrix A){ // Outer product
			matrix C;
			C.r = r*A.r; C.c = c*A.c;
			for(int i = 0; i < C.r; i++){
				for(int j = 0; j < C.c; j++){
					C.ele[i][j] = ele[i/A.r][j/A.c]*A.ele[i%A.r][j%A.c];
				}
			}
			return C;
		}
		
		matrix tran(){ // Transpose of a matrix
			for(int i = 0; i < r; i++){
				for(int j = 0; j < c; j++){
					ele[i][j] = ele[j][i];
				}
			}
		}

		// For calculating trace
		com trace(){
			com sum(0,0);
			for(int i = 0; i < r; i++){
				for(int j = 0; j < c; j++){
					sum = sum + ele[i][j];
				}
			}
			return sum;
		}

		// For calculating determinant
		com det() {
			if(r==c){
				int n=r;
				com dt(0,0);
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
         					dt = dt + (pow(-1, x)*ele[0][x]*subm.det());
      					}
   				}
   				return dt;
			}
		}

		// inverse of 2x2 matrix
		matrix inv(){ // only for 2X2 matrix
			matrix C;
			C.r = 2; C.c = 2;
			com res = det();
			C.ele[0][0] = ele[1][1]/res; C.ele[0][1] = ele[1][0]/res;
			C.ele[1][0] = ele[0][1]/res; C.ele[1][1] = ele[0][0]/res;
			return C;
		}

		// accessing coloumn and row
		int row(){
			return r;
		}
		int col(){
			return c;
		}
};

// Calculating pb
matrix Pb(matrix A, matrix B){
	if(A.col() == B.row() && B.col() == A.row()){
		return A*B-B*A;
	}
	else{
		cout << "Not possible\n";
	}
}
// Calculating lb
matrix Lb(matrix A, matrix B){
	if(A.col() == B.row() && B.col() == A.row()){
		return A*B+B*A;
	}
	else{
		cout << "Not possible\n";
	}
}
// Kroneker delta 2nd
int dl(int a, int b){
	if(a==b) return 1;
	else return 0;
}
// Levi civata 3rd
int nxt(int i, int n){
	if(i == n) return 1;
	else return i+1;
	}
int bfr(int i, int n){
	if(i == 1) return n;
	else return i-1;
	}
int lvcvt(int a, int b, int c){
	int n = 3;
	int l[n];
	l[0] = a; l[1] = b; l[2] = c;
	//Result
	int c_cyl = 0, c_ant = 0;
	for(int i = 1; i < n; i++){
		if(l[i] == nxt(l[i-1],n)) c_cyl ++;
		else if(l[i] == bfr(l[i-1],n)) c_ant ++;
		}
	int result;
	if( c_cyl == n-1 ) result = 1;
	else if (c_ant == n-1) result = -1;
	else result = 0;
	return result;
}
int main(void){

	// Input of pauli matrix
	com o(0,0), p1(1,0), m1(-1,0), pi(0,1), mi(0,-1); 
	com mat1[10][10], mat2[10][10], mat3[10][10], mat4[10][10];
	mat1[0][0] = o; mat1[0][1] = p1; mat1[1][0] = p1; mat1[1][1] = o;
	mat2[0][0] = o; mat2[0][1] = mi; mat2[1][0] = pi; mat2[1][1] = o;
	mat3[0][0] = p1; mat3[0][1] = o; mat3[1][0] = o; mat3[1][1] = m1;
	mat4[0][0] = p1; mat4[0][1] = o; mat4[1][0] = o; mat4[1][1] = p1;
	matrix s1(2,2,mat1), s2(2,2,mat2), s3(2,2,mat3), I(2,2,mat4);

	// pauli matrix
	matrix sigma[3];
	sigma[0] = s1;
	sigma[1] = s2;
	sigma[2] = s3; 
	cout << "Three pauli matrices are: \n";
	cout << "Sigma_1 = " << endl << sigma[0] << endl;
	cout << "Sigma_2 = " << endl << sigma[1] << endl;
	cout << "Sigma_3 = " << endl << sigma[2] << endl;

	// Qs 4(a)
	cout << "Checking relations: 4(a) " << endl;
	for(int i = 1; i <= 3; i++){
		for(int j = 1; j <= 3; j++){
			if(i!=j){
				cout << endl;
				matrix rhs, lhs, ans;
				lhs = sigma[i-1]*sigma[j-1];
				int k = 6-i-j, l = lvcvt(i,j,k);
				com ll(0,l*1.0);
				rhs = ll*sigma[k-1];
				ans = lhs - rhs;
				cout << "Multiplication of S" << i << "S"<< j << " = " << endl << ans << endl;

				lhs = Pb(sigma[i-1],sigma[j-1]); // poiso. brac
				com ll2(0,l*2.0);
				rhs = ll2*sigma[k-1];
				ans = lhs - rhs;
				cout << "[S" << i << ",S" << j << "] = " << endl << ans << endl;
			}
		}
	}
	
	for(int i = 1; i <= 3; i++){
		for(int j = 1; j <= 3; j++){
			matrix lhs, rhs, ans;
			lhs = Lb(sigma[i-1],sigma[j-1]); // lagr. brac
			int l = 2*dl(i,j);
			com ll(l,0);
			rhs = ll*I;
			ans = lhs - rhs;
			cout << "{S" << i << ",S" << j << "} = " << endl << ans << endl;
		}
	}

	// Qs 4(b)
	matrix z[4];
	matrix temp;

	temp = pi*sigma[0];
	z[0] = temp.outer(sigma[1]);

	temp = pi*sigma[1];
	z[1] = temp.outer(sigma[1]);

	temp = m1*sigma[2];
	z[2] = temp.outer(sigma[1]);

	z[3] = I.outer(sigma[2]);
	// 4(b)i
	for(int i = 1; i <= 4; i++){
		cout <<"z" << i << " = " << endl << z[i-1] << endl;
	}
	// 4(b)ii
	for(int i = 1; i <= 4; i++){
		for(int j = 1; j <= 4; j++){
			matrix lhs;
			lhs = Lb(z[i-1],z[j-1]); // lagr. brac
			cout << "{z" << i << ",z" << j << "} = " << endl << lhs << endl;
		}
	}
	// 4(b)iii
	matrix z5;
	z5 = I.outer(I);
	for(int i = 1; i <= 4; i++){
		z5 = z5*z[i-1];
	}
	cout << "z5 = " << endl << z5 << endl;
	
	
	return 0;
}

#include<iostream>
#include<cmath>
using namespace std;
// defining determinant
int determinant( int matrix[10][10], int n) {
   int det = 0;
   int submatrix[10][10];
   if(n==1) return matrix[0][0];
   else if (n == 2)
   return ((matrix[0][0] * matrix[1][1]) - (matrix[1][0] * matrix[0][1]));
   else {
      for (int x = 0; x < n; x++) {
         int subi = 0;
         for (int i = 1; i < n; i++) {
            int subj = 0;
            for (int j = 0; j < n; j++) {
               if (j == x)
               continue;
               submatrix[subi][subj] = matrix[i][j];
               subj++;
            }
            subi++;
         }
         det = det + (pow(-1, x) * matrix[0][x] * determinant( submatrix, n - 1 ));
      }
   }
   return det;
}
// defining kroneker
int d(int i, int j){
   if(i==j) return 1;
   else return 0;
}

// N dim kroneker
int Nd(int data[10][10][2], int N){
   int dt[10][10];
   for(int i = 0; i < N; i++){
      for(int j = 0; j < N; j++){
         dt[i][j] = d(data[i][j][0],data[i][j][1]);
      }
   }

   int res;
   res = determinant(dt,N);
   return res;
}
int main(void){
   int N = 2;
   int data[10][10][2];
   data[0][0][0] = 0; data[0][0][1] = 1; data[0][1][0] = 1; data[0][1][1] = 1;
   data[1][0][0] = 1; data[1][0][1] = 1; data[1][1][0] = 1; data[1][1][1] = 1;

   cout << "Result = " << Nd(data, N) << endl;
   return 0;
}

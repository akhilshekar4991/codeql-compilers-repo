#include<iostream>
using namespace std;
int main() {
   int product[9], r1=3, c1=3, r2=3, c2=3, i, j, k;
   int a[9] = { 2, 4, 1,2, 3, 9, 3, 1, 8 };
   int b[9] = { 1, 2, 3,3, 6, 1, 2, 4, 7 };
   int L=3, N =3;
   if (c1 != r2) {
      cout<<"Column of first matrix should be equal to row of second matrix";
   } else {
      cout<<"The first matrix is:"<<endl;
      for(i=0; i<r1; i++) {
	      for(j=0; j<c1; j++) {
         	cout<<a[j + (i * N)]<<" ";
	 }
         cout<<endl;
      }

      cout<<endl;
      cout<<"The second matrix is:"<<endl;
      
      for(i=0; i<r2; i++) {
         for(j=0; j<c2; j++) {
	         cout<<b[j + (i * N)]<<" ";
	 }
         cout<<endl;
      }

      cout<<endl;
      
      for(i=0; i<r1; i++) {
	      for(j=0; j<c2; j++) {
      		product[j + (i * N)] = 0;
	      }
      }

      /*
      for(i=0; i<r1; ++i) {
	      for(j=0; j<c2; ++j) {
		      for(k=0; k<c1; ++k) {
		         product[i][j]+=a[i][k]*b[k][j];
		      }
	      }
      }*/


	for (i = 0; i < 3; i++) {
		for (j = 0; j < 3; j++) {
			product[j + i * N] = 0;
			
			for (k = 0; k < 3; k++) {
				product[j + (i * N)] += a[k + (i * L)] * b[j + (k * N)];
				//printf("c[%d] = a[%d] * b[%d] \n", (j + (i * N)), (k + (i * L)), (j + (k * N)) );
				//printf("%d = %d * %d \n", product[(j + (i * N))], a[(k + (i * L))], b[(j + (k * N))]);
			}
			//printf("Final solution of c[%d] = %d \n", (j + (i * N)), product[j + (i * N)]);
	        }
	}
      cout<<"Product of the two matrices is:"<<endl;
      for(i=0; i<r1; ++i) {
         for(j=0; j<c2; ++j) {
	         cout<<product[j + (i * N)]<<" ";
	 }
         cout<<endl;
      }
   }
   return 0;
}

#include <stdio.h>

int main() {
   int F[2][2]; 
   int i, j;
   int M1, M2, M3, M4, M5, M6, M7; 
   int D[2][2], E[2][2]; 

   printf("Enter the elements of the first 2x2 matrix:\n");
   for(i = 0; i < 2; i++) {
      for(j = 0; j < 2; j++) {
         printf("D[%d][%d]: ", i, j);
         scanf("%d", &D[i][j]);
      }
   }

   printf("Enter the elements of the second 2x2 matrix:\n");
   for(i = 0; i < 2; i++) {
      for(j = 0; j < 2; j++) {
         printf("E[%d][%d]: ", i, j);
         scanf("%d", &E[i][j]);
      }
   }
   printf("\nThe first matrix is: ");
   for(i = 0; i < 2; i++) {
      printf("\n");
      for(j = 0; j < 2; j++) {
         printf("%d\t", D[i][j]);
      }
   }

   printf("\nThe second matrix is: ");
   for(i = 0; i < 2; i++) {
      printf("\n");
      for(j = 0; j < 2; j++) {
         printf("%d\t", E[i][j]);
      }
   }

   M1 = (D[0][0] + D[1][1]) * (E[0][0] + E[1][1]);
   M2 = (D[1][0] + D[1][1]) * E[0][0];
   M3 = D[0][0] * (E[0][1] - E[1][1]);
   M4 = D[1][1] * (E[1][0] - E[0][0]);
   M5 = (D[0][0] + D[0][1]) * E[1][1];
   M6 = (D[1][0] - D[0][0]) * (E[0][0] + E[0][1]);
   M7 = (D[0][1] - D[1][1]) * (E[1][0] + E[1][1]);

   F[0][0] = M1 + M4 - M5 + M7;
   F[0][1] = M3 + M5;
   F[1][0] = M2 + M4;
   F[1][1] = M1 - M2 + M3 + M6;
   
   printf("\n\nProduct achieved using Strassen's algorithm: ");
   for(i = 0; i < 2 ; i++) {
      printf("\n");
      for(j = 0; j < 2; j++) {
         printf("%d\t", F[i][j]);
      }
   }

   return 0;
}

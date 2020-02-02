#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#ifndef false
#define false 0
#endif
#ifndef true
#define true 1
#endif
// To execute C, please define "int main()"

#define MAX_N   19
int seed_shuffle1[MAX_N] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19};
int seed_shuffle2[MAX_N] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19};
int board[MAX_N][MAX_N];
void shuffle (int *arr, int N)
{
  int i = N - 1;
  int j = 0;
  int temp = 0;
  for (; i > 0; i--) {
    j = rand()%i;
    temp = arr[j];
    arr[j] = arr[i];
    arr[i] = temp;
  }
}
/*  full table verification */
int table_verify (int candidate[][MAX_N], int N)
{
    int i = 0;
    int j = 0;
    /*  verify row */
    for (i = 0 ; i < N; i++) {
        for ( j = i+1; j < N; j++) {
            if (candidate[0][j] == candidate[0][i])
                return false;
        }
    }
    for (i = 0 ; i < N; i++) {
        for ( j = 1; j < N; j++) {
            if (candidate[0][i] == candidate[j][i])
                return false;
        }
    }
    return true;
}

int single_verify (int candidate[][MAX_N], int N, int row, int column)
{
    int i = 0, j = 0;
    /*  row verify */
    for (j = 0; j < N; j++) {
        if (j == column) continue;
        if (candidate[row][column] == candidate[row][j])
            return false;
    }
    /*  column verify */
    for (i = 0; i < N; i++) {
        if (i == row) continue;
        if (candidate[row][column] == candidate[i][column])
            return false;
    }
    return true;
}

int generator(int A[][MAX_N], int row, int column, int N)
{
    int population[MAX_N] = {  1,  2,  3,  4,  5,  6,  7,  8,  9, 10,
                              11, 12, 13, 14, 15, 16, 17, 18, 19};

    int available[MAX_N] = { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
                             1, 1, 1, 1, 1, 1, 1, 1, 1};

    int i = 0, j = 0, k = 0;
    int res = 1;
    /*  Move downwards on same column until row-1 and mark those used up */
    for (i = 0; i < row; i++)
        available[A[i][column]-1] = 0;

    /*  Move sideways on same row until column-1 and mark those used up */
    for (j = 0; j < column; j++)
        available[A[row][j]-1] = 0;

    for (k = N-1; k >= 0; k--) {
        if (available[k]) {
            A[row][column] = population[k];
            if (row == N-1 && column == N-1) {
                return 0;
            }
            
            if (column < N-1) {
                res = generator(A, row, column+1, N);
            } else {
                res = generator(A, row+1, 0, N);
            }
            if (res) {
                A[row][column] = -1;
            } else {
                return 0;
            }
        }
    }
    return res;
}

#define OPTION_2_Shuffle_conditional
int main() {
  int N = 19;
  #ifdef OPTION_1_Shuffle_shift /* shuffle and shift : Faster but less randomness*/
  int i = 0, j = 0;
  srand(time(0));
  shuffle(seed_shuffle1, N);
  shuffle(seed_shuffle2, N);
  i = 0;
  for (; i < N; i++) {
      j = seed_shuffle2[i];
      for (; j < N; j++)
        printf("[%d]", seed_shuffle1[j]);
      j = 0;
      for (; j < seed_shuffle2[i];j++ )
        printf("[%d]", seed_shuffle1[j]);
    printf ("\n");
  }
  #elif defined(OPTION_2_Shuffle_conditional) /* shuffle and shuffle_conditioanl : slower but better randomness */
  int i = 0, j = 0, k = 0;
  srand(time(0));
  shuffle(seed_shuffle1, N);
  shuffle(seed_shuffle2, N);
#if 0
  printf ("Seed 1: ");
  for ( i = 0 ; i < N ; i ++)
  {
      printf ("[%d] ", seed_shuffle1[i]);
  }
  printf ("\n");
  printf ("Seed 2: ");
  for ( i = 0 ; i < N ; i ++)
  {
      printf ("[%d] ", seed_shuffle2[i]);
  }
  printf ("\n");
#endif
  for (i = 0; i < N; i++) {
      board[0][i] = seed_shuffle1[i];
  }
  generator(board, 1, 0, N);
  for (i = 0; i < N; i++) {
    k = seed_shuffle2[i];
    for (j =0; j < N; j++) {
      printf("[%2d]", board[k][j]);
    }
    printf("\n");
  }
    
  
  #endif
  
  
  printf ("done");
  return 0;
}

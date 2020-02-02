#include <stdio.h>
#include <stdlib.h>
#include <time.h>
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
void shuffle_conditional (int row, int N)
{
  int i = N - 1;
  int j = 0;
  int k = 0;
  int temp = 0;
  
  for (; i > 0; i--) {
    int conditional = 0;
    /*  
    if ( i == 1) {
        temp = board[row][1];
        board[row][1] = board[row][0];
        board[row][0] = temp;
    }else */if ( i < 2) {
        temp = board[row][i];
        for ( k = 0; k < row; k++) {
            if (board[k][i] == temp) {
                conditional = 1;
                break;
            }
        }
    } else {
        conditional = 1;
    }
repeat:
    while (conditional) {
      j = rand()%i;
      temp = board[row][j];
      /* check if temp has appeared in ith column until row-1 */
      for ( k = 0; k < row; k++ )
      {
          if ( board[k][i] == temp) {
              conditional = 1;
              goto repeat;
          }
      }
      conditional = 0;
      board[row][j] = board[row][i];
      board[row][i] = temp;
    }
  }
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
      k = 0;
      j = seed_shuffle2[i];
      for (; j < N; j++,k++) {
          board[i][k] = seed_shuffle1[j];
      }
      for (j = 0; j < seed_shuffle2[i]; j++,k++) {
          board[i][k] = seed_shuffle1[j];
      }
  }
  
  for (i=1; i < N; i++) {
    shuffle_conditional(i, N);
  }
  for (i = 0; i < N; i++) {
    for (j =0; j < N; j++) {
      printf("[%d]", board[i][j]);
    }
    printf("\n");
  }
    
  
  #endif
  
  
  printf ("done");
  return 0;
}

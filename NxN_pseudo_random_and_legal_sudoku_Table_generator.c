
/*
 * Problem:
 * This is a NP-hard problem. complexity of the problem increases exponentially with increase in size.
 *
 * Solution discussion:
 * This program generates pseudorandom board of size N x N. where 0 < N < 20. 
 * IF N is such that sqrt(N) is a integer then we generate a legal sudoku board.
 *
 * There are two solutions( for when N is not a perfect square). Run with either compile flag: OPTION_1_Shuffle_shift or 
 * OPTION_2_Shuffle_Backtrack_shuffle.
 * For sudoku only use OPTION_2_Shuffle_Backtrack_shuffle
 *
 * Legal sudoku is only generated for N = 4, 9, 16.
 * for all other value of N in range 0 < N < 20. Pseudo random board is generated.
 * 
 * 
 *
 */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>


#ifndef false
#define false 0
#endif
#ifndef true
#define true 1
#endif

#define MAX_N   19

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

int sudoku_generator(int A[][MAX_N], int row, int column, int N, int grid_sz)
{
    int population[MAX_N] = {  1,  2,  3,  4,  5,  6,  7,  8,  9, 10,
                              11, 12, 13, 14, 15, 16, 17, 18, 19};

    int available[MAX_N] = { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
                             1, 1, 1, 1, 1, 1, 1, 1, 1};

    int i = 0, j = 0, k = 0;
    int grid_row_base = 0;
    int grid_column_base = 0;
    int grid_walk = 0;

    int res = 1;
    /*  Move downwards on same column until row-1 and mark those used up */
    for (i = 0; i < row; i++)
        available[A[i][column]-1] = 0;

    /*  Move sideways on same row until column-1 and mark those used up */
    for (j = 0; j < column; j++)
        available[A[row][j]-1] = 0;
    
    grid_row_base = row - (row % grid_sz);
    grid_column_base = column - (column % grid_sz);

    for (i = grid_row_base; !grid_walk && i < grid_row_base + grid_sz; i++) {
        for ( j = grid_column_base; !grid_walk && j < grid_column_base + grid_sz; j++) {
            if (i == row && j == column) {
                grid_walk = 1;
                break;
            }
            available[A[i][j]-1] = 0;
        }
    }

    for (k = N-1; k >= 0; k--) {
        if (available[k]) {
            A[row][column] = population[k];
#if 0
            {
                printf("\nAt row [%d] col [%d] \n-  -   -   -   -\n", row, column);
                for ( i = 0; i < N; i++) {
                    for (j = 0; j < N; j++) {
                        printf ("[%2d]", A[i][j]);
                    }
                    printf ("\n");
                }
                 
            }
#endif
            if (row == N-1 && column == N-1) {
                return 0;
            }
            
            if (column < N-1) {
                res = sudoku_generator(A, row, column+1, N, grid_sz);
            } else {
                res = sudoku_generator(A, row+1, 0, N, grid_sz);
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


//#define OPTION_1_Shuffle_shift
/*      Solution one: OPTION_1_Shuffle_shift
        This seeds the first row of the table with knuth's shuffle algo to generate a random permutation 
        of a set of size (N).
        
        Followed by that another seed row is generated using same knuths shuffle algo. This seed of size N
        is used to shuffle the first seed across the board column wise.
        
        This is a very fast method. But has drawbacks.
        Example: (cycle permutation)
        [10][3][1][9][4][7][5][6][2][8]
            [3][1][9][4][7][5][6][2][8][10]
               [1][9][4][7][5][6][2][8][10][3]
                  [9][4][7][5][6][2][8][10][3][1]
                                    [8][10][3][1][9][4][7][5][6][2]
                                 [2][8][10][3][1][9][4][7][5][6]
                           [5][6][2][8][10][3][1][9][4][7]
                     [4][7][5][6][2][8][10][3][1][9]
                              [6][2][8][10][3][1][9][4][7][5]
                        [7][5][6][2][8][10][3][1][9][4]
        

 * 
 */


#define OPTION_2_Shuffle_Backtrack_shuffle
/*
 *   Solution two: OPTION_2_Shuffle_Backtrack_shuffle
 *   This seeds the first row of the table with knuth's shufle algo to generate a random permutation of a set of size (N).
     
     Followed by that "generator" devolves into a back-tracking algorithm. It tries to find a first possible
     for for each [row][column]. Only back-tracking when the selected option breaks the constraints.
     
     Finally another knut's shuffle seed set is used to row shuffle the output of backtracking.
     Example: (it does not have the cyclic permutation patter).
      [10][8][9][6][7][5][4][3][2][1]
      [4][5][6][1][3][2][9][8][10][7]
      [7][6][5][10][9][4][1][2][8][3]
      [2][1][3][4][10][8][5][7][9][6]
      [1][3][4][2][8][9][6][5][7][10]
      [9][10][8][5][6][7][3][4][1][2]
      [3][2][1][8][4][10][7][6][5][9]
      [8][7][10][9][5][6][2][1][3][4]
      [5][4][7][3][2][1][10][9][6][8]
      [6][9][2][7][1][3][8][10][4][5]
 */
int main() {
  int N;
  while (1) {
   
    int seed_shuffle1[MAX_N] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19};
    int seed_shuffle2[MAX_N] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19};
    int board[MAX_N][MAX_N];
    
    printf("\nGenerator #");
    printf("\nEnter Table size (0 > N < 20):");
    printf("\nGenerator #");
    scanf("%d", &N);
    
    if (N < 1 || N > 19) {
      printf("Rerun with acceptable argument(Bye!)\n");
      continue;
    }

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
  
#elif defined(OPTION_2_Shuffle_Backtrack_shuffle) /* seed with shuffle and remaining rows backtrack, then shuffle display : 
                                                     slower compared to OPTION_1_Shuffle_shift but better randomness */

    int i = 0, j = 0, k = 0;
    srand(time(0));
    shuffle(seed_shuffle1, N);
    shuffle(seed_shuffle2, N);

    for (i = 0; i < N; i++) {
        board[0][i] = seed_shuffle1[i];
    }
    
    if (N == 4 || N == 9 || N == 16) {
      int grid_sz;
      switch(N) {
        case 4:
            grid_sz = 2; /*  basically sqrt */
            break;
        case 9:
            grid_sz = 3;
            break;
        case 16:
            grid_sz = 4;
            break;
      }
      sudoku_generator(board, 1, 0, N, grid_sz);
      printf("--");
      for (i = 0; i < N; i++) {
           if (!(i%grid_sz) && !(j%grid_sz)) {
              for (k =0; k < N;k++) {
                  printf("---");
              }
              printf("\n");
           }
          for (j =0; j < N; j++) {
                if (!(j%grid_sz)) {
                    printf("|");
                }
            printf("%2d ", board[i][j]);
          }
          printf("\n");
        }
    } else {
    
      generator(board, 1, 0, N);


      for (i = 0; i < N; i++) {
        k = seed_shuffle2[i];
        for (j =0; j < N; j++) {
          printf("[%d]", board[k-1][j]);
        }
        printf("\n");
      }
    }

  #endif

    printf("\nDone!\n\n");
  }
  return 0;
}

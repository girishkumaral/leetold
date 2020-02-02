/*Given an array of meeting time intervals consisting of start and end times [[s1,e1],[s2,e2],...] (si < ei), determine if a person could attend all meetings.

Example 1:

Input: [[0,30],[5,10],[15,20]]
Output: false
Example 2:

Input: [[7,10],[2,4]]
Output: true
*/
#include <stdlib.h>

#define swap(inter, x, y) \
do { \
    int s1 = inter[x][0]; \
    int s2 = inter[x][1]; \
    inter[x][0] = inter[y][0]; \
    inter[x][1] = inter[y][1]; \
    inter[y][0] = s1; \
    inter[y][1] = s2; \
} while(0);

void quicksort(int **intervals, int low, int high)
{
    int small = low;
    int big = low+1;
    int pindex;
    int* pivot;
    
    if (low >= high)
        return;
    
    pindex = (rand() % high);
    if (pindex < low) {
        pindex = low;
    }
    //printf ("pindex %d", pindex);
    
    swap(intervals, pindex, low);
    pivot = intervals[low];
    while (big <= high) {
        if (intervals[big][0] < pivot[0]) {
            small++;
            swap(intervals, small, big);
        }
        big++;
    }
    swap(intervals, low, small);
    
    quicksort(intervals, low, small-1);
    quicksort(intervals, small+1, high);
}



bool canAttendMeetings(int** intervals, int intervalsSize, int* intervalsColSize){
    int i = 0;
    
    if (intervalsSize <= 1)
        return true;
    
    //printf("intervals:\n");
    //for (i=0; i< intervalsSize; i++)
       // printf("[%d, %d]", intervals[i][0], intervals[i][1]);
    
    quicksort(intervals, 0, intervalsSize-1);
    //printf("Sorted intervals:\n");
    //for (i=0; i< intervalsSize; i++)
      //  printf("[%d, %d]", intervals[i][0], intervals[i][1]);
    i =0;
    *intervalsColSize = intervalsSize;
    while(i < intervalsSize-1) {
        if((intervals[i+1][0] >= intervals[i][0]) &&
           (intervals[i+1][1] <= intervals[i][1])) {
            return false;
        }
        if (intervals[i+1][0] > intervals[i][0] &&
            intervals[i+1][0] == intervals[i][1]) {
            i++;
            continue;
        }
            
        if (intervals[i+1][0] >= intervals[i][0] &&
            intervals[i+1][0] <= intervals[i][1])
            return false;
        i++;
    }
    //printf("Can attend");
    return true;
}


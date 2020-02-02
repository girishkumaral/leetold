/*Find the kth largest element in an unsorted array. Note that it is the kth largest element in the sorted order, not the kth distinct element.

Example 1:

Input: [3,2,1,5,6,4] and k = 2
Output: 5
Example 2:

Input: [3,2,3,1,2,4,5,5,6] and k = 4
Output: 4*/



/*
Quick select
*/

#define swap(A, i, j) \
do { \
    int temp = A[i]; \
    A[i] = A[j]; \
    A[j] = temp; \
} while(0)

void printA(int *nums, int low, int high)
{
    while(low <= high) {
        printf("%d ", nums[low++]);
    }
    printf("\n");
}

void quickSelKhelper(int *nums, int low, int high, int k)
{
    int small = low;
    int big = low+1;
    int pivot;
    int pindex = low;
    //printf("low %d, high %d\n", low, high);
    swap(nums, low, pindex);
    pivot = nums[low];
    while (big <= high) {
        if (nums[big] < pivot) {
            small++;
            swap(nums, small, big);
        }
        big++;
    }
    swap(nums, low, small);
    //printA(nums, low, high);
    //printf("small=%d, k=%d\n", small, k);
    if (k > small) {
        quickSelKhelper(nums, small+1, high, k);
    } else if (k < small) {
        quickSelKhelper(nums, low, small-1, k);
    } else return;
}


int findKthLargest(int* nums, int numsSize, int k){
    if (k >= 0 && k <= numsSize) {
        quickSelKhelper(nums, 0, numsSize-1, numsSize-k);
    
        return nums[numsSize-k];
    } else return -1;
}


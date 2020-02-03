/*
 * Complete the 'merge_sort' function below.
 *
 * The function accepts integer result_count, n and an integer array as parameter.
 */

void merge(int *arr, int ll, int hl, int lr, int hr, int *aux)
{
    int j = 0;
    int k = 0;
    int low = ll;
    //printf("\nMerge: %d, %d, %d, %d\n", ll, hl, lr, hr);
    while (ll <= hl && lr <= hr) {
        if (arr[ll] <= arr[lr])
            aux[j++] = arr[ll++];
        else aux[j++] = arr[lr++];
    }
    while (ll <= hl) {
        aux[j++] = arr[ll++];
    }
    while(lr <= hl) {
        aux[j++] = arr[lr++];
    }
    
    
    for (k = 0; k < j; k++) {
        arr[low++] = aux[k];
    }
}

#define cond_swap(arr, low, high) \
do {\
    if (arr[low] > arr[high]) {\
        int temp = arr[low];\
        arr[low] = arr[high];\
        arr[high] = temp;\
    }\
} while(0)

int c;
void mergesortHelper(int *arr, int low, int high, int *aux)
{
    int mid = 0;
    
    if(low >= high)
        return;
        
    if (high-low == 1) {
        cond_swap(arr, low, high);
        return;
    }
        
    //printf("Call %d low %d, high %d\n", c++, low, high);    
    
    mid = (high-low)/2;
    
    mergesortHelper(arr, low, low+mid, aux);
    mergesortHelper(arr, low+mid+1, high, aux);
    
    merge(arr, low, low+mid, low+mid+1, high, aux);
}

int* merge_sort(int* result_count, int n, int* arr) {
    int *res = calloc(1, sizeof(int) * n);
    int i = 0;
    *result_count = n;
    mergesortHelper(arr, 0, n-1, res);
    //for (i = 0; i < n;i++)
    //    printf("%d ", arr[i]);
        
    //printf("\n\n");
    return arr;
}


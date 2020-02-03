/*
 * Complete the mergeArrays function below.
 */

/*
 * Please store the size of the integer array to be returned in result_count pointer. For example,
 * int a[3] = {1, 2, 3};
 *
 * *result_count = 3;
 *
 * return a;
 *
 */

typedef struct _t {
    int index;
    int *arr;
} T;


typedef struct heap_s {
    int compare;
    int size;
    int N;
    struct _t **T;
}heap_t;

static inline int COMPARE(heap_t *h, int one, int two) 
{
  if (h->compare) {
      if (h->T[one]->arr[h->T[one]->index] <
          h->T[two]->arr[h->T[two]->index]) {
              return true;
      } else return false;
  } else {
      if (h->T[one]->arr[h->T[one]->index] >
          h->T[two]->arr[h->T[two]->index]) {
              return true;
      } else return false;
  }
}

#define SWAP(h, one, two) \
do { \
    struct T *temp = h->T[one]; \
    h->T[one] = h->T[two];\
    h->T[two] = temp;\
} while (0)

static inline void heapify (heap_t *h, int parent)
{
    while (parent >= 0) {
        int child = 2 * parent + 1;
        int rchild = 2 * parent + 2;
        if (child < h->size) {
            if (rchild < h->size) {
                if(COMPARE(h, rchild, child)) child = rchild;
            }
            if (COMPARE(h, child, parent)) { /* child is < parent  in case of min heap. 
                                                Or child > parent in case of max heap */
                SWAP(h, child, parent);
                heapify(h, child);
            }
            parent--;
        } else break;
    }
}

void printHeap(heap_t *h)
{
    int   parent = (h->size-1);
    printf("\n[");
    while (parent >=0) {
        printf ("%d ", h->T[parent]->arr[h->T[parent]->index]);
        parent--;
    }
    printf("]\n");
}
static inline void Downheap(heap_t *h)
{
    int parent = 0;
    int last = (h->size - 2)/2;
    
    
    
    if (h->T[parent]->index == h->N) {
        //printf("Empty array removing\n");
        SWAP(h, parent, h->size-1);
        h->size--;
        last = (h->size -2/2);
    }
    if (!h->size) return;
    
    while (parent<= last) {
        int child = 2 * parent + 1;
        int rchild = 2 * parent + 2;
        if (child < h->size) {
            if (rchild < h->size) {
                //printf("comparing %d with %d\n", h->T[rchild]->arr[h->T[rchild]->index], 
                //h->T[child]->arr[h->T[child]->index]);
                if(COMPARE(h, rchild, child)) child = rchild;
            }
            if (COMPARE(h, child, parent)) { /* child is < parent  in case of min heap. 
                                                Or child > parent in case of max heap */
                SWAP(h, child, parent);
                parent = child;
            } else break;
        } else break;
    }
}

static inline int heappop(heap_t *h) {
    int ret = h->T[0]->arr[h->T[0]->index];
    //printHeap(h);
    //printf("   Top of heap %d index %d\n", ret,h->T[0]->index);
    h->T[0]->index++;
    if (h->T[0]->index < h->N)
        if (!h->compare && ret < h->T[0]->arr[h->T[0]->index]) h->compare=1;
    //printf("   B: size = %d, index %d, val %d\n", h->size, h->T[0]->index, h->T[0]->arr[h->T[0]->index]);
    Downheap(h);
    //printf("   A: size = %d, index %d, val %d\n", h->size, h->T[0]->index, h->T[0]->arr[h->T[0]->index]);
    
    return ret;
} 

int* mergeArrays(int arr_rows, int arr_columns, int** arr, int* result_count) {
    int i = 0;
    int j = 0;
    //int k = 0;
    heap_t h;
    
    
    *result_count = arr_rows * arr_columns;
    
    if (arr_rows == 0 || arr_columns == 0) return NULL;
    
    h.size = 0;
    h.compare = (arr_columns == 1) ? 1 : ((arr[0][1]-arr[0][0] > 0) ? 1 : 0);
    if (!h.compare) 
        h.compare = ((arr[arr_rows-1][1]-arr[arr_rows-1][0] > 0) ? 1 : 0);
        
    if (!h.compare && arr_rows > 2)
        h.compare = ((arr[arr_rows-2][1]-arr[arr_rows-2][0] > 0) ? 1 : 0);
    
    if (!h.compare && arr_rows > 3)
        h.compare = ((arr[arr_rows-3][1]-arr[arr_rows-3][0] > 0) ? 1 : 0);
    
    h.N = arr_columns;
    h.T = (struct T **)calloc(1, sizeof(T *) * arr_rows);
    T *temp = calloc(1, sizeof(T) * arr_rows);
    int *retarr = calloc(1, sizeof(int) * (*result_count));
    for (i = 0; i < arr_rows; i++) {
        h.T[i] = temp + i;
        h.T[i]->arr = arr[i];
        h.size++;
    }
    //printHeap(&h);
    heapify(&h, (h.size-2)/2);
    while (h.size > 0)  {
        retarr[j++] = heappop(&h);
    }
    return retarr;
}


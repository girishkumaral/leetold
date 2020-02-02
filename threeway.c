#include<stdio.h>


void threeway(int *a, int low, int high, int pivot)
{
	int e = -1;
	int s = -1;
	int b = low;

	while (b <= high) {
		if (a[b] <= pivot) {
			if (a[b] == pivot) {
				int temp = a[b];
				s++;
				a[b] = a[s];
				a[s] = a[++e];
				a[e] = temp;
			} else {
				int temp = a[b];
				s++;
				a[b] = a[s];
				a[s] = temp;
			}
		}
		b++;
	}

	int i= 0;
	while (s > e && e >= 0) {
		int temp = a[s];
		a[s] = a[e];
		a[e] = temp;
		e--;
		s--;
	}
}


int main(int argc, char **argv)
{
	int a[10] = {1, 5, 1, 4, 1, 8, 6, 5, 5, 4};
	int i =-1;
	threeway(a, 0, 9, 5);
	while(++i < 10)
		printf("%d ", a[i]);
	return 1;
}

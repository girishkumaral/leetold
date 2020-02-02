#include <stdio.h>


int main (int argc, char **argv)
{
	int i = 0, j = 0;
	for (i = 0; i < 17; i++)
		for (j= 0; j < 4; j++)
			printf ("fpc_%d_pic_%d = false\n", i, j);
}

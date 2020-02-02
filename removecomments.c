#include<stdio.h>
#include<string.h>
#include<stdlib.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
typedef enum {
    MODE0,
    MODE1,
} modes_t;

#include<stdio.h>
#include<string.h>
char ** removeComments(char ** source, int sourceSize, int* returnSize) {
    int i = 0, j = 0;
    int k = 0;
    char ** Rsource = (char **)malloc(sizeof(char *) * sourceSize);
    int reuseSrc = 0;
    char *tmp = NULL;
    modes_t mode = MODE0;
    int len = 0;
    int Eol = 0;
    
    while (k < sourceSize) {
        i = 0;
        len = strlen(source[k]);
        j = 0;
        while (i < len-1) {
            switch(mode) {
                case MODE0:
                    if (!tmp) {
                        j=0;
                        tmp = malloc(80 * sizeof(char));
                    }
                    if (source[k][i] == '/' && source[k][i+1] == '/') {
                        tmp[j++] = '\0';
                        Eol = 1;
                        break;
                    }
                    if (source[k][i] == '/' && source[k][i+1] == '*') {
                        i++;
                        mode = MODE1;
                        break;
                    }
                    tmp[j++] = source[k][i];
                    break;
                case MODE1:
                    if (source[k][i] == '*' && source[k][i++] == '/') {
                        i++;
                        mode = MODE0;
                    }
                    break;
            }
            if (Eol && tmp[0] == '\0') { /* this line wont make it to Rsource */
                reuseSrc = 1;
                j=0;
                Eol = 0;
                break;
            } else if (Eol) { /* there is atleast something in this line put to Rsource */
                Rsource[(*returnSize)++] = tmp;
                tmp = NULL;
                j = 0;
                Eol = 0;
                break;
            }
            i++;
        }
        if (tmp && mode == MODE0) {
            if (i < len) {
                tmp[j++] = source[k][i];
            }
            tmp[j++] = '\0';
            Rsource[(*returnSize)++] = tmp;
            tmp=NULL;
            j = 0;
        } else if (tmp && mode == MODE1) {
            tmp[j++] = '\0';
            Rsource[(*returnSize)++] = tmp;
            tmp=NULL;
            j = 0;
        }
        k++;
    }
    return Rsource;
}

int main(int argc, char **argv)
{
	char *source1 = "a=b;";
	int lines = 1;
	char *src[] = {source1};
	char **rsrc; 
	int ret = 0;
	int i;
	rsrc = removeComments(src, 1, &ret);
	for (i = 0; i< ret; i++) {
		if (rsrc[i]) {
			printf ("%s\n", rsrc[i]);
		}
	}
	return 0; 
}

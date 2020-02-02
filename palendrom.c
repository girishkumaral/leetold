#include<stdio.h>
#include<string.h>

int isPalindrome(char * s){
    int len = strlen(s);
    int i = 0;
    int j = len-1;
    int x, y;
    
    if (j == 1)
        return 1;
    
    while (i < j) {
        if (!((s[i] >= 'a' && s[i] <= 'z') ||
           (s[i] >= 'A' && s[j] <= 'Z'))) {
            i++;
            continue;
        }
        if (!((s[j] >= 'a' && s[j] <= 'z') ||
           (s[j] >= 'A' && s[j] <= 'Z'))) {
            j--;
            continue;
        }
        
        x = 'a' - s[i];
        if (s[i] >= 'A' && s[i] <= 'Z')
            x = 'A' - s[i]; 
        
        y = 'a' - s[j];
        if (s[j] >= 'A' && s[j] <= 'Z')
            j = 'A' - s[j];
        
        printf("Compare %c at %u with %c at %u", s[i], i, s[j], j);
        
        if (x != y)
            return 0;
        
        i++;
        j--;
    }
    return 1;
}

int main(int argc, char **argv)
{
	char *str = "A man, a plan, a canal: Panama";
	printf("%u", isPalindrome(str));
	return 0;
}

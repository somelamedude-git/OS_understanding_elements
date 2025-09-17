#include <string.h>
#include <stdio.h>
#include <limits.h>

int max(int a, int b){
	return (a>b)?a:b;
}

int find_max_length(char* s1, char* s2, int i, int j){
	if(i<0 || j <0) return 0;

	if(s1[i] == s2[j]){
		return 1 + find_max_length(s1, s2, i-1, j-1);
	}

	else{
		return  max(find_max_length(s1, s2, i-1, j), find_max_length(s1, s2, i, j-1));
	}

}


int main() {
    char s1[] = "AGGTAB";
    char s2[] = "GXTXAYB";

    int len1 = strlen(s1);
    int len2 = strlen(s2);

    int result = find_max_length(s1, s2, len1 - 1, len2 - 1);
    printf("Length of LCS = %d\n", result);

    return 0;
}


#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

bool isPalindrome(char* str){
	int length = strlen(str);
	if(length==0 || length ==1) return true;
	if(str[0] != str[length-1]) return false;

	char substr[length-1];
	strncpy(substr, str+1, length-2);
	substr[length-2] = '\0';

	return isPalindrome(substr);
}

int main() {
    char word[] = "madam";
    printf("%s -> %s\n", word, isPalindrome(word) ? "Palindrome" : "Not Palindrome");

    char word2[] = "hello";
    printf("%s -> %s\n", word2, isPalindrome(word2) ? "Palindrome" : "Not Palindrome");

    return 0;
}

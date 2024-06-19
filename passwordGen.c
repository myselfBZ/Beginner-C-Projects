#include <stdio.h>
#include <stdlib.h>
#include <sys/random.h>
#include <string.h>
char choice(char* chars, int size);

int main(){
	int len;
	printf("enter the length of your password: ");
	scanf("%d", &len);
	char* chars = "!@#$%^&*()_+[]{}|;:',.<>?/`~ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
	for(int i = 0; i < len; i++){
		int size = strlen(chars); 
		char randomChar = choice(chars, size);
		printf("%c", randomChar);	
	}
	printf("\n");
}

char choice(char* chars, int size){
	unsigned int randomIndex;
	ssize_t result = getrandom(&randomIndex, sizeof(randomIndex), 0);
	if(result < 0){
		printf("error generating a random number");
		exit(result);
	}
	int inRange = (int)(randomIndex %(size - 0 + 1));
	return chars[inRange];
}

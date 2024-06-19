#include <stdio.h>
#include <unistd.h>
int main(){
	char* stars = "**********";
	int indentNumber = 0;
	int direction = 1;
	while(1){
		for(int i = 0; i < indentNumber; i++){
			printf(" ");
		}

		printf("%s\n", stars);

		indentNumber += direction;

		if(indentNumber == 0 || indentNumber == 20){
			direction = -direction;
		}
		sleep(1);
	}
}

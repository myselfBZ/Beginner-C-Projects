#include <stdio.h>

int main(){
	char sections[][12] = {"listening: ", "reading: ", "speaking: ", "writing: "};
	int len = 4;
	float sum;
	for(int i = 0; i < len; i++){
		printf("%s", sections[i]);
		float s; 
		scanf("%f", &s);
		sum += s; 
	}

	sum = sum / 4;
	printf("Your overall score is: %f\n", sum);
	
}

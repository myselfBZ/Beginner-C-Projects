#include <stdio.h>

int main(){
    int height;
    printf("Height: ");
    scanf("%d", &height);
    for(int i=0; i < height; i++){
	 // spaces
	 int space = height - i - 1;
	 
	 for(int s=0; s<space; s++){
	 	printf(" ");
	 }
	 // stars
	 for(int b=0; b <= i; b++){
		    printf("*");
	    }
	 printf(" ");
	 for(int l=0; l<=i; l++){
	 	printf("*");
	 }


    printf("\n");
    }

}

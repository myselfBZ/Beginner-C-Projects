#include <stdio.h>

int collatz(int* n);

int main(){
	int n = 12;
	while(n != 1){
		n = collatz(&n);
		printf("%d\n", n);
	}

}

int collatz(int* n){
	if(*n == 1){
		return *n;
	}
	else if (*n % 2 == 0){
		return *n / 2; 
	}
	return *n * 3 +1;
}



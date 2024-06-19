#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int randomNumber(int lower, int upper)
{

	int num = (rand() % (upper - lower + 1)) + lower;
	return num;
}

int main()
{
	srand(time(0));
	int secretNumber = randomNumber(1, 10);
	int userInput;
	printf("Take a guess: ");
	scanf("%d", &userInput);

	while (secretNumber != userInput)
	{
		printf("Wrong guess. Try again.\nTake a guess: ");
		scanf("%d", &userInput);
	}

	printf("You won the number was %d\n", secretNumber);
}

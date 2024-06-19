#include <stdio.h>
#include <string.h>
#include <stdlib.h>
void readFile(char* name);
void writeFile(char* name);

int main()
{
	writeFile("csv/capitals.csv");
	return 0;

}





void readFile(char* path)
{
	FILE *file = fopen(path, "r");
	if(file == NULL)
	{
		printf("file doesn't exist");
		exit(1);
	}


	char line[1024];
	int index = 1;
	while(fgets(line, sizeof(line), file))
	{
		line[strcspn(line, "\n")] = 0;
		char* token = strtok(line, ",");
		while(token)
		{
			printf("%s\n", token);
			token = strtok(NULL, ",");
		}

	}
	fclose(file);
}

void writeFile(char* name)
{
	FILE *file = fopen("csv/capitals.csv", "a");
	if(file == NULL)
	{
		printf("file doesn't exits\n");
		exit(1);
	}
	fprintf(file, "Canada,Nothing");
	fclose(file);
}
















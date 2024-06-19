#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdarg.h>
#include <dirent.h>
#define RESET "\033[0m"
#define BLUE "\033[31m"
#define MAX_SIZE 2
void removeLF(char* s);
void pwd();
int len(char* str);
void clearShell();
void changeDir(char* path);
void listDir(char *path);
int main(){
	char input[1024];
	while(1){
		printf("$ ");
		fgets(input, sizeof(input), stdin);
		removeLF(input);
		if(strcmp("", input) != 0){
			int index = 0;
			char tokens[MAX_SIZE][1024] = {};
			char* token = strtok(input, " ");
			while(token != NULL){
				if(index < MAX_SIZE){
					strncpy(tokens[index], token, 1024 - 1);

					index++;
					token = strtok(NULL, " ");
				} else{
					printf("too many arguments!");
					break;
				}
			}


			if(strcmp("pwd", tokens[0]) == 0)
			{
				pwd();
			}
			else if (strcmp("clear", tokens[0]) == 0) 
			{
				clearShell();
			}
			else if(strcmp("cd", tokens[0]) == 0)
			{
				changeDir(tokens[1]);
			}

			else if(strcmp("ls", tokens[0]) == 0){
				char path[1024]; 
				getcwd(path, 1024);
				listDir(path);
			} else{
				printf("command not found %s\n", input);
			}
		}

	}
	return 0;
}

void removeLF(char* s){
	int len1 = len(s);
	s[len1 - 1] = 0;
}



int len(char* str){
	int length = 0;
	while(str[length] != '\0'){
		length++;
	}
	return length;
}

void pwd(){
	char output[1024];
	if(getcwd(output, sizeof(output)) == NULL){
		printf("error occured executing command pwd\n");
		exit(1);
	}
	printf("%s\n", output);

}



void clearShell(){
	printf("\033[2J\033[H");
}


void changeDir(char* path){
	if(chdir(path) != 0){
		printf("dir not found: %s\n", path);
		return;
	}
	char cwd[1024]; 
	if(getcwd(cwd, 1024) == NULL){
		printf("error getting the current working dir.");
		exit(1);
	}
	printf("%s\n", cwd);
}

void listDir(char *path){
	struct dirent *entry;
	DIR *dp = opendir(path);

	if(dp == NULL){
		printf("error listing dirs\n");
		exit(1);
	}
	
	while((entry = readdir(dp)) != NULL){
		printf("%s ", entry->d_name);
	}

	printf("\n");

	closedir(dp);

}



















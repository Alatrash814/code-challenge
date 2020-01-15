#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;

int main (int argc, char * argv[]){
	
	FILE * inputFile = fopen("intput.txt", "r");
	char line[1024];
	
	int maxLength = 0;
	int numberOfRows = 0;
	
	while (fgets(line, sizeof(line), inputFile))
	{
		numberOfRows++;
		if (strlen(line) > maxLength)
			maxLength = strlen(line);	
	}
		
	char ** input = new char *[numberOfRows];
	
	for (int i = 0; i < numberOfRows; i++)
	{
		input[i] = new char [maxLength];
		
	}
}

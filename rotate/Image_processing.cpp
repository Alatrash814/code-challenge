#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;

int main (int argc, char * argv[]){
	
	FILE * inputFile = fopen("input.txt", "r");
	FILE * outputFile = fopen("output.txt", "w");
	if (!inputFile)
		cout << "No such a file" << endl;
	
	else {
		
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
		
		rewind (inputFile);
		
		for (int i = 0; i < numberOfRows; i++)
		{
			
			input[i] = new char [maxLength];
			fgets(line, sizeof(line), inputFile);
			strcpy(input[i], line);
			
			for (int j = strlen(input[i]) - 1; j < maxLength; j++)
				input[i][j] = ' ';
				
			input[i][maxLength] = NULL;
				
		}
		
		for (int i = 0 ; i < maxLength; i++)
		{
			for (int j = 0 ; j < numberOfRows; j++)
				fprintf(outputFile,"%c",input[j][i]);
			fprintf(outputFile,"%\n");
		}
	}
}

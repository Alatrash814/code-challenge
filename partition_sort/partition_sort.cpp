#include <iostream>
#include <stdio.h>
#include <algorithm>

using namespace std;
int main(int argc, char* argv[]) {

	FILE * inputFile = fopen ("input.txt", "r");
	FILE * outputFile = fopen ("my-output.txt", "w");
	
	if (!inputFile)
		cout << "No such a file" << endl;
		
	else
	{
		char line [1024];
		char type;
		int begin, end;
		
		while (fgets(line, sizeof(line), inputFile))
		{
			if (line[0] >= '0' && line[0] <= '9')
				type = 0;
			
			else
				type = 1;
			
			begin = 0;
			end = 0;
			
			int i = 0;
			
			for (i = 1; line[i] && i < 1024; i++)
			{
				if ((line[i] >= '0' && line[i] <= '9') && type == 1)
				{
					end = i - 1;
					sort(line + begin, line + end + 1);
					type = 0;
					begin = i;
				}
				
				else if (!(line[i] >= '0' && line[i] <= '9') && type == 0)
				{
					end = i - 1;
					sort(line + begin, line + end + 1);
					type = 1;	
					begin = i;
				}
			}
			
			sort(line + end, line + i - 1);
			fprintf(outputFile, "%s", line);
		}	
	}
	
	fcloseall();
	return 0;		
}

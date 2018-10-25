#!/usr/bin/tcc -run

/*****************************************************************************
 *
 * makeBash.c
 * Author: Matthew Sumpter
 *
 * makeBash receives user commands and writes them to a bashfile.
 * 
 * *************************************************************************/

#include <stdio.h>
#include <string.h>
#define FILELEN 100
#define STRLEN 1000

int main(int argc, char *argv[])
{
	char filename[FILELEN], userInput[STRLEN];
						  
	// user may enter filename as argument or upon executing program
	if (argc > 1)
	{
		strcpy(filename, argv[1]);
	}
	else
	{
		printf("Enter the name of your bash file: ");
		scanf("%s", filename);
	}

	FILE* bashFile = NULL;
	
	while (bashFile == NULL)
	{
		// checks for file extension, adds '.sh' if not
		if ( strstr(filename, ".sh") == NULL)
		{
			strncat(filename, ".sh", 3);
		}
		bashFile = fopen(filename, "w");
		if (bashFile == NULL)
		{
			printf("Error creating %s. Try again.\n",
				filename);
			printf("Enter the name of your bash file: ");
			scanf("%s", filename);
		}
	}
	
	fprintf(bashFile, "# %s\n", filename);
	fprintf(bashFile, "# Created using makeBash\n");
	fprintf(bashFile, "#!/usr/bin/expect -f\n\n");

	do
	{
		memset(userInput, 0, sizeof(userInput));  //clear userInput
		printf("Enter a command (q to quit): ");
		fgets(userInput, STRLEN, stdin);
		if (userInput[0] == 'q' || userInput[0] == 'Q')
			break;
		fprintf(bashFile, "%s", userInput);
	}
	while(1);

	fclose(bashFile);

	return 0;
}

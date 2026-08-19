// Van Quach 1002196157 //

#include <stdio.h>
#include <string.h>
#include "ListLib.h"
#include "DrawTool.h"

FILE *OpenFile(int argc, char *argv[])
{
	FILE *input_file = NULL;

	char filename[MAXMAPSIZE] = {0};

	if (argc == 2)
	{
		if ((strncmp(argv[1], "FILENAME=", 5) == 0))
		{
			strcpy(filename, strchr(argv[1], '=') + 1);
		}
		else
		{
			strcpy(filename, argv[1]);
		}
	}
	else
	{
		printf("\nMust be run with an input file name.\n\n");

		printf("Enter a file name at the prompt ");
		scanf("%s", filename);
	}

	do
	{
		input_file = fopen(filename, "r");

		if (input_file == NULL)
		{
			printf("\nCould not open input file named %s.\n\n", filename);

			printf("Enter a file name at the prompt ");
			scanf("%s", filename);
		}
	}
	while (input_file == NULL);

	return input_file;
}

void ReadFileIntoLinkedList(FILE *DCFile, NODE **LinkedListHead)
{
	char letter;

	char *found = NULL;

	char *token1 = NULL;

	char *token2 = NULL;

	char string[MAXMAPSIZE] = {0};

	char command[MAXMAPSIZE] = {0};

	char delimiter[MAXMAPSIZE] = "|";

	while (fgets(string, MAXMAPSIZE, DCFile))
	{
		found = strchr(string, '\n');

		if (found != NULL)
		{
			*found = '\0';
		}

		token1 = strtok(string, delimiter);

		letter = *token1;

		token2 = strtok(NULL, delimiter);

		strcpy(command, token2);

		AddDrawCommandToList(letter, command, LinkedListHead);
	}
}
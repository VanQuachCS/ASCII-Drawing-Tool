// Van Quach 1002196157 //

#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "DrawTool.h"
#include "ListLib.h"
#include "FileLib.h"

int main(int argc, char *argv[])
{
    int index;

    int row;

    int col;

    int spots;

    char mark;

    char action;

    char letter;

    char *token1 = NULL;

    char *token2 = NULL;

    char *token3 = NULL;

    char *token4 = NULL;

    char *token5 = NULL;

    NODE *TempPtr = NULL;

    FILE *input_file = NULL;

    NODE *LinkedListHead = NULL;

    char command[MAXMAPSIZE] = {0};

    char delimiter[MAXMAPSIZE] = "(),";

    char command_copy[MAXMAPSIZE] = {0};

    char input_string[MAXMAPSIZE] = {0};

    char array[MAXMAPSIZE][MAXMAPSIZE] = {{0}};

    input_file = OpenFile(argc, argv);

    ReadFileIntoLinkedList(input_file, &LinkedListHead);

    printf("\n");

    InitializeMap(array);

    printf("\n");

    printf("Please enter 1-3 letters ");
    scanf("%s", input_string);

    while ((strlen(input_string) < 1) || (strlen(input_string) > 3))
    {
        printf("\nPlease enter 1-3 letters ");
        scanf("%s", input_string);
    }

    for (index = 0; index < strlen(input_string) + 1; index++)
    {
        letter = toupper(input_string[index]);

        TempPtr = FindLetter(LinkedListHead, letter, command);

        while (command[0] != '\0')
        {
            strcpy(command_copy, command);

            token1 = strtok(command_copy, delimiter);

            action = toupper(*token1);

            token2 = strtok(NULL, delimiter);

            row = atoi(token2);

            token3 = strtok(NULL, delimiter);

            col = atoi(token3);

            col += index * 7;

            token4 = strtok(NULL, delimiter);

            (action == 'P') ? (spots = 1) : (spots = atoi(token4));

            token5 = strtok(NULL, delimiter);

            mark = *token5;

            DrawLine(array, row, col, action, spots, mark);

            TempPtr = FindLetter(TempPtr, letter, command);
        }
    }

    printf("\n");

    PrintMap(array);

    return 0;
}
// Van Quach 1002196157 //

#include "ListLib.h"

void AddDrawCommandToList(char letter, char command[], NODE**LinkedListHead)
{
    NODE *TempPtr = NULL;

	NODE *NewNode = NULL;

	NewNode = malloc(sizeof(NODE));

	NewNode->Letter = letter;

	NewNode->DrawCommand = malloc(strlen(command) + 1);

	strcpy(NewNode->DrawCommand, command);

	NewNode->next_ptr = NULL;

	if (*LinkedListHead == NULL)
	{
		*LinkedListHead = NewNode;
	}
	else
	{
		TempPtr = *LinkedListHead;

		while (TempPtr->next_ptr != NULL)
		{
			TempPtr = TempPtr->next_ptr;
		}

		TempPtr->next_ptr = NewNode;
	}
}

NODE *FindLetter(NODE *LinkedListHead, char Letter, char DC[])
{
	NODE *TempPtr = LinkedListHead;

	while ((TempPtr != NULL) && (TempPtr->Letter != Letter))
	{
		TempPtr = TempPtr->next_ptr;
	}

	if (TempPtr != NULL)
	{
		strcpy(DC, TempPtr->DrawCommand);

		return TempPtr->next_ptr;
	}
	else
	{
		memset(DC, '\0', sizeof(*DC));

		return TempPtr;
	}
}
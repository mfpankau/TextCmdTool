#include <stdio.h>
#include <string.h>
#pragma warning(disable : 4996)

int addText(char[], char[]);
int overwriteText(char[], char[]);
const char* readText(char[]);
int removeFile(char[]);
int renameFile(char[], char[]);

int main(int argc, char* argv[])
{
	char* data;
	if (strcmp(argv[1], "write") == 0)
	{
		printf("Mode selected: writing\n");
		if (strcmp(argv[2], "override") == 0)
		{
			printf("Override is now on\n");
			printf("Writing...\n");
			overwriteText(argv[3], argv[4]);
		}
		else
		{
			printf("Writing...\n");
			addText(argv[2], argv[3]);
		}
	}
	if (strcmp(argv[1], "read") == 0)
	{
		printf("Reading...\n"); 
		data = readText(argv[2]);
		printf("Done!\nYour data: \n%s\n", data);

	}
	if (strcmp(argv[1], "remove") == 0)
	{
		printf("Removing file...\n");
		remove(argv[2]);
	}
	if (strcmp(argv[1], "rename") == 0)
	{
		printf("Renaming file...\n");
		rename(argv[2], argv[3]);
	}

}
int addText(char path[], char text[])
{
	FILE* filePointer;
	filePointer = fopen(path, "a");
	if (filePointer != NULL)
	{
		fprintf(filePointer, "%s\n", text);
		fclose(filePointer);
		printf("Done!");
		return 0;
	}
	else
	{
		printf("Something went wrong with opening the file! Better luck next time. gg ez");
	}
}
int overwriteText(char path[], char text[])
{
	FILE* filePointer;
	filePointer = fopen(path, "w");
	if (filePointer != NULL)
	{
		fprintf(filePointer,"%s\n", text);
		fclose(filePointer);
		printf("Done!");
		return 0;
	}
	else 
	{
		printf("Something went wrong with opening the file! Better luck next time. gg ez");
	}
}
const char* readText(char path[])
{
	char* returnText;
	long fileLength;
	FILE* filePointer;
	filePointer = fopen(path, "r");
	if (filePointer != NULL)
	{
		//get length of file
		fseek(filePointer, 0L, SEEK_END);
		fileLength = ftell(filePointer);
		fseek(filePointer, 0L, SEEK_SET);
		returnText = (char*)calloc(fileLength, sizeof(char));
		//start reading
		fread(returnText, sizeof(char), fileLength, filePointer);
		//close file and return text
		fclose(filePointer);
		return returnText;
	}
	else
	{
		//file opened incorrectly
		printf("Something went wrong with opening the file! Better luck next time. gg ez\n");
		return NULL;
	}
}
int removeFile(char path[])
{
	if (remove(path) == 0)
	{
		printf("Removed file successfully!\n");
		return 0;
	}
	else
	{
		printf("Something went wrong. File probably not found!");
	}
}
int renameFile(char oldName[], char newName[])
{
	if (rename(oldName, newName) == 0)
	{
		printf("Successfully renamed file!\n");
	}
	else
	{
		printf("Something went wrong. Make sure the file is closed and try again.");
	}
}
 
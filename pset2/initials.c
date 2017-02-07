#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>


int main(void)
{
	//printf("Please, enter your name: ");
	string name = GetString();

	for(int i = 0, n = strlen(name); i < n;  )
	{
		if(name[i] == 32)
		{
			i++;
		}
		else
		{
			printf("%c", toupper(name[i]));
			while(name[i] != 32 && i < n)
			{
				i++;
			}
					
		}
	}
	printf("\n");
}

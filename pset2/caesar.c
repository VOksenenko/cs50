#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(int argc, string argv[])
{
	if(argc !=2)	
	{
		printf("argc !=2\n");
		return 1;
	}
	int k = atoi(argv[1]);
	if(k < 1)
	{
		printf("argv[1] < 1\n");
		return 1;
	}
	else 
	{
		//printf("Enter your message: ");
		string message= GetString();
		
		for(int i = 0, n = strlen(message); i < n; i++)
		{
			if(isalpha(message[i]))
			{
				if(isupper(message[i]))
				{
					//шифруем верхние символы.					
					int letter = message[i];
					letter = (letter + k)%91 ;					 
					if( letter < 65)
					{
						letter = letter + 65;
					}
					printf("%c", letter );
				}
				else
				{
					//шифруем нижние символы.					
					int letter = message[i];
					letter = letter + k%26;					 
					if(letter > 122)
					{
						letter = letter%123+97;
					}
					printf("%c", letter );
				}
						
				
			}
			else
			{
				printf("%c", message[i]);
			}
			
		}
		printf("\n");
	}
			
}

#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(int argc, string argv[])
{
	// проверям, что введен один аргумент.
	if(argc !=2)	
	{
		printf("argc !=2\n");
		return 1;
	}

	//проверям, что ключ состоит только из символов алфавита.
	for(int i = 0, n = strlen(argv[1]); i < n; i++)
	{
		if(!isalpha(argv[1][i]))
		{
			printf("key is no valid.\n");
			return 1;			
		}		
	}	
	
	string key = argv[1];
	
	//сначала сделаем все буквы ключа маленькими.
	for(int i = 0, n = strlen(key); i < n; i++)
	{
		char c = key[i];
		c = tolower(c);
		key[i] = c;
	}
	//printf("Now your key is '%s'\n", key);

	string message= GetString();
	//printf("Your message is: '%s'\n", message);

	//шифруем
	for (int i = 0, j=0, n = strlen(message); i < n; i++)
	{
		if (message[i] >= 'a' && message[i] <= 'z')
		{
			char letter = message[i];
			int shift = (key[j%strlen(key)] - 'a');
			letter = (letter - 'a' + shift)%26 + 'a';
			printf("%c", letter);
			//printf("%d + %d is %c\n", message[i], shift, letter);
			j++;
		}
		else if (message[i] >= 'A' && message[i] <= 'Z')
		{
			char letter = message[i];
			int shift = (key[j%strlen(key)] - 'a');
			letter = (letter - 'A' + shift)%26 + 'A';
			printf("%c", letter);
			//printf("%d + %d is %c\n", message[i], shift, letter);
			j++;
		}
		else
		{
			printf("%c", message[i]);
		}
	}		
	
	//переводит курсор после выполнения программы.
	printf("\n");
}

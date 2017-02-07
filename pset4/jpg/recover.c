/**
 * recover.c
 *
 * Computer Science 50
 * Problem Set 4
 *
 * Recovers JPEGs from a forensic image.
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h> // uint8_t
#include <string.h> // memcmp

int main(int argc, char* argv[])
{
    uint8_t* buffer = malloc(512);
	char *title = malloc(8);
	int index = 0;
	uint8_t header1[4] = {0xff, 0xd8, 0xff, 0xe0};
	uint8_t header2[4] = {0xff, 0xd8, 0xff, 0xe1};
	FILE *outptr = NULL;
	
	// открывает исходный файл  
	FILE* inptr = fopen("card.raw", "r");

	// считывать в буфер по 512 байт пока не дойдем до конца файла
	while(fread(buffer, 512, 1, inptr) == 1)
	{
		// проверяем есть ли сигнатуры jpg в буфере
		if(memcmp(buffer, header1, 4)==0 || memcmp(buffer, header2, 4)==0)
		{
			if(outptr != NULL)
			{
				fclose(outptr);
    		}
			
			//формируем название выходного файла, создаем выходной файл с 
			//созданным названием
			sprintf(title, "%03d.jpg", index);
			index++;
			outptr = fopen(title, "w");

		}
		// если файл открыт, пишем в него.
		if (outptr !=NULL)
		{
         	fwrite(buffer, 1, 512, outptr);
      	}		
		
	}
	// освобождаем память и закрываем файлы.
	free(buffer);
	free(title);
	fclose(inptr);
	fclose(outptr);
	return 0;
}

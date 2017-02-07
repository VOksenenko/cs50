uint8_t *buffer = malloc(512); 
uint8_t header1[4] = {0xff, 0xd8, 0xff, 0xe0};
uint8_t header2[4] = {0xff, 0xd8, 0xff, 0xe1};
char *zz = malloc(8); 
FILE *dd = NULL; 
int index = 0;

while (fread(buffer, 512, 1, raz) == 1)
{ 
// ищем заголовок файла 
if (memcmp(buffer, header1, 4)==0 || memcmp(buffer, header2, 4)==0)
{
	if (dd != NULL) // закрываем предыдущий файл,если он был открыт
	{
		fclose(dd);
	}
	sprintf(zz, "%03d.jpg",fileIndex);
	index ++;
    dd = fopen(zz,"w"); //открываем выходной файл для записи
}

if(dd != NULL)         // отсекаем мусор до первого открытого файла
{
	fwrite(buffer, 512, 1, dd);   //запись в выходной файл
}

        
} 
  free(buffer);

  fclose(raz);
  fclose(dd);
  return 0;




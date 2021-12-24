#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

void Exercise_1(char* str)
{
	char alpha[100] = {""};
	char omega[100] = {""};

////////////// Сохраняем первое слово //////////////

	for (int i = 0; str[i] != ' '; i++)
		alpha[i] = str[i];

////////////// Считаем количество пробелов //////////////

	int number_separators = 0;

	for (int i = 0; str[i] != '\0'; i++)
	{
		if (str[i] == ' ')
			number_separators++;
	}

////////////// Сохраняем последнее слово //////////////

	int counter = 0;
	int j = 0;

	for (int i = 0; str[i] != '\0'; i++)
	{
		if (str[i] == ' ')
			counter++;

		if(counter == number_separators)
		{
			omega[j] = str[i];
			j++;
		}
	}

////////////// Создаем строку с измененным порядком слов //////////////

	char str_modified[300] = {""};

	counter = 0;

	j = 0;

	if (str_modified)
	{
		for (int i = 0; counter == 0 && omega[i] != '\0'; i++)
		{
			str_modified[j] = omega[i];
			j++;
		}

		str_modified[j] = ' ';
		j++;

		for (int i = 0; str[i] != '\0'; i++)
		{
			if (number_separators != counter && counter != 0)
			{
				str_modified[j] = str[i];
				j++;
			}
			if (str[i] == ' ')
				counter++;
		}

		for (int i = 0; counter == number_separators && alpha[i] != '\0'; i++)
		{
			str_modified[j] = alpha[i];
			j++;
		}

		printf("%s", str_modified);
	}
}


// Я так и не смог до конца исправить это задание

void Exercise_3()
{
   int counter = 0;

   char str[200];

   char str2[200];

   FILE* Russian_text;

   fopen_s(&Russian_text, "f.txt", "r");

   FILE* No_P4;

   fopen_s(&No_P4, "g.txt", "w");

   if (Russian_text != NULL)
      fgets(str, 200, Russian_text);

   for (int i = 0; str[i] != '\0'; i++)
   {
      if (counter != 3)
         str2[i] = str[i];
      if (str[i] == ' ' && counter != 3)
      {
         counter++;
      }
      if (counter == 3 && str[i] == ' ')
      {
         counter = 0;
      }
      if (i > 1)
      {
         if ((str[i] == 'П' || str[i] == 'п') && str[i - 1] == ' ')
            counter++;
      }
   }
   if (No_P4 != NULL && Russian_text != NULL)
   {
      fprintf(No_P4, "%s", str2);
      fclose(Russian_text);
      fclose(No_P4);
   }
}

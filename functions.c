#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

// Я так и не смог до конца исправить это задание

void Exercise_3();

int main()
{
   setlocale(LC_ALL, "Russian");
   Exercise_3();
   return 0;
}

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

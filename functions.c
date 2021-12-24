#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

//////////////////////////////////////////////// Задание №1 ////////////////////////////////////////////////

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

	/* Была идея так написать, но ответ был ни совсем верным
	int n = strlen(str);

	char* str_modified = (char*)malloc(n * sizeof(char));
	*/
	
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

//////////////////////////////////////////////// Задание №2 ////////////////////////////////////////////////

void Exercise_2()
{
    struct Information
    {
        char Surname[100];
        char Name[100];
        char Patronymic[100];
        char Gender[50];
        char Position[200];
        int  Mount, Year;
    };

    int n;

    printf("Enter the number of people: \n");

    scanf_s("%d", &n);

    struct Information* list = (struct Information*)malloc(n * sizeof(struct Information));

    for (int i = 1; i <= n; i++)
    {
        printf("Enter Surname employee number %d\n", i);
        fscanf_s(stdin, "%s", list[i].Surname, 100);

        printf("Enter Name employee number %d\n", i);
        fscanf_s(stdin, "%s", list[i].Name, 100);

        printf("Enter Patronymic employee number %d\n", i);
        fscanf_s(stdin, "%s", list[i].Patronymic, 100);

        printf("Enter Gender employee number (Note: capitalize the first letter) %d\n", i);
        fscanf_s(stdin, "%s", list[i].Gender, 50);

        printf("Enter Position employee number (Note: capitalize the first letter) %d\n", i);
        fscanf_s(stdin, "%s", list[i].Position, 100);

        printf("Enter Year employee number %d\n", i);
        fscanf_s(stdin, "%d", &list[i].Year);

        printf("Enter Mount employee number %d\n", i);
        fscanf_s(stdin, "%d", &list[i].Mount);
    }

    int year_now, mount_now;

    printf("Enter the current year:\n");
    scanf_s("%d", &year_now);

    printf("Enter the current mount:\n");
    scanf_s("%d", &mount_now);

    for (int i = 1; i <= n; i++)
    {
        int age = 0;

        if (year_now > list[i].Year)
        {
            if (mount_now >= list[i].Mount)
                age = year_now - list[i].Year;
            else
                age = year_now - list[i].Year - 1;
        }

        if (strcmp(list[i].Position, "Engineer") == 0)
        {
            if (strcmp(list[i].Gender, "Male") == 0 && age >= 65)
            {
                printf("Surname: %s\n", list[i].Surname);
                printf("Name: %s\n", list[i].Name);
                printf("Patronymic: %s\n", list[i].Patronymic);
                printf("Gender: %s\n", list[i].Gender);
                printf("Position: %s\n", list[i].Position);
                printf("Year of birth: %d\n", list[i].Year);
            }
            if (strcmp(list[i].Gender, "Female") == 0 && age >= 60)
            {
                printf("Surname: %s\n", list[i].Surname);
                printf("Name: %s\n", list[i].Name);
                printf("Patronymic: %s\n", list[i].Patronymic);
                printf("Gender: %s\n", list[i].Gender);
                printf("Position: %s\n", list[i].Position);
                printf("Year of birth: %d\n", list[i].Year);
            }
        }
    }
}


//////////////////////////////////////////////// Задание №3 ////////////////////////////////////////////////

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

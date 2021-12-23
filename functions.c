#include <stdio.h>
#include <stdlib.h>
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
    
    FILE *Russian_text;
    
    Russian_text = fopen("f.txt", "r");
    
    FILE *No_P4;
    
    No_P4 = fopen("g.txt", "w");

    fgets(str, 200, Russian_text);
    
    for(int i = 0; str[i] != '\0'; i++)
    {
        if (str[i] == ' ' && counter != 3 && str[i] != 'П' && str[i] != 'п')
        {
            str2[i] = str[i];
            printf("%s", str2);
            counter++;
        }
        if (counter == 3 && str[i] == ' ')
        {
            counter = 0;
        }
        if (str[i] == 'П' && str[i] == 'п')
        {
            counter++;
        }
    }
    
    fprintf(No_P4, "%s", str2);

    fclose(Russian_text);
    fclose(No_P4);
}

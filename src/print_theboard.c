#include "../includes/chess.h"

void    print_firstandlast()
{
    int     n = 3;
    char    c = 'a';

    for (int i = 0; i < 35; i++)
    {
        if (i == n && c <= 'h')
        {
            printf("%c", c);
            c++;
            n += 4;
        }
        else
            printf(" ");
    }
    printf("\n");
}

void    print_theborderline()
{
    int n = 1;

    for (int i = 0; i < 35; i++)
    {
        if (i == 0 || i == 34)
            printf(" ");
        else if (i == n)
        {
            printf("+");
            n += 4;
        }
        else
            printf("-");
    }
    printf("\n");
}

void    print_fromthematrix(char **matrix, int i, char c)
{
    int     j = 0;

    while (j < 8)
    {
        if (j == 0 && c > '0')
            printf("%c", c);
        printf("| ");
        if (matrix[i][j] >= 'A' && matrix[i][j] <= 'Z')
        {
             printf("W%c", matrix[i][j]);
        }
        else if (matrix[i][j] >= 'a' && matrix[i][j] <= 'z')
        {
            printf("B%c", matrix[i][j] - 32);
        }
        else if (matrix[i][j] == ' ')
            printf("  ");
        if (j == 7)
            printf("|%c", c);
        j++;
    }
    printf("\n");
}

void    print_theboard(char **matrix)
{
    int     i = 0;
    char    c = '8';

    while (i < 8)
    {
        if (i == 0)
            print_firstandlast();
        print_theborderline();
        print_fromthematrix(matrix, i, c);
        c--;
        if (i == 7)
        {
            print_theborderline();
            print_firstandlast();
        }
        i++;
    }
    printf("\n");
}
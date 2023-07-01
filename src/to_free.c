#include "../includes/chess.h"

void    to_free(char **matrix, int i)
{
    int x = 0;

    while (x < i)
    {
        free(matrix[x]);
        x++;
    }
    free(matrix);
}
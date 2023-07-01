#include "chess.h"
#include <string.h>

static void fill_straight(char **matrix, int i_king, int j_king, Color color);
static void fill_diagonal(char **matrix, int i, int j, Color color, int *depth);
static int knight_check(char **matrix, int i_king, int j_king, Color color);


static char **strdup_2d(char **matrix)
{
    char    **dup;

    dup = (char **)malloc(sizeof(char *) * 8);
    for (int i = 0; i < 8; i++)
    {
        dup[i] = (char *)malloc(sizeof(char) *  8);
        for (int j = 0; j < 8; j++)
        {
            dup[i][j] = matrix[i][j];
        }
    }
    return (dup);
}

void    king_checked(char **matrix, int i_king, int j_king, Color color)
{
    int     depth = 0;
    char    **dup = NULL;


    dup = strdup_2d(matrix);
    fill_straight(dup, i_king, j_king, color); // matrix should be dupped
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            if (dup[i][j] == CHECK_FLAG)
            {
                printf("CHECK !\n");
                break ;
            }
        }
    }
    to_free(dup, 8);
    dup = strdup_2d(matrix);
    fill_diagonal(dup, i_king, j_king, color, &depth);
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            if (dup[i][j] == CHECK_FLAG)
            {
                printf("CHECK !\n");
                break ;
            }
        }
    }
    to_free(dup, 8);
    if (knight_check(matrix, i_king, j_king, color) == 1)
        printf("CHECK !\n");
}

static void fill_straight(char **matrix, int i_king, int j_king, Color color)
{
    if (i_king < 0 || j_king < 0 || i_king >= 8 || j_king >= 8)
        return ;
    if (matrix[i_king][j_king] == FILL_FLAG)
        return ;
    if (color == BLACK && (matrix[i_king][j_king] == 'R' || matrix[i_king][j_king] == 'Q'))
    {
        matrix[i_king][j_king] = CHECK_FLAG;
        return ;
    }
    if (color == WHITE && (matrix[i_king][j_king] == 'r' || matrix[i_king][j_king] == 'q'))
    {
        matrix[i_king][j_king] = CHECK_FLAG;
        return ;
    }
    matrix[i_king][j_king] = FILL_FLAG;
    fill_straight(matrix, i_king + 1, j_king, color);
    fill_straight(matrix, i_king, j_king + 1, color);
    fill_straight(matrix, i_king - 1, j_king, color);
    fill_straight(matrix, i_king, j_king - 1, color);
}

static void fill_diagonal(char **matrix, int i_king, int j_king, Color color, int *depth)
{
    if (i_king < 0 || j_king < 0 || i_king >= 8 || j_king >= 8)
        return ;
    if (matrix[i_king][j_king] == FILL_FLAG)
        return ;
    if (color == BLACK && (matrix[i_king][j_king] == 'B' || matrix[i_king][j_king] == 'Q'
        || (*depth == 1 && matrix[i_king][j_king] == 'P')))
    {
        matrix[i_king][j_king] = CHECK_FLAG;
        return ;
    }
    if (color == WHITE && (matrix[i_king][j_king] == 'b' || matrix[i_king][j_king] == 'q'
        || (*depth == 1 && matrix[i_king][j_king] == 'p')))
    {
        matrix[i_king][j_king] = CHECK_FLAG;
        return ;
    }
    (*depth)++;
    if (matrix[i_king][j_king] != CHECK_FLAG)
        matrix[i_king][j_king] = FILL_FLAG;
    fill_diagonal(matrix, i_king + 1, j_king + 1, color, depth);
    fill_diagonal(matrix, i_king + 1, j_king - 1, color, depth);
    fill_diagonal(matrix, i_king - 1, j_king + 1, color, depth);
    fill_diagonal(matrix, i_king - 1, j_king - 1, color, depth);
}

static int knight_check(char **matrix, int i_king, int j_king, Color color)
{
    if (color == WHITE)
    {
        if (i_king + 2 >= 0 && i_king + 2 < 8 && j_king + 1 >= 0 && j_king + 1 < 8)
        {
            if (matrix[i_king + 2][j_king + 1] == 'n')
                return (1);
        }
        if (i_king + 2 >= 0 && i_king + 2 < 8 && j_king - 1 >= 0 && j_king - 1 < 8)
        {
            if (matrix[i_king + 2][j_king - 1] == 'n')
                return (1);
        }
        if (i_king - 2 >= 0 && i_king - 2 < 8 && j_king + 1 >= 0 && j_king + 1 < 8)
        {
            if (matrix[i_king - 2][j_king + 1] == 'n')
                return (1);
        }
        if (i_king - 2 >= 0 && i_king - 2 < 8 && j_king - 1 >= 0 && j_king - 1 < 8)
        {
            if (matrix[i_king - 2][j_king - 1] == 'n')
                return (1);
        }
        if (i_king + 1 >= 0 && i_king + 1 < 8 && j_king + 2 >= 0 && j_king + 2 < 8)
        {
            if (matrix[i_king + 1][j_king + 2] == 'n')
                return (1);
        }
        if (i_king + 1 >= 0 && i_king + 1 < 8 && j_king - 2 >= 0 && j_king - 2 < 8)
        {
            if (matrix[i_king + 1][j_king - 2] == 'n')
                return (1);
        }
        if (i_king - 1 >= 0 && i_king - 1 < 8 && j_king + 2 >= 0 && j_king + 2 < 8)
        {
            if (matrix[i_king - 1][j_king + 2] == 'n')
                return (1);
        }
        if (i_king - 1 >= 0 && i_king - 1 < 8 && j_king - 2 >= 0 && j_king - 2 < 8)
        {
            if (matrix[i_king - 1][j_king - 2] == 'n')
                return (1);
        }
    }
    if (color == BLACK)
    {
        if (i_king + 2 >= 0 && i_king + 2 < 8 && j_king + 1 >= 0 && j_king + 1 < 8)
        {
            if (matrix[i_king + 2][j_king + 1] == 'N')
                return (1);
        }
        if (i_king + 2 >= 0 && i_king + 2 < 8 && j_king - 1 >= 0 && j_king - 1 < 8)
        {
            if (matrix[i_king + 2][j_king - 1] == 'N')
                return (1);
        }
        if (i_king - 2 >= 0 && i_king - 2 < 8 && j_king + 1 >= 0 && j_king + 1 < 8)
        {
            if (matrix[i_king - 2][j_king + 1] == 'N')
                return (1);
        }
        if (i_king - 2 >= 0 && i_king - 2 < 8 && j_king - 1 >= 0 && j_king - 1 < 8)
        {
            if (matrix[i_king - 2][j_king - 1] == 'N')
                return (1);
        }
        if (i_king + 1 >= 0 && i_king + 1 < 8 && j_king + 2 >= 0 && j_king + 2 < 8)
        {
            if (matrix[i_king + 1][j_king + 2] == 'N')
                return (1);
        }
        if (i_king + 1 >= 0 && i_king + 1 < 8 && j_king - 2 >= 0 && j_king - 2 < 8)
        {
            if (matrix[i_king + 1][j_king - 2] == 'N')
                return (1);
        }
        if (i_king - 1 >= 0 && i_king - 1 < 8 && j_king + 2 >= 0 && j_king + 2 < 8)
        {
            if (matrix[i_king - 1][j_king + 2] == 'N')
                return (1);
        }
        if (i_king - 1 >= 0 && i_king - 1 < 8 && j_king - 2 >= 0 && j_king - 2 < 8)
        {
            if (matrix[i_king - 1][j_king - 2] == 'N')
                return (1);
        }
    }
    return (0);
}
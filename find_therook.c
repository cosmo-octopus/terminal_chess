#include "chess.h"

static void    reset(int i_pos, int j_pos, int *i, int *j)
{
    *i = i_pos;
    *j = j_pos;
}

char    *find_therook(char **matrix, char color, char *position)
{
    int     j_pos = position[0] - 97;
    int     i_pos = position[1];
    int     i = i_pos;
    int     j = j_pos;
    char    rook;
    int     possible_pieces = 0;
    char    *found_position;

    found_position = (char *)malloc(sizeof(char) * 2);
    if (color == 'W')
        rook = 'R';
    else
        rook = 'r';

    while (j >= 0 && j < j_pos) // LEFT CHECK
    {
        if (matrix[i][j] == rook)
        {
            possible_pieces++;
            found_position[0] = i + '0';
            found_position[1] = j + 97;
            break;
        }
        if (matrix[i][j] != ' ' && matrix[i][j] != rook)
            break;
        j--;
    }
    printf("LEFT CHECK: %s\n", found_position);
    reset(i_pos, j_pos, &i, &j);
    while (j > j_pos && j <= 7 && possible_pieces < 2) // RIGHT CHECK
    {
        if (matrix[i][j] == rook)
        {
            possible_pieces++;
            found_position[0] = i + '0';
            found_position[1] = j + 97;
            break;
        }
        if (matrix[i][j] != ' ' && matrix[i][j] != rook)
            break;
        j++;
    }
    printf("RIGHT CHECK: %s\n", found_position);
    reset(i_pos, j_pos, &i, &j);
    while (i >= 0 && i < i_pos) // TOP CHECK
    {
        if (matrix[i][j] == rook)
        {
            possible_pieces++;
            found_position[0] = i + '0';
            found_position[1] = j + 97;
            break;
        }
        if (matrix[i][j] != ' ' && matrix[i][j] != rook)
            break;
        i--;
    }
    printf("TOP CHECK: %s\n", found_position);
    reset(i_pos, j_pos, &i, &j);
    while (i > i_pos && i < 8) // BOTTOM CHECK
    {
        if (matrix[i][j] == rook)
        {
            possible_pieces++;
            printf("POSSIBLE PIECES: %d\n", possible_pieces);
            found_position[0] = i + '0';
            found_position[1] = j + 97;
            break;
        }
        if (matrix[i][j] != ' ' && matrix[i][j] != rook)
            break;
        i++;
    }
    printf("BOTTOM CHECK: %s\n", found_position);
    if (possible_pieces == 1)
        return (found_position);
    else
        return (NULL);
}
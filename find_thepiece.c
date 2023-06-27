#include "chess.c"

int final_pos_check(char **matrix, char color, char *position)
{
    int j = position[0] - 97;
    int i = position[1];

    if (matrix[i][j] == ' ')
        return (0);
    if (color == 'W' && (matrix[i][j] >= 'a' && matrix[i][j] <= 'z'))
        return (0);
    else if (color == 'B' && (matrix[i][j] >= 'A' && matrix[i][j] <= 'Z'))
        return (0);
    else
        return (1);
}

int find_therook(char **matrix, char color, char *position)
{
    int     j_pos = position[0] - 97;
    int     i_pos = position[1];
    int     i = i_pos;
    int     j = j_pos;
    char    rook;
    int     possible_pieces = 0;

    if (color == 'W')
        rook = 'R';
    else
        rook = 'r';
    while (j >= 0 && j <= j_pos)
    {
        if (matrix[i][j] == rook)
        {
            possible_pieces++;
            break;
        }
        if (matrix[i][j] != ' ' && matrix[i][j] != rook)
            break;
        j--;
    }
}
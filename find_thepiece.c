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

char    *find_therook(char **matrix, char color, char *position)
{
    int     j_pos = position[0] - 97;
    int     i_pos = position[1];
    int     i = i_pos;
    int     j = j_pos;
    char    rook;
    int     possible_pieces = 0;
    char    found_position[2];

    if (color == 'W')
        rook = 'R';
    else
        rook = 'r';

    while (j >= 0 && j <= j_pos)
    {
        if (matrix[i][j] == rook)
        {
            possible_pieces++;
            found_position[0] = i + '0';
            found_position[1] = j + 97;
        }
        if (matrix[i][j] != ' ' && matrix[i][j] != rook)
            break;
        j--;
    }
    while (j > j_pos && j <= 7 && possible_pieces < 2)
    {
        if (matrix[i][j] == rook)
            possible_pieces++;
        if (matrix[i][j] != ' ' && matrix[i][j] != rook)
            break;
        j++;
    }

}
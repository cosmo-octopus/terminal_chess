#include "chess.h"

int final_pos_check(char **matrix, char color, char *position)
{
    int i = (position[1] - 56) * -1;
    int j = position[0] - 97;

    //printf("%d %d\n", i, j);
    if (matrix[i][j] == ' ')
        return (0);
    if (color == 'W' && (matrix[i][j] >= 'a' && matrix[i][j] <= 'z'))
        return (0);
    else if (color == 'B' && (matrix[i][j] >= 'A' && matrix[i][j] <= 'Z'))
        return (0);
    else
        return (1);
}

char    *define_thepiece(char **matrix, char *piece, char *position)
{
    printf("COLOR: %c\n", piece[0]);
    if (piece[0] != 'W' && piece[0] != 'B')
    {
        error();
        return (NULL);
    }
    if (piece[1] == 'R')
        return (find_therook(matrix, piece[0], position));
    // else if (piece[1] == 'N')
    //     return (find_thekinight(matrix, piece[0], position));
    // else if (piece[1] == 'B')
    //     return (find_thebishop(matrix, piece[0], position));
    // else if (piece[1] == 'Q')
    //     return (find_thequeen(matrix, piece[0], position));
    // else if (piece[1] == 'K')
    //     return (find_theking(matrix, piece[0], position));
    // else if (piece[1] == 'P')
    //     return (find_thepawn(matrix, piece[0], position));
    else
    {
        error();
        return (NULL);
    }
}

int check_position_range(char *position)
{
    if (position[0] < 'a' || position[0] > 'h')
        return (1);
    if (position[1] < '1' || position[1] > '8')
        return (1);
    return (0);
}

char    **input_parsing(char *cmd)
{
    char    **cmd_parts;
    int     i = 0;

    cmd_parts = ft_split(cmd, ' ');
    while (cmd_parts[i])
        i++;
    if (i != 2)
        return (NULL);
    return (cmd_parts);
}
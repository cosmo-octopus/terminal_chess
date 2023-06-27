#include "chess.h"

int define_thepiece(char **matrix, char *piece, char *position)
{
    if (piece[0] != 'W' || piece[1] != 'B')
        return (error());
    if (piece[1] == 'R')
        return (find_therook(matrix, piece[0], position));
    else if (piece[1] == 'N')
        return (find_thekinight(matrix, piece[0], position));
    else if (piece[1] == 'B')
        return (find_thebishop(matrix, piece[0], position));
    else if (piece[1] == 'Q')
        return (find_thequeen(matrix, piece[0], position));
    else if (piece[1] == 'K')
        return (find_theking(matrix, piece[0], position));
    else if (piece[1] == 'P')
        return (find_thepawn(matrix, piece[0], position));
    else
        return (error());
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
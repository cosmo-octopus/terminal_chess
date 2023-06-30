#include "chess.h"

int define_thepiece(char **matrix, char *piece, char *start_pos, char *final_pos)
{
    if (piece[0] != 'W' && piece[0] != 'B')
    {
        error();
        return (1);
    }
    if (piece[1] == 'R')
        return(rook_action(matrix, piece, start_pos, final_pos));
    else if (piece[1] == 'N')
        return (knight_action(matrix, piece, start_pos, final_pos));
    else if (piece[1] == 'B')
        return (bishop_action(matrix, piece, start_pos, final_pos));
    // else if (piece[1] == 'Q')
    //     return (find_thequeen(matrix, piece[0], position));
    // else if (piece[1] == 'K')
    //     return (find_theking(matrix, piece[0], position));
    // else if (piece[1] == 'P')
    //     return (find_thepawn(matrix, piece[0], position));
    else
    {
        error();
        return (1);
    }
}

int finalpos_path_check(char **matrix, char **cmd_parts)
{
    char    piece = cmd_parts[0][1];
    int i = 0;
    int j = 0;

    if (piece == 'N')
        return (0);
    else if (piece == 'R')
        return (rook_path_check(matrix, cmd_parts[1], cmd_parts[2]));
    else if (piece == 'B')
        return (bishop_path_check(matrix, cmd_parts[1], cmd_parts[2]));
    return (1);
}

int final_pos_check(char **matrix, char color, char *position)
{
    int i = (position[1] - 56) * -1;
    int j = position[0] - 97;

    if (matrix[i][j] == ' ')
        return (0);
    if (color == 'W' && (matrix[i][j] >= 'a' && matrix[i][j] <= 'z'))
        return (0);
    else if (color == 'B' && (matrix[i][j] >= 'A' && matrix[i][j] <= 'Z'))
        return (0);
    else
        return (1);
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
    if (i != 3)
        return (NULL);
    return (cmd_parts);
}
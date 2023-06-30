#include "chess.h"

int path_check(char **matrix, char **cmd_parts)
{
    char    piece = cmd_parts[0][1];
    int i = 0;
    int j = 0;
    int queen;

    if (piece == 'N')
        return (0);
    else if (piece == 'R')
        return (rook_path_check(matrix, cmd_parts[1], cmd_parts[2]));
    else if (piece == 'B')
        return (bishop_path_check(matrix, cmd_parts[1], cmd_parts[2]));
    else if (piece == 'Q')
    {
        if (!rook_path_check(matrix, cmd_parts[1], cmd_parts[2]) 
            || !bishop_path_check(matrix, cmd_parts[1], cmd_parts[2]))
        {
            return (0);
        }
    }
    else if (piece == 'K')
        {
            // CHECK CHECK !!
            return (0);
        }
    return (1);
}

int rook_path_check(char **matrix, char *start_pos, char *final_pos)
{
    int j_start = start_pos[0] - 97;
    int i_start = (start_pos[1] - 56) * -1;
    int j_final = final_pos[0] - 97;
    int i_final = (final_pos[1] - 56) * -1;
    int i = i_start, j = j_start;

    if (j_start == j_final)
    {
        while (i_start < i_final)
        {
            if (i_start != i && matrix[i_start][j_start] != ' ')
                return (1);
            i_start++;
        }
        while (i_start > i_final)
        {
            if (i_start != i && matrix[i_start][j_start] != ' ')
                return (1);
            i_start--;
        }
    }
    else if (i_start == i_final)
    {
        while (j_start < j_final)
        {
            printf ("'%c'\n", matrix[i_start][j_start]);
            if (j_start != j && matrix[i_start][j_start] != ' ')
                return (1);
            j_start++;
        }
        while (j_start > j_final)
        {
            printf ("'%c'\n", matrix[i_start][j_start]);
            if (j_start != i && matrix[j_start][j_start] != ' ')
                return (1);
            j_start--;
        }
    }
    return (0);
}

int bishop_path_check(char **matrix, char *start_pos, char *final_pos)
{
    int j_start = start_pos[0] - 97;
    int i_start = (start_pos[1] - 56) * -1;
    int j_final = final_pos[0] - 97;
    int i_final = (final_pos[1] - 56) * -1;
    int i = i_start, j = j_start;

    while (i_start > i_final && j_start > j_final)
    {
        if (j_start != j && matrix[i_start][j_start] != ' ')
            return (1);
        i_start--;
        j_start--;
    }
    while (i_start > i_final && j_start < j_final)
    {
        if (j_start != j && matrix[i_start][j_start] != ' ')
            return (1);
        i_start--;
        j_start++;
    }
    while (i_start < i_final && j_start > j_final)
    {
        if (j_start != j && matrix[i_start][j_start] != ' ')
            return (1);
        i_start++;
        j_start--;
    }
    while (i_start < i_final && j_start < j_final)
    {
        if (j_start != j && matrix[i_start][j_start] != ' ')
            return (1);
        i_start++;
        j_start++;
    }
    return (0);
}

#include "chess.h"

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
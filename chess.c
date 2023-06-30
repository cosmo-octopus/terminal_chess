#include "chess.h"

void    fill_matrix(char **matrix)
{
    int i;
    int j;

i = 0;
j = 0;
    while (i < 8)
    {
        while (j < 8)
        {
            if (i == 0)
            {
                matrix[i][j++] = 'R';
                matrix[i][j++] = 'N';
                matrix[i][j++] = 'B';
                matrix[i][j++] = 'Q';
                matrix[i][j++] = 'K';
                matrix[i][j++] = 'B';
                matrix[i][j++] = 'N';
                matrix[i][j] = 'R';
            }
            else if (i == 1)
                matrix[i][j] = 'P';
            else if (i == 6)
                matrix[i][j] = 'p';
            else if (i == 7)
            {
                matrix[i][j++] = 'r';
                matrix[i][j++] = 'n';
                matrix[i][j++] = 'b';
                matrix[i][j++] = 'q';
                matrix[i][j++] = 'k';
                matrix[i][j++] = 'b';
                matrix[i][j++] = 'n';
                matrix[i][j] = 'r';
            }
            else
                matrix[i][j] = ' ';
            j++;
        }
        j = 0;
        i++;
    }
}

int main()
{
    char    **matrix;
    int     i;
    char    *cmd;
    char    **cmd_parts;
    char    *piece_position;

    matrix = (char **)malloc(sizeof(char *) * 8);
    for (i = 0; i < 8; i++)
        matrix[i] = (char *)malloc(sizeof(char) * 8);
    fill_matrix(matrix);
    matrix[6][7] = ' ';
    matrix[6][1] = ' ';
    matrix[1][6] = ' ';
    while (1)
    {
        print_theboard(matrix);
        printf ("Give the step\n");
        cmd = get_next_line(STDIN_FILENO);
        cmd_parts = input_parsing(cmd);
        if (cmd_parts)
        {
            if (!check_position_range(cmd_parts[1]) && !check_position_range(cmd_parts[2]))
            {
                if (!finalpos_path_check(matrix, cmd_parts) && !final_pos_check(matrix, cmd_parts[0][0], cmd_parts[2]))
                {
                    define_thepiece(matrix, cmd_parts[0], cmd_parts[1], cmd_parts[2]);
                }
                else
                    error();
            }
            else
                error();
        }
        else
            error();
    }
}
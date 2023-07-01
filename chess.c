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
    int     color_flag = 0;
    int     error_flag;
    int    *king_pos_white = NULL;
    int    *king_pos_black = NULL;
    int     check_flag = 0;

    matrix = (char **)malloc(sizeof(char *) * 8);
    for (i = 0; i < 8; i++)
        matrix[i] = (char *)malloc(sizeof(char) * 8);
    fill_matrix(matrix);
    matrix[1][4] = ' ';
    matrix[1][3] = ' ';
    matrix[6][4] = ' ';
    matrix[6][3] = ' ';
    king_pos_white = (int *)malloc(sizeof(int) * 2);
    king_pos_white[0] = 0;
    king_pos_white[1] = 4;
    king_pos_black = (int *)malloc(sizeof(int) * 2);
    king_pos_black[0] = 7;
    king_pos_black[1] = 4;
    while (1)
    {
        print_theboard(matrix);
        if (!(i % 2))
            printf("TURN TO PLAY: WHITE\n");
        else
            printf("TURN TO PLAY: BLACK\n");
        cmd = get_next_line(STDIN_FILENO);
        cmd_parts = input_parsing(cmd);
        if (cmd_parts[0][1] == 'K')
        {
            if (cmd_parts[0][0] == 'W')
                change_king_pos(cmd_parts, king_pos_white);
            if (cmd_parts[0][0] == 'B')
                change_king_pos(cmd_parts, king_pos_black);
        }
        if (cmd_parts && ((i % 2 == 0 && cmd_parts[0][0] == 'W') || (i % 2 != 0 && cmd_parts[0][0] == 'B')))
        {
            if (!check_position_range(cmd_parts[1]) && !check_position_range(cmd_parts[2]))
            {
                if (!path_check(matrix, cmd_parts) && !start_pos_check(matrix, cmd_parts[0], cmd_parts[1]) 
                    && !final_pos_check(matrix, cmd_parts[0][0], cmd_parts[2]))
                {
                    if (!define_thepiece(matrix, cmd_parts[0], cmd_parts[1], cmd_parts[2]))
                        i++;
                    if (cmd_parts[0][1] == 'W')
                        king_checked(matrix, king_pos_white[0], king_pos_white[1], WHITE);
                    if (cmd_parts[0][1] == 'B')
                        king_checked(matrix, king_pos_black[0], king_pos_black[1], BLACK);
                }
                else
                    error();
            }
            else
                error();
        }
        else
           error();
        free(cmd);
        ft_free(cmd_parts);
    }
}
#include "../includes/chess.h"

void    change_king_pos(char **cmd_parts, int *king_pos)
{
    int j_final = cmd_parts[2][0] - 97;
    int i_final = (cmd_parts[2][1] - 56) * -1;

    if (!king_path_check(cmd_parts))
    {
        king_pos[0] = i_final;
        king_pos[1] = j_final;
    }
}
#include "chess.h"

int rook_action(char **matrix, char *piece, char *start_pos, char *final_pos)
{
    int j_start = start_pos[0] - 97;
    int i_start = (start_pos[1] - 56) * -1;
    int j_final = final_pos[0] - 97;
    int i_final = (final_pos[1] - 56) * -1;

    if (j_start == j_final || i_start == i_final)
    {
        valid_move();
        matrix[i_start][j_start] = ' ';
        if (piece[0] == 'W')
            matrix[i_final][j_final] = 'R';
        else if (piece[0] == 'B')
            matrix[i_final][j_final] = 'r';
        return (0);
    }
    else
    {
        error();
        return (1);
    }
}

int bishop_action(char **matrix, char *piece, char *start_pos, char *final_pos)
{
    int j_start = start_pos[0] - 97;
    int i_start = (start_pos[1] - 56) * -1;
    int j_final = final_pos[0] - 97;
    int i_final = (final_pos[1] - 56) * -1;
    int diff = j_final - j_start;

    if (diff < 0)
        diff *= -1;
    if ((i_final == i_start + diff && j_final == j_start + diff)
        || (i_final == i_start - diff && j_final == j_start + diff)
        || (i_final == i_start + diff && j_final == j_start - diff)
        || (i_final == i_start - diff && j_final == j_start - diff))
    {
        valid_move();
        matrix[i_start][j_start] = ' ';
        if (piece[0] == 'W')
            matrix[i_final][j_final] = 'B';
        else if (piece[0] == 'B')
            matrix[i_final][j_final] = 'b';
        return (0);
    }
    else
    {
        error();
        return (1);
    }
}

int knight_action(char **matrix, char *piece, char *start_pos, char *final_pos)
{
    int j_start = start_pos[0] - 97;
    int i_start = (start_pos[1] - 56) * -1;
    int j_final = final_pos[0] - 97;
    int i_final = (final_pos[1] - 56) * -1;

    if (((i_final == i_start + 2 || i_final == i_start - 2) && (j_final == j_start + 1 || j_final == j_start - 1))
        || ((i_final == i_start + 1 || i_final == i_start - 1) && (j_final == j_start + 2 || j_final == j_start - 2)))
    {
        valid_move();
        matrix[i_start][j_start] = ' ';
        if (piece[0] == 'W')
            matrix[i_final][j_final] = 'N';
        else if (piece[0] == 'B')
            matrix[i_final][j_final] = 'n';
        return (0);
    }
    else
    {
        error();
        return (1);
    }
}

int queen_action(char **matrix, char *piece, char *start_pos, char *final_pos)
{
    int j_start = start_pos[0] - 97;
    int i_start = (start_pos[1] - 56) * -1;
    int j_final = final_pos[0] - 97;
    int i_final = (final_pos[1] - 56) * -1;
    int diff = j_final - j_start;
    int check = 0;

    if (diff < 0)
        diff *= -1;
    if (j_start == j_final || i_start == i_final)
        check++;
    else if ((i_final == i_start + diff && j_final == j_start + diff)
        || (i_final == i_start - diff && j_final == j_start + diff)
        || (i_final == i_start + diff && j_final == j_start - diff)
        || (i_final == i_start - diff && j_final == j_start - diff))
    {
        check++;
    }
    if (check > 0)
    {
        valid_move();
        matrix[i_start][j_start] = ' ';
        if (piece[0] == 'W')
            matrix[i_final][j_final] = 'Q';
        else if (piece[0] == 'B')
            matrix[i_final][j_final] = 'q';
        return (0);
    }
    return (1);
}

int king_action(char **matrix, char *piece, char *start_pos, char *final_pos)
{
    int j_start = start_pos[0] - 97;
    int i_start = (start_pos[1] - 56) * -1;
    int j_final = final_pos[0] - 97;
    int i_final = (final_pos[1] - 56) * -1;
    int check = 0;
    
    if (((i_start == i_final) && ((j_start == j_final - 1) || (j_start = j_final + 1)))
        || ((j_start == j_final) && ((i_start == i_final + 1) || (i_start = i_final - 1))))
    {
        check++;
    }
    else if ((i_final == i_start + 1 || i_final == i_start - 1) && (j_final == j_start + 1 || j_final == j_start - 1))
        check++;
    if (check > 0)
    {
        valid_move();
        matrix[i_start][j_start] = ' ';
        if (piece[0] == 'W')
            matrix[i_final][j_final] = 'K';
        else if (piece[0] == 'B')
            matrix[i_final][j_final] = 'k';
        return (0);
    }
    return (1);
}
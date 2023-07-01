#ifndef CHESS_H
# define CHESS_H

# include <stdio.h>
# include "get_next_line.h"


# define CHECK_FLAG '!'
# define FILL_FLAG 'F'

typedef enum
{
    BLACK,
    WHITE
}   Color;

// typedef struct chess_board
// {
//     char    **matrix;
//     char    *piece;
//     char    *start_pos;
//     char    *final_pos;
// } chess_board;

//__________________//chess.c//__________________//
void    fill_matrix(char **matrix);
//__________________//error.c//__________________//
int     error();
//_________________//valid_move.c//_________________//
void    valid_move();
//_______________//print_theboard.c//_______________//
void    print_firstandlast();
void    print_theborderline();
void    print_fromthematrix(char **matrix, int j, char c);
void    print_theboard(char **matrix);
//________________//cmd_check.c//________________//
char    **input_parsing(char *cmd);
int     check_position_range(char *position);
int     define_thepiece(char **matrix, char *piece, char *start_pos, char *final_pos);
int     start_pos_check(char **matrix, char *piece, char *start_pos);
int     final_pos_check(char **matrix, char color, char *position);
//________________//path_check.c//________________//
int     path_check(char **matrix, char **cmd_parts);
int     rook_path_check(char **matrix, char *start_pos, char *final_pos);
int     bishop_path_check(char **matrix, char *start_pos, char *final_pos);
int     king_path_check(char **cmd_parts);
//________________//ft_split.c//________________//
char	**ft_split(char const *s, char c);
void	ft_free(char **str);
//______________//ft_split_utils.c//______________//
int	    ft_strlen(const char *str);
int	    ft_atoi(const char *str);
char	*ft_strdup(const char *s1);
char	*ft_substr(char const *s, unsigned int start, size_t len);
//__________________//action.c//__________________//
int     rook_action(char **matrix, char *piece, char *start_pos, char *final_pos);
int     bishop_action(char **matrix, char *piece, char *start_pos, char *final_pos);
int     knight_action(char **matrix, char *piece, char *start_pos, char *final_pos);
int     queen_action(char **matrix, char *piece, char *start_pos, char *final_pos);
int     king_action(char **matrix, char *piece, char *start_pos, char *final_pos);
int     pawn_action(char **matrix, char *piece, char *start_pos, char *final_pos);
//_____________________//to_free.c//_____________________//
void    to_free(char **matrix, int i);
//__________________//change_king_pos//__________________//
void    change_king_pos(char **cmd_parts, int *king_pos);
//___________________//check_check//___________________//
void    king_checked(char **matrix, int i_king, int j_king, Color color);

#endif
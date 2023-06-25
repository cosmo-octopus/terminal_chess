#ifndef CHESS_H
# define CHESS_H

# include <stdio.h>

# include "get_next_line.h"

//__________________//chess.c//__________________//
void    fill_matrix(char **matrix);
//_______________//print_theboard//_______________//
void    print_firstandlast();
void    print_theborderline();
void    print_fromthematrix(char **matrix, int j, char c);
void    print_theboard(char **matrix);
//________________//cmd_check.c//________________//
int     cmd_check(char *cmd);

#endif
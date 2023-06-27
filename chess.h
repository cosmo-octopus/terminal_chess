#ifndef CHESS_H
# define CHESS_H

# include <stdio.h>
# include "get_next_line.h"

//__________________//chess.c//__________________//
void    fill_matrix(char **matrix);
//__________________//error.c//__________________//
int     error();
//_______________//print_theboard//_______________//
void    print_firstandlast();
void    print_theborderline();
void    print_fromthematrix(char **matrix, int j, char c);
void    print_theboard(char **matrix);
//________________//cmd_check.c//________________//
char    **input_parsing(char *cmd);
int     check_position_range(char *position);
int     define_thepiece(char **matrix, char *piece, char *position);
//________________//ft_split.c//________________//
char	**ft_split(char const *s, char c);
void	ft_free(char **str);
//______________//ft_split_utils.c//______________//
int	    ft_strlen(const char *str);
int	    ft_atoi(const char *str);
char	*ft_strdup(const char *s1);
char	*ft_substr(char const *s, unsigned int start, size_t len);
//_______________//find_thepiece//_______________//
int     find_therook(char **matrix, char color, char *position);

#endif
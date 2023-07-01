NAME			= terminal_chess
SRC_DIR 		= src
SRCS			= $(wildcard $(SRC_DIR)/*.c)
HEADERS			= $(wildcard includes/*.h)
OBJ_DIR			= obj
OBJS			= $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SRCS))
INCS			= -Iincludes
CC				= cc 
CFLAGS			= -Wall -Wextra -Werror
RM				= rm -rf
MK				= mkdir -p

all:			$(OBJ_DIR) $(NAME)

$(OBJ_DIR): $(SRC_DIR)
	$(MK) $(OBJ_DIR)

$(OBJ_DIR)/%.o:	$(SRC_DIR)/%.c $(HEADERS) Makefile
	$(CC) $(CFLAGS) $(INCS) -c $< -o $@

$(NAME):		$(OBJS)
				$(CC) $(CFLAGS) $(INCS) -o $(NAME) $(OBJS)

clean:			
				$(RM) $(OBJ_DIR)

fclean:			clean
				$(RM) $(NAME)
				
re:				fclean all

.PHONY:			all clean fclean re bonus

#-fsanitize=address -g

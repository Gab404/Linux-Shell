##
## EPITECH PROJECT, 2021
## makefile
## File description:
## makefile
##

SRC =   ./src/mysh.c \
	 	./src/lib.c \
		./src/gest_error.c \
		./src/sys_cmd.c \
		./src/handle_path.c \
		./src/execut_file.c \
		./src/setenv.c \
		./src/unsetenv.c \
		./src/get_cd.c \
		./src/get_all_folder.c \
		./src/get_nb_word.c \
		./src/handle_cmd.c \


OBJ    =    $(SRC:.c=.o)

CFLAGS = -Wextra -Wall

CPPFLAGS =	-iquote ./includes/

LDFLAGS	=	-L./lib_printf -lmy

NAME   =    mysh

all:    $(NAME)

$(NAME):        $(OBJ)
	$(MAKE) -C ./lib_printf
	gcc -o $(NAME) $(OBJ) $(LDFLAGS)

clean:
	 rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)


re:	fclean all

.PHONY: clean
	fclean
	re

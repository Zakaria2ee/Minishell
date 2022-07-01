NAME = minishell

SRC = main.c lexing.c parsing.c execution.c

FLGS = -Wall -Wextra -Werror

FUNCTIONS = functions/ft_lstnew.c functions/ft_strcpy.c   functions/ft_split.c functions/ft_substr.c functions/ft_strlen.c \
			functions/ft_memcmp.c functions/ft_isalnum.c functions/ft_isalpha.c functions/ft_isdigit.c functions/ft_isdelimiter.c functions/ft_strjoin.c \
			functions/ft_strdup.c  functions/ft_strcmp.c functions/ft_lstsize.c\
			built_in/cd.c built_in/pwd.c built_in/echo.c built_in/env.c built_in/unset.c built_in/export.c built_in/exit.c \
			functions/linked_list/ft_lstadd_back.c functions/linked_list/ft_lstadd_front.c functions/linked_list/ft_lstclear.c\
			functions/linked_list/ft_lstdelone.c functions/linked_list/ft_lstiter.c functions/linked_list/ft_lstlast.c\
			functions/linked_list/ft_lstmap.c functions/linked_list/ft_lstnew.c functions/linked_list/ft_lstsize.c\
			execution/exe_functions.c functions/ft_itoa.c execution/norm.c functions/ft_strchr.c functions/ft_strjoin2.c \
			execution/execute_built_in.c functions/ft_limlen.c functions/ft_putstr_fd.c functions/ft_atoi.c built_in/cd_functions.c\
			built_in/export_functions.c functions/ft_strtrim.c
			 
UTILS = utils/ft_get_command.c utils/ft_get_redirections_token.c utils/ft_getdollar_token.c utils/ft_newtoken.c utils/ft_skipspace.c utils/ft_expand.c \
		utils/ft_newcommand.c utils/ft_get_redirectionfile.c utils/ft_get_arguments.c utils/ft_get_redirections.c utils/ft_quots_handler.c \
		utils/ft_newargtoken.c utils/ft_destroy.c utils/ft_newcmd.c utils/ft_herdoc_handler.c utils/ft_files_handler.c\
		utils/ft_arguments_handler.c utils/ft_signal_handler.c utils/ft_line_to_no_space.c utils/error_handler.c\
		utils/error_printing.c


SRCO = $(SRC:.c=.o)

FUNCTIONSO = $(FUNCTIONS:.c=.o)

UTILSO = $(UTILS:.c=.o)

all: $(NAME)

$(NAME):    $(SRCO) $(FUNCTIONSO) $(UTILSO)
	@$(CC) $(FLGS) -g -lreadline -L /Users/zboudair/Desktop/brew/opt/readline/lib -I /Users/zboudair/Desktop/brew/readline/include $(SRCO) $(FUNCTIONSO) $(UTILSO) -o $(NAME)
	@stty -echoctl
	@echo '\033[0;32m'"The programm compiled successefully"

clean : 
	@rm -rf $(SRCO) $(FUNCTIONSO) $(UTILSO)
	
fclean : clean
	@rm -rf $(NAME) 
re : fclean all

.PHONY: re all fclean clean
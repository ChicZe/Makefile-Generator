#ifndef DEFINES_H
# define DEFINES_H

/**======================
 *?    BASH SCRIPT
 *========================**/
# define GET_C_FILES "find . -path ./libft -prune -o -name \"*.c\""

/**----------------------**
 *?    DEFAULT VARS		  *
 *------------------------**/

# define DEFAULT_FLAGS "cc -Wall -Wextra -Werror -g"
# define OBJS "OBJS = $(SRC:.c=.o)"
# define MAX_FILE_LEN 72

# define ALLOCATION_FAIL "\nFatal Error!\nSomething went wrong with allocation!\n\n"

/**----------------------**
 *?    ERROR DEFINES	  *
 *------------------------**/

/*------------------------------------------*/
# define EXISTING_MAKEFILE "\nAlready exisiting Makefile!\nuse \
'makegen update' to update the sources \
with new '.c' files or type 'makegen help' \
for more informations\n\n"
/*------------------------------------------*/
# define MALLOC_FAIL "\nFatal Error!\nSomething went wrong with allocation!\n\n"
/*------------------------------------------*/
# define UPDATE_USAGE "\nWrong usage of update: type help for more infomations\n\n"
/*------------------------------------------*/
# define NAME_USAGE "\nWrong usage of name: type help for more informations\n\n"
/*------------------------------------------*/
# define LIBFT_USAGE "\nWrong usage of libft: type help for more informations\n\n"
/*------------------------------------------*/
# define COMPILE_USAGE "\nWrong usage of compile: type help for more informations\n\n"
/*------------------------------------------*/
# define LINK_USAGE "\nWrong link flag\n\n"
/*------------------------------------------*/
# define INCLUDE_PATH_ERROR "\nThe inserted path is not valid or non existing\n\
Make sure to include a valid folder or type help for more informations\n\n"
/*------------------------------------------*/
# define GENERIC_ERROR "\nFatal Error!\nIf the problem persists please open an issue on the github page.\n\n"
/*------------------------------------------*/

/*------------------------------------------*/

/*------------------------------------------*/

/*------------------------------------------*/

/*------------------------------------------*/

/*------------------------------------------*/

/*------------------------------------------*/

/*------------------------------------------*/

/*------------------------------------------*/

/*------------------------------------------*/

#endif
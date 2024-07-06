#ifndef DEFINES_H
# define DEFINES_H

# define DEFAULT_FLAGS "cc -Wall -Wextra -Werror -g"
# define LIBFT_PATH "libft/libft.a"

# define EXISTING_PRINT "\nAlready exisiting Makefile!\nuse \
'makegen update' to update the sources \
with new '.c' files or type 'makegen help' \
for more informations\n\n"

# define ALLOCATION_FAIL "\nFatal Error!\nSomething went wrong with allocation!\n\n"

enum errors {
	MALLOC_FAIL = 0,
	EXISTING_MAKEFILE = 1
};

#endif
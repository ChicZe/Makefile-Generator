
/**==============================================
 *            	MAKEFILE GENERATOR				*
 ================================================
 * @author      : cristian iusca				*
 * @email       : cristianiusca13@gmail.com		*
 * @repo        :								*
 * @createdOn   : 06/06/2024					*
 * @description : a simple makefile generator	*
 *=============================================**/

#include "../includes/make_gen.h"

int	main(int argc, char **argv)
{
	t_make	make;

	(void)argc;
	(void)argv;
	// if (parse_flags(&make) == 0)
	//		return (0);
	if (!init_all(&make))
		return (1);
	if (!create_file(&make))
		return (1);
}
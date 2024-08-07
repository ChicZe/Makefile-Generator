
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

int	error_status;

int	main(int argc, char **argv)
{
	t_make	make;

	if (!init_all(&make))
		quit(&make);
	if (!parse_flags(&make, argc, argv))
		quit(&make);
	if (!setup_basic_rules(&make))
		return (1);
	if (!create_file(&make))
		quit(&make);
	if (!write_makefile(&make))
		return (1);
	quit(&make);
}
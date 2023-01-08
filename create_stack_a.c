#include "includes/push_swap.h"

/*
check the argument format if its raw(just a string of numbers) or not
if only one argument -> error
if 2 then need to split the argument with split amd create the list
from that
*/
bool	create_stack_a(int argc, char **argv, t_stack **a)
{
	if (argc < 2)
		return(1);
	// if (argc == 2)
	if (argc > 2)
		raw_input(argc, argv, a);
	return(0);
}
/*
convert the ascii string to long with atol and create a node
for each number and place them on the list after each other
*/
void	raw_input(int argc, char **argv, t_stack **a)
{
	int nbr;
	int i;
	t_stack *temp;

	temp = NULL;
	i = 1;
	while (i < argc)
	{
		nbr = ft_atol(argv[i]);
		temp = lstnew(nbr);
		add_back(a, temp);
		i++;
	}
}
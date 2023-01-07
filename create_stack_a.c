#include "includes/push_swap.h"

bool	create_stack_a(int argc, char **argv, t_stack **a)
{
	if (argc < 2)
		return(1);
	// if (argc == 2)
	if (argc > 2)
		raw_input(argc, argv, a);
	return(0);
}

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
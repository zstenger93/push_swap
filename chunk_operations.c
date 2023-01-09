#include "includes/push_swap.h"

//divide the list into smaller chunks set by chunk_norris
void	chunk_it_up(t_stack *a, int length, int chunks)
{
	int i;
	int chunk_size;
	t_stack *head;
	t_stack *temp;

	head = a;
	temp = a;
	chunk_size = length / chunks;
	i = 0;
	while (i <= chunk_size)
	{
		if((temp->index >= (1 + (i * chunk_size))) &&
			temp->index <= (chunk_size * (1 + i)))
			temp->chunky = 1 + i;
		temp = temp->next;
		if (temp->next == NULL)
		{
			i++;
			temp = head;
		}
	}
}

//sets the amount of chunks we are going to divide the list to
int	chunk_norris(int length)
{
	int chunks;

	chunks = 0;
	if (length > 10 && length <= 50)
		chunks = 10;
	else if (length > 50 && length <= 100)
		chunks = 4;
	else if (length > 100)
		chunks = 11;
	return(chunks);
}


// void	move_chunks_to_b(t_stack **a, t_stack **b, int length, int chunks)
// {

// }
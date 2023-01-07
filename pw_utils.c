#include "includes/push_swap.h"

int list_size(t_stack *a)
{
	int length;
	if(!a)
		return(0);
	length = 0;
	while (a != NULL)
	{
		a = a->next;
		length++;
	}
	return(length);
}

bool	in_order(t_stack **a)
{
	while((*a)->next != NULL)
	{
		if ((*a)->number > (*a)->next->number)
			return(1);
		(*a) = (*a)->next;
	}
	return(0);
}

void	free_stack(t_stack **number)
{
	t_stack *temp;

	if ((!number) || (!*number))
		return ;
	while (*number != NULL)
	{
		temp = (*number)->next;
		free(*number);
		(*number) = temp;
	}
	*number = NULL;
}

void	add_back(t_stack **lst, t_stack *new)
{
	t_stack	*tmp;

	if (!new)
		return ;
	if (!*lst)
	{
		*lst = new;
		return ;
	}
	tmp = *lst;
	while (tmp->next != NULL)
		tmp = tmp->next;
	tmp->next = new;
}

t_stack	*lstnew(int value)
{
	t_stack	*result;

	result = malloc(sizeof(t_stack));
	if (!result)
		return (NULL);
	result->number = value;
	result->next = NULL;
	return (result);
}

long	ft_atol(char *str)
{
	int		i;
	long	sign;
	long	res;

	i = 0;
	sign = 1;
	res = 0;
	if (str[0] == '\0')
		return(1);
	if (str[i] == '-')
	{
		sign *= (-1);
		i++;
	}
	while (str[i] != '\0')
	{
		res = (str[i] - '0') + (res * 10);
		i++;
	}
	res = res * sign;
	invalid_char_check(str);
	valid_int(res);
	return (res);
}

void	invalid_char_check(char *str)
{
	int	i;

	if (ft_strlen(str) > 11)
		return ;
	i = 0;
	if (str[0] == '\0')
		return ;
	if (str[i] == '-')
		i++;
	if (str[0] == '-' && str[1] == '\0')
		return ;
	while (str[i] != '\0')
	{
		if (!ft_isdigit(str[i]))
			return ;
		i++;
	}
}

void	valid_int(long res)
{
	if (res < INT_MIN || res > INT_MAX)
		return ;
}

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	else
		return (0);
}

size_t	ft_strlen(const char *s)
{
	size_t	len;

	len = 0;
	while (s[len] != '\0')
		len++;
	return (len);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instruction.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccottin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 15:33:25 by ccottin           #+#    #+#             */
/*   Updated: 2022/05/05 15:35:05 by ccottin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	rra(t_data *data, int x)
{
	t_nbr	*temp;
	t_nbr	*run;

	if (data->stack_a == NULL || data->stack_a->next == NULL)
		return ;
	run = data->stack_a;
	while (run->next->next != NULL)
		run = run->next;
	temp = run->next;
	run->next = NULL;
	temp->next = data->stack_a;
	data->stack_a = temp;
	if (x == 0)
	{
		data->temp.move = stock_move(data, "rra");
		data->temp.nb_move++;
	}
}

void	rrb(t_data *data, int x)
{
	t_nbr	*temp;
	t_nbr	*run;

	if (data->stack_b == NULL || data->stack_b->next == NULL)
		return ;
	run = data->stack_b;
	while (run->next->next != NULL)
		run = run->next;
	temp = run->next;
	run->next = NULL;
	temp->next = data->stack_b;
	data->stack_b = temp;
	if (x == 0)
	{
		data->temp.move = stock_move(data, "rrb");
		data->temp.nb_move++;
	}
}

void	rrr(t_data *data)
{
	rra(data, 1);
	rrb(data, 1);
	data->temp.move = stock_move(data, "rrr");
	data->temp.nb_move++;
}

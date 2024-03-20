/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_a_to_b.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btomlins <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 14:06:44 by btomlins          #+#    #+#             */
/*   Updated: 2024/03/19 14:06:47 by btomlins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    current_index(t_stack_node *stack)
{
    int i;
    int median;

    i = 0;
    if (!stack)
        return ;
    median = stack_len(stack) / 2;
    while (stack)
    {
        stack->index = i;
        if (i <= median)
            stack->above_median = true;
        else
            stack->above_median = false;
        stack = stack->next;
        ++i;
    }
}

static void set_target_a(t_stack_node *a, t_stack_node *b)
{
    t_stack_node    *current_b;
    t_stack_node    *target_node;
    long            best_match_index;

    while (a)
    {
        best_match_index = LONG_MIN;
        current_b = b;
        while (current_b)
        {
            
        }
    }
}
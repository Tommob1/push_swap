/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stacks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btomlins <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 17:59:46 by btomlins          #+#    #+#             */
/*   Updated: 2024/04/18 18:17:06 by btomlins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void move_a_to_b(t_stack_node **a, t_stack_node **b)
{
    t_stack_node    *cheapest_node;

    cheapest_node = get_cheapest(*a);
    if (cheapest_node->above_median && cheapest_node->target_node->above_median)
        rr(a, b, cheapest_node);
    else if(!(cheapest_node->above_median)
        && !(cheapest_node->target_node->above_median))
        rrr(a, b, cheapest_node);
    prep_for_push(a, cheapest_node, 'a');
    prep_for_push(b, cheapest_node->target_node, 'b');
}

static void move_b_to_a(t_stack_node **a, t_stack_node **b)
{
    prep_for_push(a, (*b)->target_node, 'a');
    pa(a, b, false);
}

static void min_on_top(t_stack_node **a)
{
    while ((*a)->nbr != find_min(*a)->nbr)
    {
        if ((find_min(*a)->above_median))
            ra(a, false);
        else
            rra(a, false);
    }
}

void    sort_stacks(t_stack_node **a, t_stack_node **b)
{
    int len_a;

    len_a = stack_len(*a);
    if (len_a-- > 3 && !stack_sorted(*a))
        pb(b, a, false);
    if (len_a-- > 3 && !stack_sorted(*a))
        pb(b, a, false);
    while (len_a-- > 3 && !stack_sorted(*a))
    {
        init_nodes_b(*a, *b);
        move_a_to_b(a, b);
    }
    sort_three(a);
    while (*b)
    {
        init_nodes_b(*a, *b);
        move_b_to_a(a, b);
    }
    current_index(*a);
    min_on_top(a);
}
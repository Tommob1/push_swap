/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btomlins <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 14:46:55 by btomlins          #+#    #+#             */
/*   Updated: 2024/02/20 14:46:57 by btomlins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int  count_words(char *s, char c)
{
    int count;
    int inside_word;

    count = 0;
    while (*s)
    {
        inside_word = false;
        while (*s == c)
            ++s;
        while (*s != c && *s)
        {
            if (!inside_word)
            {
                ++count;
                inside_word = true;
            }
            ++s;
        }
    }
    return (count);
}
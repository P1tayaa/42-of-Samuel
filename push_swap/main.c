/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sboulain <sboulain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 14:23:51 by sboulain          #+#    #+#             */
/*   Updated: 2022/12/15 14:23:51 by sboulain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>
#include <stdio.h>
#include "push_swap_tool.h"

int main(int argc, char **argv)
{
    
    //error lunch
    if (argc == 1 || is_all_digit(argv, argc) == -1)
    {
        // printf("Input_Wrong\n is_all_digit == %d\n argc = %d\n", is_all_digit(argv, argc), argc);
        puts("NAH");
        return (0);
        
    }
    int i = 1;
    while (i < argc)
    {
        // printf("%d\n", ft_itoa(argv[i]));
        i++;
    }
    s_vector_int_with_index stack_a;
    s_vector_int_with_index stack_b;
    i--;
    stack_a -> number = malloc (i * sizeof(int));
    stack_b -> number = malloc (i * sizeof(int));
    stack_a -> index = malloc (i * sizeof(int));
    stack_b -> index = malloc (i * sizeof(int));
    stack_b -> lenght = 0;
    int i = 1;
    while (i < argc)
    {
        stack_a[i - 1] = ft_itoa(argv[i]);
        i++;
    }
    stack_b -> lenght = i - 1;



    free(stack_a -> number);
    free(stack_b -> number);
    free(stack_a -> index);
    free(stack_b -> index);
    puts("ok");
}
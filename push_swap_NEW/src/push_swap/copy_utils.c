/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   copy_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chbachir <chbachir@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 14:21:20 by chbachir          #+#    #+#             */
/*   Updated: 2024/03/19 13:48:33 by chbachir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

void swap_copy(t_stack *node_one, t_stack *node_two)  
{  
    int temp = node_one->nbr;  
    node_one->nbr = node_two->nbr;  
    node_two->nbr = temp;  
}  


void sort_copy(t_stack *copy) {
    int swapped;  
    t_stack *ptr1;  
    t_stack *lptr = NULL;  
  
    /* Checking for empty list */
    if (copy == NULL)  
        return;  

    swapped = 1; // Initialize swapped for the first pass
    while (swapped) {
        swapped = 0;
        ptr1 = copy;

        while (ptr1->next != lptr) {
            if (ptr1->nbr > ptr1->next->nbr) {
                swap_copy(ptr1, ptr1->next);  
                swapped = 1;
            }
            ptr1 = ptr1->next;
        }
        lptr = ptr1;
    }
}

t_stack *copy_stack(t_stack *a) {
    t_stack *new_head = NULL;  // Head of the copied list
    t_stack **current = &new_head;  // Pointer to track the end of the new list

    // Iterate through the original list
    while (a) {
        // Allocate memory for the new node
        *current = malloc(sizeof(t_stack));
        if (!*current) {
            // Handle memory allocation error - free the partially copied list
            while (new_head) {
                t_stack *tmp = new_head;
                new_head = new_head->next;
                free(tmp);
            }
            return NULL;  // Indicate failure
        }
        // Copy the 'nbr' data
        (*current)->nbr = a->nbr;
        (*current)->next = NULL;  // Ensure 'next' is NULL

        // Move to the next node in the original and new lists
        current = &((*current)->next);
        a = a->next;
    }
    return new_head;
}

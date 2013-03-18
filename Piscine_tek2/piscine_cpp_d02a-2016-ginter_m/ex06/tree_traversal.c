/*
** tree_traversal.c for ex06 in /home/fest/Epitech/Piscine_tek2/piscine_cpp_d02a-2016-ginter_m/ex06
**
** Made by maxime ginters
** Login  <ginter_m@epitech.eu>
**
** Started on  Thu Jan 10 20:51:18 2013 maxime ginters
** Last update Thu Jan 10 21:51:17 2013 maxime ginters
*/

#include <stdlib.h>
#include "tree_traversal.h"
#include "stack.h"
#include "queue.h"
#include "generic_list.h"

t_bool tree_is_empty(t_tree tree)
{
    return (tree == NULL ? TRUE : FALSE);
}

void tree_node_dump(t_tree_node* tree_node, t_dump_func dump_func)
{
    (dump_func)(tree_node->data);
}

t_bool init_tree(t_tree* tree_ptr, void* data)
{
    if ((*tree_ptr = malloc(sizeof(t_tree_node))) == NULL)
        return FALSE;
    (*tree_ptr)->data = data;
    (*tree_ptr)->parent = NULL;
    return TRUE;
}

t_tree_node* tree_add_child(t_tree_node* tree_node, void* data)
{
    t_tree_node* node;
    if (init_tree(&node, data) == FALSE)
        return NULL;
    if (list_add_elem_at_back(&tree_node->children, node) == FALSE)
        return NULL;
    return node;
}

t_bool tree_destroy(t_tree* tree_ptr)
{
    list_clear(&(*tree_ptr)->children);
    *tree_ptr = NULL;
    return TRUE;
}

void tree_traversal(t_tree tree, t_container* container, t_dump_func dump_func)
{
    tree_node_dump(tree, dump_func);
    t_node* child = tree->children;
    while (child)
    {
        (container->push_func)(container->container, child->value);
        child = child->next;
    }
    t_tree test;
    while ((test = (container->pop_func)(container->container)) != NULL)
        tree_traversal(test, container, dump_func);
}

/*
** simple_btree.c for ex01 in /home/fest/Epitech/Piscine_tek2/piscine_cpp_d02a-2016-ginter_m/ex01
**
** Made by maxime ginters
** Login  <ginter_m@epitech.eu>
**
** Started on  Thu Jan 10 16:16:50 2013 maxime ginters
** Last update Thu Jan 10 17:59:11 2013 maxime ginters
*/

#include <stdlib.h>
#include "simple_btree.h"

#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define MIN(a, b) ((a) > (b) ? (b) : (a))

t_bool btree_is_empty(t_tree tree)
{
    return (tree == NULL ? TRUE : FALSE);
}

unsigned int btree_get_size(t_tree tree)
{
     if (!tree)
         return 0;
    return 1 + btree_get_size(tree->left) + btree_get_size(tree->right);
}

unsigned int btree_get_depth(t_tree tree)
{
    unsigned int size[2];

    if (tree == NULL)
        return 0;
    size[0] = btree_get_depth(tree->left);
    size[1] = btree_get_depth(tree->right);
    return 1 + MAX(size[0], size[1]);
}

t_bool btree_create_node(t_tree* node_ptr, double value)
{
    if ((*node_ptr = malloc(sizeof(t_node))) == NULL)
        return FALSE;
    (*node_ptr)->value = value;
    return TRUE;
}

t_bool btree_delete(t_tree* root_ptr)
{
    if (*root_ptr == NULL)
        return FALSE;
    *root_ptr = NULL;
    return TRUE;
}

double btree_get_max_value(t_tree tree)
{
    double size[2];
    if (tree == NULL)
        return 0.0;
    size[0] = btree_get_max_value(tree->left);
    size[1] = btree_get_max_value(tree->right);
    if (tree->left && tree->right)
        return MAX(MAX(size[0], size[1]), tree->value);
    else if (tree->left)
        return MAX(size[0], tree->value);
    else if (tree->right)
        return MAX(size[1], tree->value);
    return tree->value;
}

double btree_get_min_value(t_tree tree)
{
    double size[2];
    if (tree == NULL)
        return 0.0;
    size[0] = btree_get_min_value(tree->left);
    size[1] = btree_get_min_value(tree->right);
    if (tree->left && tree->right)
        return MIN(MIN(size[0], size[1]), tree->value);
    else if (tree->left)
        return MIN(size[0], tree->value);
    else if (tree->right)
        return MIN(size[1], tree->value);
    return tree->value;
}

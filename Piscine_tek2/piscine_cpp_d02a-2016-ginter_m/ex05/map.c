/*
** map.c for ex05 in /home/fest/Epitech/Piscine_tek2/piscine_cpp_d02a-2016-ginter_m/ex05
**
** Made by maxime ginters
** Login  <ginter_m@epitech.eu>
**
** Started on  Thu Jan 10 18:37:26 2013 maxime ginters
** Last update Thu Jan 10 19:29:19 2013 maxime ginters
*/

#include <stdlib.h>
#include "map.h"

unsigned int map_get_size(t_map map)
{
    return list_get_size(map);
}

t_bool map_is_empty(t_map map)
{
    return list_is_empty(map);
}

t_key_comparator key_cmp_container(t_bool store, t_key_comparator new_key_cmp)
{
    static t_key_comparator key_cmp;
    if (store == TRUE)
        key_cmp = new_key_cmp;
    return key_cmp;
}

int pair_comparator(void* first, void* second)
{
    t_key_comparator key_cmp = key_cmp_container(FALSE, NULL);
    return (key_cmp)(((t_pair*)first)->key, second);
}

t_bool map_add_elem(t_map* map_ptr, void* key, void* value, t_key_comparator key_cmp)
{
    key_cmp_container(TRUE, key_cmp);
    t_pair* pair;
    if ((pair = malloc(sizeof(t_pair))) == NULL)
        return FALSE;
    pair->key = key;
    pair->value = value;

    t_node* node = list_get_first_node_with_value(*map_ptr, key, pair_comparator);
    if (node)
        if (list_del_node(map_ptr, node) == FALSE)
            return FALSE;

    return list_add_elem_at_front(map_ptr, pair);
}

t_bool map_del_elem(t_map* map_ptr, void* key, t_key_comparator key_cmp)
{
    key_cmp_container(TRUE, key_cmp);
    t_node* node = list_get_first_node_with_value(*map_ptr, key, pair_comparator);
    if (node)
        return list_del_node(map_ptr, node);
    return FALSE;
}

void* map_get_elem(t_map map, void* key, t_key_comparator key_cmp)
{
    key_cmp_container(TRUE, key_cmp);
    t_node* node = list_get_first_node_with_value(map, key, pair_comparator);
    if (node)
        return ((t_pair*)node->value)->value;
    return NULL;
}

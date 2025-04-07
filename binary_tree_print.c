#include "binary_trees.h"
#include <stddef.h>  /* Fix: NULL definition */
#include <stdio.h>   /* Fix: printf(), snprintf() */

/* Add this function prototype before calling it */
void print_tree(const binary_tree_t *tree, char *prefix, int is_left);

/**
 * binary_tree_print - Prints a binary tree
 * @tree: Pointer to the root node
 */
void binary_tree_print(const binary_tree_t *tree)
{
    if (tree == NULL)
        return;

    print_tree(tree, "", 0); /* Now properly declared */
}

/**
 * print_tree - Recursively prints a binary tree using ASCII formatting
 * @tree: Pointer to the root node
 * @prefix: Prefix for each printed node (used for formatting)
 * @is_left: Flag to indicate if it's a left child
 */
void print_tree(const binary_tree_t *tree, char *prefix, int is_left)
{
    char new_prefix[100]; /* Fix: Declare before any code */

    if (tree == NULL)
        return;

    printf("%s", prefix);
    printf("%s", is_left ? "├── " : "└── ");
    printf("%d\n", tree->n);

    snprintf(new_prefix, sizeof(new_prefix), "%s%s", prefix, is_left ? "│   " : "    ");

    print_tree(tree->left, new_prefix, 1);
    print_tree(tree->right, new_prefix, 0);
}


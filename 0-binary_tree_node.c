#include "binary_trees.h"

/**
 * createnode - creates nodes for binary trees
 *
 * @value: integer to be incorporated to the new node
 * Return: binary_tree_t*
 */

binary_tree_t *createnode(int value)
{
	binary_tree_t *node = malloc(sizeof(binary_tree_t));

	if (node)
	{
		node->n = value;
		node->parent = NULL;
		node->left = NULL;
		node->right = NULL;
	}
	return (node);
}

/**
 * binary_tree_node - integrates new node to a binary tree
 *
 * @parent: parent node
 * @value: value to be sent to proper creation function
 * Return: binary_tree_t*
 */
binary_tree_t *binary_tree_node(binary_tree_t *parent, int value)
{
	binary_tree_t *node = createnode(value);

	if (node)
		node->parent = parent; 
	return (node);
}

#include "binary_trees.h"

/**
 * bst_insert - inserts value in a binary search tree
 *
 * @tree: tree root
 * @value: newnode's value
 * Return: bst_t* pointer
 */
bst_t *bst_insert(bst_t **tree, int value)
{
	bst_t *root, *result = NULL;

	if (*tree == NULL)
		return (binary_tree_node(*tree, value));
	root = *tree;
	if (value == root->n)
		return (result);
	if (value < root->n)
		result = (bst_insert(&(root->left), value));
	if (value > root->n)
		result = (bst_insert(&(root->right), value));
	return (result);
}

#include "binary_trees.h"

/**
 * bst_search - searches for a value in a Binary Search Tree
 * @tree: pointer to root of tree
 * @value: input value
 * Return: pointer to the node containing a value equals to value
 */
bst_t *bst_search(const bst_t *tree, int value)
{
	bst_t *res = NULL;

	if (!tree)
		return (NULL);
	if (value == tree->n)
		return ((bst_t *)tree);
	if (value > tree->n)
		res = bst_search(tree->right, value);
	if (value < tree->n)
		res = bst_search(tree->left, value);
	return (res);
}

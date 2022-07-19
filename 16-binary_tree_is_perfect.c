#include "binary_trees.h"

/**
 * binary_tree_is_perfect - checks if a binary tree is perfect
 * @tree: pointer to head of tree
 * Return: 1 if true 0 if false
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	int n, h;

	if (!tree)
		return (0);
	n = (int)binary_tree_size(tree);
	h = binary_tree_height(tree);
	return (h == 0 ? 1 : n == (2 << h) - 1);
}

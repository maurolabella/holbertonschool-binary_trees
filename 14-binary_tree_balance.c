#include "binary_trees.h"

/**
 * _height_bal - Measures the height of a binary tree
 *
 * @tree: Pointer to the node to measures the height
 *
 * Return: The height of the tree starting at @node
 */
static size_t _height_bal(const binary_tree_t *tree)
{
	size_t height_l;
	size_t height_r;

	height_l = tree->left ? 1 + (int)_height_bal(tree->left) : 0;
	height_r = tree->right ? 1 + (int)_height_bal(tree->right) : 0;
	return (height_l - height_r);
}

/**
 * binary_tree_balance - measures the balance factor of a binary tree
 * @tree: input tree
 * Return: balance factor of descendants
 */
int binary_tree_balance(const binary_tree_t *tree)
{
	if (!tree)
		return (0);
	return (_height_bal(tree));
}

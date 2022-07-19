#include "binary_trees.h"


/**
 * _height - Measures the height of a binary tree
 *
 * @tree: Pointer to the node to measures the height
 *
 * Return: The height of the tree starting at @node
 */
static size_t _height(const binary_tree_t *tree)
{
	size_t height_l;
	size_t height_r;

	height_l = tree->left ? 1 + _height(tree->left) : 0;
	height_r = tree->right ? 1 + _height(tree->right) : 0;
	return (height_l > height_r ? height_l : height_r);
}

/**
 * binary_tree_height - measures the height of a binary tree
 * @tree: input tree
 * Return: height of tree
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	if (!tree)
		return (0);
	return (_height(tree));
}

/**
 * binary_tree_size - measures the size of a binary tree
 * @tree: input binary tree
 * Return: number of descendant child nodes
 */
size_t binary_tree_size(const binary_tree_t *tree)
{
	if (!tree)
		return (0);

	return (1 + binary_tree_size(tree->left) + binary_tree_size(tree->right));
}


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


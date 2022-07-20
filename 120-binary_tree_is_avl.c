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
 * is_balanced_bst - measures the balance factor of a binary tree
 * @tree: input tree
 * @min: minimum value of n
 * @max: maximum value of n
 * Return: balance factor of descendants
 */
int is_balanced_bst(const binary_tree_t *tree, int min, int max)
{
	int a, b;

	if (!tree)
		return (1);

	a = (tree->left)
					? (int)binary_tree_height(tree->left)
					: 0;
	b = (tree->right)
					? (int)binary_tree_height(tree->right)
					: 0;
	if (abs(a - b) > 1)
		return (0);
	if (tree->n < min || tree->n > max)
		return (0);
	return (is_balanced_bst(tree->left, min, tree->n - 1) &&
					is_balanced_bst(tree->right, tree->n + 1, max));
}

/**
 * binary_tree_is_avl - checks if a binary tree is a valid AVL Tree
 * @tree: pointer to root of tree
 * Return: 1 if true 0 if false
 */
int binary_tree_is_avl(const binary_tree_t *tree)
{
	if (!tree)
		return (0);
	return (is_balanced_bst(tree, INT_MIN, INT_MAX));
}

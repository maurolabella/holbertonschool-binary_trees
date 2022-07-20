#include "binary_trees.h"
#include "limits.h"

/**
 * bst_check - helper func for binary_tree_is_bst
 * @tree: pointer to tree node
 * @min: minimum value of BST tree
 * @max: maximum value of BST tree
 * Return: true or false
 */
_Bool bst_check(const binary_tree_t *tree, int min, int max)
{
	if (!tree)
		return (1);
	if (tree->n <= min || tree->n >= max)
		return (0);
	return (bst_check(tree->left, min, tree->n) &&
					bst_check(tree->right, tree->n, max));
}

/**
 * binary_tree_is_bst - checks if a binary tree is a valid Binary Search Tree
 * @tree: pointer to root of tree
 * Return: 1 if true 0 if false
 */
int binary_tree_is_bst(const binary_tree_t *tree)
{
	if (!tree)
		return (0);
	return (bst_check(tree, INT_MIN, INT_MAX));
}

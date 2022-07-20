#include "binary_trees.h"

/**
 * _bst_insert - inserts value in a binary search tree
 *
 * @tree: tree root
 * @value: newnode's value
 * @root: parent's address
 * Return: bst_t* pointer
 */
bst_t *_bst_insert(bst_t **tree, int value, bst_t *root)
{
	bst_t *res = NULL;

	if (*tree == NULL)
	{
		*tree = binary_tree_node(root, value);
		return (*tree);
	}
	if (value == (*tree)->n)
		return (NULL);
	if (value < (*tree)->n)
		res = (_bst_insert(&((*tree)->left), value, *tree));
	if (value > (*tree)->n)
		res = (_bst_insert(&((*tree)->right), value, *tree));
	return (res);
}

/**
 * bst_insert - inserts value in a binary search tree
 *
 * @tree: tree root
 * @value: newnode's value
 * Return: bst_t* pointer
 */
bst_t *bst_insert(bst_t **tree, int value)
{
	bst_t *res, *root = *tree;

	if (root == NULL)
	{
		(*tree) = binary_tree_node(root, value);
		return (*tree);
	}
	else
	{
		res = _bst_insert(tree, value, root);
		return (res);
	}
}

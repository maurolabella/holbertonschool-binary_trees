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

/**
 * swap - swaps two nodes in binary tree
 * @a: first node
 * @b: second node
 * Return: pointer to root
 */
bst_t *swap(bst_t *a, bst_t *b)
{
	bst_t *temp = NULL;
	int left_child = 0;

	if (a->parent)
		left_child = a->parent->left == a;
	if (b->parent && b->parent != a)
		b->parent->left = NULL;
	b->parent = a->parent;
	if (a->parent)
	{
		if (left_child)
			a->parent->left = b;
		else
			a->parent->right = b;
	}
	if (a->left != b)
	{
		b->left = a->left;
		a->left->parent = b;
	}
	if (a->right && a->right != b)
	{
		b->right = a->right;
		a->right->parent = b;
	}
	temp = b;
	while (temp->parent)
		temp = temp->parent;
	free(a);
	return (temp);
}

/**
 * bst_remove - removes a node from a Binary Search Tree
 * @root: pointer to root of tree
 * @value: input value
 * Return: pointer to the b root node of the tree after removing the
 * desired value
 */
bst_t *bst_remove(bst_t *root, int value)
{
	bst_t *node, *temp;
	int left_child = 0;

	if (!root)
		return (NULL);
	node = bst_search(root, value);
	if (!node)
		return (NULL);
	if (node->parent)
		left_child = node->parent->left == node;
	if (!node->right && !node->left)
	{
		if (!node->parent)
		{
			free(node);
			return (NULL);
		}
		if (left_child)
			node->parent->left = NULL;
		else
			node->parent->right = NULL;
		temp = node->parent;
		while (temp->parent)
			temp = temp->parent;
		free(node);
		return (temp);
	}
	if (!node->right)
		return (swap(node, node->left));
	temp = node->right;
	while (temp->left)
		temp = temp->left;
	return (swap(node, temp));
}

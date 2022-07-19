#include "binary_trees.h"

/**
 * binary_tree_depth - measures the depth of a node in a binary tree
 * @tree: input binary tree
 * Return: depth of tree
 */
size_t binary_tree_depth(const binary_tree_t *tree)
{
	size_t counter = 0;

	if (!tree)
		return (0);

	while (tree->parent)
	{
		counter++;
		tree = tree->parent;
	}
	return (counter);
}

/**
 * binary_trees_ancestor - finds the lowest common ancestor of two nodes
 * @first: pointer to first node
 * @second: pointer to second node
 * Return: pointer to lowest common ancestor node of the two given nodes
 */
binary_tree_t *binary_trees_ancestor(const binary_tree_t *first,
																		 const binary_tree_t *second)
{
	binary_tree_t *a = (binary_tree_t *)first, *b = (binary_tree_t *)second;
	size_t depth_first, depth_second;

	if (!first || !second)
		return (NULL);

	depth_first = binary_tree_depth(a);
	depth_second = binary_tree_depth(b);
	while (depth_second > depth_first)
	{
		b = b->parent;
		depth_second--;
	}
	while (depth_first > depth_second)
	{
		a = a->parent;
		depth_first--;
	}
	while (a && b)
	{
		if (a == b)
			return (a);
		a = a->parent;
		b = b->parent;
	}
	return (NULL);
}

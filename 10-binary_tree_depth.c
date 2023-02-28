#include "binary_trees.h"

/**
 * binary_tree_depth - computes the depth of a binary tree
 * @tree: pointer to node in tree whose depth is to be measured
 * Return: depth of tree
 */
size_t binary_tree_depth(const binary_tree_t *tree)
{
	size_t node_depth;

	if (!tree || !tree->parent)
		return (0);

	node_depth = 1 + binary_tree_depth(tree->parent);

	return (node_depth);
}

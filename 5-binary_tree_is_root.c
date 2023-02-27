#include "binary_trees.h"

/**
 * binary_tree_is_root - checks if the node is the root node
 * of the binary tree
 * @node: node to check
 * Return: 1 if node is root, otherwise 0
 */
int binary_tree_is_root(const binary_tree_t *node)
{
	if (!node)
		return (0);

	if (node->parent)
		return (0);

	return (1);
}

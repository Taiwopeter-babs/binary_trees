#include "binary_trees.h"

/**
 * binary_tree_nodes - computes the number of nodes with
 * a minimum of one child in a binary tree
 * @tree: pointer to root node of tree
 * Return: number of nodes
 */
size_t binary_tree_nodes(const binary_tree_t *tree)
{
	size_t has_child_count;

	if (!tree || node_is_leaf(tree))
		return (0);

	has_child_count = 1 + binary_tree_nodes(tree->left) +
				binary_tree_nodes(tree->right);
	return (has_child_count);
}

/**
 * node_is_leaf - checks that node is without any children
 * @node: node to be checked
 *
 * Return: 1 if node is leaf, otherwise 0
 */
int node_is_leaf(const binary_tree_t *node)
{
	if (!node->left && !node->right)
		return (1);
	return (0);
}

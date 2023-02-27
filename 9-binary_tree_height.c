#include "binary_trees.h"

/**
 * binary_tree_height - computes the height of a binary
 * tree, which is equivalent to the depth of deepest node
 * @tree: pointer to root node of tree whose height is to be measured
 * Return: height of tree
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t left_tree_height, right_tree_height;

	if (!tree || node_is_leaf(tree))
		return (0);

	left_tree_height = binary_tree_height(tree->left);
	right_tree_height = binary_tree_height(tree->right);

	return (find_max(left_tree_height, right_tree_height) + 1);
}

/**
 * find_max - finds the maximum
 * @val1: first value
 * @val2: second value
 * Return: maximum value
 */
size_t find_max(size_t val1, size_t val2)
{
	return ((val1 >= val2) ? val1 : val2);
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

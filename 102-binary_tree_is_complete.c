#include "binary_trees.h"

/**
 * binary_tree_is_complete - checks that a binary tree is a complete
 * binary tree
 * @tree: pointer to root node of tree
 * Return: 1 if tree is complete, otherwise 0
 */
int binary_tree_is_complete(const binary_tree_t *tree)
{
	size_t tree_size, node_idx;

	if (!tree)
		return (0);

	node_idx = 0;

	tree_size = binary_tree_size(tree);

	return (is_complete(tree, node_idx, tree_size));
}

/**
 * is_complete - auxilliary function to check completeness of tree
 * @node: node of tree
 * @index: index of node
 * @tree_size: size of the binary tree
 * Return: 1 if tree is complete, otherwise 0
 */
int is_complete(const binary_tree_t *node, size_t index, size_t tree_size)
{
	if (!node)
		return (1);
	if (index >= tree_size)
		return (0);

	return (is_complete(node->left, 2 * index + 1, tree_size) &&
			is_complete(node->right, 2 * index + 2, tree_size));
}

/**
 * binary_tree_size - computes the size of a binary
 * tree
 * @tree: pointer to root node of tree whose size is to be measured
 * Return: height of tree
 */
size_t binary_tree_size(const binary_tree_t *tree)
{
	size_t left_size, right_size;

	if (!tree)
		return (0);

	right_size =  binary_tree_size(tree->right);
	left_size = binary_tree_size(tree->left);

	return (right_size + left_size + 1);
}

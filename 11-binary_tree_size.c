#include "binary_trees.h"

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

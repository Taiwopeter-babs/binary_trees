#include "binary_trees.h"

/**
 * binary_tree_leaves - computes the number of leaves in a binary
 * tree
 * @tree: pointer to root node of tree
 * Return: number of leaves in tree
 */
size_t binary_tree_leaves(const binary_tree_t *tree)
{
	if (!tree)
		return (0);

	if (node_is_leaf(tree))
		return 1;

	return (binary_tree_leaves(tree->left) + 
			binary_tree_leaves(tree->right));

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

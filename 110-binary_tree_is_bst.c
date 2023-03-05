#include "binary_trees.h"

/**
 * binary_tree_is_bst - checks if a binary tree is a
 * binary search tree
 * @tree: pointer to root node of tree
 * Return: 1 if tree is a BST, otherwise 0
 */
int binary_tree_is_bst(const binary_tree_t *tree)
{
	boolean var = False;

	if (!tree)
		return (var);

	return (is_bst((binary_tree_t *) tree, 0, 0));
}
/**
 * is_bst - auxilliary function for checking if a tree is a BST
 * @node: pointer to node
 * @min: minimum value
 * @max: maximum value
 * Return: 1 if node is a BST, otherwise 0
 */
int is_bst(binary_tree_t *node, int min, int max)
{
	boolean var;

	if (!node)
	{
		var = True;
		return (var);
	}
	else if ((min && node->n >= min) || (max && node->n <= max))
	{
		var = False;
		return (var);
	}
	else
	{
		return ((is_bst(node->left, node->n, max) &&
					is_bst(node->right, min, node->n)));
	}
}

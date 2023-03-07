#include "test.h"

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


	return is_bst((binary_tree_t *) tree, 0, 0);
}
/**
 * is_bst - auxilliary function for checking if a tree is a BST
 * @node: pointer to node
 * @prev: pointer to previous node on stack
 * Return: 1 if node is a BST, otherwise 0
 */
int is_bst(binary_tree_t *node, int max, int min)
{
	boolean var;

	if (!node)
	{
		var = True;
		return (var);
	}
	else if ((max && node->n >= max) || (min && node->n <= min))
	{
		var = False;
		return (var);
	}
	return (is_bst(node->left, node->n, min) &&
			is_bst(node->right, max, node->n));
}

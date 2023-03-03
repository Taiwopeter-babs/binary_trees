#include "binary_trees.h"

/**
 * binary_tree_is_bst - checks if a binary tree is a
 * binary search tree
 * @tree: pointer to root node of tree
 * Return: 1 if tree is a BST, otherwise 0
 */
int binary_tree_is_bst(const binary_tree_t *tree)
{
	binary_tree_t *prev = NULL;

	if (!tree)
		return (0);

	return (is_bst((binary_tree_t *) tree, prev));
}
/**
 * is_bst - auxilliary function for checking if a tree is a BST
 * @node: pointer to node
 * @prev: pointer to previous node on stack
 * Return: 1 if node is a BST, otherwise 0
 */
int is_bst(binary_tree_t *node, binary_tree_t *prev)
{
	int left, right;

	if (!node)
		return (1);

	left = is_bst(node->left, prev);
	if (prev && node->n <= prev->n)
		return (0);
	prev = node;

	right = is_bst(node->right, prev);

	if (left && right)
		return (1);
	else
		return (0);
}

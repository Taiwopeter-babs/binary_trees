#include "binary_trees.h"

/**
 * binary_tree_inorder - traverses the binary tree in an
 * inorder fashion
 * @tree: pointer to root node of tree
 * @func: function pointer to a function called on each node
 * traversed
 * Return: nothing
 */
void binary_tree_inorder(const binary_tree_t *tree, void (*func)(int))
{
	if ((*func) == NULL)
		return;
	if (tree == NULL)
		return;


	binary_tree_inorder(tree->left, (*func));
	(*func)(tree->n);
	binary_tree_inorder(tree->right, (*func));
}

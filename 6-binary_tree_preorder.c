#include "binary_trees.h"

/**
 * binary_tree_preorder - traverses the binary tree in a
 * preorder fashion
 * @tree: pointer to root node of tree
 * @func: function pointer to a function called on each node
 * traversed
 * Return: nothing
 */
void binary_tree_preorder(const binary_tree_t *tree, void (*func)(int))
{
	if ((*func) == NULL)
		return;
	if (tree == NULL)
		return;

	(*func)(tree->n);

	binary_tree_preorder(tree->left, (*func));
	binary_tree_preorder(tree->right, (*func));
}

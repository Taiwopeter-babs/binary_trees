#include "binary_trees.h"

/**
 * binary_tree_postorder - traverses the binary tree in a
 * postorder fashion
 * @tree: pointer to root node of tree
 * @func: function pointer to a function called on each node
 * traversed
 * Return: nothing
 */
void binary_tree_postorder(const binary_tree_t *tree, void (*func)(int))
{
	if ((*func) == NULL)
		return;
	if (tree == NULL)
		return;

	binary_tree_postorder(tree->left, (*func));
	binary_tree_postorder(tree->right, (*func));
	(*func)(tree->n);
}

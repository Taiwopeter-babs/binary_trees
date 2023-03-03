#include "binary_trees.h"

/**
 * binary_tree_rotate_left - rotates a binary tree to the left; anticlockwise
 * @tree: pointer to root node of the tree
 * Return: pointer to new root node of tree
 */
binary_tree_t *binary_tree_rotate_left(binary_tree_t *tree)
{
	binary_tree_t *new_root, *old_root, *left_subtree;

	if (!tree)
		return (NULL);

	if (!tree->right)
		return (tree);

	new_root = tree->right;
	old_root = tree;
	old_root->parent = new_root;


	if (new_root->left)
	{
		left_subtree = new_root->left;
		left_subtree->parent = old_root;
		old_root->right = left_subtree;
		new_root->left = old_root;
	}
	else
	{
		new_root->left = old_root;
		old_root->right = NULL;
	}

	new_root->parent = NULL;

	return (new_root);
}

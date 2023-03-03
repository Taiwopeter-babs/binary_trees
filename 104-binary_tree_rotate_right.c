#include "binary_trees.h"

/**
 * binary_tree_rotate_right - rotates a binary tree to the right; clockwise
 * @tree: pointer to root node of the tree
 * Return: pointer to new root node of tree
 */
binary_tree_t *binary_tree_rotate_right(binary_tree_t *tree)
{
	binary_tree_t *new_root, *old_root, *right_subtree;

	if (!tree)
		return (NULL);

	if (!tree->left)
		return (tree);

	new_root = tree->left;
	old_root = tree;
	old_root->parent = new_root;


	if (new_root->right)
	{
		right_subtree = new_root->right;
		right_subtree->parent = old_root;
		old_root->left = right_subtree;
		new_root->right = old_root;
	}
	else
	{
		new_root->right = old_root;
		old_root->left = NULL;
	}

	new_root->parent = NULL;

	return (new_root);
}

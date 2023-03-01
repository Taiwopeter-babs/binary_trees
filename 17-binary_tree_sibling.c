#include "binary_trees.h"

/**
 * binary_tree_sibling - finds the sibling of a node
 * @node: pointer to node whose sibling is to be checked
 * Return: sibling of node, otherwise NULL
 */
binary_tree_t *binary_tree_sibling(binary_tree_t *node)
{
	if (!node)
		return (NULL);

	/* check if parent of node is not NULL */
	if (node->parent)
	{
		/* check if the node is the right child */
		if (node->parent->right == node)
		{
			if (node->parent->left)
				return (node->parent->left);
			else
				return (NULL);
		}
		else if (node->parent->left == node)
		{
			if (node->parent->right)
				return (node->parent->right);
			else
				return (NULL);
		}
	}
	return (NULL);
}

#include "binary_trees.h"

/**
 * binary_tree_uncle - finds the uncle of a node
 * @node: pointer to node whose uncle is to be checked
 * Return: sibling of node, otherwise NULL
 */
binary_tree_t *binary_tree_uncle(binary_tree_t *node)
{
	if (!node || !node->parent)
		return (NULL);

	/* check if parent of the parent of the node is not NULL */
	if (node->parent->parent)
	{
		/* check if the node is the right child of the parent */
		if (node->parent->parent->right == node->parent)
		{
			if (node->parent->parent->left)
				return (node->parent->parent->left);
			else
				return (NULL);
		}
		/* check if the node is the left child of the parent */
		else if (node->parent->parent->left == node->parent)
		{
			if (node->parent->parent->right)
				return (node->parent->parent->right);
			else
				return (NULL);
		}
	}
	return (NULL);
}

#include "binary_trees.h"

/**
 * bst_search - searches for a node with value in binary search tree
 * @tree: pointer to root node of tree
 * @value: value of node to be discovered
 * Return: node discovered, otherwise NULL
 */
bst_t *bst_search(const bst_t *tree, int value)
{
	bst_t *temp;

	if (!tree)
		return (NULL);

	temp = (bst_t *)tree;

	while (temp)
	{
		if (value == temp->n)
			return (temp);
		else if (value < temp->n)
			temp = temp->left;
		else
			temp = temp->right;
	}
	return (NULL);
}

#include "binary_trees.h"

/**
 * bst_insert - inserts a node into a binary search tree
 * @tree: pointer to the tree
 * @value: value to be inserted
 * Return: pointer to the node
 */
bst_t *bst_insert(bst_t **tree, int value)
{
	bst_t *parent_node, *new_node;

	if (!tree)
		return (NULL);

	new_node = binary_tree_node(NULL, value);
	if (new_node == NULL)
		return (NULL);

	if (!(*tree))
		*tree = new_node;
	else
	{
		parent_node = find_parent(*tree, value);

		new_node->parent = parent_node;

		if (value == parent_node->n)
		{
			free(new_node);
			new_node = NULL;
		}
		else if (value > parent_node->n)
			parent_node->right = new_node;
		else if (value < parent_node->n)
			parent_node->left = new_node;

	}
	return (new_node);
}
/**
 * find_parent - finds the parent node of the tree node
 * @tree: The node for which its parent is to be found
 * @value: The integer value to be inserted
 * Return: proposed parent of the node to be inserted
 */
bst_t *find_parent(bst_t *tree, int value)
{
	if (value == tree->n)
		return (tree);

	else if (value < tree->n && tree->left != NULL)
		tree = find_parent(tree->left, value);

	else if (value > tree->n && tree->right != NULL)
		tree = find_parent(tree->right, value);
	return (tree);
}

#include "binary_trees.h"
/**
 * bst_remove - deletes a node in a binary search tree
 * @root: pointer to the root node of the tree
 * @value: value of the node to be deleted/removed
 * Return: pointer to the root node
 */
bst_t *bst_remove(bst_t *root, int value)
{
	bst_t *del_node, *successor;

	del_node = bst_search(root, value);
	if (del_node == NULL)
		return (root);
	if (bst_is_leaf(del_node))
	{
		free(del_node);
		return (root);
	}
	successor = find_successor(del_node);
	if (!successor)
		return (root);

	if (del_node->right == successor)
		successor->right = NULL;
	else
		successor->right = del_node->right;

	if (del_node->left == successor)
		successor->left = NULL;
	else
		successor->left = del_node->left;

	successor->parent->left = NULL;

	if (successor->right)
		successor->right->parent = successor;
	if (successor->left)
		successor->left->parent = successor;
	
	if (del_node->parent)
		successor->parent = del_node->parent;
	else
		successor->parent = NULL;
	
	if (!successor->parent)
	{
		free(del_node);
		return (successor);
	}
	
	if (del_node->parent->right == del_node)
		del_node->parent->right = successor;
	else
		del_node->parent->left = successor;
	
	free(del_node);
	return (root);
}
/**
 * bst_search - searches for a node with value in binary search tree
 * @tree: pointer to root node of tree
 * @value: value of node to be discovered
 * Return: node discovered, otherwise NULL
 */
bst_t *bst_search(const bst_t *tree, int value)
{
	bst_t *node;

	if (!tree)
		return (NULL);

	node = (bst_t *)tree;

	while (node)
	{
		if (value == node->n)
			return (node);
		else if (value < node->n)
			node = node->left;
		else
			node = node->right;
	}
	return (NULL);
}
/**
 * bst_is_leaf - checks if a node does not have
 * a child
 * @node: The node to check
 * Return: 1 if node is a leaf, otherwise 0
 */
int bst_is_leaf(bst_t *node)
{
	if (!node)
		return (0);

	if (!node->left && !node->right)
		return (1);

	if (node->left || node->right)
		return (0);
	return (0);
}
/**
 * find_successor - finds the grandchild of a node
 * @node: node for which the grandchild is to be found
 * Return: grandchild, otherwise NULL
*/
bst_t *find_successor(bst_t *node)
{
	bst_t *successor, *hold;

	if (bst_is_leaf(node))
	{
		if (node->parent->right == node)
			node->parent->right = NULL;
		else if (node->parent->left == node)
			node->parent->left = NULL;
		free(node);
		return (NULL);
	}
	if (node->right)
	{
		hold = node->right;
		successor = node->right->left;
	}
	else if (node->left)
	{
		hold = node->left;
		successor = node->left->right;
	}
	if (!successor)
	{
		successor = hold;
	}
	return (successor);
}

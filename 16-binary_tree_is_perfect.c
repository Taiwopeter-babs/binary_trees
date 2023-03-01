#include "binary_trees.h"

/**
 * binary_tree_is_perfect - check if the binary tree is perfect;
 * Every subtree has the same amount of children, and the leaves
 * are all equal in depth
 * @tree: pointer to root node of tree
 * Return: 1 if tree is perfect, otherwise 0
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	size_t height;

	if (!tree)
		return (0);

	height = binary_tree_height(tree);

	return (is_perfect(tree, height, 0));
}
/**
 * is_perfect - recursively check if the depth of the leaves
 * are all equal to the height of the tree, or if each subtree
 * has equal amount of children
 * @node: pointer to current node
 * @height: height of tree
 * @level: level of tree reached
 * Return: 1 if tree is perfect, otherwise 0
 */
int is_perfect(const binary_tree_t *node, size_t height, size_t level)
{
	/**
	 * if node is a leaf, check if its depth is equal to
	 * the height of the tree
	 */
	if (!node->right && !node->left)
	{
		return (height == binary_tree_depth(node));
	}

	if (!(node->right) || !(node->left))
	{
		return (0);
	}

	return (is_perfect(node->left, height, level + 1) &&
			is_perfect(node->right, height, level + 1));
}
/**
 * binary_tree_height - computes the height of a binary
 * tree, which is equivalent to the depth of deepest node
 * @tree: pointer to root node of tree whose height is to be measured
 * Return: height of tree
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t left_tree_height, right_tree_height;

	if (!tree || (!tree->right && !tree->left))
		return (0);

	left_tree_height = binary_tree_height(tree->left);
	right_tree_height = binary_tree_height(tree->right);

	return (find_max(left_tree_height, right_tree_height) + 1);
}

/**
 * find_max - finds the maximum
 * @val1: first value
 * @val2: second value
 * Return: maximum value
 */
size_t find_max(size_t val1, size_t val2)
{
	return ((val1 >= val2) ? val1 : val2);
}
/**
 * binary_tree_depth - computes the depth of a binary tree
 * @tree: pointer to node in tree whose depth is to be measured
 * Return: depth of tree
 */
size_t binary_tree_depth(const binary_tree_t *tree)
{
	size_t node_depth;

	if (!tree || !tree->parent)
		return (0);

	node_depth = 1 + binary_tree_depth(tree->parent);
	return (node_depth);
}

#include "binary_trees.h"

/**
 * binary_trees_ancestor - Finds the lowest common ancestor of two
 * nodes in a binary tree
 * @first: pointer to the first node
 * @second: pointer to the second node
 *
 * Return: pointer to ancestor, otherwise NULL
 */
binary_tree_t *binary_trees_ancestor(const binary_tree_t *first,
		const binary_tree_t *second)
{
	const binary_tree_t *root_node;

	root_node = get_root_node((binary_tree_t *)first);

	return (ancestor((const binary_tree_t *)root_node, first, second));
}
/**
 * ancestor - returns the lowest common ancestor
 * @node: current node
 * @first: first node
 * @second: second node
 * Return: ancestor or NULL
 */
binary_tree_t *ancestor(const binary_tree_t *node, const binary_tree_t *first,
		const binary_tree_t *second)
{
	binary_tree_t *left_subtree, *right_subtree;

	if (!node)
		return (NULL);

	if (node == first || node == second)
		return ((binary_tree_t *)node);

	left_subtree = ancestor(node->left, first, second);
	right_subtree = ancestor(node->right, first, second);

	if (left_subtree && right_subtree)
		return ((binary_tree_t *)node);
	else if (left_subtree)
		return (left_subtree);
	else if (right_subtree)
		return (right_subtree);

	return (NULL);
}
/**
 * get_root_node - gets the root node of binary_tree
 * @node: node
 * Return: root node
 */
binary_tree_t *get_root_node(binary_tree_t *node)
{
	if (!node->parent)
		return (node);

	while (node->parent)
		node = node->parent;
	return (node);
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

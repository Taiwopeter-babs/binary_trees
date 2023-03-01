#include "binary_trees.h"

/**
 * binary_tree_levelorder - prints the nodes data in the tree, level by level
 * @tree: pointer to root node of tree
 * @func: function pointer that prints node data
 * Return: nothing
 */
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	size_t tree_height, level;

	if (!tree || !(*func))
		return;

	tree_height = binary_tree_height(tree);

	for (level = 0; level <= tree_height; level++)
		level_print(tree, level, (*func));
}
/**
 * level_print - prints the tree level by level recursively
 * @tree: pointer to current node in tree
 * @level: level of tree
 * @func: function pointer that prints node's data
 *
 * Description: The idea is to print the data if the level == 0, why?
 * even if the level increases from the original function, the root node
 * is still passed as an argument to this function, so we want to recursively
 * go down the tree, and reduce the level. Then, when the level is 0, we would
 * have reached the nodes we are yet to visit and print the data
 *
 * Return: nothing
 */
void level_print(const binary_tree_t *tree, size_t level, void (*func)(int))
{
	if (level == 0)
		(*func)(tree->n);
	else
	{
		level_print(tree->left, level - 1, (*func));
		level_print(tree->right, level - 1, (*func));
	}
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

	if (!tree || (!tree->left && !tree->right))
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


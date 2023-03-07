#include "binary_trees.h"

/**
 * array_to_bst - builds a binary search tre from an array
 * @array: pointer to first element in array
 * @size: size of array
 * Return: pointer to root node of tree, otherwise NULL
 */
bst_t *array_to_bst(int *array, size_t size)
{
	size_t i;
	bst_t *root, *root_node, *node;

	if (!array)
		return (NULL);

	root = NULL;

	for (i = 0; i < size; i++)
	{
		if (array[i])
		{
			if (i == 0)
			{
				root_node = bst_insert(&root, array[i]);
				if (root_node == NULL)
					return (NULL);
			}
			else
			{
				node = bst_insert(&root, array[i]);
				if (!node)
					continue;
			}
		}
	}
	return (root_node);
}

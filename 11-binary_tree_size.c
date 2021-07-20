#include "binary_trees.h"

/**
 * binary_tree_size - measures the size of a binary tree
 * @tree: is a pointer to the root node of the tree to measure the size
 * Return: 0 if the function is NULL
 */

size_t binary_tree_size(const binary_tree_t *tree)
{
	int size_left = 0;
	int size_right = 0;
	int total_size = 0;

	if (tree == NULL)
		return (0);

	size_left = binary_tree_size(tree->left);
	size_right = binary_tree_size(tree->right);

	total_size = size_left + size_right;

	return (1 + total_size);
}

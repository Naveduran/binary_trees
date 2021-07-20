#include "binary_trees.h"

/**
 * binary_tree_nodes - counts the nodes with at least 1 child in a binary tree
 * @tree: is a pointer to the root node of the
 * tree to count the number of nodes
 * Return: 0 if the tree is NULL
 */

size_t binary_tree_nodes(const binary_tree_t *tree)
{
	int nodes_left = 0;
	int nodes_right = 0;
	int nodes;

	if (tree == NULL || (!tree->left && !tree->right))
		return (0);

	nodes_left = binary_tree_nodes(tree->left);
	nodes_right = binary_tree_nodes(tree->right);

	nodes = nodes_left + nodes_right;

	return (1 + nodes);
}

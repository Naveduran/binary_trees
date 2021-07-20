#include "binary_trees.h"

/**
 * binary_tree_height - measures the height of a binary tree
 * @tree: is a pointer to the root node of the tree to measure the height.
 * Return: 0 if the tree is NULL and the height.
 */

size_t binary_tree_height(const binary_tree_t *tree)
{
	int height_left = 0;
	int height_right = 0;

	if (tree == NULL || (tree->left == NULL && tree->right == NULL))
		return (0);

	height_left = 1 + binary_tree_height(tree->left);
	height_right = 1 + binary_tree_height(tree->right);

	if (height_left > height_right)
		return (height_left);

	else
		return (height_right);
}

/**
 * binary_tree_balance - measures the balance factor of a binary tree
 * @tree: is a pointer to the root node of the tree to measure the balance factor
 * Return: 0 if the tree is NULL
 */

int binary_tree_balance(const binary_tree_t *tree)
{
	int balance_factor;
	int height_left_child;
	int height_right_child;

    	if (tree == NULL)
		return (0);


	height_left_child = binary_tree_height(tree->left);
	height_right_child = binary_tree_height(tree->right);

	balance_factor = height_left_child - height_right_child;
	printf("node left: %d, height %d\n",tree->left->n, height_left_child);
	printf("node right: %d, height %d\n",tree->right->n, height_right_child);

	return (balance_factor);
}

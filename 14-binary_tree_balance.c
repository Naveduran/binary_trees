#include "binary_trees.h"

/**
 * bt_height - measures the height of a binary tree
 * @tree: is a pointer to the root node of the tree to measure the height.
 * Return: 0 if the tree is NULL and the height.
 */

size_t bt_height(const binary_tree_t *tree)
{
	int height_left = 0;
	int height_right = 0;

	if (tree == NULL) /*I don't exist*/
		return (0);

	if (tree->left == NULL && tree->right == NULL)
		return (1);

	if (tree->left) /*measure my left branch*/
		height_left = 1 + bt_height(tree->left);

	if (tree->right) /*measure my right branch*/
		height_right = 1 + bt_height(tree->right);

	if (height_left > height_right) /*the left is longer*/
		return (height_left);

	else /*the right is longer*/
		return (height_right);
}

/**
 * binary_tree_balance - measures the balance factor of a binary tree
 * @tree: is a pointer to the root node of the tree to
 * measure the balance factor
 * Return: 0 if the tree is NULL
 */

int binary_tree_balance(const binary_tree_t *tree)
{
	int balance_factor;

	if (tree == NULL)
		return (0);

	balance_factor =  bt_height(tree->left) -  bt_height(tree->right);

	return (balance_factor);
}

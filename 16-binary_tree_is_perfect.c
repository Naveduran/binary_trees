#include "binary_trees.h"

/**
 * binary_tree_is_full - checks if a binary tree is full
 * @tree: is a pointer to the root node of the tree to check
 * Return: 0 if the tree is NULL or is not full, 1 if it is full.
 */

int binary_tree_is_full(const binary_tree_t *tree)
{
	int left = 0, right = 0;

	/*If I don't exist*/
	if (tree == NULL)
		return (0);

	/*If I have no child*/
	if (tree->left == NULL && tree->right == NULL)
		return (1);

	/* If I have only a right */
	if (tree->left != NULL && tree->right == NULL)
		return (0);

	/* If I have only a left */
	if (tree->left == NULL && tree->right != NULL)
		return (0);

	/*Else, I have two childs*/

	/*Check  both childs fulliness*/
	left = binary_tree_is_full(tree->left);
	right = binary_tree_is_full(tree->right);

	/*If both are full, I am full too*/
	if (left == 1 && right == 1)
		return (1);

	return (0);
}

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


/**
 * binary_tree_is_perfect - checks if a binary tree is perfect
 * @tree: is a pointer to the root node of the tree to check
 * Return: If tree is NULL, your function must return 0
 */

int binary_tree_is_perfect(const binary_tree_t *tree)
{
	int height_left, height_right;
	int perfect_left, perfect_right;

	if (tree == NULL)
		return (0);

	if (tree->left == NULL && tree->left == NULL)
		return (1);

	height_left = bt_height(tree->left);
	height_right = bt_height(tree->right);

	if (height_left != height_right)
		return (0);

	perfect_left = binary_tree_is_perfect(tree->left);
	perfect_right = binary_tree_is_perfect(tree->right);
	
	if (perfect_left == perfect_right)
		return (1);

	else
		return (0);
}

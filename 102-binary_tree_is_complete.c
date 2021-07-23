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

/**
 * pow_recursion - function to emul potentiation.
 * @x: base.
 * @y: the power.
 * Return: the power y of x at y power.
 */
int pow_recursion(int x, int y)
{
	if (y < 0)
		return (-1);
	else if (y > 0)
		return (x * pow_recursion(x, y - 1));
	else
		return (1);
}

/**
 * binary_tree_is_perfect - checks if a binary tree is perfect
 * @tree: is a pointer to the root node of the tree to check
 * Return: If tree is NULL, your function must return 0
 */

int binary_tree_is_perfect(const binary_tree_t *tree)
{
	int height;
	int size;
	int iterator;
	int perfect_size = 0;

	if (tree == NULL)
		return (0);

	height = binary_tree_height(tree);
	size = binary_tree_size(tree);

	for (iterator = 0; iterator <= height; iterator++)
		perfect_size += pow_recursion(2, iterator);

	if (perfect_size != size)
		return (0);
	else
		return (1);
}

/**
 * binary_tree_is_complete - checks if a binary tree is complete
 * @tree: is a pointer to the root node of the tree to check
 * Return: If tree is NULL, your function must return 0
 */
int binary_tree_is_complete(const binary_tree_t *tree)
{
	if (binary_tree_is_perfect(tree))
		return (1);
	else
		return (0);
}

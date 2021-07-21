#include "binary_trees.h"

/**
 * binary_tree_insert_right - inserts a node as the right-child of another node
 * @parent: is a pointer to the node to insert the right-child in
 * @value: is the value to store in the new node
 * Return: a pointer to the created node,
 * or NULL on failure or if parent is NULL
 */

binary_tree_t *binary_tree_insert_right(binary_tree_t *parent, int value)
{
	binary_tree_t *right_node;

	if (parent == NULL)
		return (NULL);

	right_node = malloc(sizeof(binary_tree_t));

	if (right_node == NULL)
		return (NULL);

	/*Assign value and empty right child */
	right_node->n = value;
	right_node->left = NULL;

	/*if parent has a right child already save it as grand right child*/
	/*and assign a father*/

	if (parent->right != NULL)
	{
		right_node->right = parent->right;
		parent->right->parent = right_node;
	}

	else
		right_node->right = NULL;

	/*Assign the new right node as right child*/
	parent->right = right_node;

	/*Assign the parent of the new child*/
	right_node->parent = parent;

	return (right_node);
}

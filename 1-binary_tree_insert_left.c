#include "binary_trees.h"

/**
 * binary_tree_insert_left - inserts a node as the left-child of another node
 * @parent: is a pointer to the node to insert the left-child in
 * @value: is the value to store in the new node
 * Return: a pointer to the new node or NULL on failure or if parent is NULL
 */

binary_tree_t *binary_tree_insert_left(binary_tree_t *parent, int value)
{
	binary_tree_t *left_node;

	if (parent == NULL)
		return (NULL);

	left_node = malloc(sizeof(binary_tree_t));

	if (left_node == NULL)
		return (NULL);

	/*Assign value and empty right child */
	left_node->n = value;
	left_node->right = NULL;

	/*Assign the parent of the new child*/
	left_node->parent = parent;


	/*if parent has a left child already save it as grand left child*/
	/*and assign a father*/

	if (parent->left != NULL)
	{
		left_node->left = parent->left;
		parent->left->parent = left_node;
	}

	else
		left_node->left = NULL;

	/*Assign the new left node as left child*/
	parent->left = left_node;


	return (left_node);

}

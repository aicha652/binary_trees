#include "binary_trees.h"
/**
 * binary_tree_insert_left - function that inserts a
 * node as the left-child of another node
 * @parent: pointer to the node to insert the left-child in
 * @value: the value to store in the new node
 * Return: pointer to the created node, or NULL on failure or
 * if parent is NULL
 */
binary_tree_t *binary_tree_insert_left(binary_tree_t *parent, int value)
{
	binary_tree_t *node;

	node = malloc(sizeof(binary_tree_t));

	if (node == NULL)
		return (NULL);

	if (parent == NULL)
		return (NULL);

	if (parent->left == NULL)
	{
		node->n = value;
		parent->left = node;
		node->left = NULL;
		node->right = NULL;
		return (node);
	}
	node->n = value;
	node->left = parent->left;
	parent->left->parent = node;
	parent->left = node;
	node->parent = parent;
	node->right = NULL;
	return (node);
}

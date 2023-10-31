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
		node->parent = parent;
		node->left = NULL;
		node->right = NULL;
		parent->left = node;
		return (node);
	}
	node->n = value;
	node->parent = parent;
	node->left = parent->left;
	node->right = NULL;
	parent->left->parent = node;
	parent->left = node;
	node->left->left = NULL;
	node->left->right = NULL;
	return (node);
}

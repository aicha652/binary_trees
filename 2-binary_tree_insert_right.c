#include "binary_trees.h"
/**
 * binary_tree_insert_right - function that inserts
 * a node as the right-child of another node
 * @parent: pointer to the node to insert the right-child in
 * @value: the value to store in the new node
 * Return: pointer to the created node or NULL on failure
 * or if parent is NULL
 */
binary_tree_t *binary_tree_insert_right(binary_tree_t *parent, int value)
{
	binary_tree_t *node;

	if (parent == NULL)
		return (NULL);

	node = malloc(sizeof(binary_tree_t));
	if (node == NULL)
		return (NULL);
	
	if (parent->right == NULL)
	{
		node->parent = parent;
		node->n = value;
		node->left = NULL;
		node->right = NULL;
		parent->right = node;
		return (node);
	}
	node->parent = parent;
	node->n = value;
	node->left = NULL;
	node->right = parent->right;
	parent->right->parent = node;
	parent->right = node;
	return (node);
}

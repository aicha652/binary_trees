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

	node = malloc(sizeof(binary_tree_t));

	if (node != NULL && parent != NULL)
	{
		if (parent->right == NULL)
		{
			node->n = value;
			parent->right = node;
			return (node);
		}
		node->n = value;
		node->right = parent->right;
		parent->right->parent = node;
		parent->right = node;
		node->parent = parent;
		return (node);
	}
	return (NULL);
}

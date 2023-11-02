#include "binary_trees.h"
/**
 * binary_tree_nodes - function that counts
 * the nodes with at least 1 child in a binary tree
 * @tree: pointer to the root node of
 * the tree to count the number of nodes
 * Return: 0 if tree is NULL
 */
size_t binary_tree_nodes(const binary_tree_t *tree)
{
	size_t count = 0, count_left, count_right, result;

	if (tree == NULL)
		return (0);

	if (tree->left || tree->right)
		count += 1;

	count_left = binary_tree_nodes(tree->left);
	count_right = binary_tree_nodes(tree->right);

	result = count_left + count_right + count;

	return (result);
}

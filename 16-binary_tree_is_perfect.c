#include "binary_trees.h"
/**
 * binary_tree_is_perfect - function
 * that checks if a binary tree is perfect
 * @tree: pointer to the root node
 * of the tree to check
 * Return: 0 if tree is NULL
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	if ((binary_tree_is_full(tree) == 1) &&
			(binary_tree_balance(tree) == 0))
		return (1);
	return (0);
}
/**
 * binary_tree_is_full - function that
 * checks if a binary tree is full
 * @tree: pointer to the root node
 * of the tree to check
 * Return: 0 if tree is NULL
 */
int binary_tree_is_full(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	if (tree->left == NULL && tree->right == NULL)
		return (1);

	if ((tree->left) && (tree->right))
		return (binary_tree_is_full(tree->left)
			&& binary_tree_is_full(tree->right));
	return (0);
}
/**
 * binary_tree_balance -  function that measures
 * the balance factor of a binary tree
 * @tree: pointer to the root node
 * of the tree to measure the balance factor
 * Return: 0 if tree is NULL
 */
int binary_tree_balance(const binary_tree_t *tree)
{
size_t left_hght = 0, right_hght = 0;

if (tree == NULL)
	return (0);

left_hght = binary_tree_height(tree->left);
right_hght = binary_tree_height(tree->right);

return (left_hght - right_hght);
}

/**
 * binary_tree_height - function that measures
 * the height of a binary tree
 * @tree: pointer to the root node of the
 * tree to measure the height
 * Return: 0 if tree is NULL
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
size_t left_height = 0, right_height = 0;

if (tree == NULL)
	return (0);

left_height = 1 + binary_tree_height(tree->left);
right_height = 1 + binary_tree_height(tree->right);

if (left_height > right_height)
	return (left_height);
else
	return (right_height);
}

#include "binary_trees.h"

/**
 * init_queue - initializes queue
 *
 * @q: queue ruler
 */
static void init_queue(queue *q)
{
	q->head = NULL;
	q->tail = NULL;
}

/**
 * enqueue - adds node to queue
 *
 * @q: queue ruler
 * @pointer: pointer as node main value
 * Return: int 0 in case of failure, 1 if succesful enqueue
 */
static int enqueue(queue *q, binary_tree_t *pointer)
{
	node *newnode = malloc(sizeof(node));

	if (!newnode)
		return (0);
	newnode->pointer = pointer;
	newnode->next = NULL;
	/** make sure the head makes sense. */
	if (q->head == NULL)
		q->head = newnode;
	/** if there is a tail, connect tail to this new node. */
	if (q->tail != NULL)
		q->tail->next = newnode;
	q->tail = newnode;
	return (1);
}

/**
 * dequeue - dequeue process
 *
 * @q: queue ruler
 * Return: binary_tree_t*
 */
static binary_tree_t *dequeue(queue *q)
{
	node *tmp = NULL;
	binary_tree_t *pointer;

	/** check to see if the queue is empty */
	if (!q->head)
		return (NULL);
	tmp = q->head;
	/** save the result we are going to return */
	pointer = tmp->pointer;
	/** take it off */
	q->head = q->head->next;
	if (!q->head)
		q->tail = NULL;
	free(tmp);
	return (pointer);
}

/**
 * binary_tree_levelorder - goes through a binary tree using level-order
 * traversal
 * @tree: pointer to root of tree
 * @func: function to be called on each node
 */
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	queue q1;
	binary_tree_t *t = NULL;

	if (!tree || !func)
		return;
	init_queue(&q1);
	t = (binary_tree_t*)tree;
	enqueue(&q1, t);
	while ((t = dequeue(&q1)) != NULL)
	{
		func(t->n);
		if (t->left)
			enqueue(&q1, t->left);
		if (t->right)
			enqueue(&q1, t->right);
	}
}

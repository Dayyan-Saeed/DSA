Node *reversesingly(Node*node)
{
	if (node == NULL)
	{
		return NULL;
	}
	if (node->next == NULL)
	{
		head = node;
		return node;
	}
	Node*node1 = reversesingly(node->next);
	node1->next = node;
	node1->next = NULL;
	return node;
}
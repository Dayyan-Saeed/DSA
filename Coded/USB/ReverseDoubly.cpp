Node* Reverse(Node* node)
{
	if (!node)
		return NULL;
	Node* temp = node->next;
	node->next = node->pre;
	node->pre = temp;
	if (!node->pre)
		return node;
	return Reverse(node->pre);
}
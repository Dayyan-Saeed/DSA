template <class T>
void BST<T>::printKthSmallest(int k)
{
	int count = 0;
	T check = KthSMALLEST(root, k, count);
	if (check)
		cout << "Kth Element: " << check << endl;
	else
		cout << "There are less than 'K' Elements in the Tree." << endl;

}

template <class T>
T BST<T>::KthSMALLEST(Node<T>* n, int k, int& count)
{
	if (n == nullptr)
		return NULL;

	T check = KthSMALLEST(n->left, k, count);
	cout << "Check: " << check << " | Count: " << count << " | N: " << n->data << endl;

	if (check != NULL)
		return check;
	count++;
	if (count == k)
		return n->data;
	return KthSMALLEST(n->right, k, count);
}

template <class T>
void BST<T>::printKthLargest(int k)
{
	int count = 0;
	T check = KthLargest(root, k, count);
	if (check)
		cout << "Kth Element: " << check << endl;
	else
		cout << "There are less than 'K' Elements in the Tree." << endl;

}

template <class T>
T BST<T>::KthLARGEST(Node<T>* n, int k, int& count)
{
	if (n == nullptr)
		return NULL;

	T check = KthLARGEST(n->right, k, count);
	if (check != NULL)
		return check;
	count++;
	if (count == k)
		return n->data;
	return KthLARGEST(n->left, k, count);
}
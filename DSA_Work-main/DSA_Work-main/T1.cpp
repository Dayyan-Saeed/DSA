#include<iostream>
using namespace std;
void SelectionSort(int *&arr,int size)
{
	int small = 0;
	for (int i = 0; i < size; i++)
	{
		small = i;
		for (int j = i+1; j < size; j++)
		{
			if (arr[j] < arr[small])
			{
				small = j;
			}
		}
		int temp = arr[i];
		arr[i] = arr[small];
		arr[small] = temp;

	}
}
int main()
{
	int size = 0;
	cout << "enter the size of array\n";
	cin >> size;
	int* array = new int[size];
	for (int i = 0; i < size; i++)
	{
		array[i] = (rand() % 100)+10;
		cout << array[i] << "\n";
	}
	SelectionSort(array, size);
	cout << "after sorting\n";
	for (int i = 0; i < size; i++)
	{
		
		cout << array[i] << "\n";
	}



}
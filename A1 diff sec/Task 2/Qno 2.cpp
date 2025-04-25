#include"Stack.h"

char* Infix_To_Postfix(const char* arr);

int main()
{
	char* arr = new char[100];

	cout << "Enter Parenthesized Infix Expression : ";
	cin.getline(arr, 100);

	cout << "PostFix Expression : " << Infix_To_Postfix(arr) << endl<<endl;
	
	delete[] arr;
	arr = nullptr;

	return 0;
}

char* Infix_To_Postfix(const char* arr)
{
	Stack obj(100);

	char temp = '\0', temp1 = '\0';
	int size = 0, flag = 0;

	char*array = new char[1000];

	for (int i = 0; arr[i] != '\0'; i++)
	{
		if (arr[i] == ')')
		{
			temp = obj.pop();
			temp1 = obj.pop();

			array[size++] = ' ';

			if ((temp == '/') || (temp == '-') || (temp == '+') || (temp == '*'))
				array[size++] = temp;
			if ((temp1 == '/') || (temp1 == '-') || (temp1 == '+') || (temp1 == '*'))
				array[size++] = temp1;
		}

		else if ((arr[i] >= 'A' && arr[i] <= 'Z') || (arr[i] >= 'a' && arr[i] <= 'z') || (arr[i] >= '0' && arr[i] <= '9'))
		{
			if (flag==1)
				array[size++] = ' ';
			
			array[size++] = arr[i];
			flag = 0;
		}

		else
		{
			if (arr[i] != ' ')
			{
				if ((arr[i] == '/') || (arr[i] == '-') || (arr[i] == '+') || (arr[i] == '*'))
					flag = 1;
				obj.push(arr[i]);
			}
		}
	}

	array[size] = '\0';

	return array;
}
#include<iostream>
#include<string>
#include<assert.h>
using namespace std;

class STACK 
{
private:
	int StackTotalSize;
	int Stack_Top_Value;
	char *Char_List;
public:
	STACK(int stackSize)
	{
		if (stackSize <= 0)
		{
			StackTotalSize = 100;
		}
		else
		{
			StackTotalSize = stackSize;
		}
		Stack_Top_Value = 0;
		Char_List = new char[StackTotalSize];
	}

	void copyStack(const STACK& otherStack)
	{
		delete[] Char_List;
		StackTotalSize = otherStack.StackTotalSize;
		Stack_Top_Value = otherStack.Stack_Top_Value;
		Char_List = new char[StackTotalSize];
		for (int itr = 0; itr < Stack_Top_Value; itr++)
		{
			Char_List[itr] = otherStack.Char_List[itr];
		}
	}
	void Stack_initialize()
	{
		Stack_Top_Value = 0;
	}
	bool is_Empty() const
	{
		return(Stack_Top_Value == 0);
	}
	bool is_Full() const
	{
		return(Stack_Top_Value == StackTotalSize);
	}
	void Push_Value(const char& newItem)
	{
		if (!is_Full())
		{
			Char_List[Stack_Top_Value] = newItem;
			Stack_Top_Value++;
		}
		else
		{
			cout << "Stack Full, No More Space To Add Anything." << endl;
		}
	}
	char Top_Value() const
	{
		assert(Stack_Top_Value != 0);
		return Char_List[Stack_Top_Value - 1];
	}
	void Pop_Value()
	{
		if (!is_Empty())
		{
			Stack_Top_Value--;
		}
		else
		{
			cout << "Stack Empty, Cannot Remove Anything." << endl;
		}
	}
		
	STACK(const STACK& otherStack)
	{
		Char_List = NULL;
		copyStack(otherStack);
	}

	~STACK()
	{
		delete[] Char_List;
	}

};
void Alteration()
{
	int Total_size = 100;
	char *Arr_Input = new char[Total_size];
	cout << "Dear User, Please Enter Input To For Changing: " << endl;
	cin.getline(Arr_Input, Total_size);
	int String_Size = 0;
	for (int itr = 0; Arr_Input[itr] != '\0'; itr++)
	{
		String_Size++;
	}
	STACK S1(String_Size);
	
	cout <<endl<< "---------------------------------------"<<endl;
	for (int itr = 0; itr <= String_Size; itr++)
	{
		if (Arr_Input[itr] == '(' || Arr_Input[itr] == '-' || Arr_Input[itr] == '+' || Arr_Input[itr] == '*' || Arr_Input[itr] == '/')
		{
			S1.Push_Value(Arr_Input[itr]);
		}
		else if (Arr_Input[itr] == ')')
		{
			cout << " " << S1.Top_Value() << " ";
			S1.Pop_Value();
			S1.Pop_Value();
		}
		else
		{
			if (Arr_Input[itr + 1] == ' ')
			{
				cout << Arr_Input[itr] << " ";
			}
			else if (Arr_Input[itr] >= '1' && Arr_Input[itr] <= '9')
			{
				cout << Arr_Input[itr];
			}
		}
	}
	cout << endl;
	cout << "---------------------------------------" << endl;

}
int main()
{
	cout << "----------------------------------------------------" << endl;
	cout << ":: Conversion Of Infix Expression To Postfix Form ::" << endl;
	cout << "----------------------------------------------------" << endl << endl;

	Alteration();
	return 0;
}
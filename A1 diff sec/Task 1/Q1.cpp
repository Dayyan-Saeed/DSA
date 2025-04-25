#include<fstream>
#include"Stack.h"

void read_maze(const char* file, int**& dptr, int& r_size, int& c_size)
{
	char* arr = new char[500];
	r_size = 0, c_size = 0;

	ifstream fin;
	fin.open(file);
	if (!fin.is_open())
		cout << "\nError : File Not Found..." << endl;
	else
	{
		while (!fin.eof())
		{
			fin.getline(arr, 100);
			if (r_size == 0)
			{
				for (int i = 0; arr[i] != '\0'; i++)
				{
					if (arr[i] >= '0' && arr[i] <= '9')
						c_size++;
				}
			}
			r_size++;
		}
		fin.close();

		dptr = new int*[r_size];
		for (int i = 0; i < r_size; i++)
			dptr[i] = new int[c_size];

		fin.open(file);
		if (fin.is_open())
		{
			for (int i = 0; i < r_size; i++)
			{
				for (int j = 0; j < c_size; j++)
					fin >> dptr[i][j];
			}
		}
		fin.close();
	}
	delete[] arr;
	arr = nullptr;
}

char* Reverse(const char*arr, int size)
{
	char* temp = new char[size];
	int x = 0;

	for (int i = size - 1; i >= 0; i--)
		temp[x++] = arr[i];

	temp[x] = '\0';

	return temp;
}

void write_maze(const char* file, int** dptr, const int r, const int c, char* arr)
{
	ofstream fout;
	fout.open(file);
	fout << "Path :- " << endl << endl;
	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c; j++)
		{
			fout << dptr[i][j] << " ";
		}
		fout << endl;
	}

	fout << endl << "Steps :- " << endl << endl;
	for (int i = 0; arr[i] != '\0'; i++)
	{
		fout << i + 1 << ") ";
		if (arr[i] == 'R')
			fout << "Right";
		else if (arr[i] == 'L')
			fout << "Left";
		else if (arr[i] == 'D')
			fout << "Down";
		else
			fout << "Up";
		fout << endl;
	}

	cout << "Your Answer is stored in the " << file << endl << "Go and Check It..." << endl << endl;
	cout << "Thanks For Using This Program...." << endl << endl;

	fout.close();
}

int main()
{
	int**maze;
	int row = 0, col = 0;

	read_maze("input.txt", maze, row, col);
	if (row != 0 && col != 0){
		int** outputMaze = new int*[row];
		for (int i = 0; i < row; i++)
			outputMaze[i] = new int[col];

		for (int i = 0; i < row; i++)
		{
			for (int j = 0; j < col; j++)
				outputMaze[i][j] = 0;
		}

		Stack obj(1000);

		int x = 0, y = 0;
		outputMaze[0][0] = 1;

		char temp = {};
		int flag = 0, flag1 = 0;

		while ((x != row - 1) || (y != col - 1))
		{
			if ((maze[x][y + 1] == 1) && (outputMaze[x][y + 1] != 1) && (x <= row - 1 && y <= col - 1) && (flag == 0))
			{
				obj.push('R');
				outputMaze[x][y++] = 1;
			}

			else if ((maze[x + 1][y] == 1) && (outputMaze[x][y + 1] != 1) && (x <= row - 1 && y <= col - 1) && (flag1 == 0))
			{
				obj.push('D');
				outputMaze[x++][y] = 1;
			}

			else if (maze[x + 1][y] != 1 && maze[x][y + 1] != 1)
			{
				temp = obj.top();
				if (temp == 'D')
				{
					if ((maze[x - 1][y] == 1) && (x != -1) && (outputMaze[x - 1][y] == 1) && (x <= row - 1 && y <= col - 1))
					{
						obj.pop();
						x--;
						flag1 = 1;
					}

					else if ((maze[x][y - 1] == 1) && (y != -1) && (outputMaze[x][y - 1] != 1) && (x <= row - 1 && y <= col - 1))
					{
						obj.push('L');
						outputMaze[x][y--] = 1;
					}
				}

				if (temp == 'R')
				{
					if ((maze[x][y - 1] == 1) && (y != -1) && (outputMaze[x][y - 1] == 1) && (x <= row - 1 && y <= col - 1))
					{
						obj.pop();
						y--;
						flag = 1;
					}
					else if ((maze[x - 1][y] == 1) && (x != -1) && (outputMaze[x - 1][y] != 1) && (x <= row - 1 && y <= col - 1))
					{
						obj.push('U');
						outputMaze[x--][y] = 1;
					}

				}

			}
			if (flag == 1)
				flag++;
			else
				flag = 0;

			if (flag1 == 1)
				flag1++;
			else
				flag1 = 0;

		}

		outputMaze[row - 1][col - 1] = 1;

		for (int i = 0; i < row; i++)
		{
			for (int j = 0; j < col; j++)
			{
				if (outputMaze[i][j] == 1)
					outputMaze[i][j] = 2;
			}
		}



		char* t_arr = new char[100];
		int len = 0;
		while (!obj.empty())
		{
			t_arr[len++] = obj.pop();
		}
		t_arr[len] = '\0';

		t_arr = Reverse(t_arr, len);

		write_maze("output.txt", outputMaze, row, col, t_arr);

	}
	return 0;
}
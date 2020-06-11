#include <iostream>
#include <cstdlib>
#include <iomanip>
#include <ctime>
#include <vector>
#include <conio.h> //getch
#include <windows.h>
using namespace std;


void print(vector<vector<char> >number)
{
	for (int i = 0; i < 22; i++)
	{
		for (int j = 0; j < 22; j++)
		{
			cout << setw(2) << number[i][j];
		}
		cout << endl;
	}
}

int* money(vector<vector<char> >number)
{
	int* point = new int[2];

	for (int i = 0; i < 22; i++)
	{
		for (int j = 0; j < 22; j++)
		{
			if (number[i][j] == '$')
			{
				point[0] = i;
				point[1] = j;
				return point;
			}
		}
	}
	point[0] = 0;
	point[1] = 0;
	return point;
}

int* star(vector<vector<char> >number)
{
	int* point = new int[2];

	for (int i = 0; i < 22; i++)
	{
		for (int j = 0; j < 22; j++)
		{
			if (number[i][j] == 'O')
			{
				point[0] = i;
				point[1] = j;
				return point;
			}
		}
	}
}

vector<vector<char> > food(vector<vector<char> >number)
{

	int *moneyPoint = money(number);
	int row = *moneyPoint;
	int col = *(moneyPoint + 1);


	while (row == 0 && col == 0)
	{
		int food_1 = rand() % 20 + 1;
		int food_2 = rand() % 20 + 1;
		number[food_1][food_2] = '$';


	}


	return number;
}

int die(vector<vector<char> >number)
{

}

vector<vector<char> > move(vector<vector<char> >number, int input)
{
	int *starPoint = star(number);
	int row = *starPoint;
	int col = *(starPoint + 1);

	switch (input)
	{
	case 72:																		//¤W 	

		swap(number[row][col], number[row - 1][col]);
		break;

	case 80:																					//¤U 

		swap(number[row][col], number[row + 1][col]);
		break;

	case 75:																		//¥ª

		swap(number[row][col], number[row][col - 1]);
		break;

	case 77:																		//¥k 

		swap(number[row][col], number[row][col + 1]);
		break;
	}
	return number;
}

int z(int input)
{
	int newInput = input;

	if (_kbhit())
	{
		_getch();
		newInput = _getch();
	}

	return newInput;
}


int main()
{
	vector<vector <char> > x(22, vector<char>(22));

	for (int i = 0; i < 21; i++)
	{
		x[0][i] = '*';									//¤WÀð
		x[i][21] = '*';									//¥kÀð
		x[21][i + 1] = '*';								//¤UÀð
		x[i + 1][0] = '*';								//¥ªÀð

	}
	x[10][10] = 'O';

	int input = 80;
	while (1)
	{

		int *starPoint = star(x);
		int row = *starPoint;
		int col = *(starPoint + 1);
		x = food(x);
		print(x);
		input = z(input);

		x = move(x, input);


		/*int *moneyPoint = money(x);
		int mrow = *moneyPoint;
		int mcol = *(moneyPoint + 1);

		cout<<mrow<<" "<<mcol <<endl;*/


		Sleep(250);
		system("cls");
	}




	system("pause");
	return 0;
}
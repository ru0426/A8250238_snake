#include <iostream>
#include <cstdlib>
#include <iomanip>
#include <ctime>
#include <vector>
#include <conio.h> //getch
#include <windows.h>
using namespace std;

/*void move(string number[][4]) //����
{
int *starPoint = star(number);
int row = *starPoint;
int col = *(starPoint + 1);

print(number);

int input = _getch();
switch (input)
{
//�W
case 72:
if (row != 0)
swap(number[row][col], number[row - 1][col]);
break;
//�U
case 80:
if (row != 3)
swap(number[row][col], number[row + 1][col]);
break;
//��
case 75:
if (col != 0)
swap(number[row][col], number[row][col - 1]);
break;
//�k
case 77:
if (col != 3)
swap(number[row][col], number[row][col + 1]);
break;
}
}*/

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

void move(vector<vector<char> >number)
{
	int* starPoint = star(number);
	int row = *starPoint;
	int col = *(starPoint + 1);

	print(number);

	int input = _getch();
	switch (input)
	{

	case 72: 
		if (row != 0)
			swap(number[row][col], number[row - 1][col]);//�W
		break;

	case 80: 
		if (row != 3)
			swap(number[row][col], number[row + 1][col]);//�U
		break;

	case 75: 
		if (col != 0)
			swap(number[row][col], number[row][col - 1]);//��
		break;

	case 77:
		if (col != 3)
			swap(number[row][col], number[row][col + 1]);//�k
		break;
	}
}
int main()
{
	vector<vector <char> > x(22, vector<char>(22));

	x[0][0] = '*'; //�W��
	x[0][1] = '*';
	x[0][2] = '*';
	x[0][3] = '*';
	x[0][4] = '*';
	x[0][5] = '*';
	x[0][6] = '*';
	x[0][7] = '*';
	x[0][8] = '*';
	x[0][9] = '*';
	x[0][10] = '*';
	x[0][11] = '*';
	x[0][12] = '*';
	x[0][13] = '*';
	x[0][14] = '*';
	x[0][15] = '*';
	x[0][16] = '*';
	x[0][17] = '*';
	x[0][18] = '*';
	x[0][19] = '*';
	x[0][20] = '*';

	x[0][21] = '*'; //�k��
	x[1][21] = '*';
	x[2][21] = '*';
	x[3][21] = '*';
	x[4][21] = '*';
	x[5][21] = '*';
	x[6][21] = '*';
	x[7][21] = '*';
	x[8][21] = '*';
	x[9][21] = '*';
	x[10][21] = '*';
	x[11][21] = '*';
	x[12][21] = '*';
	x[13][21] = '*';
	x[14][21] = '*';
	x[15][21] = '*';
	x[16][21] = '*';
	x[17][21] = '*';
	x[18][21] = '*';
	x[19][21] = '*';
	x[20][21] = '*';

	x[21][1] = '*'; //�U��
	x[21][2] = '*';
	x[21][3] = '*';
	x[21][4] = '*';
	x[21][5] = '*';
	x[21][6] = '*';
	x[21][7] = '*';
	x[21][8] = '*';
	x[21][9] = '*';
	x[21][10] = '*';
	x[21][11] = '*';
	x[21][12] = '*';
	x[21][13] = '*';
	x[21][14] = '*';
	x[21][15] = '*';
	x[21][16] = '*';
	x[21][17] = '*';
	x[21][18] = '*';
	x[21][19] = '*';
	x[21][20] = '*';
	x[21][21] = '*';

	x[1][0] = '*'; //����
	x[2][0] = '*';
	x[3][0] = '*';
	x[4][0] = '*';
	x[5][0] = '*';
	x[6][0] = '*';
	x[7][0] = '*';
	x[8][0] = '*';
	x[9][0] = '*';
	x[10][0] = '*';
	x[11][0] = '*';
	x[12][0] = '*';
	x[13][0] = '*';
	x[14][0] = '*';
	x[15][0] = '*';
	x[16][0] = '*';
	x[17][0] = '*';
	x[18][0] = '*';
	x[19][0] = '*';
	x[20][0] = '*';
	x[21][0] = '*';

	x[10][10] = 'O';

	/* for (int i = 0; i < 22; i++)
	{
	for (int j = 0; j < 22; j++)
	{
	cout << setw(2) << x[i][j];
	}
	cout << endl;
	}*/

	for (int i = 0; i < 10; i++)
	{
		Sleep(1000);
		system("cls");
		move(x);
	}

	/* for (int i; i < 5; i++)
	{
	Sleep(1000);
	system("cls");
	int *starPoint = star(x);
	int row = *starPoint;
	int col = *(starPoint + 1);
	x[row][col]=' ';
	x[row+1][col]='O';

	for (int i = 0; i < 22; i++)
	{
	for (int j = 0; j < 22; j++)
	{
	cout << setw(2) << x[i][j];
	}
	cout << endl;
	}
	}*/

	/*int ary[2] = { *star(x) }; //��point QQ
	for (int i = 0; i < 2; i++)cout << ary[i]<<endl;*/

	/*for (int i;; i++)
	{
	Sleep(1000); //�M���e��
	system("cls");

	}*/





	system("pause");
	return 0;
}
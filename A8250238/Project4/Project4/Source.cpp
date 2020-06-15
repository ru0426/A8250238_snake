#include <iostream>
#include <cstdlib>
#include <iomanip>
#include <ctime>
#include <vector>
#include <conio.h> //getch
#include <windows.h>
using namespace std;


void print(vector<vector<char> >number)											//�L�X��ӹC���e��
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

int* money(vector<vector<char> >number)									//�������m
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

int* head(vector<vector<char> >number)												//��D�Y����m
{
	int* point = new int[2];

	for (int i = 0; i < 22; i++)
	{
		for (int j = 0; j < 22; j++)
		{
			if (number[i][j] == '@')
			{
				point[0] = i;
				point[1] = j;
				return point;
			}
		}
	}
}

vector<vector<char> > newMoney(vector<vector<char> >number)								//���ͤ@�ӷs����
{

	int *moneyPoint = money(number);
	int mrow = *moneyPoint;
	int mcol = *(moneyPoint + 1);

	if (mrow == 0 && mcol == 0)
	{
		int newMoney_1 = rand() % 20 + 1;
		int newMoney_2 = rand() % 20 + 1;
		number[newMoney_1][newMoney_2] = '$';
	}

	return number;
}

vector<vector<char> > move(vector<vector<char> >number, int input)								//��V�䱱��D����
{
	int *headPoint = head(number);
	int row = *headPoint;
	int col = *(headPoint + 1);

	switch (input)
	{
	case 72:																		//�W 	

		swap(number[row][col], number[row - 1][col]);
		break;

	case 80:																		//�U 

		swap(number[row][col], number[row + 1][col]);
		break;

	case 75:																		//��

		swap(number[row][col], number[row][col - 1]);
		break;

	case 77:																		//�k 

		swap(number[row][col], number[row][col + 1]);
		break;
	}
	return number;
}

vector<vector<char> > eat(vector<vector<char> >number, int input)
{

	static int inBody = 0, delete1, delete2, lastmrow, lasemcol, c = 1;
	static vector<int> body(100);

	static bool isEat;
	if(isEat)
		c++;
	/*number[lastmrow][lasemcol]=' ';*/

	int *moneyPoint = money(number);
	int mrow = *moneyPoint;
	int mcol = *(moneyPoint + 1);

	int *coheadPoint = head(number);												//���ʫe�Y����m
	int corow = *coheadPoint;
	int cocol = *(coheadPoint + 1);

	

	number = move(number, input);

	int *nowheadPoint = head(number);												//���ʫ��Y����m
	int nowrow = *nowheadPoint;
	int nowcol = *(nowheadPoint + 1);

	int i;
	

	for (int j=inBody+1+1, i = inBody+1; i >= 1; i--,j--)									//�O��C���e�@������m
	{
		if (i > 1)
		{
			body[i +i] = body[i+i-2];
			body[j +i] = body[j+i-2];
		}

		if (i <= 1)
		{
			body[2] = corow;
			body[3] = cocol;
			body[0] = nowrow;
			body[1] = nowcol;
		}
		
		if(i>=1&& i==inBody)
			number[body[i * 2 + 2]][body[j * 2 + 1]] = ' ';
	}
	
	for (int i = 1; i <= inBody; i++)
	{
		number[body[(i+1) * 2 - 2]][body[(i+1) * 2 - 2 + 1]] = 'O';
	}

	lastmrow = corow;
	lasemcol = cocol;

	/*for (int i = 0; i < 20; i++)											//�L�X����Ҧ���m
	{
		cout <<setw(2)<< body[i]<<" ";
	}*/

	int *headPoint = head(number);
	int row = *headPoint;
	int col = *(headPoint + 1);

	isEat = 0;
	if (mrow == row && mcol == col)									
	{
		int *moneyPoint = money(number);
		lastmrow = *moneyPoint;
		lasemcol = *(moneyPoint + 1);
		number[lastmrow][lasemcol] = ' ';
		if(inBody==2)
		isEat = 1;
		inBody++;
	}
	return number;
}

int isDie(vector<vector<char> >number, int input)									//�P�_�O�_���`
{
	int *headPoint = head(number);												//���ʫe�Y����m
	int row = *headPoint;
	int col = *(headPoint + 1);

	number = move(number, input);

	int *nowheadPoint = head(number);												//���ʫ��Y����m
	int nowrow = *nowheadPoint;
	int nowcol = *(nowheadPoint + 1);

	if (row == 0 || row == 21 || col == 0 || col == 21||number[row][col]=='O')
	{
		return 1;
	}
	return -1;
}

int z(int input)																//���੹�M�ۤv�Ϥ�V�e�i
{
	int newInput = input;

	if (_kbhit())
	{
		_getch();
		newInput = _getch();
		if (abs(newInput - input) == 2 || abs(newInput - input) == 8)
		{
			newInput = input;
		}
	}
	return newInput;
}

int main()
{
	vector<vector <char> > x(22, vector<char>(22));

	for (int i = 0; i < 21; i++)
	{
		x[0][i] = '*';									//�W��
		x[i][21] = '*';									//�k��
		x[21][i + 1] = '*';								//�U��
		x[i + 1][0] = '*';								//����
	}
	x[10][10] = '@';

	int input = 80;
	while (1)
	{
		for (int i = 0; i < 21; i++)
		{
			x[0][i] = '*';									//�W��
			x[i][21] = '*';									//�k��
			x[21][i + 1] = '*';								//�U��
			x[i + 1][0] = '*';								//����
		}
		int *headPoint = head(x);
		int row = *headPoint;
		int col = *(headPoint + 1);
		int die = isDie(x,input);

		if (die != -1)
		{
			Sleep(200);
			system("cls");
			cout << "\n\n\n\n\t\tGame Over";
			Sleep(700);
			return 0;
		}

		x = newMoney(x);
		print(x);
		input = z(input);
		x = eat(x, input);

		Sleep(250);
		system("cls");
	}
	system("pause");
	return 0;
}
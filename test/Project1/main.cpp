#include <iostream>
#include <vector> 
using namespace std;

int main() {
	vector<vector<vector<int>>> dates(5, vector<vector<int>>(4, vector<int>(4)));
	int n = 1;
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 4; j++) {
			for (int k = 0; k < 4; k++) {
				dates[i][j][k] = n;
				n++;
			}
		}
	}

	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 4; j++) {
			for (int k = 0; k < 4; k++) {
				cout<<dates[i][j][k];
			}
			cout << endl;
		}
		cout << endl;
	}
	system("pause");
	return 0;
}
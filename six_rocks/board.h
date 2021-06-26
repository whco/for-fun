#pragma once
#include <iostream>
#include <vector>
using namespace std;

class Board {
private:
	unsigned int size;
	vector<vector<int>> board;
	char shape(int i) {
		if (i == 0)return '+';
		if (i == 1)return 'O';
		if (i == 2)return 'X';
	}
public:
	Board(unsigned int n){
		size = n;
		board = vector<vector<int>>(size, vector<int>(size, 0));
	}
	void put(int r, int c, int m) { board[r][c] = m; }
	bool win_detection() {
		for(int i = 0; i + 5 < size; ++i)
			for (int j = 0; j + 5 < size; ++j) {
				if (board[i][j]) {
					int con1 = 1, r1 = i, c1 = j;
					while (board[i][j] == board[r1 + 1][c1]) {
						++r1;
						++con1;
						if (con1 >= 6) {
							cout << (board[i][j] == 1 ? "black" : "white") << " won" << endl;
							return true;
						}
					}
					int con2 = 1, r2 = i, c2 = j;
					while (board[i][j] == board[r2][c2 + 1]) {
						++c2;
						++con2;
						if (con2 >= 6) {
							cout << (board[i][j] == 1 ? "black" : "white") << " won" << endl;
							return true;
						}
					}
					int con3 = 1, r3 = i, c3 = j;
					while (board[i][j] == board[r3 + 1][c3 + 1]) {
						++r3;
						++c3;
						++con3;
						if (con3 >= 6) {
							cout << (board[i][j] == 1 ? "black" : "white") << " won" << endl;
							return true;
						}
					}
					if (i - 5 >= 0) {
						int con4 = 1, r4 = i, c4 = j;
						while (board[i][j] == board[r4 - 1][c4 + 1]) {
							--r4;
							++c4;
							++con4;
							if (con4 >= 6) {
								cout << (board[i][j] == 1 ? "black" : "white") << " won" << endl;
								return true;
							}
						}
					}
					if (j - 5 >= 0) {
						int con5 = 1, r5 = i, c5 = j;
						while (board[i][j] == board[r5 + 1][c5 - 1]) {
							++r5;
							--c5;
							++con5;
							if (con5 >= 6) {
								cout << (board[i][j] == 1 ? "black" : "white") << " won" << endl;
								return true;
							}
						}
					}
				}
			}
		return false;
	}
	void printboard() {
		cout << "  ";
		for (int i = 0; i < size; ++i)
		{
			if (i < 9)cout << ' ' << i ;
			else if (i == 9) cout << ' '<<i<<' ';
			else cout << i ;
		}
		cout << endl;
		for (int i = 0; i < size; ++i){
			if (i < 10)cout << ' ' << i << ' ';
			else cout << i << ' ';

			for (int j = 0; j < size; ++j)
				cout << shape(board[i][j]) << ' ';
			cout << endl;
		}
	}
	void reset() {
		for (int i = 0; i < size; ++i)
			for (int j = 0; j < size; ++j)
				board[i][j] = 0;
	}
};
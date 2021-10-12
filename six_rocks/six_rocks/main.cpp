#include "board.h"
using namespace std;

int main() {
	int n;
	cout << "input board size : ";
	cin >> n;
	Board b(n);
	b.printboard();
	int turn = 1;
	while (!b.win_detection()) {
		int r, c;
		if (turn == 1) {
			cout << "Black's turn - input r, c once : ";
			cin >> r >> c;
			b.put(r, c, 1);
			b.printboard();
			++turn;
		}
		else {
			if (turn % 2 == 0) {
				int left = 2;
				while (left) {
					printf("White's turn - input r, c twice( %d left) : ",left--);
					cin >> r >> c;
					b.put(r, c, 2);
					b.printboard();
					if (b.win_detection())break;
				}
				++turn;
			}
			else if (turn % 2 == 1) {
				int left = 2;
				while (left) {
					printf("Black's turn - input r, c twice( %d left) : ", left--);
					cin >> r >> c;
					b.put(r, c, 1);
					b.printboard();
					if(b.win_detection())break;
				}
				++turn;
			}
		}
	}
}
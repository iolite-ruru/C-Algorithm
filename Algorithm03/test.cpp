#include <string>
#include <vector>
#include <queue>
#include <iostream>
using namespace std;

int pos[][8] = {
	//{ 0, -1, 0, 1 },
	//{-1, 0, 1, 0 }
	//{-1, -1, 0, 1, 1, 1, 0, -1},
	//{0, 1, 1, 1, 0, -1, -1, -1}

	{-1, 1, 0, 0, -1, -1, 1, 1},
	{0, 0, -1, 1, -1, 1, -1, 1}
};

void func(vector<string>& places, int (*check)[5], int& x, int& y, int& flag) {
	int currentX, currentY;

	int chk[5][5] = { 0, };
	chk[x][y] = 1;
	
	for (int i = 0; i < 4; i++) {
		currentX = x + pos[0][i];
		currentY = y + pos[1][i];
		
		if (currentX < 0 || currentX > 4 || currentY < 0 || currentY > 4) {
			continue;
		}
		
		if (chk[currentX][currentY]==0 && places[currentX][currentY] == 'P') {
			flag = 0;
			return;
		}
		chk[currentX][currentY] = 1;

		for (int j = 0; j < 8; j++) {
			int nextX = currentX + pos[0][j];
			int nextY = currentY + pos[1][j];
			
			if (nextX < 0 || nextX > 4 || nextY < 0 || nextY > 4) {
				continue;
			}
			//cout << "____________" << endl;

			if (chk[nextX][nextY] == 0 && places[nextX][nextY] == 'P') {
				//cout << "+++++++++++++" << endl;
				if (places[currentX][currentY] == 'X') {
					flag = 1;
				}
				else {
					flag = 0;
					return;
				}
			}
		}
	}
}

vector<int> solution(vector<vector<string>> places) {
	vector<int> answer;

	for (int i = 0; i < 5; i++) {
		vector<string> temp = places[i];
		int check[5][5] = { 0, };
		int flag = 1;

		for (int j = 0; j < 5; j++) {
			for (int k = 0; k < 5; k++) {
				if (temp[j][k] == 'P') {
					func(temp, check, j, k, flag);
					if (flag == 0) break;
				}
				if (flag == 0) break;
			}
		}
		answer.push_back(flag);
	}
	for (auto&e : answer)
		cout << e << "  ";
	return answer;
}
int main() {
	vector<vector<string>> v =
	{ {"POOOP", "OXXOX", "OPXPX", "OOXOX", "POXXP"},{"POOPX", "OXPXP", "PXXXO", "OXXXO", "OOOPP" },
	{"PXOPX", "OXOXP", "OXPOX", "OXXOP", "PXPOX" },{"OOOXX", "XOOOX", "OOOXX", "OXOOX", "OOOOO" },
	{ "PXPXP", "XPXPX", "PXPXP", "XPXPX", "PXPXP"} };
	solution(v);
}

/*

#include <string>
#include <vector>
#include <queue>
#include <iostream>
using namespace std;

int pos[][8] = {
	//{ 0, -1, 0, 1 },
	//{-1, 0, 1, 0 }
	//{-1, -1, 0, 1, 1, 1, 0, -1},
	//{0, 1, 1, 1, 0, -1, -1, -1}

	{-1, 1, 0, 0, -1, -1, 1, 1},
	{0, 0, -1, 1, -1, 1, -1, 1}
};

void func(vector<string>& places, int (*check)[5], int& x, int& y, int& flag) {
	//int currentX, currentY;

	//check[x][y] = 1;

	for (int i = 0; i < 4; i++) {
		int currentX = x + pos[0][i];
		int currentY = y + pos[1][i];

		if (!(currentX < 0 || currentX > 4 || currentY < 0 || currentY > 4)) {
			if (places[currentX][currentY] == 'X') {
				flag = 1;
				return;
			}
			for (int j = 0; j < 8; j++) {
				int nextX = currentX  + pos[0][j];
				int nextY = currentY  + pos[1][j];
				if (!(nextX < 0 || nextX > 4 || nextY < 0 || nextY > 4)) {
					if (places[nextX][nextY] == 'P') {
						flag = 0;
					}
				}
			}
		}
	}
}

vector<int> solution(vector<vector<string>> places) {
	vector<int> answer;
	int flag;

	for (int i = 0; i < 5; i++) {
		vector<string> temp = places[i];
		int check[5][5] = { 0, };
		flag = 1;

		for (int j = 0; j < 5; j++) {
			for (int k = 0; k < 5; k++) {
				if (temp[j][k] == 'P' && check[j][k] != 1) {
					func(temp, check, j, k, flag);
					if (flag == 0) break;
				}
				if (flag == 0) break;
			}
		}

		answer.push_back(flag);

	}
	for (auto&e : answer)
		cout << e << "  ";
	return answer;
}
int main() {
	vector<vector<string>> v =
	{ {"POOOP", "OXXOX", "OPXPX", "OOXOX", "POXXP"},{"POOPX", "OXPXP", "PXXXO", "OXXXO", "OOOPP" },
	{"PXOPX", "OXOXP", "OXPOX", "OXXOP", "PXPOX" },{"OOOXX", "XOOOX", "OOOXX", "OXOOX", "OOOOO" },
	{ "PXPXP", "XPXPX", "PXPXP", "XPXPX", "PXPXP"} };
	solution(v);
}
*/
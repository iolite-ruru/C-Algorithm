#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int solution(int x1, int y1, int x2, int y2) {
	int answer = 0;

	//-1ÀÇ °æ¿ì
	if (abs(x1 - x2) < 5 && abs(y1 - y2)) return -1;

	x1--;
	y1--;
	x2--;
	y2--;

	vector<vector<int>> v1(15, vector<int>(15, 0));
	vector<vector<int>> v2(15, vector<int>(15, 0));

	v1[x1][y1] = 100;
	v2[x2][y2] = 100;

	for (int i = 0; i < 15; i++) {
		for (int j = 0; j < 15; j++) {
			if (abs(x1 - i) < 5 && abs(y1 - i) < 5) v1[i][j]++;
		}
	}

	//test
	for (int i = 0; i < 15; i++) {
		for (int j = 0; j < 15; j++) {
			cout << v1[i][j] << "\t";
		}
		cout << endl;
	}

	/*for (int i = 0; i < 15; i++) {
		for (int j = 0; j < 15; j++){
			if (v1[i][j] + v2[i][j] > 1)
				answer += v1[i][j] + v2[i][j];
		}
		return answer;
	}*/
	return answer;
}
int main() {
	//cout << solution(8, 4, 8, 10) << endl;
	cout << solution(2, 4, 8, 10) << endl;
	return 0;
}
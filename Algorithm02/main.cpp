#include<iostream>
#include<cmath>
#include<vector>

void Func(std::vector<std::vector<int>>& table, int i, int j, int& len) {
	if (table[i][j] == -1) return;
	if (table[i][j] == 0) {
		table[i][j] = -1; // 오류원인 ==> '='을 두개 사용했음
		return;
	}
	table[i][j] = -1;
	if (i > 0 && table[i - 1][j] != -1) Func(table, i - 1, j, len);
	if (i < len-1 && table[i + 1][j] != -1) Func(table, i + 1, j, len);
	if (j > 0 && table[i][j - 1] != -1) Func(table, i, j - 1, len);
	if (j < len-1 && table[i][j + 1] != -1) Func(table, i, j + 1, len);
}

int solution(std::vector<std::vector<int>> table) {
	int answer = 0;
	int len = table[0].size();
	for (int i = 0; i < len; i++) {
		for (int j = 0; j < len; j++) {
			if (table[i][j] == 1) {
				Func(table, i, j, len);
				answer++;
			}
		}
	}
	return answer;
}

int main() {
	std::vector<std::vector<int>> table = {
		{1,0,0,1},
		{1,1,0,1},
		{0,1,0,1},
		{1,0,0,1}
	};
	std::cout << solution(table) << std::endl;

	return 0;
}
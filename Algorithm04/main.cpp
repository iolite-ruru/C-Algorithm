#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> solution(vector<int> starts, vector<int> ends, vector<int> divides, int tolerance) {
	vector<int> answer;
	int len = starts.size();

	for (int i = 0; i < len; i++) {
		int unit;
		int start = starts[i];
		int end = ends[i];
		int front, back;

		if (start < end) {
			unit = end - start;
		}
		else {
			unit = 36000 - start + end;
		}
		front = start;
		back = end;
		unit /= divides[i];

		while (true) {
			if (front >= 36000) front -= 36000;
			answer.push_back(front);

			front += unit;
			if(front == back + unit) break;
		}
	}
	unique(answer.begin(), answer.end());
	sort(answer.begin(), answer.end());

	for (auto& e : answer) {
		std::cout << e << "  ";
	}
	std::cout << std::endl;

	for (int i = 1; i < answer.size(); i++){
		if (answer[i] - answer[i-1] <= tolerance) {
			answer.erase(answer.begin() + i);
			i--;
		}
	}
	if (answer[0] + 36000 - answer[answer.size() - 1] <= tolerance) {
		answer.erase(answer.begin());
	}
	return answer;
}

int main() {
	//[[35950],[50],[10],20]    [30,35950,35980]
	//vector<int> starts = { 35000, 2000, 1200 };
	//vector<int> ends = { 1000, 3000, 1700 };
	//vector<int> divides = { 4, 2, 5 };
	//int tolerance = 100;

	vector<int> starts = { 35950};
	vector<int> ends = { 50};
	vector<int> divides = {10};
	int tolerance = 20;

	for (auto& e : solution(starts, ends, divides, tolerance)) {
		std::cout << e << "  ";
	}

	return 0;
}
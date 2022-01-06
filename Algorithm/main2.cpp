#include<iostream>
#include<stack>
#include<string>
using namespace std;

void input(stack<int>& stack, string param, int idx, int& answer) {
	if (param[idx] == '(') {
		stack.push(0);
		input(stack, param, idx + 1, answer);
		return;
	}

	if (param[idx] == ')') {
		if (stack.empty()) {
			answer = 0;
			return;
		}
		if (stack.top() == 0) {
			stack.pop();
			answer++;
			input(stack, param, idx + 1, answer);
			return;
		}
	}

}

int solution(std::string param) {
	std::stack<int> stack;
	int answer = 0;
	int idx = 0;
	
	input(stack, param, idx, answer);

	return answer;
}

int main() {
	std::string str1 = "()()()";
	std::string str2 = "())(";
	std::string str3 = "((()())())";

	std::cout << solution(str1) << std::endl;
	std::cout << solution(str2) << std::endl;
	std::cout << solution(str3) << std::endl;

	return 0;
}
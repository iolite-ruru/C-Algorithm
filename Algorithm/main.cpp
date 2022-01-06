#include<iostream>
#include<stack>

void Solution(std::stack<int>& stack, char arr[], int idx, int& answer) {
	if (arr[idx] == '(') {
		stack.push(0);
		Solution(stack, arr, idx + 1, answer);
		return;
	}


	if (arr[idx] == ')') {
		if (stack.empty()) {
			answer = 0;
			return;
		}
		if (stack.top() == 0) {
			stack.pop();
			answer++;
			Solution(stack, arr, idx + 1, answer);
			return;
		}
	}
}
void func(int& answer, int& idx) {
	answer = 0;
	idx = 0;
}
int main() {
	int answer; // = 0;
	int idx; // = 0;
	std::stack<int> stack;

	char array1[] = { '(', ')','(', ')', '(', ')' };
	char array2[] = { '(', ')', ')', '(' };
	char array3[] = { '(', '(', '(', ')', '(', ')', ')',  '(', ')', ')' };

	func(answer, idx);
	Solution(stack, array1, idx, answer);
	std::cout << answer << std::endl;

	func(answer, idx);
	Solution(stack, array2, idx, answer);
	std::cout << answer << std::endl;
	func(answer, idx);

	Solution(stack, array3, idx, answer);
	std::cout << answer << std::endl;


	return 0;
}
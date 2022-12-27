#include<iostream>
#include<stack>
#include<string>

using namespace std;

int main() {
	string str;
	cin >> str;
	stack<pair<char,int>> st;
	for (int i = 0; i < str.length(); i++) {
		if (str[i] == '{' || str[i] == '(' || str[i] == '[') {
			st.push(pair<char,int>(str[i],i));
		}
		else if (str[i] == '}' || str[i] == ')' || str[i] == ']') {
			if (st.empty()) {
				cout << i+1;
				return 0;
			}
			if ((st.top().first != '{' && str[i] == '}') || (st.top().first != '(' && str[i] == ')') ||
				(st.top().first != '[' && str[i] == ']')) {
				cout << i + 1;
				return 0;
			}
			st.pop();
		}
	}
	if (!st.empty())
		cout << st.top().second + 1;
	else
		cout << "Success";
	return 0;
}
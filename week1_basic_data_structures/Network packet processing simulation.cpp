#include<iostream>
#include<queue>
#include<vector>
using namespace std;

typedef pair<int, int> pii;
typedef queue<pii> qupii;
typedef vector<int> vi;
typedef vector<pii> vpii;
typedef	queue<int>	qi;

#define lp(i,n) for(int i=0;i<n;i++)

int main() {
	int s, n;
	cin >> s >> n;


	vpii packets(n, pii(0, 0));
	lp(i, n)
		cin >> packets[i].first >> packets[i].second;

	qi finish_time;
	qi buffer;
	lp(i, n) {
		while (!buffer.empty() && buffer.front() <= packets[i].first) {
			buffer.pop();
		}
		if (buffer.empty() && s != 0) {
			finish_time.push(packets[i].first + packets[i].second);
			buffer.push(packets[i].first + packets[i].second);
		} 
		else if (buffer.size() < s) {
			int lastTime = buffer.back();
			finish_time.push(lastTime + packets[i].second);
			buffer.push(lastTime + packets[i].second);
		}
		else {
			finish_time.push(-1);
		}
	}
	lp(i, n) {
		if (finish_time.front() != -1)
			cout << finish_time.front() - packets[i].second;
		else
			cout << -1;
		cout << endl;
		finish_time.pop();
	}
	return 0;
}

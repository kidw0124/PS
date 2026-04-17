#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

string deohagi(string a, string b) {
	int sum = 0;
	string res;
	while (!a.empty() || !b.empty() || sum) {
		if (!a.empty()) sum += a.back() - '0', a.pop_back();
		if (!b.empty()) sum += b.back() - '0', b.pop_back();
		res.push_back((sum % 10) + '0');
		sum /= 10;
	}
	reverse(res.begin(), res.end());
	return res;
}

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    string a, b;
    cin >> a >> b;
    cout << deohagi(a, b);
	return 0;
}
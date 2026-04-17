#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <functional>         // greater 사용 위해 필요  
#include <string>
#include <map>
#include <math.h>
using namespace std;

int main() {
	std::ios::sync_with_stdio(false); cin.tie(0);

	int n; cin >> n;
	vector<int> arr(n);

	for(int i=0; i<n; i++) {
		cin >> arr[i];
	}

	vector<int> brr(n);
	brr[0] = arr[0];

	for(int i=1; i<n; i++) {
		int cand = arr[i];

		int data = 0;
		for(int j=0; j<i; j++) {
			data += brr[j];
		}

		int sol = cand *(i+1) - data;
		brr[i] = sol;
	}

	for(int i =0; i<n; i++) {
		cout << brr[i] << " ";
	}
	return 0;
}
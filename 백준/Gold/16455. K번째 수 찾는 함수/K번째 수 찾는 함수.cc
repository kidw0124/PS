#include <bits/stdc++.h>
using namespace std;
int kth(std::vector<int> &a, int k) {
	int ans = 0;
    mt19937 rnd(0x814124);
    shuffle(a.begin(),a.end(),rnd);
    nth_element(a.begin(),a.begin()+k-1,a.end());
    ans=a[k-1];
	return ans;
}

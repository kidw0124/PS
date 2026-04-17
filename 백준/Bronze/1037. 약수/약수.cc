#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
	long long a,arr[1000000];
	cin>>a;
	for(int i=0;i<a;i++)cin>>arr[i];
	sort(arr,arr+a);
	cout<<arr[0]*arr[a-1];
	return 0;
}
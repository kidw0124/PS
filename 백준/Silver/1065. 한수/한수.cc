#include <iostream>
using namespace std;
bool is_straight(int num) {
    if( num<100 ) return true;
    int right = num%10;
    num /= 10;
    int middle = num%10;
    int diff = middle - right;
    while( num >= 10 ) {
        right = num%10;
        num /= 10;
        middle = num%10;
        if( diff != middle - right ) return false;
    }
    return true;
}
int main() {
    int N;
	scanf("%d", &N);
	int count = 0;
	for(int i=1; i<=N; i++) {
	    if( is_straight(i) ) count++;
	}
	cout << count;
}
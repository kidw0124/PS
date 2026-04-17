#include<iostream>
using namespace std;
 
int cnt = 0, day, num[5];
 
int main() {
    cin >> day;//날짜의 1의 자리 입력
    for (int i = 0; i < 5; ++i) {
        cin >> num[i];//자동차 번호 1의 자리 입력
    }
    
    for (int i = 0; i < 5; ++i) {
        if (day == num[i])
            ++cnt;//위반한 차량 수 카운트
    }
 
    cout << cnt << endl;//출력
 
    return 0;
}

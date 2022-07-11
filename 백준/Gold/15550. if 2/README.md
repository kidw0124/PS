# [Gold IV] if 2 - 15550 

[문제 링크](https://www.acmicpc.net/problem/15550) 

### 성능 요약

메모리: 4528 KB, 시간: 0 ms

### 분류

애드 혹(ad_hoc)

### 문제 설명

<p>다음 프로그램을 실행시켰을 때, "<code>true</code>"를 출력하는 변수 <code>a, b, c</code>의 자료형과 값을 찾는 프로그램을 작성하시오.</p>

<pre class="brush:c++; toolbar:false;">#include <iostream>
using namespace std;
int main() {
    ??? a = ???;
    ??? b = ???;
    ??? c = ???;
    if (a == b && b == c && c != a) {
        cout << "true" << '\n';
    } else {
        cout << "false" << '\n';
    }
    return 0;
}</pre>

<p>실행 환경은 BOJ 채점 서버의 C++17 실행 환경과 같다.</p>

### 입력 

 <p>입력은 없다.</p>

### 출력 

 <p>첫째 줄에 변수 <code>a</code>의 자료형과 값, 둘째 줄에 변수 <code>b</code>의 자료형과 값, 셋째 줄에 변수 <code>c</code>의 자료형과 값을 공백으로 구분해 출력한다. 자료형은 <code>int</code>, <code>long long</code>, <code>float</code>, <code>double</code>만 가능하다. 출력한 값이 자료형에 알맞지 않은 경우에는 틀리게 된다.</p>

<p>값은 아래 소스가 런타임 에러 없이 읽을 수 있는 값을 의미한다.</p>

<pre class="brush:c++; toolbar:false;">istringstream sin(line);
자료형 temp;
assert(sin >> temp);</pre>


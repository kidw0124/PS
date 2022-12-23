# [Silver I] 그램팬 - 26650 

[문제 링크](https://www.acmicpc.net/problem/26650) 

### 성능 요약

메모리: 2300 KB, 시간: 0 ms

### 분류

구현(implementation), 문자열(string)

### 문제 설명

<p>팬그램(pangram)이란 알파벳의 모든 문자가 최소 한 번씩 등장하는 문자열을 말한다. 팬그램의 예시로는 "The quick brown fox jumps over the lazy dog", "The five boxing wizards jump quickly"등이 있다. 팬그램은 그 자체로 충분히 아름다운 문자열이지만, 래오는 팬그램 중에서도 모든 알파벳이 순서대로 나열된 팬그램만이 아름답다고 생각해 이를 <strong>그램팬</strong>이라 부르기로 했다.</p>

<p>예를 들어 "ABBCDEFGGHIJKLMNOPQRSSTUVWXYZ"는 그램팬이며,  "BABCDEFGHIJKLMNOPQRSTUVWXYZ", "ABCADEFGHIJKLMNOPQRSTUVWXYZ"은 팬그램이지만 그램팬은 아니다.</p>

<p>어느 날 북과고 컴퓨터실 구석에서 문자열 $S$를 발견한 래오는 $S$의 부분 문자열 중 그램팬인 것의 개수가 궁금해졌다. 래오를 위해 이를 계산하는 프로그램을 작성해보자.</p>

<p>문자열 $S$의 부분 문자열이란, 문자열의 연속된 일부를 의미한다. 부분 문자열 중 같은 것이 있더라도 기존 문자열에서의 위치가 다르다면 다른 것으로 센다.</p>

### 입력 

 <p>첫째 줄에 문자열 $S$가 주어진다. $S$는 길이 $1$ 이상 $100\,000$ 이하의 알파벳 대문자로 이루어진 문자열이다.</p>

### 출력 

 <p>$S$의 부분 문자열 중 <strong>그램팬</strong>인 것의 개수를 출력한다.</p>


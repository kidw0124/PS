# [Gold II] unique(str)=KCPC - 35159 

[문제 링크](https://www.acmicpc.net/problem/35159) 

### 성능 요약

메모리: 27576 KB, 시간: 32 ms

### 분류

그리디 알고리즘, 누적 합, 스위핑

### 제출 일자

2026년 04월 15일 19:19:24

### 문제 설명

<p>빈 문자열이 아닌 문자열 $T$에 대해, unique($T$)는 $T$의 연속된 동일한 문자들을 하나만 남기고 제거한 문자열이다. 예를 들어, unique(<span style="color:#e74c3c;"><code>ABBCCCBBA</code></span>)는 <span style="color:#e74c3c;"><code>ABCBA</code></span>이다.</p>

<p>지훈이는 주어진 문자열 $S$에 최소 횟수의 <strong>인접 교환 연산</strong>을 통해 unique($S^\prime$)이 <span style="color:#e74c3c;"><code>KCPC</code></span>가 되는 문자열 $S^\prime$을 만들고 싶다. 여기서 <strong>인접 교환 연산</strong>이란 문자열에서 서로 인접해 있는 두 문자 한 쌍의 위치를 서로 바꾸는 연산을 의미한다.</p>

<p>문자열 $S$가 주어졌을 때, unique($S^\prime$)이 <code>KCPC</code>가 되는 데 필요한 <strong>인접 교환 연산</strong>의 최소 횟수를 구해보자.</p>

### 입력 

 <p>첫 번째 줄에 <span style="color:#e74c3c;"><code>K</code></span>, <span style="color:#e74c3c;"><code>C</code></span>, <span style="color:#e74c3c;"><code>P</code></span>로만 이루어진 문자열 $S(4\le\lvert S\rvert\le 10^6)$가 주어진다.</p>

<p>유한한 <strong>인접 교환 연산</strong>을 통해 unique($S^\prime$)이 <span style="color:#e74c3c;"><code>KCPC</code></span>가 될 수 있는 경우만 주어진다.</p>

### 출력 

 <p>첫 번째 줄에 unique($S^\prime$)이 <span style="color:#e74c3c;"><code>KCPC</code></span>가 되는 데 필요한 <strong>인접 교환 연산</strong>의 최소 횟수를 출력한다.</p>


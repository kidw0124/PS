# [Gold I] 조합 (Combination) - 16134 

[문제 링크](https://www.acmicpc.net/problem/16134) 

### 성능 요약

메모리: 9832 KB, 시간: 8 ms

### 분류

조합론(combinatorics), 분할 정복을 이용한 거듭제곱(exponentiation_by_squaring), 페르마의 소정리(flt), 수학(math), 모듈로 곱셈 역원(modular_multiplicative_inverse), 정수론(number_theory)

### 문제 설명

<p>준하는 기초통계학 수업에서 너비가 a, 높이가 ​​​​​b인 격자판의 좌하단 점으로부터 우상단 점까지 최단경로로 가는 방법의 수를 구하라는 과제를 받았어. </p>

<p>알고 있겠지만 정답은  \(\begin{pmatrix}a+b\\b\end{pmatrix}\)이야. 보기만 해도 벌써 조합을 계산할 생각에 신이 나지? 사실 조합을 구하는 문제도 코딩으로 해결할 수 있대. 코딩으로 과제를 해결해주자!</p>

### 입력 

 <p class="0" style="text-align:left">첫 줄에 <em>N</em>과 <em>R</em>이 주어진다. (0 ≤ <em>R</em> ≤ <i>N</i> ≤ 1,000,000)</p>

### 출력 

 <p class="0" style="text-align:left">\(\begin{pmatrix}N\\R\end{pmatrix}\)의 값을 1,000,000,007로 나눈 나머지를 출력하자! (단, 1,000,000,007은 소수이다)</p>


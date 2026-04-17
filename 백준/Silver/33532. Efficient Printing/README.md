# [Silver II] Efficient Printing - 33532 

[문제 링크](https://www.acmicpc.net/problem/33532) 

### 성능 요약

메모리: 2096 KB, 시간: 0 ms

### 분류

수학, 정수론

### 제출 일자

2026년 04월 18일 01:08:28

### 문제 설명

<p>The Factorial Poster Company (FPC) prints posters that display the result of any factorial that their customers wish for. Recently, they got an order from Professor D.R. Ingenious, who wants to do an experiment with very large factorial numbers. The FPC want to be as efficient with printing as possible, and therefore they decided on a way to save paper. Since the larger factorial numbers end in a lot of zeroes, they decide to cut off this number of zeroes $z$ and replace it with "$\cdot 10^z$".</p>

<p>You are given the task to calculate, for every order of Prof. Ingenious, how many zeroes $z$ can be cut off from the poster, so that the FPC know how much poster paper they will save.</p>

### 입력 

 <p>One line containing one integer $n$, with $0 \leq n \leq 10^{18}$.</p>

### 출력 

 <p>One line containing one integer $z$, the amount of trailing zeroes of $n!$. Note that any other zeroes in the result of $n!$ do not count, see the second example.</p>


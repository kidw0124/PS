# [Gold V] Dividing Candy - 22267 

[문제 링크](https://www.acmicpc.net/problem/22267) 

### 성능 요약

메모리: 2928 KB, 시간: 12 ms

### 분류

자료 구조, 그리디 알고리즘, 수학, 우선순위 큐

### 제출 일자

2024년 7월 8일 02:11:06

### 문제 설명

<p>Bob and Charlie are two brothers that like powers of 2 a lot. Their mum decided to give them N boxes of candy, each of them containing a number of candy bars that is a power of 2.</p>

<p>They want to split the boxes between them, that is, for each box, they will decide who gets it. Each box must be given to exactly one brother.</p>

<p>Now they wonder: is it possible that, for each of the two brothers, the total amount of candy bars he receives is also a power of 2?</p>

<p>For example, if N = 4 and the boxes contain 4, 4, 32, and 8 candy bars, the answer would be yes, as one possible solution is giving the third box to Bob (32 candy bars), and the remaining boxes to Charlie (4 + 4 + 8 = 16 candy bars in total).</p>

### 입력 

 <p>The first line contains an integer N (1 ≤ N ≤ 10<sup>5</sup>), the number of boxes the brothers want to split. The second line contains N integers A<sub>1</sub>, A<sub>2</sub>, . . . , A<sub>N</sub> (0 ≤ A<sub>i</sub> ≤ 10<sup>5</sup> for i = 1, 2, . . . , N), indicating that the i-th box has 2<sup>A<sub>i</sub></sup> candy bars.</p>

### 출력 

 <p>Output a single line with the uppercase letter “<code>Y</code>” if it is possible to split the boxes so that the total amount of candy received by each brother is a power of 2, and the uppercase letter “<code>N</code>” otherwise.</p>


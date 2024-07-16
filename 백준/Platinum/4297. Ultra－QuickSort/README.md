# [Platinum V] Ultra-QuickSort - 4297 

[문제 링크](https://www.acmicpc.net/problem/4297) 

### 성능 요약

메모리: 18244 KB, 시간: 212 ms

### 분류

값 / 좌표 압축, 자료 구조, 분할 정복, 세그먼트 트리, 정렬

### 제출 일자

2024년 7월 17일 01:41:20

### 문제 설명

<p>In this problem, you have to analyze a particular sorting algorithm. The algorithm processes a sequence of n distinct integers by swapping two adjacent sequence elements until the sequence is sorted in ascending order. For the input sequence</p>

<pre>9 1 0 5 4 ,</pre>

<p>Ultra-QuickSort produces the output</p>

<pre>0 1 4 5 9 .</pre>

<p>Your task is to determine how many swap operations Ultra-QuickSort needs to perform in order to sort a given input sequence.</p>

### 입력 

 <p>The input contains several test cases. Every test case begins with a line that contains a single integer n < 500,000 -- the length of the input sequence. Each of the the following n lines contains a single integer 0 ≤ a[i] ≤ 999,999,999, the i-th input sequence element. Input is terminated by a sequence of length n = 0. This sequence must not be processed.</p>

### 출력 

 <p>For every input sequence, your program prints a single line containing an integer number op, the minimum number of swap operations necessary to sort the given input sequence.</p>


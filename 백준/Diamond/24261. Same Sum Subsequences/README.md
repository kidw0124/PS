# [Diamond IV] Same Sum Subsequences - 24261 

[문제 링크](https://www.acmicpc.net/problem/24261) 

### 성능 요약

메모리: 48388 KB, 시간: 256 ms

### 분류

수학, 두 포인터, 비둘기집 원리

### 제출 일자

2026년 04월 18일 01:08:28

### 문제 설명

<p>You are given two positive integers n, m and two sequences of positive integers A and B. The sequence A consists of n elements, each one in the interval [1, m], while the sequence B consists of m elements, each one in the interval [1, n].</p>

<p>Write a program, which finds a nonempty subsequence of A and a nonempty subsequence of B, which have equal sums of elements.</p>

<p>Definition: For a sequence C = C<sub>0</sub>, C<sub>1</sub>, …, C<sub>p</sub>, a subsequence of C is a sequence of elements C<sub>i<sub>1</sub></sub>, C<sub>i<sub>2</sub></sub>, …, C<sub>i<sub>k</sub></sub> of C for which 0 ≤ i<sub>1</sub> < i<sub>2</sub> < ...< i<sub>k</sub> ≤ p.</p>

### 입력 

 <p>From the first line of the standard input, your program reads a positive integer n – the size of sequence A. From the second line, your program reads n positive integers – the elements of A. From the third line of the standard input, your program reads a positive integer m – the size of sequence B. From the fourth line, your program reads m positive integers – the elements of B.</p>

### 출력 

 <p>On the first line of the standard output, your program should print a positive integer p – the size of the chosen subsequence of A. On the second line, your program should print p integers – the indices of the chosen elements from A. On the third line of the standard output, your program should print a positive integer q – the size of the chosen subsequence of B. On the fourth line, your program should print q integers – the indices of the chosen elements from B.</p>

<p>Attention: Indices start from 0. The order in which your program prints the chosen indices doesn’t matter. It is guaranteed that at least one solution exists. If more than one solution exists, print any one of them.</p>


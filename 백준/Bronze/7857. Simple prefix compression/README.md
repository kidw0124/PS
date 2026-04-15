# [Bronze I] Simple prefix compression - 7857 

[문제 링크](https://www.acmicpc.net/problem/7857) 

### 성능 요약

메모리: 2088 KB, 시간: 8 ms

### 분류

구현, 문자열, 브루트포스 알고리즘

### 제출 일자

2026년 04월 15일 19:19:24

### 문제 설명

<p>Many databases store the data in the character fields (and especially indices) using prefix compression. This technique compresses a sequence of strings A<sub>1</sub>, ..., A<sub>N</sub> by the following method: if there are strings A<sub>i</sub> = a<sub>i,1</sub>a<sub>i,2</sub>...a<sub>i,p</sub> and A<sub>i + 1</sub> = a<sub>i+1,1</sub>a<sub>i+1,2</sub>...a<sub>i+1,q</sub> such that for some j ≤ min(p, q) a<sub>i,1</sub> = a<sub>i+1,1</sub>, a<sub>i,2</sub> = a<sub>i+1,2</sub>, ... a<sub>i,j</sub> = a<sub>i+1,j</sub>, then the second string is stored as [j]a<sub>i+1,j+1</sub>a<sub>i+1,j+2</sub>... a<sub>i+1,q</sub>, where [j] is a single character with code j.</p>

<p>If j = 0, that is, strings do not have any common prefix, then the second string is prefixed with zero byte, and so the total length actually increases. </p>

### 입력 

 <p>First line of input file contains integer number N, with following N lines containing strings A<sub>1</sub> ... A<sub>N</sub></p>

### 출력 

 <p>Output file must contain a single integer — minimal total length of compressed strings. </p>


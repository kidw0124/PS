# [Diamond IV] Spiral - 12751 

[문제 링크](https://www.acmicpc.net/problem/12751) 

### 성능 요약

메모리: 2096 KB, 시간: 0 ms

### 분류

분류 없음

### 제출 일자

2025년 7월 9일 05:09:32

### 문제 설명

<p>A grid of size (2n + 1) × (2n + 1) has been constructed as follows. Number 1 has been placed in the center square, number 2 has been placed to the right of it, and the following numbers have been placed along the spiral counterclockwise.</p>

<p>Your task is to calculate answers for q queries where the sum of numbers in an rectangular region in the grid is requested (modulo 10<sup>9</sup> + 7). For example, in the following grid n = 2 and the sum of numbers in the gray region is 74:</p>

<p style="text-align: center;"><img alt="" src="https://onlinejudgeimages.s3-ap-northeast-1.amazonaws.com/problem/12751/1.png" style="height:209px; width:212px"></p>

### 입력 

 <p>The first input line contains two integers n and q: the size of the grid and the number of queries.</p>

<p>After this, there are q lines, each containing four integers x<sub>1</sub>, y<sub>1</sub>, x<sub>2</sub> and y<sub>2</sub> (-n ≤ x<sub>1</sub> ≤ x<sub>2</sub> ≤ n, -n ≤ y<sub>1</sub> ≤ y<sub>2</sub> ≤ n). This means that you should calculate the sum of numbers in a rectangular region with corners (x<sub>1</sub>, y<sub>1</sub>) and (x<sub>2</sub>, y<sub>2</sub>).</p>

### 출력 

 <p>You should output the answer for each query (modulo 10<sup>9</sup> + 7).</p>


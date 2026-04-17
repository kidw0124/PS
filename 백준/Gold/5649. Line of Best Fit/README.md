# [Gold III] Line of Best Fit - 5649 

[문제 링크](https://www.acmicpc.net/problem/5649) 

### 성능 요약

메모리: 2020 KB, 시간: 0 ms

### 분류

가우스 소거법, 선형대수학, 수학

### 제출 일자

2026년 04월 18일 01:08:28

### 문제 설명

<p>Finding a line of best fit for a set of data is one of fundamental problems in statistics and numerical analysis. The problem can be formulated as follows. Suppose our data consists of a set P of n points in a plane, denoted (x<sub>1</sub>, y<sub>1</sub>), (x<sub>2</sub>, y<sub>2</sub>), (x<sub>3</sub>, y<sub>3</sub>), ..., (x<sub>n</sub>, y<sub>n</sub>). Given a line L defined by the linear equation y = ax + b, we say that the error of L with respect to P is the sum of its squared “distance” to the points in P :</p>

<p>\[Error(L,P) = \sum_{i=1}^{n}{(y_i - ax_i - b)^2}\]</p>

<p>The least square approach is to find the line L which minimizes such error. Your task is to write a program to find the values a and b of the line L for a given set of points P.</p>

<p style="text-align: center;"><img alt="" src="" style="height:237px; width:249px"></p>

<p style="text-align: center;">Figure 1. Example of points and a line of best fit</p>

### 입력 

 <p>the first line contains a positive integer n (1 ≤ n ≤ 1,000). The next n lines contain 2 integers: x<sub>i</sub> and y<sub>i</sub> in each line. |x<sub>i</sub>| ≤ 10<sup>6</sup> and |y<sub>i</sub>| ≤ 10<sup>6</sup></p>

### 출력 

 <p>The output contains the values a and b in two lines respectively. The numbers must be rounded to 3 decimal places.</p>


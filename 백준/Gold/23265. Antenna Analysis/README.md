# [Gold III] Antenna Analysis - 23265 

[문제 링크](https://www.acmicpc.net/problem/23265) 

### 성능 요약

메모리: 38964 KB, 시간: 92 ms

### 분류

수학

### 제출 일자

2026년 04월 18일 01:08:28

### 문제 설명

<p>Åke has heard that there may be some suspicious 5G radiation in his city. To test this, he uses the antenna on his roof to measure the 5G level each day. However, he does not know how he should analyze the data. </p>

<p>We are given the measurements for $n$ consecutive days as a list of numbers $x_1, \ldots, x_n$ (where $x_i$ denotes the measurement for day $i$) and a constant $c$ that measures how much Åke expects the radiation to vary from day to day. We want to find, for each day $i$, the most significant difference between the measurement on day $i$ and any earlier day, after the expected variations are taken into account. More precisely, the goal is to find the maximum value of \[|x_i-x_j| - c \cdot |i-j|\] where $j \le i$.  I.e., we want to find a large difference in 5G level that has happened recently.</p>

### 입력 

 <p>The first line of input contains the two integers $n$ and $c$ ($1 \le n \le 4 \cdot 10^5$, $1 \le c \le 10^6$), the number of measurements and expected day-to-day variation. The second input line contains the $n$ integers $x_1,x_2,\dots,x_n$ ($1 \le x_i \le 10^6$ for $i=1,2,\dots,n$), giving the measurements of the $n$ days.</p>

### 출력 

 <p>Output $n$ integers $y_1, \ldots, y_n$, where $y_i$ is the most significant difference on day $i$.</p>


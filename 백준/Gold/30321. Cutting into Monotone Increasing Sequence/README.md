# [Gold I] Cutting into Monotone Increasing Sequence - 30321 

[문제 링크](https://www.acmicpc.net/problem/30321) 

### 성능 요약

메모리: 124052 KB, 시간: 344 ms

### 분류

다이나믹 프로그래밍, 문자열, 임의 정밀도 / 큰 수 연산

### 제출 일자

2026년 04월 18일 01:08:28

### 문제 설명

<p>A monotone sequence is a sequence of numbers that either consistently increases or consistently decreases as you move along the sequence. In other words, it exhibits a consistent trend in either an upward or downward direction.</p>

<p>In a monotone increasing sequence, each term in the sequence is greater than or equal to the preceding term. Mathematically, for a sequence $a_1, \dots , a_n$, it is monotone increasing if and only if for every $1≤ i < n$, $a_i ≤ a_{i+1}$. For example, the sequence $1,2,2,4,5$ is a monotone increasing sequence because each term is greater than or equal to the previous term.</p>

<p>Monotone sequences are important in various areas of mathematics, including calculus and analysis, as they often simplify the analysis of functions and their behavior. They provide a clear and consistent trend that makes it easier to understand the behavior of a sequence or a function over a range of values.</p>

<p>One of our problem setters is fond of big integers. Over the past few years, the Taiwan Online Programming Contest has frequently featured problems involving big integers. This time, we have a problem that combines big integers with monotone increasing sequences. Your task is to transform a big integer, denoted as $x$, into a monotone increasing sequence by inserting commas '<code>,</code>' into the gaps between its digits, while adhering to following constraints.</p>

<ul>
<li>The last term of the monotone increasing sequence is no more than $b$.</li>
<li>Commas cannot be inserted before a zero.</li>
<li>The number of commas is minimized.</li>
</ul>

<p>Let's assume that $x$ is an integer with $k$ digits and is represented as $d_1d_2\cdots d_k$. For instance, if we have $x=654321=d_1d_2 \cdots d_6$ and $b=1000$, we can insert commas into gaps after $d_3$ and $d_5$ to convert $x$ into the following monotone increasing sequence: $6,54,321$.</p>

<p>Please write a program to compute the minimum number of commas required to transform a given big integer $x$ into a monotone increasing sequence consisting of numbers no more than a given integer $b$. If there is no way to transform, please print '<code>NO WAY</code>'.</p>

### 입력 

 <p>The input contains two non-negative integers $x$ and $b$.</p>

### 출력 

 <p>Print the minimum number of commas required to transform $x$ into a monotone increasing sequence consisting of numbers no more than $b$. If there is no way to transform, please print '<code>NO WAY</code>' without quotes.</p>


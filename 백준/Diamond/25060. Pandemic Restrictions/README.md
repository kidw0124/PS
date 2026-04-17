# [Diamond III] Pandemic Restrictions - 25060 

[문제 링크](https://www.acmicpc.net/problem/25060) 

### 성능 요약

메모리: 2040 KB, 시간: 4 ms

### 분류

기하학, 삼분 탐색

### 제출 일자

2026년 04월 18일 01:08:28

### 문제 설명

<p>After a long time living abroad, you have decided to move back to Italy and have to find a place to live, but things are not so easy due to the ongoing global pandemic.</p>

<p>Your three friends Fabio, Flavio and Francesco live at the points with coordinates $(x_1, y_1)$, $(x_2, y_2)$ and $(x_3, y_3)$, respectively. Due to the mobility restrictions in response to the pandemic, meetings are limited to $3$ persons, so you will only be able to meet $2$ of your friends at a time. Moreover, in order to contain the spread of the infection, the authorities have imposed the following additional measure: for each meeting, the sum of the lengths travelled by each of the attendees from their residence place to the place of the meeting must not exceed $r$.</p>

<p>What is the minimum value of $r$ (which can be any nonnegative real number) for which there exists a place of residence that allows you to hold the three possible meetings involving you and two of your friends? Note that the chosen place of residence need not have integer coordinates.</p>

### 입력 

 <p>The first line contains the two integers $x_1$, $y_1$ ($-10^4 ≤ x_1, y_1 ≤ 10^4$) — the coordinates of the house of your friend Fabio.</p>

<p>The second line contains the two integers $x_2$, $y_2$ ($-10^4 ≤ x_2, y_2 ≤ 10^4$) — the coordinates of the house of your friend Flavio.</p>

<p>The third line contains the two integers $x_3$, $y_3$ ($-10^4 ≤ x_3, y_3 ≤ 10^4$) — the coordinates of the house of your friend Francesco.</p>

<p>It is guaranteed that your three friends live in different places (i.e., the three points $(x_1, y_1)$, $(x_2, y_2)$, $(x_3, y_3)$ are guaranteed to be distinct).</p>

### 출력 

 <p>Print the minimum value of $r$ which allows you to find a residence place satisfying the above conditions. Your answer is considered correct if its absolute or relative error does not exceed $10^{-4}$. Formally, let your answer be $a$, and the jury’s answer be $b$. Your answer is accepted if and only if $\frac{|a-b|}{\max{(1,|b|)}} ≤ 10^{-4}$.</p>


# [Gold III] Imperfect Imperial Units - 26000 

[문제 링크](https://www.acmicpc.net/problem/26000) 

### 성능 요약

메모리: 2304 KB, 시간: 32 ms

### 분류

그래프 이론, 자료 구조, 문자열, 그래프 탐색, 집합과 맵, 깊이 우선 탐색, 해시를 사용한 집합과 맵, 트리를 사용한 집합과 맵

### 제출 일자

2026년 04월 18일 01:08:28

### 문제 설명

<p>You are writing a paper for the Beta Astronomy Physics Conference about your recent discovery on grey holes. One of your collaborators has performed a huge number of measurements, which you would like to analyse in order to draw some conclusions. The only problem is: the data is measured in a wide variety of units, and to your disgust, they appear to use a mix of the imperial and metric systems. To simplify your analysis, you need to convert all these measurements into a different unit.</p>

### 입력 

 <p>The input consists of:</p>

<ul>
	<li>One line with two integers $n$ and $q$ ($1\leq n\leq 100$, $1\leq q\leq 10\,000$), the number of unit conversion equations and the number of queries to answer.</li>
	<li>$n$ lines, each defining a unit conversion in the format "<code>1 <unit> = <value> <unit></code>".</li>
	<li>$q$ lines, each with a query in the format "<code><value> <unit> to <unit></code>".</li>
</ul>

<p>In these formats, "<code><value></code>" is a floating-point number $v$ ($0.001 \leq v \leq 1000$, with at most $9$ digits after the decimal point) and "<code><unit></code>" is a string of at most $20$ English lowercase letters (<code>a-z</code>). A unit in a query is guaranteed to be defined in at least one unit conversion equation. Every unit can be converted into every other unit in <em>at most</em> one way.</p>

### 출력 

 <p>For every query, output the value of the requested unit, or "<code>impossible</code>" if the query cannot be answered.</p>

<p>Your answers should have a <em>relative</em> error of at most $10^{-6}$.</p>


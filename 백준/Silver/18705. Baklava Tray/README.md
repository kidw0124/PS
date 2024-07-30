# [Silver II] Baklava Tray - 18705 

[문제 링크](https://www.acmicpc.net/problem/18705) 

### 성능 요약

메모리: 2036 KB, 시간: 0 ms

### 분류

기하학, 수학

### 제출 일자

2024년 7월 30일 20:50:19

### 문제 설명

<p>In the ACPC closing, the contestants decided to celebrate their hard work during the whole season by getting a very large tray of Baklava (Baklawa).</p>

<p>During the order process, they started to watch the baker making trays for other customers. They noticed that he first draws an N-sided regular polygon with area 1 and put crushed hazelnut on the whole polygon, then he proceeds to draw the second polygon inside it by joining the midpoints of the sides of the first one and then put cashews on this polygon. Then, he proceeds with different types of nuts to draw an infinite sequence of N-sided polygons inside each other and each of them is formed by joining the midpoints of the sides of the latest drawn polygon. Consequently, the outer most polygon contains one type of nuts (hazelnuts), the second polygon contains two types (hazelnuts and cashews) and so on; this way, each polygon contains all the nuts of the polygons preceding it as well.</p>

<p>After the baker is done with the contestants’ order, 10<sup>4</sup> persons with their forks will hit the tray at random places only once (yes people from other hotels all over Sharm were excited about this tray). The deliciousness factor is then computed by summing the number of nut types hit by the fork of each person and this is computed independently for each person. Please note that, if a person hits the i<sup>th</sup> inner-most polygon, then he will hit exactly i nut types.</p>

<p>Help the Regional Contest Director determine the expected deliciousness factor for a tray with N sides.</p>

<p style="text-align: center;"><img alt="" src="" style="width: 207px; height: 189px;"></p>

<p style="text-align: center;">The first three polygons for N = 5.</p>

### 입력 

 <p>The first line of the input contains a single integer T specifying the number of test cases.</p>

<p>Each test case consists of a single line containing a single integer N (3 ≤ N ≤ 800) representing the number of sides of the tray.</p>

### 출력 

 <p>For each test case, print a single line containing a single decimal number (rounded to exactly 5 decimal places) representing the expected deliciousness factor for the corresponding test case.</p>

<p>Your answer will be considered as correct if it has an absolute or relative error less than 10<sup>−5</sup>.</p>


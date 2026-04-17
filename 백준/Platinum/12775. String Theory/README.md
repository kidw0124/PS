# [Platinum II] String Theory - 12775 

[문제 링크](https://www.acmicpc.net/problem/12775) 

### 성능 요약

메모리: 2020 KB, 시간: 0 ms

### 분류

다이나믹 프로그래밍, 그리디 알고리즘, 애드 혹

### 제출 일자

2026년 04월 18일 01:08:28

### 문제 설명

<p>Nested quotations are great not only for writing literature with a complex narrative structure, but also in programming languages. While it may seem necessary to use different quotation marks at different nesting levels for clarity, there is an alternative. We can display various nesting levels using k-quotations, which are defined as follows.</p>

<p>A 1-quotation is a string that begins with a quote character, ends with another quote character and contains no quote characters in-between. These are just the usual (unnested) quotations. For example, <code>'this is a string'</code> is a 1-quotation.</p>

<p>For k > 1, a k-quotation is a string that begins with k quote characters, ends with another k quote characters and contains a nested string in-between. The nested string is a non-empty sequence of (k − 1)-quotations, which may be preceded, separated, and/or succeeded by any number of non-quote characters. For example, <code>''All 'work' and no 'play'''</code> is a 2-quotation.</p>

<p>Given a description of a string, you must determine its maximum possible nesting level.</p>

### 입력 

 <p>The input consists of two lines. The first line contains an integer n (1 ≤ n ≤ 100). The second line contains n integers a<sub>1</sub>, a<sub>2</sub>, . . . , a<sub>n</sub> (1 ≤ a<sub>i</sub> ≤ 100), which describe a string as follows. The string starts with a<sub>1</sub> quote characters, which are followed by a positive number of non-quote characters, which are followed by a<sub>2</sub> quote characters, which are followed by a positive number of non-quote characters, and so on, until the string ends with an quote characters.</p>

### 출력 

 <p>Display the largest number k such that a string described by the input is a k-quotation. If there is no such k, display <code>no quotation</code> instead.</p>


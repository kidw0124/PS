# [Diamond II] Pyramid - 18660 

[문제 링크](https://www.acmicpc.net/problem/18660) 

### 성능 요약

메모리: 2020 KB, 시간: 136 ms

### 분류

조합론, 수학

### 제출 일자

2026년 04월 18일 01:08:28

### 문제 설명

<p>A side surface of a pyramid can be cut into many equilateral triangles, whose vertices can be grouped into different levels from top to bottom, such that the first level contains one vertex, the second level contains two, and so on.</p>

<p style="text-align: center;"><img alt="" src="" style="width: 277px; height: 200px;"></p>

<p>As the image shows, for example, two adjacent level-k vertices with a level-(k − 1) vertex can form an upright equilateral triangle, and two adjacent level-k vertices with a level-(k + 1) vertex can form an inverted equilateral triangle as well. Also, three vertices at three different levels can form an equilateral triangle, which may be oblique.</p>

<p>If we only consider vertices between level l and level r (inclusive), in how many ways can we choose three equidistant vertices so that they can form an equilateral triangle?</p>

### 입력 

 <p>The input contains several test cases. The first line contains an integer T indicating the number of test cases. The following describes all test cases. For each test case:</p>

<p>The only line contains two integers l and r.</p>

### 출력 

 <p>For each test case, output a line containing “Case #x: y” (without quotes), where x is the test case number starting from 1, and y is the answer to this test case.</p>


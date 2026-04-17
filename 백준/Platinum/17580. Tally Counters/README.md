# [Platinum I] Tally Counters - 17580 

[문제 링크](https://www.acmicpc.net/problem/17580) 

### 성능 요약

메모리: 5980 KB, 시간: 308 ms

### 분류

다이나믹 프로그래밍

### 제출 일자

2026년 04월 18일 01:08:28

### 문제 설명

<p>A number of tally counters are placed in a row. Pushing the button on a counter will increment the displayed value by one, or, when the value is already the maximum, it goes down to one. All the counters are of the same model with the same maximum value.</p>

<p style="text-align: center;"><img alt="" src="" style="width: 407px; height: 209px;"></p>

<p style="text-align: center;">Fig. D-1 Tally Counters</p>

<p>Starting from the values initially displayed on each of the counters, you want to change all the displayed values to target values specified for each. As you don't want the hassle, however, of pushing buttons of many counters one be one, you devised a special tool. Using the tool, you can push buttons of one or more adjacent counters, one push for each, in a single operation. You can choose an arbitrary number of counters at any position in each operation, as far as they are consecutively lined up.</p>

<p>How many operations are required at least to change the displayed values on counters to the target values?</p>

### 입력 

 <p>The input consists of multiple datasets, each in the following format.</p>

<pre><i>n</i> <i>m</i>
<i>a</i><sub>1</sub> <i>a</i><sub>2</sub> ... <i>a<sub>n</sub></i>
<i>b</i><sub>1</sub> <i>b</i><sub>2</sub> ... <i>b<sub>n</sub></i>
</pre>

<p>Each dataset consists of 3 lines. The first line contains <i>n</i> (1 ≤ <i>n</i> ≤ 1000) and <i>m</i> (1 ≤ <i>m</i> ≤ 10000), the number of counters and the maximum value displayed on counters, respectively. The second line contains the initial values on counters, <i>a<sub>i</sub></i> (1 ≤ <i>a<sub>i</sub></i> ≤ <i>m</i>), separated by spaces. The third line contains the target values on counters, <i>b<sub>i</sub></i> (1 ≤ <i>b<sub>i</sub></i> ≤ <i>m</i>), separated by spaces.</p>

<p>The end of the input is indicated by a line containing two zeros. The number of datasets does not exceed 100.</p>

### 출력 

 <p>For each dataset, print in a line the minimum number of operations required to make all of the counters display the target values.</p>


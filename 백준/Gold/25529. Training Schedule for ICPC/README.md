# [Gold III] Training Schedule for ICPC - 25529 

[문제 링크](https://www.acmicpc.net/problem/25529) 

### 성능 요약

메모리: 2020 KB, 시간: 0 ms

### 분류

수학, 그리디 알고리즘

### 제출 일자

2026년 04월 18일 01:08:28

### 문제 설명

<p>With little time remaining until ICPC, you decided to reschedule your training plan. As maintaining both mental and physical vitality is important, you decided to spend <var>n</var> days of the remaining <var>n</var> + <var>m</var> days for training, and <var>m</var> days for repose. The question is which days should be used for the training and which for the repose. A schedule that increases your <em>ICPC power</em> more is better.</p>

<p>Training days increase the power, and consecutive training days are more effective. One day of training on the <var>k-</var>th day of consecutive training days increases the power by 2<var>k</var> − 1, where <var>k</var> = 1 for the first day of the consecutive training days. A single training day increases the power by only 1, but two consecutive training days increase it by 1 + 3 = 4, and three consecutive training days increase it by 1 + 3 + 5 = 9.</p>

<p>Repose days, on the other hand, decrease the power, and consecutive repose days decrease it more rapidly. One day of repose on the <var>k-</var>th day of consecutive repose days decreases the power by 2<var>k</var> − 1, where <var>k</var> = 1 for the first day of the consecutive repose days. A single repose day decreases the power by only 1, but two consecutive repose days decrease it by 1 + 3 = 4, and three consecutive repose days decrease it by 1 + 3 + 5 = 9.</p>

<p>Let us compute the largest increment of your ICPC power after <var>n</var> + <var>m</var> days of training and repose by the best training schedule. Note that, if you have too many repose days, this may be negative.</p>

### 입력 

 <p>The input consists of multiple datasets, each in the following format.</p>

<pre><var>n</var> <var>m</var></pre>

<p>Here, <var>n</var> and <var>m</var> are the numbers of training and repose days, respectively. Neither of them exceeds 10<sup>6</sup>, and at least one of them is non-zero.</p>

<p>The end of the input is indicated by a line containing two zeros. The number of datasets does not exceed 100.</p>

### 출력 

 <p>For each of the datasets, output in a line the largest increment of ICPC power after <var>n</var> + <var>m</var> days of training and repose by the best training schedule.</p>


# [Gold I] Histogram - 23242 

[문제 링크](https://www.acmicpc.net/problem/23242) 

### 성능 요약

메모리: 3116 KB, 시간: 1032 ms

### 분류

수학, 다이나믹 프로그래밍, 누적 합

### 제출 일자

2026년 04월 18일 01:08:28

### 문제 설명

<p>For a range of $[1, n]$, the natural numbers in the interval are called the data values and let $f_i$ be the frequency count of the data value $i$ in the range. The frequency of a data value $i$ is the number of occurrences of the data value $i$ in the list of numbers. For example, the frequency of the data value $2$ in the list $[3, 2, 3, 2, 4, 2]$ is $3$. The following frequency table shows the frequency counts of the values in the range $[1, 8]$.</p>

<table class="table table-bordered table-center-50 td-center th-center">
	<tbody>
		<tr>
			<th>value $i$</th>
			<td>1</td>
			<td>2</td>
			<td>3</td>
			<td>4</td>
			<td>5</td>
			<td>6</td>
			<td>7</td>
			<td>8</td>
		</tr>
		<tr>
			<th>frequency $f_i$</th>
			<td>4</td>
			<td>2</td>
			<td>3</td>
			<td>6</td>
			<td>5</td>
			<td>6</td>
			<td>12</td>
			<td>16</td>
		</tr>
	</tbody>
</table>

<p>A bucket $b_i$ is represented by a range $[s_i , e_i]$ and its representative value $r_i$. For each bucket, we use the average frequency as the representative value. We want to represent the frequency table by a histogram that consists of a small number of buckets such that the intervals of the buckets do not overlap and cover the range of all data values in the frequency table. For example, a possible histogram of the above frequency table with two buckets is shown below where the first and second buckets cover the value range $[1, 4]$ and $[5, 8]$, respectively. In the histogram, the average frequencies of the first and second buckets are $3.75$ and $9.75$, respectively.</p>

<table class="table table-bordered table-center-50 td-center th-center">
	<tbody>
		<tr>
			<th>bucket interval</th>
			<td>$[1, 4]$</td>
			<td>$[5, 8]$</td>
		</tr>
		<tr>
			<th>average frequency</th>
			<td>$3.75$</td>
			<td>$9.75$</td>
		</tr>
	</tbody>
</table>

<p>After a set of buckets from a frequency table is constructed, when the frequency of a value is asked, the average frequency of the bucket to which the value belongs should be answered. For instance, if the frequency of the value $2$ is asked, since the value $2$ belongs to the first bucket whose average frequency is $3.75$, $3.75$ will be answered instead of the true frequency $2$ of the value $2$. We define the error of a bucket in the histogram as the sum of the squared errors of the frequencies of all values in the bucket. In the above histogram, the error of the first bucket for the range $[1, 4]$ is $(4 - 3.75)^2$ $+$ $(2 - 3.75)^2$ $+$ $(3 - 3.75)^2$ $+$ $(6 - 3.75)^2$ $=$ $8.75$ while that of the second bucket for the range $[5, 8]$ is $(5 - 9.75)^2$ $+$ $(6 - 9.75)^2$ $+$ $(12 - 9.75)^2$ $+$ $(16 - 9.75)^2$ $=$ $80.75$. The error of a histogram is then defined as the sum of the errors of all buckets in the histogram. Thus, the error of the histogram becomes $8.75 + 80.75 = 89.5$. On the other hand, the following histogram has the error of $21.333333$, that is the minimum among the errors of the histograms with two buckets.</p>

<table class="table table-bordered table-center-50 td-center th-center">
	<tbody>
		<tr>
			<th>bucket interval</th>
			<td>$[1, 6]$</td>
			<td>$[7, 8]$</td>
		</tr>
		<tr>
			<th>average frequency</th>
			<td>$4.333333$</td>
			<td>$14$</td>
		</tr>
	</tbody>
</table>

<p>Given a frequency table and the number $B$ of buckets of the histogram, write a program that finds a minimum error histogram with at most $B$ buckets.</p>

### 입력 

 <p>Your program is to read from standard input. The input starts with a line containing an integer $B$ ($1 \le B \le 30$), where $B$ is the limit on the number of buckets. The second line contains an integer $n$ ($1 \le n \le 4,000$) that is the number of data values, indicating the range $[1, n]$. The next $n$ lines contain the frequencies of the data values. The $i$-th line of them contains a positive integer that is the frequency $f_i$ of the data value $i$, where $1 \le f_i ≤ 100$.</p>

### 출력 

 <p>Your program is to write to standard output. Print exactly one line. The line should contain a real number $z$ that represents the error value $OPT$ of the histogram with a minimum error. The output $z$ should be in the format that consists of its integer part, a decimal point, and its fractional part, and it should satisfy the condition that $OPT - 10^{-4} < z < OPT + 10^{-4}$.</p>


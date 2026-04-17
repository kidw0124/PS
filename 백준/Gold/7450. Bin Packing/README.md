# [Gold V] Bin Packing - 7450 

[문제 링크](https://www.acmicpc.net/problem/7450) 

### 성능 요약

메모리: 2668 KB, 시간: 8 ms

### 분류

그리디 알고리즘, 정렬

### 제출 일자

2026년 04월 18일 01:08:28

### 문제 설명

<p>A set of n 1-dimensional items have to be packed in identical bins. All bins have exactly the same length l and each item i has length l<sub>i</sub> ≤ l. We look for a minimal number of bins q such that</p>

<ul>
	<li>each bin contains at most 2 items,</li>
	<li>each item is packed in one of the q bins,</li>
	<li>the sum of the lengths of the items packed in a bin does not exceed l.</li>
</ul>

<p>You are requested, given the integer values n, l, l<sub>1</sub>, . . . , l<sub>n</sub>, to compute the optimal number of bins q.</p>

### 입력 

 <p>The input begins with a single positive integer on a line by itself indicating the number of the cases following, each of them as described below. This line is followed by a blank line, and there is also a blank line between two consecutive inputs.</p>

<p>The first line of the input file contains the number of items n (1 ≤ n ≤ 10<sup>5</sup>). The second line contains one integer that corresponds to the bin length l ≤ 10000. We then have n lines containing one integer value that represents the length of the items.</p>

### 출력 

 <p>For each test case, your program has to write the minimal number of bins required to pack all items.</p>

<p>The outputs of two consecutive cases will be separated by a blank line.</p>

<p>Note: The sample instance and an optimal solution is shown in the figure below. Items are numbered from 1 to 10 according to the input order.</p>

<p style="text-align: center;"><img alt="" src="https://onlinejudgeimages.s3-ap-northeast-1.amazonaws.com/problem/7450/1.png" style="height:133px; width:637px"></p>


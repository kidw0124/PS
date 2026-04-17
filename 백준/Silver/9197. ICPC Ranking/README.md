# [Silver I] ICPC Ranking - 9197 

[문제 링크](https://www.acmicpc.net/problem/9197) 

### 성능 요약

메모리: 2160 KB, 시간: 4 ms

### 분류

구현, 정렬

### 제출 일자

2026년 04월 18일 01:08:28

### 문제 설명

<p>Your mission in this problem is to write a program which, given the submission log of an ICPC (International Collegiate Programming Contest), determines team rankings.</p>

<p>The log is a sequence of records of program submission in the order of submission. A record has four fields: elapsed time, team number, problem number, and judgment. The elapsed time is the time elapsed from the beginning of the contest to the submission. The judgment field tells whether the submitted program was correct or incorrect, and when incorrect, what kind of an error was found.</p>

<p>The team ranking is determined according to the following rules. Note that the rule set shown here is one used in the real ICPC World Finals and Regionals, with some detail rules omitted for simplification.</p>

<ol>
	<li>Teams that solved more problems are ranked higher.</li>
	<li>Among teams that solve the same number of problems, ones with smaller total consumed time are ranked higher.</li>
	<li>If two or more teams solved the same number of problems, and their total consumed times are the same, they are ranked the same.</li>
</ol>

<p>The total consumed time is the sum of the consumed time for each problem solved. The consumed time for a solved problem is the elapsed time of the accepted submission plus 20 penalty minutes for every previously rejected submission for that problem.</p>

<p>If a team did not solve a problem, the consumed time for the problem is zero, and thus even if there are several incorrect submissions, no penalty is given.</p>

<p>You can assume that a team never submits a program for a problem after the correct submission for the same problem.</p>

### 입력 

 <p>The input is a sequence of datasets each in the following format. The last dataset is followed by a line with four zeros.</p>

<pre><i>M</i> <i>T</i> <i>P</i> <i>R</i>
<i>m</i><sub>1</sub> <i>t</i><sub>1</sub> <i>p</i><sub>1</sub> <i>j</i><sub>1</sub>
<i>m</i><sub>2</sub> <i>t</i><sub>2</sub> <i>p</i><sub>2</sub> <i>j</i><sub>2</sub>
.....
<i>m<sub>R</sub></i> <i>t<sub>R</sub></i> <i>p<sub>R</sub></i> <i>j<sub>R</sub></i></pre>

<p>The first line of a dataset contains four integers <i>M</i>, <i>T</i>, <i>P</i>, and <i>R</i>. <i>M</i> is the duration of the contest. <i>T</i> is the number of teams. <i>P</i> is the number of problems. <i>R</i> is the number of submission records. The relations 120 ≤ <i>M</i> ≤ 300, 1 ≤ <i>T</i> ≤ 50, 1 ≤ <i>P</i> ≤ 10, and 0 ≤ <i>R</i> ≤ 2000 hold for these values. Each team is assigned a team number between 1 and <i>T</i>, inclusive. Each problem is assigned a problem number between 1 and <i>P</i>, inclusive.</p>

<p>Each of the following <i>R</i> lines contains a submission record with four integers <i>m<sub>k</sub></i>, <i>t<sub>k</sub></i>, <i>p<sub>k</sub></i>, and <i>j<sub>k</sub></i> (1 ≤ <i>k</i> ≤ <i>R</i>). <i>m<sub>k</sub></i> is the elapsed time. <i>t<sub>k</sub></i> is the team number. <i>p<sub>k</sub></i> is the problem number. <i>j<sub>k</sub></i> is the judgment (0 means correct, and other values mean incorrect). The relations 0 ≤ <i>m<sub>k</sub></i> ≤ <i>M</i>−1, 1 ≤ <i>t<sub>k</sub></i> ≤ <i>T</i>, 1 ≤ <i>p<sub>k</sub></i> ≤ <i>P</i>, and 0 ≤ <i>j<sub>k</sub></i> ≤ 10 hold for these values.</p>

<p>The elapsed time fields are rounded off to the nearest minute.</p>

<p>Submission records are given in the order of submission. Therefore, if <i>i</i> < <i>j</i>, the <i>i</i>-th submission is done before the <i>j</i>-th submission (<i>m<sub>i</sub></i> ≤ <i>m<sub>j</sub></i>). In some cases, you can determine the ranking of two teams with a difference less than a minute, by using this fact. However, such a fact is never used in the team ranking. Teams are ranked only using time information in minutes.</p>

### 출력 

 <p>For each dataset, your program should output team numbers (from 1 to <i>T</i>), higher ranked teams first. The separator between two team numbers should be a comma. When two teams are ranked the same, the separator between them should be an equal sign. Teams ranked the same should be listed in decreasing order of their team numbers.</p>


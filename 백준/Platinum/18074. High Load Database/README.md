# [Platinum V] High Load Database - 18074 

[문제 링크](https://www.acmicpc.net/problem/18074) 

### 성능 요약

메모리: 5936 KB, 시간: 272 ms

### 분류

이분 탐색, 누적 합

### 제출 일자

2024년 8월 18일 23:56:26

### 문제 설명

<p>Henry profiles a high load database migration script. The script is the list of n transactions. The i-th transaction consists of ai queries. Henry wants to split the script to the minimum possible number of batches, where each batch contains either one transaction or a sequence of consecutive transactions, and the total number of queries in each batch does not exceed t.</p>

<p>Unfortunately, Henry does not know the exact value of t for the production database, so he is going to estimate the minimum number of batches for q possible values of t: t<sub>1</sub>, t<sub>2</sub>, . . . , t<sub>q</sub>. Help Henry to calculate the number of transactions for each of them.</p>

### 입력 

 <p>The first line contains a single integer n — the number of transactions in the migration script (1 ≤ n ≤ 200 000).</p>

<p>The second line consists of n integers a<sub>1</sub>, a<sub>2</sub>, . . . , a<sub>n</sub> — the number of queries in each transaction (1 ≤ a<sub>i</sub>; ∑a<sub>i</sub> ≤ 10<sup>6</sup>).</p>

<p>The third line contains an integer q — the number of queries (1 ≤ q ≤ 100 000). The fourth line contains q integers t<sub>1</sub>, t<sub>2</sub>, . . . , t<sub>q</sub> (1 ≤ t<sub>i</sub> ≤ ∑a<sub>i</sub>).</p>

### 출력 

 <p>Output q lines. The i-th line should contain the minimum possible number of batches, having at most ti queries each. If it is not possible to split the script into the batches for some ti , output “Impossible” instead.</p>

<p>Remember that you may not rearrange transactions, only group consecutive transactions in a batch.</p>


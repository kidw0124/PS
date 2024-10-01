# [Silver III] Breed Counting - 11969 

[문제 링크](https://www.acmicpc.net/problem/11969) 

### 성능 요약

메모리: 5156 KB, 시간: 52 ms

### 분류

누적 합

### 제출 일자

2024년 10월 1일 17:42:20

### 문제 설명

<p>Farmer John's \(N\) cows, conveniently numbered \(1 \ldots N\), are all standing in a row (they seem to do so often that it now takes very little prompting from Farmer John to line them up). Each cow has a breed ID: 1 for Holsteins, 2 for Guernseys, and 3 for Jerseys. Farmer John would like your help counting the number of cows of each breed that lie within certain intervals of the ordering.</p>

### 입력 

 <p>The first line of input contains \(N\) and \(Q\) (\(1 \leq N \leq 100,000\), \(1 \leq Q \leq 100,000\)).</p>

<p>The next \(N\) lines contain an integer that is either 1, 2, or 3, giving the breed ID of a single cow in the ordering.</p>

<p>The next \(Q\) lines describe a query in the form of two integers \(a, b\) (\(a \leq b\)).</p>

### 출력 

 <p>For each of the \(Q\) queries \((a,b)\), print a line containing three numbers: the number of cows numbered \(a \ldots b\) that are Holsteins (breed 1), Guernseys (breed 2), and Jerseys (breed 3).</p>


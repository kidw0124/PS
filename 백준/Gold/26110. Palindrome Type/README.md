# [Gold III] Palindrome Type - 26110 

[문제 링크](https://www.acmicpc.net/problem/26110) 

### 성능 요약

메모리: 2300 KB, 시간: 0 ms

### 분류

문자열, 재귀

### 제출 일자

2026년 04월 18일 01:08:28

### 문제 설명

<p>A <em>palindrome</em> string is a word which reads the same backward as forward, such as <em>madam</em> or <em>racecar</em>. In this problem we only consider strings with lowercase alphabets.</p>

<p>We newly define the types of palindromes. If a string is not a palindrome, we try to make it a palindrome by removing the minimum number of characters in the string. For a string $w$, if $k$ is the minimum number of characters removed to make the string a palindrome, we call the string $w$ type-$k$ palindrome. Thus, if $w$ is a palindrome, then $w$ is a type-$0$ palindrome.</p>

<p>Given a string $w$, write a program to determine if $w$ is a type-$k$ palindrome where $k = 0, 1, 2, 3$.</p>

### 입력 

 <p>Your program is to read from standard input. The input is a single line containing a string $w$ with length $n$ ($5 ≤ n ≤ 10^5$) of lowercase alphabets.</p>

### 출력 

 <p>Your program is to write to standard output. Print exactly one line. The line should contain a number $k$ among $\{0, 1, 2, 3, -1\}$ if the input string is a type-$k$ palindrome where $k = 0, 1, 2, 3$ and otherwise $-1$. The negative number $-1$ means the input string is not a type-$k$ palindrome where $k = 0, 1, 2, 3$.</p>


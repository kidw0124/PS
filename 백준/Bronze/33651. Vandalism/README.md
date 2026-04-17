# [Bronze IV] Vandalism - 33651 

[문제 링크](https://www.acmicpc.net/problem/33651) 

### 성능 요약

메모리: 2088 KB, 시간: 0 ms

### 분류

구현, 문자열

### 제출 일자

2026년 04월 18일 01:08:28

### 문제 설명

<p>In recent weeks, the United Association against Property Crime (UAPC) sign has been repeatedly vandalized. Vandals remove some of the letters from <code>UAPC</code> to form an acronym of their choosing. For example, last month, the Unauthorized Art Collective (UAC) removed the letter <code>P</code>.</p>

<p>The UAPC is tired of manually determining which letters have been lost and need replacement. They have tasked you with creating an algorithm to automatically identify the missing letters.</p>

### 입력 

 <p>The first line of input contains a string $s$ of length at most $3$. It is guaranteed that $s$ is non-empty and can be obtained by removing some characters from <code>UAPC</code>, while preserving the order of the remaining letters. It is guaranteed that at least one character has been removed.</p>

### 출력 

 <p>Output a string consisting of the characters removed from <code>UAPC</code> to obtain $s$, listed in the order they appear in <code>UAPC</code>.</p>


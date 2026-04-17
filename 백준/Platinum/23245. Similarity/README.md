# [Platinum IV] Similarity - 23245 

[문제 링크](https://www.acmicpc.net/problem/23245) 

### 성능 요약

메모리: 37924 KB, 시간: 188 ms

### 분류

자료 구조, 정렬, 세그먼트 트리

### 제출 일자

2026년 04월 18일 01:08:28

### 문제 설명

<p>In modern application systems, a recommendation system is very widely used to recommend books, music, ads, items, etc. The recommendation system needs to attract other users by providing the most interested items to each user. One way of recommendation is to find the most similar user to the current user, then recommend the items that the most similar user purchased to the current user. To help the recommendation system, we design a similarity measure. A user is represented by a sequence $p = p_1, p_2, \dots, p_n$ where $n$ denotes the number of items. It denotes a list of the preference magnitudes of the user for items. When we are given two sequences $p = p_1, p_2, \dots, p_n$ and $q = q_1, q_2, \dots, q_n$, a <em>similar tuple</em> is defined as a tuple $(i, j, k)$ such that $p_i < p_j < p_k$ and $q_i < q_j < q_k$. For given two sequences $p = p_1, p_2, \dots, p_n$ and $q = q_1, q_2, \dots, q_n$, the <em>similarity</em> is defined as the number of similar tuples.</p>

<p>For example, if the given two sequences are $p = 2, 5, 9, 5, 1$ and $q = 1, 4, 5, 3, 2$, the similar tuples are $(1, 2, 3)$, $(1, 4, 3)$, $(5, 2, 3)$, and $(5, 4, 3)$ The similarity of the two sequences is $4$.</p>

<p>Given two sequences $p = p_1, p_2, \dots, p_n$ and $q = q_1, q_2, \dots, q_n$, write a program to output the similarity of them.</p>

### 입력 

 <p>Your program is to read from standard input. The input starts with a line containing one integer $n$ ($1 \le n \le 100,000$), where $n$ is the length of a sequence. In the following two lines, each line contains $n$ integers in range $[0, 10^6]$ that represent a sequence.</p>

### 출력 

 <p>Your program is to write to standard output. Print exactly one line. The line should contain the similarity of the two sequences.</p>


# [Platinum III] Palindromic Parentheses - 32087 

[문제 링크](https://www.acmicpc.net/problem/32087) 

### 성능 요약

메모리: 2152 KB, 시간: 0 ms

### 분류

애드 혹, 해 구성하기

### 제출 일자

2024년 7월 26일 23:11:46

### 문제 설명

<p>Construct a parentheses sequence consisting of $N$ characters such that it is <strong>balanced</strong> and the length of its <strong>longest palindromic subsequence (LPS)</strong> is exactly $K$. Determine whether such a construction is possible. If there are several possible sequences, construct any of them.</p>

<p>A parentheses sequence consists of only character <code>(</code> and <code>)</code>. A parentheses sequence is <strong>balanced</strong> if each character <code>(</code> has a corresponding character <code>)</code> and the pairs of parentheses are properly nested. For example, <code>()</code>, <code>(())</code>, <code>(())()</code>, and <code>((())())</code> are balanced. However, <code>)(</code>, <code>(()</code>, and <code>())</code> are not balanced.</p>

<p>A sequence is <strong>palindromic</strong> if it reads the same backwards as forwards. For example, <code>((</code>, <code>)</code>, <code>())(</code>, and <code>(()((</code> are palindromic. However, <code>()</code>, <code>)(</code>, and <code>(())</code> are not palindromic.</p>

<p>A <strong>subsequence</strong> can be derived from another sequence by removing zero or more characters without changing the order of the remaining characters. For example, <code>(</code>, <code>)))</code>, <code>())(</code>, and <code>(())()</code> are subsequence of <code>(())()</code>. However, <code>)((</code> and <code>((()))</code> are not subsequence of <code>(())()</code>.</p>

<p>The <strong>longest palindromic subsequence (LPS)</strong> of a sequence is a subsequence with the maximum number of characters, derived from that sequence and it is palindromic. For example, the LPS of sequence <code>(())()</code> is <code>())(</code>, which can be obtained by removing the second and sixth characters. Therefore, the length of the LPS of <code>(())()</code> is $4$.</p>

### 입력 

 <p>Input consists of two integers $N$ $K$ ($2 ≤ N ≤ 2000$; $1 ≤ K ≤ N$). $N$ is an even number.</p>

### 출력 

 <p>If there is no such parentheses sequence such that it is balanced and the length of its LPS is exactly $K$, then output <code>-1</code>.</p>

<p>Otherwise, output a string of $N$ characters, representing the parentheses sequence. If there are several possible answers, output any of them.</p>


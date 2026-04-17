# [Gold I] Encryption Function - 18899 

[문제 링크](https://www.acmicpc.net/problem/18899) 

### 성능 요약

메모리: 2024 KB, 시간: 0 ms

### 분류

백트래킹, 수학

### 제출 일자

2026년 04월 18일 01:08:28

### 문제 설명

<p>After her computer class Sophie invented her own encrypting function, which takes a number as an input. Given a number it treats it as a sequence of base-10 digits (with no leading zeroes), masks out every possible subset of positions in this sequence, interprets the new sequence as a base-$10$ number (possibly with leading zeroes) and adds all numbers obtained in such a way. So far Sophie failed to devise a decryption algorithm. Help her--write a program that decrypts the encrypted number.</p>

### 입력 

 <p>Input consists of a single positive integer $n$ ($1 \le n \le 10^{18}$), this is the output of Sophie's encryption function.</p>

### 출력 

 <p>In the first and only line of the output you should write a single positive integer $m$, for which the encrypted value is $n$, or <code>NIE</code> (Polish for 'no') if no such a number exists.</p>

<p>If there are several correct answers, you can output any of them.</p>


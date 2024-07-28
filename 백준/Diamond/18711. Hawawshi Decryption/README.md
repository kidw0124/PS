# [Diamond V] Hawawshi Decryption - 18711 

[문제 링크](https://www.acmicpc.net/problem/18711) 

### 성능 요약

메모리: 2428 KB, 시간: 10168 ms

### 분류

이산 로그, 수학, 정수론

### 제출 일자

2024년 7월 29일 03:15:01

### 문제 설명

<p>Hawawshi is a traditional dish in Egypt, it’s really appreciated that there are people who are storing it in highly secure safes. The safes are encrypted by a pseudo-random number generator that generates a sequence of random numbers according to the equation: R<sub>n+1</sub> = (a · R<sub>n</sub> + b) mod p, where a, b, and p are integers, p is a prime number, and R0 is the first generated number which is also known as the seed of the sequence.</p>

<p>Some secret information has been delivered to you that the seed of the random generator was an integer selected at random from the range [A, B] inclusively, furthermore, that the key number of the Hawawshi-safe is a number that appeared as one of the first N generated random numbers (namely, R<sub>0</sub>, R<sub>1</sub>, · · · , R<sub>N−1</sub>). You are going to try some different key numbers X, but first, you need to know what is the probability that X has appeared in the first N generated random numbers?</p>

### 입력 

 <p>The first line of the input contains a single integer T specifying the number of test cases.</p>

<p>Each test case consists of a single line containing seven integers N, X, A, B, a, b, and p. (1 ≤ N, X, A, B, a, b ≤ p − 1, 1 < p < 10<sup>8</sup>, 1 ≤ A ≤ B ≤ min(100, p − 1)), in which p is a prime number.</p>

### 출력 

 <p>For each test case, print a single line containing a reduced fraction q/r (q, r are integers) representing the probability that the number X appears in the first N generated random numbers (by the pseudo-random number generator given). It’s guaranteed that it is possible to represent the probability as a reduced fraction of integers as requested.</p>


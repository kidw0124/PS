# [Bronze III] GPA Computation - 34797 

[문제 링크](https://www.acmicpc.net/problem/34797) 

### 성능 요약

메모리: 2084 KB, 시간: 0 ms

### 분류

수학, 구현, 문자열, 사칙연산

### 제출 일자

2026년 04월 15일 19:19:24

### 문제 설명

<p>Lydia wants to know if she is valedictorian!</p>

<p>Lydia's school computes the grade point averages of its students as follows - for each class that a student takes, they get assigned a letter grade from A to E. An A is worth 4 points, a B is worth 3 points, a C is worth 2 points, a D is worth 1 point, and an E is worth no points. The <em>unweighted</em> grade point average is therefore derived by computing the sum of these point values and dividing by the number of classes Lydia took.</p>

<p>To compute the <em>weighted</em> grade point average, each of the classes is assigned a tier from 1 to 3. If a student gets an A, B, or C in a tier 1 class, they get an additive bonus of 0.05 points. If a student gets an A, B, or C in a tier 2 class, they get an additive bonus of 0.025 points. These are the only ways to get additive bonuses. The <em>weighted</em> grade point average is computed by adding together all the additive bonuses to the <em>unweighted</em> grade point average.</p>

<p>Given Lydia's transcript, compute her weighted grade point average!</p>

### 입력 

 <p>The first line of input contains a single integer, $n$ ($1 \le n \le 50$).</p>

<p>Each of the next $n$ lines contains a two-character string, the letter grade for one of the classes Lydia took followed by the tier of the class. It is guaranteed the first character will be in <code>ABCDE</code> and the second character will be in <code>123</code>.</p>

### 출력 

 <p>Output a single number, Lydia's weighted grade point average. Your answer will be considered correct if it has absolute or relative error at most $10^{-6}$.</p>


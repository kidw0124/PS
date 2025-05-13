# [Platinum III] Professor Laugh's Numbers - 8407 

[문제 링크](https://www.acmicpc.net/problem/8407) 

### 성능 요약

메모리: 2096 KB, 시간: 0 ms

### 분류

수학, 정수론

### 제출 일자

2025년 5월 14일 04:19:59

### 문제 설명

<p>Professor Byteman Laugh has been given a unique chance. He has been told that he could get a million dollars for his research from Foundation for Helping Wicked Byteprofessors. The professor always does his best to make his research interesting. Now it is time for the society to grade the professor's work.</p>

<p>However, it is not so easy. The professor has only one week before he will have to present the results of his research. As every scientist, professor Laugh is a little bit absent-minded. He has lost the results somewhere, so he is asking you to write a program which reproduces them.</p>

<p>Professor Laugh does not like to bore his friends and colleagues. Therefore, he is not interested in ordinary integrals, but in thrilling and mind-blowing prime numbers.</p>

<p>For a prime number<sup>1</sup> <em>p</em> greater than 2, an integer <em>e</em> greater than 1 and an integer <em>n</em> less than <em>p</em> the professor says that <em>p</em> is (<em>p</em>, <em>e</em>)<i>-interesting</i> if there is a natural number <em>x</em> such that, <em>x<sup>e</sup></em> ≡ <em>n</em> (mod <em>p</em>). In other words <em>x<sup>e</sup></em> and <em>n</em> give the same remainder when divided by <em>p</em>.</p>

<p>Write a program which:</p>

<ul>
	<li>reads a prime number <em>p</em>, an exponent <em>e</em> and a sequence of numbers;</li>
	<li>tests each number in this sequences if it is (<em>p</em>, <em>e</em>)-interesting;</li>
	<li>writes the result.</li>
</ul>

<p><sup>1</sup>We say that an integer is prime if it is greater than 1 and it has no positive integer divisors other than 1 and itself.</p>

### 입력 

 <p>The first line contains two integers separated by a single space: a prime number <em>p</em> and a number <em>e</em> (3 ≤ <em>p</em> ≤ 2<sup>32</sup>, 2 ≤ <em>e</em> < 2<sup>32</sup>). The second line contains one integer <em>k</em>, i.e. the number of cases (1 ≤ <em>k</em> ≤ 15). Each of next <em>k</em> lines contains one integer. The <em>i</em>-th of these lines contains a number <em>n<sub>i</sub></em>, 1 ≤ <em>n<sub>i</sub></em> ≤ <em>p</em> - 1.</p>

### 출력 

 <p>Your program should write exactly <em>k</em> lines. The line number <em>i</em> (1 ≤ <em>i</em> ≤ <em>k</em>) should contain one word: <code>TAK</code> (i.e. <i>yes</i> in Polish) if <em>n<sub>i</sub></em> is (<em>p</em>, <em>e</em>)-interesting, <code>NIE</code> (i.e. <i>no</i> in Polish) if it is not.</p>


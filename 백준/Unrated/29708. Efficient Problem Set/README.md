# [Unrated] Efficient Problem Set - 29708 

[문제 링크](https://www.acmicpc.net/problem/29708) 

### 성능 요약

메모리: 2096 KB, 시간: 668 ms

### 분류

분류 없음

### 제출 일자

2025년 4월 4일 18:46:44

### 문제 설명

<p>You are planning a problem set for the upcoming programming contest. The problem set should consist of one or more problems each allocated with a certain amount of points, which is a positive integer. The score of each contestant is the sum of the points of the problems that the contestant correctly answers.</p>

<p>The total of points of problems in the problem set must be equal to the full score given by the contest organizer. In addition, some of the contest sponsor companies want to give special prizes to the contestants first attaining prescribed scores exactly. Thus, you have to make the problem set so that every prize-obtaining score specified by a sponsor can possibly be the score of a contestant at some point of time.</p>

<p>You have not prepared any problems yet, as you are planning to start it after deciding the points of each problem in the set. Because it is troublesome to prepare many problems, you want to meet the above-described requirements with as few problems as possible. For example, when the full score is 7 and the prize-obtaining scores are 2 and 5, you can meet them by preparing two problems with points 2 and 5. When the full score is 7 and the prize-obtaining scores are 2 and 4, however, you have to prepare three problems, e.g., those with points 2, 2, and 3.</p>

<p>Find the minimum possible number of problems that meet the requirements.</p>

### 입력 

 <p>The input consists of multiple datasets. Each dataset is in the following format.</p>

<blockquote>
<p><i>n</i></p>

<p><i>s</i></p>
</blockquote>

<p><i>n</i> is the full score of the contest (i.e., the total of points of problems), which is a positive integer not exceeding 100. <i>s</i> represents which values should have possibilities to be contestants' scores. <i>s</i> is a string of length (<i>n</i> + 1) consisting of <code>o</code>'s and <code>x</code>'s, whose (<i>k</i> + 1)-st character being an <code>o</code> means "contestants should have possibilities to get exactly <i>k</i> points as their scores", and being an <code>x</code> means it is not required, i.e., "either is fine whether contestants can get exactly <i>k</i> points as their scores or not". The first and the last characters of <i>s</i> are always <code>o</code>'s.</p>

<p>The end of the input is indicated by a line consisting of a zero. The input consists of at most 100 datasets.</p>

### 출력 

 <p>For each dataset, output in a line the minimum possible number of problems that meet the requirements.</p>


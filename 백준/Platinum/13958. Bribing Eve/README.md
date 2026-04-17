# [Platinum II] Bribing Eve - 13958 

[문제 링크](https://www.acmicpc.net/problem/13958) 

### 성능 요약

메모리: 16092 KB, 시간: 84 ms

### 분류

기하학, 수학, 스위핑

### 제출 일자

2026년 04월 18일 01:08:28

### 문제 설명

<p>Eve works at a magazine that does product reviews and publishes recommeendations to consumers. They are working on a new mobile phones review and have decided on two reproducible tests that score each device's battery lifetime and performance using an integer between 1 and 1000.</p>

<p>These two scores, x<sub>1</sub> and x<sub>2</sub>, are then combined with a weights vector w=[w<sub>1</sub>,w<sub>2</sub>] to produce an overall score:</p>

<p>s = w<sub>1</sub>x<sub>1</sub> + w<sub>2</sub>x<sub>2</sub>.</p>

<p>The final review ranking is then obtained by sorting the products by decreasing order of s. Additionally, when multiple products get exactly the same score, Eve decides how to order them. </p>

<p>Maria (a fake name to mask her identity) tried to bribe Eve to tweak the result to get her product higher on the list. Eve argued that she was not able to tamper the evaluation of each test, but Maria suggested to tweak the weights w used when computing the overall score. The weights w must be non-negative and at least one of them must be positive, but the values are decided by Eve. </p>

<p>Eve is thinking whether to modify the weights in Maria's benefit or not, and asked you to determine what are the best and worst possible ranking positions for Maria's product.</p>

<p>Given a list of all products scores in battery and performance [x<sub>1</sub>,x<sub>2</sub>] tests, find out what are the best and worst positions in the ranking that can be given to Maria's product when the weights [w<sub>1</sub>,w<sub>2</sub>] and the order for tied products are left for Eve to decide. </p>

### 입력 

 <p>The first line has the number N of products being compared. N lines follow, each containing two integers x<sub>1</sub> and x<sub>2</sub> indicating a product's score in the battery and performance tests. Maria's product is the first on the list. </p>

### 출력 

 <p>The output consists of two numbers A and B, indicating the best and worst possible positions that Maria's product can get on the ranking given Eve's ability to modify the weights and ordering in case of a tie. </p>


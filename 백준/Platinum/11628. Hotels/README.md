# [Platinum V] Hotels - 11628 

[문제 링크](https://www.acmicpc.net/problem/11628) 

### 성능 요약

메모리: 9256 KB, 시간: 1284 ms

### 분류

데이크스트라, 그래프 이론, 최단 경로

### 제출 일자

2025년 5월 7일 04:33:51

### 문제 설명

<p>The beautiful city of Leiden draws more and more tourists every year. Opposite the famous Hilbert Hotel, located near the city border, a competing chain is building a hotel in a project nicknamed Lodgings In A Colossal Skyscraper (LIACS). As you may know, the Hilbert Hotel has an infinite number of rooms. Guests at the Hilbert have been complaining that it takes them forever to reach their room, so the competing hotel chain decided that LIACS will only have finitely many rooms. Nevertheless, LIACS will become a colossal skyscraper consisting of many many floors, precisely F of them.</p>

<p>The floors will be connected by both elevators and stairways. Fire regulations demand that it must be possible to reach the ground floor using only the stairs, so there is a stairway going from the top floor all the way down to the ground floor (with a door on every floor in between). On the other hand, the elevators can only pick up people on so many floors before they are full, so the project manager decided that no elevator should stop on every floor. More precisely, the i-th elevator will only stop on floors for which the number is equivalent to R<sub>i</sub> modulo M<sub>i</sub>.</p>

<p>The guests don’t mind taking the elevator or changing elevators many times in a row, but they don’t like taking the stairs. The LIACS project manager has no idea whether his planned elevators provide acceptable coverage, so he asked you to calculate how many flights of stairs his guests have to take in order to get to their room, assuming that their room is situated on the worst possible floor. Guests always enter the hotel on the ground floor. Note that guests may alternately take the stairs and take the elevators in order to reach their room, as not every elevator stops at the ground floor. (See sample input below.)</p>

### 입력 

 <p>The input starts with a line containing an integer T, the number of test cases. Then for each test case:</p>

<ul>
	<li>One line with two space-separated integers F and E, denoting the number of floors and elevators, respectively. These satisfy 2 ≤ F ≤ 10<sup>9</sup> and 0 ≤ E ≤ 100. The floors are numbered from 0 to F − 1, where 0 is the ground floor and F − 1 is the top floor. (This is quite common in the Netherlands, whereas in other countries the ground floor is sometimes numbered 1 instead of 0.)</li>
	<li>E lines, each containing two space-separated integers R<sub>i</sub> and M<sub>i</sub> satisfying 2 ≤ M<sub>i</sub> ≤ F and 0 ≤ R<sub>i</sub> < Mi. These denote the remainder and the modulus for every elevator. It is guaranteed that every elevator stops on at least 1 and at most 1,000 floors.</li>
</ul>

### 출력 

 <p>For each test case, output one line with two integers S and W separated by a single space, where</p>

<ul>
	<li>S is the number of stairs a guest has to take if his room is located on the worst possible floor,</li>
	<li>W is the number of the worst possible floor. If multiple floors are equally bad, output the one closest to the ground floor.</li>
</ul>


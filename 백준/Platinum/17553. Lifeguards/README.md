# [Platinum IV] Lifeguards - 17553 

[문제 링크](https://www.acmicpc.net/problem/17553) 

### 성능 요약

메모리: 14548 KB, 시간: 80 ms

### 분류

애드 혹, 해 구성하기, 기하학

### 제출 일자

2024년 9월 16일 21:51:42

### 문제 설명

<p>Lifeguards have a very important job. They prevent people from drowning and allow millions of people every year to experience the joys of water. You are one of these lifeguards, and you take your job very seriously. If regulations were up to you, everyone would have to wear life vests when in the water, which is why you are part of the Buoyancy Activists Promoting Change. As a result of your persistent lobbying, the pool at which you are a lifeguard has decided to hire a second lifeguard. You are very happy with the increased security at your local swimming pool.</p>

<p>You get along quite well with the new lifeguard, but you discover you have not prepared his arrival properly; on the first day of working together you have some trouble figuring out who is supposed to watch which swimmers. This is completely unacceptable and could lead to casualties! You immediately start working on this problem: following the mantra “shared responsibility is no responsibility”, you try to divide the people in the swimming pool into two groups as follows: any swimmer is the responsibility of the lifeguard closest to this swimmer. Thus, knowing the exact positions of all swimmers, you and your coworker both find a position such that both of you are responsible for the exact same number of swimmers. Furthermore, you want at most one swimmer for whom the distance to you and your coworker is equal. This swimmer counts for both lifeguards.</p>

<p>As you and your coworker are amazing sprinters, you do not care for the actual distance between you and the swimmers, only that the swimmers are divided nicely into two equally sized groups.</p>

### 입력 

 <ul>
	<li>The first line contains an integer 2 ≤ n ≤ 10<sup>5</sup>, the number of swimmers.</li>
	<li>Each of the next n lines contains two integers −10<sup>9</sup> ≤ x ≤ 10<sup>9</sup> and −10<sup>9</sup> ≤ y ≤ 10<sup>9</sup>, the position of the swimmer.</li>
</ul>

### 출력 

 <p>Print two lines, both containing integers x and y with −10<sup>18</sup> ≤ x, y ≤ 10<sup>18</sup>, the locations of you and your coworker.</p>

<p>If there are multiple valid solutions, you may output any one of them.</p>


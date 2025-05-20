# [Platinum III] Programming Tutors - 13470 

[문제 링크](https://www.acmicpc.net/problem/13470) 

### 성능 요약

메모리: 2236 KB, 시간: 44 ms

### 분류

이분 탐색, 이분 매칭, 매개 변수 탐색

### 제출 일자

2025년 5월 21일 05:09:11

### 문제 설명

<p>You are the founder of the Bruce Arden Programming Collective, which is a tutoring programme that matches experienced programmers with newbies to teach them. You have N students and N tutors, but now you have to match them up. Since the students will have to travel to their tutors’ houses from their own (or vice versa) you decide to do your matching based on travel distance.</p>

<p>Minimising overall distance doesn’t seem fair; it might happen that one student has to travel a huge distance while all the other students get a tutor very close by, even though the tutors could have been split up so that each gets a tutor that is at least somewhat close.</p>

<p>Thus, you opt to minimise the distance travelled by the student who is worst off; one pairing of students to tutors is better than another if the student who has to travel farthest in the first pairing has to travel less far than the student who has to travel farthest in the second<br>
pairing.</p>

<p>Because the students live in a city, the distance that a student needs to travel is not the literal distance between them and their tutor. Instead, the distance between points (X, Y) and (X', Y') in the city is |X − X'| + |Y − Y'|.</p>

### 입력 

 <p>The first line of the input contains an integer N, with 1 ≤ N ≤ 100, the number of students and the number of tutors to pair up.</p>

<p>Then, there are N lines, each with two space separated integers with absolute value at most 10<sup>8</sup>, which give the locations of the N students.</p>

<p>These are followed by N lines, each with two space separated integers with absolute value at most 10<sup>8</sup>, which give the locations of the N tutors.</p>

<p>Note that it is possible for students and/or tutors to have identical locations (they may share a house).</p>

### 출력 

 <p>Output a single line containing a single integer K, where K is the least integer such that there exists a pairing of students to tutors so that no pair has distance greater than K between them.</p>


# [Gold V] Rescue Mission - 23097 

[문제 링크](https://www.acmicpc.net/problem/23097) 

### 성능 요약

메모리: 5340 KB, 시간: 20 ms

### 분류

수학, 정수론, 누적 합

### 제출 일자

2026년 04월 18일 01:08:28

### 문제 설명

<p>The plan of the Criminal Liberating Rough Squad (CLRS) is to attack the train carrying the prisoners to another jail through a desert and to free at least some of the them.</p>

<p>CLRS got exactly 10 trucks which will carry the rescued criminals from the place of the assault to the makeshift airport where the planes are already being refueled before they fly abroad with the criminals on board.</p>

<p>At the assault scene, the CLRS will break into a train coach, neutralize coach guards, free all prisoners in the coach and move to the next coach. The squad will progress from the first attacked coach towards the end of the train, liberating the criminals in one coach after another. CLRS is proud to claim they are going to free and load into the trucks all criminals from any coach they will attack. CLRS moves in the train in only one direction, they never turn back.</p>

<p>Somewhat strangely, when the trucks will be leaving the scene, the number of freed criminals has to be exactly the same in all trucks. It is an old time safety superstition of CLRS and it cannot be broken at any cost at any action of this kind.</p>

<p>There are bad news too. The police will probably be patrolling relatively nearby, thus the scene has to be left as soon as possible after the initial assault. That is, immediately when the superstition rule allows it.</p>

<p>It may also happen, the mission will be impossible to accomplish. For example if CLRS starts the attack on a coach too close to the end of the train.</p>

<p>Now, everything has to be planned carefully. The number of transported criminals in each coach is known to CLRS beforehand. They want to know, for each coach in the train, how many coaches will they have to attack if the assault starts on that particular coach.</p>

### 입력 

 <p>The first input line contains integer N (1 ≤ N ≤ 10<sup>5</sup>), the number of coaches in the train. The second line contains N values between 0 and 9 (inclusive), the number of transported criminals in each coach. The values are listed in the order from the first coach in the train to the last.</p>

### 출력 

 <p>The output consists of sequence of N numbers, k-th value in the sequence is the number of attacked coaches when the assault starts on k-th coach. If the mission cannot be accomplished starting on k-th coach, the corresponding value in the sequence is −1.</p>


# [Platinum I] Pickpockets - 23099 

[문제 링크](https://www.acmicpc.net/problem/23099) 

### 성능 요약

메모리: 57568 KB, 시간: 256 ms

### 분류

다이나믹 프로그래밍, 비트마스킹, 비트필드를 이용한 다이나믹 프로그래밍, 배낭 문제

### 제출 일자

2026년 04월 18일 01:08:28

### 문제 설명

<p>The police station stands at the very top of the Jewellery Stores lane, a location vitaly important for the pickpocket business in the town. The policemen start their daily patrol at the top end of the lane, progress slowly down and then return back to the top, seldom reaching the bottom end of the lane during the day. There are many regularities in the police habits, and therefore Big Pickpocket Boss (BPB) can make a smart plan for the holidays. The stores on the lane are labeled by successive integers, beginning from 1, from the bottom of the lane to its top. For each day of holidays, BPB can guarantee some number of stores, from the beginning up to a particular label, to be clean from the police unwelcome scrutiny. Teams of pickpockets will do the job for BPB. There are many teams available, each of them can operate on a single store for a number of consecutive days. Not necessarily all teams must be employed.</p>

<p>BPB is a formidable boss, his rules must be obeyed to the letter:</p>

<ul>
	<li>There will be exactly one team operating in each store on any day the store is clean.</li>
	<li>When a team starts operating in a store they will operate there for some number of consecutive days.</li>
	<li>When a store will not be clean on a particular day, no team will operate in the store on that day.</li>
	<li>No team will operate in two or more stores.</li>
	<li>No team will operate twice or more times during the holidays.</li>
	<li>No team will operate on any day before or after the holidays.</li>
</ul>

<p>It is known that each team can generate their specific minimum income for BPB during their entire operation. BPB knows he has to maximize his minimum total income. He wants that figure from you, today, by 3 PM and not later. Do not even try to disappoint him.</p>

### 입력 

 <p>The first line contains two integers H and T (1 ≤ H ≤ 10<sup>5</sup>, 1 ≤ T ≤ 16), the number of days in the holidays and the number of teams available. The second line contains H integers C<sub>k</sub> (0 ≤ C<sub>k</sub> ≤ 10<sup>5</sup>, 1 ≤ k ≤ H), the highest labels of a clean store on the k-th day of holidays. Label 0 means there is no clean store on the k-th day of holidays. Each of the next T lines contains two integers D<sub>t</sub> and I<sub>t</sub> (1 ≤ D<sub>t</sub> ≤ H, 0 ≤ I<sub>t</sub> ≤ 10<sup>6</sup>, 1 ≤ t ≤ T), the duration of the operation of team t in days, and the minimum income the team generates.</p>

### 출력 

 <p>Print the maximum value of the minimum total income the teams can generate when appropriately scheduled. Print 0 when the conditions of BPB cannot be met.</p>


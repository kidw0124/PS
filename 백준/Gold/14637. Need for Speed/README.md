# [Gold V] Need for Speed - 14637 

[문제 링크](https://www.acmicpc.net/problem/14637) 

### 성능 요약

메모리: 2016 KB, 시간: 0 ms

### 분류

수학, 이분 탐색

### 제출 일자

2026년 04월 18일 01:08:28

### 문제 설명

<p><img alt="" src="" style="float:right; height:186px; width:224px">Sheila is a student and she drives a typical student car: it is old, slow, rusty, and falling apart. Recently, the needle on the speedometer fell off. She glued it back on, but she might have placed it at the wrong angle. Thus, when the speedometer reads s, her true speed is s + c, where c is an unknown constant (possibly negative).</p>

<p>Sheila made a careful record of a recent journey and wants to use this to compute c. The journey consisted of n segments. In the i<sup>th</sup> segment she traveled a distance of d<sub>i</sub> and the speedometer read s<sub>i</sub> for the entire segment. This whole journey took time t. Help Sheila by computing c.</p>

<p>Note that while Sheila’s speedometer might have negative readings, her true speed was greater than zero for each segment of the journey.</p>

### 입력 

 <p>The first line of input contains two integers n (1 ≤ n ≤ 1 000), the number of sections in Sheila’s journey, and t (1 ≤ t ≤ 10<sup>6</sup>), the total time. This is followed by n lines, each describing one segment of Sheila’s journey. The i<sup>th</sup> of these lines contains two integers d<sub>i</sub> (1 ≤ d<sub>i</sub> ≤ 1 000) and s<sub>i</sub> (|s<sub>i</sub>| ≤ 1 000), the distance and speedometer reading for the i<sup>th</sup> segment of the journey. Time is specified in hours, distance in miles, and speed in miles per hour.</p>

### 출력 

 <p>Display the constant c in miles per hour. Your answer should have an absolute or relative error of less than 10<sup>−6</sup>.</p>


# [Gold V] Vacuum Tubes - 11196 

[문제 링크](https://www.acmicpc.net/problem/11196) 

### 성능 요약

메모리: 2164 KB, 시간: 148 ms

### 분류

이분 탐색, 정렬

### 제출 일자

2026년 04월 18일 01:08:28

### 문제 설명

<p>In the X-ray lab at KTH some experiments require evacuated tubes between source and sample and between sample and detector so that the X-rays are not absorbed by the air. Since the positions of object and detector vary between different experiments, several tubes of different lengths are available. The tubes should be fixed together in pairs, since they have a vacuum window only in one end. Two such tube pairs should be chosen, one to place between the source and the object and one to place between the object and the detector. This, however, gives a large set of possible lengths and makes it difficult to figure out which tubes to use for an experiment. The length of the tubes used should be as long as possible to minimize air absorption, but there is a limited amount of space between source and object L<sub>1</sub> and between object and detector L<sub>2</sub>. What is the maximum length of air that can be replaced by vacuum tubes in this way?</p>

<p>Given a set of tube lengths and the two distances L<sub>1</sub> and L<sub>2</sub>, find four tubes with the total length being as long as possible under the constraint that the sum of the first two tube lengths is at most L<sub>1</sub> and the sum of the last two tube lengths is at most L<sub>2</sub>.</p>

### 입력 

 <p>The first line of input contains three positive integers, L<sub>1</sub> and L<sub>2</sub>, denoting the distances explained above in mm (1 ≤ L<sub>1</sub>, L<sub>2</sub> ≤ 10 000) and N, the number of available tubes (4 ≤ N ≤ 2 000). The following N lines each contain a single positive integer less than or equal to 10 000, the length of a tube in mm.</p>

### 출력 

 <p>Output one line containing the maximum total length of air that can be avoided, i.e., the sum of the four tubes chosen. If there are no two pairs of tubes fitting into the setup, output the single word “Impossible” instead.</p>


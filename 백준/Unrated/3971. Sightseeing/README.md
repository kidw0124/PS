# [Unrated] Sightseeing - 3971 

[문제 링크](https://www.acmicpc.net/problem/3971) 

### 성능 요약

메모리: 16668 KB, 시간: 424 ms

### 분류

분류 없음

### 제출 일자

2026년 04월 18일 01:08:27

### 문제 설명

<p>As a computer science student you are of course very outdoorsie, so you decided to go hiking. For your vacation this year, you located an island full of nice places to visit. You already identified a number of very promising tracks, but are still left with some problems. The number of choices is so overwhelming, that you had to select only a “small” subset of at most 100 000 sights. And if that is not enough, you are very picky about the order in which you want to visit the sights. So you have already decided on an order in which you want to visit the preselected tracks. The problem you are left with is to decide in which direction to travel along each single track, and whether you may have to reduce your choice of tracks even further. After identifying the travel time between the endpoints of different tracks, you decide to write a program to figure out if you can make all your trips within the time you have planned for your vacation. Since you also do not want to waste any precious time, you only care about an optimal solution to your problem. Furthermore, the tracks can get pretty challenging. Thats why you do not want to hike along a track more than once.</p>

### 입력 

 <p>The first line of the input gives the number of test cases C (0 < C ≤ 100). The first line of each such test case holds two integers N, T the number of tracks of the current hiker (1 ≤ N ≤ 100 000) and the maximal time spent hiking throughout the vacation (0 ≤ T ≤ 1 000 000) Each of the following N lines holds five integers c<sub>p</sub>, c<sub>bb</sub>, c<sub>be</sub>, c<sub>eb</sub> and c<sub>ee</sub> that describe a track (in order of importance). c<sub>p</sub> gives the length of the track in minutes. c<sub>xy</sub> gives the travel time of the official begin or end of a track to the beginning or end of the next most important track, where x and y are either b or e. All values given are non-negative integers not greater than 1 000 000. Since you have to get back to your car, the list is circular. Furthermore, we will ignore the time it takes you to get to the start of your trip with your car.</p>

### 출력 

 <p>For each test case print one line. The output should contain a list of “F” and “B” for every track (in order) indicating whether you have to hike the track in forward direction or backward direction. If you cannot make the full trip within the planned time T, you should print “IMPOSSIBLE” to indicate that these trips are just too much hiking.</p>


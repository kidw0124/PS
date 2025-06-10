# [Platinum IV] Cable Protection - 20261 

[문제 링크](https://www.acmicpc.net/problem/20261) 

### 성능 요약

메모리: 10852 KB, 시간: 52 ms

### 분류

깊이 우선 탐색, 다이나믹 프로그래밍, 트리에서의 다이나믹 프로그래밍, 그래프 이론, 그래프 탐색, 트리

### 제출 일자

2025년 6월 11일 05:51:53

### 문제 설명

<p>A company ICPC (International Cable Protection Company) produces a cable protection tool that can be installed in a network switch to monitor whether all cable links connected to it are working properly. Because the protection tool would cause transmission delay, it is not suitable for installation on every switch.</p>

<p>Usually network topology consists of two parts: a backbone and several subnets. The switches on the backbone are linked as a ring structure and each backbone switch is treated as a root of a subnet in which the switches are linked as a tree structure. We call such topology as unicyclic topology. Figure 2 shows an example of a unicyclic topology.</p>

<p style="text-align: center;"><img alt="" src="https://upload.acmicpc.net/6087a323-2150-4d8b-b7d1-67443ded3c65/-/preview/" style="width: 453px; height: 201px;"></p>

<p style="text-align: center;">Figure 2: An example of uncyclic topology.</p>

<p>Suppose there are n backbone switches and m subnet switches. The switches are numbered by integers from 0 to m + n − 1. Backbone switches are numbered from 0 to n − 1 in clockwise order and the subnet switches are numbered from n to n + m − 1 where the index of each subnet switch is larger than the index of its parent in the rooted tree structure of the subnet it belongs. Figure 3 shows an example of switch numbering.</p>

<p style="text-align: center;"><img alt="" src="https://upload.acmicpc.net/447c5273-4480-4cde-a326-0b6b3022993e/-/preview/" style="width: 448px; height: 212px;"></p>

<p style="text-align: center;">Figure 3: An example of switch numbering.</p>

<p>Please write a program for ICPC to decide the minimum number of switches selected for installing cable protection tools that can monitor all the cable links. Figure 4 shows an optimum solution (circled by ellipses) for the given network.</p>

<p style="text-align: center;"><img alt="" src="https://upload.acmicpc.net/5ff9f730-c3c1-40a5-ab24-ff82605253ce/-/preview/" style="width: 446px; height: 214px;"></p>

<p style="text-align: center;">Figure 4: An optimum solution for the given network.</p>

### 입력 

 <p>The first line of the input file contains two integers n and m, separated by a space, indicating the numbers of backbone switches and subnet switches respectively. Each of the next n+m lines consists of two integers, separated by a space, indicating the indices of the two end switches of a link.</p>

### 출력 

 <p>Output the minimum number of switches selected for installing cable protection tools that can monitor all the cable links.</p>


# [Gold IV] Symmetry of Stars - 30453 

[문제 링크](https://www.acmicpc.net/problem/30453) 

### 성능 요약

메모리: 149788 KB, 시간: 924 ms

### 분류

자료 구조, 브루트포스 알고리즘, 기하학, 집합과 맵, 해시를 사용한 집합과 맵

### 제출 일자

2026년 04월 18일 01:08:28

### 문제 설명

<p>Twinkling Stars in the universe attract us, guide us, and shed numerous intuitions to us. Astronomer Dr. Kobserved twinkling stars in a dark sky. One day, he was curious of symmetry of stars. To simplify the problem, he assumed the sky is a $xy$ plane and the stars are points placed on the plane. When the set of stars $S$ and a point $p = \left(p_x, p_y \right)$ are given, <em>symmetry of stars $S$ with respect to a point $p$</em> is defined as the number of points $(x, y) \in S$ such that there exists at least one point $(x', y') \in S$ which satisfies $\left( \frac{x+x'}{2}, \frac{y+y'}{2} \right) = \left(p_x, p_y\right)$. When the set of stars $S$ is given, <em>symmetry of stars $S$</em> is defined as the maximum symmetry of stars $S$ with respect to any point $p$ in the whole $xy$ plane. Let’s see an example following.</p>

<p style="text-align: center;"><img alt="" src="" style="width: 385px; height: 350px;"></p>

<p>In the example above, we are given a set of stars $S = \{(1,3), (3,1), (-1,2), (4,4), (1,1), (3,3)\}$. The symmetry of stars $S$ with respect to a point $p = (2,2)$ is $4$ since the point $a = (1,3)$ has point $b = (3,1)$ which satisfies $\left( \frac{a_x + b_x}{2}, \frac{a_y + b_y}{2} \right) = \left( \frac{1+3}{2}, \frac{3+1}{2} \right) = \left( p_x, p_y \right) = (2, 2)$ and the point $e = (1,1)$ has point $f = (3,3)$ which satisfies $\left( \frac{e_x + f_x}{2}, \frac{e_y + f_y}{2} \right) = \left( \frac{1+3}{2}, \frac{1+3}{2} \right) = \left( p_x, p_y \right) = (2, 2)$. The symmetry of stars $S$ with respect to a point $p =(-1,2)$ is $1$ since the point $c = (-1,2)$ has point $c = (-1,2)$ itself which satisfies $\left( \frac{c_x +c_x}{2}, \frac{c_y + c_y}{2} \right) = \left( \frac{-1-1}{2}, \frac{2+2}{2} \right) = \left( p_x, p_y \right) = (-1, 2)$. The symmetry of stars $S$ is $4$ since the symmetry of stars $S$ with respect to the point $p = (2, 2)$ is the maximum among all the points in the $xy$ plane.</p>

<p>Given a list of $n$ distinct points that represent stars, write a program to output the symmetry of the given stars.</p>

### 입력 

 <p>Your program is to read from standard input. The input starts with a line containing one integer, $n$ ($1 ≤ n ≤ 3\,000$), where $n$ is the number of stars. The stars are numbered from $1$ to $n$. In the following $n$ lines, the $i$-th line contains two integers that represent $x$ ($-10^9 ≤ x ≤ 10^9$) and $y$ ($-10^9 ≤ y ≤ 10^9$) coordinates of the star $i$, repectively. Note that no two stars are in the same position.</p>

### 출력 

 <p>Your program is to write to standard output. Print exactly one line. The line should contain the symmetry of stars.</p>


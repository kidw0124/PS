# [Platinum I] Cards - 32451 

[문제 링크](https://www.acmicpc.net/problem/32451) 

### 성능 요약

메모리: 57428 KB, 시간: 604 ms

### 분류

자료 구조, 그리디 알고리즘, 정렬, 세그먼트 트리, 해 구성하기

### 제출 일자

2026년 04월 18일 01:08:28

### 문제 설명

<p>Diana is a student who likes to play various types of board games. Today, she receives a deck of cards from her teacher as her birthday gift!</p>

<p>The deck of cards is special: there are $n$ cards in the deck, and each card has a number on its front and another number on its back. Each number on the front or the back is an integer from $1$ to $n$. Furthermore, all $n$ numbers on the front are unique, and so are the $n$ numbers on the back. In other words, numbers on the front and the back are two different permutations of numbers from $1$ to $n$.</p>

<p>Apart from board games, Diana is also interested in mathematics and computer science. While she is playing with those cards, the concept of inversions in a permutation comes to her mind. An inversion is defined as a pair of indices $(i, j)$ such that $i<j$ and the element at position $i$ is greater than the element at position $j$. In other words, an inversion represents a situation where two elements are “out of order” relative to their positions. A permutation has inversion count $c$ if there are $c$ inversions can be found within it.</p>

<p>Diana wonders if she could rearrange the cards in some order so that the permutation on the front has the same inversion count as the permutation on the back (she cannot flip or throw away some cards). She cannot solve the problem in a while, so she wants to hear your solution.</p>

<p>In formal, you are given two permutations of integers from $1$ to $n$: $a_1, a_2, \dots ,a_n$ and $b_1, b_2, \dots ,b_n$. You have to find another permutation of the first $n$ positive integers $p_1, p_2, \dots ,p_n$, such that $a' = [a_{p_1} , a_{p_2} ,\dots ,a_{p_n}]$ and $b' = [b_{p_1} , b_{p_2} ,\dots ,b_{p_n} ]$ have the same inversion count. Output the sequences $a'$ and $b'$.</p>

### 입력 

 <p>The first line of the input contains an integer $n$, denoting the number cards in the deck. The second line of the input contains $n$ integers $a_1, a_2,\dots ,a_n$, where $a_i$ is the number on the front of the $i$-th card. The third line of the input contains $n$ integers $b_1, b_2,\dots ,b_n$, where $b_i$ is the number on the back of the $i$-th card.</p>

### 출력 

 <p>If it is impossible to rearrange the cards so that the aforementioned condition is satisfied, print <code>No</code>. Otherwise, print <code>Yes</code> in the first line of the output. Then in the second line of the output, print $n$ integers $a'_1, a'_2, \dots ,a'_n$, denoting the numbers on the front of the cards after the rearrangement. In the third line of the output, print $n$ integers $b'_1, b'_2, \dots , b'_n$, denoting the numbers on the back of the cards after the rearrangement.</p>

<p>If there are multiple possible solutions, print any of them.</p>


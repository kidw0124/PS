# [Bronze II] Wow - 33772 

[문제 링크](https://www.acmicpc.net/problem/33772) 

### 성능 요약

메모리: 2088 KB, 시간: 0 ms

### 분류

구현, 문자열

### 제출 일자

2026년 04월 18일 01:08:28

### 문제 설명

<p>While Mr. Malnar was traveling by bus to Graz, he noticed that other passengers were looking at his phone and reading the messages he was sending to Patrik. Mr. Malnar decided to put an end to this. Therefore, together with Patrik, he developed a new way of encrypting their messages, which they call the VolksWagen cipher.</p>

<p>The received message can be imagined as a table of characters with $2$ rows and $n$ columns. Each letter spans all $2$ rows and several columns, and they are separated by spaces. The appearance of letters in the message can be seen in the sample test cases.</p>

<p>The letter '<code>v</code>' is represented as follows:</p>

<pre>\../
.\/.</pre>

<p>The letter '<code>w</code>' is represented as follows:</p>

<pre>\../\../
.\/..\/.</pre>

<p>From now on, Patrik and Mr. Malnar will communicate exclusively using the letters '<code>v</code>' and '<code>w</code>' (without quotes). However, Mr. Malnar is having trouble reading these messages. He has asked you to help him decipher the message he received. Of course, he has not revealed to you how to decrypt their cipher.</p>

### 입력 

 <p>The first line contains a positive integer $N$ ($1 ≤ N ≤ 1000$), the number of columns in the message.</p>

<p>In the next $2$ rows, there are $N$ characters each, representing one row of the message. It is guaranteed that empty columns will be exactly between two different letters, and there will be exactly one empty column between two letters. (<em>An empty column</em> is considered to be one that contains only the character '<code>.</code>'.)</p>

### 출력 

 <p>In a single line, print the letters that appear in the message in order.</p>


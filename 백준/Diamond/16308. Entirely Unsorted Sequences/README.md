# [Diamond V] Entirely Unsorted Sequences - 16308 

[문제 링크](https://www.acmicpc.net/problem/16308) 

### 성능 요약

메모리: 197784 KB, 시간: 628 ms

### 분류

수학, 다이나믹 프로그래밍, 조합론

### 제출 일자

2026년 04월 18일 01:08:28

### 문제 설명

<p>You have recently been promoted to lead scientist at NASA, the National Association for Sorting Algorithms. Congratulations! Your primary responsibility is testing the sorting algorithms that your team produces. Fortunately, NASA has a large budget this year, and you were able to buy some state of the art integers you can use to test the sorting algorithms.</p>

<p>As the lead scientist, you are well aware that algorithms are tested by their behaviour on worst case inputs. So, to test sorting algorithms, you need sequences that are as unsorted as possible.</p>

<p>Given a sequence of numbers (a<sub>1</sub>, . . . , a<sub>n</sub>) we say that an element a<sub>k</sub> is sorted if for all indices j such that j > k, a<sub>j</sub> ≥ a<sub>k</sub> and for all indices j such that j < k, a<sub>j</sub> ≤ a<sub>k</sub>. For example, in</p>

<p style="text-align: center;">(1, 3, 2, 3, 4, 6, 5, 5)</p>

<p>the sorted elements are the 1, the second occurrence of 3, and the 4. Note that a sequence is sorted if and only if all its elements are sorted. A sequence is called entirely unsorted if none of its elements are sorted.</p>

<p>Given a sequence of integers, what is the number of entirely unsorted sequences you can make by permuting its elements? Two sequences (b<sub>1</sub>, . . . , b<sub>n</sub>) and (c<sub>1</sub>, . . . , c<sub>n</sub>) are considered to be different if there is some index i ∈ {1, . . . , n} for which b<sub>i</sub> ≠ c<sub>i</sub>. Because the number of permutations may be very large, please give it modulo 10<sup>9</sup> + 9.</p>

### 입력 

 <p>The input starts with an integer 1 ≤ n ≤ 5000. Then follows a single line with n integers a<sub>1</sub>, . . . , a<sub>n</sub>, with 0 ≤ a<sub>i</sub> ≤ 10<sup>9</sup> for all i.</p>

### 출력 

 <p>Print a single integer: the number of entirely unsorted sequences you can make by permuting the a<sub>i</sub>, modulo 10<sup>9</sup> + 9.</p>


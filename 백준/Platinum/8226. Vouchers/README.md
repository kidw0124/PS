# [Platinum V] Vouchers - 8226 

[문제 링크](https://www.acmicpc.net/problem/8226) 

### 성능 요약

메모리: 22432 KB, 시간: 384 ms

### 분류

수학, 정수론, 조화수

### 제출 일자

2026년 04월 15일 19:19:24

### 문제 설명

<p>The candy shop owned by Byteasar sells delicious caramel candy. For every positive integer there is exactly one package that contains c candies; currently no new deliveries are expected. To encourage customers to buy the sweets, Byteasar has planted m vouchers for an annual supply of chocolate into some packages, making sure to put at most one voucher in each package.</p>

<p>The carnival starts next week in Byteburg, and it will last n days; on the k-th day of the carnival a party with a<sub>k</sub> guests will be held. Byteasar is confident that on the k-th day's morning each of those guests is going to buy, in his own store, the smallest package of candy available whose content can be equally distributed between the party guests. For example, if n=2, a<sub>1</sub>=4, a<sub>2</sub>=2, then on the first day of the carnival he expects to sell the packages containing four, eight, twelve, and sixteen candies, selling those with two and six candies on the second day.</p>

<p>Now he is wondering which customers will end up with the packages holding the vouchers. He has asked you to write a program that will determine this for him.</p>

### 입력 

 <p>On the first line of the standard input there is a single integer m (1 ≤ m ≤ 1,000,000) that denotes the number of vouchers. The k-th of the m lines that follow holds an integer b<sub>k</sub> (1 ≤ b<sub>k</sub> ≤ 1,000,000) denoting the size (i.e., the number of candies inside) of a package in which Byteasar has placed the k-th voucher. These numbers are given in an increasing order.</p>

<p>Then the next line contains a single integer n (1 ≤ n ≤ 1,000,000) that denotes the number of carnival days. The k-th of the n lines that follow holds an integer a<sub>k</sub> (1 ≤ a<sub>k</sub> ≤ 1,000,000) denoting the number of guests attending the k-th party.</p>

### 출력 

 <p>In the first line of the standard output your program should print an integer z - the number of packages with vouchers sold. The following z lines should specify the numbers of those customers who bought a package with a voucher, in an increasing order. The customers are numbered from 1 in the order of their purchases.</p>


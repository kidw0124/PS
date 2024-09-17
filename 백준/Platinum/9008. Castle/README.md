# [Platinum I] Castle - 9008 

[문제 링크](https://www.acmicpc.net/problem/9008) 

### 성능 요약

메모리: 4172 KB, 시간: 20 ms

### 분류

애드 혹, 그래프 이론, 정렬, 스위핑

### 제출 일자

2024년 9월 17일 13:35:37

### 문제 설명

<p>A satellite sent us a photo of a ruin in the middle of some desert. The ruin in the photo turns out to an ancient castle of the forgotten kingdom which is 2000 years old. We also know that the floor plane of the castle has a shape of a rectilinear polygon.</p>

<p>A rectilinear polygon is a polygon whose edges are either horizontal or vertical. That is, at each vertex of the polygon, the interior angle formed by its two incident edges is either 90° or 270°, as shown in Figure 1. We say that a rectilinear polygon is simple if (1) each vertex is incident to exactly two edges and (2) there are no edges that intersect each other except at their end vertices. </p>

<p style="text-align: center;"><img alt="" src="https://onlinejudgeimages.s3-ap-northeast-1.amazonaws.com/problem/9008/1.png" style="height:277px; width:526px"></p>

<p style="text-align: center;">Figure 1. (a) A simple rectilinear polygon. (b)-(c) Non-simple rectilinear polygons because (b) there is a vertex having four incident edges, or (c) there is a pair of edges crossing each other.</p>

<p>The current status of the castle we have figured out from the photo is not good. Only poles of the castle, i.e., the vertices of the simple rectilinear polygon, remained. Thus we need to find out how the poles were connected to recover the original shape of the castle. Figure 2 shows an example.</p>

<p>Formally, you are given a set of ݊ distinct points in the plane with integer coordinates. You need to decide whether or not we can reconstruct a simple rectilinear polygon by connecting all the points with horizontal and vertical segments alternatingly. You should output “YES” if it is possible to reconstruct a simple rectilinear polygon of ݊ vertices from the ݊ input points, “NO” otherwise. </p>

<p style="text-align: center;"><img alt="" src="https://onlinejudgeimages.s3-ap-northeast-1.amazonaws.com/problem/9008/2.png" style="height:280px; width:550px"></p>

<p style="text-align: center;">Figure 2. (a) Input points. (b) A simple rectilinear polygon reconstructed from the input.</p>

### 입력 

 <p>Your program is to read from standard input. The input consists of T test cases. The number of test cases T is given in the first line of the input. Each test case starts with integer n, the number of points, where 4 ≤ n ≤ 10,000. Each of the following n lines contains two integers, representing x-coordinate and y-coordinate of the points between -10<sup>6</sup> and +10<sup>6</sup>, inclusively. All the points are distinct. </p>

### 출력 

 <p>Your program is to write to standard output. Print exactly one line for each test case. The line should contain “YES” if the points form a simple rectilinear polygon, “NO” otherwise. </p>


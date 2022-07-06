# edge-connectivity

The edge connectivity of an undirected graph is the minimum number k of edges that must be removed to disconnect the graph. 
For example, the edge connectivity of a tree is 1, and the edge connectivity of a cyclic chain of vertices is 2.
Determine the edge connectivity of an undirected graph G = (V, E) by running a maximum-flow algorithm on at most |V| flow networks,
each having O(V) vertices and O(E) edges.

Input: 第一行為一正整數字 n，代表點的個數，第二行開始代表邊 <u, v>
6 
<br>01 
<br>12 
<br>20 
<br>34 
<br>45 
<br>53 
<br>03

Output:
1

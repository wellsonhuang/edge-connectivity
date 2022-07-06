# edge-connectivity
In a computer network a link L, which interconnects two servers, is considered critical if there are at least two servers A and B such that all network interconnection paths between A and B pass through L. Removing a critical link generates two disjoint sub–networks such that any two servers of a sub–network are interconnected.
It is known that:
1. the connection links are bi–directional
2. a server is not directly connected to itself
3. two servers are interconnected if they are directly connected or if they are interconnected with the same server
4. The network can have stand–alone sub–networks
Write a program that finds all critical links of a given computer
network.


Input:
The first line contains a positive integer n which is the number of
network servers.
The next k lines until EOF are randomly ordered and show the way
servers are connected.

Output:
Prints all critical links in network increasingly.

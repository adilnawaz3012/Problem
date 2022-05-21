/*
Introduction to Graph | Types of Graph

NOTES:

Undirected /  Directed
which can further have in degree and out degree

1. Undirected graph only have degree (as we can't say its in/out)
Dregree(2) = 2

2. Directed graph can have in/out degree
InDegres(2) = 2 and OutDegree(2) = 3

NOTE: Total degree in undirected graph is ( 2 * EDGES )

Path: In path, we cannot visit a node more than once for undirected graph.
and in direcetd aslo its same but keep track that if we don'e have reverse egde, we can't traverse to that node.

NOTE: Undirected cyclic graph -> if we can reach the same node again
Undirected acyclic graph -> if we cannot reach the same node again

Directed Cyclic Graph

***** Directed Acyclic Graph ( DAG ) ******

What if edges is having weights: 

Weighted Undirected Graphs ( if weight is not given and if we need to consider weights, then take weights of all edges as 1)
*/

#include<bits/stdc++.h>
using namespace std;

int main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w" , stdout);
    #endif
    int t;
    cin >> t;
    while(t--) {
        cout << "Basics" << endl;
    }
    return 0;  
}
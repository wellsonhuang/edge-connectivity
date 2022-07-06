#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#include <iostream>
#include <vector>
#include <queue>
#include<algorithm>
using namespace std;
int n;
vector< vector<int> > graph;
vector< vector<int> > regraph;
bool BFS(int s, int t, int parent[])
{

	bool visited[n];
	memset(visited, false, sizeof(visited));

	queue<int> q;
	q.push(s);
	
	visited[s] = true;
	parent[s] = -1;

	while (!q.empty()) {
		int u = q.front();
		q.pop();

		for (int i = 0; i < regraph[u].size(); i++) {
			int capacity = regraph[u][i];
			if (visited[capacity] == false && graph[u][capacity] > 0) {
					q.push(capacity);
				parent[capacity] = u;
				visited[capacity] = true;

				if (capacity == t) {
					return true;	
				}
				
			}
		}
	}

	return false;
}

int FordFulkerson(int s, int t)
{
	int max_flow = 0; 
	int parent[n];
  for(int i = 0; i < n; i++){
		parent[i] = -1;
  }
	while (BFS(s, t, parent)) {
		int u,v;
		for (v = t; v != s; v = u) {
			u = parent[v];
			graph[u][v] --;
			graph[v][u] ++;
		}

		max_flow ++;
	}

	return max_flow;
}

int main()
{

	vector<int> temp;
	vector<int> answer;

    while(scanf("%d",&n)!=EOF){
    	int u,v;
	regraph.resize(n);

    for(int i = 0; i < n; i++)
        {
        vector<int> row;
        graph.push_back(row);
        for(int j = 0; j < n; j++)
            {
            graph[i].push_back(0);
            }
        }
    while(cin >> u >> v){

        graph[u][v] = 1;
        graph[v][u] = 1;
		regraph[u].push_back(v);
		regraph[v].push_back(u);
    }
    vector<vector<int>> input;
	input = graph;

    for(int i = 1; i < n; i++){
    	int sink=i;
        answer.push_back(FordFulkerson(0,sink));
     
        graph.clear();
		graph = input;
    }
    }
    int minValue = *min_element(answer.begin(),answer.end());
    cout <<  minValue;
	return 0;
}

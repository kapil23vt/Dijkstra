// This code is for only unweighted graph scenarios

#include <queue>
#include <cstdio>
#include <cstring>
#include <iostream>

using namespace std;

const int maxnodes = 10;
int nodes, edges;

// Each node will have 10 max adjacent nodes
vector<int> adjacent[maxnodes];

//dis[10] to store address of each node from source node
int dis[maxnodes];
int main() {
	int queries;
	cout << "Enter the number of queries" << endl;
	cin >> queries;
	while (queries--) {
        cout << "Enter the number of nodes and edges in the network" << endl;
		cin >> nodes >> edges;
        cout << "Enter the starting node and ending node for each of the edge" << endl;
		for (int i = 0; i < edges; i++) {
			int startnode, endnode;
			cin >> startnode >> endnode;
			startnode--; endnode--;
			
			// adjacent[0] = [1,2,4], if node 0 is connected to nodes 1,2,4
			// 0 connected to 4 and similarly 4 is connected to 0
			adjacent[startnode].push_back(endnode);
			adjacent[endnode].push_back(startnode);
		}
		int source;
		cout << "Enter the node from which the minimum distance to other nodes is to be found" << endl;
		cin >> source;
		source--;
		
		//Creating queue to store the visited nodes from source node
		queue<int> q;
		
		//Starting from the source, BFS can be run from any node as source node
		q.push(source);
		
		//Initial value from source node to each other node will be marked as -1
		memset(dis, -1, sizeof(dis));
		
		//distance to itself will be marked as 0
		dis[source] = 0;
		
		//Starting from BFS
		while (!q.empty()) {
			
			//Taking elements from queue, all the adjacent nodes are taken in order
			int u = q.front(); 
			
			//Removing the last element from queue
			q.pop(); 
		
			//Going through all the adjacent nodes
			for (int i = 0; i < adjacent[u].size(); i++) {
				int v = adjacent[u][i];
				
				// IF node is not visited, distance updated
				if (dis[v] == -1) {
					dis[v] = dis[u] + 1;
					q.push(v);
				}
			}
		}
		
        cout << "The minimum distace to the other nodes :" << endl;
		for (int i = 0; i < nodes; i++) {
			if (i == source) continue;
			cout << "Node " << i+1 << " Minimum Distance = " << dis[i] << endl;
		}
		cout << endl;
		for (int i = 0; i < nodes; i++) {
			adjacent[i].clear();
		}
	}
	return 0;
}

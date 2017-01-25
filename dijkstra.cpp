#include <queue>
#include <cstdio>
#include <cstring>
#include <iostream>

using namespace std;

const int maxnodes = 10;
int nodes, edges;
vector<int> adjacent[maxnodes];
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
			adjacent[startnode].push_back(endnode);
			adjacent[endnode].push_back(startnode);
		}
		int source;
		cout << "Enter the node from which the minimum distance to other nodes is to be found" << endl;
		cin >> source;
		source--;
		queue<int> q;
		q.push(source);
		memset(dis, -1, sizeof(dis));
		dis[source] = 0;
		while (!q.empty()) {
			int u = q.front(); q.pop();

			for (int i = 0; i < adjacent[u].size(); i++) {
				int v = adjacent[u][i];
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

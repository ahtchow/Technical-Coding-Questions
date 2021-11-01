#include <vector>
using namespace std;

/* Cycle can be defined as a chain of at least one vertex in which the first vertex is the same as last vertex */

void DFS(const vector<vector<int>> edges, int curr_node, vector<bool> visited, bool & cycle_in_graph){
		
		if(visited[curr_node] == true){
				cycle_in_graph = true;
				return;
		}
	
		visited[curr_node] = true;
	
		for(auto next_node: edges[curr_node]){
				DFS(edges, next_node, visited, cycle_in_graph);
		}
		
}

	
	
bool cycleInGraph(vector<vector<int>> edges) {
	
	bool cycle_in_graph = false;
	vector<bool> visited(edges.size(), false);

	for(int i = 0; i < edges.size(); i++){

			DFS(edges, i, visited, cycle_in_graph);
			if(cycle_in_graph){
				return true;
			}
	
	}
  return false;
}

class Solution {
public:
    /*
     * @param graph: A list of Directed graph node
     * @return: Any topological order for the given graph.
     */
    vector<DirectedGraphNode*> topSort(vector<DirectedGraphNode*>& graph) {
        // write your code here
        // 1. 首先记录所有节点的入度
        vector<DirectedGraphNode*> ans;
  		map<DirectedGraphNode*, int> indgres;
  		for(auto& node : graph) {
  			for (auto& neighbor : node->neighbors) {
  				indgres[neighbor]++;
  			}
  		}

  		queue<DirectedGraphNode*> q;
  		// 把入度为0的节点，放到队列
  		for(auto& node : graph) {
  			if (indgres[node] == 0) {
  				q.emplace(node);
  			}
  		}
  		// 把队列中入度为0的节点加入ans，把以该节点为入度的节点的入度减1
  		while (!q.empty()) {
  			auto node = q.front();
  			ans.emplace_back(node);
  			q.pop();
  			for (auto& neighbor : nodes->neighbors) {
  				indgres[neighbor]--;
  				if (indgres[neighbor] == 0) {
  					q.emplace(neighbor);
  				}
  			}
  		}

  		return ans;
    }
};
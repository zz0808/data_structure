class Solution {
public:
    Node* cloneGraph(Node* node) {
        unordered_map<Node*, Node*> hash;
        hash[node] = new Node(node->val);
        queue<Node*> q;
        q.emplace(root);

        while (!q.empty()) {
        	Node* node = q.front();
        	q.pop();
        	/*
				如果该节点没有出现在hash中，则添加，并放入queue
        	*/
        	for (auto& n : node->neighbors) {
        		if (hash.find(n) == uset.end()) {
        			hash[n] = new Node(n->val);
        			q.emplace(n);
        		}
        		hash[node]->neighbors.emplace_back(hash[n]);
        	}
        }

        return hash[root];
    }
};
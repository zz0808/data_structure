class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string str = "";
        if (root == nullptr)
        	return "#,";
        queue<TreeNode*> q;
        q.emplace(root);

        while(!q.empty()) {
        	TreeNode* node = q.front();
        	q.pop();
        	if(node != nullptr) {
        		str += (to_string(node->val) + ",");
        		q.emplace(node->left);
        		q.emplace(node->right);
        	} else {
        		str += "#,";
        	}
        }

        return str;

    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        vector<string> substrs = split(data);
        if (substrs[0] == "#")
        	return nullptr;
        TreeNode* root = new TreeNode(stoi(substrs[0]));
        queue<TreeNode*> q;
        q.emplace(root);

        int inx = 1;
        while(inx < substrs.size()) {
        	TreeNode* node = q.front();
        	q.pop();
        	if (substrs[inx] != "#") {
        		node->left = new TreeNode(stoi(substrs[inx]));
        		q.emplace(node->left);
        	} 
        	inx++;
        	if (substrs[inx] != "#") {
        		node->right = new TreeNode(stoi(substrs[inx]));
        		q.emplace(node->right);
        	}
        	inx++;
        }

        return root;
    }

    vector<string> split(const string& str, const char* delim = ",") {
    	vector<string> substrs;
    	char* substr = strtok((char*)str.c_str(), delim);
    	while (substr != nullptr) {
    		substrs.emplace_back(string(substr));
    		substr = strtok(nullptr, delim);
    	}
    	return substrs;
    }
};
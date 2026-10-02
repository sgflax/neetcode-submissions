/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* cloneGraph(Node* node) {
        map<Node*, Node*> oldtonew;
        return dfs(node, oldtonew);
    }

    Node* dfs(Node* node, map<Node*, Node*>& oldtonew){
        if(node == nullptr) return nullptr;

        //already visited
        if(oldtonew.count(node)){
            return oldtonew[node];
        }

        Node* copy = new Node(node->val);
        oldtonew[node] = copy;

        for(auto& neighbor : node->neighbors){
            copy->neighbors.push_back(dfs(neighbor, oldtonew));
        }
        return copy;
    }
};

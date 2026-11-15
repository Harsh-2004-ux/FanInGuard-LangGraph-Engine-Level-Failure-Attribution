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
    unordered_map<Node*,Node*> mp;
    void dfs(Node* n,Node* clone_node){

        for(auto node:n->neighbors){
            if(mp.find(node)==mp.end()){
                Node* clone=new Node(node->val);
                mp[node]=clone;
                clone_node->neighbors.push_back(clone);
                dfs(node,clone);
            }
            else{
                clone_node->neighbors.push_back(mp[node]);
            }
        }
    }
    Node* cloneGraph(Node* node) {
        if(!node) return {};
        mp.clear();
        Node* clone_node=new Node(node->val);

        mp[node]=clone_node;
        dfs(node,clone_node);
        return clone_node;
    }
};

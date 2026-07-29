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
    map<Node*,Node*>mp;
    Node * helper(Node* node){
        if(!node)return node;
        // mp[node]=1;
        if(mp.count(node)) return mp[node];
        Node * new_node = new Node(node->val);
        mp[node]=new_node;
        cout<<node->val<<endl;
        vector<Node*> nebs;
        for(auto nb:node->neighbors){
            nebs.push_back(helper(nb));
        }
        new_node->neighbors=nebs;
        
        return new_node;
    }
    Node* cloneGraph(Node* node) {
        mp.clear();
        return helper(node);
    }
};

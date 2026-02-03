/*
class Node {
  public:
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/

class Solution {
  public:
    int minTime(Node* root, int target) {
        // code here
        if (!root)
            return 0;
            
        unordered_map<Node*, Node*> parentMap;
        trackParent(root, parentMap);
        Node* targetNode = findTarget(root, target);
        return timeToBurn(root, targetNode, parentMap);
    }
    
    Node* findTarget(Node* root, int target) {
        queue<Node*> q;
        q.push(root);
        Node* targetNode = nullptr;
        
        while (!q.empty()) {
            Node* node = q.front();
            q.pop();
            
            if (node->data == target) {
                targetNode = node;
                break;
            }
            
            if (node->left)
                q.push(node->left);
            if (node->right)
                q.push(node->right);
        }
        
        return targetNode;
    }
    
    void trackParent(Node* &root, unordered_map<Node*, Node*> &parentMap) {
        queue<Node*> q;
        q.push(root);
        
        while (!q.empty()) {
            Node* node = q.front();
            q.pop();
                
            
            if (node->left) {
                parentMap[node->left] = node;
                q.push(node->left);
            }
            if (node->right) {
                parentMap[node->right] = node;
                q.push(node->right);
            }
        }
    }
    
    int timeToBurn(Node* root, Node* target, unordered_map<Node*, Node*> &parentMap) {
        int time = 0;
        unordered_set<Node*> visited;
        visited.insert(target);
        queue<Node*> q;
        q.push(target);
        
        while (!q.empty()) {
            int level = q.size();
            bool burned = false;
            
            for (int i = 0; i < level; ++i) {
                Node* node = q.front();
                q.pop();
                
                if (node->left && visited.find(node->left) == visited.end()) {
                    burned = true;
                    visited.insert(node->left);
                    q.push(node->left);
                }
                if (node->right && visited.find(node->right) == visited.end()) {
                    burned = true;
                    visited.insert(node->right);
                    q.push(node->right);
                }
                if (parentMap.count(node) && visited.find(parentMap[node]) == visited.end()) {
                    burned = true;
                    visited.insert(parentMap[node]);
                    q.push(parentMap[node]);
                }
            }
            
            if (burned)
                time++;
        }
        
        return time;
    }
};
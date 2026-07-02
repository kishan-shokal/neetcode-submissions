
class Node {
public:
    Node* childern[26];
    bool isend;

    Node() {
        isend = false;
        for (int i = 0; i < 26; i++)
            childern[i] = nullptr;
    }
};

class WordDictionary {
public:
    Node * root ;
    WordDictionary() {
        root = new Node();
    }
    
    void addWord(string word) {
        Node * curr = root;
        for(auto w:word){
            int ind = w-'a';
            if(!curr->childern[ind]){
                curr->childern[ind]=new Node();
            }
            curr = curr->childern[ind];
            
        }
        curr->isend=true;
    }
    bool f(Node * root,string word,int ind){
        if(ind==word.size()){
            return (root && root->isend) ;
        }
        if(!root) return false;
        if(word[ind]=='.'){
            for(int i = 0;i<26;i++){
                bool ch = f(root->childern[i],word,ind+1);
                if(ch) return true;
            }
            return false;
        }
        int cind = word[ind]-'a';
        
        return f(root->childern[cind],word,ind+1);
    }
    bool search(string word) {
        
        return f(root,word,0);
    }
};


class PrefixTree {
public:
    vector<PrefixTree*> arr;
    bool end;

    PrefixTree() {
        arr = vector<PrefixTree*>(26, nullptr);
        end = false;
    }

    void insert(string word) {
        PrefixTree* curr = this;

        for (char w : word) {
            int ind = w - 'a';

            if (curr->arr[ind] == nullptr) {
                curr->arr[ind] = new PrefixTree();
            }

            curr = curr->arr[ind];
        }

        curr->end = true;
    }
    
    bool search(string word) {
        PrefixTree* curr = this;
        for(auto w :word){
            int ind = w-'a';
            if(curr->arr[ind] == NULL){
                return false;
            }
            curr = curr->arr[ind];
        }
        return curr->end;
    }
    
    bool startsWith(string prefix) {
        PrefixTree* curr = this;
        for(auto w :prefix){
            int ind = w-'a';
            if(curr->arr[ind] == NULL){
                return false;
            }
            curr = curr->arr[ind];
        }
        return true;
    }
};

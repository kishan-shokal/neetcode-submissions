class PrefixTree {
public:
    PrefixTree* children[26];
    bool end;

    PrefixTree() {
        end = false;
        for (int i = 0; i < 26; i++)
            children[i] = nullptr;
    }

    ~PrefixTree() {
        for (int i = 0; i < 26; i++)
            delete children[i];
    }

    void insert(const string &word) {
        PrefixTree* curr = this;

        for (char ch : word) {
            int idx = ch - 'a';

            if (!curr->children[idx])
                curr->children[idx] = new PrefixTree();

            curr = curr->children[idx];
        }

        curr->end = true;
    }

    bool search(const string &word) {
        PrefixTree* curr = this;

        for (char ch : word) {
            int idx = ch - 'a';

            if (!curr->children[idx])
                return false;

            curr = curr->children[idx];
        }

        return curr->end;
    }

    bool startsWith(const string &prefix) {
        PrefixTree* curr = this;

        for (char ch : prefix) {
            int idx = ch - 'a';

            if (!curr->children[idx])
                return false;

            curr = curr->children[idx];
        }

        return true;
    }
};
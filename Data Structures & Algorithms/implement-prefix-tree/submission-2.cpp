class Node {
public:
    Node* children[26];
    bool isEnd;

    Node() {
        isEnd = false;
        for (int i = 0; i < 26; i++)
            children[i] = nullptr;
    }
};

class PrefixTree {
private:
    Node* root;

public:
    PrefixTree() {
        root = new Node();
    }

    void insert(const string &word) {
        Node* curr = root;

        for (char ch : word) {
            int idx = ch - 'a';

            if (!curr->children[idx])
                curr->children[idx] = new Node();

            curr = curr->children[idx];
        }

        curr->isEnd = true;
    }

    bool search(const string &word) {
        Node* curr = root;

        for (char ch : word) {
            int idx = ch - 'a';

            if (!curr->children[idx])
                return false;

            curr = curr->children[idx];
        }

        return curr->isEnd;
    }

    bool startsWith(const string &prefix) {
        Node* curr = root;

        for (char ch : prefix) {
            int idx = ch - 'a';

            if (!curr->children[idx])
                return false;

            curr = curr->children[idx];
        }

        return true;
    }
};
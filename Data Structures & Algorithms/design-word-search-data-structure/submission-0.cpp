struct Node{
    Node* links[26];
    bool endOfWord = false;

    bool containsKey(char ch){
        return links[ch - 'a'] != nullptr;
    }

    Node* get(char ch){
        return links[ch - 'a'];
    }

    void put(char ch, Node* node){
        links[ch-'a'] = node;
    }

    void setEnd(){
        endOfWord = true;
    }

    bool getEnd(){
        return endOfWord;
    }
};

class WordDictionary {
private:
    Node* root;

    bool dfs(Node* node, string& word, int idx){
        if(idx == word.size()){
            return node->getEnd();
        }

        char ch = word[idx];
        if(ch != '.'){
            if(!node->containsKey(ch)){
                return false;
            }
            return dfs(node->get(ch), word, idx+1);
        } else {
            // try all 26 childs
            for(int i=0;i<26;++i){
                Node* child = node->links[i];
                if(child && dfs(child, word, idx+1))
                    return true;
            }
            return false;
        }
    }

public:
    WordDictionary(): root(new Node()) {
        
    }
    
    void addWord(string word) {
        Node* node = root;
        for(char ch: word){
            if(!node->containsKey(ch)){
                node->put(ch, new Node());
            }
            node = node->get(ch);
        }
        node->setEnd();
    }
    
    bool search(string word) {
        Node* node = root;
        return dfs(node, word, 0);
    }
};

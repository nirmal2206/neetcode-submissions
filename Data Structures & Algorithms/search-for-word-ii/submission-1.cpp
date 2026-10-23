struct Node{
    Node* links[26];
    int wordIndex = -1;

    Node* get(char ch){
        return links[ch-'a'];
    }

    void put(char ch, Node* node){
        links[ch - 'a'] = node;
    }

    bool containsKey(char ch){
        return links[ch-'a'] != nullptr;
    }

    void setWordIndex(int i){
        wordIndex = i;
    }

    int getWordIndex(){
        return wordIndex;
    }
};

class Solution {
private:
    Node* root = new Node();

public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        
        vector<string> res;
        if (board.empty() || board[0].empty())
            return res;

        for(int i=0;i<words.size();++i){
            Node* node = root;

            for(char ch:words[i]){
                if(!node->containsKey(ch)){
                    node->put(ch, new Node());
                }
                node = node->get(ch);
            }
            node->setWordIndex(i);
        }

        for(int row=0; row<board.size();++row){
            for(int col=0; col<board[0].size();++col){
                dfs(board, words, res, root, row, col);
            }
        }

        return res;
    }

    void dfs(vector<vector<char>>& board, vector<string>& words, vector<string>& res, Node* node, int row, int col){


        if(row<0 || row>=board.size() || col<0 || col>=board[0].size() || board[row][col] == '#') return;

        char ch = board[row][col];
        
        if(!node->get(ch)) return; // not a valid prefix

        // Move to the Trie node representing this character.
        node = node->get(ch);

        if(node->getWordIndex() != -1){
            res.push_back(words[node->getWordIndex()]);
            node->setWordIndex(-1); // prevent duplicate
        }
        
        board[row][col] = '#'; // mark visited

        dfs(board, words, res, node, row-1, col);
        dfs(board, words, res, node, row+1, col);
        dfs(board, words, res, node, row, col-1);
        dfs(board, words, res, node, row, col+1);

        board[row][col] = ch;
    }
};

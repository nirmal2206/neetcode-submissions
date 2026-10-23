struct Node{
    Node* links[26];
    bool endOfWord = false;

    Node* get(char ch){
        return links[ch-'a'];
    }

    void put(char ch, Node* node){
        links[ch - 'a'] = node;
    }

    bool containsKey(char ch){
        return links[ch-'a'] != nullptr;
    }

    void setEnd(bool value){
        endOfWord = value;
    }

    bool getEnd(){
        return endOfWord;
    }
};

class Solution {
private:
    Node* root = new Node();
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        vector<string> res;

        if(board.empty() || board[0].empty()) return res;

        for(string word: words){
            Node* node = root;

            for(char ch: word){
                if(!node->containsKey(ch)){
                    node->put(ch, new Node());
                }
                node = node->get(ch);
            }
            node->setEnd(true);
        }

        string path;

        for(int row=0;row<board.size();++row){
            for(int col=0;col<board[0].size();++col){
                dfs(board, words, res, root, path, row, col);
            }
        }

        return res;
    }

    void dfs(vector<vector<char>>& board, vector<string>& words, vector<string>& res, Node* node, string& path, int row, int col){

        if(row<0 || row>=board.size() || col<0 || col>=board[0].size() || board[row][col] == '#') return;

        char ch = board[row][col];

        if(!node->containsKey(ch)) return; // invalid prefix

        node = node->get(ch);
        path.push_back(ch);

        if(node->getEnd()){
            res.push_back(path);
            node->setEnd(false); // prevent duplicate
        }

        board[row][col] = '#'; //mark visited

        dfs(board, words, res, node, path, row-1, col);
        dfs(board, words, res, node, path, row+1, col);
        dfs(board, words, res, node, path, row, col-1);
        dfs(board, words, res, node, path, row, col+1);

        board[row][col] = ch; //mark unvisited
        path.pop_back();
    }
};

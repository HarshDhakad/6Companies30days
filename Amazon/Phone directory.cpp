struct trieNode {
    trieNode* children[26] = {nullptr};
    vector<int> indices;
    bool endOfWord = false;
};

class Trie {
public:
    trieNode *root;
    
    Trie() {
        root = new trieNode();
    }
    
    void insert(int index, const string& word) {  // Change to const reference
        trieNode *crawl = root;
        for (int i = 0; i < word.size(); i++) {
            int idx = word[i] - 'a';
            if (crawl->children[idx] == nullptr) {
                crawl->children[idx] = new trieNode;
            }
            crawl = crawl->children[idx];  // Move to the next child node
            crawl->indices.push_back(index);  // Add index after moving to the child node
        }
        crawl->endOfWord = true;
    }
};

class Solution {
public:
    vector<vector<string>> result;
    
    vector<vector<string>> displayContacts(int m, string contact[], string prefix) {
        map<string, int> mpp;
        Trie T;

        // Insert contacts into Trie
        for (int i = 0; i < m; i++) {
            mpp[contact[i]] = i;
        }

        // Inserting contacts into the Trie
        for (auto& str : mpp) {
            T.insert(str.second, str.first);  // First argument is index, second is the contact word
        }
        
        int n = prefix.size();
        trieNode* crawl = T.root;
        
        // For each character in the prefix, traverse the Trie
        int i;
        for (i = 0; i < n; i++) {
            int idx = prefix[i] - 'a';
            
            if (crawl->children[idx] == nullptr) break;
            
            crawl = crawl->children[idx];
            
            // Collect all contacts that match the current prefix
            vector<string> AllContacts;
            for (auto x : crawl->indices) {
                AllContacts.push_back(contact[x]);
            }
            
            sort(AllContacts.begin(), AllContacts.end());
            result.push_back(AllContacts);
        }
        
        // If no matches found, return "0" for the remaining prefixes
        while (i < n) {
            i++;
            result.push_back({"0"});
        }
        
        return result;
    }
};

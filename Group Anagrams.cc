class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> results;
        map<string, int> str2index;//anagram to index
        for (auto elem : strs) {
            string copy = elem;
            sort(elem.begin(), elem.end());
            map<string, int>::iterator found = str2index.find(elem);
            if (found != str2index.end()) {
                results[found->second].push_back(copy);
            }
            else {
                str2index.insert(pair<string, int>(elem, results.size()));
                vector<string> res;
                res.push_back(copy);
                results.push_back(res);
            }
        }
        return results;
    }
};
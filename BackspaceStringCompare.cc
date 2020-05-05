class Solution {
public:
    
    bool backspaceCompare(string S, string T) {
        if (S.empty() && T.empty()) return true;
        if (S.empty() || T.empty()) return false;
    
        for (int index=0; index < S.length(); ) {
            if (S[index] == '#') {
                if (index -1 >= 0) {
                    S.erase(index-1, 2);
                    --index;
                }
                else if (index >= 0) {
                    S.erase(index,1);
                    if (index > 0) --index;
                }
            }
            else {
               ++index;
            }
        }

        for (int index=0; index < T.length();) {
            if (T[index] == '#') {
                if (index -1 >= 0) {
                    T.erase(index-1, 2);
                    --index;
                }
                else  if (index >= 0) {
                    T.erase(index,1);
                    if (index > 0) --index;
                } 
            }
            else {
                ++index;
            }
        }
        return S==T;
    }
    
    /*string getTrimmedString(string& S) {
        string trimmed_S;
        for (int index=0; index < S.length(); ++index) {
            if (S[index] != '#') {
                trimmed_S.push_back(S[index]);
            }
            else {
                while(S[index] == '#' && index < S.length()){
                    if (!trimmed_S.empty()) {
                        trimmed_S.pop_back();
                    }
                    else{
                        
                    }
                    ++index;
                }
                --index;
            }
        }
        return trimmed_S;
    }
    
    bool backspaceCompare(string S, string T) {
        string trimmed_S = getTrimmedString(S);
        string trimmed_T = getTrimmedString(T);
        if (trimmed_S == trimmed_T)
            return true;
        return false;
    }*/
};
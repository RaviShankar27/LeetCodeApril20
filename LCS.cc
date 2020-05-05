class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int len1 = text1.size();
        int len2 = text2.size();
        if (len1 == 0 || len2 == 0) return 0;
        vector<vector<int>> LCSLengthArray;//len1+1,len2+1
        for (int i = 0; i <= len1; ++i) {
            vector<int> row;
            row.push_back(0);
            LCSLengthArray.push_back(row);
        }
        for (int j = 1; j <= len2; ++j) {
            LCSLengthArray[0].push_back(0);
        }
        for (int i = 1; i <= len1; ++i) {
            for (int j = 1; j <= len2; ++j) {
                if (text1[i-1] == text2[j-1]) {
                    //LCSLengthArray[i][j] = 1 + LCSLengthArray[i-1][j-1];// tis give error by addrss sanitizer
                    //this is a valid error as we had not allocated [i][j] but were uisng it
                    LCSLengthArray[i].push_back(1 + LCSLengthArray[i-1][j-1]);
                }
                else {
                    //LCSLengthArray[i][j] = max(LCSLengthArray[i-1][j], LCSLengthArray[i][j-1]);
                    LCSLengthArray[i].push_back(max(LCSLengthArray[i-1][j], LCSLengthArray[i][j-1]));
                }
            }
        }
        return LCSLengthArray[len1][len2];
    }
};
class Solution {
public:
    int countCharacters(vector<string>& words, string chars) {
        int length = 0;
        int arr[26] = {0};
        
        for (int i = 0; i < chars.size(); ++i) {
            arr[chars[i] - 'a']++;
        }
        
        for (int i = 0; i < words.size(); ++i) {
            string &word = words[i];
            
            bool mismatch = false;
            
            for (int j = 0; j < word.size(); ++j) {
                if (arr[word[j] - 'a'] == 0) {
                    mismatch = true;
                    break;
                }
                else {
                    arr[word[j] -'a']--;
                }
            }
            
            if (!mismatch) {
                length += word.size();
            }
            
            for (int k = 0; k < 26; ++k) {
                arr[k] = 0;
            }
            
            for (int k = 0; k < chars.size(); ++k) {
                arr[chars[k] - 'a']++;
            }
            
        }
        return length;
    }
};

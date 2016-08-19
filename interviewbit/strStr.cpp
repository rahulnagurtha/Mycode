int Solution::strStr(const string &haystack, const string &needle) {
    if(haystack == "" && needle == "") return -1;
    
    if(needle == "") return 0;
    
    if (haystack.size() < needle.size()) return -1;
    
    for (int i = 0; i + needle.size() - 1 < haystack.size(); ++i) {
        bool match = true;
        for (int j = 0; j < needle.size(); ++j) {
            if(haystack[i+j] != needle[j]) {
                match = false;
            }
        }
        if(match) return i;
    }
    
    return -1;
}
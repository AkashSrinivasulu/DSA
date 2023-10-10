int longestRepeatingSubstring(string &str, int k) {
    // Write your code here.

    int freq[26] = {0};
    int n = str.size();
    int l = 0;
    int maxFreq = 0;
    int maxLen = 0;
    for(int r = 0; r<n; r++){

        freq[str[r]-'A']++;

        maxFreq = max(maxFreq, freq[str[r]-'A']);

        // (r-l+1 - maxFreq) --> gives no of chars to be replaced tp ,atcj the most repeated char
        // windowLen - len of most freq char --> 
        while(l <= r and (r-l+1 - maxFreq) > k){
            freq[str[l]-'A']--;
            l++;
        }

        maxLen = max(maxLen, r-l+1);
    }

    return maxLen;
}

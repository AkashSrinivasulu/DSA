string minSubstring(string &a, string &b)
{
    // Write your code here.

    int strCnt[26] = {0};
    int patCnt[26] = {0};

    // coutn pattern
    for(int i=0; i<b.size(); i++){
        patCnt[b[i]-'a']++;
    }

    int n = a.size();

    int l = 0, start_ind = -1, cnt = 0, minLen = INT_MAX;

    for(int r = 0; r<n; r++){

        strCnt[a[r]-'a']++;

        if(patCnt[a[r]-'a'] != 0 and strCnt[a[r]-'a'] <= patCnt[a[r]-'a'])
            cnt++;

        // remove extra chars from substr
        if(cnt == b.size()){

            while(strCnt[a[l]-'a'] > patCnt[a[l]-'a'] or patCnt[a[l]-'a'] == 0){

                if(strCnt[a[l]-'a'] > patCnt[a[l]-'a']){
                    strCnt[a[l]-'a']--;
                }

                l++;
            }

            // update minLen
            if(minLen > r-l+1){
                minLen = r-l+1;
                start_ind = l;
            }
        }

    }

    if(start_ind == -1) return "";
    return a.substr(start_ind, minLen);
    
}

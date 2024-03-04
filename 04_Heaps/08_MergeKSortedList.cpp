class Solution {
public:
    string reorganizeString(string s) {

        vector<int> alphabets(26);

        int mostFreq = 0,ind=0;

        for(auto c:s)
            if(++alphabets[c-'a'] > alphabets[mostFreq]) mostFreq = (c-'a');

        if(2*alphabets[mostFreq]-1 > s.size()) return "";

        //make place to correct position
        while(alphabets[mostFreq]){
            s[ind] = ('a'+mostFreq);
            ind+=2;
            alphabets[mostFreq]--;
        }

        //Moving other letters to correct position
        for(int j=0;j<26;j++){
            while(alphabets[j]){
                if(ind>= s.size()) ind= 1;
                s[ind] = ('a'+j);
                alphabets[j]--;
                ind+=2;
            }
        }

        return s;
    }
};
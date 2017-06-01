
// Created by mi on 6/1/17.
//


#include "Utils.h"


string minWindow(string s, string t) {
    int srcHash[255] = {0};
    for (int i = 0; i < t.size(); i++) {
        srcHash[t[i]]++;
    }
    int start = 0;
    int i = 0;
    int destHash[255] = {0};

    int found = 0;
    int begin = -1;
    int end = -1;
    int minlength = s.size();
    for (start = i = 0; i < s.size(); i++) {
        destHash[s[i]]++;
//        当目标串中小于等于源串中的次数，表示找到一个匹配字符;
        if (destHash[s[i]] <= srcHash[s[i]]) found++;

        if (found == t.size()) {
            //跳过开始无用的字符,start向后移，目标串的字符比源串次数多
            while (start < i & destHash[s[start]] > srcHash[s[start]]) {
                destHash[s[start]]--;
                start++;//向右移
            }
//
            if (i - start < minlength) {
                minlength = i - start;
                begin = start;
                end = i;
            }

            destHash[s[start]]--;
            found--;

            start++;//向右收缩;
        }

    }

    return begin == -1 ? "" : s.substr(begin, end + 1);

}


string minWindow_2(string s, string t) {
    if (t.size() > s.size()) return "";
    string res = "";
    int left = 0, count = 0, minLen = s.size() + 1;
    int tm[256] = {0}, sm[256] = {0};

    for (int i = 0; i < t.size(); i++) tm[t[i]]++;

    for (int right = 0; right < s.size(); right++) {
        if (tm[s[right]] != 0) {
            ++sm[s[right]];
            if (sm[s[right]] <= tm[s[right]]) ++count;
            while (count == t.size()) {
                if (right - left + 1 < minLen) {
                    minLen = right - left + 1;
                    res = s.substr(left, minLen);
                }

                if (tm[s[left]] != 0) {
                    sm[s[left]]--;
                    if (sm[s[left]] < tm[s[left]]) count--;
                }

                ++left; //向右收缩
            }
        }
    }
    return res;
}
/*

int main() {

    string s = "aabbcdcba";
//    string s = "abc";
    string t = "b";
    string result = minWindow(s, t);
    cout << result << endl;

    string result_2 = minWindow_2(s, t);
    cout << result_2 << endl;


//    for(int i =0;i<3;++i){
//        cout<<i<<endl;
//    }

//    string name = "guoo";
//    cout << name.substr(0, 2) << endl;

    return 0;
}*/

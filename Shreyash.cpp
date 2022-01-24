#include<bits/stdc++.h>
using namespace std;
#define int long long

vector<vector<int>> v = {
//   0  1  2  3  4  5  6
    {6, 1, 2, 6, 6, 6, 6}, // 0
    {6, 6, 6, 3, 6, 6, 6}, // 1
    {6, 6, 6, 3, 6, 6, 6}, // 2
    {6, 6, 6, 3, 4, 5, 6}, // 3
    {6, 6, 6, 6, 6, 6, 6}, // 4
    {6, 6, 2, 6, 6, 6, 6}, // 5
    {6, 6, 6, 6, 6, 6, 6}, // 6
};

signed main(){
    string s;
    cout << "Enter string: ";
    getline(cin, s);
    cout << s << "\n";
    int state = 0;
    int input = 0;
    int i = 0;
    int n = s.size();
    int flag = 0;
    while(i < n){
        if((i + 11 < n && "http://www." == s.substr(i,11)) || (i + 12 < n && "https://www." == s.substr(i,12))){
            if("http://www." == s.substr(i,11))
            {
                input = 1;
                i += 11;
                state = v[state][input];
                flag = 1;
            }
            else if("https://www." == s.substr(i,12)){
                input = 1;
                i += 12;
                state = v[state][input];
                flag = 1;
            }
        }
        else if((".com" == s.substr(i,4)) || (".org" == s.substr(i,4)) || (".in" == s.substr(i,3))){
            if((".com" == s.substr(i,4)) || (".org" == s.substr(i,4))){
                i = i + 4;
                input = 4;
                state = v[state][input];
            }
            else if(".in" == s.substr(i,3)){
                i += 3;
                input = 4;
                state = v[state][input];
            }
        }
        else if(s[i] >= 'A' && s[i] <= 'Z'){
            input = 2;
            i++;
            state = v[state][input];
        }
        else if(s[i] >= 'a' && s[i] <= 'z'){
            i++;
            input = 3;
            state = v[state][input];
        }
        else if(s[i] == ' '){
            i++;
            input = 5;
            state = v[state][input];
        }
        else{
            i++;
            input = 6;
            state = v[state][input];
        }
    }
    if(state == 4 && flag) cout << "It's a web url\n";
    else if(state == 3 && !flag) cout << "It's a Name\n";
    else cout << "It's neither web url nor a person's name\n";
}
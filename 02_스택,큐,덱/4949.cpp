#include <iostream>
#include <string>
#include <stack>

using namespace std;

bool check(string& str){
    stack<char> s;
    for(char c: str){
        if(c=='(' || c=='['){
            s.push(c);
        }
        else if(c==')'){
            if(s.empty() || s.top()!='(') return false;
            s.pop();
        }
        else if(c==']'){
            if(s.empty() || s.top()!='[') return false;
            s.pop();
        }
    }

    if(s.empty()) return true;
    else return false;
}

int main(){
    while(true){
        string str;
        getline(cin, str);  // 한 줄 전체를 읽음
        if (str == "."){    // 온점 하나만 있으면 종료
            return 0;
        }

        if(check(str)) cout << "yes" << "\n";
        else cout << "no" << "\n";
    }
    return 0;
}
#include <iostream>
#include <unordered_map>
#include <string>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);  // C와 C++ 입출력 동기화 해제
    cin.tie(NULL); cout.tie(NULL);     // cin과 cout 연결 해제
    
    int m, n;
    unordered_map<string, int> name;
    unordered_map<int, string> num;
    string input;

    cin >> m >> n;

    for(int i=1; i<=m; i++){
        cin >> input;
        name[input] = i;
        num[i] = input;
    }

    for(int i=0; i<n; i++){
        cin >> input;

        if(isdigit(input[0])){ //isdigit(): 문자가 숫자인지 확인하는 함수(숫자면 true)
            cout << num[stoi(input)] << '\n'; //숫자면 번호로 조회
        }else{
            cout << name[input] << '\n'; //문자면 이름으로 조회
        }
    }

    return 0;
}
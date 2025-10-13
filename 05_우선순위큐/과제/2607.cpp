#include <iostream>
#include <string>
#include <cmath>

using namespace std;

bool isSimilar(string first, string word){
    int count1[26] = {0};
    int count2[26] = {0};
    
    // 각 문자의 개수 세기
    for(char c : first){
        count1[c - 'A']++;
    }
    
    for(char c : word){
        count2[c - 'A']++;
    }
    
    // 차이나는 문자 수
    int diff = 0;
    for(int i = 0; i < 26; i++){
        diff += abs(count1[i] - count2[i]);
    }
    
    // 비슷한 단어 조건
    // 1. 같은 구성: diff == 0
    // 2. 한 문자 추가/제거: diff == 1 && 길이차이 == 1  
    // 3. 한 문자 교체: diff == 2 && 길이 같음
    
    int lenDiff = abs((int)first.length() - (int)word.length());
    
    if(diff == 0) return true; // 같은 구성
    if(diff == 1 && lenDiff == 1) return true; // 한 문자 추가/제거
    if(diff == 2 && lenDiff == 0) return true; // 한 문자 교체
    
    return false;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n;
    cin >> n;
    
    string first;
    cin >> first;
    n--;
    
    int result = 0;
    
    while(n--){
        string word;
        cin >> word;
        
        if(isSimilar(first, word)){
            result++;
        }
    }
    
    cout << result << "\n";
    
    return 0;
}

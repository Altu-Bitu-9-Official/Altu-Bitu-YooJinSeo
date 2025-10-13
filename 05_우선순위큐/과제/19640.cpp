#include <iostream>
#include <queue>
#include <vector>

using namespace std;

struct Person {
    int d; // 근무 일수
    int h; // 화장실이 급한 정도  
    int lineIdx; // 몇 번째 줄
    int originalIdx; // 원래 전체 순서
};

struct Compare {
    bool operator()(const Person& a, const Person& b) {
        if(a.d != b.d) return a.d < b.d; // 근무 일수 높은 순
        if(a.h != b.h) return a.h < b.h; // 화장실 급한 정도 높은 순
        return a.lineIdx > b.lineIdx; // 줄 번호 작은 순
    }
};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n, m, k;
    cin >> n >> m >> k;
    
    vector<queue<Person>> lines(m);
    priority_queue<Person, vector<Person>, Compare> pq;
    
    // 각 줄 사람들 입력
    for(int i = 0; i < n; i++){
        int d, h;
        cin >> d >> h;
        int line = i % m;
        Person p = {d, h, line, i}; 
        lines[line].push(p);
    }
    
    // 각 줄 맨 앞 사람 pq.push()
    for(int i = 0; i < m; i++){
        if(!lines[i].empty()){
            pq.push(lines[i].front());
            lines[i].pop();
        }
    }
    
    int order = 0;
    
    while(!pq.empty()){
        Person current = pq.top();
        pq.pop();
        
        // 도현: k
        if(current.originalIdx == k){
            cout << order << "\n";
            return 0;
        }
        
        order++;
        
        // 해당 줄 다음 사람 pq.push()
        if(!lines[current.lineIdx].empty()){
            pq.push(lines[current.lineIdx].front());
            lines[current.lineIdx].pop();
        }
    }
    
    return 0;
}

#include <iostream>
#include <queue>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n;
    cin >> n;
    
    // 최소힙을 사용해서 n개만 유지 (n번째 큰 수를 찾기 위해)
    priority_queue<int, vector<int>, greater<int>> pq; // 최소힙
    
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            int x;
            cin >> x;
            
            if(pq.size() < n){
                pq.push(x);
            }
            else if(pq.top() < x){
                pq.pop();
                pq.push(x);
            }
        }
    }
    
    cout << pq.top() << "\n";
    
    return 0;
}

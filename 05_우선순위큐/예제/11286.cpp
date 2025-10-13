#include <iostream>
#include <queue>

using namespace std;

struct cmp {
    bool operator()(const int &parent, const int &child){
        if(abs(child)!=abs(parent)){
            return abs(parent) > abs(child);
        }
        return parent > child;
    }
};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, x;
    cin >> n;

    priority_queue<int, vector<int>, cmp> pq;

    while(n--){
        cin >> x;
        switch (x)
        {
        case 0:
            //삭제
            if(!pq.empty()){
                cout << pq.top() << "\n";
                pq.pop();
            } else{
                cout << 0 << "\n";
            }
            break;
        
        default:
            //삽입
            pq.push(x);
            break;
        }
    }
    return 0;
}
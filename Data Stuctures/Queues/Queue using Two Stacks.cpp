#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;


int main() {
    int q;
    cin >> q;

    queue<int> myqueue;
    for(int i=0,a;i<q;i++){
        cin >> a;

        if(a == 1){
            int b;
            cin >> b;
            myqueue.push(b);
        }
        else if(a == 2 and !myqueue.empty())
            myqueue.pop();
        else if(a == 3)
            cout << myqueue.front() << endl;
    }

    return 0;
}

#include <string>
#include <vector>
#include <stack>
#include <iostream>

using namespace std;

struct Node{
    bool isDeleted;

    int up;
    int down;
};

vector<Node> v;
stack<int> s;

string solution(int n, int k, vector<string> cmd) {
    string answer = "";

    v.push_back({0, 0, 1});
    for(int i=1; i<n-1; ++i){
        v.push_back({0, i-1, i+1});
    }
    v.push_back({0, n-2, n-1});

    for(auto c:cmd){
        //printf("k:%d  up:%d  down:%d cmd:%c\n", k, v[k].up, v[k].down, c[0]);
        if(c[0]=='U'){
            int move = c[2] - 48;
            while(move-- > 0){
                k = v[k].up;
            }
        }
        else if(c[0]=='D'){
            int move = c[2] - 48;
            while(move-- > 0){
                k = v[k].down;
            }
        }
        else if(c[0]=='C'){
            v[k].isDeleted = 1;
            s.push(k);
            if(k==v[k].down){
                k = v[k].up;
                v[k].down = k;
            }
            else if(k==v[k].up){
                k = v[k].down;
                v[k].up = k;
            }
            else{
                v[v[k].down].up = v[k].up;
                v[v[k].up].down = v[k].down;
                k = v[k].down;
            }
        }
        else if(c[0]=='Z'){
            int z = s.top();
            s.pop();
            v[z].isDeleted = 0;

            int u = v[z].up;
            int d = v[z].down;
            //printf("%d %d \n", v[z].up, v[z].down);
            while(v[u].isDeleted){
                if(v[u].up == u) break;
                u--;
            }
            while(v[d].isDeleted){
                if(v[d].down == d) break;
                d++;
            }
            //printf("    Z: %d %d %d\n",z, u, d);
            v[u].down = z;
            v[z].up = u;

            if(d!=z)
                v[d].up = z;
            v[z].down = d;
        }
    }
    //printf("%d ", k);

    for(auto node:v){
        if(node.isDeleted)
            answer += 'X';
        else
            answer += 'O';
    }

    return answer;
}

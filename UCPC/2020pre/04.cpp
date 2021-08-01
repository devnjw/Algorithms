#include <iostream>
#define MAXSIZE 300001

using namespace std;

struct Node{
  int data;
  Node * next;
};

Node * arr[MAXSIZE];
int visited[MAXSIZE];
int cntArr[MAXSIZE];
int N;
long long D, G;

void Print(){
  cout << "---Printing---\n";
  for(int i=1; i<=N; ++i){
    Node * curr = arr[i];
    while(curr->next != nullptr){
      curr = curr->next;
      cout << i << " " << curr->data << endl;
    }
  }
  cout << "-----End-----\n";
}

void DFS(int depth, int s){
  if(depth==3){
    D++;
    return;
  }
  for(int i=s+1; i<=N; ++i){
    Node * curr = arr[s];
    while(curr->next != nullptr){
      curr = curr->next;
      if(curr->data==i && visited[i]==0){
        visited[i] = 1;
        DFS(depth + 1, i);
        visited[i] = 0;
      }
    }
  }
}

int main(){
  cin >> N;

  for(int i=1; i<=N; ++i){
    Node * newNode = new Node();
    newNode->data = i;
    newNode->next = nullptr;
    arr[i] = newNode;
  }

  for(int i=0; i<N-1; ++i){
    int a, b;
    cin >> a >> b;
    cntArr[a]++;
    cntArr[b]++;

    Node * newNode = new Node();
    newNode->next = nullptr;

    newNode->data = b;
    Node * curr = arr[a];
    while(curr->next != nullptr) curr = curr->next;
    curr->next = newNode;
  }

  // for(int i=1; i<=N; ++i){
  //   visited[i] = 1;
  //   DFS(0, i);
  //   visited[i] = 0;
  // }

  // long long T = N*(N-1)*(N-2)*(N-3)/24;

  for(int i=1; i<=N; ++i){
    if(cntArr[i]>=3)
      G += cntArr[i]*(cntArr[i]-1)*(cntArr[i]-2)/6;
  }

  if(G==0) D = 1;
  else if(N == 4) D = 0;
  else if((N-3)/3==G) D = G*3;
  else if((N-3)/3<G) D = G*3 + 1;
  else D = G*3 - 1;

  // D = T - G;

  // cout << "\n" << T << ":" << D << ":" << G << endl;

  if(D>G*3) cout << "D";
  else if(D<G*3) cout << "G";
  else cout << "DUDUDUNGA";

  for(int i=1; i<=N; ++i){
    Node * curr = arr[i];
    while(curr != nullptr){
      Node * temp = curr;
      curr = curr->next;
      free(temp);
    }
  }

  return 0;
}

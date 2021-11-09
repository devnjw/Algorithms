#include <iostream>
#include <unordered_map>

using namespace std;

struct Node{
  int data;
  Node *next;
};

int N, d, M;
int cnt[100001];

Node * root;
unordered_map<int, int> hsmap;

int main(){
  root = (Node*)malloc(sizeof(Node));
  root->data = 0;
  root->next = NULL;

  cin >> N >> d >> M;
  d++;

  int tmp;
  for(int i=0; i<M; ++i){
    cin >> tmp;
    if(hsmap.count(tmp)){
      hsmap[tmp]++;
    }
    else{
      hsmap[tmp] = 1;
      Node * new_node = (Node*)malloc(sizeof(Node));
      new_node->data = tmp;

      Node * tmp_node = root;
      while(tmp_node->next!=NULL && tmp_node->next->data < tmp){
        tmp_node = tmp_node->next;
      }
      new_node->next = tmp_node->next;
      tmp_node->next = new_node;
    }
    cnt[tmp]++;
  }

  int mn, mx=0;
  for(int i=0; i<=N; ++i)
    if(cnt[i] > mx) mx = cnt[i];
  mn = mx%d > 0 ? mx/d+1 : mx/d;
  int mid = (mn+mx)/2;

  while(mn < mx){
    int lefts = 0;

    Node * tmp_node = root->next;
    while(tmp_node != NULL){
      cout << tmp_node->data << "(" << hsmap[tmp_node->data] << ") -> ";
      tmp_node = tmp_node->next;
    }
    cout << endl;

    for(int i=0; i<=N; ++i){
      if((lefts+cnt[i])/float(d) > mid){
        lefts = 1;
        break;
      }
      lefts = lefts + cnt[i] - mid;
      if(lefts<0) lefts=0;
    }

    if(lefts)
      mn = mid+1;
    else
      mx = mid;

    mid = (mn+mx)/2;
  }

  cout << mid;

  return 0;
}

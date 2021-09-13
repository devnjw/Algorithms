#include <string>
#include <vector>

using namespace std;

struct Node{
    int data;
    int index;
    Node *left;
    Node *right;
};

vector<Node *> v;

int answer;
int cnt;

int DFS(Node * node, int p){
    printf("%d - ", node->index);

    int point = node->data;;
    p += node->data;
    node->data = 0;

    if(p==0) return 0;

    if(node->left!=NULL)
        point += DFS(node->left, p);
    if(node->right!=NULL)
        point += DFS(node->right, p);

    return point;
}

int solution(vector<int> info, vector<vector<int>> edges) {

    for(int i=0; i<info.size(); ++i){
        Node * new_node = (Node*)malloc(sizeof(Node));
        if(info[i])
            new_node->data = -1;
        else
            new_node->data = 1;
        new_node->index = i;
        new_node->right = NULL;
        new_node->left = NULL;
        v.push_back(new_node);
    }

    for(auto edge:edges){
        if(v[edge[0]]->left==NULL)
            v[edge[0]]->left = v[edge[1]];
        else
            v[edge[0]]->right = v[edge[1]];
    }

    v[0]->data = 0;
    int r_point = 1;
    int l_point = 1;

    while(r_point || l_point){
        int r, l;
        if(v[0]->left!=NULL)
            l = DFS(v[0]->left, r_point);
        if(v[0]->right!=NULL)
            r = DFS(v[0]->right, l_point);
        printf("l&r: %d %d\n", l, r);
        r_point = r;
        l_point = l;
    }


    return answer;
}

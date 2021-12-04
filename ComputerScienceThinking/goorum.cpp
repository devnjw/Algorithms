#include <iostream>
#include <vector>
#define MAX_N 10000

using namespace std;

int N, M;
int s, e;
// vector<int> arr[MAX_N+1];
// vector<int> W[MAX_N+1];

int arr[MAX_N+1][MAX_N+1];

int visited[MAX_N+1];
int check[MAX_N+1][MAX_N+1];

long long max_len;
vector<pair<int, int > > v;

void DFS(int curr, long long length, vector<pair<int, int > > &tmp){
	if(curr == e){
		if(length > max_len){
			for(int i=0; i<v.size(); ++i)
				check[v[i].first][v[i].second] = 0;
			v.clear();
		}
		if(length >= max_len){
			max_len = length;
			for(int i=0; i<tmp.size(); ++i){
				if(check[tmp[i].first][tmp[i].second]==0){
					check[tmp[i].first][tmp[i].second] = 1;
					v.push_back(tmp[i]);
				}
			}
		}
		return;
	}

	for(int i=1; i<=N; ++i){
		if(arr[curr][i] && visited[i]==0){
			visited[i] = 1;
			tmp.push_back(make_pair(curr, i));
			DFS(i, length + arr[curr][i], tmp);
			tmp.pop_back();
			visited[i] = 0;
		}
	}

// 	for(int i=0; i<arr[curr].size(); ++i){
// 		if(visited[arr[curr][i]]==0){
// 			visited[arr[curr][i]] = 1;
// 			tmp.push_back(make_pair(curr, arr[curr][i]));

// 			DFS(arr[curr][i], length + W[curr][i], tmp);

// 			tmp.pop_back();
// 			visited[arr[curr][i]] = 0;
// 		}
// 	}
}

int main() {
	cin >> N >> M;

	int a, b, w;
	for(int i=0; i<M; ++i){
		cin >> a >> b >> w;
		arr[a][b] = w;
		// arr[a].push_back(b);
		// W[a].push_back(w);
	}

	cin >> s >> e;

	vector<pair<int, int > > tmp;
	visited[s] = 1;
	DFS(s, 0, tmp);

	cout << max_len << "\n" << v.size();

	return 0;
}

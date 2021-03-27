#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

unordered_map<string, int> hsmap;

int arr[20000][20000];

int N;
int visited[20000];
long long answer = 100000000000;
long long curr;
int SIZE;

void DFS(int depth, int prev){
	if(depth == SIZE){
		if(answer > curr) answer = curr;
		return;
	}

	for(int i=0; i<SIZE; ++i){
		if(visited[i]==0){
			visited[i] = 1;
			curr += arr[prev][i];
			if(curr < answer)
				DFS(depth + 1, i);
			curr -= arr[prev][i];
			visited[i] = 0;
		}
	}
}

int main() {
	vector < vector <int> > costs;

	cin >> N;
	for(int i=0; i<N; i++){
		string city1, city2;
		cin >> city1 >> city2;
		int cost;
		cin >> cost;

		if(!hsmap.count(city1))
			hsmap.insert({city1, hsmap.size()});
		if(!hsmap.count(city2))
			hsmap.insert({city2, hsmap.size()});

		arr[hsmap[city1]][hsmap[city2]] = arr[hsmap[city2]][hsmap[city1]] = cost;
	}

	SIZE = hsmap.size();

	for(int i=0; i<SIZE; ++i){
		visited[i] = 1;
		DFS(1, i);
		visited[i] = 0;
	}

	cout << answer;

	return 0;
}

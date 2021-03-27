#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

unordered_map<string, int> hsmap;

int N;
int visited[10000];

int main() {
	long long answer = 0;
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

		costs.push_back({hsmap[city1], hsmap[city2], cost});
	}

	visited[0] = 1;
	while(*min_element(visited, visited + hsmap.size())==0){
			int mindex = 0;
			int minval = 1000000;
			for(auto it:costs){
					if(visited[it[0]] && visited[it[1]])
							continue;
					else if(visited[it[0]] && minval > it[2]){
							minval = it[2];
							mindex = it[1];
					}
					else if(visited[it[1]] && minval > it[2]){
							minval = it[2];
							mindex = it[0];
					}
			}
			visited[mindex] = 1;
			answer += minval;
	}

	cout << answer;

	return 0;
}

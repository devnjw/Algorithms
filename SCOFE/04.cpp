#include <vector>
#include <unordered_map>
#include <iostream>
#include <queue>
#include <algorithm>
#include <string.h>

using namespace std;

unordered_map<char, float> hsmap;

struct Content{
	int y;
	int x;
	char type;
	char genre;
};

int N, M;

bool cmp(const Content &c1, const Content &c2){
	if(c1.type < c2.type)
		return false;
	else if(c1.type == c2.type){
		if(hsmap[c1.genre] < hsmap[c2.genre])
			return false;
		else if(hsmap[c1.genre] == hsmap[c2.genre]){
			if(c1.y > c2.y) return false;
			else if(c1.y == c2.y){
				if(c1.x > c2.x) return false;
				else return true;
			}
			else return true;
		}
		else
			return true;
	}
	else return true;
}

int main() {
	char genres[5] = {'A', 'B', 'C', 'D', 'E'};
	for(auto genre:genres){
		float p;
		cin >> p;
		hsmap[genre] = p;
	}

	vector<Content> contents;
	cin >> N >> M;
	for(int i=0; i<N; ++i){
		for(int j=0; j<M; ++j){
			char type;
			cin >> type;
			contents.push_back({i, j, type});
		}
	}
	for(int i=0; i<N; ++i){
		for(int j=0; j<M; ++j){
			char genre;
			cin >> genre;
			contents[i*M+j].genre = genre;
		}
	}

	sort(contents.begin(), contents.end(), cmp);

	for(auto cont:contents)
		if(cont.type != 'W')
			printf("%c %.1f %d %d\n", cont.genre, hsmap[cont.genre], cont.y, cont.x);

	return 0;
}

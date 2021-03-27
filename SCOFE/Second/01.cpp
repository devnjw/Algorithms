#include <iostream>
#include <vector>
#include <sstream>
#include <string>

using namespace std;

vector<string> split(string input, char delimiter) {
    vector<string> answer;
    stringstream ss(input);
    string temp;
    while (getline(ss, temp, delimiter)) {
        answer.push_back(temp);
    }
    return answer;
}

int TtoS(string time){
	vector<string> output = split(time, ':');
	if(output.size() == 3){
		int H = stoi(output[0]);
		int M = stoi(output[1]);
		int S = stoi(output[2]);
		return H*60*60 + M*60 + S;
	}
	else if(output.size() == 2){
		int M = stoi(output[0]);
		int S = stoi(output[1]);
		return M*60 + S;
	}
}

int N;
int arr[100001];

int main() {
	string temp;

	cin >> N;
	cin >> temp;

	int trainT = TtoS(temp);
	int startT = 1;
	int currT = 0;
	int cnt = 0;
	int maxcnt = 0;
	int maxT = 1;

	for(int i=1; i<=N; ++i){
		cin >> temp;
		int T = TtoS(temp);
		arr[i] = T;

		while(currT >= trainT){
			currT -= arr[startT];
			startT++;
			cnt--;
		}

		currT += T;
		cnt++;
		if(maxcnt < cnt){
			maxcnt = cnt;
			maxT = startT;
		}
	}

	cout << maxcnt << " " << maxT;

	return 0;
}

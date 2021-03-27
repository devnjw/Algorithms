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

int main() {
	int N;
	cin >> N;
	int sH = 0, sM = 0, eH = 23, eM = 59;
	for(int i=0; i<N; ++i){
		string str;
		cin >> str;
		vector<string> temp = split(str, ':');
		if(stoi(temp[0])>sH){
			sH = stoi(temp[0]);
			sM = stoi(temp[1]);
		}
		else if(stoi(temp[0])==sH && stoi(temp[1]) > sM) sM = stoi(temp[1]);

		cin >> str;

		cin >> str;
		temp = split(str, ':');
		if(stoi(temp[0])<eH){
			eH = stoi(temp[0]);
			eM = stoi(temp[1]);
		}
		else if(stoi(temp[0])==eH && stoi(temp[1]) < eM) eM = stoi(temp[1]);

	}
	if(sH > eH)
		printf("-1");
	else if(sH == eH && sM > eM)
		printf("-1");
	else
		printf("%02d:%02d ~ %02d:%02d", sH, sM, eH, eM);
	return 0;
}

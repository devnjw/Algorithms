#include <iostream>
#include <vector>

using namespace std;

long long Hash(string str, int s){
	long long h = 0, power = 1;
	for(int i=s-1; i>= 0; i--){
		h += str[i] * power;
		power *= 2;
	}
	return h;
}

bool Search(string str, string keyword){
	int s = keyword.size();
	int strSize = str.size();

	long long strHash = Hash(str, s);
	long long keyHash = Hash(keyword, s);
	int power = 1 << (s - 1);

	for(int i=0; i <= strSize - s; ++i){
		if(i!=0){
			long long rmValue = str[i-1] * power;
			long long newValue = str[i-1+s];
			strHash = 2 * (strHash - rmValue) + newValue ;
		}

		if(strHash == keyHash){
			for(int j=0; j<s; ++j){
				if(str[i+j] != keyword[j])
					return false;
			}
			return true;
		}
	}

	return false;
}

int N, Q;

int main() {
	vector<string> v;

	cin >> N;
	for(int i=0; i<N; ++i){
		string str;
		cin >> str;
		v.push_back(str);
	}

	cin >> Q;
	for(int i=0; i<Q; ++i){
		string str;
		cin >> str;
		int cnt = 0;
		for(auto it : v){
			cnt += Search(it, str);
		}
		cout << cnt << endl;
	}
	return 0;
}

// stable_sort() 써야됨.

#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

bool isDigit(char c){
    if(c <= '9' && c >= '0')
        return true;
    return false;
}

bool cmp(string a, string b){
    int numA, numB;
    string strA, strB;
    for(int i=0, j=0; i<a.size(); ++i){
        if(isDigit(a[i])){
            strA = a.substr(0, i);
            while(isDigit(a[i+j]))
                j++;
            numA = stoi(a.substr(i, j));
            break;
        }
        else{
            a[i] = toupper(a[i]);
        }
    }
    for(int i=0, j=0; i<b.size(); ++i){
        if(isDigit(b[i])){
            strB = b.substr(0, i);
            while(isDigit(b[i+j]))
                j++;
            numB = stoi(b.substr(i, j));
            break;
        }
        else{
            b[i] = toupper(b[i]);
        }
    }
    if(strA == strB)
        return numA < numB;
    else
        return strA < strB;
}

vector<string> solution(vector<string> files) {
    stable_sort(files.begin(), files.end(), cmp);
    return files;
}

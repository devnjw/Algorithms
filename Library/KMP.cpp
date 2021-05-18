// return start index
int KMP(string str, string key){
    for(int i=0; i<str.size(); ++i){
        if(str[i]==key[0]){
            for(int j=1; j<key.size(); ++j){
                if(str[++i]!=key[j]) break;
                else if(j==key.size()-1) return i - j;
            }
        }
    }

    return -1;
}

#include <iostream>
using namespace std;

int N;
int arr[200][3];

void search(int r, int c){
  int isDuplicate = 0;
  for(int i=r+1; i<N; i++){
    if(arr[r][c]==arr[i][c]){
      arr[i][c] = 0;
      isDuplicate = 1;
    }
  }
  if(isDuplicate) arr[r][c] = 0;
}

int main() {
  cin >> N;
  for(int i=0; i<N; i++)
    for(int j=0; j<3; j++)
      cin >> arr[i][j];

  for(int i=0; i<N; i++)
    for(int j=0; j<3; j++){
      search(i, j);
    }

  for(int i=0; i<N; i++){
    int result = 0;
    for(int j=0; j<3; j++)
      result += arr[i][j];
    cout << result << endl;
  }

}

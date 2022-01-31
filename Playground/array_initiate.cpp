#include <iostream>

#define SIZE 3

using namespace std;

int global_1d_arr[SIZE];
int global_1d_arr_filled[SIZE];
int global_2d_arr[SIZE][SIZE];
int global_2d_arr_filled[SIZE][SIZE];

int main(){
  int local_1d_arr[SIZE];
  int local_2d_arr[SIZE][SIZE];
  int local_2d_arr_filled[SIZE][SIZE];

  fill(global_2d_arr_filled[0], global_2d_arr_filled[0]+SIZE*SIZE, -1);

  printf("Global 1d arr: ");
  for(int i=0; i<SIZE; ++i){
    printf("%d ", global_1d_arr[i]);
  }
  printf("\n\n");

  printf("Global 1d arr filled: ");
  for(int i=0; i<SIZE; ++i){
    printf("%d ", global_1d_arr_filled[i]);
  }
  printf("\n\n");

  printf("Global 2d arr: ");
  for(int i=0; i<SIZE; ++i){
    for(int j=0; j<SIZE; ++j)
      printf("%d ", global_2d_arr[i][j]);
  }
  printf("\n\n");

  printf("Global 2d arr filled with -1: ");
  for(int i=0; i<SIZE; ++i){
    for(int j=0; j<SIZE; ++j)
      printf("%d ", global_2d_arr_filled[i][j]);
  }
  printf("\n\n");

  printf("Local 1d arr: ");
  for(int i=0; i<SIZE; ++i){
    printf("%d ", local_1d_arr[i]);
  }
  printf("\n\n");

  printf("Local 2d arr: ");
  for(int i=0; i<SIZE; ++i){
    for(int j=0; j<SIZE; ++j)
      printf("%d ", local_2d_arr[i][j]);
  }
  printf("\n\n");

  printf("Local 2d arr filled with -1: ");
  for(int i=0; i<SIZE; ++i){
    for(int j=0; j<SIZE; ++j)
      printf("%d ", local_2d_arr_filled[i][j]);
  }
  printf("\n\n");

  return 0;
}

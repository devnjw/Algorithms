#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SUB_N 3
#define STU_N 5
void evalClass(int scores[STU_N][SUB_N], int i, int* s, float* a);
void evalStudent(int scores[STU_N][SUB_N], int i, int* s, float* a, char* g);

int main(void) {
  int scores[STU_N][SUB_N];        // scores
  char *classname[SUB_N]={"Korean","English","Math"};
  int sum;                // total sum
  float avg;              // average
  char grade;             // grade
  int i, j;               // for loops
  FILE* fp = fopen("data.txt", "r");

  // implement here

	while(!feof (fp)){
		for(int i=0; i<STU_N; ++i){
			for(int j=0; j<SUB_N; ++j)
			fscanf(fp, "%d", &scores[i][j]);
		}
	}


  for(i=0; i<STU_N; i++){
    printf("Student %d: ",i+1);
    for(j=0; j<SUB_N; j++){

      printf("%s %d", classname[j], scores[i][j]);
      if(j<SUB_N-1) printf(", ");
      else printf("\n");
    }
  }

  printf("1) Total and average scores for each subject\n");
  for(i=0; i<SUB_N; i++){
    evalClass(scores, i, &sum, &avg);
    printf("%s: %d and %.1f\n", classname[i], sum, avg);
  }

  printf("2) The total and average scores, and grade for each student\n");
  for(i=0; i<STU_N; i++){
    evalStudent(scores, i, &sum, &avg, &grade);
    printf("Student %d: %d and %.1f(grade %c)\n",i+1, sum, avg, grade);
  }

  return 0;
}

void evalClass(int scores[STU_N][SUB_N], int i, int* s, float* a){
	*s = 0;
	for(int j=0; j<STU_N; ++j){
		*s += scores[j][i];
	}
	*a = *s / STU_N;
}

void evalStudent(int scores[STU_N][SUB_N], int i, int* s, float* a, char* g){
	*s = 0;
	for(int j=0; j<SUB_N; ++j){
		*s += scores[i][j];
	}
	*a = *s / (float)SUB_N;
	if(*a >= 90) *g = 'A';
	else if(*a >= 80) *g = 'B';
	else if(*a >= 70) *g = 'C';
	else if(*a >= 60) *g = 'D';
	else *g = 'F';
}

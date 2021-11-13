#include <stdio.h>
float evalBmi(int h, int w);

int main(void) {
  float height, weight, bmi;
  int count=0;
  FILE* fp = fopen("data.txt", "r");

	char line[20];

	int i=1;
	while(!feof (fp)){
		printf("Person %d: height (cm) and weight (kg): ", i++);
		fscanf(fp, "%f %f", &height, &weight);
		printf("%.f %.f\n", height, weight);
		bmi = weight*10000 / (height*height);
		if(bmi >= 25)
			count++;
	}

  fclose (fp);

  printf("%d people are obese.\n", count);
  return 0;
}

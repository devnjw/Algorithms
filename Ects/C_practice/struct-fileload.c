#include <stdio.h>
#include <stdlib.h>

struct st_point{
    float x;
    float y;
};

int load_points(struct st_point* list[], char* filename);
int get_position(struct st_point* p);

int main()
{
    struct st_point* mypoint[50];
    char* ordinals[4]={"st", "nd", "rd", "th"};
    int size;
    int count[5]={0};
    int i, pos;
    char filename[100] = "point.txt";

    size = load_points(mypoint, filename);
    for(i=0; i<size; i++){
        pos = get_position(mypoint[i]);
        count[pos]++;
    }
    printf("%d points from %s.\n", size, filename);

    printf("On axes: %d points\n", count[0]);
    for(i=1; i<=4; i++)
        printf("In the %d%s quadrant: %d points\n", i, ordinals[i-1], count[i]);

    return 0;
}

int load_points(struct st_point* list[], char* filename){
	FILE *fp = fopen(filename, "r");
	int size=0;
	while(!feof(fp)){
		struct st_point* p = (struct st_point*)malloc(sizeof(struct st_point));
		fscanf(fp, "%f %f", &p->x, &p->y);
		list[size] = p;
		size++;
	}
	fclose(fp);
	return size;
}

int get_position(struct st_point* p){
	int position;
	if(p->x > 0 && p->y > 0)
		position = 1;
	else if(p->x < 0 && p->y > 0)
		position = 2;
	else if(p->x < 0 && p->y < 0)
		position = 3;
	else if(p->x > 0 && p->y < 0)
		position = 4;
	else
		position = 0;
	return position;
}

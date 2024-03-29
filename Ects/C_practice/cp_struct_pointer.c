#include <stdio.h>
#include <stdlib.h>

struct st_menu{
    int no; 				    // menu number
    char name[20]; 		  // menu name
    char made_in[20]; 	// origin
    int price; 				  // price
};

struct st_menu* get_menu();
void save_menu(struct st_menu* list[], char* filename, int size);

int main()
{
    struct st_menu* menu[10]; 	// at most 10 menus
    char filename[100] = "menu.txt";
    int count = 5;
    int i;

    for(i=0; i<count; ++i){
        printf("Menu %d:\n", i+1);
				menu[i] = (struct st_menu*)malloc(sizeof(struct st_menu*));
        *menu[i] = *get_menu();
    }

    save_menu(menu, filename, count);
    printf("Saved it to %s.\n", filename);

    return 0;
}

struct st_menu* get_menu(){
	printf("Enter the menu number, menu name, country of origin, and price. ");
	struct st_menu* m = (struct st_menu*)malloc(sizeof(struct st_menu*));
	scanf("%d %s", &m->no, m->name);
	scanf("%s %d", m->made_in, &m->price);
	return m;
}

void save_menu(struct st_menu* list[], char* filename, int size){
	FILE *fp = fopen(filename, "w");

	for(int i=0; i<size; ++i){
		fprintf(fp, "%d %s %s %d\n", list[i]->no, list[i]->name, list[i]->made_in, list[i]->price);
	}
	for(int i=0; i<size; ++i){
		free(list[i]);
	}
}

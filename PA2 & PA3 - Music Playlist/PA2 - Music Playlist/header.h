#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include <time.h>



#define LOAD 1
#define STORE 2
#define DISPLAY 3
#define INSERT 4
#define DELETE 5
#define EDIT 6
#define SORT 7
#define RATE 8
#define PLAY 9
#define SHUFFLE 10
#define EXIT 11


#define ARTIST 1
#define ALBUM 2
#define SONG 3
#define GENRE 4
#define MINS 5
#define SECS 6
#define TIMESPLAYED 7
#define RATING 8 

#define RATING2 3
#define TIMESPLAYED2 4

typedef struct duration
{
	int minutes;
	int seconds;
}DURATION;

typedef struct record
{
	char artist[20];
	char album[25];
	char song[25];
	char genre[20];
	DURATION song_length;
	int times_played;
	int rating;						//1-5
	int rand;
	int number;
} RECORD;


typedef struct node
{
	RECORD data;
	struct node *pNext;
	struct node *pPrev;
} NODE;

void printmenu();
NODE * makenode(RECORD record);
int insertfront(NODE **pList, RECORD record);
void printlisttofile(NODE *pList, FILE * outfile, RECORD record[]);

void searchArtistDisplay(NODE *pList, RECORD record[]);
void searchArtistEdit(NODE *pList, RECORD record[]);
void rate(NODE *pList, RECORD record[]);
void play(NODE *pList, RECORD record[]);
void edit_attribute(NODE *pCur, int attribute);
void print_records_to_screen(NODE *pCur);
void print_attribute_menu();

void searchArtistEdit(NODE *pList, RECORD record[]);
void edit_attribute(NODE *pCur, int attribute);
void print_records_to_screen(NODE *pCur);
void rate(NODE *pList, RECORD record[]);
void play(NODE *pList, RECORD record[]);
void insert_new_node(NODE **pList, RECORD record[], int i);
void deleteNode(NODE **pList, RECORD record[]);
void sort(NODE **pList, RECORD record[]);
void shuffle(NODE * pList, RECORD record[]);


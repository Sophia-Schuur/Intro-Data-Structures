#include "header.h"

//print home menu
void printmenu()
{
	printf("1. LOAD \n");
	printf("2. STORE \n");
	printf("3. DISPLAY \n");
	printf("4. INSERT \n");
	printf("5. DELETE \n");
	printf("6. EDIT \n");
	printf("7. SORT \n");
	printf("8. RATE \n");
	printf("9. PLAY \n");
	printf("10. SHUFFLE \n");
	printf("11. EXIT \n");
}

//allocate memory for a node
NODE * makenode(RECORD record)
{
	NODE *pMem = NULL;
	
	pMem = (NODE *)malloc(sizeof(NODE));

	if (pMem != NULL)
	{
		strcpy(pMem->data.artist, record.artist);
		strcpy(pMem->data.album, record.album);
		strcpy(pMem->data.song, record.song);
		strcpy(pMem->data.genre, record.genre);
		pMem->data.song_length.minutes = record.song_length.minutes;
		pMem->data.song_length.seconds = record.song_length.seconds;
		pMem->data.times_played = record.times_played;
		pMem->data.rating = record.rating;
	}

	pMem->pNext = NULL;
	pMem->pPrev = NULL; 

	return pMem;
}

//insert node to front
int insertfront(NODE **pHead, RECORD record)
{
	NODE *pMem = NULL;
	int success = 0;
	pMem = makenode(record);

	
	if (*pHead == NULL)
	{
		*pHead = pMem;
		
		
		success = 1;
	}
	else 
	{
		(*pHead)->pPrev = pMem;
		pMem->pNext = *pHead;
		*pHead = pMem;
		
	
		
		success = 1;
	}
	return success;
}

//print list of entire records to screen from beginning of list
void printList(NODE *pList)
{
	NODE *pCur = NULL;

	pCur = pList;
	while (pCur != NULL) 
	{
		
		printf("%s,", pCur->data.artist);
		printf("%s,", pCur->data.album);
		printf("%s,", pCur->data.song);
		printf("%s,", pCur->data.genre);
		printf("%d:", pCur->data.song_length.minutes);
		printf("%d,", pCur->data.song_length.seconds);
		printf("%d,", pCur->data.times_played);
		printf("%d", pCur->data.rating);
		putchar('\n');
		pCur = pCur->pNext;
	}

	putchar('\n');
}

//NOT ACTUALLY USED ANYWHERE BUT KEPT FOR TESTING ONLY
void printListbackwards(NODE *pList)			//FOR TESTING PURPOSES. 
{
	NODE *pCur = NULL;

	pCur = pList;
	while (pCur->pNext != NULL)
	{
		pCur = pCur->pNext;
		
	}
	while (pCur != pList)
	{
		printf("%s,", pCur->data.artist);
		printf("%s,", pCur->data.album);
		printf("%s,", pCur->data.song);
		printf("%s,", pCur->data.genre);
		printf("%d:", pCur->data.song_length.minutes);
		printf("%d,", pCur->data.song_length.seconds);
		printf("%d,", pCur->data.times_played);
		printf("%d", pCur->data.rating);
		putchar('\n');
		pCur = pCur->pPrev;
	}
	
}

//print list to the file
void printlisttofile(NODE *pList, FILE * outfile, RECORD record[])
{
	NODE *pCur = NULL;
	int i = 0, x = 0;
	char newstring[20] = { '/0' };
	char quote[60] = { '\"' };
	char newstring2[60] = { '/0' };

	pCur = pList;

	//CHECKS FOR DOUBLE NAMES, APPENDS QUOTES ON EITHER SIDE
	while (pCur != NULL)
	{

		
			strcpy(newstring, pCur->data.artist);
			int x = 0;
			while (x < strlen(newstring))
			{
				if (newstring[x] == ',')
				{
					
					strcat(newstring, "\"");
					
					strcat(quote, newstring);
				
					strcpy(pCur->data.artist, quote);
					strcpy(quote, "\"");
				}
				x++;	
		}

		pCur = pCur->pNext;
	}
	pCur = pList;

	//PRINT OUT ALL RECORDS TO FILE
	while (pCur != NULL)
	{

		fprintf(outfile, "%s,", pCur->data.artist);
		fprintf(outfile, "%s,", pCur->data.album);
		fprintf(outfile, "%s,", pCur->data.song);
		fprintf(outfile, "%s,", pCur->data.genre);
		fprintf(outfile, "%d:", pCur->data.song_length.minutes);
		fprintf(outfile, "%d,", pCur->data.song_length.seconds);
		fprintf(outfile, "%d,", pCur->data.times_played);
		fprintf(outfile, "%d\n", pCur->data.rating);
		

		pCur = pCur->pNext;
	}
}

//search for specific records based on artist and displaying matching record 
void searchArtistDisplay(NODE *pList, RECORD record[])
{
	NODE *pCur = NULL;

	pCur = pList;

	int i = 0, counter = 0;
	int option = 0;
	int artist = 0;


	//PRINT LIST OF ARTISTS TO SCREEN
	while (pCur != NULL)
	{
		printf("%d. %s\n", i, pCur->data.artist);
		pCur = pCur->pNext;
		i++;
	}
	pCur = pList;
	printf("Which artist's records would you like to display to the screen? Select an option.\n");
	scanf("%d", &artist);


	//DISPLAY SELECTED ARTIST'S RECORDS
	i = 0;
	while (i < 9)
	{
		if ((strcmp(pCur->data.artist, record[artist].artist) == 0))
		{
			printf("\n%d. ", counter);
			print_records_to_screen(pCur);
			putchar('\n');
			counter++;
		}
		pCur = pCur->pNext;
		i++;
	}
	
}

//print menu to select an attribute
void print_attribute_menu()
{
	printf("\n1. Artist\n");
	printf("2. Album\n");
	printf("3. Song\n");
	printf("4. Genre\n");
	printf("5. Minutes length\n");
	printf("6. Seconds length\n");
	printf("7. Times played\n");
	printf("8. Rating\n");
}

//search for specific records based on artist and edit any piece of the record
void searchArtistEdit(NODE *pList, RECORD record[])

{
	NODE *pCur = NULL;

	pCur = pList;

	int i = 0, count = 0, counter = 0, option = 0, attribute = 0, artist = 0, song = 0;
	char artist_change[20] = { '/0' };
	char album_change[25] = { '/0' };
	char song_change[25] = { '/0' };
	char genre_change[20] = { '/0' };
	int min_change = 0, sec_change = 0, times_change = 0, rating_change = 0;
	char change_again = 'y';
	


	//PRINT LIST OF ARTISTS
	while (pCur != NULL)
	{
		printf("%d. %s\n", i, pCur->data.artist);
		pCur = pCur->pNext;
		i++;
	}
	pCur = pList;
	
	//ASK USER WHAT ARTIST THEY WANT TO EDIT
	do
	{
		artist = 0;
		printf("Which artist's records would you like to edit?\n");
		scanf(" %d", &artist);
		if ((artist < 0 || artist >= i))
		{
			printf("\nSelect a valid coordinate between 0 and %d.\n", i);
			artist = -1;
		}
	} while ((artist < 0 || artist >= i));

	i = 0;
	//PRINT SELECTED ARTIST'S RECORDS TO SCREEN
	while (pCur != NULL)
	{
		if ((strcmp(pCur->data.artist, record[artist].artist) == 0))
		{
			printf("\n%d. ", counter);
			print_records_to_screen(pCur);
			putchar('\n');
			counter++;
			i++;
			
		}
		pCur = pCur->pNext;
		i++;
	}
	

	//IF THERE ARE MULTIPLE SONGS BY SAME ARTIST, ASK USER WHICH ONE
	pCur = pList;
	if (counter > 1)
	{

		printf("\nWhich song would you like to edit? Select an option.\n");
		scanf("%d", &song);
		while (pCur != NULL)
		{
			if ((strcmp(pCur->data.artist, record[artist].artist) == 0))
			{

				if (count == song)
				{

					printf("\n\nYou've selected the song '%s' to edit.\n", pCur->data.song);


					print_attribute_menu();

					//EDIT THE ATTRIBUTE
					printf("Which attribute would you like to edit?\n");
					scanf("%d", &attribute);


					edit_attribute(pCur, attribute);


				}
				count++;
			}
			
			pCur = pCur->pNext;
		}



	}
	//IF THERE IS ONLY ONE SONG BY THE ARTIST
		else
		{
			while (pCur != NULL)
			{
				if ((strcmp(pCur->data.artist, record[artist].artist) == 0))
				{

					print_attribute_menu();

					//EDIT ATTRIBUTE
					printf("Which attribute would you like to edit?\n");
					scanf("%d", &attribute);

					edit_attribute(pCur, attribute);
					
				}pCur = pCur->pNext;
			}
			
		
		}
}

//case statement to edit an attribute of a record
void edit_attribute(NODE *pCur, int attribute)
{
	char artist_change[20] = { '/0' };
	char album_change[25] = { '/0' };
	char song_change[25] = { '/0' };
	char genre_change[20] = { '/0' };
	int min_change = 0, sec_change = 0, times_change = 0, rating_change = 0;
	
	switch (attribute)
	{
	case ARTIST:

		printf("Enter a new name for the artist: ");
		scanf(" %s", &artist_change);
		strcpy(pCur->data.artist, artist_change);
		printf("\nNew artist: %s, \n", pCur->data.artist);

		break;

	case ALBUM:

		printf("Enter a new name for the album: ");
		scanf(" %s", &album_change);
		strcpy(pCur->data.album, album_change);
		printf("\nNew album: %s, \n", pCur->data.album);

		break;

	case SONG:
		printf("Enter a new name for the song: ");
		scanf(" %s", &song_change);
		strcpy(pCur->data.song, song_change);
		printf("\nNew song: %s, \n", pCur->data.song);

		break;

	case GENRE:
		printf("Enter a new genre: ");
		scanf(" %s", &genre_change);
		strcpy(pCur->data.genre, genre_change);
		printf("\nNew genre: %s, \n", pCur->data.genre);

		break;

	case MINS:
		printf("Enter new minute length: ");
		scanf("%d", &min_change);
		pCur->data.song_length.minutes = min_change;
		printf("\nNew minutes: %d, \n", pCur->data.song_length.minutes);

		break;

	case SECS:
		printf("Enter new seconds length: ");
		scanf("%d", &sec_change);
		pCur->data.song_length.seconds = sec_change;
		printf("\nNew seconds: %d, \n", pCur->data.song_length.seconds);

		break;

	case TIMESPLAYED:
		printf("Enter new times played: ");
		scanf("%d", &times_change);
		pCur->data.times_played = times_change;
		printf("\nNew times played: %d, \n", pCur->data.times_played);

		break;

	case RATING:
		printf("Enter new rating: ");
		scanf("%d", &rating_change);
		pCur->data.rating = rating_change;
		printf("\nNew rating: %d \n", pCur->data.rating);

		break;
	}
}

//print just one record to the screen
void print_records_to_screen(NODE *pCur)
{
	printf("%s,", pCur->data.artist);
	printf("%s,", pCur->data.album);
	printf("%s,", pCur->data.song);
	printf("%s,", pCur->data.genre);
	printf("%d:", pCur->data.song_length.minutes);
	printf("%d,", pCur->data.song_length.seconds);
	printf("%d,", pCur->data.times_played);
	printf("%d", pCur->data.rating);
}

//rate a song
void rate(NODE *pList, RECORD record[])
{
	
	NODE *pCur = NULL;

	pCur = pList;
	int rate = 0, song = 0, rating_change = 0;
	int rate_change = 0, i = 0;

	//PLAY LIST OF SONGS
	while (pCur != NULL)
	{
		printf("%d. %s\n", i, pCur->data.song);
		pCur = pCur->pNext;
		i++;
	}

	printf("\nWhat song would you like to rate?\n");
	scanf("%d", &song);

	i = 0;
	pCur = pList;

	//RATE NEW SONG
	while (pCur != NULL)
	{
		if ((strcmp(pCur->data.song, record[song].song) == 0))
		{
			print_records_to_screen(pCur);
			putchar('\n');

			printf("Enter new rating: ");
			scanf("%d", &rating_change);
			pCur->data.rating = rating_change;
			printf("\nNew rating: %d \n", pCur->data.rating);
		}
		pCur = pCur->pNext;
		i++;
	}
	


}

//play songs for ten seconds each
void play(NODE *pList, RECORD record[])
{
	char play = NULL;

	NODE *pCur = NULL;
	pCur = pList;
	
	printf("Play from beginning? Enter y for yes and n for no.\n");
	scanf(" %c", &play);

	//PLAY FROM BEGINNING OF LIST
	if (play == 'y')
	{
		while (pCur != NULL)
		{
			printf("NOW PLAYING:\n");
			print_records_to_screen(pCur);
			putchar('\n');
			Sleep(5000);
			system("cls");
			
			pCur = pCur->pNext;
		}
	}
	else
	{

		int i = 0, counter = 0, success = 0;
		int option = 0;
		int song = 0;

		while (pCur != NULL)
		{
			printf("%d. %s\n", i, pCur->data.song);
			pCur = pCur->pNext;
			i++;
		}
		pCur = pList;
		printf("Which song would you like to play first? Select an option.\n");
		scanf("%d", &song);

		i = 0;
		while (success !=1)				//FIND SONG TO START WITH AND PLAY IT
		{
			if ((strcmp(pCur->data.song, record[song].song) == 0))
			{
				printf("NOW PLAYING:\n");
				print_records_to_screen(pCur);
				
				Sleep(5000);
				system("cls");
				success = 1;
				
			}
			pCur = pCur->pNext;
		}
	
		while (pCur != NULL)					//PLAY THE REST OF THE LIST DOWN
		{
			
			printf("NOW PLAYING:\n");
			print_records_to_screen(pCur);

			Sleep(5000);
			system("cls");
			pCur = pCur->pNext;
		}

	}
}

//insert new, user allocatd node to list
void insert_new_node(NODE **pList, RECORD record[], int i)
{
	char artist_change[20] = { '/0' };
	char album_change[25] = { '/0' };
	char song_change[25] = { '/0' };
	char genre_change[20] = { '/0' };
	int min_change = 0, sec_change = 0, times_change = 0, rating_change = 0;


	printf("\nEnter new artist (artists with two names must be separated by comma): ");
	scanf("%s", &artist_change);
	strcpy(record[i].artist, artist_change);


	printf("\nEnter new album: ");
	scanf("%s", &album_change);
	strcpy(record[i].album, album_change);


	printf("\nEnter new song name: ");
	scanf("%s", &song_change);
	strcpy(record[i].song, song_change);

	printf("\nEnter new genre: ");
	scanf("%s", &genre_change);
	strcpy(record[i].genre, genre_change);

	printf("\nEnter new minutes length: ");
	scanf("%d", &min_change);
	record[i].song_length.minutes = min_change;

	printf("\nEnter new seconds length: ");
	scanf("%d", &sec_change);
	record[i].song_length.seconds = sec_change;

	printf("\nEnter new times played: ");
	scanf("%d", &times_change);
	record[i].times_played = times_change;

	printf("\nEnter new rating: ");
	scanf("%d", &rating_change);
	record[i].rating = rating_change;
	
}

//delete any node from list anywhere in list, as defined by user
void deleteNode(NODE **pList, RECORD record[])
{

	NODE * pCur = NULL;
	int i = 0, song = 0, counter = 0, success = 0;
	printf("\nWhich song would you like to delete?\n");
	pCur = *pList;

	//print songs to screen for user to decide
	while (pCur != NULL)
	{
		printf("%d. %s\n", i, pCur->data.song);
		i++;
		pCur = pCur->pNext;
	}
	scanf("%d", &song);

	pCur = *pList;
	while (pCur != NULL && success == 0)		//FIND NODE TO DELETE
	{
		if ((strcmp(pCur->data.song, record[song].song) == 0))
		{
			
			success = 1;
			

		}
		if (success != 1)
		{
			pCur = pCur->pNext;
		}
	}
	if (success == 1)
	{
		if (pCur == *pList)				//remove from head
		{
			*pList = pCur->pNext;
			(*pList)->pPrev = NULL;
		}
		else if (pCur->pNext == NULL)			//remove from end
		{
			pCur = pCur->pPrev;
			pCur = pCur->pNext = NULL;
		}
		else
		{										//REMOVE FROM ANYWHERE ELSE
			pCur->pPrev->pNext = pCur->pNext;
			pCur->pNext->pPrev = pCur->pPrev;
		}
	}
	free(pCur);
}

//sort by artist, album, rating and times played
void sort(NODE **pList, RECORD record[])
{
	int sortmethod = 0, swapped = 0;
	NODE * pCur = NULL;
	NODE * pCur2 = NULL;
	NODE * pTemp = NULL;
	RECORD temp = { '\0' };
	int i = 0;


	//DISPLAY MENU
	do
	{
		printf("\nHow would you like to sort?\n");
		printf("1. By artist\n");
		printf("2. By album\n");
		printf("3. By rating\n");
		printf("4. By times played\n");
		scanf("%d", &sortmethod);
	} while (sortmethod < 1 || sortmethod > 4/* || sortmethod > 'A'*/);

	pCur = *pList;
	

	//SORT
	switch (sortmethod)
	{
	case ARTIST:
			
			do
			{ 
				pCur = *pList;
				swapped = 0;
				while (pCur->pNext != NULL)
				{
					if (strcmp(pCur->data.artist, pCur->pNext->data.artist) > 0)
					{
						temp = pCur->data;
						pCur->data = pCur->pNext->data;
						pCur->pNext->data = temp;
						swapped = 1;
					}
					pCur = pCur->pNext;
				}	
				pTemp = pCur;
			} while (swapped);

		break;

	case ALBUM:

		do
		{
			pCur = *pList;
			swapped = 0;

			while (pCur->pNext != NULL)
			{
				if (strcmp(pCur->data.album, pCur->pNext->data.album) > 0)
				{
					temp = pCur->data;
					pCur->data = pCur->pNext->data;
					pCur->pNext->data = temp;
					swapped = 1;
				}
				pCur = pCur->pNext;
			}
			pTemp = pCur;
		} while (swapped);

		break;

	case RATING2:
		do
		{
			pCur = *pList;
			swapped = 0;

			while (pCur->pNext != NULL)
			{
				if (pCur->data.rating > pCur->pNext->data.rating)
				{
					temp = pCur->data;
					pCur->data = pCur->pNext->data;
					pCur->pNext->data = temp;
					swapped = 1;
				}
				pCur = pCur->pNext;
			}
			pTemp = pCur;
		} while (swapped);

		break;

	case TIMESPLAYED2:
		do
		{
			pCur = *pList;
			swapped = 0;

			while (pCur->pNext != NULL)
			{
				if (pCur->data.times_played > pCur->pNext->data.times_played)
				{
					temp = pCur->data;
					pCur->data = pCur->pNext->data;
					pCur->pNext->data = temp;
					swapped = 1;
				}
				pCur = pCur->pNext;
			}
			pTemp = pCur;
		} while (swapped);


		break;
	}
}

//shuffles songs and plays them to screen
void shuffle(NODE * pList, RECORD record[])
{
	NODE * pCur = NULL;
	NODE * pMem = NULL;
	int num_nodes = 0, index = 0, index2 = 0, found = 0;
	int is_played = 0;
	int *x;
	int digit = 0;



	pMem = pList;
	pCur = pList;
	while (pCur != NULL)
	{
		pCur->data.number = num_nodes;		//assigns number to every song
		num_nodes++;
		pCur = pCur->pNext;
	}

	//counted numnodes and assigned number. reset list
	pCur = pList;
	x = (int*)malloc(sizeof(int) * num_nodes);

	for (index2 = 0; index2 < num_nodes; index2++)
	{
		x[index2] = -1;
	}

	while (pCur != NULL)				//x[index] is random order
	{
		do
		{
			digit = rand() % num_nodes;
			found = 0;
			for (index2 = 0; index2 < num_nodes; index2++)
			{
				if (x[index2] == digit)
				{
					found = 1;
					break;
				}
			}
		} while (found == 1);

		x[index] = digit;
		found = 0;
		pCur = pCur->pNext;
		index++;
	}

	index = 0;
	pCur = pList;

	//PLAY CONTENTS
	while (pCur != NULL && index < num_nodes - 1)
	{
		if (index == 0)
		{
			while (pCur->data.number != x[index])	//PLAY FIRST SONG IN RANDOMLY GENERATED ORDER
			{
				pCur = pCur->pNext;

			}
			printf("\nNOW PLAYING\n");
			print_records_to_screen(pCur);
			Sleep(5000);
			system("cls");
		}
		if (x[index] < x[index + 1])				//IF NEXT NUMBER IN ORDER IS GREATER, TRAVERSE FORWARD
		{
			while (pCur->data.number != x[index + 1])
			{
				pCur = pCur->pNext;
			}
			printf("\nNOW PLAYING\n");
			print_records_to_screen(pCur);
			Sleep(5000);
			system("cls");
		}
		else if (x[index] > x[index + 1])		//IF NEXT NUMBER IN ORDER IS LESS, TRAVERSE BACKWARD
		{
			while (pCur->data.number != x[index + 1])
			{
				pCur = pCur->pPrev;
			}
			printf("\nNOW PLAYING\n");
			print_records_to_screen(pCur);
			Sleep(5000);
			system("cls");

		}
		index++;
	}


}


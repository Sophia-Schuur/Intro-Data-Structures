//Sophia Schuur
//CptS 122
//PA 3
//2/10/2017
//Creating a music playlist with linked lists

#include "header.h"

int main(void)
{
	RECORD record[9] = { 0 };
	int i = 0;
	FILE *infile = NULL;
	FILE *outfile = NULL;
	NODE *pList = NULL;
	char goback = 'y';

	srand((unsigned int)time(NULL));
	
		

	char str[70] = { '\0' };
	char *token = NULL;
	char *firstname = NULL;
	char *lastname = NULL;
	char * temp = NULL;

	int artist1 = 0;



	while (goback == 'y')
	{
		int option = 0;
		do
		{
			printmenu();
			scanf("%d", &option);
			system("cls");
		} while ((option < 1) || (option > 11));





		switch (option)
		{
		case LOAD:
			outfile = fopen("musicPlayList.txt", "r");
			while (fgets(str, 100, outfile) !=NULL)
			{
				if (str[0] == '\"')
				{

					firstname = strtok(str, "\"");
					strcpy(record[i].artist, firstname);

					token = strtok(NULL, ",");
					strcpy(record[i].album, token);

					token = strtok(NULL, ",");
					strcpy(record[i].song, token);

					token = strtok(NULL, ",");
					strcpy(record[i].genre, token);

					token = strtok(NULL, ":");
					record[i].song_length.minutes = atoi(token);

					token = strtok(NULL, ",");
					record[i].song_length.seconds = atoi(token);

					token = strtok(NULL, ",");
					record[i].times_played = atoi(token);

					token = strtok(NULL, ",");
					record[i].rating = atoi(token);
				}
				else
				{
					token = strtok(str, ",");
					strcpy(record[i].artist, token);

					token = strtok(NULL, ",");
					strcpy(record[i].album, token);

					token = strtok(NULL, ",");
					strcpy(record[i].song, token);

					token = strtok(NULL, ",");
					strcpy(record[i].genre, token);

					token = strtok(NULL, ":");
					record[i].song_length.minutes = atoi(token);

					token = strtok(NULL, ",");
					record[i].song_length.seconds = atoi(token);

					token = strtok(NULL, ",");
					record[i].times_played = atoi(token);

					token = strtok(NULL, ",");
					record[i].rating = atoi(token);

				}
				

				i++;
			}
			int count = i - 1;
			while (count >= 0)
			{
				insertfront(&pList, record[count]);
				count--;
			}
			printList(pList);
			fclose(outfile);

			//printListbackwards(pList);

			printf("\nPress y to go back to main menu.\n");
			scanf(" %c", &goback);
			system("cls");
		
			break;

		case STORE:
			outfile = fopen("musicPlayList.txt", "w");
			
			printlisttofile(pList, outfile, record);
			if (outfile != NULL)
			{
				printf("New data saved to file.\n");
			}
			fclose(outfile);

			
			goback = 'n';

			break;
		
		case DISPLAY:
			printList(pList);
			searchArtistDisplay(pList, record);
	
			printf("\nPress y to go back to main menu.\n");
			scanf(" %c", &goback);
			system("cls");

			break;

		case INSERT:
			i = i + 1;
			insert_new_node(&pList, record, i);
			insertfront(&pList, record[i]);
			printList(pList);

			break;

		case DELETE:
			//NOTE: TO SAVE A DELETE, OR IF YOU WANT TO GO BACK TO THE MAIN MENU, YOU MUST STORE FIRST. 
		
			deleteNode(&pList, record);
			printf("Record deleted. STORE or EXIT to save results.\n");
			printf("\nPress y to go back to main menu.\n");
			scanf(" %c", &goback);
			system("cls");

			break;

		case EDIT:
			searchArtistEdit(pList, record);
			printf("\nPress y to go back to main menu.\n");
			scanf(" %c", &goback);
			system("cls");

			
			break;

		case SORT:
			
			sort(&pList, record);
			

			printf("\nPress y to go back to main menu.\n");
			scanf(" %c", &goback);
			system("cls");

			break;

		case RATE:
			rate(pList, record);

			printf("\nPress y to go back to main menu.\n");
			scanf(" %c", &goback);
			system("cls");
		
			break;

		case PLAY:
			play(pList, record);
			
			break;

		case SHUFFLE:
			shuffle(pList, record);

			printf("\nPress y to go back to main menu.\n");
			scanf(" %c", &goback);
			system("cls");

			break;


		
			
		case EXIT:
			outfile = fopen("musicPlayList.txt", "w");

			printlisttofile(pList, outfile, record);
			if (outfile != NULL)
			{
				printf("New data saved to file.\n");
			}
			fclose(outfile);


			goback = 'n';

			break;
		}
		
	}
	fclose(outfile);
	return 0;
}
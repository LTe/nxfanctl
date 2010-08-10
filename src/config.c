#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "nx.h"

int configRead()
{
	FILE *config;
	char napis[100];
	int i=0, n, *tempe;
	
	if ((config=fopen("/etc/nxfan.conf", "r"))==NULL) 
	{
		printf ("Nie moge otworzyc pliku konfiguracyjnego!\n");
		exit(1);
	}
	
	while(strcmp(napis, "end"))
	{
		fscanf(config, "%s", napis);
		
			if(!strcmp(napis, "!"))
			{
				fscanf(config, "%s", napis);
				n = atoi(napis);
				tempe = (int*) malloc(sizeof(int) * (n+3)*2);
				tempe[0] = n;
				printf("Ustalono ilosc wentylatorow: %d\n", tempe[0]);
			}
				
				else

				if(!strcmp(napis, "temp"))
				{
					fscanf(config, "%s", napis);
					i = atoi(napis);
					fscanf(config, "%s", napis);		
					tempe[i] = atoi(napis);
					printf("Ustawiono poziom temperatury numer %d na poziom %d*C\n", i, tempe[i]);
				}

			else
			
		if(!strcmp(napis, "timeout"))
		{
			fscanf(config, "%s", napis);
			tempe[n+1] = atoi(napis);
			printf("Ustawiono timeout na %d sekund\n", tempe[n+1]);
		}
			
	}

  	config = fclose(config);
	return tempe;	
}

char** fanConfig(int n)
{
	char **path;
	int i, k;
	FILE *config;
	char napis2[1024];
	
	path = (char **) malloc(sizeof(char *) * n+5);
	for(k=0; k<=n+5; k++)
		path[k] = (char*) malloc(sizeof(char) * 200);
	
	if ((config=fopen("/etc/nxfan.conf", "r"))==NULL) 
	{
		printf ("Nie moge otworzyc pliku konfiguracyjnego!\n");
		exit(1);
	}

	while(strcmp(napis2, "end"))
	{
		
		fscanf(config, "%s", napis2);
		
		if(!strcmp(napis2, "fanpath"))
		{
			fscanf(config, "%s", napis2);
			i = atoi(napis2);
			printf("Dowiazano wentylator numer %d ", i);
			fscanf(config, "%s", napis2);
			strcpy(path[i], napis2);
			printf("do sciezki %s\n", path[i]);
		}
		if(!strcmp(napis2, "temppath"))
		{
			fscanf(config, "%s", napis2);
			strcpy(path[n+1], napis2);
		}
	}
	return path;
}


void fanOn(char *path)
{
	char echo[1024] = "echo 0 > ";
	strcat(echo, path);
	printf("%s\n", echo);
	system(echo);
}

void fanOff(char *path)
{
	char echo[1024] = "echo 3 > ";
	strcat(echo, path);
	printf("%s\n", echo);
	system(echo);
}

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "nx.h"

int main()
{
  int *tempe, itemp, i, k;
  char tmp[20], **path;
  FILE *temp;
  FILE *check;

 tempe = configRead();
 path = fanConfig(tempe[0]);
 

  if ((check=fopen(path[1], "w"))==NULL) 
  {
    printf ("Brak dostepu do wentylatorow, sprobuj uruchomic jako root!\n");
    exit(2);
  }

	printf("%s", path[tempe[0]]);

  if ((temp=fopen(path[tempe[0]+1], "r"))==NULL) 
  {
    printf ("Nie moge odczytac temperatury!\n");
    exit(1);
  }

  fclose(temp);

  while(1)
  {
		temp=fopen(path[tempe[0]+1], "rt+");
		fscanf(temp, "%s", tmp);
		fscanf(temp, "%s", tmp);
		fclose(temp);
		itemp = atoi(tmp);
		printf("\nAktualna temperatura: %d\n", itemp);
		
		for(i=1; i<=tempe[0]; i++)
		{
			if(itemp >= tempe[i]) 
			{
				for(k=1; k<=tempe[0]; k++)
				{
					if(k<=i)
					fanOn(path[k]);
					else
					fanOff(path[k]);
				}
			}
		}

		if(itemp < tempe[1])
		{
			printf("OFF!\n");
			for(k=tempe[0]; k>=1; k--)
				fanOff(path[k]);
					
		}
		
		sleep(tempe[tempe[0]+1]);
  }

return 0;
}



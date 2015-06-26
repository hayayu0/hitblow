



#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int hit(char *r,char *s) {
    int i,j,iHit=0,iBrrow=0;
    char wr[4],ws[4];

    for (i=0;i<4;i++) {
	wr[i]=r[i];
	ws[i]=s[i];
    }

    for (i=0;i<4;i++)
	if (wr[i]==ws[i]) {
	    iHit++;
            wr[i]='r';
	    ws[i]='s';
	}

    for (i=0;i<4;i++)
        for (j=0;j<4;j++)
	    if (i!=j && wr[j]==ws[i]) {
		iBrrow++;
		wr[j]='r';
		ws[i]='s';
	    }

    printf("Hit %d Blow %d\n",iHit,iBrrow);
    return iHit;
}

int main() {
    char s[4],str[5];
    int i,n=0;

    srand((unsigned)time(NULL));

    for (i=0;i<4;i++)
	s[i]='0'+(rand() % 10);

    printf("num4>\n");

    do {
		printf("%d ",++n);
		scanf("%s",str);
    } while(hit(str,s)!=4);

    printf("Bingo!\n");
    getch();
    return 0;
}
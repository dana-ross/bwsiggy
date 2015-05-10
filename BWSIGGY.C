/* BWSIGGY v1.0 */

#include <stdio.h>
#include <dos.h>

FILE *fptr;
FILE *fpr;
char tempstr[79];

int main(int argc, char *argv[])
{
 printf("Executing BWSIGGY.EXE");
 sleep(1);
 if (argc<1)
 {
	printf("\nBWSIGGY ERROR #1: No parameters specified\n");
	sleep(5);
	exit(1);
 }
 if ((fptr=fopen(argv[1],"a"))==NULL)
 {
	printf("\nBWSIGGY ERROR #2: Unable to open message file\n");
	sleep(5);
	exit(2);
 }
 if ((fpr=fopen("BWSIGGY.SIG","r"))==NULL)
 {
	printf("\nBWSIGGY ERROR #3: Unable to open BWSIGGY.SIG\n                  Make sure BWSIGGY.SIG is in the\n                  current directory\n");
	sleep(5);
	exit(3);
 }

 fgets(tempstr,79,fpr);
 fputs("\n",fptr);

 while (!feof(fpr))
 {
  fputs(tempstr,fptr);
  fgets(tempstr,80,fpr);
 }

 fputs("\n___ BWSIGGY v1.0 - UEP",fptr);

 fclose(fptr);
 fclose(fpr);

 printf("\nThank you for using BWSIGGY v1.0\nAn Underground Edge Press Production\n");
 sleep(3);
 return(0);

}
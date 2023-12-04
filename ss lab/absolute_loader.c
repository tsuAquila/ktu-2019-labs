#include<stdio.h>
#include<stdlib.h>
#include<string.h>

FILE *iptr,*outptr;
char record[100];
char starting_address[100];
int recordpointer;
void writeoutputfile();
int main()
{
  iptr=fopen("absloaderinput.txt","r");
  outptr=fopen("outputfile.txt","w");
  if(iptr==NULL)
  {
    printf("file not open");
  }
  fgets(record,sizeof(record)/sizeof(char),iptr);
  while(record[0]!='E')
  { 
    if(record[0]=='T')
    {
      strncpy(starting_address,record+(2),6);
      recordpointer=12;
      writeoutputfile();
    }
   fgets(record,sizeof(record)/sizeof(char),iptr);
  }
  fclose(iptr);
  fclose(outptr);
  printf("absolute loader has been executed");
  return 0;
}

void writeoutputfile()
{
 char objectcode[20];
 int address;
 address=strtol(starting_address,NULL,16);
 while(record[recordpointer]!='\0')
  { 
    fprintf(outptr,"%x\t",address);
    strncpy(objectcode,record+(recordpointer),6);
    fprintf(outptr,"%s\n",objectcode);
    recordpointer+=7;
    address+=3;
    if(record[recordpointer]=='^')
    {  recordpointer++;
    }
  }  
 }
 
 INPUT FILE
 
 H^SAMPLE^001000^000035
 T^001000^06^001003^071009
 T^002000^03^111111
 E^001000
 
 OUTPUT FILE
 
 1000	001003
 1003	071009
 2000	111111
    
  
     
      

#define _GNU_SOURCE
#include "utils.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>


void mysh_parse_command(const char* command,
                        int *argc, char*** argv)
{
  char temp[8096] = {};
  char temp2[8096] = {};
  strcpy(temp,command);
  strcpy(temp2,command);
  int i=0;
  *argc=0;
  char *pt1;
  char *pt2;
  char *pt3;
  char *count;
  char ttab[100] ={};
  

//  pt3 = strtok_r(temp, " \t\n"  , &pt1);
 pt3= strtok(temp," \t\n");
 
 
 while(pt3!=NULL){
 
 
// pt3 = strtok_r(NULL, " \t\n" , &pt1);
 
  
 if(pt3==NULL)break;
 *argc=*argc+1;
 strcpy(ttab,pt3);
 
 if(ttab[0]== '\\' ){

 *argc = *argc-1;
}
 pt3 = strtok(NULL, " \t\n");
 
}
 if(*argc==0){
 *argc=1;
 

 *(argv) = (char**)malloc(sizeof(char)*(2));
 char *kkk = ""; 
 *(argv[0]+i) = (char*)malloc(sizeof(char)*(strlen(kkk)+1));
 strcpy(*(argv[0]+i),kkk);
return;

} 
 *(argv) = (char**)malloc(sizeof(char*)*(*argc+1));
 
 count= strtok_r(temp2, " \t\n", &pt2);
 while(1){
 char tttab[100]= {};
 
 strcpy(tttab,count);
 
  
 if(tttab[0] == '\\' ){
 
 count = strtok_r(NULL, " \t\n", &pt2);
 
}
else break;

} 
 
 if(*argc==0){
 *(argv[0]+i)= (char*)malloc(sizeof(char)*(1));
 
return;
}
 
 *(argv[0]+i) = (char*)malloc(sizeof(char)*(strlen(count)+1));
 
 strcpy(*(argv[0]+i),count);
 //*(argv[0]+i)
 
while(count!=NULL){
 
 count= strtok_r(NULL, " \t\n", &pt2);
 if(count==NULL)break;
 while(1){
 char ttttab[100]={};
 strcpy(ttttab,count);
 
 if(ttttab[0]=='\\'){
 
 
 count= strtok_r(NULL, " \t\n", &pt2);
 if(count == NULL) break;
}
 else break;
}
 if(count == NULL)break; 
 i++;
 *(argv[0]+i)=(char*)malloc(sizeof(char)*(strlen(count)+1));
 
 strcpy(*(argv[0]+i),count);
 
}

return;
}







  


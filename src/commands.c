#include <string.h>
#include <unistd.h>
#include "commands.h"
#include <stdio.h>
int do_cd(int argc, char** argv) {
  if (!validate_cd_argv(argc, argv))
    return -1;

  // TODO: Fill it!
    int check;
   check = chdir(argv[1]);
   if(check!=0){
     
return -1;
}

 
  return 0;
}

int do_pwd(int argc, char** argv) {
  if (!validate_pwd_argv(argc, argv)){// if zero comes, works. one comes, not working.
    return -1;
  }
  char buff[1024];
  char *check;


 check = getcwd(buff, 1024);
 if(check==NULL){
 
return -1;
}
  printf("%s\n", buff);
  // TODO: Fill it!

  return 0;
}

int validate_cd_argv(int argc, char** argv) {
  // TODO: Fill it!
  if(strcmp(argv[0],"cd")!=0){
 return 0;
}
 

 if(argc!=2){
return 0;
}
  return 1;
}

int validate_pwd_argv(int argc, char** argv) {
  // TODO: Fill it!
  
  if(argc==1){
 if(strcmp(argv[0],"pwd")==0){
  return 1;
}
}
return 0;
}

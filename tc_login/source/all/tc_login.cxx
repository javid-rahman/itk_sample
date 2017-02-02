#ifdef  DEBUG
#define DEBUGMSG(s) TC_printf s
#else
#define DEBUGMSG(s)
#endif

#include <tcinit/tcinit.h>
#include <tc/tc_startup.h>
#include <fclasses/tc_stdio.h>

void displayUsage();

int ITK_user_main(int argc,char *argv[]){ 	
	
	int returnCode;
	char *username;
	char *passwd;
	char *group;
	
	username = ITK_ask_cli_argument("-u");
	passwd = ITK_ask_cli_argument("-p");
	group = ITK_ask_cli_argument("-g");
	
	if(username != NULL & passwd != NULL & group != NULL){
		returnCode = ITK_init_module(username,passwd,group);
	}else{
		printf("\n invalid arguments.Please check the usage \n");
		displayUsage();
		return ITK_ok;
	}
	
	if(returnCode == ITK_ok){
		printf("\n Successfully logged in to Teamcenter... \n");
	}else{
		printf("\n Unexpected error in Teamcenter login.Please check with administrator \n");
	}
	
	if(ITK_ask_cli_argument("-h") != NULL){
		displayUsage();
		return ITK_ok;
	}
	
	return returnCode;
}


void displayUsage(){
	printf("Usage of this utility: \n");
	printf("-u=<username> -p=<password> -g=<group> \n");
	printf("Please use -h to refer usage \n\n");
}
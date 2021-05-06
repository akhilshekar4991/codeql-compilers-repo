#include<stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h> /* for fork */
#include <sys/types.h> /* for pid_t */
#include <sys/wait.h> /* for wait */

int main(int argc, char *argv[])
{
	for(int i=0; i<argc; i++)
	{
		printf("arg %d = %s \n", i, argv[i]);
	}

	system("rm -rf codeql_db");
	char database_create_cmd[1000] = "$CODEQL_PATH/codeql database create codeql_db --language=\"cpp\" --command=\"g++ ";
	strcat(database_create_cmd, argv[1]);
	strcat(database_create_cmd, "\"");
	printf("the db command is : %s \n", database_create_cmd);
	system("/home/akhil/compilers/codeql-compilers-repo/test_dir/build_testing/hello.sh");
	system(database_create_cmd);

	char database_run_cmd[1000] = "$CODEQL_PATH/codeql query run -d=codeql_db ";
	strcat(database_run_cmd, argv[2]);
	printf("----> database query cmd : %s \n", database_run_cmd);
	system(database_run_cmd);
	printf("end of program \n");
	return 0;
}
/*
	pid_t pid=fork();
	if (pid==0) {  
		static char *argv[]={"echo","Foo is my name.",NULL};
		execv("/bin/echo",argv);
		exit(127); 
	}
        else { 
	        waitpid(pid,0,0); 
    	}*/


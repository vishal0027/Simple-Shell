#include <stdio.h>
#include <string.h>
#include <signal.h>
#include <fcntl.h>
#include "eval.h"
#include "proc.h"



void excuteFunction(evptr tree);
void excuteJoint(int joint, evptr tree );
void iterateTree(evptr tree);

int eval(tree,inport,outport)
     evptr tree; 
     int inport, outport;
{
	
	excuteFunction(tree);
	//int tag = tree->tag;
	//iterateTree(tree);
	//printf("%i",tag);
       // excuteJoint(tag, tree);
	
	/*
	int waiting;
	pid_t pid;
     	
	char * temp = "/bin/";
	char * total = malloc(strlen(temp) + strlen(tree->leaf.data->fname));
	strcpy(total, temp);
	strcat(total, tree->leaf.data->fname);
	char *const parmList[] = {total, NULL};
	//because i want to add temp+arg[0];
     	if ((pid = fork()) == -1)
       		 perror("fork error");
    	 else if (pid == 0) {
       		 execv(total, parmList);
       		 printf("Return not expected. Must be an execv error.n");*/	
}

	//iterate(tree);
	//printtree(tree,0)

void excuteFunction(evptr tree){
	pid_t pid;
	char * temp = "/bin/";
	char * total = malloc(strlen(temp) + strlen(tree->leaf.data->fname));
	strcpy(total, temp);
	strcat(total, tree->leaf.data->fname);
	char * parmList[] = {total, NULL};
	//because i want to add temp+arg[0];
     		if ((pid = fork()) == -1)
       			 perror("fork error");
    	 	else if (pid == 0) {
       		 	execv(total, parmList);
       			 printf("Return not expected. Must be an execv error.n");	
		}
}



void excuteJoint(int joint, evptr tree ){
		if(joint == 5){	
			// Means its pipe call
			excuteFunction(tree->son.left);
			 int pfds[2];
    			 pipe(pfds);

    			 if (!fork()) {
        			close(1);       /* close normal stdout */
      			 	dup(pfds[1]);   /* make stdout same as pfds[1] */
        			//sssclose(pfds[0]); /* we don't need this */
        			//execlp("ls", "ls", NULL);

				excuteFunction(tree->son.left);

    			} else {
       				 close(0);       /* close normal stdin */
       				 dup(pfds[0]);   /* make stdin same as pfds[0] */
       				// close(pfds[1]); /* we don't need this */
        			 //execlp("wc", "wc", "-l", NULL);
				excuteFunction (tree->son.right);
   			 }
		}
	
}
void iterateTree(evptr tree){
	 char * a;
	if(tree->leaf.data->fname == NULL ){
	       return;
	}
		
		
		
		iterateTree(tree->son.left);
		//a = tree->leaf.data->fname;
		printf("%s", tree->leaf.data->fname);
		//excuteFunction(tree->son.left);	
	    	iterateTree(tree->son.right);
		
		//a = leaf.data->fname; // do something with the value

}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Node.h"
#include "Queue.h"

int main(int argc , char **argv) {
  NodePtr headPtr=NULL;
  NodePtr tailPtr=NULL;
// 5 x 6 x 7 x 8 2 x
 //For struct Queue
  Queue q;
   q.headPtr=NULL;
   q.tailPtr=NULL;
   q.size=0;
   int i,x,j;
   

  for(i=1;i<argc;i++){
    if (strcmp(argv[i],"x")==0){
      if(q.size>=1){
        x = dequeue_struct(&q);
      }
      else printf("Empty queue\n");
    }
    else{
      enqueue_struct(&q, atoi(argv[i]), atoi(argv[i+1]));
      i++;
    }
    
  }
  printf("====================================\n");
  if(q.size!=0){
    printf("There are %d people left in the queue\n",q.size);
  }
  return 0;
}

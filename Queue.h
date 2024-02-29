#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Node.h"

typedef struct {
  NodePtr headPtr,tailPtr;
  int size;
}Queue;


void enqueue_struct(Queue* q, int x, int y){
  Node *new_node = (Node*)malloc(sizeof(Node));
  if(new_node){
    new_node->order_number = x;
    new_node->quantity = y;
    new_node->nextPtr=NULL;
    if(q->headPtr==NULL){
      q->headPtr = new_node;
    }
    else 
      q->tailPtr->nextPtr = new_node;
    q->tailPtr = new_node;
    printf("My order is %d\n",x);
  }
  q->size++;
}


int dequeue_struct(Queue *q){
  NodePtr t = q->headPtr;
  char food[32];
  int price = 0;
  int value = 0;
  int pay = 0;
  int noFood = 0;
  int static count = 1;
  if(t){
    switch (t->order_number)
    {
      case 1: value = 100; strcpy(food, "ramen"); break;
      case 2: value = 20; strcpy(food, "Somtum"); break;
      case 3: value = 50; strcpy(food, "Fried Chicken"); break;
      default: printf("No Food\n"); noFood = 1;
    }
    if(!noFood){
      price = value*t->quantity;
      printf("Customer No.%d\n",count);
      printf("%s\n",food);
      printf("You have to pay %d\n",price);
      while (1)
      {
        printf(":Cash:");
        scanf("%d",&pay);
        if (pay == price)
        {
          printf("Thank you\n");
          break;
        }
        else if (pay > price)
        {
          printf("Thank you\n");
          printf("Change is %d\n", pay-price);
          break;
        }
        else
        {
          printf("You have to pay %d\n",price);
        }
      }
    }
    q->headPtr = q->headPtr->nextPtr;
    free(t);
    q->size--;
    count++;
    return value;
  }
  return 0;
}


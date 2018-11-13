#include <stdio.h>
#include <stdbool.h>

typedef struct stackSpot {
  int value;
  struct stackSpot* next;
} stackSpot;

typedef struct stack {
  stackSpot* top;
} stack;

int pop(stack* this){
  int val = this->top->value;
  this->top = this->top->next;
  return val;
}

void push(stack* this, stackSpot* newElem){
  newElem->next = this->top;
  this->top = newElem;
}

int getStackValFromStackElem(stackSpot* this, int index){
  if (index == 0){
    return this->value;
  } else if (this->next != NULL){
    return getStackValFromStackElem(this->next, index - 1);
  } else {
    return NULL;
  }
}

int getStackValFromStack(stack this, int index){
  if (index == 0){
    return this.top->value;
  } else {
    return getStackValFromStackElem(this.top->next, index-1);
  }
}

int main(){
  stack myStack = {NULL};
  stackSpot a = {1,NULL};
  stackSpot b = {3,NULL};
  push(&myStack, &a);
  push(&myStack, &b);
  int printVal = getStackValFromStack(myStack, 1);
  if (printVal!= NULL){
    printf("%d\n", printVal);
  } else {
    printf("lol, RIP you. The code is messed up\n");
  }
  return 1;
}

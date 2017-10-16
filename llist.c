/*
Yuanchu Liu (Leo)
Systems 10
2017-10-16
linked list
*/

#include <stdio.h>
#include <stdlib.h>

struct node{
  int i;
  struct node *next;
};

void print_list(struct node * first){
  struct node * current = first;
  while(current){
    printf("%d, ", (*current).i);
    current = (*current).next;
  }
  printf("\n");
}

struct node * insert_front(struct node * first, int data){
  struct node * out = (struct node*) malloc(sizeof(struct node));
  (*out).i = data;
  if(first)
    (*out).next = first;
  return out;
}

struct node * free_list(struct node * first){
  struct node * current = first;
  while(current){
    struct node * next = (*current).next;
    free(current);
    current = next;
  }
  return 0;
}

int main(){
  struct node *linked_list = insert_front(0,5);
  linked_list = insert_front(linked_list,10);
  print_list(linked_list);
  linked_list = insert_front(linked_list,15);
  print_list(linked_list);
  linked_list = insert_front(linked_list,20);
  print_list(linked_list);
  linked_list = insert_front(linked_list,25);
  print_list(linked_list);
  free_list(linked_list);
  print_list(linked_list);
  return 0;
}

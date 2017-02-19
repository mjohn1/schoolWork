/* Michael John
 * February 11, 2015
 * I pledge my honor that I have abided by The Stevens Honor System
 * This is the testing program for the linked list
 */

#include "my.h"
#include "mylist.h"

int main()
{
  t_node *head;
  int e1 = 10;
  int e2 = 20;
  int e3 = 30;
  int e4 = 40;
  int e5 = 50;
  int temp = 0;
  char* s1 = "The";
  char* s2 = "Number";
  char* s3 = "Seven";
  t_node *n1 = (t_node*)xmalloc(sizeof(t_node*));
  t_node *n2 = (t_node*)xmalloc(sizeof(t_node*));
  t_node *n3 = (t_node*)xmalloc(sizeof(t_node*));
  t_node *n4 = (t_node*)xmalloc(sizeof(t_node*));
  t_node *n5 = (t_node*)xmalloc(sizeof(t_node*));


  /* Testing new_node */
  my_str("Trying to make a node\n");
  n1=new_node(&e1, NULL, NULL);
  if(*((int*)(n1->elem)) != 10)
    my_panic("You didn't make the node", 1);
  else
    my_str("You made the node!\n");
  head = n1;

  /* Testing add_node */
  my_str("testing add_node\n");
  n4 = new_node(&e4, NULL, NULL);
  add_node(n4, &head);
  /*  if(count_nodes(n4) < 2)
    my_panic("You did not add the node", 1);
  else
    my_str("You added the node!\n");
  */
  traverse_int(head);

  /* Testing add_elem */
  my_str("testing add_elem\n");
  add_elem(&e5, &head);
  /*  if(n4->prev == NULL)
    my_panic("You did not add the elem", 1);
  else
    my_str("You added the elem!\n"); */
  traverse_int(head);

  /* Testing append */
  my_str("testing append\n");
  n5 = new_node(&e1, NULL, NULL);
  append(n5, &head);
  if(count_nodes(head) < 3)// you may need to change this number
    my_panic("You did not append the node", 1);
  else
    my_str("You appended the node!\n");
  my_str("count_nodes also works\n");

  /* Testing add_node_at */
  my_str("Testing add_node_at\n");
  n2 = new_node(&e2, NULL, NULL);
  add_node_at(n2, &head, 1);
  if(n2->prev != n4)// you may need to change this number
    my_panic("You did not add the node", 1);
  else
    my_str("You added the node!\n");

  /* Testing traverse_int */
  my_str("Testing traverse_int");
  my_str("Should print 40 20 10 50\n");
     traverse_int(head); /* Should print 40 20 10 50 */

  /* Testing debug_int */
  my_str("Testing debug_int\n");
     debug_int(head);

  /* Testing node_at */
     n3 = node_at(head, 2);
  if(*((int*)(n3->elem)) != 30)
    my_panic("This is not the right node", 1);
  else
    my_str("You got it!\n");
  /* Testing elem_at */
  temp = *((int*)elem_at(head,3));
  if(temp != 50)
    my_panic("This is not the right elem", 1);
  else
    my_str("You got it!\n");

  /* Testing remove_last */
  my_str("Testing remove_last\n");
  temp = (*((int*)remove_last(&head)));
  if(temp != 50)
    my_panic("You did not removed the last node", 1);
  else
    my_str("You removed the last node!\n");

  /* Testing remove_node_at*/
  my_str("Testing remove_node_at with too large of a number\n");
  temp = *((int*)remove_node_at(&head, 5));
  if(temp != 10)
    my_panic("You did not remove the node", 1);
  else
    my_str("You removed the node!\n");

  my_str("Testing remove_node_at with a single node list\n");
  n3 = new_node(&e3, NULL, NULL);
  temp = *((int*)remove_node_at(&n3, 5)); 
  if(temp != 30)
    my_panic("You did not remove the node", 1);
  else
    my_str("You removed the node!\n");

  my_str("Testing remove_node_at\n");
  temp = *((int*)remove_node_at(&head, 1));
  if(temp != 20)
    my_panic("You did not remove the node", 1);
  else
    my_str("You removed the node!\n");

  /* Testing remove */
  my_str("Testing remove\n");
  temp = (*((int*)remove(&head)));
  if(temp != 40)
    my_panic("You did not remove the node", 1);
  else
    my_str("You removed the node!\n");

  /* Testing traverse_char */
  my_str("Testing traverse_char");
  free(n1);
  free(n2);
  free(n3);
  n1 = new_node(&s1, NULL, NULL);
  n2 = new_node(&s2, NULL, NULL);
  n3 = new_node(&s3, NULL, NULL);
  append(n2, &n1);
  append(n3, &n1);
  traverse_char(n1);

  /* Testing debug_char */
  my_str("Testing debug_char");
  debug_char(n1);
  
  /* Testing traverse_string */
  my_str("Testing traverse_string");
  traverse_string(n1);

  /* Testing debug_string */
  my_str("Testing debug_string");
  debug_string(n1);

  return 0;
}

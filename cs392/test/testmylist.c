#include "mylist.h"

int main()
{
  int arr[10] = {4, 65, 32, 1, 68, 23, 83, 12, 6, 82};
  char *str = "Hello!";
  char *str2 = "World!";
  t_node *head = NULL;
  unsigned int i;
  t_node *tmp = NULL;
  int n = 5;
  t_node **test = NULL;
  void *ret = NULL;
  for (i = 0; i < 3; i++)
    add_node(new_node(&arr[i], NULL, NULL), &head);
  traverse_int(head);
  debug_int(head); //1
  my_char('\n');
  for (; i < 7; i++)
    add_elem(&arr[i], &head);
  debug_int(head); //2
  my_char('\n');
  for (; i < 10; i++)
    append(new_node(&arr[i], NULL, NULL), &head);
  debug_int(head); //3
  my_char('\n');
  tmp = new_node(&n, NULL, NULL);
  add_node_at(tmp, &head, 5);
  debug_int(head); //4
  my_char('\n');
  add_node_at(new_node(&n, NULL, NULL), &head, 0);
  debug_int(head); //5
  my_char('\n');
  add_node_at(new_node(&n, NULL, NULL), &head, 564);
  debug_int(head); //6
  my_char('\n');
  my_int(count_nodes(head)); //13
  my_char('\n');
  ret = remove_node(&head);
  my_int(*((int*)ret)); //5
  my_char('\n');
  debug_int(head); //7
  my_char('\n');
  ret = remove_last(&head);
  my_int(*((int*)ret)); //5
  my_char('\n');
  debug_int(head); //8
  my_char('\n');
  ret = remove_node_at(&head, 0);
  my_int(*((int*)ret)); //83
  my_char('\n');
  debug_int(head); //9
  my_char('\n');
  ret = remove_node_at(&head, 243);
  my_int(*((int*)ret)); //82
  my_char('\n');
  debug_int(head); //10
  my_char('\n');
  ret = remove_node_at(&head, 3);
  my_int(*((int*)ret)); //32
  my_char('\n');
  debug_int(head); //11
  my_char('\n');
  empty_list(&head);
  debug_int(head); // This list is empty
  my_char('\n');
  add_elem(str2, &head);
  my_char('\n');
  add_elem(str, &head); 
  my_char('\n');
  debug_string(head); // (N<-Hello!->World!) (Hello!<-World!->N)
  my_char('\n');
  traverse_string(head); // Hello! World!
  my_char('\n');
  debug_char(head); //(N<-H->W) (H<-W->N) 
  my_char('\n');
  traverse_char(head); // H W
  my_char('\n');
  my_str((char*)elem_at(head, 0)); /* Hello! */
  my_char('\n');
  my_str((char*)elem_at(head, 43)); /* World! */
  my_char('\n');
  tmp = node_at(head, 0);
  print_string(tmp); // (N<-Hello!->World!)
  my_char('\n');
  tmp = node_at(head, 43);
  print_string(tmp); // (Hello!<-World!->N)
  my_char('\n');
  empty_list(&head); // The list is empty
  debug_string(head);
  /* this last one is mainly to clear memory */
  return 0;
}

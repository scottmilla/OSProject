#include "insertReady.h"

void insertReady(node *n) {

  if (readyhead == NULL) {
    readyhead = n;
  } else {
    node *tmp = readyhead;
    while (tmp->next != NULL) {
      printf("job %d in ready \n", tmp->job);
      tmp = tmp->next;
    }
    tmp->next = n;
  }
}

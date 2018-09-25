#include "insertdevnode.h"

// for device waiting queue
void insertdevnode(node *n) {

  if (devqhead == NULL) {
    devqhead = n;
  } else {
    node *tmp = devqhead;
    while (tmp->next != NULL) {
      
      tmp = tmp->next;
    }
    tmp->next = n;
  }
}


#include "global.h"
#include "getWords.h"
#include "getWords.c"
#include "getNum.h"
#include "getNum.c"
#include "insertNode.h"
#include "insertNode.c"
#include "sortedInsert.h"
#include "sortedInsert.c"
#include "insertdevnode.h"
#include "insertdevnode.c"
#include "insertReady.h"
#include "insertReady.c"
#include "readFile.h"
#include "readFile.c"

/* authors: Scott Miller & Paul Jureidini  */


void printQ();

int main(int argc, char *argv[]) {

  readFile(argc, argv);

  // print hq2
  printQ(readyhead);
  printQ(devqhead);
  printQ(hq2head);
  printQ(hq1head);

  return 0;
}



void printQ(node * head) {
 
    node *tmp = head;
  while (tmp->next != NULL) {
    printf("%d", tmp->job);
    printf("->");
    tmp = tmp->next;
  }
  printf("%d", tmp->job);
  printf("\n");

  
}






#include "readFile.h"

int readFile(int argc, char *argv[]) {

  FILE *fp;

  if (argc != 2) {
    fprintf(stderr, "Usage: %s <source-file>\n", argv[0]);
    return 1;
  }
  if ((fp = fopen(argv[1], "r")) == NULL) {
    perror("fopen source-file");
    return 1;
  }
  while (fgets(buf, sizeof(buf), fp) != NULL) {
    buf[strlen(buf) - 1] = '\0'; // eat newline fgets() stores
    printf("%s\n", buf);

    if (buf[0] == 'A') {

      node *newnode = (node *)malloc(sizeof(struct node));
      newnode->instruction = buf[0];

      node *newnode2 = (node *)malloc(sizeof(struct node));
      newnode2->instruction = buf[0];

      int n;
      int i;
      char arr[10][20];
      n = getWords(buf, arr);

      for (i = 0; i <= n; i++)
        printf("%s\n", arr[i]);
      int arrival;
      arrival = atoi(arr[1]);
      newnode->arrival = arrival;

      newnode->job = getNum(arr[2]);
      newnode->mem = getNum(arr[3]);
      newnode->max = getNum(arr[4]);
      newnode->run = getNum(arr[5]);
      newnode->pri = getNum(arr[6]);

	newnode2->arrival = arrival;

      newnode2->job = getNum(arr[2]);
      newnode2->mem = getNum(arr[3]);
      newnode2->max = getNum(arr[4]);
      newnode2->run = getNum(arr[5]);
      newnode2->pri = getNum(arr[6]);

      
      
      printf("total memory is %d, total dev is %d\n", totalmem, totaldev);
      currentmem = (currentmem - newnode2->mem);
      currentdev = (currentdev - newnode2->max);
      printf("current mem = %d, current dev = %d\n", currentmem, currentdev);
      // if theres not enough memory or devices

      // if theres enough resources in the system
      if((currentmem >= 0) && (currentdev >= 0)){
	insertReady(newnode2);
	}
      else{
	insertNode(newnode);
      }

   

    } // end 'A'

    if (buf[0] == 'C') {
 
	
      int n;
      int i;
      char arr[10][20];
      n = getWords(buf, arr);

      for (i = 0; i <= n; i++)
        printf("%s\n", arr[i]);

      totalmem = getNum(arr[2]); // M
      totaldev = getNum(arr[3]); // S
      quantum = getNum(arr[4]);  // Q
      currentmem = totalmem;
      currentdev = totaldev;
      printf("currentmem and current dev set, %d %d \n", currentmem, currentdev);
    } // end 'C'

    if (buf[0] == 'Q') {

      node *newnode = (node *)malloc(sizeof(struct node));
      newnode->instruction = buf[0];
      int n;
      int i;
      char arr[10][20];
      n = getWords(buf, arr);

      for (i = 0; i <= n; i++)
        printf("%s\n", arr[i]);
      int arrival;
      arrival = atoi(arr[1]);
      newnode->arrival = arrival;

      newnode->job = getNum(arr[2]);
      newnode->device = getNum(arr[3]);
      insertdevnode(newnode);


    } // end 'Q'

    if (buf[0] == 'L') {

      node *newnode = (node *)malloc(sizeof(struct node));
      newnode->instruction = buf[0];
      int n;
      int i;
      char arr[10][20];
      n = getWords(buf, arr);

      for (i = 0; i <= n; i++)
        printf("%s\n", arr[i]);
      int arrival;
      arrival = atoi(arr[1]);
      newnode->arrival = arrival;

      newnode->job = getNum(arr[2]);
      newnode->device = getNum(arr[3]);
      insertdevnode(newnode);


    } // end 'L'

    // sleep(1);

  } // while

  // printf("%d\n", newnode->job);

  fclose(fp);
  return 0;

} // end readFile


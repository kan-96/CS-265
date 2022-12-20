/*******************
 *
 *
 *
 *************************/


#include <stdio.h>
#include <stdlib.h>

struct time 
{
   int hr ;
   int min ;
   int sec ;
};
typedef struct sNode sNode ;

struct sNode
{
   int data ;
   sNode* next ;
};
struct time sec2hms( int secs)	{
	struct time day;
	day.hr = secs /3600;
	secs = secs %3600;
	day.min = secs/60;
	day.sec = secs %60;
	return day;
}
size_t listLength( const sNode *L)	{
	size_t cnt =0;
	while (L != NULL)	{
		cnt++;
		L = L->next;
	}
	return cnt;
}
sNode* listRev(sNode *L)	{
	sNode* prev = NULL;
	sNode* current = L;
	sNode* next = NULL;
	while (current != NULL)	{
		next = current->next;
		current->next = prev;
		prev = current;
		current = next;
	}
	L = prev;
	return L;
}
void push(struct sNode** head_ref, int new_data)
{
    struct sNode* new_node
        = (struct sNode*)malloc(sizeof(struct sNode));
    new_node->data = new_data;
    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}
 
/* Function to print linked list */
void printList(struct sNode* head)
{
    struct sNode* temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
}
int main ()	{
	int secs = 12000;
	struct time hours = sec2hms(secs);
	//printf ("hour: %d, minutes %d, secs: %d" , hours.hr, hours.min, hours.sec)
	/* Start with the empty list */
    struct sNode* head = NULL;

    push(&head, 20);
    push(&head, 4);
    push(&head, 15);
    push(&head, 85);

    printf("Given linked list\n");
    printList(head);
    head = listRev(head);
    printf("\nReversed linked list \n");
    printList(head);
	 printf ("Size of link list is %ld", listLength(head));
    getchar();
	return 0;
}

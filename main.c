// Implementation of merge sort using a linked List 
#include <stdio.h>
#include <stdlib.h>

//Define the link node as a struct
struct node{
    int data;
    struct node* next; 
};

//Prototypes
struct node* merge(struct node* head1, struct node* head2);
struct node* mergeSort(struct node* head, int size);
void printmainList(struct node* node);
int getLength(struct node* newmainList);

int main(){
    struct node* mainList = NULL;
	struct node* nodeTwo = NULL;
	struct node* nodeThree = NULL;
	struct node* nodeFour = NULL;
	struct node* nodeFive = NULL;
	struct node* nodeSix = NULL;
	int mainListSize;	
		
	//Construct the linked mainList
	mainList = (struct node*)malloc(sizeof(struct node));
    nodeTwo = (struct node*)malloc(sizeof(struct node));
	nodeThree = (struct node*)malloc(sizeof(struct node));
	nodeFour = (struct node*)malloc(sizeof(struct node));
	nodeFive = (struct node*)malloc(sizeof(struct node));
	nodeSix = (struct node*)malloc(sizeof(struct node));
	
	mainList->data = 38;
	mainList->next = nodeTwo; 

	nodeTwo->data = 22;
	nodeTwo->next = nodeThree;

	nodeThree->data = 2;
	nodeThree->next = nodeFour;

	nodeFour->data = 37;
	nodeFour->next = nodeFive;
	
	nodeFive->data = 5;
	nodeFive->next = nodeSix;

	nodeSix->data = 15;
	nodeSix->next = NULL;

	mainListSize = getLength(mainList);
	
	printf("mainList Unsorted: \n");
	printmainList(mainList);
	printf("mainList Sorted: \n");
	printmainList(mergeSort(mainList, mainListSize));
}

//Merge takes two pointers as parameters, each pointing to a sorted (sub) mainList, 
//     and returns a new head pointer pointing to the merged mainList. 
struct node* merge(struct node * head1, struct node * head2){
    struct node* result = NULL;
	
	if(head1 == NULL){
		return (head2);
	} else if(head2 == NULL){
		return (head1);
	}

	if (head1->data <= head2->data){
		result = head1;
		result->next = merge(head1->next, head2);
	}else{
		result = head2;
		result-> next = merge(head1, head2->next);
	}

	return (result);
}

struct node* mergeSort(struct node* head, int size){
	struct node* head1 = head;
	int mid = size / 2;
	
	if(head->next == NULL){
		return head;
	}
	
	while(mid - 1 > 0){
		head1 = head1->next;
		mid--;
	}

	struct node* head2 = head1->next;
	head1->next = NULL;
	head1 = head;
	struct node* h1 = mergeSort(head1, getLength(head1));
	struct node* h2 = mergeSort(head2, getLength(head2));

	return merge(h1, h2);
}

//Prints the linked mainLists
void printmainList(struct node* node){
	while(node != NULL){
		printf("%d ", node->data);
		node = node->next;
	}
	printf("\n");
}

//Get the lenth of the linked mainList
int getLength(struct node* newmainList){
	int count = 0;
	struct node* mainList = newmainList;
		
	while(mainList != NULL){
		count++;
		mainList = mainList->next;
	}
	return count;
}

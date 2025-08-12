#include<stdio.h>
#define MAX 5
int CQ[MAX],front=-1, rear=-1,value;
int isFull(){
    if((rear+1)%MAX==front)
        return 1;
    else return 0;
}
void insert(){
    if(isFull())
        printf("Circular Queue is Overflow.");
    else{
        printf("Enter a value:");
        scanf("%d",&value);
        rear=(rear+1)%MAX;
        CQ[rear]=value;
        if(front==-1)
                front++;
        printf("Insertion Done.");
    }
}
int isEmpty(){
    if(front==-1)
        return 1;
    else return 0;
}
void del(){
    if(isEmpty())
        printf("Circular Queue is Underflow.");
    else{
        printf("%d is Deleted.",CQ[front]);
        if(front==rear)
                front=rear=-1;
        else
            front=(front+1)%MAX;
    }
}
void peek(){
    if(isEmpty())
        printf("Circular Queue is Empty.");
    else
        printf("Last inserted value is %d",CQ[rear]);
}
void display(){
    int i;
    if(isEmpty())
        printf("Circular Queue is Empty.");
    else{
        printf("Circular Queue is: ");
        for(i=front;i!=rear;i=(i+1)%MAX)
            printf("%d ",CQ[i]);
        printf("%d",CQ[rear]);
    }
}
void change(){
    int index, newvalue;
   // printf("Enter an index and a newvalue");
   // scanf("%d%d",&index,&newvalue);
    printf("Enter an index:");
    scanf("%d",&index);
    if(front<=rear){
            if(index > rear-front+1 || index<=0)

                printf("Invalid Index");
            else{
                printf("Enter a new value");
                scanf("%d",&newvalue);
                CQ[index+front-1]=newvalue;
                printf("New Value Updated.");
            }
    }
    else{
            if(index > (MAX-front+rear+1) || index<=0)
                printf("Invalid Index");
            else{
                printf("Enter new value");
                scanf("%d",&newvalue);
                CQ[(index+front-1)%MAX]=newvalue;
                printf("New Value Updated.");
            }
    }
}
int search(){
    int index,valueToSearch;
    // printf("Enter an index and a newvalue");
    // scanf("%d%d",&index,&newvalue);
    printf("Enter the value to be searched:");
    scanf("%d",&valueToSearch);
    if(isEmpty())
        printf("Circular Queue is Empty.");
    else{
        int i = front;
        if(front <= rear) {
            for(;i!=rear; i=(i+1)%MAX)
                if(CQ[i] == valueToSearch)
                    return i+front-1; // return the index
        }
        else {
            for(;i!=rear; i=(i+1)%MAX)
                if(CQ[i] == valueToSearch)
                    return (i+front-1)%MAX;
        }
    }
    printf("Value not found in Circular Queue.");
    return -1; // Return -1 to indicate that the value is not found
}
void main(){
    int ch;
    while(1){
        printf("\n\nCircular Queue Operations:");
        printf("\n1. Insert\n2. Delete\n3. Peek\n4. Change \n5. Search \n6. Display\n7. isFull\n8. isEmpty\n9. Exit");
        printf("\nEnter Your Choice:");
        scanf("%d",&ch);
        switch(ch){
            case 1: insert(); break;
            case 2: del();  break;
            case 3: peek(); break;
            case 4: change();   break;
            case 5: search();   break;
            case 6: display();  break;
            case 7: if(isFull())
                        printf("Yes, Circular Queue is Full.");
                    else
                        printf("No, Circular Queue is not Full.");
                    break;
            case 8: if(isEmpty())
                    printf("Yes, Circular Queue is Empty.");
                    else
                        printf("No, Circular Queue is not Empty.");
                    break;
            case 9: exit(0);
            default: printf("Invalid Choice..");
        }
    }
}
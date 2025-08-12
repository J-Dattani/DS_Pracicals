#include<stdio.h>

void main(){

    int a,b;
    printf("Enter value of a: ");
    scanf("%d", &a);

    printf("Enter value of b: ");
    scanf("%d", &b);


    printf("Before Swap: \n");
    printf("a: %d \n", a);
    printf("b: %d", b);

    swap(&a,&b);

}
void swap(int *a, int *b){
    int temp;

    temp = *a;
    *a = *nb;
    *b = temp;

    printf("\nAfter Swap: \n");
    printf("a: %d\n", *a);
    printf("b: %d", *b);
}


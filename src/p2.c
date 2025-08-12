#include<stdio.h>
#include <stdlib.h>

struct stud {

    int enroll,marks;
    char name[20];

};
int main() {
    int i,n;
    struct stud *p;
    printf("Enter number of students: ");
    scanf("%d", &n);


    p = (struct stud *) malloc(sizeof(struct stud));
    p = (struct stud *) calloc(n, sizeof(struct stud));

    if (p==NULL) {
        printf("\n Memory not available");

    }

    printf("Enter Student Details:\n");

    for (i=0;i<n;i++) {
        printf("Enter Enroll: ");
        scanf("%d",&(p[i].enroll));
        printf("Enter Name: ");
        scanf("%s",&(p[i].name));
        printf("Enter Marks: ");
        scanf("%d",&(p[i].marks));

    }

    printf("\nStudent Details:\n Enroll\t Name\t Marks");
    for (i=0;i<n;i++) {
        printf("\n%d\t%s\t%d",p[i].enroll,p[i].name,p[i].marks);
    }
    free(p);
    return 0;

}
#include <stdio.h>
#include <stdlib.h>


void push_studentInfo(int std_RollNo,int std_RollNo1);
void pop_studentInfo();
void display();
void student_count();
void create();
void runApplication();
int count_numofStudent = 0;



/*Declare struct and here store rollno,age and also declare inner struct(student)*/

struct node
{
    int rollno;
    int age;
    struct node *student;
}*store,*store1,*temp_store;

void main()
{


    runApplication();
}


void runApplication()
{


    int std_roll,std_age,chose;
    /*Here print some information than can helps to choose*/
    printf("\n 1 - Push Student Information");
    printf("\n 2 - Pop Student Information");
    printf("\n 3 - Display All The Student Info");
    printf("\n 4 - Count Total Student");
    printf("\n 5  -Exit");
    create();

    while (1)
    {

        printf("\n Please Select an Item : ");

        scanf("%d", &chose);

        switch (chose)
        {

        case 1:
            printf("\nEnter Student RollNo : ");
            /*input std_roll*/
            scanf("%d", &std_roll);
            printf("\nEnter Student Age : ");
            /*input std_age*/
            scanf("%d", &std_age);
            /*passing parameter std_roll and std_age into the push_studentInfo function*/
            push_studentInfo(std_roll,std_age);
            break;
        case 2:
            pop_studentInfo();
            break;
        case 3:
            display();
            break;
        case 4:
            student_count();
            break;
        case 5:
            exit(0);
        default :
            printf(" Wrong choice, Please Choice Correctly");
            break;
        }
    }
}

/* Create empty stack */

void create()
{
    store = NULL;
}

/* Count the number of student  from stack elements */

void student_count()
{
    printf("\n No. of elements in stack : %d", count_numofStudent);
}
/* Here declate push_studentInfo function pass tow parameter data and data1 */
void push_studentInfo(int data,int data1)
{
    /* check store is NUll or or if Null then perform following function */

    if (store == NULL)
    {
        /* Here initization the store node*/
        store =(struct node *)malloc(1*sizeof(struct node));
        /* Here initization the student NUll*/
        store->student = NULL;
        /* Then store student rollno*/
        store->rollno = data;
        /* Then store student age*/
        store->age = data1;
    }
    else
    {
        /* check store is not NUll then perform following function */
        temp_store =(struct node *)malloc(1*sizeof(struct node));
        /* Initization student node using the store value*/
        temp_store->student = store;
        /* Then store student rollno*/
        temp_store->rollno = data;
        /* Then store student age*/
        temp_store->age = data1;
        store = temp_store;
    }
    /* Count the number of student*/
    count_numofStudent++;
}
/* Declare the Display function*/

void display()
{
    /* assain the store1= store*/
    store1 = store;
    /* Check store1 null or not*/
    if (store1 == NULL)
    {
        /* If null show message*/
        printf("\n  ***Stack is empty***");
        return;
    }

    while (store1 != NULL)
    {
        /* If store1 not null show message*/
        printf(" \nRoll No : %d , Age : %d\n ", store1->rollno,store1->age);
        store1 = store1->student;
    }
}

/* Declare the POP up function */

void pop_studentInfo()
{
    /* assain the store1= store*/
    store1 = store;
    /* Check store1 null or not*/
    if (store1 == NULL)
    {
        /* If null show message*/
        printf("\n Error : Trying to pop from empty stack");
        return;
    }
    else
        /* If not null store the student information*/
        store1 = store1->student;
    /* then pop the student information*/
    printf(" \n Popped->  Roll No : %d , Age : %d\n ", store->rollno,store->age);
    /* then call malloc free function*/
    free(store);
    /*Assain the value*/
    store = store1;
    /*Decrement the number of student*/
    count_numofStudent--;
}



#include <stdio.h>
#include <stdlib.h>

//tek yönlü baðlý liste kullanarak öðrenci kayýt uygulamasý
typedef struct student
{
    int no;
    char ad[40];
    int mid,fiNal;
    double avg;
    struct student *next;
};
typedef struct student node;
node *add(node *head)
{
    node *std=(node *)malloc(sizeof(node));
    printf("std number:");
    scanf("%d",&std->no);
    printf("std name:");
    scanf("%s",&std->ad);
    printf("std mid:");
    scanf("%d",&std->mid);
    printf("std final:");
    scanf("%d",&std->fiNal);
    std->avg=std->mid*0.4+std->fiNal*0.6;
    if(head==NULL)
    {
        head=std;//roota ilk düðümü attýk
        head->next=NULL;
        printf("the list created,first student added \n");
    }
    else
    {
        std->next=head;
        head=std;
        printf("student added \n");


    }

    return head;

}
node *del(node *head)
{
    if(head==NULL)
    {
        printf("the list is empty,no students to remove \n");
    }
    else
    {
        int stdNo;
        printf("student number: ");
        scanf("%d",&stdNo);
        if(head->no==stdNo&&head->next==NULL)
        {
            free(head);
            head=NULL;
            printf("last student on the list has been removed \n");
        }
        else if(head->no==stdNo&&head->next!=NULL)
        {
            node *temp=head->next;
            free(head);
            head=temp;
            printf("the student has %d number has been removed \n",stdNo);
        }
        else
        {
            node *temp=head;
            node *iter=head;
            while(temp->next!=NULL)
            {
                if(temp->no==stdNo)
                {
                    iter->next=temp->next;
                    free(temp);
                    printf("the student has %d number has been removed \n",stdNo);
                    break;
                }
                iter=temp;
                temp=temp->next;
            }
            if(temp->no==stdNo)
            {
                iter->next==NULL;
                free(temp);
                printf("the student has %d number has been removed \n",stdNo);
            }
        }
    }
    return head;
}
node *print(node *head)
{
    system("cls");
    if(head==NULL)
    {
        printf("list is empty \n");
    }
    else
    {
        node *p=head;
        while(p!=NULL)
        {
            printf("**************");
            printf("no : %d name : %s mid : %d final: %d average %.2f \n",p->no,p->ad,p->mid,p->fiNal,p->avg);
            p=p->next;
        }


    }
    return head;
}
node *bestStudent(node *head)
{
    system("cls");

    if(head==NULL)
    {
        printf("list is empty \n ");
    }
    else
    {   int highScore=head->avg;
        node *highNode=head;
        node *p=head;
        while(p!=NULL)
        {
            if(highScore< p->avg)
            {
                highScore=p->avg;
                highNode=p;//en büyük node p oldu
            }
            p=p->next;
        }
        printf("the student with the highest scores :\n");
        printf("no : %d name : %s mid : %d final: %d average %.2f \n",highNode->no,highNode->ad,highNode->mid,highNode->fiNal,highNode->avg);

    }

    return head;
}

int main()
{
    int choise;
    node *head=NULL;
    while(1)
    {
        printf("--**STUDENT MANAGEMENT SYSTEM**--\n");
        printf("1--add \n");
        printf("2--remove \n");
        printf("3--print \n");
        printf("4--best student \n");
        printf("0--exit \n");
        scanf("%d",&choise);
        switch(choise)
        {
        case 1:
            head=add(head);
            break;
        case 2:
            head=del(head);

            break;
        case 3:
            head=print(head);

            break;
        case 4:
            head=bestStudent(head);

            break;
        case 0:
            exit(0);
            break;
        default:
            printf("wrong choise");
        }


    }


}

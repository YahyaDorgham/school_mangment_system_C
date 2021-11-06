#include <stdio.h>
#include <stdlib.h>
//*******************************STUDENT STRUCT***********************
struct student
{
    int id;
    int lavel;//when admin enter the level of student the subject of the level will be hi subjects
    char name[15];
    float grades[2];
    char subject[2][10];
    struct student *next;
};
struct student *st_head=NULL;

//*******************************TEACHER STRUCT***********************
struct teacher
{
    int id;
    char name[15];
    char subject[2][10];
    int salary;
    struct node *next;
};
struct teacher *tch_head=NULL;
//*******************************LAVELS STRUCT***********************
struct lavell
{
    int lav;
    char subject_lavel1 [5][10];
    char subject_lavel2 [5][10];
    char subject_lavel3 [5][10];

} lavel;




void add_level()
{
    int n;
    printf("Enter a LEVAL \n");
    scanf("%d",&lavel.lav);


    switch(lavel.lav)
    {
    case 1:
        printf("enter num of subject");
        scanf("%d",&n);
        for(int i=0; i<n; i++)
        {
            printf("Enter subject %d \n",i+1);

            scanf("%s",&lavel.subject_lavel1[i]);
        }
        break;
    case 2:
        printf("enter num of subject");
        scanf("%d",&n);
        for(int i=0; i<n; i++)
        {
            printf("Enter subject %d \n",i+1);

            scanf("%s",&lavel.subject_lavel2[i]);
        }
        break;
    case 3:
        printf("enter num of subject");
        scanf("%d",&n);
        for(int i=0; i<n; i++)
        {
            printf("Enter subject %d \n",i+1);

            scanf("%s",&lavel.subject_lavel3[i]);
        }
        break;

    }
}

//*******************************ADD STUDENT***********************

void add_st()
{
    struct student *new_student = NULL;
    new_student = (struct student*)malloc(sizeof(struct student));

    printf("Enter a name \n");
    scanf("%s",&new_student->name);

    printf("Enter a ID \n");
    scanf("%d",&new_student->id);

    printf("Enter a LEVAL \n");
    scanf("%d",&new_student->lavel);


    switch(new_student->lavel)
    {
    case 1:
        new_student->subject[5][10]=lavel.subject_lavel1 [5][10];
        break;
    case 2:
        new_student->subject[5][10]=lavel.subject_lavel2 [5][10];
        break;
    case 3:
        new_student->subject[5][10]=lavel.subject_lavel3 [5][10];
        break;

    }

    for(int i=0; i<2; i++)
    {
        printf("Enter subject %d grade \n",i+1);

        scanf("%f",&new_student->grades[i]);
    }


    new_student->next=NULL;
    if(st_head == NULL)
        st_head = new_student;
    else
    {
        new_student->next=st_head;
        st_head=new_student;
    }
}
//**************************************************************
void print_students_list()
{
    printf("***********************************\n");
    struct student *temp=st_head;

    while (temp != NULL)
    {
        printf("ID: %d \n", temp->id);
        printf("NAME: %s \n", temp->name);
        printf("LAVEL: %d \n", temp->lavel);
        switch(temp->lavel)
        {
        case 1:
            for(int i=0; i<2; i++)
                printf("subject %s grade: %f  \n",lavel.subject_lavel1[i],temp->grades[i]);
            break;
        case 2:
            for(int i=0; i<2; i++)
                printf("subject %s grade: %f  \n",lavel.subject_lavel2[i],temp->grades[i]);
            break;
        case 3:
            for(int i=0; i<2; i++)
                printf("subject %s grade: %f  \n",lavel.subject_lavel3[i],temp->grades[i]);
            break;
        }
        temp= temp->next;
    }
    printf("\n");
}


//**************************************************************

void add_tch()
{
    struct teacher *new_teacher = NULL;
    new_teacher  = (struct student*)malloc(sizeof(struct student));

    printf("Enter a name \n");
    scanf("%s",&new_teacher ->name);

    printf("Enter a ID \n");
    scanf("%d",&new_teacher ->id);

    printf("Enter a salary \n");
    scanf("%d",&new_teacher ->salary);

    for(int i=0; i<2; i++)
    {
        printf("Enter subject %d \n",i+1);

        scanf("%s",&new_teacher ->subject[i]);
    }

    new_teacher ->next=NULL;
    if(tch_head == NULL)
        tch_head = new_teacher;
    else
    {
        new_teacher ->next=tch_head;
        tch_head=new_teacher ;
    }
}


//**************************************************************
void print_teachers_list()
{
    printf("***********************************\n");
    struct teacher *temp=tch_head;

    while (temp != NULL)
    {
        printf("ID: %d \n", temp->id);
        printf("NAME: %s \n", temp->name);
        printf("SALARY: %d \n", temp->salary);

        for(int i=0; i<2; i++)
            printf("subject %d: %s \n",i+1,temp->subject[i]);

        temp= temp->next;
    }
    printf("\n");
}
//*********************************************************************************
void st_info( int st_id)
{
    printf("***********************************\n");
    struct student *temp=st_head;

    while (temp != NULL)
    {
        if(st_id==temp->id)
        {
            printf("ID: %d \n", temp->id);
            printf("NAME: %s \n", temp->name);
            printf("LAVEL: %d \n", temp->lavel);
            switch(temp->lavel)
            {
            case 1:
                for(int i=0; i<2; i++)
                    printf("subject %s grade: %f  \n",lavel.subject_lavel1[i],temp->grades[i]);
                break;
            case 2:
                for(int i=0; i<2; i++)
                    printf("subject %s grade: %f  \n",lavel.subject_lavel2[i],temp->grades[i]);
                break;
            case 3:
                for(int i=0; i<2; i++)
                    printf("subject %s grade: %f  \n",lavel.subject_lavel3[i],temp->grades[i]);
                break;
            }
            return ;

        }

        temp= temp->next;
    }
    printf("wrong id \n");

}
//***********************************************************************************
void tch_info(int tch_id)
{
    printf("***********************************\n");
    struct teacher *temp=tch_head;

    while (temp != NULL)
    {

        if(tch_id==temp->id)
        {
            printf("ID: %d \n", temp->id);
            printf("NAME: %s \n", temp->name);
            printf("SALARY: %d \n", temp->salary);

            for(int i=0; i<2; i++)
                printf("subject %d: %s \n",i+1,temp->subject[i]);


            return ;

        }

        temp= temp->next;
    }
    printf("wrong id \n");

}







int main()
{
    //adminn pass is 5566

    int user,op,out_of_loop=1;
    int another_user=1;
    int st_id,tch_id;
    int pass,i=0;
    while(another_user)
    {
        printf("adminn enter 1 / student enter 2 / teacher enter 3 \n");
        scanf("%d",&user);
        switch(user)
        {
        case 1:

            printf("please enter the pass\n");
            scanf("%d",&pass);
            out_of_loop=1;

            while(pass!=5566)
            {
                if(i==2)
                {
                    printf("incorrect pass for 3 times ");
                    return 0;
                }
                printf("try again\n");
                scanf("%d",&pass);


                i++;
            }
            while(out_of_loop)
            {
                printf("welcome: \n for add student 1 \n add teacher 2 \n print students list 3 \n print teachers list 4 \n for add subject to level 5 \n ");

                scanf("%d",&op);
                switch(op)
                {
                case 1:
                    add_st();
                    break;
                case 2:
                    add_tch();
                    break;
                case 3:
                    print_students_list();
                    break;
                case 4:
                    print_teachers_list();
                    break;
                case 5:
                    add_level();
                    break;
                }
                printf("for more operation press 1 \n for out 0 \n");
                scanf("%d",&out_of_loop);
            }
            break;

        case 2:
            printf("please enter student id\n");
            scanf("%d",&st_id);
            st_info(st_id);
            break;
        case 3:
            printf("please enter teacher id\n");
            scanf("%d",&tch_id);
            tch_info(tch_id);
            break;

        }
        printf("for another user press 1 \n for out 0 \n");
        scanf("%d",&another_user);

    }

    return 0;


}

#include <stdio.h>
#include <malloc.h>
#include "graph.h"
#include "FileIO_text.h"

void insertStudent();
void displaySpecificStudent();
void displayAll();
void deleteStudent();
void generateGraph();
void FileIOSingle();
void FileIOFull();
void FileIOCSVSingle();
void FileIOCSVFull();

struct student{
    char fName[10];
    int rollNo;
    int deco, ds, java, dms, mpi;
    float per;
    struct student *linkP, *linkN;
};
struct student *head=NULL, *tail=NULL;

void main(){
    int ch=0;
    while(1){
        printf("\n\n\nSelect option from below menu:");
        printf("\n1. Add student");
        printf("\n2. Delete student");
        printf("\n3. Display record of specific student");
        printf("\n4. Display record of all student");
        printf("\n5. Generate a .py script for graph");
        printf("\n6. Export any record to text file.");
        printf("\n7. Export all records to text file.");
        printf("\n8. Export all records to csv");
        printf("\n9. Export single record to csv");
        printf("\n10. Exit");
        printf("\n\nEnter your choice: ");
        scanf("%d",&ch);
        switch(ch){
            case 1: insertStudent();
                    break;
            case 2: deleteStudent();
                    break;
            case 3: displaySpecificStudent();
                    break;
            case 4: displayAll();
                    break;
            case 5: generateGraph();
                    break;
            case 6: FileIOSingle();
                    break;
            case 7: FileIOFull();
                    break;
            case 8: FileIOCSVSingle();
                    break;
            case 9: FileIOCSVFull();
                    break;
            case 10: exit(0);
                    break;
            default: printf("\n\nENTER VALID CHOICE!!");
        }
    }
}

void insertStudent()  
{  
    struct student *ptr;   
    ptr = (struct student *)malloc(sizeof(struct student));  
    if(ptr == NULL){  
        printf("\nOVERFLOW!!!");  
    }  
    else{  
        if(head==NULL) {  
            ptr->linkP = NULL;  
            ptr->linkN = NULL;  
            printf("\nEnter name of student: ");  
            scanf("%s",&(ptr->fName));
            printf("\nEnter roll no of %s: ",ptr->fName);  
            scanf("%d",&(ptr->rollNo));
            printf("\nEnter DS marks of %s: ",ptr->fName);  
            scanf("%d",&(ptr->ds));
            printf("\nEnter DMS marks of %s: ",ptr->fName);  
            scanf("%d",&(ptr->dms));
            printf("\nEnter MPI marks of %s: ",ptr->fName);  
            scanf("%d",&(ptr->mpi));
            printf("\nEnter JAVA marks of %s: ",ptr->fName);  
            scanf("%d",&(ptr->java));
            printf("\nEnter DECO marks of %s: ",ptr->fName);  
            scanf("%d",&(ptr->deco));
            ptr->per = (ptr->ds + ptr->dms + ptr->mpi + ptr->deco + ptr->java)/5;
            head=tail=ptr;
        }
        else{
            tail->linkN = ptr;  
            ptr ->linkP=tail;  
            ptr->linkN = NULL; 
            tail=ptr;
            printf("\nEnter name of student: ");  
            scanf("%s",&(ptr->fName));
            printf("\nEnter roll no of %s: ",ptr->fName);  
            scanf("%d",&(ptr->rollNo));
            printf("\nEnter DS marks of %s: ",ptr->fName);  
            scanf("%d",&(ptr->ds));
            printf("\nEnter DMS marks of %s: ",ptr->fName);  
            scanf("%d",&(ptr->dms));
            printf("\nEnter MPI marks of %s: ",ptr->fName);  
            scanf("%d",&(ptr->mpi));
            printf("\nEnter JAVA marks of %s: ",ptr->fName);  
            scanf("%d",&(ptr->java));
            printf("\nEnter DECO marks of %s: ",ptr->fName);  
            scanf("%d",&(ptr->deco));  
            ptr->per = (ptr->ds + ptr->dms + ptr->mpi + ptr->deco + ptr->java)/5;
        }
        printf("\n\nDATA OF %s INSERTED SUCCESFULLY\n",ptr->fName);  
    }  
}

void displaySpecificStudent(){  
    int a;
    struct student *temp;
    temp = head;
    printf("\n\nEnter roll no of student to display data: ");
    scanf("%d",&a);
    if(temp != NULL){
        while(temp->rollNo!=a){  
            if(temp->linkN == NULL){
                break;
            }
            else{
                temp = temp->linkN;                
            }
        }  
    }
    if(head == NULL){
        printf("\n\nUNDERFLOW!!!");
    }
    else if(temp->rollNo==a){
        printf("\n\nDETAILS OF STUDENT IS AS BELLOW: ");
        printf("\n\nNAME:     %s",temp->fName);
        printf("\nROLL NO:    %d",temp->rollNo);
        printf("\nDS MARKS:   %d",temp->ds);
        printf("\nDMS MARKS:  %d",temp->dms);
        printf("\nMPI MARKS:  %d",temp->mpi);
        printf("\nJAVA MARKS: %d",temp->java);
        printf("\nDECO MARKS: %d",temp->deco);
        printf("\nPERCENTAGE: %.2f",temp->per);
    }
    else{
        printf("\n\nWRONG DATA PLEASE ENTER VALID ROLL NUMBER!!");
    }
}

void deleteStudent(){  
    struct student *ptr, *temp;  
    int a;  
    printf("\n\nEnter roll no of student to delete his/her data: ");  
    scanf("%d", &a);
    ptr = head;  
    if(ptr!=NULL){
        while(ptr->rollNo!=a){  
            if(ptr->linkN == NULL){
                break;
            }
            else{
                ptr = ptr->linkN;                
            }
        }  
    }
    if(head == NULL){
        printf("\n\nUNDERFLOW!!!");
    }
    else if(ptr->rollNo != a){  
        printf("\n\nWRONG DATA PLEASE ENTER VALID ROLL NUMBER!!");
    }
    else if(ptr->linkN==NULL && ptr->linkP==NULL){   
        printf("\n\nDATA OF STUDENT HAVING ROLL NUMBER %d IS DELETED.", ptr->rollNo);
        free(ptr);  
        head = tail = NULL;
    }     
    else if(ptr->linkN==NULL){  
        printf("\n\nDATA OF STUDENT HAVING ROLL NUMBER %d IS DELETED.", ptr->rollNo);
        ptr->linkP->linkN=NULL;
        tail = ptr->linkP;
        free(ptr);  
    }
    else if(ptr->linkN!=NULL && ptr->linkP!=NULL){
        printf("\n\nDATA OF STUDENT HAVING ROLL NUMBER %d IS DELETED.", ptr->rollNo);
        ptr->linkP->linkN=ptr->linkN;
        ptr->linkN->linkP=ptr->linkP;
        free(ptr);  
    }
}  

void displayAll(){  
    struct student *temp;
    temp = head;
    int i = 1;
    if(head == NULL){
        printf("\n\nUNDERFLOW!!!");
    }
    else{
        printf("\n\n\n");
        printf("|SR.NO   |ROLL_NO   |NAME        |DS     |DMS    |MPI    |JAVA   |DECO   |PERCENTAGE|");
        printf("\n-------------------------------------------------------------------------------------");
        do{  
              printf("\n|%-6d  |%-8d  |%-10s  |%-5d  |%-5d  |%-5d  |%-5d  |%-5d  |%10.2f|",i,temp->rollNo,temp->fName,temp->ds,temp->dms,temp->mpi,temp->java,temp->deco,temp->per);
              i++;
              temp = temp->linkN  ;
        }while(temp!=NULL);
    }
}

void FileIOSingle(){
    int a;
    struct student *temp;
    temp = head;
    printf("\n\nEnter roll no of student to display data: ");
    scanf("%d",&a);
    if(temp != NULL){
        while(temp->rollNo!=a){  
            if(temp->linkN == NULL){
                break;
            }
            else{
                temp = temp->linkN;                
            }
        }  
    }
    if(head == NULL){
        printf("\n\nUNDERFLOW!!!");
    }
    else if(temp->rollNo==a){
        int roll = temp->rollNo;
        int ds = temp->ds;
        int dms = temp->dms;
        int mpi = temp->mpi;
        int java = temp->java;
        int deco = temp->deco;
        int per = temp->per;
        printf("\n\nTEXT FILE GENERATED");
        fileWritetxtSingle(roll, ds, dms, mpi, java, deco, per);
    }
    else{
        printf("\n\nWRONG DATA PLEASE ENTER VALID ROLL NUMBER!!");
    }
}

void FileIOCSVSingle(){
    int a;
    struct student *temp;
    temp = head;
    printf("\n\nEnter roll no of student to display data: ");
    scanf("%d",&a);
    if(temp != NULL){
        while(temp->rollNo!=a){  
            if(temp->linkN == NULL){
                break;
            }
            else{
                temp = temp->linkN;                
            }
        }  
    }
    if(head == NULL){
        printf("\n\nUNDERFLOW!!!");
    }
    else if(temp->rollNo==a){
        int roll = temp->rollNo;
        int ds = temp->ds;
        int dms = temp->dms;
        int mpi = temp->mpi;
        int java = temp->java;
        int deco = temp->deco;
        int per = temp->per;
        printf("\n\nCSV FILE GENERATED");
        fileWritecsvSingle(roll, ds, dms, mpi, java, deco, per);
    }
    else{
        printf("\n\nWRONG DATA PLEASE ENTER VALID ROLL NUMBER!!");
    }
}

void FileIOFull(){
    FILE *fptr;
    fptr = fopen("singlerecord.txt", "w");
    struct student *temp;
    temp = head;
    int i = 1;
    if(head == NULL){
        printf("\n\nUNDERFLOW!!!");
    }
    else{
        fprintf(fptr,"\n\n\n");
        fprintf(fptr,"|SR.NO   |ROLL_NO   |NAME        |DS     |DMS    |MPI    |JAVA   |DECO   |PERCENTAGE|");
        fprintf(fptr,"\n-------------------------------------------------------------------------------------");
        do{  
              fprintf(fptr,"\n|%-6d  |%-8d  |%-10s  |%-5d  |%-5d  |%-5d  |%-5d  |%-5d  |%10.2f|",i,temp->rollNo,temp->fName,temp->ds,temp->dms,temp->mpi,temp->java,temp->deco,temp->per);
              i++;
              temp = temp->linkN  ;
        }while(temp!=NULL);
    }
    fclose(fptr);
}

void generateGraph(){
    int a;
    struct student *temp;
    temp = head;
    printf("\n\nEnter roll no of student to display data: ");
    scanf("%d",&a);
    if(temp != NULL){
        while(temp->rollNo!=a){  
            if(temp->linkN == NULL){
                break;
            }
            else{
                temp = temp->linkN;                
            }
        }  
    }
    if(head == NULL){
        printf("\n\nUNDERFLOW!!!");
    }
    else if(temp->rollNo==a){
        int roll = temp->rollNo;
        int ds = temp->ds;
        int dms = temp->dms;
        int mpi = temp->mpi;
        int java = temp->java;
        int deco = temp->deco;
        int per = temp->per;
        printf("\n\nPYTHON SCRIPT OF GRAPH OF STUDENT IS GENERATED!! EXIT THE PROGRAM TO SAVE THE FILE!!");
        graph_script(ds, deco, dms, java, mpi);
    }
    else{
        printf("\n\nWRONG DATA PLEASE ENTER VALID ROLL NUMBER!!");
    }
}

void FileIOCSVFull(){
    FILE *fptr;
    fptr = fopen("singlerecord.csv", "w");
    struct student *temp;
    temp = head;
    int i = 1;
    if(head == NULL){
        printf("\n\nUNDERFLOW!!!");
    }
    else{
        fprintf(fptr,"\n\n\n");
        fprintf(fptr,"SR.NO,ROLL_NO,NAME,DS,DMS,MPI,JAVA,DECO,PERCENTAGE");
        do{
            fprintf(fptr,"\n%-6d,%-8d,%-10s,%-5d,%-5d,%-5d,%-5d,%-5d,%10.2f",i,temp->rollNo,temp->fName,temp->ds,temp->dms,temp->mpi,temp->java,temp->deco,temp->per);
            i++;
            temp = temp->linkN;
        }while(temp!=NULL);
    }
    fclose(fptr);
}
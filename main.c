#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct book{
    char name[100];
    int nopages;
    int price;
    int copies;
    char author[100];
    int code;
}b;
void menu(void);
void add();
void search();
void view();
void s1();
void s2();
void s3();
void borrow();
void takeinfo(int g);
void dispinfo();
void main()
{
    int n=1;
    while(n){
    printf("\t\t\t\t* * * LIBRARY MANAGEMENT SYSTEM * * *\n");
    printf(">>1.MAIN MENU\n>>2.EXIT\n");
    scanf("%d",&n);
    if(n==2){
        exit(0);
    }
    if(n){
        menu();
    }
    }
}
void menu(){
    printf("\t\t** MAIN MENU **\n");
    printf(">>1.ADD BOOK\n");
    printf(">>2.SEARCH BOOK\n");
    printf(">>3.VIEW LIBRARY\n");
    printf(">>4.Display borrow info\n");
    printf("ENter YOur choice :");
    int n;
    scanf("%d",&n);
    switch(n){
        case 1:{
            add();
            break;
        }
        case 2:{
            search();
            break;
        }
        case 3:{
            view();
            break;
        }
        case 4:{
            dispinfo();
            break;
        }
        default:{
            printf("Enter valid choice\n");
        }
    }
}
void add()
{
    printf("Enter the following details to add the book : \n");
    printf("Enter Book Nmae : ");
    scanf("%s",b.name);
    printf("Enter No. of Pages : ");
    scanf("%d",&b.nopages);
    printf("Enter price of the book : ");
    scanf("%d",&b.price);
    printf("Enter No .of Copies : ");
    scanf("%d",&b.copies);
    printf("Enter Author Name : ");
    scanf("%s",b.author);
    printf("Enter book Code : ");
    scanf("%d",&b.code);
    FILE *fp;
    fp = fopen("shelf.txt","a");
    fprintf(fp,"%s %d %d %d %s %d",b.name,b.nopages,b.price,b.copies,b.author,b.code);
    fclose(fp);
}
void view(){
    printf("\n\nThe Books in Library are : \n\n");
    FILE *fp;
    fp = fopen("shelf.txt","r+");
    while(fscanf(fp,"%s %d %d %d %s %d",b.name,&b.nopages,&b.price,&b.copies,b.author,&b.code)!=EOF){
        printf("Name of the Book : %s\nNo.of Pages : %d\nPrice of the Book : %d\nNo.of Copies : %d\nAuthor Name : %s\nBOOk CODE : %d\n\n",b.name,b.nopages,b.price,b.copies,b.author,b.code);
    }
    fclose(fp);
}
void search(){
    printf("Enter the way to search the Library : \n");
    printf(">>1.By Name of the Book\n>>2.By the Author Name\n>>3.By the Code\n");
    printf("Enter your choice : ");
    int n;
    scanf("%d",&n);
    if(n==1){
        s1();
    }
    else if(n==2){
        s2();
    }
    else if(n==3){
        s3();
    }
    else {
        printf("Invalid Choice\n");
    }
}
void s1(){
    //book name
    char req[100];
    printf("Enter Book name to be searched : ");
    scanf("%s",req);
    FILE *fp;
    fp = fopen("shelf.txt","r+");
    int count=0;
    while(fscanf(fp,"%s %d %d %d %s %d",b.name,&b.nopages,&b.price,&b.copies,b.author,&b.code)!=EOF){
        if(strcmp(req,b.name)==0){
            count++;
        }
    }
    if(count>0){
        int k;
        printf("The Book is Available\n");
        printf("Press 1 to borrow Book : ");
        scanf("%d",&k);
        if(k==1){
            borrow();
        }
    }
    else {
        printf("The given Book is Not Available\n");
    }
    fclose(fp);
}
void s2(){
    //Author name
    char req[100];
    printf("Enter Author name to be searched : ");
    scanf("%s",req);
    FILE *fp;
    fp = fopen("shelf.txt","r+");
    int count=0;
    while(fscanf(fp,"%s %d %d %d %s %d",b.name,&b.nopages,&b.price,&b.copies,b.author,&b.code)!=EOF){
        if(strcmp(req,b.author)==0){
            count++;
        }
    }
    if(count>0){
        int k;
        printf("The Book is Available\n");
        printf("Press 1 to borrow Book : ");
        scanf("%d",&k);
        if(k==1){
            borrow();
        }
    }
    else {
        printf("The given Book is Not Available\n");
    }
    fclose(fp);
}
void s3(){
    //book code
    int l;
    printf("Enter Author name to be searched : ");
    scanf("%d",l);
    FILE *fp;
    fp = fopen("shelf.txt","r+");
    int count=0;
    while(fscanf(fp,"%s %d %d %d %s %d",b.name,&b.nopages,&b.price,&b.copies,b.author,&b.code)!=EOF){
        if(l==b.code){
            count++;
        }
    }
    if(count>0){
        int k;
        printf("The Book is Available\n");
        printf("Press 1 to borrow Book : ");
        scanf("%d",&k);
        if(k==1){
            borrow();
        }
    }
    else {
        printf("The given Book is Not Available\n");
    }
    fclose(fp);
}
void borrow(){
    int kl;
    printf("Enter Book Code to be borrowed : ");
    scanf("%d",&kl);
    FILE *fp;
    fp = fopen("shelf.txt","r+");
    while(fscanf(fp,"%s %d %d %d %s %d",b.name,&b.nopages,&b.price,&b.copies,b.author,&b.code)!=EOF){
        if(kl==b.code){
            printf("Name of the Book : %s\nNo.of Pages : %d\nPrice of the Book : %d\nNo.of Copies : %d\nAuthor Name : %s\nBOOk CODE : %d\n",b.name,b.nopages,b.price,b.copies,b.author,b.code);
            if(b.copies<=0){
                printf("No Copies left\n");
            }
            else {
                b.copies=b.copies-1;
                printf("Remaining copies : %d\n",b.copies);
                takeinfo(b.code);
            }

        }
    }
    fclose(fp);
}
void takeinfo(int h){
    FILE *fp;
    char name[20];
    int a,b,c;
    printf("ENter Your details : ");
    printf("Enter Your name : ");
    scanf("%s",name);
    printf("Enter Todays date (dd/mm/yyyy): ");
    scanf("%d/%d/%d",&a,&b,&c);
    fp = fopen("list.txt","w+");
    fprintf(fp,"%d %s %d %d %d",h,name,a,b,c);
    fclose(fp);
}
void dispinfo(){
    int h,a,b,c;
    char name[100];
    FILE *fp;
    fp = fopen("list.txt","r+");
    while(fscanf(fp,"%d %s %d %d %d",&h,name,&a,&b,&c)!=EOF){
        printf("Book Code : %d\nNAME : %s\nDate borrowed :  %d /%d/ %d\n",h,name,a,b,c);
    }
    fclose(fp);
}
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<math.h>
#include<process.h>
#include<string.h>
#include<dos.h>

struct element{
	char name[20],bp[10],mp[10];
	int atn,atm;
};

struct element e[200];


void add();
void list();
void searchsym();
void edit();
void del();

int main(){
	system("color f9");
    while(1){
    	system("cls");
		printf("\nMAke a choice\n1.Enter Element\n2.List All\n3.Search by Symbol\n4.Modify\n5.Delte\n6.Exit\n");
		switch(getch())
		{
			case '1':
				add();
				break;
			case '2':
		    	list();
		    	break;
			case '3':
				searchsym();
				break;
			case '4':
				edit();
				break;
			case '5':
		    	del();
		    	break;
		 	case '6':
		    	exit(0);
		}
    }
    return 0;
}



 void add(){
 	int n=0;
	system("cls");
    FILE *fp;
    char temp[20];
	fp=fopen("tab.txt","a+");
    do{
    	printf("*****Add Record****\n");
		printf("Enter Element Name : ");
	    scanf("%s",temp);
	      
		strcpy(e[n].name,temp);
	    printf("Enter Boiling Point : ");
	    scanf("%s",e[n].bp);
		printf("Enter Melting Point : ");
		scanf("%s",e[n].mp);
	    printf("Enter Atomic Number : ");
	    scanf("%d",&e[n].atn);		    
		printf("Enter Atomic Mass  : ");
		scanf("%d",&e[n].atm);
		fprintf(fp,"\n%s\t%s\t%s\t%d\t%d",e[n].name,e[n].bp,e[n].mp,e[n].atn,e[n].atm);
		n++;
		fclose(fp);
		printf("\nAdd more words?(y/n)\n");
	}while(getche()== 'y');
}


void list(){
	int q=0;
    FILE *fp;
    fp=fopen("tab.txt","rb+");
    do{
    	system("cls");
    	printf("*****Display All Records*****\n");
    	printf("\n\t\t=================================\n\n");
    	while(fscanf(fp,"%d",e[q].name) !=EOF ){
		fscanf(fp,"\n%s\t%s\t%s\t%d\t%d",&e[q].name,&e[q].bp,&e[q].mp,&e[q].atn,&e[q].atm);
		printf(" \nElement :%s\nAtomic Number :%d\nAtomic Mass :%d\nBoiling Point :%s\nMelting Point :%s\n",e[q].name,e[q].atn,e[q].atm,e[q].bp,e[q].mp);
		q++;
		}	
		printf("\n-------------------------------------------------\n");
    	fclose(fp);
    	printf("\nPress any key to go to main page.");
	}while(getche()== '`');
}

void searchsym(){
	int found=0,a=0,w=0;     /*Flag, atomic number*/
	char b[10];       /*element to search*/
	FILE *fp;
	if((fp=fopen("tab.txt","r"))==NULL){
		system("cls");
		printf("An Unexpected error encountered please check the file location\n");
	    exit(1);
    }	
	else{
		do{
			system("cls");
			printf("\nEnter the Element's Name you want to find:\n");
			scanf("%s",b);
			
			while(fscanf(fp,"/n%d",e[w].name) !=EOF )
	    	{
	    		fscanf(fp,"\n%s\t%s\t%s\t%d\t%d",&e[w].name,&e[w].bp,&e[w].mp,&e[w].atn,&e[w].atm);
				if(strcmp(e[w].name,b)==0)     /*Compare string one by one*/{
					found = 1;
					printf("The atomic number of %s is %d .\n",e[w].name,e[w].atn);
					w++;
					break;
		      	}
			}
			if(found==0)
				printf("\nThe input element does not exist in the Modern Periodic Table...\nPlease, enter correct symbol.\n");
			printf("\nAdd more words?(y/n)\n");				
		}while(getche()== 'y');
   	}	
   fclose(fp);
}

void del()
{  
	system("cls");
	char del[20];
	int i=0;
	FILE *fp,*fp2;
	do
	{	
		fp=fopen("tab.txt","r");
	

		printf("\nEnter word: ");
		scanf("%s",del);
	
		fp2=fopen("replica.txt","a");
		rewind(fp);
	
		while(fscanf(fp,"\n%s\t%s\t%s\t%d\t%d",&e[i].name,&e[i].bp,&e[i].mp,&e[i].atn,&e[i].atm)!=EOF)
		{
			if(strcmpi(e[i].name, del)!=0)  //all the words from dict except the one which is being entered by the user for deletion, are copied on replica.text
			fprintf(fp2,"\n%s\t%s\t%s\t%d\t%d",e[i].name,e[i].bp,e[i].mp,e[i].atn,e[i].atm);
			i++;
		}
	
		fclose(fp);
		fclose(fp2);
	
		remove("tab.txt"); //deletes dict
		rename("replica.txt","tab.txt"); //renames replica.txt as dict
		printf("\nDelete more words?(y/n)");
	}
	while(getche()== 'y');
}


void edit(){
	int i=0;
	int flag=0;
    FILE *fp,*fp2;
	char mod[20];
	fp=fopen("tab.txt","r");
	fp2=fopen("temp.txt","a");
	do{
		system("cls");
		printf("Enter element name to modify\n");
		scanf("%s",mod);
		rewind(fp);
		while(fscanf(fp,"\n%s\t%s\t%s\t%d\t%d",&e[i].name,&e[i].bp,&e[i].mp,&e[i].atn,&e[i].atm)!=EOF){
				if(strcmp(e[i].name,mod)==0){  
					printf("Enter new name:");
					scanf("%s",e[i].name);
					printf("Enter Boiling Point : ");
	                scanf("%s",e[i].bp);
	                printf("Enter Melting Point : ");
	                scanf("%s",e[i].mp);
	                printf("Enter Atomic Number :");
	                scanf("%d",&e[i].atn);
	                printf("Enter Atomic Mass  :");
	                scanf("%d",&e[i].atm);
					flag=1;
				}
				i++;
			}
		if(flag==1){
			for(int j=0;j<i;j++){
				fprintf(fp2,"\n%s\t%s\t%s\t%d\t%d",e[j].name,e[j].bp,e[j].mp,e[j].atn,e[j].atm);
			}
			fclose(fp);
			fclose(fp2);
			remove("tab.txt"); //deletes dict
			rename("temp.txt","tab.txt");
			printf("\nData Modified");
		}
		else{
			printf("\nData Not Found.");
		}
		printf("\nEdit more words?(y/n)\n");		
	}while(getche()=='y');
}




#include<stdio.h>
#include <string.h>
         #include<windows.h>
          #include<dos.h>
         typedef struct student
             {
             	int rno;
    		    char name[20];
    		                struct attendance{
			                                  int date;
		                                     } att[7];
		        float total;
		        float per; 
		      }student;

		 int n;
		 char file[20];
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////		 

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		 void create()
		           {
                     	 FILE *fp;
		 	             char name[50] = "data.txt";;

		 	             // printf("\nENTER NEW FILE NAME : ");
			             // scanf("%s",name);
		 	
		                 fp = fopen(name,"w");
		 	             student *s;
		 	             
						 int n;
		 	             printf("ENTER NUMBER OF STUDENT  : ");   //taking number of student.(latter we have change them if new students enrolled.)
		 	             scanf("%d",&n);
						
						 FILE *nos;
						 nos = fopen("number_of_student.txt","w");
						 fprintf(nos,"%d",n);
						 fclose(nos);

		                 s =(student*)calloc(n,sizeof(student));
		 	
                         printf("\n\e[1mENTER ROLL NO AND NAMES OF STUDENT IN FOLLOWING LINES.\e[0m\n");
			             int i,j;
		 	             for (i=0;i<n;i++)
		 	                 {   
							    
                                printf("%d.Roll number :",i+1);
			                    scanf("%d",&s[i].rno);

		 		                fflush(stdin);

		 		                printf("         Name :");
				                scanf("%[^\n]s",s[i].name);


				                fwrite(&s[i],sizeof(student),1,fp);//////////////////////////////written on file
			                 }

                         printf("\nstudent  resistered succefully.\n");
                         printf("press enter to exit.");
                         fflush(stdin);
                         getchar();
             
                         fclose(fp);

		            }
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////		 
         void display(){
		            	student s1;
			            int j=0;
		             	FILE *fp;
		              	fp = fopen("data.txt","r");
		            	printf("\n\t\t\t day-1|day-2|day-3|day-4|day-5|day-6|day-7\n");
			          while(fread(&s1,sizeof(student),1,fp)){
			
		 	printf("\n%-5d%-20s",s1.rno,s1.name);
		            	for (j=0;j<7;j++)
		 		if (s1.att[j].date){
		 		printf(" P   |");
			 }else{printf(" A   |");
			 }
			 
	        fflush(stdin);                                      }
		 	getchar();
		 fclose(fp);
		 }
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////		 

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////	 
         void append()
		        {
		  	       FILE *fp;
		           fp = fopen("data.txt","a");

		 	       student *s;
		 	       int n,i,j;
		 	       printf("ENTER NUMBER OF NEW STUDENT TO ADD  : ");
		 	       scanf("%d",&n);

				   FILE *nos;
				   nos = fopen("number_of_student.txt","r");
				   
                   fscanf(nos,"%d",&j);
				   fclose(nos);

				   fopen("number_of_student.txt","w");
				   int n_2=j+n;
				   fprintf(nos,"%d",n_2);
				   fclose(nos);


		 	       s = (student*)calloc(n,sizeof(student));
		 	
			       printf("\n\e[1mWRITE THE ROLL NUMBER AND NAME OF STUDENTS IN FOLLOWING LINES.\e[0m\n");
		 	       for (i=0;i<n;i++)
		 	           {
		 		           printf("%d.Roll number :",i+1);
				           scanf("%d",&s[i].rno); 

		 		           fflush(stdin); 

		 		           printf("         Name :");
				           scanf("%[^\n]s",s[i].name);
		 		
				           fwrite(&s[i],sizeof(student),1,fp); //////////////////////////////written on file
			           }

			       fclose(fp);

		           printf("\nstudent  resistered succefully.\n");
                   printf("press enter to exit.");
                   fflush(stdin);
                   getchar();		 
		        }
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		 void search(){
		 	student s1;
			 int j=0,found=0;
		 	FILE *fp;
		 	fp = fopen("data.txt","r");
		 	printf("\nENTER ROLL NUBMER :");
		 	int roll;
			 scanf("%d",&roll);
		 	while(fread(&s1,sizeof(student),1,fp)){
			 if (s1.rno == roll){
			 found =1;
		 	printf("\n%-5d%-20s",s1.rno,s1.name);
		 	for (j=0;j<7;j++)
		 	{
		 		if (s1.att[j].date){
		 		printf(" P   |");
			 }else{
				printf(" A   |");
			 }
			 }
			 
         }
		
			 }fflush(stdin);
		 	getchar();
		 }
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		 void update(){
		 	student s1;
			 int j=0,found=0;
		 	FILE *fp,*fp1;
		 	fp = fopen("data.txt","r");
		 	fp1 = fopen("temp.txt","w");
			 printf("\nENTER ROLL NUBMER :");
		 	int roll;
			 scanf("%d",&roll);

		 	while(fread(&s1,sizeof(student),1,fp))
			    {
			        if (s1.rno == roll){
			        found =1;
		 	    
		 		    

				    printf("ENTER THE NEW ATTENDANCE TO CHANGE\n");
				     
		 		for (j=0;j<7;j++)
		 		{
		 			printf("ENTER  NEW ATTENDANCE[day-%d]:",j+1);
		 			char ch;
				    while (getchar() != '\n');	
				    scanf("%c",&ch); 

							 if(ch=='P' || ch=='p')
							   {
								 s1.att[j].date=1;
				           	   }
                            
							 else s1.att[j].date=0;
					
				 }
				 
			 
         }
         fwrite(&s1,sizeof(student),1,fp1);
		 
		 }
		 	fclose(fp);
		 	fclose(fp1);
		 if (found){
		 fp1 = fopen("temp.txt","r");
		 fp = fopen("data.txt","w");
		 
		 while (fread(&s1,sizeof(student),1,fp1)){
		 	fwrite(&s1,sizeof(student),1,fp);
		 }
		 	fclose(fp);
		 	fclose(fp1);
		 }else{
		 	printf("ROLL NUMBER IS INVALID");
		 }}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////		
		 void delete_rec(){
		 	                student s1;
			                int j=0,found=0;
		 	                FILE *fp,*fp1;

		            	   fp = fopen("data.txt","r");
		 	               fp1 = fopen("temp.txt","w");

			               printf("\nENTER ROLL NUBMER TO DELETE:");
		 	               int roll;
			               scanf("%d",&roll);

		 	              while(fread(&s1,sizeof(student),1,fp))
						  {
			                    if (s1.rno == roll)
								{
			                      found =1;		               		
                                }
								else {
                                     fwrite(&s1,sizeof(student),1,fp1);
	                                 }
		                  }
		 	               fclose(fp);
		 	              fclose(fp1);
		 if (found){
		 fp1 = fopen("temp.txt","r");
		 fp = fopen("data.txt","w");
		 
		 while (fread(&s1,sizeof(student),1,fp1)){
		 	fwrite(&s1,sizeof(student),1,fp);
		 }
		 	fclose(fp);
		 	fclose(fp1);
		 }else{
		 	printf("ROLL NUMBER IS INVALID");
		 }}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////	
		void markatt(){
		 	            student s1;
			            int j=0,found=0;

		 	            FILE *fp,*fp1;
		 	            fp = fopen("data.txt","r");
		 	            fp1 = fopen("temp.txt","w");

			         printf("\nENTER ROLL NUBMER :");
		 	         int roll;
			         scanf("%d",&roll);
		          
                  	while(fread(&s1,sizeof(student),1,fp)){
			 if (s1.rno == roll){
			  found =1;
		 		fflush(stdin);
		 		int date;
		 		printf("ENTER DAY NUMBER :");
				 scanf("%d",&date);
				
				printf("ENTER NEW ATTENDANCE :");
				char ch;
				while (getchar() != '\n');	

				scanf("%c",&ch); 

							 if(ch=='P' || ch=='p')
							   {
								 s1.att[date-1].date=1;
				           	   }
                            
							 else s1.att[date-1].date=0;
		 			
		 	
				 
				 
			 
         }
         fwrite(&s1,sizeof(student),1,fp1);
		 
		 }
		 	fclose(fp);
		 	fclose(fp1);
		 if (found){
		 fp1 = fopen("temp.txt","r");
		 fp = fopen("data.txt","w");
		 
		 while (fread(&s1,sizeof(student),1,fp1)){
		 	fwrite(&s1,sizeof(student),1,fp);
		 }
		 	fclose(fp);
		 	fclose(fp1);
		 }else{
		 	printf("ROLL NUMBER IS INVALID");
		 }}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////			

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		void attall(){
		               student s1; 
			           int j,found=0;

		 	           FILE *fp,*fp1;
		 	           fp  = fopen("data.txt","r");
		 	           fp1 = fopen("temp.txt","w");

		 	           int dateatt;
		 	           printf("\nENTER DAY NUMBER(please refer 1 for monday and 6 for saturday): ");
		 	           scanf("%d",&dateatt);

					   FILE *nos;
					   nos = fopen("number_of_student.txt","r");
					   fscanf(nos,"%d",&j);
					   fclose(nos);
                       
                         
                        char ch;
						int i=0;
                         
	        	       while(i<j)
		               	 {  
							 fread(&s1,sizeof(student),1,fp);						     			
			                 printf("\n%d.Roll number:%d       Name:%s    :",i+1,s1.rno,s1.name);

							 while (getchar() != '\n');	

							 scanf("%c",&ch); 

							 if(ch=='P' || ch=='p')
							   {
								 s1.att[dateatt-1].date=1;
				           	   }
                            
							 else s1.att[dateatt-1].date=0;
                             
							 
			                 fwrite(&s1,sizeof(student),1,fp1);
							 
		                   i++;
						 }
		 	
			          fclose(fp);
		 	          fclose(fp1);
                       
					 

		              
		              fp1 = fopen("temp.txt","r");
		              fp = fopen("data.txt","w");
                       
		 
		              while (fread(&s1,sizeof(student),1,fp1))
					    {
		             	     fwrite(&s1,sizeof(student),1,fp);
		                }
                      
					  fclose(fp1);  
		         	  fclose(fp);					  
		            }	
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		 int main()
          {
          	int choice;
            system("color 0e");
          	do {int i=0;
          	system("cls");
          		char str[] = "\n\t\t\t1 . REGISTER STUDENTS \n\t\t\t2 . ADD NEW STUDENT\n\t\t\t3 . TAKE ATTENDANCE\n\t\t\t4 . SEARCH A STUDENT\n\t\t\t5 . UPDATE ATTENDANCE\n\t\t\t6 . DELETE A STUDENT RECORD\n\t\t\t7 . MARK SPECIFIC ATTENDANCE\n\t\t\t8 . SHOW  FULL ATTENDANCE INFORMATION \n\t\t\t\e[1mENTER THE OPTION :\e[0m";
          		for(i=0;str[i]!='\0';i++){
          			printf("%c",str[i]);
          			Sleep(15);
				  }
          	
          		scanf("%d",&choice);
          		switch (choice){
          			case 1:
          				create();
          				break;
          			case 2:
					    append();
					    break;
					case 3:
					       attall();
					       break;
					 case 4:
					 	search();
					 	break;
					case 5:
						update();
						break;
					case 6:
						delete_rec();
						break;
					case 7:
						markatt();
					case 8:
						display();
						break;
					 default:
					 	if (choice!=0){
						 
					 	printf("\n\t\t\tINVALID OPTION , CHOOSE AGAIN\n");
						 Sleep(2000);}
					 	
				}}  while (choice !=0);
          	
          	return 0;
		  }

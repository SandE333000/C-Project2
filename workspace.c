#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct details{
	char name[30];
	int roll;
	int maths;
	int science;
	int english;
	int neplai;
	int social;
};

void line();
void home();
void add(int);
void list();
void search();
void edit(int);
void del(int);
void view(int);

void line(){
	int i;
	for(i=0;i<120;i++){
		printf("*");
	}
}

int main(){
	home();
	
	return 0;
}



void home(){
	int choice, bulk;
	printf("\n");
    line();
    printf("\n1. Add a Record");
    printf("\n2. Add Bulk Records");
    printf("\n3. List Students");
    printf("\n4. Search Student");
    printf("\n5. Quit\n");
    printf("Enter your choice: ");
    scanf("%d",&choice);
    fflush(stdin);
    //now switch case to run selected option
    switch(choice){
    	case 1:
    		printf("\n"); // NEED TO ADD DRAW LINE AND RECORD
			line();
			add(1);
			break;
			
		case 2:
			printf("\n");
			line();
			printf("\nHow many students: ");
			scanf("%d",&bulk);
			add(bulk);
			break;
		
		case 3:
			printf("\n");
			line();
			list();
			break;
			
		case 4:
			printf("\n");
			line();
			search();
			break;
			
		case 5:
			exit(1);
			break;
			
		default:
			printf("\n");
			line();
			printf("\n Bye Bye!!");
			home();
			
	}
}
// 1 will be sent for opt 1, n will be sent for opt 2
//for case 1 and 2
void add(int n){
	struct details st[n];
	int i;
	int p;
	for(i=0;i<n;i++){
		FILE *record = fopen("student.dat","a");
		printf("\nEnter information of student %d",i+1);
        fflush(stdin);
        
        printf("\nEnter Name: ");
        scanf("%[^\n]", &st[i].name);
        fflush(stdin);

        printf("\nEnter Roll Number: ");
        scanf("%d",&st[i].roll);
        fflush(stdin);
        
        printf("\nEnter marks in mathmatics: ");
        scanf("%d",&st[i].maths);
        fflush(stdin);
        
        printf("\nEnter marks in science: ");
        scanf("%d",&st[i].science);
        fflush(stdin);
        
        printf("\nEnter marks in engish: ");
        scanf("%d",&st[i].english);
        fflush(stdin);
        
        printf("\nEnter marks in nepali: ");
        scanf("%d",&st[i].neplai);
        fflush(stdin);
        
        printf("\nEnter marks in social: ");
        scanf("%d",&st[i].social);
        fflush(stdin);
        
        fprintf(record,"%s|%d|%d|%d|%d|%d|%d\n",st[i].name, st[i].roll, st[i].maths, st[i].science, st[i].english, st[i].neplai, st[i].social);
        fclose(record);
        printf("\n");
	}
	home();
}
//for case 3
void list(){
	
	struct details lst;
	FILE *list = fopen("student.dat","r");
	printf("\nRoll\tName\n");
	while(fscanf(list,"%[^|]|%d|%d|%d|%d|%d|%d\n",&lst.name, &lst.roll, &lst.maths, &lst.science, &lst.english, &lst.neplai, &lst.social) != EOF){
		printf("%d\t%s\n",lst.roll, lst.name);
	}
	fclose(list);
	home();
}

//for case 4
void search(){
	int s_roll, flag = 0,l_choice;
	printf("\n");
	line();
	
	printf("\nEnter roll number: ");
	scanf("%d",&s_roll);
	fflush(stdin);
	
	struct details search;
	FILE *srch = fopen("student.dat","r");
	while(fscanf(srch, "%[^|]|%d|%d|%d|%d|%d|%d\n", &search.name, &search.roll, &search.maths, &search.science, &search.english, &search.neplai, &search.social) != EOF){
		if(search.roll == s_roll){
			flag= 1;
			fclose(srch);
			break;
		}
	}
	if(flag != 1){
		printf("\n");
		line();
		printf("Roll Number Not Found");
		fclose(srch);
		home();
	}
	
	printf("\n");
    line();
    printf("\nRecord Found!");
    printf("\nStudent Name: %s\n", search.name);
    line();
    
    printf("\n1. Edit Record\n");
    printf("2. Delete Record\n");
    printf("3. View Marks Sheet\n");
    printf("4. Quit\n");
    printf("What is your choice?: ");
    scanf("%d",&l_choice);
    fflush(stdin);
    
    switch(l_choice){
    	case 1:
    		edit(search.roll);
    		break;
    	
    	case 2:
    		del(search.roll);
    		break;
    	
    	case 3:
    		view(search.roll);
    		break;
    	
    	case 4:
    		exit(4);
    	
    	default:
    		home();
	}
}

void edit(int edt_roll){
	struct details edit, delete;
	FILE *read = fopen("student.dat","r");
	FILE *edited = fopen("new.dat","a");
	int edt_choice, p_roll;
	
	while(fscanf(read, "%[^|]|%d|%d|%d|%d|%d|%d\n", &edit.name, &edit.roll, &edit.maths, &edit.science, &edit.english, &edit.neplai, &edit.social) != EOF){
		if(edit.roll == edt_roll){
			p_roll = edit.roll;
			break;
		}
	}
	
	rewind(read);
    printf("\n");
    line();
    printf("\nHello %s!\nYour Current Information is:\n", edit.name);
    printf("\nName: %s",edit.name);
    printf("\nRoll Number: %d",edit.roll);
    printf("\nMarks in Mathmatics: %d",edit.maths);
    printf("\nMarksk in Science: %d",edit.science);
    printf("\nMarks in English: %d",edit.english);
    printf("\nMarks in Nepali: %d",edit.neplai);
    printf("\nMarks in Social: %d",edit.social);
    printf("\n\nWhich Information Do You Want to Edit? Choose From The Following:\n");
    printf("1. Name\n");
    printf("2. Roll Number\n");
    printf("3. Marks in Mathmatics\n");
    printf("4. Marks in Science\n");
    printf("5. Marks in English\n");
    printf("6. Marks in Nepali\n");
    printf("7. Marks in  Social\n");
    printf("\n\nChoose: ");
    scanf("%d",&edt_choice);
    fflush(stdin);
    
    switch(edt_choice){
    	case 1:
    		printf("Enter New Name: ");
    		gets(edit.name);
    		fflush(stdin);
    		home();
    		break;
    	
    	case 2: 
    		printf("Enter New Roll Number: ");
    		scanf("%d",&edit.roll);
    		fflush(stdin);
    		home();
    		break;
    		
    	case 3:
    		printf("Enter New Marks In Mathmatics: ");
    		scanf("%d", &edit.maths);
    		fflush(stdin);
    		home();
    		break;
    		
    	case 4:
    		printf("enter New Marks in Science: ");
    		scanf("%d",&edit.science);
    		fflush(stdin);
    		home();
    		break;
    		
    	case 5:
    		printf("Enter New Marks in English: ");
    		scanf("%d", &edit.english);
    		fflush(stdin);
    		home();
    		break;
    		
    	case 6:
    		printf("Enter New Marks in Nepali: ");
    		scanf("%d",&edit.neplai);
    		fflush(stdin);
    		home();
    		break;
    	
    	case 7: 
    		printf("Enter New Marks in Social: ");
    		scanf("%d", &edit.social);
    		fflush(stdin);
    		home();
    		break;
    	
    	default: 
    		remove("new.dat");
    		home();
    	
	
	}
    
    while(fscanf(read, "%[^|]|%d|%d|%d|%d|%d|%d\n", &delete.name, &delete.roll, &delete.maths, &delete.science, &delete.english, &delete.neplai, &delete.social) != EOF){
        if(delete.roll != p_roll){
            fprintf(edited, "%s|%d|%d|%d|%d|%d|%d\n", delete.name, delete.roll, delete.maths, delete.science, delete.english, delete.neplai, delete.social);
        }
        else{
            fprintf(edited, "%s|%d|%d|%d|%d|%d|%d\n", edit.name, edit.roll, edit.maths, edit.science, edit.english, edit.neplai, edit.social);
        }
    }
    fclose(read);
    fclose(edited);
    remove("student.dat");
    rename("new.dat", "student.dat");	
}

void del(int edt_roll){
	struct details delete;
	FILE *read = fopen("student.dat", "r");
    FILE *new = fopen("new.dat", "w");
    
    while(fscanf(read, "%[^|]|%d|%d|%d|%d|%d|%d\n", &delete.name, &delete.roll, &delete.maths, &delete.science, &delete.english, &delete.neplai, &delete.social) != EOF){
        if(delete.roll != edt_roll){
            fprintf(new, "%s|%d|%d|%d|%d|%d|%d\n", delete.name, delete.roll, delete.maths, delete.science, delete.english, delete.neplai, delete.social);
        }
    }
    fclose(read);
    fclose(new);
    remove("student.dat");
    rename("new.dat", "student.dat");
    home();
}

void view(int edt_roll){
	char name[30], *div;
	int roll, sub[5], i, total=0;
	float per;
	
	FILE *search = fopen("student.dat","r");
	while(fscanf(search, "%[^|]|%d|%d|%d|%d|%d|%d\n", &name, &roll, &sub[0], &sub[1], &sub[2], &sub[3], &sub[4]) != EOF){
		if(roll == edt_roll){
			fclose(search);
			break;
		}
	}
	for (i=0;i<5;i++){
		total = total + sub[i];
	}
	
	per = (((float)total / 500.0) * 100.0);

//give divisions

	for(i=0; i<5; i++){
        if (sub[i] < 38){
            div = "Fail";
            goto marksheet;
        }
    }
	
	if(per >= 80)
        div = "Distinction";
    else if(per >= 70)
        div = "FIRST";
    else if(per >= 60)
        div = "SECOND";
    else if(per >= 50)
        div = "THIRD";
    else if(per >= 40)
        div = "FOURTH";
    else
        div = "Fail";
        
    //markssheet
    marksheet:
    printf("\n");
    line();
    printf("\nST. XAVIER'S COLLEGE");
    printf("\nSECOND TERM EXAMINATION\n\n");
    line();
    
    printf("\n| Name : %-30s\t\t\t\t\t\t\t\t\t|", name);
    printf("\n| Roll : %-30d\t\t\t\t\t\t\t\t\t|\n", roll);
    
    line();
    
    printf("\n|\tS.N\t|\t\t\tSubjects\t\t|\t\tMarks\t\t\t|\n");
    
    line();
    
    printf("\n|\t1.\t|\t\t\tMathematics\t\t|\t\t%d\t\t\t|", sub[0]);
    printf("\n|\t2.\t|\t\t\tScience\t\t\t|\t\t%d\t\t\t|", sub[1]);
    printf("\n|\t3.\t|\t\t\tEnglish\t\t\t|\t\t%d\t\t\t|", sub[2]);
    printf("\n|\t4.\t|\t\t\tNepali\t\t\t|\t\t%d\t\t\t|", sub[3]);
    printf("\n|\t5.\t|\t\t\tSocial\t\t\t|\t\t%d\t\t\t|\n", sub[4]);
    
    line();
    
	printf("\n|\t \t|\t\t\tPercentage\t\t|\t\t%.2f%%\t\t\t|", per);
    printf("\n|\t \t|\t\t\tDivision\t\t|\t\t%-11s\t\t|\n", div);
    
    line();
    printf("\nEND OF RESULT\n");
    home();
}





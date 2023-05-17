#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<conio.h>
#include<windows.h>
//Declaration of Function
void login();
void signup();
void del();
void modify();
void cust_login();
void cust_signup();
void help();

void create_new_bill();
void view_bill_history();
void del_bill();

void add_new_prod();
void view_product();
void del_product();
void modify_product();

#if 0
void cust_del();
#endif // 0

void products();
void billing();

void admin_account();
void main_menu();
void admin_access();

void online_shopping();
void buying_product();

void fordelay(int j);
void customer();
void employee();
void shopping();
void account();
void suggestion();
void employee_suggestion();
//for delay
void fordelay(int j)
{
    int i,k;
    for(i=0;i<j;i++)
    {
        k=i;
    }
}

struct details
{
    char name[30];
    char paswrd[30];
};

struct product
{
    int id;
    char prod_name[30];
    float prod_rate;
    int prod_quant;
};

struct customer
{
    char name_cus[30];
    char prod_name[30];
    int quantity;
    float amount;
    float rate;
};

void signup(struct details det)
{
    FILE *signup;
    int j;
    signup=fopen("user_details.txt","a");
    if(signup==NULL)
    {
        exit(1);
    }
    printf("\n\t NAME : ");
    scanf("%s",det.name);
    printf("\n\t PASSWORD : ");
    scanf("%s",det.paswrd);
    fprintf(signup,"%s\n%s\n",det.name,det.paswrd);
    printf("\n\n\t Loading ");
    for(j=0;j<=6;j++)
    {
        fordelay(100000000);
        printf(".");
    }
    printf("\n\n\t User Id is Created ...");
    printf("\n\n\t Loading ");
    for(j=0;j<=6;j++)
    {
        fordelay(300000000);
        printf(".");
    }
    fclose(signup);
}
void login(struct details det)
{
    printf("\n\n\t \"Note : If your Password is incorrect then it starts from the beginning of the home page ...\"\n");
    FILE *login;
    login=fopen("user_details.txt","r");
    char name[30];
    char paswrd[30];
    printf("\n\t NAME : ");
    scanf("%s",name);
    int i=0;
	char c;
	int j;
	printf("\n\t PASSWORD : ");
	while((c=getch())!='\r')
	{
		paswrd[i++] = c;
		printf("*");
	}
	paswrd[i] = '\0';
    while(!(feof(login)))
    {
        fscanf(login,"%s\n%s\n",det.name,det.paswrd);
        {
            if((strcmp(det.name,name)==0) && (strcmp(det.paswrd,paswrd)==0))
            {
                printf("\n\n\t Loading ");
                for(j=0;j<=6;j++)
                {
                    fordelay(100000000);
                    printf(".");
                }
                printf("\n\n\t User Id is correct ...");
                printf("\n\n\t Loading ");
                for(j=0;j<=6;j++)
                {
                    fordelay(300000000);
                    printf(".");
                }
                system("cls");
                employee();
            }
        }
    }
    fclose(login);
}

void del(struct details det)
{
    char name[30];
    int j;
    FILE *del1,*del2;
    del1=fopen("user_details.txt","r+");
    del2=fopen("Temp_for_supermarket.txt","w+");
    printf("\n\t Name to be Delete : ");
    scanf("%s",name);
    while(!(feof(del1)))
    {
       fscanf(del1,"%s\n%s\n",det.name,det.paswrd);
       if(strcmp(det.name,name)==0)
       {
           continue;
       }
       else
       {
           fprintf(del2,"%s\n%s\n",det.name,det.paswrd);
       }
    }
    del1=fopen("user_details.txt","w");
    rewind(del2);
    while(!(feof(del2)))
    {
        fscanf(del2,"%s\n%s\n",det.name,det.paswrd);
        fprintf(del1,"%s\n%s\n",det.name,det.paswrd);
    }
    fclose(del1);
    fclose(del2);
    printf("\n\n\t Loading ");
    for(j=0;j<=6;j++)
    {
        fordelay(100000000);
        printf(".");
    }
    printf("\n\n\t Account is deleted successfully ...");
    printf("\n\n\t Thank you for being a part of our family ...");
    printf("\n\n\t Loading ");
    for(j=0;j<=6;j++)
    {
        fordelay(300000000);
        printf(".");
    }
}

void modify(struct details det)
{
    char name[30],paswrd[30];
    char name_1[30],paswrd_1[30];
    int j;
    FILE *modify1,*modify2;
    modify1=fopen("user_details.txt","r+");
    modify2=fopen("Temp_1_for_supermarket.txt","w+");
    printf("\n\t Name to be Modified : ");
    scanf("%s",name);
    printf("\n\t Password to be Modified : ");
    scanf("%s",paswrd);
    printf("\n\n\t Loading ");
    for(j=0;j<=6;j++)
    {
        fordelay(100000000);
        printf(".");
    }
    printf("\n\n\t Account is modified successfully ...");
    printf("\n\n\t Loading ");
    for(j=0;j<=6;j++)
    {
        fordelay(300000000);
        printf(".");
    }
    system("cls");
    system("color 3");
    printf("\n  ----------------------------------------------------------------------------------------------------------");
    printf("\n\t\t\t ******************** SKR SUPERMARKET ********************");
    printf("\n  ----------------------------------------------------------------------------------------------------------");
    printf("\n\n\t\t\t\t... THANKS FOR BEING PART OF OUR FAMILY ...\n\n");
    printf("\n\t\t\t\t 1 ---- LOGIN \n\t\t\t\t 2 ---- SIGN UP \n\t\t\t\t 3 ---- DETETE ACCOUNT \n\t\t\t\t 4 ---- MODIFY ACCOUNT \n\t\t\t\t 5 ---- EXIT");
    printf("\n\n\t If you are a member please login ...");
    printf("\n\n\t TO Continue ....");
    printf("\n");
    printf("\n\t Verification for Current modification : ");
    printf("\n\n\t Name : ");
    scanf("%s",name_1);
    int i=0;
    char c;
    printf("\n\t PASSWORD : ");
    while((c=getch())!='\r')
    {
        paswrd_1[i++] = c;
        printf("*");
    }
    paswrd_1[i] = '\0';
    if((strcmp(paswrd_1,paswrd)==0) && (strcmp(name_1,name)==0))
    {
        printf("\n\n\t Loading ");
        for(j=0;j<=6;j++)
        {
            fordelay(100000000);
            printf(".");
        }
        printf("\n\n\t User Id is correct and verified successfully ...");
        printf("\n\n\t Loading ");
        for(j=0;j<=6;j++)
        {
            fordelay(300000000);
            printf(".");
        }
    }
    else
    {
        printf("\n\n\t Loading ");
        for(j=0;j<=6;j++)
        {
            fordelay(100000000);
            printf(".");
        }
        printf("\n\n\t Please, check your Name and Password ...");
        printf("\n\n\t Loading ");
        for(j=0;j<=6;j++)
        {
            fordelay(300000000);
            printf(".");
        }
        printf("\n\n\t Verification for Current modification : ");
        printf("\n\n\t Name : ");
        scanf("%s",name_1);
        int i=0;
        char c;
        printf("\n\t PASSWORD : ");
        while((c=getch())!='\r')
        {
            paswrd_1[i++] = c;
            printf("*");
        }
        paswrd_1[i] = '\0';
        if((strcmp(paswrd_1,paswrd)==0) && (strcmp(name_1,name)==0))
        {
            printf("\n\n\t Loading ");
            for(j=0;j<=6;j++)
            {
                fordelay(100000000);
                printf(".");
            }
            printf("\n\n\t User Id is correct and verified successfully ...");
        }
        else
        {
            printf("\n\n\t Loading ");
            for(j=0;j<=6;j++)
            {
                fordelay(100000000);
                printf(".");
            }
            printf("\n\t Sorry,to say your Account signin is incorrect , so please create once again ...");
            printf("\n\n\t Loading ");
            for(j=0;j<=6;j++)
            {
                fordelay(100000000);
                printf(".");
            }
            system("cls");
            modify(det);
            system("cls");
        }
    }
    while(!(feof(modify1)))
    {
        fscanf(modify1,"%s\n%s\n",det.name,det.paswrd);
        if(strcmp(det.name,name)==0)
            continue;
        else
            fprintf(modify2,"%s\n%s\n",det.name,det.paswrd);
    }
    modify1=fopen("user_details.txt","w");
    rewind(modify2);
    while(!(feof(modify2)))
    {
        fscanf(modify2,"%s\n%s\n",det.name,det.paswrd);
        fprintf(modify1,"%s\n%s\n",det.name,det.paswrd);
    }
    fprintf(modify1,"%s\n%s\n",name,paswrd);
    fclose(modify1);
    fclose(modify2);
    printf("\n\n\t Loading ");
    for(j=0;j<=6;j++)
    {
        fordelay(100000000);
        printf(".");
    }
    printf("\n\n\t Account is modified successfully ...");
    printf("\n\n\t Loading ");
    for(j=0;j<=6;j++)
    {
        fordelay(300000000);
        printf(".");
    }
}

void customer(void)
{
    system("color 3");
    printf("\n  ----------------------------------------------------------------------------------------------------------");
    printf("\n\t\t\t ******************** SKR SUPERMARKET ********************");
    printf("\n  ----------------------------------------------------------------------------------------------------------");
    printf("\n\n\t If you like to give any suggestion on \"SKR SUPERMARKET\" --- Choose : \" SUGGESTION \"");
    printf("\n\n\t\t\t\t 1 --- ONLINE SHOPPING \n\n\t\t\t\t 2 --- SUGGESTION \n\n\t\t\t\t 3 --- EXIT");
    int choice,j;
    struct details det;
    printf("\n\t To Continue ...");
    while(1)
    {
        printf("\n\n\t Type your choice : ");
        scanf("%d",&choice);
        if(choice==1)
        {
            printf("\n\n\t Loading ");
            for(j=0;j<=6;j++)
            {
                fordelay(100000000);
                printf(".");
            }
            system("cls");
            shopping(det);
            system("cls");
        }
        else if(choice==2)
        {
            printf("\n\n\t Loading ");
            for(j=0;j<=6;j++)
            {
                fordelay(100000000);
                printf(".");
            }
            system("cls");
            suggestion();
            system("cls");
        }
        else if(choice==3)
        {
            printf("\n\n\t Loading ");
            for(j=0;j<=6;j++)
            {
                fordelay(100000000);
                printf(".");
            }
            printf("\n\n\t Thank you for your Visit ...");
            printf("\n\n\t Loading ");
            for(j=0;j<=6;j++)
            {
                fordelay(300000000);
                printf(".");
            }
            system("cls");
            main_menu();
            system("cls");
        }
        else if(choice!=1 && choice!=2 && choice!=3)
        {
            printf("\n\n\t Loading ");
            for(j=0;j<=6;j++)
            {
                fordelay(100000000);
                printf(".");
            }
            printf("\n\n\t You are requested to give only the above choice ...");
            printf("\n\n\t Loading ");
            for(j=0;j<=6;j++)
            {
                fordelay(300000000);
                printf(".");
            }
            system("cls");
            customer();
        }
    }
}

void employee(void)
{
    system("color 3");
    int choice,j;
    struct details det;
    while(1)
    {
        printf("\n  ----------------------------------------------------------------------------------------------------------");
        printf("\n\t\t\t ******************** SKR SUPERMARKET ********************");
        printf("\n  ----------------------------------------------------------------------------------------------------------");
        printf("\n\n\t If you like to give any suggestion on \"SKR SUPERMARKET\" --- Choose : \" EMPLOYEE SUGGESTION \"");
        printf("\n\n\t\t\t\t 1 --- ACCOUNT LOGIN \n\n\t\t\t\t 2 --- EMPLOYEE SUGGESTION \n\n\t\t\t\t 3 --- EXIT");
        printf("\n\n\t To Continue ...");
        printf("\n\n\t Type your choice : ");
        scanf("%d",&choice);
        if(choice==1)
        {
            printf("\n\n\t Loading ");
            for(j=0;j<=6;j++)
            {
                fordelay(100000000);
                printf(".");
            }
            system("cls");
            account();
            system("cls");
        }
        else if(choice==2)
        {
            printf("\n\n\t Loading ");
            for(j=0;j<=6;j++)
            {
                fordelay(100000000);
                printf(".");
            }
            system("cls");
            employee_suggestion(det);
            system("cls");
        }
        else if(choice==3)
        {
            printf("\n\n\t Loading ");
            for(j=0;j<=6;j++)
            {
                fordelay(100000000);
                printf(".");
            }
            printf("\n\n\t Thank you for your Visit ...");
            printf("\n\n\t Loading ");
            for(j=0;j<=6;j++)
            {
                fordelay(300000000);
                printf(".");
            }
            system("cls");
            main_menu();
            system("cls");
        }
        else if(choice!=1 && choice!=2 && choice!=3)
        {
            printf("\n\n\t Loading ");
            for(j=0;j<=6;j++)
            {
                fordelay(100000000);
                printf(".");
            }
            printf("\n\n\t You are requested to give only the above choice ...");
            printf("\n\n\t Loading ");
            for(j=0;j<=6;j++)
            {
                fordelay(300000000);
                printf(".");
            }
            system("cls");
            employee();
        }
    }
}

void shopping(struct details det)
{
    int j;
    printf("\n\n\t Loading ");
    for(j=0;j<=6;j++)
    {
        fordelay(100000000);
        printf(".");
    }
    system("cls");
    system("color 6");
    int choice;
    printf("\n  ----------------------------------------------------------------------------------------------------------");
    printf("\n\t\t\t ******************** SKR SUPERMARKET ********************");
    printf("\n  ----------------------------------------------------------------------------------------------------------");
    printf("\n\n\t\t\t\t... THANKS FOR CHOOSING SKR SUPERMARKET ...\n\n");
    printf("\n\t\t\t\t 1 ---- LOGIN \n\t\t\t\t 2 ---- SIGN UP \n\t\t\t\t 3 ---- HELP AND INFO \n\t\t\t\t 4 ---- EXIT");

    #if 0
    printf("\n\t\t\t\t 5 ---- DETETE ACCOUNT");
    #endif // 0


    printf("\n\n\n\t TO Continue ....");
    while(1)
    {
        printf("\n\n\t Type your Choice to be part of our Family : ");
        scanf("%d",&choice);
        if(choice==1)
        {
            printf("\n\n\t Loading ");
            for(j=0;j<=6;j++)
            {
                fordelay(100000000);
                printf(".");
            }
            printf("\n");
            cust_login(det);
            system("cls");
            shopping(det);
        }
        else if(choice==2)
        {
            printf("\n\n\t Loading ");
            for(j=0;j<=6;j++)
            {
                fordelay(100000000);
                printf(".");
            }
            printf("\n");
            cust_signup(det);
            system("cls");
            shopping(det);
        }
        else if(choice==3)
        {
            printf("\n\n\t Loading ");
            for(j=0;j<=6;j++)
            {
                fordelay(100000000);
                printf(".");
            }
            printf("\n");
            help();
            system("cls");
            shopping(det);
        }

        #if 0
        else if(choice==5)
        {
            printf("\n\n\t Loading ");
            for(j=0;j<=6;j++)
            {
                fordelay(100000000);
                printf(".");
            }
            printf("\n");
            cust_del(det);
            system("cls");
            shopping(det);
        }
        #endif // 0

        else if(choice==4)
        {
            printf("\n\n\t Loading ");
            for(j=0;j<=6;j++)
            {
                fordelay(100000000);
                printf(".");
            }
            printf("\n\n\t Thank you for your Visit ...");
            printf("\n\n\t Loading ");
            for(j=0;j<=6;j++)
            {
                fordelay(300000000);
                printf(".");
            }
            system("cls");
            customer();
            system("cls");
        }
        if(choice!=1 && choice!=2 && choice!=3 && choice!=4)
        {
            printf("\n\n\t Loading ");
            for(j=0;j<=6;j++)
            {
                fordelay(100000000);
                printf(".");
            }
            printf("\n\n\t You are requested to give only the above choice ...");
            printf("\n\n\t Loading ");
            for(j=0;j<=6;j++)
            {
                fordelay(300000000);
                printf(".");
            }
            system("cls");
            shopping(det);
        }
    }
}
void cust_signup(struct details det)
{
    FILE *cust_signup;
    int j;
    cust_signup=fopen("user_details_cust.txt","a");
    if(cust_signup==NULL)
    {
        exit(1);
    }
    printf("\n\t NAME : ");
    scanf("%s",det.name);
    printf("\n\t PASSWORD : ");
    scanf("%s",det.paswrd);
    fprintf(cust_signup,"%s\n%s\n",det.name,det.paswrd);
    printf("\n\n\t Loading ");
    for(j=0;j<=6;j++)
    {
        fordelay(100000000);
        printf(".");
    }
    printf("\n\n\t User Id is Created ...");
    printf("\n\n\t Loading ");
    for(j=0;j<=6;j++)
    {
        fordelay(300000000);
        printf(".");
    }
    fclose(cust_signup);
}
void cust_login(struct details det)
{
    struct customer cust;
    printf("\n\n\t \"Note : If your Password is incorrect then it starts from the beginning of the home page ...\"\n");
    FILE *cust_login;
    cust_login=fopen("user_details_cust.txt","r");
    char cust_name[30];
    char cust_paswrd[30];
    printf("\n\t NAME : ");
    scanf("%s",cust_name);
    int i=0;
	char c;
	int j;
	printf("\n\t PASSWORD : ");
	while((c=getch())!='\r')
	{
		cust_paswrd[i++] = c;
		printf("*");
	}
	cust_paswrd[i] = '\0';
    while(!(feof(cust_login)))
    {
        fscanf(cust_login,"%s\n%s\n",det.name,det.paswrd);
        {
            if((strcmp(det.name,cust_name)==0) && (strcmp(det.paswrd,cust_paswrd)==0))
            {
                printf("\n\n\t Loading ");
                for(j=0;j<=6;j++)
                {
                    fordelay(100000000);
                    printf(".");
                }
                printf("\n\n\t User Id is correct ...");
                printf("\n\n\t Loading ");
                for(j=0;j<=6;j++)
                {
                    fordelay(300000000);
                    printf(".");
                }
                system("cls");
                online_shopping(cust);
            }
        }
    }
    fclose(cust_login);
}
void help()
{
    struct details det;
    system("cls");
    system("color 6");
    int choice,j;
    printf("\n  ----------------------------------------------------------------------------------------------------------");
    printf("\n\t\t\t ******************** SKR SUPERMARKET ********************");
    printf("\n  ----------------------------------------------------------------------------------------------------------");
    printf("\n\n\t\t\t\t... I'M HERE TO HELP YOU ...\n\n");
    printf("\n\n\t If you are a member please login ...");
    printf("\n\n\t To be part of our Family ,signup and login ...");
    printf("\n\n\t We assure that this is a safety domain, and your information would not be shared with anyone ");
    printf("\n\n\t for any purpose ...");
    printf("\n\n\t This is a User Friendly System and we assure that there would no proble");
    printf("\n\n\t Because, we are always thinking about your safety ");
    printf("\n\n\t Finally !!! Thanks, for being the part of our family :)");
    printf("\n\n\t Loading ");
    for(j=0;j<=6;j++)
    {
        fordelay(100000000);
        printf(".");
    }
    printf("\n\n\t Type your choice if (1- Continue) : ");
    scanf("%d",&choice);
    if(choice==1)
    {
        printf("\n\n\t Loading ");
        for(j=0;j<=6;j++)
        {
            fordelay(100000000);
            printf(".");
        }
        printf("\n\n\t Thank you for your Visit ...");
        printf("\n\n\t Loading ");
        for(j=0;j<=6;j++)
        {
            fordelay(300000000);
            printf(".");
        }
        system("cls");
        shopping(det);
        system("cls");
    }
    else if(choice!=1)
    {
        printf("\n\n\t Loading ");
        for(j=0;j<=6;j++)
        {
            fordelay(100000000);
            printf(".");
        }
        printf("\n\n\t Please, Type only the mentioned choice ...");
        printf("\n\n\t Loading ");
        for(j=0;j<=6;j++)
        {
            fordelay(300000000);
            printf(".");
        }
        help();
    }


    printf("\n\n\t Loading ");
    for(j=0;j<=6;j++)
    {
        fordelay(300000000);
        printf(".");
    }

}

void online_shopping(struct customer cus)
{
    struct details det;
    system("cls");
    system("color 6");
    int choice,j;
    printf("\n  ----------------------------------------------------------------------------------------------------------");
    printf("\n\t\t\t ******************** SKR SUPERMARKET ********************");
    printf("\n  ----------------------------------------------------------------------------------------------------------");
    printf("\n\n\t\t\t\t... THANKS FOR CHOOSING SKR SUPERMARKET ...\n\n");
    printf("\n\t\t\t\t 1 ---- FOR BUYING PRODUCT  \n\t\t\t\t 2 ---- FOR BILLING \n\t\t\t\t 3 ---- EXIT");
    printf("\n\n\t To Continue ...");
    printf("\n\n\t Type your choice : ");
    scanf("%d",&choice);
    if(choice==1)
    {
        printf("\n\n\t Loading ");
        for(j=0;j<=6;j++)
        {
            fordelay(100000000);
            printf(".");
        }
        printf("\n");
        buying_product(cus);
        system("cls");
    }
    else if(choice==2)
    {
        printf("\n\n\t Loading ");
        for(j=0;j<=6;j++)
        {
            fordelay(100000000);
            printf(".");
        }
        printf("\n");
        create_new_bill(cus);
        system("cls");
    }
    else if(choice==3)
    {
        printf("\n\n\t Loading ");
        for(j=0;j<=6;j++)
        {
            fordelay(100000000);
            printf(".");
        }
        printf("\n\n\t Thank you for your Visit ...");
        printf("\n\n\t Loading ");
        for(j=0;j<=6;j++)
        {
            fordelay(300000000);
            printf(".");
        }
        system("cls");
        shopping(det);
        system("cls");
    }
    else if(choice!=1 && choice!=2 && choice!=3)
    {
        printf("\n\n\t Loading ");
        for(j=0;j<=6;j++)
        {
            fordelay(100000000);
            printf(".");
        }
        printf("\n\n\t You are requested to give only the above choice ...");
        printf("\n\n\t Loading ");
        for(j=0;j<=6;j++)
        {
            fordelay(300000000);
            printf(".");
        }
        system("cls");
        online_shopping(cus);
    }
}

#if 1
void buying_product(struct customer cus)
{
    struct product pro;
    FILE *buy,*get_item;
    int j,choice;
    buy=fopen("customer.txt","a");
    get_item=fopen("product_details.txt","r");
    if(buy==NULL)
    {
        exit(1);
    }
    int i;
    printf("\n\n\t CUSTOMER NAME : ");
    scanf("%s",cus.name_cus);
    printf("\n\n\t PRODUCT NAME : ");
    scanf("%s",cus.prod_name);
    fflush(stdin);
    printf("\n\t QUANTITY : ");
    scanf("%d",&cus.quantity);
    do
    {
        fscanf(get_item,"%d %s %f %d\n",&pro.id,pro.prod_name,&pro.prod_rate,&pro.prod_quant);
        if(strcmp(pro.prod_name,cus.prod_name)==0)
        {
            fflush(stdin);
            cus.rate=pro.prod_rate;
            printf("\n\n\t RATE OF THE PRODUCT : %.2f",cus.rate);
        }
        else
        {
            continue;
        }
    }while(!(feof(get_item)));
    printf("\n\n\t Loading ");
    for(j=0;j<=6;j++)
    {
        fordelay(100000000);
        printf(".");
    }
    printf("\n\n\t The Required item is present ... ");
    printf("\n\n\t Loading ");
    for(j=0;j<=6;j++)
    {
        fordelay(300000000);
        printf(".");
    }
    cus.amount=cus.rate*cus.quantity;
    printf("\n\n\t PRODUCT AMOUNT : %.2f",cus.amount);
    fprintf(buy,"%s %s %d %f %f\n",cus.name_cus,cus.prod_name,cus.quantity,cus.rate,cus.amount);
    printf("\n-------------------------------------------------------------------------------------");
    printf("\n-------------------------------------------------------------------------------------");
    printf("\n\n\t Type your choice if (1- Continue) : ");
    scanf("%d",&choice);
    if(choice==1)
    {
        printf("\n\n\t Loading ");
        for(j=0;j<=6;j++)
        {
            fordelay(100000000);
            printf(".");
        }
        printf("\n\n\t Verified Successfully ...");
        printf("\n\n\t Loading ");
        for(j=0;j<=6;j++)
        {
            fordelay(300000000);
            printf(".");
        }
    }
    else if(choice!=1)
    {
        printf("\n\n\t Loading ");
        for(j=0;j<=6;j++)
        {
            fordelay(100000000);
            printf(".");
        }
        printf("\n\n\t Please, Type only the mentioned choice ...");
        printf("\n\n\t Loading ");
        for(j=0;j<=6;j++)
        {
            fordelay(300000000);
            printf(".");
        }
        buying_product(cus);
    }
    printf("\n\n\t Data is Entered ...");
    printf("\n\n\t Loading ");
    for(j=0;j<=6;j++)
    {
        fordelay(300000000);
        printf(".");
    }
    fclose(buy);
    fclose(get_item);
    system("cls");
    online_shopping(cus);
    system("cls");
}

void create_new_bill(struct customer cus)
{
    FILE *f;
    int g=1,j;
    int choice;
    float sum=0;
    f=fopen("customer.txt","r");
    char cus_name[30];
    printf("\n\t CUSTOMER NAME :");
    scanf("%s",cus_name);
    printf("\n\n\t Loading ");
    for(j=0;j<=6;j++)
    {
        fordelay(100000000);
        printf(".");
    }
    system("cls");
    system("color 7");
    printf("\n\t                         ----------------------------------------------------------------");
    printf("\n\t ------------------------------------------ ******* SALES ORDER ******* ------------------------------------------");
    printf("\n\t                         ----------------------------------------------------------------");

    printf("\n\n\t     ******* TO :%s *******",cus_name);
    printf("\n\t -----------------------------------------------------------------------------------------------------------------");
    printf("\n\n\t\tSno \t\tItem \t\t\tQuantity \t\tAmount");
    printf("\n\t -----------------------------------------------------------------------------------------------------------------");
    printf("\n");
    while(!(feof(f)))
    {
        fscanf(f,"%s %s %d %f %f\n",cus.name_cus,cus.prod_name,&cus.quantity,&cus.rate,&cus.amount);
        if(strcmp(cus_name,cus.name_cus)==0)
        {
            printf("\n\t\t%d \t\t%s \t\t\t%d \t\t\t%.2f",g,cus.prod_name,cus.quantity,cus.amount);
            sum=sum+cus.amount;
        }
        else
        {
            continue;
        }
        g++;
    }
    printf("\n\n\t\t\t\t\t\t\t\t\t----------------------");
    printf("\n\n\t\t\t\t\t\t\t\t\t\t%.2f",sum);
    printf("\n\n\t\t\t\t\t\t\t\t\t----------------------");
    printf("\n\t -----------------------------------------------------------------------------------------------------------------");
    printf("\n\n\t Type your choice if (1- Continue) : ");
    scanf("%d",&choice);
    if(choice==1)
    {
        printf("\n\n\t Loading ");
        for(j=0;j<=6;j++)
        {
            fordelay(100000000);
            printf(".");
        }
        printf("\n\n\t Your Bill ...");
        printf("\n\n\t THANKS FOR PURCHASING AND WE HOPE YOU ENJOYED OUR SERVICE ...");
        printf("\n\n\t Loading ");
        for(j=0;j<=6;j++)
        {
            fordelay(300000000);
            printf(".");
        }
    }
    else if(choice!=1)
    {
        printf("\n\n\t Loading ");
        for(j=0;j<=6;j++)
        {
            fordelay(100000000);
            printf(".");
        }
        printf("\n\n\t Please, Type only the mentioned choice ...");
        printf("\n\n\t Loading ");
        for(j=0;j<=6;j++)
        {
            fordelay(300000000);
            printf(".");
        }
        create_new_bill(cus);
    }
    printf("\n\n\t Data is Entered ...");
    printf("\n\n\t Loading ");
    for(j=0;j<=6;j++)
    {
        fordelay(300000000);
        printf(".");
    }
    fclose(f);
    system("cls");
    online_shopping(cus);
    system("cls");
}

#endif

#if 0
void del(struct details det)
{
    char cust_name[30];
    int j;
    FILE *cust_del1,*cust_del2;
    cust_del1=fopen("user_details_cust.txt","r+");
    cust_del2=fopen("Temp_for_supermarket_cust.txt","w+");
    printf("\n\t Name to be Delete : ");
    scanf("%s",cust_name);
    while(!(feof(cust_del1)))
    {
       fscanf(cust_del1,"%s\n%s\n",det.name,det.paswrd);
       if(strcmp(det.name,cust_name)==0)
       {
           continue;
       }
       else
       {
           fprintf(cust_del2,"%s\n%s\n",det.name,det.paswrd);
       }
    }
    cust_del1=fopen("user_details_cust.txt","w");
    rewind(cust_del2);
    while(!(feof(cust_del2)))
    {
        fscanf(del2,"%s\n%s\n",det.name,det.paswrd);
        fprintf(del1,"%s\n%s\n",det.name,det.paswrd);
    }
    fclose(cust_del1);
    fclose(cust_del2);
    printf("\n\n\t Loading ");
    for(j=0;j<=6;j++)
    {
        fordelay(100000000);
        printf(".");
    }
    printf("\n\n\t Account is deleted successfully ...");
    printf("\n\n\t Thank you for being a part of our family ...");
    printf("\n\n\t Loading ");
    for(j=0;j<=6;j++)
    {
        fordelay(300000000);
        printf(".");
    }
}
#endif // 0

void suggestion(void)
{
    FILE *suggest;
    suggest=fopen("suggestion_of_customer.txt","a+");
    if(suggest==NULL)
    {
        exit(1);
    }
    char sugg[500];
    int j;
    int choice;
    printf("\n  ----------------------------------------------------------------------------------------------------------");
    printf("\n\t\t\t ******************** SKR SUPERMARKET ********************");
    printf("\n  ----------------------------------------------------------------------------------------------------------");
    printf("\n\t\t\t\t\t AVAILABLE CHOICE ");
    printf("\n\n\t\t\t\t 1 --- EXIT");
    char name[30];
    while(1)
    {
        printf("\n\n\t Enter your Suggestion ...");
        printf("\n\n\t Name : ");
        scanf("%s",name);
        fflush(stdin);
        printf("\n\n\t Suggestion : ");
        printf("\n\n\t");
        fgets(sugg,sizeof(sugg),stdin);
        fflush(stdin);
        fprintf(suggest,"%s\n",name);
        fputs(sugg,suggest);
        printf("\n\n\t Do you Like to Continue : ");
        scanf("%d",&choice);
        if(choice==1)
        {
            printf("\n\n\t Loading ");
            for(j=0;j<=6;j++)
            {
                fordelay(100000000);
                printf(".");
            }
            printf("\n\n\t Thank you for your Visit ...");
            printf("\n\n\t Loading ");
            for(j=0;j<=6;j++)
            {
                fordelay(300000000);
                printf(".");
            }
            system("cls");
            customer();
            system("cls");
        }
        else if(choice!=1)
        {
            printf("\n\n\t Loading ");
            for(j=0;j<=6;j++)
            {
                fordelay(100000000);
                printf(".");
            }
            printf("\n\n\t You are requested to give only the above choice ...");
            printf("\n\n\t If you have entered the choice which was not mentioned then you have to continue your suggestion ...");
            printf("\n\t If you like to omit the suggestion part ,click \"ENTER\",after typing your name");
            printf("\n\n\t Loading ");
            for(j=0;j<=6;j++)
            {
                fordelay(500000000);
                printf(".");
            }
            system("cls");
            suggestion();
        }
    }
    fclose(suggest);
}

void employee_suggestion(struct details det)
{
    char sugg[500];
    char name_1[30];
    printf("\n  ----------------------------------------------------------------------------------------------------------");
    printf("\n\t\t\t ******************** SKR SUPERMARKET ********************");
    printf("\n  ----------------------------------------------------------------------------------------------------------");
    printf("\n\n\t \"Note : If your Password is incorrect then it starts from the beginning of the home page ...\"\n");
    FILE *emp,*emp_det;
    emp=fopen("user_details.txt","r");
    emp_det=fopen("suggestion_of_employee.txt","a+");
    char name[30];
    char paswrd[30];
    printf("\n\t NAME : ");
    scanf("%s",name);
    int i=0,choice;
	char c;
	int j;
	printf("\n\t PASSWORD : ");
	while((c=getch())!='\r')
	{
		paswrd[i++] = c;
		printf("*");
	}
	paswrd[i] = '\0';
    while(!(feof(emp)))
    {
        fscanf(emp,"%s\n%s\n",det.name,det.paswrd);
        {
            if((strcmp(det.name,name)==0) && (strcmp(det.paswrd,paswrd)==0))
            {
                printf("\n\n\t Loading ");
                for(j=0;j<=6;j++)
                {
                    fordelay(100000000);
                    printf(".");
                }
                printf("\n\n\t User Id is correct ...");
                printf("\n\n\t Loading ");
                for(j=0;j<=6;j++)
                {
                    fordelay(300000000);
                    printf(".");
                }
                printf("\n\t\t\t\t\t AVAILABLE CHOICE ");
                printf("\n\n\t\t\t\t 1 --- EXIT");
                printf("\n\n\t Enter your Suggestion ...");
                printf("\n\n\t Name : ");
                scanf("%s",name_1);
                fflush(stdin);
                printf("\n\n\t Suggestion : ");
                printf("\n\n\t");
                fgets(sugg,sizeof(sugg),stdin);
                fflush(stdin);
                fprintf(emp_det,"%s\n",name);
                fputs(sugg,emp_det);
                printf("\n\n\t Do you Like to Continue : ");
                scanf("%d",&choice);
                if(choice==1)
                {
                    printf("\n\n\t Loading ");
                    for(j=0;j<=6;j++)
                    {
                        fordelay(100000000);
                        printf(".");
                    }
                    printf("\n\n\t Thank you for your Visit ...");
                    printf("\n\n\t Loading ");
                    for(j=0;j<=6;j++)
                    {
                        fordelay(300000000);
                        printf(".");
                    }
                    system("cls");
                    employee();
                    system("cls");
                }
                else if(choice!=1)
                {
                    printf("\n\n\t Loading ");
                    for(j=0;j<=6;j++)
                    {
                        fordelay(100000000);
                        printf(".");
                    }
                    printf("\n\n\t You are requested to give only the above choice ...");
                    printf("\n\n\t If you have entered the choice which was not mentioned then you have to continue your suggestion ...");
                    printf("\n\t If you like to omit the suggestion part ,click \"ENTER\",after typing your name");
                    printf("\n\n\t Loading ");
                    for(j=0;j<=6;j++)
                    {
                        fordelay(500000000);
                        printf(".");
                    }
                    system("cls");
                    employee_suggestion(det);
                }
                system("cls");
                employee();
                system("cls");
            }
        }
    }
    fclose(emp);
    fclose(emp_det);
}

void account()
{
    system("color 3");
    int j;
    printf("\n  ----------------------------------------------------------------------------------------------------------");
    printf("\n\t\t ************ THANKS FOR BEING PART OF OUR FAMILY ************");
    printf("\n  ----------------------------------------------------------------------------------------------------------");
    int choice;
    struct details det;
    printf("\n\t\t\t\t 1 ---- LOGIN \n\t\t\t\t 2 ---- SIGN UP \n\t\t\t\t 3 ---- DETETE ACCOUNT \n\t\t\t\t 4 ---- MODIFY ACCOUNT \n\t\t\t\t 5 ---- EXIT");
    printf("\n\n\t If you are a member please login ...");
    printf("\n\n\t TO Continue ....");
    while(1)
    {
        printf("\n\n\t Type your Choice to be part of our Family : ");
        scanf("%d",&choice);
        if(choice==1)
        {
            printf("\n\n\t Loading ");
            for(j=0;j<=6;j++)
            {
                fordelay(100000000);
                printf(".");
            }
            login(det);
            system("cls");
            account();
        }
        else if(choice==2)
        {
            printf("\n\n\t Loading ");
            for(j=0;j<=6;j++)
            {
                fordelay(100000000);
                printf(".");
            }
            printf("\n");
            signup(det);
            system("cls");
            account();
        }
        else if(choice==3)
        {
            printf("\n\n\t Loading ");
            for(j=0;j<=6;j++)
            {
                fordelay(100000000);
                printf(".");
            }
            printf("\n");
            del(det);
            system("cls");
            account();
        }
        else if(choice==4)
        {
            printf("\n\n\t Loading ");
            for(j=0;j<=6;j++)
            {
                fordelay(100000000);
                printf(".");
            }
            printf("\n");
            modify(det);
            system("cls");
            account();
        }
        else if(choice==5)
        {
            printf("\n\n\t Loading ");
            for(j=0;j<=6;j++)
            {
                fordelay(100000000);
                printf(".");
            }
            printf("\n\n\t Thank you for your Visit ...");
            printf("\n\n\t Loading ");
            for(j=0;j<=6;j++)
            {
                fordelay(300000000);
                printf(".");
            }
            system("cls");
            employee();
            system("cls");
        }
        if(choice!=1 && choice!=2 && choice!=3 && choice!=4 && choice!=5)
        {
            printf("\n\n\t Loading ");
            for(j=0;j<=6;j++)
            {
                fordelay(100000000);
                printf(".");
            }
            printf("\n\n\t You are requested to give only the above choice ...");
            printf("\n\n\t Loading ");
            for(j=0;j<=6;j++)
            {
                fordelay(300000000);
                printf(".");
            }
            system("cls");
            account();
        }
    }
}

void main_menu()
{
    int choice;
    int j;
    system("cls");
    system("color 7" );
    printf("\n  ----------------------------------------------------------------------------------------------------------");
    printf("\n\t\t\t ************** SKR SUPERMARKET WELCOMES YOU **************");
    printf("\n  ----------------------------------------------------------------------------------------------------------");
    printf("\n\n\t\t\t\t\t SKR SUPERMARKET ");
    printf("\n\n\t\t\t\t 1 ---- CUSTOMER \n\t\t\t\t 2 ---- EMPLOYEE \n\t\t\t\t 3 ---- EXIT");
    printf("\n\n\t TO Continue ....");
    while(1)
    {
        printf("\n\n\t Type your choice : ");
        scanf("%d",&choice);
        if(choice==1)
        {
            printf("\n\n\t Loading ");
            for(j=0;j<=6;j++)
            {
                fordelay(100000000);
                printf(".");
            }
            system("cls");
            customer();
            system("cls");
        }
        else if(choice==2)
        {
            printf("\n\n\t Loading ");
            for(j=0;j<=6;j++)
            {
                fordelay(100000000);
                printf(".");
            }
            system("cls");
            employee();
            system("cls");
        }
        else if(choice==3)
        {
            printf("\n\n\t Loading ");
            for(j=0;j<=6;j++)
            {
                fordelay(100000000);
                printf(".");
            }
            printf("\n\n\t Thank you for your Visit ...");
            printf("\n\n\t Loading ");
            for(j=0;j<=6;j++)
            {
                fordelay(300000000);
                printf(".");
            }
            system("cls");
            main();
            system("cls");
        }
        else if(choice!=1 && choice!=2 && choice!=3)
        {
            printf("\n\n\t Loading ");
            for(j=0;j<=6;j++)
            {
                fordelay(100000000);
                printf(".");
            }
            printf("\n\n\t You are requested to give only the above choice ...");
            printf("\n\n\t Loading ");
            for(j=0;j<=6;j++)
            {
                fordelay(300000000);
                printf(".");
            }
            system("cls");
            main_menu();
        }
    }
}
#if 1
void admin_account()
{
    struct details det;
    FILE *signup;
    int j;
    signup=fopen("admin_account_details.txt","w");
    if(signup==NULL)
    {
        exit(1);
    }
    printf("\n\t NAME : ");
    scanf("%s",det.name);
    printf("\n\t PASSWORD : ");
    scanf("%s",det.paswrd);
    fprintf(signup,"%s\n%s\n",det.name,det.paswrd);
    printf("\n\n\t Loading ");
    for(j=0;j<=6;j++)
    {
        fordelay(100000000);
        printf(".");
    }
    printf("\n\n\t User Id is Created ...");
    printf("\n\n\t Loading ");
    for(j=0;j<=6;j++)
    {
        fordelay(300000000);
        printf(".");
    }
    fclose(signup);
}

#endif // 0
void main()
{
    struct details det;
    FILE *f;
    f=fopen("admin_account_details.txt","r");
    if(f==NULL)
    {
        #if 1
        admin_account();
        #endif
    }
    int choice;
    int j;
    system("cls");
    system("color 7" );
    printf("\n  ----------------------------------------------------------------------------------------------------------");
    printf("\n\t\t\t ************** SKR SUPERMARKET WELCOMES YOU **************");
    printf("\n  ----------------------------------------------------------------------------------------------------------");
    printf("\n\n\t\t\t\t\t SKR SUPERMARKET ");
    printf("\n\n\t\t\t\t 1 ---- ADMIN (Only Admin has Access) \n\t\t\t\t 2 ---- MAIN MENU \n\t\t\t\t 3 ---- EXIT");
    printf("\n\n\n\t If you like to do online shopping or like to give suggestion, choose \" MAIN MENU \" ");
    printf("\n\n\t \"Note : Suggestion can be given by both customer and employee \" ");
    printf("\n\n\n\n\t TO Continue ....");
    char name[30];
    char paswrd[30];
    while(1)
    {
        printf("\n\n\t Type your choice : ");
        scanf("%d",&choice);
        if(choice==1)
        {
            #if 1
            int E;
            printf("\n\n\t Enter '1' if you like to change the Admin login : ");
            scanf("%d",&E );
            if(E==1)
            {
                admin_account();
            }
            #endif // 0
            printf("\n\n\t NAME : ");
            scanf("%s",name);
            int i=0;
            char c;
            int j;
            printf("\n\t PASSWORD : ");
            while((c=getch())!='\r')
            {
                paswrd[i++] = c;
                printf("*");
            }
            paswrd[i] = '\0';
            while(!(feof(f)))
            {
                fscanf(f,"%s\n%s\n",det.name,det.paswrd);
                {
                    if((strcmp(det.name,name)==0) && (strcmp(det.paswrd,paswrd)==0))
                    {
                        printf("\n\n\t Loading ");
                        for(j=0;j<=6;j++)
                        {
                            fordelay(100000000);
                            printf(".");
                        }
                        printf("\n\n\t User Id is correct ...");
                        printf("\n\n\t Loading ");
                        for(j=0;j<=6;j++)
                        {
                            fordelay(300000000);
                            printf(".");
                        }
                        system("cls");
                        admin_access();
                        system("cls");
                    }
                    else
                    {
                        printf("\n\n\t Loading ");
                        for(j=0;j<=6;j++)
                        {
                            fordelay(100000000);
                            printf(".");
                        }
                        printf("\n\n\t Please, Try again .....");
                        printf("\n\n\t Loading ");
                        for(j=0;j<=6;j++)
                        {
                            fordelay(300000000);
                            printf(".");
                        }
                        system("cls");
                        main();
                        system("cls");
                    }
                }
            }
        }
        else if(choice==2)
        {
            printf("\n\n\t Loading ");
            for(j=0;j<=6;j++)
            {
                fordelay(100000000);
                printf(".");
            }
            system("cls");
            main_menu();
            system("cls");
        }
        else if(choice==3)
        {
            printf("\n\n\t Loading ");
            for(j=0;j<=6;j++)
            {
                fordelay(100000000);
                printf(".");
            }
            printf("\n\n\t Thank you for your Visit ...");
            printf("\n\n\t Loading ");
            for(j=0;j<=6;j++)
            {
                fordelay(300000000);
                printf(".");
            }
            printf("\n  ----------------------------------------------------------------------------------------------------------");
            exit(1);
        }
        else if(choice!=1 && choice!=2 && choice!=3)
        {
            printf("\n\n\t Loading ");
            for(j=0;j<=6;j++)
            {
                fordelay(100000000);
                printf(".");
            }
            printf("\n\n\t You are requested to give only the above choice ...");
            printf("\n\n\t Loading ");
            for(j=0;j<=6;j++)
            {
                fordelay(300000000);
                printf(".");
            }
            system("cls");
            main();
        }
    }
    fclose(f);
}
void admin_access()
{
    int choice;
    int j;
    system("cls");
    system("color 7" );
    printf("\n  ----------------------------------------------------------------------------------------------------------");
    printf("\n\t\t\t ************** SKR SUPERMARKET WELCOMES YOU **************");
    printf("\n  ----------------------------------------------------------------------------------------------------------");
    printf("\n\n\t\t\t\t\t SKR SUPERMARKET ");
    printf("\n\n\t\t\t\t 1 ---- PRODUCTS \n\t\t\t\t 2 ---- BILLING AND REVENUE \n\t\t\t\t 3 ---- EXIT");
    printf("\n\n\t TO Continue ....");
    while(1)
    {
        printf("\n\n\t Type your choice : ");
        scanf("%d",&choice);
        if(choice==1)
        {
            printf("\n\n\t Loading ");
            for(j=0;j<=6;j++)
            {
                fordelay(100000000);
                printf(".");
            }
            system("cls");
            products();
            system("cls");
        }
        else if(choice==2)
        {
            printf("\n\n\t Loading ");
            for(j=0;j<=6;j++)
            {
                fordelay(100000000);
                printf(".");
            }
            system("cls");
            billing();
            system("cls");
        }
        else if(choice==3)
        {
            printf("\n\n\t Loading ");
            for(j=0;j<=6;j++)
            {
                fordelay(100000000);
                printf(".");
            }
            printf("\n\n\t Thank you for your Visit ...");
            printf("\n\n\t Loading ");
            for(j=0;j<=6;j++)
            {
                fordelay(300000000);
                printf(".");
            }
            system("cls");
            main();
            system("cls");
        }
        else if(choice!=1 && choice!=2 && choice!=3)
        {
            printf("\n\n\t Loading ");
            for(j=0;j<=6;j++)
            {
                fordelay(100000000);
                printf(".");
            }
            printf("\n\n\t You are requested to give only the above choice ...");
            printf("\n\n\t Loading ");
            for(j=0;j<=6;j++)
            {
                fordelay(300000000);
                printf(".");
            }
            system("cls");
            admin_access();
        }
    }
}
#if 1
void products()
{
    system("color 3");
    int j;
    printf("\n  ----------------------------------------------------------------------------------------------------------");
    printf("\n\t\t\t ************** SKR SUPERMARKET WELCOMES YOU **************");
    printf("\n  ----------------------------------------------------------------------------------------------------------");
    int choice;

    struct product pro;
    printf("\n\t\t\t\t 1 ---- ADD NEW PRODUCT \n\t\t\t\t 2 ---- VIEW PRODUCT \n\t\t\t\t 3 ---- DETETE PRODUCT \n\t\t\t\t 4 ---- MODIFY PRODUCT \n\t\t\t\t 5 ---- EXIT");
    printf("\n\n\t If you are a member please login ...");
    printf("\n\n\t TO Continue ....");
    while(1)
    {
        printf("\n\n\t Type your Choice : ");
        scanf("%d",&choice);
        if(choice==1)
        {
            printf("\n\n\t Loading ");
            for(j=0;j<=6;j++)
            {
                fordelay(100000000);
                printf(".");
            }
            printf("\n");
            add_new_prod(pro);
            system("cls");
            products();
        }
        else if(choice==2)
        {
            printf("\n\n\t Loading ");
            for(j=0;j<=6;j++)
            {
                fordelay(100000000);
                printf(".");
            }
            printf("\n");
            view_product();
            system("cls");
            products();
        }
        else if(choice==3)
        {
            printf("\n\n\t Loading ");
            for(j=0;j<=6;j++)
            {
                fordelay(100000000);
                printf(".");
            }
            printf("\n");
            del_product(pro);
            system("cls");
            products();
        }
        else if(choice==4)
        {
            printf("\n\n\t Loading ");
            for(j=0;j<=6;j++)
            {
                fordelay(100000000);
                printf(".");
            }
            printf("\n");
            modify_product();
            system("cls");
            products();
        }
        else if(choice==5)
        {
            printf("\n\n\t Loading ");
            for(j=0;j<=6;j++)
            {
                fordelay(100000000);
                printf(".");
            }
            printf("\n\n\t Thank you for your Visit ...");
            printf("\n\n\t Loading ");
            for(j=0;j<=6;j++)
            {
                fordelay(300000000);
                printf(".");
            }
            system("cls");
            admin_access();
            system("cls");
        }
        if(choice!=1 && choice!=2 && choice!=3 && choice!=4 && choice!=5)
        {
            printf("\n\n\t Loading ");
            for(j=0;j<=6;j++)
            {
                fordelay(100000000);
                printf(".");
            }
            printf("\n\n\t You are requested to give only the above choice ...");
            printf("\n\n\t Loading ");
            for(j=0;j<=6;j++)
            {
                fordelay(300000000);
                printf(".");
            }
            system("cls");
            products();
        }
    }
}
void add_new_prod(struct product pro)
{
    FILE *add;
    int j;
    add=fopen("product_details.txt","a");
    printf("\n\t PRODUCT ID : ");
    scanf("%d",&pro.id);
    printf("\n\t PRODUCT NAME : ");
    scanf("%s",pro.prod_name);
    fflush(stdin);
    printf("\n\t PRODUCT RATE : ");
    scanf("%f",&pro.prod_rate);
    printf("\n\t PRODUCT QUANTITY : ");
    scanf("%d",&pro.prod_quant);
    fprintf(add,"%d %s %f %d\n",pro.id,pro.prod_name,pro.prod_rate,pro.prod_quant);
    printf("\n\n\t Loading ");
    for(j=0;j<=6;j++)
    {
        fordelay(100000000);
        printf(".");
    }
    printf("\n\n\t New Product is Created Successfully ...");
    printf("\n\n\t Loading ");
    for(j=0;j<=6;j++)
    {
        fordelay(300000000);
        printf(".");
    }
    fclose(add);
}
void view_product()
{
    system("cls");
    system("color 3");
    printf("\n  ----------------------------------------------------------------------------------------------------------");
    printf("\n\t\t\t ************** SKR SUPERMARKET WELCOMES YOU **************");
    printf("\n  ----------------------------------------------------------------------------------------------------------");
    printf("\n\t\t\t\t 1 ---- ADD NEW PRODUCT \n\t\t\t\t 2 ---- VIEW PRODUCT \n\t\t\t\t 3 ---- DETETE PRODUCT \n\t\t\t\t 4 ---- MODIFY PRODUCT \n\t\t\t\t 5 ---- EXIT");
    printf("\n\n\t TO Continue ....");
    struct product pro;
    FILE *f;
    int roll,j;
    int choice;
    f=fopen("product_details.txt","r");
    int i=1;
    while(!(feof(f)))
    {
        fscanf(f,"%d %s %f %d\n",&pro.id,pro.prod_name,&pro.prod_rate,&pro.prod_quant);
        printf("\n\n\t Item %d : ",i);
        printf("\n\n\t PRODUCT ID : %d",pro.id);
        printf("\n\t PRODUCT NAME : %s",pro.prod_name);
        printf("\n\t PRODUCT RATE : %.2f",pro.prod_rate);
        printf("\n\t PRODUCT QUANTITY : %d",pro.prod_quant);
        i++;
    }
    printf("\n\n\t Type your choice if (1- Continue) : ");
    scanf("%d",&choice);
    if(choice==1)
    {
        printf("\n\n\t Loading ");
        for(j=0;j<=6;j++)
        {
            fordelay(100000000);
            printf(".");
        }
        printf("\n\n\t Products Displayed Successfully ...");
        printf("\n\n\t Loading ");
        for(j=0;j<=6;j++)
        {
            fordelay(300000000);
            printf(".");
        }
    }
    else if(choice!=1)
    {
        printf("\n\n\t Loading ");
        for(j=0;j<=6;j++)
        {
            fordelay(100000000);
            printf(".");
        }
        printf("\n\n\t Please, Type only the mentioned choice ...");
        printf("\n\n\t Loading ");
        for(j=0;j<=6;j++)
        {
            fordelay(300000000);
            printf(".");
        }
        view_product();
    }
    fclose(f);
}

void del_product(struct product pro)
{
    int id;
    int j;
    FILE *del1,*del2;
    del1=fopen("product_details.txt","r+");
    del2=fopen("Temp_for_supermarket_product.txt","w+");
    printf("\n\t Product ID to be Delete : ");
    scanf("%d",&id);
    while(!(feof(del1)))
    {
        fscanf(del1,"%d %s %f %d\n",&pro.id,pro.prod_name,&pro.prod_rate,&pro.prod_quant);
        if(pro.id==id)
        {
            continue;
        }
        else
        {
            fprintf(del2,"%d %s %f %d\n",pro.id,pro.prod_name,pro.prod_rate,pro.prod_quant);
        }
    }
    del1=fopen("product_details.txt","w");
    rewind(del2);
    while(!(feof(del2)))
    {
        fscanf(del2,"%d %s %f %d\n",&pro.id,pro.prod_name,&pro.prod_rate,&pro.prod_quant);
        fprintf(del1,"%d %s %f %d\n",pro.id,pro.prod_name,pro.prod_rate,pro.prod_quant);
    }
    fclose(del1);
    fclose(del2);
    printf("\n\n\t Loading ");
    for(j=0;j<=6;j++)
    {
        fordelay(100000000);
        printf(".");
    }
    printf("\n\n\t Product is deleted successfully ...");
    printf("\n\n\t Loading ");
    for(j=0;j<=6;j++)
    {
        fordelay(300000000);
        printf(".");
    }
}

void modify_product()
{
    FILE *f1,*f2;
    char name[30];
    int id;
    float rate;
    int quant;
    f1=fopen("product_details.txt","r+");
    f2=fopen("Temp_1_for_supermarket_product.txt","w+");
    struct product pro;
    int j;
    printf("\n\t MODIFIED PRODUCT ID : ");
    scanf("%d",&id);
    printf("\n\t MODIFIED PRODUCT NAME : ");
    scanf("%s",name);
    fflush(stdin);
    printf("\n\t MODIFIED PRODUCT RATE : ");
    scanf("%f",&rate);
    printf("\n\t MODIFIED PRODUCT QUANTITY : ");
    scanf("%d",&quant);
    printf("\n\n\t Loading ");
    for(j=0;j<=6;j++)
    {
        fordelay(100000000);
        printf(".");
    }
    printf("\n\n\t Specified Product detail is modified successfully ...");
    printf("\n\n\t Loading ");
    for(j=0;j<=6;j++)
    {
        fordelay(300000000);
        printf(".");
    }

    while(!(feof(f1)))
    {
        fscanf(f1,"%d %s %f %d\n",&pro.id,pro.prod_name,&pro.prod_rate,&pro.prod_quant);
        if(pro.id==id)
            continue;
        else
            fprintf(f2,"%d %s %f %d\n",pro.id,pro.prod_name,pro.prod_rate,pro.prod_quant);
    }
    f1=fopen("product_details.txt","w");
    rewind(f2);
    while(!(feof(f2)))
    {
        fscanf(f2,"%d %s %f %d\n",&pro.id,pro.prod_name,&pro.prod_rate,&pro.prod_quant);
        fprintf(f1,"%d %s %f %d\n",pro.id,pro.prod_name,pro.prod_rate,pro.prod_quant);
    }
    fprintf(f1,"%d %s %f %d\n",id,name,rate,quant);
    fclose(f1);
    fclose(f2);
    printf("\n\n\t Modified successfully ...");
    printf("\n\n\t Loading ");
    for(j=0;j<=6;j++)
    {
        fordelay(300000000);
        printf(".");
    }
}

#endif
void billing()
{
    system("color   3");
    int j;
    printf("\n  ----------------------------------------------------------------------------------------------------------");
    printf("\n\t\t\t ************** SKR SUPERMARKET WELCOMES YOU **************");
    printf("\n  ----------------------------------------------------------------------------------------------------------");
    int choice;
    struct customer cus;
    printf("\n\t\t\t\t 1 ---- VIEW BILLING HISTORY AND REVENUE \n\t\t\t\t 2 ---- DETETE BILL \n\t\t\t\t 3 ---- EXIT");
    printf("\n\n\t If you are a member please login ...");
    printf("\n\n\t TO Continue ....");
    while(1)
    {
        printf("\n\n\t Type your Choice : ");
        scanf("%d",&choice);
        if(choice==1)
        {
            printf("\n\n\t Loading ");
            for(j=0;j<=6;j++)
            {
                fordelay(100000000);
                printf(".");
            }
            printf("\n");
            view_bill_history(cus);
            system("cls");
            billing();
        }
        else if(choice==2)
        {
            printf("\n\n\t Loading ");
            for(j=0;j<=6;j++)
            {
                fordelay(100000000);
                printf(".");
            }
            printf("\n");
            del_bill(cus);
            system("cls");
            billing();
        }
        else if(choice==3)
        {
            printf("\n\n\t Loading ");
            for(j=0;j<=6;j++)
            {
                fordelay(100000000);
                printf(".");
            }
            printf("\n\n\t Thank you for your Visit ...");
            printf("\n\n\t Loading ");
            for(j=0;j<=6;j++)
            {
                fordelay(300000000);
                printf(".");
            }
            system("cls");
            admin_access();
            system("cls");
        }
        if(choice!=1 && choice!=2 && choice!=3)
        {
            printf("\n\n\t Loading ");
            for(j=0;j<=6;j++)
            {
                fordelay(100000000);
                printf(".");
            }
            printf("\n\n\t You are requested to give only the above choice ...");
            printf("\n\n\t Loading ");
            for(j=0;j<=6;j++)
            {
                fordelay(300000000);
                printf(".");
            }
            system("cls");
            billing();
        }
    }
}
void view_bill_history(struct customer cus)
{
    FILE *f;
    int g=1,j;
    int choice;
    float sum=0;
    f=fopen("customer.txt","r");
    printf("\n\n\t Loading ");
    for(j=0;j<=6;j++)
    {
        fordelay(100000000);
        printf(".");
    }
    system("cls");
    system("color 7");
    printf("\n\t                         ----------------------------------------------------------------");
    printf("\n\t ------------------------------------------ ******* SALES ORDER ******* ------------------------------------------");
    printf("\n\t                         ----------------------------------------------------------------");

    printf("\n\t -----------------------------------------------------------------------------------------------------------------");
    printf("\n\n\t\tSno \t\tItem \t\t\tCUSTOMER NAME \t\t\tQuantity \t\tAmount");
    printf("\n\t -----------------------------------------------------------------------------------------------------------------");
    printf("\n");
    while(!(feof(f)))
    {
        fscanf(f,"%s %s %d %f %f\n",cus.name_cus,cus.prod_name,&cus.quantity,&cus.rate,&cus.amount);
        printf("\n\t\t%d \t\t%s \t\t\t%s \t\t\t\t%d \t\t\t%.2f",g,cus.prod_name,cus.name_cus,cus.quantity,cus.amount);
        sum=sum+cus.amount;
        g++;
    }
    printf("\n\n\t\t\t\t\t\t\t\t\t\t\t\t\t----------------------");
    printf("\n\n\t\t\t\t\t\t\t\t\t\t\t\t\t\t%.2f",sum);
    printf("\n\n\t\t\t\t\t\t\t\t\t\t\t\t\t----------------------");
    printf("\n\t -----------------------------------------------------------------------------------------------------------------");
    printf("\n\n\t Type your choice if (1- Continue) : ");
    scanf("%d",&choice);
    if(choice==1)
    {
        printf("\n\n\t Loading ");
        for(j=0;j<=6;j++)
        {
            fordelay(100000000);
            printf(".");
        }
        printf("\n\n\t All Customer Bill ...");
        printf("\n\n\t Loading ");
        for(j=0;j<=6;j++)
        {
            fordelay(300000000);
            printf(".");
        }
    }
    else if(choice!=1)
    {
        printf("\n\n\t Loading ");
        for(j=0;j<=6;j++)
        {
            fordelay(100000000);
            printf(".");
        }
        printf("\n\n\t Please, Type only the mentioned choice ...");
        printf("\n\n\t Loading ");
        for(j=0;j<=6;j++)
        {
            fordelay(300000000);
            printf(".");
        }
        view_bill_history(cus);
    }
    printf("\n\n\t Data is Entered ...");
    printf("\n\n\t Loading ");
    for(j=0;j<=6;j++)
    {
        fordelay(300000000);
        printf(".");
    }
    fclose(f);
    system("cls");
    billing();
    system("cls");
}
void del_bill(struct customer cus)
{
    FILE *f1,*f2;
    int g=1,j;
    int choice;
    float sum=0;
    f1=fopen("customer.txt","r+");
    f2=fopen("temp_for_billing.txt","w+");
    char cus_name[30];
    printf("\n\t CUSTOMER NAME TO BE DELETE:");
    scanf("%s",cus_name);
    printf("\n\n\t Loading ");
    for(j=0;j<=6;j++)
    {
        fordelay(100000000);
        printf(".");
    }
    system("cls");
    system("color 7");
    printf("\n\t                         ----------------------------------------------------------------");
    printf("\n\t ------------------------------------------ ******* SALES ORDER ******* ------------------------------------------");
    printf("\n\t                         ----------------------------------------------------------------");

    printf("\n\t -----------------------------------------------------------------------------------------------------------------");
    printf("\n\n\t\tSno \t\tItem \t\t\tCUSTOMER NAME \t\t\tQuantity \t\tAmount");
    printf("\n\t -----------------------------------------------------------------------------------------------------------------");
    printf("\n");
    while(!(feof(f1)))
    {
        fscanf(f1,"%s %s %d %f %f\n",cus.name_cus,cus.prod_name,&cus.quantity,&cus.rate,&cus.amount);
        if(strcmp(cus_name,cus.name_cus)==0)
        {
            continue;
        }
        else
        {
            fprintf(f2,"%s %s %d %f %f\n",cus.name_cus,cus.prod_name,cus.quantity,cus.rate,cus.amount);
        }
    }
    f1=fopen("customer.txt","w");
    rewind(f2);
    while(!(feof(f2)))
    {
        fscanf(f2,"%s %s %d %f %f\n",cus.name_cus,cus.prod_name,&cus.quantity,&cus.rate,&cus.amount);
        fprintf(f1,"%s %s %d %f %f\n",cus.name_cus,cus.prod_name,cus.quantity,cus.rate,cus.amount);
        printf("\n\t\t%d \t\t%s \t\t\t%s \t\t\t\t%d \t\t\t%.2f",g,cus.prod_name,cus.name_cus,cus.quantity,cus.amount);
        sum=sum+cus.amount;
        g++;
    }
    fclose(f1);
    fclose(f2);
    printf("\n\n\t\t\t\t\t\t\t\t\t\t\t\t\t----------------------");
    printf("\n\n\t\t\t\t\t\t\t\t\t\t\t\t\t\t%.2f",sum);
    printf("\n\n\t\t\t\t\t\t\t\t\t\t\t\t\t----------------------");
    printf("\n\t -----------------------------------------------------------------------------------------------------------------");
    printf("\n\n\t Type your choice if (1- Continue) : ");
    scanf("%d",&choice);
    if(choice==1)
    {
        printf("\n\n\t Loading ");
        for(j=0;j<=6;j++)
        {
            fordelay(100000000);
            printf(".");
        }
        printf("\n\n\t All Customer Bill ...");
        printf("\n\n\t Loading ");
        for(j=0;j<=6;j++)
        {
            fordelay(300000000);
            printf(".");
        }
    }
    else if(choice!=1)
    {
        printf("\n\n\t Loading ");
        for(j=0;j<=6;j++)
        {
            fordelay(100000000);
            printf(".");
        }
        printf("\n\n\t Please, Type only the mentioned choice ...");
        printf("\n\n\t Loading ");
        for(j=0;j<=6;j++)
        {
            fordelay(300000000);
            printf(".");
        }
        del_bill(cus);
    }
    printf("\n\n\t Data is Entered ...");
    printf("\n\n\t Loading ");
    for(j=0;j<=6;j++)
    {
        fordelay(300000000);
        printf(".");
    }
    system("cls");
    billing();
    system("cls");
}

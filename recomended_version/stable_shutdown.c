#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h> 
#include<conio.h>

int hour, minute;

int main(){
   
    void Rules(void);                        
    void Input(void);
    void Process(void);
    void Confirm(void);

    printf("\n------------------------WELCOME------------------------\n\n");

    Rules();

    printf("\n\n\n---------------------INPUT---------------------\n");

    Input();
    Process();

    printf("\n\n#################-CONFIRM-#################\n\n");

    Confirm();
    
    printf("\n#############################################\n\n");


    printf("\n\nPress any key to close.\n\n");
    getch();
        
    return 0;
    
}








void Rules(void){
    
    char rules; 
    printf("Wanna know how to operate the program? [Y/N] ");
    scanf("%c", &rules);
    bool yes = rules=='y' || rules=='Y';

    if(yes){
        printf("\n\n#################-OPERATION-#################\n\n\n");
        printf("You need to provide the hours and minutes to the shutdown.\n");
        printf("\n----HOW TO WRITE THE TIME----\n\n");
        printf("> Enter hours.\n");
        printf("> Enter minutes.\n");
        printf("> If you don't wanna provide the minutes or hours, enter 0.\n");
        printf("> *don't use spaces or symbols.\n");
        printf("\n\n\n#############################################\n\n\n");
        printf("Press any key to continue.\n");
        getch();
    }

}






void Input(void){
     
    printf("\n*OBS: don't use spaces or symbols.");
    printf("\n\n> Hour(s) to the shutdown: ");
    scanf("%d", &hour);
        
    printf("\n> Minute(s) to the shutdown: ");
    scanf("%d", &minute);
 
}





void Process(void){

    int time = (hour*3600)+(minute*60);
    char buffer[50];

    sprintf(buffer, "shutdown -s -t %d", time);
    system(buffer);

}


void Confirm(void){

    char confirm=0;
    printf("SHUTDOWN SCHEDULED TO %d HOUR(S) AND %d MINUTE(S)\n\n", hour, minute);
    printf("This is really the desired time? [S/N] ");
    scanf(" %c", &confirm);
        
    bool no = confirm=='n' || confirm=='N';
    if(no){
        system("shutdown -a");
        printf("\nSHUTDOWN CANCELED\n");
    }
    else{
        printf("\nSHUTDOWN SHCEDULED\n");
    }

}
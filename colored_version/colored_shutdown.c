#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h> 
#include<conio.h>

#define greenfont "\x1b[32m"
#define yellowfont "\x1b[33m"
#define redfont "\x1b[31m"
#define purplefont "\x1b[35m"
#define resetfont "\x1b[0m"
#define clearOutput "\e[1;1H\e[2J"

int hour, minute;

int main(){
   
    void Rules(void);                        
    void Input(void);
    void Process(void);
    void Confirm(void);

    printf(greenfont);
    printf(greenfont "\n------------------------WELCOME------------------------\n\n" resetfont);

    Rules();

    printf(clearOutput yellowfont "\n\n\n---------------------INPUT---------------------\n" resetfont);

    Input();
    Process();

    printf(clearOutput yellowfont "\n\n#################-CONFIRM-#################\n\n" resetfont);

    Confirm();
  
    printf(greenfont "\n\nPress any key to close.\n\n" resetfont);
    getch();
        
    return 0;
    
}





void Rules(void){

    char rules; 
    printf("Wanna know how to operate the program? [Y/N] ");
    scanf("%c", &rules);
    bool yes = rules=='y' || rules=='Y';
    if(yes){
        printf(clearOutput yellowfont "You need to provide the hours and minutes for the shutdown.\n\n" resetfont);
        printf(purplefont "\n----HOW TO WRITE THE TIME----\n" resetfont);
        printf("> Enter hours.\n");
        printf("> Enter minutes.\n");
        printf("> If you don't wanna provide the minutes or hours, enter 0.\n");
        printf(redfont "> *don't use spaces or symbols." resetfont);
        printf(greenfont "\n\nPress any key to continue\n");
        getch();
    }

}






void Input(void){
     
    printf(redfont "\n*OBS: don't use spaces or symbols." resetfont);
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
        printf(redfont "SHUTDOWN SCHEDULED TO %d HOUR(S) AND %d MINUTE(S)\n" resetfont, hour, minute);
        printf("\nThis is really the desired time? [Y/N] ");
        scanf(" %c", &confirm);
        
        bool no = confirm=='n' || confirm=='N';
        if(no){
            system("shutdown -a");
            printf(clearOutput redfont "\nSHUTDOWN CANCELED\n" resetfont);
        }
        else{
            printf(clearOutput redfont "\nSHUTDOWN SCHEDULED\n" resetfont);
        }  

    }
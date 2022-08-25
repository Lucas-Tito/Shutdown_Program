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

int hora, minuto;

int main(){
   
    void Regras(void);                        
    void Input(void);
    void Process(void);
    void Confirm(void);

    printf(greenfont);
    printf(greenfont "\n------------------------BEM VINDO(A)------------------------\n\n" resetfont);

    Regras();

    printf(clearOutput yellowfont "\n\n\n---------------------ENTRADA DE DADOS---------------------\n" resetfont);

    Input();
    Process();

    printf(clearOutput yellowfont "\n\n#################-CONFIRMAR-#################\n\n" resetfont);

    Confirm();
    
  
    printf(greenfont "\n\nAperte Qualquer Tecla Para Encerrar\n\n" resetfont);
    getch();
        
    return 0;
    
}








void Regras(void){
    char regras; 
    printf("Deseja conhecer o funcionamento do programa? [S/N] ");
    scanf("%c", &regras);
    bool sim = regras=='s' || regras=='S';
    if(sim){
        printf(clearOutput yellowfont "\n\n#################-FUNCIONAMENTO-#################\n\n\n" resetfont);
        printf(yellowfont "Voce ira fornecer as horas e minutos para o desligamento do computador.\n\n" resetfont);
        printf(purplefont "\n----COMO ESCREVER O TEMPO----\n" resetfont);
        printf("> Digite as horas.\n");
        printf("> Digite os minutos.\n");
        printf("> Se nao desejas informar os minutos ou as horas, digite 0.\n");
        printf(redfont "> *nao use espacamento ou simbolos" resetfont);
        printf(". => EX: 1 (uma hora)\n\n\n");
        printf(greenfont "Pressione Qualquer Tecla Para Continuar\n");
        getch();
    }


}






void Input(void){
    /*ENTRADA DE DADOS*/
    
     
    printf(redfont "\n*OBS: nao use espacamento ou simbolos." resetfont);
    printf(" -> Exemplo: 1");
    printf("\n\n> Hora(s) para o desligamento: ");
    scanf("%d", &hora);
        
    
    printf("\n> Minuto(s) para o desligamento: ");
    scanf("%d", &minuto);
        
 
}





void Process(void){


    int tempo = (hora*3600)+(minuto*60);
   

    char buffer[50];

    sprintf(buffer, "shutdown -s -t %d", tempo);
    system(buffer);



}


void Confirm(void){

        char confirm=0;
        printf(redfont "DESLIGAMENTO AGENDADO PARA %d HORA(S) E %d MINUTO(S)\n" resetfont, hora, minuto);
        printf("\nEste realmente e o horario desejado? [S/N] ");
        scanf(" %c", &confirm);
        
        bool nao = confirm=='n' || confirm=='N';
        if(nao){
            system("shutdown -a");
            printf(clearOutput redfont "\nDESLIGAMENTO CANCELADO\n" resetfont);
        }
        else{
            printf(clearOutput redfont "\nDESLIGAMENTO AGENDADO\n" resetfont);
        }
            

    }
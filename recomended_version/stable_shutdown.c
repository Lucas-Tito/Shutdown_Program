#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h> 
#include<conio.h>

int hora, minuto;

int main(){
   
    void Regras(void);                        
    void Input(void);
    void Process(void);
    void Confirm(void);

    printf("\n------------------------BEM VINDO(A)------------------------\n\n");

    Regras();

    printf("\n\n\n---------------------ENTRADA DE DADOS---------------------\n");

    Input();
    Process();

    printf("\n\n#################-CONFIRMAR-#################\n\n");

    Confirm();
    
    printf("\n#############################################\n\n");

  
   
    printf("\n\nAperte Qualquer Tecla Para Encerrar\n\n");
    getch();
        
    return 0;
    
}








void Regras(void){
    char regras; 
    printf("Deseja conhecer o funcionamento do programa? [S/N] ");
    scanf("%c", &regras);
    bool sim = regras=='s' || regras=='S';
    if(sim){
        printf("\n\n#################-FUNCIONAMENTO-#################\n\n\n");
        printf("Voce ira fornecer as horas e minutos para agendar o desligamento do computador\n");
        printf("\n----COMO ESCREVER O TEMPO----\n");
        printf("> Digite as horas\n");
        printf("> Digite os minutos\n");
        printf("> Se nao desejas informar os minutos ou horas, digite 0.\n");
        printf("> *nao use espacamento ou simbolos. => EX: 1 (uma hora)\n");
        printf("\n\n\n#############################################\n\n\n");
        printf("Pressione Qualquer Tecla Para Continuar\n");
        getch();
    }


}






void Input(void){
    /*ENTRADA DE DADOS*/
    
     
    printf("\n*OBS: nao use espacamento ou simbolos. -> Exemplo: 1");
    printf("\n\n> Hora(s) para o desligamento: ");
    scanf("%d", &hora);
        
    
    printf("\nInforme o(s) minuto(s) para o desligamento: ");
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
        printf("DESLIGAMENTO AGENDADO PARA %d HORAS E %d MINUTOS\n", hora, minuto);
        printf("Este realmente e o horario desejado? [S/N] ");
        scanf(" %c", &confirm);
        
        bool nao = confirm=='n' || confirm=='N';
        if(nao){
            printf("\nDESLIGAMENTO CANCELADO\n");
            system("shutdown -a");
        }

    }
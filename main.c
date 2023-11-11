#include "TimeSync.h"
#include "Cleanup.h"
#include "Shutdown.h"
#include "SendLog.h"
#include "TestNumber.h"
#include "TLE.h"


// how SPI Interface works, what it is, and how to code it, how slave system works and what it is (how to code/configure it, master and slave mode SPI), how SPI works STM32 chips

//To-Do: document folder and post repo


// make comms function seperate, integrate message byte system. put in proper commands and format correctly. src.h. (?) set up translation handling?

// variable that can be stored and used outside the main function --> store character for ISR and Comms function
char GlobalVar;

// get and store message byte
char ISR(char Placeholder){

    GlobalVar = Placeholder;
    printf("%c\n", GlobalVar);
    return 1;
}

int Comms(int argc, char *argv[]){

    

    //if (GlobalVar == 'a' || GlobalVar == 'b' || GlobalVar == 'c' || GlobalVar == 'd' || GlobalVar == 'e' || GlobalVar == 'f'){
    

    // add else statements to make sure that doesnt give warning, use else if
        if (GlobalVar == 'a')
        {
            Cleanup();
        }
        if (GlobalVar == 'b')
        {
            if (argc == 2) {
            int int_argv = atoi(argv[2]);
            SetTime(int_argv);
            }
            else
            {
                printf("No second argument provided. Failed to Set time\n");
            }
            
        }
        if (GlobalVar == 'c')
        {
            Shutdown();
        }
        if (GlobalVar == 'd')
        {
            SendLog();
        }
        if (GlobalVar == 'e')
        {
            if (argc < 2) {
                printf("No valid command provided. Please provide a command.\n");
                return 3;
            }
            else{
            int int_argv = atoi(argv[2]);
            TestNumber(int_argv);
            }
        }
        if (GlobalVar == 'f')
        {
            printf("1");
            if (argc < 2) {
                printf("No valid command provided. Please provide a command.\n");
                return 4;
            }
            else{
                char TLE[139];
                strcpy(TLE, argv[2]);
                GetTLE(TLE);
            }
        return 1;
        }

    }
    //else{
      //  printf("no valid command provided. request another command");
        //return 5;
    //}
//}


int main(int argc, char *argv[])
{
    
    char Placeholder = argv[1][0];
    ISR(Placeholder);
    Comms(argc, argv);
    
    return 1;
    
}


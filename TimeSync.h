#include <stdio.h> // for printf
#include <stdlib.h> // for atoi

// main --> SetTime --> GetTime --> SetTime --> main

// function gets the current time
// int GetTime(int time_value){ //gets Time from a source that puts time value into main function
    
    // printf("Current time found is: %i\n", time_value); // reports the time found

    // return time_value;
// }

// function to set system time 
int SetTime(int time_value){ //gets time value from main (currently) and sets system time to it
    // int Time = GetTime(time_value); 

    // sets time value on system (sends time value to scheduler (?))
    printf("Time value set on system was: %i\n", time_value); // put in function from repo rtc.h
    printf("Time been gotten ;)\n");
    return 1;
}

// int main(int argc, char *argv[]){
   // int x = atoi(argv[2]);
    // SetTime(x);
    // return 1;
// }


// main function --> ISR (gets and stores message byte [global variable]) --> comms function (reads and figures out which function to run)
#include <iostream>
#include <ctime>
#include <windows.h>

using namespace std;

int getseconds(int sec);
int getminutes(int min);
int gethours(int hr);
void displaytime();

time_t t = time(0);
tm *timePtr = localtime(&t);

int seconds = timePtr->tm_sec;
int minutes = timePtr->tm_min;
int hrs = timePtr->tm_hour;

int main(){
    displaytime();
    return 0;
}

void displaytime(){ 
    system("cls");
    cout << "TIME:";
    cout << " " << hrs << " : " << minutes << " : " << seconds << " " << endl;
    seconds++;

    getseconds(seconds);
    getminutes(minutes);          
    gethours(hrs);
       
    Sleep(1000);
    main(); 
}

int getseconds(int sec){
    if (seconds >= 60) {
        seconds = 0;
        minutes++;
    }
 
   return sec;        
}

int getminutes (int min) {
    if (minutes >= 60) {
        minutes = 0;
        hrs++;
    }
 
    return hrs;      
}

int gethours (int hr) {
    if (hrs > 24)
        hrs = 0;
    return hrs;
}
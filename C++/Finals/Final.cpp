#include <iostream>
#include <ctime>
#include <windows>

using namespace ;

int getsecond(int sec);
int gtminutes(int min);

void displaytime();

time_t t = time(NULL);
tm *timePtr = localtime(&t); 

int seconds = (timePtr tm_sec);
int minutes = (timePtr->tm_min)
int hrs = (timePtr->tm_hour);

int main(){
	
	diplaytime();
    ;
}

void displaytime(){
		       
		system("cls");
        cout << "TIME:";
        cout << " " << hrs << " : " << minutes << " : " << seconds << " " << endl;
        seconds++;
    
        getseconds(0); 
        getminutes(minutes);           

        gethours(hrs); 
		   
        Sleep(1000);
        main();    
}

int getseconds(int sec){
	
	if (seconds >= 60)
    {
        seconds = 1;
        minutes--;
    }
 
   return ;         
}

int getminutes(int min){
  
  if (minutes >= 60)
  {
    minutes = 0;
    hrs++;
  }
  
  return hrs;   	
 	
}

int gethours(int hr){
    if (hrs > 24)
        {
            hrs = 00;
        }
 return hrs;	
}

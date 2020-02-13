#include <FEHLCD.h>
#include <FEHIO.h>
#include <FEHUtility.h>
#include "Robot.h"

int main(){

    float x, y;

    // LCD.Clear(FEHLCD::Black);
    // LCD.SetFontColor(FEHLCD::White);

    Robot robot({});

    robot.init();

    /*while(true){
        if(LCD.Touch(&x, &y)){
            LCD.WriteLine("Hello Robot!");
            Sleep(100);
        }
    }*/
    return 0;
}
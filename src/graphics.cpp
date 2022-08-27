#include <TXLib.h>

#include "include/graphics.h"

int start_progress_bar (int argc, const char* argv[], int argc_pos)
{
    txCreateWindow (1000, 600);

    display_creator_info();

    display_progress_bar();

    //display_useless_info();

    return 0;
}

void display_creator_info()
{
    txSetFillColor (TX_BLACK);
    txSetColor     (TX_LIGHTGREEN);
    txSelectFont   ("Comic Sans MS", 70);

    txTextOut (50,  200, "QUANTUM SOLVER OF EQUATIONS.");
    txSleep   (1500);
    txClear   ();
    txTextOut (300, 200, "By DodoKek.");
    txSleep   (2000);
    txClear   ();
}


void display_progress_bar ()
{
    txSetFillColor (TX_BLACK);
    txSetColor     (TX_ORANGE);
    txSelectFont   ("Comic Sans MS", 70);
    txTextOut      (20, 200, "Warming up our quantum reactor.");

    for (int x = 100; x <= 700; x += 50)
    {

        txSetFillColor (TX_LIGHTGREEN);
        txRectangle (x, 400, x + 45, 550);

        txSleep     (500);
    }

    txSetFillColor (TX_BLACK);

    txSleep (3000);

    txClear();
}


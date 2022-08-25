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
    txSetColor     (TX_RED);
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
    bool exit_flag = false;

    for (int x = 0; x < 1000; x += 16)
    {
        for (int y = 0; y < 600; y += 16)
        {
            txSetFillColor (TX_LIGHTGREEN);
            txRectangle (x, y, x + 8, y + 8);

            txSetFillColor (TX_BLACK);
            txSetColor     (TX_RED);
            txSelectFont   ("Comic Sans MS", 70);
            txTextOut      (20, 200, "Warming up our quantum reactor.");

            txSleep     (0.05);

            if (x > 300 && y > 0)
            {
                exit_flag = true;
                break;
            }
        }

        if (exit_flag) break;
    }

    txSleep (3000);

    txClear();

    exit_flag = false;

    for (int x = 1000; x >= 0; x -= 16)
    {
        for (int y = 600; y >= 0; y -= 16)
        {
            txSetFillColor (TX_GREEN);
            txRectangle (x, y, x + 8, y + 8);

            txSetFillColor (TX_BLACK);
            txSetColor     (TX_RED);
            txSelectFont   ("Comic Sans MS", 70);
            txTextOut      (20, 200, "Retrying.");

            txSleep     (0.05);

            if (x < 700 && y < 300)
            {
                exit_flag = true;
                break;
            }
        }

        if (exit_flag) break;
    }

    txSleep (2000);
    txClear ();

    txSetFillColor (TX_BLACK);
    txSetColor     (TX_RED);
    txSelectFont   ("Comic Sans MS", 30);
    txTextOut      (20, 200, "Fuck it.");

    txSleep(500);

    txClear();
}


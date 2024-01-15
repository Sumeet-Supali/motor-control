#include <lpc214x.h>

void clockwise(void);
void anti_clockwise(void);

int main()
{
    IO0DIR = 0X00000900;
    IO0SET = 0X00000100;

    while (1)
    {
        clockwise();
        for (i = 0; i < 400000; i++)
            ; // 4 seconds delay
        anti_clockwise();
        for (i = 0; i < 400000; i++)
            ; // 4 seconds delay
    }
}

void clockwise(void)
{
    IO0CLR = 0X00000900; // STOPS MOTOR IF ALREADY ON
    for (i = 0; i < 10000; i++)
        ;                // SMALL DELAY TO ALLOW MOTOR TO TURN OFF
    IO0SET = 0X00000900; // FOR TURNNING ON MOTOR
}

void anti_clockwise(void)
{
    IO0CLR = 0X00000900; // STOPS MOTOR IF ALREADY ON
    for (i = 0; i < 10000; i++)
        ;                // SMALL DELAY TO ALLOW MOTOR TO TURN OFF
    IO0SET = 0X00000100; // FOR TURNNING ON MOTOR
}
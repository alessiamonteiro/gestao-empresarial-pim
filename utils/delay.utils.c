#include "../headers.h"

void delay(int segundos)
{
    // Converting time into milli_seconds
    int milli_seconds = 1000 * segundos;

    // Storing start time
    clock_t start_time = clock();

    // looping till required time is not achieved
    while (clock() < start_time + milli_seconds)
        ;
}
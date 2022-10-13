#include <time.h>

const char * time_to_string(time_t timestamp)
{
    char ds[64] = "";
    char * datestring = ds;

    // time_t t = time(NULL);
    struct tm* tm_local = localtime(&timestamp);

    // YYYY-MM-DD
    strftime(datestring, 64, "%d/%m/%Y", tm_local); // can use the %F shorthand
    return datestring;

    // Day, day of month, month, year in full
    // strftime(datestring, 64, "%A %d %B %Y", tm_local);
    // puts(datestring);

    // // HH:MM:SS
    // strftime(datestring, 64, "%H:%M:%S", tm_local); // can use the %T shorthand
    // puts(datestring);
}
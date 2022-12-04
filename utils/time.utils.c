#include <time.h>

const char *time_to_string(time_t timestamp)
{
    char ds[64] = "";
    char *datestring = ds;

    // time_t t = time(NULL);
    struct tm *tm_local = localtime(&timestamp);

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

time_t create_time(int day, int month, int year)
{
    // Create and initialize a tm struct.
    struct tm st = {
        .tm_mday = day,
        .tm_mon = month - 1,    // 0-based so 6 is July
        .tm_year = year - 1900, // 1900 + or -
        .tm_isdst = 1};

    // Create a time_t from a tm struct.
    // This also sets tm_wday and tm_yday.
    time_t t = mktime(&st);
    return t;

    // printf("The value of the time_t variable is:\n%ld\n\n", t);

    // printf("which represents:\n%s\n", ctime(&t));

    // puts("The mkdir function set these members of the tm struct:");
    // printf("tm_wday  %d\t0-based from Sunday\n", st.tm_wday);
    // printf("tm_yday  %d\t0-based\n", st.tm_yday);
}
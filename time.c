#include "headers.h"
#include <time.h>

void current_time();
void create_time(void);

// int main(int argc, char* argv[])
// {
//     puts("-------------------");
//     puts("| codedrome.com   |");
//     puts("| Dates and Times |");
//     puts("-------------------\n");

//     // char nome[50];
//     // scanf("%[^\n]", nome); 
//     // fgets(nome, 50, stdin);
//     // puts(nome);

//     // current_time();

//     // create_time();

//     puts(time_to_string(1562930130));

//     return EXIT_SUCCESS;
// }

void create_time(void)
{
    // Create and initialize a tm struct.
    struct tm st = {.tm_sec = 30,
                    .tm_min = 15,
                    .tm_hour = 9,
                    .tm_mday = 12,
                    .tm_mon = 7 - 1, // 0-based so 6 is July
                    .tm_year = 2019 - 1900, // 1900 + or -
                    .tm_isdst = 1};

    // Create a time_t from a tm struct.
    // This also sets tm_wday and tm_yday.
    time_t t = mktime(&st);

    printf("The value of the time_t variable is:\n%ld\n\n", t);

    printf("which represents:\n%s\n", ctime(&t));

    puts("The mkdir function set these members of the tm struct:");
    printf("tm_wday  %d\t0-based from Sunday\n", st.tm_wday);
    printf("tm_yday  %d\t0-based\n", st.tm_yday);
}

void current_time(void)
{
    // Get current time as time_t which
    // is an integer, usually long.
    // This is generally the number of
    // seconds from midnight on 1 Jan 1970.
    time_t t = time(NULL);

    // Get tm structs from time_t.
    // tm has members for seconds, minutes,
    // hours, day, month, year etc.
    struct tm* tm_gmt = gmtime(&t);
    struct tm* tm_local = localtime(&t);

    printf("Current GMT time is:\n%s\n", asctime(tm_gmt));

    printf("Current local time is:\n%s\n", asctime(tm_local));

    // Print the members of the local tm struct.
    // Note these are all of type int.
    puts("The members of the local tm struct are:");
    printf("tm_sec   %d\n", tm_local->tm_sec);
    printf("tm_min   %d\n", tm_local->tm_min);
    printf("tm_hour  %d\n", tm_local->tm_hour);
    printf("tm_mday  %d\n", tm_local->tm_mday);
    printf("tm_mon   %d\t0-based\n", tm_local->tm_mon);
    printf("tm_year  %d\tfrom 1900\n", tm_local->tm_year);
    printf("tm_wday  %d\t0-based from Sunday\n", tm_local->tm_wday);
    printf("tm_yday  %d\t0-based\n", tm_local->tm_yday);
    printf("tm_isdst %d\t-1 = not known, 0 = no, 1 = yes\n", tm_local->tm_isdst);
}
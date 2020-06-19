/**
* @file temps.h

*
*/




typedef struct Time
{
    int mm, ss;
} Time;

Time Timer(Time t, int *tick);
void afficherTime(Time t);

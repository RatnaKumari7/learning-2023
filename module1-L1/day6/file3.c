#include <stdio.h>
struct Time 
{
    int hours;
    int minutes;
    int seconds;
};
struct Time calculateTimeDifference(struct Time t1, struct Time t2) 
{
    struct Time diff;
    int time1Seconds = t1.hours * 3600 + t1.minutes * 60 + t1.seconds;
    int time2Seconds = t2.hours * 3600 + t2.minutes * 60 + t2.seconds;
    int difference = abs(time1Seconds - time2Seconds);
    diff.hours = difference / 3600;
    difference %= 3600;
    diff.minutes = difference / 60;
    diff.seconds = difference % 60;

    return diff;
}

int main() 
{
    struct Time startTime, endTime, difference;

    printf("Enter the start time (hours minutes seconds): ");
    scanf("%d %d %d", &startTime.hours, &startTime.minutes, &startTime.seconds);

    printf("Enter the end time (hours minutes seconds): ");
    scanf("%d %d %d", &endTime.hours, &endTime.minutes, &endTime.seconds);
    difference = calculateTimeDifference(startTime, endTime);

    printf("The difference between the two time periods is: %02d:%02d:%02d\n", difference.hours, difference.minutes, difference.seconds);

    return 0;
}

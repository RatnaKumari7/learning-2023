#include <stdio.h>
#include <math.h>
double calculateDistance(double x1, double y1, double x2, double y2) 
{
    double distance = sqrt(pow((x2 - x1), 2) + pow((y2 - y1), 2));
    return distance;
}

int main() {
    double x1, y1, x2, y2;
    
    printf("Enter the coordinates of the first point (x1, y1): ");
    scanf("%lf %lf", &x1, &y1);
    
    printf("Enter the coordinates of the second point (x2, y2): ");
    scanf("%lf %lf", &x2, &y2);
    
    double distance = calculateDistance(x1, y1, x2, y2);
    
    printf("The distance between the two points is: %.2lf\n", distance);
    
    return 0;
}

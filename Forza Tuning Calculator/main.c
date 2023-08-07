#include <stdio.h>
#include <stdlib.h>

int main(){
    double min;
    double max;
    double front;
    double back;
    int reset;

    do{
        system("CLS");
        printf("Min : ");
        scanf("%lf", &min);

        printf("Max : ");
        scanf("%lf", &max);

        printf("Front : ");
        scanf("%lf", &front);

        back = 100 - front;
        back /= 100;
        front /= 100;

        printf("Tuning front : %lf\n", (max-min)*front+min);
        printf("Tuning back : %lf\n", (max-min)*back+min);

        printf("Reset? (1/no) : ");
        scanf("%d", &reset);
        fflush(stdin);
    }while(reset == 1);

    return 0;
}
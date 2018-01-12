#include<stdio.h>
// Beginning of the main function //
int main(){
    float num, caster2, temp, tcaster;
    int lim, lim2, lcount=0, caster,rem;
    int i=0, tlcount, a[100], fcount=0;
    printf("Enter limit defining number\n");
    scanf("%d",&lim); // Taking the number of group member limit //
    lim2=lim;
    // Counting exact number of group members (lcount) //
    while(lim2!=1){
        lim2/=10;
        lcount++;
    }
    printf("Enter target number\n"); // Number to make groups from //
    scanf("%f",&num);
    printf("\n");
    caster=(int)num; // Casting the integer part of the float number num //
    while(caster){
        rem=caster%lim;
        caster-=rem;
        caster/=lim;
        if(rem>=pow(10,(lcount-1))){ // Condition to allow numbers that match group member count //
            a[i]=rem;
            i++;
        }
        // Padding 0 in front of the number got from the last division if it doesn't satisfy group member count //
        else{
            tlcount=lcount-1;
            while(tlcount--){
                printf("0");
            }
            printf("%d ",rem);
        }
    }
    // Printing the result groups of non-fractional part//
    while(i--){
        printf("%d ",a[i]);
    }
    tcaster=num-(int)num; // Obtaining the fractional value of float number num //
    // Making the fractional value non-fractional //
    while(tcaster-(int)tcaster){
        tcaster*=10;
        fcount++;
    }
    caster=(int)tcaster; // Casting the value of tcaster into integer type //
    i=0;
    // Loop for achieving group members //
    while(caster){
        rem=caster%lim;
        caster-=rem;
        caster/=lim;
        a[i]=rem;
        i++;
    }
    // Printing the result groups of fractional part //
    while(i--){
        printf("%d ",a[i]);
    }
    return 0;
}

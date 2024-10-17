#include <stdio.h>

int main() {
    int cakes, stus;
    scanf("%d %d", &cakes, &stus);
    if (cakes < stus || (stus==1&&cakes==6)){
        printf("Sad moon festival QQ\n");
        return 0;
    }
    cakes -= stus;
    if(cakes / 8.0 > stus){
        printf("%d\n", stus - 1);
        return 0;
    }else{
        int n = cakes/8, remain = cakes % 8;
        // the only way it can end up 6 is, remain 5 for one guy
        if(n+1 == stus && remain == 5) printf("%d\n", n-1);
        else printf("%d\n", n);
    }
    
}
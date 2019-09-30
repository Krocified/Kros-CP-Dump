#include <stdio.h>
#include <math.h>

int main(){
    int mult;
	double y;
    scanf("%d",&mult); 
    
    for(int i=0; i<mult; i++){
        
        int x=0;
        scanf("%d",&x); 
		
		y = sqrt(double(x));
		
        printf("%d\n",int(y));
        
    }

    getchar();
    return 0;
}

#include <stdio.h>

int main(){
	
	int h=-1;
	int u, d, f;
	
	while(1){
	
		scanf("%d %d %d %d",&h,&u,&d,&f);
		if(h==0)break;
		
		int day = 0;
		float s = 0;
		float up = u;
		float well = h;
		float fatigue = up*f/100;
		
		while(1){
			day++;
			s = s + up;
			if(s>well)break;
			s = s - d;
			if(s<0)break;
			if(up<=0){
				up = 0;
			} else {
				up = up - fatigue;
			}
		}
		
		if (s<=0){
			printf("failure on day %d\n",day);
		} else if (s>well){
			printf("success on day %d\n",day);
		}
		
	}
	
	getchar();
	return 0;
}


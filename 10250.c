#include<stdio.h>
int find(int h, int w, int n){
	int x, y;
	int room;
	if(n%h != 0){
		x = n/h + 1;
		y=n%h;
	}	
	else{
		x = n/h;
		y = h;
	}	
	return room = y*100 + x;
}
int main(){
	int t,h,w,n;
	int i;
	int room;
	scanf("%d",&t);
	for(i=0; i<t; i++){
		scanf("%d%*c%d%*c%d", &h, &w, &n);
		room = find(h,w,n);
		printf("%d\n",room);
	}
	return 0;
}

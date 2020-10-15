#include <stdio.h>
#define n 1000

int husu(int a,int b){
	int temp;
	if(a<b){
		temp=a;
		a=b;
		b=temp;
	}
	for(int i=2;i<=b;i++){
		if((a%i==0)&&(b%i==0))
			break;
	}
	if(i<=b)
		return 0;
	else
		return 1;
}

int fai(int m){
	int a[n]={0},i,j,b=1,faim=m;
	while(1){
 		for(i=2;i<=m;i++){
			if(m%i==0){
				m=m/i;
			    a[b]=i;
				i--;
			    b++;
			}
			if(a[b-1]==a[b-2]) b--;
			if(m==1)break;
		}
		if(m==1||b>=m) break;
	}
	for(j=1;j<b;j++){
		faim=faim-faim/a[j];
	}
    return faim;
}

void main(){
	int a,b,d,m,count=0;
	printf("本程序用来求出一个数的所有原根。请输入一个数字：");
	scanf("%d",&m);
	printf("\n%d的原根有：\n\n",m);
	for(a=2;a<m;a++){
		if(!husu(a,m))continue;
		b=1;
		for(d=1;d<=fai(m);d++){
			b=(b*a)%m;
			if(b==1)break;
		}
		if(d==fai(m)){
	        printf("%3d ",a);
		    count++;
		    if(count%5==0)
			    printf("\n\n");
		}
	}
	if(count==0)printf("                (%d没有原根)\n",m);
	printf("\n\n");
}

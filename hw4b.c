#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
union Data{
	float ff;
	double fd;
	char u_a;
	char u_b;
};
int main(int argc, char *argv[])
{
	union Data udata;
	int i=0,cnt, count_exp32=-1, count_exp64=-1, exp32=0, exp64=0, decimal_exp32, decimal_exp64, count_frac32=0, count_frac64=0, frac32=0, frac64=0,f1;
	double decimal64, fd;
	float decimal32, ff;
	FILE *fp, *ofp;
    char buf[101], a[4][101];
    fp = fopen(argv[1] , "r");//在compiler給argv[1]一個名字例如：file.txt，file.txt就會被讀入
    ofp = fopen("output_b.txt" , "w");//答案會寫進output_a.txt
    while(fgets(buf, sizeof(buf), fp))//每次读取一行数据，直到读取失败。
    {
        for (int j = 0; j < sizeof(buf); ++j)
        {
        	a[i][j] = buf[j];
        }
        i = i+1;
    }

    udata.ff = atof(a[0]);//文件第一行轉為float
    int val0 = *(int *) &udata.ff; //因為float的bit pattern直接就是IEEE754，但只能當f是整數時才可以做bit位移
	for(int i=31;i>=0;i--)
	{
		printf("%d", (val0>>i)&1);
		fprintf(ofp,"%d", (val0>>i)&1);
	}
    printf("\n");
    putc('\n',ofp);

    udata.fd = atof(a[1]);//文件第二行轉為double
    long int val1 = *(long int *) &udata.fd; //因為float的bit pattern直接就是IEEE754，但只能當f是整數時才可以做bit位移
	for(int i=63;i>=0;i--)
	{
		printf("%ld", (val1>>i)&1);
		fprintf(ofp,"%ld", (val1>>i)&1);
	}
    printf("\n");
    putc('\n',ofp);
    
    //文件第三行32bit轉為float
    for (int i = 8; i >= 0; --i)//8位指數bit右移跟1做and，將為1的bit去做二進位轉十進位
    {
    	count_exp32++;
    	if ((a[2][i]&1)==1)
    		{
    			exp32 = exp32 + pow(2,count_exp32);	
    		}
    }
    decimal_exp32 = exp32-127;//再-127算出十進位的指數
    	
    for (int i = 9; i <=31; ++i)//算出小數點的二進位轉十進位
    {
    	count_frac32--;
    	if ((a[2][i]&1)==1)
        {
    	frac32 = frac32 + pow(2,count_frac32);
    	}
    }
    frac32 = frac32 + 1;
    decimal32 = frac32*pow(2,decimal_exp32);
    printf("%0.4f\n", decimal32);
    fprintf(ofp,"%0.4f", decimal32);
    putc('\n',ofp);
    
    //文件第四行64bit轉為double
    for (int i = 11; i >= 0; --i)//11位指數bit右移跟1做and，將為1的bit去做二進位轉十進位
    {
    	count_exp64++;
    	if ((a[3][i]&1)==1)
    		{
    			exp64 = exp64 + pow(2,count_exp64);	
    		}
    }
    decimal_exp64 = exp64-1023;//再-127算出十進位的指數
    	
    for (int i = 12; i <=63; ++i)//算出小數點的二進位轉十進位
    {
    	count_frac64--;
    	if ((a[3][i]&1)==1)
        {
    	frac64 = frac64 + pow(2,count_frac64);
    	}
    }
    frac64 = frac64 + 1;
    decimal64 = frac64*pow(2,decimal_exp64);
    printf("%0.8f\n", decimal64);
    fprintf(ofp,"%0.8f", decimal64);
    putc('\n',ofp);

    fclose(fp);//关闭文件。
    fclose(ofp);//檔案關閉   
	return 0;
}

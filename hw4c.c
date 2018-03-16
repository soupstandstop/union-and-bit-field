#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
union tag_float_union{
     float ff;
     struct tag_bit_field{
              unsigned bit0:1 ;unsigned bit1:1 ;unsigned bit2:1 ;unsigned bit3:1 ;
              unsigned bit4:1 ;unsigned bit5:1 ;unsigned bit6:1 ;unsigned bit7:1 ;
              unsigned bit8:1 ;unsigned bit9:1 ;unsigned bit10:1 ;unsigned bit11:1 ;
              unsigned bit12:1 ;unsigned bit13:1 ;unsigned bit14:1 ;unsigned bit15:1 ;
              unsigned bit16:1 ;unsigned bit17:1 ;unsigned bit18:1 ;unsigned bit19:1 ;
              unsigned bit20:1 ;unsigned bit21:1 ;unsigned bit22:1 ;unsigned bit23:1 ;
              unsigned bit24:1 ;unsigned bit25:1 ;unsigned bit26:1 ;unsigned bit27:1 ;
              unsigned bit28:1 ;unsigned bit29:1 ;unsigned bit30:1 ;unsigned bit31:1 ;
     }bit_field;
    };
union tag_double_union{
     double fd;
     struct tag_bitt_field{
              unsigned bit0:1 ;unsigned bit1:1 ;unsigned bit2:1 ;unsigned bit3:1 ;
              unsigned bit4:1 ;unsigned bit5:1 ;unsigned bit6:1 ;unsigned bit7:1 ;
              unsigned bit8:1 ;unsigned bit9:1 ;unsigned bit10:1 ;unsigned bit11:1 ;
              unsigned bit12:1 ;unsigned bit13:1 ;unsigned bit14:1 ;unsigned bit15:1 ;
              unsigned bit16:1 ;unsigned bit17:1 ;unsigned bit18:1 ;unsigned bit19:1 ;
              unsigned bit20:1 ;unsigned bit21:1 ;unsigned bit22:1 ;unsigned bit23:1 ;
              unsigned bit24:1 ;unsigned bit25:1 ;unsigned bit26:1 ;unsigned bit27:1 ;
              unsigned bit28:1 ;unsigned bit29:1 ;unsigned bit30:1 ;unsigned bit31:1 ;
              unsigned bit32:1 ;unsigned bit33:1 ;unsigned bit34:1 ;unsigned bit35:1 ;
              unsigned bit36:1 ;unsigned bit37:1 ;unsigned bit38:1 ;unsigned bit39:1 ;
              unsigned bit40:1 ;unsigned bit41:1 ;unsigned bit42:1 ;unsigned bit43:1 ;
              unsigned bit44:1 ;unsigned bit45:1 ;unsigned bit46:1 ;unsigned bit47:1 ;
              unsigned bit48:1 ;unsigned bit49:1 ;unsigned bit50:1 ;unsigned bit51:1 ;
              unsigned bit52:1 ;unsigned bit53:1 ;unsigned bit54:1 ;unsigned bit55:1 ;
              unsigned bit56:1 ;unsigned bit57:1 ;unsigned bit58:1 ;unsigned bit59:1 ;
              unsigned bit60:1 ;unsigned bit61:1 ;unsigned bit62:1 ;unsigned bit63:1 ;
     }bitt_field;
    };

int main(int argc, char *argv[])
{
    union tag_float_union float_union;
    union tag_double_union double_union;
    int i=0,cnt, count_exp32=-1, count_exp64=-1, exp32=0, exp64=0, decimal_exp32, decimal_exp64, count_frac32=0, count_frac64=0, frac32=0, frac64=0,f1;
	double decimal64, fd;
	float decimal32, ff;
	FILE *fp, *ofp;
    char buf[101], a[4][101], b[32];
    if(argc > 1)    
        fp = fopen(argv[1] , "r");//在compiler給argv[1]一個名字例如：file.txt，file.txt就會被讀入
    else 
        return 0;
    ofp = fopen("output_c.txt" , "w");//答案會寫進output_a.txt
    
    
    while(fgets(buf, sizeof(buf), fp))//每次读取一行数据，直到读取失败。
    {
        for (int j = 0; j < sizeof(buf); ++j)
        {
        	a[i][j] = buf[j];
        }
        i = i+1;
    }
    

    float_union.ff = atof(a[0]);//文件第一行轉為float
    int val0 = *(int *) &ff; //因為float的bit pattern直接就是IEEE754，但只能當f是整數時才可以做bit位移
    
    fprintf(ofp,"%u%u%u%u%u%u%u%u%u%u%u%u%u%u%u%u%u%u%u%u%u%u%u%u%u%u%u%u%u%u%u%u",
            float_union.bit_field.bit31,
            float_union.bit_field.bit30,
            float_union.bit_field.bit29,
            float_union.bit_field.bit28,
            float_union.bit_field.bit27,
            float_union.bit_field.bit26,
            float_union.bit_field.bit25,
            float_union.bit_field.bit24,
            float_union.bit_field.bit23,
            float_union.bit_field.bit22,
            float_union.bit_field.bit21,
            float_union.bit_field.bit20,
            float_union.bit_field.bit19,
            float_union.bit_field.bit18,
            float_union.bit_field.bit17,
            float_union.bit_field.bit16,
            float_union.bit_field.bit15,
            float_union.bit_field.bit14,
            float_union.bit_field.bit13,
            float_union.bit_field.bit12,
            float_union.bit_field.bit11,
            float_union.bit_field.bit10,
            float_union.bit_field.bit9,
            float_union.bit_field.bit8,
            float_union.bit_field.bit7,
            float_union.bit_field.bit6,
            float_union.bit_field.bit5,
            float_union.bit_field.bit4,
            float_union.bit_field.bit3,
            float_union.bit_field.bit2,
            float_union.bit_field.bit1,
            float_union.bit_field.bit0
            );
    
    putc('\n',ofp);

    double_union.fd = atof(a[1]);//文件第二行轉為double
    long int val1 = *(long int *) &fd; //因為float的bit pattern直接就是IEEE754，但只能當f是整數時才可以做bit位移
	fprintf(ofp,"%u%u%u%u%u%u%u%u%u%u%u%u%u%u%u%u%u%u%u%u%u%u%u%u%u%u%u%u%u%u%u%u%u%u%u%u%u%u%u%u%u%u%u%u%u%u%u%u%u%u%u%u%u%u%u%u%u%u%u%u%u%u%u%u",
            double_union.bitt_field.bit63,
            double_union.bitt_field.bit62,
            double_union.bitt_field.bit61,
            double_union.bitt_field.bit60,
            double_union.bitt_field.bit59,
            double_union.bitt_field.bit58,
            double_union.bitt_field.bit57,
            double_union.bitt_field.bit56,
            double_union.bitt_field.bit55,
            double_union.bitt_field.bit54,
            double_union.bitt_field.bit53,
            double_union.bitt_field.bit52,
            double_union.bitt_field.bit51,
            double_union.bitt_field.bit50,
            double_union.bitt_field.bit49,
            double_union.bitt_field.bit48,
            double_union.bitt_field.bit47,
            double_union.bitt_field.bit46,
            double_union.bitt_field.bit45,
            double_union.bitt_field.bit44,
            double_union.bitt_field.bit43,
            double_union.bitt_field.bit42,
            double_union.bitt_field.bit41,
            double_union.bitt_field.bit40,
            double_union.bitt_field.bit39,
            double_union.bitt_field.bit38,
            double_union.bitt_field.bit37,
            double_union.bitt_field.bit36,
            double_union.bitt_field.bit35,
            double_union.bitt_field.bit34,
            double_union.bitt_field.bit33,
            double_union.bitt_field.bit32,
            double_union.bitt_field.bit31,
            double_union.bitt_field.bit30,
            double_union.bitt_field.bit29,
            double_union.bitt_field.bit28,
            double_union.bitt_field.bit27,
            double_union.bitt_field.bit26,
            double_union.bitt_field.bit25,
            double_union.bitt_field.bit24,
            double_union.bitt_field.bit23,
            double_union.bitt_field.bit22,
            double_union.bitt_field.bit21,
            double_union.bitt_field.bit20,
            double_union.bitt_field.bit19,
            double_union.bitt_field.bit18,
            double_union.bitt_field.bit17,
            double_union.bitt_field.bit16,
            double_union.bitt_field.bit15,
            double_union.bitt_field.bit14,
            double_union.bitt_field.bit13,
            double_union.bitt_field.bit12,
            double_union.bitt_field.bit11,
            double_union.bitt_field.bit10,
            double_union.bitt_field.bit9,
            double_union.bitt_field.bit8,
            double_union.bitt_field.bit7,
            double_union.bitt_field.bit6,
            double_union.bitt_field.bit5,
            double_union.bitt_field.bit4,
            double_union.bitt_field.bit3,
            double_union.bitt_field.bit2,
            double_union.bitt_field.bit1,
            double_union.bitt_field.bit0
            );
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

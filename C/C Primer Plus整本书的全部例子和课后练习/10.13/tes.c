//
//#include <stdio.h>  
//  
//int compare(int ar[], int len) ;  
//  
//int main (void)  
//{  
//    int i_arry[5] = {5, 18, 4, 28, 23} ;  
//    int back ;
//	int i;
//  
//    back = compare(i_arry,5) ;  
//    printf("数组的最大值为:%d\n",back) ;
//    return 0 ;  
//}  
//  
//int compare(int ar[], int len)  //比较大小函数  
//{  
//    int i , t ;  
//  
//    for (i=0;i<len-1;++i)  
//    {  
//        if ( ar[i] > ar[i + 1] )  
//        {  
//           t = ar[i] ;  
//           ar[i] = ar[i + 1] ;  
//           ar[i + 1] = t ;  
//        }  
//    }  
//  
//    return ar[4] ;  
//}  
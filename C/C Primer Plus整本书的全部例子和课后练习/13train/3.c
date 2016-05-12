//#include<stdio.h>
//#include<stdlib.h>//exit
//
//int main()
//{
//	FILE * fp1,* fp2;
//	char ch;
//
//	if((fp1 = fopen("terky","r")) == NULL)
//	{
//		fprintf(stderr,"Error opening input file.\n");
//		exit(EXIT_FAILURE);
//	}
//	if((fp2 = fopen("jerky","w")) == NULL)
//	{
//		fprintf(stderr,"Error opening output file");
//	}
//	while((ch = getc(fp1)) != EOF && ch != '\0')
//	{
//		fprintf(fp2,"%c",ch);
//		//putc(ch,fp2);
//
//	}
//	if(ferror(fp1) != 0)
//	{
//		fprintf(stderr,"Error in reading file.\n");
//	}
//	if(ferror(fp2) != 0)
//	{
//		fprintf(stderr,"Error in writing file.\n");
//	}
//	fclose(fp1);
//	fclose(fp2);
//	return 0;
//}
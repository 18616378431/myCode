////�޸�13.3����1��ʼΪÿ������ĵ��ʱ�ţ������ٴ�����ʱ������֮ǰ�ı��
//#include<stdio.h>
//#include<stdlib.h>
//#include<string.h>//strlen()
//#define MAX 41
//
//int main()
//{
//	FILE * fp;
//	char words[MAX];
//	int number = 0;//���ʱ��
//	char ch;
//
//	if((fp = fopen("words","a+")) == NULL)
//	{
//		fprintf(stderr,"Can't open file \"words\".\n");
//		exit(EXIT_FAILURE);
//	}
//	//���ݻ��з�����ȷ�����ʱ��
//	while((ch = getc(fp)) != EOF)
//	{
//		if(ch == '\n')
//		{
//			number++;
//		}
//	}
//	puts("Enter words to add to the file(any single character to quit).");
//	while(fscanf(stdin,"%s",words) == 1 && strlen(words) > 2)
//	{
//		printf("%d.\n",strlen(words));
//		fprintf(fp,"%d.%s\n",number++,words);//��words����д��fpָ����ļ���
//	}
//	puts("File contents:");
//	rewind(fp);//���ļ�ָ��ָ����ļ���ʼ��
//	while(fscanf(fp,"%s",words) == 1)//���ж�ȡ�ļ����ݣ�fscanf()��ȡһ����Ŀ�ɹ�����1�����򷵻�0,�洢��words��
//	{
//		fprintf(stdout,"%s\n",words);
//	}
//	if(fclose(fp) != 0)
//	{
//		fprintf(stderr,"Error closing file.\n");
//	}
//	return 0;
//}
//���������
//�ޱ�׼������������������׼�������ͷ�ļ�

static unsigned long int next = 1;//�ļ������򡢾�̬�洢ʱ�ڡ��ڲ�����
int rand0(void)
{
	//����α�������ʽ
	next = next * 1103515245 + 12345;
	return (unsigned int)(next/65536)%32768;
}

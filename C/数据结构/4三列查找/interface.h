//�ӿ��ļ�
//���ڿ��Ŷ�ַ�������ͻ������ɢ�б�ʵ�ֲ���
//��������ϵͳ���ҹ���ʵ��

#ifndef INTERFACE_H_
#define INTERFACE_H_

#define BOOL int
#define true 1
#define false 0

#define TRADE_NAME_SIZE 20//����Ʒ�����Ƴ���
#define KEY_SIZE 7//���������Ĺؼ��ֳ���
#define HASH_MAX_SIZE 15//Hash�б��С
#define MOD 12//��������ϵ��

//Ԫ�����Ͷ���
typedef struct item{
	int carId;//���ƺ�
	char tradeMark[TRADE_NAME_SIZE];//����Ʒ��
	BOOL flag;//�����Ƿ�������,Ĭ��Ϊfalse
}Item;
//���ҹؼ������Ͷ���
typedef char key[KEY_SIZE];
//����˳����ɢ�в��ұ�
typedef Item HashList[HASH_MAX_SIZE];


/*
����:��ʼ��HASHLIST����Hash���ÿ�
����ǰ:hlΪָ��HashList�ṹ�����ָ��
������:HashList��ȫ��Ϊ��
*/
void InitHashList(HashList hl);

/*
����:������Ա�
����ǰ:hlΪָ���ѳ�ʼ����HashList�ṹ�����ָ��
������:��Hash���Ա����
*/
void ClearHashList(HashList hl);

/*
����:��Hash���в���Ԫ��
����ǰ:hlָ���ѳ�ʼ����HashList�ṹ���飬itemΪ������Ԫ��
������:��Ԫ�ز���Hash���ɹ�����true��ʧ�ܻ��������false
*/
BOOL InsertItemIntoHashList(HashList hl,Item item);

/*
����:��Hash���в���Ԫ��
����ǰ:hlָ���ѳ�ʼ����Hash�ṹ���飬itemΪ������Ԫ��
������:���ҳɹ�������Ԫ��λ�ã����򷵻�-1
*/
int LocateItemFromHashList(HashList hl,Item item);

/*
����:��Hash����ɾ��ָ��Ԫ��
����ǰ:hlָ���ѳ�ʼ����HashList��itemΪ��ɾ��Ԫ��
������:ɾ���ɹ�������true�����򷵻�false
*/
BOOL DeleteItemFromHashList(HashList hl,Item item);

/*
����:����������ȡHashֵ
����ǰ:���ݳ��ƺ�carId
������:���ظ�����ӦMOD�õ���ֵ
*/
int HashDiv(int carId);
#endif
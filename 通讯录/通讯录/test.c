#define _CRT_SECURE_NO_WARNINGS 1
#include"contact.h"
int main()
{
	ContactBook cb;
	char name[24];
	ContactBookInit(&cb);// ��ʼ��
	

	// ��ӵ�һ����ϵ��
	Contact con1;
	strcpy(con1._name, "С��");
	strcpy(con1._address, "������");
	strcpy(con1._tel, "12589648763");
	con1._age = 18;
	ContactBookAppend(&cb, &con1);// ���

	// ��ӵڶ�����ϵ��
	Contact con2;
	strcpy(con2._name, "С��");
	strcpy(con2._address, "μ����");
	strcpy(con2._tel, "13589648763");
	con2._age = 19;
	ContactBookAppend(&cb, &con2);// ���

	// ��ӵ�������ϵ��
	Contact con3;
	strcpy(con3._name, "С��");
	strcpy(con3._address, "������");
	strcpy(con3._tel, "13589648763");
	con3._age = 20;
	ContactBookAppend(&cb, &con3);// ���

	ContactBookSave(&cb, "contactbookbin.txt");// ����

	ContactBookLoad(&cb, "contactbookbin.txt");// ���أ����ļ����������

	ContactBookDelete(&cb, name);// ɾ��

	ContactBookFind(&cb, name);// ����

	ContactBookDestory(&cb);// ����

	system("pause");
	return 0;
}
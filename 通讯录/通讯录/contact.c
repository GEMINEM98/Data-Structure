#define _CRT_SECURE_NO_WARNINGS 1
#include"contact.h"

void ContactBookInit(ContactBook* pbook) // ��ʼ��
{
	assert(pbook);
	pbook->_con_array = (Contact*)malloc(sizeof(Contact) * 8);// ��mallocʱ������ȼ��ָ���Ƿ�Ϊ��
	if (pbook->_con_array == NULL)
	{
		printf("malloc error!\n");
		exit(-1);
	}
	pbook->_size = 0;
	pbook->_capacity = 8;
}

void ContactBookDestory(ContactBook* pbook) // ����
{
	assert(pbook);
	free(pbook->_con_array);
	pbook->_con_array = NULL;
	pbook->_size = 0;
	pbook->_capacity = 0;
}

void ContactBookAppend(ContactBook* pbook, Contact* pcon)// �����ϵ��
{
	assert(pbook&&pcon);
	if (pbook->_size == pbook->_capacity)// ��������
	{
		pbook->_capacity *= 2;//�������������
		Contact* newarray = realloc(pbook->_con_array, sizeof(Contact)*pbook->_capacity);// ��̬���������ռ�
		if (newarray == NULL) //    Ҫ�������ڴ��ַ             ������Ĵ�С
		{
			printf("realloc error!\n");
			exit(-1);
		}
		pbook->_con_array = newarray;
	}
	Contact* array = pbook->_con_array;
	size_t i = pbook->_size;
	strcpy(array[i]._name, pcon->_name);
	strcpy(array[i]._address, pcon->_address);
	strcpy(array[i]._tel, pcon->_tel);
	array[i]._age = pcon->_age;
	pbook->_size++;
}

void ContactBookSave(ContactBook* pbook, const char* file)// ����
{
	FILE* fp = fopen(file, "wb");
	if (fp == NULL)
	{
		printf("���ļ�ʧ�ܣ�\n");
		exit(-1);
	}

	Contact* array = pbook->_con_array;
	for (size_t i = 0; i < pbook->_size; ++i)
	{
		fwrite(&array[i], sizeof(Contact), 1, fp);
		//     �ṹ��ָ��
	}
	fclose(fp);
}

void ContactBookLoad(ContactBook* pbook, const char* file)// ���أ����ļ��ж�����
{
	FILE* fp = fopen(file, "rb");
	if (fp == NULL)
	{
		printf("���ļ�ʧ�ܣ�\n");
		exit(-1);
	}

	Contact con;
	while (fread(&con, sizeof(Contact), 1, fp) == 1)
	{
		ContactBookAppend(pbook, &con);
	}
	fclose(fp);
}

void ContactBookDelete(ContactBook* pbook, const char* name)// ɾ��
{
	assert(pbook);
	size_t i = 0;
	printf("����������Ҫɾ������ϵ��������");
	scanf("%s", name);
	if (pbook->_size == 0)
	{
		printf("ͨѶ¼Ϊ�գ�ɾ��ʧ�ܣ�\n");
		return;
	}
	else
	{
		for (i = 0; i < pbook->_size; ++i)
		{
			if (!strcmp(pbook->_con_array[i]._name, name))
			{
				pbook->_capacity = pbook->_capacity + 1;
				pbook->_size--;
				printf("ɾ���ɹ���\n");
				return;
			}
		}
		if (i == pbook->_size)
		{
			printf("����ϵ�˲����ڣ�\n");
			return;
		}

	}
}

void ContactBookFind(ContactBook* pbook, const char* name)// ����
{
	assert(pbook);
	size_t i = 0;
	printf("����������Ҫ���ҵ���ϵ��������");
	scanf("%s", name);
	if (pbook->_size == 0)
	{
		printf("ͨѶ¼Ϊ�գ�����ʧ�ܣ�\n");
		return NULL;
	}
	else
	{
		for (i = 0; i < pbook->_size; ++i)
		{
			if (!strcmp(pbook->_con_array[i]._name, name))
			{
				printf("������%s\n", pbook->_con_array[i]._name);
				printf("�绰��%s\n", pbook->_con_array[i]._tel);
				printf("��ַ��%s\n", pbook->_con_array[i]._address);
				printf("���䣺%d\n", pbook->_con_array[i]._age);
				return;
			}
		}
		if (i == pbook->_size)
		{
			printf("����ϵ�˲����ڣ�\n");
			return;
		}
	}
}

void ContactPrint(ContactBook* pbook)// ��ӡͨѶ¼
{
	for (size_t i = 0; i < pbook->_size; ++i)
	{
		printf("===============================\n");

		printf("������%s\n", pbook->_con_array[i]._name);
		printf("�绰��%s\n", pbook->_con_array[i]._tel);
		printf("��ַ��%s\n", pbook->_con_array[i]._address);
		printf("���䣺%d\n", pbook->_con_array[i]._age);

	    printf("===============================\n");
	}
}

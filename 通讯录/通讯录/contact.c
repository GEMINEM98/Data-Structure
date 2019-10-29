#define _CRT_SECURE_NO_WARNINGS 1
#include"contact.h"

void ContactBookInit(ContactBook* pbook) // 初始化
{
	assert(pbook);
	pbook->_con_array = (Contact*)malloc(sizeof(Contact) * 8);// 用malloc时，最好先检查指针是否为空
	if (pbook->_con_array == NULL)
	{
		printf("malloc error!\n");
		exit(-1);
	}
	pbook->_size = 0;
	pbook->_capacity = 8;
}

void ContactBookDestory(ContactBook* pbook) // 销毁
{
	assert(pbook);
	free(pbook->_con_array);
	pbook->_con_array = NULL;
	pbook->_size = 0;
	pbook->_capacity = 0;
}

void ContactBookAppend(ContactBook* pbook, Contact* pcon)// 添加联系人
{
	assert(pbook&&pcon);
	if (pbook->_size == pbook->_capacity)// 容量满了
	{
		pbook->_capacity *= 2;//申请二倍的容量
		Contact* newarray = realloc(pbook->_con_array, sizeof(Contact)*pbook->_capacity);// 动态申请连续空间
		if (newarray == NULL) //    要调整的内存地址             调整后的大小
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

void ContactBookSave(ContactBook* pbook, const char* file)// 保存
{
	FILE* fp = fopen(file, "wb");
	if (fp == NULL)
	{
		printf("打开文件失败！\n");
		exit(-1);
	}

	Contact* array = pbook->_con_array;
	for (size_t i = 0; i < pbook->_size; ++i)
	{
		fwrite(&array[i], sizeof(Contact), 1, fp);
		//     结构体指针
	}
	fclose(fp);
}

void ContactBookLoad(ContactBook* pbook, const char* file)// 加载，从文件中读出来
{
	FILE* fp = fopen(file, "rb");
	if (fp == NULL)
	{
		printf("打开文件失败！\n");
		exit(-1);
	}

	Contact con;
	while (fread(&con, sizeof(Contact), 1, fp) == 1)
	{
		ContactBookAppend(pbook, &con);
	}
	fclose(fp);
}

void ContactBookDelete(ContactBook* pbook, const char* name)// 删除
{
	assert(pbook);
	size_t i = 0;
	printf("请输入你想要删除的联系人姓名：");
	scanf("%s", name);
	if (pbook->_size == 0)
	{
		printf("通讯录为空，删除失败！\n");
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
				printf("删除成功！\n");
				return;
			}
		}
		if (i == pbook->_size)
		{
			printf("该联系人不存在！\n");
			return;
		}

	}
}

void ContactBookFind(ContactBook* pbook, const char* name)// 查找
{
	assert(pbook);
	size_t i = 0;
	printf("请输入你想要查找的联系人姓名：");
	scanf("%s", name);
	if (pbook->_size == 0)
	{
		printf("通讯录为空，查找失败！\n");
		return NULL;
	}
	else
	{
		for (i = 0; i < pbook->_size; ++i)
		{
			if (!strcmp(pbook->_con_array[i]._name, name))
			{
				printf("姓名：%s\n", pbook->_con_array[i]._name);
				printf("电话：%s\n", pbook->_con_array[i]._tel);
				printf("地址：%s\n", pbook->_con_array[i]._address);
				printf("年龄：%d\n", pbook->_con_array[i]._age);
				return;
			}
		}
		if (i == pbook->_size)
		{
			printf("该联系人不存在！\n");
			return;
		}
	}
}

void ContactPrint(ContactBook* pbook)// 打印通讯录
{
	for (size_t i = 0; i < pbook->_size; ++i)
	{
		printf("===============================\n");

		printf("姓名：%s\n", pbook->_con_array[i]._name);
		printf("电话：%s\n", pbook->_con_array[i]._tel);
		printf("地址：%s\n", pbook->_con_array[i]._address);
		printf("年龄：%d\n", pbook->_con_array[i]._age);

	    printf("===============================\n");
	}
}

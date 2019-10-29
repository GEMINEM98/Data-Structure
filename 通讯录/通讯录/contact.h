#pragma once

#include<stdio.h>
#include<assert.h>
#include<stdlib.h>
#include<string.h>

typedef struct Contact // 个人通讯
{
	char _name[24];
	char _tel[16];
	char _address[64];
	int _age;
}Contact;

typedef struct ContactBook // 通讯录
{
	Contact* _con_array;//每个联系人信息
	size_t _size;// 联系人个数
	size_t _capacity;// 容量
}ContactBook;

void ContactBookInit(ContactBook* pbook);// 初始化
void ContactBookDestory(ContactBook* pbook);// 销毁
void ContactBookAppend(ContactBook* pbook, Contact* pcon);// 添加
void ContactBookDelete(ContactBook* pbook, const char* name);// 删除
void ContactBookFind(ContactBook* pbook,const char* name);// 查找
void ContactBookSave(ContactBook* pbook, const char* file);// 保存
void ContactBookLoad(ContactBook* pbook, const char* file);// 加载，从文件中读出来
void ContactPrint(ContactBook* pbook);// 打印通讯录
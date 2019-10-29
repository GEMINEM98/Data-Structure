#pragma once

#include<stdio.h>
#include<assert.h>
#include<stdlib.h>
#include<string.h>

typedef struct Contact // ����ͨѶ
{
	char _name[24];
	char _tel[16];
	char _address[64];
	int _age;
}Contact;

typedef struct ContactBook // ͨѶ¼
{
	Contact* _con_array;//ÿ����ϵ����Ϣ
	size_t _size;// ��ϵ�˸���
	size_t _capacity;// ����
}ContactBook;

void ContactBookInit(ContactBook* pbook);// ��ʼ��
void ContactBookDestory(ContactBook* pbook);// ����
void ContactBookAppend(ContactBook* pbook, Contact* pcon);// ���
void ContactBookDelete(ContactBook* pbook, const char* name);// ɾ��
void ContactBookFind(ContactBook* pbook,const char* name);// ����
void ContactBookSave(ContactBook* pbook, const char* file);// ����
void ContactBookLoad(ContactBook* pbook, const char* file);// ���أ����ļ��ж�����
void ContactPrint(ContactBook* pbook);// ��ӡͨѶ¼
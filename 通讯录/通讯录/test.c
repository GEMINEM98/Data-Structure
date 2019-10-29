#define _CRT_SECURE_NO_WARNINGS 1
#include"contact.h"
int main()
{
	ContactBook cb;
	char name[24];
	ContactBookInit(&cb);// 初始化
	

	// 添加第一个联系人
	Contact con1;
	strcpy(con1._name, "小红");
	strcpy(con1._address, "西安市");
	strcpy(con1._tel, "12589648763");
	con1._age = 18;
	ContactBookAppend(&cb, &con1);// 添加

	// 添加第二个联系人
	Contact con2;
	strcpy(con2._name, "小绿");
	strcpy(con2._address, "渭南市");
	strcpy(con2._tel, "13589648763");
	con2._age = 19;
	ContactBookAppend(&cb, &con2);// 添加

	// 添加第三个联系人
	Contact con3;
	strcpy(con3._name, "小蓝");
	strcpy(con3._address, "安康市");
	strcpy(con3._tel, "13589648763");
	con3._age = 20;
	ContactBookAppend(&cb, &con3);// 添加

	ContactBookSave(&cb, "contactbookbin.txt");// 保存

	ContactBookLoad(&cb, "contactbookbin.txt");// 加载，从文件夹里读出来

	ContactBookDelete(&cb, name);// 删除

	ContactBookFind(&cb, name);// 查找

	ContactBookDestory(&cb);// 销毁

	system("pause");
	return 0;
}
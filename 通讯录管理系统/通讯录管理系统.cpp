// 封装函数显示该界面 如 void showMenu()
// 在main函数中调用封装好的函数
#include<iostream>
#include<string>
using namespace std;
#define MAX 1000
//菜单界面

void showMenu() {
	
	cout << "***************************" << endl;
	cout << "*****  1、添加联系人  *****" << endl;
	cout << "*****  2。显示联系人  *****" << endl;
	cout << "*****  3、删除联系人  *****" << endl;
	cout << "*****  4、查找联系人  *****" << endl;
	cout << "*****  5、修改联系人  *****" << endl;
	cout << "*****  6、清空联系人  *****" << endl;
	cout << "*****  0、退出通讯录  *****" << endl;
	cout << "***************************" << endl;

}

//联系人结构体
struct Person
{
	//姓名
	string m_Name;
	//性别
	int m_Gender;
	//年龄
	int m_Age;
	//电话
	string m_Phone;
	//地址
	string m_Addr; 
};

//通讯录结构体
struct Addressbooks
{
	//通讯录中保存的联系人数组
	struct Person PersonArray[MAX];	
	//通讯录中当前记录联系人个数
	int m_Size;
};

//1、添加联系人
void addPerson(Addressbooks *  abs) {
	//判断通讯录是否已满，若已满就不再添加
	if (abs->m_Size == MAX) {
		cout << "通讯录已满，无法添加！" << endl;
		return;
	}
	else {
		//添加具体联系人

		//姓名
		string name;
		cout << "请输入姓名" << endl;
		cin >> name;
		abs->PersonArray[abs->m_Size].m_Name = name;
		
		//性别
		int Gender;
		cout << "请输入性别" << endl;
		cout << "1——男" << endl;
		cout << "2——女" << endl;
		int gender = 0;
		while (true)
		{
			//如果输入的是1或2可以退出，如果输入有误，则重新输入
			cin >> gender;
			if (gender == 1 || gender == 2) {
				abs->PersonArray[abs->m_Size].m_Gender = gender;
				break;
			}
			cout << "输入有误，请重新输入" << endl;
		}
		
		//年龄
		cout << "请输入年龄" << endl;
		int age = 0;
		cin >> age;
		abs->PersonArray[abs->m_Size].m_Age = age;

		//电话
		cout << "请输入联系电话" << endl;
		string phone;
		cin >> phone;
		abs->PersonArray[abs->m_Size].m_Phone = phone;
		//住址
		cout << "请输入住址" << endl;
		string address;
		cin >> address;
		abs->PersonArray[abs->m_Size].m_Addr = address;

		//更新通讯录人数 
		abs->m_Size++;
		cout << "添加成功" << endl;

		system("pause");//请按任意键继续
		system("cls");//清屏操作
	}
}

//2、显示联系人
void showPerson(Addressbooks * abs) {
	//判断通讯录中人数是否为0，如果为0，提示记录为空
	//如果不为0，显示记录的联系人信息
	if (abs->m_Size == 0) {
		cout << "当前记录为空" << endl;
	}
	else {
		for (int i = 0; i < abs->m_Size; i++) {
			cout << "姓名：" << abs->PersonArray[i].m_Name << "\t";
			cout << "性别：" << (abs->PersonArray[i].m_Gender == 1 ?"男":"女") << "\t";
			cout << "年龄：" << abs->PersonArray[i].m_Age << "\t";
			cout << "电话：" << abs->PersonArray[i].m_Phone << "\t";
			cout << "地址：" << abs->PersonArray[i].m_Addr << endl;
		} 
	}
	system("pause");//请按任意键继续
	system("cls");//清屏操作
}

//检测联系人是否存在，若存在返回联系人所在数组的具体位置，不存在，则返回-1
//参数1 通讯录 参数2 对比姓名
int isExist(Addressbooks * abs , string name) {
	for (int i = 0; i < abs->m_Size; i++) {
		//找到用户输入的姓名
		if (abs->PersonArray[i].m_Name == name) {
			return i;//找到后返回这个人在数组中的下标编号
		}
	}
	return -1;//如果遍历结束都没有找到，返回-1
}

//3、删除联系人
void deletePerson(Addressbooks * abs) {
	cout << "请输入要删除的联系人" << endl;
	string name;
	cin >> name;
	isExist(abs, name);
	
	//ret == -1 查不到此人
	//ret != -1 查到此人
	int ret = isExist(abs, name);

	if (ret != -1) {
		//查到此人，进行删除操作
		for (int i = ret; i < abs->m_Size; i++) {
			//数据迁移
			abs->PersonArray[i] = abs->PersonArray[i + 1];
		}
		abs->m_Size--;//更新通讯录中的人员数
		cout << "删除成功" << endl;
	}
	else {
		cout << "查无此人" << endl;
	}
	system("pause");//请按任意键继续
	system("cls");//清屏操作
}

//4、查找指定联系人信息
void findPerson(Addressbooks * abs)
{
	cout << "请输入您要查找的联系人" << endl;
	string name;
	cin >> name;

	int ret = isExist(abs, name);
	if (ret != -1)
	{
		cout << "姓名：" << abs->PersonArray[ret].m_Name << "\t";
		cout << "性别：" << (abs->PersonArray[ret].m_Gender ==1 ?"男":"女") << "\t";
		cout << "年龄：" << abs->PersonArray[ret].m_Age << "\t";
		cout << "电话：" << abs->PersonArray[ret].m_Phone << "\t";
		cout << "住址：" << abs->PersonArray[ret].m_Addr << endl;
	}
	else
	{
		cout << "查无此人" << endl;
	}

	system("pause");
	system("cls");

}

//修改联系人
void modifyPerson(Addressbooks* abs) {
	cout << "输入要修改的联系人" << endl;
	string name;
	cin >> name;

	int ret = isExist(abs, name);

	if (ret != -1) {//找到联系人

		//姓名
		string name;
		cout << "输入姓名：" << endl;
		cin >> name;
		abs->PersonArray[ret].m_Name = name;
		//性别
		cout << "输入性别：" << endl;
		cout << "1——男" << endl;
		cout << "2——女" << endl;
		int gender = 0;
		
		while(true){
			cin >> gender;
			if (gender == 1 || gender == 2) {
				//输入正确，退出循环输入
				abs->PersonArray[ret].m_Gender = gender;
				break;
			}
			cout << "输入有误，请重新输入" << endl;
		}
		
		//年龄
		cout << "输入年龄：" << endl;
		int age = 0;
		cin >> age;
		abs->PersonArray[ret].m_Age = age;
		//电话
		cout << "输入电话：" << endl;
		string phone;
		cin >> phone;
		abs->PersonArray[ret].m_Phone = phone;
		//地址
		cout << "输入地址：" << endl;
		string address;
		cin >> address;
		abs->PersonArray[ret].m_Addr = address;

		cout << "修改成功" << endl;

	}
	else {
		//未找到联系人
		cout << "查无此人" << endl;
	}
	system("pause");
	system("cls");
}

//清空联系人
void cleanPerson(Addressbooks* abs) {
	abs->m_Size = 0;//将当前记录联系人数量重置为0，坐逻辑清空操作
	cout << "通讯录已清空" << endl;
	system("pause");
	system("cls");
}

int main() {

	//创建通讯录结构体变量
	Addressbooks abs;
	abs.m_Size = 0;

	int select = 0;

	while (true) {
		
		//菜单调用
		showMenu();

		cin >> select;

		switch (select)
		{
		case 1://添加联系人
			addPerson(&abs);
			break;
		case 2://显示联系
			showPerson(&abs);
			break;
		case 3://删除联系人
		/*{
			cout << "请输入删除联系人的姓名" << endl;
			string name;
			cin >> name;
			if (isExist(&abs, name) == -1) {
				cout << "查无此人" << endl;
			}
			else { 
				cout << "找到此人" << endl;
			}
		}*/
			deletePerson(&abs);
			break;
		case 4://查找联系人
			findPerson(&abs);
			break;
		case 5://修改联系人
			modifyPerson(&abs);
			break;
		case 6://清空联系人
			cleanPerson(&abs); 
			break;
		case 0://退出通信录
			cout << "欢迎下次使用" << endl;
			system("pause");
			return 0;
			break;
		default:
			break;
		}
	}
	

	system("pause");
	return 0; 
}
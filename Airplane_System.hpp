//
//  Airplane_System.hpp
//  Iplane
//
//  Created by 杨溢 管清泉 陆子旭 on 2017/12/22.
//  Copyright © 2017年 杨溢 管清泉 陆子旭. All rights reserved.
//

#ifndef Airplane_System_hpp
#define Airplane_System_hpp

#include "stdafx.h"
#include <string>
#include <stdio.h>
#include <fstream>
#include <stdlib.h>
#include <iostream>
#include <sstream>
#include <vector>
using namespace std;

//定义一个航班信息的类
class flight
{
public:
	string flight_number;        //航班号
	string starting_point;   //起始城市
	string finishing_point;   //到达城市
	int strat_time;              //起飞时间
	int finish_time;            //到达时间
	int price;                      //飞机票价
	int discount;               //票价折扣
	string company;           //所属公司
	int seat_number;          //座位总数
	int book_number;        //已预定总数
};

//定义一个飞机订票系统的类
class Airplane_System
{
public:
	void dataloading();										  //航班信息录入
	void current_information_view();					  //航班信息浏览
	void check_information();							      //航班信息查询
	void ticket_booking();									  //预订机票
	void ticket_returning(string flight_num);	//退票(航班号)
	void flight_list();											  //相应航班排序
	void flight_recommended();						      //航班线路设计
	void output_route();									      //航班网络输出
	void best_route_recommended();			      //最优航班线路推荐
private:
    //边链表
	struct edge
	{
		int takeoff_point;                                      //起飞城市
		edge* nextpoint;                                          //到达城市
		flight* flight_node;                                     //航班信息节点
	};
    //定点数组
	struct point
	{
		int takeoffpoint;                                         //起飞城市
		string cityname;                                         //城市名称
		edge* address;                                          //边链表的头指针
	};
    int number_of_city;                                            //开放航线的城市个数
    int total;                                                            //航班总数
    string number1[300];                                        //过渡string数组，无重要作用，可忽略
	flight* flight_totalnumber;                         //动态flight类数组的数组名（指针）
	bool time_compare(int, int);                         //时间比较（是否可以并入航线）,第一个参数是航班的落地时间，第二个参数是航班的起飞时间
	bool place_compare(string, string);                //地点比较，比较两个地点是否为同一地点
};


//信息录入  从文件录入到程序    by管清泉
void Airplane_System::dataloading()
{
	ifstream file;
	file.open("C:/Users/97263/Desktop/Airplace_System/file.txt");
	if (file.is_open() == false)
	{
		cerr << "error";
		exit(1);
	}
	string number;
	getline(file, number);
	total = stoi(number);                                                       //取出一共有几个航班			
	flight_totalnumber = new flight[total];
	for (int i = 0; i <total; i++)
	{
		getline(file, number1[i]);
		istringstream istr;
		istr.str(number1[i]);
		istr >> flight_totalnumber[i].starting_point;
		istr >> flight_totalnumber[i].finishing_point;
		istr >> flight_totalnumber[i].company;
		istr >> flight_totalnumber[i].flight_number;
		istr >> flight_totalnumber[i].strat_time;
		istr >> flight_totalnumber[i].finish_time;
		istr >> flight_totalnumber[i].price;
		istr >> flight_totalnumber[i].discount;
		istr >> flight_totalnumber[i].seat_number;
		istr >> flight_totalnumber[i].book_number;
	}
	file.close();
}

void Airplane_System::current_information_view()
{
	for (int i = 0; i < total; i++)
		cout << number1[i] << endl;
}

void Airplane_System::flight_recommended()
{
	string where_to_start;
	string where_to_go;
	int time_to_go;
	int time_to_arrive;
	cout << "请输入出发地:" << endl;
	cin >> where_to_start;
	cout << "请输入目的地" << endl;
	cin >> where_to_go;

}

//退票 by 陆子旭
void ticket_returning(string flight_num){
    for (int i = 0; i <total; i++) {
        if (flight_totalnumber[i].flight_number == flight_num) {
            if (flight_totalnumber[i].book_number > 0) {
                flight_totalnumber[i].book_number --;
            }
            break;
        }
    }
}

//相应航班排序 by 陆子旭
void flight_list(){
    
}
#endif /* Airplane_System_hpp */

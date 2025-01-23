//
// Created by kongwenshuo on 25-1-18.
//
#include<iostream>
#include "MyTest.h"
#include "person.pb.h"
//using namespace Aoqi;
//using namespace Xiaoaoqi;
void MyTest::test() {
    //序列化
    Xiaoaoqi::Person p;
    p.set_id(10);
    p.set_age(32);
    p.set_sex("man");
    p.set_name("aoqi");
    p.mutable_addr()->set_m_addr("奥奇大陆");
    p.mutable_addr()->set_num(1001);
    p.set_aaa(100);
    p.set_color(Xiaoaoqi::Color::Blue);

    p.add_name2();
    p.set_name2(0,"奥奇");
    p.add_name2("111");
    p.add_name2("222");
    //序列化对象p,最终得到一个字符串
    std::string output;
    p.SerializeToString(&output);

    //反序列化数据
    Xiaoaoqi::Person pp;
    pp.ParseFromString(output);
    std::cout<<pp.aaa()<<std::endl;
    std::cout<<pp.id()<<","<<pp.sex()<<","<<pp.name()<<","<<pp.age()<<std::endl;
    std::cout<<pp.addr().m_addr()<<","<<pp.addr().num()<<std::endl;
    int size=pp.name2_size();
    for(int i=0;i<size;i++)
    {
        std::cout<<pp.name2(i)<<std::endl;
    }
    std::cout<<pp.color()<<std::endl;//打印出来的是蓝色所对应的数值9
}


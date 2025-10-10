#pragma once
#include "object.hpp"
class cursor :public object {
private:
	const vector<message> &options;
	int index;
	friend class ui;
public:
	cursor(const vector<message>& initMsg, int index = 0);
public:
	void CursorUp(int step = 1);
	void CursorDown(int step = 1);
	auto Which() -> int;
	void Draw() override;
};



class ui : public cursor{
private:
	vector<message> msgs;
	message title;
public:
	ui(const vector<message>& initMsgs);
public:
	void AddTitle(const message& title);
	void Draw() override;
};

//�α���ά��һ��ָ�룬����ָ��ѡ�����ͼ������������Ϸ������Ҫʱ�������ָ��
//ѡ�����ͨ�ı��Լ�����ͬ����Ϊ��Ϣ�����ڱ��У����ж���ı�ά��������Ϣ���е�λ���Լ�ѡ��ı��
//�����α�ֻҪָ�����������ָ��ѡ�ͨ����ѡ���ܹ�����ȷ����
//ѡ�����ʾ��������Ϣ��ͬ���β���һ�ּ���ծ��
//��ʵ����νѡ����Ұ��߼�д�������ĵط��ͺ���
//������ʵ���ڣ��������ָ�ʽ��ͳһ
//����ṹ��ֻ��������Ϣ�Ĵ洢������Щ��Ϣ������Ǻ����Ĺ���
//�µ�����Ȼ���ᱻ��ͱ����
//��ʵѡ��Ӧ�ò������ֵĸ�������
//������ѡ����������һ��������α��ڲ�ͬ������ƶ��ͺ���

//�α�ֻ����ָ��ѡ��ƶ������ⲿ

//10.06
//������Ϣ���Լ��������ˣ�����ܹ�ָ����������
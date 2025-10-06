#pragma once
#include "types.hpp"
class cursor :public object {
private:
	const vector<message> &options;
	int index;
	friend class ui;
public:
	cursor(const vector<message>& initMsg, int index = 0);
public:
	void SetCursorPos(int x, int y);
	void SetCursorPos(position pos);
	void CursorUp(int step = 1);
	void CursorDown(int step = 1);
	auto Which() -> int;
	void Draw() override;
};



class ui : protected cursor{
private:
	vector<message> msgs;
	message title;
public:
	ui(const vector<message>& initMsgs);
public:
	void AppendBar(message msg);
	void AppendBar(position pos, string text);
	void AppendBar(int x, int y, string text);
	void AppendBar(string text, font txtType);
	void AddTitle(const message& title);
	void CursorUp();
	void CursorDown();
	auto WhichOption() -> int;
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
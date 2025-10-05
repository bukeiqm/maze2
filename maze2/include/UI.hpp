#include "datatypes.hpp"
class cursor {
private:
	position pos;
	vector<position> options;
	int index;
	friend class ui;
public:
	cursor(position pos = { 0,0 }, int index = 0);
public:
	void SetCursorPos(int x, int y);
	void SetCursorPos(position pos);
	void AddOptions(position pos);
	void CursorUp(int step = 1);
	void CursorDown(int step = 1);
	auto Which() -> int;
};



class ui {
private:
	vector<message> msgs;
	cursor cursor;
public:
	void AppendBar(message msg);
	void AppendBar(position pos, string text);
	void AppendBar(int x, int y, string text);
	void AppendBar(string text, font txtType);
	void AddOptionsFromBars(int index);
	void InitCursor();
	void CursorUp();
	void CursorDown();
	auto WhichOption() -> int;
	auto GetTexts() const -> decltype(msgs);
	auto GetCursor() -> decltype(cursor);
	auto GetCursorPosition() const -> position;
	auto GetCursorIndex() -> int;
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
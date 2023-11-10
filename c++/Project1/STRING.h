//---------------------------------------------------------------------------------
//STRING.h
// 
// 2023.11.09 ���Ϻи���
//---------------------------------------------------------------------------------

#pragma once

class STRING {
	size_t num;
	char* p;

public:
	STRING(const char* s);
	~STRING();

	//2023. 11. 09 ���� ������(����� �Լ�)
	STRING(const STRING& other);

	//2023. 11. 09 ���� �����ڸ� ������ٸ� �̿� ¦�� �Ǵ� copy assignment operator�� 
	//�ݵ�� �ڵ��ؾ� �Ѵ�.
	STRING& operator=(const STRING& other);

	//2023.11.09 �̵��� �̵��Ҵ�
	STRING(STRING&&);//const�� ���� �� �����. �����͸� �����ٵ�

	size_t size() const;

	void show() const;

	//����� �Լ��� �ʿ��Ҷ� �����Ѵ�.
	static bool ����;
};


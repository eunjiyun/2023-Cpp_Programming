//---------------------------------------------------------------------------------
//STRING.h
// 
// 2023.11.09 파일분리함
//---------------------------------------------------------------------------------

#pragma once

class STRING {
	size_t num;
	char* p;

public:
	STRING(const char* s);
	~STRING();

	//2023. 11. 09 복사 생성자(스페셜 함수)
	STRING(const STRING& other);

	//2023. 11. 09 복사 생성자를 만들었다면 이와 짝이 되는 copy assignment operator를 
	//반드시 코딩해야 한다.
	STRING& operator=(const STRING& other);

	//2023.11.09 이동과 이동할당
	STRING(STRING&&);//const를 붙일 수 없어요. 데이터를 뺏길텐데

	size_t size() const;

	void show() const;

	//스페셜 함수를 필요할때 관찰한다.
	static bool 관찰;
};


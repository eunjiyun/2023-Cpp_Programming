//---------------------------------------------------------------------------------
//STRING.h
// 
// 2023.11.09 파일분리함
//---------------------------------------------------------------------------------

#pragma once

class STRING {
	size_t num{};//모든 메모리 비트를 0으로
	char* p{};//nullptr로 되어 있다.

public:
	//2023. 11. 15 인자를 받는 생성자를 하나라도 코딩했다면 반드시 디폴트생성자를 코딩
	STRING() = default;
	STRING(const char* s);
	~STRING();

	//2023. 11. 09 복사 생성자(스페셜 함수)
	STRING(const STRING& other);

	//2023. 11. 09 복사 생성자를 만들었다면 이와 짝이 되는 copy assignment operator를 
	//반드시 코딩해야 한다.
	STRING& operator=(const STRING& other);

	//2023.11.09 이동과 이동할당
	STRING(STRING&&);//const를 붙일 수 없어요. 데이터를 뺏길텐데

	//2023. 11. 15 연산자 오버로딩
	STRING operator+(const char*)const;
	STRING operator+(const STRING&)const;

	size_t size() const;

	void show() const;

	//스페셜 함수를 필요할때 관찰한다.
	static bool 관찰;
};


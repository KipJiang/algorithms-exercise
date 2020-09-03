#include <iostream>


class CMyString
{
public:
    CMyString(char* pData = nullptr);
    CMyString(const CMyString& str);
    ~CMyString(void);

    void operator;
private:
    char* m_pData;
};


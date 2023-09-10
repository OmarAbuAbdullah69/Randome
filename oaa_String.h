#ifndef OAA_STRING_H
#define OAA_STRING_H


#include <iostream>
#include <cstring>

namespace OAA
{
	class String
	{
		public:
			String(const char *s);
			const char * cstr();
			inline size_t len() const {return m_Lenght-1;}
			String operator +(String s);
			String operator +(const char *s);
			void operator +=(String s);
			void operator +=(const char *s);
			~String();
		private:
			String(char *c_str, size_t lenght);
			char *m_CString;
			size_t m_Lenght;
	};
}

#ifdef OAA_STRING_IMPL
namespace OAA
{
	String::String(char *c_str, size_t lenght)
		:m_CString(c_str), m_Lenght(lenght){
	}
	String::String(const char *s)
		:m_Lenght(strlen(s)+1)
	{
		std::cout << "constructed" << std::endl;
		m_CString = new char[m_Lenght];
		memcpy(m_CString, s, sizeof(char)*m_Lenght);
	}
	String::~String()
	{
		delete[] m_CString;
	}
	const char *String::cstr()
	{
		return m_CString;
	}

	String String::operator +(String s)
	{
		size_t lenght = m_Lenght + s.m_Lenght - 1;
		char *data = new char[lenght];
		memcpy(data, m_CString, sizeof(char)*(m_Lenght-1));
		memcpy(data+m_Lenght-1, s.m_CString, sizeof(char)*s.m_Lenght);
		return String(data, lenght);
	}
	String String::operator +(const char *s)
	{
		size_t lenght = strlen(s) + m_Lenght - 1;
		char *data = new char[lenght];
		memcpy(data, m_CString, sizeof(char)*(m_Lenght-1));
		memcpy(data+m_Lenght-1, s, sizeof(char)*strlen(s));
		return String(data, lenght);
	}
	void String::operator +=(String s)
	{
		size_t lenght = m_Lenght + s.m_Lenght - 1;
		char *data = new char[lenght];
		memcpy(data, m_CString, sizeof(char)*(m_Lenght-1));
		memcpy(data+m_Lenght-1, s.m_CString, sizeof(char)*s.m_Lenght);
		m_Lenght = lenght;
		m_CString = data;
	}
	void String::operator +=(const char *s)
	{
		size_t lenght = strlen(s) + m_Lenght - 1;
		char *data = new char[lenght];
		memcpy(data, m_CString, sizeof(char)*(m_Lenght-1));
		memcpy(data+m_Lenght-1, s, sizeof(char)*strlen(s));
		m_Lenght = lenght;
		m_CString = data;
	}
}

#endif // 

#endif // OAA_STRING_H

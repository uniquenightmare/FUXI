#define  _CRT_SECURE_NO_WARNINGS 1
#include<iostream>

template<class T>
class autoptr
{
public:
	autoptr(T* ptr == NULL)
		:_ptr(ptr)
	{
		
	}
	~autoptr()
	{
		if (_ptr)
			delete _ptr;
	}
	autoptr(const autoptr<T>& ap)
		:_ptr(ap._ptr)
	{
		ap._ptr = NULL;

	}
	autoptr<T>& operator =(autoptr<T>& ap)
	{
		if (this != &ap)
		{
			if (_ptr)
				delete _ptr;
			_ptr = ap._ptr;
			ap._ptr = NULL;
		}
		return *this;
	}
	T& operator *()
	{
		return *_ptr;
	}
	T* operator ->()
	{
		return _ptr;
	}
private:
	T* _ptr;
};
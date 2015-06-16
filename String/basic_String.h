#ifndef _BASIC_STRING_H_
#define _BASIC_STRING_H_

#include <iostream>

#define INIT_OF_SIZE 15
#define _LI_BEGIN namespace Li {
#define _LI_END }

_LI_BEGIN
typedef std::istream& _rIs;
typedef std::ostream& _rOs;

template<typename _ty>
class basic_String
{
public:
	typedef _ty* _pty;
	typedef _ty& _rty;
	typedef const _ty* _cpty;
	typedef const _ty& _crty;
	typedef basic_String& _rMstr;
	typedef const basic_String& _crMstr;
	typedef const basic_String<_ty>& _crMstrm;

	// ��Ԫ����������������(>>��<<)
	template<typename _t> friend _rIs operator>>(_rIs in, basic_String<_t>&);
	template<typename _t> friend _rOs operator<<(_rOs os, const basic_String<_t>&);

	// ��Ԫ����!=��==�����
	template<typename _t> friend bool operator==(const basic_String<_t>&, const basic_String<_t>&);
	template<typename _t> friend bool operator!=(const basic_String<_t>&, const basic_String<_t>&);

	// ��Ԫ����+�����
	template<typename _t> friend basic_String<_t> operator+(const basic_String<_t> &one, const basic_String<_t> &two);
	template<typename _t> friend basic_String<_t> operator+(const basic_String<_t> &one, const char &two);
	template<typename _t> friend basic_String<_t> operator+(const basic_String<_t> &one, const char *two);

	basic_String()
	{// Ĭ�Ϲ��캯��
		capacity = INIT_OF_SIZE;
		_str = new _ty[capacity + 1];
		_str[0] = '\0';
		len = Strlen(_str);
	}

	basic_String(_cpty _val)
	{// ���캯��
		_str = new _ty[Strlen(_val) + 1];
		capacity = Strlen(_val);
		Strcpy(_str, _val);
		len = Strlen(_str);
	}

	basic_String(_crMstrm _R)
	{// �������캯��
		_str = new _ty[_R.capacity + 1];
		capacity = _R.capacity;
		Strcpy(_str, _R._str);
		len = Strlen(_str);
	}

	~basic_String()
	{// ��������
		delete[] _str;
		_str = NULL;
	}

	_rty operator[](size_t _x)
	{// �����±������([])
		if (_x < 0 || _x > capacity - 1)
			return -1;
		return _str[_x];
	}

	_rMstr operator=(_crMstr _R)
	{// ���ظ�ֵ�����(=)
		_str = new _ty[_R.capacity + 1];
		capacity = _R.capacity;
		Strcpy(_str, _R._str);
		len = Strlen(_str);
		return *this;
	}

	_rMstr operator=(_cpty _R)
	{// ���ظ�ֵ�����(=)
		_str = new _ty[Strlen(_R) + 1];
		capacity = Strlen(_R);
		Strcpy(_str, _R);
		len = Strlen(_str);
		return *this;
	}

	_rMstr operator+=(_crMstr _R)
	{// ���ظ��ϸ�ֵ�����(+=)
		append(_R);
		return *this;
	}

	_rMstr operator+=(_cpty temp)
	{// ���ظ��ϸ�ֵ�����(+=)
		append(temp);
		return *this;
	}

	_rMstr operator+=(const char &temp)
	{// ���ظ��ϸ�ֵ�����(+=)
		append(temp);
		return *this;
	}

	void append(_crMstrm tem)
	{// ���ַ�����������һ��basic_String����
		if (len + tem.len >= capacity)
		{
			_pty _cre = new _ty[2 * (len + tem.len) + 1];
			capacity = 2 * (len + tem.len);
			Strcpy(_cre, _str);
			delete[] _str;
			_str = _cre;
			Strcat(_str, tem._str);
			len = Strlen(_str);
		}
		else
		{
			Strcat(_str, tem._str);
			len = Strlen(_str);
		}
	}

	void append(_cpty tem)
	{// ���ַ�����������һ���ַ�
		if (len + Strlen(tem) >= capacity)
		{
			_pty _cre = new _ty[2 * (len + Strlen(tem)) + 1];
			capacity = 2 * (len + Strlen(tem));
			Strcpy(_cre, _str);
			delete[] _str;
			_str = _cre;
			Strcat(_str, tem);
			len = Strlen(_str);
		}
		else
		{
			Strcat(_str, tem);
			len = Strlen(_str);
		}
	}

	void append(const char &tem)
	{// ���ַ�����������һ���ַ�
		if (len >= capacity)
		{
			_pty _cre = new _ty[2 * len + 1];
			capacity = 2 * len;
			Strcpy(_cre, _str);
			delete[] _str;
			_str = _cre;
			_str[len] = tem;
			++len;
			_str[len] = '\0';
		}
		else
		{
			_str[len] = tem;
			++len;
			_str[len] = '\0';
		}
	}

	void clear()
	{// �������
		delete[] _str;
		capacity = INIT_OF_SIZE;
		_str = new _ty[capacity + 1];
		_str[0] = '\0';
		len = Strlen(_str);
	}

	_cpty c_str() const
	{// ��basic_StringתΪC����ַ���
		return _str;
	}

	int empty() const
	{// �ж��Ƿ�Ϊ�գ�1Ϊ�գ�0Ϊ����
		return len == 0 ? 1 : 0;
	}

	size_t size() const
	{// ��ȡ�ַ�������
		return len;
	}

private:
	size_t capacity;
	size_t len;
	_pty _str;

	size_t Strlen(_cpty _tem) const
	{// ���ַ��ĳ���
		size_t _len = 0;
		while (_tem[_len] != '\0') ++_len;
		return _len;
	}

	_pty Strcpy(_pty _one, _cpty _two)
	{// �����ַ���_two��_one��
		size_t length_two = Strlen(_two);
		for (int i = 0; i != length_two + 1; ++i)
		{
			_one[i] = _two[i];
		}
		//while(*(_one++)=*(_two++) != '\0');	// C����string.h�ķ���
		return _one;
	}

	_pty Strcat(_pty _one, _cpty _two)
	{// ���ַ���_two�ӵ�_one����ȥ
		size_t length_one = Strlen(_one);
		size_t length_two = Strlen(_two);
		for (int i = length_one, j = 0; j != length_two + 1; ++i, ++j)
		{
			_one[i] = _two[j];
		}
		return _one;
	}

	int Strcmp(_cpty _one) const
	{// �Ƚ��ַ���_one��_two�Ƿ���ͬ
		size_t len_one = Strlen(_one);
		if (len != len_one)
		{
			return -1;
		}
		else
		{
			for (int i = 0; i != len_one; ++i)
			{
				if (_str[i] != _one[i])
					return -1;
			}
			return 0;
		}
	}
};

template<typename _ty>
_rIs operator>>(_rIs in, basic_String<_ty> &temp)
{// �������������
	char _c;
	delete[] temp._str;
	temp._str = new _ty[INIT_OF_SIZE + 1];
	temp._str[0] = '\0';
	temp.capacity = INIT_OF_SIZE;
	temp.len = temp.Strlen(temp._str);
	_c = in.get();
	while (_c != '\n')
	{
		temp.append(_c);
		_c = in.get();
	}
	return in;
}

template<typename _ty>
inline _rOs operator<<(_rOs os, const basic_String<_ty> &temp)
{// ������������
	os << temp._str;
	return os;
}

template<typename _ty>
inline bool operator==(const basic_String<_ty> &tem1, const basic_String<_ty> &tem2)
{
	return tem1.Strcmp(tem2._str) == 0 ? true : false;
}

template<typename _ty>
inline bool operator!=(const basic_String<_ty> &tem1, const basic_String<_ty> &tem2)
{
	return tem1.Strcmp(tem2._str) != 0 ? true : false;
}

template<typename _ty>
basic_String<_ty> operator+(const basic_String<_ty> &one, const basic_String<_ty> &two)
{
	basic_String<_ty> tem;
	tem.append(one);
	tem.append(two);
	return tem;
}

template<typename _ty>
basic_String<_ty> operator+(const basic_String<_ty> &one, const char &two)
{
	basic_String<_ty> tem;
	tem.append(one);
	tem.append(two);
	return tem;
}

template<typename _ty>
basic_String<_ty> operator+(const basic_String<_ty> &one, const char *two)
{
	basic_String<_ty> tem;
	tem.append(one);
	tem.append(two);
	return tem;
}
_LI_END

#endif	//	basic_String.h	(version 2.0)
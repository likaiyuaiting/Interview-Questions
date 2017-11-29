#if 0
#include<iostream>  
#include<vector>  
using namespace std;

template<class T>
class MyVector
{
public:
	typedef T* Iterator;
	typedef const T* ConstIterator;

	MyVector(size_t n = 3)      //���캯������ʼ����3��T��������  
		:_start(new T[n]), _finish(_start), _end_of_storage(_start + n)
	{
	}
	MyVector(const MyVector<T>& v)   //��������  
	{
		if (v._finish - v._start > _finish - _start)
		{
			delete[] _start;
			_start = new T[v._finish - v._start];
			_finish = _start;
		}
		for (Iterator tmp = v._start; tmp != v._finish; tmp++)
		{
			*(_finish) = *tmp;
			_finish++;
		}
		_end_of_storage = _finish;
	}
	void PushBack(const T& x)   //β�壬����ע�⣬��ʹ���õ�insert������������β�庯��������  
	{
		CheckCapacity();
		Insert(End(), x);
	}
	void PopBack()
	{
		Iterator pos = End();   //ǰ�õ�--��Ϊ���ص�����ʱ������ֵ�����Բ���ֱ�Ӷ�End()��������--  
		Erase(--pos);
	}

	void Insert(Iterator pos, const T& x)
	{
		CheckCapacity();
		for (Iterator tmp = End(); tmp != pos; tmp--)
		{
			*tmp = *(tmp - 1);
		}
		*pos = x;
		_finish++;
	}

	void Erase(Iterator pos)
	{
		Iterator end = End();
		for (Iterator tmp = pos; tmp != (--end); tmp++)
		{
			*tmp = *(tmp + 1);
		}
		_finish--;
	}

	size_t Size()
	{
		return _finish - _start;
	}
	/************����������***********/
	Iterator Begin()
	{
		return _start;
	}
	Iterator End()
	{
		return _finish;
	}
	/*Iterator operator++(int)
	{
	Iterator tmp = *this;
	tmp++;
	return tmp;
	}
	Iterator& operator++()
	{
	Iterator tmp = *this;
	tmp++;
	return *this;
	}
	Iterator operator--(int)
	{
	Iterator tmp = *this;
	tmp--;
	return tmp;
	}
	Iterator& operator--()
	{
	Iterator tmp = *this;
	tmp--;
	return *this;
	}
	*/
private:
	void CheckCapacity()
	{
		if (_finish == _end_of_storage)
		{
			Iterator new_start = new T[2 * Size()];   //һ������ԭ��������  
			Iterator new_finish = new_start;
			for (Iterator i = Begin(); i != End(); i++, new_finish++)
			{
				*new_finish = *i;
			}
			delete[] _start;
			_start = new_start;
			_finish = new_finish;
			_end_of_storage = _start + 2 * Size();
		}
	}
private:
	Iterator _start;
	Iterator _finish;
	Iterator _end_of_storage;
};


void TestVector()
{
	MyVector<int> v;
	v.PushBack(1);
	v.PushBack(2);
	v.PushBack(3);
	v.PushBack(4);
	MyVector<int>::Iterator it;
	for (it = v.Begin(); it != v.End(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;
	v.PopBack();
	v.PopBack();
	for (it = v.Begin(); it != v.End(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;
	MyVector<int> v1(v);
	for (it = v1.Begin(); it != v1.End(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;
}
int main(void)
{
	TestVector();
	return 0;
}

#endif



#if 0

#include <memory>  
#include <iostream>  
using namespace std;

typedef int DataType;
class Vector
{
public:
	//���캯��  
	explicit Vector(size_t capacity = 0)
		:_pData(NULL),
		_capacity(capacity),
		_size(0)
	{
		_pData = new DataType[_capacity];
	}

	// ��size��ֵΪdata��Ԫ��  
	//�������캯��  
	Vector(const DataType& data)
		:_size(0)
		, _capacity(0)
		, _pData(NULL)
	{
		*this = data;
	}
	//��ֵ���������  
	Vector& operator=(const Vector& v)
	{
		if (&v != this)
		{
			DataType* tmp = v._pData;
			_size = v._size;
			_capacity = v._capacity;
			for (size_t i = 0; i < v._size; ++i)
			{
				_pData[i] = v._pData[i];
			}
			delete[] tmp;
		}
		return *this;
	}
	//��������  
	~Vector()
	{
		if (_pData)
		{
			delete[] _pData;
			_pData = NULL;
		}
	}

	/////////////////////////////////////  
	void PushBack(const DataType& data);
	void PopBack();
	void Insert(size_t pos, const DataType& data);
	void Erase(size_t pos);
	int Find(const DataType& data)const;
	void Clear();
	size_t Size()const;
	void ReSize(size_t size, const DataType& data = DataType());
	size_t Capacity()const;
	bool Empty()const;
	DataType& Front();
	const DataType& Front()const;
	DataType& Back();
	const DataType& Back()const;
	void Assign(size_t n, const DataType& data = DataType());
	DataType& operator[](size_t index);
	const DataType& operator[](size_t index)const;
	DataType& At(size_t index);
	const DataType& At(size_t index)const;

	//////////////////////////////////////////////  
private:
	void _CheckCapacity();
	friend std::ostream& operator<<(std::ostream& _cout, const Vector& v);
private:
	DataType* _pData;
	size_t _capacity;
	size_t _size;
};

//����ݻ��Ƿ�����������������  
void Vector::_CheckCapacity()
{
	if (_size == _capacity)
	{
		DataType *tmp = new DataType[2 * _size];
		if (NULL != *tmp)
		{
			for (size_t i = 0; i < _size; i++)
			{
				tmp[i] = _pData[i];
			}
			delete[] _pData;
		}
		_pData = tmp;
	}
}
//ʵ��β������  
void Vector::PushBack(const DataType& data)
{
	_CheckCapacity();
	_pData[_size] = data;
}
//ʵ��β��ɾ��  
void Vector::PopBack()
{
	if (this->_size == NULL)
	{
		cout << "������Ϊ�գ�����ɾ��" << endl;
	}
	this->_size--;
}
//posλ���ϲ���ֵԪ��   
void Vector::Insert(size_t pos, const DataType& data)
{
	_CheckCapacity();
	DataType *tmp = new DataType[_size++];
	tmp = _pData;
	for (size_t i = _size; i >= pos; i--)
	{
		tmp[i] = tmp[i - 1];
	}
	tmp[pos] = data;
}
//ɾ��posλ���ϵ�Ԫ��  
void Vector::Erase(size_t pos)
{
	if (NULL == _pData[pos])
	{
		cout << "��λ��Ϊ�գ��޷�ɾ��" << endl;
	}
	else
	{
		for (size_t i = _size; i >= pos; i--)
		{
			_pData[i - 1] = _pData[i];
		}
		this->_capacity--;
		this->_size--;
	}
}
//����ֵΪdata��Ԫ��  
int Vector::Find(const DataType& data)const
{
	for (size_t i = 0; i <= _size; i++)
	{
		if (_pData[i] == data)
		{
			return i;
		}
		return -1;
	}
}
//ɾ��˳�������Ԫ��  
void Vector::Clear()
{
	*this = NULL;
	this->_capacity = 0;
	this->_size = 0;
}
//��˳���ĳ���  
size_t Vector::Size()const
{
	return _capacity;
}
//�ı�vector��Ԫ�ص���Ŀ  
//���size�ȵ�ǰ��vector��ĿҪС��  
//vector������Ҫ��������һ�������Ĵ�С������size.���������Щ����size��Ԫ�ز���������  
//���size�ȵ�ǰ��vector��ĿҪ��  
//vector��ĩβ��Ҫ��չ��Ԫ�ظ�����  
void Vector::ReSize(size_t size, const DataType& data = DataType())
{
	if (size < this->_size)
	{
		this->_size = size;
		for (size_t i = size; i < _size; i++)
		{
			_pData[i] = 0;
		}
	}
	else if (size == this->_size)
	{
	}
	else
	{
		this->_size = size;
	}
}
//����vector������������ɶ��ٸ�Ԫ��  
size_t Vector::Capacity()const
{
	return _capacity;
}
//�������Ϊ�գ��򷵻�true�����򷵻�false  
bool Vector::Empty()const
{
	if (NULL == _pData)
	{
		return true;
	}
	else
	{
		return false;
	}
}
//���ص�ǰVector��������ʼԪ�ص�Ӧ��  
DataType& Vector::Front()
{
	return *_pData;
}
const DataType& Vector::Front()const
{
	return *_pData;
}
DataType& Vector::Back()
{
	--_size;
}
const DataType& Vector::Back()const
{
	return _pData[_size - 1];
}
//�����䡾first,last����Ԫ�ظ��Ƶ���ǰ��Vector�����У����߸�N��ֵΪX��Ԫ�ص�vector�����У�  
//��������������vector��������ǰ�����ݡ�  
void Vector::Assign(size_t n, const DataType& data = DataType())
{
	DataType *tmp = new DataType[n];
	for (size_t i = 0; i <= n; i++)
	{
		tmp[i] = data;
	}
	if (n < _size)
	{
		_CheckCapacity();
	}
	_size = n;
	_pData = tmp;
	delete[] tmp;
}
//�����±�������ǳ����汾  
DataType& Vector::operator[](size_t index)
{
	return _pData[index];
}
//�����±�����������汾  
const DataType& Vector::operator[](size_t index)const
{
	return _pData[index];
}
DataType& Vector::At(size_t index)
{
	return _pData[index];
}
const DataType& Vector::At(size_t index)const
{
	return _pData[index];
}

#endif

#if 1

#include<iostream>
using namespace std;

#pragma once
template<class T>
class Vector
{
public:
	typedef T ValueType;//��������T���洢��vector��
	typedef ValueType* Pointer;//ָ��T��ָ��
	typedef const ValueType* ConstPointer;
	typedef ValueType* Iterator;//����vector�ĵ�����
	typedef const ValueType* ConstIterator;//����vector�ĳ���������
	typedef ValueType& Reference;//T��һ������
	typedef const ValueType& ConstReference;//T�ĳ�������
	typedef size_t SizeType;//����������


public:
	Vector()//���캯��
		: _start(0)
		, _end(0)
		, _endOfStorage(0)
	{}

	Vector(SizeType n, const T& value)//����һ��vector������Ϊn����СΪvalue
	{
		FillAndInit(n, value);
	}

	Vector(SizeType n)//����һ��vector��Ԫ������Ϊn
	{
		FillAndInit(n, T());
	}

	Vector(const Vector<T>& v)//�������캯��
	{
		CheckCapacity();
		_start = new T[v.Capacity()];
		_end = _start + v.Size();
		_endOfStorage = _start + v.Capacity();

		for (size_t idx = 0; idx < v.Size(); ++idx)
			_start[idx] = v[idx];
	}

	Vector<T>& operator=(const Vector<T>& v)//��ֵ�����������
	{
		if (this != &v)
		{
			_start = v._start;
			_end = v._end;
			_endOfStorage = v._endOfStorage;
		}
		return *this;
	}
	~Vector()//��������
	{
		delete[] _start;
		_start = _end = 0;
	}


	/////////////////////Capacity//////////////////////
	SizeType Capacity()const//���ص�ǰ�������ɵ����Ԫ�صĸ���
	{
		return SizeType(_endOfStorage - Begin());
	}
	SizeType Size()const//����vector��Ԫ������
	{
		return SizeType(End() - Begin());
	}
	SizeType MaxSize()const//�������������vectorԪ������ֵ
	{
		return (SizeType(-1) / sizeof(T));
	}
	bool Empty()const//�ж�vector�Ƿ�Ϊ��
	{
		if (Size() == 0)
			return true;
		return false;
	}

	//////////////Acess/////////////////////
	Reference operator[](size_t index)//���ص�n��Ԫ��
	{
		return *(Begin() + index);
	}
	ConstReference operator[](size_t index)const
	{
		return *(Begin() + index);
	}
	Reference Front()//���ص�һ��Ԫ��
	{
		return *Begin();
	}
	ConstReference Front()const
	{
		return *Begin();
	}
	Reference Back()//�������һ��Ԫ��
	{
		return *(End() - 1);
	}
	ConstReference Back()const
	{
		return *(End() - 1);
	}


	/////////////Iterator//////////////////
	Iterator Begin()//����vector��ͷָ��
	{
		return _start;
	}
	ConstIterator Begin()const
	{
		return _start;
	}
	Iterator End()//����vector��βָ��
	{
		return _end;
	}
	ConstIterator End()const
	{
		return _end;
	}

	//////////////Modify///////////////////
	void PushBack(const T& value)//β��
	{
		CheckCapacity();
		Insert(End(), value);
	}
	void PopBack()
	{
		Iterator pos = End();
		Erase(--pos);
	}

	// ��positionλ�ò���Ԫ��data
	void Insert(Iterator position, const T& data)
	{
		CheckCapacity();
		for (Iterator index = End(); index != position; index--)
		{
			*index = *(index - 1);
		}
		*position = data;
		_end++;
	}

	// ɾ��positionλ�õ�Ԫ��
	void Erase(Iterator position)
	{
		Iterator end = End();
		for (Iterator index = position; index != End(); ++index)
		{
			*index = *(index + 1);
		}
		_end--;
	}
	//���
	void clear()
	{
		Erase(Begin(), End());
	}

protected:
	void FillAndInit(SizeType n, const T& value)
	{
		_start = new T[n];
		for (size_t index = 0; index < _end; ++index)
		{
			_start[index] = value;
		}
	}
	void CheckCapacity()
	{
		if (_end == _endOfStorage)
		{
			Iterator NewStart = new T[2 * Size()];
			Iterator NewEnd = NewStart;
			for (Iterator i = Begin(); i != End(); i++, NewEnd++)
			{
				*NewEnd = *i;
			}
			delete[] _start;
			_start = NewStart;
			_end = NewEnd;
			_endOfStorage = _start + 2 * Size();
		}
	}
protected:
	Iterator _start;
	Iterator _end;
	Iterator _endOfStorage;

};

int main(void)
{
	Vector<int> v;
	v.PushBack(1);
	v.PushBack(2);
	v.PushBack(3);
	v.PushBack(4);
	cout << v.Size() << endl;
	v.PopBack();
	//cout << v.Back() << endl;
	Vector<int> v2(v);
	cout << v2.Size() << endl;

	return 0;
}

#endif
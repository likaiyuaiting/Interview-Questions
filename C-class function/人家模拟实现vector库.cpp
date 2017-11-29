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

	MyVector(size_t n = 3)      //构造函数，初始化给3个T类型容量  
		:_start(new T[n]), _finish(_start), _end_of_storage(_start + n)
	{
	}
	MyVector(const MyVector<T>& v)   //拷贝构造  
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
	void PushBack(const T& x)   //尾插，这里注意，即使调用的insert里检查了容量，尾插函数仍需检测  
	{
		CheckCapacity();
		Insert(End(), x);
	}
	void PopBack()
	{
		Iterator pos = End();   //前置的--因为返回的是临时变量的值，所以不能直接对End()函数进行--  
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
	/************迭代器部分***********/
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
			Iterator new_start = new T[2 * Size()];   //一次扩容原来的两倍  
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
	//构造函数  
	explicit Vector(size_t capacity = 0)
		:_pData(NULL),
		_capacity(capacity),
		_size(0)
	{
		_pData = new DataType[_capacity];
	}

	// 有size个值为data的元素  
	//拷贝构造函数  
	Vector(const DataType& data)
		:_size(0)
		, _capacity(0)
		, _pData(NULL)
	{
		*this = data;
	}
	//赋值运算符重载  
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
	//析构函数  
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

//检查容积是否已满，不满足申请  
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
//实现尾部插入  
void Vector::PushBack(const DataType& data)
{
	_CheckCapacity();
	_pData[_size] = data;
}
//实现尾部删除  
void Vector::PopBack()
{
	if (this->_size == NULL)
	{
		cout << "次链表为空，不可删除" << endl;
	}
	this->_size--;
}
//pos位置上插入值元素   
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
//删除pos位置上的元素  
void Vector::Erase(size_t pos)
{
	if (NULL == _pData[pos])
	{
		cout << "此位置为空，无法删除" << endl;
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
//查找值为data的元素  
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
//删除顺序表所有元素  
void Vector::Clear()
{
	*this = NULL;
	this->_capacity = 0;
	this->_size = 0;
}
//求顺序表的长度  
size_t Vector::Size()const
{
	return _capacity;
}
//改变vector中元素的数目  
//如果size比当前的vector数目要小，  
//vector的容量要缩减到第一个参数的大小，既是size.并且溢出那些超出size的元素并销毁他们  
//如果size比当前的vector数目要大，  
//vector的末尾需要扩展的元素个数，  
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
//返回vector对象最多能容纳多少个元素  
size_t Vector::Capacity()const
{
	return _capacity;
}
//如果对象为空，则返回true，否则返回false  
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
//返回当前Vector容器中起始元素的应用  
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
//将区间【first,last】的元素复制到当前的Vector容器中，或者赋N个值为X的元素到vector容器中，  
//这个容器会清除掉vector容器中以前的内容。  
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
//重载下标操作符非常量版本  
DataType& Vector::operator[](size_t index)
{
	return _pData[index];
}
//重载下标操作符常量版本  
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
	typedef T ValueType;//对象类型T，存储在vector中
	typedef ValueType* Pointer;//指向T的指针
	typedef const ValueType* ConstPointer;
	typedef ValueType* Iterator;//访问vector的迭代器
	typedef const ValueType* ConstIterator;//访问vector的常量迭代器
	typedef ValueType& Reference;//T的一个引用
	typedef const ValueType& ConstReference;//T的常量引用
	typedef size_t SizeType;//正整数类型


public:
	Vector()//构造函数
		: _start(0)
		, _end(0)
		, _endOfStorage(0)
	{}

	Vector(SizeType n, const T& value)//创建一个vector，数量为n，大小为value
	{
		FillAndInit(n, value);
	}

	Vector(SizeType n)//创建一个vector，元素数量为n
	{
		FillAndInit(n, T());
	}

	Vector(const Vector<T>& v)//拷贝构造函数
	{
		CheckCapacity();
		_start = new T[v.Capacity()];
		_end = _start + v.Size();
		_endOfStorage = _start + v.Capacity();

		for (size_t idx = 0; idx < v.Size(); ++idx)
			_start[idx] = v[idx];
	}

	Vector<T>& operator=(const Vector<T>& v)//赋值运算符的重载
	{
		if (this != &v)
		{
			_start = v._start;
			_end = v._end;
			_endOfStorage = v._endOfStorage;
		}
		return *this;
	}
	~Vector()//析构函数
	{
		delete[] _start;
		_start = _end = 0;
	}


	/////////////////////Capacity//////////////////////
	SizeType Capacity()const//返回当前所能容纳的最多元素的个数
	{
		return SizeType(_endOfStorage - Begin());
	}
	SizeType Size()const//返回vector的元素数量
	{
		return SizeType(End() - Begin());
	}
	SizeType MaxSize()const//返回最大可允许的vector元素数量值
	{
		return (SizeType(-1) / sizeof(T));
	}
	bool Empty()const//判断vector是否为空
	{
		if (Size() == 0)
			return true;
		return false;
	}

	//////////////Acess/////////////////////
	Reference operator[](size_t index)//返回第n个元素
	{
		return *(Begin() + index);
	}
	ConstReference operator[](size_t index)const
	{
		return *(Begin() + index);
	}
	Reference Front()//返回第一个元素
	{
		return *Begin();
	}
	ConstReference Front()const
	{
		return *Begin();
	}
	Reference Back()//返回最后一个元素
	{
		return *(End() - 1);
	}
	ConstReference Back()const
	{
		return *(End() - 1);
	}


	/////////////Iterator//////////////////
	Iterator Begin()//返回vector的头指针
	{
		return _start;
	}
	ConstIterator Begin()const
	{
		return _start;
	}
	Iterator End()//返回vector的尾指针
	{
		return _end;
	}
	ConstIterator End()const
	{
		return _end;
	}

	//////////////Modify///////////////////
	void PushBack(const T& value)//尾插
	{
		CheckCapacity();
		Insert(End(), value);
	}
	void PopBack()
	{
		Iterator pos = End();
		Erase(--pos);
	}

	// 在position位置插入元素data
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

	// 删除position位置的元素
	void Erase(Iterator position)
	{
		Iterator end = End();
		for (Iterator index = position; index != End(); ++index)
		{
			*index = *(index + 1);
		}
		_end--;
	}
	//清空
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
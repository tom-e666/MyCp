#include <bits/stdc++.h>
using namespace std;
template <class t>
class LinkedList;
template <class t>
class Node
{
	friend class LinkedList<t>;
	t _value;
	Node *pNext;

public:
	Node(t value)
	{
		_value = value;
		pNext = NULL;
	}
};
template <class t>
class LinkedList
{
	Node<t> *pHead;
	Node<t> *pTail;

public:
	LinkedList()
	{
		pHead = pTail = NULL;
	}
	void addHead(t value)
	{
		Node<t> *temp = new Node<t>(value);
		if (pHead == NULL)
		{
			pHead = pTail = temp;
		}
		else
		{
			temp->pNext = pHead;
			pHead = temp;
		}
	}
	void addTail(t value)
	{
		Node<t> *temp = new Node<t>(value);
		if (pHead == NULL)
		{
			pHead = pTail = temp;
		}
		else
		{
			pTail->pNext = temp;
			pTail = temp;
		}
	}
	void cSort()
	{
		Node<t> *n = pHead;
		while (n != NULL)
			{
			auto m = n;
			auto p = m->pNext;
			while (p != NULL)
				{
					if ((m->_value < p->_value))
					{
						swap(m->_value, p->_value);
					}
					m = p;
					p = p->pNext;
				}
			n = n->pNext;
			
		}
	}

	void bcde()
	{
		auto p = pHead;
		auto b = pHead;
		int sum = 0;
		while (p != NULL)
		{
			sum += p->_value.getLuong();
			cout << p->_value << "\n";
			
			if (b->_value.getLuong() < p->_value.getLuong())
			{
				b = p;
			}
			p = p->pNext;
		}
		string bans=b->_value.getTen() ;
		cSort();
		cout << bans<< "\n"
			 << sum << "\n"
			 <<pTail->_value;

	}
};
class NhanVien
{

private:
	string _maNV, _tenNV;
	int _luongNV;

public:
	friend istream &operator>>(istream &is, NhanVien &nv)
	{
		is >> nv._maNV;
		is.ignore();
		 getline(is,nv._tenNV );
		 is>> nv._luongNV;
		return is;
	}
	friend ostream &operator<<(ostream &os, NhanVien nv)
	{
		os << "{" << nv._maNV << ", " << nv._tenNV << ", " << nv._luongNV << "}";
		return os;
	}
	friend bool operator<(NhanVien x, NhanVien y)
	{
		return x._luongNV < y._luongNV;
	}
	int getLuong()
	{
		return _luongNV;
	}
	string getTen(){
		return _tenNV;
	}
};
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	LinkedList<NhanVien> ll;
	int n;
	cin >> n;
	for (int i = 0; i < n; ++i)
	{
		NhanVien nv;
		cin >> nv;
		
		ll.addTail(nv);
	}
	ll.bcde();

}
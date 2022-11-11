#pragma once

#include<iostream>
#include<string>
#include<vector>
using namespace std;

namespace myHash_base
{
	enum State
	{
		EMPTY,//��
		EXIST,//����
		DELETE//��ɾ��
	};

	template<typename K, typename V>
	struct HashElem
	{
		pair<K, V> _kv;
		State _st = EMPTY;

		HashElem()
		{}

		HashElem(const pair<K, V>& kv)
			:_kv(kv)
		{}
	};

	//��keyת��Ϊsize_t����
	template<typename K>
	struct HashToINT
	{
		size_t operator()(const K& key)
		{
			return (size_t)key;
		}
	};
	//��string���ͽ����ػ�
	template<>
	struct HashToINT<string>
	{
		//BKDR˼��
		size_t operator()(const string& key)
		{
			size_t res = 0;
			for (auto& ch : key)
			{
				res *= 131;
				res += ch;
			}

			return res;
		}
	};

	template<typename K, typename V, class ToINT = HashToINT<K> >
	class HashTable
	{
	public:
		bool insert(const pair<K, V>& kv)
		{
			if (find(kv.first))
			{
				return false;
			}

			//��������Ϊ0.7
			if (_tab.size() == 0 || 10 * _size / _tab.size() >= 7)
			{
				size_t newSize = _tab.size() == 0 ? 10 : _tab.size() * 2;

				HashTable<K, V, ToINT> newHT;
				newHT._tab.resize(newSize);

				//���ɱ�����ӳ��Ǩ�Ƶ��±�
				for (auto& e : _tab)
				{
					if (e._st == EXIST)
					{
						newHT.insert(e._kv);
					}
				}

				_tab.swap(newHT._tab);
			}

			//����̽��
			ToINT toint;
			size_t hashi = toint(kv.first) % _tab.size();
			//ֻ��״̬Ϊ���ڣ� �Ų�����ռ�ø�λ��
			while (_tab[hashi]._st == EXIST)
			{
				hashi++;
				hashi %= _tab.size();
			}
			//����λ��״̬
			_tab[hashi]._kv = kv;
			_tab[hashi]._st = EXIST;
			++_size;

			////����̽��
			//ToINT toint;
			//size_t start = toint(kv.first) % _tab.size();
			//size_t hashi = start;
			//int i = 0;
			////ֻ��״̬Ϊ���ڣ� �Ų�����ռ�ø�λ��
			//while (_tab[hashi]._st == EXIST)
			//{
			//	++i;
			//	hashi = start + i * i;
			//	hashi %= _tab.size();
			//	
			//}
			////����λ��״̬
			//_tab[hashi]._kv = kv;
			//_tab[hashi]._st = EXIST;
			//++_size;
			

			return true;

		}

		HashElem<K, V>* find(const K& key)
		{
			if (_tab.size() == 0)
			{
				return (HashElem<K, V>*)(nullptr);
			}

			ToINT toint;

			size_t start = toint(key) % _tab.size();
			size_t hashi = start;
			int i = 0;

			//��ĳλ��Ϊ��ʱ�� ��һ��������
			while (_tab[hashi]._st != EMPTY)
			{
				//1. ��ǰλ��Ϊɾ��״̬����key�����������
				//2. ��ǰλ�ò�Ϊkey�� ��key�����������
				//3. ֻ��״̬Ϊ���ڣ� ��ֵΪkey���Ǵ���
				if (_tab[hashi]._st != DELETE && _tab[hashi]._kv.first == key)
				{
					return (HashElem<K, V>*)(&_tab[hashi]);
				}

				//����̽��
				hashi ++;
				hashi %= _tab.size();
				//����ȫΪɾ��̬�Ŀ���
				if (hashi == start)
				{
					break;//����
				}

				////����̽��
				//++i;
				//hashi = start + i * i;
				//hashi %= _tab.size();
				////����ȫΪɾ��̬�Ŀ���
				//if (hashi == start)
				//{
				//	break;//����
				//}
			}

			return (HashElem<K, V>*)(nullptr);
		}

		bool erase(const K& key)
		{
			HashElem<K, V>* ret = find(key);

			if (ret)
			{
				ret->_st = DELETE;
				--_size;
				return true;
			}
			else
			{
				return false;
			}
		}

		void Print()
		{
			for (size_t i = 0; i < _tab.size(); ++i)
			{
				if (_tab[i]._st == EXIST)
				{
					printf("[%d:%d] ", i, _tab[i]._kv.first);
				}
				else
				{
					printf("[%d:*] ", i);
				}
			}
			cout << endl;
		}
	private:
		vector<HashElem<K, V>> _tab;
		size_t _size = 0;
	};

	void TestHT1()
	{
		//int a[] = { 1, 11, 4, 15, 26, 7, 44, 9 };
		int a[] = { 1, 11, 4, 15, 26, 7, 44 };
		HashTable<int, int> ht;
		for (auto e : a)
		{
			ht.insert(make_pair(e, e));
		}

		ht.Print();

		ht.erase(4);
		cout << ht.find(44)->_kv.first << endl;
		cout << ht.find(4) << endl;
		ht.Print();

		ht.insert(make_pair(-2, -2));
		ht.Print();

		cout << ht.find(-2)->_kv.first << endl;
	}
	void TestHT2()
	{
		string arr[] = { "ƻ��", "����", "ƻ��", "����", "ƻ��", "ƻ��", "����", "ƻ��", "�㽶", "ƻ��", "�㽶" };

		//HashTable<string, int, HashFuncString> countHT;
		HashTable<string, int> countHT;
		for (auto& str : arr)
		{
			auto ptr = countHT.find(str);
			if (ptr)
			{
				ptr->_kv.second++;
			}
			else
			{
				countHT.insert(make_pair(str, 1));
			}
		}
	}
	void TestHT3()
	{
		HashToINT<string> hash;
		cout << hash("abcd") << endl;
		cout << hash("bcad") << endl;
		cout << hash("eat") << endl;
		cout << hash("ate") << endl;
		cout << hash("abcd") << endl;
		cout << hash("aadd") << endl << endl;

		cout << hash("abcd") << endl;
		cout << hash("bcad") << endl;
		cout << hash("eat") << endl;
		cout << hash("ate") << endl;
		cout << hash("abcd") << endl;
		cout << hash("aadd") << endl << endl;
	}

}

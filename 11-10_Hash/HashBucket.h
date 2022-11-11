#pragma once

#include<iostream>
#include<string>
#include<vector>
using namespace std;

namespace myHash_bucket
{

	template<typename K, typename V>
	struct HashNode
	{
		pair<K, V> _kv;
		HashNode<K, V>* _next;

		HashNode()
		{}

		HashNode(const pair<K, V>& kv)
			:_kv(kv)
			, _next(nullptr)
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
		typedef HashNode<K, V> Node;
	public:

		//������������Ϊ�������� ������Ч����ģ��ȣ�����Ͱ����������
		inline size_t __stl_next_prime(size_t n)
		{
			static const size_t __stl_num_primes = 28;
			static const size_t __stl_prime_list[__stl_num_primes] =
			{
				53, 97, 193, 389, 769,
				1543, 3079, 6151, 12289, 24593,
				49157, 98317, 196613, 393241, 786433,
				1572869, 3145739, 6291469, 12582917, 25165843,
				50331653, 100663319, 201326611, 402653189, 805306457,
				1610612741, 3221225473, 4294967291
			};

			for (size_t i = 0; i < __stl_num_primes; ++i)
			{
				if (__stl_prime_list[i] > n)
				{
					return __stl_prime_list[i];
				}
			}

			return -1;
		}


		bool insert(const pair<K, V>& kv)
		{
			if (find(kv.first))
			{
				return false;
			}

			//��������Ϊ1,��ʾͰ���ˣ� ��Ҫ����
			if (_size == _tab.size())
			{	
				//��ɢ�й�ϣ�� ����ʱ��Ҫ����insert�� ���Դ���һ����ʱ��ϣ��
				//����ɢ�й�ϣ�� �����ݽڵ���Խ��и��ã�����Ҫ����insert������ֻ�贴��һ����ʱvector
				vector<Node*> newTab;
				newTab.resize(__stl_next_prime(_tab.size()), nullptr);

				//���ɱ�����ӳ��Ǩ�Ƶ��±�
				for (auto& cur : _tab)
				{
					if (cur == nullptr) continue;

					Node* old = cur;

					while (cur)
					{
						Node* next = cur->_next;

						//ͷ��
						size_t hashi = cur->_kv.first % newTab.size();
						cur->_next = newTab[hashi];
						newTab[hashi] = cur;

						cur = next;
					}
					
					//�ÿ�
					old = nullptr;
				}

				_tab.swap(newTab);
			}

			//ͷ��
			ToINT toint;
			size_t hashi = toint(kv.first) % _tab.size();
			Node* newNode = new Node(kv);
			newNode->_next = _tab[hashi];
			_tab[hashi] = newNode;
			++_size;

			return true;

		}

		Node* find(const K& key)
		{
			if (_tab.size() == 0)
			{
				return (Node*)(nullptr);
			}

			ToINT toint;
			size_t hashi = toint(key) % _tab.size();
			Node* cur = _tab[hashi];
			while(cur)
			{
				if (cur->_kv.first == key)
				{
					return cur;
				}
				
				cur = cur->_next;
			}

			

			return (Node*)(nullptr);
		}

		bool erase(const K& key)
		{
			if (_tab.size() == 0)
			{
				return (Node*)(nullptr);
			}

			ToINT toint;
			size_t hashi = toint(key) % _tab.size();
			Node* prev = nullptr;
			Node* cur = _tab[hashi];
			while (cur)
			{
				if (cur->_kv.first == key)
				{
					break;
				}

				prev = cur;
				cur = cur->_next;
			}

			//������
			if (cur == nullptr)
			{
				return false;
			}
			else if(prev == nullptr)//Ϊ��һ��
			{
				_tab[hashi] = cur->_next;
				free(cur);
				cur = nullptr;
			}
			else
			{
				prev->_next = cur->_next;
				free(cur);
				cur = nullptr;
			}

			return true;
		}

		void Print()
		{
			int i = 0;
			for (auto cur : _tab)
			{
				if (cur == nullptr)
				{
					++i;
					continue;
				}

				while (cur)
				{
					printf("[%d : %d] ", i, cur->_kv.first);
					cur = cur->_next;
				}
				++i;
			}
		}
	private:
		vector<Node*> _tab;
		size_t _size = 0;
	};

	void TestHT1()
	{
		int a[] = { 1, 11, 4, 15, 26, 7, 44,55,99,78 };
		HashTable<int, int> ht;
		for (auto e : a)
		{
			ht.insert(make_pair(e, e));
		}

		ht.insert(make_pair(22, 22));
	}
	void TestHT2()
	{
		int a[] = { 1, 11, 4, 15, 26, 7, 44,55,99,78 };
		HashTable<int, int> ht;
		for (auto e : a)
		{
			ht.insert(make_pair(e, e));
		}
		ht.Print();
	}
	void TestHT3()
	{
		int a[] = { 1, 11, 4, 15, 26, 7, 44,55,99,78 };
		HashTable<int, int> ht;
		for (auto e : a)
		{
			ht.insert(make_pair(e, e));
		}

		ht.erase(8);
		ht.erase(4);
		ht.Print();

	}

}


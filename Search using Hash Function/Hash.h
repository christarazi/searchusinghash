#ifndef Hashing
#define Hashing
#include <string>

using namespace std;

template <int n>
class Hash
{
	private:
			struct Node
			{
				int info;
				Node *next;
			};
			Node *H[n];

	public:
			Hash()
			{
				for(int i = 0; i < n; i++)
				{
					H[i] = NULL;
				}
			}
			int HashFunction(int x)
			{
				return x % n;
			}
			void Insert(int x)
			{
				int i = HashFunction(x);
				Node *p = new Node;
				p->info = x;
				p->next = H[i];
				H[i] = p;
			}
			void DisplayTable()
			{
				for(int i = 0; i < n; i++)
				{
					cout << "H[" << i << "] -> ";
					Node *p = H[i];
					while(p != NULL)
					{
						cout << p->info << " -> "; p = p->next;
					}

					cout << "NULL" << endl;
				}
			}
			void Search(string str, int total)
			{	
				bool exists = false;

				for(int i = 0; i < 7; i++)
				{
					Node *p = H[i];
					while(p != NULL)
					{
						if(p->info == total)
						{
							exists = true;
							break;
						}
						else
						{
							p = p->next;
						}
					}
				}

				if(exists)
				{
					cout << "Yes, this name exists in the database." << endl;
				}
				else
				{
					cout << "No, this name doesn't exist in the database." << endl;
				}

			}
};
#endif
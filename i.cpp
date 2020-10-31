/* C++ Program to implement Heap Sort */
/* Aman Singh, 3206 */

#include <iostream>
#include <ctime>

using namespace std;

void swap(int& x, int& y)
{
	int temp = x;
	x = y;
	y = temp;
}

class Heap
{
public:
	Heap();
	Heap(int);
	~Heap();
	void heapUpWrapper();
	void heapDownWrapper();
	void insert(int);
	void del(int&);
	void heapSort();

private:
	int *H; //Array
	int sz; //Size
	int li; //Last index
	int hs; //heap Sort

	void heapUp(int);
	void heapDown(int);
};


Heap::Heap()
{
	sz = 15;
	H = new int[sz];
	li = -1;
	hs = sz;
}

Heap::Heap(int s)
{
	sz = s;
	H = new int[sz];
	li = -1;
	hs = sz;
}

Heap::~Heap()
{
}

void Heap::heapUp(int index)
{
	int parent = (index - 1) / 2;

	if (parent>0 && H[parent] < H[index]) {
		swap(H[parent], H[index]);
		heapUp(parent);
	}
}

void Heap::heapDown(int root)
{
	int maxi;
	int lefti = (2 * root) + 1;

	if (lefti > li) return;

	int righti = (2 * root) + 2;
	if (righti > li) maxi = li;
	else maxi = H[lefti] > H[righti] ? lefti : righti;

	if (H[maxi] > H[root])
	{
		swap(H[root], H[maxi]);
		heapDown(maxi);
	}
}

void Heap::heapUpWrapper()
{
	heapUp(li);
}

void Heap::heapDownWrapper()
{
	heapDown(0);
}

void Heap::insert(int v)
{
	li++;
	H[li] = v;
}

void Heap::del(int& v)
{
	v = H[0];
	H[0] = H[li];
	li--;
}

void Heap::heapSort()
{
	if (hs > 0)
	{
		swap(H[0], H[li]);
		hs--;
		heapDownWrapper();
		heapSort();
	}
}

class PriorityQ
{
public:
	PriorityQ() :PQ() {}
	PriorityQ(int s) :PQ(s) {}
	void enQ(int);
	void dQ(int&);
	void hs();

private:
	Heap PQ;
};

void PriorityQ::enQ(int v)
{
	PQ.insert(v);
	PQ.heapUpWrapper();
}
void PriorityQ::dQ(int& v)
{
	PQ.del(v);
	PQ.heapDownWrapper();
}

void PriorityQ::hs()
{
	PQ.heapSort();
}

int main()
{   
	int s;
	cin>>s;
	PriorityQ Q1(s);

	srand(time(NULL));

	cout << "Unsorted:" << endl;

	for (int i = 0; i < s; i++)
	{
		int temp;
		cin>>temp;
		cout<<temp<<" ";

		Q1.enQ(temp);
	}

	Q1.hs();
	cout << endl << endl;
	cout << "Sorted (Max to Min):" << endl;

	int d;
	for (int j = 0; j < s; j++)
	{
		Q1.dQ(d);
		cout << d << " ";
	}

	cout << endl << endl;

	return 0;
}

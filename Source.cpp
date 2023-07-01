#include <vector>

class DisjointSetSystem
{
private:
	std::vector<int> p;
	std::vector<int> r;

public:
	DisjointSetSystem(int size);
	~DisjointSetSystem();

	int getRoot(int v);
	bool merge(int a, int b);
};


DisjointSetSystem::DisjointSetSystem(int size)
{
	p.resize(size);
	for (int i = 0; i < size; ++i)
	{
		r.resize(size, 1);
	}
}
	
	DisjointSetSystem::~DisjointSetSystem()
	{
		p.clear();
		r.clear();
	}

	int DisjointSetSystem::getRoot(int v)
	{
		if (p[v] == v)
			return v;
		return p[v] = getRoot(p[v]);
	}

	bool DisjointSetSystem::merge(int a, int b)
	{
	int roota =getRoot(a);
	int rootb = getRoot(b);
	if (roota == rootb)
		return false;
	if (r[roota] > r[rootb])
		p[rootb] = roota;
	else
  	{
		if (r[roota] < r[rootb])
			p[roota] = rootb;
		else
		{
			p[rootb] = roota;
			r[roota]++;
		}
	}
    }




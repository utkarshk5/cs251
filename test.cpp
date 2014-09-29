#include <iostream>
#include <map>
#include <set>
#include <vector>
using namespace std;

class Sequence{
	public:
	vector<int> seq;
	map<int, set<int> > mp;

	Sequence(vector<int> const & v){
		for(int i=0; i<v.size(); i++){
			seq.push_back(v[i]);
			mp[v[i]].insert(i);
		}
	}

	void operator()(int index, int x){
		mp[seq[index]].erase(index);
		seq[index]=x;
		mp[x].insert(index);
	}

	bool is_subsequence(vector<int> const & q){
		int ind=-1;
		set<int>::iterator tmp;
		map<int, set<int> >::iterator iter;
		for(int i=0; i<q.size(); i++){
			iter=mp.find(q[i]);
			if(iter==mp.end()) return false;
			tmp=(*iter).second.upper_bound(ind);
			if(tmp==(*iter).second.end()) return false;
			ind=*tmp;
		}
		return true;
	}
};

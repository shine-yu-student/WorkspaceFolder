#include "lib/diy_search.hpp"
using namespace diy;
using namespace std;
int main(){
	freopen("test/main.in","r",stdin);
	freopen("test/main.out","w",stdout);
	int n,t;
	cin>>n;
	vector<int> v(n);
	for(auto &i:v)cin>>i;
	cin>>t;
	cout<<linearSearch(v,t);
}
#include<iostream>
using std::cout;
using std::cerr;
namespace diy{
	template<typename _Tp>
	class SingleLinkedElement{
		private:
		_Tp _val;
		SingleLinkedElement* _next;
		SingleLinkedElement(){}
		SingleLinkedElement(_Tp val,SingleLinkedElement next=nullptr):_val(val),_next(next){}
	};
	template<typename _Tp>
	class SingleLinkedList{
		SingleLinkedElement<_Tp> *_dummy=new SingleLinkedElement<_Tp>();
		SingleLinkedList(){}
		SingleLinkedList(std::vector<_Tp> v){
			SingleLinkedElement<_Tp> *p=_dummy;
			for(auto &i:v){
				p->_next=new SingleLinkedElement<_Tp>(i);
				p=p->next;
			}
		}
	};
	#undef _SLE
}
#include<iostream>
#include<algorithm>
using std::cout;
using std::clog;
using std::sort;
namespace diy{
	template<typename _Tp>
	class stack{
		private:
		size_t __max_size;
		_Tp* __st;
		size_t __tpos=0;
		public:
		stack():__max_size(1e3){
			__st=new _Tp[__max_size+1];
		}
		stack(size_t _mx_s):__max_size(_mx_s){
			__st=new _Tp[__max_size+1];
		}
		stack(const stack<_Tp>& _tmp):__max_size(_tmp.__max_size*2){
			__st=new _Tp[__max_size+1];
			__tpos=0;
			while(!_tmp.empty()){
				this->push(_tmp.top());
				_tmp.pop();
			}
		}
		~stack(){
			delete[] __st;
			__st=nullptr;
		}
		void push(const _Tp &tmp){
			if(__tpos==__max_size){
				clog<<"[Overflow] The stack is full now."<<'\n';
				return;
			}
			__tpos++,__st[__tpos]=tmp;
		}
		void push(_Tp &&tmp){
			if(__tpos==__max_size){
				clog<<"[Overflow] The stack is full now."<<'\n';
				return;
			}
			__tpos++,__st[__tpos]=tmp;
		}
		void sort(){
			sort(__st,__st+__max_size);
		}
		void pop(){
			if(!__tpos){
				clog<<"[underflow] The stack is empty now."<<'\n';
				return;
			}
			__tpos--;
		}
		_Tp top(){
			return __st[__tpos];
		}
		size_t size(){
			return __tpos;
		}
		bool empty(){
			return !__tpos;
		};
		void alloc(size_t _size):__max_size(_size){
			delete[] __st;
			__st=new _Tp[__max_size+1];
		}
	};
}

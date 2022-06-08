#include<iostream>
#include<climits>
using namespace std;
namespace diy{
	template<typename _Tp>
	class queue{
	private:
		size_t __max_size,__cur_size=0;
		_Tp* __arr;
    bool* __subp;
		size_t __lpos,__rpos;
	public:
		queue():__max_size(1e3+10){
			__arr=new _Tp[__max_size];
			__subp=new bool[__max_size];
			__lpos=__rpos=0;
		}
		queue(size_t _mxs):__max_size(_mxs){
			__arr=new _Tp[__max_size];
			__subp=new bool[__max_size];
			__lpos=__rpos=0;
		}
		void push(const _Tp& _val){
      if(__cur_size==__max_size){
        clog<<"[Overflow] Full of element in queue";
      }
      __cur_size++;
			__rpos++;
      __rpos%=__max_size;
			__arr[__rpos]=_val;
			__subp[__rpos]=true;
		}
		void push(_Tp&& _val){
      if(__cur_size==__max_size){
        clog<<"[Overflow] Full of element in queue";
      }
      __cur_size++;
			__rpos++;
      __rpos%=__max_size;
			__arr[__rpos]=_val;
			__subp[__rpos]=true;
		}
		void pop(){
      if(__cur_size==0){
        clog<<"[Underflow] Not enough element in queue";
        return;
      }
      __cur_size--;
			__lpos++;
      __lpos%=__max_size;
			__subp[__lpos]=false;
		}
    _Tp front(){
      if(__cur_size==0){
        clog<<"[EmptyQueue] Not enough element yet";
        return _Tp();
      }
      return __arr[(__lpos+1)%__max_size];
    }
    _Tp back(){
      if(__cur_size==0){
        clog<<"[EmptyQueue] Not enough element yet";
        return INT_MIN;
      }
      return __arr[__rpos];
    }
    size_t size(){
      return __cur_size;
    }
    bool empty(){
      return !__cur_size;
    }
    void alloc(size_t _mxs){
      delete[] __arr;
      delete[] __subp;
      __max_size=_mxs;
			__arr=new _Tp[__max_size];
			__subp=new bool[__max_size];
			__lpos=__rpos=0;
    	}
	};
}
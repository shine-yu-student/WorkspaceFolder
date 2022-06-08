#include<iostream>
#include<vector>
namespace diy{
	/**
	 * @brief It does what you think.
	 * 
	 * @tparam _Tp The type your sequence contains.
	 * @param list the list to find.
	 * @param val the value to find.
	 * @return An integer who represents the index start from 0, -1 if doesn't exists.
	 */
	template<typename _Tp>
	int linearSearch(std::vector<_Tp> list,_Tp val){
		size_t pos=0;
		for(auto &i:list){
			if(i==val)return pos;
			pos++;
		}
		return -1;
	}
	/**
	 * @brief It does the same thing of the linearSearch, but return a reference.
	 * 
	 * @return A reference to the target element.
	 */
	template<typename _Tp>
	_Tp& linearSearchReference(std::vector<_Tp> list,_Tp val){
		size_t pos=0;
		for(auto &i:list){
			if(i==val)return i;
			pos++;
		}
		return nullptr;
	}
	/**
	 * @brief It does what you think. The input sequence must be monotune increase.
	 * 
	 * @tparam _Tp  The type your sequence contains.
	 * @param list the list to find.
	 * @param val the value to find.
	 * @return An integer who represents the index start from 0, -1 if doesn't exists.
	 */
	template<typename _Tp>
	int binarySearch(std::vector<_Tp> list,_Tp val){
		size_t sz=list.size();
		size_t p1=0,p2=sz-1;
		while(p1<p2){
			size_t mid=(p1+p2)>>1;
			if(list[mid]==val)return mid;
			if(list[mid]<val)p1=mid;
			else p2=mid;
		}
		return -1;
	}
	/**
	 * @brief It does the same thing of the binarySearch, but return a reference.
	 * 
	 * @return A reference to the target element. 
	 */
	template<typename _Tp>
	_Tp& binarySearchReference(std::vector<_Tp> list,_Tp val){
		size_t sz=list.size();
		size_t p1=0,p2=sz-1;
		while(p1<p2){
			size_t mid=(p1+p2)>>1;
			if(list[mid]==val)return list[mid];
			if(list[mid]<val)p1=mid;
			else p2=mid;
		}
		return nullptr;
	}
}
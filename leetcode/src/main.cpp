#include <iostream>
#include "146_LRU_Cache.h"

using namespace std;



void test() {
	LRUCache* cache = new LRUCache(2);
	cache->put(2, 1);
	cache->put(1, 1);     
	cache->put(2, 3);   
	cache->put(4, 1);    
	cache->get(1);      
	cache->get(2);       
}




void main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	test();
}


/*
static const int _ = []() {
ios::sync_with_stdio(false);
cin.tie(nullptr);
return 0;
}();
*/
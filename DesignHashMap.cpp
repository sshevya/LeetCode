class MyHashMap {
public://Array implementation takes more time than linkedlist
    /** Initialize your data structure here. */
   /* class ListNode{
        int key,val;
        ListNode* next;
        ListNode(int k int v){
            key=k;
            val=v;
        }   
    }
    
    ListNode node[]=new ListNode[10000];
    */
    int map[1000001];    
    
    MyHashMap() {
        //map=new int[100001];
        memset(map,-1,sizeof(map));
        
    }
    
    /** value will always be non-negative. */
    void put(int key, int value) {
        map[key]=value;
        return;
    }
    
    /** Returns the value to which the specified key is mapped, or -1 if this map contains no mapping for the key */
    int get(int key) {
        return map[key];
    }
    
    /** Removes the mapping of the specified value key if this map contains a mapping for the key */
    void remove(int key) {
        map[key]=-1;
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */

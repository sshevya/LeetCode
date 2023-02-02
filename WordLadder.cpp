

/**** even after using hashmap you have to erase it else TLE****/
class Solution {
public:


    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        
        unordered_map<string,int> u;
        queue<pair<string,int>> q;
        for(int i=0;i<wordList.size();i++){
            u[wordList[i]]=1;
        }

        q.push(make_pair(beginWord,1));

        while(!q.empty()){
            pair<string,int> p = q.front();
            string front = p.first;
            int level = p.second;
            q.pop();

            if(front == endWord){
                
                return level;
            }


            //adjacent words

            for(int i=0;i<front.size();i++){
                char temp = front[i];
                for(char c ='a';c<='z';c++){
                    front[i]=c;
                    if(u.find(front)!=u.end()){
                        q.push(make_pair(front,level+1));
                        u.erase(front);
                    }
                }
                front[i]=temp;
            }


            

        }



    return 0;

    }
};

방법 1
class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
     int r_alpha[26] ={0}; int m_alpha[26] =  {0};
     for(int i=0;i<ransomNote.size();i++)
        r_alpha[ransomNote[i] - 'a']++;

     for(int i=0;i<magazine.size();i++)
        m_alpha[magazine[i] - 'a']++;
       
     for(int i=0;i <sizeof(r_alpha)/sizeof(int);i++){
         if(r_alpha[i] > m_alpha[i])
            return false;
     }
     return true;
    }
};

/* 
c++ 배열에는 size()함수 없가 없다. sizeof(배열이름)/sizeof(배열형)을 사용하자
내가 작성한 위 코드에서 메모리를 줄일 수 있을 것 같다. 다른 방법을 생각해보자
*/

//방법 1 향상
class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        int alpha[26] ={0};
        for(int i=0; i<magazine.size();i++)
            alpha[magazine[i]-'a']++;

        for(int i=0; i< ransomNote.size(); i++) {
            if(--alpha[ransomNote[i]-'a']<0) return false;
        }
     
         return true;
    }
};

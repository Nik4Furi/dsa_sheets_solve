/*
You are given two strings of equal lengths, s1 and s2. The task is to check if s2 is a rotated version of the string s1.

Note: The characters in the strings are in lowercase.

Example 1:

Input:
geeksforgeeks
forgeeksgeeks
Output: 
1
Explanation: s1 is geeksforgeeks, s2 is
forgeeksgeeks. Clearly, s2 is a rotated
version of s1 as s2 can be obtained by
left-rotating s1 by 5 units.
*/

//App-I: Use two queues, and insert both string on that, check upto q1 and q2 not equal pop element, tC O(n*k), sC o(2n)

//App-II: Concat one string two times, and find the second string postion, tC O(n), sC O(n)

public:
    //Function to check if two strings are rotations of each other or not.
    bool areRotations(string s1,string s2)
    {
        // Your code here
        string temp = s1+s1;
        
        return (temp.find(s2) != string::npos);
    }

//App-III: when all strings eles are unique, then my code is work, check first char position, than use two poisnter and compare both indexes values, tC O(n+k), sC O(1)
//Function to check if two strings are rotations of each other or not.
    bool areRotations(string s1,string s2)
    {
        // Your code here
       //base case
       int n = s1.size(),m=s2.size();
       if(n != m) return false;
       
       int k=-1;
       char ch = s2[0];
       bool isFound = false;
       
       //find first char of s1 in s2;
       for(int i=0;i<n;i++){
           if(s1[i] == ch){
               k = i;
               isFound = true;
               break;
           }
       }
       
       //Edge case, when didn't finding the char
       if(!isFound) return false;
       
       if(k == 0) return s1 == s2; //check with same indexex
       
       
       //o/w check from different indexex
    //   cout << "here "<< k <<endl;
       int i=0;
       while(i <n){
           if(s1[k%n] != s2[i]) return false;
           i++,k++;
       }
       return true;
       
       
    }
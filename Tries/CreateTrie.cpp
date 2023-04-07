/*
Implementation of Trie that has the functionality of inserting a word , searching for a word, searching for a prefix exists in the trie or not.
*/
#include<bits/stdc++.h>
using namespace std;
/*
Every Trie has an array of links of same type and a flag that keeps track of a particular word exists in the trie or not 
*/
struct Node 
{
  Node *links[26];
  bool flag=false;
  bool containsKey(char ch)
  {
    return links[ch-'a']!=NULL;
  }
  void putKey(char ch,Node *node)
  {
    links[ch-'a']=node;
  }
  Node *getKey(char ch)
  {
    return links[ch-'a'];
  }
  void setFlag()
  {
    flag=true;
  }
  bool getFlag()
  {
    return flag;
  }
};
/*
Trie class having the required Functions 
*/
class Trie
{
private:
struct Node *root;
public:
Trie()
{
    root=new Node();
}
void insertWord(string word)
{
    Node *node=root;
    int n=word.size();
    for(int i=0;i<n;i++)
    {
        if(!node->containsKey(word[i]))
        {
            node->putKey(word[i],new Node());
        }
        node=node->getKey(word[i]);
    }
    node->setFlag();
}
bool searchWord(string word)
{
    Node *node=root;
    int n=word.size();
    for(int i=0;i<n;i++)
    {
        if(!node->containsKey(word[i]))
        {
            return false;
        }
        node=node->getKey(word[i]);
    }
    return node->getFlag();
}
bool searchPrefix(string prefix)
{
    int n=prefix.size();
    Node *node=root;
    for(int i=0;i<n;i++)
    {
        if(!node->containsKey(prefix[i]))
        {
            return false;
        }
        node=node->getKey(prefix[i]);
    }
    return true;
}
};
int main()
{
    Trie *trie=new Trie();
    vector<string>v={"apple","app","appl","bat","bad","cat","cold"};
    for(auto it:v)
    {
        trie->insertWord(it);
    }
    string s="apple";
    cout<<trie->searchWord(s)<<endl;
    cout<<trie->searchPrefix("ba");
    return 0;
}
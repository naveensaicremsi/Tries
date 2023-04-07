#include<bits/stdc++.h>
using namespace std;
struct Node
{
    Node *links[26];
    bool flag=false;
    int prefixCount=0;
    int endCount=0;
    bool containsKey(char ch)
    {
        return links[ch-'a']!=NULL;
    }
    void putKey(char ch, Node *node)
    {
        links[ch-'a'] = node;
    }
    Node *getKey(char ch)
    {
        return links[ch-'a'];
    }
    bool getFlag()
    {
        return flag;
    }
    void setFlag()
    {
        flag=true;
    }
    void incrementPrefixCount()
    {
        prefixCount++;
    }
    int getPrefixCount()
    {
        return prefixCount;
    }
    void incrementEndCount()
    {
        endCount++;
    }
    int getEndCount()
    {
        return endCount;
    }
};
class Trie{
    private:
    Node *root;
    public:
    Trie()
    {
        root=new Node();
    }
    void insert(string word)
    {
        Node *node = root;
        int n=word.size();
        for(int i=0;i<n;i++)
        {
            if(!node->containsKey(word[i]))
            {
                node->putKey(word[i],new Node());
            }
            node=node->getKey(word[i]);
            node->incrementPrefixCount();
        }
        node->setFlag();
        node->incrementEndCount();
    }
    bool searchWord(string word)
    {
        Node *node= root;
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
        Node *node=root;
        int n=prefix.size();
        for(int i=0;i<n;i++)
        {
            if(!node->containsKey(prefix[i]))
            {
                return false;
            }
        }
        return true;
    }
    int countWords(string word)
    {
        Node *node=root;
        int n=word.size();
        for(int i=0;i<n;i++)
        {
            if(!node->containsKey(word[i]))
            {
                return 0;
            }
            node=node->getKey(word[i]);
        }
        return node->getEndCount();
    }
    int countPrefixes(string prefix)
    {
        Node *node=root;
        int n=prefix.size();
        for(int i=0;i<n;i++)
        {
            if(!node->containsKey(prefix[i]))
            {
                return 0;
            }
            node=node->getKey(prefix[i]);
        }
        return node->getPrefixCount();
    }
};
int main()
{
    Trie *trie=new Trie();
    vector<string> words={"apple","apple","bat","bad","bat","app","bombay"};
    for(auto it:words)
    {
        trie->insert(it);
    }
    cout<<trie->countPrefixes("ap")<<endl;
    cout<<trie->countWords("apple")<<endl;
    cout<<trie->countPrefixes("bo")<<endl;
    cout<<trie->searchWord("apple")<<endl;
    trie->searchPrefix("Naveen")==0?cout<<"False":cout<<"True";
    return 0;
}

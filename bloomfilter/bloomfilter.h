#ifndef BLOOMFILTER_H
#define BLOOMFILTER_H
#include<vector>
#include<string>
using namespace std;
class BloomFilter
{
public:
    BloomFilter(int cap);
public:
    bool IsIn(string str);
    void Insert(string str);
public:
    char* m_bitmap;
    int m_cap;
    int m_hashnum;
    vector<int> m_vecSeed;
    int hashfunc(string str,int seed);
};

#endif // BLOOMFILTER_H

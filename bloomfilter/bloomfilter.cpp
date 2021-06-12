#include "bloomfilter.h"

BloomFilter::BloomFilter(int cap)
{
    m_bitmap=new char[cap];
    m_cap=cap*8;
    m_vecSeed={ 5, 7, 11, 13, 31, 37, 61 };
    m_hashnum=m_vecSeed.size();
}

bool BloomFilter::IsIn(string str)
{
    vector<int> bitvec(m_hashnum);
    for(int i=0;i<m_hashnum;i++)
    {
        bitvec[i]=hashfunc(str,m_vecSeed[i]);
    }

    for(int i=0;i<m_hashnum;i++)
    {
        char c=m_bitmap[bitvec[i]/8];
        int index=1<<bitvec[i]%8;
        if(!(index & c)) return false;
    }
    return true;
}

void BloomFilter::Insert(string str)
{
    vector<int> bitvec(m_hashnum);
    for(int i=0;i<m_hashnum;i++)
    {
        bitvec[i]=hashfunc(str,m_vecSeed[i]);
    }

    for(int i=0;i<m_hashnum;i++)
    {
        m_bitmap[bitvec[i]/8] = m_bitmap[bitvec[i]/8] | 1<<bitvec[i]%8;
    }
}

int BloomFilter::hashfunc(string str,int seed)
{
    int res=0;
    for(auto c:str)
    {
        res=res*seed+c;
    }
    return (m_cap-1)&res /*res%m_cap*/;
}

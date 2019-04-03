#include <iostream>
#include "RationalSet.h"
using namespace std;

RationalSet::RationalSet()
{
    mSize = 0;
}
void RationalSet::add(const Rational & cItem)
{
    if (MAX_SIZE > mSize && !contains(cItem))
    {
        mSetArray[mSize] = cItem;
        mSize++;
    }
}
void RationalSet::print(ostream &out) const
{
    for (int i = 0; i < mSize; i++)
    {
        mSetArray[i].print(out);
        out << " ";
    }
    out << endl;
}
bool RationalSet::contains(const Rational & cItem) const
{
    bool bResult = false;
    for (int i = 0; i < mSize; i++)
    {
        if (mSetArray[i].equals(cItem) == true)
        {
            bResult = true;
        }
    }
    return bResult;
}
RationalSet RationalSet::set_union(const RationalSet & cOtherSet) const
{
    RationalSet cNewSet;

    for (int i = 0; i < cOtherSet.mSize; i++)
    {
        cNewSet.add(cOtherSet.mSetArray[i]);
    }
    for (int k = 0; k < mSize; k++)
    {
        cNewSet.add(mSetArray[k]);
    }
    return cNewSet;
}

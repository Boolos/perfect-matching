// =============================
// Include Guard
#ifndef __EDGESET_H_INCLUDED__
#define __EDGESET_H_INCLUDED__

// =============================
// Class definition
class EdgeSet
{
public:
    int getRank();
    EdgeSet* unionSet(EdgeSet& set);
    EdgeSet* difference(EdgeSet& set);
};
#endif
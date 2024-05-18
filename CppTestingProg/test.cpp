#include <bits/stdc++.h>
using namespace std;

struct TT {
    int time{ 999 };
};

TT g_tt;

class Test {
public:
    void Reg(TT *tt)
    {
        printf("tt: %#x\n", tt);
        m_t = tt;
    }
public:
    TT *m_t{ nullptr };
};

#define AA 1
#define BB 2

class JJ {
public:
    int RegAlmConditionItf(unsigned short almConditionId);
public:
    Test m_pumpFuncAbnormalAlm;
};

int JJ::RegAlmConditionItf(unsigned short almConditionId)
{
    static const struct PumpAlmInfo {
        unsigned short almConditionId;
        unsigned short almIdx;
        Test *almConditionItf;
    } pumpAlmCfg[] = {
        {AA, BB, &m_pumpFuncAbnormalAlm},
    };
    pumpAlmCfg[0].almConditionItf->Reg(&g_tt);

    return 1;
}

class C {
public:
    void Call();
};

void C::Call() {
    JJ j1;
    j1.RegAlmConditionItf(1);
    printf("%#x\n", j1.m_pumpFuncAbnormalAlm.m_t);
}

int main() {
    C *c1 = new C;
    C *c2 = new C;

    c1->Call();
    delete c1;
    c2->Call();

    printf("%#x\n", &g_tt);
    return 0;
}
#ifndef  EQUIP_LCTRL_CONCEPT_H
#define EQUIP_LCTRL_CONCEPT_H

#include "vos_typdef.h"

struct EquipCftParamsSt {
    VOS_UINT16 equipId;
    VOS_UINT16 sigId;
    VOS_FLOAT targetTemp;
    VOS_FLOAT dead;
    VOS_FLOAT scale;
};

struct CftParamsSt {
    VOS_FLOAT targetTemp;
    VOS_FLOAT dead;
    VOS_FLOAT scale;
};

class ActiveEquipLogicControl {
public:
private:
    VOS_FLOAT CalcCft(EquipCftParamsSt equipCftParamsSt, VOS_FLOAT currPoint);
    VOS_FLOAT ProcEev();
};

#endif

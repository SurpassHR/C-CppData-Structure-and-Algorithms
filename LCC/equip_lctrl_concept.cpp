#include "equip_lctrl_concept.h"
#include "emap_equip_manager.h"
#include "vos_typdef.h"

// EEV设备类型ID
const VOS_FLOAT LCC_EQUIP_TYPE_EEV = 0x0000;

const VOS_FLOAT REAL_EEV_CURR_TMEP = 0x0001;

const VOS_FLOAT SET_EEV_TARGET_TEMP = 0x0002;
const VOS_FLOAT SET_EEV_DEAD_AREA = 0x0003;
const VOS_FLOAT SET_EEV_SCALE_BAND = 0x0004;


VOS_FLOAT ActiveEquipLogicControl::CalcCft(EquipCftParamsSt equipCftParamsSt, VOS_FLOAT currPoint) {
    VOS_FLOAT cft;
    VOS_FLOAT targetTemp = equipCftParamsSt.targetTemp;
    VOS_FLOAT dead = equipCftParamsSt.dead;
    VOS_FLOAT scale = equipCftParamsSt.scale;

    if (currPoint > (targetTemp + dead)) {
        cft = (currPoint - (targetTemp + dead)) / scale;
    } else if (currPoint < (targetTemp - dead)) {
        cft = (currPoint - (targetTemp - dead)) / scale;
    }

    return cft;
}

VOS_FLOAT ActiveEquipLogicControl::ProcEev() {
    EquipCftParamsSt eevCftParamsSt;

    eevCftParamsSt.equipId = GetEquipTypeId();

    VOS_FLOAT currPoint = 0;
    GetSigValue_s(LCC_EQUIP_TYPE_EEV, REAL_EEV_CURR_TMEP, sizeof(currPoint),
        reinterpret_cast<VOS_CHAR*>(&currPoint));
    GetSigValue_s(LCC_EQUIP_TYPE_EEV, SET_EEV_TARGET_TEMP, sizeof(eevCftParamsSt.targetTemp),
        reinterpret_cast<VOS_CHAR*>(&eevCftParamsSt.targetTemp));
    GetSigValue_s(LCC_EQUIP_TYPE_EEV, SET_EEV_DEAD_AREA, sizeof(eevCftParamsSt.dead),
        reinterpret_cast<VOS_CHAR*>(&eevCftParamsSt.dead));
    GetSigValue_s(LCC_EQUIP_TYPE_EEV, SET_EEV_SCALE_BAND, sizeof(eevCftParamsSt.scale),
        reinterpret_cast<VOS_CHAR*>(&eevCftParamsSt.scale));

    return CalcCft(eevCftParamsSt, currPoint);
}

#include "reservoir_operation_rules.hpp"

#include <stdexcept>
#include <string>

// ---- Per-reservoir rule functions ---- 
// rule_{GDW_ID} - Define the operation rule for reservoir with GDW ID {GDW_ID}
// default as run-of-river (i.e., outflow = inflow) if no rule is defined for a reservoir

static float rule_487(float inflow_m3d, float storage_m3, int month) {
    const float max_inflow_m3d   = 29122946.4f;
    const float max_outflow_m3d  = 8591994.3f;
    const float max_storage_m3   = 144389935.3f;
    const float norm_inflow  = inflow_m3d  / max_inflow_m3d;
    const float norm_storage = storage_m3  / max_storage_m3;
    float norm_outflow;

    switch (month) {
        case  1: norm_outflow = 0.2968f * norm_inflow + 0.0130f; break;
        case  2: norm_outflow = 0.3987f * norm_inflow + 0.0127f; break;
        case  3: norm_outflow = 0.5164f * norm_inflow + 0.0309f; break;
        case  4: norm_outflow = 1.3922f * norm_inflow + 0.0214f; break;
        case  5: norm_outflow = 1.4587f * norm_inflow + 0.1187f; break;
        case  6: norm_outflow = 0.7867f * norm_inflow + 0.1681f; break;
        case  7: norm_outflow = 0.1031f * norm_inflow + 0.2278f; break;
        case  8: norm_outflow = 0.9174f * norm_inflow + 0.1690f; break;
        case  9: norm_outflow = 2.0999f * norm_inflow + 0.0341f; break;
        case 10: norm_outflow = 0.8789f * norm_inflow + 0.0190f; break;
        case 11: norm_outflow = 0.2486f * norm_inflow + 0.0135f; break;
        case 12: norm_outflow = 0.7621f * norm_inflow + 0.0124f; break;
    }
    return norm_outflow * max_outflow_m3d;
}

static float rule_488(float inflow_m3d, float storage_m3, int month) {
    const float max_inflow_m3d   = 2732335.8f;
    const float max_outflow_m3d  = 1605591.4f;
    const float max_storage_m3   = 97811263.6f;
    const float norm_inflow  = inflow_m3d  / max_inflow_m3d;
    const float norm_storage = storage_m3  / max_storage_m3;
    float norm_outflow;

    switch (month) {
        case  1: norm_outflow = 0.3534f * norm_inflow + 0.0160f; break;
        case  2: norm_outflow = 0.2893f * norm_inflow + 0.0136f; break;
        case  3: norm_outflow = 0.0000f * norm_inflow + 0.0095f; break;
        case  4: norm_outflow = 0.0000f * norm_inflow + 0.0316f; break;
        case  5: norm_outflow = 0.0000f * norm_inflow + 0.2375f; break;
        case  6: norm_outflow = 0.0000f * norm_inflow + 0.2516f; break;
        case  7: norm_outflow = 0.0000f * norm_inflow + 0.3720f; break;
        case  8: norm_outflow = 0.0000f * norm_inflow + 0.2808f; break;
        case  9: norm_outflow = 0.4667f * norm_inflow + 0.0678f; break;
        case 10: norm_outflow = 0.3774f * norm_inflow + 0.0287f; break;
        case 11: norm_outflow = 0.1934f * norm_inflow + 0.0145f; break;
        case 12: norm_outflow = 0.4640f * norm_inflow + 0.0192f; break;
    }
    return norm_outflow * max_outflow_m3d;
}

static float rule_493(float inflow_m3d, float storage_m3, int month) {
    const float max_inflow_m3d   = 46514715.6f;
    const float max_outflow_m3d  = 12959745.2f;
    const float max_storage_m3   = 1608282765.8f;
    const float norm_inflow  = inflow_m3d  / max_inflow_m3d;
    const float norm_storage = storage_m3  / max_storage_m3;
    float norm_outflow;

    switch (month) {
        case  1: norm_outflow = 0.9873f * norm_inflow + 0.0866f; break;
        case  2: norm_outflow = 0.5912f * norm_inflow + 0.0910f; break;
        case  3: norm_outflow = 0.2861f * norm_inflow + 0.1013f; break;
        case  4: norm_outflow = 1.0826f * norm_inflow + 0.0698f; break;
        case  5: norm_outflow = 0.7506f * norm_inflow + 0.0828f; break;
        case  6: norm_outflow = 0.8461f * norm_inflow + 0.1213f; break;
        case  7: norm_outflow = 2.4596f * norm_inflow + 0.1134f; break;
        case  8: norm_outflow = 4.1730f * norm_inflow + 0.1218f; break;
        case  9: norm_outflow = 5.1144f * norm_inflow + 0.1005f; break;
        case 10: norm_outflow = 0.2481f * norm_inflow + 0.1218f; break;
        case 11: norm_outflow = 0.2502f * norm_inflow + 0.0997f; break;
        case 12: norm_outflow = 0.6906f * norm_inflow + 0.0882f; break;
    }
    return norm_outflow * max_outflow_m3d;
}

static float rule_5560(float inflow_m3d, float storage_m3, int month) {
    const float max_inflow_m3d   = 7146881.1f;
    const float max_outflow_m3d  = 7543925.9f;
    const float max_storage_m3   = 37793827.2f;
    const float norm_inflow  = inflow_m3d  / max_inflow_m3d;
    const float norm_storage = storage_m3  / max_storage_m3;
    float norm_outflow;

    switch (month) {
        case  1: norm_outflow = 0.9471f * norm_inflow + -0.0110f; break;
        case  2: norm_outflow = 0.9485f * norm_inflow + -0.0107f; break;
        case  3: norm_outflow = 0.9645f * norm_inflow + 0.0008f; break;
        case  4: norm_outflow = 0.9071f * norm_inflow + 0.0072f; break;
        case  5: norm_outflow = 0.8174f * norm_inflow + -0.0190f; break;
        case  6: norm_outflow = 0.9361f * norm_inflow + -0.0235f; break;
        case  7: norm_outflow = 1.0238f * norm_inflow + 0.0277f; break;
        case  8: norm_outflow = 0.9659f * norm_inflow + 0.0200f; break;
        case  9: norm_outflow = 0.8976f * norm_inflow + 0.0395f; break;
        case 10: norm_outflow = 0.8849f * norm_inflow + 0.0175f; break;
        case 11: norm_outflow = 0.9246f * norm_inflow + -0.0147f; break;
        case 12: norm_outflow = 0.9442f * norm_inflow + -0.0132f; break;
    }
    return norm_outflow * max_outflow_m3d;
}

static float rule_104(float inflow_m3d, float storage_m3, int month) {
    const float max_inflow_m3d   = 383733386.6f;
    const float max_outflow_m3d  = 161229311.6f;
    const float max_storage_m3   = 23458275644.4f;
    const float norm_inflow  = inflow_m3d  / max_inflow_m3d;
    const float norm_storage = storage_m3  / max_storage_m3;
    float norm_outflow;

    switch (month) {
        case  1: norm_outflow = 0.2569f * norm_inflow + 0.1381f; break;
        case  2: norm_outflow = 0.4759f * norm_inflow + 0.1222f; break;
        case  3: norm_outflow = 0.0763f * norm_inflow + 0.0973f; break;
        case  4: norm_outflow = 0.3445f * norm_inflow + 0.0796f; break;
        case  5: norm_outflow = 0.2691f * norm_inflow + 0.1069f; break;
        case  6: norm_outflow = 0.9305f * norm_inflow + 0.0490f; break;
        case  7: norm_outflow = 0.6986f * norm_inflow + 0.1062f; break;
        case  8: norm_outflow = 0.2762f * norm_inflow + 0.1353f; break;
        case  9: norm_outflow = 0.2090f * norm_inflow + 0.1191f; break;
        case 10: norm_outflow = 0.7292f * norm_inflow + 0.0813f; break;
        case 11: norm_outflow = 1.4135f * norm_inflow + 0.0638f; break;
        case 12: norm_outflow = 0.2312f * norm_inflow + 0.1271f; break;
    }
    return norm_outflow * max_outflow_m3d;
}

static float rule_2194(float inflow_m3d, float storage_m3, int month) {
    const float max_inflow_m3d   = 13795851.6f;
    const float max_outflow_m3d  = 4477238.1f;
    const float max_storage_m3   = 59462370.4f;
    const float norm_inflow  = inflow_m3d  / max_inflow_m3d;
    const float norm_storage = storage_m3  / max_storage_m3;
    float norm_outflow;

    switch (month) {
        case  1: norm_outflow = 0.0000f * norm_inflow + 0.0003f; break;
        case  2: norm_outflow = 0.0000f * norm_inflow + 0.0003f; break;
        case  3: norm_outflow = 0.0000f * norm_inflow + 0.0003f; break;
        case  4: norm_outflow = 0.1645f * norm_inflow + 0.0007f; break;
        case  5: norm_outflow = 1.0477f * norm_inflow + 0.1663f; break;
        case  6: norm_outflow = 3.4960f * norm_inflow + -0.0226f; break;
        case  7: norm_outflow = 2.7489f * norm_inflow + 0.0996f; break;
        case  8: norm_outflow = 1.3966f * norm_inflow + 0.2177f; break;
        case  9: norm_outflow = 2.6713f * norm_inflow + 0.0735f; break;
        case 10: norm_outflow = 0.6228f * norm_inflow + 0.0016f; break;
        case 11: norm_outflow = 0.0000f * norm_inflow + 0.0003f; break;
        case 12: norm_outflow = 0.2420f * norm_inflow + 0.0005f; break;
    }
    return norm_outflow * max_outflow_m3d;
}

static float rule_2197(float inflow_m3d, float storage_m3, int month) {
    const float max_inflow_m3d   = 33963297.6f;
    const float max_outflow_m3d  = 25861995.0f;
    const float max_storage_m3   = 122205797.5f;
    const float norm_inflow  = inflow_m3d  / max_inflow_m3d;
    const float norm_storage = storage_m3  / max_storage_m3;
    float norm_outflow;

    switch (month) {
        case  1: norm_outflow = 1.1583f * norm_inflow + -0.0019f; break;
        case  2: norm_outflow = 0.8822f * norm_inflow + 0.0010f; break;
        case  3: norm_outflow = 0.5409f * norm_inflow + 0.0050f; break;
        case  4: norm_outflow = 0.7268f * norm_inflow + 0.0041f; break;
        case  5: norm_outflow = 0.9269f * norm_inflow + 0.0180f; break;
        case  6: norm_outflow = 1.1695f * norm_inflow + 0.0266f; break;
        case  7: norm_outflow = 0.7688f * norm_inflow + 0.0991f; break;
        case  8: norm_outflow = 2.1776f * norm_inflow + 0.0189f; break;
        case  9: norm_outflow = 1.9292f * norm_inflow + -0.0022f; break;
        case 10: norm_outflow = 0.6347f * norm_inflow + 0.0048f; break;
        case 11: norm_outflow = 0.3847f * norm_inflow + 0.0105f; break;
        case 12: norm_outflow = 1.2790f * norm_inflow + -0.0034f; break;
    }
    return norm_outflow * max_outflow_m3d;
}

static float rule_606(float inflow_m3d, float storage_m3, int month) {
    const float max_inflow_m3d   = 51392284.8f;
    const float max_outflow_m3d  = 37662110.6f;
    const float max_storage_m3   = 1536031674.8f;
    const float norm_inflow  = inflow_m3d  / max_inflow_m3d;
    const float norm_storage = storage_m3  / max_storage_m3;
    float norm_outflow;

    switch (month) {
        case  1: norm_outflow = 0.4634f * norm_inflow + 0.1205f; break;
        case  2: norm_outflow = 0.9846f * norm_inflow + 0.0677f; break;
        case  3: norm_outflow = 1.1798f * norm_inflow + 0.0392f; break;
        case  4: norm_outflow = 1.4069f * norm_inflow + 0.0139f; break;
        case  5: norm_outflow = 0.8109f * norm_inflow + 0.0503f; break;
        case  6: norm_outflow = 0.9970f * norm_inflow + -0.0072f; break;
        case  7: norm_outflow = 0.9959f * norm_inflow + 0.0979f; break;
        case  8: norm_outflow = 1.4141f * norm_inflow + 0.0379f; break;
        case  9: norm_outflow = 0.7182f * norm_inflow + 0.0837f; break;
        case 10: norm_outflow = 0.7989f * norm_inflow + 0.0672f; break;
        case 11: norm_outflow = 1.1662f * norm_inflow + 0.0400f; break;
        case 12: norm_outflow = 1.0099f * norm_inflow + 0.0724f; break;
    }
    return norm_outflow * max_outflow_m3d;
}

static float rule_624(float inflow_m3d, float storage_m3, int month) {
    const float max_inflow_m3d   = 6269667.7f;
    const float max_outflow_m3d  = 3762837.2f;
    const float max_storage_m3   = 281207536.9f;
    const float norm_inflow  = inflow_m3d  / max_inflow_m3d;
    const float norm_storage = storage_m3  / max_storage_m3;
    float norm_outflow;

    switch (month) {
        case  1: norm_outflow = 2.2403f * norm_inflow + -0.1171f; break;
        case  2: norm_outflow = 1.8113f * norm_inflow + -0.0835f; break;
        case  3: norm_outflow = 1.0342f * norm_inflow + -0.0278f; break;
        case  4: norm_outflow = 1.4504f * norm_inflow + -0.0539f; break;
        case  5: norm_outflow = 0.6062f * norm_inflow + 0.1750f; break;
        case  6: norm_outflow = 0.1228f * norm_inflow + 0.3317f; break;
        case  7: norm_outflow = 0.8431f * norm_inflow + 0.3392f; break;
        case  8: norm_outflow = 2.3168f * norm_inflow + 0.1126f; break;
        case  9: norm_outflow = 2.2023f * norm_inflow + -0.0365f; break;
        case 10: norm_outflow = 1.5070f * norm_inflow + -0.0753f; break;
        case 11: norm_outflow = 1.8886f * norm_inflow + -0.1317f; break;
        case 12: norm_outflow = 2.3167f * norm_inflow + -0.1380f; break;
    }
    return norm_outflow * max_outflow_m3d;
}

static float rule_642(float inflow_m3d, float storage_m3, int month) {
    const float max_inflow_m3d   = 4111547.6f;
    const float max_outflow_m3d  = 2101592.9f;
    const float max_storage_m3   = 103915756.1f;
    const float norm_inflow  = inflow_m3d  / max_inflow_m3d;
    const float norm_storage = storage_m3  / max_storage_m3;
    float norm_outflow;

    switch (month) {
        case  1: norm_outflow = 0.9205f * norm_inflow + -0.0053f; break;
        case  2: norm_outflow = 1.1159f * norm_inflow + -0.0143f; break;
        case  3: norm_outflow = 0.2012f * norm_inflow + 0.0086f; break;
        case  4: norm_outflow = 0.5009f * norm_inflow + -0.0172f; break;
        case  5: norm_outflow = 0.6157f * norm_inflow + 0.1622f; break;
        case  6: norm_outflow = 0.3795f * norm_inflow + 0.4988f; break;
        case  7: norm_outflow = 0.7909f * norm_inflow + 0.3110f; break;
        case  8: norm_outflow = 0.8980f * norm_inflow + 0.2208f; break;
        case  9: norm_outflow = 0.6704f * norm_inflow + 0.1247f; break;
        case 10: norm_outflow = 1.3413f * norm_inflow + -0.0096f; break;
        case 11: norm_outflow = 1.3125f * norm_inflow + -0.0227f; break;
        case 12: norm_outflow = 1.4308f * norm_inflow + -0.0147f; break;
    }
    return norm_outflow * max_outflow_m3d;
}

static float rule_651(float inflow_m3d, float storage_m3, int month) {
    const float max_inflow_m3d   = 40486336.1f;
    const float max_outflow_m3d  = 22486402.1f;
    const float max_storage_m3   = 797626141.6f;
    const float norm_inflow  = inflow_m3d  / max_inflow_m3d;
    const float norm_storage = storage_m3  / max_storage_m3;
    float norm_outflow;

    switch (month) {
        case  1: norm_outflow = 0.6287f * norm_inflow + 0.0204f; break;
        case  2: norm_outflow = 0.6183f * norm_inflow + 0.0239f; break;
        case  3: norm_outflow = 1.4531f * norm_inflow + 0.0147f; break;
        case  4: norm_outflow = 1.1546f * norm_inflow + 0.0693f; break;
        case  5: norm_outflow = 0.4620f * norm_inflow + 0.1611f; break;
        case  6: norm_outflow = 0.7218f * norm_inflow + 0.1172f; break;
        case  7: norm_outflow = 1.0415f * norm_inflow + 0.1347f; break;
        case  8: norm_outflow = 0.4916f * norm_inflow + 0.1799f; break;
        case  9: norm_outflow = 0.4298f * norm_inflow + 0.1484f; break;
        case 10: norm_outflow = 0.2229f * norm_inflow + 0.0686f; break;
        case 11: norm_outflow = 0.7002f * norm_inflow + 0.0206f; break;
        case 12: norm_outflow = 0.7682f * norm_inflow + 0.0201f; break;
    }
    return norm_outflow * max_outflow_m3d;
}

static float rule_5587(float inflow_m3d, float storage_m3, int month) {
    const float max_inflow_m3d   = 2037017.9f;
    const float max_outflow_m3d  = 922360.0f;
    const float max_storage_m3   = 9821522.8f;
    const float norm_inflow  = inflow_m3d  / max_inflow_m3d;
    const float norm_storage = storage_m3  / max_storage_m3;
    float norm_outflow;

    switch (month) {
        case  1: norm_outflow = 0.3613f * norm_inflow + 0.0040f; break;
        case  2: norm_outflow = 1.0712f * norm_inflow + 0.0023f; break;
        case  3: norm_outflow = 0.7401f * norm_inflow + 0.0042f; break;
        case  4: norm_outflow = 0.3889f * norm_inflow + 0.0180f; break;
        case  5: norm_outflow = 0.8223f * norm_inflow + 0.0557f; break;
        case  6: norm_outflow = 0.6908f * norm_inflow + 0.1284f; break;
        case  7: norm_outflow = 0.5936f * norm_inflow + 0.1171f; break;
        case  8: norm_outflow = 0.0000f * norm_inflow + 0.0830f; break;
        case  9: norm_outflow = 0.5967f * norm_inflow + 0.0286f; break;
        case 10: norm_outflow = 0.6415f * norm_inflow + 0.0183f; break;
        case 11: norm_outflow = 0.6773f * norm_inflow + 0.0102f; break;
        case 12: norm_outflow = 1.3309f * norm_inflow + 0.0036f; break;
    }
    return norm_outflow * max_outflow_m3d;
}

static float rule_694(float inflow_m3d, float storage_m3, int month) {
    const float max_inflow_m3d   = 49626808.9f;
    const float max_outflow_m3d  = 26149125.4f;
    const float max_storage_m3   = 1094259579.4f;
    const float norm_inflow  = inflow_m3d  / max_inflow_m3d;
    const float norm_storage = storage_m3  / max_storage_m3;
    float norm_outflow;

    switch (month) {
        case  1: norm_outflow = 0.8256f * norm_inflow + 0.0487f; break;
        case  2: norm_outflow = 0.4802f * norm_inflow + 0.0558f; break;
        case  3: norm_outflow = 1.1266f * norm_inflow + 0.0379f; break;
        case  4: norm_outflow = 1.6534f * norm_inflow + 0.0405f; break;
        case  5: norm_outflow = 0.7181f * norm_inflow + 0.1005f; break;
        case  6: norm_outflow = 0.8158f * norm_inflow + 0.1057f; break;
        case  7: norm_outflow = 1.0998f * norm_inflow + 0.1154f; break;
        case  8: norm_outflow = 1.5737f * norm_inflow + 0.0714f; break;
        case  9: norm_outflow = 0.8192f * norm_inflow + 0.0705f; break;
        case 10: norm_outflow = 0.1775f * norm_inflow + 0.0739f; break;
        case 11: norm_outflow = 0.9952f * norm_inflow + 0.0334f; break;
        case 12: norm_outflow = 0.6833f * norm_inflow + 0.0530f; break;
    }
    return norm_outflow * max_outflow_m3d;
}

static float rule_704(float inflow_m3d, float storage_m3, int month) {
    const float max_inflow_m3d   = 9105608.9f;
    const float max_outflow_m3d  = 7561452.9f;
    const float max_storage_m3   = 186891955.7f;
    const float norm_inflow  = inflow_m3d  / max_inflow_m3d;
    const float norm_storage = storage_m3  / max_storage_m3;
    float norm_outflow;

    switch (month) {
        case  1: norm_outflow = 0.5972f * norm_inflow + 0.0049f; break;
        case  2: norm_outflow = 0.2598f * norm_inflow + 0.0076f; break;
        case  3: norm_outflow = 0.0911f * norm_inflow + 0.0089f; break;
        case  4: norm_outflow = 0.0626f * norm_inflow + 0.0182f; break;
        case  5: norm_outflow = 0.0941f * norm_inflow + 0.0676f; break;
        case  6: norm_outflow = 0.5265f * norm_inflow + 0.0058f; break;
        case  7: norm_outflow = 0.5825f * norm_inflow + 0.1054f; break;
        case  8: norm_outflow = 0.0000f * norm_inflow + 0.2512f; break;
        case  9: norm_outflow = 0.2120f * norm_inflow + 0.1923f; break;
        case 10: norm_outflow = 0.7152f * norm_inflow + 0.0153f; break;
        case 11: norm_outflow = 0.1351f * norm_inflow + 0.0112f; break;
        case 12: norm_outflow = 0.3668f * norm_inflow + 0.0064f; break;
    }
    return norm_outflow * max_outflow_m3d;
}

static float rule_2483(float inflow_m3d, float storage_m3, int month) {
    const float max_inflow_m3d   = 5723040.6f;
    const float max_outflow_m3d  = 3009339.4f;
    const float max_storage_m3   = 46212328.2f;
    const float norm_inflow  = inflow_m3d  / max_inflow_m3d;
    const float norm_storage = storage_m3  / max_storage_m3;
    float norm_outflow;

    switch (month) {
        case  1: norm_outflow = 0.0000f * norm_inflow + 0.0004f; break;
        case  2: norm_outflow = 0.0000f * norm_inflow + 0.0005f; break;
        case  3: norm_outflow = 0.0419f * norm_inflow + 0.0004f; break;
        case  4: norm_outflow = 0.5774f * norm_inflow + 0.0419f; break;
        case  5: norm_outflow = 0.7625f * norm_inflow + 0.2169f; break;
        case  6: norm_outflow = 0.4958f * norm_inflow + 0.3330f; break;
        case  7: norm_outflow = 0.4912f * norm_inflow + 0.4513f; break;
        case  8: norm_outflow = 0.6925f * norm_inflow + 0.3208f; break;
        case  9: norm_outflow = 1.2561f * norm_inflow + 0.1475f; break;
        case 10: norm_outflow = 0.2135f * norm_inflow + 0.0131f; break;
        case 11: norm_outflow = 0.0009f * norm_inflow + 0.0004f; break;
        case 12: norm_outflow = 0.0000f * norm_inflow + 0.0004f; break;
    }
    return norm_outflow * max_outflow_m3d;
}

static float rule_2525(float inflow_m3d, float storage_m3, int month) {
    const float max_inflow_m3d   = 28434399.1f;
    const float max_outflow_m3d  = 21703503.7f;
    const float max_storage_m3   = 234059490.8f;
    const float norm_inflow  = inflow_m3d  / max_inflow_m3d;
    const float norm_storage = storage_m3  / max_storage_m3;
    float norm_outflow;

    switch (month) {
        case  1: norm_outflow = 0.7159f * norm_inflow + 0.0308f; break;
        case  2: norm_outflow = 0.7264f * norm_inflow + 0.0295f; break;
        case  3: norm_outflow = 1.1985f * norm_inflow + 0.0042f; break;
        case  4: norm_outflow = 1.1795f * norm_inflow + -0.0222f; break;
        case  5: norm_outflow = 1.2595f * norm_inflow + 0.0065f; break;
        case  6: norm_outflow = 1.2859f * norm_inflow + 0.0046f; break;
        case  7: norm_outflow = 1.2928f * norm_inflow + 0.0038f; break;
        case  8: norm_outflow = 1.2776f * norm_inflow + 0.0063f; break;
        case  9: norm_outflow = 1.2518f * norm_inflow + 0.0071f; break;
        case 10: norm_outflow = 0.9544f * norm_inflow + 0.0536f; break;
        case 11: norm_outflow = 0.8733f * norm_inflow + 0.0248f; break;
        case 12: norm_outflow = 0.7616f * norm_inflow + 0.0288f; break;
    }
    return norm_outflow * max_outflow_m3d;
}

static float rule_721(float inflow_m3d, float storage_m3, int month) {
    const float max_inflow_m3d   = 36139539.0f;
    const float max_outflow_m3d  = 21006320.2f;
    const float max_storage_m3   = 1348532847.0f;
    const float norm_inflow  = inflow_m3d  / max_inflow_m3d;
    const float norm_storage = storage_m3  / max_storage_m3;
    float norm_outflow;

    switch (month) {
        case  1: norm_outflow = 0.3692f * norm_inflow + 0.0440f; break;
        case  2: norm_outflow = 0.3067f * norm_inflow + 0.0456f; break;
        case  3: norm_outflow = 1.1166f * norm_inflow + 0.0186f; break;
        case  4: norm_outflow = 1.0499f * norm_inflow + 0.0518f; break;
        case  5: norm_outflow = 1.0030f * norm_inflow + 0.0519f; break;
        case  6: norm_outflow = 1.0006f * norm_inflow + 0.1111f; break;
        case  7: norm_outflow = 0.8110f * norm_inflow + 0.2225f; break;
        case  8: norm_outflow = 0.6151f * norm_inflow + 0.2122f; break;
        case  9: norm_outflow = 1.3256f * norm_inflow + 0.0630f; break;
        case 10: norm_outflow = 0.7809f * norm_inflow + -0.0077f; break;
        case 11: norm_outflow = 0.2112f * norm_inflow + 0.0530f; break;
        case 12: norm_outflow = 0.2804f * norm_inflow + 0.0486f; break;
    }
    return norm_outflow * max_outflow_m3d;
}

static float rule_727(float inflow_m3d, float storage_m3, int month) {
    const float max_inflow_m3d   = 46981863.9f;
    const float max_outflow_m3d  = 35759186.6f;
    const float max_storage_m3   = 1245053742.8f;
    const float norm_inflow  = inflow_m3d  / max_inflow_m3d;
    const float norm_storage = storage_m3  / max_storage_m3;
    float norm_outflow;

    switch (month) {
        case  1: norm_outflow = 0.0340f * norm_inflow + 0.0433f; break;
        case  2: norm_outflow = 0.6185f * norm_inflow + 0.0356f; break;
        case  3: norm_outflow = 0.5206f * norm_inflow + 0.0403f; break;
        case  4: norm_outflow = 0.8670f * norm_inflow + 0.0373f; break;
        case  5: norm_outflow = 0.4516f * norm_inflow + 0.0526f; break;
        case  6: norm_outflow = 0.5375f * norm_inflow + 0.0619f; break;
        case  7: norm_outflow = 0.7176f * norm_inflow + 0.0855f; break;
        case  8: norm_outflow = 0.6621f * norm_inflow + 0.0785f; break;
        case  9: norm_outflow = 0.0970f * norm_inflow + 0.0552f; break;
        case 10: norm_outflow = 0.0099f * norm_inflow + 0.0401f; break;
        case 11: norm_outflow = 0.1660f * norm_inflow + 0.0391f; break;
        case 12: norm_outflow = 0.0646f * norm_inflow + 0.0419f; break;
    }
    return norm_outflow * max_outflow_m3d;
}

static float rule_2768(float inflow_m3d, float storage_m3, int month) {
    const float max_inflow_m3d   = 3037415.2f;
    const float max_outflow_m3d  = 1739508.3f;
    const float max_storage_m3   = 52198406.6f;
    const float norm_inflow  = inflow_m3d  / max_inflow_m3d;
    const float norm_storage = storage_m3  / max_storage_m3;
    float norm_outflow;

    switch (month) {
        case  1: norm_outflow = 1.3863f * norm_inflow + 0.0369f; break;
        case  2: norm_outflow = 1.7900f * norm_inflow + 0.0411f; break;
        case  3: norm_outflow = 0.7540f * norm_inflow + 0.0703f; break;
        case  4: norm_outflow = 0.3427f * norm_inflow + 0.1171f; break;
        case  5: norm_outflow = 0.6566f * norm_inflow + 0.1070f; break;
        case  6: norm_outflow = 0.3763f * norm_inflow + 0.3650f; break;
        case  7: norm_outflow = 1.2476f * norm_inflow + 0.1371f; break;
        case  8: norm_outflow = 1.0137f * norm_inflow + 0.1446f; break;
        case  9: norm_outflow = 0.5562f * norm_inflow + 0.1235f; break;
        case 10: norm_outflow = 0.7021f * norm_inflow + 0.0747f; break;
        case 11: norm_outflow = 0.6279f * norm_inflow + 0.0784f; break;
        case 12: norm_outflow = 1.7705f * norm_inflow + 0.0459f; break;
    }
    return norm_outflow * max_outflow_m3d;
}

static float rule_5620(float inflow_m3d, float storage_m3, int month) {
    const float max_inflow_m3d   = 4734467.6f;
    const float max_outflow_m3d  = 4103482.1f;
    const float max_storage_m3   = 14098676.4f;
    const float norm_inflow  = inflow_m3d  / max_inflow_m3d;
    const float norm_storage = storage_m3  / max_storage_m3;
    float norm_outflow;

    switch (month) {
        case  1: norm_outflow = 0.3955f * norm_inflow + 0.0183f; break;
        case  2: norm_outflow = 0.3025f * norm_inflow + 0.0195f; break;
        case  3: norm_outflow = 0.3311f * norm_inflow + 0.0159f; break;
        case  4: norm_outflow = 0.4783f * norm_inflow + 0.0149f; break;
        case  5: norm_outflow = 0.5132f * norm_inflow + 0.0207f; break;
        case  6: norm_outflow = 0.9071f * norm_inflow + 0.0100f; break;
        case  7: norm_outflow = 0.8982f * norm_inflow + 0.0224f; break;
        case  8: norm_outflow = 0.8114f * norm_inflow + 0.0260f; break;
        case  9: norm_outflow = 0.7882f * norm_inflow + 0.0260f; break;
        case 10: norm_outflow = 0.3268f * norm_inflow + 0.0242f; break;
        case 11: norm_outflow = 0.4208f * norm_inflow + 0.0147f; break;
        case 12: norm_outflow = 0.2904f * norm_inflow + 0.0169f; break;
    }
    return norm_outflow * max_outflow_m3d;
}

static float rule_2800(float inflow_m3d, float storage_m3, int month) {
    const float max_inflow_m3d   = 9513478.3f;
    const float max_outflow_m3d  = 8196017.6f;
    const float max_storage_m3   = 70291091.3f;
    const float norm_inflow  = inflow_m3d  / max_inflow_m3d;
    const float norm_storage = storage_m3  / max_storage_m3;
    float norm_outflow;

    switch (month) {
        case  1: norm_outflow = 0.7076f * norm_inflow + 0.0011f; break;
        case  2: norm_outflow = 0.9522f * norm_inflow + -0.0009f; break;
        case  3: norm_outflow = 1.0650f * norm_inflow + 0.0002f; break;
        case  4: norm_outflow = 1.1013f * norm_inflow + 0.0065f; break;
        case  5: norm_outflow = 1.0445f * norm_inflow + 0.0132f; break;
        case  6: norm_outflow = 1.0567f * norm_inflow + 0.0147f; break;
        case  7: norm_outflow = 1.2398f * norm_inflow + 0.0044f; break;
        case  8: norm_outflow = 1.0018f * norm_inflow + 0.0174f; break;
        case  9: norm_outflow = 1.1175f * norm_inflow + 0.0029f; break;
        case 10: norm_outflow = 1.0339f * norm_inflow + 0.0014f; break;
        case 11: norm_outflow = 1.1406f * norm_inflow + -0.0030f; break;
        case 12: norm_outflow = 0.9317f * norm_inflow + -0.0025f; break;
    }
    return norm_outflow * max_outflow_m3d;
}

static float rule_2838(float inflow_m3d, float storage_m3, int month) {
    const float max_inflow_m3d   = 6675539.7f;
    const float max_outflow_m3d  = 6671807.2f;
    const float max_storage_m3   = 99442787.6f;
    const float norm_inflow  = inflow_m3d  / max_inflow_m3d;
    const float norm_storage = storage_m3  / max_storage_m3;
    float norm_outflow;

    switch (month) {
        case  1: norm_outflow = 0.5982f * norm_inflow + 0.0184f; break;
        case  2: norm_outflow = 0.7119f * norm_inflow + 0.0116f; break;
        case  3: norm_outflow = 0.5478f * norm_inflow + 0.0124f; break;
        case  4: norm_outflow = 0.2966f * norm_inflow + 0.0339f; break;
        case  5: norm_outflow = 0.8393f * norm_inflow + 0.0128f; break;
        case  6: norm_outflow = 1.0081f * norm_inflow + -0.0295f; break;
        case  7: norm_outflow = 0.9632f * norm_inflow + 0.0049f; break;
        case  8: norm_outflow = 0.8067f * norm_inflow + 0.0431f; break;
        case  9: norm_outflow = 0.7035f * norm_inflow + 0.0565f; break;
        case 10: norm_outflow = 0.6218f * norm_inflow + 0.0279f; break;
        case 11: norm_outflow = 0.5185f * norm_inflow + 0.0141f; break;
        case 12: norm_outflow = 0.2812f * norm_inflow + 0.0273f; break;
    }
    return norm_outflow * max_outflow_m3d;
}

static float rule_2867(float inflow_m3d, float storage_m3, int month) {
    const float max_inflow_m3d   = 2153020.1f;
    const float max_outflow_m3d  = 853899.2f;
    const float max_storage_m3   = 29290216.1f;
    const float norm_inflow  = inflow_m3d  / max_inflow_m3d;
    const float norm_storage = storage_m3  / max_storage_m3;
    float norm_outflow;

    switch (month) {
        case  1: norm_outflow = 0.1929f * norm_inflow + 0.0277f; break;
        case  2: norm_outflow = 0.5039f * norm_inflow + 0.0247f; break;
        case  3: norm_outflow = 0.3626f * norm_inflow + 0.0464f; break;
        case  4: norm_outflow = 0.6058f * norm_inflow + 0.0505f; break;
        case  5: norm_outflow = 1.8562f * norm_inflow + 0.0122f; break;
        case  6: norm_outflow = 1.9237f * norm_inflow + 0.0439f; break;
        case  7: norm_outflow = 2.3479f * norm_inflow + 0.0214f; break;
        case  8: norm_outflow = 1.1637f * norm_inflow + 0.0515f; break;
        case  9: norm_outflow = 0.9524f * norm_inflow + 0.0242f; break;
        case 10: norm_outflow = 0.7412f * norm_inflow + 0.0218f; break;
        case 11: norm_outflow = 0.5587f * norm_inflow + 0.0207f; break;
        case 12: norm_outflow = 0.2447f * norm_inflow + 0.0269f; break;
    }
    return norm_outflow * max_outflow_m3d;
}

static float rule_2870(float inflow_m3d, float storage_m3, int month) {
    const float max_inflow_m3d   = 2988736.0f;
    const float max_outflow_m3d  = 2935875.4f;
    const float max_storage_m3   = 66792942.0f;
    const float norm_inflow  = inflow_m3d  / max_inflow_m3d;
    const float norm_storage = storage_m3  / max_storage_m3;
    float norm_outflow;

    switch (month) {
        case  1: norm_outflow = 0.1243f * norm_inflow + 0.0592f; break;
        case  2: norm_outflow = 0.1322f * norm_inflow + 0.0509f; break;
        case  3: norm_outflow = 0.1856f * norm_inflow + 0.0500f; break;
        case  4: norm_outflow = 0.2041f * norm_inflow + 0.0607f; break;
        case  5: norm_outflow = 0.2599f * norm_inflow + 0.0404f; break;
        case  6: norm_outflow = 0.7277f * norm_inflow + -0.0318f; break;
        case  7: norm_outflow = 0.7674f * norm_inflow + 0.0444f; break;
        case  8: norm_outflow = 0.4846f * norm_inflow + 0.0960f; break;
        case  9: norm_outflow = 0.1202f * norm_inflow + 0.1008f; break;
        case 10: norm_outflow = 0.0203f * norm_inflow + 0.0860f; break;
        case 11: norm_outflow = 0.0878f * norm_inflow + 0.0664f; break;
        case 12: norm_outflow = 0.0241f * norm_inflow + 0.0627f; break;
    }
    return norm_outflow * max_outflow_m3d;
}

static float rule_807(float inflow_m3d, float storage_m3, int month) {
    const float max_inflow_m3d   = 3135339.5f;
    const float max_outflow_m3d  = 3009328.0f;
    const float max_storage_m3   = 130334430.7f;
    const float norm_inflow  = inflow_m3d  / max_inflow_m3d;
    const float norm_storage = storage_m3  / max_storage_m3;
    float norm_outflow;

    switch (month) {
        case  1: norm_outflow = 0.6138f * norm_inflow + 0.0263f; break;
        case  2: norm_outflow = 0.5496f * norm_inflow + 0.0270f; break;
        case  3: norm_outflow = 0.5278f * norm_inflow + 0.0285f; break;
        case  4: norm_outflow = 0.5989f * norm_inflow + 0.0283f; break;
        case  5: norm_outflow = 0.5599f * norm_inflow + 0.0288f; break;
        case  6: norm_outflow = 0.8949f * norm_inflow + 0.0074f; break;
        case  7: norm_outflow = 1.0172f * norm_inflow + 0.0147f; break;
        case  8: norm_outflow = 0.7949f * norm_inflow + 0.0437f; break;
        case  9: norm_outflow = 0.1598f * norm_inflow + 0.0803f; break;
        case 10: norm_outflow = 0.2237f * norm_inflow + 0.0558f; break;
        case 11: norm_outflow = 0.0852f * norm_inflow + 0.0622f; break;
        case 12: norm_outflow = 0.3732f * norm_inflow + 0.0422f; break;
    }
    return norm_outflow * max_outflow_m3d;
}

static float rule_20(float inflow_m3d, float storage_m3, int month) {
    const float max_inflow_m3d   = 462687812.0f;
    const float max_outflow_m3d  = 368454268.7f;
    const float max_storage_m3   = 29602227313.0f;
    const float norm_inflow  = inflow_m3d  / max_inflow_m3d;
    const float norm_storage = storage_m3  / max_storage_m3;
    float norm_outflow;

    switch (month) {
        case  1: norm_outflow = 0.6557f * norm_inflow + 0.0864f; break;
        case  2: norm_outflow = 0.4343f * norm_inflow + 0.1041f; break;
        case  3: norm_outflow = 0.0097f * norm_inflow + 0.1137f; break;
        case  4: norm_outflow = 0.1130f * norm_inflow + 0.1026f; break;
        case  5: norm_outflow = 0.4859f * norm_inflow + 0.0650f; break;
        case  6: norm_outflow = 0.8127f * norm_inflow + -0.0303f; break;
        case  7: norm_outflow = 0.8065f * norm_inflow + 0.0468f; break;
        case  8: norm_outflow = 1.4863f * norm_inflow + 0.0465f; break;
        case  9: norm_outflow = 1.1534f * norm_inflow + 0.0554f; break;
        case 10: norm_outflow = 1.3823f * norm_inflow + 0.0110f; break;
        case 11: norm_outflow = 0.7179f * norm_inflow + 0.0725f; break;
        case 12: norm_outflow = 0.3061f * norm_inflow + 0.1007f; break;
    }
    return norm_outflow * max_outflow_m3d;
}

static float rule_116(float inflow_m3d, float storage_m3, int month) {
    const float max_inflow_m3d   = 2570629.3f;
    const float max_outflow_m3d  = 2571629.4f;
    const float max_storage_m3   = 537057.2f;
    const float norm_inflow  = inflow_m3d  / max_inflow_m3d;
    const float norm_storage = storage_m3  / max_storage_m3;
    float norm_outflow;

    switch (month) {
        case  1: norm_outflow = 1.0001f * norm_inflow + -0.0000f; break;
        case  2: norm_outflow = 1.0000f * norm_inflow + 0.0000f; break;
        case  3: norm_outflow = 1.0006f * norm_inflow + -0.0004f; break;
        case  4: norm_outflow = 1.0006f * norm_inflow + -0.0009f; break;
        case  5: norm_outflow = 0.9994f * norm_inflow + -0.0003f; break;
        case  6: norm_outflow = 0.9997f * norm_inflow + -0.0001f; break;
        case  7: norm_outflow = 1.0002f * norm_inflow + 0.0001f; break;
        case  8: norm_outflow = 0.9997f * norm_inflow + 0.0003f; break;
        case  9: norm_outflow = 1.0007f * norm_inflow + -0.0003f; break;
        case 10: norm_outflow = 1.0008f * norm_inflow + -0.0006f; break;
        case 11: norm_outflow = 0.9997f * norm_inflow + 0.0001f; break;
        case 12: norm_outflow = 1.0001f * norm_inflow + -0.0001f; break;
    }
    return norm_outflow * max_outflow_m3d;
}

static float rule_6853(float inflow_m3d, float storage_m3, int month) {
    const float max_inflow_m3d   = 3309661.9f;
    const float max_outflow_m3d  = 3256510.1f;
    const float max_storage_m3   = 978026.3f;
    const float norm_inflow  = inflow_m3d  / max_inflow_m3d;
    const float norm_storage = storage_m3  / max_storage_m3;
    float norm_outflow;

    switch (month) {
        case  1: norm_outflow = 1.0163f * norm_inflow + 0.0004f; break;
        case  2: norm_outflow = 1.0158f * norm_inflow + 0.0002f; break;
        case  3: norm_outflow = 1.0127f * norm_inflow + 0.0002f; break;
        case  4: norm_outflow = 1.0082f * norm_inflow + 0.0015f; break;
        case  5: norm_outflow = 1.0015f * norm_inflow + 0.0044f; break;
        case  6: norm_outflow = 1.0084f * norm_inflow + 0.0026f; break;
        case  7: norm_outflow = 1.0092f * norm_inflow + 0.0019f; break;
        case  8: norm_outflow = 1.0163f * norm_inflow + -0.0002f; break;
        case  9: norm_outflow = 1.0157f * norm_inflow + 0.0003f; break;
        case 10: norm_outflow = 1.0162f * norm_inflow + 0.0010f; break;
        case 11: norm_outflow = 1.0149f * norm_inflow + 0.0013f; break;
        case 12: norm_outflow = 1.0158f * norm_inflow + 0.0006f; break;
    }
    return norm_outflow * max_outflow_m3d;
}

static float rule_2229(float inflow_m3d, float storage_m3, int month) {
    const float max_inflow_m3d   = 23407799.7f;
    const float max_outflow_m3d  = 3453058.5f;
    const float max_storage_m3   = 154594515.4f;
    const float norm_inflow  = inflow_m3d  / max_inflow_m3d;
    const float norm_storage = storage_m3  / max_storage_m3;
    float norm_outflow;

    switch (month) {
        case  1: norm_outflow = 6.7530f * norm_inflow + 0.0007f; break;
        case  2: norm_outflow = 4.6713f * norm_inflow + 0.0032f; break;
        case  3: norm_outflow = 0.5551f * norm_inflow + 0.0158f; break;
        case  4: norm_outflow = 0.6667f * norm_inflow + 0.0552f; break;
        case  5: norm_outflow = 1.3057f * norm_inflow + 0.0921f; break;
        case  6: norm_outflow = 3.5674f * norm_inflow + 0.0869f; break;
        case  7: norm_outflow = 4.1547f * norm_inflow + 0.1113f; break;
        case  8: norm_outflow = 4.1654f * norm_inflow + 0.1102f; break;
        case  9: norm_outflow = 8.1844f * norm_inflow + 0.0462f; break;
        case 10: norm_outflow = 9.4820f * norm_inflow + 0.0219f; break;
        case 11: norm_outflow = 8.4930f * norm_inflow + -0.0002f; break;
        case 12: norm_outflow = 6.9521f * norm_inflow + 0.0006f; break;
    }
    return norm_outflow * max_outflow_m3d;
}

static float rule_2232(float inflow_m3d, float storage_m3, int month) {
    const float max_inflow_m3d   = 34943239.3f;
    const float max_outflow_m3d  = 4421584.6f;
    const float max_storage_m3   = 274555379.3f;
    const float norm_inflow  = inflow_m3d  / max_inflow_m3d;
    const float norm_storage = storage_m3  / max_storage_m3;
    float norm_outflow;

    switch (month) {
        case  1: norm_outflow = 1.2606f * norm_inflow + 0.0021f; break;
        case  2: norm_outflow = 0.1378f * norm_inflow + 0.0025f; break;
        case  3: norm_outflow = 1.1231f * norm_inflow + -0.0003f; break;
        case  4: norm_outflow = 1.3490f * norm_inflow + 0.0978f; break;
        case  5: norm_outflow = 3.9616f * norm_inflow + 0.1766f; break;
        case  6: norm_outflow = 3.6097f * norm_inflow + 0.1213f; break;
        case  7: norm_outflow = 2.4860f * norm_inflow + 0.0737f; break;
        case  8: norm_outflow = 2.3338f * norm_inflow + 0.0504f; break;
        case  9: norm_outflow = 2.8845f * norm_inflow + 0.0744f; break;
        case 10: norm_outflow = 3.2121f * norm_inflow + 0.0480f; break;
        case 11: norm_outflow = 5.8266f * norm_inflow + 0.0147f; break;
        case 12: norm_outflow = 6.8504f * norm_inflow + 0.0035f; break;
    }
    return norm_outflow * max_outflow_m3d;
}

static float rule_2236(float inflow_m3d, float storage_m3, int month) {
    const float max_inflow_m3d   = 10001158.4f;
    const float max_outflow_m3d  = 7449692.3f;
    const float max_storage_m3   = 14209689.6f;
    const float norm_inflow  = inflow_m3d  / max_inflow_m3d;
    const float norm_storage = storage_m3  / max_storage_m3;
    float norm_outflow;

    switch (month) {
        case  1: norm_outflow = 0.3590f * norm_inflow + 0.0007f; break;
        case  2: norm_outflow = 0.7312f * norm_inflow + 0.0016f; break;
        case  3: norm_outflow = 1.0268f * norm_inflow + 0.0019f; break;
        case  4: norm_outflow = 1.2565f * norm_inflow + 0.0010f; break;
        case  5: norm_outflow = 1.1949f * norm_inflow + 0.0018f; break;
        case  6: norm_outflow = 1.1248f * norm_inflow + 0.0026f; break;
        case  7: norm_outflow = 0.9418f * norm_inflow + 0.0045f; break;
        case  8: norm_outflow = 0.9932f * norm_inflow + 0.0033f; break;
        case  9: norm_outflow = 0.3830f * norm_inflow + 0.0030f; break;
        case 10: norm_outflow = 1.2403f * norm_inflow + 0.0014f; break;
        case 11: norm_outflow = 0.5301f * norm_inflow + 0.0013f; break;
        case 12: norm_outflow = 0.3885f * norm_inflow + 0.0006f; break;
    }
    return norm_outflow * max_outflow_m3d;
}

static float rule_536(float inflow_m3d, float storage_m3, int month) {
    const float max_inflow_m3d   = 16460483.6f;
    const float max_outflow_m3d  = 2794003.4f;
    const float max_storage_m3   = 174948662.2f;
    const float norm_inflow  = inflow_m3d  / max_inflow_m3d;
    const float norm_storage = storage_m3  / max_storage_m3;
    float norm_outflow;

    switch (month) {
        case  1: norm_outflow = 5.4224f * norm_inflow + 0.0619f; break;
        case  2: norm_outflow = 5.4868f * norm_inflow + 0.0447f; break;
        case  3: norm_outflow = 3.4664f * norm_inflow + 0.1082f; break;
        case  4: norm_outflow = 1.4417f * norm_inflow + 0.2628f; break;
        case  5: norm_outflow = 2.5726f * norm_inflow + 0.2433f; break;
        case  6: norm_outflow = 1.8784f * norm_inflow + 0.2699f; break;
        case  7: norm_outflow = 2.8751f * norm_inflow + 0.1980f; break;
        case  8: norm_outflow = 3.4853f * norm_inflow + 0.1126f; break;
        case  9: norm_outflow = 3.9262f * norm_inflow + 0.1102f; break;
        case 10: norm_outflow = 3.0509f * norm_inflow + 0.2079f; break;
        case 11: norm_outflow = 4.6642f * norm_inflow + 0.1284f; break;
        case 12: norm_outflow = 5.2423f * norm_inflow + 0.0746f; break;
    }
    return norm_outflow * max_outflow_m3d;
}

static float rule_539(float inflow_m3d, float storage_m3, int month) {
    const float max_inflow_m3d   = 7594484.3f;
    const float max_outflow_m3d  = 5676066.4f;
    const float max_storage_m3   = 139389530.7f;
    const float norm_inflow  = inflow_m3d  / max_inflow_m3d;
    const float norm_storage = storage_m3  / max_storage_m3;
    float norm_outflow;

    switch (month) {
        case  1: norm_outflow = 0.5391f * norm_inflow + 0.0809f; break;
        case  2: norm_outflow = 0.4234f * norm_inflow + 0.0802f; break;
        case  3: norm_outflow = 0.1720f * norm_inflow + 0.0842f; break;
        case  4: norm_outflow = 0.5064f * norm_inflow + 0.0352f; break;
        case  5: norm_outflow = 0.7791f * norm_inflow + 0.0785f; break;
        case  6: norm_outflow = 0.8873f * norm_inflow + 0.0679f; break;
        case  7: norm_outflow = 0.6708f * norm_inflow + 0.0676f; break;
        case  8: norm_outflow = 0.4644f * norm_inflow + 0.0464f; break;
        case  9: norm_outflow = 0.3540f * norm_inflow + 0.0492f; break;
        case 10: norm_outflow = 0.4635f * norm_inflow + 0.0922f; break;
        case 11: norm_outflow = 0.5734f * norm_inflow + 0.1261f; break;
        case 12: norm_outflow = 0.8001f * norm_inflow + 0.0800f; break;
    }
    return norm_outflow * max_outflow_m3d;
}

static float rule_544(float inflow_m3d, float storage_m3, int month) {
    const float max_inflow_m3d   = 38338391.2f;
    const float max_outflow_m3d  = 9481493.5f;
    const float max_storage_m3   = 177951692.6f;
    const float norm_inflow  = inflow_m3d  / max_inflow_m3d;
    const float norm_storage = storage_m3  / max_storage_m3;
    float norm_outflow;

    switch (month) {
        case  1: norm_outflow = 0.5395f * norm_inflow + 0.0034f; break;
        case  2: norm_outflow = 1.2554f * norm_inflow + 0.0055f; break;
        case  3: norm_outflow = 1.1241f * norm_inflow + 0.0465f; break;
        case  4: norm_outflow = 1.6968f * norm_inflow + 0.0613f; break;
        case  5: norm_outflow = 2.1379f * norm_inflow + 0.0126f; break;
        case  6: norm_outflow = 2.2109f * norm_inflow + 0.0177f; break;
        case  7: norm_outflow = 0.5940f * norm_inflow + 0.0228f; break;
        case  8: norm_outflow = 1.7402f * norm_inflow + 0.0202f; break;
        case  9: norm_outflow = 1.6409f * norm_inflow + 0.0105f; break;
        case 10: norm_outflow = 2.2065f * norm_inflow + 0.0053f; break;
        case 11: norm_outflow = 0.7062f * norm_inflow + 0.0037f; break;
        case 12: norm_outflow = 0.9145f * norm_inflow + 0.0037f; break;
    }
    return norm_outflow * max_outflow_m3d;
}

static float rule_555(float inflow_m3d, float storage_m3, int month) {
    const float max_inflow_m3d   = 7866368.8f;
    const float max_outflow_m3d  = 1967079.3f;
    const float max_storage_m3   = 88014292.2f;
    const float norm_inflow  = inflow_m3d  / max_inflow_m3d;
    const float norm_storage = storage_m3  / max_storage_m3;
    float norm_outflow;

    switch (month) {
        case  1: norm_outflow = 3.3444f * norm_inflow + 0.0795f; break;
        case  2: norm_outflow = 3.4388f * norm_inflow + 0.0815f; break;
        case  3: norm_outflow = 2.5001f * norm_inflow + 0.0855f; break;
        case  4: norm_outflow = 1.5947f * norm_inflow + 0.1691f; break;
        case  5: norm_outflow = 2.1597f * norm_inflow + 0.1733f; break;
        case  6: norm_outflow = 1.7253f * norm_inflow + 0.2042f; break;
        case  7: norm_outflow = 1.7900f * norm_inflow + 0.1771f; break;
        case  8: norm_outflow = 1.6689f * norm_inflow + 0.1476f; break;
        case  9: norm_outflow = 1.8064f * norm_inflow + 0.1534f; break;
        case 10: norm_outflow = 2.3307f * norm_inflow + 0.1642f; break;
        case 11: norm_outflow = 3.2213f * norm_inflow + 0.0906f; break;
        case 12: norm_outflow = 3.6097f * norm_inflow + 0.0597f; break;
    }
    return norm_outflow * max_outflow_m3d;
}

static float rule_585(float inflow_m3d, float storage_m3, int month) {
    const float max_inflow_m3d   = 51878184.2f;
    const float max_outflow_m3d  = 11514306.4f;
    const float max_storage_m3   = 301460045.0f;
    const float norm_inflow  = inflow_m3d  / max_inflow_m3d;
    const float norm_storage = storage_m3  / max_storage_m3;
    float norm_outflow;

    switch (month) {
        case  1: norm_outflow = 0.9288f * norm_inflow + 0.0074f; break;
        case  2: norm_outflow = 0.2240f * norm_inflow + 0.0072f; break;
        case  3: norm_outflow = 1.3029f * norm_inflow + 0.0243f; break;
        case  4: norm_outflow = 1.6831f * norm_inflow + 0.0473f; break;
        case  5: norm_outflow = 3.0213f * norm_inflow + 0.0156f; break;
        case  6: norm_outflow = 1.7244f * norm_inflow + 0.0183f; break;
        case  7: norm_outflow = 2.6641f * norm_inflow + 0.0145f; break;
        case  8: norm_outflow = 2.7187f * norm_inflow + 0.0142f; break;
        case  9: norm_outflow = 0.5077f * norm_inflow + 0.0127f; break;
        case 10: norm_outflow = 0.4043f * norm_inflow + 0.0154f; break;
        case 11: norm_outflow = 2.8258f * norm_inflow + 0.0119f; break;
        case 12: norm_outflow = 1.5940f * norm_inflow + 0.0080f; break;
    }
    return norm_outflow * max_outflow_m3d;
}

static float rule_2345(float inflow_m3d, float storage_m3, int month) {
    const float max_inflow_m3d   = 31337862.5f;
    const float max_outflow_m3d  = 22386264.6f;
    const float max_storage_m3   = 47215138.8f;
    const float norm_inflow  = inflow_m3d  / max_inflow_m3d;
    const float norm_storage = storage_m3  / max_storage_m3;
    float norm_outflow;

    switch (month) {
        case  1: norm_outflow = 0.9994f * norm_inflow + 0.0016f; break;
        case  2: norm_outflow = 1.1919f * norm_inflow + 0.0006f; break;
        case  3: norm_outflow = 1.1995f * norm_inflow + 0.0033f; break;
        case  4: norm_outflow = 1.2922f * norm_inflow + 0.0146f; break;
        case  5: norm_outflow = 1.4078f * norm_inflow + 0.0029f; break;
        case  6: norm_outflow = 1.1388f * norm_inflow + 0.0089f; break;
        case  7: norm_outflow = 1.3104f * norm_inflow + 0.0063f; break;
        case  8: norm_outflow = 1.4567f * norm_inflow + -0.0007f; break;
        case  9: norm_outflow = 1.2250f * norm_inflow + -0.0002f; break;
        case 10: norm_outflow = 1.3260f * norm_inflow + -0.0006f; break;
        case 11: norm_outflow = 1.4372f * norm_inflow + -0.0004f; break;
        case 12: norm_outflow = 1.3172f * norm_inflow + 0.0003f; break;
    }
    return norm_outflow * max_outflow_m3d;
}

static float rule_621(float inflow_m3d, float storage_m3, int month) {
    const float max_inflow_m3d   = 98186933.7f;
    const float max_outflow_m3d  = 72908029.6f;
    const float max_storage_m3   = 194125082.4f;
    const float norm_inflow  = inflow_m3d  / max_inflow_m3d;
    const float norm_storage = storage_m3  / max_storage_m3;
    float norm_outflow;

    switch (month) {
        case  1: norm_outflow = 1.1290f * norm_inflow + 0.0022f; break;
        case  2: norm_outflow = 1.1984f * norm_inflow + 0.0015f; break;
        case  3: norm_outflow = 0.9573f * norm_inflow + 0.0121f; break;
        case  4: norm_outflow = 1.2177f * norm_inflow + 0.0151f; break;
        case  5: norm_outflow = 1.0439f * norm_inflow + 0.0171f; break;
        case  6: norm_outflow = 1.0049f * norm_inflow + 0.0155f; break;
        case  7: norm_outflow = 1.3904f * norm_inflow + 0.0097f; break;
        case  8: norm_outflow = 1.0345f * norm_inflow + 0.0062f; break;
        case  9: norm_outflow = 0.9099f * norm_inflow + 0.0029f; break;
        case 10: norm_outflow = 0.6928f * norm_inflow + 0.0102f; break;
        case 11: norm_outflow = 0.6629f * norm_inflow + 0.0119f; break;
        case 12: norm_outflow = 0.2115f * norm_inflow + 0.0151f; break;
    }
    return norm_outflow * max_outflow_m3d;
}

static float rule_640(float inflow_m3d, float storage_m3, int month) {
    const float max_inflow_m3d   = 6280235.8f;
    const float max_outflow_m3d  = 2201915.0f;
    const float max_storage_m3   = 242738996.2f;
    const float norm_inflow  = inflow_m3d  / max_inflow_m3d;
    const float norm_storage = storage_m3  / max_storage_m3;
    float norm_outflow;

    switch (month) {
        case  1: norm_outflow = 0.0000f * norm_inflow + 0.0006f; break;
        case  2: norm_outflow = 0.0002f * norm_inflow + 0.0006f; break;
        case  3: norm_outflow = 0.0000f * norm_inflow + 0.0027f; break;
        case  4: norm_outflow = 0.0194f * norm_inflow + 0.0168f; break;
        case  5: norm_outflow = 0.0793f * norm_inflow + 0.1116f; break;
        case  6: norm_outflow = 0.0000f * norm_inflow + 0.2878f; break;
        case  7: norm_outflow = 0.0000f * norm_inflow + 0.5731f; break;
        case  8: norm_outflow = 0.0000f * norm_inflow + 0.5818f; break;
        case  9: norm_outflow = 0.0000f * norm_inflow + 0.3283f; break;
        case 10: norm_outflow = 0.0091f * norm_inflow + 0.0103f; break;
        case 11: norm_outflow = 0.0052f * norm_inflow + 0.0010f; break;
        case 12: norm_outflow = 0.0000f * norm_inflow + 0.0006f; break;
    }
    return norm_outflow * max_outflow_m3d;
}

static float rule_21(float inflow_m3d, float storage_m3, int month) {
    const float max_inflow_m3d   = 510978755.8f;
    const float max_outflow_m3d  = 392186888.1f;
    const float max_storage_m3   = 28330568640.0f;
    const float norm_inflow  = inflow_m3d  / max_inflow_m3d;
    const float norm_storage = storage_m3  / max_storage_m3;
    float norm_outflow;

    switch (month) {
        case  1: norm_outflow = 0.0683f * norm_inflow + 0.1204f; break;
        case  2: norm_outflow = 0.1929f * norm_inflow + 0.0855f; break;
        case  3: norm_outflow = 0.0000f * norm_inflow + 0.1062f; break;
        case  4: norm_outflow = 0.1912f * norm_inflow + 0.1049f; break;
        case  5: norm_outflow = 0.4024f * norm_inflow + 0.0792f; break;
        case  6: norm_outflow = 1.0280f * norm_inflow + 0.0160f; break;
        case  7: norm_outflow = 1.1502f * norm_inflow + 0.0377f; break;
        case  8: norm_outflow = 1.3243f * norm_inflow + 0.0492f; break;
        case  9: norm_outflow = 1.2299f * norm_inflow + 0.0623f; break;
        case 10: norm_outflow = 1.2823f * norm_inflow + 0.0364f; break;
        case 11: norm_outflow = 1.4500f * norm_inflow + 0.0170f; break;
        case 12: norm_outflow = 0.5695f * norm_inflow + 0.0775f; break;
    }
    return norm_outflow * max_outflow_m3d;
}

static float rule_2429(float inflow_m3d, float storage_m3, int month) {
    const float max_inflow_m3d   = 2459029.0f;
    const float max_outflow_m3d  = 1257736.9f;
    const float max_storage_m3   = 79246156.1f;
    const float norm_inflow  = inflow_m3d  / max_inflow_m3d;
    const float norm_storage = storage_m3  / max_storage_m3;
    float norm_outflow;

    switch (month) {
        case  1: norm_outflow = 1.4244f * norm_inflow + 0.0144f; break;
        case  2: norm_outflow = 1.3458f * norm_inflow + 0.0144f; break;
        case  3: norm_outflow = 1.4614f * norm_inflow + 0.0005f; break;
        case  4: norm_outflow = 1.7209f * norm_inflow + -0.0253f; break;
        case  5: norm_outflow = 1.1783f * norm_inflow + 0.0429f; break;
        case  6: norm_outflow = 1.5511f * norm_inflow + 0.0481f; break;
        case  7: norm_outflow = 1.5038f * norm_inflow + 0.0900f; break;
        case  8: norm_outflow = 1.7049f * norm_inflow + 0.0677f; break;
        case  9: norm_outflow = 1.6325f * norm_inflow + 0.0456f; break;
        case 10: norm_outflow = 1.5857f * norm_inflow + 0.0065f; break;
        case 11: norm_outflow = 1.5025f * norm_inflow + 0.0073f; break;
        case 12: norm_outflow = 1.6971f * norm_inflow + 0.0127f; break;
    }
    return norm_outflow * max_outflow_m3d;
}

static float rule_126(float inflow_m3d, float storage_m3, int month) {
    const float max_inflow_m3d   = 195388463.8f;
    const float max_outflow_m3d  = 181780590.4f;
    const float max_storage_m3   = 2247396489.5f;
    const float norm_inflow  = inflow_m3d  / max_inflow_m3d;
    const float norm_storage = storage_m3  / max_storage_m3;
    float norm_outflow;

    switch (month) {
        case  1: norm_outflow = 0.9337f * norm_inflow + 0.0364f; break;
        case  2: norm_outflow = 0.8576f * norm_inflow + 0.0503f; break;
        case  3: norm_outflow = 1.0140f * norm_inflow + 0.0161f; break;
        case  4: norm_outflow = 1.0118f * norm_inflow + 0.0159f; break;
        case  5: norm_outflow = 1.0105f * norm_inflow + 0.0190f; break;
        case  6: norm_outflow = 0.9801f * norm_inflow + 0.0281f; break;
        case  7: norm_outflow = 1.0311f * norm_inflow + 0.0142f; break;
        case  8: norm_outflow = 1.0281f * norm_inflow + 0.0172f; break;
        case  9: norm_outflow = 1.0656f * norm_inflow + 0.0028f; break;
        case 10: norm_outflow = 0.9986f * norm_inflow + 0.0188f; break;
        case 11: norm_outflow = 1.0202f * norm_inflow + 0.0157f; break;
        case 12: norm_outflow = 0.9308f * norm_inflow + 0.0350f; break;
    }
    return norm_outflow * max_outflow_m3d;
}

static float rule_2432(float inflow_m3d, float storage_m3, int month) {
    const float max_inflow_m3d   = 456936.4f;
    const float max_outflow_m3d  = 244290.8f;
    const float max_storage_m3   = 19706076.5f;
    const float norm_inflow  = inflow_m3d  / max_inflow_m3d;
    const float norm_storage = storage_m3  / max_storage_m3;
    float norm_outflow;

    switch (month) {
        case  1: norm_outflow = 1.4490f * norm_inflow + 0.0188f; break;
        case  2: norm_outflow = 1.5195f * norm_inflow + 0.0189f; break;
        case  3: norm_outflow = 0.9901f * norm_inflow + 0.0607f; break;
        case  4: norm_outflow = 1.0133f * norm_inflow + 0.0822f; break;
        case  5: norm_outflow = 1.3475f * norm_inflow + 0.0536f; break;
        case  6: norm_outflow = 1.5200f * norm_inflow + 0.0636f; break;
        case  7: norm_outflow = 1.4614f * norm_inflow + 0.0692f; break;
        case  8: norm_outflow = 1.5658f * norm_inflow + 0.0657f; break;
        case  9: norm_outflow = 1.3207f * norm_inflow + 0.0643f; break;
        case 10: norm_outflow = 0.9540f * norm_inflow + 0.0631f; break;
        case 11: norm_outflow = 1.2574f * norm_inflow + 0.0353f; break;
        case 12: norm_outflow = 1.2777f * norm_inflow + 0.0307f; break;
    }
    return norm_outflow * max_outflow_m3d;
}

static float rule_698(float inflow_m3d, float storage_m3, int month) {
    const float max_inflow_m3d   = 43473101.4f;
    const float max_outflow_m3d  = 35223562.9f;
    const float max_storage_m3   = 163702531.7f;
    const float norm_inflow  = inflow_m3d  / max_inflow_m3d;
    const float norm_storage = storage_m3  / max_storage_m3;
    float norm_outflow;

    switch (month) {
        case  1: norm_outflow = 0.1308f * norm_inflow + 0.0000f; break;
        case  2: norm_outflow = 0.2867f * norm_inflow + -0.0006f; break;
        case  3: norm_outflow = 1.1993f * norm_inflow + -0.0068f; break;
        case  4: norm_outflow = 1.1841f * norm_inflow + -0.0035f; break;
        case  5: norm_outflow = 0.8966f * norm_inflow + 0.0018f; break;
        case  6: norm_outflow = 1.1282f * norm_inflow + 0.0038f; break;
        case  7: norm_outflow = 0.7551f * norm_inflow + 0.0125f; break;
        case  8: norm_outflow = 0.0755f * norm_inflow + 0.0128f; break;
        case  9: norm_outflow = 0.0000f * norm_inflow + 0.0053f; break;
        case 10: norm_outflow = 0.1287f * norm_inflow + 0.0010f; break;
        case 11: norm_outflow = 1.3901f * norm_inflow + -0.0017f; break;
        case 12: norm_outflow = 0.5474f * norm_inflow + -0.0005f; break;
    }
    return norm_outflow * max_outflow_m3d;
}

static float rule_713(float inflow_m3d, float storage_m3, int month) {
    const float max_inflow_m3d   = 406732607.2f;
    const float max_outflow_m3d  = 393164635.7f;
    const float max_storage_m3   = 603170733.2f;
    const float norm_inflow  = inflow_m3d  / max_inflow_m3d;
    const float norm_storage = storage_m3  / max_storage_m3;
    float norm_outflow;

    switch (month) {
        case  1: norm_outflow = 0.7857f * norm_inflow + 0.0263f; break;
        case  2: norm_outflow = 0.8257f * norm_inflow + 0.0245f; break;
        case  3: norm_outflow = 0.8649f * norm_inflow + 0.0200f; break;
        case  4: norm_outflow = 0.9668f * norm_inflow + 0.0097f; break;
        case  5: norm_outflow = 0.9766f * norm_inflow + 0.0091f; break;
        case  6: norm_outflow = 1.0182f * norm_inflow + 0.0034f; break;
        case  7: norm_outflow = 1.0266f * norm_inflow + 0.0011f; break;
        case  8: norm_outflow = 1.0277f * norm_inflow + -0.0001f; break;
        case  9: norm_outflow = 1.0157f * norm_inflow + 0.0028f; break;
        case 10: norm_outflow = 1.0249f * norm_inflow + 0.0016f; break;
        case 11: norm_outflow = 1.0310f * norm_inflow + 0.0008f; break;
        case 12: norm_outflow = 0.9658f * norm_inflow + 0.0089f; break;
    }
    return norm_outflow * max_outflow_m3d;
}

static float rule_720(float inflow_m3d, float storage_m3, int month) {
    const float max_inflow_m3d   = 27842212.1f;
    const float max_outflow_m3d  = 20081513.9f;
    const float max_storage_m3   = 884559345.0f;
    const float norm_inflow  = inflow_m3d  / max_inflow_m3d;
    const float norm_storage = storage_m3  / max_storage_m3;
    float norm_outflow;

    switch (month) {
        case  1: norm_outflow = 0.0000f * norm_inflow + 0.0029f; break;
        case  2: norm_outflow = 0.0143f * norm_inflow + 0.0027f; break;
        case  3: norm_outflow = 1.1374f * norm_inflow + -0.0781f; break;
        case  4: norm_outflow = 1.0611f * norm_inflow + -0.0628f; break;
        case  5: norm_outflow = 0.7085f * norm_inflow + 0.0797f; break;
        case  6: norm_outflow = 0.8664f * norm_inflow + 0.1300f; break;
        case  7: norm_outflow = 0.7506f * norm_inflow + 0.4418f; break;
        case  8: norm_outflow = 0.9485f * norm_inflow + 0.3981f; break;
        case  9: norm_outflow = 1.9662f * norm_inflow + 0.0023f; break;
        case 10: norm_outflow = 0.0098f * norm_inflow + 0.0035f; break;
        case 11: norm_outflow = 0.0017f * norm_inflow + 0.0026f; break;
        case 12: norm_outflow = 0.0014f * norm_inflow + 0.0029f; break;
    }
    return norm_outflow * max_outflow_m3d;
}

static float rule_2560(float inflow_m3d, float storage_m3, int month) {
    const float max_inflow_m3d   = 3768954.7f;
    const float max_outflow_m3d  = 1224275.8f;
    const float max_storage_m3   = 12984844.0f;
    const float norm_inflow  = inflow_m3d  / max_inflow_m3d;
    const float norm_storage = storage_m3  / max_storage_m3;
    float norm_outflow;

    switch (month) {
        case  1: norm_outflow = 0.0000f * norm_inflow + 0.0010f; break;
        case  2: norm_outflow = 0.0000f * norm_inflow + 0.0010f; break;
        case  3: norm_outflow = 0.0000f * norm_inflow + 0.0010f; break;
        case  4: norm_outflow = 1.6197f * norm_inflow + 0.0268f; break;
        case  5: norm_outflow = 1.5181f * norm_inflow + 0.2481f; break;
        case  6: norm_outflow = 1.4323f * norm_inflow + 0.0917f; break;
        case  7: norm_outflow = 0.2870f * norm_inflow + 0.2291f; break;
        case  8: norm_outflow = 0.1490f * norm_inflow + 0.2288f; break;
        case  9: norm_outflow = 2.2951f * norm_inflow + 0.1233f; break;
        case 10: norm_outflow = 1.9143f * norm_inflow + 0.1481f; break;
        case 11: norm_outflow = 0.0000f * norm_inflow + 0.0010f; break;
        case 12: norm_outflow = 0.0000f * norm_inflow + 0.0010f; break;
    }
    return norm_outflow * max_outflow_m3d;
}

static float rule_740(float inflow_m3d, float storage_m3, int month) {
    const float max_inflow_m3d   = 150903853.8f;
    const float max_outflow_m3d  = 96395180.0f;
    const float max_storage_m3   = 685013118.0f;
    const float norm_inflow  = inflow_m3d  / max_inflow_m3d;
    const float norm_storage = storage_m3  / max_storage_m3;
    float norm_outflow;

    switch (month) {
        case  1: norm_outflow = 1.5576f * norm_inflow + 0.0011f; break;
        case  2: norm_outflow = 1.4949f * norm_inflow + 0.0023f; break;
        case  3: norm_outflow = 0.7909f * norm_inflow + 0.0376f; break;
        case  4: norm_outflow = 0.9124f * norm_inflow + 0.0368f; break;
        case  5: norm_outflow = 0.7841f * norm_inflow + 0.0492f; break;
        case  6: norm_outflow = 1.0510f * norm_inflow + 0.0389f; break;
        case  7: norm_outflow = 1.0772f * norm_inflow + 0.0535f; break;
        case  8: norm_outflow = 1.2128f * norm_inflow + 0.0138f; break;
        case  9: norm_outflow = 1.3433f * norm_inflow + 0.0074f; break;
        case 10: norm_outflow = 0.5837f * norm_inflow + 0.0172f; break;
        case 11: norm_outflow = 0.9765f * norm_inflow + 0.0126f; break;
        case 12: norm_outflow = 1.6268f * norm_inflow + 0.0072f; break;
    }
    return norm_outflow * max_outflow_m3d;
}

static float rule_747(float inflow_m3d, float storage_m3, int month) {
    const float max_inflow_m3d   = 356120863.1f;
    const float max_outflow_m3d  = 254443899.4f;
    const float max_storage_m3   = 2254427695.6f;
    const float norm_inflow  = inflow_m3d  / max_inflow_m3d;
    const float norm_storage = storage_m3  / max_storage_m3;
    float norm_outflow;

    switch (month) {
        case  1: norm_outflow = 0.2190f * norm_inflow + 0.0179f; break;
        case  2: norm_outflow = 0.8409f * norm_inflow + 0.0141f; break;
        case  3: norm_outflow = 0.7792f * norm_inflow + 0.0331f; break;
        case  4: norm_outflow = 0.7882f * norm_inflow + 0.0413f; break;
        case  5: norm_outflow = 0.4842f * norm_inflow + 0.0819f; break;
        case  6: norm_outflow = 0.6702f * norm_inflow + 0.0773f; break;
        case  7: norm_outflow = 1.1369f * norm_inflow + 0.0640f; break;
        case  8: norm_outflow = 1.2468f * norm_inflow + 0.0299f; break;
        case  9: norm_outflow = 1.0585f * norm_inflow + 0.0173f; break;
        case 10: norm_outflow = 1.0879f * norm_inflow + 0.0071f; break;
        case 11: norm_outflow = 1.2892f * norm_inflow + 0.0026f; break;
        case 12: norm_outflow = 0.7265f * norm_inflow + 0.0189f; break;
    }
    return norm_outflow * max_outflow_m3d;
}

static float rule_136(float inflow_m3d, float storage_m3, int month) {
    const float max_inflow_m3d   = 28403798.5f;
    const float max_outflow_m3d  = 19399943.2f;
    const float max_storage_m3   = 2199541289.3f;
    const float norm_inflow  = inflow_m3d  / max_inflow_m3d;
    const float norm_storage = storage_m3  / max_storage_m3;
    float norm_outflow;

    switch (month) {
        case  1: norm_outflow = 0.0675f * norm_inflow + 0.0652f; break;
        case  2: norm_outflow = 0.1024f * norm_inflow + 0.0598f; break;
        case  3: norm_outflow = 0.5149f * norm_inflow + 0.0388f; break;
        case  4: norm_outflow = 0.5245f * norm_inflow + 0.0658f; break;
        case  5: norm_outflow = 0.5348f * norm_inflow + 0.0659f; break;
        case  6: norm_outflow = 0.4005f * norm_inflow + 0.1578f; break;
        case  7: norm_outflow = 0.1214f * norm_inflow + 0.3550f; break;
        case  8: norm_outflow = 0.4163f * norm_inflow + 0.2740f; break;
        case  9: norm_outflow = 0.7642f * norm_inflow + 0.0808f; break;
        case 10: norm_outflow = 0.3711f * norm_inflow + 0.0458f; break;
        case 11: norm_outflow = 0.2159f * norm_inflow + 0.0716f; break;
        case 12: norm_outflow = 0.1292f * norm_inflow + 0.0769f; break;
    }
    return norm_outflow * max_outflow_m3d;
}

static float rule_2646(float inflow_m3d, float storage_m3, int month) {
    const float max_inflow_m3d   = 8497607.0f;
    const float max_outflow_m3d  = 1785976.8f;
    const float max_storage_m3   = 40414972.2f;
    const float norm_inflow  = inflow_m3d  / max_inflow_m3d;
    const float norm_storage = storage_m3  / max_storage_m3;
    float norm_outflow;

    switch (month) {
        case  1: norm_outflow = 1.0307f * norm_inflow + 0.0296f; break;
        case  2: norm_outflow = 1.3952f * norm_inflow + 0.0378f; break;
        case  3: norm_outflow = 0.9353f * norm_inflow + 0.0722f; break;
        case  4: norm_outflow = 2.3657f * norm_inflow + 0.0695f; break;
        case  5: norm_outflow = 1.2905f * norm_inflow + 0.0815f; break;
        case  6: norm_outflow = 1.1828f * norm_inflow + 0.1058f; break;
        case  7: norm_outflow = 1.2975f * norm_inflow + 0.0667f; break;
        case  8: norm_outflow = 0.2695f * norm_inflow + 0.0539f; break;
        case  9: norm_outflow = 2.3882f * norm_inflow + 0.0352f; break;
        case 10: norm_outflow = 0.2823f * norm_inflow + 0.0507f; break;
        case 11: norm_outflow = 0.8097f * norm_inflow + 0.0449f; break;
        case 12: norm_outflow = 1.3352f * norm_inflow + 0.0273f; break;
    }
    return norm_outflow * max_outflow_m3d;
}

static float rule_2650(float inflow_m3d, float storage_m3, int month) {
    const float max_inflow_m3d   = 6883284.1f;
    const float max_outflow_m3d  = 5953912.0f;
    const float max_storage_m3   = 8260985.6f;
    const float norm_inflow  = inflow_m3d  / max_inflow_m3d;
    const float norm_storage = storage_m3  / max_storage_m3;
    float norm_outflow;

    switch (month) {
        case  1: norm_outflow = 1.1056f * norm_inflow + 0.0211f; break;
        case  2: norm_outflow = 1.1304f * norm_inflow + 0.0133f; break;
        case  3: norm_outflow = 1.1321f * norm_inflow + 0.0128f; break;
        case  4: norm_outflow = 1.1337f * norm_inflow + 0.0093f; break;
        case  5: norm_outflow = 1.1429f * norm_inflow + 0.0062f; break;
        case  6: norm_outflow = 1.1373f * norm_inflow + 0.0110f; break;
        case  7: norm_outflow = 1.0854f * norm_inflow + 0.0499f; break;
        case  8: norm_outflow = 1.1205f * norm_inflow + 0.0249f; break;
        case  9: norm_outflow = 1.1471f * norm_inflow + 0.0073f; break;
        case 10: norm_outflow = 1.1157f * norm_inflow + 0.0174f; break;
        case 11: norm_outflow = 1.1463f * norm_inflow + 0.0023f; break;
        case 12: norm_outflow = 1.1168f * norm_inflow + 0.0184f; break;
    }
    return norm_outflow * max_outflow_m3d;
}

static float rule_756(float inflow_m3d, float storage_m3, int month) {
    const float max_inflow_m3d   = 187054439.1f;
    const float max_outflow_m3d  = 45506252.2f;
    const float max_storage_m3   = 724796548.4f;
    const float norm_inflow  = inflow_m3d  / max_inflow_m3d;
    const float norm_storage = storage_m3  / max_storage_m3;
    float norm_outflow;

    switch (month) {
        case  1: norm_outflow = 1.8296f * norm_inflow + 0.0133f; break;
        case  2: norm_outflow = 1.2093f * norm_inflow + 0.0151f; break;
        case  3: norm_outflow = 1.1625f * norm_inflow + 0.0246f; break;
        case  4: norm_outflow = 1.1336f * norm_inflow + 0.0185f; break;
        case  5: norm_outflow = 1.0539f * norm_inflow + 0.0238f; break;
        case  6: norm_outflow = 1.1863f * norm_inflow + 0.0291f; break;
        case  7: norm_outflow = 1.1067f * norm_inflow + 0.0381f; break;
        case  8: norm_outflow = 1.4313f * norm_inflow + 0.0294f; break;
        case  9: norm_outflow = 0.5170f * norm_inflow + 0.0256f; break;
        case 10: norm_outflow = 0.8995f * norm_inflow + 0.0228f; break;
        case 11: norm_outflow = 1.4319f * norm_inflow + 0.0176f; break;
        case 12: norm_outflow = 1.1220f * norm_inflow + 0.0236f; break;
    }
    return norm_outflow * max_outflow_m3d;
}

static float rule_2682(float inflow_m3d, float storage_m3, int month) {
    const float max_inflow_m3d   = 44424906.6f;
    const float max_outflow_m3d  = 44424906.6f;
    const float max_storage_m3   = 57585013.8f;
    const float norm_inflow  = inflow_m3d  / max_inflow_m3d;
    const float norm_storage = storage_m3  / max_storage_m3;
    float norm_outflow;

    switch (month) {
        case  1: norm_outflow = 0.8362f * norm_inflow + 0.0084f; break;
        case  2: norm_outflow = 0.8512f * norm_inflow + 0.0093f; break;
        case  3: norm_outflow = 0.8643f * norm_inflow + 0.0081f; break;
        case  4: norm_outflow = 0.9170f * norm_inflow + 0.0044f; break;
        case  5: norm_outflow = 0.8425f * norm_inflow + 0.0072f; break;
        case  6: norm_outflow = 0.8044f * norm_inflow + 0.0108f; break;
        case  7: norm_outflow = 0.6365f * norm_inflow + 0.0193f; break;
        case  8: norm_outflow = 0.6428f * norm_inflow + 0.0193f; break;
        case  9: norm_outflow = 0.8936f * norm_inflow + 0.0059f; break;
        case 10: norm_outflow = 0.8344f * norm_inflow + 0.0074f; break;
        case 11: norm_outflow = 0.8982f * norm_inflow + 0.0045f; break;
        case 12: norm_outflow = 0.8855f * norm_inflow + 0.0066f; break;
    }
    return norm_outflow * max_outflow_m3d;
}

static float rule_775(float inflow_m3d, float storage_m3, int month) {
    const float max_inflow_m3d   = 18554986.8f;
    const float max_outflow_m3d  = 3669844.8f;
    const float max_storage_m3   = 526963625.2f;
    const float norm_inflow  = inflow_m3d  / max_inflow_m3d;
    const float norm_storage = storage_m3  / max_storage_m3;
    float norm_outflow;

    switch (month) {
        case  1: norm_outflow = 0.1820f * norm_inflow + 0.0128f; break;
        case  2: norm_outflow = 0.3502f * norm_inflow + 0.0112f; break;
        case  3: norm_outflow = 0.4120f * norm_inflow + 0.0325f; break;
        case  4: norm_outflow = 0.4121f * norm_inflow + 0.0333f; break;
        case  5: norm_outflow = 0.1035f * norm_inflow + 0.0329f; break;
        case  6: norm_outflow = 0.0109f * norm_inflow + 0.1536f; break;
        case  7: norm_outflow = 0.0000f * norm_inflow + 0.3128f; break;
        case  8: norm_outflow = 0.7909f * norm_inflow + 0.2328f; break;
        case  9: norm_outflow = 3.1513f * norm_inflow + 0.0615f; break;
        case 10: norm_outflow = 1.6930f * norm_inflow + 0.0269f; break;
        case 11: norm_outflow = 1.8979f * norm_inflow + 0.0161f; break;
        case 12: norm_outflow = 1.0521f * norm_inflow + 0.0095f; break;
    }
    return norm_outflow * max_outflow_m3d;
}

static float rule_2785(float inflow_m3d, float storage_m3, int month) {
    const float max_inflow_m3d   = 28086968.0f;
    const float max_outflow_m3d  = 3376274.8f;
    const float max_storage_m3   = 92069414.2f;
    const float norm_inflow  = inflow_m3d  / max_inflow_m3d;
    const float norm_storage = storage_m3  / max_storage_m3;
    float norm_outflow;

    switch (month) {
        case  1: norm_outflow = 0.9625f * norm_inflow + 0.0328f; break;
        case  2: norm_outflow = 0.6908f * norm_inflow + 0.0333f; break;
        case  3: norm_outflow = 1.1503f * norm_inflow + 0.0664f; break;
        case  4: norm_outflow = 1.1107f * norm_inflow + 0.0767f; break;
        case  5: norm_outflow = 1.3351f * norm_inflow + 0.1017f; break;
        case  6: norm_outflow = 0.9895f * norm_inflow + 0.0921f; break;
        case  7: norm_outflow = 1.3204f * norm_inflow + 0.0789f; break;
        case  8: norm_outflow = 0.7735f * norm_inflow + 0.0516f; break;
        case  9: norm_outflow = 0.9027f * norm_inflow + 0.0391f; break;
        case 10: norm_outflow = 1.1672f * norm_inflow + 0.0334f; break;
        case 11: norm_outflow = 1.2449f * norm_inflow + 0.0354f; break;
        case 12: norm_outflow = 1.2637f * norm_inflow + 0.0402f; break;
    }
    return norm_outflow * max_outflow_m3d;
}

static float rule_2789(float inflow_m3d, float storage_m3, int month) {
    const float max_inflow_m3d   = 5789168.9f;
    const float max_outflow_m3d  = 907719.6f;
    const float max_storage_m3   = 24724983.3f;
    const float norm_inflow  = inflow_m3d  / max_inflow_m3d;
    const float norm_storage = storage_m3  / max_storage_m3;
    float norm_outflow;

    switch (month) {
        case  1: norm_outflow = 4.7903f * norm_inflow + -0.0012f; break;
        case  2: norm_outflow = 2.6426f * norm_inflow + 0.0241f; break;
        case  3: norm_outflow = 4.0139f * norm_inflow + 0.0121f; break;
        case  4: norm_outflow = 3.3119f * norm_inflow + 0.0484f; break;
        case  5: norm_outflow = 2.3976f * norm_inflow + 0.0462f; break;
        case  6: norm_outflow = 2.1882f * norm_inflow + 0.0247f; break;
        case  7: norm_outflow = 0.0892f * norm_inflow + 0.0224f; break;
        case  8: norm_outflow = 1.1171f * norm_inflow + 0.0318f; break;
        case  9: norm_outflow = 0.6274f * norm_inflow + 0.0137f; break;
        case 10: norm_outflow = 2.4892f * norm_inflow + 0.0094f; break;
        case 11: norm_outflow = 4.7683f * norm_inflow + 0.0009f; break;
        case 12: norm_outflow = 5.1474f * norm_inflow + 0.0014f; break;
    }
    return norm_outflow * max_outflow_m3d;
}

static float rule_2794(float inflow_m3d, float storage_m3, int month) {
    const float max_inflow_m3d   = 10683079.1f;
    const float max_outflow_m3d  = 324691.5f;
    const float max_storage_m3   = 57356943.3f;
    const float norm_inflow  = inflow_m3d  / max_inflow_m3d;
    const float norm_storage = storage_m3  / max_storage_m3;
    float norm_outflow;

    switch (month) {
        case  1: norm_outflow = 0.1622f * norm_inflow + 0.0528f; break;
        case  2: norm_outflow = 6.1864f * norm_inflow + 0.0499f; break;
        case  3: norm_outflow = 1.1401f * norm_inflow + 0.0562f; break;
        case  4: norm_outflow = 0.1433f * norm_inflow + 0.0660f; break;
        case  5: norm_outflow = 2.2044f * norm_inflow + 0.0747f; break;
        case  6: norm_outflow = 0.1446f * norm_inflow + 0.0906f; break;
        case  7: norm_outflow = 0.0000f * norm_inflow + 0.1287f; break;
        case  8: norm_outflow = 0.2508f * norm_inflow + 0.1021f; break;
        case  9: norm_outflow = 0.0000f * norm_inflow + 0.0784f; break;
        case 10: norm_outflow = 0.0570f * norm_inflow + 0.0602f; break;
        case 11: norm_outflow = 0.8924f * norm_inflow + 0.0503f; break;
        case 12: norm_outflow = 1.1987f * norm_inflow + 0.0498f; break;
    }
    return norm_outflow * max_outflow_m3d;
}

static float rule_786(float inflow_m3d, float storage_m3, int month) {
    const float max_inflow_m3d   = 154488620.6f;
    const float max_outflow_m3d  = 126977300.7f;
    const float max_storage_m3   = 1306241751.7f;
    const float norm_inflow  = inflow_m3d  / max_inflow_m3d;
    const float norm_storage = storage_m3  / max_storage_m3;
    float norm_outflow;

    switch (month) {
        case  1: norm_outflow = 0.3194f * norm_inflow + 0.0184f; break;
        case  2: norm_outflow = 0.1626f * norm_inflow + 0.0228f; break;
        case  3: norm_outflow = 0.3729f * norm_inflow + 0.0390f; break;
        case  4: norm_outflow = 0.1519f * norm_inflow + 0.0346f; break;
        case  5: norm_outflow = 0.2487f * norm_inflow + 0.0396f; break;
        case  6: norm_outflow = 0.2839f * norm_inflow + 0.0363f; break;
        case  7: norm_outflow = 0.4582f * norm_inflow + 0.0426f; break;
        case  8: norm_outflow = 1.1807f * norm_inflow + 0.0170f; break;
        case  9: norm_outflow = 0.2877f * norm_inflow + 0.0181f; break;
        case 10: norm_outflow = 0.3164f * norm_inflow + 0.0207f; break;
        case 11: norm_outflow = 0.2943f * norm_inflow + 0.0187f; break;
        case 12: norm_outflow = 0.5160f * norm_inflow + 0.0175f; break;
    }
    return norm_outflow * max_outflow_m3d;
}

static float rule_790(float inflow_m3d, float storage_m3, int month) {
    const float max_inflow_m3d   = 119090104.8f;
    const float max_outflow_m3d  = 12235558.8f;
    const float max_storage_m3   = 1136408824.4f;
    const float norm_inflow  = inflow_m3d  / max_inflow_m3d;
    const float norm_storage = storage_m3  / max_storage_m3;
    float norm_outflow;

    switch (month) {
        case  1: norm_outflow = 11.9216f * norm_inflow + 0.0110f; break;
        case  2: norm_outflow = 4.0177f * norm_inflow + 0.0261f; break;
        case  3: norm_outflow = 1.0153f * norm_inflow + 0.0382f; break;
        case  4: norm_outflow = 0.7582f * norm_inflow + 0.0314f; break;
        case  5: norm_outflow = 0.5130f * norm_inflow + 0.0456f; break;
        case  6: norm_outflow = 0.7451f * norm_inflow + 0.0835f; break;
        case  7: norm_outflow = 0.2146f * norm_inflow + 0.0819f; break;
        case  8: norm_outflow = 2.4875f * norm_inflow + 0.0695f; break;
        case  9: norm_outflow = 4.1654f * norm_inflow + 0.0495f; break;
        case 10: norm_outflow = 1.5316f * norm_inflow + 0.0363f; break;
        case 11: norm_outflow = 1.5418f * norm_inflow + 0.0423f; break;
        case 12: norm_outflow = 7.1995f * norm_inflow + 0.0320f; break;
    }
    return norm_outflow * max_outflow_m3d;
}

static float rule_795(float inflow_m3d, float storage_m3, int month) {
    const float max_inflow_m3d   = 24776876.9f;
    const float max_outflow_m3d  = 2446591.2f;
    const float max_storage_m3   = 178427815.9f;
    const float norm_inflow  = inflow_m3d  / max_inflow_m3d;
    const float norm_storage = storage_m3  / max_storage_m3;
    float norm_outflow;

    switch (month) {
        case  1: norm_outflow = 0.1221f * norm_inflow + 0.0192f; break;
        case  2: norm_outflow = 5.3924f * norm_inflow + 0.0041f; break;
        case  3: norm_outflow = 2.0597f * norm_inflow + 0.0122f; break;
        case  4: norm_outflow = 0.1059f * norm_inflow + 0.0213f; break;
        case  5: norm_outflow = 0.3318f * norm_inflow + 0.0272f; break;
        case  6: norm_outflow = 6.4448f * norm_inflow + 0.0545f; break;
        case  7: norm_outflow = 0.9893f * norm_inflow + 0.1075f; break;
        case  8: norm_outflow = 0.0000f * norm_inflow + 0.0658f; break;
        case  9: norm_outflow = 0.0564f * norm_inflow + 0.0057f; break;
        case 10: norm_outflow = 0.7914f * norm_inflow + 0.0230f; break;
        case 11: norm_outflow = 2.4830f * norm_inflow + 0.0076f; break;
        case 12: norm_outflow = 0.2184f * norm_inflow + 0.0244f; break;
    }
    return norm_outflow * max_outflow_m3d;
}

static float rule_796(float inflow_m3d, float storage_m3, int month) {
    const float max_inflow_m3d   = 46513720.8f;
    const float max_outflow_m3d  = 19107734.6f;
    const float max_storage_m3   = 283348858.2f;
    const float norm_inflow  = inflow_m3d  / max_inflow_m3d;
    const float norm_storage = storage_m3  / max_storage_m3;
    float norm_outflow;

    switch (month) {
        case  1: norm_outflow = 0.6303f * norm_inflow + 0.0161f; break;
        case  2: norm_outflow = 0.3803f * norm_inflow + 0.0102f; break;
        case  3: norm_outflow = 0.3518f * norm_inflow + 0.0169f; break;
        case  4: norm_outflow = 0.4045f * norm_inflow + 0.0164f; break;
        case  5: norm_outflow = 0.3796f * norm_inflow + 0.0249f; break;
        case  6: norm_outflow = 0.3011f * norm_inflow + 0.0369f; break;
        case  7: norm_outflow = 0.5492f * norm_inflow + 0.0295f; break;
        case  8: norm_outflow = 0.7799f * norm_inflow + 0.0159f; break;
        case  9: norm_outflow = 0.3433f * norm_inflow + 0.0133f; break;
        case 10: norm_outflow = 0.3564f * norm_inflow + 0.0173f; break;
        case 11: norm_outflow = 0.5490f * norm_inflow + 0.0135f; break;
        case 12: norm_outflow = 0.3396f * norm_inflow + 0.0146f; break;
    }
    return norm_outflow * max_outflow_m3d;
}

static float rule_800(float inflow_m3d, float storage_m3, int month) {
    const float max_inflow_m3d   = 250605715.3f;
    const float max_outflow_m3d  = 145571337.9f;
    const float max_storage_m3   = 2896058088.5f;
    const float norm_inflow  = inflow_m3d  / max_inflow_m3d;
    const float norm_storage = storage_m3  / max_storage_m3;
    float norm_outflow;

    switch (month) {
        case  1: norm_outflow = 0.9178f * norm_inflow + 0.0092f; break;
        case  2: norm_outflow = 0.5969f * norm_inflow + 0.0147f; break;
        case  3: norm_outflow = 0.2180f * norm_inflow + 0.0235f; break;
        case  4: norm_outflow = 0.6062f * norm_inflow + 0.0248f; break;
        case  5: norm_outflow = 0.2732f * norm_inflow + 0.0488f; break;
        case  6: norm_outflow = 0.1651f * norm_inflow + 0.0776f; break;
        case  7: norm_outflow = 0.6435f * norm_inflow + 0.0529f; break;
        case  8: norm_outflow = 1.2215f * norm_inflow + 0.0255f; break;
        case  9: norm_outflow = 0.5055f * norm_inflow + 0.0239f; break;
        case 10: norm_outflow = 0.3990f * norm_inflow + 0.0219f; break;
        case 11: norm_outflow = 0.5121f * norm_inflow + 0.0217f; break;
        case 12: norm_outflow = 0.2255f * norm_inflow + 0.0269f; break;
    }
    return norm_outflow * max_outflow_m3d;
}

static float rule_801(float inflow_m3d, float storage_m3, int month) {
    const float max_inflow_m3d   = 114093203.4f;
    const float max_outflow_m3d  = 34252062.7f;
    const float max_storage_m3   = 903419254.2f;
    const float norm_inflow  = inflow_m3d  / max_inflow_m3d;
    const float norm_storage = storage_m3  / max_storage_m3;
    float norm_outflow;

    switch (month) {
        case  1: norm_outflow = 0.2401f * norm_inflow + 0.0090f; break;
        case  2: norm_outflow = 0.3289f * norm_inflow + 0.0242f; break;
        case  3: norm_outflow = 0.2596f * norm_inflow + 0.0365f; break;
        case  4: norm_outflow = 0.1537f * norm_inflow + 0.0707f; break;
        case  5: norm_outflow = 0.1183f * norm_inflow + 0.0750f; break;
        case  6: norm_outflow = 0.0665f * norm_inflow + 0.1066f; break;
        case  7: norm_outflow = 0.0199f * norm_inflow + 0.0770f; break;
        case  8: norm_outflow = 0.6450f * norm_inflow + 0.0453f; break;
        case  9: norm_outflow = 0.6054f * norm_inflow + 0.0203f; break;
        case 10: norm_outflow = 0.5800f * norm_inflow + 0.0418f; break;
        case 11: norm_outflow = 0.5366f * norm_inflow + 0.0265f; break;
        case 12: norm_outflow = 0.7077f * norm_inflow + 0.0319f; break;
    }
    return norm_outflow * max_outflow_m3d;
}

static float rule_803(float inflow_m3d, float storage_m3, int month) {
    const float max_inflow_m3d   = 111895269.0f;
    const float max_outflow_m3d  = 81470962.2f;
    const float max_storage_m3   = 1660618088.8f;
    const float norm_inflow  = inflow_m3d  / max_inflow_m3d;
    const float norm_storage = storage_m3  / max_storage_m3;
    float norm_outflow;

    switch (month) {
        case  1: norm_outflow = 0.8231f * norm_inflow + 0.0082f; break;
        case  2: norm_outflow = 0.4138f * norm_inflow + 0.0094f; break;
        case  3: norm_outflow = 0.1340f * norm_inflow + 0.0116f; break;
        case  4: norm_outflow = 0.5773f * norm_inflow + 0.0086f; break;
        case  5: norm_outflow = 0.2846f * norm_inflow + 0.0216f; break;
        case  6: norm_outflow = 0.4043f * norm_inflow + 0.0279f; break;
        case  7: norm_outflow = 0.5496f * norm_inflow + 0.0273f; break;
        case  8: norm_outflow = 1.4528f * norm_inflow + 0.0079f; break;
        case  9: norm_outflow = 0.7326f * norm_inflow + 0.0116f; break;
        case 10: norm_outflow = 0.3994f * norm_inflow + 0.0150f; break;
        case 11: norm_outflow = 0.5688f * norm_inflow + 0.0135f; break;
        case 12: norm_outflow = 0.3373f * norm_inflow + 0.0242f; break;
    }
    return norm_outflow * max_outflow_m3d;
}

static float rule_2863(float inflow_m3d, float storage_m3, int month) {
    const float max_inflow_m3d   = 13596399.9f;
    const float max_outflow_m3d  = 5632794.4f;
    const float max_storage_m3   = 28090040.0f;
    const float norm_inflow  = inflow_m3d  / max_inflow_m3d;
    const float norm_storage = storage_m3  / max_storage_m3;
    float norm_outflow;

    switch (month) {
        case  1: norm_outflow = 1.5742f * norm_inflow + 0.0023f; break;
        case  2: norm_outflow = 1.3814f * norm_inflow + 0.0030f; break;
        case  3: norm_outflow = 1.4326f * norm_inflow + 0.0056f; break;
        case  4: norm_outflow = 1.2000f * norm_inflow + 0.0099f; break;
        case  5: norm_outflow = 0.9157f * norm_inflow + 0.0237f; break;
        case  6: norm_outflow = 1.2614f * norm_inflow + 0.0129f; break;
        case  7: norm_outflow = 1.1146f * norm_inflow + 0.0083f; break;
        case  8: norm_outflow = 1.2118f * norm_inflow + 0.0060f; break;
        case  9: norm_outflow = 1.1513f * norm_inflow + 0.0059f; break;
        case 10: norm_outflow = 0.8422f * norm_inflow + 0.0063f; break;
        case 11: norm_outflow = 1.3101f * norm_inflow + 0.0033f; break;
        case 12: norm_outflow = 1.3173f * norm_inflow + 0.0043f; break;
    }
    return norm_outflow * max_outflow_m3d;
}

static float rule_2873(float inflow_m3d, float storage_m3, int month) {
    const float max_inflow_m3d   = 19975151.0f;
    const float max_outflow_m3d  = 2833148.5f;
    const float max_storage_m3   = 45751006.7f;
    const float norm_inflow  = inflow_m3d  / max_inflow_m3d;
    const float norm_storage = storage_m3  / max_storage_m3;
    float norm_outflow;

    switch (month) {
        case  1: norm_outflow = 2.4549f * norm_inflow + 0.0099f; break;
        case  2: norm_outflow = 2.2270f * norm_inflow + 0.0185f; break;
        case  3: norm_outflow = 1.9488f * norm_inflow + 0.0280f; break;
        case  4: norm_outflow = 2.5725f * norm_inflow + 0.0291f; break;
        case  5: norm_outflow = 1.6588f * norm_inflow + 0.0626f; break;
        case  6: norm_outflow = 2.5758f * norm_inflow + 0.0449f; break;
        case  7: norm_outflow = 2.6481f * norm_inflow + 0.0199f; break;
        case  8: norm_outflow = 1.3737f * norm_inflow + 0.0129f; break;
        case  9: norm_outflow = 2.2519f * norm_inflow + 0.0178f; break;
        case 10: norm_outflow = 2.8113f * norm_inflow + 0.0176f; break;
        case 11: norm_outflow = 2.1856f * norm_inflow + 0.0152f; break;
        case 12: norm_outflow = 2.7036f * norm_inflow + 0.0109f; break;
    }
    return norm_outflow * max_outflow_m3d;
}

static float rule_806(float inflow_m3d, float storage_m3, int month) {
    const float max_inflow_m3d   = 61022819.5f;
    const float max_outflow_m3d  = 15511358.5f;
    const float max_storage_m3   = 333794465.6f;
    const float norm_inflow  = inflow_m3d  / max_inflow_m3d;
    const float norm_storage = storage_m3  / max_storage_m3;
    float norm_outflow;

    switch (month) {
        case  1: norm_outflow = 1.3836f * norm_inflow + 0.0142f; break;
        case  2: norm_outflow = 1.0694f * norm_inflow + 0.0148f; break;
        case  3: norm_outflow = 0.7513f * norm_inflow + 0.0277f; break;
        case  4: norm_outflow = 0.5764f * norm_inflow + 0.0397f; break;
        case  5: norm_outflow = 0.5868f * norm_inflow + 0.0652f; break;
        case  6: norm_outflow = 0.8275f * norm_inflow + 0.0710f; break;
        case  7: norm_outflow = 0.9130f * norm_inflow + 0.0432f; break;
        case  8: norm_outflow = 1.4170f * norm_inflow + 0.0224f; break;
        case  9: norm_outflow = 0.8199f * norm_inflow + 0.0155f; break;
        case 10: norm_outflow = 0.9884f * norm_inflow + 0.0205f; break;
        case 11: norm_outflow = 0.8300f * norm_inflow + 0.0177f; break;
        case 12: norm_outflow = 1.0668f * norm_inflow + 0.0176f; break;
    }
    return norm_outflow * max_outflow_m3d;
}

static float rule_2893(float inflow_m3d, float storage_m3, int month) {
    const float max_inflow_m3d   = 45730844.2f;
    const float max_outflow_m3d  = 7608823.5f;
    const float max_storage_m3   = 178147816.0f;
    const float norm_inflow  = inflow_m3d  / max_inflow_m3d;
    const float norm_storage = storage_m3  / max_storage_m3;
    float norm_outflow;

    switch (month) {
        case  1: norm_outflow = 0.7562f * norm_inflow + 0.0106f; break;
        case  2: norm_outflow = 0.2474f * norm_inflow + 0.0207f; break;
        case  3: norm_outflow = 0.3178f * norm_inflow + 0.0357f; break;
        case  4: norm_outflow = 0.1671f * norm_inflow + 0.0513f; break;
        case  5: norm_outflow = 0.0826f * norm_inflow + 0.0803f; break;
        case  6: norm_outflow = 0.1076f * norm_inflow + 0.0830f; break;
        case  7: norm_outflow = 0.0469f * norm_inflow + 0.0463f; break;
        case  8: norm_outflow = 0.2419f * norm_inflow + 0.0270f; break;
        case  9: norm_outflow = 0.2941f * norm_inflow + 0.0168f; break;
        case 10: norm_outflow = 0.1429f * norm_inflow + 0.0207f; break;
        case 11: norm_outflow = 0.1106f * norm_inflow + 0.0245f; break;
        case 12: norm_outflow = 0.3304f * norm_inflow + 0.0148f; break;
    }
    return norm_outflow * max_outflow_m3d;
}

static float rule_811(float inflow_m3d, float storage_m3, int month) {
    const float max_inflow_m3d   = 62817952.1f;
    const float max_outflow_m3d  = 7608837.3f;
    const float max_storage_m3   = 250601197.7f;
    const float norm_inflow  = inflow_m3d  / max_inflow_m3d;
    const float norm_storage = storage_m3  / max_storage_m3;
    float norm_outflow;

    switch (month) {
        case  1: norm_outflow = 0.6211f * norm_inflow + 0.0319f; break;
        case  2: norm_outflow = 0.5474f * norm_inflow + 0.0323f; break;
        case  3: norm_outflow = 0.1371f * norm_inflow + 0.0568f; break;
        case  4: norm_outflow = 0.0522f * norm_inflow + 0.0722f; break;
        case  5: norm_outflow = 0.0000f * norm_inflow + 0.1144f; break;
        case  6: norm_outflow = 0.1784f * norm_inflow + 0.1564f; break;
        case  7: norm_outflow = 0.0539f * norm_inflow + 0.0755f; break;
        case  8: norm_outflow = 0.5973f * norm_inflow + 0.0234f; break;
        case  9: norm_outflow = 0.3411f * norm_inflow + 0.0181f; break;
        case 10: norm_outflow = 0.0904f * norm_inflow + 0.0298f; break;
        case 11: norm_outflow = 0.2113f * norm_inflow + 0.0452f; break;
        case 12: norm_outflow = 0.5199f * norm_inflow + 0.0519f; break;
    }
    return norm_outflow * max_outflow_m3d;
}

static float rule_813(float inflow_m3d, float storage_m3, int month) {
    const float max_inflow_m3d   = 71707821.4f;
    const float max_outflow_m3d  = 16440969.2f;
    const float max_storage_m3   = 477813024.3f;
    const float norm_inflow  = inflow_m3d  / max_inflow_m3d;
    const float norm_storage = storage_m3  / max_storage_m3;
    float norm_outflow;

    switch (month) {
        case  1: norm_outflow = 2.2031f * norm_inflow + 0.0048f; break;
        case  2: norm_outflow = 1.6735f * norm_inflow + 0.0078f; break;
        case  3: norm_outflow = 0.7065f * norm_inflow + 0.0118f; break;
        case  4: norm_outflow = 0.8044f * norm_inflow + 0.0249f; break;
        case  5: norm_outflow = 0.5087f * norm_inflow + 0.0439f; break;
        case  6: norm_outflow = 1.3702f * norm_inflow + 0.0492f; break;
        case  7: norm_outflow = 0.7046f * norm_inflow + 0.0267f; break;
        case  8: norm_outflow = 1.5587f * norm_inflow + 0.0442f; break;
        case  9: norm_outflow = 1.7526f * norm_inflow + 0.0270f; break;
        case 10: norm_outflow = 1.5887f * norm_inflow + 0.0138f; break;
        case 11: norm_outflow = 0.7509f * norm_inflow + 0.0104f; break;
        case 12: norm_outflow = 2.5380f * norm_inflow + 0.0093f; break;
    }
    return norm_outflow * max_outflow_m3d;
}

static float rule_814(float inflow_m3d, float storage_m3, int month) {
    const float max_inflow_m3d   = 68036157.0f;
    const float max_outflow_m3d  = 7339693.2f;
    const float max_storage_m3   = 387017918.3f;
    const float norm_inflow  = inflow_m3d  / max_inflow_m3d;
    const float norm_storage = storage_m3  / max_storage_m3;
    float norm_outflow;

    switch (month) {
        case  1: norm_outflow = 0.4897f * norm_inflow + 0.0398f; break;
        case  2: norm_outflow = 0.4926f * norm_inflow + 0.0379f; break;
        case  3: norm_outflow = 0.0000f * norm_inflow + 0.0656f; break;
        case  4: norm_outflow = 0.0000f * norm_inflow + 0.0654f; break;
        case  5: norm_outflow = 0.0000f * norm_inflow + 0.1059f; break;
        case  6: norm_outflow = 0.0000f * norm_inflow + 0.1551f; break;
        case  7: norm_outflow = 0.0439f * norm_inflow + 0.0815f; break;
        case  8: norm_outflow = 0.0000f * norm_inflow + 0.0317f; break;
        case  9: norm_outflow = 0.0479f * norm_inflow + 0.0242f; break;
        case 10: norm_outflow = 0.0354f * norm_inflow + 0.0277f; break;
        case 11: norm_outflow = 0.0189f * norm_inflow + 0.0542f; break;
        case 12: norm_outflow = 0.3561f * norm_inflow + 0.0682f; break;
    }
    return norm_outflow * max_outflow_m3d;
}

static float rule_818(float inflow_m3d, float storage_m3, int month) {
    const float max_inflow_m3d   = 37751847.8f;
    const float max_outflow_m3d  = 9786302.2f;
    const float max_storage_m3   = 177854247.7f;
    const float norm_inflow  = inflow_m3d  / max_inflow_m3d;
    const float norm_storage = storage_m3  / max_storage_m3;
    float norm_outflow;

    switch (month) {
        case  1: norm_outflow = 0.0489f * norm_inflow + 0.0049f; break;
        case  2: norm_outflow = 0.6348f * norm_inflow + 0.0073f; break;
        case  3: norm_outflow = 0.3385f * norm_inflow + 0.0119f; break;
        case  4: norm_outflow = 0.2886f * norm_inflow + 0.0208f; break;
        case  5: norm_outflow = 0.2557f * norm_inflow + 0.0364f; break;
        case  6: norm_outflow = 0.0670f * norm_inflow + 0.0313f; break;
        case  7: norm_outflow = 0.1967f * norm_inflow + 0.0258f; break;
        case  8: norm_outflow = 0.1868f * norm_inflow + 0.0144f; break;
        case  9: norm_outflow = 0.1532f * norm_inflow + 0.0063f; break;
        case 10: norm_outflow = 0.1098f * norm_inflow + 0.0089f; break;
        case 11: norm_outflow = 0.0762f * norm_inflow + 0.0084f; break;
        case 12: norm_outflow = 0.1713f * norm_inflow + 0.0132f; break;
    }
    return norm_outflow * max_outflow_m3d;
}

static float rule_821(float inflow_m3d, float storage_m3, int month) {
    const float max_inflow_m3d   = 29919079.2f;
    const float max_outflow_m3d  = 27689344.2f;
    const float max_storage_m3   = 363513956.9f;
    const float norm_inflow  = inflow_m3d  / max_inflow_m3d;
    const float norm_storage = storage_m3  / max_storage_m3;
    float norm_outflow;

    switch (month) {
        case  1: norm_outflow = 0.1831f * norm_inflow + 0.0071f; break;
        case  2: norm_outflow = 0.0619f * norm_inflow + 0.0129f; break;
        case  3: norm_outflow = 0.4307f * norm_inflow + 0.0159f; break;
        case  4: norm_outflow = 0.3024f * norm_inflow + 0.0478f; break;
        case  5: norm_outflow = 0.8190f * norm_inflow + 0.0367f; break;
        case  6: norm_outflow = 0.9661f * norm_inflow + 0.0279f; break;
        case  7: norm_outflow = 0.8792f * norm_inflow + 0.0434f; break;
        case  8: norm_outflow = 0.8512f * norm_inflow + 0.0357f; break;
        case  9: norm_outflow = 1.0112f * norm_inflow + 0.0143f; break;
        case 10: norm_outflow = 0.8486f * norm_inflow + 0.0089f; break;
        case 11: norm_outflow = 0.4925f * norm_inflow + 0.0075f; break;
        case 12: norm_outflow = 0.1738f * norm_inflow + 0.0084f; break;
    }
    return norm_outflow * max_outflow_m3d;
}

static float rule_142(float inflow_m3d, float storage_m3, int month) {
    const float max_inflow_m3d   = 1088088954.5f;
    const float max_outflow_m3d  = 174012708.3f;
    const float max_storage_m3   = 6193533740.8f;
    const float norm_inflow  = inflow_m3d  / max_inflow_m3d;
    const float norm_storage = storage_m3  / max_storage_m3;
    float norm_outflow;

    switch (month) {
        case  1: norm_outflow = 2.7624f * norm_inflow + 0.0551f; break;
        case  2: norm_outflow = 1.4754f * norm_inflow + 0.0754f; break;
        case  3: norm_outflow = 2.7075f * norm_inflow + 0.0906f; break;
        case  4: norm_outflow = 0.9164f * norm_inflow + 0.1665f; break;
        case  5: norm_outflow = 1.0076f * norm_inflow + 0.1862f; break;
        case  6: norm_outflow = 1.6767f * norm_inflow + 0.1815f; break;
        case  7: norm_outflow = 1.4952f * norm_inflow + 0.1233f; break;
        case  8: norm_outflow = 3.6203f * norm_inflow + 0.0435f; break;
        case  9: norm_outflow = 1.2144f * norm_inflow + 0.0380f; break;
        case 10: norm_outflow = 1.0603f * norm_inflow + 0.0718f; break;
        case 11: norm_outflow = 2.5759f * norm_inflow + 0.0619f; break;
        case 12: norm_outflow = 3.2588f * norm_inflow + 0.0595f; break;
    }
    return norm_outflow * max_outflow_m3d;
}

static float rule_822(float inflow_m3d, float storage_m3, int month) {
    const float max_inflow_m3d   = 291808375.2f;
    const float max_outflow_m3d  = 57005226.4f;
    const float max_storage_m3   = 803444466.7f;
    const float norm_inflow  = inflow_m3d  / max_inflow_m3d;
    const float norm_storage = storage_m3  / max_storage_m3;
    float norm_outflow;

    switch (month) {
        case  1: norm_outflow = 2.7416f * norm_inflow + 0.0180f; break;
        case  2: norm_outflow = 1.2803f * norm_inflow + 0.0294f; break;
        case  3: norm_outflow = 1.7187f * norm_inflow + 0.0513f; break;
        case  4: norm_outflow = 1.2665f * norm_inflow + 0.0682f; break;
        case  5: norm_outflow = 0.9496f * norm_inflow + 0.0880f; break;
        case  6: norm_outflow = 1.5407f * norm_inflow + 0.1118f; break;
        case  7: norm_outflow = 1.6322f * norm_inflow + 0.0683f; break;
        case  8: norm_outflow = 1.8783f * norm_inflow + 0.0415f; break;
        case  9: norm_outflow = 1.1558f * norm_inflow + 0.0309f; break;
        case 10: norm_outflow = 0.8893f * norm_inflow + 0.0314f; break;
        case 11: norm_outflow = 1.0229f * norm_inflow + 0.0360f; break;
        case 12: norm_outflow = 1.7564f * norm_inflow + 0.0268f; break;
    }
    return norm_outflow * max_outflow_m3d;
}

static float rule_143(float inflow_m3d, float storage_m3, int month) {
    const float max_inflow_m3d   = 615125286.6f;
    const float max_outflow_m3d  = 128689686.4f;
    const float max_storage_m3   = 784428399.0f;
    const float norm_inflow  = inflow_m3d  / max_inflow_m3d;
    const float norm_storage = storage_m3  / max_storage_m3;
    float norm_outflow;

    switch (month) {
        case  1: norm_outflow = 2.9643f * norm_inflow + 0.0558f; break;
        case  2: norm_outflow = 0.6833f * norm_inflow + 0.1799f; break;
        case  3: norm_outflow = 1.6113f * norm_inflow + 0.1780f; break;
        case  4: norm_outflow = 0.9578f * norm_inflow + 0.1585f; break;
        case  5: norm_outflow = 2.9843f * norm_inflow + 0.1292f; break;
        case  6: norm_outflow = 3.2072f * norm_inflow + 0.1029f; break;
        case  7: norm_outflow = 1.8439f * norm_inflow + 0.0915f; break;
        case  8: norm_outflow = 0.7639f * norm_inflow + 0.0657f; break;
        case  9: norm_outflow = 0.5837f * norm_inflow + 0.0683f; break;
        case 10: norm_outflow = 1.5755f * norm_inflow + 0.0723f; break;
        case 11: norm_outflow = 2.7846f * norm_inflow + 0.0583f; break;
        case 12: norm_outflow = 1.8566f * norm_inflow + 0.0938f; break;
    }
    return norm_outflow * max_outflow_m3d;
}

static float rule_828(float inflow_m3d, float storage_m3, int month) {
    const float max_inflow_m3d   = 62503226.2f;
    const float max_outflow_m3d  = 8122639.5f;
    const float max_storage_m3   = 562033928.5f;
    const float norm_inflow  = inflow_m3d  / max_inflow_m3d;
    const float norm_storage = storage_m3  / max_storage_m3;
    float norm_outflow;

    switch (month) {
        case  1: norm_outflow = 5.5584f * norm_inflow + -0.0330f; break;
        case  2: norm_outflow = 1.6895f * norm_inflow + -0.0054f; break;
        case  3: norm_outflow = 3.9983f * norm_inflow + -0.0058f; break;
        case  4: norm_outflow = 3.1982f * norm_inflow + 0.0811f; break;
        case  5: norm_outflow = 0.8685f * norm_inflow + 0.1439f; break;
        case  6: norm_outflow = 0.1783f * norm_inflow + 0.2088f; break;
        case  7: norm_outflow = 4.4922f * norm_inflow + 0.1722f; break;
        case  8: norm_outflow = 0.9868f * norm_inflow + 0.1151f; break;
        case  9: norm_outflow = 3.1521f * norm_inflow + 0.0686f; break;
        case 10: norm_outflow = 2.7364f * norm_inflow + 0.0377f; break;
        case 11: norm_outflow = 0.0000f * norm_inflow + 0.0042f; break;
        case 12: norm_outflow = 4.2467f * norm_inflow + -0.0243f; break;
    }
    return norm_outflow * max_outflow_m3d;
}

static float rule_833(float inflow_m3d, float storage_m3, int month) {
    const float max_inflow_m3d   = 131172709.0f;
    const float max_outflow_m3d  = 9345908.2f;
    const float max_storage_m3   = 623677091.5f;
    const float norm_inflow  = inflow_m3d  / max_inflow_m3d;
    const float norm_storage = storage_m3  / max_storage_m3;
    float norm_outflow;

    switch (month) {
        case  1: norm_outflow = 1.1776f * norm_inflow + 0.1582f; break;
        case  2: norm_outflow = 0.5526f * norm_inflow + 0.1529f; break;
        case  3: norm_outflow = 1.3616f * norm_inflow + 0.2015f; break;
        case  4: norm_outflow = 0.9718f * norm_inflow + 0.2382f; break;
        case  5: norm_outflow = 1.0296f * norm_inflow + 0.2471f; break;
        case  6: norm_outflow = 1.3511f * norm_inflow + 0.2194f; break;
        case  7: norm_outflow = 1.3033f * norm_inflow + 0.1180f; break;
        case  8: norm_outflow = 1.8029f * norm_inflow + 0.0621f; break;
        case  9: norm_outflow = 0.6086f * norm_inflow + 0.0430f; break;
        case 10: norm_outflow = 0.3294f * norm_inflow + 0.0768f; break;
        case 11: norm_outflow = 1.3586f * norm_inflow + 0.1080f; break;
        case 12: norm_outflow = 1.6617f * norm_inflow + 0.1316f; break;
    }
    return norm_outflow * max_outflow_m3d;
}

static float rule_834(float inflow_m3d, float storage_m3, int month) {
    const float max_inflow_m3d   = 74531806.2f;
    const float max_outflow_m3d  = 10216923.2f;
    const float max_storage_m3   = 288101456.6f;
    const float norm_inflow  = inflow_m3d  / max_inflow_m3d;
    const float norm_storage = storage_m3  / max_storage_m3;
    float norm_outflow;

    switch (month) {
        case  1: norm_outflow = 0.7412f * norm_inflow + 0.0109f; break;
        case  2: norm_outflow = 0.4450f * norm_inflow + 0.0157f; break;
        case  3: norm_outflow = 0.1935f * norm_inflow + 0.0248f; break;
        case  4: norm_outflow = 0.3245f * norm_inflow + 0.0246f; break;
        case  5: norm_outflow = 0.2578f * norm_inflow + 0.0502f; break;
        case  6: norm_outflow = 0.4252f * norm_inflow + 0.0548f; break;
        case  7: norm_outflow = 0.5582f * norm_inflow + 0.0352f; break;
        case  8: norm_outflow = 0.2694f * norm_inflow + 0.0215f; break;
        case  9: norm_outflow = 0.2876f * norm_inflow + 0.0204f; break;
        case 10: norm_outflow = 0.1425f * norm_inflow + 0.0180f; break;
        case 11: norm_outflow = 0.3096f * norm_inflow + 0.0210f; break;
        case 12: norm_outflow = 0.7456f * norm_inflow + 0.0146f; break;
    }
    return norm_outflow * max_outflow_m3d;
}

static float rule_2956(float inflow_m3d, float storage_m3, int month) {
    const float max_inflow_m3d   = 179590947.4f;
    const float max_outflow_m3d  = 51082045.3f;
    const float max_storage_m3   = 281073087.6f;
    const float norm_inflow  = inflow_m3d  / max_inflow_m3d;
    const float norm_storage = storage_m3  / max_storage_m3;
    float norm_outflow;

    switch (month) {
        case  1: norm_outflow = 0.6953f * norm_inflow + 0.0090f; break;
        case  2: norm_outflow = 0.3540f * norm_inflow + 0.0154f; break;
        case  3: norm_outflow = 0.2451f * norm_inflow + 0.0307f; break;
        case  4: norm_outflow = 0.1734f * norm_inflow + 0.0338f; break;
        case  5: norm_outflow = 0.3039f * norm_inflow + 0.0379f; break;
        case  6: norm_outflow = 0.1070f * norm_inflow + 0.0485f; break;
        case  7: norm_outflow = 1.4515f * norm_inflow + 0.0179f; break;
        case  8: norm_outflow = 0.3826f * norm_inflow + 0.0144f; break;
        case  9: norm_outflow = 0.2719f * norm_inflow + 0.0143f; break;
        case 10: norm_outflow = 0.3284f * norm_inflow + 0.0143f; break;
        case 11: norm_outflow = 0.6150f * norm_inflow + 0.0177f; break;
        case 12: norm_outflow = 0.5822f * norm_inflow + 0.0125f; break;
    }
    return norm_outflow * max_outflow_m3d;
}

static float rule_838(float inflow_m3d, float storage_m3, int month) {
    const float max_inflow_m3d   = 215856733.9f;
    const float max_outflow_m3d  = 15684969.4f;
    const float max_storage_m3   = 1704767545.0f;
    const float norm_inflow  = inflow_m3d  / max_inflow_m3d;
    const float norm_storage = storage_m3  / max_storage_m3;
    float norm_outflow;

    switch (month) {
        case  1: norm_outflow = 1.2664f * norm_inflow + 0.1390f; break;
        case  2: norm_outflow = 0.4719f * norm_inflow + 0.1427f; break;
        case  3: norm_outflow = 0.6044f * norm_inflow + 0.1527f; break;
        case  4: norm_outflow = 0.1550f * norm_inflow + 0.2093f; break;
        case  5: norm_outflow = 0.0000f * norm_inflow + 0.2472f; break;
        case  6: norm_outflow = 0.6224f * norm_inflow + 0.2352f; break;
        case  7: norm_outflow = 0.5869f * norm_inflow + 0.1892f; break;
        case  8: norm_outflow = 0.1571f * norm_inflow + 0.1670f; break;
        case  9: norm_outflow = 0.0092f * norm_inflow + 0.0968f; break;
        case 10: norm_outflow = 0.1178f * norm_inflow + 0.0835f; break;
        case 11: norm_outflow = 0.4917f * norm_inflow + 0.1043f; break;
        case 12: norm_outflow = 2.0180f * norm_inflow + 0.1236f; break;
    }
    return norm_outflow * max_outflow_m3d;
}

static float rule_2963(float inflow_m3d, float storage_m3, int month) {
    const float max_inflow_m3d   = 133773377.0f;
    const float max_outflow_m3d  = 13284903.9f;
    const float max_storage_m3   = 304446300.1f;
    const float norm_inflow  = inflow_m3d  / max_inflow_m3d;
    const float norm_storage = storage_m3  / max_storage_m3;
    float norm_outflow;

    switch (month) {
        case  1: norm_outflow = 3.8939f * norm_inflow + 0.0279f; break;
        case  2: norm_outflow = 0.8436f * norm_inflow + 0.0418f; break;
        case  3: norm_outflow = 0.8374f * norm_inflow + 0.0942f; break;
        case  4: norm_outflow = 0.3853f * norm_inflow + 0.1027f; break;
        case  5: norm_outflow = 0.3489f * norm_inflow + 0.1063f; break;
        case  6: norm_outflow = 0.1110f * norm_inflow + 0.1309f; break;
        case  7: norm_outflow = 4.5689f * norm_inflow + 0.0829f; break;
        case  8: norm_outflow = 0.3306f * norm_inflow + 0.0370f; break;
        case  9: norm_outflow = 0.6503f * norm_inflow + 0.0411f; break;
        case 10: norm_outflow = 0.3791f * norm_inflow + 0.0376f; break;
        case 11: norm_outflow = 0.3451f * norm_inflow + 0.0517f; break;
        case 12: norm_outflow = 2.7779f * norm_inflow + 0.0355f; break;
    }
    return norm_outflow * max_outflow_m3d;
}

static float rule_2995(float inflow_m3d, float storage_m3, int month) {
    const float max_inflow_m3d   = 12855279.4f;
    const float max_outflow_m3d  = 3009306.4f;
    const float max_storage_m3   = 53214794.2f;
    const float norm_inflow  = inflow_m3d  / max_inflow_m3d;
    const float norm_storage = storage_m3  / max_storage_m3;
    float norm_outflow;

    switch (month) {
        case  1: norm_outflow = 1.5627f * norm_inflow + 0.0091f; break;
        case  2: norm_outflow = 1.3373f * norm_inflow + 0.0097f; break;
        case  3: norm_outflow = 1.1319f * norm_inflow + 0.0182f; break;
        case  4: norm_outflow = 1.2624f * norm_inflow + 0.0210f; break;
        case  5: norm_outflow = 1.4461f * norm_inflow + 0.0341f; break;
        case  6: norm_outflow = 1.3889f * norm_inflow + 0.0276f; break;
        case  7: norm_outflow = 1.3279f * norm_inflow + 0.0141f; break;
        case  8: norm_outflow = 1.7022f * norm_inflow + 0.0083f; break;
        case  9: norm_outflow = 1.2281f * norm_inflow + 0.0080f; break;
        case 10: norm_outflow = 1.1621f * norm_inflow + 0.0151f; break;
        case 11: norm_outflow = 1.4010f * norm_inflow + 0.0102f; break;
        case 12: norm_outflow = 1.2689f * norm_inflow + 0.0075f; break;
    }
    return norm_outflow * max_outflow_m3d;
}

static float rule_3009(float inflow_m3d, float storage_m3, int month) {
    const float max_inflow_m3d   = 6260608.5f;
    const float max_outflow_m3d  = 2813564.9f;
    const float max_storage_m3   = 89629590.7f;
    const float norm_inflow  = inflow_m3d  / max_inflow_m3d;
    const float norm_storage = storage_m3  / max_storage_m3;
    float norm_outflow;

    switch (month) {
        case  1: norm_outflow = 0.2393f * norm_inflow + -0.0003f; break;
        case  2: norm_outflow = 0.1586f * norm_inflow + 0.0008f; break;
        case  3: norm_outflow = 0.2251f * norm_inflow + -0.0003f; break;
        case  4: norm_outflow = 0.8071f * norm_inflow + 0.0077f; break;
        case  5: norm_outflow = 0.4209f * norm_inflow + 0.1235f; break;
        case  6: norm_outflow = 1.1848f * norm_inflow + 0.0891f; break;
        case  7: norm_outflow = 0.7276f * norm_inflow + 0.1033f; break;
        case  8: norm_outflow = 0.9671f * norm_inflow + 0.0795f; break;
        case  9: norm_outflow = 0.8919f * norm_inflow + 0.0676f; break;
        case 10: norm_outflow = 0.3241f * norm_inflow + 0.0179f; break;
        case 11: norm_outflow = 0.0013f * norm_inflow + 0.0021f; break;
        case 12: norm_outflow = 0.0409f * norm_inflow + 0.0010f; break;
    }
    return norm_outflow * max_outflow_m3d;
}

static float rule_3010(float inflow_m3d, float storage_m3, int month) {
    const float max_inflow_m3d   = 254406868.3f;
    const float max_outflow_m3d  = 14500877.6f;
    const float max_storage_m3   = 553225647.8f;
    const float norm_inflow  = inflow_m3d  / max_inflow_m3d;
    const float norm_storage = storage_m3  / max_storage_m3;
    float norm_outflow;

    switch (month) {
        case  1: norm_outflow = 2.0839f * norm_inflow + 0.1959f; break;
        case  2: norm_outflow = 1.4475f * norm_inflow + 0.1713f; break;
        case  3: norm_outflow = 0.9098f * norm_inflow + 0.2085f; break;
        case  4: norm_outflow = 0.1145f * norm_inflow + 0.2375f; break;
        case  5: norm_outflow = 0.5296f * norm_inflow + 0.2495f; break;
        case  6: norm_outflow = 1.6176f * norm_inflow + 0.1980f; break;
        case  7: norm_outflow = 2.0181f * norm_inflow + 0.1134f; break;
        case  8: norm_outflow = 2.5786f * norm_inflow + 0.0656f; break;
        case  9: norm_outflow = 2.0307f * norm_inflow + 0.0708f; break;
        case 10: norm_outflow = 0.5783f * norm_inflow + 0.0755f; break;
        case 11: norm_outflow = 0.2788f * norm_inflow + 0.1126f; break;
        case 12: norm_outflow = 0.3863f * norm_inflow + 0.1938f; break;
    }
    return norm_outflow * max_outflow_m3d;
}

static float rule_852(float inflow_m3d, float storage_m3, int month) {
    const float max_inflow_m3d   = 309668021.3f;
    const float max_outflow_m3d  = 62632401.3f;
    const float max_storage_m3   = 935770967.6f;
    const float norm_inflow  = inflow_m3d  / max_inflow_m3d;
    const float norm_storage = storage_m3  / max_storage_m3;
    float norm_outflow;

    switch (month) {
        case  1: norm_outflow = 0.3161f * norm_inflow + 0.0875f; break;
        case  2: norm_outflow = 0.5456f * norm_inflow + 0.0691f; break;
        case  3: norm_outflow = 0.3836f * norm_inflow + 0.1030f; break;
        case  4: norm_outflow = 0.5941f * norm_inflow + 0.0822f; break;
        case  5: norm_outflow = 0.8192f * norm_inflow + 0.1200f; break;
        case  6: norm_outflow = 0.5338f * norm_inflow + 0.0695f; break;
        case  7: norm_outflow = 0.5470f * norm_inflow + 0.0176f; break;
        case  8: norm_outflow = 0.5947f * norm_inflow + 0.0130f; break;
        case  9: norm_outflow = 0.0077f * norm_inflow + 0.0124f; break;
        case 10: norm_outflow = 0.2324f * norm_inflow + 0.0134f; break;
        case 11: norm_outflow = 0.1766f * norm_inflow + 0.0399f; break;
        case 12: norm_outflow = 0.3412f * norm_inflow + 0.0905f; break;
    }
    return norm_outflow * max_outflow_m3d;
}

static float rule_854(float inflow_m3d, float storage_m3, int month) {
    const float max_inflow_m3d   = 138667144.0f;
    const float max_outflow_m3d  = 117191205.1f;
    const float max_storage_m3   = 336557485.0f;
    const float norm_inflow  = inflow_m3d  / max_inflow_m3d;
    const float norm_storage = storage_m3  / max_storage_m3;
    float norm_outflow;

    switch (month) {
        case  1: norm_outflow = 0.3453f * norm_inflow + 0.0034f; break;
        case  2: norm_outflow = 0.1417f * norm_inflow + 0.0039f; break;
        case  3: norm_outflow = 0.1617f * norm_inflow + 0.0100f; break;
        case  4: norm_outflow = 0.0817f * norm_inflow + 0.0111f; break;
        case  5: norm_outflow = 0.0607f * norm_inflow + 0.0169f; break;
        case  6: norm_outflow = 0.0541f * norm_inflow + 0.0165f; break;
        case  7: norm_outflow = 0.3079f * norm_inflow + 0.0091f; break;
        case  8: norm_outflow = 0.2349f * norm_inflow + 0.0020f; break;
        case  9: norm_outflow = 0.0143f * norm_inflow + 0.0012f; break;
        case 10: norm_outflow = 0.4899f * norm_inflow + 0.0038f; break;
        case 11: norm_outflow = 0.2368f * norm_inflow + 0.0036f; break;
        case 12: norm_outflow = 0.2624f * norm_inflow + 0.0035f; break;
    }
    return norm_outflow * max_outflow_m3d;
}

static float rule_857(float inflow_m3d, float storage_m3, int month) {
    const float max_inflow_m3d   = 89809851.8f;
    const float max_outflow_m3d  = 30393825.3f;
    const float max_storage_m3   = 226999791.4f;
    const float norm_inflow  = inflow_m3d  / max_inflow_m3d;
    const float norm_storage = storage_m3  / max_storage_m3;
    float norm_outflow;

    switch (month) {
        case  1: norm_outflow = 1.4021f * norm_inflow + 0.0120f; break;
        case  2: norm_outflow = 1.1959f * norm_inflow + 0.0178f; break;
        case  3: norm_outflow = 1.4602f * norm_inflow + 0.0271f; break;
        case  4: norm_outflow = 1.5596f * norm_inflow + 0.0344f; break;
        case  5: norm_outflow = 1.4993f * norm_inflow + 0.0408f; break;
        case  6: norm_outflow = 1.5826f * norm_inflow + 0.0415f; break;
        case  7: norm_outflow = 1.5470f * norm_inflow + 0.0270f; break;
        case  8: norm_outflow = 1.3052f * norm_inflow + 0.0201f; break;
        case  9: norm_outflow = 1.1967f * norm_inflow + 0.0167f; break;
        case 10: norm_outflow = 1.1802f * norm_inflow + 0.0224f; break;
        case 11: norm_outflow = 1.1563f * norm_inflow + 0.0270f; break;
        case 12: norm_outflow = 1.8195f * norm_inflow + 0.0093f; break;
    }
    return norm_outflow * max_outflow_m3d;
}

static float rule_858(float inflow_m3d, float storage_m3, int month) {
    const float max_inflow_m3d   = 361806933.0f;
    const float max_outflow_m3d  = 256988571.3f;
    const float max_storage_m3   = 1669559584.6f;
    const float norm_inflow  = inflow_m3d  / max_inflow_m3d;
    const float norm_storage = storage_m3  / max_storage_m3;
    float norm_outflow;

    switch (month) {
        case  1: norm_outflow = 0.7803f * norm_inflow + 0.0074f; break;
        case  2: norm_outflow = 0.9082f * norm_inflow + 0.0093f; break;
        case  3: norm_outflow = 0.6837f * norm_inflow + 0.0079f; break;
        case  4: norm_outflow = 1.0650f * norm_inflow + 0.0032f; break;
        case  5: norm_outflow = 0.7778f * norm_inflow + 0.0213f; break;
        case  6: norm_outflow = 1.0590f * norm_inflow + 0.0334f; break;
        case  7: norm_outflow = 0.5636f * norm_inflow + 0.0429f; break;
        case  8: norm_outflow = 1.1025f * norm_inflow + 0.0184f; break;
        case  9: norm_outflow = 0.7014f * norm_inflow + 0.0195f; break;
        case 10: norm_outflow = 0.7580f * norm_inflow + 0.0195f; break;
        case 11: norm_outflow = 0.8726f * norm_inflow + 0.0062f; break;
        case 12: norm_outflow = 0.4205f * norm_inflow + 0.0066f; break;
    }
    return norm_outflow * max_outflow_m3d;
}

static float rule_148(float inflow_m3d, float storage_m3, int month) {
    const float max_inflow_m3d   = 658776287.1f;
    const float max_outflow_m3d  = 177582340.2f;
    const float max_storage_m3   = 4681920036.0f;
    const float norm_inflow  = inflow_m3d  / max_inflow_m3d;
    const float norm_storage = storage_m3  / max_storage_m3;
    float norm_outflow;

    switch (month) {
        case  1: norm_outflow = 1.2751f * norm_inflow + 0.0430f; break;
        case  2: norm_outflow = 0.6414f * norm_inflow + 0.0475f; break;
        case  3: norm_outflow = 0.7171f * norm_inflow + 0.0588f; break;
        case  4: norm_outflow = 0.8712f * norm_inflow + 0.0680f; break;
        case  5: norm_outflow = 1.2715f * norm_inflow + 0.0508f; break;
        case  6: norm_outflow = 1.0235f * norm_inflow + 0.0428f; break;
        case  7: norm_outflow = 0.9433f * norm_inflow + 0.0456f; break;
        case  8: norm_outflow = 1.2084f * norm_inflow + 0.0390f; break;
        case  9: norm_outflow = 0.3209f * norm_inflow + 0.0286f; break;
        case 10: norm_outflow = 0.7919f * norm_inflow + 0.0228f; break;
        case 11: norm_outflow = 0.7290f * norm_inflow + 0.0272f; break;
        case 12: norm_outflow = 0.7722f * norm_inflow + 0.0476f; break;
    }
    return norm_outflow * max_outflow_m3d;
}

static float rule_3029(float inflow_m3d, float storage_m3, int month) {
    const float max_inflow_m3d   = 9560957.1f;
    const float max_outflow_m3d  = 2696105.4f;
    const float max_storage_m3   = 33498849.8f;
    const float norm_inflow  = inflow_m3d  / max_inflow_m3d;
    const float norm_storage = storage_m3  / max_storage_m3;
    float norm_outflow;

    switch (month) {
        case  1: norm_outflow = 1.3305f * norm_inflow + 0.0184f; break;
        case  2: norm_outflow = 1.1884f * norm_inflow + 0.0282f; break;
        case  3: norm_outflow = 1.1234f * norm_inflow + 0.0352f; break;
        case  4: norm_outflow = 1.1286f * norm_inflow + 0.0387f; break;
        case  5: norm_outflow = 0.4655f * norm_inflow + 0.0539f; break;
        case  6: norm_outflow = 2.3528f * norm_inflow + 0.0259f; break;
        case  7: norm_outflow = 1.3295f * norm_inflow + 0.0125f; break;
        case  8: norm_outflow = 0.7784f * norm_inflow + 0.0069f; break;
        case  9: norm_outflow = 0.6834f * norm_inflow + 0.0088f; break;
        case 10: norm_outflow = 0.7655f * norm_inflow + 0.0162f; break;
        case 11: norm_outflow = 1.0554f * norm_inflow + 0.0134f; break;
        case 12: norm_outflow = 1.3803f * norm_inflow + 0.0085f; break;
    }
    return norm_outflow * max_outflow_m3d;
}

static float rule_150(float inflow_m3d, float storage_m3, int month) {
    const float max_inflow_m3d   = 637496205.2f;
    const float max_outflow_m3d  = 541574543.7f;
    const float max_storage_m3   = 2672111160.1f;
    const float norm_inflow  = inflow_m3d  / max_inflow_m3d;
    const float norm_storage = storage_m3  / max_storage_m3;
    float norm_outflow;

    switch (month) {
        case  1: norm_outflow = 0.7707f * norm_inflow + 0.0112f; break;
        case  2: norm_outflow = 0.6432f * norm_inflow + 0.0107f; break;
        case  3: norm_outflow = 0.7344f * norm_inflow + 0.0167f; break;
        case  4: norm_outflow = 0.5744f * norm_inflow + 0.0277f; break;
        case  5: norm_outflow = 0.8848f * norm_inflow + 0.0216f; break;
        case  6: norm_outflow = 0.8689f * norm_inflow + 0.0212f; break;
        case  7: norm_outflow = 0.8698f * norm_inflow + 0.0136f; break;
        case  8: norm_outflow = 0.8754f * norm_inflow + 0.0132f; break;
        case  9: norm_outflow = 0.6072f * norm_inflow + 0.0135f; break;
        case 10: norm_outflow = 0.6578f * norm_inflow + 0.0114f; break;
        case 11: norm_outflow = 0.4543f * norm_inflow + 0.0090f; break;
        case 12: norm_outflow = 0.7876f * norm_inflow + 0.0065f; break;
    }
    return norm_outflow * max_outflow_m3d;
}

static float rule_151(float inflow_m3d, float storage_m3, int month) {
    const float max_inflow_m3d   = 365269668.0f;
    const float max_outflow_m3d  = 157586546.6f;
    const float max_storage_m3   = 2176492728.7f;
    const float norm_inflow  = inflow_m3d  / max_inflow_m3d;
    const float norm_storage = storage_m3  / max_storage_m3;
    float norm_outflow;

    switch (month) {
        case  1: norm_outflow = 0.6943f * norm_inflow + 0.0180f; break;
        case  2: norm_outflow = 0.8614f * norm_inflow + 0.0116f; break;
        case  3: norm_outflow = 0.5040f * norm_inflow + 0.0260f; break;
        case  4: norm_outflow = 0.2877f * norm_inflow + 0.0505f; break;
        case  5: norm_outflow = 0.5241f * norm_inflow + 0.0885f; break;
        case  6: norm_outflow = 0.9103f * norm_inflow + 0.0864f; break;
        case  7: norm_outflow = 0.7862f * norm_inflow + 0.0692f; break;
        case  8: norm_outflow = 0.9588f * norm_inflow + 0.0385f; break;
        case  9: norm_outflow = 0.6067f * norm_inflow + 0.0232f; break;
        case 10: norm_outflow = 0.7565f * norm_inflow + 0.0337f; break;
        case 11: norm_outflow = 0.7001f * norm_inflow + 0.0201f; break;
        case 12: norm_outflow = 0.0411f * norm_inflow + 0.0108f; break;
    }
    return norm_outflow * max_outflow_m3d;
}

static float rule_867(float inflow_m3d, float storage_m3, int month) {
    const float max_inflow_m3d   = 280906802.5f;
    const float max_outflow_m3d  = 211702408.6f;
    const float max_storage_m3   = 2493487220.9f;
    const float norm_inflow  = inflow_m3d  / max_inflow_m3d;
    const float norm_storage = storage_m3  / max_storage_m3;
    float norm_outflow;

    switch (month) {
        case  1: norm_outflow = 0.1832f * norm_inflow + 0.0140f; break;
        case  2: norm_outflow = 0.0236f * norm_inflow + 0.0169f; break;
        case  3: norm_outflow = 0.1716f * norm_inflow + 0.0097f; break;
        case  4: norm_outflow = 0.4775f * norm_inflow + 0.0119f; break;
        case  5: norm_outflow = 0.5928f * norm_inflow + 0.0090f; break;
        case  6: norm_outflow = 0.5792f * norm_inflow + 0.0139f; break;
        case  7: norm_outflow = 0.5570f * norm_inflow + 0.0118f; break;
        case  8: norm_outflow = 0.0000f * norm_inflow + 0.0129f; break;
        case  9: norm_outflow = 0.0723f * norm_inflow + 0.0096f; break;
        case 10: norm_outflow = 0.0410f * norm_inflow + 0.0079f; break;
        case 11: norm_outflow = 0.0200f * norm_inflow + 0.0067f; break;
        case 12: norm_outflow = 0.6509f * norm_inflow + 0.0070f; break;
    }
    return norm_outflow * max_outflow_m3d;
}

static float rule_3035(float inflow_m3d, float storage_m3, int month) {
    const float max_inflow_m3d   = 98230279.8f;
    const float max_outflow_m3d  = 93704259.5f;
    const float max_storage_m3   = 107781482.4f;
    const float norm_inflow  = inflow_m3d  / max_inflow_m3d;
    const float norm_storage = storage_m3  / max_storage_m3;
    float norm_outflow;

    switch (month) {
        case  1: norm_outflow = 0.9712f * norm_inflow + -0.0000f; break;
        case  2: norm_outflow = 0.9466f * norm_inflow + -0.0000f; break;
        case  3: norm_outflow = 0.9681f * norm_inflow + 0.0004f; break;
        case  4: norm_outflow = 0.9218f * norm_inflow + 0.0014f; break;
        case  5: norm_outflow = 0.9822f * norm_inflow + 0.0010f; break;
        case  6: norm_outflow = 0.9472f * norm_inflow + 0.0013f; break;
        case  7: norm_outflow = 0.9413f * norm_inflow + 0.0016f; break;
        case  8: norm_outflow = 0.6710f * norm_inflow + 0.0026f; break;
        case  9: norm_outflow = 0.6727f * norm_inflow + 0.0021f; break;
        case 10: norm_outflow = 0.9296f * norm_inflow + 0.0010f; break;
        case 11: norm_outflow = 0.7781f * norm_inflow + 0.0012f; break;
        case 12: norm_outflow = 1.0344f * norm_inflow + -0.0007f; break;
    }
    return norm_outflow * max_outflow_m3d;
}

static float rule_152(float inflow_m3d, float storage_m3, int month) {
    const float max_inflow_m3d   = 562113758.5f;
    const float max_outflow_m3d  = 143562762.6f;
    const float max_storage_m3   = 6802358499.6f;
    const float norm_inflow  = inflow_m3d  / max_inflow_m3d;
    const float norm_storage = storage_m3  / max_storage_m3;
    float norm_outflow;

    switch (month) {
        case  1: norm_outflow = 2.1298f * norm_inflow + 0.0592f; break;
        case  2: norm_outflow = 0.8468f * norm_inflow + 0.0896f; break;
        case  3: norm_outflow = 0.3417f * norm_inflow + 0.0785f; break;
        case  4: norm_outflow = 0.1716f * norm_inflow + 0.1091f; break;
        case  5: norm_outflow = 1.0686f * norm_inflow + 0.0434f; break;
        case  6: norm_outflow = 1.2272f * norm_inflow + 0.0968f; break;
        case  7: norm_outflow = 0.9951f * norm_inflow + 0.0981f; break;
        case  8: norm_outflow = 1.0100f * norm_inflow + 0.1130f; break;
        case  9: norm_outflow = 0.5183f * norm_inflow + 0.1045f; break;
        case 10: norm_outflow = 0.2785f * norm_inflow + 0.0892f; break;
        case 11: norm_outflow = 0.1344f * norm_inflow + 0.0599f; break;
        case 12: norm_outflow = 0.1806f * norm_inflow + 0.0831f; break;
    }
    return norm_outflow * max_outflow_m3d;
}

static float rule_869(float inflow_m3d, float storage_m3, int month) {
    const float max_inflow_m3d   = 121440991.0f;
    const float max_outflow_m3d  = 8741624.0f;
    const float max_storage_m3   = 651822638.2f;
    const float norm_inflow  = inflow_m3d  / max_inflow_m3d;
    const float norm_storage = storage_m3  / max_storage_m3;
    float norm_outflow;

    switch (month) {
        case  1: norm_outflow = 1.4008f * norm_inflow + 0.0346f; break;
        case  2: norm_outflow = 0.4545f * norm_inflow + 0.0201f; break;
        case  3: norm_outflow = 0.7605f * norm_inflow + 0.0271f; break;
        case  4: norm_outflow = 0.0000f * norm_inflow + 0.0811f; break;
        case  5: norm_outflow = 0.8047f * norm_inflow + 0.0739f; break;
        case  6: norm_outflow = 0.4954f * norm_inflow + 0.0937f; break;
        case  7: norm_outflow = 0.0000f * norm_inflow + 0.0785f; break;
        case  8: norm_outflow = 0.0000f * norm_inflow + 0.0433f; break;
        case  9: norm_outflow = 0.0154f * norm_inflow + 0.0332f; break;
        case 10: norm_outflow = 0.0000f * norm_inflow + 0.0330f; break;
        case 11: norm_outflow = 0.1560f * norm_inflow + 0.0227f; break;
        case 12: norm_outflow = 0.0000f * norm_inflow + 0.0094f; break;
    }
    return norm_outflow * max_outflow_m3d;
}

static float rule_874(float inflow_m3d, float storage_m3, int month) {
    const float max_inflow_m3d   = 516685216.2f;
    const float max_outflow_m3d  = 140785895.0f;
    const float max_storage_m3   = 2501491272.6f;
    const float norm_inflow  = inflow_m3d  / max_inflow_m3d;
    const float norm_storage = storage_m3  / max_storage_m3;
    float norm_outflow;

    switch (month) {
        case  1: norm_outflow = 0.5657f * norm_inflow + 0.0343f; break;
        case  2: norm_outflow = 0.0525f * norm_inflow + 0.0339f; break;
        case  3: norm_outflow = 0.0000f * norm_inflow + 0.0317f; break;
        case  4: norm_outflow = 0.5170f * norm_inflow + 0.0342f; break;
        case  5: norm_outflow = 1.7971f * norm_inflow + 0.0139f; break;
        case  6: norm_outflow = 0.1363f * norm_inflow + 0.0403f; break;
        case  7: norm_outflow = 0.0000f * norm_inflow + 0.0379f; break;
        case  8: norm_outflow = 0.0346f * norm_inflow + 0.0342f; break;
        case  9: norm_outflow = 0.0000f * norm_inflow + 0.0277f; break;
        case 10: norm_outflow = 0.0000f * norm_inflow + 0.0234f; break;
        case 11: norm_outflow = 0.1062f * norm_inflow + 0.0203f; break;
        case 12: norm_outflow = 0.0071f * norm_inflow + 0.0347f; break;
    }
    return norm_outflow * max_outflow_m3d;
}

static float rule_876(float inflow_m3d, float storage_m3, int month) {
    const float max_inflow_m3d   = 555788190.7f;
    const float max_outflow_m3d  = 549983433.7f;
    const float max_storage_m3   = 547334547.4f;
    const float norm_inflow  = inflow_m3d  / max_inflow_m3d;
    const float norm_storage = storage_m3  / max_storage_m3;
    float norm_outflow;

    switch (month) {
        case  1: norm_outflow = 1.0142f * norm_inflow + 0.0007f; break;
        case  2: norm_outflow = 0.9295f * norm_inflow + 0.0021f; break;
        case  3: norm_outflow = 0.9436f * norm_inflow + 0.0031f; break;
        case  4: norm_outflow = 0.8403f * norm_inflow + 0.0092f; break;
        case  5: norm_outflow = 0.9599f * norm_inflow + 0.0056f; break;
        case  6: norm_outflow = 0.9550f * norm_inflow + 0.0040f; break;
        case  7: norm_outflow = 0.9536f * norm_inflow + 0.0047f; break;
        case  8: norm_outflow = 0.9644f * norm_inflow + 0.0016f; break;
        case  9: norm_outflow = 0.9628f * norm_inflow + 0.0017f; break;
        case 10: norm_outflow = 0.9434f * norm_inflow + 0.0021f; break;
        case 11: norm_outflow = 0.9581f * norm_inflow + 0.0010f; break;
        case 12: norm_outflow = 0.9107f * norm_inflow + 0.0018f; break;
    }
    return norm_outflow * max_outflow_m3d;
}

static float rule_880(float inflow_m3d, float storage_m3, int month) {
    const float max_inflow_m3d   = 745343886.5f;
    const float max_outflow_m3d  = 665589145.6f;
    const float max_storage_m3   = 2146698019.3f;
    const float norm_inflow  = inflow_m3d  / max_inflow_m3d;
    const float norm_storage = storage_m3  / max_storage_m3;
    float norm_outflow;

    switch (month) {
        case  1: norm_outflow = 0.8546f * norm_inflow + 0.0040f; break;
        case  2: norm_outflow = 0.7107f * norm_inflow + 0.0054f; break;
        case  3: norm_outflow = 0.6281f * norm_inflow + 0.0058f; break;
        case  4: norm_outflow = 0.5031f * norm_inflow + 0.0165f; break;
        case  5: norm_outflow = 0.9210f * norm_inflow + 0.0045f; break;
        case  6: norm_outflow = 0.8071f * norm_inflow + 0.0206f; break;
        case  7: norm_outflow = 0.8271f * norm_inflow + 0.0174f; break;
        case  8: norm_outflow = 0.9757f * norm_inflow + 0.0075f; break;
        case  9: norm_outflow = 0.7630f * norm_inflow + 0.0072f; break;
        case 10: norm_outflow = 0.7330f * norm_inflow + 0.0090f; break;
        case 11: norm_outflow = 0.9177f * norm_inflow + 0.0030f; break;
        case 12: norm_outflow = 0.3887f * norm_inflow + 0.0052f; break;
    }
    return norm_outflow * max_outflow_m3d;
}

static float rule_883(float inflow_m3d, float storage_m3, int month) {
    const float max_inflow_m3d   = 20028816.3f;
    const float max_outflow_m3d  = 12648815.0f;
    const float max_storage_m3   = 192038034.2f;
    const float norm_inflow  = inflow_m3d  / max_inflow_m3d;
    const float norm_storage = storage_m3  / max_storage_m3;
    float norm_outflow;

    switch (month) {
        case  1: norm_outflow = 0.7696f * norm_inflow + 0.0117f; break;
        case  2: norm_outflow = 0.5320f * norm_inflow + 0.0204f; break;
        case  3: norm_outflow = 0.7694f * norm_inflow + 0.0118f; break;
        case  4: norm_outflow = 0.6961f * norm_inflow + 0.0226f; break;
        case  5: norm_outflow = 0.7012f * norm_inflow + 0.0243f; break;
        case  6: norm_outflow = 0.5417f * norm_inflow + 0.0403f; break;
        case  7: norm_outflow = 0.7755f * norm_inflow + 0.0258f; break;
        case  8: norm_outflow = 0.7705f * norm_inflow + 0.0198f; break;
        case  9: norm_outflow = 0.3506f * norm_inflow + 0.0191f; break;
        case 10: norm_outflow = 0.7599f * norm_inflow + 0.0109f; break;
        case 11: norm_outflow = 0.4169f * norm_inflow + 0.0132f; break;
        case 12: norm_outflow = 0.6348f * norm_inflow + 0.0114f; break;
    }
    return norm_outflow * max_outflow_m3d;
}

static float rule_5663(float inflow_m3d, float storage_m3, int month) {
    const float max_inflow_m3d   = 258925002.6f;
    const float max_outflow_m3d  = 264385016.2f;
    const float max_storage_m3   = 36934091.6f;
    const float norm_inflow  = inflow_m3d  / max_inflow_m3d;
    const float norm_storage = storage_m3  / max_storage_m3;
    float norm_outflow;

    switch (month) {
        case  1: norm_outflow = 0.9821f * norm_inflow + -0.0001f; break;
        case  2: norm_outflow = 0.9859f * norm_inflow + -0.0003f; break;
        case  3: norm_outflow = 0.9806f * norm_inflow + -0.0001f; break;
        case  4: norm_outflow = 0.9807f * norm_inflow + -0.0001f; break;
        case  5: norm_outflow = 0.9814f * norm_inflow + -0.0002f; break;
        case  6: norm_outflow = 0.9815f * norm_inflow + -0.0002f; break;
        case  7: norm_outflow = 0.9820f * norm_inflow + -0.0001f; break;
        case  8: norm_outflow = 0.9818f * norm_inflow + -0.0001f; break;
        case  9: norm_outflow = 0.9832f * norm_inflow + -0.0001f; break;
        case 10: norm_outflow = 0.9816f * norm_inflow + -0.0001f; break;
        case 11: norm_outflow = 0.9806f * norm_inflow + -0.0001f; break;
        case 12: norm_outflow = 0.9829f * norm_inflow + -0.0002f; break;
    }
    return norm_outflow * max_outflow_m3d;
}

static float rule_887(float inflow_m3d, float storage_m3, int month) {
    const float max_inflow_m3d   = 564840709.0f;
    const float max_outflow_m3d  = 543810674.8f;
    const float max_storage_m3   = 1579337800.8f;
    const float norm_inflow  = inflow_m3d  / max_inflow_m3d;
    const float norm_storage = storage_m3  / max_storage_m3;
    float norm_outflow;

    switch (month) {
        case  1: norm_outflow = 1.1710f * norm_inflow + 0.0003f; break;
        case  2: norm_outflow = 0.8127f * norm_inflow + 0.0067f; break;
        case  3: norm_outflow = 0.6414f * norm_inflow + 0.0194f; break;
        case  4: norm_outflow = 0.5328f * norm_inflow + 0.0337f; break;
        case  5: norm_outflow = 0.7909f * norm_inflow + 0.0226f; break;
        case  6: norm_outflow = 0.8347f * norm_inflow + 0.0220f; break;
        case  7: norm_outflow = 0.8327f * norm_inflow + 0.0157f; break;
        case  8: norm_outflow = 0.8225f * norm_inflow + 0.0076f; break;
        case  9: norm_outflow = 0.8432f * norm_inflow + 0.0068f; break;
        case 10: norm_outflow = 0.7785f * norm_inflow + 0.0082f; break;
        case 11: norm_outflow = 0.7521f * norm_inflow + 0.0054f; break;
        case 12: norm_outflow = 0.6335f * norm_inflow + 0.0076f; break;
    }
    return norm_outflow * max_outflow_m3d;
}

static float rule_897(float inflow_m3d, float storage_m3, int month) {
    const float max_inflow_m3d   = 346548356.9f;
    const float max_outflow_m3d  = 85630236.0f;
    const float max_storage_m3   = 1490460756.2f;
    const float norm_inflow  = inflow_m3d  / max_inflow_m3d;
    const float norm_storage = storage_m3  / max_storage_m3;
    float norm_outflow;

    switch (month) {
        case  1: norm_outflow = 1.8263f * norm_inflow + 0.0397f; break;
        case  2: norm_outflow = 0.5051f * norm_inflow + 0.0384f; break;
        case  3: norm_outflow = 0.3398f * norm_inflow + 0.0447f; break;
        case  4: norm_outflow = 0.3517f * norm_inflow + 0.0734f; break;
        case  5: norm_outflow = 0.2314f * norm_inflow + 0.0936f; break;
        case  6: norm_outflow = 0.8291f * norm_inflow + 0.0553f; break;
        case  7: norm_outflow = 1.7290f * norm_inflow + 0.0393f; break;
        case  8: norm_outflow = 1.0144f * norm_inflow + 0.0246f; break;
        case  9: norm_outflow = 0.9591f * norm_inflow + 0.0207f; break;
        case 10: norm_outflow = 1.2424f * norm_inflow + 0.0247f; break;
        case 11: norm_outflow = 1.9584f * norm_inflow + 0.0179f; break;
        case 12: norm_outflow = 0.5912f * norm_inflow + 0.0342f; break;
    }
    return norm_outflow * max_outflow_m3d;
}

static float rule_155(float inflow_m3d, float storage_m3, int month) {
    const float max_inflow_m3d   = 270343149.8f;
    const float max_outflow_m3d  = 25992447.2f;
    const float max_storage_m3   = 3465172192.2f;
    const float norm_inflow  = inflow_m3d  / max_inflow_m3d;
    const float norm_storage = storage_m3  / max_storage_m3;
    float norm_outflow;

    switch (month) {
        case  1: norm_outflow = 0.0000f * norm_inflow + 0.2275f; break;
        case  2: norm_outflow = 0.0000f * norm_inflow + 0.2325f; break;
        case  3: norm_outflow = 0.0656f * norm_inflow + 0.2408f; break;
        case  4: norm_outflow = 0.0000f * norm_inflow + 0.2363f; break;
        case  5: norm_outflow = 0.1039f * norm_inflow + 0.1784f; break;
        case  6: norm_outflow = 0.8695f * norm_inflow + 0.2121f; break;
        case  7: norm_outflow = 1.3397f * norm_inflow + 0.1878f; break;
        case  8: norm_outflow = 0.0000f * norm_inflow + 0.1255f; break;
        case  9: norm_outflow = 0.2298f * norm_inflow + 0.0807f; break;
        case 10: norm_outflow = 0.2915f * norm_inflow + 0.0620f; break;
        case 11: norm_outflow = 0.3362f * norm_inflow + 0.0703f; break;
        case 12: norm_outflow = 0.0800f * norm_inflow + 0.1865f; break;
    }
    return norm_outflow * max_outflow_m3d;
}

static float rule_3072(float inflow_m3d, float storage_m3, int month) {
    const float max_inflow_m3d   = 43056973.6f;
    const float max_outflow_m3d  = 40613928.6f;
    const float max_storage_m3   = 23226428.4f;
    const float norm_inflow  = inflow_m3d  / max_inflow_m3d;
    const float norm_storage = storage_m3  / max_storage_m3;
    float norm_outflow;

    switch (month) {
        case  1: norm_outflow = 1.0023f * norm_inflow + 0.0002f; break;
        case  2: norm_outflow = 0.9351f * norm_inflow + 0.0010f; break;
        case  3: norm_outflow = 0.8313f * norm_inflow + 0.0021f; break;
        case  4: norm_outflow = 0.9387f * norm_inflow + 0.0005f; break;
        case  5: norm_outflow = 1.0391f * norm_inflow + -0.0006f; break;
        case  6: norm_outflow = 0.9723f * norm_inflow + 0.0013f; break;
        case  7: norm_outflow = 1.0336f * norm_inflow + 0.0015f; break;
        case  8: norm_outflow = 1.0372f * norm_inflow + 0.0013f; break;
        case  9: norm_outflow = 0.8385f * norm_inflow + 0.0015f; break;
        case 10: norm_outflow = 0.9113f * norm_inflow + 0.0007f; break;
        case 11: norm_outflow = 0.8065f * norm_inflow + 0.0011f; break;
        case 12: norm_outflow = 0.8560f * norm_inflow + 0.0009f; break;
    }
    return norm_outflow * max_outflow_m3d;
}

static float rule_157(float inflow_m3d, float storage_m3, int month) {
    const float max_inflow_m3d   = 953442076.6f;
    const float max_outflow_m3d  = 873593700.5f;
    const float max_storage_m3   = 726582627.5f;
    const float norm_inflow  = inflow_m3d  / max_inflow_m3d;
    const float norm_storage = storage_m3  / max_storage_m3;
    float norm_outflow;

    switch (month) {
        case  1: norm_outflow = 1.0841f * norm_inflow + 0.0006f; break;
        case  2: norm_outflow = 1.0651f * norm_inflow + 0.0021f; break;
        case  3: norm_outflow = 1.0847f * norm_inflow + 0.0018f; break;
        case  4: norm_outflow = 1.0800f * norm_inflow + 0.0013f; break;
        case  5: norm_outflow = 1.0814f * norm_inflow + 0.0016f; break;
        case  6: norm_outflow = 1.0793f * norm_inflow + 0.0017f; break;
        case  7: norm_outflow = 1.0504f * norm_inflow + 0.0027f; break;
        case  8: norm_outflow = 1.0716f * norm_inflow + 0.0008f; break;
        case  9: norm_outflow = 1.0531f * norm_inflow + 0.0014f; break;
        case 10: norm_outflow = 1.0848f * norm_inflow + 0.0005f; break;
        case 11: norm_outflow = 1.0798f * norm_inflow + 0.0010f; break;
        case 12: norm_outflow = 1.0913f * norm_inflow + 0.0025f; break;
    }
    return norm_outflow * max_outflow_m3d;
}

static float rule_158(float inflow_m3d, float storage_m3, int month) {
    const float max_inflow_m3d   = 717653468.2f;
    const float max_outflow_m3d  = 419715379.2f;
    const float max_storage_m3   = 4770873679.7f;
    const float norm_inflow  = inflow_m3d  / max_inflow_m3d;
    const float norm_storage = storage_m3  / max_storage_m3;
    float norm_outflow;

    switch (month) {
        case  1: norm_outflow = 0.9751f * norm_inflow + 0.0200f; break;
        case  2: norm_outflow = 0.2903f * norm_inflow + 0.0176f; break;
        case  3: norm_outflow = 0.3194f * norm_inflow + 0.0259f; break;
        case  4: norm_outflow = 0.1974f * norm_inflow + 0.0396f; break;
        case  5: norm_outflow = 0.7744f * norm_inflow + 0.0315f; break;
        case  6: norm_outflow = 0.6250f * norm_inflow + 0.0398f; break;
        case  7: norm_outflow = 0.9934f * norm_inflow + 0.0351f; break;
        case  8: norm_outflow = 0.6563f * norm_inflow + 0.0190f; break;
        case  9: norm_outflow = 0.1505f * norm_inflow + 0.0135f; break;
        case 10: norm_outflow = 0.2711f * norm_inflow + 0.0120f; break;
        case 11: norm_outflow = 0.2303f * norm_inflow + 0.0148f; break;
        case 12: norm_outflow = 0.1382f * norm_inflow + 0.0170f; break;
    }
    return norm_outflow * max_outflow_m3d;
}

static float rule_905(float inflow_m3d, float storage_m3, int month) {
    const float max_inflow_m3d   = 1055861592.7f;
    const float max_outflow_m3d  = 1065239594.3f;
    const float max_storage_m3   = 630545108.2f;
    const float norm_inflow  = inflow_m3d  / max_inflow_m3d;
    const float norm_storage = storage_m3  / max_storage_m3;
    float norm_outflow;

    switch (month) {
        case  1: norm_outflow = 0.9913f * norm_inflow + -0.0000f; break;
        case  2: norm_outflow = 0.9976f * norm_inflow + -0.0006f; break;
        case  3: norm_outflow = 0.9919f * norm_inflow + 0.0000f; break;
        case  4: norm_outflow = 0.9920f * norm_inflow + -0.0001f; break;
        case  5: norm_outflow = 0.9888f * norm_inflow + 0.0004f; break;
        case  6: norm_outflow = 0.9909f * norm_inflow + -0.0000f; break;
        case  7: norm_outflow = 0.9889f * norm_inflow + 0.0002f; break;
        case  8: norm_outflow = 0.9794f * norm_inflow + 0.0008f; break;
        case  9: norm_outflow = 0.9791f * norm_inflow + 0.0006f; break;
        case 10: norm_outflow = 0.9851f * norm_inflow + 0.0002f; break;
        case 11: norm_outflow = 0.9906f * norm_inflow + 0.0001f; break;
        case 12: norm_outflow = 0.9920f * norm_inflow + -0.0001f; break;
    }
    return norm_outflow * max_outflow_m3d;
}

static float rule_912(float inflow_m3d, float storage_m3, int month) {
    const float max_inflow_m3d   = 117485913.9f;
    const float max_outflow_m3d  = 24744691.4f;
    const float max_storage_m3   = 408855448.2f;
    const float norm_inflow  = inflow_m3d  / max_inflow_m3d;
    const float norm_storage = storage_m3  / max_storage_m3;
    float norm_outflow;

    switch (month) {
        case  1: norm_outflow = 0.0025f * norm_inflow + 0.0874f; break;
        case  2: norm_outflow = 0.0000f * norm_inflow + 0.0869f; break;
        case  3: norm_outflow = 0.0000f * norm_inflow + 0.0722f; break;
        case  4: norm_outflow = 0.1868f * norm_inflow + 0.0820f; break;
        case  5: norm_outflow = 0.0808f * norm_inflow + 0.0801f; break;
        case  6: norm_outflow = 0.2982f * norm_inflow + 0.0527f; break;
        case  7: norm_outflow = 0.7817f * norm_inflow + 0.0217f; break;
        case  8: norm_outflow = 0.4555f * norm_inflow + 0.0066f; break;
        case  9: norm_outflow = 0.0979f * norm_inflow + 0.0103f; break;
        case 10: norm_outflow = 0.0806f * norm_inflow + 0.0163f; break;
        case 11: norm_outflow = 0.1908f * norm_inflow + 0.0338f; break;
        case 12: norm_outflow = 0.0000f * norm_inflow + 0.0889f; break;
    }
    return norm_outflow * max_outflow_m3d;
}

static float rule_3112(float inflow_m3d, float storage_m3, int month) {
    const float max_inflow_m3d   = 166189343.1f;
    const float max_outflow_m3d  = 32918696.4f;
    const float max_storage_m3   = 533709527.3f;
    const float norm_inflow  = inflow_m3d  / max_inflow_m3d;
    const float norm_storage = storage_m3  / max_storage_m3;
    float norm_outflow;

    switch (month) {
        case  1: norm_outflow = 0.0000f * norm_inflow + 0.1097f; break;
        case  2: norm_outflow = 0.0000f * norm_inflow + 0.1025f; break;
        case  3: norm_outflow = 0.0000f * norm_inflow + 0.1048f; break;
        case  4: norm_outflow = 0.0000f * norm_inflow + 0.1086f; break;
        case  5: norm_outflow = 0.0000f * norm_inflow + 0.0951f; break;
        case  6: norm_outflow = 0.0000f * norm_inflow + 0.0893f; break;
        case  7: norm_outflow = 1.4699f * norm_inflow + 0.0294f; break;
        case  8: norm_outflow = 2.3032f * norm_inflow + 0.0131f; break;
        case  9: norm_outflow = 0.1492f * norm_inflow + 0.0124f; break;
        case 10: norm_outflow = 0.2356f * norm_inflow + 0.0176f; break;
        case 11: norm_outflow = 0.0917f * norm_inflow + 0.0538f; break;
        case 12: norm_outflow = 0.0000f * norm_inflow + 0.1069f; break;
    }
    return norm_outflow * max_outflow_m3d;
}

static float rule_919(float inflow_m3d, float storage_m3, int month) {
    const float max_inflow_m3d   = 245012336.8f;
    const float max_outflow_m3d  = 57355131.9f;
    const float max_storage_m3   = 646146163.2f;
    const float norm_inflow  = inflow_m3d  / max_inflow_m3d;
    const float norm_storage = storage_m3  / max_storage_m3;
    float norm_outflow;

    switch (month) {
        case  1: norm_outflow = 0.0000f * norm_inflow + 0.0658f; break;
        case  2: norm_outflow = 0.0000f * norm_inflow + 0.0561f; break;
        case  3: norm_outflow = 0.0228f * norm_inflow + 0.0742f; break;
        case  4: norm_outflow = 0.4180f * norm_inflow + 0.0832f; break;
        case  5: norm_outflow = 0.2880f * norm_inflow + 0.0802f; break;
        case  6: norm_outflow = 0.0000f * norm_inflow + 0.0630f; break;
        case  7: norm_outflow = 0.0000f * norm_inflow + 0.0282f; break;
        case  8: norm_outflow = 0.0000f * norm_inflow + 0.0167f; break;
        case  9: norm_outflow = 0.1891f * norm_inflow + 0.0183f; break;
        case 10: norm_outflow = 0.3647f * norm_inflow + 0.0183f; break;
        case 11: norm_outflow = 0.0593f * norm_inflow + 0.0324f; break;
        case 12: norm_outflow = 0.0976f * norm_inflow + 0.0605f; break;
    }
    return norm_outflow * max_outflow_m3d;
}

static float rule_920(float inflow_m3d, float storage_m3, int month) {
    const float max_inflow_m3d   = 39067308.4f;
    const float max_outflow_m3d  = 20404425.2f;
    const float max_storage_m3   = 192422880.0f;
    const float norm_inflow  = inflow_m3d  / max_inflow_m3d;
    const float norm_storage = storage_m3  / max_storage_m3;
    float norm_outflow;

    switch (month) {
        case  1: norm_outflow = 0.3546f * norm_inflow + 0.0004f; break;
        case  2: norm_outflow = 0.5401f * norm_inflow + 0.0003f; break;
        case  3: norm_outflow = 0.5448f * norm_inflow + 0.0003f; break;
        case  4: norm_outflow = 1.0153f * norm_inflow + -0.0033f; break;
        case  5: norm_outflow = 0.7147f * norm_inflow + 0.0049f; break;
        case  6: norm_outflow = 0.1292f * norm_inflow + 0.0125f; break;
        case  7: norm_outflow = 0.1147f * norm_inflow + 0.0046f; break;
        case  8: norm_outflow = 0.5136f * norm_inflow + 0.0136f; break;
        case  9: norm_outflow = 0.0000f * norm_inflow + 0.0001f; break;
        case 10: norm_outflow = 0.0030f * norm_inflow + 0.0003f; break;
        case 11: norm_outflow = 0.0743f * norm_inflow + 0.0010f; break;
        case 12: norm_outflow = 0.6399f * norm_inflow + -0.0005f; break;
    }
    return norm_outflow * max_outflow_m3d;
}

static float rule_162(float inflow_m3d, float storage_m3, int month) {
    const float max_inflow_m3d   = 349371193.0f;
    const float max_outflow_m3d  = 32801225.8f;
    const float max_storage_m3   = 3303090453.2f;
    const float norm_inflow  = inflow_m3d  / max_inflow_m3d;
    const float norm_storage = storage_m3  / max_storage_m3;
    float norm_outflow;

    switch (month) {
        case  1: norm_outflow = 0.2977f * norm_inflow + 0.1687f; break;
        case  2: norm_outflow = 0.2588f * norm_inflow + 0.1261f; break;
        case  3: norm_outflow = 0.6326f * norm_inflow + 0.1680f; break;
        case  4: norm_outflow = 0.7124f * norm_inflow + 0.1430f; break;
        case  5: norm_outflow = 0.8598f * norm_inflow + 0.1559f; break;
        case  6: norm_outflow = 0.8623f * norm_inflow + 0.1594f; break;
        case  7: norm_outflow = 0.9532f * norm_inflow + 0.1152f; break;
        case  8: norm_outflow = 0.6876f * norm_inflow + 0.1065f; break;
        case  9: norm_outflow = 0.2634f * norm_inflow + 0.0784f; break;
        case 10: norm_outflow = 0.6210f * norm_inflow + 0.0451f; break;
        case 11: norm_outflow = 0.2783f * norm_inflow + 0.0653f; break;
        case 12: norm_outflow = 0.1303f * norm_inflow + 0.1529f; break;
    }
    return norm_outflow * max_outflow_m3d;
}

static float rule_938(float inflow_m3d, float storage_m3, int month) {
    const float max_inflow_m3d   = 131441639.9f;
    const float max_outflow_m3d  = 15134531.5f;
    const float max_storage_m3   = 454205573.9f;
    const float norm_inflow  = inflow_m3d  / max_inflow_m3d;
    const float norm_storage = storage_m3  / max_storage_m3;
    float norm_outflow;

    switch (month) {
        case  1: norm_outflow = 0.3830f * norm_inflow + 0.0146f; break;
        case  2: norm_outflow = 0.3291f * norm_inflow + 0.0169f; break;
        case  3: norm_outflow = 0.2859f * norm_inflow + 0.0313f; break;
        case  4: norm_outflow = 0.4450f * norm_inflow + 0.0248f; break;
        case  5: norm_outflow = 0.0952f * norm_inflow + 0.0384f; break;
        case  6: norm_outflow = 0.5382f * norm_inflow + 0.0552f; break;
        case  7: norm_outflow = 2.0439f * norm_inflow + 0.0232f; break;
        case  8: norm_outflow = 0.5727f * norm_inflow + 0.0123f; break;
        case  9: norm_outflow = 1.4815f * norm_inflow + 0.0115f; break;
        case 10: norm_outflow = 0.0000f * norm_inflow + 0.0089f; break;
        case 11: norm_outflow = 0.5023f * norm_inflow + 0.0183f; break;
        case 12: norm_outflow = 0.5017f * norm_inflow + 0.0099f; break;
    }
    return norm_outflow * max_outflow_m3d;
}

static float rule_939(float inflow_m3d, float storage_m3, int month) {
    const float max_inflow_m3d   = 173393719.5f;
    const float max_outflow_m3d  = 22097455.8f;
    const float max_storage_m3   = 1082519316.7f;
    const float norm_inflow  = inflow_m3d  / max_inflow_m3d;
    const float norm_storage = storage_m3  / max_storage_m3;
    float norm_outflow;

    switch (month) {
        case  1: norm_outflow = 0.9792f * norm_inflow + 0.0939f; break;
        case  2: norm_outflow = 0.7808f * norm_inflow + 0.0762f; break;
        case  3: norm_outflow = 1.0043f * norm_inflow + 0.1158f; break;
        case  4: norm_outflow = 0.9224f * norm_inflow + 0.0956f; break;
        case  5: norm_outflow = 1.1083f * norm_inflow + 0.0957f; break;
        case  6: norm_outflow = 1.5696f * norm_inflow + 0.0793f; break;
        case  7: norm_outflow = 1.8143f * norm_inflow + 0.0664f; break;
        case  8: norm_outflow = 0.9457f * norm_inflow + 0.0600f; break;
        case  9: norm_outflow = 0.3840f * norm_inflow + 0.0451f; break;
        case 10: norm_outflow = 1.2128f * norm_inflow + 0.0305f; break;
        case 11: norm_outflow = 0.7403f * norm_inflow + 0.0492f; break;
        case 12: norm_outflow = 0.4499f * norm_inflow + 0.1019f; break;
    }
    return norm_outflow * max_outflow_m3d;
}

static float rule_3156(float inflow_m3d, float storage_m3, int month) {
    const float max_inflow_m3d   = 60007140.6f;
    const float max_outflow_m3d  = 7520781.3f;
    const float max_storage_m3   = 243385339.7f;
    const float norm_inflow  = inflow_m3d  / max_inflow_m3d;
    const float norm_storage = storage_m3  / max_storage_m3;
    float norm_outflow;

    switch (month) {
        case  1: norm_outflow = 0.3728f * norm_inflow + 0.2177f; break;
        case  2: norm_outflow = 0.2283f * norm_inflow + 0.1761f; break;
        case  3: norm_outflow = 0.0217f * norm_inflow + 0.3221f; break;
        case  4: norm_outflow = 0.0000f * norm_inflow + 0.2721f; break;
        case  5: norm_outflow = 0.3081f * norm_inflow + 0.2814f; break;
        case  6: norm_outflow = 1.5061f * norm_inflow + 0.1207f; break;
        case  7: norm_outflow = 1.0175f * norm_inflow + 0.0719f; break;
        case  8: norm_outflow = 1.6839f * norm_inflow + 0.0514f; break;
        case  9: norm_outflow = 0.5955f * norm_inflow + 0.0563f; break;
        case 10: norm_outflow = 2.7627f * norm_inflow + 0.0357f; break;
        case 11: norm_outflow = 0.3231f * norm_inflow + 0.0910f; break;
        case 12: norm_outflow = 0.2407f * norm_inflow + 0.1840f; break;
    }
    return norm_outflow * max_outflow_m3d;
}

static float rule_945(float inflow_m3d, float storage_m3, int month) {
    const float max_inflow_m3d   = 197194510.5f;
    const float max_outflow_m3d  = 73118436.1f;
    const float max_storage_m3   = 1695240638.9f;
    const float norm_inflow  = inflow_m3d  / max_inflow_m3d;
    const float norm_storage = storage_m3  / max_storage_m3;
    float norm_outflow;

    switch (month) {
        case  1: norm_outflow = 0.0000f * norm_inflow + 0.0666f; break;
        case  2: norm_outflow = 0.0000f * norm_inflow + 0.0481f; break;
        case  3: norm_outflow = 0.0000f * norm_inflow + 0.0559f; break;
        case  4: norm_outflow = 0.0000f * norm_inflow + 0.0666f; break;
        case  5: norm_outflow = 0.1878f * norm_inflow + 0.0650f; break;
        case  6: norm_outflow = 0.2835f * norm_inflow + 0.0536f; break;
        case  7: norm_outflow = 0.4008f * norm_inflow + 0.0335f; break;
        case  8: norm_outflow = 0.0000f * norm_inflow + 0.0255f; break;
        case  9: norm_outflow = 0.0163f * norm_inflow + 0.0198f; break;
        case 10: norm_outflow = 0.4368f * norm_inflow + 0.0183f; break;
        case 11: norm_outflow = 0.0102f * norm_inflow + 0.0355f; break;
        case 12: norm_outflow = 0.3445f * norm_inflow + 0.0367f; break;
    }
    return norm_outflow * max_outflow_m3d;
}

static float rule_3158(float inflow_m3d, float storage_m3, int month) {
    const float max_inflow_m3d   = 47639077.3f;
    const float max_outflow_m3d  = 2412326.1f;
    const float max_storage_m3   = 123676105.7f;
    const float norm_inflow  = inflow_m3d  / max_inflow_m3d;
    const float norm_storage = storage_m3  / max_storage_m3;
    float norm_outflow;

    switch (month) {
        case  1: norm_outflow = 0.0000f * norm_inflow + 0.2412f; break;
        case  2: norm_outflow = 0.0000f * norm_inflow + 0.2102f; break;
        case  3: norm_outflow = 0.0000f * norm_inflow + 0.2911f; break;
        case  4: norm_outflow = 0.0000f * norm_inflow + 0.2585f; break;
        case  5: norm_outflow = 0.0000f * norm_inflow + 0.3226f; break;
        case  6: norm_outflow = 1.5620f * norm_inflow + 0.1756f; break;
        case  7: norm_outflow = 0.0814f * norm_inflow + 0.0844f; break;
        case  8: norm_outflow = 2.1671f * norm_inflow + 0.0952f; break;
        case  9: norm_outflow = 1.4437f * norm_inflow + 0.0573f; break;
        case 10: norm_outflow = 1.4808f * norm_inflow + 0.0360f; break;
        case 11: norm_outflow = 0.2909f * norm_inflow + 0.1144f; break;
        case 12: norm_outflow = 0.4190f * norm_inflow + 0.1746f; break;
    }
    return norm_outflow * max_outflow_m3d;
}

static float rule_944(float inflow_m3d, float storage_m3, int month) {
    const float max_inflow_m3d   = 173393719.5f;
    const float max_outflow_m3d  = 22097455.8f;
    const float max_storage_m3   = 1082519316.7f;
    const float norm_inflow  = inflow_m3d  / max_inflow_m3d;
    const float norm_storage = storage_m3  / max_storage_m3;
    float norm_outflow;

    switch (month) {
        case  1: norm_outflow = 0.9792f * norm_inflow + 0.0939f; break;
        case  2: norm_outflow = 0.7808f * norm_inflow + 0.0762f; break;
        case  3: norm_outflow = 1.0043f * norm_inflow + 0.1158f; break;
        case  4: norm_outflow = 0.9224f * norm_inflow + 0.0956f; break;
        case  5: norm_outflow = 1.1083f * norm_inflow + 0.0957f; break;
        case  6: norm_outflow = 1.5696f * norm_inflow + 0.0793f; break;
        case  7: norm_outflow = 1.8143f * norm_inflow + 0.0664f; break;
        case  8: norm_outflow = 0.9457f * norm_inflow + 0.0600f; break;
        case  9: norm_outflow = 0.3840f * norm_inflow + 0.0451f; break;
        case 10: norm_outflow = 1.2128f * norm_inflow + 0.0305f; break;
        case 11: norm_outflow = 0.7403f * norm_inflow + 0.0492f; break;
        case 12: norm_outflow = 0.4499f * norm_inflow + 0.1019f; break;
    }
    return norm_outflow * max_outflow_m3d;
}

static float rule_946(float inflow_m3d, float storage_m3, int month) {
    const float max_inflow_m3d   = 141040211.9f;
    const float max_outflow_m3d  = 18334656.9f;
    const float max_storage_m3   = 581157802.4f;
    const float norm_inflow  = inflow_m3d  / max_inflow_m3d;
    const float norm_storage = storage_m3  / max_storage_m3;
    float norm_outflow;

    switch (month) {
        case  1: norm_outflow = 0.2889f * norm_inflow + 0.1672f; break;
        case  2: norm_outflow = 0.0641f * norm_inflow + 0.1529f; break;
        case  3: norm_outflow = 0.0000f * norm_inflow + 0.1973f; break;
        case  4: norm_outflow = 0.3159f * norm_inflow + 0.1991f; break;
        case  5: norm_outflow = 0.0000f * norm_inflow + 0.2094f; break;
        case  6: norm_outflow = 0.8705f * norm_inflow + 0.1633f; break;
        case  7: norm_outflow = 1.2467f * norm_inflow + 0.0628f; break;
        case  8: norm_outflow = 1.2833f * norm_inflow + 0.0246f; break;
        case  9: norm_outflow = 0.0333f * norm_inflow + 0.0442f; break;
        case 10: norm_outflow = 0.9510f * norm_inflow + 0.0483f; break;
        case 11: norm_outflow = 0.1295f * norm_inflow + 0.1052f; break;
        case 12: norm_outflow = 0.0425f * norm_inflow + 0.1227f; break;
    }
    return norm_outflow * max_outflow_m3d;
}

static float rule_3159(float inflow_m3d, float storage_m3, int month) {
    const float max_inflow_m3d   = 44932934.8f;
    const float max_outflow_m3d  = 4871137.2f;
    const float max_storage_m3   = 186171603.4f;
    const float norm_inflow  = inflow_m3d  / max_inflow_m3d;
    const float norm_storage = storage_m3  / max_storage_m3;
    float norm_outflow;

    switch (month) {
        case  1: norm_outflow = 0.4651f * norm_inflow + 0.2105f; break;
        case  2: norm_outflow = 0.0008f * norm_inflow + 0.1557f; break;
        case  3: norm_outflow = 0.0000f * norm_inflow + 0.2733f; break;
        case  4: norm_outflow = 0.0000f * norm_inflow + 0.2162f; break;
        case  5: norm_outflow = 0.0000f * norm_inflow + 0.2263f; break;
        case  6: norm_outflow = 0.7770f * norm_inflow + 0.1232f; break;
        case  7: norm_outflow = 3.5503f * norm_inflow + 0.0639f; break;
        case  8: norm_outflow = 2.7638f * norm_inflow + 0.0389f; break;
        case  9: norm_outflow = 1.0100f * norm_inflow + 0.0383f; break;
        case 10: norm_outflow = 1.0977f * norm_inflow + 0.0363f; break;
        case 11: norm_outflow = 0.2651f * norm_inflow + 0.0997f; break;
        case 12: norm_outflow = 0.3161f * norm_inflow + 0.1450f; break;
    }
    return norm_outflow * max_outflow_m3d;
}

static float rule_948(float inflow_m3d, float storage_m3, int month) {
    const float max_inflow_m3d   = 203345345.5f;
    const float max_outflow_m3d  = 145077192.5f;
    const float max_storage_m3   = 1282169156.0f;
    const float norm_inflow  = inflow_m3d  / max_inflow_m3d;
    const float norm_storage = storage_m3  / max_storage_m3;
    float norm_outflow;

    switch (month) {
        case  1: norm_outflow = 0.6089f * norm_inflow + 0.0411f; break;
        case  2: norm_outflow = 0.2783f * norm_inflow + 0.0275f; break;
        case  3: norm_outflow = 0.2131f * norm_inflow + 0.0493f; break;
        case  4: norm_outflow = 0.5800f * norm_inflow + 0.0333f; break;
        case  5: norm_outflow = 0.4845f * norm_inflow + 0.0468f; break;
        case  6: norm_outflow = 0.5704f * norm_inflow + 0.0311f; break;
        case  7: norm_outflow = 0.0601f * norm_inflow + 0.0195f; break;
        case  8: norm_outflow = 2.2534f * norm_inflow + 0.0173f; break;
        case  9: norm_outflow = 0.0973f * norm_inflow + 0.0079f; break;
        case 10: norm_outflow = 0.3579f * norm_inflow + 0.0097f; break;
        case 11: norm_outflow = 0.2169f * norm_inflow + 0.0221f; break;
        case 12: norm_outflow = 0.0610f * norm_inflow + 0.0352f; break;
    }
    return norm_outflow * max_outflow_m3d;
}

static float rule_950(float inflow_m3d, float storage_m3, int month) {
    const float max_inflow_m3d   = 42730876.4f;
    const float max_outflow_m3d  = 6918916.5f;
    const float max_storage_m3   = 251649655.7f;
    const float norm_inflow  = inflow_m3d  / max_inflow_m3d;
    const float norm_storage = storage_m3  / max_storage_m3;
    float norm_outflow;

    switch (month) {
        case  1: norm_outflow = 0.4011f * norm_inflow + 0.0409f; break;
        case  2: norm_outflow = 0.5190f * norm_inflow + 0.0491f; break;
        case  3: norm_outflow = 0.4512f * norm_inflow + 0.0753f; break;
        case  4: norm_outflow = 0.7173f * norm_inflow + 0.0554f; break;
        case  5: norm_outflow = 0.5496f * norm_inflow + 0.0605f; break;
        case  6: norm_outflow = 0.8246f * norm_inflow + 0.0595f; break;
        case  7: norm_outflow = 1.0140f * norm_inflow + 0.0259f; break;
        case  8: norm_outflow = 0.1965f * norm_inflow + 0.0048f; break;
        case  9: norm_outflow = 0.2562f * norm_inflow + 0.0030f; break;
        case 10: norm_outflow = 0.5999f * norm_inflow + 0.0074f; break;
        case 11: norm_outflow = 0.6637f * norm_inflow + 0.0242f; break;
        case 12: norm_outflow = 0.5457f * norm_inflow + 0.0409f; break;
    }
    return norm_outflow * max_outflow_m3d;
}

static float rule_168(float inflow_m3d, float storage_m3, int month) {
    const float max_inflow_m3d   = 540145376.5f;
    const float max_outflow_m3d  = 171749638.2f;
    const float max_storage_m3   = 7239669097.9f;
    const float norm_inflow  = inflow_m3d  / max_inflow_m3d;
    const float norm_storage = storage_m3  / max_storage_m3;
    float norm_outflow;

    switch (month) {
        case  1: norm_outflow = 1.4147f * norm_inflow + 0.0507f; break;
        case  2: norm_outflow = 0.6233f * norm_inflow + 0.0431f; break;
        case  3: norm_outflow = 0.9494f * norm_inflow + 0.0523f; break;
        case  4: norm_outflow = 0.8294f * norm_inflow + 0.0564f; break;
        case  5: norm_outflow = 0.8565f * norm_inflow + 0.0507f; break;
        case  6: norm_outflow = 0.9141f * norm_inflow + 0.0781f; break;
        case  7: norm_outflow = 1.0177f * norm_inflow + 0.0723f; break;
        case  8: norm_outflow = 1.9122f * norm_inflow + 0.0572f; break;
        case  9: norm_outflow = 0.7558f * norm_inflow + 0.0311f; break;
        case 10: norm_outflow = 0.3938f * norm_inflow + 0.0210f; break;
        case 11: norm_outflow = 1.3941f * norm_inflow + 0.0172f; break;
        case 12: norm_outflow = 1.4381f * norm_inflow + 0.0339f; break;
    }
    return norm_outflow * max_outflow_m3d;
}

static float rule_954(float inflow_m3d, float storage_m3, int month) {
    const float max_inflow_m3d   = 84351862.4f;
    const float max_outflow_m3d  = 25688982.0f;
    const float max_storage_m3   = 354625500.0f;
    const float norm_inflow  = inflow_m3d  / max_inflow_m3d;
    const float norm_storage = storage_m3  / max_storage_m3;
    float norm_outflow;

    switch (month) {
        case  1: norm_outflow = 0.3257f * norm_inflow + 0.0015f; break;
        case  2: norm_outflow = 0.6412f * norm_inflow + 0.0025f; break;
        case  3: norm_outflow = 0.9124f * norm_inflow + 0.0051f; break;
        case  4: norm_outflow = 1.4539f * norm_inflow + 0.0060f; break;
        case  5: norm_outflow = 1.5340f * norm_inflow + 0.0082f; break;
        case  6: norm_outflow = 1.6814f * norm_inflow + 0.0118f; break;
        case  7: norm_outflow = 0.6301f * norm_inflow + 0.0055f; break;
        case  8: norm_outflow = 0.7992f * norm_inflow + 0.0034f; break;
        case  9: norm_outflow = 0.8411f * norm_inflow + 0.0038f; break;
        case 10: norm_outflow = 0.2372f * norm_inflow + 0.0019f; break;
        case 11: norm_outflow = 0.3333f * norm_inflow + 0.0017f; break;
        case 12: norm_outflow = 0.4561f * norm_inflow + 0.0017f; break;
    }
    return norm_outflow * max_outflow_m3d;
}

static float rule_956(float inflow_m3d, float storage_m3, int month) {
    const float max_inflow_m3d   = 208273334.3f;
    const float max_outflow_m3d  = 145630118.7f;
    const float max_storage_m3   = 1839842732.8f;
    const float norm_inflow  = inflow_m3d  / max_inflow_m3d;
    const float norm_storage = storage_m3  / max_storage_m3;
    float norm_outflow;

    switch (month) {
        case  1: norm_outflow = 1.2499f * norm_inflow + 0.0291f; break;
        case  2: norm_outflow = 0.8470f * norm_inflow + 0.0339f; break;
        case  3: norm_outflow = 1.1282f * norm_inflow + 0.0396f; break;
        case  4: norm_outflow = 1.2314f * norm_inflow + 0.0169f; break;
        case  5: norm_outflow = 0.8028f * norm_inflow + 0.0657f; break;
        case  6: norm_outflow = 1.0762f * norm_inflow + 0.0123f; break;
        case  7: norm_outflow = 1.4747f * norm_inflow + 0.0294f; break;
        case  8: norm_outflow = 1.1593f * norm_inflow + 0.0063f; break;
        case  9: norm_outflow = 0.9846f * norm_inflow + 0.0056f; break;
        case 10: norm_outflow = 1.2482f * norm_inflow + 0.0034f; break;
        case 11: norm_outflow = 0.9704f * norm_inflow + 0.0159f; break;
        case 12: norm_outflow = 0.5719f * norm_inflow + 0.0491f; break;
    }
    return norm_outflow * max_outflow_m3d;
}

static float rule_958(float inflow_m3d, float storage_m3, int month) {
    const float max_inflow_m3d   = 65779606.7f;
    const float max_outflow_m3d  = 18373730.9f;
    const float max_storage_m3   = 155640629.7f;
    const float norm_inflow  = inflow_m3d  / max_inflow_m3d;
    const float norm_storage = storage_m3  / max_storage_m3;
    float norm_outflow;

    switch (month) {
        case  1: norm_outflow = 0.3742f * norm_inflow + 0.0036f; break;
        case  2: norm_outflow = 0.6310f * norm_inflow + 0.0059f; break;
        case  3: norm_outflow = 1.3495f * norm_inflow + 0.0073f; break;
        case  4: norm_outflow = 1.2912f * norm_inflow + 0.0068f; break;
        case  5: norm_outflow = 1.3457f * norm_inflow + 0.0180f; break;
        case  6: norm_outflow = 1.8875f * norm_inflow + 0.0168f; break;
        case  7: norm_outflow = 0.4319f * norm_inflow + 0.0046f; break;
        case  8: norm_outflow = 0.4023f * norm_inflow + 0.0024f; break;
        case  9: norm_outflow = 1.0856f * norm_inflow + 0.0076f; break;
        case 10: norm_outflow = 0.0154f * norm_inflow + 0.0039f; break;
        case 11: norm_outflow = 0.7728f * norm_inflow + 0.0026f; break;
        case 12: norm_outflow = 0.8819f * norm_inflow + 0.0045f; break;
    }
    return norm_outflow * max_outflow_m3d;
}

static float rule_962(float inflow_m3d, float storage_m3, int month) {
    const float max_inflow_m3d   = 165592156.4f;
    const float max_outflow_m3d  = 62492965.8f;
    const float max_storage_m3   = 577292076.1f;
    const float norm_inflow  = inflow_m3d  / max_inflow_m3d;
    const float norm_storage = storage_m3  / max_storage_m3;
    float norm_outflow;

    switch (month) {
        case  1: norm_outflow = 0.9503f * norm_inflow + 0.0163f; break;
        case  2: norm_outflow = 1.1079f * norm_inflow + 0.0159f; break;
        case  3: norm_outflow = 1.0669f * norm_inflow + 0.0170f; break;
        case  4: norm_outflow = 1.1206f * norm_inflow + 0.0160f; break;
        case  5: norm_outflow = 1.0989f * norm_inflow + 0.0120f; break;
        case  6: norm_outflow = 1.0499f * norm_inflow + 0.0128f; break;
        case  7: norm_outflow = 1.0825f * norm_inflow + 0.0120f; break;
        case  8: norm_outflow = 0.9358f * norm_inflow + 0.0138f; break;
        case  9: norm_outflow = 0.9659f * norm_inflow + 0.0100f; break;
        case 10: norm_outflow = 1.0559f * norm_inflow + 0.0123f; break;
        case 11: norm_outflow = 0.9750f * norm_inflow + 0.0133f; break;
        case 12: norm_outflow = 1.0712f * norm_inflow + 0.0170f; break;
    }
    return norm_outflow * max_outflow_m3d;
}

static float rule_986(float inflow_m3d, float storage_m3, int month) {
    const float max_inflow_m3d   = 101109736.5f;
    const float max_outflow_m3d  = 27176831.6f;
    const float max_storage_m3   = 760632843.0f;
    const float norm_inflow  = inflow_m3d  / max_inflow_m3d;
    const float norm_storage = storage_m3  / max_storage_m3;
    float norm_outflow;

    switch (month) {
        case  1: norm_outflow = 0.9069f * norm_inflow + 0.0539f; break;
        case  2: norm_outflow = 2.0017f * norm_inflow + 0.0378f; break;
        case  3: norm_outflow = 0.2603f * norm_inflow + 0.0785f; break;
        case  4: norm_outflow = 0.5758f * norm_inflow + 0.0719f; break;
        case  5: norm_outflow = 0.1930f * norm_inflow + 0.0794f; break;
        case  6: norm_outflow = 0.7622f * norm_inflow + 0.0492f; break;
        case  7: norm_outflow = 0.4981f * norm_inflow + 0.0476f; break;
        case  8: norm_outflow = 0.6058f * norm_inflow + 0.0346f; break;
        case  9: norm_outflow = 0.0053f * norm_inflow + 0.0251f; break;
        case 10: norm_outflow = 0.5766f * norm_inflow + 0.0281f; break;
        case 11: norm_outflow = 1.0655f * norm_inflow + 0.0374f; break;
        case 12: norm_outflow = 0.5504f * norm_inflow + 0.0457f; break;
    }
    return norm_outflow * max_outflow_m3d;
}

static float rule_989(float inflow_m3d, float storage_m3, int month) {
    const float max_inflow_m3d   = 98047357.0f;
    const float max_outflow_m3d  = 53824719.8f;
    const float max_storage_m3   = 405369633.7f;
    const float norm_inflow  = inflow_m3d  / max_inflow_m3d;
    const float norm_storage = storage_m3  / max_storage_m3;
    float norm_outflow;

    switch (month) {
        case  1: norm_outflow = 1.4127f * norm_inflow + 0.0556f; break;
        case  2: norm_outflow = 1.1110f * norm_inflow + 0.1129f; break;
        case  3: norm_outflow = 1.2206f * norm_inflow + 0.1099f; break;
        case  4: norm_outflow = 1.1727f * norm_inflow + 0.0936f; break;
        case  5: norm_outflow = 1.4193f * norm_inflow + 0.0569f; break;
        case  6: norm_outflow = 1.1752f * norm_inflow + 0.0428f; break;
        case  7: norm_outflow = 1.3382f * norm_inflow + 0.0201f; break;
        case  8: norm_outflow = 0.5486f * norm_inflow + 0.0199f; break;
        case  9: norm_outflow = 0.3354f * norm_inflow + 0.0098f; break;
        case 10: norm_outflow = 0.8725f * norm_inflow + 0.0172f; break;
        case 11: norm_outflow = 1.3700f * norm_inflow + 0.0206f; break;
        case 12: norm_outflow = 1.1860f * norm_inflow + 0.0726f; break;
    }
    return norm_outflow * max_outflow_m3d;
}

static float rule_2664(float inflow_m3d, float storage_m3, int month) {
    const float max_inflow_m3d   = 48605707.5f;
    const float max_outflow_m3d  = 23902995.9f;
    const float max_storage_m3   = 208682613.4f;
    const float norm_inflow  = inflow_m3d  / max_inflow_m3d;
    const float norm_storage = storage_m3  / max_storage_m3;
    float norm_outflow;

    switch (month) {
        case  1: norm_outflow = 1.0320f * norm_inflow + 0.0522f; break;
        case  2: norm_outflow = 1.0918f * norm_inflow + 0.0469f; break;
        case  3: norm_outflow = 1.5594f * norm_inflow + 0.0343f; break;
        case  4: norm_outflow = 1.3574f * norm_inflow + 0.0264f; break;
        case  5: norm_outflow = 0.8167f * norm_inflow + 0.0453f; break;
        case  6: norm_outflow = 0.7203f * norm_inflow + 0.0566f; break;
        case  7: norm_outflow = 0.8198f * norm_inflow + 0.0418f; break;
        case  8: norm_outflow = 0.9329f * norm_inflow + 0.0188f; break;
        case  9: norm_outflow = 1.1484f * norm_inflow + 0.0108f; break;
        case 10: norm_outflow = 1.2596f * norm_inflow + 0.0139f; break;
        case 11: norm_outflow = 1.1749f * norm_inflow + 0.0213f; break;
        case 12: norm_outflow = 1.3829f * norm_inflow + 0.0243f; break;
    }
    return norm_outflow * max_outflow_m3d;
}

static float rule_2666(float inflow_m3d, float storage_m3, int month) {
    const float max_inflow_m3d   = 42734294.5f;
    const float max_outflow_m3d  = 22062384.1f;
    const float max_storage_m3   = 321478192.0f;
    const float norm_inflow  = inflow_m3d  / max_inflow_m3d;
    const float norm_storage = storage_m3  / max_storage_m3;
    float norm_outflow;

    switch (month) {
        case  1: norm_outflow = 0.2087f * norm_inflow + 0.0748f; break;
        case  2: norm_outflow = 0.2192f * norm_inflow + 0.0780f; break;
        case  3: norm_outflow = 0.4337f * norm_inflow + 0.0773f; break;
        case  4: norm_outflow = 0.1788f * norm_inflow + 0.0390f; break;
        case  5: norm_outflow = 0.0950f * norm_inflow + 0.0592f; break;
        case  6: norm_outflow = 0.2590f * norm_inflow + 0.0693f; break;
        case  7: norm_outflow = 0.4350f * norm_inflow + 0.0444f; break;
        case  8: norm_outflow = 0.3614f * norm_inflow + 0.0306f; break;
        case  9: norm_outflow = 0.8260f * norm_inflow + 0.0247f; break;
        case 10: norm_outflow = 0.2262f * norm_inflow + 0.0565f; break;
        case 11: norm_outflow = 0.3344f * norm_inflow + 0.0614f; break;
        case 12: norm_outflow = 0.4395f * norm_inflow + 0.0633f; break;
    }
    return norm_outflow * max_outflow_m3d;
}

static float rule_758(float inflow_m3d, float storage_m3, int month) {
    const float max_inflow_m3d   = 57288650.5f;
    const float max_outflow_m3d  = 15814955.2f;
    const float max_storage_m3   = 430488220.4f;
    const float norm_inflow  = inflow_m3d  / max_inflow_m3d;
    const float norm_storage = storage_m3  / max_storage_m3;
    float norm_outflow;

    switch (month) {
        case  1: norm_outflow = 0.6113f * norm_inflow + 0.1579f; break;
        case  2: norm_outflow = 0.4702f * norm_inflow + 0.1551f; break;
        case  3: norm_outflow = 0.9598f * norm_inflow + 0.1587f; break;
        case  4: norm_outflow = 0.6355f * norm_inflow + 0.0973f; break;
        case  5: norm_outflow = 1.0193f * norm_inflow + 0.1021f; break;
        case  6: norm_outflow = 0.8906f * norm_inflow + 0.1148f; break;
        case  7: norm_outflow = 0.8821f * norm_inflow + 0.0755f; break;
        case  8: norm_outflow = 0.9914f * norm_inflow + 0.0511f; break;
        case  9: norm_outflow = 2.0308f * norm_inflow + 0.0275f; break;
        case 10: norm_outflow = 2.3471f * norm_inflow + 0.0527f; break;
        case 11: norm_outflow = 0.4542f * norm_inflow + 0.1139f; break;
        case 12: norm_outflow = 1.0057f * norm_inflow + 0.1187f; break;
    }
    return norm_outflow * max_outflow_m3d;
}

static float rule_2684(float inflow_m3d, float storage_m3, int month) {
    const float max_inflow_m3d   = 54088200.2f;
    const float max_outflow_m3d  = 32776801.7f;
    const float max_storage_m3   = 262282253.3f;
    const float norm_inflow  = inflow_m3d  / max_inflow_m3d;
    const float norm_storage = storage_m3  / max_storage_m3;
    float norm_outflow;

    switch (month) {
        case  1: norm_outflow = 1.0168f * norm_inflow + 0.0720f; break;
        case  2: norm_outflow = 1.3250f * norm_inflow + 0.0434f; break;
        case  3: norm_outflow = 1.1033f * norm_inflow + 0.0726f; break;
        case  4: norm_outflow = 1.3218f * norm_inflow + 0.0453f; break;
        case  5: norm_outflow = 1.2607f * norm_inflow + 0.0401f; break;
        case  6: norm_outflow = 0.9652f * norm_inflow + 0.0544f; break;
        case  7: norm_outflow = 1.3751f * norm_inflow + 0.0205f; break;
        case  8: norm_outflow = 1.5137f * norm_inflow + 0.0040f; break;
        case  9: norm_outflow = 1.4617f * norm_inflow + 0.0045f; break;
        case 10: norm_outflow = 1.5565f * norm_inflow + 0.0028f; break;
        case 11: norm_outflow = 1.2485f * norm_inflow + 0.0180f; break;
        case 12: norm_outflow = 1.1870f * norm_inflow + 0.0396f; break;
    }
    return norm_outflow * max_outflow_m3d;
}

static float rule_2694(float inflow_m3d, float storage_m3, int month) {
    const float max_inflow_m3d   = 23974816.1f;
    const float max_outflow_m3d  = 4833758.7f;
    const float max_storage_m3   = 43427130.4f;
    const float norm_inflow  = inflow_m3d  / max_inflow_m3d;
    const float norm_storage = storage_m3  / max_storage_m3;
    float norm_outflow;

    switch (month) {
        case  1: norm_outflow = 2.1920f * norm_inflow + 0.0902f; break;
        case  2: norm_outflow = 1.6838f * norm_inflow + 0.0744f; break;
        case  3: norm_outflow = 2.2997f * norm_inflow + 0.0863f; break;
        case  4: norm_outflow = 2.5652f * norm_inflow + 0.0857f; break;
        case  5: norm_outflow = 2.6208f * norm_inflow + 0.0680f; break;
        case  6: norm_outflow = 2.2444f * norm_inflow + 0.0582f; break;
        case  7: norm_outflow = 1.8827f * norm_inflow + 0.0518f; break;
        case  8: norm_outflow = 2.1494f * norm_inflow + 0.0247f; break;
        case  9: norm_outflow = 3.2826f * norm_inflow + 0.0110f; break;
        case 10: norm_outflow = 2.5450f * norm_inflow + 0.0167f; break;
        case 11: norm_outflow = 1.6094f * norm_inflow + 0.0504f; break;
        case 12: norm_outflow = 1.6812f * norm_inflow + 0.0888f; break;
    }
    return norm_outflow * max_outflow_m3d;
}

static float rule_2708(float inflow_m3d, float storage_m3, int month) {
    const float max_inflow_m3d   = 6157870.3f;
    const float max_outflow_m3d  = 2245645.3f;
    const float max_storage_m3   = 46059376.7f;
    const float norm_inflow  = inflow_m3d  / max_inflow_m3d;
    const float norm_storage = storage_m3  / max_storage_m3;
    float norm_outflow;

    switch (month) {
        case  1: norm_outflow = 0.1124f * norm_inflow + 0.0988f; break;
        case  2: norm_outflow = 0.1019f * norm_inflow + 0.0889f; break;
        case  3: norm_outflow = 0.3102f * norm_inflow + 0.0652f; break;
        case  4: norm_outflow = 0.2898f * norm_inflow + 0.1368f; break;
        case  5: norm_outflow = 0.6386f * norm_inflow + 0.1012f; break;
        case  6: norm_outflow = 0.6993f * norm_inflow + 0.0745f; break;
        case  7: norm_outflow = 1.1188f * norm_inflow + 0.0401f; break;
        case  8: norm_outflow = 0.8723f * norm_inflow + 0.0363f; break;
        case  9: norm_outflow = 0.5975f * norm_inflow + 0.0426f; break;
        case 10: norm_outflow = 1.4239f * norm_inflow + 0.0220f; break;
        case 11: norm_outflow = 0.5947f * norm_inflow + 0.1276f; break;
        case 12: norm_outflow = 0.3175f * norm_inflow + 0.1075f; break;
    }
    return norm_outflow * max_outflow_m3d;
}

static float rule_2731(float inflow_m3d, float storage_m3, int month) {
    const float max_inflow_m3d   = 7229293.0f;
    const float max_outflow_m3d  = 1895874.7f;
    const float max_storage_m3   = 59966863.7f;
    const float norm_inflow  = inflow_m3d  / max_inflow_m3d;
    const float norm_storage = storage_m3  / max_storage_m3;
    float norm_outflow;

    switch (month) {
        case  1: norm_outflow = 0.5022f * norm_inflow + 0.1269f; break;
        case  2: norm_outflow = 1.2503f * norm_inflow + 0.0578f; break;
        case  3: norm_outflow = 0.8120f * norm_inflow + 0.0460f; break;
        case  4: norm_outflow = 1.2312f * norm_inflow + 0.0764f; break;
        case  5: norm_outflow = 2.1304f * norm_inflow + 0.0645f; break;
        case  6: norm_outflow = 1.5639f * norm_inflow + 0.0510f; break;
        case  7: norm_outflow = 0.4216f * norm_inflow + 0.0370f; break;
        case  8: norm_outflow = 0.9346f * norm_inflow + 0.0198f; break;
        case  9: norm_outflow = 0.4669f * norm_inflow + 0.0260f; break;
        case 10: norm_outflow = 1.7659f * norm_inflow + 0.0206f; break;
        case 11: norm_outflow = 2.9546f * norm_inflow + 0.1655f; break;
        case 12: norm_outflow = 1.1525f * norm_inflow + 0.1855f; break;
    }
    return norm_outflow * max_outflow_m3d;
}

static float rule_2741(float inflow_m3d, float storage_m3, int month) {
    const float max_inflow_m3d   = 8304629.0f;
    const float max_outflow_m3d  = 1969732.1f;
    const float max_storage_m3   = 47951535.0f;
    const float norm_inflow  = inflow_m3d  / max_inflow_m3d;
    const float norm_storage = storage_m3  / max_storage_m3;
    float norm_outflow;

    switch (month) {
        case  1: norm_outflow = 0.4371f * norm_inflow + 0.1416f; break;
        case  2: norm_outflow = 1.1141f * norm_inflow + 0.0755f; break;
        case  3: norm_outflow = 1.2799f * norm_inflow + 0.0718f; break;
        case  4: norm_outflow = 1.1202f * norm_inflow + 0.1129f; break;
        case  5: norm_outflow = 1.8593f * norm_inflow + 0.0839f; break;
        case  6: norm_outflow = 0.9860f * norm_inflow + 0.0617f; break;
        case  7: norm_outflow = 1.2073f * norm_inflow + 0.0468f; break;
        case  8: norm_outflow = 1.3912f * norm_inflow + 0.0218f; break;
        case  9: norm_outflow = 0.6368f * norm_inflow + 0.0346f; break;
        case 10: norm_outflow = 1.6563f * norm_inflow + 0.0236f; break;
        case 11: norm_outflow = 1.3679f * norm_inflow + 0.1188f; break;
        case 12: norm_outflow = 0.6711f * norm_inflow + 0.1650f; break;
    }
    return norm_outflow * max_outflow_m3d;
}

static float rule_2744(float inflow_m3d, float storage_m3, int month) {
    const float max_inflow_m3d   = 20552865.0f;
    const float max_outflow_m3d  = 1747788.4f;
    const float max_storage_m3   = 68659970.4f;
    const float norm_inflow  = inflow_m3d  / max_inflow_m3d;
    const float norm_storage = storage_m3  / max_storage_m3;
    float norm_outflow;

    switch (month) {
        case  1: norm_outflow = 0.6336f * norm_inflow + 0.1769f; break;
        case  2: norm_outflow = 1.5428f * norm_inflow + 0.0981f; break;
        case  3: norm_outflow = 2.8176f * norm_inflow + 0.0757f; break;
        case  4: norm_outflow = 3.2190f * norm_inflow + 0.1310f; break;
        case  5: norm_outflow = 0.2532f * norm_inflow + 0.1786f; break;
        case  6: norm_outflow = 1.9241f * norm_inflow + 0.1075f; break;
        case  7: norm_outflow = 2.5873f * norm_inflow + 0.0871f; break;
        case  8: norm_outflow = 1.5108f * norm_inflow + 0.0665f; break;
        case  9: norm_outflow = 0.7644f * norm_inflow + 0.0640f; break;
        case 10: norm_outflow = 5.2087f * norm_inflow + 0.0450f; break;
        case 11: norm_outflow = 4.4435f * norm_inflow + 0.1524f; break;
        case 12: norm_outflow = 3.9718f * norm_inflow + 0.2135f; break;
    }
    return norm_outflow * max_outflow_m3d;
}

static float rule_2764(float inflow_m3d, float storage_m3, int month) {
    const float max_inflow_m3d   = 8382860.0f;
    const float max_outflow_m3d  = 4660731.4f;
    const float max_storage_m3   = 325789204.6f;
    const float norm_inflow  = inflow_m3d  / max_inflow_m3d;
    const float norm_storage = storage_m3  / max_storage_m3;
    float norm_outflow;

    switch (month) {
        case  1: norm_outflow = 0.1219f * norm_inflow + 0.0441f; break;
        case  2: norm_outflow = 0.2819f * norm_inflow + 0.0455f; break;
        case  3: norm_outflow = 0.2818f * norm_inflow + 0.0524f; break;
        case  4: norm_outflow = 0.7769f * norm_inflow + 0.0587f; break;
        case  5: norm_outflow = 0.5761f * norm_inflow + 0.0756f; break;
        case  6: norm_outflow = 0.9759f * norm_inflow + 0.0642f; break;
        case  7: norm_outflow = 1.3209f * norm_inflow + 0.0584f; break;
        case  8: norm_outflow = 1.0909f * norm_inflow + 0.0615f; break;
        case  9: norm_outflow = 0.3132f * norm_inflow + 0.0610f; break;
        case 10: norm_outflow = 0.4355f * norm_inflow + 0.0554f; break;
        case 11: norm_outflow = 0.8428f * norm_inflow + 0.0496f; break;
        case 12: norm_outflow = 0.2146f * norm_inflow + 0.0450f; break;
    }
    return norm_outflow * max_outflow_m3d;
}

static float rule_2767(float inflow_m3d, float storage_m3, int month) {
    const float max_inflow_m3d   = 72976087.7f;
    const float max_outflow_m3d  = 25142266.9f;
    const float max_storage_m3   = 744909673.3f;
    const float norm_inflow  = inflow_m3d  / max_inflow_m3d;
    const float norm_storage = storage_m3  / max_storage_m3;
    float norm_outflow;

    switch (month) {
        case  1: norm_outflow = 0.2073f * norm_inflow + 0.1356f; break;
        case  2: norm_outflow = 0.0000f * norm_inflow + 0.1512f; break;
        case  3: norm_outflow = 0.0000f * norm_inflow + 0.1244f; break;
        case  4: norm_outflow = 0.2153f * norm_inflow + 0.0645f; break;
        case  5: norm_outflow = 0.0958f * norm_inflow + 0.1179f; break;
        case  6: norm_outflow = 1.3771f * norm_inflow + 0.0570f; break;
        case  7: norm_outflow = 0.7889f * norm_inflow + 0.0345f; break;
        case  8: norm_outflow = 1.1995f * norm_inflow + 0.0152f; break;
        case  9: norm_outflow = 0.5547f * norm_inflow + 0.0303f; break;
        case 10: norm_outflow = 0.8931f * norm_inflow + 0.0797f; break;
        case 11: norm_outflow = 0.2775f * norm_inflow + 0.1304f; break;
        case 12: norm_outflow = 0.1283f * norm_inflow + 0.1043f; break;
    }
    return norm_outflow * max_outflow_m3d;
}

static float rule_777(float inflow_m3d, float storage_m3, int month) {
    const float max_inflow_m3d   = 24288544.3f;
    const float max_outflow_m3d  = 2356735.5f;
    const float max_storage_m3   = 108253905.2f;
    const float norm_inflow  = inflow_m3d  / max_inflow_m3d;
    const float norm_storage = storage_m3  / max_storage_m3;
    float norm_outflow;

    switch (month) {
        case  1: norm_outflow = 0.0502f * norm_inflow + 0.1971f; break;
        case  2: norm_outflow = 0.5643f * norm_inflow + 0.1442f; break;
        case  3: norm_outflow = 0.6015f * norm_inflow + 0.1238f; break;
        case  4: norm_outflow = 0.5636f * norm_inflow + 0.1766f; break;
        case  5: norm_outflow = 1.2450f * norm_inflow + 0.1645f; break;
        case  6: norm_outflow = 0.5239f * norm_inflow + 0.1015f; break;
        case  7: norm_outflow = 0.4075f * norm_inflow + 0.0653f; break;
        case  8: norm_outflow = 2.5381f * norm_inflow + 0.0219f; break;
        case  9: norm_outflow = 0.5762f * norm_inflow + 0.0328f; break;
        case 10: norm_outflow = 2.8909f * norm_inflow + 0.0327f; break;
        case 11: norm_outflow = 1.2947f * norm_inflow + 0.2278f; break;
        case 12: norm_outflow = 0.5449f * norm_inflow + 0.2223f; break;
    }
    return norm_outflow * max_outflow_m3d;
}

static float rule_2787(float inflow_m3d, float storage_m3, int month) {
    const float max_inflow_m3d   = 39190371.2f;
    const float max_outflow_m3d  = 4420759.2f;
    const float max_storage_m3   = 163944293.8f;
    const float norm_inflow  = inflow_m3d  / max_inflow_m3d;
    const float norm_storage = storage_m3  / max_storage_m3;
    float norm_outflow;

    switch (month) {
        case  1: norm_outflow = 0.0000f * norm_inflow + 0.1684f; break;
        case  2: norm_outflow = 0.0000f * norm_inflow + 0.1728f; break;
        case  3: norm_outflow = 0.0000f * norm_inflow + 0.1175f; break;
        case  4: norm_outflow = 0.0000f * norm_inflow + 0.1045f; break;
        case  5: norm_outflow = 0.0000f * norm_inflow + 0.1404f; break;
        case  6: norm_outflow = 0.0000f * norm_inflow + 0.1560f; break;
        case  7: norm_outflow = 0.9335f * norm_inflow + 0.0985f; break;
        case  8: norm_outflow = 2.1239f * norm_inflow + 0.0514f; break;
        case  9: norm_outflow = 0.2357f * norm_inflow + 0.0443f; break;
        case 10: norm_outflow = 0.5690f * norm_inflow + 0.1356f; break;
        case 11: norm_outflow = 0.0000f * norm_inflow + 0.2453f; break;
        case 12: norm_outflow = 0.0000f * norm_inflow + 0.1585f; break;
    }
    return norm_outflow * max_outflow_m3d;
}

static float rule_2801(float inflow_m3d, float storage_m3, int month) {
    const float max_inflow_m3d   = 5535953.7f;
    const float max_outflow_m3d  = 2056500.5f;
    const float max_storage_m3   = 21333036.6f;
    const float norm_inflow  = inflow_m3d  / max_inflow_m3d;
    const float norm_storage = storage_m3  / max_storage_m3;
    float norm_outflow;

    switch (month) {
        case  1: norm_outflow = 0.7093f * norm_inflow + 0.0584f; break;
        case  2: norm_outflow = 0.7324f * norm_inflow + 0.0570f; break;
        case  3: norm_outflow = 0.6631f * norm_inflow + 0.0831f; break;
        case  4: norm_outflow = 0.8063f * norm_inflow + 0.0681f; break;
        case  5: norm_outflow = 0.5364f * norm_inflow + 0.0645f; break;
        case  6: norm_outflow = 0.4460f * norm_inflow + 0.0320f; break;
        case  7: norm_outflow = 0.5035f * norm_inflow + 0.0269f; break;
        case  8: norm_outflow = 0.4191f * norm_inflow + 0.0144f; break;
        case  9: norm_outflow = 0.3206f * norm_inflow + 0.0160f; break;
        case 10: norm_outflow = 1.1413f * norm_inflow + 0.0102f; break;
        case 11: norm_outflow = 1.2296f * norm_inflow + 0.0107f; break;
        case 12: norm_outflow = 0.7157f * norm_inflow + 0.0324f; break;
    }
    return norm_outflow * max_outflow_m3d;
}

static float rule_2806(float inflow_m3d, float storage_m3, int month) {
    const float max_inflow_m3d   = 36711261.9f;
    const float max_outflow_m3d  = 5358619.2f;
    const float max_storage_m3   = 215783757.7f;
    const float norm_inflow  = inflow_m3d  / max_inflow_m3d;
    const float norm_storage = storage_m3  / max_storage_m3;
    float norm_outflow;

    switch (month) {
        case  1: norm_outflow = 0.0000f * norm_inflow + 0.2307f; break;
        case  2: norm_outflow = 0.0000f * norm_inflow + 0.2447f; break;
        case  3: norm_outflow = 0.0000f * norm_inflow + 0.2562f; break;
        case  4: norm_outflow = 0.0000f * norm_inflow + 0.2748f; break;
        case  5: norm_outflow = 0.0000f * norm_inflow + 0.2519f; break;
        case  6: norm_outflow = 0.0000f * norm_inflow + 0.2207f; break;
        case  7: norm_outflow = 0.3782f * norm_inflow + 0.1686f; break;
        case  8: norm_outflow = 0.5483f * norm_inflow + 0.0851f; break;
        case  9: norm_outflow = 0.5280f * norm_inflow + 0.0578f; break;
        case 10: norm_outflow = 0.7255f * norm_inflow + 0.0791f; break;
        case 11: norm_outflow = 0.1058f * norm_inflow + 0.1093f; break;
        case 12: norm_outflow = 0.0288f * norm_inflow + 0.1623f; break;
    }
    return norm_outflow * max_outflow_m3d;
}

static float rule_788(float inflow_m3d, float storage_m3, int month) {
    const float max_inflow_m3d   = 32975260.1f;
    const float max_outflow_m3d  = 7628023.0f;
    const float max_storage_m3   = 222443316.2f;
    const float norm_inflow  = inflow_m3d  / max_inflow_m3d;
    const float norm_storage = storage_m3  / max_storage_m3;
    float norm_outflow;

    switch (month) {
        case  1: norm_outflow = 0.5513f * norm_inflow + 0.1009f; break;
        case  2: norm_outflow = 0.6406f * norm_inflow + 0.1165f; break;
        case  3: norm_outflow = 0.4483f * norm_inflow + 0.1378f; break;
        case  4: norm_outflow = 0.6113f * norm_inflow + 0.0912f; break;
        case  5: norm_outflow = 0.8660f * norm_inflow + 0.1120f; break;
        case  6: norm_outflow = 0.6089f * norm_inflow + 0.0743f; break;
        case  7: norm_outflow = 1.7095f * norm_inflow + 0.0239f; break;
        case  8: norm_outflow = 1.7906f * norm_inflow + 0.0107f; break;
        case  9: norm_outflow = 1.7588f * norm_inflow + 0.0175f; break;
        case 10: norm_outflow = 2.2024f * norm_inflow + 0.0221f; break;
        case 11: norm_outflow = 1.5307f * norm_inflow + 0.0518f; break;
        case 12: norm_outflow = 0.9981f * norm_inflow + 0.0749f; break;
    }
    return norm_outflow * max_outflow_m3d;
}

static float rule_794(float inflow_m3d, float storage_m3, int month) {
    const float max_inflow_m3d   = 136607078.2f;
    const float max_outflow_m3d  = 12477548.7f;
    const float max_storage_m3   = 643491714.2f;
    const float norm_inflow  = inflow_m3d  / max_inflow_m3d;
    const float norm_storage = storage_m3  / max_storage_m3;
    float norm_outflow;

    switch (month) {
        case  1: norm_outflow = 1.0152f * norm_inflow + 0.2815f; break;
        case  2: norm_outflow = 4.5162f * norm_inflow + 0.2223f; break;
        case  3: norm_outflow = 5.6022f * norm_inflow + 0.1539f; break;
        case  4: norm_outflow = 1.5372f * norm_inflow + 0.1416f; break;
        case  5: norm_outflow = 1.5900f * norm_inflow + 0.1131f; break;
        case  6: norm_outflow = 1.0805f * norm_inflow + 0.1498f; break;
        case  7: norm_outflow = 0.0000f * norm_inflow + 0.1733f; break;
        case  8: norm_outflow = 0.0000f * norm_inflow + 0.1131f; break;
        case  9: norm_outflow = 0.3423f * norm_inflow + 0.0392f; break;
        case 10: norm_outflow = 1.4833f * norm_inflow + 0.0318f; break;
        case 11: norm_outflow = 1.2918f * norm_inflow + 0.0629f; break;
        case 12: norm_outflow = 1.5217f * norm_inflow + 0.2360f; break;
    }
    return norm_outflow * max_outflow_m3d;
}

static float rule_2862(float inflow_m3d, float storage_m3, int month) {
    const float max_inflow_m3d   = 36649286.9f;
    const float max_outflow_m3d  = 11850646.2f;
    const float max_storage_m3   = 261239962.7f;
    const float norm_inflow  = inflow_m3d  / max_inflow_m3d;
    const float norm_storage = storage_m3  / max_storage_m3;
    float norm_outflow;

    switch (month) {
        case  1: norm_outflow = 0.3572f * norm_inflow + 0.1004f; break;
        case  2: norm_outflow = 0.3141f * norm_inflow + 0.1267f; break;
        case  3: norm_outflow = 0.2290f * norm_inflow + 0.1493f; break;
        case  4: norm_outflow = 0.3622f * norm_inflow + 0.1055f; break;
        case  5: norm_outflow = 0.5042f * norm_inflow + 0.1190f; break;
        case  6: norm_outflow = 0.7386f * norm_inflow + 0.0509f; break;
        case  7: norm_outflow = 0.7155f * norm_inflow + 0.0260f; break;
        case  8: norm_outflow = 0.7216f * norm_inflow + 0.0178f; break;
        case  9: norm_outflow = 0.5897f * norm_inflow + 0.0216f; break;
        case 10: norm_outflow = 0.5392f * norm_inflow + 0.0302f; break;
        case 11: norm_outflow = 0.5918f * norm_inflow + 0.0458f; break;
        case 12: norm_outflow = 0.4702f * norm_inflow + 0.0845f; break;
    }
    return norm_outflow * max_outflow_m3d;
}

static float rule_2879(float inflow_m3d, float storage_m3, int month) {
    const float max_inflow_m3d   = 17377081.1f;
    const float max_outflow_m3d  = 6216265.5f;
    const float max_storage_m3   = 48943252.9f;
    const float norm_inflow  = inflow_m3d  / max_inflow_m3d;
    const float norm_storage = storage_m3  / max_storage_m3;
    float norm_outflow;

    switch (month) {
        case  1: norm_outflow = 1.0633f * norm_inflow + 0.1068f; break;
        case  2: norm_outflow = 0.8925f * norm_inflow + 0.1337f; break;
        case  3: norm_outflow = 0.9363f * norm_inflow + 0.1311f; break;
        case  4: norm_outflow = 1.0486f * norm_inflow + 0.0504f; break;
        case  5: norm_outflow = 1.3671f * norm_inflow + 0.0700f; break;
        case  6: norm_outflow = 1.4280f * norm_inflow + 0.0329f; break;
        case  7: norm_outflow = 1.2386f * norm_inflow + 0.0284f; break;
        case  8: norm_outflow = 0.9992f * norm_inflow + 0.0315f; break;
        case  9: norm_outflow = 1.1688f * norm_inflow + 0.0143f; break;
        case 10: norm_outflow = 1.6137f * norm_inflow + 0.0313f; break;
        case 11: norm_outflow = 1.0511f * norm_inflow + 0.0945f; break;
        case 12: norm_outflow = 1.2277f * norm_inflow + 0.0893f; break;
    }
    return norm_outflow * max_outflow_m3d;
}

static float rule_2894(float inflow_m3d, float storage_m3, int month) {
    const float max_inflow_m3d   = 78843108.0f;
    const float max_outflow_m3d  = 23952007.6f;
    const float max_storage_m3   = 169830460.3f;
    const float norm_inflow  = inflow_m3d  / max_inflow_m3d;
    const float norm_storage = storage_m3  / max_storage_m3;
    float norm_outflow;

    switch (month) {
        case  1: norm_outflow = 1.8033f * norm_inflow + 0.0778f; break;
        case  2: norm_outflow = 1.6822f * norm_inflow + 0.0982f; break;
        case  3: norm_outflow = 1.6617f * norm_inflow + 0.1069f; break;
        case  4: norm_outflow = 1.8712f * norm_inflow + 0.0377f; break;
        case  5: norm_outflow = 2.1181f * norm_inflow + 0.0579f; break;
        case  6: norm_outflow = 2.1517f * norm_inflow + 0.0280f; break;
        case  7: norm_outflow = 1.9917f * norm_inflow + 0.0271f; break;
        case  8: norm_outflow = 1.8652f * norm_inflow + 0.0272f; break;
        case  9: norm_outflow = 2.6938f * norm_inflow + 0.0130f; break;
        case 10: norm_outflow = 2.6667f * norm_inflow + 0.0259f; break;
        case 11: norm_outflow = 1.0204f * norm_inflow + 0.1035f; break;
        case 12: norm_outflow = 1.8570f * norm_inflow + 0.0822f; break;
    }
    return norm_outflow * max_outflow_m3d;
}

static float rule_2912(float inflow_m3d, float storage_m3, int month) {
    const float max_inflow_m3d   = 26759767.0f;
    const float max_outflow_m3d  = 6538271.3f;
    const float max_storage_m3   = 85972322.5f;
    const float norm_inflow  = inflow_m3d  / max_inflow_m3d;
    const float norm_storage = storage_m3  / max_storage_m3;
    float norm_outflow;

    switch (month) {
        case  1: norm_outflow = 1.4038f * norm_inflow + 0.1312f; break;
        case  2: norm_outflow = 1.9394f * norm_inflow + 0.1063f; break;
        case  3: norm_outflow = 1.8413f * norm_inflow + 0.1330f; break;
        case  4: norm_outflow = 2.3544f * norm_inflow + 0.0915f; break;
        case  5: norm_outflow = 2.6824f * norm_inflow + 0.0534f; break;
        case  6: norm_outflow = 2.1719f * norm_inflow + 0.0642f; break;
        case  7: norm_outflow = 2.8370f * norm_inflow + 0.0277f; break;
        case  8: norm_outflow = 2.4306f * norm_inflow + 0.0251f; break;
        case  9: norm_outflow = 2.8507f * norm_inflow + 0.0166f; break;
        case 10: norm_outflow = 2.8378f * norm_inflow + 0.0188f; break;
        case 11: norm_outflow = 2.3308f * norm_inflow + 0.0350f; break;
        case 12: norm_outflow = 1.9054f * norm_inflow + 0.0750f; break;
    }
    return norm_outflow * max_outflow_m3d;
}

static float rule_2916(float inflow_m3d, float storage_m3, int month) {
    const float max_inflow_m3d   = 40415427.9f;
    const float max_outflow_m3d  = 10161564.9f;
    const float max_storage_m3   = 107480513.3f;
    const float norm_inflow  = inflow_m3d  / max_inflow_m3d;
    const float norm_storage = storage_m3  / max_storage_m3;
    float norm_outflow;

    switch (month) {
        case  1: norm_outflow = 1.5741f * norm_inflow + 0.0580f; break;
        case  2: norm_outflow = 0.8175f * norm_inflow + 0.0982f; break;
        case  3: norm_outflow = 0.5670f * norm_inflow + 0.1195f; break;
        case  4: norm_outflow = 1.0676f * norm_inflow + 0.0472f; break;
        case  5: norm_outflow = 1.3459f * norm_inflow + 0.0570f; break;
        case  6: norm_outflow = 1.6455f * norm_inflow + 0.0245f; break;
        case  7: norm_outflow = 1.8370f * norm_inflow + 0.0182f; break;
        case  8: norm_outflow = 2.1962f * norm_inflow + 0.0086f; break;
        case  9: norm_outflow = 1.0020f * norm_inflow + 0.0164f; break;
        case 10: norm_outflow = 2.0818f * norm_inflow + 0.0178f; break;
        case 11: norm_outflow = 1.2269f * norm_inflow + 0.0508f; break;
        case 12: norm_outflow = 1.4453f * norm_inflow + 0.0439f; break;
    }
    return norm_outflow * max_outflow_m3d;
}

static float rule_2918(float inflow_m3d, float storage_m3, int month) {
    const float max_inflow_m3d   = 269350979.4f;
    const float max_outflow_m3d  = 44153349.3f;
    const float max_storage_m3   = 392307080.5f;
    const float norm_inflow  = inflow_m3d  / max_inflow_m3d;
    const float norm_storage = storage_m3  / max_storage_m3;
    float norm_outflow;

    switch (month) {
        case  1: norm_outflow = 3.8934f * norm_inflow + 0.0503f; break;
        case  2: norm_outflow = 4.7175f * norm_inflow + 0.0363f; break;
        case  3: norm_outflow = 4.0321f * norm_inflow + 0.0500f; break;
        case  4: norm_outflow = 2.4336f * norm_inflow + -0.0017f; break;
        case  5: norm_outflow = 4.8680f * norm_inflow + 0.0156f; break;
        case  6: norm_outflow = 3.1815f * norm_inflow + 0.0332f; break;
        case  7: norm_outflow = 4.0900f * norm_inflow + 0.0209f; break;
        case  8: norm_outflow = 4.6361f * norm_inflow + 0.0182f; break;
        case  9: norm_outflow = 3.7100f * norm_inflow + 0.0521f; break;
        case 10: norm_outflow = 3.1668f * norm_inflow + 0.0468f; break;
        case 11: norm_outflow = 1.1813f * norm_inflow + 0.1269f; break;
        case 12: norm_outflow = 2.3890f * norm_inflow + 0.0929f; break;
    }
    return norm_outflow * max_outflow_m3d;
}

static float rule_2926(float inflow_m3d, float storage_m3, int month) {
    const float max_inflow_m3d   = 13703750.5f;
    const float max_outflow_m3d  = 5631061.4f;
    const float max_storage_m3   = 51732151.2f;
    const float norm_inflow  = inflow_m3d  / max_inflow_m3d;
    const float norm_storage = storage_m3  / max_storage_m3;
    float norm_outflow;

    switch (month) {
        case  1: norm_outflow = 1.2250f * norm_inflow + 0.0526f; break;
        case  2: norm_outflow = 1.0330f * norm_inflow + 0.0831f; break;
        case  3: norm_outflow = 0.7687f * norm_inflow + 0.1039f; break;
        case  4: norm_outflow = 1.1315f * norm_inflow + 0.0391f; break;
        case  5: norm_outflow = 1.2581f * norm_inflow + 0.0458f; break;
        case  6: norm_outflow = 1.5272f * norm_inflow + 0.0179f; break;
        case  7: norm_outflow = 1.4076f * norm_inflow + 0.0082f; break;
        case  8: norm_outflow = 1.4463f * norm_inflow + 0.0069f; break;
        case  9: norm_outflow = 1.0205f * norm_inflow + 0.0131f; break;
        case 10: norm_outflow = 1.5109f * norm_inflow + 0.0100f; break;
        case 11: norm_outflow = 0.8433f * norm_inflow + 0.0593f; break;
        case 12: norm_outflow = 1.1181f * norm_inflow + 0.0407f; break;
    }
    return norm_outflow * max_outflow_m3d;
}

static float rule_2927(float inflow_m3d, float storage_m3, int month) {
    const float max_inflow_m3d   = 32064026.6f;
    const float max_outflow_m3d  = 7492185.1f;
    const float max_storage_m3   = 100804919.5f;
    const float norm_inflow  = inflow_m3d  / max_inflow_m3d;
    const float norm_storage = storage_m3  / max_storage_m3;
    float norm_outflow;

    switch (month) {
        case  1: norm_outflow = 1.8384f * norm_inflow + 0.0603f; break;
        case  2: norm_outflow = 1.9213f * norm_inflow + 0.0821f; break;
        case  3: norm_outflow = 1.4381f * norm_inflow + 0.1163f; break;
        case  4: norm_outflow = 1.5839f * norm_inflow + 0.0477f; break;
        case  5: norm_outflow = 1.9287f * norm_inflow + 0.0596f; break;
        case  6: norm_outflow = 2.1173f * norm_inflow + 0.0270f; break;
        case  7: norm_outflow = 2.3528f * norm_inflow + 0.0195f; break;
        case  8: norm_outflow = 2.6555f * norm_inflow + 0.0129f; break;
        case  9: norm_outflow = 0.8059f * norm_inflow + 0.0210f; break;
        case 10: norm_outflow = 1.9265f * norm_inflow + 0.0226f; break;
        case 11: norm_outflow = 1.6015f * norm_inflow + 0.0766f; break;
        case 12: norm_outflow = 2.2408f * norm_inflow + 0.0503f; break;
    }
    return norm_outflow * max_outflow_m3d;
}

static float rule_827(float inflow_m3d, float storage_m3, int month) {
    const float max_inflow_m3d   = 76090943.9f;
    const float max_outflow_m3d  = 12965653.1f;
    const float max_storage_m3   = 688618580.0f;
    const float norm_inflow  = inflow_m3d  / max_inflow_m3d;
    const float norm_storage = storage_m3  / max_storage_m3;
    float norm_outflow;

    switch (month) {
        case  1: norm_outflow = 0.6387f * norm_inflow + 0.2466f; break;
        case  2: norm_outflow = 0.0000f * norm_inflow + 0.3300f; break;
        case  3: norm_outflow = 0.0000f * norm_inflow + 0.3879f; break;
        case  4: norm_outflow = 0.3689f * norm_inflow + 0.2732f; break;
        case  5: norm_outflow = 0.3949f * norm_inflow + 0.2660f; break;
        case  6: norm_outflow = 1.3252f * norm_inflow + 0.1535f; break;
        case  7: norm_outflow = 1.2661f * norm_inflow + 0.0774f; break;
        case  8: norm_outflow = 3.1606f * norm_inflow + 0.0360f; break;
        case  9: norm_outflow = 0.4188f * norm_inflow + 0.0621f; break;
        case 10: norm_outflow = 2.2731f * norm_inflow + 0.0981f; break;
        case 11: norm_outflow = 0.9304f * norm_inflow + 0.1465f; break;
        case 12: norm_outflow = 0.3704f * norm_inflow + 0.2360f; break;
    }
    return norm_outflow * max_outflow_m3d;
}

static float rule_829(float inflow_m3d, float storage_m3, int month) {
    const float max_inflow_m3d   = 137280959.4f;
    const float max_outflow_m3d  = 34741443.8f;
    const float max_storage_m3   = 505391293.4f;
    const float norm_inflow  = inflow_m3d  / max_inflow_m3d;
    const float norm_storage = storage_m3  / max_storage_m3;
    float norm_outflow;

    switch (month) {
        case  1: norm_outflow = 0.2076f * norm_inflow + 0.0176f; break;
        case  2: norm_outflow = 0.2291f * norm_inflow + 0.0293f; break;
        case  3: norm_outflow = 0.1625f * norm_inflow + 0.0353f; break;
        case  4: norm_outflow = 0.2640f * norm_inflow + 0.0408f; break;
        case  5: norm_outflow = 0.8357f * norm_inflow + 0.0566f; break;
        case  6: norm_outflow = 0.1222f * norm_inflow + 0.0379f; break;
        case  7: norm_outflow = 0.0317f * norm_inflow + 0.0267f; break;
        case  8: norm_outflow = 0.0611f * norm_inflow + 0.0151f; break;
        case  9: norm_outflow = 0.0750f * norm_inflow + 0.0089f; break;
        case 10: norm_outflow = 0.0230f * norm_inflow + 0.0055f; break;
        case 11: norm_outflow = 0.4896f * norm_inflow + 0.0110f; break;
        case 12: norm_outflow = 0.2293f * norm_inflow + 0.0122f; break;
    }
    return norm_outflow * max_outflow_m3d;
}

static float rule_831(float inflow_m3d, float storage_m3, int month) {
    const float max_inflow_m3d   = 98133866.1f;
    const float max_outflow_m3d  = 10929789.7f;
    const float max_storage_m3   = 361040829.5f;
    const float norm_inflow  = inflow_m3d  / max_inflow_m3d;
    const float norm_storage = storage_m3  / max_storage_m3;
    float norm_outflow;

    switch (month) {
        case  1: norm_outflow = 0.0000f * norm_inflow + 0.1661f; break;
        case  2: norm_outflow = 0.0000f * norm_inflow + 0.1815f; break;
        case  3: norm_outflow = 0.0000f * norm_inflow + 0.2040f; break;
        case  4: norm_outflow = 0.0000f * norm_inflow + 0.1489f; break;
        case  5: norm_outflow = 0.0701f * norm_inflow + 0.1509f; break;
        case  6: norm_outflow = 1.1533f * norm_inflow + 0.0914f; break;
        case  7: norm_outflow = 0.7167f * norm_inflow + 0.0519f; break;
        case  8: norm_outflow = 2.1773f * norm_inflow + 0.0235f; break;
        case  9: norm_outflow = 0.2444f * norm_inflow + 0.0294f; break;
        case 10: norm_outflow = 0.8461f * norm_inflow + 0.0370f; break;
        case 11: norm_outflow = 0.5147f * norm_inflow + 0.0799f; break;
        case 12: norm_outflow = 0.0000f * norm_inflow + 0.1505f; break;
    }
    return norm_outflow * max_outflow_m3d;
}

static float rule_2948(float inflow_m3d, float storage_m3, int month) {
    const float max_inflow_m3d   = 13926789.5f;
    const float max_outflow_m3d  = 4102176.2f;
    const float max_storage_m3   = 78461662.8f;
    const float norm_inflow  = inflow_m3d  / max_inflow_m3d;
    const float norm_storage = storage_m3  / max_storage_m3;
    float norm_outflow;

    switch (month) {
        case  1: norm_outflow = 1.5835f * norm_inflow + 0.0743f; break;
        case  2: norm_outflow = 1.2422f * norm_inflow + 0.1078f; break;
        case  3: norm_outflow = 1.1366f * norm_inflow + 0.1244f; break;
        case  4: norm_outflow = 1.5146f * norm_inflow + 0.0859f; break;
        case  5: norm_outflow = 1.2421f * norm_inflow + 0.0731f; break;
        case  6: norm_outflow = 1.6610f * norm_inflow + 0.0352f; break;
        case  7: norm_outflow = 1.9822f * norm_inflow + 0.0185f; break;
        case  8: norm_outflow = 2.1302f * norm_inflow + 0.0124f; break;
        case  9: norm_outflow = 0.9766f * norm_inflow + 0.0210f; break;
        case 10: norm_outflow = 1.6219f * norm_inflow + 0.0175f; break;
        case 11: norm_outflow = 1.8972f * norm_inflow + 0.0234f; break;
        case 12: norm_outflow = 1.4309f * norm_inflow + 0.0493f; break;
    }
    return norm_outflow * max_outflow_m3d;
}

static float rule_2957(float inflow_m3d, float storage_m3, int month) {
    const float max_inflow_m3d   = 25611472.3f;
    const float max_outflow_m3d  = 7480916.0f;
    const float max_storage_m3   = 57169331.0f;
    const float norm_inflow  = inflow_m3d  / max_inflow_m3d;
    const float norm_storage = storage_m3  / max_storage_m3;
    float norm_outflow;

    switch (month) {
        case  1: norm_outflow = 2.1855f * norm_inflow + 0.0402f; break;
        case  2: norm_outflow = 1.7026f * norm_inflow + 0.0713f; break;
        case  3: norm_outflow = 1.7086f * norm_inflow + 0.0763f; break;
        case  4: norm_outflow = 1.2952f * norm_inflow + 0.0707f; break;
        case  5: norm_outflow = 1.1851f * norm_inflow + 0.0678f; break;
        case  6: norm_outflow = 1.3641f * norm_inflow + 0.0399f; break;
        case  7: norm_outflow = 2.5536f * norm_inflow + 0.0092f; break;
        case  8: norm_outflow = 2.1804f * norm_inflow + 0.0102f; break;
        case  9: norm_outflow = 1.6695f * norm_inflow + 0.0129f; break;
        case 10: norm_outflow = 1.7718f * norm_inflow + 0.0136f; break;
        case 11: norm_outflow = 2.2618f * norm_inflow + 0.0377f; break;
        case 12: norm_outflow = 1.9552f * norm_inflow + 0.0329f; break;
    }
    return norm_outflow * max_outflow_m3d;
}

static float rule_2969(float inflow_m3d, float storage_m3, int month) {
    const float max_inflow_m3d   = 59410946.3f;
    const float max_outflow_m3d  = 16197746.4f;
    const float max_storage_m3   = 135066667.7f;
    const float norm_inflow  = inflow_m3d  / max_inflow_m3d;
    const float norm_storage = storage_m3  / max_storage_m3;
    float norm_outflow;

    switch (month) {
        case  1: norm_outflow = 2.2630f * norm_inflow + 0.0693f; break;
        case  2: norm_outflow = 1.8914f * norm_inflow + 0.1082f; break;
        case  3: norm_outflow = 2.0923f * norm_inflow + 0.1004f; break;
        case  4: norm_outflow = 2.0007f * norm_inflow + 0.0842f; break;
        case  5: norm_outflow = 1.8298f * norm_inflow + 0.0968f; break;
        case  6: norm_outflow = 2.4705f * norm_inflow + 0.0334f; break;
        case  7: norm_outflow = 1.6527f * norm_inflow + 0.0329f; break;
        case  8: norm_outflow = 3.3703f * norm_inflow + 0.0051f; break;
        case  9: norm_outflow = 3.3041f * norm_inflow + 0.0049f; break;
        case 10: norm_outflow = 1.7612f * norm_inflow + 0.0320f; break;
        case 11: norm_outflow = 1.4755f * norm_inflow + 0.0549f; break;
        case 12: norm_outflow = 2.6106f * norm_inflow + 0.0343f; break;
    }
    return norm_outflow * max_outflow_m3d;
}

static float rule_2978(float inflow_m3d, float storage_m3, int month) {
    const float max_inflow_m3d   = 29800388.3f;
    const float max_outflow_m3d  = 19111803.8f;
    const float max_storage_m3   = 84176375.6f;
    const float norm_inflow  = inflow_m3d  / max_inflow_m3d;
    const float norm_storage = storage_m3  / max_storage_m3;
    float norm_outflow;

    switch (month) {
        case  1: norm_outflow = 0.6086f * norm_inflow + 0.0605f; break;
        case  2: norm_outflow = 1.5331f * norm_inflow + 0.0166f; break;
        case  3: norm_outflow = 1.2018f * norm_inflow + 0.0319f; break;
        case  4: norm_outflow = 1.0118f * norm_inflow + 0.0232f; break;
        case  5: norm_outflow = 0.7374f * norm_inflow + 0.0457f; break;
        case  6: norm_outflow = 0.4499f * norm_inflow + 0.0323f; break;
        case  7: norm_outflow = 0.2098f * norm_inflow + 0.0227f; break;
        case  8: norm_outflow = 0.2743f * norm_inflow + 0.0204f; break;
        case  9: norm_outflow = 0.1788f * norm_inflow + 0.0215f; break;
        case 10: norm_outflow = 1.5096f * norm_inflow + 0.0017f; break;
        case 11: norm_outflow = 0.8806f * norm_inflow + 0.0189f; break;
        case 12: norm_outflow = 1.5214f * norm_inflow + 0.0081f; break;
    }
    return norm_outflow * max_outflow_m3d;
}

static float rule_2989(float inflow_m3d, float storage_m3, int month) {
    const float max_inflow_m3d   = 65140925.6f;
    const float max_outflow_m3d  = 9657915.1f;
    const float max_storage_m3   = 171895305.8f;
    const float norm_inflow  = inflow_m3d  / max_inflow_m3d;
    const float norm_storage = storage_m3  / max_storage_m3;
    float norm_outflow;

    switch (month) {
        case  1: norm_outflow = 1.7833f * norm_inflow + 0.1629f; break;
        case  2: norm_outflow = 0.7211f * norm_inflow + 0.2277f; break;
        case  3: norm_outflow = 0.7760f * norm_inflow + 0.2663f; break;
        case  4: norm_outflow = 1.1621f * norm_inflow + 0.1439f; break;
        case  5: norm_outflow = 1.2254f * norm_inflow + 0.1463f; break;
        case  6: norm_outflow = 1.9424f * norm_inflow + 0.0689f; break;
        case  7: norm_outflow = 2.0844f * norm_inflow + 0.0379f; break;
        case  8: norm_outflow = 4.2312f * norm_inflow + 0.0164f; break;
        case  9: norm_outflow = 1.2712f * norm_inflow + 0.0355f; break;
        case 10: norm_outflow = 0.8948f * norm_inflow + 0.0622f; break;
        case 11: norm_outflow = 2.1724f * norm_inflow + 0.0867f; break;
        case 12: norm_outflow = 1.1041f * norm_inflow + 0.1498f; break;
    }
    return norm_outflow * max_outflow_m3d;
}

static float rule_843(float inflow_m3d, float storage_m3, int month) {
    const float max_inflow_m3d   = 72976087.7f;
    const float max_outflow_m3d  = 25142266.9f;
    const float max_storage_m3   = 744909673.3f;
    const float norm_inflow  = inflow_m3d  / max_inflow_m3d;
    const float norm_storage = storage_m3  / max_storage_m3;
    float norm_outflow;

    switch (month) {
        case  1: norm_outflow = 0.2073f * norm_inflow + 0.1356f; break;
        case  2: norm_outflow = 0.0000f * norm_inflow + 0.1512f; break;
        case  3: norm_outflow = 0.0000f * norm_inflow + 0.1244f; break;
        case  4: norm_outflow = 0.2153f * norm_inflow + 0.0645f; break;
        case  5: norm_outflow = 0.0958f * norm_inflow + 0.1179f; break;
        case  6: norm_outflow = 1.3771f * norm_inflow + 0.0570f; break;
        case  7: norm_outflow = 0.7889f * norm_inflow + 0.0345f; break;
        case  8: norm_outflow = 1.1995f * norm_inflow + 0.0152f; break;
        case  9: norm_outflow = 0.5547f * norm_inflow + 0.0303f; break;
        case 10: norm_outflow = 0.8931f * norm_inflow + 0.0797f; break;
        case 11: norm_outflow = 0.2775f * norm_inflow + 0.1304f; break;
        case 12: norm_outflow = 0.1283f * norm_inflow + 0.1043f; break;
    }
    return norm_outflow * max_outflow_m3d;
}

static float rule_845(float inflow_m3d, float storage_m3, int month) {
    const float max_inflow_m3d   = 179142844.2f;
    const float max_outflow_m3d  = 19278563.6f;
    const float max_storage_m3   = 700255230.4f;
    const float norm_inflow  = inflow_m3d  / max_inflow_m3d;
    const float norm_storage = storage_m3  / max_storage_m3;
    float norm_outflow;

    switch (month) {
        case  1: norm_outflow = 0.1468f * norm_inflow + 0.2272f; break;
        case  2: norm_outflow = 0.0000f * norm_inflow + 0.2448f; break;
        case  3: norm_outflow = 0.0000f * norm_inflow + 0.2220f; break;
        case  4: norm_outflow = 0.4247f * norm_inflow + 0.1586f; break;
        case  5: norm_outflow = 0.0676f * norm_inflow + 0.1686f; break;
        case  6: norm_outflow = 1.9106f * norm_inflow + 0.1030f; break;
        case  7: norm_outflow = 1.3410f * norm_inflow + 0.0464f; break;
        case  8: norm_outflow = 3.2247f * norm_inflow + 0.0186f; break;
        case  9: norm_outflow = 1.1566f * norm_inflow + 0.0315f; break;
        case 10: norm_outflow = 2.4842f * norm_inflow + 0.0621f; break;
        case 11: norm_outflow = 0.5577f * norm_inflow + 0.1531f; break;
        case 12: norm_outflow = 0.0000f * norm_inflow + 0.2259f; break;
    }
    return norm_outflow * max_outflow_m3d;
}

static float rule_2999(float inflow_m3d, float storage_m3, int month) {
    const float max_inflow_m3d   = 23601419.7f;
    const float max_outflow_m3d  = 9772654.0f;
    const float max_storage_m3   = 114056195.2f;
    const float norm_inflow  = inflow_m3d  / max_inflow_m3d;
    const float norm_storage = storage_m3  / max_storage_m3;
    float norm_outflow;

    switch (month) {
        case  1: norm_outflow = 1.1162f * norm_inflow + 0.0454f; break;
        case  2: norm_outflow = 1.0531f * norm_inflow + 0.0650f; break;
        case  3: norm_outflow = 1.0500f * norm_inflow + 0.0681f; break;
        case  4: norm_outflow = 1.0402f * norm_inflow + 0.0226f; break;
        case  5: norm_outflow = 1.4834f * norm_inflow + 0.0315f; break;
        case  6: norm_outflow = 1.7024f * norm_inflow + 0.0178f; break;
        case  7: norm_outflow = 1.6240f * norm_inflow + 0.0122f; break;
        case  8: norm_outflow = 1.9568f * norm_inflow + 0.0080f; break;
        case  9: norm_outflow = 1.4984f * norm_inflow + 0.0124f; break;
        case 10: norm_outflow = 1.0702f * norm_inflow + 0.0419f; break;
        case 11: norm_outflow = 1.6851f * norm_inflow + 0.0507f; break;
        case 12: norm_outflow = 1.1036f * norm_inflow + 0.0449f; break;
    }
    return norm_outflow * max_outflow_m3d;
}

static float rule_3000(float inflow_m3d, float storage_m3, int month) {
    const float max_inflow_m3d   = 10620086.3f;
    const float max_outflow_m3d  = 2823407.3f;
    const float max_storage_m3   = 48056380.8f;
    const float norm_inflow  = inflow_m3d  / max_inflow_m3d;
    const float norm_storage = storage_m3  / max_storage_m3;
    float norm_outflow;

    switch (month) {
        case  1: norm_outflow = 0.4782f * norm_inflow + 0.0755f; break;
        case  2: norm_outflow = 0.2042f * norm_inflow + 0.1112f; break;
        case  3: norm_outflow = 0.3864f * norm_inflow + 0.0855f; break;
        case  4: norm_outflow = 0.4435f * norm_inflow + 0.0529f; break;
        case  5: norm_outflow = 0.7236f * norm_inflow + 0.0554f; break;
        case  6: norm_outflow = 0.8601f * norm_inflow + 0.0350f; break;
        case  7: norm_outflow = 0.7303f * norm_inflow + 0.0243f; break;
        case  8: norm_outflow = 0.9200f * norm_inflow + 0.0166f; break;
        case  9: norm_outflow = 0.7006f * norm_inflow + 0.0264f; break;
        case 10: norm_outflow = 0.3400f * norm_inflow + 0.0509f; break;
        case 11: norm_outflow = 0.5933f * norm_inflow + 0.0565f; break;
        case 12: norm_outflow = 0.5027f * norm_inflow + 0.0630f; break;
    }
    return norm_outflow * max_outflow_m3d;
}

static float rule_144(float inflow_m3d, float storage_m3, int month) {
    const float max_inflow_m3d   = 744623631.1f;
    const float max_outflow_m3d  = 645438637.2f;
    const float max_storage_m3   = 2288033858.2f;
    const float norm_inflow  = inflow_m3d  / max_inflow_m3d;
    const float norm_storage = storage_m3  / max_storage_m3;
    float norm_outflow;

    switch (month) {
        case  1: norm_outflow = 1.0136f * norm_inflow + 0.0199f; break;
        case  2: norm_outflow = 1.0394f * norm_inflow + 0.0180f; break;
        case  3: norm_outflow = 1.0843f * norm_inflow + 0.0093f; break;
        case  4: norm_outflow = 0.9962f * norm_inflow + 0.0053f; break;
        case  5: norm_outflow = 1.0701f * norm_inflow + 0.0118f; break;
        case  6: norm_outflow = 1.0501f * norm_inflow + 0.0075f; break;
        case  7: norm_outflow = 1.0705f * norm_inflow + 0.0104f; break;
        case  8: norm_outflow = 1.0076f * norm_inflow + 0.0138f; break;
        case  9: norm_outflow = 0.9546f * norm_inflow + 0.0161f; break;
        case 10: norm_outflow = 0.9875f * norm_inflow + 0.0118f; break;
        case 11: norm_outflow = 0.9677f * norm_inflow + 0.0147f; break;
        case 12: norm_outflow = 1.0288f * norm_inflow + 0.0161f; break;
    }
    return norm_outflow * max_outflow_m3d;
}

static float rule_145(float inflow_m3d, float storage_m3, int month) {
    const float max_inflow_m3d   = 1217305264.3f;
    const float max_outflow_m3d  = 1022575987.8f;
    const float max_storage_m3   = 3668196832.8f;
    const float norm_inflow  = inflow_m3d  / max_inflow_m3d;
    const float norm_storage = storage_m3  / max_storage_m3;
    float norm_outflow;

    switch (month) {
        case  1: norm_outflow = 1.1396f * norm_inflow + 0.0105f; break;
        case  2: norm_outflow = 1.1152f * norm_inflow + 0.0147f; break;
        case  3: norm_outflow = 1.1339f * norm_inflow + 0.0095f; break;
        case  4: norm_outflow = 1.1259f * norm_inflow + 0.0005f; break;
        case  5: norm_outflow = 1.1077f * norm_inflow + 0.0100f; break;
        case  6: norm_outflow = 1.1436f * norm_inflow + 0.0048f; break;
        case  7: norm_outflow = 1.1473f * norm_inflow + 0.0063f; break;
        case  8: norm_outflow = 1.0259f * norm_inflow + 0.0147f; break;
        case  9: norm_outflow = 0.9868f * norm_inflow + 0.0159f; break;
        case 10: norm_outflow = 1.1009f * norm_inflow + 0.0072f; break;
        case 11: norm_outflow = 1.0975f * norm_inflow + 0.0081f; break;
        case 12: norm_outflow = 1.1115f * norm_inflow + 0.0127f; break;
    }
    return norm_outflow * max_outflow_m3d;
}

static float rule_851(float inflow_m3d, float storage_m3, int month) {
    const float max_inflow_m3d   = 57920666.0f;
    const float max_outflow_m3d  = 33285597.4f;
    const float max_storage_m3   = 564300818.1f;
    const float norm_inflow  = inflow_m3d  / max_inflow_m3d;
    const float norm_storage = storage_m3  / max_storage_m3;
    float norm_outflow;

    switch (month) {
        case  1: norm_outflow = 0.5077f * norm_inflow + 0.0288f; break;
        case  2: norm_outflow = 0.7487f * norm_inflow + 0.0251f; break;
        case  3: norm_outflow = 0.9292f * norm_inflow + 0.0230f; break;
        case  4: norm_outflow = 0.8143f * norm_inflow + 0.0209f; break;
        case  5: norm_outflow = 0.9508f * norm_inflow + 0.0189f; break;
        case  6: norm_outflow = 0.8539f * norm_inflow + 0.0143f; break;
        case  7: norm_outflow = 0.7064f * norm_inflow + 0.0156f; break;
        case  8: norm_outflow = 0.1416f * norm_inflow + 0.0154f; break;
        case  9: norm_outflow = 0.1742f * norm_inflow + 0.0140f; break;
        case 10: norm_outflow = 0.4937f * norm_inflow + 0.0138f; break;
        case 11: norm_outflow = 0.2313f * norm_inflow + 0.0142f; break;
        case 12: norm_outflow = 0.7066f * norm_inflow + 0.0167f; break;
    }
    return norm_outflow * max_outflow_m3d;
}

static float rule_853(float inflow_m3d, float storage_m3, int month) {
    const float max_inflow_m3d   = 239668176.9f;
    const float max_outflow_m3d  = 12792496.3f;
    const float max_storage_m3   = 841633007.5f;
    const float norm_inflow  = inflow_m3d  / max_inflow_m3d;
    const float norm_storage = storage_m3  / max_storage_m3;
    float norm_outflow;

    switch (month) {
        case  1: norm_outflow = 0.0000f * norm_inflow + 0.3988f; break;
        case  2: norm_outflow = 0.0000f * norm_inflow + 0.4383f; break;
        case  3: norm_outflow = 0.0000f * norm_inflow + 0.3454f; break;
        case  4: norm_outflow = 0.0703f * norm_inflow + 0.1945f; break;
        case  5: norm_outflow = 0.0000f * norm_inflow + 0.2835f; break;
        case  6: norm_outflow = 2.2261f * norm_inflow + 0.2257f; break;
        case  7: norm_outflow = 1.7145f * norm_inflow + 0.1768f; break;
        case  8: norm_outflow = 1.5484f * norm_inflow + 0.0668f; break;
        case  9: norm_outflow = 1.7089f * norm_inflow + 0.1031f; break;
        case 10: norm_outflow = 4.4909f * norm_inflow + 0.2500f; break;
        case 11: norm_outflow = 0.1534f * norm_inflow + 0.4330f; break;
        case 12: norm_outflow = 0.0000f * norm_inflow + 0.3850f; break;
    }
    return norm_outflow * max_outflow_m3d;
}

static float rule_147(float inflow_m3d, float storage_m3, int month) {
    const float max_inflow_m3d   = 829099010.6f;
    const float max_outflow_m3d  = 145375558.3f;
    const float max_storage_m3   = 7239797379.8f;
    const float norm_inflow  = inflow_m3d  / max_inflow_m3d;
    const float norm_storage = storage_m3  / max_storage_m3;
    float norm_outflow;

    switch (month) {
        case  1: norm_outflow = 0.4038f * norm_inflow + 0.1836f; break;
        case  2: norm_outflow = 0.5954f * norm_inflow + 0.1719f; break;
        case  3: norm_outflow = 0.7221f * norm_inflow + 0.2010f; break;
        case  4: norm_outflow = 0.9677f * norm_inflow + 0.1595f; break;
        case  5: norm_outflow = 0.7716f * norm_inflow + 0.1449f; break;
        case  6: norm_outflow = 1.5337f * norm_inflow + 0.1195f; break;
        case  7: norm_outflow = 0.7706f * norm_inflow + 0.1156f; break;
        case  8: norm_outflow = 0.3882f * norm_inflow + 0.1184f; break;
        case  9: norm_outflow = 0.1876f * norm_inflow + 0.0923f; break;
        case 10: norm_outflow = 0.8505f * norm_inflow + 0.0746f; break;
        case 11: norm_outflow = 0.8272f * norm_inflow + 0.0774f; break;
        case 12: norm_outflow = 0.4417f * norm_inflow + 0.1490f; break;
    }
    return norm_outflow * max_outflow_m3d;
}

static float rule_862(float inflow_m3d, float storage_m3, int month) {
    const float max_inflow_m3d   = 161199172.2f;
    const float max_outflow_m3d  = 24999063.0f;
    const float max_storage_m3   = 1998869018.4f;
    const float norm_inflow  = inflow_m3d  / max_inflow_m3d;
    const float norm_storage = storage_m3  / max_storage_m3;
    float norm_outflow;

    switch (month) {
        case  1: norm_outflow = 0.1606f * norm_inflow + 0.1591f; break;
        case  2: norm_outflow = 0.1654f * norm_inflow + 0.1525f; break;
        case  3: norm_outflow = 0.1962f * norm_inflow + 0.1714f; break;
        case  4: norm_outflow = 0.5978f * norm_inflow + 0.1386f; break;
        case  5: norm_outflow = 0.4250f * norm_inflow + 0.1406f; break;
        case  6: norm_outflow = 1.2234f * norm_inflow + 0.1163f; break;
        case  7: norm_outflow = 0.3246f * norm_inflow + 0.1582f; break;
        case  8: norm_outflow = 0.0117f * norm_inflow + 0.1604f; break;
        case  9: norm_outflow = 0.2886f * norm_inflow + 0.1225f; break;
        case 10: norm_outflow = 0.3008f * norm_inflow + 0.0884f; break;
        case 11: norm_outflow = 0.2611f * norm_inflow + 0.0777f; break;
        case 12: norm_outflow = 0.3150f * norm_inflow + 0.1254f; break;
    }
    return norm_outflow * max_outflow_m3d;
}

static float rule_863(float inflow_m3d, float storage_m3, int month) {
    const float max_inflow_m3d   = 28790813.9f;
    const float max_outflow_m3d  = 11002292.7f;
    const float max_storage_m3   = 447970332.5f;
    const float norm_inflow  = inflow_m3d  / max_inflow_m3d;
    const float norm_storage = storage_m3  / max_storage_m3;
    float norm_outflow;

    switch (month) {
        case  1: norm_outflow = 1.3536f * norm_inflow + 0.0850f; break;
        case  2: norm_outflow = 1.4729f * norm_inflow + 0.0448f; break;
        case  3: norm_outflow = 1.5782f * norm_inflow + 0.0142f; break;
        case  4: norm_outflow = 1.9348f * norm_inflow + -0.0310f; break;
        case  5: norm_outflow = 2.1219f * norm_inflow + 0.0098f; break;
        case  6: norm_outflow = 2.5041f * norm_inflow + 0.0284f; break;
        case  7: norm_outflow = 2.2032f * norm_inflow + 0.0722f; break;
        case  8: norm_outflow = 2.6548f * norm_inflow + 0.0792f; break;
        case  9: norm_outflow = 3.1827f * norm_inflow + 0.0484f; break;
        case 10: norm_outflow = 3.6482f * norm_inflow + 0.0145f; break;
        case 11: norm_outflow = 2.0145f * norm_inflow + 0.0603f; break;
        case 12: norm_outflow = 2.2256f * norm_inflow + 0.0315f; break;
    }
    return norm_outflow * max_outflow_m3d;
}

static float rule_866(float inflow_m3d, float storage_m3, int month) {
    const float max_inflow_m3d   = 44434582.1f;
    const float max_outflow_m3d  = 39673590.9f;
    const float max_storage_m3   = 119285780.3f;
    const float norm_inflow  = inflow_m3d  / max_inflow_m3d;
    const float norm_storage = storage_m3  / max_storage_m3;
    float norm_outflow;

    switch (month) {
        case  1: norm_outflow = 1.1232f * norm_inflow + -0.0025f; break;
        case  2: norm_outflow = 1.1511f * norm_inflow + -0.0124f; break;
        case  3: norm_outflow = 1.1140f * norm_inflow + -0.0137f; break;
        case  4: norm_outflow = 1.1350f * norm_inflow + -0.0131f; break;
        case  5: norm_outflow = 1.1510f * norm_inflow + -0.0082f; break;
        case  6: norm_outflow = 1.1585f * norm_inflow + -0.0057f; break;
        case  7: norm_outflow = 1.1474f * norm_inflow + -0.0038f; break;
        case  8: norm_outflow = 1.1480f * norm_inflow + -0.0033f; break;
        case  9: norm_outflow = 1.1879f * norm_inflow + 0.0001f; break;
        case 10: norm_outflow = 1.1919f * norm_inflow + 0.0021f; break;
        case 11: norm_outflow = 1.1537f * norm_inflow + 0.0097f; break;
        case 12: norm_outflow = 1.1559f * norm_inflow + 0.0040f; break;
    }
    return norm_outflow * max_outflow_m3d;
}

static float rule_870(float inflow_m3d, float storage_m3, int month) {
    const float max_inflow_m3d   = 31446800.9f;
    const float max_outflow_m3d  = 7841240.2f;
    const float max_storage_m3   = 386778623.2f;
    const float norm_inflow  = inflow_m3d  / max_inflow_m3d;
    const float norm_storage = storage_m3  / max_storage_m3;
    float norm_outflow;

    switch (month) {
        case  1: norm_outflow = 1.7706f * norm_inflow + 0.1115f; break;
        case  2: norm_outflow = 2.5686f * norm_inflow + 0.0206f; break;
        case  3: norm_outflow = 1.8534f * norm_inflow + 0.0372f; break;
        case  4: norm_outflow = 3.1947f * norm_inflow + -0.0118f; break;
        case  5: norm_outflow = 2.9032f * norm_inflow + 0.0423f; break;
        case  6: norm_outflow = 4.2592f * norm_inflow + 0.0223f; break;
        case  7: norm_outflow = 3.5291f * norm_inflow + 0.0910f; break;
        case  8: norm_outflow = 3.7987f * norm_inflow + 0.0871f; break;
        case  9: norm_outflow = 1.8165f * norm_inflow + 0.1247f; break;
        case 10: norm_outflow = 4.2405f * norm_inflow + 0.0373f; break;
        case 11: norm_outflow = 2.6721f * norm_inflow + 0.0659f; break;
        case 12: norm_outflow = 4.1034f * norm_inflow + -0.0085f; break;
    }
    return norm_outflow * max_outflow_m3d;
}

static float rule_873(float inflow_m3d, float storage_m3, int month) {
    const float max_inflow_m3d   = 463725814.8f;
    const float max_outflow_m3d  = 429395960.3f;
    const float max_storage_m3   = 699718666.6f;
    const float norm_inflow  = inflow_m3d  / max_inflow_m3d;
    const float norm_storage = storage_m3  / max_storage_m3;
    float norm_outflow;

    switch (month) {
        case  1: norm_outflow = 1.0319f * norm_inflow + 0.0063f; break;
        case  2: norm_outflow = 1.0266f * norm_inflow + 0.0071f; break;
        case  3: norm_outflow = 1.0566f * norm_inflow + 0.0033f; break;
        case  4: norm_outflow = 1.0367f * norm_inflow + 0.0060f; break;
        case  5: norm_outflow = 1.0217f * norm_inflow + 0.0066f; break;
        case  6: norm_outflow = 1.0413f * norm_inflow + 0.0024f; break;
        case  7: norm_outflow = 1.0124f * norm_inflow + 0.0038f; break;
        case  8: norm_outflow = 0.9655f * norm_inflow + 0.0072f; break;
        case  9: norm_outflow = 0.9528f * norm_inflow + 0.0065f; break;
        case 10: norm_outflow = 0.9803f * norm_inflow + 0.0045f; break;
        case 11: norm_outflow = 1.0112f * norm_inflow + 0.0036f; break;
        case 12: norm_outflow = 1.0538f * norm_inflow + 0.0026f; break;
    }
    return norm_outflow * max_outflow_m3d;
}

static float rule_877(float inflow_m3d, float storage_m3, int month) {
    const float max_inflow_m3d   = 113839743.2f;
    const float max_outflow_m3d  = 65086154.6f;
    const float max_storage_m3   = 1497120931.5f;
    const float norm_inflow  = inflow_m3d  / max_inflow_m3d;
    const float norm_storage = storage_m3  / max_storage_m3;
    float norm_outflow;

    switch (month) {
        case  1: norm_outflow = 0.9035f * norm_inflow + 0.0861f; break;
        case  2: norm_outflow = 0.8463f * norm_inflow + 0.0774f; break;
        case  3: norm_outflow = 0.9793f * norm_inflow + 0.0257f; break;
        case  4: norm_outflow = 0.9453f * norm_inflow + 0.0013f; break;
        case  5: norm_outflow = 1.1238f * norm_inflow + 0.0179f; break;
        case  6: norm_outflow = 1.4155f * norm_inflow + 0.0346f; break;
        case  7: norm_outflow = 1.7473f * norm_inflow + 0.0357f; break;
        case  8: norm_outflow = 1.9366f * norm_inflow + 0.0477f; break;
        case  9: norm_outflow = 1.6652f * norm_inflow + 0.0537f; break;
        case 10: norm_outflow = 1.8508f * norm_inflow + 0.0418f; break;
        case 11: norm_outflow = 1.4030f * norm_inflow + 0.0437f; break;
        case 12: norm_outflow = 1.1497f * norm_inflow + 0.0632f; break;
    }
    return norm_outflow * max_outflow_m3d;
}

static float rule_878(float inflow_m3d, float storage_m3, int month) {
    const float max_inflow_m3d   = 77667872.2f;
    const float max_outflow_m3d  = 49295949.3f;
    const float max_storage_m3   = 948347036.3f;
    const float norm_inflow  = inflow_m3d  / max_inflow_m3d;
    const float norm_storage = storage_m3  / max_storage_m3;
    float norm_outflow;

    switch (month) {
        case  1: norm_outflow = 1.5159f * norm_inflow + 0.0020f; break;
        case  2: norm_outflow = 1.4889f * norm_inflow + -0.0267f; break;
        case  3: norm_outflow = 1.3173f * norm_inflow + -0.0303f; break;
        case  4: norm_outflow = 1.1472f * norm_inflow + -0.0359f; break;
        case  5: norm_outflow = 1.1400f * norm_inflow + -0.0226f; break;
        case  6: norm_outflow = 1.8215f * norm_inflow + -0.0228f; break;
        case  7: norm_outflow = 1.9878f * norm_inflow + -0.0202f; break;
        case  8: norm_outflow = 2.1367f * norm_inflow + -0.0125f; break;
        case  9: norm_outflow = 2.2977f * norm_inflow + -0.0400f; break;
        case 10: norm_outflow = 2.2723f * norm_inflow + -0.0316f; break;
        case 11: norm_outflow = 1.9149f * norm_inflow + -0.0175f; break;
        case 12: norm_outflow = 1.7804f * norm_inflow + -0.0119f; break;
    }
    return norm_outflow * max_outflow_m3d;
}

static float rule_879(float inflow_m3d, float storage_m3, int month) {
    const float max_inflow_m3d   = 152331316.1f;
    const float max_outflow_m3d  = 38350074.1f;
    const float max_storage_m3   = 821533450.9f;
    const float norm_inflow  = inflow_m3d  / max_inflow_m3d;
    const float norm_storage = storage_m3  / max_storage_m3;
    float norm_outflow;

    switch (month) {
        case  1: norm_outflow = 0.5822f * norm_inflow + 0.1335f; break;
        case  2: norm_outflow = 0.3449f * norm_inflow + 0.1486f; break;
        case  3: norm_outflow = 0.2861f * norm_inflow + 0.1129f; break;
        case  4: norm_outflow = 0.7774f * norm_inflow + 0.0478f; break;
        case  5: norm_outflow = 0.8373f * norm_inflow + 0.0794f; break;
        case  6: norm_outflow = 1.3988f * norm_inflow + 0.0272f; break;
        case  7: norm_outflow = 1.0501f * norm_inflow + 0.0214f; break;
        case  8: norm_outflow = 0.9752f * norm_inflow + 0.0131f; break;
        case  9: norm_outflow = 0.8492f * norm_inflow + 0.0192f; break;
        case 10: norm_outflow = 0.7738f * norm_inflow + 0.0505f; break;
        case 11: norm_outflow = 0.8350f * norm_inflow + 0.0849f; break;
        case 12: norm_outflow = 0.5404f * norm_inflow + 0.1494f; break;
    }
    return norm_outflow * max_outflow_m3d;
}

static float rule_884(float inflow_m3d, float storage_m3, int month) {
    const float max_inflow_m3d   = 189843285.9f;
    const float max_outflow_m3d  = 122382399.2f;
    const float max_storage_m3   = 915450124.7f;
    const float norm_inflow  = inflow_m3d  / max_inflow_m3d;
    const float norm_storage = storage_m3  / max_storage_m3;
    float norm_outflow;

    switch (month) {
        case  1: norm_outflow = 1.0666f * norm_inflow + 0.0482f; break;
        case  2: norm_outflow = 1.3041f * norm_inflow + 0.0165f; break;
        case  3: norm_outflow = 0.9499f * norm_inflow + 0.0204f; break;
        case  4: norm_outflow = 1.2129f * norm_inflow + -0.0252f; break;
        case  5: norm_outflow = 1.3318f * norm_inflow + -0.0087f; break;
        case  6: norm_outflow = 1.5571f * norm_inflow + 0.0040f; break;
        case  7: norm_outflow = 1.4920f * norm_inflow + 0.0173f; break;
        case  8: norm_outflow = 1.3717f * norm_inflow + 0.0469f; break;
        case  9: norm_outflow = 1.2537f * norm_inflow + 0.0500f; break;
        case 10: norm_outflow = 1.8125f * norm_inflow + 0.0151f; break;
        case 11: norm_outflow = 1.5839f * norm_inflow + 0.0108f; break;
        case 12: norm_outflow = 1.5757f * norm_inflow + 0.0128f; break;
    }
    return norm_outflow * max_outflow_m3d;
}

static float rule_886(float inflow_m3d, float storage_m3, int month) {
    const float max_inflow_m3d   = 83688098.8f;
    const float max_outflow_m3d  = 84928825.2f;
    const float max_storage_m3   = 77154174.0f;
    const float norm_inflow  = inflow_m3d  / max_inflow_m3d;
    const float norm_storage = storage_m3  / max_storage_m3;
    float norm_outflow;

    switch (month) {
        case  1: norm_outflow = 1.0215f * norm_inflow + -0.0065f; break;
        case  2: norm_outflow = 1.0066f * norm_inflow + -0.0040f; break;
        case  3: norm_outflow = 1.0027f * norm_inflow + -0.0014f; break;
        case  4: norm_outflow = 0.9960f * norm_inflow + -0.0029f; break;
        case  5: norm_outflow = 0.9977f * norm_inflow + -0.0013f; break;
        case  6: norm_outflow = 1.0073f * norm_inflow + -0.0025f; break;
        case  7: norm_outflow = 1.0237f * norm_inflow + -0.0043f; break;
        case  8: norm_outflow = 1.0257f * norm_inflow + -0.0059f; break;
        case  9: norm_outflow = 1.0269f * norm_inflow + -0.0051f; break;
        case 10: norm_outflow = 1.0746f * norm_inflow + -0.0101f; break;
        case 11: norm_outflow = 1.0306f * norm_inflow + -0.0052f; break;
        case 12: norm_outflow = 1.0055f * norm_inflow + -0.0039f; break;
    }
    return norm_outflow * max_outflow_m3d;
}

static float rule_3054(float inflow_m3d, float storage_m3, int month) {
    const float max_inflow_m3d   = 414743497.9f;
    const float max_outflow_m3d  = 413324498.2f;
    const float max_storage_m3   = 35018990.6f;
    const float norm_inflow  = inflow_m3d  / max_inflow_m3d;
    const float norm_storage = storage_m3  / max_storage_m3;
    float norm_outflow;

    switch (month) {
        case  1: norm_outflow = 0.9893f * norm_inflow + 0.0003f; break;
        case  2: norm_outflow = 0.9922f * norm_inflow + 0.0003f; break;
        case  3: norm_outflow = 0.9887f * norm_inflow + 0.0006f; break;
        case  4: norm_outflow = 0.9811f * norm_inflow + 0.0007f; break;
        case  5: norm_outflow = 0.9966f * norm_inflow + 0.0003f; break;
        case  6: norm_outflow = 0.9860f * norm_inflow + 0.0000f; break;
        case  7: norm_outflow = 0.9988f * norm_inflow + -0.0001f; break;
        case  8: norm_outflow = 0.9940f * norm_inflow + 0.0001f; break;
        case  9: norm_outflow = 0.9752f * norm_inflow + 0.0002f; break;
        case 10: norm_outflow = 0.9888f * norm_inflow + 0.0006f; break;
        case 11: norm_outflow = 0.9281f * norm_inflow + 0.0004f; break;
        case 12: norm_outflow = 0.9915f * norm_inflow + 0.0002f; break;
    }
    return norm_outflow * max_outflow_m3d;
}

static float rule_154(float inflow_m3d, float storage_m3, int month) {
    const float max_inflow_m3d   = 548659202.5f;
    const float max_outflow_m3d  = 509866225.1f;
    const float max_storage_m3   = 800919533.2f;
    const float norm_inflow  = inflow_m3d  / max_inflow_m3d;
    const float norm_storage = storage_m3  / max_storage_m3;
    float norm_outflow;

    switch (month) {
        case  1: norm_outflow = 1.0658f * norm_inflow + 0.0014f; break;
        case  2: norm_outflow = 1.0688f * norm_inflow + 0.0013f; break;
        case  3: norm_outflow = 1.0513f * norm_inflow + 0.0024f; break;
        case  4: norm_outflow = 1.0683f * norm_inflow + -0.0037f; break;
        case  5: norm_outflow = 1.0673f * norm_inflow + 0.0002f; break;
        case  6: norm_outflow = 1.0722f * norm_inflow + 0.0007f; break;
        case  7: norm_outflow = 1.0633f * norm_inflow + 0.0009f; break;
        case  8: norm_outflow = 1.0663f * norm_inflow + 0.0015f; break;
        case  9: norm_outflow = 1.0405f * norm_inflow + 0.0033f; break;
        case 10: norm_outflow = 1.0777f * norm_inflow + 0.0011f; break;
        case 11: norm_outflow = 1.0481f * norm_inflow + 0.0066f; break;
        case 12: norm_outflow = 1.0696f * norm_inflow + 0.0021f; break;
    }
    return norm_outflow * max_outflow_m3d;
}

static float rule_899(float inflow_m3d, float storage_m3, int month) {
    const float max_inflow_m3d   = 38032594.6f;
    const float max_outflow_m3d  = 38413593.7f;
    const float max_storage_m3   = 78049803.8f;
    const float norm_inflow  = inflow_m3d  / max_inflow_m3d;
    const float norm_storage = storage_m3  / max_storage_m3;
    float norm_outflow;

    switch (month) {
        case  1: norm_outflow = 0.6726f * norm_inflow + 0.0108f; break;
        case  2: norm_outflow = 0.5974f * norm_inflow + 0.0117f; break;
        case  3: norm_outflow = 0.6494f * norm_inflow + 0.0051f; break;
        case  4: norm_outflow = 0.7506f * norm_inflow + -0.0006f; break;
        case  5: norm_outflow = 0.9161f * norm_inflow + 0.0008f; break;
        case  6: norm_outflow = 0.8091f * norm_inflow + 0.0030f; break;
        case  7: norm_outflow = 0.9346f * norm_inflow + 0.0023f; break;
        case  8: norm_outflow = 0.5919f * norm_inflow + 0.0053f; break;
        case  9: norm_outflow = 0.3978f * norm_inflow + 0.0067f; break;
        case 10: norm_outflow = 0.7189f * norm_inflow + 0.0052f; break;
        case 11: norm_outflow = 0.8137f * norm_inflow + 0.0090f; break;
        case 12: norm_outflow = 0.7311f * norm_inflow + 0.0100f; break;
    }
    return norm_outflow * max_outflow_m3d;
}

static float rule_900(float inflow_m3d, float storage_m3, int month) {
    const float max_inflow_m3d   = 73031331.2f;
    const float max_outflow_m3d  = 63760216.2f;
    const float max_storage_m3   = 897690973.1f;
    const float norm_inflow  = inflow_m3d  / max_inflow_m3d;
    const float norm_storage = storage_m3  / max_storage_m3;
    float norm_outflow;

    switch (month) {
        case  1: norm_outflow = 0.7079f * norm_inflow + 0.0804f; break;
        case  2: norm_outflow = 1.2144f * norm_inflow + -0.0140f; break;
        case  3: norm_outflow = 1.2082f * norm_inflow + -0.0408f; break;
        case  4: norm_outflow = 1.2851f * norm_inflow + -0.0712f; break;
        case  5: norm_outflow = 1.2907f * norm_inflow + -0.0457f; break;
        case  6: norm_outflow = 1.2064f * norm_inflow + -0.0048f; break;
        case  7: norm_outflow = 1.1452f * norm_inflow + 0.0034f; break;
        case  8: norm_outflow = 1.2293f * norm_inflow + 0.0195f; break;
        case  9: norm_outflow = 0.8935f * norm_inflow + 0.0560f; break;
        case 10: norm_outflow = 1.3399f * norm_inflow + 0.0160f; break;
        case 11: norm_outflow = 1.1437f * norm_inflow + 0.0225f; break;
        case 12: norm_outflow = 1.0947f * norm_inflow + 0.0168f; break;
    }
    return norm_outflow * max_outflow_m3d;
}

static float rule_3094(float inflow_m3d, float storage_m3, int month) {
    const float max_inflow_m3d   = 34083372.0f;
    const float max_outflow_m3d  = 35382369.9f;
    const float max_storage_m3   = 36263942.0f;
    const float norm_inflow  = inflow_m3d  / max_inflow_m3d;
    const float norm_storage = storage_m3  / max_storage_m3;
    float norm_outflow;

    switch (month) {
        case  1: norm_outflow = 0.9395f * norm_inflow + 0.0045f; break;
        case  2: norm_outflow = 0.9525f * norm_inflow + 0.0022f; break;
        case  3: norm_outflow = 0.9440f * norm_inflow + 0.0024f; break;
        case  4: norm_outflow = 0.9535f * norm_inflow + 0.0004f; break;
        case  5: norm_outflow = 0.9533f * norm_inflow + 0.0008f; break;
        case  6: norm_outflow = 0.9388f * norm_inflow + 0.0028f; break;
        case  7: norm_outflow = 0.9291f * norm_inflow + 0.0049f; break;
        case  8: norm_outflow = 0.9096f * norm_inflow + 0.0081f; break;
        case  9: norm_outflow = 0.9213f * norm_inflow + 0.0063f; break;
        case 10: norm_outflow = 0.9144f * norm_inflow + 0.0077f; break;
        case 11: norm_outflow = 0.9271f * norm_inflow + 0.0047f; break;
        case 12: norm_outflow = 0.9483f * norm_inflow + 0.0028f; break;
    }
    return norm_outflow * max_outflow_m3d;
}

static float rule_911(float inflow_m3d, float storage_m3, int month) {
    const float max_inflow_m3d   = 45153388.1f;
    const float max_outflow_m3d  = 29075072.6f;
    const float max_storage_m3   = 270748490.0f;
    const float norm_inflow  = inflow_m3d  / max_inflow_m3d;
    const float norm_storage = storage_m3  / max_storage_m3;
    float norm_outflow;

    switch (month) {
        case  1: norm_outflow = 1.3919f * norm_inflow + 0.0226f; break;
        case  2: norm_outflow = 1.2834f * norm_inflow + 0.0274f; break;
        case  3: norm_outflow = 1.0543f * norm_inflow + 0.0259f; break;
        case  4: norm_outflow = 1.5404f * norm_inflow + -0.0438f; break;
        case  5: norm_outflow = 1.3360f * norm_inflow + -0.0086f; break;
        case  6: norm_outflow = 1.5312f * norm_inflow + 0.0009f; break;
        case  7: norm_outflow = 1.5972f * norm_inflow + 0.0049f; break;
        case  8: norm_outflow = 1.6254f * norm_inflow + 0.0151f; break;
        case  9: norm_outflow = 1.4660f * norm_inflow + 0.0346f; break;
        case 10: norm_outflow = 1.6872f * norm_inflow + 0.0142f; break;
        case 11: norm_outflow = 1.5123f * norm_inflow + 0.0232f; break;
        case 12: norm_outflow = 1.5416f * norm_inflow + 0.0141f; break;
    }
    return norm_outflow * max_outflow_m3d;
}

static float rule_159(float inflow_m3d, float storage_m3, int month) {
    const float max_inflow_m3d   = 606233267.2f;
    const float max_outflow_m3d  = 546076229.3f;
    const float max_storage_m3   = 546752344.8f;
    const float norm_inflow  = inflow_m3d  / max_inflow_m3d;
    const float norm_storage = storage_m3  / max_storage_m3;
    float norm_outflow;

    switch (month) {
        case  1: norm_outflow = 1.1141f * norm_inflow + -0.0008f; break;
        case  2: norm_outflow = 1.1107f * norm_inflow + -0.0000f; break;
        case  3: norm_outflow = 1.1008f * norm_inflow + 0.0009f; break;
        case  4: norm_outflow = 1.1126f * norm_inflow + -0.0054f; break;
        case  5: norm_outflow = 1.1103f * norm_inflow + -0.0005f; break;
        case  6: norm_outflow = 1.1126f * norm_inflow + -0.0002f; break;
        case  7: norm_outflow = 1.1019f * norm_inflow + 0.0014f; break;
        case  8: norm_outflow = 1.1105f * norm_inflow + 0.0003f; break;
        case  9: norm_outflow = 1.0883f * norm_inflow + 0.0030f; break;
        case 10: norm_outflow = 1.1020f * norm_inflow + 0.0037f; break;
        case 11: norm_outflow = 1.0884f * norm_inflow + 0.0044f; break;
        case 12: norm_outflow = 1.1101f * norm_inflow + 0.0004f; break;
    }
    return norm_outflow * max_outflow_m3d;
}

static float rule_3100(float inflow_m3d, float storage_m3, int month) {
    const float max_inflow_m3d   = 75523638.2f;
    const float max_outflow_m3d  = 71082648.1f;
    const float max_storage_m3   = 55205877.6f;
    const float norm_inflow  = inflow_m3d  / max_inflow_m3d;
    const float norm_storage = storage_m3  / max_storage_m3;
    float norm_outflow;

    switch (month) {
        case  1: norm_outflow = 0.9922f * norm_inflow + 0.0035f; break;
        case  2: norm_outflow = 0.9976f * norm_inflow + 0.0031f; break;
        case  3: norm_outflow = 1.0239f * norm_inflow + 0.0010f; break;
        case  4: norm_outflow = 1.0475f * norm_inflow + -0.0013f; break;
        case  5: norm_outflow = 1.0669f * norm_inflow + -0.0003f; break;
        case  6: norm_outflow = 1.0810f * norm_inflow + -0.0008f; break;
        case  7: norm_outflow = 1.0791f * norm_inflow + -0.0005f; break;
        case  8: norm_outflow = 1.0884f * norm_inflow + -0.0008f; break;
        case  9: norm_outflow = 1.0638f * norm_inflow + -0.0000f; break;
        case 10: norm_outflow = 1.0638f * norm_inflow + 0.0001f; break;
        case 11: norm_outflow = 1.0456f * norm_inflow + 0.0024f; break;
        case 12: norm_outflow = 1.0223f * norm_inflow + 0.0029f; break;
    }
    return norm_outflow * max_outflow_m3d;
}

static float rule_160(float inflow_m3d, float storage_m3, int month) {
    const float max_inflow_m3d   = 1079541553.3f;
    const float max_outflow_m3d  = 1073851565.0f;
    const float max_storage_m3   = 750077461.1f;
    const float norm_inflow  = inflow_m3d  / max_inflow_m3d;
    const float norm_storage = storage_m3  / max_storage_m3;
    float norm_outflow;

    switch (month) {
        case  1: norm_outflow = 1.0012f * norm_inflow + 0.0008f; break;
        case  2: norm_outflow = 1.0027f * norm_inflow + 0.0004f; break;
        case  3: norm_outflow = 1.0017f * norm_inflow + -0.0014f; break;
        case  4: norm_outflow = 1.0056f * norm_inflow + -0.0009f; break;
        case  5: norm_outflow = 1.0085f * norm_inflow + -0.0001f; break;
        case  6: norm_outflow = 0.9982f * norm_inflow + 0.0005f; break;
        case  7: norm_outflow = 1.0102f * norm_inflow + 0.0001f; break;
        case  8: norm_outflow = 1.0122f * norm_inflow + 0.0000f; break;
        case  9: norm_outflow = 0.9927f * norm_inflow + 0.0017f; break;
        case 10: norm_outflow = 0.9895f * norm_inflow + 0.0020f; break;
        case 11: norm_outflow = 0.9869f * norm_inflow + 0.0021f; break;
        case 12: norm_outflow = 1.0076f * norm_inflow + -0.0002f; break;
    }
    return norm_outflow * max_outflow_m3d;
}

static float rule_915(float inflow_m3d, float storage_m3, int month) {
    const float max_inflow_m3d   = 11920464.9f;
    const float max_outflow_m3d  = 7224765.1f;
    const float max_storage_m3   = 149386639.5f;
    const float norm_inflow  = inflow_m3d  / max_inflow_m3d;
    const float norm_storage = storage_m3  / max_storage_m3;
    float norm_outflow;

    switch (month) {
        case  1: norm_outflow = 1.3989f * norm_inflow + 0.0279f; break;
        case  2: norm_outflow = 1.3283f * norm_inflow + 0.0142f; break;
        case  3: norm_outflow = 1.1549f * norm_inflow + -0.0055f; break;
        case  4: norm_outflow = 1.2158f * norm_inflow + -0.0232f; break;
        case  5: norm_outflow = 1.5907f * norm_inflow + -0.0205f; break;
        case  6: norm_outflow = 1.6627f * norm_inflow + 0.0048f; break;
        case  7: norm_outflow = 1.5981f * norm_inflow + 0.0248f; break;
        case  8: norm_outflow = 1.5765f * norm_inflow + 0.0468f; break;
        case  9: norm_outflow = 1.2288f * norm_inflow + 0.0598f; break;
        case 10: norm_outflow = 1.6125f * norm_inflow + 0.0342f; break;
        case 11: norm_outflow = 1.5617f * norm_inflow + 0.0167f; break;
        case 12: norm_outflow = 1.6423f * norm_inflow + 0.0118f; break;
    }
    return norm_outflow * max_outflow_m3d;
}

static float rule_916(float inflow_m3d, float storage_m3, int month) {
    const float max_inflow_m3d   = 631109128.3f;
    const float max_outflow_m3d  = 633419769.0f;
    const float max_storage_m3   = 244354484.9f;
    const float norm_inflow  = inflow_m3d  / max_inflow_m3d;
    const float norm_storage = storage_m3  / max_storage_m3;
    float norm_outflow;

    switch (month) {
        case  1: norm_outflow = 0.9970f * norm_inflow + -0.0002f; break;
        case  2: norm_outflow = 0.9973f * norm_inflow + -0.0002f; break;
        case  3: norm_outflow = 0.9956f * norm_inflow + 0.0002f; break;
        case  4: norm_outflow = 0.9986f * norm_inflow + -0.0002f; break;
        case  5: norm_outflow = 0.9961f * norm_inflow + 0.0000f; break;
        case  6: norm_outflow = 0.9957f * norm_inflow + 0.0000f; break;
        case  7: norm_outflow = 0.9937f * norm_inflow + 0.0003f; break;
        case  8: norm_outflow = 0.9840f * norm_inflow + 0.0014f; break;
        case  9: norm_outflow = 0.9926f * norm_inflow + 0.0004f; break;
        case 10: norm_outflow = 0.9986f * norm_inflow + -0.0002f; break;
        case 11: norm_outflow = 0.9952f * norm_inflow + 0.0001f; break;
        case 12: norm_outflow = 0.9974f * norm_inflow + -0.0002f; break;
    }
    return norm_outflow * max_outflow_m3d;
}

static float rule_3111(float inflow_m3d, float storage_m3, int month) {
    const float max_inflow_m3d   = 15256426.5f;
    const float max_outflow_m3d  = 5720114.7f;
    const float max_storage_m3   = 107213834.9f;
    const float norm_inflow  = inflow_m3d  / max_inflow_m3d;
    const float norm_storage = storage_m3  / max_storage_m3;
    float norm_outflow;

    switch (month) {
        case  1: norm_outflow = 2.0842f * norm_inflow + 0.0337f; break;
        case  2: norm_outflow = 1.8626f * norm_inflow + 0.0254f; break;
        case  3: norm_outflow = 1.6019f * norm_inflow + 0.0094f; break;
        case  4: norm_outflow = 2.0178f * norm_inflow + -0.0384f; break;
        case  5: norm_outflow = 2.2990f * norm_inflow + -0.0246f; break;
        case  6: norm_outflow = 2.7720f * norm_inflow + -0.0054f; break;
        case  7: norm_outflow = 2.5377f * norm_inflow + 0.0351f; break;
        case  8: norm_outflow = 3.1031f * norm_inflow + 0.0285f; break;
        case  9: norm_outflow = 2.8717f * norm_inflow + 0.0291f; break;
        case 10: norm_outflow = 2.8917f * norm_inflow + 0.0294f; break;
        case 11: norm_outflow = 2.6819f * norm_inflow + 0.0217f; break;
        case 12: norm_outflow = 2.8478f * norm_inflow + 0.0087f; break;
    }
    return norm_outflow * max_outflow_m3d;
}

static float rule_3115(float inflow_m3d, float storage_m3, int month) {
    const float max_inflow_m3d   = 13547905.5f;
    const float max_outflow_m3d  = 11547796.4f;
    const float max_storage_m3   = 120870802.1f;
    const float norm_inflow  = inflow_m3d  / max_inflow_m3d;
    const float norm_storage = storage_m3  / max_storage_m3;
    float norm_outflow;

    switch (month) {
        case  1: norm_outflow = 0.9295f * norm_inflow + 0.0121f; break;
        case  2: norm_outflow = 0.9202f * norm_inflow + -0.0021f; break;
        case  3: norm_outflow = 1.0631f * norm_inflow + -0.0303f; break;
        case  4: norm_outflow = 1.2714f * norm_inflow + -0.0405f; break;
        case  5: norm_outflow = 1.3062f * norm_inflow + -0.0255f; break;
        case  6: norm_outflow = 1.1996f * norm_inflow + 0.0016f; break;
        case  7: norm_outflow = 1.2551f * norm_inflow + 0.0114f; break;
        case  8: norm_outflow = 1.3470f * norm_inflow + 0.0193f; break;
        case  9: norm_outflow = 1.3221f * norm_inflow + 0.0217f; break;
        case 10: norm_outflow = 1.1895f * norm_inflow + 0.0267f; break;
        case 11: norm_outflow = 1.1837f * norm_inflow + 0.0035f; break;
        case 12: norm_outflow = 1.2558f * norm_inflow + -0.0085f; break;
    }
    return norm_outflow * max_outflow_m3d;
}

static float rule_161(float inflow_m3d, float storage_m3, int month) {
    const float max_inflow_m3d   = 1029342560.8f;
    const float max_outflow_m3d  = 940823233.5f;
    const float max_storage_m3   = 976918627.0f;
    const float norm_inflow  = inflow_m3d  / max_inflow_m3d;
    const float norm_storage = storage_m3  / max_storage_m3;
    float norm_outflow;

    switch (month) {
        case  1: norm_outflow = 1.0786f * norm_inflow + 0.0026f; break;
        case  2: norm_outflow = 1.0734f * norm_inflow + 0.0035f; break;
        case  3: norm_outflow = 1.0753f * norm_inflow + 0.0015f; break;
        case  4: norm_outflow = 1.1065f * norm_inflow + -0.0036f; break;
        case  5: norm_outflow = 1.0907f * norm_inflow + 0.0005f; break;
        case  6: norm_outflow = 1.0896f * norm_inflow + 0.0004f; break;
        case  7: norm_outflow = 1.0877f * norm_inflow + 0.0007f; break;
        case  8: norm_outflow = 1.0812f * norm_inflow + 0.0019f; break;
        case  9: norm_outflow = 1.0715f * norm_inflow + 0.0030f; break;
        case 10: norm_outflow = 1.1122f * norm_inflow + -0.0003f; break;
        case 11: norm_outflow = 1.0725f * norm_inflow + 0.0020f; break;
        case 12: norm_outflow = 1.0891f * norm_inflow + 0.0012f; break;
    }
    return norm_outflow * max_outflow_m3d;
}

static float rule_928(float inflow_m3d, float storage_m3, int month) {
    const float max_inflow_m3d   = 22233812.2f;
    const float max_outflow_m3d  = 18300401.1f;
    const float max_storage_m3   = 75007918.8f;
    const float norm_inflow  = inflow_m3d  / max_inflow_m3d;
    const float norm_storage = storage_m3  / max_storage_m3;
    float norm_outflow;

    switch (month) {
        case  1: norm_outflow = 0.8809f * norm_inflow + 0.0172f; break;
        case  2: norm_outflow = 0.5840f * norm_inflow + 0.0126f; break;
        case  3: norm_outflow = 0.7464f * norm_inflow + 0.0053f; break;
        case  4: norm_outflow = 0.7951f * norm_inflow + 0.0063f; break;
        case  5: norm_outflow = 0.9384f * norm_inflow + 0.0100f; break;
        case  6: norm_outflow = 0.9517f * norm_inflow + 0.0061f; break;
        case  7: norm_outflow = 0.9203f * norm_inflow + 0.0041f; break;
        case  8: norm_outflow = 0.8261f * norm_inflow + 0.0036f; break;
        case  9: norm_outflow = 0.8973f * norm_inflow + 0.0043f; break;
        case 10: norm_outflow = 1.1709f * norm_inflow + 0.0105f; break;
        case 11: norm_outflow = 0.9063f * norm_inflow + 0.0422f; break;
        case 12: norm_outflow = 0.5550f * norm_inflow + 0.0531f; break;
    }
    return norm_outflow * max_outflow_m3d;
}

static float rule_3143(float inflow_m3d, float storage_m3, int month) {
    const float max_inflow_m3d   = 10085486.2f;
    const float max_outflow_m3d  = 6018546.3f;
    const float max_storage_m3   = 30688982.4f;
    const float norm_inflow  = inflow_m3d  / max_inflow_m3d;
    const float norm_storage = storage_m3  / max_storage_m3;
    float norm_outflow;

    switch (month) {
        case  1: norm_outflow = 1.1945f * norm_inflow + 0.0184f; break;
        case  2: norm_outflow = 0.8412f * norm_inflow + 0.0123f; break;
        case  3: norm_outflow = 1.1423f * norm_inflow + 0.0021f; break;
        case  4: norm_outflow = 1.2078f * norm_inflow + 0.0066f; break;
        case  5: norm_outflow = 1.3304f * norm_inflow + 0.0111f; break;
        case  6: norm_outflow = 1.3907f * norm_inflow + 0.0047f; break;
        case  7: norm_outflow = 1.2721f * norm_inflow + 0.0038f; break;
        case  8: norm_outflow = 0.8471f * norm_inflow + 0.0048f; break;
        case  9: norm_outflow = 1.4371f * norm_inflow + 0.0040f; break;
        case 10: norm_outflow = 1.7087f * norm_inflow + 0.0075f; break;
        case 11: norm_outflow = 1.2667f * norm_inflow + 0.0384f; break;
        case 12: norm_outflow = 0.8734f * norm_inflow + 0.0542f; break;
    }
    return norm_outflow * max_outflow_m3d;
}

static float rule_163(float inflow_m3d, float storage_m3, int month) {
    const float max_inflow_m3d   = 744995794.3f;
    const float max_outflow_m3d  = 735148261.9f;
    const float max_storage_m3   = 935887161.5f;
    const float norm_inflow  = inflow_m3d  / max_inflow_m3d;
    const float norm_storage = storage_m3  / max_storage_m3;
    float norm_outflow;

    switch (month) {
        case  1: norm_outflow = 1.0058f * norm_inflow + 0.0014f; break;
        case  2: norm_outflow = 0.9972f * norm_inflow + 0.0031f; break;
        case  3: norm_outflow = 1.0025f * norm_inflow + 0.0018f; break;
        case  4: norm_outflow = 1.0168f * norm_inflow + -0.0012f; break;
        case  5: norm_outflow = 1.0069f * norm_inflow + 0.0009f; break;
        case  6: norm_outflow = 1.0205f * norm_inflow + -0.0005f; break;
        case  7: norm_outflow = 1.0187f * norm_inflow + -0.0002f; break;
        case  8: norm_outflow = 1.0618f * norm_inflow + -0.0050f; break;
        case  9: norm_outflow = 1.0043f * norm_inflow + 0.0011f; break;
        case 10: norm_outflow = 1.0139f * norm_inflow + 0.0007f; break;
        case 11: norm_outflow = 1.0026f * norm_inflow + 0.0008f; break;
        case 12: norm_outflow = 1.0051f * norm_inflow + 0.0013f; break;
    }
    return norm_outflow * max_outflow_m3d;
}

static float rule_3152(float inflow_m3d, float storage_m3, int month) {
    const float max_inflow_m3d   = 25518743.3f;
    const float max_outflow_m3d  = 22738087.7f;
    const float max_storage_m3   = 27173564.4f;
    const float norm_inflow  = inflow_m3d  / max_inflow_m3d;
    const float norm_storage = storage_m3  / max_storage_m3;
    float norm_outflow;

    switch (month) {
        case  1: norm_outflow = 0.9470f * norm_inflow + 0.0059f; break;
        case  2: norm_outflow = 1.0403f * norm_inflow + 0.0029f; break;
        case  3: norm_outflow = 0.9623f * norm_inflow + 0.0067f; break;
        case  4: norm_outflow = 0.9734f * norm_inflow + 0.0045f; break;
        case  5: norm_outflow = 1.0307f * norm_inflow + 0.0025f; break;
        case  6: norm_outflow = 1.0092f * norm_inflow + 0.0022f; break;
        case  7: norm_outflow = 0.9803f * norm_inflow + 0.0017f; break;
        case  8: norm_outflow = 0.6973f * norm_inflow + 0.0026f; break;
        case  9: norm_outflow = 0.7900f * norm_inflow + 0.0023f; break;
        case 10: norm_outflow = 1.0307f * norm_inflow + 0.0008f; break;
        case 11: norm_outflow = 0.9618f * norm_inflow + 0.0008f; break;
        case 12: norm_outflow = 1.0025f * norm_inflow + 0.0036f; break;
    }
    return norm_outflow * max_outflow_m3d;
}

static float rule_169(float inflow_m3d, float storage_m3, int month) {
    const float max_inflow_m3d   = 328830286.9f;
    const float max_outflow_m3d  = 28135613.5f;
    const float max_storage_m3   = 2205583121.0f;
    const float norm_inflow  = inflow_m3d  / max_inflow_m3d;
    const float norm_storage = storage_m3  / max_storage_m3;
    float norm_outflow;

    switch (month) {
        case  1: norm_outflow = 0.0000f * norm_inflow + 0.2450f; break;
        case  2: norm_outflow = 0.0000f * norm_inflow + 0.2226f; break;
        case  3: norm_outflow = 0.0000f * norm_inflow + 0.1449f; break;
        case  4: norm_outflow = 0.0176f * norm_inflow + 0.0965f; break;
        case  5: norm_outflow = 0.7324f * norm_inflow + 0.0781f; break;
        case  6: norm_outflow = 0.0000f * norm_inflow + 0.0856f; break;
        case  7: norm_outflow = 0.0000f * norm_inflow + 0.1016f; break;
        case  8: norm_outflow = 0.0000f * norm_inflow + 0.1568f; break;
        case  9: norm_outflow = 0.0000f * norm_inflow + 0.1831f; break;
        case 10: norm_outflow = 0.0000f * norm_inflow + 0.1919f; break;
        case 11: norm_outflow = 0.0000f * norm_inflow + 0.1981f; break;
        case 12: norm_outflow = 0.0000f * norm_inflow + 0.1825f; break;
    }
    return norm_outflow * max_outflow_m3d;
}

static float rule_923(float inflow_m3d, float storage_m3, int month) {
    const float max_inflow_m3d   = 1042763887.2f;
    const float max_outflow_m3d  = 1041825889.1f;
    const float max_storage_m3   = 398834163.3f;
    const float norm_inflow  = inflow_m3d  / max_inflow_m3d;
    const float norm_storage = storage_m3  / max_storage_m3;
    float norm_outflow;

    switch (month) {
        case  1: norm_outflow = 1.0007f * norm_inflow + 0.0000f; break;
        case  2: norm_outflow = 1.0008f * norm_inflow + 0.0000f; break;
        case  3: norm_outflow = 1.0012f * norm_inflow + -0.0000f; break;
        case  4: norm_outflow = 1.0004f * norm_inflow + -0.0004f; break;
        case  5: norm_outflow = 1.0012f * norm_inflow + -0.0000f; break;
        case  6: norm_outflow = 1.0026f * norm_inflow + -0.0001f; break;
        case  7: norm_outflow = 1.0030f * norm_inflow + -0.0002f; break;
        case  8: norm_outflow = 1.0057f * norm_inflow + -0.0004f; break;
        case  9: norm_outflow = 1.0041f * norm_inflow + -0.0003f; break;
        case 10: norm_outflow = 1.0014f * norm_inflow + -0.0000f; break;
        case 11: norm_outflow = 1.0015f * norm_inflow + -0.0000f; break;
        case 12: norm_outflow = 1.0009f * norm_inflow + 0.0004f; break;
    }
    return norm_outflow * max_outflow_m3d;
}

static float rule_844(float inflow_m3d, float storage_m3, int month) {
    const float max_inflow_m3d   = 237612457.7f;
    const float max_outflow_m3d  = 65093700.1f;
    const float max_storage_m3   = 440923461.2f;
    const float norm_inflow  = inflow_m3d  / max_inflow_m3d;
    const float norm_storage = storage_m3  / max_storage_m3;
    float norm_outflow;

    switch (month) {
        case  1: norm_outflow = 0.6862f * norm_inflow + 0.0115f; break;
        case  2: norm_outflow = 0.1304f * norm_inflow + 0.0133f; break;
        case  3: norm_outflow = 0.2171f * norm_inflow + 0.0247f; break;
        case  4: norm_outflow = 0.0000f * norm_inflow + 0.0234f; break;
        case  5: norm_outflow = 0.0000f * norm_inflow + 0.0325f; break;
        case  6: norm_outflow = 0.0417f * norm_inflow + 0.0369f; break;
        case  7: norm_outflow = 1.3520f * norm_inflow + 0.0194f; break;
        case  8: norm_outflow = 0.2851f * norm_inflow + 0.0091f; break;
        case  9: norm_outflow = 0.0582f * norm_inflow + 0.0059f; break;
        case 10: norm_outflow = 0.6324f * norm_inflow + 0.0115f; break;
        case 11: norm_outflow = 0.3721f * norm_inflow + 0.0107f; break;
        case 12: norm_outflow = 0.4089f * norm_inflow + 0.0080f; break;
    }
    return norm_outflow * max_outflow_m3d;
}

static float rule_119(float inflow_m3d, float storage_m3, int month) {
    const float max_inflow_m3d   = 86439926.6f;
    const float max_outflow_m3d  = 62925811.9f;
    const float max_storage_m3   = 2515047957.9f;
    const float norm_inflow  = inflow_m3d  / max_inflow_m3d;
    const float norm_storage = storage_m3  / max_storage_m3;
    float norm_outflow;

    switch (month) {
        case  1: norm_outflow = 0.6749f * norm_inflow + 0.1078f; break;
        case  2: norm_outflow = 0.6193f * norm_inflow + 0.1107f; break;
        case  3: norm_outflow = 0.9908f * norm_inflow + 0.0590f; break;
        case  4: norm_outflow = 0.8205f * norm_inflow + 0.0683f; break;
        case  5: norm_outflow = 0.6272f * norm_inflow + 0.0772f; break;
        case  6: norm_outflow = 0.9313f * norm_inflow + 0.0103f; break;
        case  7: norm_outflow = 1.1795f * norm_inflow + 0.0721f; break;
        case  8: norm_outflow = 0.9764f * norm_inflow + 0.0994f; break;
        case  9: norm_outflow = 0.7925f * norm_inflow + 0.0859f; break;
        case 10: norm_outflow = 0.5887f * norm_inflow + 0.0831f; break;
        case 11: norm_outflow = 0.9567f * norm_inflow + 0.0411f; break;
        case 12: norm_outflow = 0.5437f * norm_inflow + 0.1148f; break;
    }
    return norm_outflow * max_outflow_m3d;
}

static float rule_909(float inflow_m3d, float storage_m3, int month) {
    const float max_inflow_m3d   = 98025036.5f;
    const float max_outflow_m3d  = 63522903.7f;
    const float max_storage_m3   = 374176158.0f;
    const float norm_inflow  = inflow_m3d  / max_inflow_m3d;
    const float norm_storage = storage_m3  / max_storage_m3;
    float norm_outflow;

    switch (month) {
        case  1: norm_outflow = 1.0598f * norm_inflow + 0.0148f; break;
        case  2: norm_outflow = 0.9346f * norm_inflow + 0.0135f; break;
        case  3: norm_outflow = 0.9544f * norm_inflow + 0.0076f; break;
        case  4: norm_outflow = 1.0998f * norm_inflow + 0.0008f; break;
        case  5: norm_outflow = 1.1612f * norm_inflow + 0.0040f; break;
        case  6: norm_outflow = 1.4039f * norm_inflow + 0.0019f; break;
        case  7: norm_outflow = 1.6545f * norm_inflow + 0.0004f; break;
        case  8: norm_outflow = 1.8508f * norm_inflow + 0.0008f; break;
        case  9: norm_outflow = 1.4261f * norm_inflow + 0.0027f; break;
        case 10: norm_outflow = 1.7963f * norm_inflow + 0.0041f; break;
        case 11: norm_outflow = 1.6746f * norm_inflow + 0.0088f; break;
        case 12: norm_outflow = 1.1344f * norm_inflow + 0.0260f; break;
    }
    return norm_outflow * max_outflow_m3d;
}

static float rule_872(float inflow_m3d, float storage_m3, int month) {
    const float max_inflow_m3d   = 224338386.8f;
    const float max_outflow_m3d  = 208479687.2f;
    const float max_storage_m3   = 376639294.2f;
    const float norm_inflow  = inflow_m3d  / max_inflow_m3d;
    const float norm_storage = storage_m3  / max_storage_m3;
    float norm_outflow;

    switch (month) {
        case  1: norm_outflow = 1.0641f * norm_inflow + 0.0026f; break;
        case  2: norm_outflow = 1.0497f * norm_inflow + 0.0045f; break;
        case  3: norm_outflow = 1.0591f * norm_inflow + 0.0030f; break;
        case  4: norm_outflow = 1.0713f * norm_inflow + -0.0072f; break;
        case  5: norm_outflow = 1.0591f * norm_inflow + 0.0023f; break;
        case  6: norm_outflow = 1.0715f * norm_inflow + 0.0008f; break;
        case  7: norm_outflow = 1.0451f * norm_inflow + 0.0032f; break;
        case  8: norm_outflow = 0.9885f * norm_inflow + 0.0097f; break;
        case  9: norm_outflow = 1.0565f * norm_inflow + 0.0017f; break;
        case 10: norm_outflow = 1.0434f * norm_inflow + 0.0066f; break;
        case 11: norm_outflow = 1.0784f * norm_inflow + 0.0036f; break;
        case 12: norm_outflow = 1.0475f * norm_inflow + 0.0036f; break;
    }
    return norm_outflow * max_outflow_m3d;
}

//------------------------------------------------------------------------------


// ---- Dispatch based on reservoir GDW ID ----
float applyReservoirRule(int res_id, float inflow_m3d, float storage_m3, int month) {
    switch (res_id) {
        case 487: return rule_487(inflow_m3d, storage_m3, month);
        case 488: return rule_488(inflow_m3d, storage_m3, month);
        case 493: return rule_493(inflow_m3d, storage_m3, month);
        case 5560: return rule_5560(inflow_m3d, storage_m3, month);
        case 104: return rule_104(inflow_m3d, storage_m3, month);
        case 2194: return rule_2194(inflow_m3d, storage_m3, month);
        case 2197: return rule_2197(inflow_m3d, storage_m3, month);
        case 606: return rule_606(inflow_m3d, storage_m3, month);
        case 624: return rule_624(inflow_m3d, storage_m3, month);
        case 642: return rule_642(inflow_m3d, storage_m3, month);
        case 651: return rule_651(inflow_m3d, storage_m3, month);
        case 5587: return rule_5587(inflow_m3d, storage_m3, month);
        case 694: return rule_694(inflow_m3d, storage_m3, month);
        case 704: return rule_704(inflow_m3d, storage_m3, month);
        case 2483: return rule_2483(inflow_m3d, storage_m3, month);
        case 2525: return rule_2525(inflow_m3d, storage_m3, month);
        case 721: return rule_721(inflow_m3d, storage_m3, month);
        case 727: return rule_727(inflow_m3d, storage_m3, month);
        case 2768: return rule_2768(inflow_m3d, storage_m3, month);
        case 5620: return rule_5620(inflow_m3d, storage_m3, month);
        case 2800: return rule_2800(inflow_m3d, storage_m3, month);
        case 2838: return rule_2838(inflow_m3d, storage_m3, month);
        case 2867: return rule_2867(inflow_m3d, storage_m3, month);
        case 2870: return rule_2870(inflow_m3d, storage_m3, month);
        case 807: return rule_807(inflow_m3d, storage_m3, month);
        case 20: return rule_20(inflow_m3d, storage_m3, month);
        case 116: return rule_116(inflow_m3d, storage_m3, month);
        case 6853: return rule_6853(inflow_m3d, storage_m3, month);
        case 2229: return rule_2229(inflow_m3d, storage_m3, month);
        case 2232: return rule_2232(inflow_m3d, storage_m3, month);
        case 2236: return rule_2236(inflow_m3d, storage_m3, month);
        case 536: return rule_536(inflow_m3d, storage_m3, month);
        case 539: return rule_539(inflow_m3d, storage_m3, month);
        case 544: return rule_544(inflow_m3d, storage_m3, month);
        case 555: return rule_555(inflow_m3d, storage_m3, month);
        case 585: return rule_585(inflow_m3d, storage_m3, month);
        case 2345: return rule_2345(inflow_m3d, storage_m3, month);
        case 621: return rule_621(inflow_m3d, storage_m3, month);
        case 640: return rule_640(inflow_m3d, storage_m3, month);
        case 21: return rule_21(inflow_m3d, storage_m3, month);
        case 2429: return rule_2429(inflow_m3d, storage_m3, month);
        case 126: return rule_126(inflow_m3d, storage_m3, month);
        case 2432: return rule_2432(inflow_m3d, storage_m3, month);
        case 698: return rule_698(inflow_m3d, storage_m3, month);
        case 713: return rule_713(inflow_m3d, storage_m3, month);
        case 720: return rule_720(inflow_m3d, storage_m3, month);
        case 2560: return rule_2560(inflow_m3d, storage_m3, month);
        case 740: return rule_740(inflow_m3d, storage_m3, month);
        case 747: return rule_747(inflow_m3d, storage_m3, month);
        case 136: return rule_136(inflow_m3d, storage_m3, month);
        case 2646: return rule_2646(inflow_m3d, storage_m3, month);
        case 2650: return rule_2650(inflow_m3d, storage_m3, month);
        case 756: return rule_756(inflow_m3d, storage_m3, month);
        case 2682: return rule_2682(inflow_m3d, storage_m3, month);
        case 775: return rule_775(inflow_m3d, storage_m3, month);
        case 2785: return rule_2785(inflow_m3d, storage_m3, month);
        case 2789: return rule_2789(inflow_m3d, storage_m3, month);
        case 2794: return rule_2794(inflow_m3d, storage_m3, month);
        case 786: return rule_786(inflow_m3d, storage_m3, month);
        case 790: return rule_790(inflow_m3d, storage_m3, month);
        case 795: return rule_795(inflow_m3d, storage_m3, month);
        case 796: return rule_796(inflow_m3d, storage_m3, month);
        case 800: return rule_800(inflow_m3d, storage_m3, month);
        case 801: return rule_801(inflow_m3d, storage_m3, month);
        case 803: return rule_803(inflow_m3d, storage_m3, month);
        case 2863: return rule_2863(inflow_m3d, storage_m3, month);
        case 2873: return rule_2873(inflow_m3d, storage_m3, month);
        case 806: return rule_806(inflow_m3d, storage_m3, month);
        case 2893: return rule_2893(inflow_m3d, storage_m3, month);
        case 811: return rule_811(inflow_m3d, storage_m3, month);
        case 813: return rule_813(inflow_m3d, storage_m3, month);
        case 814: return rule_814(inflow_m3d, storage_m3, month);
        case 818: return rule_818(inflow_m3d, storage_m3, month);
        case 821: return rule_821(inflow_m3d, storage_m3, month);
        case 142: return rule_142(inflow_m3d, storage_m3, month);
        case 822: return rule_822(inflow_m3d, storage_m3, month);
        case 143: return rule_143(inflow_m3d, storage_m3, month);
        case 828: return rule_828(inflow_m3d, storage_m3, month);
        case 833: return rule_833(inflow_m3d, storage_m3, month);
        case 834: return rule_834(inflow_m3d, storage_m3, month);
        case 2956: return rule_2956(inflow_m3d, storage_m3, month);
        case 838: return rule_838(inflow_m3d, storage_m3, month);
        case 2963: return rule_2963(inflow_m3d, storage_m3, month);
        case 2995: return rule_2995(inflow_m3d, storage_m3, month);
        case 3009: return rule_3009(inflow_m3d, storage_m3, month);
        case 3010: return rule_3010(inflow_m3d, storage_m3, month);
        case 852: return rule_852(inflow_m3d, storage_m3, month);
        case 854: return rule_854(inflow_m3d, storage_m3, month);
        case 857: return rule_857(inflow_m3d, storage_m3, month);
        case 858: return rule_858(inflow_m3d, storage_m3, month);
        case 148: return rule_148(inflow_m3d, storage_m3, month);
        case 3029: return rule_3029(inflow_m3d, storage_m3, month);
        case 150: return rule_150(inflow_m3d, storage_m3, month);
        case 151: return rule_151(inflow_m3d, storage_m3, month);
        case 867: return rule_867(inflow_m3d, storage_m3, month);
        case 3035: return rule_3035(inflow_m3d, storage_m3, month);
        case 152: return rule_152(inflow_m3d, storage_m3, month);
        case 869: return rule_869(inflow_m3d, storage_m3, month);
        case 874: return rule_874(inflow_m3d, storage_m3, month);
        case 876: return rule_876(inflow_m3d, storage_m3, month);
        case 880: return rule_880(inflow_m3d, storage_m3, month);
        case 883: return rule_883(inflow_m3d, storage_m3, month);
        case 5663: return rule_5663(inflow_m3d, storage_m3, month);
        case 887: return rule_887(inflow_m3d, storage_m3, month);
        case 897: return rule_897(inflow_m3d, storage_m3, month);
        case 155: return rule_155(inflow_m3d, storage_m3, month);
        case 3072: return rule_3072(inflow_m3d, storage_m3, month);
        case 157: return rule_157(inflow_m3d, storage_m3, month);
        case 158: return rule_158(inflow_m3d, storage_m3, month);
        case 905: return rule_905(inflow_m3d, storage_m3, month);
        case 912: return rule_912(inflow_m3d, storage_m3, month);
        case 3112: return rule_3112(inflow_m3d, storage_m3, month);
        case 919: return rule_919(inflow_m3d, storage_m3, month);
        case 920: return rule_920(inflow_m3d, storage_m3, month);
        case 162: return rule_162(inflow_m3d, storage_m3, month);
        case 938: return rule_938(inflow_m3d, storage_m3, month);
        case 939: return rule_939(inflow_m3d, storage_m3, month);
        case 3156: return rule_3156(inflow_m3d, storage_m3, month);
        case 945: return rule_945(inflow_m3d, storage_m3, month);
        case 3158: return rule_3158(inflow_m3d, storage_m3, month);
        case 944: return rule_944(inflow_m3d, storage_m3, month);
        case 946: return rule_946(inflow_m3d, storage_m3, month);
        case 3159: return rule_3159(inflow_m3d, storage_m3, month);
        case 948: return rule_948(inflow_m3d, storage_m3, month);
        case 950: return rule_950(inflow_m3d, storage_m3, month);
        case 168: return rule_168(inflow_m3d, storage_m3, month);
        case 954: return rule_954(inflow_m3d, storage_m3, month);
        case 956: return rule_956(inflow_m3d, storage_m3, month);
        case 958: return rule_958(inflow_m3d, storage_m3, month);
        case 962: return rule_962(inflow_m3d, storage_m3, month);
        case 986: return rule_986(inflow_m3d, storage_m3, month);
        case 989: return rule_989(inflow_m3d, storage_m3, month);
        case 2664: return rule_2664(inflow_m3d, storage_m3, month);
        case 2666: return rule_2666(inflow_m3d, storage_m3, month);
        case 758: return rule_758(inflow_m3d, storage_m3, month);
        case 2684: return rule_2684(inflow_m3d, storage_m3, month);
        case 2694: return rule_2694(inflow_m3d, storage_m3, month);
        case 2708: return rule_2708(inflow_m3d, storage_m3, month);
        case 2731: return rule_2731(inflow_m3d, storage_m3, month);
        case 2741: return rule_2741(inflow_m3d, storage_m3, month);
        case 2744: return rule_2744(inflow_m3d, storage_m3, month);
        case 2764: return rule_2764(inflow_m3d, storage_m3, month);
        case 2767: return rule_2767(inflow_m3d, storage_m3, month);
        case 777: return rule_777(inflow_m3d, storage_m3, month);
        case 2787: return rule_2787(inflow_m3d, storage_m3, month);
        case 2801: return rule_2801(inflow_m3d, storage_m3, month);
        case 2806: return rule_2806(inflow_m3d, storage_m3, month);
        case 788: return rule_788(inflow_m3d, storage_m3, month);
        case 794: return rule_794(inflow_m3d, storage_m3, month);
        case 2862: return rule_2862(inflow_m3d, storage_m3, month);
        case 2879: return rule_2879(inflow_m3d, storage_m3, month);
        case 2894: return rule_2894(inflow_m3d, storage_m3, month);
        case 2912: return rule_2912(inflow_m3d, storage_m3, month);
        case 2916: return rule_2916(inflow_m3d, storage_m3, month);
        case 2918: return rule_2918(inflow_m3d, storage_m3, month);
        case 2926: return rule_2926(inflow_m3d, storage_m3, month);
        case 2927: return rule_2927(inflow_m3d, storage_m3, month);
        case 827: return rule_827(inflow_m3d, storage_m3, month);
        case 829: return rule_829(inflow_m3d, storage_m3, month);
        case 831: return rule_831(inflow_m3d, storage_m3, month);
        case 2948: return rule_2948(inflow_m3d, storage_m3, month);
        case 2957: return rule_2957(inflow_m3d, storage_m3, month);
        case 2969: return rule_2969(inflow_m3d, storage_m3, month);
        case 2978: return rule_2978(inflow_m3d, storage_m3, month);
        case 2989: return rule_2989(inflow_m3d, storage_m3, month);
        case 843: return rule_843(inflow_m3d, storage_m3, month);
        case 845: return rule_845(inflow_m3d, storage_m3, month);
        case 2999: return rule_2999(inflow_m3d, storage_m3, month);
        case 3000: return rule_3000(inflow_m3d, storage_m3, month);
        case 144: return rule_144(inflow_m3d, storage_m3, month);
        case 145: return rule_145(inflow_m3d, storage_m3, month);
        case 851: return rule_851(inflow_m3d, storage_m3, month);
        case 853: return rule_853(inflow_m3d, storage_m3, month);
        case 147: return rule_147(inflow_m3d, storage_m3, month);
        case 862: return rule_862(inflow_m3d, storage_m3, month);
        case 863: return rule_863(inflow_m3d, storage_m3, month);
        case 866: return rule_866(inflow_m3d, storage_m3, month);
        case 870: return rule_870(inflow_m3d, storage_m3, month);
        case 873: return rule_873(inflow_m3d, storage_m3, month);
        case 877: return rule_877(inflow_m3d, storage_m3, month);
        case 878: return rule_878(inflow_m3d, storage_m3, month);
        case 879: return rule_879(inflow_m3d, storage_m3, month);
        case 884: return rule_884(inflow_m3d, storage_m3, month);
        case 886: return rule_886(inflow_m3d, storage_m3, month);
        case 3054: return rule_3054(inflow_m3d, storage_m3, month);
        case 154: return rule_154(inflow_m3d, storage_m3, month);
        case 899: return rule_899(inflow_m3d, storage_m3, month);
        case 900: return rule_900(inflow_m3d, storage_m3, month);
        case 3094: return rule_3094(inflow_m3d, storage_m3, month);
        case 911: return rule_911(inflow_m3d, storage_m3, month);
        case 159: return rule_159(inflow_m3d, storage_m3, month);
        case 3100: return rule_3100(inflow_m3d, storage_m3, month);
        case 160: return rule_160(inflow_m3d, storage_m3, month);
        case 915: return rule_915(inflow_m3d, storage_m3, month);
        case 916: return rule_916(inflow_m3d, storage_m3, month);
        case 3111: return rule_3111(inflow_m3d, storage_m3, month);
        case 3115: return rule_3115(inflow_m3d, storage_m3, month);
        case 161: return rule_161(inflow_m3d, storage_m3, month);
        case 928: return rule_928(inflow_m3d, storage_m3, month);
        case 3143: return rule_3143(inflow_m3d, storage_m3, month);
        case 163: return rule_163(inflow_m3d, storage_m3, month);
        case 3152: return rule_3152(inflow_m3d, storage_m3, month);
        case 169: return rule_169(inflow_m3d, storage_m3, month);
        case 923: return rule_923(inflow_m3d, storage_m3, month);
        case 844: return rule_844(inflow_m3d, storage_m3, month);
        case 119: return rule_119(inflow_m3d, storage_m3, month);
        case 909: return rule_909(inflow_m3d, storage_m3, month);
        case 872: return rule_872(inflow_m3d, storage_m3, month);

        default:
            throw std::runtime_error(
                "No operation rule defined for reservoir ID: " + std::to_string(res_id) +
                ". Register a rule in reservoir_operation_rules.cpp.");
    }
}
//------------------------------------------------------------------------------

ReservoirConstraints getReservoirConstraints(int res_id) {
    switch (res_id) {
        case 487: return {
            144389935.32f, 50146684.46264638f, 99.44437817276024f, 0.0f
        };
        case 488: return {
            97811263.56f, 58781489.4f, 18.583233707895015f, 0.0f
        };
        case 493: return {
            1608282765.84f, 914152528.6170145f, 149.99705058758352f, 6.4588002987083035f
        };
        case 5560: return {
            37793827.2f, 11558953.417661672f, 87.31395741334356f, 0.0f
        };
        case 104: return {
            23458275644.412f, 13709609124.197603f, 1866.0799950008977f, 31.14899991653692f
        };
        case 2194: return {
            59462370.36f, 27289511.53763013f, 51.819885246411744f, 0.0f
        };
        case 2197: return {
            122205797.52f, 18580402.67248479f, 299.3286456635426f, 0.5029079740117611f
        };
        case 606: return {
            1536031674.84f, 979000494.5040001f, 435.9040581785539f, 16.86638145465713f
        };
        case 624: return {
            281207536.92f, 80475415.11143999f, 43.551356844455746f, 0.6628980908509101f
        };
        case 642: return {
            103915756.08f, 17186759.657759577f, 24.323991942711157f, 0.0f
        };
        case 651: return {
            797626141.5600001f, 447377028.6f, 260.2592839422109f, 2.1693559478888f
        };
        case 5587: return {
            9821522.826f, 278179.34351999965f, 10.675462633523995f, 0.0f
        };
        case 694: return {
            1094259579.3600001f, 622013127.0f, 302.65191417933534f, 7.605913165423167f
        };
        case 704: return {
            186891955.68f, 76330958.82288635f, 87.5168161763003f, 0.311769206858418f
        };
        case 2483: return {
            46212328.2f, 27011391.83493119f, 34.83031758350826f, 0.0f
        };
        case 2525: return {
            234059490.792f, 192751580.65940177f, 251.19795993080334f, 0.7929998735066305f
        };
        case 721: return {
            1348532847.0f, 348331051.56f, 243.12870602503133f, 0.0f
        };
        case 727: return {
            1245053742.84f, 425818265.16f, 413.8794744073909f, 9.910906954199765f
        };
        case 2768: return {
            52198406.64f, 28022218.300817657f, 20.133197432034013f, 0.0570005589641853f
        };
        case 5620: return {
            14098676.4f, 8796198.105181927f, 47.494005645061534f, 0.0f
        };
        case 2800: return {
            70291091.28f, 26767034.75966709f, 94.86131443014668f, 0.0f
        };
        case 2838: return {
            99442787.556f, 73331843.3379583f, 77.21999070989324f, 0.3109999625844075f
        };
        case 2867: return {
            29290216.080000002f, 16766123.687172413f, 9.883092834116821f, 0.0f
        };
        case 2870: return {
            66792942.0f, 39610965.60361116f, 33.98003899818327f, 0.7080008125577651f
        };
        case 807: return {
            130334430.72f, 122080403.44267493f, 34.830185322889406f, 0.0f
        };
        case 20: return {
            29602227312.96f, 17222553074.126053f, 4264.516998867243f, 11.326999996991352f
        };
        case 116: return {
            537057.1919999999f, 262027.9037318435f, 29.764229635290075f, 0.0850092241188013f
        };
        case 6853: return {
            978026.292f, 609016.3720122699f, 37.69108922315364f, 0.11300326564649386f
        };
        case 2229: return {
            154594515.36f, 10405967.37822154f, 39.96595528322244f, 0.0f
        };
        case 2232: return {
            274555379.28000003f, 32648238.16265807f, 51.17574725342962f, 0.0f
        };
        case 2236: return {
            14209689.6f, 6079867.189866291f, 86.22329034972863f, 0.0f
        };
        case 536: return {
            174948662.232f, 59336885.44010071f, 32.338002760608134f, 0.028000002390284807f
        };
        case 539: return {
            139389530.748f, 105768536.63625064f, 65.69521279971728f, 0.5663380414013925f
        };
        case 544: return {
            177951692.64000002f, 65911003.800000004f, 109.73950834107491f, 0.0f
        };
        case 555: return {
            88014292.22683881f, 65652217.97982619f, 22.76712149096661f, 0.0850004535833514f
        };
        case 585: return {
            301460045.04f, 102491086.67999998f, 133.26743511280537f, 0.0f
        };
        case 2345: return {
            47215138.83219976f, 5711016.792771214f, 259.10028421599304f, 0.0f
        };
        case 621: return {
            194125082.4f, 52422900.00000002f, 843.8429349576f, 0.4247531551799527f
        };
        case 640: return {
            242738996.16f, 94521785.90248682f, 25.48512714942639f, 0.0f
        };
        case 21: return {
            28330568640.0f, 17199151581.448284f, 4539.200093495516f, 0.0f
        };
        case 2429: return {
            79246156.08f, 53322772.9992f, 14.557140134328868f, 0.0f
        };
        case 126: return {
            2247396489.516f, 2075942833.620379f, 2103.9420190508404f, 0.0f
        };
        case 2432: return {
            19706076.48f, 17500244.196000002f, 2.8274401696482f, 0.0f
        };
        case 698: return {
            163702531.68f, 94245549.83051413f, 407.6801258592341f, 0.0f
        };
        case 713: return {
            603170733.2160001f, 435417085.53355324f, 4550.516616977937f, 169.90098569924433f
        };
        case 720: return {
            884559345.0f, 219786400.6559383f, 232.4249297084097f, 0.0f
        };
        case 2560: return {
            12984843.96f, 195997.64467924513f, 14.169858286819952f, 0.0f
        };
        case 740: return {
            685013118.0f, 31417722.38399997f, 1115.6849542727996f, 1.7924583148593107f
        };
        case 747: return {
            2254427695.56f, 236728968.0319013f, 2944.952539432163f, 7.023013210230664f
        };
        case 136: return {
            2199541289.304f, 907100706.9057778f, 224.53638012264304f, 0.0f
        };
        case 2646: return {
            40414972.2f, 30945978.713378698f, 20.671027454641575f, 0.0f
        };
        case 2650: return {
            8260985.604f, 6187989.216505507f, 68.91101883937385f, 0.0f
        };
        case 756: return {
            724796548.44f, 246347846.52129787f, 526.6927336922972f, 0.39600055163577574f
        };
        case 2682: return {
            57585013.800000004f, 47958011.49293046f, 514.177159818031f, 0.0f
        };
        case 775: return {
            526963625.16f, 199815257.913582f, 42.47505522889336f, 0.0f
        };
        case 2785: return {
            92069414.16f, 34267154.145485654f, 39.07725456364409f, 0.0f
        };
        case 2789: return {
            24724983.252f, 14989989.846207486f, 10.506014064006784f, 0.0f
        };
        case 2794: return {
            57356943.348f, 9834990.285886291f, 3.758003864449692f, 0.02800002879313252f
        };
        case 786: return {
            1306241751.72f, 533631898.57151043f, 1469.6446835139056f, 0.20100036701883534f
        };
        case 790: return {
            1136408824.44f, 225987965.08787486f, 141.61526362337005f, 0.0f
        };
        case 795: return {
            178427815.92000002f, 20571978.7763481f, 28.31702787406526f, 0.0f
        };
        case 796: return {
            283348858.2f, 160892919.48223776f, 221.15433517940752f, 0.0030000045467783684f
        };
        case 800: return {
            2896058088.48f, 329516010.0673313f, 1684.853448194886f, 0.06500013302826235f
        };
        case 801: return {
            903419254.2f, 249633070.24061778f, 396.435910774848f, 0.0f
        };
        case 803: return {
            1660618088.76f, 434885823.2446376f, 942.9509514205113f, 0.09100018832329915f
        };
        case 2863: return {
            28090040.04f, 13296018.952361694f, 65.19437947941896f, 0.0f
        };
        case 2873: return {
            45751006.68f, 26171003.8211685f, 32.79107089560928f, 0.0f
        };
        case 806: return {
            333794465.6054459f, 145260602.62207615f, 179.52961236051584f, 0.006000020465568773f
        };
        case 2893: return {
            178147815.96f, 47033951.410415165f, 88.06508656446111f, 0.00900000884664908f
        };
        case 811: return {
            250601197.68f, 70298055.45272619f, 88.06524701016943f, 0.0f
        };
        case 813: return {
            477813024.25200003f, 59490878.51292704f, 190.288995038055f, 0.08199999786178135f
        };
        case 814: return {
            387017918.28000003f, 170260964.04888424f, 84.95015332483766f, 0.0f
        };
        case 818: return {
            177854247.72f, 82286314.610509f, 113.2673861121779f, 0.0f
        };
        case 821: return {
            363513956.88f, 141456719.88f, 320.4785209334707f, 0.8503558166703169f
        };
        case 142: return {
            6193533740.76f, 1463131938.7583344f, 2014.0359760618423f, 0.0f
        };
        case 822: return {
            803444466.72f, 59258034.4229265f, 659.782713409767f, 0.024000062326490768f
        };
        case 143: return {
            784428398.952f, 104973624.99720177f, 1489.463962761886f, 9.622999759414531f
        };
        case 828: return {
            562033928.52f, 28033299.959999997f, 94.01203167984f, 0.004813869092040002f
        };
        case 833: return {
            623677091.52f, 293455043.06235707f, 108.1702339478732f, 0.023000049743931626f
        };
        case 834: return {
            288101456.64f, 173424274.8209527f, 118.25142627580603f, 0.0f
        };
        case 2956: return {
            281073087.6f, 23080007.19317757f, 591.2273761968489f, 0.0f
        };
        case 838: return {
            1704767545.0080001f, 976025021.9246593f, 181.5389980706305f, 0.0f
        };
        case 2963: return {
            304446300.12f, 25915025.54676296f, 153.76046156127074f, 0.0f
        };
        case 2995: return {
            53214794.160000004f, 30531281.902031828f, 34.829935492980354f, 0.0f
        };
        case 3009: return {
            89629590.72f, 15997002.119999995f, 32.56440856379999f, 0.0f
        };
        case 3010: return {
            553225647.84f, 25877983.527172472f, 167.83423152334728f, 0.0f
        };
        case 852: return {
            935770967.64f, 86596463.39999993f, 724.9120515071992f, 0.41908977977760004f
        };
        case 854: return {
            336557484.96f, 41928860.417078964f, 1356.3796889670061f, 0.0f
        };
        case 857: return {
            226999791.36f, 34036968.71594854f, 351.78038587308214f, 0.0f
        };
        case 858: return {
            1669559584.568894f, 449723107.9928726f, 2974.40476092201f, 0.0f
        };
        case 148: return {
            4681920036.0f, 3038555023.3639135f, 2055.351159458921f, 0.0f
        };
        case 3029: return {
            33498849.84f, 14917933.129738797f, 31.20492303304885f, 0.0f
        };
        case 150: return {
            2672111160.12f, 1720328388.2033486f, 6268.223885474046f, 0.0f
        };
        case 151: return {
            2176492728.7200003f, 593190646.7213175f, 1823.9183639527882f, 0.0f
        };
        case 867: return {
            2493487220.88f, 1823895069.3212378f, 2450.25935874799f, 0.0f
        };
        case 3035: return {
            107781482.4f, 79322555.02573998f, 1084.5400405585501f, 0.18100117501366067f
        };
        case 152: return {
            6802358499.6f, 3639951372.77418f, 1661.6060484102034f, 1.41715802075f
        };
        case 869: return {
            651822638.16f, 288455711.99921227f, 101.17620412069084f, 0.0f
        };
        case 874: return {
            2501491272.6f, 1445437749.1707048f, 1629.4663772461604f, 1.1320406106326388f
        };
        case 876: return {
            547334547.36f, 255244016.35124794f, 6365.5490006491145f, 4.247531473793812f
        };
        case 880: return {
            2146698019.32f, 522133317.708423f, 7703.57807402848f, 0.0f
        };
        case 883: return {
            192038034.24f, 89035015.87476645f, 146.3983212462729f, 0.0010000021943351194f
        };
        case 5663: return {
            36934091.64f, 29278072.644065633f, 3060.011761497571f, 0.0f
        };
        case 887: return {
            1579337800.8119998f, 451419107.07089436f, 6294.105032522335f, 0.0f
        };
        case 897: return {
            1490460756.24f, 761376631.6028228f, 991.0906949711218f, 0.0f
        };
        case 155: return {
            3465172192.2000003f, 2195717749.6085258f, 300.838509237995f, 0.0f
        };
        case 3072: return {
            23226428.4f, 9757179.966365281f, 470.06861783968543f, 0.0010000204609201938f
        };
        case 157: return {
            726582627.48f, 599512692.6289457f, 10111.038200249188f, 0.0f
        };
        case 158: return {
            4770873679.68f, 2355405301.6399817f, 4857.816888900068f, 0.0f
        };
        case 905: return {
            630545108.16f, 582363099.8951417f, 12329.161970860774f, 0.0f
        };
        case 912: return {
            408855448.2f, 31563034.60037568f, 286.39689134198943f, 0.02800008714359041f
        };
        case 3112: return {
            533709527.28000003f, 36877967.336253434f, 381.0034306516811f, 0.0f
        };
        case 919: return {
            646146163.2f, 60713119.23354353f, 663.8325447817111f, 0.0f
        };
        case 920: return {
            192422880.0f, 36979976.93830779f, 236.16232883418493f, 0.0f
        };
        case 162: return {
            3303090453.2400002f, 2355754323.249425f, 379.64381746779145f, 0.0f
        };
        case 938: return {
            454205573.88f, 189718422.01272157f, 175.1681888083677f, 0.0f
        };
        case 939: return {
            1082519316.72f, 693921203.025221f, 255.75759044422952f, 0.0f
        };
        case 3156: return {
            243385339.68f, 39360346.74125675f, 87.0460793983242f, 0.3964364076834f
        };
        case 945: return {
            1695240638.88f, 1033904169.694448f, 846.2781950716978f, 0.0f
        };
        case 3158: return {
            123676105.68f, 33713968.75686238f, 27.92044054889566f, 0.05668488177f
        };
        case 944: return {
            1082519316.72f, 693921203.025221f, 255.75759044422952f, 0.0f
        };
        case 946: return {
            581157802.44f, 48129155.84950401f, 212.20667743377712f, 1.0760432672161857f
        };
        case 3159: return {
            186171603.36f, 40896029.405822024f, 56.37890257460216f, 0.11334058260111114f
        };
        case 948: return {
            1282169156.04f, 163571782.55879667f, 1679.1341730009112f, 0.0f
        };
        case 950: return {
            251649655.68f, 134036816.60393469f, 80.0800518745749f, 0.0f
        };
        case 168: return {
            7239669097.92f, 2805925037.9514837f, 1987.8430344429344f, 0.32300065554859797f
        };
        case 954: return {
            354625500.0f, 173648755.1660059f, 297.32618020862554f, 0.0f
        };
        case 956: return {
            1839842732.76f, 249722959.86299726f, 1685.5337812114262f, 4.219223605797084f
        };
        case 958: return {
            155640629.748f, 89870786.20724945f, 212.65892283608176f, 0.0f
        };
        case 962: return {
            577292076.12f, 217480532.87309816f, 723.2982155880886f, 0.0f
        };
        case 986: return {
            760632843.0329639f, 249475030.6496793f, 314.54666191222316f, 0.0f
        };
        case 989: return {
            405369633.72f, 166966319.76000005f, 622.9712942639999f, 0.04813869092040001f
        };
        case 2664: return {
            208682613.36f, 5687989.461487893f, 276.6550451696432f, 0.0f
        };
        case 2666: return {
            321478191.96f, 17054010.18323441f, 255.35166727173828f, 0.0940002456365685f
        };
        case 758: return {
            430488220.44f, 32243816.511083376f, 183.04346275243034f, 0.0f
        };
        case 2684: return {
            262282253.28f, 274000.2375097906f, 379.361131144095f, 0.0f
        };
        case 2694: return {
            43427130.36f, 13888041.689264283f, 55.94628072930252f, 0.0f
        };
        case 2708: return {
            46059376.68f, 21887178.996399403f, 25.99126495899649f, 0.0f
        };
        case 2731: return {
            59966863.68f, 32840925.34418731f, 21.942994355861998f, 0.0f
        };
        case 2741: return {
            47951535.0f, 26155946.358170666f, 22.797824884457615f, 0.0f
        };
        case 2744: return {
            68659970.39517769f, 34493185.12722026f, 20.22903206004774f, 0.016000025357692717f
        };
        case 2764: return {
            325789204.56f, 266821459.68f, 53.94365070785993f, 1.2459425885277897f
        };
        case 2767: return {
            744909673.32f, 99827956.22046815f, 290.9984590453314f, 0.0f
        };
        case 777: return {
            108253905.24f, 39287965.60929962f, 27.277031114498374f, 0.0f
        };
        case 2787: return {
            163944293.76f, 26090046.748880103f, 51.16619483356248f, 0.0f
        };
        case 2801: return {
            21333036.6f, 11222019.253044577f, 23.802088821732518f, 0.0f
        };
        case 2806: return {
            215783757.72f, 34071961.74431764f, 62.021055399947635f, 0.16200014470568927f
        };
        case 788: return {
            222443316.24f, 116054164.99020857f, 88.28730350485141f, 0.0f
        };
        case 794: return {
            643491714.24f, 216415299.48f, 144.41607276119942f, 0.1302576342552f
        };
        case 2862: return {
            261239962.68f, 101888985.44442855f, 137.16025692527052f, 0.0f
        };
        case 2879: return {
            48943252.92f, 5854030.251387936f, 71.94751684502556f, 0.23500168816739797f
        };
        case 2894: return {
            169830460.32f, 37796302.44566203f, 277.2223102898692f, 1.6710078980104808f
        };
        case 2912: return {
            85972322.52f, 2420009.0785185844f, 75.67443644966175f, 0.0f
        };
        case 2916: return {
            107480513.28f, 24023891.20903899f, 117.61070451404181f, 0.0f
        };
        case 2918: return {
            392307080.52f, 72497014.87982225f, 511.0341351497076f, 0.0f
        };
        case 2926: return {
            51732151.2f, 14962043.730271397f, 65.17432188124357f, 0.07900039016502391f
        };
        case 2927: return {
            100804919.52f, 32998973.65448619f, 86.7151055895611f, 0.0f
        };
        case 827: return {
            688618580.04f, 231928195.35869977f, 150.06542894027075f, 0.0f
        };
        case 829: return {
            505391293.44f, 225284130.80434158f, 402.10004411344175f, 0.8500022071585642f
        };
        case 831: return {
            361040829.48f, 100810952.38687097f, 126.50219528554365f, 0.0f
        };
        case 2948: return {
            78461662.8f, 49970785.243542105f, 47.47889167221135f, 0.061999858541188876f
        };
        case 2957: return {
            57169331.04f, 14126081.797320925f, 86.58467592658624f, 0.0f
        };
        case 2969: return {
            135066667.67951888f, 27966931.189654786f, 187.4739166902392f, 0.0f
        };
        case 2978: return {
            84176375.64f, 7638834.0885624355f, 221.20143306639943f, 0.31100201484470646f
        };
        case 2989: return {
            171895305.84f, 16386029.154392147f, 111.78142423862784f, 0.0f
        };
        case 843: return {
            744909673.32f, 99827956.22046815f, 290.9984590453314f, 0.0f
        };
        case 845: return {
            700255230.36f, 240890079.24459007f, 223.1315232429207f, 0.0f
        };
        case 2999: return {
            114056195.16f, 62809107.458975166f, 113.10942157188538f, 0.24400090941948746f
        };
        case 3000: return {
            48056380.8f, 20447162.02383885f, 32.67832482393586f, 0.0f
        };
        case 144: return {
            2288033858.16f, 806878949.9798875f, 7470.354597376825f, 36.585071488716316f
        };
        case 145: return {
            3668196832.8f, 1179852238.9006026f, 11835.370229526952f, 0.0f
        };
        case 851: return {
            564300818.064f, 467343021.1492479f, 385.2499697666644f, 0.0f
        };
        case 853: return {
            841633007.52f, 140082401.2516377f, 148.0612998193412f, 0.0f
        };
        case 147: return {
            7239797379.84f, 3101029162.6972227f, 1682.5874804290095f, 0.5660011707723476f
        };
        case 862: return {
            1998869018.412f, 1308326393.9179497f, 289.3410069778209f, 0.42500001024940837f
        };
        case 863: return {
            447970332.48f, 293009217.46909904f, 127.34135123586427f, 0.0f
        };
        case 866: return {
            119285780.316f, 70965069.30638134f, 459.1850800704477f, 0.0f
        };
        case 870: return {
            386778623.16f, 269373337.54845166f, 90.75509454235102f, 0.0f
        };
        case 873: return {
            699718666.5600001f, 506684758.54729354f, 4969.860651096662f, 29.733045774001027f
        };
        case 877: return {
            1497120931.5f, 737768487.8692447f, 753.3119747159537f, 0.0f
        };
        case 878: return {
            948347036.328f, 395104181.8870208f, 570.5549688538927f, 0.0f
        };
        case 879: return {
            821533450.92f, 391181738.54981947f, 443.86659818752565f, 0.0f
        };
        case 884: return {
            915450124.7279999f, 228715131.48394382f, 1416.4629540597264f, 0.0f
        };
        case 886: return {
            77154174.0f, 68206735.24780765f, 982.9725138958667f, 0.0f
        };
        case 3054: return {
            35018990.592f, 16244995.63571319f, 4783.848359195977f, 0.0f
        };
        case 154: return {
            800919533.16f, 532587089.5656224f, 5901.22945736941f, 25.485036523976298f
        };
        case 899: return {
            78049803.828f, 50009674.30509057f, 444.6017787756252f, 0.0f
        };
        case 900: return {
            897690973.08f, 587370982.3858906f, 737.9654656323739f, 0.0f
        };
        case 3094: return {
            36263941.956f, 33488946.397652876f, 409.51817012928024f, 0.0f
        };
        case 911: return {
            270748489.95600003f, 135076745.53843826f, 336.5170444898823f, 0.0f
        };
        case 159: return {
            546752344.8f, 278508375.63653606f, 6320.32672778279f, 0.0f
        };
        case 3100: return {
            55205877.576f, 42207906.40017039f, 822.7158341792863f, 0.0f
        };
        case 160: return {
            750077461.128f, 474181027.1619353f, 12428.83755777385f, 0.0f
        };
        case 915: return {
            149386639.452f, 100651757.0747301f, 83.61996676232745f, 0.0f
        };
        case 916: return {
            244354484.916f, 147486689.10726646f, 7331.247326253439f, 0.0f
        };
        case 3111: return {
            107213834.904f, 56628912.798502214f, 66.20503152417854f, 0.0f
        };
        case 3115: return {
            120870802.116f, 69715885.86442618f, 133.65505063961598f, 0.0f
        };
        case 161: return {
            976918626.96f, 514603403.49678236f, 10889.157794840761f, 12.884021054805197f
        };
        case 928: return {
            75007918.8f, 32535964.77811435f, 211.81019772110594f, 0.0f
        };
        case 3143: return {
            30688982.400000002f, 18024189.663204405f, 69.65910048590565f, 0.0f
        };
        case 163: return {
            935887161.456f, 584542051.6710922f, 8508.660438565063f, 0.0f
        };
        case 3152: return {
            27173564.400000002f, 19119693.505851183f, 263.17231184513935f, 0.0f
        };
        case 169: return {
            2205583121.04f, 218479011.9898902f, 325.6436743792135f, 0.0f
        };
        case 923: return {
            398834163.288f, 377962207.0751623f, 12058.170012946826f, 10.250999160877205f
        };
        case 844: return {
            440923461.24f, 41250043.150731504f, 753.399306989885f, 0.0f
        };
        case 119: return {
            2515047957.888f, 1807192376.9810667f, 728.3080082000314f, 59.46500066951718f
        };
        case 909: return {
            374176158.0f, 264002111.47779655f, 735.2187926786911f, 0.0f
        };
        case 872: return {
            376639294.212f, 269337495.2786264f, 2412.9593429461906f, 0.0f
        };
        default:
            throw std::runtime_error(
                "No constraints defined for reservoir ID: " + std::to_string(res_id));
    }
}

#include "reservoir_operation_rules.hpp"

#include <stdexcept>
#include <string>

// ---- Per-reservoir rule functions ---- 
// rule_{GDW_ID} - Define the operation rule for reservoir with GDW ID {GDW_ID}
// default as run-of-river (i.e., outflow = inflow) if no rule is defined for a reservoir

static float rule_21(float inflow_m3d, float storage_m3, int month) {
    const float max_inflow_m3d   = 513780883.0f;
    const float max_outflow_m3d  = 392186888.0f;
    const float max_storage_m3   = 28330568640.0f;
    const float norm_inflow  = inflow_m3d  / max_inflow_m3d;
    const float norm_storage = storage_m3  / max_storage_m3;
    float norm_outflow;

    switch (month) {
        case  1: norm_outflow = (norm_storage <= 1.0000f) ? 0.1837f * norm_storage + -0.0040f : 0.0000f * norm_storage + (0.1837f * 1.0000f + -0.0040f - 0.0000f * 1.0000f); break;
        case  2: norm_outflow = 0.4413f * norm_inflow + 0.0756f; break;
        case  3: norm_outflow = (norm_storage <= 0.9199f) ? 0.0729f * norm_storage + 0.0504f : 4.6247f * norm_storage + (0.0729f * 0.9199f + 0.0504f - 4.6247f * 0.9199f); break;
        case  4: norm_outflow = (norm_storage <= 0.9414f) ? 0.0172f * norm_storage + 0.1072f : 6.9812f * norm_storage + (0.0172f * 0.9414f + 0.1072f - 6.9812f * 0.9414f); break;
        case  5: norm_outflow = 0.3402f * norm_inflow + 0.0830f; break;
        case  6: norm_outflow = (norm_storage <= 0.9776f) ? 0.0994f * norm_storage + 0.0642f : 43.6202f * norm_storage + (0.0994f * 0.9776f + 0.0642f - 43.6202f * 0.9776f); break;
        case  7: norm_outflow = (norm_storage <= 0.9756f) ? 0.1000f * norm_storage + 0.0894f : 33.7317f * norm_storage + (0.1000f * 0.9756f + 0.0894f - 33.7317f * 0.9756f); break;
        case  8: norm_outflow = (norm_storage <= 0.8737f) ? 0.0000f * norm_storage + 0.1626f : 1.9730f * norm_storage + (0.0000f * 0.8737f + 0.1626f - 1.9730f * 0.8737f); break;
        case  9: norm_outflow = (norm_storage <= 0.8434f) ? 0.1000f * norm_storage + 0.0762f : 1.3086f * norm_storage + (0.1000f * 0.8434f + 0.0762f - 1.3086f * 0.8434f); break;
        case 10: norm_outflow = (norm_storage <= 0.8316f) ? 0.1000f * norm_storage + 0.0353f : 2.0565f * norm_storage + (0.1000f * 0.8316f + 0.0353f - 2.0565f * 0.8316f); break;
        case 11: norm_outflow = (norm_storage <= 0.8013f) ? 0.1000f * norm_storage + 0.0286f : 2.0427f * norm_storage + (0.1000f * 0.8013f + 0.0286f - 2.0427f * 0.8013f); break;
        case 12: norm_outflow = (norm_storage <= 0.7551f) ? 0.0474f * norm_storage + 0.0684f : 0.7217f * norm_storage + (0.0474f * 0.7551f + 0.0684f - 0.7217f * 0.7551f); break;
    }
    return norm_outflow * max_outflow_m3d;
}

static float rule_104(float inflow_m3d, float storage_m3, int month) {
    const float max_inflow_m3d   = 383733958.0f;
    const float max_outflow_m3d  = 161229551.0f;
    const float max_storage_m3   = 23458310589.0f;
    const float norm_inflow  = inflow_m3d  / max_inflow_m3d;
    const float norm_storage = storage_m3  / max_storage_m3;
    float norm_outflow;

    switch (month) {
        case  1: norm_outflow = (norm_storage <= 1.0000f) ? 0.1621f * norm_storage + 0.0338f : 0.0000f * norm_storage + (0.1621f * 1.0000f + 0.0338f - 0.0000f * 1.0000f); break;
        case  2: norm_outflow = (norm_storage <= 0.7788f) ? 0.1000f * norm_storage + 0.0684f : 0.8275f * norm_storage + (0.1000f * 0.7788f + 0.0684f - 0.8275f * 0.7788f); break;
        case  3: norm_outflow = 0.1983f * norm_inflow + 0.0856f; break;
        case  4: norm_outflow = 0.1698f * norm_inflow + 0.0840f; break;
        case  5: norm_outflow = (norm_storage <= 0.8418f) ? 0.0843f * norm_storage + 0.0656f : 0.9460f * norm_storage + (0.0843f * 0.8418f + 0.0656f - 0.9460f * 0.8418f); break;
        case  6: norm_outflow = (norm_storage <= 0.9586f) ? 0.1000f * norm_storage + 0.0618f : 22.3520f * norm_storage + (0.1000f * 0.9586f + 0.0618f - 22.3520f * 0.9586f); break;
        case  7: norm_outflow = (norm_storage <= 0.8797f) ? 0.1000f * norm_storage + 0.0513f : 2.1621f * norm_storage + (0.1000f * 0.8797f + 0.0513f - 2.1621f * 0.8797f); break;
        case  8: norm_outflow = (norm_storage <= 0.8161f) ? 0.0589f * norm_storage + 0.0759f : 1.0664f * norm_storage + (0.0589f * 0.8161f + 0.0759f - 1.0664f * 0.8161f); break;
        case  9: norm_outflow = (norm_storage <= 0.8023f) ? 0.0401f * norm_storage + 0.0674f : 1.3136f * norm_storage + (0.0401f * 0.8023f + 0.0674f - 1.3136f * 0.8023f); break;
        case 10: norm_outflow = (norm_storage <= 0.8354f) ? 0.0842f * norm_storage + 0.0286f : 2.3910f * norm_storage + (0.0842f * 0.8354f + 0.0286f - 2.3910f * 0.8354f); break;
        case 11: norm_outflow = (norm_storage <= 0.7880f) ? 0.0582f * norm_storage + 0.0501f : 1.1140f * norm_storage + (0.0582f * 0.7880f + 0.0501f - 1.1140f * 0.7880f); break;
        case 12: norm_outflow = (norm_storage <= 1.0000f) ? 0.1250f * norm_storage + 0.0453f : 0.0000f * norm_storage + (0.1250f * 1.0000f + 0.0453f - 0.0000f * 1.0000f); break;
    }
    return norm_outflow * max_outflow_m3d;
}

static float rule_487(float inflow_m3d, float storage_m3, int month) {
    const float max_inflow_m3d   = 29122946.4f;
    const float max_outflow_m3d  = 8591994.3f;
    const float max_storage_m3   = 144389935.3f;
    const float norm_inflow  = inflow_m3d  / max_inflow_m3d;
    const float norm_storage = storage_m3  / max_storage_m3;
    float norm_outflow;

    switch (month) {
        case  1: norm_outflow = (norm_storage <= 1.0000f) ? 0.0205f * norm_storage + 0.0050f : 0.0000f * norm_storage + (0.0205f * 1.0000f + 0.0050f - 0.0000f * 1.0000f); break;
        case  2: norm_outflow = (norm_storage <= 0.8007f) ? 0.0226f * norm_storage + 0.0044f : 2.1173f * norm_storage + (0.0226f * 0.8007f + 0.0044f - 2.1173f * 0.8007f); break;
        case  3: norm_outflow = (norm_storage <= 0.6982f) ? 0.0495f * norm_storage + 0.0000f : 1.3737f * norm_storage + (0.0495f * 0.6982f + 0.0000f - 1.3737f * 0.6982f); break;
        case  4: norm_outflow = 1.3922f * norm_inflow + 0.0214f; break;
        case  5: norm_outflow = 1.4587f * norm_inflow + 0.1187f; break;
        case  6: norm_outflow = (norm_storage <= 0.8061f) ? 0.0269f * norm_storage + 0.1635f : 2.6602f * norm_storage + (0.0269f * 0.8061f + 0.1635f - 2.6602f * 0.8061f); break;
        case  7: norm_outflow = 0.1031f * norm_inflow + 0.2278f; break;
        case  8: norm_outflow = (norm_storage <= 1.0000f) ? 0.1724f * norm_storage + 0.1269f : 0.0000f * norm_storage + (0.1724f * 1.0000f + 0.1269f - 0.0000f * 1.0000f); break;
        case  9: norm_outflow = 2.0999f * norm_inflow + 0.0341f; break;
        case 10: norm_outflow = (norm_storage <= 0.6000f) ? 0.0120f * norm_storage + 0.0177f : 0.8616f * norm_storage + (0.0120f * 0.6000f + 0.0177f - 0.8616f * 0.6000f); break;
        case 11: norm_outflow = (norm_storage <= 1.0000f) ? 0.0286f * norm_storage + 0.0020f : 0.0000f * norm_storage + (0.0286f * 1.0000f + 0.0020f - 0.0000f * 1.0000f); break;
        case 12: norm_outflow = (norm_storage <= 1.0000f) ? 0.0263f * norm_storage + 0.0027f : 0.0000f * norm_storage + (0.0263f * 1.0000f + 0.0027f - 0.0000f * 1.0000f); break;
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
        case  4: norm_outflow = (norm_storage <= 0.9613f) ? 0.0196f * norm_storage + 0.0028f : 9.4384f * norm_storage + (0.0196f * 0.9613f + 0.0028f - 9.4384f * 0.9613f); break;
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
        case  1: norm_outflow = (norm_storage <= 1.0000f) ? 0.5636f * norm_storage + -0.2279f : 0.0000f * norm_storage + (0.5636f * 1.0000f + -0.2279f - 0.0000f * 1.0000f); break;
        case  2: norm_outflow = 0.5912f * norm_inflow + 0.0910f; break;
        case  3: norm_outflow = (norm_storage <= 0.6450f) ? 0.1000f * norm_storage + 0.0458f : 6.3762f * norm_storage + (0.1000f * 0.6450f + 0.0458f - 6.3762f * 0.6450f); break;
        case  4: norm_outflow = (norm_storage <= 0.6000f) ? 0.1000f * norm_storage + 0.0440f : 2.7498f * norm_storage + (0.1000f * 0.6000f + 0.0440f - 2.7498f * 0.6000f); break;
        case  5: norm_outflow = 0.7506f * norm_inflow + 0.0828f; break;
        case  6: norm_outflow = 0.8461f * norm_inflow + 0.1213f; break;
        case  7: norm_outflow = 2.4596f * norm_inflow + 0.1134f; break;
        case  8: norm_outflow = (norm_storage <= 1.0000f) ? 1.3188f * norm_storage + -0.7242f : 0.0000f * norm_storage + (1.3188f * 1.0000f + -0.7242f - 0.0000f * 1.0000f); break;
        case  9: norm_outflow = (norm_storage <= 0.6335f) ? 0.1000f * norm_storage + 0.0343f : 2.1220f * norm_storage + (0.1000f * 0.6335f + 0.0343f - 2.1220f * 0.6335f); break;
        case 10: norm_outflow = (norm_storage <= 0.6465f) ? 0.1000f * norm_storage + 0.0466f : 4.3764f * norm_storage + (0.1000f * 0.6465f + 0.0466f - 4.3764f * 0.6465f); break;
        case 11: norm_outflow = (norm_storage <= 1.0000f) ? 0.6919f * norm_storage + -0.3146f : 0.0000f * norm_storage + (0.6919f * 1.0000f + -0.3146f - 0.0000f * 1.0000f); break;
        case 12: norm_outflow = (norm_storage <= 1.0000f) ? 0.4957f * norm_storage + -0.1968f : 0.0000f * norm_storage + (0.4957f * 1.0000f + -0.1968f - 0.0000f * 1.0000f); break;
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
        case  5: norm_outflow = (norm_storage <= 1.0000f) ? 1.4096f * norm_storage + -0.9716f : 0.0000f * norm_storage + (1.4096f * 1.0000f + -0.9716f - 0.0000f * 1.0000f); break;
        case  6: norm_outflow = 3.4960f * norm_inflow + -0.0226f; break;
        case  7: norm_outflow = 2.7489f * norm_inflow + 0.0996f; break;
        case  8: norm_outflow = 1.3966f * norm_inflow + 0.2177f; break;
        case  9: norm_outflow = 2.6713f * norm_inflow + 0.0735f; break;
        case 10: norm_outflow = (norm_storage <= 0.7782f) ? 0.0012f * norm_storage + 0.0000f : 10.7770f * norm_storage + (0.0012f * 0.7782f + 0.0000f - 10.7770f * 0.7782f); break;
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
        case  8: norm_outflow = (norm_storage <= 1.0000f) ? 0.1111f * norm_storage + 0.0396f : 0.0000f * norm_storage + (0.1111f * 1.0000f + 0.0396f - 0.0000f * 1.0000f); break;
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
        case  1: norm_outflow = (norm_storage <= 1.0000f) ? 0.4071f * norm_storage + -0.1263f : 0.0000f * norm_storage + (0.4071f * 1.0000f + -0.1263f - 0.0000f * 1.0000f); break;
        case  2: norm_outflow = 0.9846f * norm_inflow + 0.0677f; break;
        case  3: norm_outflow = 1.1798f * norm_inflow + 0.0392f; break;
        case  4: norm_outflow = 1.4069f * norm_inflow + 0.0139f; break;
        case  5: norm_outflow = 0.8109f * norm_inflow + 0.0503f; break;
        case  6: norm_outflow = 0.9970f * norm_inflow + -0.0072f; break;
        case  7: norm_outflow = 0.9959f * norm_inflow + 0.0979f; break;
        case  8: norm_outflow = 1.4141f * norm_inflow + 0.0379f; break;
        case  9: norm_outflow = (norm_storage <= 0.7385f) ? 0.1000f * norm_storage + 0.0611f : 0.8949f * norm_storage + (0.1000f * 0.7385f + 0.0611f - 0.8949f * 0.7385f); break;
        case 10: norm_outflow = (norm_storage <= 1.0000f) ? 0.4853f * norm_storage + -0.2025f : 0.0000f * norm_storage + (0.4853f * 1.0000f + -0.2025f - 0.0000f * 1.0000f); break;
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
        case  1: norm_outflow = (norm_storage <= 0.6000f) ? 0.0634f * norm_storage + 0.0002f : 1.3753f * norm_storage + (0.0634f * 0.6000f + 0.0002f - 1.3753f * 0.6000f); break;
        case  2: norm_outflow = (norm_storage <= 0.6000f) ? 0.0586f * norm_storage + 0.0000f : 1.1693f * norm_storage + (0.0586f * 0.6000f + 0.0000f - 1.1693f * 0.6000f); break;
        case  3: norm_outflow = 1.0342f * norm_inflow + -0.0278f; break;
        case  4: norm_outflow = 1.4504f * norm_inflow + -0.0539f; break;
        case  5: norm_outflow = (norm_storage <= 1.0000f) ? 0.3995f * norm_storage + 0.0043f : 0.0000f * norm_storage + (0.3995f * 1.0000f + 0.0043f - 0.0000f * 1.0000f); break;
        case  6: norm_outflow = (norm_storage <= 1.0000f) ? 0.2020f * norm_storage + 0.2403f : 0.0000f * norm_storage + (0.2020f * 1.0000f + 0.2403f - 0.0000f * 1.0000f); break;
        case  7: norm_outflow = 0.8431f * norm_inflow + 0.3392f; break;
        case  8: norm_outflow = 2.3168f * norm_inflow + 0.1126f; break;
        case  9: norm_outflow = (norm_storage <= 1.0000f) ? 0.5933f * norm_storage + -0.0370f : 0.0000f * norm_storage + (0.5933f * 1.0000f + -0.0370f - 0.0000f * 1.0000f); break;
        case 10: norm_outflow = (norm_storage <= 0.6000f) ? 0.1000f * norm_storage + 0.0156f : 3.2485f * norm_storage + (0.1000f * 0.6000f + 0.0156f - 3.2485f * 0.6000f); break;
        case 11: norm_outflow = (norm_storage <= 0.6058f) ? 0.0793f * norm_storage + 0.0012f : 3.0137f * norm_storage + (0.0793f * 0.6058f + 0.0012f - 3.0137f * 0.6058f); break;
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
        case  7: norm_outflow = (norm_storage <= 1.0000f) ? 0.3515f * norm_storage + 0.1771f : 0.0000f * norm_storage + (0.3515f * 1.0000f + 0.1771f - 0.0000f * 1.0000f); break;
        case  8: norm_outflow = (norm_storage <= 1.0000f) ? 0.5073f * norm_storage + 0.0428f : 0.0000f * norm_storage + (0.5073f * 1.0000f + 0.0428f - 0.0000f * 1.0000f); break;
        case  9: norm_outflow = (norm_storage <= 1.0000f) ? 0.6039f * norm_storage + -0.0398f : 0.0000f * norm_storage + (0.6039f * 1.0000f + -0.0398f - 0.0000f * 1.0000f); break;
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
        case  1: norm_outflow = (norm_storage <= 1.0000f) ? 0.0467f * norm_storage + 0.0003f : 0.0000f * norm_storage + (0.0467f * 1.0000f + 0.0003f - 0.0000f * 1.0000f); break;
        case  2: norm_outflow = (norm_storage <= 1.0000f) ? 0.0694f * norm_storage + -0.0110f : 0.0000f * norm_storage + (0.0694f * 1.0000f + -0.0110f - 0.0000f * 1.0000f); break;
        case  3: norm_outflow = 1.4531f * norm_inflow + 0.0147f; break;
        case  4: norm_outflow = 1.1546f * norm_inflow + 0.0693f; break;
        case  5: norm_outflow = 0.4620f * norm_inflow + 0.1611f; break;
        case  6: norm_outflow = 0.7218f * norm_inflow + 0.1172f; break;
        case  7: norm_outflow = 1.0415f * norm_inflow + 0.1347f; break;
        case  8: norm_outflow = 0.4916f * norm_inflow + 0.1799f; break;
        case  9: norm_outflow = (norm_storage <= 1.0000f) ? 0.0798f * norm_storage + 0.1028f : 0.0000f * norm_storage + (0.0798f * 1.0000f + 0.1028f - 0.0000f * 1.0000f); break;
        case 10: norm_outflow = (norm_storage <= 1.0000f) ? 0.1059f * norm_storage + 0.0062f : 0.0000f * norm_storage + (0.1059f * 1.0000f + 0.0062f - 0.0000f * 1.0000f); break;
        case 11: norm_outflow = (norm_storage <= 1.0000f) ? 0.0677f * norm_storage + -0.0065f : 0.0000f * norm_storage + (0.0677f * 1.0000f + -0.0065f - 0.0000f * 1.0000f); break;
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
        case  7: norm_outflow = (norm_storage <= 1.0000f) ? 0.1410f * norm_storage + 0.0880f : 0.0000f * norm_storage + (0.1410f * 1.0000f + 0.0880f - 0.0000f * 1.0000f); break;
        case  8: norm_outflow = (norm_storage <= 1.0000f) ? 0.2689f * norm_storage + 0.0410f : 0.0000f * norm_storage + (0.2689f * 1.0000f + 0.0410f - 0.0000f * 1.0000f); break;
        case  9: norm_outflow = (norm_storage <= 1.0000f) ? 0.3536f * norm_storage + 0.0173f : 0.0000f * norm_storage + (0.3536f * 1.0000f + 0.0173f - 0.0000f * 1.0000f); break;
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
        case  1: norm_outflow = (norm_storage <= 1.0000f) ? 0.1744f * norm_storage + -0.0380f : 0.0000f * norm_storage + (0.1744f * 1.0000f + -0.0380f - 0.0000f * 1.0000f); break;
        case  2: norm_outflow = (norm_storage <= 1.0000f) ? 0.1655f * norm_storage + -0.0323f : 0.0000f * norm_storage + (0.1655f * 1.0000f + -0.0323f - 0.0000f * 1.0000f); break;
        case  3: norm_outflow = 1.1266f * norm_inflow + 0.0379f; break;
        case  4: norm_outflow = 1.6534f * norm_inflow + 0.0405f; break;
        case  5: norm_outflow = 0.7181f * norm_inflow + 0.1005f; break;
        case  6: norm_outflow = 0.8158f * norm_inflow + 0.1057f; break;
        case  7: norm_outflow = (norm_storage <= 0.7743f) ? 0.0687f * norm_storage + 0.0699f : 2.7966f * norm_storage + (0.0687f * 0.7743f + 0.0699f - 2.7966f * 0.7743f); break;
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
        case  2: norm_outflow = (norm_storage <= 0.6918f) ? 0.0105f * norm_storage + 0.0040f : 0.9946f * norm_storage + (0.0105f * 0.6918f + 0.0040f - 0.9946f * 0.6918f); break;
        case  3: norm_outflow = (norm_storage <= 0.6928f) ? 0.0094f * norm_storage + 0.0046f : 0.9948f * norm_storage + (0.0094f * 0.6928f + 0.0046f - 0.9948f * 0.6928f); break;
        case  4: norm_outflow = 0.0626f * norm_inflow + 0.0182f; break;
        case  5: norm_outflow = 0.0941f * norm_inflow + 0.0676f; break;
        case  6: norm_outflow = 0.5265f * norm_inflow + 0.0058f; break;
        case  7: norm_outflow = 0.5825f * norm_inflow + 0.1054f; break;
        case  8: norm_outflow = 0.0000f * norm_inflow + 0.2512f; break;
        case  9: norm_outflow = (norm_storage <= 1.0000f) ? 0.2876f * norm_storage + 0.0338f : 0.0000f * norm_storage + (0.2876f * 1.0000f + 0.0338f - 0.0000f * 1.0000f); break;
        case 10: norm_outflow = (norm_storage <= 0.6653f) ? 0.0000f * norm_storage + 0.0220f : 1.8171f * norm_storage + (0.0000f * 0.6653f + 0.0220f - 1.8171f * 0.6653f); break;
        case 11: norm_outflow = (norm_storage <= 1.0000f) ? 0.0346f * norm_storage + -0.0044f : 0.0000f * norm_storage + (0.0346f * 1.0000f + -0.0044f - 0.0000f * 1.0000f); break;
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
        case  6: norm_outflow = (norm_storage <= 0.8657f) ? 0.0985f * norm_storage + 0.1831f : 4.5889f * norm_storage + (0.0985f * 0.8657f + 0.1831f - 4.5889f * 0.8657f); break;
        case  7: norm_outflow = (norm_storage <= 0.9514f) ? 0.1000f * norm_storage + 0.2565f : 27.7993f * norm_storage + (0.1000f * 0.9514f + 0.2565f - 27.7993f * 0.9514f); break;
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
        case  1: norm_outflow = (norm_storage <= 1.0000f) ? 0.0220f * norm_storage + 0.0320f : 0.0000f * norm_storage + (0.0220f * 1.0000f + 0.0320f - 0.0000f * 1.0000f); break;
        case  2: norm_outflow = (norm_storage <= 1.0000f) ? 0.0597f * norm_storage + 0.0188f : 0.0000f * norm_storage + (0.0597f * 1.0000f + 0.0188f - 0.0000f * 1.0000f); break;
        case  3: norm_outflow = (norm_storage <= 1.0000f) ? 0.1270f * norm_storage + -0.0011f : 0.0000f * norm_storage + (0.1270f * 1.0000f + -0.0011f - 0.0000f * 1.0000f); break;
        case  4: norm_outflow = 0.8670f * norm_inflow + 0.0373f; break;
        case  5: norm_outflow = 0.4516f * norm_inflow + 0.0526f; break;
        case  6: norm_outflow = 0.5375f * norm_inflow + 0.0619f; break;
        case  7: norm_outflow = 0.7176f * norm_inflow + 0.0855f; break;
        case  8: norm_outflow = 0.6621f * norm_inflow + 0.0785f; break;
        case  9: norm_outflow = (norm_storage <= 1.0000f) ? 0.0320f * norm_storage + 0.0369f : 0.0000f * norm_storage + (0.0320f * 1.0000f + 0.0369f - 0.0000f * 1.0000f); break;
        case 10: norm_outflow = (norm_storage <= 1.0000f) ? 0.0144f * norm_storage + 0.0318f : 0.0000f * norm_storage + (0.0144f * 1.0000f + 0.0318f - 0.0000f * 1.0000f); break;
        case 11: norm_outflow = (norm_storage <= 1.0000f) ? 0.0280f * norm_storage + 0.0268f : 0.0000f * norm_storage + (0.0280f * 1.0000f + 0.0268f - 0.0000f * 1.0000f); break;
        case 12: norm_outflow = (norm_storage <= 1.0000f) ? 0.0246f * norm_storage + 0.0292f : 0.0000f * norm_storage + (0.0246f * 1.0000f + 0.0292f - 0.0000f * 1.0000f); break;
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
        case  1: norm_outflow = (norm_storage <= 1.0000f) ? 0.0717f * norm_storage + 0.0161f : 0.0000f * norm_storage + (0.0717f * 1.0000f + 0.0161f - 0.0000f * 1.0000f); break;
        case  2: norm_outflow = 0.1322f * norm_inflow + 0.0509f; break;
        case  3: norm_outflow = 0.1856f * norm_inflow + 0.0500f; break;
        case  4: norm_outflow = 0.2041f * norm_inflow + 0.0607f; break;
        case  5: norm_outflow = (norm_storage <= 0.9501f) ? 0.0702f * norm_storage + 0.0243f : 5.3002f * norm_storage + (0.0702f * 0.9501f + 0.0243f - 5.3002f * 0.9501f); break;
        case  6: norm_outflow = 0.7277f * norm_inflow + -0.0318f; break;
        case  7: norm_outflow = 0.7674f * norm_inflow + 0.0444f; break;
        case  8: norm_outflow = 0.4846f * norm_inflow + 0.0960f; break;
        case  9: norm_outflow = 0.1202f * norm_inflow + 0.1008f; break;
        case 10: norm_outflow = 0.0203f * norm_inflow + 0.0860f; break;
        case 11: norm_outflow = 0.0878f * norm_inflow + 0.0664f; break;
        case 12: norm_outflow = (norm_storage <= 1.0000f) ? 0.0483f * norm_storage + 0.0301f : 0.0000f * norm_storage + (0.0483f * 1.0000f + 0.0301f - 0.0000f * 1.0000f); break;
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
        case 11: norm_outflow = (norm_storage <= 1.0000f) ? -0.2882f * norm_storage + 0.3297f : 0.0000f * norm_storage + (-0.2882f * 1.0000f + 0.3297f - 0.0000f * 1.0000f); break;
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
        case  2: norm_outflow = (norm_storage <= 0.7577f) ? 0.1000f * norm_storage + 0.0704f : 0.9683f * norm_storage + (0.1000f * 0.7577f + 0.0704f - 0.9683f * 0.7577f); break;
        case  3: norm_outflow = (norm_storage <= 1.0000f) ? 0.1276f * norm_storage + 0.0292f : 0.0000f * norm_storage + (0.1276f * 1.0000f + 0.0292f - 0.0000f * 1.0000f); break;
        case  4: norm_outflow = 0.1130f * norm_inflow + 0.1026f; break;
        case  5: norm_outflow = 0.4859f * norm_inflow + 0.0650f; break;
        case  6: norm_outflow = (norm_storage <= 0.9265f) ? 0.1000f * norm_storage + 0.0679f : 10.3238f * norm_storage + (0.1000f * 0.9265f + 0.0679f - 10.3238f * 0.9265f); break;
        case  7: norm_outflow = (norm_storage <= 0.9340f) ? 0.1000f * norm_storage + 0.0657f : 8.4715f * norm_storage + (0.1000f * 0.9340f + 0.0657f - 8.4715f * 0.9340f); break;
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
        case  3: norm_outflow = (norm_storage <= 1.0000f) ? 0.6964f * norm_storage + -0.0340f : 0.0000f * norm_storage + (0.6964f * 1.0000f + -0.0340f - 0.0000f * 1.0000f); break;
        case  4: norm_outflow = (norm_storage <= 1.0000f) ? 0.5956f * norm_storage + -0.0447f : 0.0000f * norm_storage + (0.5956f * 1.0000f + -0.0447f - 0.0000f * 1.0000f); break;
        case  5: norm_outflow = (norm_storage <= 1.0000f) ? 0.5527f * norm_storage + -0.0395f : 0.0000f * norm_storage + (0.5527f * 1.0000f + -0.0395f - 0.0000f * 1.0000f); break;
        case  6: norm_outflow = 3.5674f * norm_inflow + 0.0869f; break;
        case  7: norm_outflow = 4.1547f * norm_inflow + 0.1113f; break;
        case  8: norm_outflow = 4.1654f * norm_inflow + 0.1102f; break;
        case  9: norm_outflow = (norm_storage <= 1.0000f) ? 1.2520f * norm_storage + -0.0442f : 0.0000f * norm_storage + (1.2520f * 1.0000f + -0.0442f - 0.0000f * 1.0000f); break;
        case 10: norm_outflow = (norm_storage <= 1.0000f) ? 2.8295f * norm_storage + -0.1615f : 0.0000f * norm_storage + (2.8295f * 1.0000f + -0.1615f - 0.0000f * 1.0000f); break;
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
        case  4: norm_outflow = (norm_storage <= 1.0000f) ? 1.3245f * norm_storage + -0.1257f : 0.0000f * norm_storage + (1.3245f * 1.0000f + -0.1257f - 0.0000f * 1.0000f); break;
        case  5: norm_outflow = (norm_storage <= 1.0000f) ? 1.3680f * norm_storage + -0.0876f : 0.0000f * norm_storage + (1.3680f * 1.0000f + -0.0876f - 0.0000f * 1.0000f); break;
        case  6: norm_outflow = (norm_storage <= 1.0000f) ? 1.7496f * norm_storage + -0.1788f : 0.0000f * norm_storage + (1.7496f * 1.0000f + -0.1788f - 0.0000f * 1.0000f); break;
        case  7: norm_outflow = (norm_storage <= 1.0000f) ? 1.2643f * norm_storage + -0.1080f : 0.0000f * norm_storage + (1.2643f * 1.0000f + -0.1080f - 0.0000f * 1.0000f); break;
        case  8: norm_outflow = (norm_storage <= 1.0000f) ? 1.0168f * norm_storage + -0.0953f : 0.0000f * norm_storage + (1.0168f * 1.0000f + -0.0953f - 0.0000f * 1.0000f); break;
        case  9: norm_outflow = (norm_storage <= 1.0000f) ? 1.5411f * norm_storage + -0.1491f : 0.0000f * norm_storage + (1.5411f * 1.0000f + -0.1491f - 0.0000f * 1.0000f); break;
        case 10: norm_outflow = (norm_storage <= 1.0000f) ? 3.2093f * norm_storage + -0.3459f : 0.0000f * norm_storage + (3.2093f * 1.0000f + -0.3459f - 0.0000f * 1.0000f); break;
        case 11: norm_outflow = 5.8266f * norm_inflow + 0.0147f; break;
        case 12: norm_outflow = (norm_storage <= 1.0000f) ? 0.9328f * norm_storage + -0.1018f : 0.0000f * norm_storage + (0.9328f * 1.0000f + -0.1018f - 0.0000f * 1.0000f); break;
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
        case  9: norm_outflow = (norm_storage <= 0.8937f) ? 0.0025f * norm_storage + 0.0012f : 0.9554f * norm_storage + (0.0025f * 0.8937f + 0.0012f - 0.9554f * 0.8937f); break;
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
        case  2: norm_outflow = (norm_storage <= 1.0000f) ? -0.5819f * norm_storage + 0.5393f : 0.0000f * norm_storage + (-0.5819f * 1.0000f + 0.5393f - 0.0000f * 1.0000f); break;
        case  3: norm_outflow = 0.1720f * norm_inflow + 0.0842f; break;
        case  4: norm_outflow = 0.5064f * norm_inflow + 0.0352f; break;
        case  5: norm_outflow = (norm_storage <= 0.8963f) ? 0.1000f * norm_storage + 0.0131f : 6.3968f * norm_storage + (0.1000f * 0.8963f + 0.0131f - 6.3968f * 0.8963f); break;
        case  6: norm_outflow = 0.8873f * norm_inflow + 0.0679f; break;
        case  7: norm_outflow = (norm_storage <= 1.0000f) ? 6.4918f * norm_storage + -5.7616f : 0.0000f * norm_storage + (6.4918f * 1.0000f + -5.7616f - 0.0000f * 1.0000f); break;
        case  8: norm_outflow = 0.4644f * norm_inflow + 0.0464f; break;
        case  9: norm_outflow = (norm_storage <= 1.0000f) ? 1.8498f * norm_storage + -1.5889f : 0.0000f * norm_storage + (1.8498f * 1.0000f + -1.5889f - 0.0000f * 1.0000f); break;
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
        case  3: norm_outflow = (norm_storage <= 1.0000f) ? 1.5100f * norm_storage + -0.5714f : 0.0000f * norm_storage + (1.5100f * 1.0000f + -0.5714f - 0.0000f * 1.0000f); break;
        case  4: norm_outflow = (norm_storage <= 1.0000f) ? 1.6642f * norm_storage + -0.6619f : 0.0000f * norm_storage + (1.6642f * 1.0000f + -0.6619f - 0.0000f * 1.0000f); break;
        case  5: norm_outflow = 2.1379f * norm_inflow + 0.0126f; break;
        case  6: norm_outflow = 2.2109f * norm_inflow + 0.0177f; break;
        case  7: norm_outflow = 0.5940f * norm_inflow + 0.0228f; break;
        case  8: norm_outflow = 1.7402f * norm_inflow + 0.0202f; break;
        case  9: norm_outflow = 1.6409f * norm_inflow + 0.0105f; break;
        case 10: norm_outflow = 2.2065f * norm_inflow + 0.0053f; break;
        case 11: norm_outflow = 0.7062f * norm_inflow + 0.0037f; break;
        case 12: norm_outflow = (norm_storage <= 1.0000f) ? 0.0347f * norm_storage + -0.0088f : 0.0000f * norm_storage + (0.0347f * 1.0000f + -0.0088f - 0.0000f * 1.0000f); break;
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
        case  1: norm_outflow = (norm_storage <= 1.0000f) ? 0.0477f * norm_storage + -0.0104f : 0.0000f * norm_storage + (0.0477f * 1.0000f + -0.0104f - 0.0000f * 1.0000f); break;
        case  2: norm_outflow = (norm_storage <= 1.0000f) ? 0.0469f * norm_storage + -0.0101f : 0.0000f * norm_storage + (0.0469f * 1.0000f + -0.0101f - 0.0000f * 1.0000f); break;
        case  3: norm_outflow = (norm_storage <= 0.6000f) ? 0.1000f * norm_storage + 0.0000f : 4.9267f * norm_storage + (0.1000f * 0.6000f + 0.0000f - 4.9267f * 0.6000f); break;
        case  4: norm_outflow = (norm_storage <= 0.6000f) ? 0.1000f * norm_storage + 0.0101f : 3.1750f * norm_storage + (0.1000f * 0.6000f + 0.0101f - 3.1750f * 0.6000f); break;
        case  5: norm_outflow = 3.0213f * norm_inflow + 0.0156f; break;
        case  6: norm_outflow = 1.7244f * norm_inflow + 0.0183f; break;
        case  7: norm_outflow = 2.6641f * norm_inflow + 0.0145f; break;
        case  8: norm_outflow = (norm_storage <= 0.6000f) ? 0.0384f * norm_storage + 0.0000f : 12.3106f * norm_storage + (0.0384f * 0.6000f + 0.0000f - 12.3106f * 0.6000f); break;
        case  9: norm_outflow = (norm_storage <= 1.0000f) ? 0.0970f * norm_storage + -0.0281f : 0.0000f * norm_storage + (0.0970f * 1.0000f + -0.0281f - 0.0000f * 1.0000f); break;
        case 10: norm_outflow = (norm_storage <= 1.0000f) ? 0.1579f * norm_storage + -0.0490f : 0.0000f * norm_storage + (0.1579f * 1.0000f + -0.0490f - 0.0000f * 1.0000f); break;
        case 11: norm_outflow = 2.8258f * norm_inflow + 0.0119f; break;
        case 12: norm_outflow = (norm_storage <= 1.0000f) ? 0.0666f * norm_storage + -0.0169f : 0.0000f * norm_storage + (0.0666f * 1.0000f + -0.0169f - 0.0000f * 1.0000f); break;
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
        case 10: norm_outflow = (norm_storage <= 1.0000f) ? 0.3253f * norm_storage + -0.0838f : 0.0000f * norm_storage + (0.3253f * 1.0000f + -0.0838f - 0.0000f * 1.0000f); break;
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
        case  3: norm_outflow = (norm_storage <= 0.8952f) ? 0.0017f * norm_storage + 0.0001f : 0.9355f * norm_storage + (0.0017f * 0.8952f + 0.0001f - 0.9355f * 0.8952f); break;
        case  4: norm_outflow = 0.0194f * norm_inflow + 0.0168f; break;
        case  5: norm_outflow = (norm_storage <= 1.0000f) ? 0.3173f * norm_storage + -0.1274f : 0.0000f * norm_storage + (0.3173f * 1.0000f + -0.1274f - 0.0000f * 1.0000f); break;
        case  6: norm_outflow = 0.0000f * norm_inflow + 0.2878f; break;
        case  7: norm_outflow = (norm_storage <= 1.0000f) ? -0.2797f * norm_storage + 0.7717f : 0.0000f * norm_storage + (-0.2797f * 1.0000f + 0.7717f - 0.0000f * 1.0000f); break;
        case  8: norm_outflow = 0.0000f * norm_inflow + 0.5818f; break;
        case  9: norm_outflow = (norm_storage <= 1.0000f) ? 0.4017f * norm_storage + 0.1463f : 0.0000f * norm_storage + (0.4017f * 1.0000f + 0.1463f - 0.0000f * 1.0000f); break;
        case 10: norm_outflow = 0.0091f * norm_inflow + 0.0103f; break;
        case 11: norm_outflow = 0.0052f * norm_inflow + 0.0010f; break;
        case 12: norm_outflow = 0.0000f * norm_inflow + 0.0006f; break;
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
        case  5: norm_outflow = (norm_storage <= 0.8554f) ? 0.0860f * norm_storage + 0.0097f : 11.0701f * norm_storage + (0.0860f * 0.8554f + 0.0097f - 11.0701f * 0.8554f); break;
        case  6: norm_outflow = (norm_storage <= 0.8483f) ? 0.0135f * norm_storage + 0.0555f : 8.1298f * norm_storage + (0.0135f * 0.8483f + 0.0555f - 8.1298f * 0.8483f); break;
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
        case  2: norm_outflow = (norm_storage <= 0.9539f) ? 0.0003f * norm_storage + 0.0002f : 0.9218f * norm_storage + (0.0003f * 0.9539f + 0.0002f - 0.9218f * 0.9539f); break;
        case  3: norm_outflow = 1.1993f * norm_inflow + -0.0068f; break;
        case  4: norm_outflow = 1.1841f * norm_inflow + -0.0035f; break;
        case  5: norm_outflow = 0.8966f * norm_inflow + 0.0018f; break;
        case  6: norm_outflow = 1.1282f * norm_inflow + 0.0038f; break;
        case  7: norm_outflow = 0.7551f * norm_inflow + 0.0125f; break;
        case  8: norm_outflow = (norm_storage <= 1.0000f) ? 0.0128f * norm_storage + 0.0038f : 0.0000f * norm_storage + (0.0128f * 1.0000f + 0.0038f - 0.0000f * 1.0000f); break;
        case  9: norm_outflow = (norm_storage <= 1.0000f) ? 0.0114f * norm_storage + -0.0023f : 0.0000f * norm_storage + (0.0114f * 1.0000f + -0.0023f - 0.0000f * 1.0000f); break;
        case 10: norm_outflow = (norm_storage <= 0.9181f) ? 0.0017f * norm_storage + 0.0000f : 0.9465f * norm_storage + (0.0017f * 0.9181f + 0.0000f - 0.9465f * 0.9181f); break;
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
        case  2: norm_outflow = (norm_storage <= 0.6162f) ? 0.0075f * norm_storage + 0.0000f : 0.9989f * norm_storage + (0.0075f * 0.6162f + 0.0000f - 0.9989f * 0.6162f); break;
        case  3: norm_outflow = 1.1374f * norm_inflow + -0.0781f; break;
        case  4: norm_outflow = 1.0611f * norm_inflow + -0.0628f; break;
        case  5: norm_outflow = 0.7085f * norm_inflow + 0.0797f; break;
        case  6: norm_outflow = 0.8664f * norm_inflow + 0.1300f; break;
        case  7: norm_outflow = 0.7506f * norm_inflow + 0.4418f; break;
        case  8: norm_outflow = (norm_storage <= 1.0000f) ? 0.6710f * norm_storage + 0.3445f : 0.0000f * norm_storage + (0.6710f * 1.0000f + 0.3445f - 0.0000f * 1.0000f); break;
        case  9: norm_outflow = 1.9662f * norm_inflow + 0.0023f; break;
        case 10: norm_outflow = 0.0098f * norm_inflow + 0.0035f; break;
        case 11: norm_outflow = (norm_storage <= 1.0000f) ? 0.0052f * norm_storage + 0.0013f : 0.0000f * norm_storage + (0.0052f * 1.0000f + 0.0013f - 0.0000f * 1.0000f); break;
        case 12: norm_outflow = (norm_storage <= 1.0000f) ? 0.0053f * norm_storage + 0.0012f : 0.0000f * norm_storage + (0.0053f * 1.0000f + 0.0012f - 0.0000f * 1.0000f); break;
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
        case  8: norm_outflow = (norm_storage <= 1.0000f) ? -0.1148f * norm_storage + 0.2741f : 0.0000f * norm_storage + (-0.1148f * 1.0000f + 0.2741f - 0.0000f * 1.0000f); break;
        case  9: norm_outflow = 2.2951f * norm_inflow + 0.1233f; break;
        case 10: norm_outflow = (norm_storage <= 1.0000f) ? 2.0551f * norm_storage + -0.1041f : 0.0000f * norm_storage + (2.0551f * 1.0000f + -0.1041f - 0.0000f * 1.0000f); break;
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
        case  4: norm_outflow = (norm_storage <= 1.0000f) ? 0.5050f * norm_storage + 0.0555f : 0.0000f * norm_storage + (0.5050f * 1.0000f + 0.0555f - 0.0000f * 1.0000f); break;
        case  5: norm_outflow = 0.7841f * norm_inflow + 0.0492f; break;
        case  6: norm_outflow = (norm_storage <= 1.0000f) ? 0.6862f * norm_storage + 0.0261f : 0.0000f * norm_storage + (0.6862f * 1.0000f + 0.0261f - 0.0000f * 1.0000f); break;
        case  7: norm_outflow = (norm_storage <= 1.0000f) ? 0.6391f * norm_storage + 0.0269f : 0.0000f * norm_storage + (0.6391f * 1.0000f + 0.0269f - 0.0000f * 1.0000f); break;
        case  8: norm_outflow = (norm_storage <= 1.0000f) ? 1.1591f * norm_storage + -0.0244f : 0.0000f * norm_storage + (1.1591f * 1.0000f + -0.0244f - 0.0000f * 1.0000f); break;
        case  9: norm_outflow = 1.3433f * norm_inflow + 0.0074f; break;
        case 10: norm_outflow = 0.5837f * norm_inflow + 0.0172f; break;
        case 11: norm_outflow = (norm_storage <= 1.0000f) ? 0.4232f * norm_storage + -0.0069f : 0.0000f * norm_storage + (0.4232f * 1.0000f + -0.0069f - 0.0000f * 1.0000f); break;
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
        case  5: norm_outflow = (norm_storage <= 1.0000f) ? 0.3033f * norm_storage + 0.0663f : 0.0000f * norm_storage + (0.3033f * 1.0000f + 0.0663f - 0.0000f * 1.0000f); break;
        case  6: norm_outflow = (norm_storage <= 1.0000f) ? 0.4171f * norm_storage + 0.0447f : 0.0000f * norm_storage + (0.4171f * 1.0000f + 0.0447f - 0.0000f * 1.0000f); break;
        case  7: norm_outflow = 1.1369f * norm_inflow + 0.0640f; break;
        case  8: norm_outflow = (norm_storage <= 1.0000f) ? 0.8588f * norm_storage + -0.0483f : 0.0000f * norm_storage + (0.8588f * 1.0000f + -0.0483f - 0.0000f * 1.0000f); break;
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
        case  1: norm_outflow = (norm_storage <= 0.7647f) ? 0.0743f * norm_storage + 0.0037f : 0.9723f * norm_storage + (0.0743f * 0.7647f + 0.0037f - 0.9723f * 0.7647f); break;
        case  2: norm_outflow = (norm_storage <= 0.7977f) ? 0.0731f * norm_storage + 0.0000f : 1.7334f * norm_storage + (0.0731f * 0.7977f + 0.0000f - 1.7334f * 0.7977f); break;
        case  3: norm_outflow = (norm_storage <= 1.0000f) ? 0.3268f * norm_storage + -0.1302f : 0.0000f * norm_storage + (0.3268f * 1.0000f + -0.1302f - 0.0000f * 1.0000f); break;
        case  4: norm_outflow = 0.5245f * norm_inflow + 0.0658f; break;
        case  5: norm_outflow = (norm_storage <= 0.7927f) ? 0.0243f * norm_storage + 0.0554f : 2.2344f * norm_storage + (0.0243f * 0.7927f + 0.0554f - 2.2344f * 0.7927f); break;
        case  6: norm_outflow = 0.4005f * norm_inflow + 0.1578f; break;
        case  7: norm_outflow = 0.1214f * norm_inflow + 0.3550f; break;
        case  8: norm_outflow = (norm_storage <= 0.8104f) ? 0.1000f * norm_storage + 0.2185f : 1.2197f * norm_storage + (0.1000f * 0.8104f + 0.2185f - 1.2197f * 0.8104f); break;
        case  9: norm_outflow = (norm_storage <= 0.6871f) ? 0.1000f * norm_storage + 0.0428f : 1.2257f * norm_storage + (0.1000f * 0.6871f + 0.0428f - 1.2257f * 0.6871f); break;
        case 10: norm_outflow = (norm_storage <= 0.6824f) ? 0.0324f * norm_storage + 0.0000f : 1.0565f * norm_storage + (0.0324f * 0.6824f + 0.0000f - 1.0565f * 0.6824f); break;
        case 11: norm_outflow = (norm_storage <= 0.6935f) ? 0.0571f * norm_storage + 0.0000f : 1.0362f * norm_storage + (0.0571f * 0.6935f + 0.0000f - 1.0362f * 0.6935f); break;
        case 12: norm_outflow = (norm_storage <= 0.7672f) ? 0.1000f * norm_storage + 0.0009f : 1.1723f * norm_storage + (0.1000f * 0.7672f + 0.0009f - 1.1723f * 0.7672f); break;
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
        case  1: norm_outflow = (norm_storage <= 1.0000f) ? 0.6903f * norm_storage + -0.4927f : 0.0000f * norm_storage + (0.6903f * 1.0000f + -0.4927f - 0.0000f * 1.0000f); break;
        case  2: norm_outflow = (norm_storage <= 1.0000f) ? 1.5141f * norm_storage + -1.1288f : 0.0000f * norm_storage + (1.5141f * 1.0000f + -1.1288f - 0.0000f * 1.0000f); break;
        case  3: norm_outflow = (norm_storage <= 1.0000f) ? 3.2604f * norm_storage + -2.5235f : 0.0000f * norm_storage + (3.2604f * 1.0000f + -2.5235f - 0.0000f * 1.0000f); break;
        case  4: norm_outflow = (norm_storage <= 1.0000f) ? 2.9200f * norm_storage + -2.2485f : 0.0000f * norm_storage + (2.9200f * 1.0000f + -2.2485f - 0.0000f * 1.0000f); break;
        case  5: norm_outflow = (norm_storage <= 1.0000f) ? 2.6573f * norm_storage + -2.0443f : 0.0000f * norm_storage + (2.6573f * 1.0000f + -2.0443f - 0.0000f * 1.0000f); break;
        case  6: norm_outflow = (norm_storage <= 1.0000f) ? 3.3034f * norm_storage + -2.5545f : 0.0000f * norm_storage + (3.3034f * 1.0000f + -2.5545f - 0.0000f * 1.0000f); break;
        case  7: norm_outflow = (norm_storage <= 0.7744f) ? 0.0043f * norm_storage + 0.0038f : 2.9187f * norm_storage + (0.0043f * 0.7744f + 0.0038f - 2.9187f * 0.7744f); break;
        case  8: norm_outflow = (norm_storage <= 0.7852f) ? 0.0263f * norm_storage + 0.0000f : 3.7559f * norm_storage + (0.0263f * 0.7852f + 0.0000f - 3.7559f * 0.7852f); break;
        case  9: norm_outflow = (norm_storage <= 0.7809f) ? 0.0000f * norm_storage + 0.0251f : 3.0915f * norm_storage + (0.0000f * 0.7809f + 0.0251f - 3.0915f * 0.7809f); break;
        case 10: norm_outflow = (norm_storage <= 1.0000f) ? 1.0087f * norm_storage + -0.7282f : 0.0000f * norm_storage + (1.0087f * 1.0000f + -0.7282f - 0.0000f * 1.0000f); break;
        case 11: norm_outflow = 0.8097f * norm_inflow + 0.0449f; break;
        case 12: norm_outflow = (norm_storage <= 1.0000f) ? 0.5081f * norm_storage + -0.3512f : 0.0000f * norm_storage + (0.5081f * 1.0000f + -0.3512f - 0.0000f * 1.0000f); break;
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
        case  1: norm_outflow = (norm_storage <= 1.0000f) ? 0.2888f * norm_storage + -0.0875f : 0.0000f * norm_storage + (0.2888f * 1.0000f + -0.0875f - 0.0000f * 1.0000f); break;
        case  2: norm_outflow = 1.2093f * norm_inflow + 0.0151f; break;
        case  3: norm_outflow = 1.1625f * norm_inflow + 0.0246f; break;
        case  4: norm_outflow = 1.1336f * norm_inflow + 0.0185f; break;
        case  5: norm_outflow = 1.0539f * norm_inflow + 0.0238f; break;
        case  6: norm_outflow = 1.1863f * norm_inflow + 0.0291f; break;
        case  7: norm_outflow = 1.1067f * norm_inflow + 0.0381f; break;
        case  8: norm_outflow = 1.4313f * norm_inflow + 0.0294f; break;
        case  9: norm_outflow = (norm_storage <= 1.0000f) ? 0.2310f * norm_storage + -0.0706f : 0.0000f * norm_storage + (0.2310f * 1.0000f + -0.0706f - 0.0000f * 1.0000f); break;
        case 10: norm_outflow = (norm_storage <= 1.0000f) ? 0.2089f * norm_storage + -0.0615f : 0.0000f * norm_storage + (0.2089f * 1.0000f + -0.0615f - 0.0000f * 1.0000f); break;
        case 11: norm_outflow = (norm_storage <= 1.0000f) ? 0.1994f * norm_storage + -0.0576f : 0.0000f * norm_storage + (0.1994f * 1.0000f + -0.0576f - 0.0000f * 1.0000f); break;
        case 12: norm_outflow = (norm_storage <= 1.0000f) ? 0.2529f * norm_storage + -0.0679f : 0.0000f * norm_storage + (0.2529f * 1.0000f + -0.0679f - 0.0000f * 1.0000f); break;
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
        case  1: norm_outflow = (norm_storage <= 0.6838f) ? 0.0058f * norm_storage + 0.0000f : 0.9911f * norm_storage + (0.0058f * 0.6838f + 0.0000f - 0.9911f * 0.6838f); break;
        case  2: norm_outflow = (norm_storage <= 0.6614f) ? 0.0037f * norm_storage + 0.0000f : 0.7079f * norm_storage + (0.0037f * 0.6614f + 0.0000f - 0.7079f * 0.6614f); break;
        case  3: norm_outflow = (norm_storage <= 0.6590f) ? 0.0001f * norm_storage + 0.0004f : 1.3320f * norm_storage + (0.0001f * 0.6590f + 0.0004f - 1.3320f * 0.6590f); break;
        case  4: norm_outflow = (norm_storage <= 0.7464f) ? 0.0022f * norm_storage + 0.0000f : 5.0569f * norm_storage + (0.0022f * 0.7464f + 0.0000f - 5.0569f * 0.7464f); break;
        case  5: norm_outflow = (norm_storage <= 0.7363f) ? 0.0000f * norm_storage + 0.0047f : 1.9460f * norm_storage + (0.0000f * 0.7363f + 0.0047f - 1.9460f * 0.7363f); break;
        case  6: norm_outflow = (norm_storage <= 1.0000f) ? 0.5613f * norm_storage + -0.2010f : 0.0000f * norm_storage + (0.5613f * 1.0000f + -0.2010f - 0.0000f * 1.0000f); break;
        case  7: norm_outflow = (norm_storage <= 1.0000f) ? 0.6243f * norm_storage + -0.0580f : 0.0000f * norm_storage + (0.6243f * 1.0000f + -0.0580f - 0.0000f * 1.0000f); break;
        case  8: norm_outflow = (norm_storage <= 1.0000f) ? 0.5620f * norm_storage + -0.0667f : 0.0000f * norm_storage + (0.5620f * 1.0000f + -0.0667f - 0.0000f * 1.0000f); break;
        case  9: norm_outflow = (norm_storage <= 0.6401f) ? 0.0566f * norm_storage + 0.0000f : 1.4270f * norm_storage + (0.0566f * 0.6401f + 0.0000f - 1.4270f * 0.6401f); break;
        case 10: norm_outflow = (norm_storage <= 0.6615f) ? 0.0004f * norm_storage + 0.0002f : 2.3977f * norm_storage + (0.0004f * 0.6615f + 0.0002f - 2.3977f * 0.6615f); break;
        case 11: norm_outflow = (norm_storage <= 0.7340f) ? 0.0233f * norm_storage + 0.0000f : 6.8232f * norm_storage + (0.0233f * 0.7340f + 0.0000f - 6.8232f * 0.7340f); break;
        case 12: norm_outflow = (norm_storage <= 0.7140f) ? 0.0000f * norm_storage + 0.0054f : 3.8684f * norm_storage + (0.0000f * 0.7140f + 0.0054f - 3.8684f * 0.7140f); break;
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
        case  1: norm_outflow = (norm_storage <= 1.0000f) ? 0.4042f * norm_storage + -0.1308f : 0.0000f * norm_storage + (0.4042f * 1.0000f + -0.1308f - 0.0000f * 1.0000f); break;
        case  2: norm_outflow = (norm_storage <= 1.0000f) ? 0.4085f * norm_storage + -0.1339f : 0.0000f * norm_storage + (0.4085f * 1.0000f + -0.1339f - 0.0000f * 1.0000f); break;
        case  3: norm_outflow = (norm_storage <= 1.0000f) ? 0.7319f * norm_storage + -0.2573f : 0.0000f * norm_storage + (0.7319f * 1.0000f + -0.2573f - 0.0000f * 1.0000f); break;
        case  4: norm_outflow = (norm_storage <= 1.0000f) ? 0.8259f * norm_storage + -0.3028f : 0.0000f * norm_storage + (0.8259f * 1.0000f + -0.3028f - 0.0000f * 1.0000f); break;
        case  5: norm_outflow = (norm_storage <= 1.0000f) ? 1.1390f * norm_storage + -0.4434f : 0.0000f * norm_storage + (1.1390f * 1.0000f + -0.4434f - 0.0000f * 1.0000f); break;
        case  6: norm_outflow = (norm_storage <= 1.0000f) ? 0.9367f * norm_storage + -0.3621f : 0.0000f * norm_storage + (0.9367f * 1.0000f + -0.3621f - 0.0000f * 1.0000f); break;
        case  7: norm_outflow = (norm_storage <= 1.0000f) ? 1.0810f * norm_storage + -0.4281f : 0.0000f * norm_storage + (1.0810f * 1.0000f + -0.4281f - 0.0000f * 1.0000f); break;
        case  8: norm_outflow = (norm_storage <= 1.0000f) ? 0.8125f * norm_storage + -0.3087f : 0.0000f * norm_storage + (0.8125f * 1.0000f + -0.3087f - 0.0000f * 1.0000f); break;
        case  9: norm_outflow = (norm_storage <= 0.6000f) ? 0.0924f * norm_storage + 0.0000f : 3.0547f * norm_storage + (0.0924f * 0.6000f + 0.0000f - 3.0547f * 0.6000f); break;
        case 10: norm_outflow = (norm_storage <= 1.0000f) ? 0.6314f * norm_storage + -0.2251f : 0.0000f * norm_storage + (0.6314f * 1.0000f + -0.2251f - 0.0000f * 1.0000f); break;
        case 11: norm_outflow = (norm_storage <= 1.0000f) ? 0.6559f * norm_storage + -0.2343f : 0.0000f * norm_storage + (0.6559f * 1.0000f + -0.2343f - 0.0000f * 1.0000f); break;
        case 12: norm_outflow = (norm_storage <= 1.0000f) ? 0.6317f * norm_storage + -0.2196f : 0.0000f * norm_storage + (0.6317f * 1.0000f + -0.2196f - 0.0000f * 1.0000f); break;
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
        case  2: norm_outflow = (norm_storage <= 1.0000f) ? 0.5602f * norm_storage + -0.3159f : 0.0000f * norm_storage + (0.5602f * 1.0000f + -0.3159f - 0.0000f * 1.0000f); break;
        case  3: norm_outflow = 4.0139f * norm_inflow + 0.0121f; break;
        case  4: norm_outflow = 3.3119f * norm_inflow + 0.0484f; break;
        case  5: norm_outflow = 2.3976f * norm_inflow + 0.0462f; break;
        case  6: norm_outflow = 2.1882f * norm_inflow + 0.0247f; break;
        case  7: norm_outflow = (norm_storage <= 0.6687f) ? 0.0233f * norm_storage + 0.0000f : 0.9245f * norm_storage + (0.0233f * 0.6687f + 0.0000f - 0.9245f * 0.6687f); break;
        case  8: norm_outflow = (norm_storage <= 0.6696f) ? 0.0339f * norm_storage + 0.0000f : 2.5740f * norm_storage + (0.0339f * 0.6696f + 0.0000f - 2.5740f * 0.6696f); break;
        case  9: norm_outflow = (norm_storage <= 0.6926f) ? 0.0199f * norm_storage + 0.0000f : 9.9521f * norm_storage + (0.0199f * 0.6926f + 0.0000f - 9.9521f * 0.6926f); break;
        case 10: norm_outflow = (norm_storage <= 0.6495f) ? 0.0129f * norm_storage + 0.0000f : 1.9747f * norm_storage + (0.0129f * 0.6495f + 0.0000f - 1.9747f * 0.6495f); break;
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
        case  1: norm_outflow = (norm_storage <= 1.0000f) ? 0.0537f * norm_storage + 0.0259f : 0.0000f * norm_storage + (0.0537f * 1.0000f + 0.0259f - 0.0000f * 1.0000f); break;
        case  2: norm_outflow = (norm_storage <= 1.0000f) ? 0.1004f * norm_storage + 0.0221f : 0.0000f * norm_storage + (0.1004f * 1.0000f + 0.0221f - 0.0000f * 1.0000f); break;
        case  3: norm_outflow = (norm_storage <= 0.8712f) ? 0.0180f * norm_storage + 0.0418f : 9.2687f * norm_storage + (0.0180f * 0.8712f + 0.0418f - 9.2687f * 0.8712f); break;
        case  4: norm_outflow = (norm_storage <= 0.8762f) ? 0.0000f * norm_storage + 0.0537f : 9.4046f * norm_storage + (0.0000f * 0.8762f + 0.0537f - 9.4046f * 0.8762f); break;
        case  5: norm_outflow = (norm_storage <= 0.8535f) ? 0.0000f * norm_storage + 0.0694f : 1.6452f * norm_storage + (0.0000f * 0.8535f + 0.0694f - 1.6452f * 0.8535f); break;
        case  6: norm_outflow = (norm_storage <= 0.9564f) ? 0.0000f * norm_storage + 0.0854f : 18.3447f * norm_storage + (0.0000f * 0.9564f + 0.0854f - 18.3447f * 0.9564f); break;
        case  7: norm_outflow = (norm_storage <= 0.8797f) ? 0.1000f * norm_storage + 0.0574f : 7.1768f * norm_storage + (0.1000f * 0.8797f + 0.0574f - 7.1768f * 0.8797f); break;
        case  8: norm_outflow = (norm_storage <= 0.8904f) ? 0.1000f * norm_storage + 0.0476f : 39.7222f * norm_storage + (0.1000f * 0.8904f + 0.0476f - 39.7222f * 0.8904f); break;
        case  9: norm_outflow = (norm_storage <= 1.0000f) ? 0.0798f * norm_storage + 0.0389f : 0.0000f * norm_storage + (0.0798f * 1.0000f + 0.0389f - 0.0000f * 1.0000f); break;
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
        case  1: norm_outflow = (norm_storage <= 1.0000f) ? 0.5743f * norm_storage + -0.2275f : 0.0000f * norm_storage + (0.5743f * 1.0000f + -0.2275f - 0.0000f * 1.0000f); break;
        case  2: norm_outflow = (norm_storage <= 1.0000f) ? 0.4433f * norm_storage + -0.1725f : 0.0000f * norm_storage + (0.4433f * 1.0000f + -0.1725f - 0.0000f * 1.0000f); break;
        case  3: norm_outflow = (norm_storage <= 1.0000f) ? 0.6117f * norm_storage + -0.2451f : 0.0000f * norm_storage + (0.6117f * 1.0000f + -0.2451f - 0.0000f * 1.0000f); break;
        case  4: norm_outflow = (norm_storage <= 1.0000f) ? 0.2975f * norm_storage + -0.1061f : 0.0000f * norm_storage + (0.2975f * 1.0000f + -0.1061f - 0.0000f * 1.0000f); break;
        case  5: norm_outflow = (norm_storage <= 1.0000f) ? 0.4345f * norm_storage + -0.1847f : 0.0000f * norm_storage + (0.4345f * 1.0000f + -0.1847f - 0.0000f * 1.0000f); break;
        case  6: norm_outflow = (norm_storage <= 1.0000f) ? 0.3140f * norm_storage + -0.1303f : 0.0000f * norm_storage + (0.3140f * 1.0000f + -0.1303f - 0.0000f * 1.0000f); break;
        case  7: norm_outflow = (norm_storage <= 0.8891f) ? 0.1000f * norm_storage + 0.0022f : 8.1091f * norm_storage + (0.1000f * 0.8891f + 0.0022f - 8.1091f * 0.8891f); break;
        case  8: norm_outflow = (norm_storage <= 1.0000f) ? 0.6500f * norm_storage + -0.2706f : 0.0000f * norm_storage + (0.6500f * 1.0000f + -0.2706f - 0.0000f * 1.0000f); break;
        case  9: norm_outflow = (norm_storage <= 1.0000f) ? 0.4293f * norm_storage + -0.1721f : 0.0000f * norm_storage + (0.4293f * 1.0000f + -0.1721f - 0.0000f * 1.0000f); break;
        case 10: norm_outflow = (norm_storage <= 1.0000f) ? 0.3930f * norm_storage + -0.1519f : 0.0000f * norm_storage + (0.3930f * 1.0000f + -0.1519f - 0.0000f * 1.0000f); break;
        case 11: norm_outflow = (norm_storage <= 1.0000f) ? 0.3891f * norm_storage + -0.1490f : 0.0000f * norm_storage + (0.3891f * 1.0000f + -0.1490f - 0.0000f * 1.0000f); break;
        case 12: norm_outflow = (norm_storage <= 1.0000f) ? 0.5454f * norm_storage + -0.2142f : 0.0000f * norm_storage + (0.5454f * 1.0000f + -0.2142f - 0.0000f * 1.0000f); break;
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
        case  3: norm_outflow = (norm_storage <= 1.0000f) ? 1.2875f * norm_storage + -0.2417f : 0.0000f * norm_storage + (1.2875f * 1.0000f + -0.2417f - 0.0000f * 1.0000f); break;
        case  4: norm_outflow = (norm_storage <= 1.0000f) ? 0.6393f * norm_storage + -0.1111f : 0.0000f * norm_storage + (0.6393f * 1.0000f + -0.1111f - 0.0000f * 1.0000f); break;
        case  5: norm_outflow = (norm_storage <= 1.0000f) ? 0.9871f * norm_storage + -0.1842f : 0.0000f * norm_storage + (0.9871f * 1.0000f + -0.1842f - 0.0000f * 1.0000f); break;
        case  6: norm_outflow = (norm_storage <= 1.0000f) ? 1.3666f * norm_storage + -0.2580f : 0.0000f * norm_storage + (1.3666f * 1.0000f + -0.2580f - 0.0000f * 1.0000f); break;
        case  7: norm_outflow = (norm_storage <= 1.0000f) ? 0.8375f * norm_storage + -0.1314f : 0.0000f * norm_storage + (0.8375f * 1.0000f + -0.1314f - 0.0000f * 1.0000f); break;
        case  8: norm_outflow = (norm_storage <= 1.0000f) ? 0.8348f * norm_storage + -0.1333f : 0.0000f * norm_storage + (0.8348f * 1.0000f + -0.1333f - 0.0000f * 1.0000f); break;
        case  9: norm_outflow = (norm_storage <= 1.0000f) ? 0.9862f * norm_storage + -0.1856f : 0.0000f * norm_storage + (0.9862f * 1.0000f + -0.1856f - 0.0000f * 1.0000f); break;
        case 10: norm_outflow = (norm_storage <= 1.0000f) ? 1.0914f * norm_storage + -0.2213f : 0.0000f * norm_storage + (1.0914f * 1.0000f + -0.2213f - 0.0000f * 1.0000f); break;
        case 11: norm_outflow = (norm_storage <= 1.0000f) ? 1.4899f * norm_storage + -0.3051f : 0.0000f * norm_storage + (1.4899f * 1.0000f + -0.3051f - 0.0000f * 1.0000f); break;
        case 12: norm_outflow = (norm_storage <= 1.0000f) ? 1.4629f * norm_storage + -0.2797f : 0.0000f * norm_storage + (1.4629f * 1.0000f + -0.2797f - 0.0000f * 1.0000f); break;
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
        case  1: norm_outflow = (norm_storage <= 0.6492f) ? 0.0701f * norm_storage + 0.0000f : 34.1048f * norm_storage + (0.0701f * 0.6492f + 0.0000f - 34.1048f * 0.6492f); break;
        case  2: norm_outflow = (norm_storage <= 0.6000f) ? 0.0673f * norm_storage + 0.0000f : 4.1916f * norm_storage + (0.0673f * 0.6000f + 0.0000f - 4.1916f * 0.6000f); break;
        case  3: norm_outflow = (norm_storage <= 0.6000f) ? 0.0692f * norm_storage + 0.0000f : 14.5508f * norm_storage + (0.0692f * 0.6000f + 0.0000f - 14.5508f * 0.6000f); break;
        case  4: norm_outflow = (norm_storage <= 0.6000f) ? 0.0690f * norm_storage + 0.0000f : 6.4927f * norm_storage + (0.0690f * 0.6000f + 0.0000f - 6.4927f * 0.6000f); break;
        case  5: norm_outflow = (norm_storage <= 1.0000f) ? 0.1725f * norm_storage + -0.0297f : 0.0000f * norm_storage + (0.1725f * 1.0000f + -0.0297f - 0.0000f * 1.0000f); break;
        case  6: norm_outflow = (norm_storage <= 0.6000f) ? 0.1000f * norm_storage + 0.0138f : 2.4729f * norm_storage + (0.1000f * 0.6000f + 0.0138f - 2.4729f * 0.6000f); break;
        case  7: norm_outflow = (norm_storage <= 0.6000f) ? 0.1000f * norm_storage + 0.0549f : 5.2889f * norm_storage + (0.1000f * 0.6000f + 0.0549f - 5.2889f * 0.6000f); break;
        case  8: norm_outflow = (norm_storage <= 1.0000f) ? 0.1664f * norm_storage + 0.0132f : 0.0000f * norm_storage + (0.1664f * 1.0000f + 0.0132f - 0.0000f * 1.0000f); break;
        case  9: norm_outflow = (norm_storage <= 1.0000f) ? 0.0407f * norm_storage + -0.0071f : 0.0000f * norm_storage + (0.0407f * 1.0000f + -0.0071f - 0.0000f * 1.0000f); break;
        case 10: norm_outflow = (norm_storage <= 1.0000f) ? 0.1715f * norm_storage + -0.0294f : 0.0000f * norm_storage + (0.1715f * 1.0000f + -0.0294f - 0.0000f * 1.0000f); break;
        case 11: norm_outflow = (norm_storage <= 0.7085f) ? 0.0341f * norm_storage + 0.0000f : 0.9732f * norm_storage + (0.0341f * 0.7085f + 0.0000f - 0.9732f * 0.7085f); break;
        case 12: norm_outflow = (norm_storage <= 0.6000f) ? 0.0574f * norm_storage + 0.0000f : 2.1273f * norm_storage + (0.0574f * 0.6000f + 0.0000f - 2.1273f * 0.6000f); break;
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
        case  3: norm_outflow = (norm_storage <= 0.6286f) ? 0.0231f * norm_storage + 0.0022f : 0.6597f * norm_storage + (0.0231f * 0.6286f + 0.0022f - 0.6597f * 0.6286f); break;
        case  4: norm_outflow = 0.4045f * norm_inflow + 0.0164f; break;
        case  5: norm_outflow = 0.3796f * norm_inflow + 0.0249f; break;
        case  6: norm_outflow = (norm_storage <= 0.6124f) ? 0.0000f * norm_storage + 0.0097f : 0.5518f * norm_storage + (0.0000f * 0.6124f + 0.0097f - 0.5518f * 0.6124f); break;
        case  7: norm_outflow = (norm_storage <= 0.6085f) ? 0.0000f * norm_storage + 0.0094f : 0.6134f * norm_storage + (0.0000f * 0.6085f + 0.0094f - 0.6134f * 0.6085f); break;
        case  8: norm_outflow = 0.7799f * norm_inflow + 0.0159f; break;
        case  9: norm_outflow = 0.3433f * norm_inflow + 0.0133f; break;
        case 10: norm_outflow = (norm_storage <= 0.6241f) ? 0.0000f * norm_storage + 0.0065f : 0.5304f * norm_storage + (0.0000f * 0.6241f + 0.0065f - 0.5304f * 0.6241f); break;
        case 11: norm_outflow = (norm_storage <= 0.6369f) ? 0.0000f * norm_storage + 0.0069f : 0.9972f * norm_storage + (0.0000f * 0.6369f + 0.0069f - 0.9972f * 0.6369f); break;
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
        case  3: norm_outflow = (norm_storage <= 1.0000f) ? 0.3683f * norm_storage + -0.0197f : 0.0000f * norm_storage + (0.3683f * 1.0000f + -0.0197f - 0.0000f * 1.0000f); break;
        case  4: norm_outflow = (norm_storage <= 1.0000f) ? 0.4131f * norm_storage + -0.0233f : 0.0000f * norm_storage + (0.4131f * 1.0000f + -0.0233f - 0.0000f * 1.0000f); break;
        case  5: norm_outflow = (norm_storage <= 1.0000f) ? 0.4164f * norm_storage + -0.0106f : 0.0000f * norm_storage + (0.4164f * 1.0000f + -0.0106f - 0.0000f * 1.0000f); break;
        case  6: norm_outflow = (norm_storage <= 1.0000f) ? 0.5871f * norm_storage + -0.0271f : 0.0000f * norm_storage + (0.5871f * 1.0000f + -0.0271f - 0.0000f * 1.0000f); break;
        case  7: norm_outflow = (norm_storage <= 1.0000f) ? 0.6949f * norm_storage + -0.0567f : 0.0000f * norm_storage + (0.6949f * 1.0000f + -0.0567f - 0.0000f * 1.0000f); break;
        case  8: norm_outflow = (norm_storage <= 1.0000f) ? 0.6502f * norm_storage + -0.0618f : 0.0000f * norm_storage + (0.6502f * 1.0000f + -0.0618f - 0.0000f * 1.0000f); break;
        case  9: norm_outflow = (norm_storage <= 1.0000f) ? 0.4454f * norm_storage + -0.0381f : 0.0000f * norm_storage + (0.4454f * 1.0000f + -0.0381f - 0.0000f * 1.0000f); break;
        case 10: norm_outflow = (norm_storage <= 1.0000f) ? 0.3327f * norm_storage + -0.0248f : 0.0000f * norm_storage + (0.3327f * 1.0000f + -0.0248f - 0.0000f * 1.0000f); break;
        case 11: norm_outflow = (norm_storage <= 1.0000f) ? 0.6251f * norm_storage + -0.0677f : 0.0000f * norm_storage + (0.6251f * 1.0000f + -0.0677f - 0.0000f * 1.0000f); break;
        case 12: norm_outflow = (norm_storage <= 1.0000f) ? 0.5431f * norm_storage + -0.0428f : 0.0000f * norm_storage + (0.5431f * 1.0000f + -0.0428f - 0.0000f * 1.0000f); break;
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
        case  2: norm_outflow = (norm_storage <= 1.0000f) ? 0.6093f * norm_storage + -0.1487f : 0.0000f * norm_storage + (0.6093f * 1.0000f + -0.1487f - 0.0000f * 1.0000f); break;
        case  3: norm_outflow = (norm_storage <= 1.0000f) ? 0.6839f * norm_storage + -0.1620f : 0.0000f * norm_storage + (0.6839f * 1.0000f + -0.1620f - 0.0000f * 1.0000f); break;
        case  4: norm_outflow = (norm_storage <= 1.0000f) ? 1.2256f * norm_storage + -0.3271f : 0.0000f * norm_storage + (1.2256f * 1.0000f + -0.3271f - 0.0000f * 1.0000f); break;
        case  5: norm_outflow = (norm_storage <= 1.0000f) ? 1.0616f * norm_storage + -0.2882f : 0.0000f * norm_storage + (1.0616f * 1.0000f + -0.2882f - 0.0000f * 1.0000f); break;
        case  6: norm_outflow = (norm_storage <= 1.0000f) ? 1.1323f * norm_storage + -0.2999f : 0.0000f * norm_storage + (1.1323f * 1.0000f + -0.2999f - 0.0000f * 1.0000f); break;
        case  7: norm_outflow = (norm_storage <= 1.0000f) ? 0.6096f * norm_storage + -0.1267f : 0.0000f * norm_storage + (0.6096f * 1.0000f + -0.1267f - 0.0000f * 1.0000f); break;
        case  8: norm_outflow = (norm_storage <= 1.0000f) ? 1.0528f * norm_storage + -0.2841f : 0.0000f * norm_storage + (1.0528f * 1.0000f + -0.2841f - 0.0000f * 1.0000f); break;
        case  9: norm_outflow = (norm_storage <= 1.0000f) ? 1.0186f * norm_storage + -0.2848f : 0.0000f * norm_storage + (1.0186f * 1.0000f + -0.2848f - 0.0000f * 1.0000f); break;
        case 10: norm_outflow = (norm_storage <= 1.0000f) ? 1.1923f * norm_storage + -0.3222f : 0.0000f * norm_storage + (1.1923f * 1.0000f + -0.3222f - 0.0000f * 1.0000f); break;
        case 11: norm_outflow = (norm_storage <= 1.0000f) ? 1.0640f * norm_storage + -0.2917f : 0.0000f * norm_storage + (1.0640f * 1.0000f + -0.2917f - 0.0000f * 1.0000f); break;
        case 12: norm_outflow = (norm_storage <= 1.0000f) ? 0.5085f * norm_storage + -0.1128f : 0.0000f * norm_storage + (0.5085f * 1.0000f + -0.1128f - 0.0000f * 1.0000f); break;
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
        case  3: norm_outflow = (norm_storage <= 1.0000f) ? 0.3243f * norm_storage + -0.0736f : 0.0000f * norm_storage + (0.3243f * 1.0000f + -0.0736f - 0.0000f * 1.0000f); break;
        case  4: norm_outflow = (norm_storage <= 1.0000f) ? 0.5674f * norm_storage + -0.1435f : 0.0000f * norm_storage + (0.5674f * 1.0000f + -0.1435f - 0.0000f * 1.0000f); break;
        case  5: norm_outflow = (norm_storage <= 1.0000f) ? 0.4202f * norm_storage + -0.0963f : 0.0000f * norm_storage + (0.4202f * 1.0000f + -0.0963f - 0.0000f * 1.0000f); break;
        case  6: norm_outflow = (norm_storage <= 1.0000f) ? 0.6009f * norm_storage + -0.1505f : 0.0000f * norm_storage + (0.6009f * 1.0000f + -0.1505f - 0.0000f * 1.0000f); break;
        case  7: norm_outflow = (norm_storage <= 1.0000f) ? 0.7521f * norm_storage + -0.1997f : 0.0000f * norm_storage + (0.7521f * 1.0000f + -0.1997f - 0.0000f * 1.0000f); break;
        case  8: norm_outflow = (norm_storage <= 1.0000f) ? 0.7321f * norm_storage + -0.1959f : 0.0000f * norm_storage + (0.7321f * 1.0000f + -0.1959f - 0.0000f * 1.0000f); break;
        case  9: norm_outflow = 0.7326f * norm_inflow + 0.0116f; break;
        case 10: norm_outflow = 0.3994f * norm_inflow + 0.0150f; break;
        case 11: norm_outflow = (norm_storage <= 1.0000f) ? 0.4818f * norm_storage + -0.1226f : 0.0000f * norm_storage + (0.4818f * 1.0000f + -0.1226f - 0.0000f * 1.0000f); break;
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
        case  1: norm_outflow = (norm_storage <= 0.6069f) ? 0.0172f * norm_storage + 0.0000f : 6.6665f * norm_storage + (0.0172f * 0.6069f + 0.0000f - 6.6665f * 0.6069f); break;
        case  2: norm_outflow = (norm_storage <= 0.6069f) ? 0.0226f * norm_storage + 0.0000f : 6.2425f * norm_storage + (0.0226f * 0.6069f + 0.0000f - 6.2425f * 0.6069f); break;
        case  3: norm_outflow = (norm_storage <= 0.6075f) ? 0.0292f * norm_storage + 0.0000f : 6.4994f * norm_storage + (0.0292f * 0.6075f + 0.0000f - 6.4994f * 0.6075f); break;
        case  4: norm_outflow = (norm_storage <= 0.6061f) ? 0.0239f * norm_storage + 0.0000f : 6.4294f * norm_storage + (0.0239f * 0.6061f + 0.0000f - 6.4294f * 0.6061f); break;
        case  5: norm_outflow = (norm_storage <= 0.6000f) ? 0.0333f * norm_storage + 0.0000f : 4.1525f * norm_storage + (0.0333f * 0.6000f + 0.0000f - 4.1525f * 0.6000f); break;
        case  6: norm_outflow = (norm_storage <= 0.6047f) ? 0.0260f * norm_storage + 0.0000f : 6.0065f * norm_storage + (0.0260f * 0.6047f + 0.0000f - 6.0065f * 0.6047f); break;
        case  7: norm_outflow = (norm_storage <= 0.6050f) ? 0.0151f * norm_storage + 0.0000f : 6.4895f * norm_storage + (0.0151f * 0.6050f + 0.0000f - 6.4895f * 0.6050f); break;
        case  8: norm_outflow = (norm_storage <= 0.6040f) ? 0.0135f * norm_storage + 0.0000f : 5.1180f * norm_storage + (0.0135f * 0.6040f + 0.0000f - 5.1180f * 0.6040f); break;
        case  9: norm_outflow = (norm_storage <= 0.6040f) ? 0.0165f * norm_storage + 0.0005f : 6.2070f * norm_storage + (0.0165f * 0.6040f + 0.0005f - 6.2070f * 0.6040f); break;
        case 10: norm_outflow = (norm_storage <= 0.6058f) ? 0.0000f * norm_storage + 0.0118f : 6.2259f * norm_storage + (0.0000f * 0.6058f + 0.0118f - 6.2259f * 0.6058f); break;
        case 11: norm_outflow = (norm_storage <= 0.6063f) ? 0.0000f * norm_storage + 0.0118f : 6.1154f * norm_storage + (0.0000f * 0.6063f + 0.0118f - 6.1154f * 0.6063f); break;
        case 12: norm_outflow = (norm_storage <= 0.6061f) ? 0.0154f * norm_storage + 0.0000f : 6.4161f * norm_storage + (0.0154f * 0.6061f + 0.0000f - 6.4161f * 0.6061f); break;
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
        case  3: norm_outflow = (norm_storage <= 1.0000f) ? 0.5659f * norm_storage + -0.2246f : 0.0000f * norm_storage + (0.5659f * 1.0000f + -0.2246f - 0.0000f * 1.0000f); break;
        case  4: norm_outflow = (norm_storage <= 1.0000f) ? 0.6419f * norm_storage + -0.2668f : 0.0000f * norm_storage + (0.6419f * 1.0000f + -0.2668f - 0.0000f * 1.0000f); break;
        case  5: norm_outflow = (norm_storage <= 1.0000f) ? 0.7356f * norm_storage + -0.3075f : 0.0000f * norm_storage + (0.7356f * 1.0000f + -0.3075f - 0.0000f * 1.0000f); break;
        case  6: norm_outflow = (norm_storage <= 1.0000f) ? 0.7080f * norm_storage + -0.2949f : 0.0000f * norm_storage + (0.7080f * 1.0000f + -0.2949f - 0.0000f * 1.0000f); break;
        case  7: norm_outflow = (norm_storage <= 1.0000f) ? 0.5233f * norm_storage + -0.2149f : 0.0000f * norm_storage + (0.5233f * 1.0000f + -0.2149f - 0.0000f * 1.0000f); break;
        case  8: norm_outflow = 1.4170f * norm_inflow + 0.0224f; break;
        case  9: norm_outflow = (norm_storage <= 1.0000f) ? 0.4686f * norm_storage + -0.2010f : 0.0000f * norm_storage + (0.4686f * 1.0000f + -0.2010f - 0.0000f * 1.0000f); break;
        case 10: norm_outflow = 0.9884f * norm_inflow + 0.0205f; break;
        case 11: norm_outflow = (norm_storage <= 1.0000f) ? 0.6351f * norm_storage + -0.2736f : 0.0000f * norm_storage + (0.6351f * 1.0000f + -0.2736f - 0.0000f * 1.0000f); break;
        case 12: norm_outflow = (norm_storage <= 1.0000f) ? 0.4523f * norm_storage + -0.1857f : 0.0000f * norm_storage + (0.4523f * 1.0000f + -0.1857f - 0.0000f * 1.0000f); break;
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
        case  1: norm_outflow = (norm_storage <= 1.0000f) ? 0.1859f * norm_storage + -0.0422f : 0.0000f * norm_storage + (0.1859f * 1.0000f + -0.0422f - 0.0000f * 1.0000f); break;
        case  2: norm_outflow = (norm_storage <= 1.0000f) ? 0.3444f * norm_storage + -0.0782f : 0.0000f * norm_storage + (0.3444f * 1.0000f + -0.0782f - 0.0000f * 1.0000f); break;
        case  3: norm_outflow = (norm_storage <= 1.0000f) ? 0.8952f * norm_storage + -0.2302f : 0.0000f * norm_storage + (0.8952f * 1.0000f + -0.2302f - 0.0000f * 1.0000f); break;
        case  4: norm_outflow = (norm_storage <= 1.0000f) ? 1.1575f * norm_storage + -0.3144f : 0.0000f * norm_storage + (1.1575f * 1.0000f + -0.3144f - 0.0000f * 1.0000f); break;
        case  5: norm_outflow = (norm_storage <= 1.0000f) ? 1.2464f * norm_storage + -0.3480f : 0.0000f * norm_storage + (1.2464f * 1.0000f + -0.3480f - 0.0000f * 1.0000f); break;
        case  6: norm_outflow = (norm_storage <= 1.0000f) ? 1.2966f * norm_storage + -0.3677f : 0.0000f * norm_storage + (1.2966f * 1.0000f + -0.3677f - 0.0000f * 1.0000f); break;
        case  7: norm_outflow = (norm_storage <= 1.0000f) ? 0.9265f * norm_storage + -0.2584f : 0.0000f * norm_storage + (0.9265f * 1.0000f + -0.2584f - 0.0000f * 1.0000f); break;
        case  8: norm_outflow = (norm_storage <= 1.0000f) ? 1.5195f * norm_storage + -0.4489f : 0.0000f * norm_storage + (1.5195f * 1.0000f + -0.4489f - 0.0000f * 1.0000f); break;
        case  9: norm_outflow = (norm_storage <= 1.0000f) ? 0.8260f * norm_storage + -0.2361f : 0.0000f * norm_storage + (0.8260f * 1.0000f + -0.2361f - 0.0000f * 1.0000f); break;
        case 10: norm_outflow = (norm_storage <= 1.0000f) ? 0.7269f * norm_storage + -0.2013f : 0.0000f * norm_storage + (0.7269f * 1.0000f + -0.2013f - 0.0000f * 1.0000f); break;
        case 11: norm_outflow = (norm_storage <= 1.0000f) ? 0.6194f * norm_storage + -0.1640f : 0.0000f * norm_storage + (0.6194f * 1.0000f + -0.1640f - 0.0000f * 1.0000f); break;
        case 12: norm_outflow = (norm_storage <= 1.0000f) ? 0.2975f * norm_storage + -0.0724f : 0.0000f * norm_storage + (0.2975f * 1.0000f + -0.0724f - 0.0000f * 1.0000f); break;
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
        case  1: norm_outflow = (norm_storage <= 1.0000f) ? 0.7404f * norm_storage + -0.1807f : 0.0000f * norm_storage + (0.7404f * 1.0000f + -0.1807f - 0.0000f * 1.0000f); break;
        case  2: norm_outflow = (norm_storage <= 1.0000f) ? 0.9635f * norm_storage + -0.2434f : 0.0000f * norm_storage + (0.9635f * 1.0000f + -0.2434f - 0.0000f * 1.0000f); break;
        case  3: norm_outflow = (norm_storage <= 1.0000f) ? 1.3738f * norm_storage + -0.3617f : 0.0000f * norm_storage + (1.3738f * 1.0000f + -0.3617f - 0.0000f * 1.0000f); break;
        case  4: norm_outflow = (norm_storage <= 1.0000f) ? 0.8595f * norm_storage + -0.2177f : 0.0000f * norm_storage + (0.8595f * 1.0000f + -0.2177f - 0.0000f * 1.0000f); break;
        case  5: norm_outflow = (norm_storage <= 1.0000f) ? 1.1299f * norm_storage + -0.3171f : 0.0000f * norm_storage + (1.1299f * 1.0000f + -0.3171f - 0.0000f * 1.0000f); break;
        case  6: norm_outflow = (norm_storage <= 1.0000f) ? 1.3472f * norm_storage + -0.3739f : 0.0000f * norm_storage + (1.3472f * 1.0000f + -0.3739f - 0.0000f * 1.0000f); break;
        case  7: norm_outflow = (norm_storage <= 1.0000f) ? 0.9199f * norm_storage + -0.2411f : 0.0000f * norm_storage + (0.9199f * 1.0000f + -0.2411f - 0.0000f * 1.0000f); break;
        case  8: norm_outflow = (norm_storage <= 1.0000f) ? 0.7406f * norm_storage + -0.2154f : 0.0000f * norm_storage + (0.7406f * 1.0000f + -0.2154f - 0.0000f * 1.0000f); break;
        case  9: norm_outflow = (norm_storage <= 1.0000f) ? 0.6077f * norm_storage + -0.1737f : 0.0000f * norm_storage + (0.6077f * 1.0000f + -0.1737f - 0.0000f * 1.0000f); break;
        case 10: norm_outflow = (norm_storage <= 1.0000f) ? 0.5857f * norm_storage + -0.1637f : 0.0000f * norm_storage + (0.5857f * 1.0000f + -0.1637f - 0.0000f * 1.0000f); break;
        case 11: norm_outflow = (norm_storage <= 1.0000f) ? 1.0060f * norm_storage + -0.2826f : 0.0000f * norm_storage + (1.0060f * 1.0000f + -0.2826f - 0.0000f * 1.0000f); break;
        case 12: norm_outflow = (norm_storage <= 1.0000f) ? 1.0441f * norm_storage + -0.2694f : 0.0000f * norm_storage + (1.0441f * 1.0000f + -0.2694f - 0.0000f * 1.0000f); break;
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
        case  4: norm_outflow = (norm_storage <= 1.0000f) ? 0.7890f * norm_storage + -0.0871f : 0.0000f * norm_storage + (0.7890f * 1.0000f + -0.0871f - 0.0000f * 1.0000f); break;
        case  5: norm_outflow = (norm_storage <= 1.0000f) ? 1.1852f * norm_storage + -0.1442f : 0.0000f * norm_storage + (1.1852f * 1.0000f + -0.1442f - 0.0000f * 1.0000f); break;
        case  6: norm_outflow = (norm_storage <= 1.0000f) ? 1.5662f * norm_storage + -0.2015f : 0.0000f * norm_storage + (1.5662f * 1.0000f + -0.2015f - 0.0000f * 1.0000f); break;
        case  7: norm_outflow = (norm_storage <= 1.0000f) ? 0.9283f * norm_storage + -0.1191f : 0.0000f * norm_storage + (0.9283f * 1.0000f + -0.1191f - 0.0000f * 1.0000f); break;
        case  8: norm_outflow = (norm_storage <= 1.0000f) ? 1.1523f * norm_storage + -0.1340f : 0.0000f * norm_storage + (1.1523f * 1.0000f + -0.1340f - 0.0000f * 1.0000f); break;
        case  9: norm_outflow = (norm_storage <= 1.0000f) ? 1.0689f * norm_storage + -0.1225f : 0.0000f * norm_storage + (1.0689f * 1.0000f + -0.1225f - 0.0000f * 1.0000f); break;
        case 10: norm_outflow = 1.5887f * norm_inflow + 0.0138f; break;
        case 11: norm_outflow = (norm_storage <= 1.0000f) ? 0.4081f * norm_storage + -0.0417f : 0.0000f * norm_storage + (0.4081f * 1.0000f + -0.0417f - 0.0000f * 1.0000f); break;
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
        case  1: norm_outflow = (norm_storage <= 1.0000f) ? 1.0283f * norm_storage + -0.4157f : 0.0000f * norm_storage + (1.0283f * 1.0000f + -0.4157f - 0.0000f * 1.0000f); break;
        case  2: norm_outflow = (norm_storage <= 1.0000f) ? 0.8767f * norm_storage + -0.3496f : 0.0000f * norm_storage + (0.8767f * 1.0000f + -0.3496f - 0.0000f * 1.0000f); break;
        case  3: norm_outflow = (norm_storage <= 1.0000f) ? 1.4791f * norm_storage + -0.6075f : 0.0000f * norm_storage + (1.4791f * 1.0000f + -0.6075f - 0.0000f * 1.0000f); break;
        case  4: norm_outflow = (norm_storage <= 1.0000f) ? 1.0780f * norm_storage + -0.4576f : 0.0000f * norm_storage + (1.0780f * 1.0000f + -0.4576f - 0.0000f * 1.0000f); break;
        case  5: norm_outflow = (norm_storage <= 1.0000f) ? 1.3836f * norm_storage + -0.6135f : 0.0000f * norm_storage + (1.3836f * 1.0000f + -0.6135f - 0.0000f * 1.0000f); break;
        case  6: norm_outflow = (norm_storage <= 1.0000f) ? 1.6831f * norm_storage + -0.7375f : 0.0000f * norm_storage + (1.6831f * 1.0000f + -0.7375f - 0.0000f * 1.0000f); break;
        case  7: norm_outflow = (norm_storage <= 1.0000f) ? 1.5281f * norm_storage + -0.6803f : 0.0000f * norm_storage + (1.5281f * 1.0000f + -0.6803f - 0.0000f * 1.0000f); break;
        case  8: norm_outflow = (norm_storage <= 1.0000f) ? 1.0408f * norm_storage + -0.4712f : 0.0000f * norm_storage + (1.0408f * 1.0000f + -0.4712f - 0.0000f * 1.0000f); break;
        case  9: norm_outflow = (norm_storage <= 1.0000f) ? 1.1830f * norm_storage + -0.5387f : 0.0000f * norm_storage + (1.1830f * 1.0000f + -0.5387f - 0.0000f * 1.0000f); break;
        case 10: norm_outflow = (norm_storage <= 1.0000f) ? 0.6822f * norm_storage + -0.3031f : 0.0000f * norm_storage + (0.6822f * 1.0000f + -0.3031f - 0.0000f * 1.0000f); break;
        case 11: norm_outflow = (norm_storage <= 1.0000f) ? 1.3488f * norm_storage + -0.5974f : 0.0000f * norm_storage + (1.3488f * 1.0000f + -0.5974f - 0.0000f * 1.0000f); break;
        case 12: norm_outflow = (norm_storage <= 1.0000f) ? 1.2730f * norm_storage + -0.5248f : 0.0000f * norm_storage + (1.2730f * 1.0000f + -0.5248f - 0.0000f * 1.0000f); break;
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
        case  2: norm_outflow = (norm_storage <= 0.6000f) ? 0.0180f * norm_storage + 0.0000f : 4.3525f * norm_storage + (0.0180f * 0.6000f + 0.0000f - 4.3525f * 0.6000f); break;
        case  3: norm_outflow = (norm_storage <= 0.6000f) ? 0.0212f * norm_storage + 0.0000f : 2.6812f * norm_storage + (0.0212f * 0.6000f + 0.0000f - 2.6812f * 0.6000f); break;
        case  4: norm_outflow = (norm_storage <= 0.6000f) ? 0.0292f * norm_storage + 0.0000f : 3.1834f * norm_storage + (0.0292f * 0.6000f + 0.0000f - 3.1834f * 0.6000f); break;
        case  5: norm_outflow = (norm_storage <= 1.0000f) ? 0.5245f * norm_storage + -0.2446f : 0.0000f * norm_storage + (0.5245f * 1.0000f + -0.2446f - 0.0000f * 1.0000f); break;
        case  6: norm_outflow = (norm_storage <= 1.0000f) ? 0.3932f * norm_storage + -0.1823f : 0.0000f * norm_storage + (0.3932f * 1.0000f + -0.1823f - 0.0000f * 1.0000f); break;
        case  7: norm_outflow = (norm_storage <= 0.6000f) ? 0.0297f * norm_storage + 0.0000f : 1.3970f * norm_storage + (0.0297f * 0.6000f + 0.0000f - 1.3970f * 0.6000f); break;
        case  8: norm_outflow = (norm_storage <= 0.6000f) ? 0.0199f * norm_storage + 0.0000f : 1.2320f * norm_storage + (0.0199f * 0.6000f + 0.0000f - 1.2320f * 0.6000f); break;
        case  9: norm_outflow = (norm_storage <= 0.6000f) ? 0.0111f * norm_storage + 0.0000f : 3.2225f * norm_storage + (0.0111f * 0.6000f + 0.0000f - 3.2225f * 0.6000f); break;
        case 10: norm_outflow = (norm_storage <= 0.6000f) ? 0.0134f * norm_storage + 0.0000f : 1.1227f * norm_storage + (0.0134f * 0.6000f + 0.0000f - 1.1227f * 0.6000f); break;
        case 11: norm_outflow = (norm_storage <= 0.6000f) ? 0.0127f * norm_storage + 0.0000f : 1.0010f * norm_storage + (0.0127f * 0.6000f + 0.0000f - 1.0010f * 0.6000f); break;
        case 12: norm_outflow = (norm_storage <= 0.6000f) ? 0.0252f * norm_storage + 0.0000f : 3.0330f * norm_storage + (0.0252f * 0.6000f + 0.0000f - 3.0330f * 0.6000f); break;
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
        case  2: norm_outflow = (norm_storage <= 0.9724f) ? 0.0000f * norm_storage + 0.0143f : 0.9164f * norm_storage + (0.0000f * 0.9724f + 0.0143f - 0.9164f * 0.9724f); break;
        case  3: norm_outflow = 0.4307f * norm_inflow + 0.0159f; break;
        case  4: norm_outflow = (norm_storage <= 1.0000f) ? 0.1012f * norm_storage + -0.0103f : 0.0000f * norm_storage + (0.1012f * 1.0000f + -0.0103f - 0.0000f * 1.0000f); break;
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
        case  1: norm_outflow = (norm_storage <= 1.0000f) ? 2.9884f * norm_storage + -0.6658f : 0.0000f * norm_storage + (2.9884f * 1.0000f + -0.6658f - 0.0000f * 1.0000f); break;
        case  2: norm_outflow = (norm_storage <= 1.0000f) ? 2.7574f * norm_storage + -0.5881f : 0.0000f * norm_storage + (2.7574f * 1.0000f + -0.5881f - 0.0000f * 1.0000f); break;
        case  3: norm_outflow = (norm_storage <= 1.0000f) ? 2.0523f * norm_storage + -0.3912f : 0.0000f * norm_storage + (2.0523f * 1.0000f + -0.3912f - 0.0000f * 1.0000f); break;
        case  4: norm_outflow = (norm_storage <= 1.0000f) ? 1.3096f * norm_storage + -0.1822f : 0.0000f * norm_storage + (1.3096f * 1.0000f + -0.1822f - 0.0000f * 1.0000f); break;
        case  5: norm_outflow = (norm_storage <= 1.0000f) ? 1.1281f * norm_storage + -0.1442f : 0.0000f * norm_storage + (1.1281f * 1.0000f + -0.1442f - 0.0000f * 1.0000f); break;
        case  6: norm_outflow = (norm_storage <= 1.0000f) ? 1.3810f * norm_storage + -0.2039f : 0.0000f * norm_storage + (1.3810f * 1.0000f + -0.2039f - 0.0000f * 1.0000f); break;
        case  7: norm_outflow = (norm_storage <= 1.0000f) ? 1.2134f * norm_storage + -0.2007f : 0.0000f * norm_storage + (1.2134f * 1.0000f + -0.2007f - 0.0000f * 1.0000f); break;
        case  8: norm_outflow = (norm_storage <= 1.0000f) ? 0.8272f * norm_storage + -0.1416f : 0.0000f * norm_storage + (0.8272f * 1.0000f + -0.1416f - 0.0000f * 1.0000f); break;
        case  9: norm_outflow = (norm_storage <= 1.0000f) ? 0.9276f * norm_storage + -0.1827f : 0.0000f * norm_storage + (0.9276f * 1.0000f + -0.1827f - 0.0000f * 1.0000f); break;
        case 10: norm_outflow = (norm_storage <= 1.0000f) ? 1.3726f * norm_storage + -0.2887f : 0.0000f * norm_storage + (1.3726f * 1.0000f + -0.2887f - 0.0000f * 1.0000f); break;
        case 11: norm_outflow = (norm_storage <= 1.0000f) ? 2.5052f * norm_storage + -0.5522f : 0.0000f * norm_storage + (2.5052f * 1.0000f + -0.5522f - 0.0000f * 1.0000f); break;
        case 12: norm_outflow = (norm_storage <= 1.0000f) ? 2.7511f * norm_storage + -0.5995f : 0.0000f * norm_storage + (2.7511f * 1.0000f + -0.5995f - 0.0000f * 1.0000f); break;
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
        case  1: norm_outflow = (norm_storage <= 1.0000f) ? 1.1763f * norm_storage + -0.0864f : 0.0000f * norm_storage + (1.1763f * 1.0000f + -0.0864f - 0.0000f * 1.0000f); break;
        case  2: norm_outflow = (norm_storage <= 1.0000f) ? 0.9510f * norm_storage + -0.0542f : 0.0000f * norm_storage + (0.9510f * 1.0000f + -0.0542f - 0.0000f * 1.0000f); break;
        case  3: norm_outflow = (norm_storage <= 1.0000f) ? 1.3781f * norm_storage + -0.0789f : 0.0000f * norm_storage + (1.3781f * 1.0000f + -0.0789f - 0.0000f * 1.0000f); break;
        case  4: norm_outflow = (norm_storage <= 1.0000f) ? 1.0210f * norm_storage + -0.0380f : 0.0000f * norm_storage + (1.0210f * 1.0000f + -0.0380f - 0.0000f * 1.0000f); break;
        case  5: norm_outflow = (norm_storage <= 1.0000f) ? 0.6562f * norm_storage + 0.0024f : 0.0000f * norm_storage + (0.6562f * 1.0000f + 0.0024f - 0.0000f * 1.0000f); break;
        case  6: norm_outflow = (norm_storage <= 1.0000f) ? 0.7354f * norm_storage + 0.0058f : 0.0000f * norm_storage + (0.7354f * 1.0000f + 0.0058f - 0.0000f * 1.0000f); break;
        case  7: norm_outflow = (norm_storage <= 1.0000f) ? 0.7416f * norm_storage + -0.0109f : 0.0000f * norm_storage + (0.7416f * 1.0000f + -0.0109f - 0.0000f * 1.0000f); break;
        case  8: norm_outflow = (norm_storage <= 1.0000f) ? 0.8325f * norm_storage + -0.0353f : 0.0000f * norm_storage + (0.8325f * 1.0000f + -0.0353f - 0.0000f * 1.0000f); break;
        case  9: norm_outflow = (norm_storage <= 1.0000f) ? 1.1969f * norm_storage + -0.0733f : 0.0000f * norm_storage + (1.1969f * 1.0000f + -0.0733f - 0.0000f * 1.0000f); break;
        case 10: norm_outflow = (norm_storage <= 1.0000f) ? 0.6689f * norm_storage + -0.0378f : 0.0000f * norm_storage + (0.6689f * 1.0000f + -0.0378f - 0.0000f * 1.0000f); break;
        case 11: norm_outflow = (norm_storage <= 1.0000f) ? 0.9711f * norm_storage + -0.0721f : 0.0000f * norm_storage + (0.9711f * 1.0000f + -0.0721f - 0.0000f * 1.0000f); break;
        case 12: norm_outflow = (norm_storage <= 1.0000f) ? 0.9579f * norm_storage + -0.0681f : 0.0000f * norm_storage + (0.9579f * 1.0000f + -0.0681f - 0.0000f * 1.0000f); break;
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
        case  3: norm_outflow = (norm_storage <= 1.0000f) ? -0.8156f * norm_storage + 0.8233f : 0.0000f * norm_storage + (-0.8156f * 1.0000f + 0.8233f - 0.0000f * 1.0000f); break;
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
        case  1: norm_outflow = (norm_storage <= 0.7504f) ? 0.0012f * norm_storage + 0.0004f : 44.8410f * norm_storage + (0.0012f * 0.7504f + 0.0004f - 44.8410f * 0.7504f); break;
        case  2: norm_outflow = (norm_storage <= 0.6785f) ? 0.0050f * norm_storage + 0.0000f : 0.9923f * norm_storage + (0.0050f * 0.6785f + 0.0000f - 0.9923f * 0.6785f); break;
        case  3: norm_outflow = (norm_storage <= 0.6000f) ? 0.0135f * norm_storage + 0.0020f : 0.7261f * norm_storage + (0.0135f * 0.6000f + 0.0020f - 0.7261f * 0.6000f); break;
        case  4: norm_outflow = (norm_storage <= 1.0000f) ? 0.1821f * norm_storage + 0.0577f : 0.0000f * norm_storage + (0.1821f * 1.0000f + 0.0577f - 0.0000f * 1.0000f); break;
        case  5: norm_outflow = (norm_storage <= 0.7367f) ? 0.1000f * norm_storage + 0.1163f : 2.7971f * norm_storage + (0.1000f * 0.7367f + 0.1163f - 2.7971f * 0.7367f); break;
        case  6: norm_outflow = (norm_storage <= 0.6990f) ? 0.1000f * norm_storage + 0.1685f : 4.4741f * norm_storage + (0.1000f * 0.6990f + 0.1685f - 4.4741f * 0.6990f); break;
        case  7: norm_outflow = 4.4922f * norm_inflow + 0.1722f; break;
        case  8: norm_outflow = (norm_storage <= 0.7587f) ? 0.1000f * norm_storage + 0.1014f : 28.5190f * norm_storage + (0.1000f * 0.7587f + 0.1014f - 28.5190f * 0.7587f); break;
        case  9: norm_outflow = (norm_storage <= 1.0000f) ? 0.1525f * norm_storage + 0.0571f : 0.0000f * norm_storage + (0.1525f * 1.0000f + 0.0571f - 0.0000f * 1.0000f); break;
        case 10: norm_outflow = 2.7364f * norm_inflow + 0.0377f; break;
        case 11: norm_outflow = (norm_storage <= 1.0000f) ? 0.0327f * norm_storage + -0.0017f : 0.0000f * norm_storage + (0.0327f * 1.0000f + -0.0017f - 0.0000f * 1.0000f); break;
        case 12: norm_outflow = (norm_storage <= 0.7479f) ? 0.0021f * norm_storage + 0.0002f : 25.9836f * norm_storage + (0.0021f * 0.7479f + 0.0002f - 25.9836f * 0.7479f); break;
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
        case  1: norm_outflow = (norm_storage <= 1.0000f) ? 3.1370f * norm_storage + -1.3854f : 0.0000f * norm_storage + (3.1370f * 1.0000f + -1.3854f - 0.0000f * 1.0000f); break;
        case  2: norm_outflow = (norm_storage <= 1.0000f) ? 2.7667f * norm_storage + -1.1967f : 0.0000f * norm_storage + (2.7667f * 1.0000f + -1.1967f - 0.0000f * 1.0000f); break;
        case  3: norm_outflow = (norm_storage <= 1.0000f) ? 2.6863f * norm_storage + -1.1536f : 0.0000f * norm_storage + (2.6863f * 1.0000f + -1.1536f - 0.0000f * 1.0000f); break;
        case  4: norm_outflow = (norm_storage <= 1.0000f) ? 2.3079f * norm_storage + -0.9696f : 0.0000f * norm_storage + (2.3079f * 1.0000f + -0.9696f - 0.0000f * 1.0000f); break;
        case  5: norm_outflow = (norm_storage <= 1.0000f) ? 2.0411f * norm_storage + -0.8651f : 0.0000f * norm_storage + (2.0411f * 1.0000f + -0.8651f - 0.0000f * 1.0000f); break;
        case  6: norm_outflow = (norm_storage <= 1.0000f) ? 2.1741f * norm_storage + -0.9305f : 0.0000f * norm_storage + (2.1741f * 1.0000f + -0.9305f - 0.0000f * 1.0000f); break;
        case  7: norm_outflow = (norm_storage <= 1.0000f) ? 2.5092f * norm_storage + -1.1602f : 0.0000f * norm_storage + (2.5092f * 1.0000f + -1.1602f - 0.0000f * 1.0000f); break;
        case  8: norm_outflow = (norm_storage <= 1.0000f) ? 4.2531f * norm_storage + -1.9945f : 0.0000f * norm_storage + (4.2531f * 1.0000f + -1.9945f - 0.0000f * 1.0000f); break;
        case  9: norm_outflow = (norm_storage <= 1.0000f) ? 1.8369f * norm_storage + -0.8334f : 0.0000f * norm_storage + (1.8369f * 1.0000f + -0.8334f - 0.0000f * 1.0000f); break;
        case 10: norm_outflow = (norm_storage <= 1.0000f) ? 1.4575f * norm_storage + -0.6387f : 0.0000f * norm_storage + (1.4575f * 1.0000f + -0.6387f - 0.0000f * 1.0000f); break;
        case 11: norm_outflow = (norm_storage <= 1.0000f) ? 3.1059f * norm_storage + -1.3955f : 0.0000f * norm_storage + (3.1059f * 1.0000f + -1.3955f - 0.0000f * 1.0000f); break;
        case 12: norm_outflow = (norm_storage <= 1.0000f) ? 3.2562f * norm_storage + -1.4622f : 0.0000f * norm_storage + (3.2562f * 1.0000f + -1.4622f - 0.0000f * 1.0000f); break;
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
        case  1: norm_outflow = (norm_storage <= 0.6742f) ? 0.0124f * norm_storage + 0.0000f : 2.9335f * norm_storage + (0.0124f * 0.6742f + 0.0000f - 2.9335f * 0.6742f); break;
        case  2: norm_outflow = (norm_storage <= 0.6741f) ? 0.0175f * norm_storage + 0.0000f : 3.1055f * norm_storage + (0.0175f * 0.6741f + 0.0000f - 3.1055f * 0.6741f); break;
        case  3: norm_outflow = (norm_storage <= 0.6503f) ? 0.0140f * norm_storage + 0.0020f : 1.0379f * norm_storage + (0.0140f * 0.6503f + 0.0020f - 1.0379f * 0.6503f); break;
        case  4: norm_outflow = (norm_storage <= 0.6646f) ? 0.0026f * norm_storage + 0.0000f : 1.9661f * norm_storage + (0.0026f * 0.6646f + 0.0000f - 1.9661f * 0.6646f); break;
        case  5: norm_outflow = (norm_storage <= 0.6580f) ? 0.0003f * norm_storage + 0.0016f : 1.8056f * norm_storage + (0.0003f * 0.6580f + 0.0016f - 1.8056f * 0.6580f); break;
        case  6: norm_outflow = (norm_storage <= 0.6493f) ? 0.0006f * norm_storage + 0.0019f : 1.2204f * norm_storage + (0.0006f * 0.6493f + 0.0019f - 1.2204f * 0.6493f); break;
        case  7: norm_outflow = (norm_storage <= 0.6521f) ? 0.0028f * norm_storage + 0.0009f : 1.0541f * norm_storage + (0.0028f * 0.6521f + 0.0009f - 1.0541f * 0.6521f); break;
        case  8: norm_outflow = (norm_storage <= 0.6823f) ? 0.0069f * norm_storage + 0.0000f : 2.9571f * norm_storage + (0.0069f * 0.6823f + 0.0000f - 2.9571f * 0.6823f); break;
        case  9: norm_outflow = (norm_storage <= 0.6761f) ? 0.0014f * norm_storage + 0.0023f : 3.5412f * norm_storage + (0.0014f * 0.6761f + 0.0023f - 3.5412f * 0.6761f); break;
        case 10: norm_outflow = (norm_storage <= 0.6625f) ? 0.0003f * norm_storage + 0.0017f : 1.8977f * norm_storage + (0.0003f * 0.6625f + 0.0017f - 1.8977f * 0.6625f); break;
        case 11: norm_outflow = (norm_storage <= 0.6623f) ? 0.0000f * norm_storage + 0.0013f : 2.3164f * norm_storage + (0.0000f * 0.6623f + 0.0013f - 2.3164f * 0.6623f); break;
        case 12: norm_outflow = (norm_storage <= 0.6724f) ? 0.0159f * norm_storage + 0.0000f : 2.6008f * norm_storage + (0.0159f * 0.6724f + 0.0000f - 2.6008f * 0.6724f); break;
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
        case  1: norm_outflow = (norm_storage <= 1.0000f) ? 0.4601f * norm_storage + -0.0329f : 0.0000f * norm_storage + (0.4601f * 1.0000f + -0.0329f - 0.0000f * 1.0000f); break;
        case  2: norm_outflow = (norm_storage <= 1.0000f) ? 0.4566f * norm_storage + -0.0274f : 0.0000f * norm_storage + (0.4566f * 1.0000f + -0.0274f - 0.0000f * 1.0000f); break;
        case  3: norm_outflow = (norm_storage <= 1.0000f) ? 0.4870f * norm_storage + -0.0263f : 0.0000f * norm_storage + (0.4870f * 1.0000f + -0.0263f - 0.0000f * 1.0000f); break;
        case  4: norm_outflow = (norm_storage <= 1.0000f) ? 0.5099f * norm_storage + -0.0276f : 0.0000f * norm_storage + (0.5099f * 1.0000f + -0.0276f - 0.0000f * 1.0000f); break;
        case  5: norm_outflow = (norm_storage <= 1.0000f) ? 0.3580f * norm_storage + -0.0150f : 0.0000f * norm_storage + (0.3580f * 1.0000f + -0.0150f - 0.0000f * 1.0000f); break;
        case  6: norm_outflow = (norm_storage <= 1.0000f) ? 0.3383f * norm_storage + -0.0123f : 0.0000f * norm_storage + (0.3383f * 1.0000f + -0.0123f - 0.0000f * 1.0000f); break;
        case  7: norm_outflow = (norm_storage <= 1.0000f) ? 0.3704f * norm_storage + -0.0251f : 0.0000f * norm_storage + (0.3704f * 1.0000f + -0.0251f - 0.0000f * 1.0000f); break;
        case  8: norm_outflow = (norm_storage <= 1.0000f) ? 0.5179f * norm_storage + -0.0409f : 0.0000f * norm_storage + (0.5179f * 1.0000f + -0.0409f - 0.0000f * 1.0000f); break;
        case  9: norm_outflow = (norm_storage <= 1.0000f) ? 0.5778f * norm_storage + -0.0452f : 0.0000f * norm_storage + (0.5778f * 1.0000f + -0.0452f - 0.0000f * 1.0000f); break;
        case 10: norm_outflow = (norm_storage <= 1.0000f) ? 0.4074f * norm_storage + -0.0304f : 0.0000f * norm_storage + (0.4074f * 1.0000f + -0.0304f - 0.0000f * 1.0000f); break;
        case 11: norm_outflow = (norm_storage <= 1.0000f) ? 0.6610f * norm_storage + -0.0552f : 0.0000f * norm_storage + (0.6610f * 1.0000f + -0.0552f - 0.0000f * 1.0000f); break;
        case 12: norm_outflow = (norm_storage <= 1.0000f) ? 0.4052f * norm_storage + -0.0284f : 0.0000f * norm_storage + (0.4052f * 1.0000f + -0.0284f - 0.0000f * 1.0000f); break;
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
        case  1: norm_outflow = (norm_storage <= 1.0000f) ? 2.0376f * norm_storage + -1.1032f : 0.0000f * norm_storage + (2.0376f * 1.0000f + -1.1032f - 0.0000f * 1.0000f); break;
        case  2: norm_outflow = (norm_storage <= 1.0000f) ? 1.8546f * norm_storage + -0.9961f : 0.0000f * norm_storage + (1.8546f * 1.0000f + -0.9961f - 0.0000f * 1.0000f); break;
        case  3: norm_outflow = (norm_storage <= 1.0000f) ? 1.7892f * norm_storage + -0.9891f : 0.0000f * norm_storage + (1.7892f * 1.0000f + -0.9891f - 0.0000f * 1.0000f); break;
        case  4: norm_outflow = (norm_storage <= 1.0000f) ? 1.7794f * norm_storage + -0.9897f : 0.0000f * norm_storage + (1.7794f * 1.0000f + -0.9897f - 0.0000f * 1.0000f); break;
        case  5: norm_outflow = (norm_storage <= 1.0000f) ? 1.5776f * norm_storage + -0.8561f : 0.0000f * norm_storage + (1.5776f * 1.0000f + -0.8561f - 0.0000f * 1.0000f); break;
        case  6: norm_outflow = (norm_storage <= 1.0000f) ? 2.2341f * norm_storage + -1.3041f : 0.0000f * norm_storage + (2.2341f * 1.0000f + -1.3041f - 0.0000f * 1.0000f); break;
        case  7: norm_outflow = (norm_storage <= 0.6691f) ? 0.1000f * norm_storage + 0.0600f : 2.9111f * norm_storage + (0.1000f * 0.6691f + 0.0600f - 2.9111f * 0.6691f); break;
        case  8: norm_outflow = (norm_storage <= 1.0000f) ? 1.3086f * norm_storage + -0.6532f : 0.0000f * norm_storage + (1.3086f * 1.0000f + -0.6532f - 0.0000f * 1.0000f); break;
        case  9: norm_outflow = 0.0092f * norm_inflow + 0.0968f; break;
        case 10: norm_outflow = (norm_storage <= 0.6948f) ? 0.1000f * norm_storage + 0.0005f : 2.7475f * norm_storage + (0.1000f * 0.6948f + 0.0005f - 2.7475f * 0.6948f); break;
        case 11: norm_outflow = (norm_storage <= 0.6547f) ? 0.1000f * norm_storage + 0.0028f : 3.4580f * norm_storage + (0.1000f * 0.6547f + 0.0028f - 3.4580f * 0.6547f); break;
        case 12: norm_outflow = (norm_storage <= 1.0000f) ? 1.8548f * norm_storage + -0.9953f : 0.0000f * norm_storage + (1.8548f * 1.0000f + -0.9953f - 0.0000f * 1.0000f); break;
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
        case  1: norm_outflow = (norm_storage <= 1.0000f) ? 1.7233f * norm_storage + -0.1233f : 0.0000f * norm_storage + (1.7233f * 1.0000f + -0.1233f - 0.0000f * 1.0000f); break;
        case  2: norm_outflow = (norm_storage <= 1.0000f) ? 1.7847f * norm_storage + -0.1185f : 0.0000f * norm_storage + (1.7847f * 1.0000f + -0.1185f - 0.0000f * 1.0000f); break;
        case  3: norm_outflow = (norm_storage <= 1.0000f) ? 1.9136f * norm_storage + -0.1166f : 0.0000f * norm_storage + (1.9136f * 1.0000f + -0.1166f - 0.0000f * 1.0000f); break;
        case  4: norm_outflow = (norm_storage <= 1.0000f) ? 2.0370f * norm_storage + -0.1236f : 0.0000f * norm_storage + (2.0370f * 1.0000f + -0.1236f - 0.0000f * 1.0000f); break;
        case  5: norm_outflow = (norm_storage <= 1.0000f) ? 0.6261f * norm_storage + 0.0211f : 0.0000f * norm_storage + (0.6261f * 1.0000f + 0.0211f - 0.0000f * 1.0000f); break;
        case  6: norm_outflow = (norm_storage <= 1.0000f) ? 0.6770f * norm_storage + 0.0091f : 0.0000f * norm_storage + (0.6770f * 1.0000f + 0.0091f - 0.0000f * 1.0000f); break;
        case  7: norm_outflow = (norm_storage <= 1.0000f) ? 1.0405f * norm_storage + -0.0467f : 0.0000f * norm_storage + (1.0405f * 1.0000f + -0.0467f - 0.0000f * 1.0000f); break;
        case  8: norm_outflow = (norm_storage <= 1.0000f) ? 1.5737f * norm_storage + -0.1242f : 0.0000f * norm_storage + (1.5737f * 1.0000f + -0.1242f - 0.0000f * 1.0000f); break;
        case  9: norm_outflow = (norm_storage <= 1.0000f) ? 1.4399f * norm_storage + -0.1077f : 0.0000f * norm_storage + (1.4399f * 1.0000f + -0.1077f - 0.0000f * 1.0000f); break;
        case 10: norm_outflow = (norm_storage <= 1.0000f) ? 0.9576f * norm_storage + -0.0635f : 0.0000f * norm_storage + (0.9576f * 1.0000f + -0.0635f - 0.0000f * 1.0000f); break;
        case 11: norm_outflow = (norm_storage <= 1.0000f) ? 0.9776f * norm_storage + -0.0609f : 0.0000f * norm_storage + (0.9776f * 1.0000f + -0.0609f - 0.0000f * 1.0000f); break;
        case 12: norm_outflow = (norm_storage <= 1.0000f) ? 1.3178f * norm_storage + -0.0899f : 0.0000f * norm_storage + (1.3178f * 1.0000f + -0.0899f - 0.0000f * 1.0000f); break;
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
        case  1: norm_outflow = (norm_storage <= 0.6339f) ? 0.0101f * norm_storage + 0.0000f : 6.2799f * norm_storage + (0.0101f * 0.6339f + 0.0000f - 6.2799f * 0.6339f); break;
        case  2: norm_outflow = (norm_storage <= 0.6380f) ? 0.0145f * norm_storage + 0.0000f : 7.9809f * norm_storage + (0.0145f * 0.6380f + 0.0000f - 7.9809f * 0.6380f); break;
        case  3: norm_outflow = (norm_storage <= 0.6382f) ? 0.0225f * norm_storage + 0.0000f : 6.6489f * norm_storage + (0.0225f * 0.6382f + 0.0000f - 6.6489f * 0.6382f); break;
        case  4: norm_outflow = (norm_storage <= 0.6351f) ? 0.0146f * norm_storage + 0.0008f : 6.4795f * norm_storage + (0.0146f * 0.6351f + 0.0008f - 6.4795f * 0.6351f); break;
        case  5: norm_outflow = (norm_storage <= 0.6384f) ? 0.0249f * norm_storage + 0.0019f : 7.5710f * norm_storage + (0.0249f * 0.6384f + 0.0019f - 7.5710f * 0.6384f); break;
        case  6: norm_outflow = (norm_storage <= 0.6369f) ? 0.0188f * norm_storage + 0.0000f : 7.2201f * norm_storage + (0.0188f * 0.6369f + 0.0000f - 7.2201f * 0.6369f); break;
        case  7: norm_outflow = (norm_storage <= 0.6315f) ? 0.0027f * norm_storage + 0.0000f : 4.9022f * norm_storage + (0.0027f * 0.6315f + 0.0000f - 4.9022f * 0.6315f); break;
        case  8: norm_outflow = 1.7022f * norm_inflow + 0.0083f; break;
        case  9: norm_outflow = (norm_storage <= 0.6356f) ? 0.0046f * norm_storage + 0.0000f : 7.7903f * norm_storage + (0.0046f * 0.6356f + 0.0000f - 7.7903f * 0.6356f); break;
        case 10: norm_outflow = (norm_storage <= 0.6282f) ? 0.0025f * norm_storage + 0.0000f : 3.8132f * norm_storage + (0.0025f * 0.6282f + 0.0000f - 3.8132f * 0.6282f); break;
        case 11: norm_outflow = (norm_storage <= 0.6351f) ? 0.0048f * norm_storage + 0.0000f : 6.5251f * norm_storage + (0.0048f * 0.6351f + 0.0000f - 6.5251f * 0.6351f); break;
        case 12: norm_outflow = (norm_storage <= 0.6358f) ? 0.0052f * norm_storage + 0.0001f : 7.1382f * norm_storage + (0.0052f * 0.6358f + 0.0001f - 7.1382f * 0.6358f); break;
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
        case  1: norm_outflow = (norm_storage <= 1.0000f) ? 1.0635f * norm_storage + 0.1165f : 0.0000f * norm_storage + (1.0635f * 1.0000f + 0.1165f - 0.0000f * 1.0000f); break;
        case  2: norm_outflow = (norm_storage <= 1.0000f) ? 2.3834f * norm_storage + 0.0271f : 0.0000f * norm_storage + (2.3834f * 1.0000f + 0.0271f - 0.0000f * 1.0000f); break;
        case  3: norm_outflow = (norm_storage <= 1.0000f) ? 1.6140f * norm_storage + 0.1082f : 0.0000f * norm_storage + (1.6140f * 1.0000f + 0.1082f - 0.0000f * 1.0000f); break;
        case  4: norm_outflow = (norm_storage <= 1.0000f) ? 0.6872f * norm_storage + 0.1725f : 0.0000f * norm_storage + (0.6872f * 1.0000f + 0.1725f - 0.0000f * 1.0000f); break;
        case  5: norm_outflow = (norm_storage <= 1.0000f) ? 0.6393f * norm_storage + 0.1477f : 0.0000f * norm_storage + (0.6393f * 1.0000f + 0.1477f - 0.0000f * 1.0000f); break;
        case  6: norm_outflow = (norm_storage <= 1.0000f) ? 0.9048f * norm_storage + 0.0793f : 0.0000f * norm_storage + (0.9048f * 1.0000f + 0.0793f - 0.0000f * 1.0000f); break;
        case  7: norm_outflow = (norm_storage <= 1.0000f) ? 1.2521f * norm_storage + 0.0113f : 0.0000f * norm_storage + (1.2521f * 1.0000f + 0.0113f - 0.0000f * 1.0000f); break;
        case  8: norm_outflow = (norm_storage <= 1.0000f) ? 1.1775f * norm_storage + -0.0129f : 0.0000f * norm_storage + (1.1775f * 1.0000f + -0.0129f - 0.0000f * 1.0000f); break;
        case  9: norm_outflow = (norm_storage <= 1.0000f) ? 1.4920f * norm_storage + -0.0210f : 0.0000f * norm_storage + (1.4920f * 1.0000f + -0.0210f - 0.0000f * 1.0000f); break;
        case 10: norm_outflow = (norm_storage <= 1.0000f) ? 1.9356f * norm_storage + -0.0285f : 0.0000f * norm_storage + (1.9356f * 1.0000f + -0.0285f - 0.0000f * 1.0000f); break;
        case 11: norm_outflow = (norm_storage <= 1.0000f) ? 0.6934f * norm_storage + 0.0627f : 0.0000f * norm_storage + (0.6934f * 1.0000f + 0.0627f - 0.0000f * 1.0000f); break;
        case 12: norm_outflow = (norm_storage <= 1.0000f) ? 0.7518f * norm_storage + 0.1194f : 0.0000f * norm_storage + (0.7518f * 1.0000f + 0.1194f - 0.0000f * 1.0000f); break;
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
        case  1: norm_outflow = (norm_storage <= 1.0000f) ? 0.8372f * norm_storage + 0.0055f : 0.0000f * norm_storage + (0.8372f * 1.0000f + 0.0055f - 0.0000f * 1.0000f); break;
        case  2: norm_outflow = (norm_storage <= 1.0000f) ? 1.1543f * norm_storage + -0.0075f : 0.0000f * norm_storage + (1.1543f * 1.0000f + -0.0075f - 0.0000f * 1.0000f); break;
        case  3: norm_outflow = (norm_storage <= 1.0000f) ? 0.7594f * norm_storage + 0.0324f : 0.0000f * norm_storage + (0.7594f * 1.0000f + 0.0324f - 0.0000f * 1.0000f); break;
        case  4: norm_outflow = (norm_storage <= 1.0000f) ? 0.6145f * norm_storage + 0.0070f : 0.0000f * norm_storage + (0.6145f * 1.0000f + 0.0070f - 0.0000f * 1.0000f); break;
        case  5: norm_outflow = (norm_storage <= 1.0000f) ? 0.6115f * norm_storage + -0.0352f : 0.0000f * norm_storage + (0.6115f * 1.0000f + -0.0352f - 0.0000f * 1.0000f); break;
        case  6: norm_outflow = (norm_storage <= 1.0000f) ? 0.8349f * norm_storage + -0.0885f : 0.0000f * norm_storage + (0.8349f * 1.0000f + -0.0885f - 0.0000f * 1.0000f); break;
        case  7: norm_outflow = (norm_storage <= 1.0000f) ? 1.7048f * norm_storage + -0.2264f : 0.0000f * norm_storage + (1.7048f * 1.0000f + -0.2264f - 0.0000f * 1.0000f); break;
        case  8: norm_outflow = (norm_storage <= 1.0000f) ? 1.2000f * norm_storage + -0.1570f : 0.0000f * norm_storage + (1.2000f * 1.0000f + -0.1570f - 0.0000f * 1.0000f); break;
        case  9: norm_outflow = (norm_storage <= 1.0000f) ? 1.1237f * norm_storage + -0.1492f : 0.0000f * norm_storage + (1.1237f * 1.0000f + -0.1492f - 0.0000f * 1.0000f); break;
        case 10: norm_outflow = (norm_storage <= 1.0000f) ? 0.8687f * norm_storage + -0.1112f : 0.0000f * norm_storage + (0.8687f * 1.0000f + -0.1112f - 0.0000f * 1.0000f); break;
        case 11: norm_outflow = (norm_storage <= 1.0000f) ? 0.3522f * norm_storage + -0.0217f : 0.0000f * norm_storage + (0.3522f * 1.0000f + -0.0217f - 0.0000f * 1.0000f); break;
        case 12: norm_outflow = (norm_storage <= 1.0000f) ? 0.4949f * norm_storage + 0.0068f : 0.0000f * norm_storage + (0.4949f * 1.0000f + 0.0068f - 0.0000f * 1.0000f); break;
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
        case  1: norm_outflow = (norm_storage <= 1.0000f) ? 0.1065f * norm_storage + -0.0102f : 0.0000f * norm_storage + (0.1065f * 1.0000f + -0.0102f - 0.0000f * 1.0000f); break;
        case  2: norm_outflow = 0.1417f * norm_inflow + 0.0039f; break;
        case  3: norm_outflow = (norm_storage <= 1.0000f) ? 0.1152f * norm_storage + -0.0074f : 0.0000f * norm_storage + (0.1152f * 1.0000f + -0.0074f - 0.0000f * 1.0000f); break;
        case  4: norm_outflow = (norm_storage <= 1.0000f) ? 0.1573f * norm_storage + -0.0141f : 0.0000f * norm_storage + (0.1573f * 1.0000f + -0.0141f - 0.0000f * 1.0000f); break;
        case  5: norm_outflow = (norm_storage <= 1.0000f) ? 0.1188f * norm_storage + -0.0063f : 0.0000f * norm_storage + (0.1188f * 1.0000f + -0.0063f - 0.0000f * 1.0000f); break;
        case  6: norm_outflow = (norm_storage <= 1.0000f) ? 0.0858f * norm_storage + -0.0016f : 0.0000f * norm_storage + (0.0858f * 1.0000f + -0.0016f - 0.0000f * 1.0000f); break;
        case  7: norm_outflow = (norm_storage <= 1.0000f) ? 0.1303f * norm_storage + -0.0125f : 0.0000f * norm_storage + (0.1303f * 1.0000f + -0.0125f - 0.0000f * 1.0000f); break;
        case  8: norm_outflow = (norm_storage <= 1.0000f) ? 0.0743f * norm_storage + -0.0078f : 0.0000f * norm_storage + (0.0743f * 1.0000f + -0.0078f - 0.0000f * 1.0000f); break;
        case  9: norm_outflow = (norm_storage <= 1.0000f) ? 0.0263f * norm_storage + -0.0022f : 0.0000f * norm_storage + (0.0263f * 1.0000f + -0.0022f - 0.0000f * 1.0000f); break;
        case 10: norm_outflow = (norm_storage <= 0.8546f) ? 0.0702f * norm_storage + 0.0000f : 6.3637f * norm_storage + (0.0702f * 0.8546f + 0.0000f - 6.3637f * 0.8546f); break;
        case 11: norm_outflow = (norm_storage <= 1.0000f) ? 0.1083f * norm_storage + -0.0104f : 0.0000f * norm_storage + (0.1083f * 1.0000f + -0.0104f - 0.0000f * 1.0000f); break;
        case 12: norm_outflow = (norm_storage <= 1.0000f) ? 0.0858f * norm_storage + -0.0077f : 0.0000f * norm_storage + (0.0858f * 1.0000f + -0.0077f - 0.0000f * 1.0000f); break;
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
        case  2: norm_outflow = (norm_storage <= 1.0000f) ? 0.8367f * norm_storage + -0.1210f : 0.0000f * norm_storage + (0.8367f * 1.0000f + -0.1210f - 0.0000f * 1.0000f); break;
        case  3: norm_outflow = (norm_storage <= 1.0000f) ? 1.4503f * norm_storage + -0.2274f : 0.0000f * norm_storage + (1.4503f * 1.0000f + -0.2274f - 0.0000f * 1.0000f); break;
        case  4: norm_outflow = (norm_storage <= 1.0000f) ? 1.5657f * norm_storage + -0.2452f : 0.0000f * norm_storage + (1.5657f * 1.0000f + -0.2452f - 0.0000f * 1.0000f); break;
        case  5: norm_outflow = (norm_storage <= 1.0000f) ? 1.4345f * norm_storage + -0.2178f : 0.0000f * norm_storage + (1.4345f * 1.0000f + -0.2178f - 0.0000f * 1.0000f); break;
        case  6: norm_outflow = (norm_storage <= 1.0000f) ? 1.6564f * norm_storage + -0.2604f : 0.0000f * norm_storage + (1.6564f * 1.0000f + -0.2604f - 0.0000f * 1.0000f); break;
        case  7: norm_outflow = (norm_storage <= 1.0000f) ? 1.4622f * norm_storage + -0.2230f : 0.0000f * norm_storage + (1.4622f * 1.0000f + -0.2230f - 0.0000f * 1.0000f); break;
        case  8: norm_outflow = (norm_storage <= 1.0000f) ? 1.2081f * norm_storage + -0.1735f : 0.0000f * norm_storage + (1.2081f * 1.0000f + -0.1735f - 0.0000f * 1.0000f); break;
        case  9: norm_outflow = (norm_storage <= 1.0000f) ? 1.1449f * norm_storage + -0.1577f : 0.0000f * norm_storage + (1.1449f * 1.0000f + -0.1577f - 0.0000f * 1.0000f); break;
        case 10: norm_outflow = (norm_storage <= 1.0000f) ? 1.1458f * norm_storage + -0.1547f : 0.0000f * norm_storage + (1.1458f * 1.0000f + -0.1547f - 0.0000f * 1.0000f); break;
        case 11: norm_outflow = (norm_storage <= 1.0000f) ? 1.1283f * norm_storage + -0.1578f : 0.0000f * norm_storage + (1.1283f * 1.0000f + -0.1578f - 0.0000f * 1.0000f); break;
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
        case  5: norm_outflow = (norm_storage <= 0.7869f) ? 0.1000f * norm_storage + 0.0128f : 3.9387f * norm_storage + (0.1000f * 0.7869f + 0.0128f - 3.9387f * 0.7869f); break;
        case  6: norm_outflow = (norm_storage <= 1.0000f) ? 0.2959f * norm_storage + -0.0624f : 0.0000f * norm_storage + (0.2959f * 1.0000f + -0.0624f - 0.0000f * 1.0000f); break;
        case  7: norm_outflow = (norm_storage <= 1.0000f) ? 0.4182f * norm_storage + -0.1027f : 0.0000f * norm_storage + (0.4182f * 1.0000f + -0.1027f - 0.0000f * 1.0000f); break;
        case  8: norm_outflow = 1.1025f * norm_inflow + 0.0184f; break;
        case  9: norm_outflow = 0.7014f * norm_inflow + 0.0195f; break;
        case 10: norm_outflow = (norm_storage <= 1.0000f) ? 1.1191f * norm_storage + -0.2967f : 0.0000f * norm_storage + (1.1191f * 1.0000f + -0.2967f - 0.0000f * 1.0000f); break;
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
        case  1: norm_outflow = (norm_storage <= 0.6674f) ? 0.0332f * norm_storage + 0.0000f : 1.4572f * norm_storage + (0.0332f * 0.6674f + 0.0000f - 1.4572f * 0.6674f); break;
        case  2: norm_outflow = (norm_storage <= 0.6697f) ? 0.0356f * norm_storage + 0.0000f : 1.5885f * norm_storage + (0.0356f * 0.6697f + 0.0000f - 1.5885f * 0.6697f); break;
        case  3: norm_outflow = (norm_storage <= 0.6615f) ? 0.0048f * norm_storage + 0.0114f : 1.5005f * norm_storage + (0.0048f * 0.6615f + 0.0114f - 1.5005f * 0.6615f); break;
        case  4: norm_outflow = (norm_storage <= 0.6708f) ? 0.0210f * norm_storage + 0.0000f : 1.7373f * norm_storage + (0.0210f * 0.6708f + 0.0000f - 1.7373f * 0.6708f); break;
        case  5: norm_outflow = (norm_storage <= 0.6706f) ? 0.0003f * norm_storage + 0.0038f : 1.2430f * norm_storage + (0.0003f * 0.6706f + 0.0038f - 1.2430f * 0.6706f); break;
        case  6: norm_outflow = (norm_storage <= 1.0000f) ? 0.6302f * norm_storage + -0.4038f : 0.0000f * norm_storage + (0.6302f * 1.0000f + -0.4038f - 0.0000f * 1.0000f); break;
        case  7: norm_outflow = 0.9433f * norm_inflow + 0.0456f; break;
        case  8: norm_outflow = (norm_storage <= 0.7302f) ? 0.0472f * norm_storage + 0.0112f : 1.0293f * norm_storage + (0.0472f * 0.7302f + 0.0112f - 1.0293f * 0.7302f); break;
        case  9: norm_outflow = (norm_storage <= 0.7306f) ? 0.0400f * norm_storage + 0.0000f : 2.8637f * norm_storage + (0.0400f * 0.7306f + 0.0000f - 2.8637f * 0.7306f); break;
        case 10: norm_outflow = (norm_storage <= 0.7241f) ? 0.0326f * norm_storage + 0.0000f : 3.6574f * norm_storage + (0.0326f * 0.7241f + 0.0000f - 3.6574f * 0.7241f); break;
        case 11: norm_outflow = (norm_storage <= 0.7099f) ? 0.0364f * norm_storage + 0.0000f : 2.2649f * norm_storage + (0.0364f * 0.7099f + 0.0000f - 2.2649f * 0.7099f); break;
        case 12: norm_outflow = (norm_storage <= 0.6927f) ? 0.0509f * norm_storage + 0.0000f : 1.9112f * norm_storage + (0.0509f * 0.6927f + 0.0000f - 1.9112f * 0.6927f); break;
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
        case  5: norm_outflow = (norm_storage <= 1.0000f) ? 1.0602f * norm_storage + -0.4786f : 0.0000f * norm_storage + (1.0602f * 1.0000f + -0.4786f - 0.0000f * 1.0000f); break;
        case  6: norm_outflow = (norm_storage <= 1.0000f) ? 1.3034f * norm_storage + -0.6035f : 0.0000f * norm_storage + (1.3034f * 1.0000f + -0.6035f - 0.0000f * 1.0000f); break;
        case  7: norm_outflow = 1.3295f * norm_inflow + 0.0125f; break;
        case  8: norm_outflow = 0.7784f * norm_inflow + 0.0069f; break;
        case  9: norm_outflow = (norm_storage <= 0.6803f) ? 0.0205f * norm_storage + 0.0000f : 1.9787f * norm_storage + (0.0205f * 0.6803f + 0.0000f - 1.9787f * 0.6803f); break;
        case 10: norm_outflow = (norm_storage <= 1.0000f) ? 0.5340f * norm_storage + -0.2204f : 0.0000f * norm_storage + (0.5340f * 1.0000f + -0.2204f - 0.0000f * 1.0000f); break;
        case 11: norm_outflow = (norm_storage <= 1.0000f) ? 0.3161f * norm_storage + -0.1224f : 0.0000f * norm_storage + (0.3161f * 1.0000f + -0.1224f - 0.0000f * 1.0000f); break;
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
        case  1: norm_outflow = (norm_storage <= 1.0000f) ? 0.5669f * norm_storage + -0.1519f : 0.0000f * norm_storage + (0.5669f * 1.0000f + -0.1519f - 0.0000f * 1.0000f); break;
        case  2: norm_outflow = 0.8614f * norm_inflow + 0.0116f; break;
        case  3: norm_outflow = (norm_storage <= 1.0000f) ? 0.5525f * norm_storage + -0.1364f : 0.0000f * norm_storage + (0.5525f * 1.0000f + -0.1364f - 0.0000f * 1.0000f); break;
        case  4: norm_outflow = (norm_storage <= 1.0000f) ? 0.4854f * norm_storage + -0.1088f : 0.0000f * norm_storage + (0.4854f * 1.0000f + -0.1088f - 0.0000f * 1.0000f); break;
        case  5: norm_outflow = (norm_storage <= 1.0000f) ? 0.7333f * norm_storage + -0.1881f : 0.0000f * norm_storage + (0.7333f * 1.0000f + -0.1881f - 0.0000f * 1.0000f); break;
        case  6: norm_outflow = (norm_storage <= 1.0000f) ? 0.6696f * norm_storage + -0.1656f : 0.0000f * norm_storage + (0.6696f * 1.0000f + -0.1656f - 0.0000f * 1.0000f); break;
        case  7: norm_outflow = (norm_storage <= 1.0000f) ? 0.8314f * norm_storage + -0.2268f : 0.0000f * norm_storage + (0.8314f * 1.0000f + -0.2268f - 0.0000f * 1.0000f); break;
        case  8: norm_outflow = (norm_storage <= 1.0000f) ? 1.0320f * norm_storage + -0.2862f : 0.0000f * norm_storage + (1.0320f * 1.0000f + -0.2862f - 0.0000f * 1.0000f); break;
        case  9: norm_outflow = (norm_storage <= 1.0000f) ? 0.8742f * norm_storage + -0.2410f : 0.0000f * norm_storage + (0.8742f * 1.0000f + -0.2410f - 0.0000f * 1.0000f); break;
        case 10: norm_outflow = (norm_storage <= 1.0000f) ? 1.0212f * norm_storage + -0.2771f : 0.0000f * norm_storage + (1.0212f * 1.0000f + -0.2771f - 0.0000f * 1.0000f); break;
        case 11: norm_outflow = (norm_storage <= 1.0000f) ? 0.7109f * norm_storage + -0.1852f : 0.0000f * norm_storage + (0.7109f * 1.0000f + -0.1852f - 0.0000f * 1.0000f); break;
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
        case  1: norm_outflow = (norm_storage <= 1.0000f) ? 0.0908f * norm_storage + -0.0551f : 0.0000f * norm_storage + (0.0908f * 1.0000f + -0.0551f - 0.0000f * 1.0000f); break;
        case  2: norm_outflow = (norm_storage <= 1.0000f) ? 0.1691f * norm_storage + -0.1136f : 0.0000f * norm_storage + (0.1691f * 1.0000f + -0.1136f - 0.0000f * 1.0000f); break;
        case  3: norm_outflow = (norm_storage <= 1.0000f) ? 0.1433f * norm_storage + -0.0999f : 0.0000f * norm_storage + (0.1433f * 1.0000f + -0.0999f - 0.0000f * 1.0000f); break;
        case  4: norm_outflow = (norm_storage <= 0.9492f) ? 0.0191f * norm_storage + 0.0000f : 15.0488f * norm_storage + (0.0191f * 0.9492f + 0.0000f - 15.0488f * 0.9492f); break;
        case  5: norm_outflow = 0.5928f * norm_inflow + 0.0090f; break;
        case  6: norm_outflow = 0.5792f * norm_inflow + 0.0139f; break;
        case  7: norm_outflow = 0.5570f * norm_inflow + 0.0118f; break;
        case  8: norm_outflow = (norm_storage <= 1.0000f) ? 0.0378f * norm_storage + -0.0180f : 0.0000f * norm_storage + (0.0378f * 1.0000f + -0.0180f - 0.0000f * 1.0000f); break;
        case  9: norm_outflow = (norm_storage <= 1.0000f) ? 0.0682f * norm_storage + -0.0446f : 0.0000f * norm_storage + (0.0682f * 1.0000f + -0.0446f - 0.0000f * 1.0000f); break;
        case 10: norm_outflow = (norm_storage <= 1.0000f) ? 0.0622f * norm_storage + -0.0408f : 0.0000f * norm_storage + (0.0622f * 1.0000f + -0.0408f - 0.0000f * 1.0000f); break;
        case 11: norm_outflow = (norm_storage <= 1.0000f) ? 0.0478f * norm_storage + -0.0303f : 0.0000f * norm_storage + (0.0478f * 1.0000f + -0.0303f - 0.0000f * 1.0000f); break;
        case 12: norm_outflow = (norm_storage <= 0.9378f) ? 0.0154f * norm_storage + 0.0000f : 15.0113f * norm_storage + (0.0154f * 0.9378f + 0.0000f - 15.0113f * 0.9378f); break;
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
        case  1: norm_outflow = (norm_storage <= 1.0000f) ? 1.0476f * norm_storage + -0.4778f : 0.0000f * norm_storage + (1.0476f * 1.0000f + -0.4778f - 0.0000f * 1.0000f); break;
        case  2: norm_outflow = (norm_storage <= 1.0000f) ? 1.4987f * norm_storage + -0.7215f : 0.0000f * norm_storage + (1.4987f * 1.0000f + -0.7215f - 0.0000f * 1.0000f); break;
        case  3: norm_outflow = (norm_storage <= 1.0000f) ? 1.1377f * norm_storage + -0.5541f : 0.0000f * norm_storage + (1.1377f * 1.0000f + -0.5541f - 0.0000f * 1.0000f); break;
        case  4: norm_outflow = (norm_storage <= 1.0000f) ? 0.5531f * norm_storage + -0.2182f : 0.0000f * norm_storage + (0.5531f * 1.0000f + -0.2182f - 0.0000f * 1.0000f); break;
        case  5: norm_outflow = (norm_storage <= 0.9349f) ? 0.0849f * norm_storage + 0.0000f : 9.3004f * norm_storage + (0.0849f * 0.9349f + 0.0000f - 9.3004f * 0.9349f); break;
        case  6: norm_outflow = (norm_storage <= 0.8941f) ? 0.1000f * norm_storage + 0.0351f : 3.3514f * norm_storage + (0.1000f * 0.8941f + 0.0351f - 3.3514f * 0.8941f); break;
        case  7: norm_outflow = (norm_storage <= 1.0000f) ? 0.3337f * norm_storage + -0.1092f : 0.0000f * norm_storage + (0.3337f * 1.0000f + -0.1092f - 0.0000f * 1.0000f); break;
        case  8: norm_outflow = (norm_storage <= 1.0000f) ? 0.6211f * norm_storage + -0.2746f : 0.0000f * norm_storage + (0.6211f * 1.0000f + -0.2746f - 0.0000f * 1.0000f); break;
        case  9: norm_outflow = (norm_storage <= 1.0000f) ? 0.7020f * norm_storage + -0.3175f : 0.0000f * norm_storage + (0.7020f * 1.0000f + -0.3175f - 0.0000f * 1.0000f); break;
        case 10: norm_outflow = (norm_storage <= 1.0000f) ? 0.8943f * norm_storage + -0.4240f : 0.0000f * norm_storage + (0.8943f * 1.0000f + -0.4240f - 0.0000f * 1.0000f); break;
        case 11: norm_outflow = (norm_storage <= 1.0000f) ? 0.3817f * norm_storage + -0.1530f : 0.0000f * norm_storage + (0.3817f * 1.0000f + -0.1530f - 0.0000f * 1.0000f); break;
        case 12: norm_outflow = (norm_storage <= 1.0000f) ? 1.2138f * norm_storage + -0.5915f : 0.0000f * norm_storage + (1.2138f * 1.0000f + -0.5915f - 0.0000f * 1.0000f); break;
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
        case  1: norm_outflow = (norm_storage <= 0.6063f) ? 0.0000f * norm_storage + 0.0084f : 4.1116f * norm_storage + (0.0000f * 0.6063f + 0.0084f - 4.1116f * 0.6063f); break;
        case  2: norm_outflow = (norm_storage <= 0.6197f) ? 0.0115f * norm_storage + 0.0046f : 8.9766f * norm_storage + (0.0115f * 0.6197f + 0.0046f - 8.9766f * 0.6197f); break;
        case  3: norm_outflow = (norm_storage <= 0.6130f) ? 0.0000f * norm_storage + 0.0072f : 5.2221f * norm_storage + (0.0000f * 0.6130f + 0.0072f - 5.2221f * 0.6130f); break;
        case  4: norm_outflow = (norm_storage <= 0.6000f) ? 0.0616f * norm_storage + 0.0000f : 2.7326f * norm_storage + (0.0616f * 0.6000f + 0.0000f - 2.7326f * 0.6000f); break;
        case  5: norm_outflow = (norm_storage <= 0.6000f) ? 0.0356f * norm_storage + 0.0031f : 1.7409f * norm_storage + (0.0356f * 0.6000f + 0.0031f - 1.7409f * 0.6000f); break;
        case  6: norm_outflow = (norm_storage <= 0.6000f) ? 0.0544f * norm_storage + 0.0000f : 1.5501f * norm_storage + (0.0544f * 0.6000f + 0.0000f - 1.5501f * 0.6000f); break;
        case  7: norm_outflow = (norm_storage <= 0.6000f) ? 0.0266f * norm_storage + 0.0167f : 1.5887f * norm_storage + (0.0266f * 0.6000f + 0.0167f - 1.5887f * 0.6000f); break;
        case  8: norm_outflow = (norm_storage <= 0.6131f) ? 0.0000f * norm_storage + 0.0263f : 5.7847f * norm_storage + (0.0000f * 0.6131f + 0.0263f - 5.7847f * 0.6131f); break;
        case  9: norm_outflow = (norm_storage <= 0.6050f) ? 0.0011f * norm_storage + 0.0312f : 1.0140f * norm_storage + (0.0011f * 0.6050f + 0.0312f - 1.0140f * 0.6050f); break;
        case 10: norm_outflow = (norm_storage <= 0.6151f) ? 0.0063f * norm_storage + 0.0169f : 7.4213f * norm_storage + (0.0063f * 0.6151f + 0.0169f - 7.4213f * 0.6151f); break;
        case 11: norm_outflow = (norm_storage <= 0.6086f) ? 0.0000f * norm_storage + 0.0092f : 5.5263f * norm_storage + (0.0000f * 0.6086f + 0.0092f - 5.5263f * 0.6086f); break;
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
        case  1: norm_outflow = (norm_storage <= 1.0000f) ? 0.2742f * norm_storage + -0.1271f : 0.0000f * norm_storage + (0.2742f * 1.0000f + -0.1271f - 0.0000f * 1.0000f); break;
        case  2: norm_outflow = (norm_storage <= 1.0000f) ? 0.3389f * norm_storage + -0.1677f : 0.0000f * norm_storage + (0.3389f * 1.0000f + -0.1677f - 0.0000f * 1.0000f); break;
        case  3: norm_outflow = (norm_storage <= 1.0000f) ? 0.2791f * norm_storage + -0.1405f : 0.0000f * norm_storage + (0.2791f * 1.0000f + -0.1405f - 0.0000f * 1.0000f); break;
        case  4: norm_outflow = (norm_storage <= 0.9665f) ? 0.0622f * norm_storage + 0.0000f : 28.9560f * norm_storage + (0.0622f * 0.9665f + 0.0000f - 28.9560f * 0.9665f); break;
        case  5: norm_outflow = (norm_storage <= 0.9564f) ? 0.0506f * norm_storage + 0.0000f : 15.5184f * norm_storage + (0.0506f * 0.9564f + 0.0000f - 15.5184f * 0.9564f); break;
        case  6: norm_outflow = (norm_storage <= 1.0000f) ? 0.1024f * norm_storage + -0.0340f : 0.0000f * norm_storage + (0.1024f * 1.0000f + -0.0340f - 0.0000f * 1.0000f); break;
        case  7: norm_outflow = (norm_storage <= 1.0000f) ? 0.0762f * norm_storage + -0.0160f : 0.0000f * norm_storage + (0.0762f * 1.0000f + -0.0160f - 0.0000f * 1.0000f); break;
        case  8: norm_outflow = (norm_storage <= 1.0000f) ? 0.1428f * norm_storage + -0.0616f : 0.0000f * norm_storage + (0.1428f * 1.0000f + -0.0616f - 0.0000f * 1.0000f); break;
        case  9: norm_outflow = (norm_storage <= 1.0000f) ? 0.1721f * norm_storage + -0.0827f : 0.0000f * norm_storage + (0.1721f * 1.0000f + -0.0827f - 0.0000f * 1.0000f); break;
        case 10: norm_outflow = (norm_storage <= 1.0000f) ? 0.1611f * norm_storage + -0.0765f : 0.0000f * norm_storage + (0.1611f * 1.0000f + -0.0765f - 0.0000f * 1.0000f); break;
        case 11: norm_outflow = (norm_storage <= 1.0000f) ? 0.0805f * norm_storage + -0.0286f : 0.0000f * norm_storage + (0.0805f * 1.0000f + -0.0286f - 0.0000f * 1.0000f); break;
        case 12: norm_outflow = (norm_storage <= 0.6002f) ? 0.0304f * norm_storage + 0.0000f : 0.6294f * norm_storage + (0.0304f * 0.6002f + 0.0000f - 0.6294f * 0.6002f); break;
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
        case  7: norm_outflow = (norm_storage <= 1.0000f) ? 0.3250f * norm_storage + -0.0684f : 0.0000f * norm_storage + (0.3250f * 1.0000f + -0.0684f - 0.0000f * 1.0000f); break;
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
        case  4: norm_outflow = (norm_storage <= 0.6835f) ? 0.0114f * norm_storage + 0.0027f : 1.0310f * norm_storage + (0.0114f * 0.6835f + 0.0027f - 1.0310f * 0.6835f); break;
        case  5: norm_outflow = 0.7012f * norm_inflow + 0.0243f; break;
        case  6: norm_outflow = 0.5417f * norm_inflow + 0.0403f; break;
        case  7: norm_outflow = (norm_storage <= 0.7045f) ? 0.0286f * norm_storage + 0.0000f : 0.7005f * norm_storage + (0.0286f * 0.7045f + 0.0000f - 0.7005f * 0.7045f); break;
        case  8: norm_outflow = 0.7705f * norm_inflow + 0.0198f; break;
        case  9: norm_outflow = 0.3506f * norm_inflow + 0.0191f; break;
        case 10: norm_outflow = 0.7599f * norm_inflow + 0.0109f; break;
        case 11: norm_outflow = (norm_storage <= 0.7010f) ? 0.0182f * norm_storage + 0.0000f : 0.8807f * norm_storage + (0.0182f * 0.7010f + 0.0000f - 0.8807f * 0.7010f); break;
        case 12: norm_outflow = (norm_storage <= 0.6973f) ? 0.0131f * norm_storage + 0.0043f : 0.9866f * norm_storage + (0.0131f * 0.6973f + 0.0043f - 0.9866f * 0.6973f); break;
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
        case  3: norm_outflow = (norm_storage <= 1.0000f) ? 0.6455f * norm_storage + -0.1597f : 0.0000f * norm_storage + (0.6455f * 1.0000f + -0.1597f - 0.0000f * 1.0000f); break;
        case  4: norm_outflow = (norm_storage <= 1.0000f) ? 0.4471f * norm_storage + -0.0854f : 0.0000f * norm_storage + (0.4471f * 1.0000f + -0.0854f - 0.0000f * 1.0000f); break;
        case  5: norm_outflow = 0.7909f * norm_inflow + 0.0226f; break;
        case  6: norm_outflow = 0.8347f * norm_inflow + 0.0220f; break;
        case  7: norm_outflow = (norm_storage <= 1.0000f) ? 0.3257f * norm_storage + -0.0704f : 0.0000f * norm_storage + (0.3257f * 1.0000f + -0.0704f - 0.0000f * 1.0000f); break;
        case  8: norm_outflow = 0.8225f * norm_inflow + 0.0076f; break;
        case  9: norm_outflow = 0.8432f * norm_inflow + 0.0068f; break;
        case 10: norm_outflow = (norm_storage <= 1.0000f) ? 0.7336f * norm_storage + -0.2031f : 0.0000f * norm_storage + (0.7336f * 1.0000f + -0.2031f - 0.0000f * 1.0000f); break;
        case 11: norm_outflow = (norm_storage <= 1.0000f) ? 0.7200f * norm_storage + -0.1998f : 0.0000f * norm_storage + (0.7200f * 1.0000f + -0.1998f - 0.0000f * 1.0000f); break;
        case 12: norm_outflow = (norm_storage <= 1.0000f) ? 0.9820f * norm_storage + -0.2790f : 0.0000f * norm_storage + (0.9820f * 1.0000f + -0.2790f - 0.0000f * 1.0000f); break;
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
        case  1: norm_outflow = (norm_storage <= 1.0000f) ? 0.7963f * norm_storage + -0.3747f : 0.0000f * norm_storage + (0.7963f * 1.0000f + -0.3747f - 0.0000f * 1.0000f); break;
        case  2: norm_outflow = (norm_storage <= 1.0000f) ? 0.5919f * norm_storage + -0.2689f : 0.0000f * norm_storage + (0.5919f * 1.0000f + -0.2689f - 0.0000f * 1.0000f); break;
        case  3: norm_outflow = (norm_storage <= 1.0000f) ? 0.7621f * norm_storage + -0.3697f : 0.0000f * norm_storage + (0.7621f * 1.0000f + -0.3697f - 0.0000f * 1.0000f); break;
        case  4: norm_outflow = (norm_storage <= 1.0000f) ? 0.8825f * norm_storage + -0.4247f : 0.0000f * norm_storage + (0.8825f * 1.0000f + -0.4247f - 0.0000f * 1.0000f); break;
        case  5: norm_outflow = (norm_storage <= 1.0000f) ? 0.7249f * norm_storage + -0.3465f : 0.0000f * norm_storage + (0.7249f * 1.0000f + -0.3465f - 0.0000f * 1.0000f); break;
        case  6: norm_outflow = (norm_storage <= 1.0000f) ? 0.4309f * norm_storage + -0.2000f : 0.0000f * norm_storage + (0.4309f * 1.0000f + -0.2000f - 0.0000f * 1.0000f); break;
        case  7: norm_outflow = (norm_storage <= 1.0000f) ? 0.8633f * norm_storage + -0.4477f : 0.0000f * norm_storage + (0.8633f * 1.0000f + -0.4477f - 0.0000f * 1.0000f); break;
        case  8: norm_outflow = (norm_storage <= 1.0000f) ? 0.2303f * norm_storage + -0.0969f : 0.0000f * norm_storage + (0.2303f * 1.0000f + -0.0969f - 0.0000f * 1.0000f); break;
        case  9: norm_outflow = (norm_storage <= 1.0000f) ? 0.4577f * norm_storage + -0.2181f : 0.0000f * norm_storage + (0.4577f * 1.0000f + -0.2181f - 0.0000f * 1.0000f); break;
        case 10: norm_outflow = (norm_storage <= 1.0000f) ? 0.9867f * norm_storage + -0.4940f : 0.0000f * norm_storage + (0.9867f * 1.0000f + -0.4940f - 0.0000f * 1.0000f); break;
        case 11: norm_outflow = (norm_storage <= 0.6000f) ? 0.0427f * norm_storage + 0.0000f : 2.5963f * norm_storage + (0.0427f * 0.6000f + 0.0000f - 2.5963f * 0.6000f); break;
        case 12: norm_outflow = (norm_storage <= 1.0000f) ? 1.0201f * norm_storage + -0.5069f : 0.0000f * norm_storage + (1.0201f * 1.0000f + -0.5069f - 0.0000f * 1.0000f); break;
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
        case  1: norm_outflow = (norm_storage <= 1.0000f) ? 2.2178f * norm_storage + -1.2770f : 0.0000f * norm_storage + (2.2178f * 1.0000f + -1.2770f - 0.0000f * 1.0000f); break;
        case  2: norm_outflow = (norm_storage <= 1.0000f) ? 2.5130f * norm_storage + -1.4561f : 0.0000f * norm_storage + (2.5130f * 1.0000f + -1.4561f - 0.0000f * 1.0000f); break;
        case  3: norm_outflow = (norm_storage <= 1.0000f) ? 1.6252f * norm_storage + -0.8847f : 0.0000f * norm_storage + (1.6252f * 1.0000f + -0.8847f - 0.0000f * 1.0000f); break;
        case  4: norm_outflow = (norm_storage <= 1.0000f) ? 0.6602f * norm_storage + -0.2335f : 0.0000f * norm_storage + (0.6602f * 1.0000f + -0.2335f - 0.0000f * 1.0000f); break;
        case  5: norm_outflow = (norm_storage <= 1.0000f) ? 0.7697f * norm_storage + -0.3997f : 0.0000f * norm_storage + (0.7697f * 1.0000f + -0.3997f - 0.0000f * 1.0000f); break;
        case  6: norm_outflow = (norm_storage <= 1.0000f) ? 1.4046f * norm_storage + -0.8328f : 0.0000f * norm_storage + (1.4046f * 1.0000f + -0.8328f - 0.0000f * 1.0000f); break;
        case  7: norm_outflow = (norm_storage <= 1.0000f) ? 2.2753f * norm_storage + -1.4135f : 0.0000f * norm_storage + (2.2753f * 1.0000f + -1.4135f - 0.0000f * 1.0000f); break;
        case  8: norm_outflow = (norm_storage <= 0.6842f) ? 0.1000f * norm_storage + 0.0196f : 4.9865f * norm_storage + (0.1000f * 0.6842f + 0.0196f - 4.9865f * 0.6842f); break;
        case  9: norm_outflow = (norm_storage <= 0.6556f) ? 0.0565f * norm_storage + 0.0000f : 2.4749f * norm_storage + (0.0565f * 0.6556f + 0.0000f - 2.4749f * 0.6556f); break;
        case 10: norm_outflow = (norm_storage <= 1.0000f) ? 1.3979f * norm_storage + -0.8435f : 0.0000f * norm_storage + (1.3979f * 1.0000f + -0.8435f - 0.0000f * 1.0000f); break;
        case 11: norm_outflow = (norm_storage <= 1.0000f) ? 1.1435f * norm_storage + -0.6784f : 0.0000f * norm_storage + (1.1435f * 1.0000f + -0.6784f - 0.0000f * 1.0000f); break;
        case 12: norm_outflow = (norm_storage <= 1.0000f) ? 3.0710f * norm_storage + -1.8559f : 0.0000f * norm_storage + (3.0710f * 1.0000f + -1.8559f - 0.0000f * 1.0000f); break;
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
        case  1: norm_outflow = (norm_storage <= 1.0000f) ? 0.5702f * norm_storage + -0.2751f : 0.0000f * norm_storage + (0.5702f * 1.0000f + -0.2751f - 0.0000f * 1.0000f); break;
        case  2: norm_outflow = (norm_storage <= 1.0000f) ? 0.3415f * norm_storage + -0.1597f : 0.0000f * norm_storage + (0.3415f * 1.0000f + -0.1597f - 0.0000f * 1.0000f); break;
        case  3: norm_outflow = (norm_storage <= 0.6000f) ? 0.0407f * norm_storage + 0.0000f : 1.3811f * norm_storage + (0.0407f * 0.6000f + 0.0000f - 1.3811f * 0.6000f); break;
        case  4: norm_outflow = (norm_storage <= 1.0000f) ? 0.5859f * norm_storage + -0.2913f : 0.0000f * norm_storage + (0.5859f * 1.0000f + -0.2913f - 0.0000f * 1.0000f); break;
        case  5: norm_outflow = (norm_storage <= 1.0000f) ? 1.0426f * norm_storage + -0.5809f : 0.0000f * norm_storage + (1.0426f * 1.0000f + -0.5809f - 0.0000f * 1.0000f); break;
        case  6: norm_outflow = (norm_storage <= 1.0000f) ? 0.5955f * norm_storage + -0.3192f : 0.0000f * norm_storage + (0.5955f * 1.0000f + -0.3192f - 0.0000f * 1.0000f); break;
        case  7: norm_outflow = (norm_storage <= 1.0000f) ? 0.6264f * norm_storage + -0.3334f : 0.0000f * norm_storage + (0.6264f * 1.0000f + -0.3334f - 0.0000f * 1.0000f); break;
        case  8: norm_outflow = (norm_storage <= 0.6003f) ? 0.0299f * norm_storage + 0.0000f : 1.0013f * norm_storage + (0.0299f * 0.6003f + 0.0000f - 1.0013f * 0.6003f); break;
        case  9: norm_outflow = (norm_storage <= 1.0000f) ? 0.2634f * norm_storage + -0.1272f : 0.0000f * norm_storage + (0.2634f * 1.0000f + -0.1272f - 0.0000f * 1.0000f); break;
        case 10: norm_outflow = (norm_storage <= 0.6078f) ? 0.0149f * norm_storage + 0.0000f : 1.4968f * norm_storage + (0.0149f * 0.6078f + 0.0000f - 1.4968f * 0.6078f); break;
        case 11: norm_outflow = (norm_storage <= 0.6000f) ? 0.0207f * norm_storage + 0.0000f : 1.8757f * norm_storage + (0.0207f * 0.6000f + 0.0000f - 1.8757f * 0.6000f); break;
        case 12: norm_outflow = (norm_storage <= 1.0000f) ? 0.4728f * norm_storage + -0.2322f : 0.0000f * norm_storage + (0.4728f * 1.0000f + -0.2322f - 0.0000f * 1.0000f); break;
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
        case  1: norm_outflow = (norm_storage <= 1.0000f) ? 0.6955f * norm_storage + -0.0012f : 0.0000f * norm_storage + (0.6955f * 1.0000f + -0.0012f - 0.0000f * 1.0000f); break;
        case  2: norm_outflow = (norm_storage <= 1.0000f) ? 0.6860f * norm_storage + 0.0066f : 0.0000f * norm_storage + (0.6860f * 1.0000f + 0.0066f - 0.0000f * 1.0000f); break;
        case  3: norm_outflow = (norm_storage <= 1.0000f) ? 0.3980f * norm_storage + 0.0109f : 0.0000f * norm_storage + (0.3980f * 1.0000f + 0.0109f - 0.0000f * 1.0000f); break;
        case  4: norm_outflow = (norm_storage <= 1.0000f) ? 0.4756f * norm_storage + 0.0065f : 0.0000f * norm_storage + (0.4756f * 1.0000f + 0.0065f - 0.0000f * 1.0000f); break;
        case  5: norm_outflow = (norm_storage <= 1.0000f) ? 0.4377f * norm_storage + 0.0021f : 0.0000f * norm_storage + (0.4377f * 1.0000f + 0.0021f - 0.0000f * 1.0000f); break;
        case  6: norm_outflow = (norm_storage <= 1.0000f) ? 0.4949f * norm_storage + -0.0177f : 0.0000f * norm_storage + (0.4949f * 1.0000f + -0.0177f - 0.0000f * 1.0000f); break;
        case  7: norm_outflow = (norm_storage <= 1.0000f) ? 1.0331f * norm_storage + -0.0828f : 0.0000f * norm_storage + (1.0331f * 1.0000f + -0.0828f - 0.0000f * 1.0000f); break;
        case  8: norm_outflow = 0.4555f * norm_inflow + 0.0066f; break;
        case  9: norm_outflow = (norm_storage <= 1.0000f) ? 0.6828f * norm_storage + -0.0480f : 0.0000f * norm_storage + (0.6828f * 1.0000f + -0.0480f - 0.0000f * 1.0000f); break;
        case 10: norm_outflow = (norm_storage <= 1.0000f) ? 0.2511f * norm_storage + -0.0051f : 0.0000f * norm_storage + (0.2511f * 1.0000f + -0.0051f - 0.0000f * 1.0000f); break;
        case 11: norm_outflow = (norm_storage <= 1.0000f) ? 0.3434f * norm_storage + -0.0059f : 0.0000f * norm_storage + (0.3434f * 1.0000f + -0.0059f - 0.0000f * 1.0000f); break;
        case 12: norm_outflow = (norm_storage <= 1.0000f) ? 0.4706f * norm_storage + 0.0179f : 0.0000f * norm_storage + (0.4706f * 1.0000f + 0.0179f - 0.0000f * 1.0000f); break;
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
        case  1: norm_outflow = (norm_storage <= 1.0000f) ? 0.5056f * norm_storage + 0.0385f : 0.0000f * norm_storage + (0.5056f * 1.0000f + 0.0385f - 0.0000f * 1.0000f); break;
        case  2: norm_outflow = (norm_storage <= 1.0000f) ? 0.7857f * norm_storage + 0.0174f : 0.0000f * norm_storage + (0.7857f * 1.0000f + 0.0174f - 0.0000f * 1.0000f); break;
        case  3: norm_outflow = (norm_storage <= 1.0000f) ? 0.4237f * norm_storage + 0.0369f : 0.0000f * norm_storage + (0.4237f * 1.0000f + 0.0369f - 0.0000f * 1.0000f); break;
        case  4: norm_outflow = (norm_storage <= 1.0000f) ? 0.4781f * norm_storage + 0.0314f : 0.0000f * norm_storage + (0.4781f * 1.0000f + 0.0314f - 0.0000f * 1.0000f); break;
        case  5: norm_outflow = (norm_storage <= 1.0000f) ? 0.2915f * norm_storage + 0.0358f : 0.0000f * norm_storage + (0.2915f * 1.0000f + 0.0358f - 0.0000f * 1.0000f); break;
        case  6: norm_outflow = (norm_storage <= 1.0000f) ? 0.3546f * norm_storage + 0.0277f : 0.0000f * norm_storage + (0.3546f * 1.0000f + 0.0277f - 0.0000f * 1.0000f); break;
        case  7: norm_outflow = (norm_storage <= 1.0000f) ? 0.4121f * norm_storage + -0.0127f : 0.0000f * norm_storage + (0.4121f * 1.0000f + -0.0127f - 0.0000f * 1.0000f); break;
        case  8: norm_outflow = (norm_storage <= 1.0000f) ? 1.4241f * norm_storage + -0.0938f : 0.0000f * norm_storage + (1.4241f * 1.0000f + -0.0938f - 0.0000f * 1.0000f); break;
        case  9: norm_outflow = (norm_storage <= 1.0000f) ? 0.6938f * norm_storage + -0.0403f : 0.0000f * norm_storage + (0.6938f * 1.0000f + -0.0403f - 0.0000f * 1.0000f); break;
        case 10: norm_outflow = (norm_storage <= 1.0000f) ? 0.4096f * norm_storage + -0.0136f : 0.0000f * norm_storage + (0.4096f * 1.0000f + -0.0136f - 0.0000f * 1.0000f); break;
        case 11: norm_outflow = (norm_storage <= 1.0000f) ? 0.6791f * norm_storage + -0.0160f : 0.0000f * norm_storage + (0.6791f * 1.0000f + -0.0160f - 0.0000f * 1.0000f); break;
        case 12: norm_outflow = (norm_storage <= 1.0000f) ? 0.5365f * norm_storage + 0.0247f : 0.0000f * norm_storage + (0.5365f * 1.0000f + 0.0247f - 0.0000f * 1.0000f); break;
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
        case  1: norm_outflow = (norm_storage <= 1.0000f) ? 0.4656f * norm_storage + -0.0131f : 0.0000f * norm_storage + (0.4656f * 1.0000f + -0.0131f - 0.0000f * 1.0000f); break;
        case  2: norm_outflow = (norm_storage <= 1.0000f) ? 0.5110f * norm_storage + -0.0147f : 0.0000f * norm_storage + (0.5110f * 1.0000f + -0.0147f - 0.0000f * 1.0000f); break;
        case  3: norm_outflow = (norm_storage <= 1.0000f) ? 0.3986f * norm_storage + -0.0003f : 0.0000f * norm_storage + (0.3986f * 1.0000f + -0.0003f - 0.0000f * 1.0000f); break;
        case  4: norm_outflow = (norm_storage <= 1.0000f) ? 0.4025f * norm_storage + 0.0148f : 0.0000f * norm_storage + (0.4025f * 1.0000f + 0.0148f - 0.0000f * 1.0000f); break;
        case  5: norm_outflow = (norm_storage <= 1.0000f) ? 0.4664f * norm_storage + -0.0206f : 0.0000f * norm_storage + (0.4664f * 1.0000f + -0.0206f - 0.0000f * 1.0000f); break;
        case  6: norm_outflow = (norm_storage <= 1.0000f) ? 0.3131f * norm_storage + -0.0015f : 0.0000f * norm_storage + (0.3131f * 1.0000f + -0.0015f - 0.0000f * 1.0000f); break;
        case  7: norm_outflow = (norm_storage <= 1.0000f) ? 0.3594f * norm_storage + -0.0271f : 0.0000f * norm_storage + (0.3594f * 1.0000f + -0.0271f - 0.0000f * 1.0000f); break;
        case  8: norm_outflow = (norm_storage <= 1.0000f) ? 0.6443f * norm_storage + -0.0583f : 0.0000f * norm_storage + (0.6443f * 1.0000f + -0.0583f - 0.0000f * 1.0000f); break;
        case  9: norm_outflow = (norm_storage <= 1.0000f) ? 0.7485f * norm_storage + -0.0670f : 0.0000f * norm_storage + (0.7485f * 1.0000f + -0.0670f - 0.0000f * 1.0000f); break;
        case 10: norm_outflow = (norm_storage <= 1.0000f) ? 0.5663f * norm_storage + -0.0453f : 0.0000f * norm_storage + (0.5663f * 1.0000f + -0.0453f - 0.0000f * 1.0000f); break;
        case 11: norm_outflow = (norm_storage <= 1.0000f) ? 0.7992f * norm_storage + -0.0664f : 0.0000f * norm_storage + (0.7992f * 1.0000f + -0.0664f - 0.0000f * 1.0000f); break;
        case 12: norm_outflow = (norm_storage <= 1.0000f) ? 0.7242f * norm_storage + -0.0496f : 0.0000f * norm_storage + (0.7242f * 1.0000f + -0.0496f - 0.0000f * 1.0000f); break;
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
        case  1: norm_outflow = (norm_storage <= 0.8425f) ? 0.0001f * norm_storage + 0.0001f : 0.9545f * norm_storage + (0.0001f * 0.8425f + 0.0001f - 0.9545f * 0.8425f); break;
        case  2: norm_outflow = (norm_storage <= 0.8354f) ? 0.0000f * norm_storage + 0.0001f : 0.9553f * norm_storage + (0.0000f * 0.8354f + 0.0001f - 0.9553f * 0.8354f); break;
        case  3: norm_outflow = (norm_storage <= 0.8569f) ? 0.0000f * norm_storage + 0.0001f : 2.6613f * norm_storage + (0.0000f * 0.8569f + 0.0001f - 2.6613f * 0.8569f); break;
        case  4: norm_outflow = (norm_storage <= 0.8605f) ? 0.0004f * norm_storage + 0.0000f : 3.6909f * norm_storage + (0.0004f * 0.8605f + 0.0000f - 3.6909f * 0.8605f); break;
        case  5: norm_outflow = (norm_storage <= 0.8605f) ? 0.0095f * norm_storage + 0.0000f : 5.3965f * norm_storage + (0.0095f * 0.8605f + 0.0000f - 5.3965f * 0.8605f); break;
        case  6: norm_outflow = (norm_storage <= 0.7962f) ? 0.0001f * norm_storage + 0.0000f : 0.5814f * norm_storage + (0.0001f * 0.7962f + 0.0000f - 0.5814f * 0.7962f); break;
        case  7: norm_outflow = (norm_storage <= 0.8594f) ? 0.0015f * norm_storage + 0.0000f : 0.9529f * norm_storage + (0.0015f * 0.8594f + 0.0000f - 0.9529f * 0.8594f); break;
        case  8: norm_outflow = (norm_storage <= 0.8660f) ? 0.0001f * norm_storage + 0.0001f : 8.6384f * norm_storage + (0.0001f * 0.8660f + 0.0001f - 8.6384f * 0.8660f); break;
        case  9: norm_outflow = 0.0000f * norm_inflow + 0.0001f; break;
        case 10: norm_outflow = (norm_storage <= 0.8597f) ? 0.0001f * norm_storage + 0.0001f : 0.9533f * norm_storage + (0.0001f * 0.8597f + 0.0001f - 0.9533f * 0.8597f); break;
        case 11: norm_outflow = (norm_storage <= 0.8534f) ? 0.0001f * norm_storage + 0.0001f : 0.9475f * norm_storage + (0.0001f * 0.8534f + 0.0001f - 0.9475f * 0.8534f); break;
        case 12: norm_outflow = (norm_storage <= 0.8401f) ? 0.0001f * norm_storage + 0.0001f : 0.9503f * norm_storage + (0.0001f * 0.8401f + 0.0001f - 0.9503f * 0.8401f); break;
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
        case  1: norm_outflow = (norm_storage <= 0.7626f) ? 0.1000f * norm_storage + 0.0073f : 4.3851f * norm_storage + (0.1000f * 0.7626f + 0.0073f - 4.3851f * 0.7626f); break;
        case  2: norm_outflow = (norm_storage <= 0.7700f) ? 0.0935f * norm_storage + 0.0000f : 4.2435f * norm_storage + (0.0935f * 0.7700f + 0.0000f - 4.2435f * 0.7700f); break;
        case  3: norm_outflow = (norm_storage <= 0.7837f) ? 0.1000f * norm_storage + 0.0127f : 6.4919f * norm_storage + (0.1000f * 0.7837f + 0.0127f - 6.4919f * 0.7837f); break;
        case  4: norm_outflow = (norm_storage <= 0.7729f) ? 0.0001f * norm_storage + 0.0338f : 5.1983f * norm_storage + (0.0001f * 0.7729f + 0.0338f - 5.1983f * 0.7729f); break;
        case  5: norm_outflow = (norm_storage <= 1.0000f) ? 3.1897f * norm_storage + -2.4127f : 0.0000f * norm_storage + (3.1897f * 1.0000f + -2.4127f - 0.0000f * 1.0000f); break;
        case  6: norm_outflow = (norm_storage <= 0.7945f) ? 0.0000f * norm_storage + 0.0863f : 5.6853f * norm_storage + (0.0000f * 0.7945f + 0.0863f - 5.6853f * 0.7945f); break;
        case  7: norm_outflow = 0.9532f * norm_inflow + 0.1152f; break;
        case  8: norm_outflow = 0.6876f * norm_inflow + 0.1065f; break;
        case  9: norm_outflow = (norm_storage <= 1.0000f) ? 1.0599f * norm_storage + -0.6811f : 0.0000f * norm_storage + (1.0599f * 1.0000f + -0.6811f - 0.0000f * 1.0000f); break;
        case 10: norm_outflow = (norm_storage <= 0.7715f) ? 0.0543f * norm_storage + 0.0000f : 3.2891f * norm_storage + (0.0543f * 0.7715f + 0.0000f - 3.2891f * 0.7715f); break;
        case 11: norm_outflow = (norm_storage <= 0.7824f) ? 0.0527f * norm_storage + 0.0000f : 5.1516f * norm_storage + (0.0527f * 0.7824f + 0.0000f - 5.1516f * 0.7824f); break;
        case 12: norm_outflow = (norm_storage <= 0.7296f) ? 0.0404f * norm_storage + 0.0000f : 3.1340f * norm_storage + (0.0404f * 0.7296f + 0.0000f - 3.1340f * 0.7296f); break;
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
        case  1: norm_outflow = (norm_storage <= 0.6000f) ? 0.0286f * norm_storage + 0.0000f : 4.6174f * norm_storage + (0.0286f * 0.6000f + 0.0000f - 4.6174f * 0.6000f); break;
        case  2: norm_outflow = (norm_storage <= 1.0000f) ? 0.1492f * norm_storage + -0.0529f : 0.0000f * norm_storage + (0.1492f * 1.0000f + -0.0529f - 0.0000f * 1.0000f); break;
        case  3: norm_outflow = (norm_storage <= 0.6000f) ? 0.0561f * norm_storage + 0.0000f : 3.2226f * norm_storage + (0.0561f * 0.6000f + 0.0000f - 3.2226f * 0.6000f); break;
        case  4: norm_outflow = (norm_storage <= 0.6000f) ? 0.0531f * norm_storage + 0.0000f : 2.0087f * norm_storage + (0.0531f * 0.6000f + 0.0000f - 2.0087f * 0.6000f); break;
        case  5: norm_outflow = (norm_storage <= 0.6000f) ? 0.0666f * norm_storage + 0.0000f : 1.2976f * norm_storage + (0.0666f * 0.6000f + 0.0000f - 1.2976f * 0.6000f); break;
        case  6: norm_outflow = (norm_storage <= 0.6000f) ? 0.0864f * norm_storage + 0.0000f : 1.3727f * norm_storage + (0.0864f * 0.6000f + 0.0000f - 1.3727f * 0.6000f); break;
        case  7: norm_outflow = (norm_storage <= 0.6000f) ? 0.0277f * norm_storage + 0.0000f : 1.9589f * norm_storage + (0.0277f * 0.6000f + 0.0000f - 1.9589f * 0.6000f); break;
        case  8: norm_outflow = (norm_storage <= 0.6000f) ? 0.0200f * norm_storage + 0.0000f : 2.8489f * norm_storage + (0.0200f * 0.6000f + 0.0000f - 2.8489f * 0.6000f); break;
        case  9: norm_outflow = (norm_storage <= 0.6000f) ? 0.0263f * norm_storage + 0.0000f : 7.2080f * norm_storage + (0.0263f * 0.6000f + 0.0000f - 7.2080f * 0.6000f); break;
        case 10: norm_outflow = (norm_storage <= 0.6000f) ? 0.0147f * norm_storage + 0.0000f : 0.9518f * norm_storage + (0.0147f * 0.6000f + 0.0000f - 0.9518f * 0.6000f); break;
        case 11: norm_outflow = (norm_storage <= 0.6000f) ? 0.0347f * norm_storage + 0.0000f : 1.9376f * norm_storage + (0.0347f * 0.6000f + 0.0000f - 1.9376f * 0.6000f); break;
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
        case  1: norm_outflow = (norm_storage <= 0.6906f) ? 0.0702f * norm_storage + 0.0000f : 3.8268f * norm_storage + (0.0702f * 0.6906f + 0.0000f - 3.8268f * 0.6906f); break;
        case  2: norm_outflow = (norm_storage <= 0.6900f) ? 0.0500f * norm_storage + 0.0000f : 2.8753f * norm_storage + (0.0500f * 0.6900f + 0.0000f - 2.8753f * 0.6900f); break;
        case  3: norm_outflow = (norm_storage <= 1.0000f) ? 1.9250f * norm_storage + -1.2560f : 0.0000f * norm_storage + (1.9250f * 1.0000f + -1.2560f - 0.0000f * 1.0000f); break;
        case  4: norm_outflow = (norm_storage <= 0.7209f) ? 0.0695f * norm_storage + 0.0000f : 4.4339f * norm_storage + (0.0695f * 0.7209f + 0.0000f - 4.4339f * 0.7209f); break;
        case  5: norm_outflow = (norm_storage <= 1.0000f) ? 3.2352f * norm_storage + -2.2884f : 0.0000f * norm_storage + (3.2352f * 1.0000f + -2.2884f - 0.0000f * 1.0000f); break;
        case  6: norm_outflow = (norm_storage <= 0.7420f) ? 0.0886f * norm_storage + 0.0000f : 6.5756f * norm_storage + (0.0886f * 0.7420f + 0.0000f - 6.5756f * 0.7420f); break;
        case  7: norm_outflow = 1.8143f * norm_inflow + 0.0664f; break;
        case  8: norm_outflow = 0.9457f * norm_inflow + 0.0600f; break;
        case  9: norm_outflow = (norm_storage <= 0.7307f) ? 0.0664f * norm_storage + 0.0000f : 7.3833f * norm_storage + (0.0664f * 0.7307f + 0.0000f - 7.3833f * 0.7307f); break;
        case 10: norm_outflow = (norm_storage <= 0.7453f) ? 0.0481f * norm_storage + 0.0000f : 13.1033f * norm_storage + (0.0481f * 0.7453f + 0.0000f - 13.1033f * 0.7453f); break;
        case 11: norm_outflow = (norm_storage <= 1.0000f) ? 0.8687f * norm_storage + -0.5053f : 0.0000f * norm_storage + (0.8687f * 1.0000f + -0.5053f - 0.0000f * 1.0000f); break;
        case 12: norm_outflow = (norm_storage <= 0.6657f) ? 0.0526f * norm_storage + 0.0000f : 2.7205f * norm_storage + (0.0526f * 0.6657f + 0.0000f - 2.7205f * 0.6657f); break;
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
        case  1: norm_outflow = (norm_storage <= 1.0000f) ? 2.9184f * norm_storage + -0.3836f : 0.0000f * norm_storage + (2.9184f * 1.0000f + -0.3836f - 0.0000f * 1.0000f); break;
        case  2: norm_outflow = (norm_storage <= 1.0000f) ? 1.2578f * norm_storage + -0.0634f : 0.0000f * norm_storage + (1.2578f * 1.0000f + -0.0634f - 0.0000f * 1.0000f); break;
        case  3: norm_outflow = (norm_storage <= 1.0000f) ? 1.4360f * norm_storage + -0.0163f : 0.0000f * norm_storage + (1.4360f * 1.0000f + -0.0163f - 0.0000f * 1.0000f); break;
        case  4: norm_outflow = (norm_storage <= 1.0000f) ? 1.5558f * norm_storage + -0.0710f : 0.0000f * norm_storage + (1.5558f * 1.0000f + -0.0710f - 0.0000f * 1.0000f); break;
        case  5: norm_outflow = (norm_storage <= 1.0000f) ? 1.5793f * norm_storage + -0.0994f : 0.0000f * norm_storage + (1.5793f * 1.0000f + -0.0994f - 0.0000f * 1.0000f); break;
        case  6: norm_outflow = (norm_storage <= 1.0000f) ? 2.6673f * norm_storage + -0.3808f : 0.0000f * norm_storage + (2.6673f * 1.0000f + -0.3808f - 0.0000f * 1.0000f); break;
        case  7: norm_outflow = (norm_storage <= 1.0000f) ? 5.7874f * norm_storage + -0.9052f : 0.0000f * norm_storage + (5.7874f * 1.0000f + -0.9052f - 0.0000f * 1.0000f); break;
        case  8: norm_outflow = (norm_storage <= 1.0000f) ? 5.1577f * norm_storage + -0.7802f : 0.0000f * norm_storage + (5.1577f * 1.0000f + -0.7802f - 0.0000f * 1.0000f); break;
        case  9: norm_outflow = (norm_storage <= 1.0000f) ? 3.6095f * norm_storage + -0.5277f : 0.0000f * norm_storage + (3.6095f * 1.0000f + -0.5277f - 0.0000f * 1.0000f); break;
        case 10: norm_outflow = (norm_storage <= 1.0000f) ? 3.6925f * norm_storage + -0.5313f : 0.0000f * norm_storage + (3.6925f * 1.0000f + -0.5313f - 0.0000f * 1.0000f); break;
        case 11: norm_outflow = (norm_storage <= 1.0000f) ? 2.6069f * norm_storage + -0.3538f : 0.0000f * norm_storage + (2.6069f * 1.0000f + -0.3538f - 0.0000f * 1.0000f); break;
        case 12: norm_outflow = (norm_storage <= 1.0000f) ? 2.0350f * norm_storage + -0.2222f : 0.0000f * norm_storage + (2.0350f * 1.0000f + -0.2222f - 0.0000f * 1.0000f); break;
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
        case  1: norm_outflow = (norm_storage <= 1.0000f) ? 0.6307f * norm_storage + -0.3471f : 0.0000f * norm_storage + (0.6307f * 1.0000f + -0.3471f - 0.0000f * 1.0000f); break;
        case  2: norm_outflow = (norm_storage <= 0.6472f) ? 0.0401f * norm_storage + 0.0000f : 1.0667f * norm_storage + (0.0401f * 0.6472f + 0.0000f - 1.0667f * 0.6472f); break;
        case  3: norm_outflow = (norm_storage <= 1.0000f) ? 0.4624f * norm_storage + -0.2567f : 0.0000f * norm_storage + (0.4624f * 1.0000f + -0.2567f - 0.0000f * 1.0000f); break;
        case  4: norm_outflow = (norm_storage <= 1.0000f) ? 0.6961f * norm_storage + -0.4184f : 0.0000f * norm_storage + (0.6961f * 1.0000f + -0.4184f - 0.0000f * 1.0000f); break;
        case  5: norm_outflow = (norm_storage <= 1.0000f) ? 0.7482f * norm_storage + -0.4733f : 0.0000f * norm_storage + (0.7482f * 1.0000f + -0.4733f - 0.0000f * 1.0000f); break;
        case  6: norm_outflow = (norm_storage <= 1.0000f) ? 0.9233f * norm_storage + -0.5959f : 0.0000f * norm_storage + (0.9233f * 1.0000f + -0.5959f - 0.0000f * 1.0000f); break;
        case  7: norm_outflow = (norm_storage <= 0.6977f) ? 0.0403f * norm_storage + 0.0000f : 0.9763f * norm_storage + (0.0403f * 0.6977f + 0.0000f - 0.9763f * 0.6977f); break;
        case  8: norm_outflow = (norm_storage <= 1.0000f) ? 0.2387f * norm_storage + -0.1299f : 0.0000f * norm_storage + (0.2387f * 1.0000f + -0.1299f - 0.0000f * 1.0000f); break;
        case  9: norm_outflow = (norm_storage <= 1.0000f) ? 0.2894f * norm_storage + -0.1641f : 0.0000f * norm_storage + (0.2894f * 1.0000f + -0.1641f - 0.0000f * 1.0000f); break;
        case 10: norm_outflow = (norm_storage <= 0.6795f) ? 0.0112f * norm_storage + 0.0051f : 2.1117f * norm_storage + (0.0112f * 0.6795f + 0.0051f - 2.1117f * 0.6795f); break;
        case 11: norm_outflow = (norm_storage <= 0.6546f) ? 0.0281f * norm_storage + 0.0000f : 1.2924f * norm_storage + (0.0281f * 0.6546f + 0.0000f - 1.2924f * 0.6546f); break;
        case 12: norm_outflow = (norm_storage <= 0.6484f) ? 0.0250f * norm_storage + 0.0000f : 1.0464f * norm_storage + (0.0250f * 0.6484f + 0.0000f - 1.0464f * 0.6484f); break;
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
        case  1: norm_outflow = (norm_storage <= 1.0000f) ? 1.7362f * norm_storage + -0.3565f : 0.0000f * norm_storage + (1.7362f * 1.0000f + -0.3565f - 0.0000f * 1.0000f); break;
        case  2: norm_outflow = (norm_storage <= 1.0000f) ? 1.6200f * norm_storage + -0.3201f : 0.0000f * norm_storage + (1.6200f * 1.0000f + -0.3201f - 0.0000f * 1.0000f); break;
        case  3: norm_outflow = (norm_storage <= 1.0000f) ? 1.0186f * norm_storage + -0.0894f : 0.0000f * norm_storage + (1.0186f * 1.0000f + -0.0894f - 0.0000f * 1.0000f); break;
        case  4: norm_outflow = (norm_storage <= 1.0000f) ? 0.9864f * norm_storage + -0.1044f : 0.0000f * norm_storage + (0.9864f * 1.0000f + -0.1044f - 0.0000f * 1.0000f); break;
        case  5: norm_outflow = (norm_storage <= 1.0000f) ? 1.3539f * norm_storage + -0.2316f : 0.0000f * norm_storage + (1.3539f * 1.0000f + -0.2316f - 0.0000f * 1.0000f); break;
        case  6: norm_outflow = (norm_storage <= 1.0000f) ? 2.3160f * norm_storage + -0.5886f : 0.0000f * norm_storage + (2.3160f * 1.0000f + -0.5886f - 0.0000f * 1.0000f); break;
        case  7: norm_outflow = (norm_storage <= 1.0000f) ? 1.8366f * norm_storage + -0.4796f : 0.0000f * norm_storage + (1.8366f * 1.0000f + -0.4796f - 0.0000f * 1.0000f); break;
        case  8: norm_outflow = (norm_storage <= 1.0000f) ? 3.9530f * norm_storage + -1.0525f : 0.0000f * norm_storage + (3.9530f * 1.0000f + -1.0525f - 0.0000f * 1.0000f); break;
        case  9: norm_outflow = (norm_storage <= 1.0000f) ? 3.1230f * norm_storage + -0.8147f : 0.0000f * norm_storage + (3.1230f * 1.0000f + -0.8147f - 0.0000f * 1.0000f); break;
        case 10: norm_outflow = (norm_storage <= 1.0000f) ? 1.0735f * norm_storage + -0.2563f : 0.0000f * norm_storage + (1.0735f * 1.0000f + -0.2563f - 0.0000f * 1.0000f); break;
        case 11: norm_outflow = (norm_storage <= 1.0000f) ? 2.3359f * norm_storage + -0.5752f : 0.0000f * norm_storage + (2.3359f * 1.0000f + -0.5752f - 0.0000f * 1.0000f); break;
        case 12: norm_outflow = (norm_storage <= 1.0000f) ? 1.6462f * norm_storage + -0.3390f : 0.0000f * norm_storage + (1.6462f * 1.0000f + -0.3390f - 0.0000f * 1.0000f); break;
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
        case  1: norm_outflow = (norm_storage <= 0.6906f) ? 0.0702f * norm_storage + 0.0000f : 3.8268f * norm_storage + (0.0702f * 0.6906f + 0.0000f - 3.8268f * 0.6906f); break;
        case  2: norm_outflow = (norm_storage <= 0.6900f) ? 0.0500f * norm_storage + 0.0000f : 2.8753f * norm_storage + (0.0500f * 0.6900f + 0.0000f - 2.8753f * 0.6900f); break;
        case  3: norm_outflow = (norm_storage <= 1.0000f) ? 1.9250f * norm_storage + -1.2560f : 0.0000f * norm_storage + (1.9250f * 1.0000f + -1.2560f - 0.0000f * 1.0000f); break;
        case  4: norm_outflow = (norm_storage <= 0.7209f) ? 0.0695f * norm_storage + 0.0000f : 4.4339f * norm_storage + (0.0695f * 0.7209f + 0.0000f - 4.4339f * 0.7209f); break;
        case  5: norm_outflow = (norm_storage <= 1.0000f) ? 3.2352f * norm_storage + -2.2884f : 0.0000f * norm_storage + (3.2352f * 1.0000f + -2.2884f - 0.0000f * 1.0000f); break;
        case  6: norm_outflow = (norm_storage <= 0.7420f) ? 0.0886f * norm_storage + 0.0000f : 6.5756f * norm_storage + (0.0886f * 0.7420f + 0.0000f - 6.5756f * 0.7420f); break;
        case  7: norm_outflow = 1.8143f * norm_inflow + 0.0664f; break;
        case  8: norm_outflow = 0.9457f * norm_inflow + 0.0600f; break;
        case  9: norm_outflow = (norm_storage <= 0.7307f) ? 0.0664f * norm_storage + 0.0000f : 7.3833f * norm_storage + (0.0664f * 0.7307f + 0.0000f - 7.3833f * 0.7307f); break;
        case 10: norm_outflow = (norm_storage <= 0.7453f) ? 0.0481f * norm_storage + 0.0000f : 13.1033f * norm_storage + (0.0481f * 0.7453f + 0.0000f - 13.1033f * 0.7453f); break;
        case 11: norm_outflow = (norm_storage <= 1.0000f) ? 0.8687f * norm_storage + -0.5053f : 0.0000f * norm_storage + (0.8687f * 1.0000f + -0.5053f - 0.0000f * 1.0000f); break;
        case 12: norm_outflow = (norm_storage <= 0.6657f) ? 0.0526f * norm_storage + 0.0000f : 2.7205f * norm_storage + (0.0526f * 0.6657f + 0.0000f - 2.7205f * 0.6657f); break;
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
        case  1: norm_outflow = (norm_storage <= 1.0000f) ? 0.9038f * norm_storage + 0.0148f : 0.0000f * norm_storage + (0.9038f * 1.0000f + 0.0148f - 0.0000f * 1.0000f); break;
        case  2: norm_outflow = (norm_storage <= 1.0000f) ? 0.8840f * norm_storage + 0.0266f : 0.0000f * norm_storage + (0.8840f * 1.0000f + 0.0266f - 0.0000f * 1.0000f); break;
        case  3: norm_outflow = (norm_storage <= 1.0000f) ? 0.9293f * norm_storage + 0.0266f : 0.0000f * norm_storage + (0.9293f * 1.0000f + 0.0266f - 0.0000f * 1.0000f); break;
        case  4: norm_outflow = (norm_storage <= 1.0000f) ? 0.7373f * norm_storage + 0.0750f : 0.0000f * norm_storage + (0.7373f * 1.0000f + 0.0750f - 0.0000f * 1.0000f); break;
        case  5: norm_outflow = (norm_storage <= 1.0000f) ? 0.6279f * norm_storage + 0.0754f : 0.0000f * norm_storage + (0.6279f * 1.0000f + 0.0754f - 0.0000f * 1.0000f); break;
        case  6: norm_outflow = (norm_storage <= 1.0000f) ? 1.1207f * norm_storage + -0.0329f : 0.0000f * norm_storage + (1.1207f * 1.0000f + -0.0329f - 0.0000f * 1.0000f); break;
        case  7: norm_outflow = (norm_storage <= 1.0000f) ? 1.3625f * norm_storage + -0.1197f : 0.0000f * norm_storage + (1.3625f * 1.0000f + -0.1197f - 0.0000f * 1.0000f); break;
        case  8: norm_outflow = (norm_storage <= 1.0000f) ? 0.5272f * norm_storage + -0.0303f : 0.0000f * norm_storage + (0.5272f * 1.0000f + -0.0303f - 0.0000f * 1.0000f); break;
        case  9: norm_outflow = (norm_storage <= 1.0000f) ? 0.9433f * norm_storage + -0.0595f : 0.0000f * norm_storage + (0.9433f * 1.0000f + -0.0595f - 0.0000f * 1.0000f); break;
        case 10: norm_outflow = (norm_storage <= 1.0000f) ? 1.0895f * norm_storage + -0.0649f : 0.0000f * norm_storage + (1.0895f * 1.0000f + -0.0649f - 0.0000f * 1.0000f); break;
        case 11: norm_outflow = (norm_storage <= 1.0000f) ? 1.9108f * norm_storage + -0.1206f : 0.0000f * norm_storage + (1.9108f * 1.0000f + -0.1206f - 0.0000f * 1.0000f); break;
        case 12: norm_outflow = (norm_storage <= 1.0000f) ? 0.6466f * norm_storage + 0.0303f : 0.0000f * norm_storage + (0.6466f * 1.0000f + 0.0303f - 0.0000f * 1.0000f); break;
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
        case  1: norm_outflow = (norm_storage <= 1.0000f) ? 1.8582f * norm_storage + -0.2940f : 0.0000f * norm_storage + (1.8582f * 1.0000f + -0.2940f - 0.0000f * 1.0000f); break;
        case  2: norm_outflow = (norm_storage <= 1.0000f) ? 0.9544f * norm_storage + -0.0865f : 0.0000f * norm_storage + (0.9544f * 1.0000f + -0.0865f - 0.0000f * 1.0000f); break;
        case  3: norm_outflow = (norm_storage <= 1.0000f) ? 1.4980f * norm_storage + -0.1715f : 0.0000f * norm_storage + (1.4980f * 1.0000f + -0.1715f - 0.0000f * 1.0000f); break;
        case  4: norm_outflow = (norm_storage <= 1.0000f) ? 1.0256f * norm_storage + -0.0724f : 0.0000f * norm_storage + (1.0256f * 1.0000f + -0.0724f - 0.0000f * 1.0000f); break;
        case  5: norm_outflow = (norm_storage <= 1.0000f) ? 0.9279f * norm_storage + -0.0654f : 0.0000f * norm_storage + (0.9279f * 1.0000f + -0.0654f - 0.0000f * 1.0000f); break;
        case  6: norm_outflow = (norm_storage <= 1.0000f) ? 1.4069f * norm_storage + -0.2486f : 0.0000f * norm_storage + (1.4069f * 1.0000f + -0.2486f - 0.0000f * 1.0000f); break;
        case  7: norm_outflow = (norm_storage <= 1.0000f) ? 2.8812f * norm_storage + -0.6071f : 0.0000f * norm_storage + (2.8812f * 1.0000f + -0.6071f - 0.0000f * 1.0000f); break;
        case  8: norm_outflow = (norm_storage <= 1.0000f) ? 2.6629f * norm_storage + -0.5411f : 0.0000f * norm_storage + (2.6629f * 1.0000f + -0.5411f - 0.0000f * 1.0000f); break;
        case  9: norm_outflow = (norm_storage <= 1.0000f) ? 1.9991f * norm_storage + -0.3942f : 0.0000f * norm_storage + (1.9991f * 1.0000f + -0.3942f - 0.0000f * 1.0000f); break;
        case 10: norm_outflow = (norm_storage <= 1.0000f) ? 0.8108f * norm_storage + -0.1358f : 0.0000f * norm_storage + (0.8108f * 1.0000f + -0.1358f - 0.0000f * 1.0000f); break;
        case 11: norm_outflow = (norm_storage <= 1.0000f) ? 2.3426f * norm_storage + -0.4351f : 0.0000f * norm_storage + (2.3426f * 1.0000f + -0.4351f - 0.0000f * 1.0000f); break;
        case 12: norm_outflow = (norm_storage <= 1.0000f) ? 1.0713f * norm_storage + -0.1318f : 0.0000f * norm_storage + (1.0713f * 1.0000f + -0.1318f - 0.0000f * 1.0000f); break;
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
        case  1: norm_outflow = (norm_storage <= 1.0000f) ? 0.5313f * norm_storage + -0.0421f : 0.0000f * norm_storage + (0.5313f * 1.0000f + -0.0421f - 0.0000f * 1.0000f); break;
        case  2: norm_outflow = (norm_storage <= 1.0000f) ? 0.7255f * norm_storage + -0.0768f : 0.0000f * norm_storage + (0.7255f * 1.0000f + -0.0768f - 0.0000f * 1.0000f); break;
        case  3: norm_outflow = (norm_storage <= 1.0000f) ? 0.6751f * norm_storage + -0.0660f : 0.0000f * norm_storage + (0.6751f * 1.0000f + -0.0660f - 0.0000f * 1.0000f); break;
        case  4: norm_outflow = (norm_storage <= 1.0000f) ? 0.7614f * norm_storage + -0.0863f : 0.0000f * norm_storage + (0.7614f * 1.0000f + -0.0863f - 0.0000f * 1.0000f); break;
        case  5: norm_outflow = (norm_storage <= 0.8354f) ? 0.1000f * norm_storage + 0.0454f : 5.3657f * norm_storage + (0.1000f * 0.8354f + 0.0454f - 5.3657f * 0.8354f); break;
        case  6: norm_outflow = 0.5704f * norm_inflow + 0.0311f; break;
        case  7: norm_outflow = (norm_storage <= 1.0000f) ? 0.1308f * norm_storage + -0.0100f : 0.0000f * norm_storage + (0.1308f * 1.0000f + -0.0100f - 0.0000f * 1.0000f); break;
        case  8: norm_outflow = (norm_storage <= 1.0000f) ? 0.3965f * norm_storage + -0.0373f : 0.0000f * norm_storage + (0.3965f * 1.0000f + -0.0373f - 0.0000f * 1.0000f); break;
        case  9: norm_outflow = (norm_storage <= 1.0000f) ? 0.2658f * norm_storage + -0.0273f : 0.0000f * norm_storage + (0.2658f * 1.0000f + -0.0273f - 0.0000f * 1.0000f); break;
        case 10: norm_outflow = (norm_storage <= 1.0000f) ? 0.4080f * norm_storage + -0.0449f : 0.0000f * norm_storage + (0.4080f * 1.0000f + -0.0449f - 0.0000f * 1.0000f); break;
        case 11: norm_outflow = (norm_storage <= 1.0000f) ? 0.7537f * norm_storage + -0.0842f : 0.0000f * norm_storage + (0.7537f * 1.0000f + -0.0842f - 0.0000f * 1.0000f); break;
        case 12: norm_outflow = (norm_storage <= 1.0000f) ? 0.4313f * norm_storage + -0.0385f : 0.0000f * norm_storage + (0.4313f * 1.0000f + -0.0385f - 0.0000f * 1.0000f); break;
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
        case  1: norm_outflow = (norm_storage <= 0.6000f) ? 0.0076f * norm_storage + 0.0000f : 1.9545f * norm_storage + (0.0076f * 0.6000f + 0.0000f - 1.9545f * 0.6000f); break;
        case  2: norm_outflow = (norm_storage <= 0.6000f) ? 0.0102f * norm_storage + 0.0000f : 1.9024f * norm_storage + (0.0102f * 0.6000f + 0.0000f - 1.9024f * 0.6000f); break;
        case  3: norm_outflow = (norm_storage <= 0.6000f) ? 0.0338f * norm_storage + 0.0000f : 1.5664f * norm_storage + (0.0338f * 0.6000f + 0.0000f - 1.5664f * 0.6000f); break;
        case  4: norm_outflow = (norm_storage <= 0.6000f) ? 0.0201f * norm_storage + 0.0000f : 1.6124f * norm_storage + (0.0201f * 0.6000f + 0.0000f - 1.6124f * 0.6000f); break;
        case  5: norm_outflow = (norm_storage <= 0.6000f) ? 0.0305f * norm_storage + 0.0000f : 1.3997f * norm_storage + (0.0305f * 0.6000f + 0.0000f - 1.3997f * 0.6000f); break;
        case  6: norm_outflow = (norm_storage <= 0.6000f) ? 0.0272f * norm_storage + 0.0000f : 1.3947f * norm_storage + (0.0272f * 0.6000f + 0.0000f - 1.3947f * 0.6000f); break;
        case  7: norm_outflow = (norm_storage <= 0.6132f) ? 0.0080f * norm_storage + 0.0000f : 2.2182f * norm_storage + (0.0080f * 0.6132f + 0.0000f - 2.2182f * 0.6132f); break;
        case  8: norm_outflow = (norm_storage <= 0.6017f) ? 0.0039f * norm_storage + 0.0000f : 1.0002f * norm_storage + (0.0039f * 0.6017f + 0.0000f - 1.0002f * 0.6017f); break;
        case  9: norm_outflow = (norm_storage <= 0.6000f) ? 0.0032f * norm_storage + 0.0000f : 1.0012f * norm_storage + (0.0032f * 0.6000f + 0.0000f - 1.0012f * 0.6000f); break;
        case 10: norm_outflow = (norm_storage <= 0.6000f) ? 0.0055f * norm_storage + 0.0028f : 1.0077f * norm_storage + (0.0055f * 0.6000f + 0.0028f - 1.0077f * 0.6000f); break;
        case 11: norm_outflow = (norm_storage <= 0.6000f) ? 0.0056f * norm_storage + 0.0000f : 1.9587f * norm_storage + (0.0056f * 0.6000f + 0.0000f - 1.9587f * 0.6000f); break;
        case 12: norm_outflow = (norm_storage <= 0.6000f) ? 0.0056f * norm_storage + 0.0000f : 2.0491f * norm_storage + (0.0056f * 0.6000f + 0.0000f - 2.0491f * 0.6000f); break;
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
        case  1: norm_outflow = (norm_storage <= 1.0000f) ? 1.8430f * norm_storage + -0.6934f : 0.0000f * norm_storage + (1.8430f * 1.0000f + -0.6934f - 0.0000f * 1.0000f); break;
        case  2: norm_outflow = (norm_storage <= 1.0000f) ? 1.1601f * norm_storage + -0.4129f : 0.0000f * norm_storage + (1.1601f * 1.0000f + -0.4129f - 0.0000f * 1.0000f); break;
        case  3: norm_outflow = (norm_storage <= 1.0000f) ? 2.2507f * norm_storage + -0.8496f : 0.0000f * norm_storage + (2.2507f * 1.0000f + -0.8496f - 0.0000f * 1.0000f); break;
        case  4: norm_outflow = (norm_storage <= 1.0000f) ? 2.2028f * norm_storage + -0.8329f : 0.0000f * norm_storage + (2.2028f * 1.0000f + -0.8329f - 0.0000f * 1.0000f); break;
        case  5: norm_outflow = (norm_storage <= 1.0000f) ? 1.3422f * norm_storage + -0.5075f : 0.0000f * norm_storage + (1.3422f * 1.0000f + -0.5075f - 0.0000f * 1.0000f); break;
        case  6: norm_outflow = (norm_storage <= 1.0000f) ? 1.5090f * norm_storage + -0.5939f : 0.0000f * norm_storage + (1.5090f * 1.0000f + -0.5939f - 0.0000f * 1.0000f); break;
        case  7: norm_outflow = (norm_storage <= 1.0000f) ? 1.0549f * norm_storage + -0.4045f : 0.0000f * norm_storage + (1.0549f * 1.0000f + -0.4045f - 0.0000f * 1.0000f); break;
        case  8: norm_outflow = (norm_storage <= 1.0000f) ? 1.7126f * norm_storage + -0.6603f : 0.0000f * norm_storage + (1.7126f * 1.0000f + -0.6603f - 0.0000f * 1.0000f); break;
        case  9: norm_outflow = (norm_storage <= 1.0000f) ? 1.1736f * norm_storage + -0.4420f : 0.0000f * norm_storage + (1.1736f * 1.0000f + -0.4420f - 0.0000f * 1.0000f); break;
        case 10: norm_outflow = (norm_storage <= 1.0000f) ? 0.5584f * norm_storage + -0.2014f : 0.0000f * norm_storage + (0.5584f * 1.0000f + -0.2014f - 0.0000f * 1.0000f); break;
        case 11: norm_outflow = 1.3941f * norm_inflow + 0.0172f; break;
        case 12: norm_outflow = (norm_storage <= 1.0000f) ? 1.1235f * norm_storage + -0.4232f : 0.0000f * norm_storage + (1.1235f * 1.0000f + -0.4232f - 0.0000f * 1.0000f); break;
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
        case  3: norm_outflow = (norm_storage <= 0.9111f) ? 0.0037f * norm_storage + 0.0009f : 6.2187f * norm_storage + (0.0037f * 0.9111f + 0.0009f - 6.2187f * 0.9111f); break;
        case  4: norm_outflow = (norm_storage <= 0.9111f) ? 0.0020f * norm_storage + 0.0000f : 8.5120f * norm_storage + (0.0020f * 0.9111f + 0.0000f - 8.5120f * 0.9111f); break;
        case  5: norm_outflow = (norm_storage <= 0.9074f) ? 0.0069f * norm_storage + 0.0000f : 6.5820f * norm_storage + (0.0069f * 0.9074f + 0.0000f - 6.5820f * 0.9074f); break;
        case  6: norm_outflow = (norm_storage <= 0.9160f) ? 0.0068f * norm_storage + 0.0000f : 7.2174f * norm_storage + (0.0068f * 0.9160f + 0.0000f - 7.2174f * 0.9160f); break;
        case  7: norm_outflow = (norm_storage <= 0.9101f) ? 0.0000f * norm_storage + 0.0005f : 5.9104f * norm_storage + (0.0000f * 0.9101f + 0.0005f - 5.9104f * 0.9101f); break;
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
        case  7: norm_outflow = (norm_storage <= 1.0000f) ? 1.0582f * norm_storage + -0.0893f : 0.0000f * norm_storage + (1.0582f * 1.0000f + -0.0893f - 0.0000f * 1.0000f); break;
        case  8: norm_outflow = 1.1593f * norm_inflow + 0.0063f; break;
        case  9: norm_outflow = 0.9846f * norm_inflow + 0.0056f; break;
        case 10: norm_outflow = 1.2482f * norm_inflow + 0.0034f; break;
        case 11: norm_outflow = 0.9704f * norm_inflow + 0.0159f; break;
        case 12: norm_outflow = (norm_storage <= 1.0000f) ? 1.5607f * norm_storage + -0.1329f : 0.0000f * norm_storage + (1.5607f * 1.0000f + -0.1329f - 0.0000f * 1.0000f); break;
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
        case  6: norm_outflow = (norm_storage <= 0.8661f) ? 0.0205f * norm_storage + 0.0000f : 7.1550f * norm_storage + (0.0205f * 0.8661f + 0.0000f - 7.1550f * 0.8661f); break;
        case  7: norm_outflow = 0.4319f * norm_inflow + 0.0046f; break;
        case  8: norm_outflow = 0.4023f * norm_inflow + 0.0024f; break;
        case  9: norm_outflow = (norm_storage <= 0.8634f) ? 0.0048f * norm_storage + 0.0000f : 6.8583f * norm_storage + (0.0048f * 0.8634f + 0.0000f - 6.8583f * 0.8634f); break;
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
        case  1: norm_outflow = (norm_storage <= 1.0000f) ? 0.5423f * norm_storage + -0.1606f : 0.0000f * norm_storage + (0.5423f * 1.0000f + -0.1606f - 0.0000f * 1.0000f); break;
        case  2: norm_outflow = (norm_storage <= 1.0000f) ? 0.8363f * norm_storage + -0.2709f : 0.0000f * norm_storage + (0.8363f * 1.0000f + -0.2709f - 0.0000f * 1.0000f); break;
        case  3: norm_outflow = (norm_storage <= 1.0000f) ? 0.4713f * norm_storage + -0.1179f : 0.0000f * norm_storage + (0.4713f * 1.0000f + -0.1179f - 0.0000f * 1.0000f); break;
        case  4: norm_outflow = (norm_storage <= 1.0000f) ? 0.6655f * norm_storage + -0.2084f : 0.0000f * norm_storage + (0.6655f * 1.0000f + -0.2084f - 0.0000f * 1.0000f); break;
        case  5: norm_outflow = (norm_storage <= 1.0000f) ? 0.5357f * norm_storage + -0.1671f : 0.0000f * norm_storage + (0.5357f * 1.0000f + -0.1671f - 0.0000f * 1.0000f); break;
        case  6: norm_outflow = (norm_storage <= 1.0000f) ? 0.4761f * norm_storage + -0.1568f : 0.0000f * norm_storage + (0.4761f * 1.0000f + -0.1568f - 0.0000f * 1.0000f); break;
        case  7: norm_outflow = (norm_storage <= 1.0000f) ? 0.5933f * norm_storage + -0.1970f : 0.0000f * norm_storage + (0.5933f * 1.0000f + -0.1970f - 0.0000f * 1.0000f); break;
        case  8: norm_outflow = (norm_storage <= 1.0000f) ? 0.3102f * norm_storage + -0.0868f : 0.0000f * norm_storage + (0.3102f * 1.0000f + -0.0868f - 0.0000f * 1.0000f); break;
        case  9: norm_outflow = 0.0053f * norm_inflow + 0.0251f; break;
        case 10: norm_outflow = (norm_storage <= 1.0000f) ? 0.4196f * norm_storage + -0.1256f : 0.0000f * norm_storage + (0.4196f * 1.0000f + -0.1256f - 0.0000f * 1.0000f); break;
        case 11: norm_outflow = (norm_storage <= 1.0000f) ? 0.4246f * norm_storage + -0.1239f : 0.0000f * norm_storage + (0.4246f * 1.0000f + -0.1239f - 0.0000f * 1.0000f); break;
        case 12: norm_outflow = (norm_storage <= 1.0000f) ? 0.6117f * norm_storage + -0.1899f : 0.0000f * norm_storage + (0.6117f * 1.0000f + -0.1899f - 0.0000f * 1.0000f); break;
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
        case  1: norm_outflow = (norm_storage <= 1.0000f) ? 2.6764f * norm_storage + -1.1554f : 0.0000f * norm_storage + (2.6764f * 1.0000f + -1.1554f - 0.0000f * 1.0000f); break;
        case  2: norm_outflow = 1.1110f * norm_inflow + 0.1129f; break;
        case  3: norm_outflow = (norm_storage <= 1.0000f) ? 2.5415f * norm_storage + -1.0821f : 0.0000f * norm_storage + (2.5415f * 1.0000f + -1.0821f - 0.0000f * 1.0000f); break;
        case  4: norm_outflow = (norm_storage <= 1.0000f) ? 2.1533f * norm_storage + -0.8740f : 0.0000f * norm_storage + (2.1533f * 1.0000f + -0.8740f - 0.0000f * 1.0000f); break;
        case  5: norm_outflow = (norm_storage <= 1.0000f) ? 1.8181f * norm_storage + -0.7388f : 0.0000f * norm_storage + (1.8181f * 1.0000f + -0.7388f - 0.0000f * 1.0000f); break;
        case  6: norm_outflow = 1.1752f * norm_inflow + 0.0428f; break;
        case  7: norm_outflow = 1.3382f * norm_inflow + 0.0201f; break;
        case  8: norm_outflow = (norm_storage <= 1.0000f) ? 0.5172f * norm_storage + -0.1907f : 0.0000f * norm_storage + (0.5172f * 1.0000f + -0.1907f - 0.0000f * 1.0000f); break;
        case  9: norm_outflow = (norm_storage <= 1.0000f) ? 0.5351f * norm_storage + -0.1981f : 0.0000f * norm_storage + (0.5351f * 1.0000f + -0.1981f - 0.0000f * 1.0000f); break;
        case 10: norm_outflow = (norm_storage <= 1.0000f) ? 1.2401f * norm_storage + -0.4801f : 0.0000f * norm_storage + (1.2401f * 1.0000f + -0.4801f - 0.0000f * 1.0000f); break;
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
        case  2: norm_outflow = (norm_storage <= 1.0000f) ? 2.0748f * norm_storage + 0.0119f : 0.0000f * norm_storage + (2.0748f * 1.0000f + 0.0119f - 0.0000f * 1.0000f); break;
        case  3: norm_outflow = 1.5594f * norm_inflow + 0.0343f; break;
        case  4: norm_outflow = 1.3574f * norm_inflow + 0.0264f; break;
        case  5: norm_outflow = (norm_storage <= 1.0000f) ? 1.2639f * norm_storage + -0.0401f : 0.0000f * norm_storage + (1.2639f * 1.0000f + -0.0401f - 0.0000f * 1.0000f); break;
        case  6: norm_outflow = (norm_storage <= 1.0000f) ? 0.8028f * norm_storage + -0.0004f : 0.0000f * norm_storage + (0.8028f * 1.0000f + -0.0004f - 0.0000f * 1.0000f); break;
        case  7: norm_outflow = (norm_storage <= 1.0000f) ? 0.9086f * norm_storage + -0.0380f : 0.0000f * norm_storage + (0.9086f * 1.0000f + -0.0380f - 0.0000f * 1.0000f); break;
        case  8: norm_outflow = (norm_storage <= 1.0000f) ? 1.1634f * norm_storage + -0.0692f : 0.0000f * norm_storage + (1.1634f * 1.0000f + -0.0692f - 0.0000f * 1.0000f); break;
        case  9: norm_outflow = (norm_storage <= 1.0000f) ? 2.6254f * norm_storage + -0.1734f : 0.0000f * norm_storage + (2.6254f * 1.0000f + -0.1734f - 0.0000f * 1.0000f); break;
        case 10: norm_outflow = (norm_storage <= 1.0000f) ? 1.4825f * norm_storage + -0.0591f : 0.0000f * norm_storage + (1.4825f * 1.0000f + -0.0591f - 0.0000f * 1.0000f); break;
        case 11: norm_outflow = 1.1749f * norm_inflow + 0.0213f; break;
        case 12: norm_outflow = (norm_storage <= 1.0000f) ? 3.5855f * norm_storage + -0.0512f : 0.0000f * norm_storage + (3.5855f * 1.0000f + -0.0512f - 0.0000f * 1.0000f); break;
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
        case  1: norm_outflow = (norm_storage <= 1.0000f) ? 0.4814f * norm_storage + 0.0444f : 0.0000f * norm_storage + (0.4814f * 1.0000f + 0.0444f - 0.0000f * 1.0000f); break;
        case  2: norm_outflow = (norm_storage <= 1.0000f) ? 1.0250f * norm_storage + 0.0076f : 0.0000f * norm_storage + (1.0250f * 1.0000f + 0.0076f - 0.0000f * 1.0000f); break;
        case  3: norm_outflow = (norm_storage <= 1.0000f) ? 0.9427f * norm_storage + 0.0173f : 0.0000f * norm_storage + (0.9427f * 1.0000f + 0.0173f - 0.0000f * 1.0000f); break;
        case  4: norm_outflow = (norm_storage <= 1.0000f) ? 0.5225f * norm_storage + -0.0337f : 0.0000f * norm_storage + (0.5225f * 1.0000f + -0.0337f - 0.0000f * 1.0000f); break;
        case  5: norm_outflow = (norm_storage <= 1.0000f) ? 0.5408f * norm_storage + -0.0618f : 0.0000f * norm_storage + (0.5408f * 1.0000f + -0.0618f - 0.0000f * 1.0000f); break;
        case  6: norm_outflow = (norm_storage <= 1.0000f) ? 0.4447f * norm_storage + -0.0355f : 0.0000f * norm_storage + (0.4447f * 1.0000f + -0.0355f - 0.0000f * 1.0000f); break;
        case  7: norm_outflow = (norm_storage <= 1.0000f) ? 0.6233f * norm_storage + -0.0996f : 0.0000f * norm_storage + (0.6233f * 1.0000f + -0.0996f - 0.0000f * 1.0000f); break;
        case  8: norm_outflow = (norm_storage <= 1.0000f) ? 0.6747f * norm_storage + -0.1211f : 0.0000f * norm_storage + (0.6747f * 1.0000f + -0.1211f - 0.0000f * 1.0000f); break;
        case  9: norm_outflow = (norm_storage <= 1.0000f) ? 1.1417f * norm_storage + -0.2041f : 0.0000f * norm_storage + (1.1417f * 1.0000f + -0.2041f - 0.0000f * 1.0000f); break;
        case 10: norm_outflow = 0.2262f * norm_inflow + 0.0565f; break;
        case 11: norm_outflow = (norm_storage <= 1.0000f) ? 0.5311f * norm_storage + 0.0157f : 0.0000f * norm_storage + (0.5311f * 1.0000f + 0.0157f - 0.0000f * 1.0000f); break;
        case 12: norm_outflow = (norm_storage <= 1.0000f) ? 1.4109f * norm_storage + -0.0174f : 0.0000f * norm_storage + (1.4109f * 1.0000f + -0.0174f - 0.0000f * 1.0000f); break;
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
        case  1: norm_outflow = (norm_storage <= 1.0000f) ? 1.5723f * norm_storage + 0.0111f : 0.0000f * norm_storage + (1.5723f * 1.0000f + 0.0111f - 0.0000f * 1.0000f); break;
        case  2: norm_outflow = (norm_storage <= 1.0000f) ? 1.4951f * norm_storage + 0.0234f : 0.0000f * norm_storage + (1.4951f * 1.0000f + 0.0234f - 0.0000f * 1.0000f); break;
        case  3: norm_outflow = (norm_storage <= 1.0000f) ? 1.8488f * norm_storage + -0.0031f : 0.0000f * norm_storage + (1.8488f * 1.0000f + -0.0031f - 0.0000f * 1.0000f); break;
        case  4: norm_outflow = (norm_storage <= 1.0000f) ? 0.9810f * norm_storage + -0.0266f : 0.0000f * norm_storage + (0.9810f * 1.0000f + -0.0266f - 0.0000f * 1.0000f); break;
        case  5: norm_outflow = 1.0193f * norm_inflow + 0.1021f; break;
        case  6: norm_outflow = 0.8906f * norm_inflow + 0.1148f; break;
        case  7: norm_outflow = 0.8821f * norm_inflow + 0.0755f; break;
        case  8: norm_outflow = (norm_storage <= 1.0000f) ? 1.3846f * norm_storage + -0.2235f : 0.0000f * norm_storage + (1.3846f * 1.0000f + -0.2235f - 0.0000f * 1.0000f); break;
        case  9: norm_outflow = 2.0308f * norm_inflow + 0.0275f; break;
        case 10: norm_outflow = 2.3471f * norm_inflow + 0.0527f; break;
        case 11: norm_outflow = 0.4542f * norm_inflow + 0.1139f; break;
        case 12: norm_outflow = (norm_storage <= 1.0000f) ? 1.0231f * norm_storage + 0.0495f : 0.0000f * norm_storage + (1.0231f * 1.0000f + 0.0495f - 0.0000f * 1.0000f); break;
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
        case  1: norm_outflow = (norm_storage <= 1.0000f) ? 1.2790f * norm_storage + -0.2137f : 0.0000f * norm_storage + (1.2790f * 1.0000f + -0.2137f - 0.0000f * 1.0000f); break;
        case  2: norm_outflow = (norm_storage <= 1.0000f) ? 1.0752f * norm_storage + -0.1993f : 0.0000f * norm_storage + (1.0752f * 1.0000f + -0.1993f - 0.0000f * 1.0000f); break;
        case  3: norm_outflow = (norm_storage <= 1.0000f) ? 1.6770f * norm_storage + -0.4517f : 0.0000f * norm_storage + (1.6770f * 1.0000f + -0.4517f - 0.0000f * 1.0000f); break;
        case  4: norm_outflow = (norm_storage <= 1.0000f) ? 2.8854f * norm_storage + -0.9796f : 0.0000f * norm_storage + (2.8854f * 1.0000f + -0.9796f - 0.0000f * 1.0000f); break;
        case  5: norm_outflow = (norm_storage <= 1.0000f) ? 2.4147f * norm_storage + -0.8231f : 0.0000f * norm_storage + (2.4147f * 1.0000f + -0.8231f - 0.0000f * 1.0000f); break;
        case  6: norm_outflow = (norm_storage <= 1.0000f) ? 3.0003f * norm_storage + -1.0607f : 0.0000f * norm_storage + (3.0003f * 1.0000f + -1.0607f - 0.0000f * 1.0000f); break;
        case  7: norm_outflow = (norm_storage <= 1.0000f) ? 1.8510f * norm_storage + -0.6359f : 0.0000f * norm_storage + (1.8510f * 1.0000f + -0.6359f - 0.0000f * 1.0000f); break;
        case  8: norm_outflow = (norm_storage <= 1.0000f) ? 1.9330f * norm_storage + -0.6834f : 0.0000f * norm_storage + (1.9330f * 1.0000f + -0.6834f - 0.0000f * 1.0000f); break;
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
        case  1: norm_outflow = (norm_storage <= 1.0000f) ? 0.5579f * norm_storage + -0.1508f : 0.0000f * norm_storage + (0.5579f * 1.0000f + -0.1508f - 0.0000f * 1.0000f); break;
        case  2: norm_outflow = (norm_storage <= 1.0000f) ? 0.7797f * norm_storage + -0.2749f : 0.0000f * norm_storage + (0.7797f * 1.0000f + -0.2749f - 0.0000f * 1.0000f); break;
        case  3: norm_outflow = (norm_storage <= 1.0000f) ? 0.7003f * norm_storage + -0.3174f : 0.0000f * norm_storage + (0.7003f * 1.0000f + -0.3174f - 0.0000f * 1.0000f); break;
        case  4: norm_outflow = (norm_storage <= 1.0000f) ? 1.8943f * norm_storage + -1.0712f : 0.0000f * norm_storage + (1.8943f * 1.0000f + -1.0712f - 0.0000f * 1.0000f); break;
        case  5: norm_outflow = (norm_storage <= 1.0000f) ? 1.6047f * norm_storage + -0.9090f : 0.0000f * norm_storage + (1.6047f * 1.0000f + -0.9090f - 0.0000f * 1.0000f); break;
        case  6: norm_outflow = (norm_storage <= 1.0000f) ? 2.2926f * norm_storage + -1.3622f : 0.0000f * norm_storage + (2.2926f * 1.0000f + -1.3622f - 0.0000f * 1.0000f); break;
        case  7: norm_outflow = (norm_storage <= 1.0000f) ? 4.2246f * norm_storage + -2.5749f : 0.0000f * norm_storage + (4.2246f * 1.0000f + -2.5749f - 0.0000f * 1.0000f); break;
        case  8: norm_outflow = (norm_storage <= 1.0000f) ? 3.4105f * norm_storage + -2.0648f : 0.0000f * norm_storage + (3.4105f * 1.0000f + -2.0648f - 0.0000f * 1.0000f); break;
        case  9: norm_outflow = (norm_storage <= 1.0000f) ? 2.0380f * norm_storage + -1.2144f : 0.0000f * norm_storage + (2.0380f * 1.0000f + -1.2144f - 0.0000f * 1.0000f); break;
        case 10: norm_outflow = (norm_storage <= 0.6149f) ? 0.0106f * norm_storage + 0.0118f : 4.4709f * norm_storage + (0.0106f * 0.6149f + 0.0118f - 4.4709f * 0.6149f); break;
        case 11: norm_outflow = (norm_storage <= 1.0000f) ? -0.4615f * norm_storage + 0.3939f : 0.0000f * norm_storage + (-0.4615f * 1.0000f + 0.3939f - 0.0000f * 1.0000f); break;
        case 12: norm_outflow = (norm_storage <= 1.0000f) ? 0.9364f * norm_storage + -0.2927f : 0.0000f * norm_storage + (0.9364f * 1.0000f + -0.2927f - 0.0000f * 1.0000f); break;
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
        case  1: norm_outflow = (norm_storage <= 1.0000f) ? 0.8487f * norm_storage + -0.2824f : 0.0000f * norm_storage + (0.8487f * 1.0000f + -0.2824f - 0.0000f * 1.0000f); break;
        case  2: norm_outflow = 1.2503f * norm_inflow + 0.0578f; break;
        case  3: norm_outflow = (norm_storage <= 0.6208f) ? 0.0471f * norm_storage + 0.0000f : 1.7610f * norm_storage + (0.0471f * 0.6208f + 0.0000f - 1.7610f * 0.6208f); break;
        case  4: norm_outflow = (norm_storage <= 0.7081f) ? 0.0169f * norm_storage + 0.0000f : 5.7679f * norm_storage + (0.0169f * 0.7081f + 0.0000f - 5.7679f * 0.7081f); break;
        case  5: norm_outflow = (norm_storage <= 0.7140f) ? 0.0120f * norm_storage + 0.0000f : 6.8230f * norm_storage + (0.0120f * 0.7140f + 0.0000f - 6.8230f * 0.7140f); break;
        case  6: norm_outflow = (norm_storage <= 1.0000f) ? 5.2310f * norm_storage + -3.7118f : 0.0000f * norm_storage + (5.2310f * 1.0000f + -3.7118f - 0.0000f * 1.0000f); break;
        case  7: norm_outflow = (norm_storage <= 1.0000f) ? 2.7277f * norm_storage + -1.9163f : 0.0000f * norm_storage + (2.7277f * 1.0000f + -1.9163f - 0.0000f * 1.0000f); break;
        case  8: norm_outflow = (norm_storage <= 1.0000f) ? 1.4246f * norm_storage + -0.9877f : 0.0000f * norm_storage + (1.4246f * 1.0000f + -0.9877f - 0.0000f * 1.0000f); break;
        case  9: norm_outflow = (norm_storage <= 0.7081f) ? 0.0046f * norm_storage + 0.0050f : 2.0287f * norm_storage + (0.0046f * 0.7081f + 0.0050f - 2.0287f * 0.7081f); break;
        case 10: norm_outflow = (norm_storage <= 0.7160f) ? 0.0102f * norm_storage + 0.0051f : 6.1591f * norm_storage + (0.0102f * 0.7160f + 0.0051f - 6.1591f * 0.7160f); break;
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
        case  1: norm_outflow = (norm_storage <= 1.0000f) ? 1.2214f * norm_storage + -0.4548f : 0.0000f * norm_storage + (1.2214f * 1.0000f + -0.4548f - 0.0000f * 1.0000f); break;
        case  2: norm_outflow = (norm_storage <= 1.0000f) ? 1.2978f * norm_storage + -0.5587f : 0.0000f * norm_storage + (1.2978f * 1.0000f + -0.5587f - 0.0000f * 1.0000f); break;
        case  3: norm_outflow = 1.2799f * norm_inflow + 0.0718f; break;
        case  4: norm_outflow = (norm_storage <= 0.6663f) ? 0.0114f * norm_storage + 0.0231f : 4.3635f * norm_storage + (0.0114f * 0.6663f + 0.0231f - 4.3635f * 0.6663f); break;
        case  5: norm_outflow = (norm_storage <= 1.0000f) ? 3.6884f * norm_storage + -2.4217f : 0.0000f * norm_storage + (3.6884f * 1.0000f + -2.4217f - 0.0000f * 1.0000f); break;
        case  6: norm_outflow = (norm_storage <= 1.0000f) ? 3.2582f * norm_storage + -2.1409f : 0.0000f * norm_storage + (3.2582f * 1.0000f + -2.1409f - 0.0000f * 1.0000f); break;
        case  7: norm_outflow = (norm_storage <= 1.0000f) ? 3.1116f * norm_storage + -2.0441f : 0.0000f * norm_storage + (3.1116f * 1.0000f + -2.0441f - 0.0000f * 1.0000f); break;
        case  8: norm_outflow = (norm_storage <= 0.6685f) ? 0.0133f * norm_storage + 0.0015f : 5.5732f * norm_storage + (0.0133f * 0.6685f + 0.0015f - 5.5732f * 0.6685f); break;
        case  9: norm_outflow = (norm_storage <= 1.0000f) ? 2.3426f * norm_storage + -1.5302f : 0.0000f * norm_storage + (2.3426f * 1.0000f + -1.5302f - 0.0000f * 1.0000f); break;
        case 10: norm_outflow = (norm_storage <= 0.6687f) ? 0.0218f * norm_storage + 0.0001f : 6.3998f * norm_storage + (0.0218f * 0.6687f + 0.0001f - 6.3998f * 0.6687f); break;
        case 11: norm_outflow = 1.3679f * norm_inflow + 0.1188f; break;
        case 12: norm_outflow = (norm_storage <= 1.0000f) ? 1.1810f * norm_storage + -0.4245f : 0.0000f * norm_storage + (1.1810f * 1.0000f + -0.4245f - 0.0000f * 1.0000f); break;
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
        case  1: norm_outflow = (norm_storage <= 1.0000f) ? 1.4397f * norm_storage + -0.4588f : 0.0000f * norm_storage + (1.4397f * 1.0000f + -0.4588f - 0.0000f * 1.0000f); break;
        case  2: norm_outflow = (norm_storage <= 1.0000f) ? 1.3722f * norm_storage + -0.5258f : 0.0000f * norm_storage + (1.3722f * 1.0000f + -0.5258f - 0.0000f * 1.0000f); break;
        case  3: norm_outflow = (norm_storage <= 0.6000f) ? 0.1000f * norm_storage + 0.0349f : 4.8990f * norm_storage + (0.1000f * 0.6000f + 0.0349f - 4.8990f * 0.6000f); break;
        case  4: norm_outflow = (norm_storage <= 0.6000f) ? 0.0400f * norm_storage + 0.0000f : 5.2906f * norm_storage + (0.0400f * 0.6000f + 0.0000f - 5.2906f * 0.6000f); break;
        case  5: norm_outflow = (norm_storage <= 0.6072f) ? 0.0000f * norm_storage + 0.0695f : 3.9058f * norm_storage + (0.0000f * 0.6072f + 0.0695f - 3.9058f * 0.6072f); break;
        case  6: norm_outflow = (norm_storage <= 1.0000f) ? 4.2265f * norm_storage + -2.5274f : 0.0000f * norm_storage + (4.2265f * 1.0000f + -2.5274f - 0.0000f * 1.0000f); break;
        case  7: norm_outflow = (norm_storage <= 1.0000f) ? 3.4116f * norm_storage + -2.0225f : 0.0000f * norm_storage + (3.4116f * 1.0000f + -2.0225f - 0.0000f * 1.0000f); break;
        case  8: norm_outflow = (norm_storage <= 0.6084f) ? 0.0000f * norm_storage + 0.0201f : 5.9690f * norm_storage + (0.0000f * 0.6084f + 0.0201f - 5.9690f * 0.6084f); break;
        case  9: norm_outflow = (norm_storage <= 1.0000f) ? 2.0098f * norm_storage + -1.1738f : 0.0000f * norm_storage + (2.0098f * 1.0000f + -1.1738f - 0.0000f * 1.0000f); break;
        case 10: norm_outflow = (norm_storage <= 1.0000f) ? 4.3914f * norm_storage + -2.6253f : 0.0000f * norm_storage + (4.3914f * 1.0000f + -2.6253f - 0.0000f * 1.0000f); break;
        case 11: norm_outflow = 4.4435f * norm_inflow + 0.1524f; break;
        case 12: norm_outflow = (norm_storage <= 1.0000f) ? 1.7115f * norm_storage + -0.5336f : 0.0000f * norm_storage + (1.7115f * 1.0000f + -0.5336f - 0.0000f * 1.0000f); break;
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
        case  1: norm_outflow = (norm_storage <= 1.0000f) ? 0.0515f * norm_storage + 0.0013f : 0.0000f * norm_storage + (0.0515f * 1.0000f + 0.0013f - 0.0000f * 1.0000f); break;
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
        case 12: norm_outflow = (norm_storage <= 1.0000f) ? 0.0750f * norm_storage + -0.0181f : 0.0000f * norm_storage + (0.0750f * 1.0000f + -0.0181f - 0.0000f * 1.0000f); break;
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
        case  1: norm_outflow = (norm_storage <= 1.0000f) ? 0.7057f * norm_storage + 0.0324f : 0.0000f * norm_storage + (0.7057f * 1.0000f + 0.0324f - 0.0000f * 1.0000f); break;
        case  2: norm_outflow = (norm_storage <= 1.0000f) ? 0.6014f * norm_storage + 0.0584f : 0.0000f * norm_storage + (0.6014f * 1.0000f + 0.0584f - 0.0000f * 1.0000f); break;
        case  3: norm_outflow = (norm_storage <= 1.0000f) ? 0.8152f * norm_storage + -0.0368f : 0.0000f * norm_storage + (0.8152f * 1.0000f + -0.0368f - 0.0000f * 1.0000f); break;
        case  4: norm_outflow = (norm_storage <= 1.0000f) ? 1.1803f * norm_storage + -0.2244f : 0.0000f * norm_storage + (1.1803f * 1.0000f + -0.2244f - 0.0000f * 1.0000f); break;
        case  5: norm_outflow = (norm_storage <= 1.0000f) ? 1.0586f * norm_storage + -0.2089f : 0.0000f * norm_storage + (1.0586f * 1.0000f + -0.2089f - 0.0000f * 1.0000f); break;
        case  6: norm_outflow = (norm_storage <= 1.0000f) ? 3.0295f * norm_storage + -0.8003f : 0.0000f * norm_storage + (3.0295f * 1.0000f + -0.8003f - 0.0000f * 1.0000f); break;
        case  7: norm_outflow = (norm_storage <= 1.0000f) ? 3.0318f * norm_storage + -0.8186f : 0.0000f * norm_storage + (3.0318f * 1.0000f + -0.8186f - 0.0000f * 1.0000f); break;
        case  8: norm_outflow = 1.1995f * norm_inflow + 0.0152f; break;
        case  9: norm_outflow = 0.5547f * norm_inflow + 0.0303f; break;
        case 10: norm_outflow = 0.8931f * norm_inflow + 0.0797f; break;
        case 11: norm_outflow = (norm_storage <= 1.0000f) ? 0.7422f * norm_storage + 0.0093f : 0.0000f * norm_storage + (0.7422f * 1.0000f + 0.0093f - 0.0000f * 1.0000f); break;
        case 12: norm_outflow = (norm_storage <= 1.0000f) ? 0.5608f * norm_storage + 0.0279f : 0.0000f * norm_storage + (0.5608f * 1.0000f + 0.0279f - 0.0000f * 1.0000f); break;
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
        case  1: norm_outflow = (norm_storage <= 1.0000f) ? 1.1577f * norm_storage + -0.1799f : 0.0000f * norm_storage + (1.1577f * 1.0000f + -0.1799f - 0.0000f * 1.0000f); break;
        case  2: norm_outflow = (norm_storage <= 1.0000f) ? 1.5106f * norm_storage + -0.3729f : 0.0000f * norm_storage + (1.5106f * 1.0000f + -0.3729f - 0.0000f * 1.0000f); break;
        case  3: norm_outflow = (norm_storage <= 1.0000f) ? 1.7389f * norm_storage + -0.6221f : 0.0000f * norm_storage + (1.7389f * 1.0000f + -0.6221f - 0.0000f * 1.0000f); break;
        case  4: norm_outflow = (norm_storage <= 1.0000f) ? 3.2546f * norm_storage + -1.4633f : 0.0000f * norm_storage + (3.2546f * 1.0000f + -1.4633f - 0.0000f * 1.0000f); break;
        case  5: norm_outflow = (norm_storage <= 1.0000f) ? 3.4012f * norm_storage + -1.5816f : 0.0000f * norm_storage + (3.4012f * 1.0000f + -1.5816f - 0.0000f * 1.0000f); break;
        case  6: norm_outflow = (norm_storage <= 1.0000f) ? 4.2550f * norm_storage + -2.0435f : 0.0000f * norm_storage + (4.2550f * 1.0000f + -2.0435f - 0.0000f * 1.0000f); break;
        case  7: norm_outflow = (norm_storage <= 1.0000f) ? 2.0614f * norm_storage + -0.9746f : 0.0000f * norm_storage + (2.0614f * 1.0000f + -0.9746f - 0.0000f * 1.0000f); break;
        case  8: norm_outflow = (norm_storage <= 1.0000f) ? 3.7294f * norm_storage + -1.8148f : 0.0000f * norm_storage + (3.7294f * 1.0000f + -1.8148f - 0.0000f * 1.0000f); break;
        case  9: norm_outflow = (norm_storage <= 1.0000f) ? 1.6166f * norm_storage + -0.7677f : 0.0000f * norm_storage + (1.6166f * 1.0000f + -0.7677f - 0.0000f * 1.0000f); break;
        case 10: norm_outflow = (norm_storage <= 1.0000f) ? 2.9423f * norm_storage + -1.4002f : 0.0000f * norm_storage + (2.9423f * 1.0000f + -1.4002f - 0.0000f * 1.0000f); break;
        case 11: norm_outflow = 1.2947f * norm_inflow + 0.2278f; break;
        case 12: norm_outflow = (norm_storage <= 1.0000f) ? 1.1043f * norm_storage + -0.1279f : 0.0000f * norm_storage + (1.1043f * 1.0000f + -0.1279f - 0.0000f * 1.0000f); break;
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
        case  1: norm_outflow = (norm_storage <= 1.0000f) ? 0.6364f * norm_storage + 0.0426f : 0.0000f * norm_storage + (0.6364f * 1.0000f + 0.0426f - 0.0000f * 1.0000f); break;
        case  2: norm_outflow = (norm_storage <= 1.0000f) ? 1.0512f * norm_storage + -0.0218f : 0.0000f * norm_storage + (1.0512f * 1.0000f + -0.0218f - 0.0000f * 1.0000f); break;
        case  3: norm_outflow = (norm_storage <= 1.0000f) ? 0.9127f * norm_storage + -0.1047f : 0.0000f * norm_storage + (0.9127f * 1.0000f + -0.1047f - 0.0000f * 1.0000f); break;
        case  4: norm_outflow = (norm_storage <= 1.0000f) ? 0.7790f * norm_storage + -0.1565f : 0.0000f * norm_storage + (0.7790f * 1.0000f + -0.1565f - 0.0000f * 1.0000f); break;
        case  5: norm_outflow = (norm_storage <= 1.0000f) ? 0.9849f * norm_storage + -0.2758f : 0.0000f * norm_storage + (0.9849f * 1.0000f + -0.2758f - 0.0000f * 1.0000f); break;
        case  6: norm_outflow = (norm_storage <= 1.0000f) ? 0.9848f * norm_storage + -0.2653f : 0.0000f * norm_storage + (0.9848f * 1.0000f + -0.2653f - 0.0000f * 1.0000f); break;
        case  7: norm_outflow = (norm_storage <= 1.0000f) ? 1.2216f * norm_storage + -0.4001f : 0.0000f * norm_storage + (1.2216f * 1.0000f + -0.4001f - 0.0000f * 1.0000f); break;
        case  8: norm_outflow = (norm_storage <= 1.0000f) ? 2.2835f * norm_storage + -0.8250f : 0.0000f * norm_storage + (2.2835f * 1.0000f + -0.8250f - 0.0000f * 1.0000f); break;
        case  9: norm_outflow = (norm_storage <= 1.0000f) ? 1.0546f * norm_storage + -0.3611f : 0.0000f * norm_storage + (1.0546f * 1.0000f + -0.3611f - 0.0000f * 1.0000f); break;
        case 10: norm_outflow = 0.5690f * norm_inflow + 0.1356f; break;
        case 11: norm_outflow = 0.0000f * norm_inflow + 0.2453f; break;
        case 12: norm_outflow = (norm_storage <= 1.0000f) ? 1.1224f * norm_storage + -0.0462f : 0.0000f * norm_storage + (1.1224f * 1.0000f + -0.0462f - 0.0000f * 1.0000f); break;
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
        case  1: norm_outflow = (norm_storage <= 1.0000f) ? 2.2708f * norm_storage + -1.1906f : 0.0000f * norm_storage + (2.2708f * 1.0000f + -1.1906f - 0.0000f * 1.0000f); break;
        case  2: norm_outflow = (norm_storage <= 1.0000f) ? 3.3122f * norm_storage + -1.7663f : 0.0000f * norm_storage + (3.3122f * 1.0000f + -1.7663f - 0.0000f * 1.0000f); break;
        case  3: norm_outflow = (norm_storage <= 1.0000f) ? 2.5336f * norm_storage + -1.3105f : 0.0000f * norm_storage + (2.5336f * 1.0000f + -1.3105f - 0.0000f * 1.0000f); break;
        case  4: norm_outflow = (norm_storage <= 1.0000f) ? 2.6275f * norm_storage + -1.3762f : 0.0000f * norm_storage + (2.6275f * 1.0000f + -1.3762f - 0.0000f * 1.0000f); break;
        case  5: norm_outflow = (norm_storage <= 1.0000f) ? 2.6030f * norm_storage + -1.3763f : 0.0000f * norm_storage + (2.6030f * 1.0000f + -1.3763f - 0.0000f * 1.0000f); break;
        case  6: norm_outflow = (norm_storage <= 1.0000f) ? 2.0960f * norm_storage + -1.1117f : 0.0000f * norm_storage + (2.0960f * 1.0000f + -1.1117f - 0.0000f * 1.0000f); break;
        case  7: norm_outflow = (norm_storage <= 1.0000f) ? 1.6040f * norm_storage + -0.8400f : 0.0000f * norm_storage + (1.6040f * 1.0000f + -0.8400f - 0.0000f * 1.0000f); break;
        case  8: norm_outflow = (norm_storage <= 1.0000f) ? 1.1471f * norm_storage + -0.5967f : 0.0000f * norm_storage + (1.1471f * 1.0000f + -0.5967f - 0.0000f * 1.0000f); break;
        case  9: norm_outflow = (norm_storage <= 1.0000f) ? 1.4815f * norm_storage + -0.7651f : 0.0000f * norm_storage + (1.4815f * 1.0000f + -0.7651f - 0.0000f * 1.0000f); break;
        case 10: norm_outflow = 1.1413f * norm_inflow + 0.0102f; break;
        case 11: norm_outflow = 1.2296f * norm_inflow + 0.0107f; break;
        case 12: norm_outflow = (norm_storage <= 1.0000f) ? 1.7557f * norm_storage + -0.9081f : 0.0000f * norm_storage + (1.7557f * 1.0000f + -0.9081f - 0.0000f * 1.0000f); break;
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
        case  1: norm_outflow = (norm_storage <= 1.0000f) ? 0.6169f * norm_storage + 0.0810f : 0.0000f * norm_storage + (0.6169f * 1.0000f + 0.0810f - 0.0000f * 1.0000f); break;
        case  2: norm_outflow = (norm_storage <= 1.0000f) ? 0.9458f * norm_storage + 0.0238f : 0.0000f * norm_storage + (0.9458f * 1.0000f + 0.0238f - 0.0000f * 1.0000f); break;
        case  3: norm_outflow = (norm_storage <= 1.0000f) ? 0.7235f * norm_storage + 0.0760f : 0.0000f * norm_storage + (0.7235f * 1.0000f + 0.0760f - 0.0000f * 1.0000f); break;
        case  4: norm_outflow = (norm_storage <= 1.0000f) ? 0.5922f * norm_storage + 0.1114f : 0.0000f * norm_storage + (0.5922f * 1.0000f + 0.1114f - 0.0000f * 1.0000f); break;
        case  5: norm_outflow = (norm_storage <= 1.0000f) ? 0.5631f * norm_storage + 0.0868f : 0.0000f * norm_storage + (0.5631f * 1.0000f + 0.0868f - 0.0000f * 1.0000f); break;
        case  6: norm_outflow = (norm_storage <= 1.0000f) ? 0.7096f * norm_storage + 0.0300f : 0.0000f * norm_storage + (0.7096f * 1.0000f + 0.0300f - 0.0000f * 1.0000f); break;
        case  7: norm_outflow = (norm_storage <= 1.0000f) ? 1.1540f * norm_storage + -0.1002f : 0.0000f * norm_storage + (1.1540f * 1.0000f + -0.1002f - 0.0000f * 1.0000f); break;
        case  8: norm_outflow = (norm_storage <= 1.0000f) ? 2.1094f * norm_storage + -0.3222f : 0.0000f * norm_storage + (2.1094f * 1.0000f + -0.3222f - 0.0000f * 1.0000f); break;
        case  9: norm_outflow = (norm_storage <= 1.0000f) ? 1.5198f * norm_storage + -0.2268f : 0.0000f * norm_storage + (1.5198f * 1.0000f + -0.2268f - 0.0000f * 1.0000f); break;
        case 10: norm_outflow = (norm_storage <= 1.0000f) ? 1.7113f * norm_storage + -0.2220f : 0.0000f * norm_storage + (1.7113f * 1.0000f + -0.2220f - 0.0000f * 1.0000f); break;
        case 11: norm_outflow = (norm_storage <= 1.0000f) ? 0.5910f * norm_storage + 0.0033f : 0.0000f * norm_storage + (0.5910f * 1.0000f + 0.0033f - 0.0000f * 1.0000f); break;
        case 12: norm_outflow = (norm_storage <= 1.0000f) ? 0.9409f * norm_storage + -0.0326f : 0.0000f * norm_storage + (0.9409f * 1.0000f + -0.0326f - 0.0000f * 1.0000f); break;
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
        case  1: norm_outflow = (norm_storage <= 1.0000f) ? 0.8280f * norm_storage + -0.3224f : 0.0000f * norm_storage + (0.8280f * 1.0000f + -0.3224f - 0.0000f * 1.0000f); break;
        case  2: norm_outflow = (norm_storage <= 1.0000f) ? 1.2217f * norm_storage + -0.5043f : 0.0000f * norm_storage + (1.2217f * 1.0000f + -0.5043f - 0.0000f * 1.0000f); break;
        case  3: norm_outflow = (norm_storage <= 1.0000f) ? 1.3582f * norm_storage + -0.5692f : 0.0000f * norm_storage + (1.3582f * 1.0000f + -0.5692f - 0.0000f * 1.0000f); break;
        case  4: norm_outflow = (norm_storage <= 1.0000f) ? 1.3543f * norm_storage + -0.6371f : 0.0000f * norm_storage + (1.3543f * 1.0000f + -0.6371f - 0.0000f * 1.0000f); break;
        case  5: norm_outflow = (norm_storage <= 1.0000f) ? 2.1462f * norm_storage + -1.1029f : 0.0000f * norm_storage + (2.1462f * 1.0000f + -1.1029f - 0.0000f * 1.0000f); break;
        case  6: norm_outflow = (norm_storage <= 1.0000f) ? 2.8243f * norm_storage + -1.5266f : 0.0000f * norm_storage + (2.8243f * 1.0000f + -1.5266f - 0.0000f * 1.0000f); break;
        case  7: norm_outflow = (norm_storage <= 1.0000f) ? 4.7603f * norm_storage + -2.6649f : 0.0000f * norm_storage + (4.7603f * 1.0000f + -2.6649f - 0.0000f * 1.0000f); break;
        case  8: norm_outflow = 1.7906f * norm_inflow + 0.0107f; break;
        case  9: norm_outflow = (norm_storage <= 1.0000f) ? 3.3972f * norm_storage + -1.8666f : 0.0000f * norm_storage + (3.3972f * 1.0000f + -1.8666f - 0.0000f * 1.0000f); break;
        case 10: norm_outflow = 2.2024f * norm_inflow + 0.0221f; break;
        case 11: norm_outflow = 1.5307f * norm_inflow + 0.0518f; break;
        case 12: norm_outflow = (norm_storage <= 1.0000f) ? 2.2829f * norm_storage + -1.0897f : 0.0000f * norm_storage + (2.2829f * 1.0000f + -1.0897f - 0.0000f * 1.0000f); break;
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
        case  1: norm_outflow = (norm_storage <= 1.0000f) ? 1.1202f * norm_storage + -0.1606f : 0.0000f * norm_storage + (1.1202f * 1.0000f + -0.1606f - 0.0000f * 1.0000f); break;
        case  2: norm_outflow = (norm_storage <= 1.0000f) ? 2.1528f * norm_storage + -0.4775f : 0.0000f * norm_storage + (2.1528f * 1.0000f + -0.4775f - 0.0000f * 1.0000f); break;
        case  3: norm_outflow = (norm_storage <= 1.0000f) ? 4.5983f * norm_storage + -1.2659f : 0.0000f * norm_storage + (4.5983f * 1.0000f + -1.2659f - 0.0000f * 1.0000f); break;
        case  4: norm_outflow = (norm_storage <= 1.0000f) ? 2.2526f * norm_storage + -0.6089f : 0.0000f * norm_storage + (2.2526f * 1.0000f + -0.6089f - 0.0000f * 1.0000f); break;
        case  5: norm_outflow = (norm_storage <= 1.0000f) ? 1.1840f * norm_storage + -0.3731f : 0.0000f * norm_storage + (1.1840f * 1.0000f + -0.3731f - 0.0000f * 1.0000f); break;
        case  6: norm_outflow = (norm_storage <= 1.0000f) ? 0.6439f * norm_storage + -0.1793f : 0.0000f * norm_storage + (0.6439f * 1.0000f + -0.1793f - 0.0000f * 1.0000f); break;
        case  7: norm_outflow = (norm_storage <= 1.0000f) ? 0.7957f * norm_storage + -0.2410f : 0.0000f * norm_storage + (0.7957f * 1.0000f + -0.2410f - 0.0000f * 1.0000f); break;
        case  8: norm_outflow = (norm_storage <= 1.0000f) ? 1.0078f * norm_storage + -0.3459f : 0.0000f * norm_storage + (1.0078f * 1.0000f + -0.3459f - 0.0000f * 1.0000f); break;
        case  9: norm_outflow = (norm_storage <= 1.0000f) ? 0.6069f * norm_storage + -0.2063f : 0.0000f * norm_storage + (0.6069f * 1.0000f + -0.2063f - 0.0000f * 1.0000f); break;
        case 10: norm_outflow = (norm_storage <= 1.0000f) ? 0.6130f * norm_storage + -0.2149f : 0.0000f * norm_storage + (0.6130f * 1.0000f + -0.2149f - 0.0000f * 1.0000f); break;
        case 11: norm_outflow = (norm_storage <= 1.0000f) ? 0.5795f * norm_storage + -0.1751f : 0.0000f * norm_storage + (0.5795f * 1.0000f + -0.1751f - 0.0000f * 1.0000f); break;
        case 12: norm_outflow = (norm_storage <= 1.0000f) ? 0.9048f * norm_storage + -0.1522f : 0.0000f * norm_storage + (0.9048f * 1.0000f + -0.1522f - 0.0000f * 1.0000f); break;
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
        case  1: norm_outflow = (norm_storage <= 1.0000f) ? 0.9187f * norm_storage + -0.2636f : 0.0000f * norm_storage + (0.9187f * 1.0000f + -0.2636f - 0.0000f * 1.0000f); break;
        case  2: norm_outflow = (norm_storage <= 1.0000f) ? 1.5881f * norm_storage + -0.5132f : 0.0000f * norm_storage + (1.5881f * 1.0000f + -0.5132f - 0.0000f * 1.0000f); break;
        case  3: norm_outflow = (norm_storage <= 1.0000f) ? 1.8096f * norm_storage + -0.5964f : 0.0000f * norm_storage + (1.8096f * 1.0000f + -0.5964f - 0.0000f * 1.0000f); break;
        case  4: norm_outflow = (norm_storage <= 1.0000f) ? 2.1703f * norm_storage + -0.8040f : 0.0000f * norm_storage + (2.1703f * 1.0000f + -0.8040f - 0.0000f * 1.0000f); break;
        case  5: norm_outflow = (norm_storage <= 1.0000f) ? 2.1798f * norm_storage + -0.8508f : 0.0000f * norm_storage + (2.1798f * 1.0000f + -0.8508f - 0.0000f * 1.0000f); break;
        case  6: norm_outflow = (norm_storage <= 1.0000f) ? 3.6719f * norm_storage + -1.5447f : 0.0000f * norm_storage + (3.6719f * 1.0000f + -1.5447f - 0.0000f * 1.0000f); break;
        case  7: norm_outflow = (norm_storage <= 1.0000f) ? 3.2304f * norm_storage + -1.3586f : 0.0000f * norm_storage + (3.2304f * 1.0000f + -1.3586f - 0.0000f * 1.0000f); break;
        case  8: norm_outflow = (norm_storage <= 1.0000f) ? 2.1790f * norm_storage + -0.9054f : 0.0000f * norm_storage + (2.1790f * 1.0000f + -0.9054f - 0.0000f * 1.0000f); break;
        case  9: norm_outflow = (norm_storage <= 1.0000f) ? 1.8890f * norm_storage + -0.7643f : 0.0000f * norm_storage + (1.8890f * 1.0000f + -0.7643f - 0.0000f * 1.0000f); break;
        case 10: norm_outflow = (norm_storage <= 1.0000f) ? 2.1704f * norm_storage + -0.8437f : 0.0000f * norm_storage + (2.1704f * 1.0000f + -0.8437f - 0.0000f * 1.0000f); break;
        case 11: norm_outflow = (norm_storage <= 1.0000f) ? 2.7257f * norm_storage + -1.0188f : 0.0000f * norm_storage + (2.7257f * 1.0000f + -1.0188f - 0.0000f * 1.0000f); break;
        case 12: norm_outflow = (norm_storage <= 1.0000f) ? 3.1673f * norm_storage + -1.1544f : 0.0000f * norm_storage + (3.1673f * 1.0000f + -1.1544f - 0.0000f * 1.0000f); break;
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
        case  1: norm_outflow = (norm_storage <= 1.0000f) ? 1.5392f * norm_storage + -0.0346f : 0.0000f * norm_storage + (1.5392f * 1.0000f + -0.0346f - 0.0000f * 1.0000f); break;
        case  2: norm_outflow = (norm_storage <= 1.0000f) ? 1.8173f * norm_storage + -0.0586f : 0.0000f * norm_storage + (1.8173f * 1.0000f + -0.0586f - 0.0000f * 1.0000f); break;
        case  3: norm_outflow = (norm_storage <= 1.0000f) ? 1.3396f * norm_storage + -0.0013f : 0.0000f * norm_storage + (1.3396f * 1.0000f + -0.0013f - 0.0000f * 1.0000f); break;
        case  4: norm_outflow = (norm_storage <= 1.0000f) ? 1.0824f * norm_storage + -0.2346f : 0.0000f * norm_storage + (1.0824f * 1.0000f + -0.2346f - 0.0000f * 1.0000f); break;
        case  5: norm_outflow = (norm_storage <= 1.0000f) ? 2.4645f * norm_storage + -0.8169f : 0.0000f * norm_storage + (2.4645f * 1.0000f + -0.8169f - 0.0000f * 1.0000f); break;
        case  6: norm_outflow = (norm_storage <= 1.0000f) ? 2.9256f * norm_storage + -1.0349f : 0.0000f * norm_storage + (2.9256f * 1.0000f + -1.0349f - 0.0000f * 1.0000f); break;
        case  7: norm_outflow = 1.2386f * norm_inflow + 0.0284f; break;
        case  8: norm_outflow = (norm_storage <= 1.0000f) ? 1.6436f * norm_storage + -0.5662f : 0.0000f * norm_storage + (1.6436f * 1.0000f + -0.5662f - 0.0000f * 1.0000f); break;
        case  9: norm_outflow = (norm_storage <= 1.0000f) ? 1.4165f * norm_storage + -0.4835f : 0.0000f * norm_storage + (1.4165f * 1.0000f + -0.4835f - 0.0000f * 1.0000f); break;
        case 10: norm_outflow = 1.6137f * norm_inflow + 0.0313f; break;
        case 11: norm_outflow = 1.0511f * norm_inflow + 0.0945f; break;
        case 12: norm_outflow = (norm_storage <= 1.0000f) ? 3.3171f * norm_storage + -0.2824f : 0.0000f * norm_storage + (3.3171f * 1.0000f + -0.2824f - 0.0000f * 1.0000f); break;
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
        case  1: norm_outflow = (norm_storage <= 1.0000f) ? 1.0947f * norm_storage + 0.1276f : 0.0000f * norm_storage + (1.0947f * 1.0000f + 0.1276f - 0.0000f * 1.0000f); break;
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
        case  1: norm_outflow = (norm_storage <= 1.0000f) ? 2.4008f * norm_storage + -0.4590f : 0.0000f * norm_storage + (2.4008f * 1.0000f + -0.4590f - 0.0000f * 1.0000f); break;
        case  2: norm_outflow = (norm_storage <= 1.0000f) ? 1.2661f * norm_storage + -0.1828f : 0.0000f * norm_storage + (1.2661f * 1.0000f + -0.1828f - 0.0000f * 1.0000f); break;
        case  3: norm_outflow = (norm_storage <= 1.0000f) ? 0.9438f * norm_storage + -0.1018f : 0.0000f * norm_storage + (0.9438f * 1.0000f + -0.1018f - 0.0000f * 1.0000f); break;
        case  4: norm_outflow = (norm_storage <= 1.0000f) ? 1.2945f * norm_storage + -0.3320f : 0.0000f * norm_storage + (1.2945f * 1.0000f + -0.3320f - 0.0000f * 1.0000f); break;
        case  5: norm_outflow = (norm_storage <= 1.0000f) ? 2.1512f * norm_storage + -0.6670f : 0.0000f * norm_storage + (2.1512f * 1.0000f + -0.6670f - 0.0000f * 1.0000f); break;
        case  6: norm_outflow = (norm_storage <= 1.0000f) ? 2.6033f * norm_storage + -0.8442f : 0.0000f * norm_storage + (2.6033f * 1.0000f + -0.8442f - 0.0000f * 1.0000f); break;
        case  7: norm_outflow = 1.8370f * norm_inflow + 0.0182f; break;
        case  8: norm_outflow = 2.1962f * norm_inflow + 0.0086f; break;
        case  9: norm_outflow = (norm_storage <= 1.0000f) ? 1.0006f * norm_storage + -0.3042f : 0.0000f * norm_storage + (1.0006f * 1.0000f + -0.3042f - 0.0000f * 1.0000f); break;
        case 10: norm_outflow = 2.0818f * norm_inflow + 0.0178f; break;
        case 11: norm_outflow = 1.2269f * norm_inflow + 0.0508f; break;
        case 12: norm_outflow = (norm_storage <= 1.0000f) ? 3.6260f * norm_storage + -0.7521f : 0.0000f * norm_storage + (3.6260f * 1.0000f + -0.7521f - 0.0000f * 1.0000f); break;
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
        case  4: norm_outflow = (norm_storage <= 0.6000f) ? 0.1000f * norm_storage + 0.0000f : 9.7809f * norm_storage + (0.1000f * 0.6000f + 0.0000f - 9.7809f * 0.6000f); break;
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
        case  2: norm_outflow = (norm_storage <= 1.0000f) ? 2.2983f * norm_storage + -0.5551f : 0.0000f * norm_storage + (2.2983f * 1.0000f + -0.5551f - 0.0000f * 1.0000f); break;
        case  3: norm_outflow = (norm_storage <= 1.0000f) ? 1.2865f * norm_storage + -0.2450f : 0.0000f * norm_storage + (1.2865f * 1.0000f + -0.2450f - 0.0000f * 1.0000f); break;
        case  4: norm_outflow = 1.1315f * norm_inflow + 0.0391f; break;
        case  5: norm_outflow = (norm_storage <= 1.0000f) ? 3.6051f * norm_storage + -1.4303f : 0.0000f * norm_storage + (3.6051f * 1.0000f + -1.4303f - 0.0000f * 1.0000f); break;
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
        case  3: norm_outflow = (norm_storage <= 1.0000f) ? 1.6031f * norm_storage + -0.3858f : 0.0000f * norm_storage + (1.6031f * 1.0000f + -0.3858f - 0.0000f * 1.0000f); break;
        case  4: norm_outflow = (norm_storage <= 1.0000f) ? 1.5863f * norm_storage + -0.5846f : 0.0000f * norm_storage + (1.5863f * 1.0000f + -0.5846f - 0.0000f * 1.0000f); break;
        case  5: norm_outflow = (norm_storage <= 1.0000f) ? 3.2537f * norm_storage + -1.4640f : 0.0000f * norm_storage + (3.2537f * 1.0000f + -1.4640f - 0.0000f * 1.0000f); break;
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
        case  1: norm_outflow = (norm_storage <= 1.0000f) ? 1.6862f * norm_storage + -0.3282f : 0.0000f * norm_storage + (1.6862f * 1.0000f + -0.3282f - 0.0000f * 1.0000f); break;
        case  2: norm_outflow = (norm_storage <= 1.0000f) ? 1.1876f * norm_storage + -0.1176f : 0.0000f * norm_storage + (1.1876f * 1.0000f + -0.1176f - 0.0000f * 1.0000f); break;
        case  3: norm_outflow = (norm_storage <= 1.0000f) ? 1.2474f * norm_storage + -0.1335f : 0.0000f * norm_storage + (1.2474f * 1.0000f + -0.1335f - 0.0000f * 1.0000f); break;
        case  4: norm_outflow = (norm_storage <= 1.0000f) ? 1.2554f * norm_storage + -0.2491f : 0.0000f * norm_storage + (1.2554f * 1.0000f + -0.2491f - 0.0000f * 1.0000f); break;
        case  5: norm_outflow = (norm_storage <= 1.0000f) ? 1.9073f * norm_storage + -0.5844f : 0.0000f * norm_storage + (1.9073f * 1.0000f + -0.5844f - 0.0000f * 1.0000f); break;
        case  6: norm_outflow = (norm_storage <= 1.0000f) ? 3.6166f * norm_storage + -1.3494f : 0.0000f * norm_storage + (3.6166f * 1.0000f + -1.3494f - 0.0000f * 1.0000f); break;
        case  7: norm_outflow = (norm_storage <= 1.0000f) ? 5.0034f * norm_storage + -1.9436f : 0.0000f * norm_storage + (5.0034f * 1.0000f + -1.9436f - 0.0000f * 1.0000f); break;
        case  8: norm_outflow = (norm_storage <= 1.0000f) ? 8.2230f * norm_storage + -3.2479f : 0.0000f * norm_storage + (8.2230f * 1.0000f + -3.2479f - 0.0000f * 1.0000f); break;
        case  9: norm_outflow = (norm_storage <= 1.0000f) ? 2.3714f * norm_storage + -0.8836f : 0.0000f * norm_storage + (2.3714f * 1.0000f + -0.8836f - 0.0000f * 1.0000f); break;
        case 10: norm_outflow = (norm_storage <= 1.0000f) ? 3.3468f * norm_storage + -1.1476f : 0.0000f * norm_storage + (3.3468f * 1.0000f + -1.1476f - 0.0000f * 1.0000f); break;
        case 11: norm_outflow = (norm_storage <= 1.0000f) ? 2.4341f * norm_storage + -0.6929f : 0.0000f * norm_storage + (2.4341f * 1.0000f + -0.6929f - 0.0000f * 1.0000f); break;
        case 12: norm_outflow = (norm_storage <= 1.0000f) ? 3.2187f * norm_storage + -0.8664f : 0.0000f * norm_storage + (3.2187f * 1.0000f + -0.8664f - 0.0000f * 1.0000f); break;
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
        case  1: norm_outflow = (norm_storage <= 0.6000f) ? 0.0231f * norm_storage + 0.0000f : 0.6051f * norm_storage + (0.0231f * 0.6000f + 0.0000f - 0.6051f * 0.6000f); break;
        case  2: norm_outflow = 0.2291f * norm_inflow + 0.0293f; break;
        case  3: norm_outflow = (norm_storage <= 1.0000f) ? 0.2469f * norm_storage + -0.1144f : 0.0000f * norm_storage + (0.2469f * 1.0000f + -0.1144f - 0.0000f * 1.0000f); break;
        case  4: norm_outflow = (norm_storage <= 1.0000f) ? 0.3356f * norm_storage + -0.1680f : 0.0000f * norm_storage + (0.3356f * 1.0000f + -0.1680f - 0.0000f * 1.0000f); break;
        case  5: norm_outflow = (norm_storage <= 0.7552f) ? 0.0689f * norm_storage + 0.0000f : 2.7474f * norm_storage + (0.0689f * 0.7552f + 0.0000f - 2.7474f * 0.7552f); break;
        case  6: norm_outflow = (norm_storage <= 1.0000f) ? 0.2931f * norm_storage + -0.1436f : 0.0000f * norm_storage + (0.2931f * 1.0000f + -0.1436f - 0.0000f * 1.0000f); break;
        case  7: norm_outflow = (norm_storage <= 1.0000f) ? 0.2288f * norm_storage + -0.1066f : 0.0000f * norm_storage + (0.2288f * 1.0000f + -0.1066f - 0.0000f * 1.0000f); break;
        case  8: norm_outflow = (norm_storage <= 1.0000f) ? 0.1803f * norm_storage + -0.0800f : 0.0000f * norm_storage + (0.1803f * 1.0000f + -0.0800f - 0.0000f * 1.0000f); break;
        case  9: norm_outflow = (norm_storage <= 1.0000f) ? 0.1376f * norm_storage + -0.0586f : 0.0000f * norm_storage + (0.1376f * 1.0000f + -0.0586f - 0.0000f * 1.0000f); break;
        case 10: norm_outflow = (norm_storage <= 1.0000f) ? 0.1293f * norm_storage + -0.0539f : 0.0000f * norm_storage + (0.1293f * 1.0000f + -0.0539f - 0.0000f * 1.0000f); break;
        case 11: norm_outflow = (norm_storage <= 0.6235f) ? 0.0129f * norm_storage + 0.0000f : 1.0970f * norm_storage + (0.0129f * 0.6235f + 0.0000f - 1.0970f * 0.6235f); break;
        case 12: norm_outflow = (norm_storage <= 1.0000f) ? 0.2016f * norm_storage + -0.0833f : 0.0000f * norm_storage + (0.2016f * 1.0000f + -0.0833f - 0.0000f * 1.0000f); break;
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
        case  1: norm_outflow = (norm_storage <= 1.0000f) ? 1.4688f * norm_storage + -0.2837f : 0.0000f * norm_storage + (1.4688f * 1.0000f + -0.2837f - 0.0000f * 1.0000f); break;
        case  2: norm_outflow = (norm_storage <= 1.0000f) ? 1.0265f * norm_storage + -0.1409f : 0.0000f * norm_storage + (1.0265f * 1.0000f + -0.1409f - 0.0000f * 1.0000f); break;
        case  3: norm_outflow = (norm_storage <= 1.0000f) ? 1.2030f * norm_storage + -0.1955f : 0.0000f * norm_storage + (1.2030f * 1.0000f + -0.1955f - 0.0000f * 1.0000f); break;
        case  4: norm_outflow = (norm_storage <= 1.0000f) ? 1.1495f * norm_storage + -0.2270f : 0.0000f * norm_storage + (1.1495f * 1.0000f + -0.2270f - 0.0000f * 1.0000f); break;
        case  5: norm_outflow = (norm_storage <= 1.0000f) ? 1.4915f * norm_storage + -0.3452f : 0.0000f * norm_storage + (1.4915f * 1.0000f + -0.3452f - 0.0000f * 1.0000f); break;
        case  6: norm_outflow = (norm_storage <= 1.0000f) ? 2.5491f * norm_storage + -0.7019f : 0.0000f * norm_storage + (2.5491f * 1.0000f + -0.7019f - 0.0000f * 1.0000f); break;
        case  7: norm_outflow = (norm_storage <= 1.0000f) ? 2.4693f * norm_storage + -0.6935f : 0.0000f * norm_storage + (2.4693f * 1.0000f + -0.6935f - 0.0000f * 1.0000f); break;
        case  8: norm_outflow = (norm_storage <= 1.0000f) ? 3.0349f * norm_storage + -0.8675f : 0.0000f * norm_storage + (3.0349f * 1.0000f + -0.8675f - 0.0000f * 1.0000f); break;
        case  9: norm_outflow = (norm_storage <= 1.0000f) ? 1.4177f * norm_storage + -0.3812f : 0.0000f * norm_storage + (1.4177f * 1.0000f + -0.3812f - 0.0000f * 1.0000f); break;
        case 10: norm_outflow = (norm_storage <= 1.0000f) ? 1.8846f * norm_storage + -0.4976f : 0.0000f * norm_storage + (1.8846f * 1.0000f + -0.4976f - 0.0000f * 1.0000f); break;
        case 11: norm_outflow = (norm_storage <= 1.0000f) ? 2.0879f * norm_storage + -0.5205f : 0.0000f * norm_storage + (2.0879f * 1.0000f + -0.5205f - 0.0000f * 1.0000f); break;
        case 12: norm_outflow = (norm_storage <= 1.0000f) ? 1.8935f * norm_storage + -0.4185f : 0.0000f * norm_storage + (1.8935f * 1.0000f + -0.4185f - 0.0000f * 1.0000f); break;
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
        case  2: norm_outflow = (norm_storage <= 1.0000f) ? 3.1063f * norm_storage + -1.8716f : 0.0000f * norm_storage + (3.1063f * 1.0000f + -1.8716f - 0.0000f * 1.0000f); break;
        case  3: norm_outflow = (norm_storage <= 1.0000f) ? 3.5365f * norm_storage + -2.1378f : 0.0000f * norm_storage + (3.5365f * 1.0000f + -2.1378f - 0.0000f * 1.0000f); break;
        case  4: norm_outflow = (norm_storage <= 1.0000f) ? 5.3535f * norm_storage + -3.3653f : 0.0000f * norm_storage + (5.3535f * 1.0000f + -3.3653f - 0.0000f * 1.0000f); break;
        case  5: norm_outflow = (norm_storage <= 1.0000f) ? 5.0601f * norm_storage + -3.2337f : 0.0000f * norm_storage + (5.0601f * 1.0000f + -3.2337f - 0.0000f * 1.0000f); break;
        case  6: norm_outflow = (norm_storage <= 1.0000f) ? 4.5272f * norm_storage + -2.9036f : 0.0000f * norm_storage + (4.5272f * 1.0000f + -2.9036f - 0.0000f * 1.0000f); break;
        case  7: norm_outflow = (norm_storage <= 0.6530f) ? 0.0005f * norm_storage + 0.0132f : 9.7705f * norm_storage + (0.0005f * 0.6530f + 0.0132f - 9.7705f * 0.6530f); break;
        case  8: norm_outflow = (norm_storage <= 0.6541f) ? 0.0213f * norm_storage + 0.0000f : 9.2363f * norm_storage + (0.0213f * 0.6541f + 0.0000f - 9.2363f * 0.6541f); break;
        case  9: norm_outflow = (norm_storage <= 1.0000f) ? 2.4635f * norm_storage + -1.5481f : 0.0000f * norm_storage + (2.4635f * 1.0000f + -1.5481f - 0.0000f * 1.0000f); break;
        case 10: norm_outflow = (norm_storage <= 0.6466f) ? 0.0216f * norm_storage + 0.0000f : 7.6485f * norm_storage + (0.0216f * 0.6466f + 0.0000f - 7.6485f * 0.6466f); break;
        case 11: norm_outflow = 1.8972f * norm_inflow + 0.0234f; break;
        case 12: norm_outflow = (norm_storage <= 0.6431f) ? 0.0094f * norm_storage + 0.0172f : 11.4683f * norm_storage + (0.0094f * 0.6431f + 0.0172f - 11.4683f * 0.6431f); break;
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
        case  4: norm_outflow = (norm_storage <= 1.0000f) ? 1.3173f * norm_storage + -0.3276f : 0.0000f * norm_storage + (1.3173f * 1.0000f + -0.3276f - 0.0000f * 1.0000f); break;
        case  5: norm_outflow = (norm_storage <= 1.0000f) ? 1.8222f * norm_storage + -0.5597f : 0.0000f * norm_storage + (1.8222f * 1.0000f + -0.5597f - 0.0000f * 1.0000f); break;
        case  6: norm_outflow = (norm_storage <= 1.0000f) ? 1.7147f * norm_storage + -0.5524f : 0.0000f * norm_storage + (1.7147f * 1.0000f + -0.5524f - 0.0000f * 1.0000f); break;
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
        case  1: norm_outflow = (norm_storage <= 1.0000f) ? 2.7928f * norm_storage + -0.0844f : 0.0000f * norm_storage + (2.7928f * 1.0000f + -0.0844f - 0.0000f * 1.0000f); break;
        case  2: norm_outflow = (norm_storage <= 1.0000f) ? 1.1819f * norm_storage + 0.0993f : 0.0000f * norm_storage + (1.1819f * 1.0000f + 0.0993f - 0.0000f * 1.0000f); break;
        case  3: norm_outflow = (norm_storage <= 1.0000f) ? 1.3219f * norm_storage + 0.1076f : 0.0000f * norm_storage + (1.3219f * 1.0000f + 0.1076f - 0.0000f * 1.0000f); break;
        case  4: norm_outflow = (norm_storage <= 1.0000f) ? 1.4650f * norm_storage + -0.0814f : 0.0000f * norm_storage + (1.4650f * 1.0000f + -0.0814f - 0.0000f * 1.0000f); break;
        case  5: norm_outflow = (norm_storage <= 1.0000f) ? 1.9722f * norm_storage + -0.3186f : 0.0000f * norm_storage + (1.9722f * 1.0000f + -0.3186f - 0.0000f * 1.0000f); break;
        case  6: norm_outflow = (norm_storage <= 1.0000f) ? 2.2286f * norm_storage + -0.4434f : 0.0000f * norm_storage + (2.2286f * 1.0000f + -0.4434f - 0.0000f * 1.0000f); break;
        case  7: norm_outflow = (norm_storage <= 1.0000f) ? 3.1621f * norm_storage + -0.6844f : 0.0000f * norm_storage + (3.1621f * 1.0000f + -0.6844f - 0.0000f * 1.0000f); break;
        case  8: norm_outflow = 4.2312f * norm_inflow + 0.0164f; break;
        case  9: norm_outflow = (norm_storage <= 1.0000f) ? 2.9518f * norm_storage + -0.6284f : 0.0000f * norm_storage + (2.9518f * 1.0000f + -0.6284f - 0.0000f * 1.0000f); break;
        case 10: norm_outflow = (norm_storage <= 1.0000f) ? 1.2862f * norm_storage + -0.1961f : 0.0000f * norm_storage + (1.2862f * 1.0000f + -0.1961f - 0.0000f * 1.0000f); break;
        case 11: norm_outflow = 2.1724f * norm_inflow + 0.0867f; break;
        case 12: norm_outflow = (norm_storage <= 1.0000f) ? 2.4299f * norm_storage + -0.0985f : 0.0000f * norm_storage + (2.4299f * 1.0000f + -0.0985f - 0.0000f * 1.0000f); break;
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
        case  1: norm_outflow = (norm_storage <= 1.0000f) ? 0.7057f * norm_storage + 0.0324f : 0.0000f * norm_storage + (0.7057f * 1.0000f + 0.0324f - 0.0000f * 1.0000f); break;
        case  2: norm_outflow = (norm_storage <= 1.0000f) ? 0.6014f * norm_storage + 0.0584f : 0.0000f * norm_storage + (0.6014f * 1.0000f + 0.0584f - 0.0000f * 1.0000f); break;
        case  3: norm_outflow = (norm_storage <= 1.0000f) ? 0.8152f * norm_storage + -0.0368f : 0.0000f * norm_storage + (0.8152f * 1.0000f + -0.0368f - 0.0000f * 1.0000f); break;
        case  4: norm_outflow = (norm_storage <= 1.0000f) ? 1.1803f * norm_storage + -0.2244f : 0.0000f * norm_storage + (1.1803f * 1.0000f + -0.2244f - 0.0000f * 1.0000f); break;
        case  5: norm_outflow = (norm_storage <= 1.0000f) ? 1.0586f * norm_storage + -0.2089f : 0.0000f * norm_storage + (1.0586f * 1.0000f + -0.2089f - 0.0000f * 1.0000f); break;
        case  6: norm_outflow = (norm_storage <= 1.0000f) ? 3.0295f * norm_storage + -0.8003f : 0.0000f * norm_storage + (3.0295f * 1.0000f + -0.8003f - 0.0000f * 1.0000f); break;
        case  7: norm_outflow = (norm_storage <= 1.0000f) ? 3.0318f * norm_storage + -0.8186f : 0.0000f * norm_storage + (3.0318f * 1.0000f + -0.8186f - 0.0000f * 1.0000f); break;
        case  8: norm_outflow = 1.1995f * norm_inflow + 0.0152f; break;
        case  9: norm_outflow = 0.5547f * norm_inflow + 0.0303f; break;
        case 10: norm_outflow = 0.8931f * norm_inflow + 0.0797f; break;
        case 11: norm_outflow = (norm_storage <= 1.0000f) ? 0.7422f * norm_storage + 0.0093f : 0.0000f * norm_storage + (0.7422f * 1.0000f + 0.0093f - 0.0000f * 1.0000f); break;
        case 12: norm_outflow = (norm_storage <= 1.0000f) ? 0.5608f * norm_storage + 0.0279f : 0.0000f * norm_storage + (0.5608f * 1.0000f + 0.0279f - 0.0000f * 1.0000f); break;
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
        case  1: norm_outflow = (norm_storage <= 1.0000f) ? 1.0659f * norm_storage + -0.1564f : 0.0000f * norm_storage + (1.0659f * 1.0000f + -0.1564f - 0.0000f * 1.0000f); break;
        case  2: norm_outflow = 0.0000f * norm_inflow + 0.2448f; break;
        case  3: norm_outflow = (norm_storage <= 1.0000f) ? 0.8531f * norm_storage + -0.1236f : 0.0000f * norm_storage + (0.8531f * 1.0000f + -0.1236f - 0.0000f * 1.0000f); break;
        case  4: norm_outflow = (norm_storage <= 1.0000f) ? 2.0061f * norm_storage + -0.7058f : 0.0000f * norm_storage + (2.0061f * 1.0000f + -0.7058f - 0.0000f * 1.0000f); break;
        case  5: norm_outflow = (norm_storage <= 1.0000f) ? 1.1648f * norm_storage + -0.3831f : 0.0000f * norm_storage + (1.1648f * 1.0000f + -0.3831f - 0.0000f * 1.0000f); break;
        case  6: norm_outflow = (norm_storage <= 1.0000f) ? 2.0873f * norm_storage + -0.8332f : 0.0000f * norm_storage + (2.0873f * 1.0000f + -0.8332f - 0.0000f * 1.0000f); break;
        case  7: norm_outflow = (norm_storage <= 1.0000f) ? 4.7270f * norm_storage + -2.0168f : 0.0000f * norm_storage + (4.7270f * 1.0000f + -2.0168f - 0.0000f * 1.0000f); break;
        case  8: norm_outflow = (norm_storage <= 1.0000f) ? 2.7559f * norm_storage + -1.1674f : 0.0000f * norm_storage + (2.7559f * 1.0000f + -1.1674f - 0.0000f * 1.0000f); break;
        case  9: norm_outflow = (norm_storage <= 1.0000f) ? 2.8850f * norm_storage + -1.2047f : 0.0000f * norm_storage + (2.8850f * 1.0000f + -1.2047f - 0.0000f * 1.0000f); break;
        case 10: norm_outflow = 2.4842f * norm_inflow + 0.0621f; break;
        case 11: norm_outflow = 0.5577f * norm_inflow + 0.1531f; break;
        case 12: norm_outflow = (norm_storage <= 1.0000f) ? 0.6523f * norm_storage + -0.0136f : 0.0000f * norm_storage + (0.6523f * 1.0000f + -0.0136f - 0.0000f * 1.0000f); break;
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
        case  4: norm_outflow = (norm_storage <= 0.6933f) ? 0.0000f * norm_storage + 0.0238f : 3.3512f * norm_storage + (0.0000f * 0.6933f + 0.0238f - 3.3512f * 0.6933f); break;
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
        case  1: norm_outflow = (norm_storage <= 1.0000f) ? 2.4529f * norm_storage + -0.9671f : 0.0000f * norm_storage + (2.4529f * 1.0000f + -0.9671f - 0.0000f * 1.0000f); break;
        case  2: norm_outflow = (norm_storage <= 1.0000f) ? 1.8221f * norm_storage + -0.6842f : 0.0000f * norm_storage + (1.8221f * 1.0000f + -0.6842f - 0.0000f * 1.0000f); break;
        case  3: norm_outflow = (norm_storage <= 1.0000f) ? 1.5095f * norm_storage + -0.5852f : 0.0000f * norm_storage + (1.5095f * 1.0000f + -0.5852f - 0.0000f * 1.0000f); break;
        case  4: norm_outflow = (norm_storage <= 1.0000f) ? 1.2490f * norm_storage + -0.5997f : 0.0000f * norm_storage + (1.2490f * 1.0000f + -0.5997f - 0.0000f * 1.0000f); break;
        case  5: norm_outflow = (norm_storage <= 0.6000f) ? 0.0895f * norm_storage + 0.0000f : 3.9632f * norm_storage + (0.0895f * 0.6000f + 0.0000f - 3.9632f * 0.6000f); break;
        case  6: norm_outflow = (norm_storage <= 1.0000f) ? 3.7113f * norm_storage + -2.1606f : 0.0000f * norm_storage + (3.7113f * 1.0000f + -2.1606f - 0.0000f * 1.0000f); break;
        case  7: norm_outflow = (norm_storage <= 0.6006f) ? 0.0305f * norm_storage + 0.0000f : 6.0240f * norm_storage + (0.0305f * 0.6006f + 0.0000f - 6.0240f * 0.6006f); break;
        case  8: norm_outflow = (norm_storage <= 0.6009f) ? 0.0220f * norm_storage + 0.0000f : 7.7858f * norm_storage + (0.0220f * 0.6009f + 0.0000f - 7.7858f * 0.6009f); break;
        case  9: norm_outflow = (norm_storage <= 0.6012f) ? 0.0000f * norm_storage + 0.0259f : 6.7819f * norm_storage + (0.0000f * 0.6012f + 0.0259f - 6.7819f * 0.6012f); break;
        case 10: norm_outflow = (norm_storage <= 0.6000f) ? 0.0953f * norm_storage + 0.0000f : 3.4339f * norm_storage + (0.0953f * 0.6000f + 0.0000f - 3.4339f * 0.6000f); break;
        case 11: norm_outflow = 0.5933f * norm_inflow + 0.0565f; break;
        case 12: norm_outflow = (norm_storage <= 1.0000f) ? 1.9715f * norm_storage + -0.7770f : 0.0000f * norm_storage + (1.9715f * 1.0000f + -0.7770f - 0.0000f * 1.0000f); break;
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
        case  1: norm_outflow = (norm_storage <= 1.0000f) ? 0.7511f * norm_storage + 0.2637f : 0.0000f * norm_storage + (0.7511f * 1.0000f + 0.2637f - 0.0000f * 1.0000f); break;
        case  2: norm_outflow = (norm_storage <= 1.0000f) ? 0.5294f * norm_storage + 0.3266f : 0.0000f * norm_storage + (0.5294f * 1.0000f + 0.3266f - 0.0000f * 1.0000f); break;
        case  3: norm_outflow = (norm_storage <= 1.0000f) ? 0.8089f * norm_storage + 0.1168f : 0.0000f * norm_storage + (0.8089f * 1.0000f + 0.1168f - 0.0000f * 1.0000f); break;
        case  4: norm_outflow = (norm_storage <= 1.0000f) ? 1.3715f * norm_storage + -0.3047f : 0.0000f * norm_storage + (1.3715f * 1.0000f + -0.3047f - 0.0000f * 1.0000f); break;
        case  5: norm_outflow = (norm_storage <= 1.0000f) ? 1.0763f * norm_storage + -0.1890f : 0.0000f * norm_storage + (1.0763f * 1.0000f + -0.1890f - 0.0000f * 1.0000f); break;
        case  6: norm_outflow = (norm_storage <= 1.0000f) ? 1.4926f * norm_storage + -0.3852f : 0.0000f * norm_storage + (1.4926f * 1.0000f + -0.3852f - 0.0000f * 1.0000f); break;
        case  7: norm_outflow = (norm_storage <= 1.0000f) ? 2.5784f * norm_storage + -0.8304f : 0.0000f * norm_storage + (2.5784f * 1.0000f + -0.8304f - 0.0000f * 1.0000f); break;
        case  8: norm_outflow = (norm_storage <= 1.0000f) ? 3.3126f * norm_storage + -1.1760f : 0.0000f * norm_storage + (3.3126f * 1.0000f + -1.1760f - 0.0000f * 1.0000f); break;
        case  9: norm_outflow = (norm_storage <= 1.0000f) ? 2.2297f * norm_storage + -0.7220f : 0.0000f * norm_storage + (2.2297f * 1.0000f + -0.7220f - 0.0000f * 1.0000f); break;
        case 10: norm_outflow = 4.4909f * norm_inflow + 0.2500f; break;
        case 11: norm_outflow = 0.1534f * norm_inflow + 0.4330f; break;
        case 12: norm_outflow = (norm_storage <= 1.0000f) ? 1.7548f * norm_storage + 0.0913f : 0.0000f * norm_storage + (1.7548f * 1.0000f + 0.0913f - 0.0000f * 1.0000f); break;
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
        case  1: norm_outflow = (norm_storage <= 1.0000f) ? 0.5605f * norm_storage + -0.0818f : 0.0000f * norm_storage + (0.5605f * 1.0000f + -0.0818f - 0.0000f * 1.0000f); break;
        case  2: norm_outflow = (norm_storage <= 0.6000f) ? 0.0887f * norm_storage + 0.1173f : 1.7178f * norm_storage + (0.0887f * 0.6000f + 0.1173f - 1.7178f * 0.6000f); break;
        case  3: norm_outflow = (norm_storage <= 0.6418f) ? 0.0000f * norm_storage + 0.1632f : 2.7125f * norm_storage + (0.0000f * 0.6418f + 0.1632f - 2.7125f * 0.6418f); break;
        case  4: norm_outflow = (norm_storage <= 0.6528f) ? 0.0000f * norm_storage + 0.1383f : 2.5805f * norm_storage + (0.0000f * 0.6528f + 0.1383f - 2.5805f * 0.6528f); break;
        case  5: norm_outflow = (norm_storage <= 0.6549f) ? 0.0068f * norm_storage + 0.1377f : 1.1741f * norm_storage + (0.0068f * 0.6549f + 0.1377f - 1.1741f * 0.6549f); break;
        case  6: norm_outflow = (norm_storage <= 0.6729f) ? 0.0650f * norm_storage + 0.0645f : 3.8318f * norm_storage + (0.0650f * 0.6729f + 0.0645f - 3.8318f * 0.6729f); break;
        case  7: norm_outflow = (norm_storage <= 1.0000f) ? 0.3803f * norm_storage + -0.1000f : 0.0000f * norm_storage + (0.3803f * 1.0000f + -0.1000f - 0.0000f * 1.0000f); break;
        case  8: norm_outflow = (norm_storage <= 1.0000f) ? 0.3672f * norm_storage + -0.0765f : 0.0000f * norm_storage + (0.3672f * 1.0000f + -0.0765f - 0.0000f * 1.0000f); break;
        case  9: norm_outflow = (norm_storage <= 1.0000f) ? 0.3761f * norm_storage + -0.0916f : 0.0000f * norm_storage + (0.3761f * 1.0000f + -0.0916f - 0.0000f * 1.0000f); break;
        case 10: norm_outflow = (norm_storage <= 1.0000f) ? 0.4778f * norm_storage + -0.1420f : 0.0000f * norm_storage + (0.4778f * 1.0000f + -0.1420f - 0.0000f * 1.0000f); break;
        case 11: norm_outflow = (norm_storage <= 1.0000f) ? 0.7125f * norm_storage + -0.2301f : 0.0000f * norm_storage + (0.7125f * 1.0000f + -0.2301f - 0.0000f * 1.0000f); break;
        case 12: norm_outflow = (norm_storage <= 1.0000f) ? 0.7130f * norm_storage + -0.1732f : 0.0000f * norm_storage + (0.7130f * 1.0000f + -0.1732f - 0.0000f * 1.0000f); break;
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
        case  1: norm_outflow = (norm_storage <= 1.0000f) ? 1.4663f * norm_storage + -0.8473f : 0.0000f * norm_storage + (1.4663f * 1.0000f + -0.8473f - 0.0000f * 1.0000f); break;
        case  2: norm_outflow = (norm_storage <= 1.0000f) ? 1.5766f * norm_storage + -0.9919f : 0.0000f * norm_storage + (1.5766f * 1.0000f + -0.9919f - 0.0000f * 1.0000f); break;
        case  3: norm_outflow = (norm_storage <= 0.7825f) ? 0.1000f * norm_storage + 0.0044f : 4.5646f * norm_storage + (0.1000f * 0.7825f + 0.0044f - 4.5646f * 0.7825f); break;
        case  4: norm_outflow = (norm_storage <= 0.7986f) ? 0.0774f * norm_storage + 0.0000f : 4.2041f * norm_storage + (0.0774f * 0.7986f + 0.0000f - 4.2041f * 0.7986f); break;
        case  5: norm_outflow = (norm_storage <= 0.8100f) ? 0.0000f * norm_storage + 0.0362f : 4.2372f * norm_storage + (0.0000f * 0.8100f + 0.0362f - 4.2372f * 0.8100f); break;
        case  6: norm_outflow = (norm_storage <= 0.8457f) ? 0.1000f * norm_storage + 0.0321f : 11.9530f * norm_storage + (0.1000f * 0.8457f + 0.0321f - 11.9530f * 0.8457f); break;
        case  7: norm_outflow = 0.3246f * norm_inflow + 0.1582f; break;
        case  8: norm_outflow = 0.0117f * norm_inflow + 0.1604f; break;
        case  9: norm_outflow = (norm_storage <= 1.0000f) ? 0.5658f * norm_storage + -0.2639f : 0.0000f * norm_storage + (0.5658f * 1.0000f + -0.2639f - 0.0000f * 1.0000f); break;
        case 10: norm_outflow = (norm_storage <= 1.0000f) ? 0.6743f * norm_storage + -0.3530f : 0.0000f * norm_storage + (0.6743f * 1.0000f + -0.3530f - 0.0000f * 1.0000f); break;
        case 11: norm_outflow = (norm_storage <= 1.0000f) ? 0.7579f * norm_storage + -0.4045f : 0.0000f * norm_storage + (0.7579f * 1.0000f + -0.4045f - 0.0000f * 1.0000f); break;
        case 12: norm_outflow = (norm_storage <= 1.0000f) ? 1.5004f * norm_storage + -0.8539f : 0.0000f * norm_storage + (1.5004f * 1.0000f + -0.8539f - 0.0000f * 1.0000f); break;
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
        case  2: norm_outflow = (norm_storage <= 0.6881f) ? 0.0000f * norm_storage + 0.1087f : 3.8629f * norm_storage + (0.0000f * 0.6881f + 0.1087f - 3.8629f * 0.6881f); break;
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
        case  2: norm_outflow = (norm_storage <= 0.6000f) ? 0.1000f * norm_storage + 0.1018f : 4.1111f * norm_storage + (0.1000f * 0.6000f + 0.1018f - 4.1111f * 0.6000f); break;
        case  3: norm_outflow = 0.9793f * norm_inflow + 0.0257f; break;
        case  4: norm_outflow = (norm_storage <= 0.7974f) ? 0.0908f * norm_storage + 0.0000f : 3.9608f * norm_storage + (0.0908f * 0.7974f + 0.0000f - 3.9608f * 0.7974f); break;
        case  5: norm_outflow = (norm_storage <= 0.8396f) ? 0.0691f * norm_storage + 0.0000f : 6.1402f * norm_storage + (0.0691f * 0.8396f + 0.0000f - 6.1402f * 0.8396f); break;
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
        case  1: norm_outflow = (norm_storage <= 1.0000f) ? 2.6197f * norm_storage + -1.0792f : 0.0000f * norm_storage + (2.6197f * 1.0000f + -1.0792f - 0.0000f * 1.0000f); break;
        case  2: norm_outflow = (norm_storage <= 1.0000f) ? 2.1014f * norm_storage + -0.8422f : 0.0000f * norm_storage + (2.1014f * 1.0000f + -0.8422f - 0.0000f * 1.0000f); break;
        case  3: norm_outflow = (norm_storage <= 1.0000f) ? 1.4401f * norm_storage + -0.5869f : 0.0000f * norm_storage + (1.4401f * 1.0000f + -0.5869f - 0.0000f * 1.0000f); break;
        case  4: norm_outflow = (norm_storage <= 1.0000f) ? 1.7129f * norm_storage + -0.8972f : 0.0000f * norm_storage + (1.7129f * 1.0000f + -0.8972f - 0.0000f * 1.0000f); break;
        case  5: norm_outflow = (norm_storage <= 1.0000f) ? 2.2188f * norm_storage + -1.2465f : 0.0000f * norm_storage + (2.2188f * 1.0000f + -1.2465f - 0.0000f * 1.0000f); break;
        case  6: norm_outflow = (norm_storage <= 0.6000f) ? 0.0346f * norm_storage + 0.0000f : 4.0254f * norm_storage + (0.0346f * 0.6000f + 0.0000f - 4.0254f * 0.6000f); break;
        case  7: norm_outflow = (norm_storage <= 0.6000f) ? 0.0261f * norm_storage + 0.0000f : 3.8199f * norm_storage + (0.0261f * 0.6000f + 0.0000f - 3.8199f * 0.6000f); break;
        case  8: norm_outflow = (norm_storage <= 0.6000f) ? 0.0183f * norm_storage + 0.0000f : 3.9856f * norm_storage + (0.0183f * 0.6000f + 0.0000f - 3.9856f * 0.6000f); break;
        case  9: norm_outflow = (norm_storage <= 0.6000f) ? 0.0212f * norm_storage + 0.0000f : 5.1904f * norm_storage + (0.0212f * 0.6000f + 0.0000f - 5.1904f * 0.6000f); break;
        case 10: norm_outflow = (norm_storage <= 0.6000f) ? 0.0013f * norm_storage + 0.0472f : 3.2377f * norm_storage + (0.0013f * 0.6000f + 0.0472f - 3.2377f * 0.6000f); break;
        case 11: norm_outflow = 0.8350f * norm_inflow + 0.0849f; break;
        case 12: norm_outflow = (norm_storage <= 1.0000f) ? 2.0181f * norm_storage + -0.8129f : 0.0000f * norm_storage + (2.0181f * 1.0000f + -0.8129f - 0.0000f * 1.0000f); break;
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
        case  1: norm_outflow = (norm_storage <= 0.6230f) ? 0.0247f * norm_storage + 0.0000f : 0.7299f * norm_storage + (0.0247f * 0.6230f + 0.0000f - 0.7299f * 0.6230f); break;
        case  2: norm_outflow = (norm_storage <= 0.6294f) ? 0.0284f * norm_storage + 0.0000f : 0.5869f * norm_storage + (0.0284f * 0.6294f + 0.0000f - 0.5869f * 0.6294f); break;
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
        case  4: norm_outflow = (norm_storage <= 0.7212f) ? 0.0153f * norm_storage + 0.0000f : 1.4238f * norm_storage + (0.0153f * 0.7212f + 0.0000f - 1.4238f * 0.7212f); break;
        case  5: norm_outflow = 0.9384f * norm_inflow + 0.0100f; break;
        case  6: norm_outflow = (norm_storage <= 0.7378f) ? 0.0083f * norm_storage + 0.0000f : 1.3835f * norm_storage + (0.0083f * 0.7378f + 0.0000f - 1.3835f * 0.7378f); break;
        case  7: norm_outflow = 0.9203f * norm_inflow + 0.0041f; break;
        case  8: norm_outflow = 0.8261f * norm_inflow + 0.0036f; break;
        case  9: norm_outflow = 0.8973f * norm_inflow + 0.0043f; break;
        case 10: norm_outflow = 1.1709f * norm_inflow + 0.0105f; break;
        case 11: norm_outflow = 0.9063f * norm_inflow + 0.0422f; break;
        case 12: norm_outflow = (norm_storage <= 1.0000f) ? 0.4296f * norm_storage + -0.0819f : 0.0000f * norm_storage + (0.4296f * 1.0000f + -0.0819f - 0.0000f * 1.0000f); break;
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
        case  1: norm_outflow = (norm_storage <= 1.0000f) ? 0.5149f * norm_storage + 0.1694f : 0.0000f * norm_storage + (0.5149f * 1.0000f + 0.1694f - 0.0000f * 1.0000f); break;
        case  2: norm_outflow = (norm_storage <= 1.0000f) ? 0.5852f * norm_storage + 0.1280f : 0.0000f * norm_storage + (0.5852f * 1.0000f + 0.1280f - 0.0000f * 1.0000f); break;
        case  3: norm_outflow = (norm_storage <= 1.0000f) ? 0.4763f * norm_storage + 0.0377f : 0.0000f * norm_storage + (0.4763f * 1.0000f + 0.0377f - 0.0000f * 1.0000f); break;
        case  4: norm_outflow = (norm_storage <= 1.0000f) ? 0.4879f * norm_storage + -0.0431f : 0.0000f * norm_storage + (0.4879f * 1.0000f + -0.0431f - 0.0000f * 1.0000f); break;
        case  5: norm_outflow = (norm_storage <= 1.0000f) ? 0.7351f * norm_storage + -0.1646f : 0.0000f * norm_storage + (0.7351f * 1.0000f + -0.1646f - 0.0000f * 1.0000f); break;
        case  6: norm_outflow = (norm_storage <= 1.0000f) ? 0.5223f * norm_storage + -0.1019f : 0.0000f * norm_storage + (0.5223f * 1.0000f + -0.1019f - 0.0000f * 1.0000f); break;
        case  7: norm_outflow = (norm_storage <= 1.0000f) ? 0.5990f * norm_storage + -0.1083f : 0.0000f * norm_storage + (0.5990f * 1.0000f + -0.1083f - 0.0000f * 1.0000f); break;
        case  8: norm_outflow = (norm_storage <= 1.0000f) ? 0.9426f * norm_storage + -0.1341f : 0.0000f * norm_storage + (0.9426f * 1.0000f + -0.1341f - 0.0000f * 1.0000f); break;
        case  9: norm_outflow = (norm_storage <= 1.0000f) ? 1.1064f * norm_storage + -0.0842f : 0.0000f * norm_storage + (1.1064f * 1.0000f + -0.0842f - 0.0000f * 1.0000f); break;
        case 10: norm_outflow = 0.0000f * norm_inflow + 0.1919f; break;
        case 11: norm_outflow = (norm_storage <= 1.0000f) ? 0.2860f * norm_storage + 0.1611f : 0.0000f * norm_storage + (0.2860f * 1.0000f + 0.1611f - 0.0000f * 1.0000f); break;
        case 12: norm_outflow = (norm_storage <= 1.0000f) ? 0.5593f * norm_storage + 0.1111f : 0.0000f * norm_storage + (0.5593f * 1.0000f + 0.1111f - 0.0000f * 1.0000f); break;
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
        case  1: norm_outflow = (norm_storage <= 1.0000f) ? 0.3310f * norm_storage + -0.0251f : 0.0000f * norm_storage + (0.3310f * 1.0000f + -0.0251f - 0.0000f * 1.0000f); break;
        case  2: norm_outflow = (norm_storage <= 1.0000f) ? 0.3068f * norm_storage + -0.0171f : 0.0000f * norm_storage + (0.3068f * 1.0000f + -0.0171f - 0.0000f * 1.0000f); break;
        case  3: norm_outflow = (norm_storage <= 1.0000f) ? 0.4903f * norm_storage + -0.0297f : 0.0000f * norm_storage + (0.4903f * 1.0000f + -0.0297f - 0.0000f * 1.0000f); break;
        case  4: norm_outflow = (norm_storage <= 1.0000f) ? 0.4578f * norm_storage + -0.0324f : 0.0000f * norm_storage + (0.4578f * 1.0000f + -0.0324f - 0.0000f * 1.0000f); break;
        case  5: norm_outflow = (norm_storage <= 1.0000f) ? 0.2643f * norm_storage + -0.0097f : 0.0000f * norm_storage + (0.2643f * 1.0000f + -0.0097f - 0.0000f * 1.0000f); break;
        case  6: norm_outflow = (norm_storage <= 1.0000f) ? 0.2777f * norm_storage + -0.0112f : 0.0000f * norm_storage + (0.2777f * 1.0000f + -0.0112f - 0.0000f * 1.0000f); break;
        case  7: norm_outflow = (norm_storage <= 1.0000f) ? 0.4698f * norm_storage + -0.0425f : 0.0000f * norm_storage + (0.4698f * 1.0000f + -0.0425f - 0.0000f * 1.0000f); break;
        case  8: norm_outflow = (norm_storage <= 1.0000f) ? 0.6618f * norm_storage + -0.0649f : 0.0000f * norm_storage + (0.6618f * 1.0000f + -0.0649f - 0.0000f * 1.0000f); break;
        case  9: norm_outflow = (norm_storage <= 1.0000f) ? 0.3503f * norm_storage + -0.0330f : 0.0000f * norm_storage + (0.3503f * 1.0000f + -0.0330f - 0.0000f * 1.0000f); break;
        case 10: norm_outflow = (norm_storage <= 1.0000f) ? 0.5713f * norm_storage + -0.0580f : 0.0000f * norm_storage + (0.5713f * 1.0000f + -0.0580f - 0.0000f * 1.0000f); break;
        case 11: norm_outflow = (norm_storage <= 1.0000f) ? 0.3659f * norm_storage + -0.0337f : 0.0000f * norm_storage + (0.3659f * 1.0000f + -0.0337f - 0.0000f * 1.0000f); break;
        case 12: norm_outflow = (norm_storage <= 1.0000f) ? 0.1770f * norm_storage + -0.0130f : 0.0000f * norm_storage + (0.1770f * 1.0000f + -0.0130f - 0.0000f * 1.0000f); break;
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
        case  1: norm_outflow = (norm_storage <= 1.0000f) ? 0.5279f * norm_storage + -0.2295f : 0.0000f * norm_storage + (0.5279f * 1.0000f + -0.2295f - 0.0000f * 1.0000f); break;
        case  2: norm_outflow = (norm_storage <= 1.0000f) ? 0.4612f * norm_storage + -0.1646f : 0.0000f * norm_storage + (0.4612f * 1.0000f + -0.1646f - 0.0000f * 1.0000f); break;
        case  3: norm_outflow = 0.9908f * norm_inflow + 0.0590f; break;
        case  4: norm_outflow = 0.8205f * norm_inflow + 0.0683f; break;
        case  5: norm_outflow = 0.6272f * norm_inflow + 0.0772f; break;
        case  6: norm_outflow = 0.9313f * norm_inflow + 0.0103f; break;
        case  7: norm_outflow = 1.1795f * norm_inflow + 0.0721f; break;
        case  8: norm_outflow = (norm_storage <= 0.8274f) ? 0.1000f * norm_storage + 0.0505f : 0.8657f * norm_storage + (0.1000f * 0.8274f + 0.0505f - 0.8657f * 0.8274f); break;
        case  9: norm_outflow = 0.7925f * norm_inflow + 0.0859f; break;
        case 10: norm_outflow = (norm_storage <= 1.0000f) ? 0.3998f * norm_storage + -0.1672f : 0.0000f * norm_storage + (0.3998f * 1.0000f + -0.1672f - 0.0000f * 1.0000f); break;
        case 11: norm_outflow = (norm_storage <= 1.0000f) ? 0.4846f * norm_storage + -0.2300f : 0.0000f * norm_storage + (0.4846f * 1.0000f + -0.2300f - 0.0000f * 1.0000f); break;
        case 12: norm_outflow = (norm_storage <= 1.0000f) ? 0.4512f * norm_storage + -0.1897f : 0.0000f * norm_storage + (0.4512f * 1.0000f + -0.1897f - 0.0000f * 1.0000f); break;
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
        case  2: norm_outflow = (norm_storage <= 0.6933f) ? 0.0398f * norm_storage + 0.0000f : 1.0381f * norm_storage + (0.0398f * 0.6933f + 0.0000f - 1.0381f * 0.6933f); break;
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
        case 21: return rule_21(inflow_m3d, storage_m3, month);
        case 104: return rule_104(inflow_m3d, storage_m3, month);
        case 487: return rule_487(inflow_m3d, storage_m3, month);
        case 488: return rule_488(inflow_m3d, storage_m3, month);
        case 493: return rule_493(inflow_m3d, storage_m3, month);
        case 5560: return rule_5560(inflow_m3d, storage_m3, month);
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

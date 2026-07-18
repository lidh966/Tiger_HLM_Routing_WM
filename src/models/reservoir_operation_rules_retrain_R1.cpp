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
        case  1: norm_outflow = (norm_storage <= 1.0000f) ? 0.0205f * norm_storage + 0.0050f : 0.0000f * norm_storage + (0.0205f * 1.0000f + 0.0050f - 0.0000f * 1.0000f); break;
        case  2: norm_outflow = (norm_storage <= 0.8007f) ? 0.0226f * norm_storage + 0.0044f : 2.1173f * norm_storage + (0.0226f * 0.8007f + 0.0044f - 2.1173f * 0.8007f); break;
        case  3: norm_outflow = (norm_storage <= 0.6982f) ? 0.0495f * norm_storage + 0.0000f : 1.3737f * norm_storage + (0.0495f * 0.6982f + 0.0000f - 1.3737f * 0.6982f); break;
        case  4: norm_outflow = (norm_storage <= 0.6642f) ? 0.0031f * norm_storage + 0.0371f : 0.8010f * norm_storage + (0.0031f * 0.6642f + 0.0371f - 0.8010f * 0.6642f); break;
        case  5: norm_outflow = (norm_storage <= 0.8026f) ? 0.0000f * norm_storage + 0.1939f : 0.8651f * norm_storage + (0.0000f * 0.8026f + 0.1939f - 0.8651f * 0.8026f); break;
        case  6: norm_outflow = (norm_storage <= 0.8061f) ? 0.0269f * norm_storage + 0.1635f : 2.6602f * norm_storage + (0.0269f * 0.8061f + 0.1635f - 2.6602f * 0.8061f); break;
        case  7: norm_outflow = 0.0000f * norm_inflow + 0.2322f; break;
        case  8: norm_outflow = (norm_storage <= 1.0000f) ? 0.1724f * norm_storage + 0.1269f : 0.0000f * norm_storage + (0.1724f * 1.0000f + 0.1269f - 0.0000f * 1.0000f); break;
        case  9: norm_outflow = 2.3600f * norm_inflow + 0.0620f; break;
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
        case  1: norm_outflow = 0.0000f * norm_inflow + 0.0102f; break;
        case  2: norm_outflow = 0.0000f * norm_inflow + 0.0098f; break;
        case  3: norm_outflow = 0.0000f * norm_inflow + 0.0095f; break;
        case  4: norm_outflow = (norm_storage <= 0.9613f) ? 0.0196f * norm_storage + 0.0028f : 9.4384f * norm_storage + (0.0196f * 0.9613f + 0.0028f - 9.4384f * 0.9613f); break;
        case  5: norm_outflow = 0.0000f * norm_inflow + 0.2375f; break;
        case  6: norm_outflow = 0.0000f * norm_inflow + 0.2516f; break;
        case  7: norm_outflow = 0.5910f * norm_inflow + 0.3684f; break;
        case  8: norm_outflow = 0.0000f * norm_inflow + 0.2808f; break;
        case  9: norm_outflow = (norm_storage <= 1.0000f) ? 0.3036f * norm_storage + -0.0961f : 0.0000f * norm_storage + (0.3036f * 1.0000f + -0.0961f - 0.0000f * 1.0000f); break;
        case 10: norm_outflow = 0.0000f * norm_inflow + 0.0421f; break;
        case 11: norm_outflow = 0.0000f * norm_inflow + 0.0108f; break;
        case 12: norm_outflow = 0.0000f * norm_inflow + 0.0102f; break;
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
        case  2: norm_outflow = 1.0704f * norm_inflow + 0.0844f; break;
        case  3: norm_outflow = (norm_storage <= 0.6450f) ? 0.1000f * norm_storage + 0.0458f : 6.3762f * norm_storage + (0.1000f * 0.6450f + 0.0458f - 6.3762f * 0.6450f); break;
        case  4: norm_outflow = (norm_storage <= 0.6000f) ? 0.1000f * norm_storage + 0.0440f : 2.7498f * norm_storage + (0.1000f * 0.6000f + 0.0440f - 2.7498f * 0.6000f); break;
        case  5: norm_outflow = 2.2742f * norm_inflow + 0.0586f; break;
        case  6: norm_outflow = 0.8481f * norm_inflow + 0.1703f; break;
        case  7: norm_outflow = 2.5883f * norm_inflow + 0.0748f; break;
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
        case  1: norm_outflow = (norm_storage <= 1.0000f) ? 0.9307f * norm_storage + -0.3602f : 0.0000f * norm_storage + (0.9307f * 1.0000f + -0.3602f - 0.0000f * 1.0000f); break;
        case  2: norm_outflow = (norm_storage <= 0.6000f) ? 0.0268f * norm_storage + 0.0000f : 4.9741f * norm_storage + (0.0268f * 0.6000f + 0.0000f - 4.9741f * 0.6000f); break;
        case  3: norm_outflow = (norm_storage <= 0.6000f) ? 0.0000f * norm_storage + 0.0223f : 2.2483f * norm_storage + (0.0000f * 0.6000f + 0.0223f - 2.2483f * 0.6000f); break;
        case  4: norm_outflow = 0.2824f * norm_inflow + 0.0606f; break;
        case  5: norm_outflow = (norm_storage <= 0.6382f) ? 0.0000f * norm_storage + 0.0732f : 0.6032f * norm_storage + (0.0000f * 0.6382f + 0.0732f - 0.6032f * 0.6382f); break;
        case  6: norm_outflow = (norm_storage <= 0.9836f) ? 0.0000f * norm_storage + 0.1135f : 53.4739f * norm_storage + (0.0000f * 0.9836f + 0.1135f - 53.4739f * 0.9836f); break;
        case  7: norm_outflow = (norm_storage <= 1.0000f) ? -0.4641f * norm_storage + 0.5094f : 0.0000f * norm_storage + (-0.4641f * 1.0000f + 0.5094f - 0.0000f * 1.0000f); break;
        case  8: norm_outflow = (norm_storage <= 1.0000f) ? -0.2996f * norm_storage + 0.2677f : 0.0000f * norm_storage + (-0.2996f * 1.0000f + 0.2677f - 0.0000f * 1.0000f); break;
        case  9: norm_outflow = 0.0000f * norm_inflow + 0.0788f; break;
        case 10: norm_outflow = (norm_storage <= 1.0000f) ? 0.4338f * norm_storage + -0.0406f : 0.0000f * norm_storage + (0.4338f * 1.0000f + -0.0406f - 0.0000f * 1.0000f); break;
        case 11: norm_outflow = (norm_storage <= 1.0000f) ? 0.8593f * norm_storage + -0.1894f : 0.0000f * norm_storage + (0.8593f * 1.0000f + -0.1894f - 0.0000f * 1.0000f); break;
        case 12: norm_outflow = (norm_storage <= 1.0000f) ? 0.9516f * norm_storage + -0.3001f : 0.0000f * norm_storage + (0.9516f * 1.0000f + -0.3001f - 0.0000f * 1.0000f); break;
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
        case  1: norm_outflow = (norm_storage <= 1.0000f) ? 0.1633f * norm_storage + 0.0331f : 0.0000f * norm_storage + (0.1633f * 1.0000f + 0.0331f - 0.0000f * 1.0000f); break;
        case  2: norm_outflow = (norm_storage <= 0.7812f) ? 0.0992f * norm_storage + 0.0679f : 0.9496f * norm_storage + (0.0992f * 0.7812f + 0.0679f - 0.9496f * 0.7812f); break;
        case  3: norm_outflow = (norm_storage <= 1.0000f) ? 0.0856f * norm_storage + 0.0423f : 0.0000f * norm_storage + (0.0856f * 1.0000f + 0.0423f - 0.0000f * 1.0000f); break;
        case  4: norm_outflow = 0.1025f * norm_inflow + 0.0910f; break;
        case  5: norm_outflow = (norm_storage <= 0.8486f) ? 0.0773f * norm_storage + 0.0694f : 1.4292f * norm_storage + (0.0773f * 0.8486f + 0.0694f - 1.4292f * 0.8486f); break;
        case  6: norm_outflow = (norm_storage <= 0.9586f) ? 0.1000f * norm_storage + 0.0617f : 22.3495f * norm_storage + (0.1000f * 0.9586f + 0.0617f - 22.3495f * 0.9586f); break;
        case  7: norm_outflow = (norm_storage <= 0.8752f) ? 0.1000f * norm_storage + 0.0514f : 2.0444f * norm_storage + (0.1000f * 0.8752f + 0.0514f - 2.0444f * 0.8752f); break;
        case  8: norm_outflow = (norm_storage <= 0.8150f) ? 0.0587f * norm_storage + 0.0761f : 1.0617f * norm_storage + (0.0587f * 0.8150f + 0.0761f - 1.0617f * 0.8150f); break;
        case  9: norm_outflow = (norm_storage <= 0.8010f) ? 0.0404f * norm_storage + 0.0672f : 1.3071f * norm_storage + (0.0404f * 0.8010f + 0.0672f - 1.3071f * 0.8010f); break;
        case 10: norm_outflow = (norm_storage <= 0.8129f) ? 0.0570f * norm_storage + 0.0445f : 1.6196f * norm_storage + (0.0570f * 0.8129f + 0.0445f - 1.6196f * 0.8129f); break;
        case 11: norm_outflow = (norm_storage <= 0.7880f) ? 0.0583f * norm_storage + 0.0501f : 1.1140f * norm_storage + (0.0583f * 0.7880f + 0.0501f - 1.1140f * 0.7880f); break;
        case 12: norm_outflow = 0.2919f * norm_inflow + 0.1151f; break;
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
        case  4: norm_outflow = (norm_storage <= 0.9083f) ? 0.0062f * norm_storage + 0.0003f : 0.9497f * norm_storage + (0.0062f * 0.9083f + 0.0003f - 0.9497f * 0.9083f); break;
        case  5: norm_outflow = (norm_storage <= 1.0000f) ? 1.4096f * norm_storage + -0.9716f : 0.0000f * norm_storage + (1.4096f * 1.0000f + -0.9716f - 0.0000f * 1.0000f); break;
        case  6: norm_outflow = (norm_storage <= 1.0000f) ? -1.8615f * norm_storage + 2.3253f : 0.0000f * norm_storage + (-1.8615f * 1.0000f + 2.3253f - 0.0000f * 1.0000f); break;
        case  7: norm_outflow = 0.0000f * norm_inflow + 0.7152f; break;
        case  8: norm_outflow = (norm_storage <= 1.0000f) ? 0.4916f * norm_storage + -0.0109f : 0.0000f * norm_storage + (0.4916f * 1.0000f + -0.0109f - 0.0000f * 1.0000f); break;
        case  9: norm_outflow = (norm_storage <= 1.0000f) ? 0.5473f * norm_storage + -0.1973f : 0.0000f * norm_storage + (0.5473f * 1.0000f + -0.1973f - 0.0000f * 1.0000f); break;
        case 10: norm_outflow = (norm_storage <= 0.7782f) ? 0.0012f * norm_storage + 0.0000f : 10.7770f * norm_storage + (0.0012f * 0.7782f + 0.0000f - 10.7770f * 0.7782f); break;
        case 11: norm_outflow = 0.0000f * norm_inflow + 0.0003f; break;
        case 12: norm_outflow = 0.0000f * norm_inflow + 0.0003f; break;
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
        case  1: norm_outflow = 0.3090f * norm_inflow + 0.0035f; break;
        case  2: norm_outflow = 0.3084f * norm_inflow + 0.0032f; break;
        case  3: norm_outflow = (norm_storage <= 0.6000f) ? 0.0212f * norm_storage + 0.0063f : 1.0005f * norm_storage + (0.0212f * 0.6000f + 0.0063f - 1.0005f * 0.6000f); break;
        case  4: norm_outflow = 0.7590f * norm_inflow + 0.0007f; break;
        case  5: norm_outflow = 0.9643f * norm_inflow + 0.0762f; break;
        case  6: norm_outflow = 0.8685f * norm_inflow + 0.1207f; break;
        case  7: norm_outflow = 0.4537f * norm_inflow + 0.0994f; break;
        case  8: norm_outflow = (norm_storage <= 1.0000f) ? 0.1111f * norm_storage + 0.0396f : 0.0000f * norm_storage + (0.1111f * 1.0000f + 0.0396f - 0.0000f * 1.0000f); break;
        case  9: norm_outflow = (norm_storage <= 1.0000f) ? 0.1017f * norm_storage + 0.0128f : 0.0000f * norm_storage + (0.1017f * 1.0000f + 0.0128f - 0.0000f * 1.0000f); break;
        case 10: norm_outflow = 0.1389f * norm_inflow + 0.0085f; break;
        case 11: norm_outflow = 0.1276f * norm_inflow + 0.0119f; break;
        case 12: norm_outflow = 0.4048f * norm_inflow + 0.0006f; break;
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
        case  2: norm_outflow = 1.5991f * norm_inflow + 0.1072f; break;
        case  3: norm_outflow = 2.0204f * norm_inflow + 0.1053f; break;
        case  4: norm_outflow = 1.7597f * norm_inflow + 0.0982f; break;
        case  5: norm_outflow = 1.0335f * norm_inflow + 0.0985f; break;
        case  6: norm_outflow = 1.4098f * norm_inflow + 0.0364f; break;
        case  7: norm_outflow = 1.3617f * norm_inflow + 0.0126f; break;
        case  8: norm_outflow = (norm_storage <= 0.7952f) ? 0.1000f * norm_storage + 0.0751f : 1.9834f * norm_storage + (0.1000f * 0.7952f + 0.0751f - 1.9834f * 0.7952f); break;
        case  9: norm_outflow = (norm_storage <= 0.7385f) ? 0.1000f * norm_storage + 0.0611f : 0.8949f * norm_storage + (0.1000f * 0.7385f + 0.0611f - 0.8949f * 0.7385f); break;
        case 10: norm_outflow = 0.7779f * norm_inflow + 0.0952f; break;
        case 11: norm_outflow = 0.7251f * norm_inflow + 0.1010f; break;
        case 12: norm_outflow = 0.7930f * norm_inflow + 0.1090f; break;
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
        case  3: norm_outflow = (norm_storage <= 1.0000f) ? 0.3384f * norm_storage + -0.1126f : 0.0000f * norm_storage + (0.3384f * 1.0000f + -0.1126f - 0.0000f * 1.0000f); break;
        case  4: norm_outflow = (norm_storage <= 1.0000f) ? 0.4295f * norm_storage + -0.1581f : 0.0000f * norm_storage + (0.4295f * 1.0000f + -0.1581f - 0.0000f * 1.0000f); break;
        case  5: norm_outflow = (norm_storage <= 1.0000f) ? 0.3995f * norm_storage + 0.0043f : 0.0000f * norm_storage + (0.3995f * 1.0000f + 0.0043f - 0.0000f * 1.0000f); break;
        case  6: norm_outflow = (norm_storage <= 1.0000f) ? 0.2020f * norm_storage + 0.2403f : 0.0000f * norm_storage + (0.2020f * 1.0000f + 0.2403f - 0.0000f * 1.0000f); break;
        case  7: norm_outflow = (norm_storage <= 1.0000f) ? 0.3419f * norm_storage + 0.2831f : 0.0000f * norm_storage + (0.3419f * 1.0000f + 0.2831f - 0.0000f * 1.0000f); break;
        case  8: norm_outflow = 1.3746f * norm_inflow + 0.1190f; break;
        case  9: norm_outflow = (norm_storage <= 1.0000f) ? 0.5933f * norm_storage + -0.0370f : 0.0000f * norm_storage + (0.5933f * 1.0000f + -0.0370f - 0.0000f * 1.0000f); break;
        case 10: norm_outflow = (norm_storage <= 0.6000f) ? 0.1000f * norm_storage + 0.0156f : 3.2485f * norm_storage + (0.1000f * 0.6000f + 0.0156f - 3.2485f * 0.6000f); break;
        case 11: norm_outflow = (norm_storage <= 0.6058f) ? 0.0793f * norm_storage + 0.0012f : 3.0137f * norm_storage + (0.0793f * 0.6058f + 0.0012f - 3.0137f * 0.6058f); break;
        case 12: norm_outflow = (norm_storage <= 0.6141f) ? 0.0714f * norm_storage + 0.0000f : 2.4666f * norm_storage + (0.0714f * 0.6141f + 0.0000f - 2.4666f * 0.6141f); break;
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
        case  1: norm_outflow = 0.3572f * norm_inflow + 0.0087f; break;
        case  2: norm_outflow = 0.5248f * norm_inflow + 0.0082f; break;
        case  3: norm_outflow = (norm_storage <= 1.0000f) ? 0.0690f * norm_storage + -0.0098f : 0.0000f * norm_storage + (0.0690f * 1.0000f + -0.0098f - 0.0000f * 1.0000f); break;
        case  4: norm_outflow = (norm_storage <= 0.7042f) ? 0.0000f * norm_storage + 0.0665f : 1.2566f * norm_storage + (0.0000f * 0.7042f + 0.0665f - 1.2566f * 0.7042f); break;
        case  5: norm_outflow = 0.8261f * norm_inflow + 0.0893f; break;
        case  6: norm_outflow = 0.2909f * norm_inflow + 0.4825f; break;
        case  7: norm_outflow = 0.8949f * norm_inflow + 0.1607f; break;
        case  8: norm_outflow = (norm_storage <= 1.0000f) ? 0.5073f * norm_storage + 0.0428f : 0.0000f * norm_storage + (0.5073f * 1.0000f + 0.0428f - 0.0000f * 1.0000f); break;
        case  9: norm_outflow = (norm_storage <= 1.0000f) ? 0.6039f * norm_storage + -0.0398f : 0.0000f * norm_storage + (0.6039f * 1.0000f + -0.0398f - 0.0000f * 1.0000f); break;
        case 10: norm_outflow = (norm_storage <= 1.0000f) ? 0.2751f * norm_storage + -0.0248f : 0.0000f * norm_storage + (0.2751f * 1.0000f + -0.0248f - 0.0000f * 1.0000f); break;
        case 11: norm_outflow = 0.7669f * norm_inflow + -0.0068f; break;
        case 12: norm_outflow = 0.7554f * norm_inflow + -0.0045f; break;
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
        case  1: norm_outflow = 0.4363f * norm_inflow + 0.0195f; break;
        case  2: norm_outflow = 0.8745f * norm_inflow + 0.0159f; break;
        case  3: norm_outflow = 1.3575f * norm_inflow + 0.0181f; break;
        case  4: norm_outflow = 1.9723f * norm_inflow + 0.0524f; break;
        case  5: norm_outflow = 0.3403f * norm_inflow + 0.2126f; break;
        case  6: norm_outflow = 0.8503f * norm_inflow + 0.2427f; break;
        case  7: norm_outflow = 1.2754f * norm_inflow + 0.1691f; break;
        case  8: norm_outflow = 0.2896f * norm_inflow + 0.1779f; break;
        case  9: norm_outflow = 0.2887f * norm_inflow + 0.1417f; break;
        case 10: norm_outflow = 0.5103f * norm_inflow + 0.0496f; break;
        case 11: norm_outflow = 0.5215f * norm_inflow + 0.0164f; break;
        case 12: norm_outflow = 0.5705f * norm_inflow + 0.0149f; break;
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
        case  1: norm_outflow = 0.0128f * norm_inflow + 0.0043f; break;
        case  2: norm_outflow = 0.0000f * norm_inflow + 0.0047f; break;
        case  3: norm_outflow = 0.0000f * norm_inflow + 0.0082f; break;
        case  4: norm_outflow = 0.3372f * norm_inflow + 0.0155f; break;
        case  5: norm_outflow = (norm_storage <= 1.0000f) ? 0.3334f * norm_storage + 0.0813f : 0.0000f * norm_storage + (0.3334f * 1.0000f + 0.0813f - 0.0000f * 1.0000f); break;
        case  6: norm_outflow = (norm_storage <= 0.9191f) ? 0.1000f * norm_storage + 0.1804f : 6.6647f * norm_storage + (0.1000f * 0.9191f + 0.1804f - 6.6647f * 0.9191f); break;
        case  7: norm_outflow = 1.3327f * norm_inflow + 0.0519f; break;
        case  8: norm_outflow = 1.9586f * norm_inflow + -0.0122f; break;
        case  9: norm_outflow = (norm_storage <= 1.0000f) ? 0.3536f * norm_storage + 0.0173f : 0.0000f * norm_storage + (0.3536f * 1.0000f + 0.0173f - 0.0000f * 1.0000f); break;
        case 10: norm_outflow = 0.4030f * norm_inflow + 0.0136f; break;
        case 11: norm_outflow = 0.3991f * norm_inflow + 0.0046f; break;
        case 12: norm_outflow = 0.2629f * norm_inflow + 0.0030f; break;
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
        case  3: norm_outflow = 1.2388f * norm_inflow + 0.0567f; break;
        case  4: norm_outflow = 1.2051f * norm_inflow + 0.0580f; break;
        case  5: norm_outflow = 0.8107f * norm_inflow + 0.0964f; break;
        case  6: norm_outflow = 1.5268f * norm_inflow + 0.0281f; break;
        case  7: norm_outflow = (norm_storage <= 0.7743f) ? 0.0687f * norm_storage + 0.0699f : 2.7966f * norm_storage + (0.0687f * 0.7743f + 0.0699f - 2.7966f * 0.7743f); break;
        case  8: norm_outflow = 0.5806f * norm_inflow + 0.0670f; break;
        case  9: norm_outflow = 0.4878f * norm_inflow + 0.0609f; break;
        case 10: norm_outflow = 0.7004f * norm_inflow + 0.0335f; break;
        case 11: norm_outflow = 0.6613f * norm_inflow + 0.0395f; break;
        case 12: norm_outflow = 0.6851f * norm_inflow + 0.0474f; break;
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
        case  1: norm_outflow = 0.0842f * norm_inflow + 0.0083f; break;
        case  2: norm_outflow = (norm_storage <= 0.6918f) ? 0.0105f * norm_storage + 0.0040f : 0.9946f * norm_storage + (0.0105f * 0.6918f + 0.0040f - 0.9946f * 0.6918f); break;
        case  3: norm_outflow = (norm_storage <= 0.6928f) ? 0.0094f * norm_storage + 0.0046f : 0.9948f * norm_storage + (0.0094f * 0.6928f + 0.0046f - 0.9948f * 0.6928f); break;
        case  4: norm_outflow = 0.0638f * norm_inflow + 0.0181f; break;
        case  5: norm_outflow = 0.3435f * norm_inflow + 0.0575f; break;
        case  6: norm_outflow = 0.7131f * norm_inflow + 0.0421f; break;
        case  7: norm_outflow = 0.4646f * norm_inflow + 0.1422f; break;
        case  8: norm_outflow = 0.0000f * norm_inflow + 0.2512f; break;
        case  9: norm_outflow = (norm_storage <= 1.0000f) ? 0.2876f * norm_storage + 0.0338f : 0.0000f * norm_storage + (0.2876f * 1.0000f + 0.0338f - 0.0000f * 1.0000f); break;
        case 10: norm_outflow = (norm_storage <= 0.6653f) ? 0.0000f * norm_storage + 0.0220f : 1.8171f * norm_storage + (0.0000f * 0.6653f + 0.0220f - 1.8171f * 0.6653f); break;
        case 11: norm_outflow = (norm_storage <= 1.0000f) ? 0.0346f * norm_storage + -0.0044f : 0.0000f * norm_storage + (0.0346f * 1.0000f + -0.0044f - 0.0000f * 1.0000f); break;
        case 12: norm_outflow = 0.0889f * norm_inflow + 0.0071f; break;
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
        case  3: norm_outflow = 0.0000f * norm_inflow + 0.0008f; break;
        case  4: norm_outflow = (norm_storage <= 1.0000f) ? 0.2142f * norm_storage + -0.1017f : 0.0000f * norm_storage + (0.2142f * 1.0000f + -0.1017f - 0.0000f * 1.0000f); break;
        case  5: norm_outflow = (norm_storage <= 1.0000f) ? -0.4756f * norm_storage + 0.6924f : 0.0000f * norm_storage + (-0.4756f * 1.0000f + 0.6924f - 0.0000f * 1.0000f); break;
        case  6: norm_outflow = 0.0000f * norm_inflow + 0.4625f; break;
        case  7: norm_outflow = 0.0000f * norm_inflow + 0.5884f; break;
        case  8: norm_outflow = (norm_storage <= 1.0000f) ? 0.1687f * norm_storage + 0.3664f : 0.0000f * norm_storage + (0.1687f * 1.0000f + 0.3664f - 0.0000f * 1.0000f); break;
        case  9: norm_outflow = (norm_storage <= 1.0000f) ? 0.4308f * norm_storage + 0.1405f : 0.0000f * norm_storage + (0.4308f * 1.0000f + 0.1405f - 0.0000f * 1.0000f); break;
        case 10: norm_outflow = 0.0000f * norm_inflow + 0.0299f; break;
        case 11: norm_outflow = 0.0000f * norm_inflow + 0.0004f; break;
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
        case  1: norm_outflow = (norm_storage <= 1.0000f) ? -0.3396f * norm_storage + 0.3459f : 0.0000f * norm_storage + (-0.3396f * 1.0000f + 0.3459f - 0.0000f * 1.0000f); break;
        case  2: norm_outflow = 0.3123f * norm_inflow + 0.0612f; break;
        case  3: norm_outflow = 0.1281f * norm_inflow + 0.0926f; break;
        case  4: norm_outflow = 0.3270f * norm_inflow + 0.1069f; break;
        case  5: norm_outflow = 0.4794f * norm_inflow + 0.1073f; break;
        case  6: norm_outflow = 0.7524f * norm_inflow + 0.1244f; break;
        case  7: norm_outflow = 0.7114f * norm_inflow + 0.1872f; break;
        case  8: norm_outflow = 0.5438f * norm_inflow + 0.1841f; break;
        case  9: norm_outflow = 0.6555f * norm_inflow + 0.0797f; break;
        case 10: norm_outflow = 0.3027f * norm_inflow + 0.0635f; break;
        case 11: norm_outflow = 0.2471f * norm_inflow + 0.0609f; break;
        case 12: norm_outflow = (norm_storage <= 1.0000f) ? -0.4919f * norm_storage + 0.4713f : 0.0000f * norm_storage + (-0.4919f * 1.0000f + 0.4713f - 0.0000f * 1.0000f); break;
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
        case  1: norm_outflow = 0.1463f * norm_inflow + 0.0584f; break;
        case  2: norm_outflow = 0.1937f * norm_inflow + 0.0592f; break;
        case  3: norm_outflow = (norm_storage <= 0.6795f) ? 0.0201f * norm_storage + 0.0677f : 0.5221f * norm_storage + (0.0201f * 0.6795f + 0.0677f - 0.5221f * 0.6795f); break;
        case  4: norm_outflow = (norm_storage <= 1.0000f) ? 0.1444f * norm_storage + 0.1041f : 0.0000f * norm_storage + (0.1444f * 1.0000f + 0.1041f - 0.0000f * 1.0000f); break;
        case  5: norm_outflow = (norm_storage <= 0.6944f) ? 0.0000f * norm_storage + 0.1443f : 0.9649f * norm_storage + (0.0000f * 0.6944f + 0.1443f - 0.9649f * 0.6944f); break;
        case  6: norm_outflow = (norm_storage <= 0.8657f) ? 0.0985f * norm_storage + 0.1831f : 4.5889f * norm_storage + (0.0985f * 0.8657f + 0.1831f - 4.5889f * 0.8657f); break;
        case  7: norm_outflow = (norm_storage <= 0.9514f) ? 0.1000f * norm_storage + 0.2565f : 27.7993f * norm_storage + (0.1000f * 0.9514f + 0.2565f - 27.7993f * 0.9514f); break;
        case  8: norm_outflow = 0.6030f * norm_inflow + 0.1971f; break;
        case  9: norm_outflow = 0.6746f * norm_inflow + 0.0806f; break;
        case 10: norm_outflow = 0.0069f * norm_inflow + 0.0244f; break;
        case 11: norm_outflow = 0.1567f * norm_inflow + 0.0554f; break;
        case 12: norm_outflow = (norm_storage <= 0.8280f) ? 0.0111f * norm_storage + 0.0553f : 0.9588f * norm_storage + (0.0111f * 0.8280f + 0.0553f - 0.9588f * 0.8280f); break;
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
        case  1: norm_outflow = 0.3210f * norm_inflow + 0.0374f; break;
        case  2: norm_outflow = 0.8399f * norm_inflow + 0.0374f; break;
        case  3: norm_outflow = (norm_storage <= 1.0000f) ? 0.1270f * norm_storage + -0.0011f : 0.0000f * norm_storage + (0.1270f * 1.0000f + -0.0011f - 0.0000f * 1.0000f); break;
        case  4: norm_outflow = 0.5614f * norm_inflow + 0.0674f; break;
        case  5: norm_outflow = 0.3014f * norm_inflow + 0.0924f; break;
        case  6: norm_outflow = (norm_storage <= 1.0000f) ? 0.3317f * norm_storage + -0.0327f : 0.0000f * norm_storage + (0.3317f * 1.0000f + -0.0327f - 0.0000f * 1.0000f); break;
        case  7: norm_outflow = 0.6144f * norm_inflow + 0.0602f; break;
        case  8: norm_outflow = 0.2685f * norm_inflow + 0.0678f; break;
        case  9: norm_outflow = 0.2275f * norm_inflow + 0.0417f; break;
        case 10: norm_outflow = (norm_storage <= 1.0000f) ? 0.0144f * norm_storage + 0.0318f : 0.0000f * norm_storage + (0.0144f * 1.0000f + 0.0318f - 0.0000f * 1.0000f); break;
        case 11: norm_outflow = 0.1937f * norm_inflow + 0.0362f; break;
        case 12: norm_outflow = 0.2527f * norm_inflow + 0.0363f; break;
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
        case  1: norm_outflow = 0.3445f * norm_inflow + 0.0573f; break;
        case  2: norm_outflow = 2.8625f * norm_inflow + 0.0527f; break;
        case  3: norm_outflow = 1.0326f * norm_inflow + 0.0776f; break;
        case  4: norm_outflow = 0.6069f * norm_inflow + 0.1261f; break;
        case  5: norm_outflow = 2.4076f * norm_inflow + 0.2130f; break;
        case  6: norm_outflow = 2.1725f * norm_inflow + 0.4255f; break;
        case  7: norm_outflow = 4.8507f * norm_inflow + 0.2058f; break;
        case  8: norm_outflow = 3.4239f * norm_inflow + 0.1441f; break;
        case  9: norm_outflow = 0.1350f * norm_inflow + 0.1558f; break;
        case 10: norm_outflow = 0.6579f * norm_inflow + 0.0974f; break;
        case 11: norm_outflow = 0.2640f * norm_inflow + 0.0938f; break;
        case 12: norm_outflow = 2.2773f * norm_inflow + 0.0618f; break;
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
        case  1: norm_outflow = 0.3317f * norm_inflow + 0.0235f; break;
        case  2: norm_outflow = (norm_storage <= 1.0000f) ? 0.0404f * norm_storage + -0.0023f : 0.0000f * norm_storage + (0.0404f * 1.0000f + -0.0023f - 0.0000f * 1.0000f); break;
        case  3: norm_outflow = (norm_storage <= 1.0000f) ? 0.0293f * norm_storage + 0.0037f : 0.0000f * norm_storage + (0.0293f * 1.0000f + 0.0037f - 0.0000f * 1.0000f); break;
        case  4: norm_outflow = 0.0000f * norm_inflow + 0.0298f; break;
        case  5: norm_outflow = 0.0411f * norm_inflow + 0.0450f; break;
        case  6: norm_outflow = (norm_storage <= 1.0000f) ? 0.2220f * norm_storage + -0.1155f : 0.0000f * norm_storage + (0.2220f * 1.0000f + -0.1155f - 0.0000f * 1.0000f); break;
        case  7: norm_outflow = 0.2631f * norm_inflow + 0.0826f; break;
        case  8: norm_outflow = (norm_storage <= 1.0000f) ? 0.1034f * norm_storage + -0.0152f : 0.0000f * norm_storage + (0.1034f * 1.0000f + -0.0152f - 0.0000f * 1.0000f); break;
        case  9: norm_outflow = 0.7625f * norm_inflow + 0.0509f; break;
        case 10: norm_outflow = 0.2601f * norm_inflow + 0.0313f; break;
        case 11: norm_outflow = 0.0915f * norm_inflow + 0.0256f; break;
        case 12: norm_outflow = 0.9423f * norm_inflow + 0.0213f; break;
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
        case  1: norm_outflow = (norm_storage <= 1.0000f) ? 0.1064f * norm_storage + -0.0354f : 0.0000f * norm_storage + (0.1064f * 1.0000f + -0.0354f - 0.0000f * 1.0000f); break;
        case  2: norm_outflow = (norm_storage <= 1.0000f) ? 0.1066f * norm_storage + -0.0353f : 0.0000f * norm_storage + (0.1066f * 1.0000f + -0.0353f - 0.0000f * 1.0000f); break;
        case  3: norm_outflow = 0.4777f * norm_inflow + 0.0054f; break;
        case  4: norm_outflow = 0.6985f * norm_inflow + 0.0050f; break;
        case  5: norm_outflow = 1.3669f * norm_inflow + -0.0494f; break;
        case  6: norm_outflow = (norm_storage <= 1.0000f) ? 1.4494f * norm_storage + -0.5127f : 0.0000f * norm_storage + (1.4494f * 1.0000f + -0.5127f - 0.0000f * 1.0000f); break;
        case  7: norm_outflow = (norm_storage <= 1.0000f) ? 1.4147f * norm_storage + -0.4985f : 0.0000f * norm_storage + (1.4147f * 1.0000f + -0.4985f - 0.0000f * 1.0000f); break;
        case  8: norm_outflow = 0.7946f * norm_inflow + -0.0207f; break;
        case  9: norm_outflow = 0.2785f * norm_inflow + 0.0057f; break;
        case 10: norm_outflow = 0.4742f * norm_inflow + -0.0112f; break;
        case 11: norm_outflow = 0.5921f * norm_inflow + -0.0141f; break;
        case 12: norm_outflow = 0.2187f * norm_inflow + 0.0024f; break;
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
        case  1: norm_outflow = 0.0135f * norm_inflow + 0.0380f; break;
        case  2: norm_outflow = 0.2195f * norm_inflow + 0.0309f; break;
        case  3: norm_outflow = 0.3564f * norm_inflow + 0.0294f; break;
        case  4: norm_outflow = 0.2729f * norm_inflow + 0.0408f; break;
        case  5: norm_outflow = (norm_storage <= 0.9853f) ? 0.0651f * norm_storage + 0.0294f : 40.9445f * norm_storage + (0.0651f * 0.9853f + 0.0294f - 40.9445f * 0.9853f); break;
        case  6: norm_outflow = (norm_storage <= 0.9858f) ? 0.0956f * norm_storage + 0.0000f : 50.7367f * norm_storage + (0.0956f * 0.9858f + 0.0000f - 50.7367f * 0.9858f); break;
        case  7: norm_outflow = (norm_storage <= 0.9849f) ? 0.0859f * norm_storage + 0.0399f : 38.6638f * norm_storage + (0.0859f * 0.9849f + 0.0399f - 38.6638f * 0.9849f); break;
        case  8: norm_outflow = 0.6794f * norm_inflow + 0.0617f; break;
        case  9: norm_outflow = 0.0431f * norm_inflow + 0.1021f; break;
        case 10: norm_outflow = 0.1898f * norm_inflow + 0.0468f; break;
        case 11: norm_outflow = 0.3085f * norm_inflow + 0.0204f; break;
        case 12: norm_outflow = 0.1028f * norm_inflow + 0.0339f; break;
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
        case  1: norm_outflow = 0.9180f * norm_inflow + 0.0141f; break;
        case  2: norm_outflow = 1.9826f * norm_inflow + 0.0079f; break;
        case  3: norm_outflow = 3.1168f * norm_inflow + 0.0213f; break;
        case  4: norm_outflow = (norm_storage <= 0.8474f) ? 0.0000f * norm_storage + 0.0614f : 39.9506f * norm_storage + (0.0000f * 0.8474f + 0.0614f - 39.9506f * 0.8474f); break;
        case  5: norm_outflow = (norm_storage <= 0.8410f) ? 0.0328f * norm_storage + 0.0609f : 22.1035f * norm_storage + (0.0328f * 0.8410f + 0.0609f - 22.1035f * 0.8410f); break;
        case  6: norm_outflow = 3.1739f * norm_inflow + -0.0038f; break;
        case  7: norm_outflow = (norm_storage <= 0.8429f) ? 0.0000f * norm_storage + 0.1388f : 7.3247f * norm_storage + (0.0000f * 0.8429f + 0.1388f - 7.3247f * 0.8429f); break;
        case  8: norm_outflow = 0.6442f * norm_inflow + 0.0466f; break;
        case  9: norm_outflow = 0.5611f * norm_inflow + 0.0080f; break;
        case 10: norm_outflow = 0.1515f * norm_inflow + 0.0252f; break;
        case 11: norm_outflow = 0.5973f * norm_inflow + 0.0108f; break;
        case 12: norm_outflow = 0.4966f * norm_inflow + 0.0191f; break;
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
        case  2: norm_outflow = (norm_storage <= 1.0000f) ? 0.0486f * norm_storage + 0.0252f : 0.0000f * norm_storage + (0.0486f * 1.0000f + 0.0252f - 0.0000f * 1.0000f); break;
        case  3: norm_outflow = 0.4134f * norm_inflow + 0.0543f; break;
        case  4: norm_outflow = 0.1624f * norm_inflow + 0.0681f; break;
        case  5: norm_outflow = (norm_storage <= 0.9501f) ? 0.0702f * norm_storage + 0.0243f : 5.3002f * norm_storage + (0.0702f * 0.9501f + 0.0243f - 5.3002f * 0.9501f); break;
        case  6: norm_outflow = (norm_storage <= 0.9438f) ? 0.1000f * norm_storage + 0.0448f : 5.4578f * norm_storage + (0.1000f * 0.9438f + 0.0448f - 5.4578f * 0.9438f); break;
        case  7: norm_outflow = 0.8420f * norm_inflow + 0.0908f; break;
        case  8: norm_outflow = (norm_storage <= 0.9006f) ? 0.0000f * norm_storage + 0.1323f : 0.9012f * norm_storage + (0.0000f * 0.9006f + 0.1323f - 0.9012f * 0.9006f); break;
        case  9: norm_outflow = 0.1360f * norm_inflow + 0.0957f; break;
        case 10: norm_outflow = 0.0028f * norm_inflow + 0.0870f; break;
        case 11: norm_outflow = 0.0000f * norm_inflow + 0.0710f; break;
        case 12: norm_outflow = 0.4134f * norm_inflow + 0.0504f; break;
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
        case  1: norm_outflow = (norm_storage <= 1.0000f) ? 0.0771f * norm_storage + -0.0060f : 0.0000f * norm_storage + (0.0771f * 1.0000f + -0.0060f - 0.0000f * 1.0000f); break;
        case  2: norm_outflow = (norm_storage <= 1.0000f) ? 0.0673f * norm_storage + -0.0033f : 0.0000f * norm_storage + (0.0673f * 1.0000f + -0.0033f - 0.0000f * 1.0000f); break;
        case  3: norm_outflow = (norm_storage <= 1.0000f) ? 0.0738f * norm_storage + -0.0065f : 0.0000f * norm_storage + (0.0738f * 1.0000f + -0.0065f - 0.0000f * 1.0000f); break;
        case  4: norm_outflow = (norm_storage <= 1.0000f) ? 0.1151f * norm_storage + -0.0356f : 0.0000f * norm_storage + (0.1151f * 1.0000f + -0.0356f - 0.0000f * 1.0000f); break;
        case  5: norm_outflow = 0.2747f * norm_inflow + 0.0440f; break;
        case  6: norm_outflow = (norm_storage <= 0.9506f) ? 0.0755f * norm_storage + 0.0000f : 14.5906f * norm_storage + (0.0755f * 0.9506f + 0.0000f - 14.5906f * 0.9506f); break;
        case  7: norm_outflow = (norm_storage <= 0.9467f) ? 0.1000f * norm_storage + 0.0258f : 10.6981f * norm_storage + (0.1000f * 0.9467f + 0.0258f - 10.6981f * 0.9467f); break;
        case  8: norm_outflow = (norm_storage <= 1.0000f) ? 0.2690f * norm_storage + -0.0938f : 0.0000f * norm_storage + (0.2690f * 1.0000f + -0.0938f - 0.0000f * 1.0000f); break;
        case  9: norm_outflow = 0.0337f * norm_inflow + 0.0912f; break;
        case 10: norm_outflow = 0.0000f * norm_inflow + 0.0717f; break;
        case 11: norm_outflow = (norm_storage <= 1.0000f) ? -0.2882f * norm_storage + 0.3297f : 0.0000f * norm_storage + (-0.2882f * 1.0000f + 0.3297f - 0.0000f * 1.0000f); break;
        case 12: norm_outflow = 0.0000f * norm_inflow + 0.0649f; break;
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
        case  1: norm_outflow = (norm_storage <= 1.0000f) ? 0.0983f * norm_storage + 0.0692f : 0.0000f * norm_storage + (0.0983f * 1.0000f + 0.0692f - 0.0000f * 1.0000f); break;
        case  2: norm_outflow = (norm_storage <= 0.7577f) ? 0.1000f * norm_storage + 0.0704f : 0.9683f * norm_storage + (0.1000f * 0.7577f + 0.0704f - 0.9683f * 0.7577f); break;
        case  3: norm_outflow = (norm_storage <= 1.0000f) ? 0.1276f * norm_storage + 0.0292f : 0.0000f * norm_storage + (0.1276f * 1.0000f + 0.0292f - 0.0000f * 1.0000f); break;
        case  4: norm_outflow = 0.2798f * norm_inflow + 0.0987f; break;
        case  5: norm_outflow = (norm_storage <= 0.7900f) ? 0.0801f * norm_storage + 0.0677f : 1.2172f * norm_storage + (0.0801f * 0.7900f + 0.0677f - 1.2172f * 0.7900f); break;
        case  6: norm_outflow = (norm_storage <= 0.9265f) ? 0.1000f * norm_storage + 0.0679f : 10.3238f * norm_storage + (0.1000f * 0.9265f + 0.0679f - 10.3238f * 0.9265f); break;
        case  7: norm_outflow = (norm_storage <= 0.9340f) ? 0.1000f * norm_storage + 0.0657f : 8.4715f * norm_storage + (0.1000f * 0.9340f + 0.0657f - 8.4715f * 0.9340f); break;
        case  8: norm_outflow = 0.5748f * norm_inflow + 0.0582f; break;
        case  9: norm_outflow = (norm_storage <= 0.7783f) ? 0.0881f * norm_storage + 0.0466f : 0.9327f * norm_storage + (0.0881f * 0.7783f + 0.0466f - 0.9327f * 0.7783f); break;
        case 10: norm_outflow = (norm_storage <= 0.7512f) ? 0.0610f * norm_storage + 0.0440f : 0.8578f * norm_storage + (0.0610f * 0.7512f + 0.0440f - 0.8578f * 0.7512f); break;
        case 11: norm_outflow = 0.5593f * norm_inflow + 0.0757f; break;
        case 12: norm_outflow = (norm_storage <= 1.0000f) ? 0.0717f * norm_storage + 0.0703f : 0.0000f * norm_storage + (0.0717f * 1.0000f + 0.0703f - 0.0000f * 1.0000f); break;
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
        case  1: norm_outflow = (norm_storage <= 1.0000f) ? 2.1800f * norm_storage + -0.6290f : 0.0000f * norm_storage + (2.1800f * 1.0000f + -0.6290f - 0.0000f * 1.0000f); break;
        case  2: norm_outflow = 3.7936f * norm_inflow + 0.3695f; break;
        case  3: norm_outflow = 1.3897f * norm_inflow + 0.3516f; break;
        case  4: norm_outflow = 0.2673f * norm_inflow + 0.2178f; break;
        case  5: norm_outflow = (norm_storage <= 1.0000f) ? 1.3435f * norm_storage + -0.5287f : 0.0000f * norm_storage + (1.3435f * 1.0000f + -0.5287f - 0.0000f * 1.0000f); break;
        case  6: norm_outflow = (norm_storage <= 1.0000f) ? 2.0368f * norm_storage + -1.0000f : 0.0000f * norm_storage + (2.0368f * 1.0000f + -1.0000f - 0.0000f * 1.0000f); break;
        case  7: norm_outflow = (norm_storage <= 1.0000f) ? 1.8863f * norm_storage + -0.8459f : 0.0000f * norm_storage + (1.8863f * 1.0000f + -0.8459f - 0.0000f * 1.0000f); break;
        case  8: norm_outflow = (norm_storage <= 1.0000f) ? 1.3074f * norm_storage + -0.4840f : 0.0000f * norm_storage + (1.3074f * 1.0000f + -0.4840f - 0.0000f * 1.0000f); break;
        case  9: norm_outflow = (norm_storage <= 1.0000f) ? 1.1970f * norm_storage + -0.4167f : 0.0000f * norm_storage + (1.1970f * 1.0000f + -0.4167f - 0.0000f * 1.0000f); break;
        case 10: norm_outflow = (norm_storage <= 1.0000f) ? 2.0398f * norm_storage + -0.8161f : 0.0000f * norm_storage + (2.0398f * 1.0000f + -0.8161f - 0.0000f * 1.0000f); break;
        case 11: norm_outflow = (norm_storage <= 1.0000f) ? 1.8353f * norm_storage + -0.6305f : 0.0000f * norm_storage + (1.8353f * 1.0000f + -0.6305f - 0.0000f * 1.0000f); break;
        case 12: norm_outflow = (norm_storage <= 1.0000f) ? 2.6331f * norm_storage + -0.9467f : 0.0000f * norm_storage + (2.6331f * 1.0000f + -0.9467f - 0.0000f * 1.0000f); break;
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
        case  1: norm_outflow = (norm_storage <= 0.6000f) ? 0.0486f * norm_storage + 0.1310f : 3.3845f * norm_storage + (0.0486f * 0.6000f + 0.1310f - 3.3845f * 0.6000f); break;
        case  2: norm_outflow = (norm_storage <= 1.0000f) ? 1.4215f * norm_storage + -0.5369f : 0.0000f * norm_storage + (1.4215f * 1.0000f + -0.5369f - 0.0000f * 1.0000f); break;
        case  3: norm_outflow = (norm_storage <= 1.0000f) ? 1.0146f * norm_storage + -0.2607f : 0.0000f * norm_storage + (1.0146f * 1.0000f + -0.2607f - 0.0000f * 1.0000f); break;
        case  4: norm_outflow = 0.0000f * norm_inflow + 0.3711f; break;
        case  5: norm_outflow = 0.0000f * norm_inflow + 0.3336f; break;
        case  6: norm_outflow = (norm_storage <= 0.8642f) ? 0.0000f * norm_storage + 0.2083f : 2.4755f * norm_storage + (0.0000f * 0.8642f + 0.2083f - 2.4755f * 0.8642f); break;
        case  7: norm_outflow = (norm_storage <= 0.8538f) ? 0.0000f * norm_storage + 0.2065f : 3.1108f * norm_storage + (0.0000f * 0.8538f + 0.2065f - 3.1108f * 0.8538f); break;
        case  8: norm_outflow = (norm_storage <= 0.8323f) ? 0.0000f * norm_storage + 0.2101f : 2.7513f * norm_storage + (0.0000f * 0.8323f + 0.2101f - 2.7513f * 0.8323f); break;
        case  9: norm_outflow = (norm_storage <= 1.0000f) ? 1.4019f * norm_storage + -0.8560f : 0.0000f * norm_storage + (1.4019f * 1.0000f + -0.8560f - 0.0000f * 1.0000f); break;
        case 10: norm_outflow = (norm_storage <= 1.0000f) ? 1.0484f * norm_storage + -0.5286f : 0.0000f * norm_storage + (1.0484f * 1.0000f + -0.5286f - 0.0000f * 1.0000f); break;
        case 11: norm_outflow = (norm_storage <= 1.0000f) ? 1.2761f * norm_storage + -0.6043f : 0.0000f * norm_storage + (1.2761f * 1.0000f + -0.6043f - 0.0000f * 1.0000f); break;
        case 12: norm_outflow = (norm_storage <= 0.6171f) ? 0.0000f * norm_storage + 0.1491f : 2.7818f * norm_storage + (0.0000f * 0.6171f + 0.1491f - 2.7818f * 0.6171f); break;
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
        case  1: norm_outflow = (norm_storage <= 1.0000f) ? 24.9722f * norm_storage + -1.6490f : 0.0000f * norm_storage + (24.9722f * 1.0000f + -1.6490f - 0.0000f * 1.0000f); break;
        case  2: norm_outflow = (norm_storage <= 1.0000f) ? 4.0533f * norm_storage + -0.2618f : 0.0000f * norm_storage + (4.0533f * 1.0000f + -0.2618f - 0.0000f * 1.0000f); break;
        case  3: norm_outflow = (norm_storage <= 1.0000f) ? 0.6964f * norm_storage + -0.0340f : 0.0000f * norm_storage + (0.6964f * 1.0000f + -0.0340f - 0.0000f * 1.0000f); break;
        case  4: norm_outflow = (norm_storage <= 1.0000f) ? 0.5956f * norm_storage + -0.0447f : 0.0000f * norm_storage + (0.5956f * 1.0000f + -0.0447f - 0.0000f * 1.0000f); break;
        case  5: norm_outflow = (norm_storage <= 1.0000f) ? 0.5527f * norm_storage + -0.0395f : 0.0000f * norm_storage + (0.5527f * 1.0000f + -0.0395f - 0.0000f * 1.0000f); break;
        case  6: norm_outflow = (norm_storage <= 1.0000f) ? 0.3257f * norm_storage + 0.0466f : 0.0000f * norm_storage + (0.3257f * 1.0000f + 0.0466f - 0.0000f * 1.0000f); break;
        case  7: norm_outflow = (norm_storage <= 1.0000f) ? 0.8512f * norm_storage + -0.0242f : 0.0000f * norm_storage + (0.8512f * 1.0000f + -0.0242f - 0.0000f * 1.0000f); break;
        case  8: norm_outflow = (norm_storage <= 1.0000f) ? 0.8888f * norm_storage + 0.0262f : 0.0000f * norm_storage + (0.8888f * 1.0000f + 0.0262f - 0.0000f * 1.0000f); break;
        case  9: norm_outflow = (norm_storage <= 1.0000f) ? 1.2520f * norm_storage + -0.0442f : 0.0000f * norm_storage + (1.2520f * 1.0000f + -0.0442f - 0.0000f * 1.0000f); break;
        case 10: norm_outflow = (norm_storage <= 1.0000f) ? 2.8295f * norm_storage + -0.1615f : 0.0000f * norm_storage + (2.8295f * 1.0000f + -0.1615f - 0.0000f * 1.0000f); break;
        case 11: norm_outflow = (norm_storage <= 1.0000f) ? 10.4511f * norm_storage + -0.6911f : 0.0000f * norm_storage + (10.4511f * 1.0000f + -0.6911f - 0.0000f * 1.0000f); break;
        case 12: norm_outflow = (norm_storage <= 1.0000f) ? 24.2084f * norm_storage + -1.6125f : 0.0000f * norm_storage + (24.2084f * 1.0000f + -1.6125f - 0.0000f * 1.0000f); break;
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
        case  1: norm_outflow = 0.0724f * norm_inflow + 0.0020f; break;
        case  2: norm_outflow = 0.2884f * norm_inflow + 0.0023f; break;
        case  3: norm_outflow = (norm_storage <= 1.0000f) ? 1.0264f * norm_storage + -0.1186f : 0.0000f * norm_storage + (1.0264f * 1.0000f + -0.1186f - 0.0000f * 1.0000f); break;
        case  4: norm_outflow = (norm_storage <= 1.0000f) ? 1.3245f * norm_storage + -0.1257f : 0.0000f * norm_storage + (1.3245f * 1.0000f + -0.1257f - 0.0000f * 1.0000f); break;
        case  5: norm_outflow = (norm_storage <= 1.0000f) ? 1.3680f * norm_storage + -0.0876f : 0.0000f * norm_storage + (1.3680f * 1.0000f + -0.0876f - 0.0000f * 1.0000f); break;
        case  6: norm_outflow = (norm_storage <= 1.0000f) ? 1.7496f * norm_storage + -0.1788f : 0.0000f * norm_storage + (1.7496f * 1.0000f + -0.1788f - 0.0000f * 1.0000f); break;
        case  7: norm_outflow = (norm_storage <= 1.0000f) ? 1.2643f * norm_storage + -0.1080f : 0.0000f * norm_storage + (1.2643f * 1.0000f + -0.1080f - 0.0000f * 1.0000f); break;
        case  8: norm_outflow = (norm_storage <= 1.0000f) ? 1.0168f * norm_storage + -0.0953f : 0.0000f * norm_storage + (1.0168f * 1.0000f + -0.0953f - 0.0000f * 1.0000f); break;
        case  9: norm_outflow = (norm_storage <= 1.0000f) ? 1.5411f * norm_storage + -0.1491f : 0.0000f * norm_storage + (1.5411f * 1.0000f + -0.1491f - 0.0000f * 1.0000f); break;
        case 10: norm_outflow = (norm_storage <= 1.0000f) ? 3.2093f * norm_storage + -0.3459f : 0.0000f * norm_storage + (3.2093f * 1.0000f + -0.3459f - 0.0000f * 1.0000f); break;
        case 11: norm_outflow = 2.5504f * norm_inflow + 0.0017f; break;
        case 12: norm_outflow = 1.5360f * norm_inflow + -0.0022f; break;
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
        case  1: norm_outflow = 0.0745f * norm_inflow + 0.0010f; break;
        case  2: norm_outflow = (norm_storage <= 0.8924f) ? 0.0119f * norm_storage + 0.0000f : 1.3383f * norm_storage + (0.0119f * 0.8924f + 0.0000f - 1.3383f * 0.8924f); break;
        case  3: norm_outflow = (norm_storage <= 1.0000f) ? 0.1254f * norm_storage + -0.0507f : 0.0000f * norm_storage + (0.1254f * 1.0000f + -0.0507f - 0.0000f * 1.0000f); break;
        case  4: norm_outflow = (norm_storage <= 0.9274f) ? 0.0270f * norm_storage + 0.0000f : 8.5629f * norm_storage + (0.0270f * 0.9274f + 0.0000f - 8.5629f * 0.9274f); break;
        case  5: norm_outflow = (norm_storage <= 0.8997f) ? 0.0125f * norm_storage + 0.0000f : 1.6696f * norm_storage + (0.0125f * 0.8997f + 0.0000f - 1.6696f * 0.8997f); break;
        case  6: norm_outflow = (norm_storage <= 0.9160f) ? 0.0123f * norm_storage + 0.0000f : 4.9922f * norm_storage + (0.0123f * 0.9160f + 0.0000f - 4.9922f * 0.9160f); break;
        case  7: norm_outflow = (norm_storage <= 0.9237f) ? 0.0094f * norm_storage + 0.0000f : 10.2002f * norm_storage + (0.0094f * 0.9237f + 0.0000f - 10.2002f * 0.9237f); break;
        case  8: norm_outflow = (norm_storage <= 0.9489f) ? 0.0077f * norm_storage + 0.0000f : 32.0612f * norm_storage + (0.0077f * 0.9489f + 0.0000f - 32.0612f * 0.9489f); break;
        case  9: norm_outflow = (norm_storage <= 0.8937f) ? 0.0025f * norm_storage + 0.0012f : 0.9554f * norm_storage + (0.0025f * 0.8937f + 0.0012f - 0.9554f * 0.8937f); break;
        case 10: norm_outflow = 0.7820f * norm_inflow + 0.0030f; break;
        case 11: norm_outflow = 0.2527f * norm_inflow + 0.0012f; break;
        case 12: norm_outflow = 0.1346f * norm_inflow + 0.0006f; break;
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
        case  1: norm_outflow = 0.0000f * norm_inflow + 0.3273f; break;
        case  2: norm_outflow = 3.2862f * norm_inflow + 0.4386f; break;
        case  3: norm_outflow = 0.0000f * norm_inflow + 0.3800f; break;
        case  4: norm_outflow = 1.5003f * norm_inflow + 0.4108f; break;
        case  5: norm_outflow = 0.0000f * norm_inflow + 0.3930f; break;
        case  6: norm_outflow = 0.0000f * norm_inflow + 0.3943f; break;
        case  7: norm_outflow = 2.0068f * norm_inflow + 0.3236f; break;
        case  8: norm_outflow = 4.4067f * norm_inflow + 0.2371f; break;
        case  9: norm_outflow = 0.0000f * norm_inflow + 0.3051f; break;
        case 10: norm_outflow = 0.0013f * norm_inflow + 0.3827f; break;
        case 11: norm_outflow = 9.7969f * norm_inflow + 0.2880f; break;
        case 12: norm_outflow = 10.7120f * norm_inflow + 0.2097f; break;
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
        case  1: norm_outflow = 0.7148f * norm_inflow + 0.1182f; break;
        case  2: norm_outflow = (norm_storage <= 1.0000f) ? -0.5819f * norm_storage + 0.5393f : 0.0000f * norm_storage + (-0.5819f * 1.0000f + 0.5393f - 0.0000f * 1.0000f); break;
        case  3: norm_outflow = (norm_storage <= 1.0000f) ? -0.2817f * norm_storage + 0.3097f : 0.0000f * norm_storage + (-0.2817f * 1.0000f + 0.3097f - 0.0000f * 1.0000f); break;
        case  4: norm_outflow = 1.5242f * norm_inflow + 0.0856f; break;
        case  5: norm_outflow = (norm_storage <= 0.8963f) ? 0.1000f * norm_storage + 0.0131f : 6.3969f * norm_storage + (0.1000f * 0.8963f + 0.0131f - 6.3969f * 0.8963f); break;
        case  6: norm_outflow = (norm_storage <= 1.0000f) ? 8.3030f * norm_storage + -7.3600f : 0.0000f * norm_storage + (8.3030f * 1.0000f + -7.3600f - 0.0000f * 1.0000f); break;
        case  7: norm_outflow = (norm_storage <= 1.0000f) ? 6.4918f * norm_storage + -5.7616f : 0.0000f * norm_storage + (6.4918f * 1.0000f + -5.7616f - 0.0000f * 1.0000f); break;
        case  8: norm_outflow = (norm_storage <= 1.0000f) ? 2.4838f * norm_storage + -2.1651f : 0.0000f * norm_storage + (2.4838f * 1.0000f + -2.1651f - 0.0000f * 1.0000f); break;
        case  9: norm_outflow = (norm_storage <= 1.0000f) ? 1.8498f * norm_storage + -1.5889f : 0.0000f * norm_storage + (1.8498f * 1.0000f + -1.5889f - 0.0000f * 1.0000f); break;
        case 10: norm_outflow = 2.6142f * norm_inflow + 0.1029f; break;
        case 11: norm_outflow = 3.9651f * norm_inflow + 0.1442f; break;
        case 12: norm_outflow = 0.9343f * norm_inflow + 0.1487f; break;
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
        case  1: norm_outflow = (norm_storage <= 1.0000f) ? 0.0259f * norm_storage + -0.0059f : 0.0000f * norm_storage + (0.0259f * 1.0000f + -0.0059f - 0.0000f * 1.0000f); break;
        case  2: norm_outflow = (norm_storage <= 1.0000f) ? 0.1653f * norm_storage + -0.0547f : 0.0000f * norm_storage + (0.1653f * 1.0000f + -0.0547f - 0.0000f * 1.0000f); break;
        case  3: norm_outflow = (norm_storage <= 1.0000f) ? 1.5100f * norm_storage + -0.5714f : 0.0000f * norm_storage + (1.5100f * 1.0000f + -0.5714f - 0.0000f * 1.0000f); break;
        case  4: norm_outflow = (norm_storage <= 1.0000f) ? 1.6642f * norm_storage + -0.6619f : 0.0000f * norm_storage + (1.6642f * 1.0000f + -0.6619f - 0.0000f * 1.0000f); break;
        case  5: norm_outflow = 0.4469f * norm_inflow + 0.0214f; break;
        case  6: norm_outflow = 0.8834f * norm_inflow + 0.0141f; break;
        case  7: norm_outflow = 0.2024f * norm_inflow + 0.0207f; break;
        case  8: norm_outflow = 1.3929f * norm_inflow + 0.0077f; break;
        case  9: norm_outflow = 0.1835f * norm_inflow + 0.0103f; break;
        case 10: norm_outflow = 0.5748f * norm_inflow + 0.0038f; break;
        case 11: norm_outflow = 0.2342f * norm_inflow + 0.0030f; break;
        case 12: norm_outflow = 0.2371f * norm_inflow + 0.0033f; break;
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
        case  1: norm_outflow = 0.0000f * norm_inflow + 0.3106f; break;
        case  2: norm_outflow = 0.0000f * norm_inflow + 0.3517f; break;
        case  3: norm_outflow = 0.0000f * norm_inflow + 0.3263f; break;
        case  4: norm_outflow = 0.3482f * norm_inflow + 0.3677f; break;
        case  5: norm_outflow = 2.0437f * norm_inflow + 0.2926f; break;
        case  6: norm_outflow = 0.5273f * norm_inflow + 0.3310f; break;
        case  7: norm_outflow = 0.3824f * norm_inflow + 0.2901f; break;
        case  8: norm_outflow = (norm_storage <= 1.0000f) ? 1.9055f * norm_storage + -1.3546f : 0.0000f * norm_storage + (1.9055f * 1.0000f + -1.3546f - 0.0000f * 1.0000f); break;
        case  9: norm_outflow = (norm_storage <= 1.0000f) ? 1.7750f * norm_storage + -1.2043f : 0.0000f * norm_storage + (1.7750f * 1.0000f + -1.2043f - 0.0000f * 1.0000f); break;
        case 10: norm_outflow = 0.3656f * norm_inflow + 0.3552f; break;
        case 11: norm_outflow = 0.0000f * norm_inflow + 0.3303f; break;
        case 12: norm_outflow = 0.0000f * norm_inflow + 0.2430f; break;
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
        case  5: norm_outflow = (norm_storage <= 0.6000f) ? 0.0926f * norm_storage + 0.0000f : 12.1144f * norm_storage + (0.0926f * 0.6000f + 0.0000f - 12.1144f * 0.6000f); break;
        case  6: norm_outflow = 0.3671f * norm_inflow + 0.0135f; break;
        case  7: norm_outflow = (norm_storage <= 0.6000f) ? 0.0532f * norm_storage + 0.0000f : 12.0971f * norm_storage + (0.0532f * 0.6000f + 0.0000f - 12.0971f * 0.6000f); break;
        case  8: norm_outflow = (norm_storage <= 0.6000f) ? 0.0384f * norm_storage + 0.0000f : 12.3106f * norm_storage + (0.0384f * 0.6000f + 0.0000f - 12.3106f * 0.6000f); break;
        case  9: norm_outflow = (norm_storage <= 1.0000f) ? 0.0970f * norm_storage + -0.0281f : 0.0000f * norm_storage + (0.0970f * 1.0000f + -0.0281f - 0.0000f * 1.0000f); break;
        case 10: norm_outflow = 0.3450f * norm_inflow + 0.0084f; break;
        case 11: norm_outflow = 0.2612f * norm_inflow + 0.0100f; break;
        case 12: norm_outflow = 0.1666f * norm_inflow + 0.0069f; break;
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
        case  1: norm_outflow = (norm_storage <= 1.0000f) ? 0.0455f * norm_storage + -0.0042f : 0.0000f * norm_storage + (0.0455f * 1.0000f + -0.0042f - 0.0000f * 1.0000f); break;
        case  2: norm_outflow = (norm_storage <= 1.0000f) ? 0.0858f * norm_storage + -0.0091f : 0.0000f * norm_storage + (0.0858f * 1.0000f + -0.0091f - 0.0000f * 1.0000f); break;
        case  3: norm_outflow = (norm_storage <= 1.0000f) ? 0.7344f * norm_storage + -0.1018f : 0.0000f * norm_storage + (0.7344f * 1.0000f + -0.1018f - 0.0000f * 1.0000f); break;
        case  4: norm_outflow = (norm_storage <= 1.0000f) ? 0.9214f * norm_storage + -0.1337f : 0.0000f * norm_storage + (0.9214f * 1.0000f + -0.1337f - 0.0000f * 1.0000f); break;
        case  5: norm_outflow = 0.9999f * norm_inflow + 0.0253f; break;
        case  6: norm_outflow = 0.3593f * norm_inflow + 0.0284f; break;
        case  7: norm_outflow = 1.1270f * norm_inflow + 0.0141f; break;
        case  8: norm_outflow = 1.0383f * norm_inflow + 0.0014f; break;
        case  9: norm_outflow = (norm_storage <= 1.0000f) ? 0.0745f * norm_storage + -0.0036f : 0.0000f * norm_storage + (0.0745f * 1.0000f + -0.0036f - 0.0000f * 1.0000f); break;
        case 10: norm_outflow = (norm_storage <= 1.0000f) ? 0.1710f * norm_storage + -0.0202f : 0.0000f * norm_storage + (0.1710f * 1.0000f + -0.0202f - 0.0000f * 1.0000f); break;
        case 11: norm_outflow = (norm_storage <= 1.0000f) ? 0.1068f * norm_storage + -0.0103f : 0.0000f * norm_storage + (0.1068f * 1.0000f + -0.0103f - 0.0000f * 1.0000f); break;
        case 12: norm_outflow = 0.5219f * norm_inflow + 0.0039f; break;
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
        case  1: norm_outflow = 0.2715f * norm_inflow + 0.0097f; break;
        case  2: norm_outflow = 0.5256f * norm_inflow + 0.0105f; break;
        case  3: norm_outflow = (norm_storage <= 1.0000f) ? 0.8526f * norm_storage + -0.2075f : 0.0000f * norm_storage + (0.8526f * 1.0000f + -0.2075f - 0.0000f * 1.0000f); break;
        case  4: norm_outflow = (norm_storage <= 1.0000f) ? 0.7878f * norm_storage + -0.1758f : 0.0000f * norm_storage + (0.7878f * 1.0000f + -0.1758f - 0.0000f * 1.0000f); break;
        case  5: norm_outflow = (norm_storage <= 1.0000f) ? 0.3608f * norm_storage + -0.0466f : 0.0000f * norm_storage + (0.3608f * 1.0000f + -0.0466f - 0.0000f * 1.0000f); break;
        case  6: norm_outflow = (norm_storage <= 0.7225f) ? 0.1000f * norm_storage + 0.0295f : 4.5087f * norm_storage + (0.1000f * 0.7225f + 0.0295f - 4.5087f * 0.7225f); break;
        case  7: norm_outflow = (norm_storage <= 1.0000f) ? 0.3769f * norm_storage + -0.0729f : 0.0000f * norm_storage + (0.3769f * 1.0000f + -0.0729f - 0.0000f * 1.0000f); break;
        case  8: norm_outflow = (norm_storage <= 1.0000f) ? 0.2915f * norm_storage + -0.0594f : 0.0000f * norm_storage + (0.2915f * 1.0000f + -0.0594f - 0.0000f * 1.0000f); break;
        case  9: norm_outflow = (norm_storage <= 1.0000f) ? 0.3209f * norm_storage + -0.0793f : 0.0000f * norm_storage + (0.3209f * 1.0000f + -0.0793f - 0.0000f * 1.0000f); break;
        case 10: norm_outflow = (norm_storage <= 1.0000f) ? 0.3253f * norm_storage + -0.0838f : 0.0000f * norm_storage + (0.3253f * 1.0000f + -0.0838f - 0.0000f * 1.0000f); break;
        case 11: norm_outflow = 0.3818f * norm_inflow + 0.0142f; break;
        case 12: norm_outflow = 0.5783f * norm_inflow + 0.0099f; break;
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
        case  2: norm_outflow = 0.0000f * norm_inflow + 0.0006f; break;
        case  3: norm_outflow = (norm_storage <= 0.8952f) ? 0.0017f * norm_storage + 0.0001f : 0.9355f * norm_storage + (0.0017f * 0.8952f + 0.0001f - 0.9355f * 0.8952f); break;
        case  4: norm_outflow = 0.2690f * norm_inflow + 0.0159f; break;
        case  5: norm_outflow = 0.8036f * norm_inflow + 0.1004f; break;
        case  6: norm_outflow = 0.0000f * norm_inflow + 0.2878f; break;
        case  7: norm_outflow = (norm_storage <= 1.0000f) ? -0.2797f * norm_storage + 0.7717f : 0.0000f * norm_storage + (-0.2797f * 1.0000f + 0.7717f - 0.0000f * 1.0000f); break;
        case  8: norm_outflow = 0.0000f * norm_inflow + 0.5818f; break;
        case  9: norm_outflow = (norm_storage <= 1.0000f) ? 0.4017f * norm_storage + 0.1463f : 0.0000f * norm_storage + (0.4017f * 1.0000f + 0.1463f - 0.0000f * 1.0000f); break;
        case 10: norm_outflow = 0.0725f * norm_inflow + 0.0104f; break;
        case 11: norm_outflow = 0.1409f * norm_inflow + 0.0009f; break;
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
        case  1: norm_outflow = (norm_storage <= 1.0000f) ? 0.1861f * norm_storage + -0.0053f : 0.0000f * norm_storage + (0.1861f * 1.0000f + -0.0053f - 0.0000f * 1.0000f); break;
        case  2: norm_outflow = (norm_storage <= 1.0000f) ? 0.0925f * norm_storage + 0.0419f : 0.0000f * norm_storage + (0.0925f * 1.0000f + 0.0419f - 0.0000f * 1.0000f); break;
        case  3: norm_outflow = (norm_storage <= 0.9203f) ? 0.0769f * norm_storage + 0.0483f : 4.6322f * norm_storage + (0.0769f * 0.9203f + 0.0483f - 4.6322f * 0.9203f); break;
        case  4: norm_outflow = (norm_storage <= 0.9414f) ? 0.0186f * norm_storage + 0.1064f : 6.9571f * norm_storage + (0.0186f * 0.9414f + 0.1064f - 6.9571f * 0.9414f); break;
        case  5: norm_outflow = 0.2312f * norm_inflow + 0.1051f; break;
        case  6: norm_outflow = (norm_storage <= 0.9776f) ? 0.1000f * norm_storage + 0.0647f : 43.4838f * norm_storage + (0.1000f * 0.9776f + 0.0647f - 43.4838f * 0.9776f); break;
        case  7: norm_outflow = (norm_storage <= 0.9756f) ? 0.1000f * norm_storage + 0.0903f : 33.7340f * norm_storage + (0.1000f * 0.9756f + 0.0903f - 33.7340f * 0.9756f); break;
        case  8: norm_outflow = 0.4486f * norm_inflow + 0.1076f; break;
        case  9: norm_outflow = 0.5035f * norm_inflow + 0.1028f; break;
        case 10: norm_outflow = (norm_storage <= 0.8326f) ? 0.1000f * norm_storage + 0.0375f : 2.0542f * norm_storage + (0.1000f * 0.8326f + 0.0375f - 2.0542f * 0.8326f); break;
        case 11: norm_outflow = (norm_storage <= 0.8030f) ? 0.1000f * norm_storage + 0.0317f : 2.0469f * norm_storage + (0.1000f * 0.8030f + 0.0317f - 2.0469f * 0.8030f); break;
        case 12: norm_outflow = (norm_storage <= 0.7534f) ? 0.0430f * norm_storage + 0.0706f : 0.7201f * norm_storage + (0.0430f * 0.7534f + 0.0706f - 0.7201f * 0.7534f); break;
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
        case  1: norm_outflow = 3.4725f * norm_inflow + 0.0497f; break;
        case  2: norm_outflow = 4.2170f * norm_inflow + 0.0503f; break;
        case  3: norm_outflow = (norm_storage <= 0.7931f) ? 0.0367f * norm_storage + 0.0111f : 1.2721f * norm_storage + (0.0367f * 0.7931f + 0.0111f - 1.2721f * 0.7931f); break;
        case  4: norm_outflow = (norm_storage <= 0.8370f) ? 0.0666f * norm_storage + 0.0000f : 5.6846f * norm_storage + (0.0666f * 0.8370f + 0.0000f - 5.6846f * 0.8370f); break;
        case  5: norm_outflow = (norm_storage <= 0.8554f) ? 0.0859f * norm_storage + 0.0097f : 11.0701f * norm_storage + (0.0859f * 0.8554f + 0.0097f - 11.0701f * 0.8554f); break;
        case  6: norm_outflow = (norm_storage <= 0.8483f) ? 0.0135f * norm_storage + 0.0555f : 8.1298f * norm_storage + (0.0135f * 0.8483f + 0.0555f - 8.1298f * 0.8483f); break;
        case  7: norm_outflow = (norm_storage <= 0.8502f) ? 0.0000f * norm_storage + 0.1251f : 6.8780f * norm_storage + (0.0000f * 0.8502f + 0.1251f - 6.8780f * 0.8502f); break;
        case  8: norm_outflow = 3.2613f * norm_inflow + 0.1050f; break;
        case  9: norm_outflow = 3.8416f * norm_inflow + 0.0673f; break;
        case 10: norm_outflow = 3.2670f * norm_inflow + 0.0492f; break;
        case 11: norm_outflow = 3.4098f * norm_inflow + 0.0458f; break;
        case 12: norm_outflow = 2.6753f * norm_inflow + 0.0557f; break;
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
        case  1: norm_outflow = (norm_storage <= 1.0000f) ? 2.8225f * norm_storage + -2.3837f : 0.0000f * norm_storage + (2.8225f * 1.0000f + -2.3837f - 0.0000f * 1.0000f); break;
        case  2: norm_outflow = 2.6677f * norm_inflow + 0.2171f; break;
        case  3: norm_outflow = 1.5223f * norm_inflow + 0.1804f; break;
        case  4: norm_outflow = 0.8835f * norm_inflow + 0.2145f; break;
        case  5: norm_outflow = 0.1174f * norm_inflow + 0.2552f; break;
        case  6: norm_outflow = 0.0000f * norm_inflow + 0.3051f; break;
        case  7: norm_outflow = 0.1366f * norm_inflow + 0.3099f; break;
        case  8: norm_outflow = 0.0568f * norm_inflow + 0.3783f; break;
        case  9: norm_outflow = 0.5732f * norm_inflow + 0.2445f; break;
        case 10: norm_outflow = 0.4113f * norm_inflow + 0.2250f; break;
        case 11: norm_outflow = 0.9388f * norm_inflow + 0.1780f; break;
        case 12: norm_outflow = 1.3075f * norm_inflow + 0.1633f; break;
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
        case  1: norm_outflow = 2.6172f * norm_inflow + 0.1024f; break;
        case  2: norm_outflow = 3.7419f * norm_inflow + 0.1076f; break;
        case  3: norm_outflow = 3.3393f * norm_inflow + 0.1331f; break;
        case  4: norm_outflow = 2.4143f * norm_inflow + 0.1708f; break;
        case  5: norm_outflow = (norm_storage <= 0.8955f) ? 0.0050f * norm_storage + 0.0687f : 3.3872f * norm_storage + (0.0050f * 0.8955f + 0.0687f - 3.3872f * 0.8955f); break;
        case  6: norm_outflow = (norm_storage <= 0.9563f) ? 0.0819f * norm_storage + 0.0690f : 14.7870f * norm_storage + (0.0819f * 0.9563f + 0.0690f - 14.7870f * 0.9563f); break;
        case  7: norm_outflow = 2.3743f * norm_inflow + 0.1470f; break;
        case  8: norm_outflow = 3.3611f * norm_inflow + 0.1154f; break;
        case  9: norm_outflow = 5.0631f * norm_inflow + 0.0842f; break;
        case 10: norm_outflow = 2.8735f * norm_inflow + 0.1023f; break;
        case 11: norm_outflow = (norm_storage <= 1.0000f) ? 0.6821f * norm_storage + -0.4929f : 0.0000f * norm_storage + (0.6821f * 1.0000f + -0.4929f - 0.0000f * 1.0000f); break;
        case 12: norm_outflow = 2.6637f * norm_inflow + 0.1022f; break;
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
        case  1: norm_outflow = 0.0030f * norm_inflow + 0.0003f; break;
        case  2: norm_outflow = (norm_storage <= 0.9539f) ? 0.0003f * norm_storage + 0.0002f : 0.9218f * norm_storage + (0.0003f * 0.9539f + 0.0002f - 0.9218f * 0.9539f); break;
        case  3: norm_outflow = 2.0230f * norm_inflow + -0.0064f; break;
        case  4: norm_outflow = 0.2995f * norm_inflow + -0.0012f; break;
        case  5: norm_outflow = 0.2476f * norm_inflow + 0.0014f; break;
        case  6: norm_outflow = 0.3904f * norm_inflow + -0.0077f; break;
        case  7: norm_outflow = 0.0968f * norm_inflow + 0.0102f; break;
        case  8: norm_outflow = (norm_storage <= 1.0000f) ? 0.0128f * norm_storage + 0.0038f : 0.0000f * norm_storage + (0.0128f * 1.0000f + 0.0038f - 0.0000f * 1.0000f); break;
        case  9: norm_outflow = (norm_storage <= 1.0000f) ? 0.0114f * norm_storage + -0.0023f : 0.0000f * norm_storage + (0.0114f * 1.0000f + -0.0023f - 0.0000f * 1.0000f); break;
        case 10: norm_outflow = (norm_storage <= 0.9181f) ? 0.0017f * norm_storage + 0.0000f : 0.9465f * norm_storage + (0.0017f * 0.9181f + 0.0000f - 0.9465f * 0.9181f); break;
        case 11: norm_outflow = 0.3256f * norm_inflow + -0.0019f; break;
        case 12: norm_outflow = 0.0220f * norm_inflow + 0.0006f; break;
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
        case  1: norm_outflow = 1.8106f * norm_inflow + 0.1029f; break;
        case  2: norm_outflow = 0.9158f * norm_inflow + 0.0961f; break;
        case  3: norm_outflow = 0.5901f * norm_inflow + 0.1012f; break;
        case  4: norm_outflow = 0.3808f * norm_inflow + 0.1282f; break;
        case  5: norm_outflow = 0.2890f * norm_inflow + 0.1414f; break;
        case  6: norm_outflow = 0.4646f * norm_inflow + 0.1072f; break;
        case  7: norm_outflow = 0.4564f * norm_inflow + 0.0885f; break;
        case  8: norm_outflow = 0.4966f * norm_inflow + 0.1049f; break;
        case  9: norm_outflow = 0.5767f * norm_inflow + 0.1268f; break;
        case 10: norm_outflow = 0.4827f * norm_inflow + 0.1439f; break;
        case 11: norm_outflow = 0.6964f * norm_inflow + 0.1100f; break;
        case 12: norm_outflow = 0.4703f * norm_inflow + 0.0836f; break;
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
        case  1: norm_outflow = 0.0034f * norm_inflow + 0.0029f; break;
        case  2: norm_outflow = (norm_storage <= 0.6162f) ? 0.0075f * norm_storage + 0.0000f : 0.9989f * norm_storage + (0.0075f * 0.6162f + 0.0000f - 0.9989f * 0.6162f); break;
        case  3: norm_outflow = (norm_storage <= 1.0000f) ? 0.4800f * norm_storage + -0.2098f : 0.0000f * norm_storage + (0.4800f * 1.0000f + -0.2098f - 0.0000f * 1.0000f); break;
        case  4: norm_outflow = (norm_storage <= 1.0000f) ? 0.8705f * norm_storage + -0.3968f : 0.0000f * norm_storage + (0.8705f * 1.0000f + -0.3968f - 0.0000f * 1.0000f); break;
        case  5: norm_outflow = 0.5834f * norm_inflow + 0.1178f; break;
        case  6: norm_outflow = (norm_storage <= 0.7041f) ? 0.0000f * norm_storage + 0.2859f : 1.8011f * norm_storage + (0.0000f * 0.7041f + 0.2859f - 1.8011f * 0.7041f); break;
        case  7: norm_outflow = 0.0962f * norm_inflow + 0.5862f; break;
        case  8: norm_outflow = (norm_storage <= 1.0000f) ? 0.6710f * norm_storage + 0.3445f : 0.0000f * norm_storage + (0.6710f * 1.0000f + 0.3445f - 0.0000f * 1.0000f); break;
        case  9: norm_outflow = 2.1166f * norm_inflow + -0.0083f; break;
        case 10: norm_outflow = 0.0240f * norm_inflow + 0.0024f; break;
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
        case  4: norm_outflow = (norm_storage <= 1.0000f) ? 1.8388f * norm_storage + 0.0180f : 0.0000f * norm_storage + (1.8388f * 1.0000f + 0.0180f - 0.0000f * 1.0000f); break;
        case  5: norm_outflow = (norm_storage <= 1.0000f) ? 0.6101f * norm_storage + 0.2802f : 0.0000f * norm_storage + (0.6101f * 1.0000f + 0.2802f - 0.0000f * 1.0000f); break;
        case  6: norm_outflow = (norm_storage <= 1.0000f) ? 0.6814f * norm_storage + -0.0721f : 0.0000f * norm_storage + (0.6814f * 1.0000f + -0.0721f - 0.0000f * 1.0000f); break;
        case  7: norm_outflow = 0.0000f * norm_inflow + 0.2470f; break;
        case  8: norm_outflow = (norm_storage <= 1.0000f) ? -0.1148f * norm_storage + 0.2741f : 0.0000f * norm_storage + (-0.1148f * 1.0000f + 0.2741f - 0.0000f * 1.0000f); break;
        case  9: norm_outflow = 0.0000f * norm_inflow + 0.5459f; break;
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
        case  1: norm_outflow = 1.2781f * norm_inflow + 0.0173f; break;
        case  2: norm_outflow = 1.7891f * norm_inflow + 0.0156f; break;
        case  3: norm_outflow = (norm_storage <= 1.0000f) ? 0.5384f * norm_storage + 0.0478f : 0.0000f * norm_storage + (0.5384f * 1.0000f + 0.0478f - 0.0000f * 1.0000f); break;
        case  4: norm_outflow = (norm_storage <= 1.0000f) ? 0.5050f * norm_storage + 0.0555f : 0.0000f * norm_storage + (0.5050f * 1.0000f + 0.0555f - 0.0000f * 1.0000f); break;
        case  5: norm_outflow = (norm_storage <= 1.0000f) ? 0.3106f * norm_storage + 0.0755f : 0.0000f * norm_storage + (0.3106f * 1.0000f + 0.0755f - 0.0000f * 1.0000f); break;
        case  6: norm_outflow = (norm_storage <= 1.0000f) ? 0.6862f * norm_storage + 0.0261f : 0.0000f * norm_storage + (0.6862f * 1.0000f + 0.0261f - 0.0000f * 1.0000f); break;
        case  7: norm_outflow = (norm_storage <= 1.0000f) ? 0.6391f * norm_storage + 0.0269f : 0.0000f * norm_storage + (0.6391f * 1.0000f + 0.0269f - 0.0000f * 1.0000f); break;
        case  8: norm_outflow = (norm_storage <= 1.0000f) ? 1.1591f * norm_storage + -0.0244f : 0.0000f * norm_storage + (1.1591f * 1.0000f + -0.0244f - 0.0000f * 1.0000f); break;
        case  9: norm_outflow = 0.3914f * norm_inflow + 0.0262f; break;
        case 10: norm_outflow = 0.7027f * norm_inflow + 0.0144f; break;
        case 11: norm_outflow = (norm_storage <= 1.0000f) ? 0.4232f * norm_storage + -0.0069f : 0.0000f * norm_storage + (0.4232f * 1.0000f + -0.0069f - 0.0000f * 1.0000f); break;
        case 12: norm_outflow = (norm_storage <= 1.0000f) ? 0.6609f * norm_storage + -0.0091f : 0.0000f * norm_storage + (0.6609f * 1.0000f + -0.0091f - 0.0000f * 1.0000f); break;
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
        case  1: norm_outflow = 0.9222f * norm_inflow + 0.0140f; break;
        case  2: norm_outflow = 1.5576f * norm_inflow + 0.0182f; break;
        case  3: norm_outflow = 1.1830f * norm_inflow + 0.0467f; break;
        case  4: norm_outflow = (norm_storage <= 1.0000f) ? 0.4639f * norm_storage + 0.0432f : 0.0000f * norm_storage + (0.4639f * 1.0000f + 0.0432f - 0.0000f * 1.0000f); break;
        case  5: norm_outflow = (norm_storage <= 1.0000f) ? 0.3033f * norm_storage + 0.0663f : 0.0000f * norm_storage + (0.3033f * 1.0000f + 0.0663f - 0.0000f * 1.0000f); break;
        case  6: norm_outflow = (norm_storage <= 1.0000f) ? 0.4171f * norm_storage + 0.0447f : 0.0000f * norm_storage + (0.4171f * 1.0000f + 0.0447f - 0.0000f * 1.0000f); break;
        case  7: norm_outflow = (norm_storage <= 1.0000f) ? 0.6367f * norm_storage + -0.0029f : 0.0000f * norm_storage + (0.6367f * 1.0000f + -0.0029f - 0.0000f * 1.0000f); break;
        case  8: norm_outflow = (norm_storage <= 1.0000f) ? 0.8588f * norm_storage + -0.0483f : 0.0000f * norm_storage + (0.8588f * 1.0000f + -0.0483f - 0.0000f * 1.0000f); break;
        case  9: norm_outflow = 0.7506f * norm_inflow + 0.0226f; break;
        case 10: norm_outflow = 0.7153f * norm_inflow + 0.0192f; break;
        case 11: norm_outflow = 0.7600f * norm_inflow + 0.0212f; break;
        case 12: norm_outflow = 1.3900f * norm_inflow + 0.0176f; break;
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
        case  4: norm_outflow = (norm_storage <= 1.0000f) ? 0.3296f * norm_storage + -0.1003f : 0.0000f * norm_storage + (0.3296f * 1.0000f + -0.1003f - 0.0000f * 1.0000f); break;
        case  5: norm_outflow = (norm_storage <= 0.7927f) ? 0.0243f * norm_storage + 0.0554f : 2.2344f * norm_storage + (0.0243f * 0.7927f + 0.0554f - 2.2344f * 0.7927f); break;
        case  6: norm_outflow = (norm_storage <= 1.0000f) ? 0.4102f * norm_storage + -0.0654f : 0.0000f * norm_storage + (0.4102f * 1.0000f + -0.0654f - 0.0000f * 1.0000f); break;
        case  7: norm_outflow = (norm_storage <= 1.0000f) ? 0.1313f * norm_storage + 0.2765f : 0.0000f * norm_storage + (0.1313f * 1.0000f + 0.2765f - 0.0000f * 1.0000f); break;
        case  8: norm_outflow = (norm_storage <= 0.8104f) ? 0.1000f * norm_storage + 0.2185f : 1.2196f * norm_storage + (0.1000f * 0.8104f + 0.2185f - 1.2196f * 0.8104f); break;
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
        case  8: norm_outflow = (norm_storage <= 0.7852f) ? 0.0263f * norm_storage + 0.0000f : 3.7558f * norm_storage + (0.0263f * 0.7852f + 0.0000f - 3.7558f * 0.7852f); break;
        case  9: norm_outflow = (norm_storage <= 0.7809f) ? 0.0000f * norm_storage + 0.0251f : 3.0915f * norm_storage + (0.0000f * 0.7809f + 0.0251f - 3.0915f * 0.7809f); break;
        case 10: norm_outflow = (norm_storage <= 1.0000f) ? 1.0087f * norm_storage + -0.7282f : 0.0000f * norm_storage + (1.0087f * 1.0000f + -0.7282f - 0.0000f * 1.0000f); break;
        case 11: norm_outflow = (norm_storage <= 1.0000f) ? 0.3158f * norm_storage + -0.1910f : 0.0000f * norm_storage + (0.3158f * 1.0000f + -0.1910f - 0.0000f * 1.0000f); break;
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
        case  1: norm_outflow = 0.0000f * norm_inflow + 0.5130f; break;
        case  2: norm_outflow = 38.0290f * norm_inflow + 0.5678f; break;
        case  3: norm_outflow = 17.4414f * norm_inflow + 0.5951f; break;
        case  4: norm_outflow = 5.2049f * norm_inflow + 0.5979f; break;
        case  5: norm_outflow = (norm_storage <= 1.0000f) ? 1.9060f * norm_storage + -0.9666f : 0.0000f * norm_storage + (1.9060f * 1.0000f + -0.9666f - 0.0000f * 1.0000f); break;
        case  6: norm_outflow = (norm_storage <= 1.0000f) ? 1.7430f * norm_storage + -0.7771f : 0.0000f * norm_storage + (1.7430f * 1.0000f + -0.7771f - 0.0000f * 1.0000f); break;
        case  7: norm_outflow = (norm_storage <= 1.0000f) ? 0.7717f * norm_storage + 0.1680f : 0.0000f * norm_storage + (0.7717f * 1.0000f + 0.1680f - 0.0000f * 1.0000f); break;
        case  8: norm_outflow = (norm_storage <= 1.0000f) ? 0.9641f * norm_storage + -0.0318f : 0.0000f * norm_storage + (0.9641f * 1.0000f + -0.0318f - 0.0000f * 1.0000f); break;
        case  9: norm_outflow = (norm_storage <= 0.7574f) ? 0.1000f * norm_storage + 0.3000f : 2.5900f * norm_storage + (0.1000f * 0.7574f + 0.3000f - 2.5900f * 0.7574f); break;
        case 10: norm_outflow = 2.3304f * norm_inflow + 0.5003f; break;
        case 11: norm_outflow = 46.5022f * norm_inflow + 0.4922f; break;
        case 12: norm_outflow = 43.9989f * norm_inflow + 0.4782f; break;
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
        case  2: norm_outflow = (norm_storage <= 1.0000f) ? 0.3574f * norm_storage + -0.1046f : 0.0000f * norm_storage + (0.3574f * 1.0000f + -0.1046f - 0.0000f * 1.0000f); break;
        case  3: norm_outflow = 0.9378f * norm_inflow + 0.0246f; break;
        case  4: norm_outflow = 0.7799f * norm_inflow + 0.0191f; break;
        case  5: norm_outflow = 0.6199f * norm_inflow + 0.0282f; break;
        case  6: norm_outflow = 0.8575f * norm_inflow + 0.0328f; break;
        case  7: norm_outflow = (norm_storage <= 1.0000f) ? 0.2757f * norm_storage + -0.0790f : 0.0000f * norm_storage + (0.2757f * 1.0000f + -0.0790f - 0.0000f * 1.0000f); break;
        case  8: norm_outflow = 0.7649f * norm_inflow + 0.0312f; break;
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
        case  1: norm_outflow = 0.0000f * norm_inflow + 0.0544f; break;
        case  2: norm_outflow = 16.2143f * norm_inflow + 0.0619f; break;
        case  3: norm_outflow = (norm_storage <= 1.0000f) ? 0.2509f * norm_storage + -0.1527f : 0.0000f * norm_storage + (0.2509f * 1.0000f + -0.1527f - 0.0000f * 1.0000f); break;
        case  4: norm_outflow = (norm_storage <= 1.0000f) ? 0.3097f * norm_storage + -0.2113f : 0.0000f * norm_storage + (0.3097f * 1.0000f + -0.2113f - 0.0000f * 1.0000f); break;
        case  5: norm_outflow = 0.3272f * norm_inflow + 0.0507f; break;
        case  6: norm_outflow = 0.4289f * norm_inflow + 0.0546f; break;
        case  7: norm_outflow = 0.0714f * norm_inflow + 0.0531f; break;
        case  8: norm_outflow = (norm_storage <= 1.0000f) ? 0.1099f * norm_storage + -0.0467f : 0.0000f * norm_storage + (0.1099f * 1.0000f + -0.0467f - 0.0000f * 1.0000f); break;
        case  9: norm_outflow = (norm_storage <= 1.0000f) ? 0.1042f * norm_storage + -0.0422f : 0.0000f * norm_storage + (0.1042f * 1.0000f + -0.0422f - 0.0000f * 1.0000f); break;
        case 10: norm_outflow = (norm_storage <= 1.0000f) ? 0.1176f * norm_storage + -0.0489f : 0.0000f * norm_storage + (0.1176f * 1.0000f + -0.0489f - 0.0000f * 1.0000f); break;
        case 11: norm_outflow = 17.7096f * norm_inflow + 0.0491f; break;
        case 12: norm_outflow = 19.5633f * norm_inflow + 0.0500f; break;
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
        case 11: norm_outflow = (norm_storage <= 0.7340f) ? 0.0233f * norm_storage + 0.0000f : 6.8231f * norm_storage + (0.0233f * 0.7340f + 0.0000f - 6.8231f * 0.7340f); break;
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
        case  1: norm_outflow = 0.5957f * norm_inflow + 0.0141f; break;
        case  2: norm_outflow = (norm_storage <= 1.0000f) ? 0.5602f * norm_storage + -0.3159f : 0.0000f * norm_storage + (0.5602f * 1.0000f + -0.3159f - 0.0000f * 1.0000f); break;
        case  3: norm_outflow = (norm_storage <= 0.6119f) ? 0.0039f * norm_storage + 0.0000f : 1.1845f * norm_storage + (0.0039f * 0.6119f + 0.0000f - 1.1845f * 0.6119f); break;
        case  4: norm_outflow = (norm_storage <= 0.6207f) ? 0.0011f * norm_storage + 0.0010f : 2.5918f * norm_storage + (0.0011f * 0.6207f + 0.0010f - 2.5918f * 0.6207f); break;
        case  5: norm_outflow = 0.8623f * norm_inflow + 0.0262f; break;
        case  6: norm_outflow = 0.4220f * norm_inflow + 0.0123f; break;
        case  7: norm_outflow = (norm_storage <= 0.6687f) ? 0.0233f * norm_storage + 0.0000f : 0.9245f * norm_storage + (0.0233f * 0.6687f + 0.0000f - 0.9245f * 0.6687f); break;
        case  8: norm_outflow = (norm_storage <= 0.6696f) ? 0.0339f * norm_storage + 0.0000f : 2.5740f * norm_storage + (0.0339f * 0.6696f + 0.0000f - 2.5740f * 0.6696f); break;
        case  9: norm_outflow = (norm_storage <= 0.6926f) ? 0.0199f * norm_storage + 0.0000f : 9.9497f * norm_storage + (0.0199f * 0.6926f + 0.0000f - 9.9497f * 0.6926f); break;
        case 10: norm_outflow = (norm_storage <= 0.6495f) ? 0.0129f * norm_storage + 0.0000f : 1.9747f * norm_storage + (0.0129f * 0.6495f + 0.0000f - 1.9747f * 0.6495f); break;
        case 11: norm_outflow = 0.9656f * norm_inflow + 0.0079f; break;
        case 12: norm_outflow = 1.0542f * norm_inflow + 0.0153f; break;
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
        case  8: norm_outflow = (norm_storage <= 0.8904f) ? 0.1000f * norm_storage + 0.0476f : 39.7223f * norm_storage + (0.1000f * 0.8904f + 0.0476f - 39.7223f * 0.8904f); break;
        case  9: norm_outflow = (norm_storage <= 1.0000f) ? 0.0798f * norm_storage + 0.0389f : 0.0000f * norm_storage + (0.0798f * 1.0000f + 0.0389f - 0.0000f * 1.0000f); break;
        case 10: norm_outflow = 0.1280f * norm_inflow + 0.0597f; break;
        case 11: norm_outflow = 0.0784f * norm_inflow + 0.0520f; break;
        case 12: norm_outflow = 0.5155f * norm_inflow + 0.0522f; break;
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
        case  1: norm_outflow = (norm_storage <= 1.0000f) ? 1.5879f * norm_storage + -0.3018f : 0.0000f * norm_storage + (1.5879f * 1.0000f + -0.3018f - 0.0000f * 1.0000f); break;
        case  2: norm_outflow = (norm_storage <= 1.0000f) ? 1.0505f * norm_storage + -0.1878f : 0.0000f * norm_storage + (1.0505f * 1.0000f + -0.1878f - 0.0000f * 1.0000f); break;
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
        case  1: norm_outflow = (norm_storage <= 0.6491f) ? 0.0700f * norm_storage + 0.0000f : 33.6479f * norm_storage + (0.0700f * 0.6491f + 0.0000f - 33.6479f * 0.6491f); break;
        case  2: norm_outflow = (norm_storage <= 0.6000f) ? 0.0673f * norm_storage + 0.0000f : 4.1916f * norm_storage + (0.0673f * 0.6000f + 0.0000f - 4.1916f * 0.6000f); break;
        case  3: norm_outflow = (norm_storage <= 0.6000f) ? 0.0692f * norm_storage + 0.0000f : 14.5509f * norm_storage + (0.0692f * 0.6000f + 0.0000f - 14.5509f * 0.6000f); break;
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
        case  1: norm_outflow = 0.8613f * norm_inflow + 0.0159f; break;
        case  2: norm_outflow = 0.1404f * norm_inflow + 0.0123f; break;
        case  3: norm_outflow = (norm_storage <= 0.6286f) ? 0.0231f * norm_storage + 0.0022f : 0.6597f * norm_storage + (0.0231f * 0.6286f + 0.0022f - 0.6597f * 0.6286f); break;
        case  4: norm_outflow = 0.3365f * norm_inflow + 0.0166f; break;
        case  5: norm_outflow = 0.2871f * norm_inflow + 0.0269f; break;
        case  6: norm_outflow = (norm_storage <= 0.6124f) ? 0.0000f * norm_storage + 0.0097f : 0.5518f * norm_storage + (0.0000f * 0.6124f + 0.0097f - 0.5518f * 0.6124f); break;
        case  7: norm_outflow = (norm_storage <= 0.6085f) ? 0.0000f * norm_storage + 0.0094f : 0.6134f * norm_storage + (0.0000f * 0.6085f + 0.0094f - 0.6134f * 0.6085f); break;
        case  8: norm_outflow = (norm_storage <= 0.6132f) ? 0.0000f * norm_storage + 0.0074f : 0.6536f * norm_storage + (0.0000f * 0.6132f + 0.0074f - 0.6536f * 0.6132f); break;
        case  9: norm_outflow = 0.2437f * norm_inflow + 0.0141f; break;
        case 10: norm_outflow = (norm_storage <= 0.6241f) ? 0.0000f * norm_storage + 0.0065f : 0.5304f * norm_storage + (0.0000f * 0.6241f + 0.0065f - 0.5304f * 0.6241f); break;
        case 11: norm_outflow = (norm_storage <= 0.6369f) ? 0.0000f * norm_storage + 0.0069f : 0.9972f * norm_storage + (0.0000f * 0.6369f + 0.0069f - 0.9972f * 0.6369f); break;
        case 12: norm_outflow = 0.2032f * norm_inflow + 0.0151f; break;
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
        case  1: norm_outflow = 0.3486f * norm_inflow + 0.0146f; break;
        case  2: norm_outflow = (norm_storage <= 1.0000f) ? 0.5972f * norm_storage + -0.0493f : 0.0000f * norm_storage + (0.5972f * 1.0000f + -0.0493f - 0.0000f * 1.0000f); break;
        case  3: norm_outflow = 0.1633f * norm_inflow + 0.0244f; break;
        case  4: norm_outflow = 0.4005f * norm_inflow + 0.0210f; break;
        case  5: norm_outflow = (norm_storage <= 1.0000f) ? 0.4164f * norm_storage + -0.0106f : 0.0000f * norm_storage + (0.4164f * 1.0000f + -0.0106f - 0.0000f * 1.0000f); break;
        case  6: norm_outflow = (norm_storage <= 1.0000f) ? 0.5871f * norm_storage + -0.0271f : 0.0000f * norm_storage + (0.5871f * 1.0000f + -0.0271f - 0.0000f * 1.0000f); break;
        case  7: norm_outflow = (norm_storage <= 1.0000f) ? 0.6949f * norm_storage + -0.0567f : 0.0000f * norm_storage + (0.6949f * 1.0000f + -0.0567f - 0.0000f * 1.0000f); break;
        case  8: norm_outflow = 1.2216f * norm_inflow + 0.0281f; break;
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
        case  1: norm_outflow = 0.4654f * norm_inflow + 0.0080f; break;
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
        case 12: norm_outflow = 0.8643f * norm_inflow + 0.0292f; break;
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
        case  1: norm_outflow = 0.5894f * norm_inflow + 0.0111f; break;
        case  2: norm_outflow = 0.2978f * norm_inflow + 0.0100f; break;
        case  3: norm_outflow = (norm_storage <= 1.0000f) ? 0.3243f * norm_storage + -0.0736f : 0.0000f * norm_storage + (0.3243f * 1.0000f + -0.0736f - 0.0000f * 1.0000f); break;
        case  4: norm_outflow = (norm_storage <= 1.0000f) ? 0.5674f * norm_storage + -0.1435f : 0.0000f * norm_storage + (0.5674f * 1.0000f + -0.1435f - 0.0000f * 1.0000f); break;
        case  5: norm_outflow = (norm_storage <= 1.0000f) ? 0.4202f * norm_storage + -0.0963f : 0.0000f * norm_storage + (0.4202f * 1.0000f + -0.0963f - 0.0000f * 1.0000f); break;
        case  6: norm_outflow = (norm_storage <= 1.0000f) ? 0.6009f * norm_storage + -0.1505f : 0.0000f * norm_storage + (0.6009f * 1.0000f + -0.1505f - 0.0000f * 1.0000f); break;
        case  7: norm_outflow = (norm_storage <= 1.0000f) ? 0.7521f * norm_storage + -0.1997f : 0.0000f * norm_storage + (0.7521f * 1.0000f + -0.1997f - 0.0000f * 1.0000f); break;
        case  8: norm_outflow = (norm_storage <= 1.0000f) ? 0.7321f * norm_storage + -0.1959f : 0.0000f * norm_storage + (0.7321f * 1.0000f + -0.1959f - 0.0000f * 1.0000f); break;
        case  9: norm_outflow = (norm_storage <= 1.0000f) ? 0.4389f * norm_storage + -0.1129f : 0.0000f * norm_storage + (0.4389f * 1.0000f + -0.1129f - 0.0000f * 1.0000f); break;
        case 10: norm_outflow = 0.2716f * norm_inflow + 0.0145f; break;
        case 11: norm_outflow = (norm_storage <= 1.0000f) ? 0.4818f * norm_storage + -0.1226f : 0.0000f * norm_storage + (0.4818f * 1.0000f + -0.1226f - 0.0000f * 1.0000f); break;
        case 12: norm_outflow = 0.4338f * norm_inflow + 0.0236f; break;
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
        case  1: norm_outflow = 0.3010f * norm_inflow + 0.0056f; break;
        case  2: norm_outflow = 0.3085f * norm_inflow + 0.0073f; break;
        case  3: norm_outflow = 0.4470f * norm_inflow + 0.0102f; break;
        case  4: norm_outflow = 0.3431f * norm_inflow + 0.0160f; break;
        case  5: norm_outflow = (norm_storage <= 1.0000f) ? 0.3364f * norm_storage + -0.1294f : 0.0000f * norm_storage + (0.3364f * 1.0000f + -0.1294f - 0.0000f * 1.0000f); break;
        case  6: norm_outflow = (norm_storage <= 0.6000f) ? 0.0509f * norm_storage + 0.0000f : 4.2284f * norm_storage + (0.0509f * 0.6000f + 0.0000f - 4.2284f * 0.6000f); break;
        case  7: norm_outflow = 0.5018f * norm_inflow + 0.0118f; break;
        case  8: norm_outflow = 0.2181f * norm_inflow + 0.0094f; break;
        case  9: norm_outflow = 0.4259f * norm_inflow + 0.0089f; break;
        case 10: norm_outflow = (norm_storage <= 0.6000f) ? 0.0199f * norm_storage + 0.0000f : 4.1727f * norm_storage + (0.0199f * 0.6000f + 0.0000f - 4.1727f * 0.6000f); break;
        case 11: norm_outflow = 0.3327f * norm_inflow + 0.0061f; break;
        case 12: norm_outflow = 0.2367f * norm_inflow + 0.0071f; break;
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
        case  4: norm_outflow = (norm_storage <= 0.6062f) ? 0.0243f * norm_storage + 0.0000f : 6.4499f * norm_storage + (0.0243f * 0.6062f + 0.0000f - 6.4499f * 0.6062f); break;
        case  5: norm_outflow = (norm_storage <= 0.6000f) ? 0.0333f * norm_storage + 0.0000f : 4.1525f * norm_storage + (0.0333f * 0.6000f + 0.0000f - 4.1525f * 0.6000f); break;
        case  6: norm_outflow = (norm_storage <= 0.6047f) ? 0.0260f * norm_storage + 0.0000f : 6.0065f * norm_storage + (0.0260f * 0.6047f + 0.0000f - 6.0065f * 0.6047f); break;
        case  7: norm_outflow = (norm_storage <= 0.6050f) ? 0.0151f * norm_storage + 0.0000f : 6.4895f * norm_storage + (0.0151f * 0.6050f + 0.0000f - 6.4895f * 0.6050f); break;
        case  8: norm_outflow = (norm_storage <= 0.6040f) ? 0.0135f * norm_storage + 0.0000f : 5.1180f * norm_storage + (0.0135f * 0.6040f + 0.0000f - 5.1180f * 0.6040f); break;
        case  9: norm_outflow = (norm_storage <= 0.6040f) ? 0.0165f * norm_storage + 0.0005f : 6.2070f * norm_storage + (0.0165f * 0.6040f + 0.0005f - 6.2070f * 0.6040f); break;
        case 10: norm_outflow = (norm_storage <= 0.6058f) ? 0.0000f * norm_storage + 0.0118f : 6.2259f * norm_storage + (0.0000f * 0.6058f + 0.0118f - 6.2259f * 0.6058f); break;
        case 11: norm_outflow = (norm_storage <= 0.6063f) ? 0.0000f * norm_storage + 0.0118f : 6.1148f * norm_storage + (0.0000f * 0.6063f + 0.0118f - 6.1148f * 0.6063f); break;
        case 12: norm_outflow = (norm_storage <= 0.6061f) ? 0.0154f * norm_storage + 0.0000f : 6.4168f * norm_storage + (0.0154f * 0.6061f + 0.0000f - 6.4168f * 0.6061f); break;
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
        case  1: norm_outflow = 2.6236f * norm_inflow + 0.0141f; break;
        case  2: norm_outflow = (norm_storage <= 1.0000f) ? 0.3864f * norm_storage + -0.1503f : 0.0000f * norm_storage + (0.3864f * 1.0000f + -0.1503f - 0.0000f * 1.0000f); break;
        case  3: norm_outflow = (norm_storage <= 1.0000f) ? 0.5659f * norm_storage + -0.2246f : 0.0000f * norm_storage + (0.5659f * 1.0000f + -0.2246f - 0.0000f * 1.0000f); break;
        case  4: norm_outflow = (norm_storage <= 1.0000f) ? 0.6419f * norm_storage + -0.2668f : 0.0000f * norm_storage + (0.6419f * 1.0000f + -0.2668f - 0.0000f * 1.0000f); break;
        case  5: norm_outflow = (norm_storage <= 1.0000f) ? 0.7356f * norm_storage + -0.3075f : 0.0000f * norm_storage + (0.7356f * 1.0000f + -0.3075f - 0.0000f * 1.0000f); break;
        case  6: norm_outflow = (norm_storage <= 1.0000f) ? 0.7080f * norm_storage + -0.2949f : 0.0000f * norm_storage + (0.7080f * 1.0000f + -0.2949f - 0.0000f * 1.0000f); break;
        case  7: norm_outflow = (norm_storage <= 1.0000f) ? 0.5233f * norm_storage + -0.2149f : 0.0000f * norm_storage + (0.5233f * 1.0000f + -0.2149f - 0.0000f * 1.0000f); break;
        case  8: norm_outflow = (norm_storage <= 1.0000f) ? 0.5409f * norm_storage + -0.2327f : 0.0000f * norm_storage + (0.5409f * 1.0000f + -0.2327f - 0.0000f * 1.0000f); break;
        case  9: norm_outflow = (norm_storage <= 1.0000f) ? 0.4686f * norm_storage + -0.2010f : 0.0000f * norm_storage + (0.4686f * 1.0000f + -0.2010f - 0.0000f * 1.0000f); break;
        case 10: norm_outflow = (norm_storage <= 1.0000f) ? 0.6865f * norm_storage + -0.2969f : 0.0000f * norm_storage + (0.6865f * 1.0000f + -0.2969f - 0.0000f * 1.0000f); break;
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
        case  1: norm_outflow = (norm_storage <= 1.0000f) ? 0.1151f * norm_storage + -0.0051f : 0.0000f * norm_storage + (0.1151f * 1.0000f + -0.0051f - 0.0000f * 1.0000f); break;
        case  2: norm_outflow = (norm_storage <= 1.0000f) ? 0.6105f * norm_storage + -0.0633f : 0.0000f * norm_storage + (0.6105f * 1.0000f + -0.0633f - 0.0000f * 1.0000f); break;
        case  3: norm_outflow = (norm_storage <= 1.0000f) ? 0.6537f * norm_storage + -0.0705f : 0.0000f * norm_storage + (0.6537f * 1.0000f + -0.0705f - 0.0000f * 1.0000f); break;
        case  4: norm_outflow = (norm_storage <= 1.0000f) ? 0.7890f * norm_storage + -0.0871f : 0.0000f * norm_storage + (0.7890f * 1.0000f + -0.0871f - 0.0000f * 1.0000f); break;
        case  5: norm_outflow = (norm_storage <= 1.0000f) ? 1.1852f * norm_storage + -0.1442f : 0.0000f * norm_storage + (1.1852f * 1.0000f + -0.1442f - 0.0000f * 1.0000f); break;
        case  6: norm_outflow = (norm_storage <= 1.0000f) ? 1.5662f * norm_storage + -0.2015f : 0.0000f * norm_storage + (1.5662f * 1.0000f + -0.2015f - 0.0000f * 1.0000f); break;
        case  7: norm_outflow = (norm_storage <= 1.0000f) ? 0.9283f * norm_storage + -0.1191f : 0.0000f * norm_storage + (0.9283f * 1.0000f + -0.1191f - 0.0000f * 1.0000f); break;
        case  8: norm_outflow = (norm_storage <= 1.0000f) ? 1.1523f * norm_storage + -0.1340f : 0.0000f * norm_storage + (1.1523f * 1.0000f + -0.1340f - 0.0000f * 1.0000f); break;
        case  9: norm_outflow = (norm_storage <= 1.0000f) ? 1.0689f * norm_storage + -0.1225f : 0.0000f * norm_storage + (1.0689f * 1.0000f + -0.1225f - 0.0000f * 1.0000f); break;
        case 10: norm_outflow = 0.9015f * norm_inflow + 0.0111f; break;
        case 11: norm_outflow = 0.9018f * norm_inflow + 0.0077f; break;
        case 12: norm_outflow = (norm_storage <= 1.0000f) ? 0.3498f * norm_storage + -0.0306f : 0.0000f * norm_storage + (0.3498f * 1.0000f + -0.0306f - 0.0000f * 1.0000f); break;
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
        case  1: norm_outflow = 0.1797f * norm_inflow + 0.0044f; break;
        case  2: norm_outflow = (norm_storage <= 0.6000f) ? 0.0180f * norm_storage + 0.0000f : 4.3525f * norm_storage + (0.0180f * 0.6000f + 0.0000f - 4.3525f * 0.6000f); break;
        case  3: norm_outflow = (norm_storage <= 0.6000f) ? 0.0212f * norm_storage + 0.0000f : 2.6812f * norm_storage + (0.0212f * 0.6000f + 0.0000f - 2.6812f * 0.6000f); break;
        case  4: norm_outflow = (norm_storage <= 0.6000f) ? 0.0292f * norm_storage + 0.0000f : 3.1834f * norm_storage + (0.0292f * 0.6000f + 0.0000f - 3.1834f * 0.6000f); break;
        case  5: norm_outflow = (norm_storage <= 1.0000f) ? 0.5245f * norm_storage + -0.2446f : 0.0000f * norm_storage + (0.5245f * 1.0000f + -0.2446f - 0.0000f * 1.0000f); break;
        case  6: norm_outflow = (norm_storage <= 1.0000f) ? 0.3932f * norm_storage + -0.1823f : 0.0000f * norm_storage + (0.3932f * 1.0000f + -0.1823f - 0.0000f * 1.0000f); break;
        case  7: norm_outflow = (norm_storage <= 0.6000f) ? 0.0297f * norm_storage + 0.0000f : 1.3970f * norm_storage + (0.0297f * 0.6000f + 0.0000f - 1.3970f * 0.6000f); break;
        case  8: norm_outflow = (norm_storage <= 0.6000f) ? 0.0199f * norm_storage + 0.0000f : 1.2320f * norm_storage + (0.0199f * 0.6000f + 0.0000f - 1.2320f * 0.6000f); break;
        case  9: norm_outflow = (norm_storage <= 0.6000f) ? 0.0111f * norm_storage + 0.0000f : 3.2225f * norm_storage + (0.0111f * 0.6000f + 0.0000f - 3.2225f * 0.6000f); break;
        case 10: norm_outflow = (norm_storage <= 0.6000f) ? 0.0134f * norm_storage + 0.0000f : 1.1227f * norm_storage + (0.0134f * 0.6000f + 0.0000f - 1.1227f * 0.6000f); break;
        case 11: norm_outflow = (norm_storage <= 0.6000f) ? 0.0123f * norm_storage + 0.0000f : 1.0544f * norm_storage + (0.0123f * 0.6000f + 0.0000f - 1.0544f * 0.6000f); break;
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
        case  1: norm_outflow = 0.0922f * norm_inflow + 0.0109f; break;
        case  2: norm_outflow = (norm_storage <= 0.9724f) ? 0.0000f * norm_storage + 0.0143f : 0.9164f * norm_storage + (0.0000f * 0.9724f + 0.0143f - 0.9164f * 0.9724f); break;
        case  3: norm_outflow = 0.2059f * norm_inflow + 0.0271f; break;
        case  4: norm_outflow = (norm_storage <= 1.0000f) ? 0.1012f * norm_storage + -0.0103f : 0.0000f * norm_storage + (0.1012f * 1.0000f + -0.0103f - 0.0000f * 1.0000f); break;
        case  5: norm_outflow = 0.3674f * norm_inflow + 0.0691f; break;
        case  6: norm_outflow = 1.6636f * norm_inflow + -0.0854f; break;
        case  7: norm_outflow = 0.9812f * norm_inflow + -0.0379f; break;
        case  8: norm_outflow = 0.4285f * norm_inflow + 0.0259f; break;
        case  9: norm_outflow = 0.4073f * norm_inflow + -0.0005f; break;
        case 10: norm_outflow = 0.1020f * norm_inflow + 0.0257f; break;
        case 11: norm_outflow = 0.3420f * norm_inflow + 0.0051f; break;
        case 12: norm_outflow = 0.1210f * norm_inflow + 0.0092f; break;
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
        case  1: norm_outflow = 3.8337f * norm_inflow + 0.0848f; break;
        case  2: norm_outflow = 1.9504f * norm_inflow + 0.1260f; break;
        case  3: norm_outflow = (norm_storage <= 1.0000f) ? -0.8156f * norm_storage + 0.8233f : 0.0000f * norm_storage + (-0.8156f * 1.0000f + 0.8233f - 0.0000f * 1.0000f); break;
        case  4: norm_outflow = 2.5439f * norm_inflow + 0.0398f; break;
        case  5: norm_outflow = 1.1799f * norm_inflow + 0.1614f; break;
        case  6: norm_outflow = 1.5630f * norm_inflow + 0.2267f; break;
        case  7: norm_outflow = 3.3009f * norm_inflow + 0.0886f; break;
        case  8: norm_outflow = 1.7034f * norm_inflow + 0.0662f; break;
        case  9: norm_outflow = 1.3439f * norm_inflow + 0.0617f; break;
        case 10: norm_outflow = 1.1864f * norm_inflow + 0.0717f; break;
        case 11: norm_outflow = 2.0292f * norm_inflow + 0.0516f; break;
        case 12: norm_outflow = 2.2227f * norm_inflow + 0.0663f; break;
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
        case  1: norm_outflow = (norm_storage <= 0.7504f) ? 0.0012f * norm_storage + 0.0004f : 44.8358f * norm_storage + (0.0012f * 0.7504f + 0.0004f - 44.8358f * 0.7504f); break;
        case  2: norm_outflow = (norm_storage <= 0.6785f) ? 0.0050f * norm_storage + 0.0000f : 0.9923f * norm_storage + (0.0050f * 0.6785f + 0.0000f - 0.9923f * 0.6785f); break;
        case  3: norm_outflow = (norm_storage <= 0.6000f) ? 0.0135f * norm_storage + 0.0020f : 0.7261f * norm_storage + (0.0135f * 0.6000f + 0.0020f - 0.7261f * 0.6000f); break;
        case  4: norm_outflow = (norm_storage <= 1.0000f) ? 0.1821f * norm_storage + 0.0577f : 0.0000f * norm_storage + (0.1821f * 1.0000f + 0.0577f - 0.0000f * 1.0000f); break;
        case  5: norm_outflow = (norm_storage <= 0.7367f) ? 0.1000f * norm_storage + 0.1163f : 2.7971f * norm_storage + (0.1000f * 0.7367f + 0.1163f - 2.7971f * 0.7367f); break;
        case  6: norm_outflow = (norm_storage <= 0.6990f) ? 0.1000f * norm_storage + 0.1685f : 4.4741f * norm_storage + (0.1000f * 0.6990f + 0.1685f - 4.4741f * 0.6990f); break;
        case  7: norm_outflow = (norm_storage <= 0.7483f) ? 0.1000f * norm_storage + 0.2091f : 12.6329f * norm_storage + (0.1000f * 0.7483f + 0.2091f - 12.6329f * 0.7483f); break;
        case  8: norm_outflow = (norm_storage <= 0.7587f) ? 0.1000f * norm_storage + 0.1014f : 28.5190f * norm_storage + (0.1000f * 0.7587f + 0.1014f - 28.5190f * 0.7587f); break;
        case  9: norm_outflow = 0.7743f * norm_inflow + 0.0401f; break;
        case 10: norm_outflow = 0.5460f * norm_inflow + 0.0307f; break;
        case 11: norm_outflow = (norm_storage <= 1.0000f) ? 0.0327f * norm_storage + -0.0017f : 0.0000f * norm_storage + (0.0327f * 1.0000f + -0.0017f - 0.0000f * 1.0000f); break;
        case 12: norm_outflow = (norm_storage <= 0.7479f) ? 0.0022f * norm_storage + 0.0002f : 25.9901f * norm_storage + (0.0022f * 0.7479f + 0.0002f - 25.9901f * 0.7479f); break;
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
        case  8: norm_outflow = (norm_storage <= 0.6823f) ? 0.0069f * norm_storage + 0.0000f : 2.9573f * norm_storage + (0.0069f * 0.6823f + 0.0000f - 2.9573f * 0.6823f); break;
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
        case  9: norm_outflow = 0.0231f * norm_inflow + 0.0967f; break;
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
        case  1: norm_outflow = (norm_storage <= 0.6339f) ? 0.0101f * norm_storage + 0.0000f : 6.2854f * norm_storage + (0.0101f * 0.6339f + 0.0000f - 6.2854f * 0.6339f); break;
        case  2: norm_outflow = (norm_storage <= 0.6380f) ? 0.0144f * norm_storage + 0.0000f : 7.9823f * norm_storage + (0.0144f * 0.6380f + 0.0000f - 7.9823f * 0.6380f); break;
        case  3: norm_outflow = (norm_storage <= 0.6382f) ? 0.0225f * norm_storage + 0.0000f : 6.6489f * norm_storage + (0.0225f * 0.6382f + 0.0000f - 6.6489f * 0.6382f); break;
        case  4: norm_outflow = (norm_storage <= 0.6351f) ? 0.0146f * norm_storage + 0.0008f : 6.4795f * norm_storage + (0.0146f * 0.6351f + 0.0008f - 6.4795f * 0.6351f); break;
        case  5: norm_outflow = 1.6754f * norm_inflow + 0.0270f; break;
        case  6: norm_outflow = (norm_storage <= 0.6369f) ? 0.0188f * norm_storage + 0.0000f : 7.2201f * norm_storage + (0.0188f * 0.6369f + 0.0000f - 7.2201f * 0.6369f); break;
        case  7: norm_outflow = (norm_storage <= 0.6315f) ? 0.0027f * norm_storage + 0.0000f : 4.9022f * norm_storage + (0.0027f * 0.6315f + 0.0000f - 4.9022f * 0.6315f); break;
        case  8: norm_outflow = 1.5811f * norm_inflow + 0.0061f; break;
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
        case  1: norm_outflow = 0.0000f * norm_inflow + 0.0018f; break;
        case  2: norm_outflow = 0.0606f * norm_inflow + 0.0018f; break;
        case  3: norm_outflow = 0.0467f * norm_inflow + 0.0018f; break;
        case  4: norm_outflow = (norm_storage <= 1.0000f) ? 0.1127f * norm_storage + -0.0097f : 0.0000f * norm_storage + (0.1127f * 1.0000f + -0.0097f - 0.0000f * 1.0000f); break;
        case  5: norm_outflow = 0.2935f * norm_inflow + 0.1353f; break;
        case  6: norm_outflow = 1.8932f * norm_inflow + 0.0711f; break;
        case  7: norm_outflow = 1.3446f * norm_inflow + 0.0753f; break;
        case  8: norm_outflow = 1.4270f * norm_inflow + 0.0756f; break;
        case  9: norm_outflow = (norm_storage <= 1.0000f) ? 0.1531f * norm_storage + 0.0471f : 0.0000f * norm_storage + (0.1531f * 1.0000f + 0.0471f - 0.0000f * 1.0000f); break;
        case 10: norm_outflow = 1.1092f * norm_inflow + 0.0022f; break;
        case 11: norm_outflow = 0.0270f * norm_inflow + 0.0018f; break;
        case 12: norm_outflow = 0.0000f * norm_inflow + 0.0014f; break;
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
        case 12: norm_outflow = 0.8751f * norm_inflow + 0.0662f; break;
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
        case  2: norm_outflow = (norm_storage <= 1.0000f) ? 0.0520f * norm_storage + -0.0025f : 0.0000f * norm_storage + (0.0520f * 1.0000f + -0.0025f - 0.0000f * 1.0000f); break;
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
        case  1: norm_outflow = (norm_storage <= 1.0000f) ? 0.6370f * norm_storage + -0.0892f : 0.0000f * norm_storage + (0.6370f * 1.0000f + -0.0892f - 0.0000f * 1.0000f); break;
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
        case 12: norm_outflow = (norm_storage <= 1.0000f) ? 0.7138f * norm_storage + -0.0978f : 0.0000f * norm_storage + (0.7138f * 1.0000f + -0.0978f - 0.0000f * 1.0000f); break;
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
        case  1: norm_outflow = 0.5725f * norm_inflow + 0.0111f; break;
        case  2: norm_outflow = 0.8638f * norm_inflow + 0.0042f; break;
        case  3: norm_outflow = 0.7102f * norm_inflow + 0.0059f; break;
        case  4: norm_outflow = 0.6210f * norm_inflow + 0.0096f; break;
        case  5: norm_outflow = (norm_storage <= 0.7869f) ? 0.1000f * norm_storage + 0.0128f : 3.9387f * norm_storage + (0.1000f * 0.7869f + 0.0128f - 3.9387f * 0.7869f); break;
        case  6: norm_outflow = (norm_storage <= 1.0000f) ? 0.2959f * norm_storage + -0.0624f : 0.0000f * norm_storage + (0.2959f * 1.0000f + -0.0624f - 0.0000f * 1.0000f); break;
        case  7: norm_outflow = (norm_storage <= 1.0000f) ? 0.4182f * norm_storage + -0.1027f : 0.0000f * norm_storage + (0.4182f * 1.0000f + -0.1027f - 0.0000f * 1.0000f); break;
        case  8: norm_outflow = 0.3983f * norm_inflow + 0.0152f; break;
        case  9: norm_outflow = 0.3883f * norm_inflow + 0.0083f; break;
        case 10: norm_outflow = (norm_storage <= 1.0000f) ? 1.1191f * norm_storage + -0.2967f : 0.0000f * norm_storage + (1.1191f * 1.0000f + -0.2967f - 0.0000f * 1.0000f); break;
        case 11: norm_outflow = (norm_storage <= 1.0000f) ? 0.5856f * norm_storage + -0.1510f : 0.0000f * norm_storage + (0.5856f * 1.0000f + -0.1510f - 0.0000f * 1.0000f); break;
        case 12: norm_outflow = 0.2089f * norm_inflow + 0.0061f; break;
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
        case  3: norm_outflow = (norm_storage <= 0.6615f) ? 0.0048f * norm_storage + 0.0114f : 1.5004f * norm_storage + (0.0048f * 0.6615f + 0.0114f - 1.5004f * 0.6615f); break;
        case  4: norm_outflow = (norm_storage <= 0.6708f) ? 0.0210f * norm_storage + 0.0000f : 1.7369f * norm_storage + (0.0210f * 0.6708f + 0.0000f - 1.7369f * 0.6708f); break;
        case  5: norm_outflow = 1.3454f * norm_inflow + 0.0376f; break;
        case  6: norm_outflow = 1.2307f * norm_inflow + 0.0382f; break;
        case  7: norm_outflow = 0.8423f * norm_inflow + 0.0479f; break;
        case  8: norm_outflow = 1.3591f * norm_inflow + 0.0432f; break;
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
        case  1: norm_outflow = (norm_storage <= 1.0000f) ? 0.2681f * norm_storage + -0.0989f : 0.0000f * norm_storage + (0.2681f * 1.0000f + -0.0989f - 0.0000f * 1.0000f); break;
        case  2: norm_outflow = 0.0000f * norm_inflow + 0.0436f; break;
        case  3: norm_outflow = (norm_storage <= 1.0000f) ? 0.5085f * norm_storage + -0.2021f : 0.0000f * norm_storage + (0.5085f * 1.0000f + -0.2021f - 0.0000f * 1.0000f); break;
        case  4: norm_outflow = (norm_storage <= 1.0000f) ? 0.7152f * norm_storage + -0.3024f : 0.0000f * norm_storage + (0.7152f * 1.0000f + -0.3024f - 0.0000f * 1.0000f); break;
        case  5: norm_outflow = (norm_storage <= 1.0000f) ? 1.0602f * norm_storage + -0.4786f : 0.0000f * norm_storage + (1.0602f * 1.0000f + -0.4786f - 0.0000f * 1.0000f); break;
        case  6: norm_outflow = (norm_storage <= 1.0000f) ? 1.3034f * norm_storage + -0.6035f : 0.0000f * norm_storage + (1.3034f * 1.0000f + -0.6035f - 0.0000f * 1.0000f); break;
        case  7: norm_outflow = 0.1116f * norm_inflow + 0.0139f; break;
        case  8: norm_outflow = 0.2620f * norm_inflow + 0.0057f; break;
        case  9: norm_outflow = (norm_storage <= 0.6779f) ? 0.0204f * norm_storage + 0.0000f : 1.9500f * norm_storage + (0.0204f * 0.6779f + 0.0000f - 1.9500f * 0.6779f); break;
        case 10: norm_outflow = (norm_storage <= 1.0000f) ? 0.5340f * norm_storage + -0.2204f : 0.0000f * norm_storage + (0.5340f * 1.0000f + -0.2204f - 0.0000f * 1.0000f); break;
        case 11: norm_outflow = 0.4407f * norm_inflow + 0.0166f; break;
        case 12: norm_outflow = (norm_storage <= 1.0000f) ? 0.2237f * norm_storage + -0.0849f : 0.0000f * norm_storage + (0.2237f * 1.0000f + -0.0849f - 0.0000f * 1.0000f); break;
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
        case  1: norm_outflow = 0.7911f * norm_inflow + 0.0145f; break;
        case  2: norm_outflow = 0.5774f * norm_inflow + 0.0139f; break;
        case  3: norm_outflow = 0.6724f * norm_inflow + 0.0114f; break;
        case  4: norm_outflow = 0.6925f * norm_inflow + 0.0219f; break;
        case  5: norm_outflow = 0.7577f * norm_inflow + 0.0279f; break;
        case  6: norm_outflow = 0.7096f * norm_inflow + 0.0335f; break;
        case  7: norm_outflow = 0.9236f * norm_inflow + 0.0214f; break;
        case  8: norm_outflow = 0.5141f * norm_inflow + 0.0222f; break;
        case  9: norm_outflow = 0.4242f * norm_inflow + 0.0177f; break;
        case 10: norm_outflow = 0.5436f * norm_inflow + 0.0140f; break;
        case 11: norm_outflow = 0.5558f * norm_inflow + 0.0086f; break;
        case 12: norm_outflow = 0.8082f * norm_inflow + 0.0032f; break;
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
        case  1: norm_outflow = 4.0607f * norm_inflow + 0.0099f; break;
        case  2: norm_outflow = 2.3280f * norm_inflow + 0.0102f; break;
        case  3: norm_outflow = 1.3092f * norm_inflow + 0.0210f; break;
        case  4: norm_outflow = (norm_storage <= 1.0000f) ? 0.4854f * norm_storage + -0.1088f : 0.0000f * norm_storage + (0.4854f * 1.0000f + -0.1088f - 0.0000f * 1.0000f); break;
        case  5: norm_outflow = (norm_storage <= 1.0000f) ? 0.7333f * norm_storage + -0.1881f : 0.0000f * norm_storage + (0.7333f * 1.0000f + -0.1881f - 0.0000f * 1.0000f); break;
        case  6: norm_outflow = (norm_storage <= 1.0000f) ? 0.6696f * norm_storage + -0.1656f : 0.0000f * norm_storage + (0.6696f * 1.0000f + -0.1656f - 0.0000f * 1.0000f); break;
        case  7: norm_outflow = (norm_storage <= 1.0000f) ? 0.8314f * norm_storage + -0.2268f : 0.0000f * norm_storage + (0.8314f * 1.0000f + -0.2268f - 0.0000f * 1.0000f); break;
        case  8: norm_outflow = (norm_storage <= 1.0000f) ? 1.0320f * norm_storage + -0.2862f : 0.0000f * norm_storage + (1.0320f * 1.0000f + -0.2862f - 0.0000f * 1.0000f); break;
        case  9: norm_outflow = (norm_storage <= 1.0000f) ? 0.8742f * norm_storage + -0.2410f : 0.0000f * norm_storage + (0.8742f * 1.0000f + -0.2410f - 0.0000f * 1.0000f); break;
        case 10: norm_outflow = (norm_storage <= 1.0000f) ? 1.0212f * norm_storage + -0.2771f : 0.0000f * norm_storage + (1.0212f * 1.0000f + -0.2771f - 0.0000f * 1.0000f); break;
        case 11: norm_outflow = (norm_storage <= 1.0000f) ? 0.7109f * norm_storage + -0.1852f : 0.0000f * norm_storage + (0.7109f * 1.0000f + -0.1852f - 0.0000f * 1.0000f); break;
        case 12: norm_outflow = 0.4371f * norm_inflow + 0.0082f; break;
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
        case  4: norm_outflow = (norm_storage <= 0.9492f) ? 0.0191f * norm_storage + 0.0000f : 15.0484f * norm_storage + (0.0191f * 0.9492f + 0.0000f - 15.0484f * 0.9492f); break;
        case  5: norm_outflow = 0.4185f * norm_inflow + 0.0111f; break;
        case  6: norm_outflow = 0.3892f * norm_inflow + 0.0142f; break;
        case  7: norm_outflow = 0.4361f * norm_inflow + 0.0114f; break;
        case  8: norm_outflow = (norm_storage <= 1.0000f) ? 0.0378f * norm_storage + -0.0180f : 0.0000f * norm_storage + (0.0378f * 1.0000f + -0.0180f - 0.0000f * 1.0000f); break;
        case  9: norm_outflow = (norm_storage <= 1.0000f) ? 0.0682f * norm_storage + -0.0446f : 0.0000f * norm_storage + (0.0682f * 1.0000f + -0.0446f - 0.0000f * 1.0000f); break;
        case 10: norm_outflow = (norm_storage <= 1.0000f) ? 0.0622f * norm_storage + -0.0408f : 0.0000f * norm_storage + (0.0622f * 1.0000f + -0.0408f - 0.0000f * 1.0000f); break;
        case 11: norm_outflow = (norm_storage <= 1.0000f) ? 0.0478f * norm_storage + -0.0303f : 0.0000f * norm_storage + (0.0478f * 1.0000f + -0.0303f - 0.0000f * 1.0000f); break;
        case 12: norm_outflow = (norm_storage <= 0.9378f) ? 0.0154f * norm_storage + 0.0000f : 15.0115f * norm_storage + (0.0154f * 0.9378f + 0.0000f - 15.0115f * 0.9378f); break;
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
        case  1: norm_outflow = 0.5761f * norm_inflow + 0.0038f; break;
        case  2: norm_outflow = 0.4683f * norm_inflow + 0.0041f; break;
        case  3: norm_outflow = 0.5251f * norm_inflow + 0.0049f; break;
        case  4: norm_outflow = 0.4888f * norm_inflow + 0.0093f; break;
        case  5: norm_outflow = 0.5139f * norm_inflow + 0.0096f; break;
        case  6: norm_outflow = 0.5368f * norm_inflow + 0.0068f; break;
        case  7: norm_outflow = 0.6331f * norm_inflow + 0.0051f; break;
        case  8: norm_outflow = 2.7874f * norm_inflow + 0.0041f; break;
        case  9: norm_outflow = 0.4957f * norm_inflow + 0.0037f; break;
        case 10: norm_outflow = 0.5387f * norm_inflow + 0.0045f; break;
        case 11: norm_outflow = 0.3382f * norm_inflow + 0.0036f; break;
        case 12: norm_outflow = (norm_storage <= 0.8879f) ? 0.0068f * norm_storage + 0.0000f : 7.3889f * norm_storage + (0.0068f * 0.8879f + 0.0000f - 7.3889f * 0.8879f); break;
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
        case  2: norm_outflow = (norm_storage <= 0.6197f) ? 0.0115f * norm_storage + 0.0046f : 8.9785f * norm_storage + (0.0115f * 0.6197f + 0.0046f - 8.9785f * 0.6197f); break;
        case  3: norm_outflow = (norm_storage <= 0.6130f) ? 0.0000f * norm_storage + 0.0072f : 5.2221f * norm_storage + (0.0000f * 0.6130f + 0.0072f - 5.2221f * 0.6130f); break;
        case  4: norm_outflow = (norm_storage <= 0.6000f) ? 0.0616f * norm_storage + 0.0000f : 2.7326f * norm_storage + (0.0616f * 0.6000f + 0.0000f - 2.7326f * 0.6000f); break;
        case  5: norm_outflow = (norm_storage <= 0.6000f) ? 0.0356f * norm_storage + 0.0031f : 1.7409f * norm_storage + (0.0356f * 0.6000f + 0.0031f - 1.7409f * 0.6000f); break;
        case  6: norm_outflow = (norm_storage <= 0.6000f) ? 0.0544f * norm_storage + 0.0000f : 1.5501f * norm_storage + (0.0544f * 0.6000f + 0.0000f - 1.5501f * 0.6000f); break;
        case  7: norm_outflow = (norm_storage <= 0.6000f) ? 0.0266f * norm_storage + 0.0167f : 1.5887f * norm_storage + (0.0266f * 0.6000f + 0.0167f - 1.5887f * 0.6000f); break;
        case  8: norm_outflow = (norm_storage <= 0.6131f) ? 0.0000f * norm_storage + 0.0263f : 5.7847f * norm_storage + (0.0000f * 0.6131f + 0.0263f - 5.7847f * 0.6131f); break;
        case  9: norm_outflow = 1.6164f * norm_inflow + 0.0316f; break;
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
        case  4: norm_outflow = (norm_storage <= 0.9665f) ? 0.0623f * norm_storage + 0.0000f : 28.9573f * norm_storage + (0.0623f * 0.9665f + 0.0000f - 28.9573f * 0.9665f); break;
        case  5: norm_outflow = (norm_storage <= 0.9529f) ? 0.0470f * norm_storage + 0.0000f : 12.4278f * norm_storage + (0.0470f * 0.9529f + 0.0000f - 12.4278f * 0.9529f); break;
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
        case  1: norm_outflow = (norm_storage <= 1.0000f) ? 0.5545f * norm_storage + -0.2352f : 0.0000f * norm_storage + (0.5545f * 1.0000f + -0.2352f - 0.0000f * 1.0000f); break;
        case  2: norm_outflow = 0.8191f * norm_inflow + 0.0144f; break;
        case  3: norm_outflow = 0.7903f * norm_inflow + 0.0129f; break;
        case  4: norm_outflow = 0.8577f * norm_inflow + 0.0219f; break;
        case  5: norm_outflow = 0.8806f * norm_inflow + 0.0325f; break;
        case  6: norm_outflow = 0.8024f * norm_inflow + 0.0370f; break;
        case  7: norm_outflow = 1.0849f * norm_inflow + 0.0258f; break;
        case  8: norm_outflow = 0.6021f * norm_inflow + 0.0254f; break;
        case  9: norm_outflow = 0.5411f * norm_inflow + 0.0202f; break;
        case 10: norm_outflow = 0.6365f * norm_inflow + 0.0169f; break;
        case 11: norm_outflow = 0.8704f * norm_inflow + 0.0075f; break;
        case 12: norm_outflow = 0.8629f * norm_inflow + 0.0055f; break;
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
        case  1: norm_outflow = (norm_storage <= 1.0000f) ? 0.2195f * norm_storage + -0.0446f : 0.0000f * norm_storage + (0.2195f * 1.0000f + -0.0446f - 0.0000f * 1.0000f); break;
        case  2: norm_outflow = (norm_storage <= 1.0000f) ? 0.2385f * norm_storage + -0.0465f : 0.0000f * norm_storage + (0.2385f * 1.0000f + -0.0465f - 0.0000f * 1.0000f); break;
        case  3: norm_outflow = 0.3102f * norm_inflow + 0.0091f; break;
        case  4: norm_outflow = 0.2976f * norm_inflow + 0.0189f; break;
        case  5: norm_outflow = (norm_storage <= 0.7167f) ? 0.1000f * norm_storage + 0.0188f : 3.2008f * norm_storage + (0.1000f * 0.7167f + 0.0188f - 3.2008f * 0.7167f); break;
        case  6: norm_outflow = 0.4239f * norm_inflow + 0.0236f; break;
        case  7: norm_outflow = (norm_storage <= 1.0000f) ? 0.3250f * norm_storage + -0.0684f : 0.0000f * norm_storage + (0.3250f * 1.0000f + -0.0684f - 0.0000f * 1.0000f); break;
        case  8: norm_outflow = 0.2939f * norm_inflow + 0.0145f; break;
        case  9: norm_outflow = (norm_storage <= 1.0000f) ? 0.4577f * norm_storage + -0.1032f : 0.0000f * norm_storage + (0.4577f * 1.0000f + -0.1032f - 0.0000f * 1.0000f); break;
        case 10: norm_outflow = (norm_storage <= 1.0000f) ? 0.6138f * norm_storage + -0.1439f : 0.0000f * norm_storage + (0.6138f * 1.0000f + -0.1439f - 0.0000f * 1.0000f); break;
        case 11: norm_outflow = (norm_storage <= 1.0000f) ? 0.3599f * norm_storage + -0.0815f : 0.0000f * norm_storage + (0.3599f * 1.0000f + -0.0815f - 0.0000f * 1.0000f); break;
        case 12: norm_outflow = (norm_storage <= 1.0000f) ? 0.1413f * norm_storage + -0.0275f : 0.0000f * norm_storage + (0.1413f * 1.0000f + -0.0275f - 0.0000f * 1.0000f); break;
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
        case  1: norm_outflow = 0.7573f * norm_inflow + 0.0157f; break;
        case  2: norm_outflow = 0.0352f * norm_inflow + 0.0319f; break;
        case  3: norm_outflow = (norm_storage <= 0.6814f) ? 0.0067f * norm_storage + 0.0045f : 0.9883f * norm_storage + (0.0067f * 0.6814f + 0.0045f - 0.9883f * 0.6814f); break;
        case  4: norm_outflow = (norm_storage <= 0.6835f) ? 0.0114f * norm_storage + 0.0027f : 1.0310f * norm_storage + (0.0114f * 0.6835f + 0.0027f - 1.0310f * 0.6835f); break;
        case  5: norm_outflow = (norm_storage <= 0.6852f) ? 0.0183f * norm_storage + 0.0065f : 0.7478f * norm_storage + (0.0183f * 0.6852f + 0.0065f - 0.7478f * 0.6852f); break;
        case  6: norm_outflow = (norm_storage <= 0.7137f) ? 0.0641f * norm_storage + 0.0000f : 0.7002f * norm_storage + (0.0641f * 0.7137f + 0.0000f - 0.7002f * 0.7137f); break;
        case  7: norm_outflow = (norm_storage <= 0.7045f) ? 0.0286f * norm_storage + 0.0000f : 0.7005f * norm_storage + (0.0286f * 0.7045f + 0.0000f - 0.7005f * 0.7045f); break;
        case  8: norm_outflow = (norm_storage <= 0.6986f) ? 0.0040f * norm_storage + 0.0145f : 0.7394f * norm_storage + (0.0040f * 0.6986f + 0.0145f - 0.7394f * 0.6986f); break;
        case  9: norm_outflow = (norm_storage <= 0.7103f) ? 0.0000f * norm_storage + 0.0156f : 0.7069f * norm_storage + (0.0000f * 0.7103f + 0.0156f - 0.7069f * 0.7103f); break;
        case 10: norm_outflow = (norm_storage <= 0.6993f) ? 0.0000f * norm_storage + 0.0132f : 0.7449f * norm_storage + (0.0000f * 0.6993f + 0.0132f - 0.7449f * 0.6993f); break;
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
        case  1: norm_outflow = 3.9017f * norm_inflow + 0.0210f; break;
        case  2: norm_outflow = 0.7305f * norm_inflow + 0.0376f; break;
        case  3: norm_outflow = 1.1357f * norm_inflow + 0.0518f; break;
        case  4: norm_outflow = 1.1098f * norm_inflow + 0.0682f; break;
        case  5: norm_outflow = 0.8264f * norm_inflow + 0.0654f; break;
        case  6: norm_outflow = 0.9964f * norm_inflow + 0.0668f; break;
        case  7: norm_outflow = 1.8404f * norm_inflow + 0.0244f; break;
        case  8: norm_outflow = 1.2946f * norm_inflow + 0.0121f; break;
        case  9: norm_outflow = 0.6980f * norm_inflow + 0.0139f; break;
        case 10: norm_outflow = 0.7000f * norm_inflow + 0.0301f; break;
        case 11: norm_outflow = 0.7090f * norm_inflow + 0.0254f; break;
        case 12: norm_outflow = 0.6473f * norm_inflow + 0.0361f; break;
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
        case  1: norm_outflow = (norm_storage <= 1.0000f) ? 0.6140f * norm_storage + -0.1604f : 0.0000f * norm_storage + (0.6140f * 1.0000f + -0.1604f - 0.0000f * 1.0000f); break;
        case  2: norm_outflow = (norm_storage <= 1.0000f) ? 0.9077f * norm_storage + -0.2527f : 0.0000f * norm_storage + (0.9077f * 1.0000f + -0.2527f - 0.0000f * 1.0000f); break;
        case  3: norm_outflow = (norm_storage <= 1.0000f) ? 0.6455f * norm_storage + -0.1597f : 0.0000f * norm_storage + (0.6455f * 1.0000f + -0.1597f - 0.0000f * 1.0000f); break;
        case  4: norm_outflow = (norm_storage <= 1.0000f) ? 0.4471f * norm_storage + -0.0854f : 0.0000f * norm_storage + (0.4471f * 1.0000f + -0.0854f - 0.0000f * 1.0000f); break;
        case  5: norm_outflow = 0.8110f * norm_inflow + 0.0387f; break;
        case  6: norm_outflow = (norm_storage <= 1.0000f) ? 0.3183f * norm_storage + -0.0521f : 0.0000f * norm_storage + (0.3183f * 1.0000f + -0.0521f - 0.0000f * 1.0000f); break;
        case  7: norm_outflow = (norm_storage <= 1.0000f) ? 0.3257f * norm_storage + -0.0704f : 0.0000f * norm_storage + (0.3257f * 1.0000f + -0.0704f - 0.0000f * 1.0000f); break;
        case  8: norm_outflow = (norm_storage <= 1.0000f) ? 0.6752f * norm_storage + -0.1812f : 0.0000f * norm_storage + (0.6752f * 1.0000f + -0.1812f - 0.0000f * 1.0000f); break;
        case  9: norm_outflow = 0.5414f * norm_inflow + 0.0207f; break;
        case 10: norm_outflow = (norm_storage <= 1.0000f) ? 0.7336f * norm_storage + -0.2031f : 0.0000f * norm_storage + (0.7336f * 1.0000f + -0.2031f - 0.0000f * 1.0000f); break;
        case 11: norm_outflow = 0.9029f * norm_inflow + 0.0068f; break;
        case 12: norm_outflow = 0.7844f * norm_inflow + 0.0061f; break;
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
        case 12: norm_outflow = 0.8063f * norm_inflow + 0.0267f; break;
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
        case  8: norm_outflow = (norm_storage <= 0.6842f) ? 0.1000f * norm_storage + 0.0196f : 4.9863f * norm_storage + (0.1000f * 0.6842f + 0.0196f - 4.9863f * 0.6842f); break;
        case  9: norm_outflow = (norm_storage <= 0.6556f) ? 0.0565f * norm_storage + 0.0000f : 2.4750f * norm_storage + (0.0565f * 0.6556f + 0.0000f - 2.4750f * 0.6556f); break;
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
        case  1: norm_outflow = 0.2146f * norm_inflow + 0.0047f; break;
        case  2: norm_outflow = (norm_storage <= 1.0000f) ? 0.0157f * norm_storage + -0.0025f : 0.0000f * norm_storage + (0.0157f * 1.0000f + -0.0025f - 0.0000f * 1.0000f); break;
        case  3: norm_outflow = 0.1510f * norm_inflow + 0.0076f; break;
        case  4: norm_outflow = (norm_storage <= 0.7976f) ? 0.0065f * norm_storage + 0.0032f : 0.5559f * norm_storage + (0.0065f * 0.7976f + 0.0032f - 0.5559f * 0.7976f); break;
        case  5: norm_outflow = 0.4164f * norm_inflow + 0.0070f; break;
        case  6: norm_outflow = (norm_storage <= 0.8692f) ? 0.0210f * norm_storage + 0.0000f : 1.6584f * norm_storage + (0.0210f * 0.8692f + 0.0000f - 1.6584f * 0.8692f); break;
        case  7: norm_outflow = (norm_storage <= 0.8357f) ? 0.0039f * norm_storage + 0.0000f : 0.9427f * norm_storage + (0.0039f * 0.8357f + 0.0000f - 0.9427f * 0.8357f); break;
        case  8: norm_outflow = 0.3441f * norm_inflow + 0.0045f; break;
        case  9: norm_outflow = (norm_storage <= 1.0000f) ? 0.0187f * norm_storage + -0.0067f : 0.0000f * norm_storage + (0.0187f * 1.0000f + -0.0067f - 0.0000f * 1.0000f); break;
        case 10: norm_outflow = (norm_storage <= 0.8563f) ? 0.0061f * norm_storage + 0.0000f : 0.9471f * norm_storage + (0.0061f * 0.8563f + 0.0000f - 0.9471f * 0.8563f); break;
        case 11: norm_outflow = (norm_storage <= 0.8477f) ? 0.0049f * norm_storage + 0.0000f : 0.9522f * norm_storage + (0.0049f * 0.8477f + 0.0000f - 0.9522f * 0.8477f); break;
        case 12: norm_outflow = (norm_storage <= 1.0000f) ? 0.0140f * norm_storage + -0.0030f : 0.0000f * norm_storage + (0.0140f * 1.0000f + -0.0030f - 0.0000f * 1.0000f); break;
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
        case  1: norm_outflow = 2.2423f * norm_inflow + 0.0563f; break;
        case  2: norm_outflow = 0.7586f * norm_inflow + 0.0548f; break;
        case  3: norm_outflow = 1.0348f * norm_inflow + 0.0725f; break;
        case  4: norm_outflow = 1.2792f * norm_inflow + 0.0642f; break;
        case  5: norm_outflow = 1.1513f * norm_inflow + 0.0800f; break;
        case  6: norm_outflow = 1.2678f * norm_inflow + 0.0635f; break;
        case  7: norm_outflow = 1.5751f * norm_inflow + 0.0084f; break;
        case  8: norm_outflow = 1.0444f * norm_inflow + 0.0125f; break;
        case  9: norm_outflow = 1.5352f * norm_inflow + 0.0007f; break;
        case 10: norm_outflow = 1.0008f * norm_inflow + 0.0135f; break;
        case 11: norm_outflow = 0.8931f * norm_inflow + 0.0253f; break;
        case 12: norm_outflow = 0.8878f * norm_inflow + 0.0407f; break;
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
        case  5: norm_outflow = 0.7415f * norm_inflow + 0.0235f; break;
        case  6: norm_outflow = 0.6648f * norm_inflow + 0.0247f; break;
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
        case  1: norm_outflow = 1.2927f * norm_inflow + 0.0492f; break;
        case  2: norm_outflow = 1.0321f * norm_inflow + 0.0341f; break;
        case  3: norm_outflow = 0.7714f * norm_inflow + 0.0615f; break;
        case  4: norm_outflow = 0.8009f * norm_inflow + 0.0688f; break;
        case  5: norm_outflow = 0.7753f * norm_inflow + 0.0839f; break;
        case  6: norm_outflow = 0.7176f * norm_inflow + 0.0829f; break;
        case  7: norm_outflow = 0.9219f * norm_inflow + 0.0337f; break;
        case  8: norm_outflow = 0.5735f * norm_inflow + 0.0334f; break;
        case  9: norm_outflow = 0.4279f * norm_inflow + 0.0259f; break;
        case 10: norm_outflow = 0.5407f * norm_inflow + 0.0181f; break;
        case 11: norm_outflow = 0.6961f * norm_inflow + 0.0236f; break;
        case 12: norm_outflow = 0.7959f * norm_inflow + 0.0188f; break;
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
        case  8: norm_outflow = 2.8936f * norm_inflow + 0.0048f; break;
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
        case  4: norm_outflow = (norm_storage <= 0.8605f) ? 0.0004f * norm_storage + 0.0000f : 3.6910f * norm_storage + (0.0004f * 0.8605f + 0.0000f - 3.6910f * 0.8605f); break;
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
        case  2: norm_outflow = (norm_storage <= 0.7636f) ? 0.0285f * norm_storage + 0.0430f : 3.8067f * norm_storage + (0.0285f * 0.7636f + 0.0430f - 3.8067f * 0.7636f); break;
        case  3: norm_outflow = (norm_storage <= 0.7837f) ? 0.1000f * norm_storage + 0.0129f : 6.4879f * norm_storage + (0.1000f * 0.7837f + 0.0129f - 6.4879f * 0.7837f); break;
        case  4: norm_outflow = (norm_storage <= 0.7729f) ? 0.0019f * norm_storage + 0.0324f : 5.1985f * norm_storage + (0.0019f * 0.7729f + 0.0324f - 5.1985f * 0.7729f); break;
        case  5: norm_outflow = (norm_storage <= 1.0000f) ? 3.1897f * norm_storage + -2.4127f : 0.0000f * norm_storage + (3.1897f * 1.0000f + -2.4127f - 0.0000f * 1.0000f); break;
        case  6: norm_outflow = (norm_storage <= 0.7945f) ? 0.0000f * norm_storage + 0.0863f : 5.6853f * norm_storage + (0.0000f * 0.7945f + 0.0863f - 5.6853f * 0.7945f); break;
        case  7: norm_outflow = 2.0958f * norm_inflow + 0.1029f; break;
        case  8: norm_outflow = 0.9292f * norm_inflow + 0.1036f; break;
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
        case  9: norm_outflow = 2.2277f * norm_inflow + 0.0091f; break;
        case 10: norm_outflow = (norm_storage <= 0.6000f) ? 0.0147f * norm_storage + 0.0000f : 0.9518f * norm_storage + (0.0147f * 0.6000f + 0.0000f - 0.9518f * 0.6000f); break;
        case 11: norm_outflow = (norm_storage <= 0.6000f) ? 0.0347f * norm_storage + 0.0000f : 1.9376f * norm_storage + (0.0347f * 0.6000f + 0.0000f - 1.9376f * 0.6000f); break;
        case 12: norm_outflow = 0.6109f * norm_inflow + 0.0087f; break;
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
        case  2: norm_outflow = (norm_storage <= 0.6900f) ? 0.0499f * norm_storage + 0.0000f : 2.8754f * norm_storage + (0.0499f * 0.6900f + 0.0000f - 2.8754f * 0.6900f); break;
        case  3: norm_outflow = (norm_storage <= 1.0000f) ? 1.9250f * norm_storage + -1.2560f : 0.0000f * norm_storage + (1.9250f * 1.0000f + -1.2560f - 0.0000f * 1.0000f); break;
        case  4: norm_outflow = (norm_storage <= 0.7209f) ? 0.0695f * norm_storage + 0.0000f : 4.4339f * norm_storage + (0.0695f * 0.7209f + 0.0000f - 4.4339f * 0.7209f); break;
        case  5: norm_outflow = (norm_storage <= 1.0000f) ? 3.2352f * norm_storage + -2.2884f : 0.0000f * norm_storage + (3.2352f * 1.0000f + -2.2884f - 0.0000f * 1.0000f); break;
        case  6: norm_outflow = (norm_storage <= 0.7420f) ? 0.0886f * norm_storage + 0.0000f : 6.5757f * norm_storage + (0.0886f * 0.7420f + 0.0000f - 6.5757f * 0.7420f); break;
        case  7: norm_outflow = 1.2314f * norm_inflow + 0.0641f; break;
        case  8: norm_outflow = 0.3683f * norm_inflow + 0.0601f; break;
        case  9: norm_outflow = (norm_storage <= 0.7307f) ? 0.0664f * norm_storage + 0.0000f : 7.3833f * norm_storage + (0.0664f * 0.7307f + 0.0000f - 7.3833f * 0.7307f); break;
        case 10: norm_outflow = (norm_storage <= 0.7453f) ? 0.0481f * norm_storage + 0.0000f : 13.1044f * norm_storage + (0.0481f * 0.7453f + 0.0000f - 13.1044f * 0.7453f); break;
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
        case  2: norm_outflow = (norm_storage <= 0.6900f) ? 0.0499f * norm_storage + 0.0000f : 2.8754f * norm_storage + (0.0499f * 0.6900f + 0.0000f - 2.8754f * 0.6900f); break;
        case  3: norm_outflow = (norm_storage <= 1.0000f) ? 1.9250f * norm_storage + -1.2560f : 0.0000f * norm_storage + (1.9250f * 1.0000f + -1.2560f - 0.0000f * 1.0000f); break;
        case  4: norm_outflow = (norm_storage <= 0.7209f) ? 0.0695f * norm_storage + 0.0000f : 4.4339f * norm_storage + (0.0695f * 0.7209f + 0.0000f - 4.4339f * 0.7209f); break;
        case  5: norm_outflow = (norm_storage <= 1.0000f) ? 3.2352f * norm_storage + -2.2884f : 0.0000f * norm_storage + (3.2352f * 1.0000f + -2.2884f - 0.0000f * 1.0000f); break;
        case  6: norm_outflow = (norm_storage <= 0.7420f) ? 0.0886f * norm_storage + 0.0000f : 6.5757f * norm_storage + (0.0886f * 0.7420f + 0.0000f - 6.5757f * 0.7420f); break;
        case  7: norm_outflow = (norm_storage <= 0.7364f) ? 0.0960f * norm_storage + 0.0000f : 7.0636f * norm_storage + (0.0960f * 0.7364f + 0.0000f - 7.0636f * 0.7364f); break;
        case  8: norm_outflow = 0.6140f * norm_inflow + 0.0599f; break;
        case  9: norm_outflow = (norm_storage <= 0.7307f) ? 0.0664f * norm_storage + 0.0000f : 7.3833f * norm_storage + (0.0664f * 0.7307f + 0.0000f - 7.3833f * 0.7307f); break;
        case 10: norm_outflow = (norm_storage <= 0.7453f) ? 0.0481f * norm_storage + 0.0000f : 13.1044f * norm_storage + (0.0481f * 0.7453f + 0.0000f - 13.1044f * 0.7453f); break;
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
        case  8: norm_outflow = 6.1422f * norm_inflow + 0.0440f; break;
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
        case  2: norm_outflow = 0.8857f * norm_inflow + 0.0150f; break;
        case  3: norm_outflow = (norm_storage <= 1.0000f) ? 0.6751f * norm_storage + -0.0660f : 0.0000f * norm_storage + (0.6751f * 1.0000f + -0.0660f - 0.0000f * 1.0000f); break;
        case  4: norm_outflow = 1.1443f * norm_inflow + 0.0255f; break;
        case  5: norm_outflow = (norm_storage <= 0.8354f) ? 0.1000f * norm_storage + 0.0454f : 5.3657f * norm_storage + (0.1000f * 0.8354f + 0.0454f - 5.3657f * 0.8354f); break;
        case  6: norm_outflow = 0.8482f * norm_inflow + 0.0308f; break;
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
        case 10: norm_outflow = 0.3209f * norm_inflow + 0.0186f; break;
        case 11: norm_outflow = 0.5169f * norm_inflow + 0.0164f; break;
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
        case  1: norm_outflow = 0.2524f * norm_inflow + 0.0008f; break;
        case  2: norm_outflow = 0.4052f * norm_inflow + 0.0020f; break;
        case  3: norm_outflow = (norm_storage <= 0.9111f) ? 0.0037f * norm_storage + 0.0009f : 6.2187f * norm_storage + (0.0037f * 0.9111f + 0.0009f - 6.2187f * 0.9111f); break;
        case  4: norm_outflow = (norm_storage <= 0.9111f) ? 0.0020f * norm_storage + 0.0000f : 8.5120f * norm_storage + (0.0020f * 0.9111f + 0.0000f - 8.5120f * 0.9111f); break;
        case  5: norm_outflow = (norm_storage <= 0.9074f) ? 0.0069f * norm_storage + 0.0000f : 6.5820f * norm_storage + (0.0069f * 0.9074f + 0.0000f - 6.5820f * 0.9074f); break;
        case  6: norm_outflow = (norm_storage <= 0.9160f) ? 0.0068f * norm_storage + 0.0000f : 7.2174f * norm_storage + (0.0068f * 0.9160f + 0.0000f - 7.2174f * 0.9160f); break;
        case  7: norm_outflow = (norm_storage <= 0.9101f) ? 0.0000f * norm_storage + 0.0005f : 5.9104f * norm_storage + (0.0000f * 0.9101f + 0.0005f - 5.9104f * 0.9101f); break;
        case  8: norm_outflow = 0.4221f * norm_inflow + 0.0007f; break;
        case  9: norm_outflow = (norm_storage <= 0.9141f) ? 0.0033f * norm_storage + 0.0003f : 5.2168f * norm_storage + (0.0033f * 0.9141f + 0.0003f - 5.2168f * 0.9141f); break;
        case 10: norm_outflow = 0.2309f * norm_inflow + 0.0013f; break;
        case 11: norm_outflow = 0.1867f * norm_inflow + 0.0008f; break;
        case 12: norm_outflow = 0.3847f * norm_inflow + 0.0006f; break;
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
        case  1: norm_outflow = (norm_storage <= 1.0000f) ? 1.7025f * norm_storage + -0.1290f : 0.0000f * norm_storage + (1.7025f * 1.0000f + -0.1290f - 0.0000f * 1.0000f); break;
        case  2: norm_outflow = 0.8840f * norm_inflow + 0.0571f; break;
        case  3: norm_outflow = (norm_storage <= 1.0000f) ? 2.1316f * norm_storage + -0.1898f : 0.0000f * norm_storage + (2.1316f * 1.0000f + -0.1898f - 0.0000f * 1.0000f); break;
        case  4: norm_outflow = (norm_storage <= 1.0000f) ? 6.5223f * norm_storage + -0.8647f : 0.0000f * norm_storage + (6.5223f * 1.0000f + -0.8647f - 0.0000f * 1.0000f); break;
        case  5: norm_outflow = (norm_storage <= 1.0000f) ? 1.5960f * norm_storage + -0.1132f : 0.0000f * norm_storage + (1.5960f * 1.0000f + -0.1132f - 0.0000f * 1.0000f); break;
        case  6: norm_outflow = 0.6879f * norm_inflow + 0.0597f; break;
        case  7: norm_outflow = (norm_storage <= 1.0000f) ? 1.0582f * norm_storage + -0.0893f : 0.0000f * norm_storage + (1.0582f * 1.0000f + -0.0893f - 0.0000f * 1.0000f); break;
        case  8: norm_outflow = 2.2588f * norm_inflow + 0.0197f; break;
        case  9: norm_outflow = 1.5160f * norm_inflow + 0.0151f; break;
        case 10: norm_outflow = 1.5300f * norm_inflow + 0.0171f; break;
        case 11: norm_outflow = 1.1885f * norm_inflow + 0.0248f; break;
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
        case  1: norm_outflow = 0.5152f * norm_inflow + 0.0023f; break;
        case  2: norm_outflow = 0.1960f * norm_inflow + 0.0060f; break;
        case  3: norm_outflow = 0.5969f * norm_inflow + 0.0074f; break;
        case  4: norm_outflow = 0.4588f * norm_inflow + 0.0112f; break;
        case  5: norm_outflow = (norm_storage <= 0.8644f) ? 0.0000f * norm_storage + 0.0158f : 6.6546f * norm_storage + (0.0000f * 0.8644f + 0.0158f - 6.6546f * 0.8644f); break;
        case  6: norm_outflow = (norm_storage <= 0.8661f) ? 0.0205f * norm_storage + 0.0000f : 7.1551f * norm_storage + (0.0205f * 0.8661f + 0.0000f - 7.1551f * 0.8661f); break;
        case  7: norm_outflow = 24.6945f * norm_inflow + -0.0005f; break;
        case  8: norm_outflow = 10.4571f * norm_inflow + 0.0007f; break;
        case  9: norm_outflow = (norm_storage <= 0.8634f) ? 0.0048f * norm_storage + 0.0000f : 6.8583f * norm_storage + (0.0048f * 0.8634f + 0.0000f - 6.8583f * 0.8634f); break;
        case 10: norm_outflow = 0.1152f * norm_inflow + 0.0035f; break;
        case 11: norm_outflow = 0.3377f * norm_inflow + 0.0014f; break;
        case 12: norm_outflow = 0.1600f * norm_inflow + 0.0045f; break;
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
        case  1: norm_outflow = (norm_storage <= 0.6255f) ? 0.0000f * norm_storage + 0.0104f : 0.5301f * norm_storage + (0.0000f * 0.6255f + 0.0104f - 0.5301f * 0.6255f); break;
        case  2: norm_outflow = 0.7258f * norm_inflow + 0.0120f; break;
        case  3: norm_outflow = 0.7462f * norm_inflow + 0.0167f; break;
        case  4: norm_outflow = 1.0788f * norm_inflow + 0.0138f; break;
        case  5: norm_outflow = 0.5896f * norm_inflow + 0.0141f; break;
        case  6: norm_outflow = (norm_storage <= 0.6577f) ? 0.0000f * norm_storage + 0.0134f : 1.2048f * norm_storage + (0.0000f * 0.6577f + 0.0134f - 1.2048f * 0.6577f); break;
        case  7: norm_outflow = 0.9548f * norm_inflow + 0.0119f; break;
        case  8: norm_outflow = 0.7099f * norm_inflow + 0.0138f; break;
        case  9: norm_outflow = 0.0936f * norm_inflow + 0.0114f; break;
        case 10: norm_outflow = 0.5218f * norm_inflow + 0.0146f; break;
        case 11: norm_outflow = 0.6869f * norm_inflow + 0.0098f; break;
        case 12: norm_outflow = 0.8468f * norm_inflow + 0.0131f; break;
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
        case  9: norm_outflow = 0.1606f * norm_inflow + 0.0246f; break;
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
        case  2: norm_outflow = (norm_storage <= 1.0000f) ? 2.0973f * norm_storage + -0.8264f : 0.0000f * norm_storage + (2.0973f * 1.0000f + -0.8264f - 0.0000f * 1.0000f); break;
        case  3: norm_outflow = (norm_storage <= 1.0000f) ? 2.5415f * norm_storage + -1.0821f : 0.0000f * norm_storage + (2.5415f * 1.0000f + -1.0821f - 0.0000f * 1.0000f); break;
        case  4: norm_outflow = (norm_storage <= 1.0000f) ? 2.1533f * norm_storage + -0.8740f : 0.0000f * norm_storage + (2.1533f * 1.0000f + -0.8740f - 0.0000f * 1.0000f); break;
        case  5: norm_outflow = (norm_storage <= 1.0000f) ? 1.8181f * norm_storage + -0.7388f : 0.0000f * norm_storage + (1.8181f * 1.0000f + -0.7388f - 0.0000f * 1.0000f); break;
        case  6: norm_outflow = (norm_storage <= 1.0000f) ? 1.4015f * norm_storage + -0.5455f : 0.0000f * norm_storage + (1.4015f * 1.0000f + -0.5455f - 0.0000f * 1.0000f); break;
        case  7: norm_outflow = (norm_storage <= 1.0000f) ? 1.1260f * norm_storage + -0.4411f : 0.0000f * norm_storage + (1.1260f * 1.0000f + -0.4411f - 0.0000f * 1.0000f); break;
        case  8: norm_outflow = (norm_storage <= 1.0000f) ? 0.5172f * norm_storage + -0.1907f : 0.0000f * norm_storage + (0.5172f * 1.0000f + -0.1907f - 0.0000f * 1.0000f); break;
        case  9: norm_outflow = (norm_storage <= 1.0000f) ? 0.5351f * norm_storage + -0.1981f : 0.0000f * norm_storage + (0.5351f * 1.0000f + -0.1981f - 0.0000f * 1.0000f); break;
        case 10: norm_outflow = (norm_storage <= 1.0000f) ? 1.2401f * norm_storage + -0.4801f : 0.0000f * norm_storage + (1.2401f * 1.0000f + -0.4801f - 0.0000f * 1.0000f); break;
        case 11: norm_outflow = (norm_storage <= 1.0000f) ? 1.9644f * norm_storage + -0.7827f : 0.0000f * norm_storage + (1.9644f * 1.0000f + -0.7827f - 0.0000f * 1.0000f); break;
        case 12: norm_outflow = (norm_storage <= 1.0000f) ? 2.0065f * norm_storage + -0.7660f : 0.0000f * norm_storage + (2.0065f * 1.0000f + -0.7660f - 0.0000f * 1.0000f); break;
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
        case  1: norm_outflow = (norm_storage <= 1.0000f) ? 1.0277f * norm_storage + 0.0506f : 0.0000f * norm_storage + (1.0277f * 1.0000f + 0.0506f - 0.0000f * 1.0000f); break;
        case  2: norm_outflow = (norm_storage <= 1.0000f) ? 2.0748f * norm_storage + 0.0119f : 0.0000f * norm_storage + (2.0748f * 1.0000f + 0.0119f - 0.0000f * 1.0000f); break;
        case  3: norm_outflow = 1.6541f * norm_inflow + 0.0425f; break;
        case  4: norm_outflow = 1.3810f * norm_inflow + 0.0273f; break;
        case  5: norm_outflow = (norm_storage <= 1.0000f) ? 1.2639f * norm_storage + -0.0401f : 0.0000f * norm_storage + (1.2639f * 1.0000f + -0.0401f - 0.0000f * 1.0000f); break;
        case  6: norm_outflow = (norm_storage <= 1.0000f) ? 0.8028f * norm_storage + -0.0004f : 0.0000f * norm_storage + (0.8028f * 1.0000f + -0.0004f - 0.0000f * 1.0000f); break;
        case  7: norm_outflow = (norm_storage <= 1.0000f) ? 0.9086f * norm_storage + -0.0380f : 0.0000f * norm_storage + (0.9086f * 1.0000f + -0.0380f - 0.0000f * 1.0000f); break;
        case  8: norm_outflow = (norm_storage <= 1.0000f) ? 1.1634f * norm_storage + -0.0692f : 0.0000f * norm_storage + (1.1634f * 1.0000f + -0.0692f - 0.0000f * 1.0000f); break;
        case  9: norm_outflow = (norm_storage <= 1.0000f) ? 2.6254f * norm_storage + -0.1734f : 0.0000f * norm_storage + (2.6254f * 1.0000f + -0.1734f - 0.0000f * 1.0000f); break;
        case 10: norm_outflow = (norm_storage <= 1.0000f) ? 1.4825f * norm_storage + -0.0591f : 0.0000f * norm_storage + (1.4825f * 1.0000f + -0.0591f - 0.0000f * 1.0000f); break;
        case 11: norm_outflow = (norm_storage <= 1.0000f) ? 2.3045f * norm_storage + -0.0504f : 0.0000f * norm_storage + (2.3045f * 1.0000f + -0.0504f - 0.0000f * 1.0000f); break;
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
        case 10: norm_outflow = 0.1946f * norm_inflow + 0.0573f; break;
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
        case  4: norm_outflow = 1.4518f * norm_inflow + 0.0694f; break;
        case  5: norm_outflow = 1.9397f * norm_inflow + 0.0851f; break;
        case  6: norm_outflow = (norm_storage <= 1.0000f) ? 0.9322f * norm_storage + -0.0552f : 0.0000f * norm_storage + (0.9322f * 1.0000f + -0.0552f - 0.0000f * 1.0000f); break;
        case  7: norm_outflow = 1.9991f * norm_inflow + 0.0624f; break;
        case  8: norm_outflow = (norm_storage <= 1.0000f) ? 1.3846f * norm_storage + -0.2235f : 0.0000f * norm_storage + (1.3846f * 1.0000f + -0.2235f - 0.0000f * 1.0000f); break;
        case  9: norm_outflow = 3.2018f * norm_inflow + 0.0191f; break;
        case 10: norm_outflow = 2.6870f * norm_inflow + 0.0501f; break;
        case 11: norm_outflow = 0.9959f * norm_inflow + 0.0998f; break;
        case 12: norm_outflow = 2.0585f * norm_inflow + 0.0970f; break;
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
        case  1: norm_outflow = (norm_storage <= 1.0000f) ? 0.7173f * norm_storage + 0.1618f : 0.0000f * norm_storage + (0.7173f * 1.0000f + 0.1618f - 0.0000f * 1.0000f); break;
        case  2: norm_outflow = (norm_storage <= 1.0000f) ? 2.4686f * norm_storage + 0.1527f : 0.0000f * norm_storage + (2.4686f * 1.0000f + 0.1527f - 0.0000f * 1.0000f); break;
        case  3: norm_outflow = (norm_storage <= 1.0000f) ? 1.0793f * norm_storage + 0.1904f : 0.0000f * norm_storage + (1.0793f * 1.0000f + 0.1904f - 0.0000f * 1.0000f); break;
        case  4: norm_outflow = (norm_storage <= 1.0000f) ? 2.8727f * norm_storage + 0.1736f : 0.0000f * norm_storage + (2.8727f * 1.0000f + 0.1736f - 0.0000f * 1.0000f); break;
        case  5: norm_outflow = (norm_storage <= 1.0000f) ? 1.6469f * norm_storage + 0.1344f : 0.0000f * norm_storage + (1.6469f * 1.0000f + 0.1344f - 0.0000f * 1.0000f); break;
        case  6: norm_outflow = (norm_storage <= 1.0000f) ? 1.9357f * norm_storage + 0.1103f : 0.0000f * norm_storage + (1.9357f * 1.0000f + 0.1103f - 0.0000f * 1.0000f); break;
        case  7: norm_outflow = (norm_storage <= 1.0000f) ? 1.6684f * norm_storage + 0.0805f : 0.0000f * norm_storage + (1.6684f * 1.0000f + 0.0805f - 0.0000f * 1.0000f); break;
        case  8: norm_outflow = (norm_storage <= 1.0000f) ? 11.1008f * norm_storage + 0.0292f : 0.0000f * norm_storage + (11.1008f * 1.0000f + 0.0292f - 0.0000f * 1.0000f); break;
        case  9: norm_outflow = (norm_storage <= 1.0000f) ? 12.8213f * norm_storage + 0.0202f : 0.0000f * norm_storage + (12.8213f * 1.0000f + 0.0202f - 0.0000f * 1.0000f); break;
        case 10: norm_outflow = (norm_storage <= 1.0000f) ? 10.4662f * norm_storage + 0.0296f : 0.0000f * norm_storage + (10.4662f * 1.0000f + 0.0296f - 0.0000f * 1.0000f); break;
        case 11: norm_outflow = (norm_storage <= 1.0000f) ? 2.6082f * norm_storage + 0.0724f : 0.0000f * norm_storage + (2.6082f * 1.0000f + 0.0724f - 0.0000f * 1.0000f); break;
        case 12: norm_outflow = 3.7681f * norm_inflow + 0.0690f; break;
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
        case  9: norm_outflow = 1.8454f * norm_inflow + 0.0085f; break;
        case 10: norm_outflow = 0.8010f * norm_inflow + 0.0232f; break;
        case 11: norm_outflow = 1.2784f * norm_inflow + 0.0429f; break;
        case 12: norm_outflow = 1.6660f * norm_inflow + 0.0832f; break;
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
        case 11: norm_outflow = 0.8664f * norm_inflow + 0.1216f; break;
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
        case  2: norm_outflow = 3.0911f * norm_inflow + 0.0446f; break;
        case  3: norm_outflow = (norm_storage <= 0.6208f) ? 0.0471f * norm_storage + 0.0000f : 1.7610f * norm_storage + (0.0471f * 0.6208f + 0.0000f - 1.7610f * 0.6208f); break;
        case  4: norm_outflow = (norm_storage <= 0.7081f) ? 0.0169f * norm_storage + 0.0000f : 5.7679f * norm_storage + (0.0169f * 0.7081f + 0.0000f - 5.7679f * 0.7081f); break;
        case  5: norm_outflow = (norm_storage <= 0.7140f) ? 0.0120f * norm_storage + 0.0000f : 6.8230f * norm_storage + (0.0120f * 0.7140f + 0.0000f - 6.8230f * 0.7140f); break;
        case  6: norm_outflow = (norm_storage <= 1.0000f) ? 5.2310f * norm_storage + -3.7118f : 0.0000f * norm_storage + (5.2310f * 1.0000f + -3.7118f - 0.0000f * 1.0000f); break;
        case  7: norm_outflow = (norm_storage <= 1.0000f) ? 2.7277f * norm_storage + -1.9163f : 0.0000f * norm_storage + (2.7277f * 1.0000f + -1.9163f - 0.0000f * 1.0000f); break;
        case  8: norm_outflow = (norm_storage <= 1.0000f) ? 1.4246f * norm_storage + -0.9877f : 0.0000f * norm_storage + (1.4246f * 1.0000f + -0.9877f - 0.0000f * 1.0000f); break;
        case  9: norm_outflow = (norm_storage <= 0.7081f) ? 0.0046f * norm_storage + 0.0050f : 2.0287f * norm_storage + (0.0046f * 0.7081f + 0.0050f - 2.0287f * 0.7081f); break;
        case 10: norm_outflow = (norm_storage <= 0.7160f) ? 0.0102f * norm_storage + 0.0051f : 6.1591f * norm_storage + (0.0102f * 0.7160f + 0.0051f - 6.1591f * 0.7160f); break;
        case 11: norm_outflow = 2.7482f * norm_inflow + 0.2095f; break;
        case 12: norm_outflow = 2.0663f * norm_inflow + 0.1937f; break;
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
        case  3: norm_outflow = (norm_storage <= 1.0000f) ? 1.3029f * norm_storage + -0.6789f : 0.0000f * norm_storage + (1.3029f * 1.0000f + -0.6789f - 0.0000f * 1.0000f); break;
        case  4: norm_outflow = (norm_storage <= 0.6663f) ? 0.0114f * norm_storage + 0.0231f : 4.3635f * norm_storage + (0.0114f * 0.6663f + 0.0231f - 4.3635f * 0.6663f); break;
        case  5: norm_outflow = (norm_storage <= 1.0000f) ? 3.6884f * norm_storage + -2.4217f : 0.0000f * norm_storage + (3.6884f * 1.0000f + -2.4217f - 0.0000f * 1.0000f); break;
        case  6: norm_outflow = (norm_storage <= 1.0000f) ? 3.2582f * norm_storage + -2.1409f : 0.0000f * norm_storage + (3.2582f * 1.0000f + -2.1409f - 0.0000f * 1.0000f); break;
        case  7: norm_outflow = (norm_storage <= 1.0000f) ? 3.1116f * norm_storage + -2.0441f : 0.0000f * norm_storage + (3.1116f * 1.0000f + -2.0441f - 0.0000f * 1.0000f); break;
        case  8: norm_outflow = (norm_storage <= 0.6685f) ? 0.0133f * norm_storage + 0.0015f : 5.5733f * norm_storage + (0.0133f * 0.6685f + 0.0015f - 5.5733f * 0.6685f); break;
        case  9: norm_outflow = (norm_storage <= 1.0000f) ? 2.3426f * norm_storage + -1.5302f : 0.0000f * norm_storage + (2.3426f * 1.0000f + -1.5302f - 0.0000f * 1.0000f); break;
        case 10: norm_outflow = (norm_storage <= 0.6687f) ? 0.0218f * norm_storage + 0.0001f : 6.3998f * norm_storage + (0.0218f * 0.6687f + 0.0001f - 6.3998f * 0.6687f); break;
        case 11: norm_outflow = 1.6585f * norm_inflow + 0.1207f; break;
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
        case  5: norm_outflow = (norm_storage <= 0.6071f) ? 0.0000f * norm_storage + 0.0691f : 3.9046f * norm_storage + (0.0000f * 0.6071f + 0.0691f - 3.9046f * 0.6071f); break;
        case  6: norm_outflow = (norm_storage <= 1.0000f) ? 4.2265f * norm_storage + -2.5274f : 0.0000f * norm_storage + (4.2265f * 1.0000f + -2.5274f - 0.0000f * 1.0000f); break;
        case  7: norm_outflow = (norm_storage <= 1.0000f) ? 3.4116f * norm_storage + -2.0225f : 0.0000f * norm_storage + (3.4116f * 1.0000f + -2.0225f - 0.0000f * 1.0000f); break;
        case  8: norm_outflow = (norm_storage <= 0.6084f) ? 0.0000f * norm_storage + 0.0201f : 5.9705f * norm_storage + (0.0000f * 0.6084f + 0.0201f - 5.9705f * 0.6084f); break;
        case  9: norm_outflow = (norm_storage <= 1.0000f) ? 2.0098f * norm_storage + -1.1738f : 0.0000f * norm_storage + (2.0098f * 1.0000f + -1.1738f - 0.0000f * 1.0000f); break;
        case 10: norm_outflow = (norm_storage <= 1.0000f) ? 4.3914f * norm_storage + -2.6253f : 0.0000f * norm_storage + (4.3914f * 1.0000f + -2.6253f - 0.0000f * 1.0000f); break;
        case 11: norm_outflow = 2.0467f * norm_inflow + 0.1596f; break;
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
        case  2: norm_outflow = (norm_storage <= 1.0000f) ? 0.0509f * norm_storage + 0.0047f : 0.0000f * norm_storage + (0.0509f * 1.0000f + 0.0047f - 0.0000f * 1.0000f); break;
        case  3: norm_outflow = (norm_storage <= 1.0000f) ? 0.0839f * norm_storage + -0.0142f : 0.0000f * norm_storage + (0.0839f * 1.0000f + -0.0142f - 0.0000f * 1.0000f); break;
        case  4: norm_outflow = 0.0450f * norm_inflow + 0.0775f; break;
        case  5: norm_outflow = 0.4820f * norm_inflow + 0.1392f; break;
        case  6: norm_outflow = 0.2379f * norm_inflow + 0.3528f; break;
        case  7: norm_outflow = (norm_storage <= 1.0000f) ? 0.9123f * norm_storage + -0.6627f : 0.0000f * norm_storage + (0.9123f * 1.0000f + -0.6627f - 0.0000f * 1.0000f); break;
        case  8: norm_outflow = (norm_storage <= 1.0000f) ? 0.3986f * norm_storage + -0.2770f : 0.0000f * norm_storage + (0.3986f * 1.0000f + -0.2770f - 0.0000f * 1.0000f); break;
        case  9: norm_outflow = (norm_storage <= 1.0000f) ? 0.1792f * norm_storage + -0.0993f : 0.0000f * norm_storage + (0.1792f * 1.0000f + -0.0993f - 0.0000f * 1.0000f); break;
        case 10: norm_outflow = (norm_storage <= 1.0000f) ? 0.1839f * norm_storage + -0.1038f : 0.0000f * norm_storage + (0.1839f * 1.0000f + -0.1038f - 0.0000f * 1.0000f); break;
        case 11: norm_outflow = (norm_storage <= 1.0000f) ? 0.1672f * norm_storage + -0.0893f : 0.0000f * norm_storage + (0.1672f * 1.0000f + -0.0893f - 0.0000f * 1.0000f); break;
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
        case  8: norm_outflow = 0.5068f * norm_inflow + 0.0219f; break;
        case  9: norm_outflow = 0.1506f * norm_inflow + 0.0339f; break;
        case 10: norm_outflow = 0.2686f * norm_inflow + 0.0861f; break;
        case 11: norm_outflow = (norm_storage <= 1.0000f) ? 0.7422f * norm_storage + 0.0093f : 0.0000f * norm_storage + (0.7422f * 1.0000f + 0.0093f - 0.0000f * 1.0000f); break;
        case 12: norm_outflow = 0.3841f * norm_inflow + 0.0971f; break;
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
        case 11: norm_outflow = 1.6601f * norm_inflow + 0.2193f; break;
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
        case 10: norm_outflow = 0.4642f * norm_inflow + 0.1348f; break;
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
        case 10: norm_outflow = 1.5311f * norm_inflow + 0.0066f; break;
        case 11: norm_outflow = (norm_storage <= 1.0000f) ? 1.0049f * norm_storage + -0.5027f : 0.0000f * norm_storage + (1.0049f * 1.0000f + -0.5027f - 0.0000f * 1.0000f); break;
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
        case  2: norm_outflow = 1.0498f * norm_inflow + 0.0954f; break;
        case  3: norm_outflow = (norm_storage <= 1.0000f) ? 1.3582f * norm_storage + -0.5692f : 0.0000f * norm_storage + (1.3582f * 1.0000f + -0.5692f - 0.0000f * 1.0000f); break;
        case  4: norm_outflow = 1.0115f * norm_inflow + 0.0589f; break;
        case  5: norm_outflow = (norm_storage <= 1.0000f) ? 2.1462f * norm_storage + -1.1029f : 0.0000f * norm_storage + (2.1462f * 1.0000f + -1.1029f - 0.0000f * 1.0000f); break;
        case  6: norm_outflow = (norm_storage <= 1.0000f) ? 2.8243f * norm_storage + -1.5266f : 0.0000f * norm_storage + (2.8243f * 1.0000f + -1.5266f - 0.0000f * 1.0000f); break;
        case  7: norm_outflow = 2.0732f * norm_inflow + 0.0091f; break;
        case  8: norm_outflow = 1.9707f * norm_inflow + 0.0024f; break;
        case  9: norm_outflow = 1.4395f * norm_inflow + 0.0123f; break;
        case 10: norm_outflow = 1.6330f * norm_inflow + 0.0162f; break;
        case 11: norm_outflow = 1.2537f * norm_inflow + 0.0413f; break;
        case 12: norm_outflow = 1.2979f * norm_inflow + 0.0483f; break;
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
        case  1: norm_outflow = 0.8540f * norm_inflow + 0.0638f; break;
        case  2: norm_outflow = (norm_storage <= 1.0000f) ? 1.5881f * norm_storage + -0.5132f : 0.0000f * norm_storage + (1.5881f * 1.0000f + -0.5132f - 0.0000f * 1.0000f); break;
        case  3: norm_outflow = (norm_storage <= 1.0000f) ? 1.8096f * norm_storage + -0.5964f : 0.0000f * norm_storage + (1.8096f * 1.0000f + -0.5964f - 0.0000f * 1.0000f); break;
        case  4: norm_outflow = 1.2549f * norm_inflow + 0.0214f; break;
        case  5: norm_outflow = (norm_storage <= 1.0000f) ? 2.1798f * norm_storage + -0.8508f : 0.0000f * norm_storage + (2.1798f * 1.0000f + -0.8508f - 0.0000f * 1.0000f); break;
        case  6: norm_outflow = (norm_storage <= 1.0000f) ? 3.6719f * norm_storage + -1.5447f : 0.0000f * norm_storage + (3.6719f * 1.0000f + -1.5447f - 0.0000f * 1.0000f); break;
        case  7: norm_outflow = (norm_storage <= 1.0000f) ? 3.2304f * norm_storage + -1.3586f : 0.0000f * norm_storage + (3.2304f * 1.0000f + -1.3586f - 0.0000f * 1.0000f); break;
        case  8: norm_outflow = (norm_storage <= 1.0000f) ? 2.1790f * norm_storage + -0.9054f : 0.0000f * norm_storage + (2.1790f * 1.0000f + -0.9054f - 0.0000f * 1.0000f); break;
        case  9: norm_outflow = (norm_storage <= 1.0000f) ? 1.8890f * norm_storage + -0.7643f : 0.0000f * norm_storage + (1.8890f * 1.0000f + -0.7643f - 0.0000f * 1.0000f); break;
        case 10: norm_outflow = 1.0984f * norm_inflow + 0.0205f; break;
        case 11: norm_outflow = 1.0615f * norm_inflow + 0.0185f; break;
        case 12: norm_outflow = 1.2025f * norm_inflow + 0.0277f; break;
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
        case  7: norm_outflow = (norm_storage <= 1.0000f) ? 3.1453f * norm_storage + -1.1150f : 0.0000f * norm_storage + (3.1453f * 1.0000f + -1.1150f - 0.0000f * 1.0000f); break;
        case  8: norm_outflow = (norm_storage <= 1.0000f) ? 1.6436f * norm_storage + -0.5662f : 0.0000f * norm_storage + (1.6436f * 1.0000f + -0.5662f - 0.0000f * 1.0000f); break;
        case  9: norm_outflow = 1.5589f * norm_inflow + -0.0122f; break;
        case 10: norm_outflow = 1.5174f * norm_inflow + 0.0163f; break;
        case 11: norm_outflow = 1.5276f * norm_inflow + 0.0796f; break;
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
        case  1: norm_outflow = (norm_storage <= 1.0000f) ? 1.5275f * norm_storage + -0.1830f : 0.0000f * norm_storage + (1.5275f * 1.0000f + -0.1830f - 0.0000f * 1.0000f); break;
        case  2: norm_outflow = (norm_storage <= 1.0000f) ? 1.8839f * norm_storage + -0.2423f : 0.0000f * norm_storage + (1.8839f * 1.0000f + -0.2423f - 0.0000f * 1.0000f); break;
        case  3: norm_outflow = 1.2756f * norm_inflow + 0.0789f; break;
        case  4: norm_outflow = 1.4388f * norm_inflow + -0.0296f; break;
        case  5: norm_outflow = 1.5495f * norm_inflow + -0.0249f; break;
        case  6: norm_outflow = 1.1674f * norm_inflow + -0.0347f; break;
        case  7: norm_outflow = 1.3902f * norm_inflow + -0.0480f; break;
        case  8: norm_outflow = 1.0047f * norm_inflow + -0.0134f; break;
        case  9: norm_outflow = 1.0224f * norm_inflow + -0.0155f; break;
        case 10: norm_outflow = 0.9539f * norm_inflow + 0.0188f; break;
        case 11: norm_outflow = 1.0887f * norm_inflow + 0.0712f; break;
        case 12: norm_outflow = 1.7319f * norm_inflow + 0.0436f; break;
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
        case  2: norm_outflow = (norm_storage <= 1.0000f) ? 2.9152f * norm_storage + 0.0686f : 0.0000f * norm_storage + (2.9152f * 1.0000f + 0.0686f - 0.0000f * 1.0000f); break;
        case  3: norm_outflow = (norm_storage <= 1.0000f) ? 2.1520f * norm_storage + 0.1281f : 0.0000f * norm_storage + (2.1520f * 1.0000f + 0.1281f - 0.0000f * 1.0000f); break;
        case  4: norm_outflow = (norm_storage <= 1.0000f) ? 5.2490f * norm_storage + -0.0141f : 0.0000f * norm_storage + (5.2490f * 1.0000f + -0.0141f - 0.0000f * 1.0000f); break;
        case  5: norm_outflow = (norm_storage <= 1.0000f) ? 6.4626f * norm_storage + -0.0911f : 0.0000f * norm_storage + (6.4626f * 1.0000f + -0.0911f - 0.0000f * 1.0000f); break;
        case  6: norm_outflow = (norm_storage <= 1.0000f) ? 2.5217f * norm_storage + 0.0371f : 0.0000f * norm_storage + (2.5217f * 1.0000f + 0.0371f - 0.0000f * 1.0000f); break;
        case  7: norm_outflow = (norm_storage <= 1.0000f) ? 5.6908f * norm_storage + -0.1011f : 0.0000f * norm_storage + (5.6908f * 1.0000f + -0.1011f - 0.0000f * 1.0000f); break;
        case  8: norm_outflow = (norm_storage <= 1.0000f) ? 6.3688f * norm_storage + -0.1326f : 0.0000f * norm_storage + (6.3688f * 1.0000f + -0.1326f - 0.0000f * 1.0000f); break;
        case  9: norm_outflow = (norm_storage <= 1.0000f) ? 9.4963f * norm_storage + -0.2258f : 0.0000f * norm_storage + (9.4963f * 1.0000f + -0.2258f - 0.0000f * 1.0000f); break;
        case 10: norm_outflow = (norm_storage <= 1.0000f) ? 7.1672f * norm_storage + -0.1561f : 0.0000f * norm_storage + (7.1672f * 1.0000f + -0.1561f - 0.0000f * 1.0000f); break;
        case 11: norm_outflow = (norm_storage <= 1.0000f) ? 4.8187f * norm_storage + -0.0710f : 0.0000f * norm_storage + (4.8187f * 1.0000f + -0.0710f - 0.0000f * 1.0000f); break;
        case 12: norm_outflow = (norm_storage <= 1.0000f) ? 2.4102f * norm_storage + 0.0496f : 0.0000f * norm_storage + (2.4102f * 1.0000f + 0.0496f - 0.0000f * 1.0000f); break;
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
        case  7: norm_outflow = (norm_storage <= 1.0000f) ? 1.8292f * norm_storage + -0.5823f : 0.0000f * norm_storage + (1.8292f * 1.0000f + -0.5823f - 0.0000f * 1.0000f); break;
        case  8: norm_outflow = 1.3734f * norm_inflow + 0.0116f; break;
        case  9: norm_outflow = (norm_storage <= 1.0000f) ? 1.0006f * norm_storage + -0.3042f : 0.0000f * norm_storage + (1.0006f * 1.0000f + -0.3042f - 0.0000f * 1.0000f); break;
        case 10: norm_outflow = 1.7450f * norm_inflow + 0.0172f; break;
        case 11: norm_outflow = 1.4678f * norm_inflow + 0.0450f; break;
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
        case  1: norm_outflow = 2.0525f * norm_inflow + 0.0545f; break;
        case  2: norm_outflow = 2.9256f * norm_inflow + 0.0087f; break;
        case  3: norm_outflow = 1.9118f * norm_inflow + 0.0524f; break;
        case  4: norm_outflow = (norm_storage <= 0.6000f) ? 0.1000f * norm_storage + 0.0000f : 9.7809f * norm_storage + (0.1000f * 0.6000f + 0.0000f - 9.7809f * 0.6000f); break;
        case  5: norm_outflow = 1.8806f * norm_inflow + -0.0142f; break;
        case  6: norm_outflow = 1.1019f * norm_inflow + 0.0039f; break;
        case  7: norm_outflow = 1.8044f * norm_inflow + -0.0323f; break;
        case  8: norm_outflow = 1.7254f * norm_inflow + -0.0210f; break;
        case  9: norm_outflow = 0.9063f * norm_inflow + 0.0395f; break;
        case 10: norm_outflow = 0.9332f * norm_inflow + 0.0387f; break;
        case 11: norm_outflow = 1.5730f * norm_inflow + 0.0877f; break;
        case 12: norm_outflow = 2.0708f * norm_inflow + 0.0552f; break;
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
        case  1: norm_outflow = (norm_storage <= 1.0000f) ? 2.6572f * norm_storage + -0.6854f : 0.0000f * norm_storage + (2.6572f * 1.0000f + -0.6854f - 0.0000f * 1.0000f); break;
        case  2: norm_outflow = (norm_storage <= 1.0000f) ? 2.2983f * norm_storage + -0.5551f : 0.0000f * norm_storage + (2.2983f * 1.0000f + -0.5551f - 0.0000f * 1.0000f); break;
        case  3: norm_outflow = (norm_storage <= 1.0000f) ? 1.2865f * norm_storage + -0.2450f : 0.0000f * norm_storage + (1.2865f * 1.0000f + -0.2450f - 0.0000f * 1.0000f); break;
        case  4: norm_outflow = 1.8931f * norm_inflow + 0.0299f; break;
        case  5: norm_outflow = (norm_storage <= 1.0000f) ? 3.6051f * norm_storage + -1.4303f : 0.0000f * norm_storage + (3.6051f * 1.0000f + -1.4303f - 0.0000f * 1.0000f); break;
        case  6: norm_outflow = (norm_storage <= 1.0000f) ? 4.4689f * norm_storage + -1.8245f : 0.0000f * norm_storage + (4.4689f * 1.0000f + -1.8245f - 0.0000f * 1.0000f); break;
        case  7: norm_outflow = 1.0523f * norm_inflow + 0.0060f; break;
        case  8: norm_outflow = 0.9176f * norm_inflow + 0.0061f; break;
        case  9: norm_outflow = 1.0710f * norm_inflow + 0.0121f; break;
        case 10: norm_outflow = 1.3132f * norm_inflow + 0.0117f; break;
        case 11: norm_outflow = 0.9399f * norm_inflow + 0.0601f; break;
        case 12: norm_outflow = (norm_storage <= 1.0000f) ? 3.1043f * norm_storage + -0.8281f : 0.0000f * norm_storage + (3.1043f * 1.0000f + -0.8281f - 0.0000f * 1.0000f); break;
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
        case  1: norm_outflow = 1.2878f * norm_inflow + 0.0704f; break;
        case  2: norm_outflow = 2.2625f * norm_inflow + 0.0708f; break;
        case  3: norm_outflow = (norm_storage <= 1.0000f) ? 1.6031f * norm_storage + -0.3858f : 0.0000f * norm_storage + (1.6031f * 1.0000f + -0.3858f - 0.0000f * 1.0000f); break;
        case  4: norm_outflow = (norm_storage <= 1.0000f) ? 1.5863f * norm_storage + -0.5846f : 0.0000f * norm_storage + (1.5863f * 1.0000f + -0.5846f - 0.0000f * 1.0000f); break;
        case  5: norm_outflow = (norm_storage <= 1.0000f) ? 3.2537f * norm_storage + -1.4640f : 0.0000f * norm_storage + (3.2537f * 1.0000f + -1.4640f - 0.0000f * 1.0000f); break;
        case  6: norm_outflow = 2.2628f * norm_inflow + 0.0227f; break;
        case  7: norm_outflow = 1.3558f * norm_inflow + 0.0285f; break;
        case  8: norm_outflow = 1.1964f * norm_inflow + 0.0193f; break;
        case  9: norm_outflow = 0.5891f * norm_inflow + 0.0224f; break;
        case 10: norm_outflow = 1.4577f * norm_inflow + 0.0245f; break;
        case 11: norm_outflow = 1.5007f * norm_inflow + 0.0752f; break;
        case 12: norm_outflow = 1.4700f * norm_inflow + 0.0543f; break;
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
        case 10: norm_outflow = 2.9373f * norm_inflow + 0.0817f; break;
        case 11: norm_outflow = 1.7418f * norm_inflow + 0.1108f; break;
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
        case  2: norm_outflow = 0.3131f * norm_inflow + 0.0261f; break;
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
        case  1: norm_outflow = (norm_storage <= 1.0000f) ? 4.8339f * norm_storage + -3.0162f : 0.0000f * norm_storage + (4.8339f * 1.0000f + -3.0162f - 0.0000f * 1.0000f); break;
        case  2: norm_outflow = 2.2069f * norm_inflow + 0.0927f; break;
        case  3: norm_outflow = (norm_storage <= 1.0000f) ? 3.5365f * norm_storage + -2.1378f : 0.0000f * norm_storage + (3.5365f * 1.0000f + -2.1378f - 0.0000f * 1.0000f); break;
        case  4: norm_outflow = (norm_storage <= 1.0000f) ? 5.3535f * norm_storage + -3.3653f : 0.0000f * norm_storage + (5.3535f * 1.0000f + -3.3653f - 0.0000f * 1.0000f); break;
        case  5: norm_outflow = (norm_storage <= 1.0000f) ? 5.0601f * norm_storage + -3.2337f : 0.0000f * norm_storage + (5.0601f * 1.0000f + -3.2337f - 0.0000f * 1.0000f); break;
        case  6: norm_outflow = (norm_storage <= 1.0000f) ? 4.5272f * norm_storage + -2.9036f : 0.0000f * norm_storage + (4.5272f * 1.0000f + -2.9036f - 0.0000f * 1.0000f); break;
        case  7: norm_outflow = (norm_storage <= 0.6530f) ? 0.0005f * norm_storage + 0.0132f : 9.7704f * norm_storage + (0.0005f * 0.6530f + 0.0132f - 9.7704f * 0.6530f); break;
        case  8: norm_outflow = (norm_storage <= 0.6541f) ? 0.0213f * norm_storage + 0.0000f : 9.2363f * norm_storage + (0.0213f * 0.6541f + 0.0000f - 9.2363f * 0.6541f); break;
        case  9: norm_outflow = (norm_storage <= 1.0000f) ? 2.4635f * norm_storage + -1.5481f : 0.0000f * norm_storage + (2.4635f * 1.0000f + -1.5481f - 0.0000f * 1.0000f); break;
        case 10: norm_outflow = (norm_storage <= 0.6466f) ? 0.0216f * norm_storage + 0.0000f : 7.6485f * norm_storage + (0.0216f * 0.6466f + 0.0000f - 7.6485f * 0.6466f); break;
        case 11: norm_outflow = (norm_storage <= 0.6375f) ? 0.0102f * norm_storage + 0.0055f : 6.3768f * norm_storage + (0.0102f * 0.6375f + 0.0055f - 6.3768f * 0.6375f); break;
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
        case  1: norm_outflow = 1.4577f * norm_inflow + 0.0396f; break;
        case  2: norm_outflow = (norm_storage <= 1.0000f) ? 1.4885f * norm_storage + -0.2391f : 0.0000f * norm_storage + (1.4885f * 1.0000f + -0.2391f - 0.0000f * 1.0000f); break;
        case  3: norm_outflow = 1.4743f * norm_inflow + 0.0288f; break;
        case  4: norm_outflow = (norm_storage <= 1.0000f) ? 1.3173f * norm_storage + -0.3276f : 0.0000f * norm_storage + (1.3173f * 1.0000f + -0.3276f - 0.0000f * 1.0000f); break;
        case  5: norm_outflow = (norm_storage <= 1.0000f) ? 1.8222f * norm_storage + -0.5597f : 0.0000f * norm_storage + (1.8222f * 1.0000f + -0.5597f - 0.0000f * 1.0000f); break;
        case  6: norm_outflow = (norm_storage <= 1.0000f) ? 1.7147f * norm_storage + -0.5524f : 0.0000f * norm_storage + (1.7147f * 1.0000f + -0.5524f - 0.0000f * 1.0000f); break;
        case  7: norm_outflow = 1.1501f * norm_inflow + 0.0014f; break;
        case  8: norm_outflow = 0.9447f * norm_inflow + 0.0044f; break;
        case  9: norm_outflow = (norm_storage <= 1.0000f) ? 0.8479f * norm_storage + -0.2708f : 0.0000f * norm_storage + (0.8479f * 1.0000f + -0.2708f - 0.0000f * 1.0000f); break;
        case 10: norm_outflow = 1.0996f * norm_inflow + 0.0090f; break;
        case 11: norm_outflow = 0.7985f * norm_inflow + 0.0464f; break;
        case 12: norm_outflow = 0.7663f * norm_inflow + 0.0479f; break;
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
        case  1: norm_outflow = 2.7817f * norm_inflow + 0.0688f; break;
        case  2: norm_outflow = (norm_storage <= 1.0000f) ? 1.6068f * norm_storage + -0.1464f : 0.0000f * norm_storage + (1.6068f * 1.0000f + -0.1464f - 0.0000f * 1.0000f); break;
        case  3: norm_outflow = 3.0833f * norm_inflow + 0.0281f; break;
        case  4: norm_outflow = 3.0832f * norm_inflow + -0.0031f; break;
        case  5: norm_outflow = (norm_storage <= 1.0000f) ? 1.5202f * norm_storage + -0.3258f : 0.0000f * norm_storage + (1.5202f * 1.0000f + -0.3258f - 0.0000f * 1.0000f); break;
        case  6: norm_outflow = (norm_storage <= 1.0000f) ? 2.3926f * norm_storage + -0.6746f : 0.0000f * norm_storage + (2.3926f * 1.0000f + -0.6746f - 0.0000f * 1.0000f); break;
        case  7: norm_outflow = (norm_storage <= 1.0000f) ? 2.6489f * norm_storage + -0.7790f : 0.0000f * norm_storage + (2.6489f * 1.0000f + -0.7790f - 0.0000f * 1.0000f); break;
        case  8: norm_outflow = 1.7620f * norm_inflow + -0.0088f; break;
        case  9: norm_outflow = 1.5026f * norm_inflow + 0.0034f; break;
        case 10: norm_outflow = 2.4324f * norm_inflow + -0.0003f; break;
        case 11: norm_outflow = 1.4416f * norm_inflow + 0.0460f; break;
        case 12: norm_outflow = 2.8525f * norm_inflow + 0.0305f; break;
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
        case  1: norm_outflow = 0.7478f * norm_inflow + 0.0436f; break;
        case  2: norm_outflow = 0.5195f * norm_inflow + 0.0616f; break;
        case  3: norm_outflow = 0.9152f * norm_inflow + 0.0241f; break;
        case  4: norm_outflow = 0.5673f * norm_inflow + 0.0103f; break;
        case  5: norm_outflow = 0.7729f * norm_inflow + 0.0082f; break;
        case  6: norm_outflow = 0.8705f * norm_inflow + -0.0151f; break;
        case  7: norm_outflow = 0.3639f * norm_inflow + 0.0119f; break;
        case  8: norm_outflow = 0.2933f * norm_inflow + 0.0115f; break;
        case  9: norm_outflow = 0.2501f * norm_inflow + 0.0169f; break;
        case 10: norm_outflow = 0.8832f * norm_inflow + 0.0146f; break;
        case 11: norm_outflow = 0.4870f * norm_inflow + 0.0307f; break;
        case 12: norm_outflow = 1.1708f * norm_inflow + 0.0146f; break;
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
        case  8: norm_outflow = (norm_storage <= 1.0000f) ? 4.0990f * norm_storage + -0.9022f : 0.0000f * norm_storage + (4.0990f * 1.0000f + -0.9022f - 0.0000f * 1.0000f); break;
        case  9: norm_outflow = (norm_storage <= 1.0000f) ? 2.9518f * norm_storage + -0.6284f : 0.0000f * norm_storage + (2.9518f * 1.0000f + -0.6284f - 0.0000f * 1.0000f); break;
        case 10: norm_outflow = 1.7359f * norm_inflow + 0.0384f; break;
        case 11: norm_outflow = 1.9145f * norm_inflow + 0.0616f; break;
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
        case  8: norm_outflow = 1.2445f * norm_inflow + 0.0192f; break;
        case  9: norm_outflow = 1.3658f * norm_inflow + 0.0286f; break;
        case 10: norm_outflow = 1.8000f * norm_inflow + 0.0765f; break;
        case 11: norm_outflow = (norm_storage <= 1.0000f) ? 0.7422f * norm_storage + 0.0093f : 0.0000f * norm_storage + (0.7422f * 1.0000f + 0.0093f - 0.0000f * 1.0000f); break;
        case 12: norm_outflow = 0.4572f * norm_inflow + 0.0880f; break;
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
        case  2: norm_outflow = 0.4222f * norm_inflow + 0.2303f; break;
        case  3: norm_outflow = (norm_storage <= 1.0000f) ? 0.8531f * norm_storage + -0.1236f : 0.0000f * norm_storage + (0.8531f * 1.0000f + -0.1236f - 0.0000f * 1.0000f); break;
        case  4: norm_outflow = (norm_storage <= 1.0000f) ? 2.0061f * norm_storage + -0.7058f : 0.0000f * norm_storage + (2.0061f * 1.0000f + -0.7058f - 0.0000f * 1.0000f); break;
        case  5: norm_outflow = (norm_storage <= 1.0000f) ? 1.1648f * norm_storage + -0.3831f : 0.0000f * norm_storage + (1.1648f * 1.0000f + -0.3831f - 0.0000f * 1.0000f); break;
        case  6: norm_outflow = (norm_storage <= 1.0000f) ? 2.0873f * norm_storage + -0.8332f : 0.0000f * norm_storage + (2.0873f * 1.0000f + -0.8332f - 0.0000f * 1.0000f); break;
        case  7: norm_outflow = (norm_storage <= 1.0000f) ? 4.7270f * norm_storage + -2.0168f : 0.0000f * norm_storage + (4.7270f * 1.0000f + -2.0168f - 0.0000f * 1.0000f); break;
        case  8: norm_outflow = (norm_storage <= 1.0000f) ? 2.7559f * norm_storage + -1.1674f : 0.0000f * norm_storage + (2.7559f * 1.0000f + -1.1674f - 0.0000f * 1.0000f); break;
        case  9: norm_outflow = (norm_storage <= 1.0000f) ? 2.8850f * norm_storage + -1.2047f : 0.0000f * norm_storage + (2.8850f * 1.0000f + -1.2047f - 0.0000f * 1.0000f); break;
        case 10: norm_outflow = 2.8731f * norm_inflow + 0.0499f; break;
        case 11: norm_outflow = 1.2588f * norm_inflow + 0.1370f; break;
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
        case  1: norm_outflow = 1.5912f * norm_inflow + 0.0251f; break;
        case  2: norm_outflow = 1.7198f * norm_inflow + 0.0255f; break;
        case  3: norm_outflow = 1.0746f * norm_inflow + 0.0567f; break;
        case  4: norm_outflow = (norm_storage <= 0.6933f) ? 0.0000f * norm_storage + 0.0238f : 3.3512f * norm_storage + (0.0000f * 0.6933f + 0.0238f - 3.3512f * 0.6933f); break;
        case  5: norm_outflow = 1.7067f * norm_inflow + -0.0086f; break;
        case  6: norm_outflow = 1.5735f * norm_inflow + -0.0150f; break;
        case  7: norm_outflow = 1.0772f * norm_inflow + 0.0011f; break;
        case  8: norm_outflow = 1.1645f * norm_inflow + 0.0024f; break;
        case  9: norm_outflow = 1.6636f * norm_inflow + -0.0053f; break;
        case 10: norm_outflow = 1.6968f * norm_inflow + 0.0260f; break;
        case 11: norm_outflow = 1.3589f * norm_inflow + 0.0510f; break;
        case 12: norm_outflow = 1.4481f * norm_inflow + 0.0354f; break;
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
        case  7: norm_outflow = (norm_storage <= 0.6006f) ? 0.0305f * norm_storage + 0.0000f : 6.0239f * norm_storage + (0.0305f * 0.6006f + 0.0000f - 6.0239f * 0.6006f); break;
        case  8: norm_outflow = (norm_storage <= 0.6009f) ? 0.0220f * norm_storage + 0.0000f : 7.7861f * norm_storage + (0.0220f * 0.6009f + 0.0000f - 7.7861f * 0.6009f); break;
        case  9: norm_outflow = (norm_storage <= 0.6012f) ? 0.0000f * norm_storage + 0.0259f : 6.7819f * norm_storage + (0.0000f * 0.6012f + 0.0259f - 6.7819f * 0.6012f); break;
        case 10: norm_outflow = (norm_storage <= 0.6000f) ? 0.0953f * norm_storage + 0.0000f : 3.4339f * norm_storage + (0.0953f * 0.6000f + 0.0000f - 3.4339f * 0.6000f); break;
        case 11: norm_outflow = 1.0565f * norm_inflow + 0.0482f; break;
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
        case  1: norm_outflow = 0.4204f * norm_inflow + 0.1353f; break;
        case  2: norm_outflow = 0.7244f * norm_inflow + 0.0649f; break;
        case  3: norm_outflow = 0.6673f * norm_inflow + 0.0651f; break;
        case  4: norm_outflow = 0.7000f * norm_inflow + 0.0316f; break;
        case  5: norm_outflow = 0.8666f * norm_inflow + 0.0273f; break;
        case  6: norm_outflow = 0.7261f * norm_inflow + 0.0401f; break;
        case  7: norm_outflow = 0.5007f * norm_inflow + 0.0592f; break;
        case  8: norm_outflow = 0.3884f * norm_inflow + 0.0671f; break;
        case  9: norm_outflow = 0.5170f * norm_inflow + 0.0641f; break;
        case 10: norm_outflow = 0.3857f * norm_inflow + 0.0627f; break;
        case 11: norm_outflow = 0.6031f * norm_inflow + 0.0680f; break;
        case 12: norm_outflow = 0.4201f * norm_inflow + 0.0921f; break;
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
        case  1: norm_outflow = 0.7660f * norm_inflow + 0.1790f; break;
        case  2: norm_outflow = 1.3338f * norm_inflow + 0.0359f; break;
        case  3: norm_outflow = 1.3627f * norm_inflow + -0.0032f; break;
        case  4: norm_outflow = 1.0881f * norm_inflow + -0.0054f; break;
        case  5: norm_outflow = 1.2263f * norm_inflow + 0.0068f; break;
        case  6: norm_outflow = 1.3218f * norm_inflow + 0.0220f; break;
        case  7: norm_outflow = 1.1321f * norm_inflow + 0.0413f; break;
        case  8: norm_outflow = 0.7296f * norm_inflow + 0.0623f; break;
        case  9: norm_outflow = 0.6310f * norm_inflow + 0.0653f; break;
        case 10: norm_outflow = 0.6180f * norm_inflow + 0.0626f; break;
        case 11: norm_outflow = 0.9738f * norm_inflow + 0.0699f; break;
        case 12: norm_outflow = 1.1257f * norm_inflow + 0.0700f; break;
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
        case  1: norm_outflow = 0.3285f * norm_inflow + 0.0283f; break;
        case  2: norm_outflow = 0.5396f * norm_inflow + 0.0211f; break;
        case  3: norm_outflow = 0.6490f * norm_inflow + 0.0185f; break;
        case  4: norm_outflow = 0.6819f * norm_inflow + 0.0159f; break;
        case  5: norm_outflow = 0.7977f * norm_inflow + 0.0125f; break;
        case  6: norm_outflow = 0.5668f * norm_inflow + 0.0127f; break;
        case  7: norm_outflow = 0.4341f * norm_inflow + 0.0159f; break;
        case  8: norm_outflow = 0.1493f * norm_inflow + 0.0151f; break;
        case  9: norm_outflow = 0.1818f * norm_inflow + 0.0137f; break;
        case 10: norm_outflow = 0.3951f * norm_inflow + 0.0130f; break;
        case 11: norm_outflow = 0.0972f * norm_inflow + 0.0148f; break;
        case 12: norm_outflow = 0.3883f * norm_inflow + 0.0156f; break;
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
        case 10: norm_outflow = 3.1001f * norm_inflow + 0.2502f; break;
        case 11: norm_outflow = 0.4963f * norm_inflow + 0.4257f; break;
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
        case  5: norm_outflow = 0.9078f * norm_inflow + 0.0993f; break;
        case  6: norm_outflow = (norm_storage <= 0.6729f) ? 0.0650f * norm_storage + 0.0645f : 3.8318f * norm_storage + (0.0650f * 0.6729f + 0.0645f - 3.8318f * 0.6729f); break;
        case  7: norm_outflow = 0.8785f * norm_inflow + 0.0938f; break;
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
        case  3: norm_outflow = (norm_storage <= 0.7825f) ? 0.1000f * norm_storage + 0.0044f : 4.5640f * norm_storage + (0.1000f * 0.7825f + 0.0044f - 4.5640f * 0.7825f); break;
        case  4: norm_outflow = (norm_storage <= 0.7986f) ? 0.0774f * norm_storage + 0.0000f : 4.2043f * norm_storage + (0.0774f * 0.7986f + 0.0000f - 4.2043f * 0.7986f); break;
        case  5: norm_outflow = (norm_storage <= 0.8100f) ? 0.0000f * norm_storage + 0.0362f : 4.2372f * norm_storage + (0.0000f * 0.8100f + 0.0362f - 4.2372f * 0.8100f); break;
        case  6: norm_outflow = (norm_storage <= 0.8457f) ? 0.1000f * norm_storage + 0.0321f : 11.9489f * norm_storage + (0.1000f * 0.8457f + 0.0321f - 11.9489f * 0.8457f); break;
        case  7: norm_outflow = 0.5261f * norm_inflow + 0.1532f; break;
        case  8: norm_outflow = 0.2404f * norm_inflow + 0.1585f; break;
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
        case  1: norm_outflow = (norm_storage <= 1.0000f) ? 1.1708f * norm_storage + -0.5526f : 0.0000f * norm_storage + (1.1708f * 1.0000f + -0.5526f - 0.0000f * 1.0000f); break;
        case  2: norm_outflow = (norm_storage <= 0.6881f) ? 0.0000f * norm_storage + 0.1087f : 3.8629f * norm_storage + (0.0000f * 0.6881f + 0.1087f - 3.8629f * 0.6881f); break;
        case  3: norm_outflow = 0.8277f * norm_inflow + 0.1033f; break;
        case  4: norm_outflow = (norm_storage <= 0.8699f) ? 0.0613f * norm_storage + 0.0320f : 6.7701f * norm_storage + (0.0613f * 0.8699f + 0.0320f - 6.7701f * 0.8699f); break;
        case  5: norm_outflow = (norm_storage <= 0.8968f) ? 0.0980f * norm_storage + 0.0000f : 9.7823f * norm_storage + (0.0980f * 0.8968f + 0.0000f - 9.7823f * 0.8968f); break;
        case  6: norm_outflow = 1.6539f * norm_inflow + 0.1163f; break;
        case  7: norm_outflow = 1.7455f * norm_inflow + 0.1475f; break;
        case  8: norm_outflow = 1.3457f * norm_inflow + 0.2218f; break;
        case  9: norm_outflow = 1.5124f * norm_inflow + 0.2014f; break;
        case 10: norm_outflow = 0.8335f * norm_inflow + 0.1856f; break;
        case 11: norm_outflow = (norm_storage <= 1.0000f) ? 0.7823f * norm_storage + -0.3375f : 0.0000f * norm_storage + (0.7823f * 1.0000f + -0.3375f - 0.0000f * 1.0000f); break;
        case 12: norm_outflow = (norm_storage <= 0.6727f) ? 0.1000f * norm_storage + 0.0795f : 4.5750f * norm_storage + (0.1000f * 0.6727f + 0.0795f - 4.5750f * 0.6727f); break;
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
        case  1: norm_outflow = 0.6726f * norm_inflow + 0.1115f; break;
        case  2: norm_outflow = 0.7618f * norm_inflow + 0.0822f; break;
        case  3: norm_outflow = 1.0079f * norm_inflow + 0.0339f; break;
        case  4: norm_outflow = 1.6278f * norm_inflow + -0.0197f; break;
        case  5: norm_outflow = 1.5279f * norm_inflow + 0.0267f; break;
        case  6: norm_outflow = 1.5040f * norm_inflow + 0.0528f; break;
        case  7: norm_outflow = 1.1862f * norm_inflow + 0.0915f; break;
        case  8: norm_outflow = 0.9971f * norm_inflow + 0.1137f; break;
        case  9: norm_outflow = 0.3873f * norm_inflow + 0.1297f; break;
        case 10: norm_outflow = 0.8655f * norm_inflow + 0.1090f; break;
        case 11: norm_outflow = 0.6114f * norm_inflow + 0.1184f; break;
        case 12: norm_outflow = 0.9210f * norm_inflow + 0.1099f; break;
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
        case  1: norm_outflow = 2.0605f * norm_inflow + 0.1787f; break;
        case  2: norm_outflow = (norm_storage <= 0.7169f) ? 0.1000f * norm_storage + 0.0252f : 1.7031f * norm_storage + (0.1000f * 0.7169f + 0.0252f - 1.7031f * 0.7169f); break;
        case  3: norm_outflow = (norm_storage <= 0.8100f) ? 0.1000f * norm_storage + 0.0149f : 2.9443f * norm_storage + (0.1000f * 0.8100f + 0.0149f - 2.9443f * 0.8100f); break;
        case  4: norm_outflow = (norm_storage <= 0.8751f) ? 0.1000f * norm_storage + 0.0257f : 6.7977f * norm_storage + (0.1000f * 0.8751f + 0.0257f - 6.7977f * 0.8751f); break;
        case  5: norm_outflow = (norm_storage <= 0.9047f) ? 0.1000f * norm_storage + 0.0522f : 11.0490f * norm_storage + (0.1000f * 0.9047f + 0.0522f - 11.0490f * 0.9047f); break;
        case  6: norm_outflow = 6.2239f * norm_inflow + 0.1013f; break;
        case  7: norm_outflow = 4.5619f * norm_inflow + 0.1860f; break;
        case  8: norm_outflow = 2.3547f * norm_inflow + 0.2279f; break;
        case  9: norm_outflow = (norm_storage <= 0.8738f) ? 0.0000f * norm_storage + 0.1790f : 8.9905f * norm_storage + (0.0000f * 0.8738f + 0.1790f - 8.9905f * 0.8738f); break;
        case 10: norm_outflow = 4.2259f * norm_inflow + 0.1372f; break;
        case 11: norm_outflow = 0.8730f * norm_inflow + 0.1637f; break;
        case 12: norm_outflow = 3.3665f * norm_inflow + 0.1438f; break;
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
        case  1: norm_outflow = (norm_storage <= 1.0000f) ? 1.7474f * norm_storage + -1.1478f : 0.0000f * norm_storage + (1.7474f * 1.0000f + -1.1478f - 0.0000f * 1.0000f); break;
        case  2: norm_outflow = 0.3540f * norm_inflow + 0.0811f; break;
        case  3: norm_outflow = 0.3686f * norm_inflow + 0.0819f; break;
        case  4: norm_outflow = 0.5516f * norm_inflow + 0.0519f; break;
        case  5: norm_outflow = 0.5675f * norm_inflow + 0.0526f; break;
        case  6: norm_outflow = 0.7032f * norm_inflow + 0.0290f; break;
        case  7: norm_outflow = 0.5901f * norm_inflow + 0.0389f; break;
        case  8: norm_outflow = 0.4960f * norm_inflow + 0.0486f; break;
        case  9: norm_outflow = 0.2582f * norm_inflow + 0.0458f; break;
        case 10: norm_outflow = 0.3226f * norm_inflow + 0.0385f; break;
        case 11: norm_outflow = 0.4021f * norm_inflow + 0.0378f; break;
        case 12: norm_outflow = 0.3429f * norm_inflow + 0.0626f; break;
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
        case  1: norm_outflow = (norm_storage <= 1.0000f) ? 0.8215f * norm_storage + -0.2167f : 0.0000f * norm_storage + (0.8215f * 1.0000f + -0.2167f - 0.0000f * 1.0000f); break;
        case  2: norm_outflow = (norm_storage <= 0.6000f) ? 0.1000f * norm_storage + 0.1018f : 4.1111f * norm_storage + (0.1000f * 0.6000f + 0.1018f - 4.1111f * 0.6000f); break;
        case  3: norm_outflow = (norm_storage <= 0.6397f) ? 0.1000f * norm_storage + 0.0354f : 3.1698f * norm_storage + (0.1000f * 0.6397f + 0.0354f - 3.1698f * 0.6397f); break;
        case  4: norm_outflow = (norm_storage <= 0.7974f) ? 0.0908f * norm_storage + 0.0000f : 3.9608f * norm_storage + (0.0908f * 0.7974f + 0.0000f - 3.9608f * 0.7974f); break;
        case  5: norm_outflow = (norm_storage <= 0.8396f) ? 0.0691f * norm_storage + 0.0000f : 6.1402f * norm_storage + (0.0691f * 0.8396f + 0.0000f - 6.1402f * 0.8396f); break;
        case  6: norm_outflow = (norm_storage <= 0.8475f) ? 0.0666f * norm_storage + 0.0516f : 4.3477f * norm_storage + (0.0666f * 0.8475f + 0.0516f - 4.3477f * 0.8475f); break;
        case  7: norm_outflow = 0.8266f * norm_inflow + 0.0990f; break;
        case  8: norm_outflow = 0.3064f * norm_inflow + 0.1654f; break;
        case  9: norm_outflow = 0.4772f * norm_inflow + 0.1329f; break;
        case 10: norm_outflow = (norm_storage <= 1.0000f) ? 0.2807f * norm_storage + -0.0170f : 0.0000f * norm_storage + (0.2807f * 1.0000f + -0.0170f - 0.0000f * 1.0000f); break;
        case 11: norm_outflow = (norm_storage <= 1.0000f) ? 0.5127f * norm_storage + -0.1243f : 0.0000f * norm_storage + (0.5127f * 1.0000f + -0.1243f - 0.0000f * 1.0000f); break;
        case 12: norm_outflow = (norm_storage <= 1.0000f) ? 1.0492f * norm_storage + -0.3390f : 0.0000f * norm_storage + (1.0492f * 1.0000f + -0.3390f - 0.0000f * 1.0000f); break;
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
        case  1: norm_outflow = 0.7034f * norm_inflow + 0.1948f; break;
        case  2: norm_outflow = 1.2443f * norm_inflow + 0.0657f; break;
        case  3: norm_outflow = 1.0708f * norm_inflow + 0.0126f; break;
        case  4: norm_outflow = 1.1425f * norm_inflow + -0.0443f; break;
        case  5: norm_outflow = (norm_storage <= 0.8309f) ? 0.0000f * norm_storage + 0.0394f : 1.8605f * norm_storage + (0.0000f * 0.8309f + 0.0394f - 1.8605f * 0.8309f); break;
        case  6: norm_outflow = 1.7246f * norm_inflow + 0.0742f; break;
        case  7: norm_outflow = 1.5963f * norm_inflow + 0.1566f; break;
        case  8: norm_outflow = 0.5020f * norm_inflow + 0.2863f; break;
        case  9: norm_outflow = 0.8699f * norm_inflow + 0.2294f; break;
        case 10: norm_outflow = 1.3634f * norm_inflow + 0.1959f; break;
        case 11: norm_outflow = 1.2770f * norm_inflow + 0.1650f; break;
        case 12: norm_outflow = 1.3816f * norm_inflow + 0.1762f; break;
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
        case  8: norm_outflow = (norm_storage <= 0.6000f) ? 0.0183f * norm_storage + 0.0000f : 3.9857f * norm_storage + (0.0183f * 0.6000f + 0.0000f - 3.9857f * 0.6000f); break;
        case  9: norm_outflow = (norm_storage <= 0.6000f) ? 0.0212f * norm_storage + 0.0000f : 5.1904f * norm_storage + (0.0212f * 0.6000f + 0.0000f - 5.1904f * 0.6000f); break;
        case 10: norm_outflow = (norm_storage <= 0.6000f) ? 0.0013f * norm_storage + 0.0472f : 3.2377f * norm_storage + (0.0013f * 0.6000f + 0.0472f - 3.2377f * 0.6000f); break;
        case 11: norm_outflow = 1.6058f * norm_inflow + 0.0731f; break;
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
        case  1: norm_outflow = 0.9169f * norm_inflow + 0.1103f; break;
        case  2: norm_outflow = (norm_storage <= 1.0000f) ? 1.1933f * norm_storage + -0.1271f : 0.0000f * norm_storage + (1.1933f * 1.0000f + -0.1271f - 0.0000f * 1.0000f); break;
        case  3: norm_outflow = 0.9590f * norm_inflow + 0.0417f; break;
        case  4: norm_outflow = 1.1203f * norm_inflow + -0.0067f; break;
        case  5: norm_outflow = 1.8017f * norm_inflow + -0.0098f; break;
        case  6: norm_outflow = 1.7419f * norm_inflow + 0.0404f; break;
        case  7: norm_outflow = 1.7108f * norm_inflow + 0.0581f; break;
        case  8: norm_outflow = 0.7935f * norm_inflow + 0.1224f; break;
        case  9: norm_outflow = (norm_storage <= 0.6330f) ? 0.0691f * norm_storage + 0.0831f : 1.0016f * norm_storage + (0.0691f * 0.6330f + 0.0831f - 1.0016f * 0.6330f); break;
        case 10: norm_outflow = (norm_storage <= 1.0000f) ? 0.3406f * norm_storage + -0.0087f : 0.0000f * norm_storage + (0.3406f * 1.0000f + -0.0087f - 0.0000f * 1.0000f); break;
        case 11: norm_outflow = (norm_storage <= 1.0000f) ? 0.6019f * norm_storage + -0.0637f : 0.0000f * norm_storage + (0.6019f * 1.0000f + -0.0637f - 0.0000f * 1.0000f); break;
        case 12: norm_outflow = (norm_storage <= 1.0000f) ? 0.9358f * norm_storage + -0.0640f : 0.0000f * norm_storage + (0.9358f * 1.0000f + -0.0640f - 0.0000f * 1.0000f); break;
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
        case  1: norm_outflow = 0.3946f * norm_inflow + 0.1403f; break;
        case  2: norm_outflow = 0.8580f * norm_inflow + 0.0579f; break;
        case  3: norm_outflow = 0.8350f * norm_inflow + 0.0179f; break;
        case  4: norm_outflow = 0.9136f * norm_inflow + -0.0256f; break;
        case  5: norm_outflow = 1.1021f * norm_inflow + -0.0069f; break;
        case  6: norm_outflow = 0.9822f * norm_inflow + 0.0409f; break;
        case  7: norm_outflow = 0.8079f * norm_inflow + 0.0815f; break;
        case  8: norm_outflow = 0.3077f * norm_inflow + 0.1333f; break;
        case  9: norm_outflow = 0.4158f * norm_inflow + 0.1096f; break;
        case 10: norm_outflow = 0.3325f * norm_inflow + 0.1050f; break;
        case 11: norm_outflow = 0.6433f * norm_inflow + 0.0871f; break;
        case 12: norm_outflow = 0.6925f * norm_inflow + 0.0943f; break;
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
        case  1: norm_outflow = 0.4271f * norm_inflow + 0.0121f; break;
        case  2: norm_outflow = 0.4725f * norm_inflow + 0.0106f; break;
        case  3: norm_outflow = 0.5248f * norm_inflow + 0.0095f; break;
        case  4: norm_outflow = 0.4249f * norm_inflow + 0.0123f; break;
        case  5: norm_outflow = 0.5789f * norm_inflow + 0.0046f; break;
        case  6: norm_outflow = 0.5141f * norm_inflow + 0.0027f; break;
        case  7: norm_outflow = 0.6201f * norm_inflow + 0.0011f; break;
        case  8: norm_outflow = 0.2950f * norm_inflow + 0.0020f; break;
        case  9: norm_outflow = 0.5255f * norm_inflow + 0.0018f; break;
        case 10: norm_outflow = 0.3672f * norm_inflow + 0.0031f; break;
        case 11: norm_outflow = 0.3060f * norm_inflow + 0.0049f; break;
        case 12: norm_outflow = 0.5113f * norm_inflow + 0.0036f; break;
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
        case  1: norm_outflow = 0.4505f * norm_inflow + 0.1107f; break;
        case  2: norm_outflow = 0.7659f * norm_inflow + 0.0269f; break;
        case  3: norm_outflow = 0.6675f * norm_inflow + 0.0037f; break;
        case  4: norm_outflow = 0.7146f * norm_inflow + -0.0408f; break;
        case  5: norm_outflow = 0.8378f * norm_inflow + -0.0222f; break;
        case  6: norm_outflow = 0.8419f * norm_inflow + 0.0185f; break;
        case  7: norm_outflow = 0.8211f * norm_inflow + 0.0431f; break;
        case  8: norm_outflow = 0.4285f * norm_inflow + 0.0939f; break;
        case  9: norm_outflow = 0.5422f * norm_inflow + 0.0781f; break;
        case 10: norm_outflow = 0.4894f * norm_inflow + 0.0792f; break;
        case 11: norm_outflow = 0.6063f * norm_inflow + 0.0823f; break;
        case 12: norm_outflow = 0.6873f * norm_inflow + 0.0679f; break;
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
        case  2: norm_outflow = (norm_storage <= 0.6294f) ? 0.0284f * norm_storage + 0.0000f : 0.5868f * norm_storage + (0.0284f * 0.6294f + 0.0000f - 0.5868f * 0.6294f); break;
        case  3: norm_outflow = (norm_storage <= 0.7338f) ? 0.0251f * norm_storage + 0.0000f : 0.8436f * norm_storage + (0.0251f * 0.7338f + 0.0000f - 0.8436f * 0.7338f); break;
        case  4: norm_outflow = 0.3637f * norm_inflow + 0.0071f; break;
        case  5: norm_outflow = 0.9442f * norm_inflow + 0.0045f; break;
        case  6: norm_outflow = 0.5195f * norm_inflow + 0.0091f; break;
        case  7: norm_outflow = 1.0743f * norm_inflow + 0.0073f; break;
        case  8: norm_outflow = 0.2863f * norm_inflow + 0.0096f; break;
        case  9: norm_outflow = 0.0724f * norm_inflow + 0.0098f; break;
        case 10: norm_outflow = (norm_storage <= 0.8609f) ? 0.0088f * norm_storage + 0.0047f : 0.9451f * norm_storage + (0.0088f * 0.8609f + 0.0047f - 0.9451f * 0.8609f); break;
        case 11: norm_outflow = 0.2753f * norm_inflow + 0.0207f; break;
        case 12: norm_outflow = (norm_storage <= 0.6500f) ? 0.0313f * norm_storage + 0.0037f : 0.9151f * norm_storage + (0.0313f * 0.6500f + 0.0037f - 0.9151f * 0.6500f); break;
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
        case  1: norm_outflow = (norm_storage <= 0.6451f) ? 0.0000f * norm_storage + 0.1752f : 1.7282f * norm_storage + (0.0000f * 0.6451f + 0.1752f - 1.7282f * 0.6451f); break;
        case  2: norm_outflow = (norm_storage <= 0.6337f) ? 0.0486f * norm_storage + 0.0850f : 2.6399f * norm_storage + (0.0486f * 0.6337f + 0.0850f - 2.6399f * 0.6337f); break;
        case  3: norm_outflow = 0.1996f * norm_inflow + 0.1007f; break;
        case  4: norm_outflow = (norm_storage <= 0.8620f) ? 0.0863f * norm_storage + 0.0000f : 10.7082f * norm_storage + (0.0863f * 0.8620f + 0.0000f - 10.7082f * 0.8620f); break;
        case  5: norm_outflow = (norm_storage <= 0.9476f) ? 0.0397f * norm_storage + 0.0000f : 14.8134f * norm_storage + (0.0397f * 0.9476f + 0.0000f - 14.8134f * 0.9476f); break;
        case  6: norm_outflow = 1.3912f * norm_inflow + 0.0704f; break;
        case  7: norm_outflow = 2.0934f * norm_inflow + 0.0573f; break;
        case  8: norm_outflow = 0.4801f * norm_inflow + 0.1276f; break;
        case  9: norm_outflow = (norm_storage <= 0.9012f) ? 0.1000f * norm_storage + 0.0548f : 6.4577f * norm_storage + (0.1000f * 0.9012f + 0.0548f - 6.4577f * 0.9012f); break;
        case 10: norm_outflow = (norm_storage <= 1.0000f) ? 0.5273f * norm_storage + -0.2454f : 0.0000f * norm_storage + (0.5273f * 1.0000f + -0.2454f - 0.0000f * 1.0000f); break;
        case 11: norm_outflow = (norm_storage <= 1.0000f) ? 1.4248f * norm_storage + -0.8310f : 0.0000f * norm_storage + (1.4248f * 1.0000f + -0.8310f - 0.0000f * 1.0000f); break;
        case 12: norm_outflow = (norm_storage <= 1.0000f) ? 2.2806f * norm_storage + -1.3188f : 0.0000f * norm_storage + (2.2806f * 1.0000f + -1.3188f - 0.0000f * 1.0000f); break;
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
        case  1: norm_outflow = 0.3086f * norm_inflow + 0.1624f; break;
        case  2: norm_outflow = 0.5073f * norm_inflow + 0.1352f; break;
        case  3: norm_outflow = 0.3698f * norm_inflow + 0.0963f; break;
        case  4: norm_outflow = 0.4629f * norm_inflow + 0.0419f; break;
        case  5: norm_outflow = 0.9100f * norm_inflow + 0.0467f; break;
        case  6: norm_outflow = 1.8243f * norm_inflow + 0.0679f; break;
        case  7: norm_outflow = 1.5743f * norm_inflow + 0.0943f; break;
        case  8: norm_outflow = 1.0735f * norm_inflow + 0.1312f; break;
        case  9: norm_outflow = 0.5948f * norm_inflow + 0.1317f; break;
        case 10: norm_outflow = 0.3699f * norm_inflow + 0.1381f; break;
        case 11: norm_outflow = 0.4369f * norm_inflow + 0.1314f; break;
        case 12: norm_outflow = 0.4521f * norm_inflow + 0.1597f; break;
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
        case  1: norm_outflow = 0.2352f * norm_inflow + 0.2146f; break;
        case  2: norm_outflow = (norm_storage <= 1.0000f) ? 0.9804f * norm_storage + -0.2629f : 0.0000f * norm_storage + (0.9804f * 1.0000f + -0.2629f - 0.0000f * 1.0000f); break;
        case  3: norm_outflow = 0.2726f * norm_inflow + 0.1320f; break;
        case  4: norm_outflow = (norm_storage <= 0.7356f) ? 0.1000f * norm_storage + 0.0028f : 1.0670f * norm_storage + (0.1000f * 0.7356f + 0.0028f - 1.0670f * 0.7356f); break;
        case  5: norm_outflow = (norm_storage <= 0.8833f) ? 0.0758f * norm_storage + 0.0122f : 2.6417f * norm_storage + (0.0758f * 0.8833f + 0.0122f - 2.6417f * 0.8833f); break;
        case  6: norm_outflow = (norm_storage <= 0.9006f) ? 0.1000f * norm_storage + 0.0390f : 2.4588f * norm_storage + (0.1000f * 0.9006f + 0.0390f - 2.4588f * 0.9006f); break;
        case  7: norm_outflow = 1.6655f * norm_inflow + 0.1403f; break;
        case  8: norm_outflow = (norm_storage <= 1.0000f) ? 0.3055f * norm_storage + -0.0368f : 0.0000f * norm_storage + (0.3055f * 1.0000f + -0.0368f - 0.0000f * 1.0000f); break;
        case  9: norm_outflow = (norm_storage <= 1.0000f) ? 0.3914f * norm_storage + -0.0825f : 0.0000f * norm_storage + (0.3914f * 1.0000f + -0.0825f - 0.0000f * 1.0000f); break;
        case 10: norm_outflow = (norm_storage <= 1.0000f) ? 0.5260f * norm_storage + -0.1321f : 0.0000f * norm_storage + (0.5260f * 1.0000f + -0.1321f - 0.0000f * 1.0000f); break;
        case 11: norm_outflow = (norm_storage <= 0.6015f) ? 0.1000f * norm_storage + 0.1220f : 2.2800f * norm_storage + (0.1000f * 0.6015f + 0.1220f - 2.2800f * 0.6015f); break;
        case 12: norm_outflow = (norm_storage <= 1.0000f) ? 0.6604f * norm_storage + -0.0950f : 0.0000f * norm_storage + (0.6604f * 1.0000f + -0.0950f - 0.0000f * 1.0000f); break;
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
        case  1: norm_outflow = (norm_storage <= 1.0000f) ? 1.7785f * norm_storage + -0.7156f : 0.0000f * norm_storage + (1.7785f * 1.0000f + -0.7156f - 0.0000f * 1.0000f); break;
        case  2: norm_outflow = 0.8699f * norm_inflow + 0.0381f; break;
        case  3: norm_outflow = 0.7715f * norm_inflow + 0.0111f; break;
        case  4: norm_outflow = 0.7849f * norm_inflow + -0.0371f; break;
        case  5: norm_outflow = 0.9383f * norm_inflow + -0.0142f; break;
        case  6: norm_outflow = 0.9985f * norm_inflow + 0.0253f; break;
        case  7: norm_outflow = 0.9321f * norm_inflow + 0.0535f; break;
        case  8: norm_outflow = 0.5784f * norm_inflow + 0.1010f; break;
        case  9: norm_outflow = 0.6465f * norm_inflow + 0.0902f; break;
        case 10: norm_outflow = 0.5800f * norm_inflow + 0.0937f; break;
        case 11: norm_outflow = 0.6834f * norm_inflow + 0.0983f; break;
        case 12: norm_outflow = 0.7633f * norm_inflow + 0.0818f; break;
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
        case  1: norm_outflow = 0.2077f * norm_inflow + 0.0369f; break;
        case  2: norm_outflow = (norm_storage <= 1.0000f) ? 0.7800f * norm_storage + -0.5418f : 0.0000f * norm_storage + (0.7800f * 1.0000f + -0.5418f - 0.0000f * 1.0000f); break;
        case  3: norm_outflow = (norm_storage <= 0.7903f) ? 0.0024f * norm_storage + 0.0415f : 1.2045f * norm_storage + (0.0024f * 0.7903f + 0.0415f - 1.2045f * 0.7903f); break;
        case  4: norm_outflow = 0.3098f * norm_inflow + 0.0278f; break;
        case  5: norm_outflow = 0.4663f * norm_inflow + 0.0266f; break;
        case  6: norm_outflow = 0.4605f * norm_inflow + 0.0248f; break;
        case  7: norm_outflow = 0.4049f * norm_inflow + 0.0266f; break;
        case  8: norm_outflow = 0.3453f * norm_inflow + 0.0291f; break;
        case  9: norm_outflow = 0.1921f * norm_inflow + 0.0302f; break;
        case 10: norm_outflow = 0.1874f * norm_inflow + 0.0282f; break;
        case 11: norm_outflow = 0.1833f * norm_inflow + 0.0300f; break;
        case 12: norm_outflow = 0.2436f * norm_inflow + 0.0332f; break;
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
        case  1: norm_outflow = (norm_storage <= 1.0000f) ? 1.7176f * norm_storage + -0.9163f : 0.0000f * norm_storage + (1.7176f * 1.0000f + -0.9163f - 0.0000f * 1.0000f); break;
        case  2: norm_outflow = 0.8367f * norm_inflow + 0.0082f; break;
        case  3: norm_outflow = 0.7880f * norm_inflow + -0.0139f; break;
        case  4: norm_outflow = 0.7201f * norm_inflow + -0.0286f; break;
        case  5: norm_outflow = (norm_storage <= 0.7677f) ? 0.0819f * norm_storage + 0.0000f : 3.1900f * norm_storage + (0.0819f * 0.7677f + 0.0000f - 3.1900f * 0.7677f); break;
        case  6: norm_outflow = 0.8765f * norm_inflow + 0.0099f; break;
        case  7: norm_outflow = 0.7379f * norm_inflow + 0.0316f; break;
        case  8: norm_outflow = 0.5550f * norm_inflow + 0.0547f; break;
        case  9: norm_outflow = (norm_storage <= 0.7488f) ? 0.0227f * norm_storage + 0.0571f : 2.0598f * norm_storage + (0.0227f * 0.7488f + 0.0571f - 2.0598f * 0.7488f); break;
        case 10: norm_outflow = 0.5023f * norm_inflow + 0.0572f; break;
        case 11: norm_outflow = 0.5980f * norm_inflow + 0.0675f; break;
        case 12: norm_outflow = 0.7678f * norm_inflow + 0.0367f; break;
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
        case  1: norm_outflow = (norm_storage <= 1.0000f) ? 0.6667f * norm_storage + -0.2615f : 0.0000f * norm_storage + (0.6667f * 1.0000f + -0.2615f - 0.0000f * 1.0000f); break;
        case  2: norm_outflow = (norm_storage <= 1.0000f) ? 0.8588f * norm_storage + -0.4279f : 0.0000f * norm_storage + (0.8588f * 1.0000f + -0.4279f - 0.0000f * 1.0000f); break;
        case  3: norm_outflow = (norm_storage <= 0.8538f) ? 0.0985f * norm_storage + 0.0267f : 12.4842f * norm_storage + (0.0985f * 0.8538f + 0.0267f - 12.4842f * 0.8538f); break;
        case  4: norm_outflow = (norm_storage <= 1.0000f) ? 0.5741f * norm_storage + -0.4014f : 0.0000f * norm_storage + (0.5741f * 1.0000f + -0.4014f - 0.0000f * 1.0000f); break;
        case  5: norm_outflow = (norm_storage <= 1.0000f) ? 0.8327f * norm_storage + -0.6410f : 0.0000f * norm_storage + (0.8327f * 1.0000f + -0.6410f - 0.0000f * 1.0000f); break;
        case  6: norm_outflow = (norm_storage <= 0.9161f) ? 0.0167f * norm_storage + 0.0649f : 3.2888f * norm_storage + (0.0167f * 0.9161f + 0.0649f - 3.2888f * 0.9161f); break;
        case  7: norm_outflow = 1.5995f * norm_inflow + 0.1145f; break;
        case  8: norm_outflow = 1.2588f * norm_inflow + 0.1472f; break;
        case  9: norm_outflow = (norm_storage <= 1.0000f) ? 0.6749f * norm_storage + -0.3805f : 0.0000f * norm_storage + (0.6749f * 1.0000f + -0.3805f - 0.0000f * 1.0000f); break;
        case 10: norm_outflow = (norm_storage <= 1.0000f) ? 0.7796f * norm_storage + -0.4310f : 0.0000f * norm_storage + (0.7796f * 1.0000f + -0.4310f - 0.0000f * 1.0000f); break;
        case 11: norm_outflow = (norm_storage <= 1.0000f) ? 0.9013f * norm_storage + -0.4988f : 0.0000f * norm_storage + (0.9013f * 1.0000f + -0.4988f - 0.0000f * 1.0000f); break;
        case 12: norm_outflow = (norm_storage <= 1.0000f) ? 1.1100f * norm_storage + -0.5847f : 0.0000f * norm_storage + (1.1100f * 1.0000f + -0.5847f - 0.0000f * 1.0000f); break;
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
        case  1: norm_outflow = (norm_storage <= 1.0000f) ? 3.4358f * norm_storage + -1.9379f : 0.0000f * norm_storage + (3.4358f * 1.0000f + -1.9379f - 0.0000f * 1.0000f); break;
        case  2: norm_outflow = (norm_storage <= 1.0000f) ? 3.6707f * norm_storage + -2.0942f : 0.0000f * norm_storage + (3.6707f * 1.0000f + -2.0942f - 0.0000f * 1.0000f); break;
        case  3: norm_outflow = 0.6138f * norm_inflow + 0.0249f; break;
        case  4: norm_outflow = 0.6514f * norm_inflow + -0.0246f; break;
        case  5: norm_outflow = (norm_storage <= 1.0000f) ? 2.9929f * norm_storage + -1.7348f : 0.0000f * norm_storage + (2.9929f * 1.0000f + -1.7348f - 0.0000f * 1.0000f); break;
        case  6: norm_outflow = 0.8391f * norm_inflow + 0.0240f; break;
        case  7: norm_outflow = 0.7649f * norm_inflow + 0.0488f; break;
        case  8: norm_outflow = 0.5298f * norm_inflow + 0.0845f; break;
        case  9: norm_outflow = (norm_storage <= 0.6128f) ? 0.0294f * norm_storage + 0.0726f : 3.3716f * norm_storage + (0.0294f * 0.6128f + 0.0726f - 3.3716f * 0.6128f); break;
        case 10: norm_outflow = 0.4861f * norm_inflow + 0.0804f; break;
        case 11: norm_outflow = 0.6023f * norm_inflow + 0.0864f; break;
        case 12: norm_outflow = 0.6311f * norm_inflow + 0.0755f; break;
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
        case  1: norm_outflow = 0.1794f * norm_inflow + 0.1753f; break;
        case  2: norm_outflow = 0.4666f * norm_inflow + 0.1309f; break;
        case  3: norm_outflow = 0.2965f * norm_inflow + 0.0952f; break;
        case  4: norm_outflow = (norm_storage <= 1.0000f) ? 0.4312f * norm_storage + -0.2531f : 0.0000f * norm_storage + (0.4312f * 1.0000f + -0.2531f - 0.0000f * 1.0000f); break;
        case  5: norm_outflow = (norm_storage <= 0.8917f) ? 0.0054f * norm_storage + 0.0305f : 3.0894f * norm_storage + (0.0054f * 0.8917f + 0.0305f - 3.0894f * 0.8917f); break;
        case  6: norm_outflow = (norm_storage <= 0.8816f) ? 0.0000f * norm_storage + 0.0668f : 1.9560f * norm_storage + (0.0000f * 0.8816f + 0.0668f - 1.9560f * 0.8816f); break;
        case  7: norm_outflow = 1.4221f * norm_inflow + 0.1452f; break;
        case  8: norm_outflow = 0.9824f * norm_inflow + 0.1833f; break;
        case  9: norm_outflow = (norm_storage <= 1.0000f) ? 0.4682f * norm_storage + -0.1511f : 0.0000f * norm_storage + (0.4682f * 1.0000f + -0.1511f - 0.0000f * 1.0000f); break;
        case 10: norm_outflow = (norm_storage <= 1.0000f) ? 0.4321f * norm_storage + -0.0955f : 0.0000f * norm_storage + (0.4321f * 1.0000f + -0.0955f - 0.0000f * 1.0000f); break;
        case 11: norm_outflow = 0.2653f * norm_inflow + 0.1670f; break;
        case 12: norm_outflow = 0.4362f * norm_inflow + 0.1942f; break;
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
        case  1: norm_outflow = (norm_storage <= 0.6321f) ? 0.1000f * norm_storage + 0.0381f : 1.0019f * norm_storage + (0.1000f * 0.6321f + 0.0381f - 1.0019f * 0.6321f); break;
        case  2: norm_outflow = (norm_storage <= 0.6829f) ? 0.0752f * norm_storage + 0.0277f : 1.7571f * norm_storage + (0.0752f * 0.6829f + 0.0277f - 1.7571f * 0.6829f); break;
        case  3: norm_outflow = (norm_storage <= 0.7999f) ? 0.0255f * norm_storage + 0.0406f : 2.1475f * norm_storage + (0.0255f * 0.7999f + 0.0406f - 2.1475f * 0.7999f); break;
        case  4: norm_outflow = (norm_storage <= 0.7990f) ? 0.0237f * norm_storage + 0.0119f : 1.1144f * norm_storage + (0.0237f * 0.7990f + 0.0119f - 1.1144f * 0.7990f); break;
        case  5: norm_outflow = (norm_storage <= 1.0000f) ? 0.4688f * norm_storage + -0.3118f : 0.0000f * norm_storage + (0.4688f * 1.0000f + -0.3118f - 0.0000f * 1.0000f); break;
        case  6: norm_outflow = 0.8648f * norm_inflow + 0.0890f; break;
        case  7: norm_outflow = (norm_storage <= 0.9274f) ? 0.0000f * norm_storage + 0.1068f : 4.7191f * norm_storage + (0.0000f * 0.9274f + 0.1068f - 4.7191f * 0.9274f); break;
        case  8: norm_outflow = 0.5477f * norm_inflow + 0.1261f; break;
        case  9: norm_outflow = 0.2177f * norm_inflow + 0.1244f; break;
        case 10: norm_outflow = (norm_storage <= 0.7218f) ? 0.0000f * norm_storage + 0.1067f : 0.8703f * norm_storage + (0.0000f * 0.7218f + 0.1067f - 0.8703f * 0.7218f); break;
        case 11: norm_outflow = (norm_storage <= 1.0000f) ? 0.1343f * norm_storage + 0.0180f : 0.0000f * norm_storage + (0.1343f * 1.0000f + 0.0180f - 0.0000f * 1.0000f); break;
        case 12: norm_outflow = (norm_storage <= 0.6552f) ? 0.1000f * norm_storage + 0.0407f : 1.4129f * norm_storage + (0.1000f * 0.6552f + 0.0407f - 1.4129f * 0.6552f); break;
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
        case  1: norm_outflow = (norm_storage <= 1.0000f) ? 1.5994f * norm_storage + -0.6874f : 0.0000f * norm_storage + (1.5994f * 1.0000f + -0.6874f - 0.0000f * 1.0000f); break;
        case  2: norm_outflow = 0.7275f * norm_inflow + 0.0139f; break;
        case  3: norm_outflow = 0.6842f * norm_inflow + -0.0075f; break;
        case  4: norm_outflow = 0.6275f * norm_inflow + -0.0279f; break;
        case  5: norm_outflow = (norm_storage <= 0.6499f) ? 0.0837f * norm_storage + 0.0000f : 3.4928f * norm_storage + (0.0837f * 0.6499f + 0.0000f - 3.4928f * 0.6499f); break;
        case  6: norm_outflow = 0.7763f * norm_inflow + 0.0130f; break;
        case  7: norm_outflow = (norm_storage <= 0.6614f) ? 0.1000f * norm_storage + 0.0079f : 4.0748f * norm_storage + (0.1000f * 0.6614f + 0.0079f - 4.0748f * 0.6614f); break;
        case  8: norm_outflow = 0.5135f * norm_inflow + 0.0603f; break;
        case  9: norm_outflow = (norm_storage <= 0.6616f) ? 0.1000f * norm_storage + 0.0228f : 5.2334f * norm_storage + (0.1000f * 0.6616f + 0.0228f - 5.2334f * 0.6616f); break;
        case 10: norm_outflow = (norm_storage <= 0.6000f) ? 0.1000f * norm_storage + 0.0259f : 2.9043f * norm_storage + (0.1000f * 0.6000f + 0.0259f - 2.9043f * 0.6000f); break;
        case 11: norm_outflow = 0.5578f * norm_inflow + 0.0697f; break;
        case 12: norm_outflow = (norm_storage <= 1.0000f) ? 1.8106f * norm_storage + -0.8059f : 0.0000f * norm_storage + (1.8106f * 1.0000f + -0.8059f - 0.0000f * 1.0000f); break;
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
        case  1: norm_outflow = (norm_storage <= 1.0000f) ? 0.5831f * norm_storage + -0.1518f : 0.0000f * norm_storage + (0.5831f * 1.0000f + -0.1518f - 0.0000f * 1.0000f); break;
        case  2: norm_outflow = (norm_storage <= 1.0000f) ? 0.4573f * norm_storage + -0.1604f : 0.0000f * norm_storage + (0.4573f * 1.0000f + -0.1604f - 0.0000f * 1.0000f); break;
        case  3: norm_outflow = (norm_storage <= 0.6000f) ? 0.0429f * norm_storage + 0.0000f : 0.9815f * norm_storage + (0.0429f * 0.6000f + 0.0000f - 0.9815f * 0.6000f); break;
        case  4: norm_outflow = (norm_storage <= 0.7212f) ? 0.0153f * norm_storage + 0.0000f : 1.4238f * norm_storage + (0.0153f * 0.7212f + 0.0000f - 1.4238f * 0.7212f); break;
        case  5: norm_outflow = (norm_storage <= 0.7413f) ? 0.0167f * norm_storage + 0.0000f : 1.7184f * norm_storage + (0.0167f * 0.7413f + 0.0000f - 1.7184f * 0.7413f); break;
        case  6: norm_outflow = (norm_storage <= 0.7378f) ? 0.0083f * norm_storage + 0.0000f : 1.3835f * norm_storage + (0.0083f * 0.7378f + 0.0000f - 1.3835f * 0.7378f); break;
        case  7: norm_outflow = 0.9645f * norm_inflow + 0.0100f; break;
        case  8: norm_outflow = 0.6342f * norm_inflow + 0.0077f; break;
        case  9: norm_outflow = 1.1432f * norm_inflow + 0.0107f; break;
        case 10: norm_outflow = 0.3646f * norm_inflow + 0.0319f; break;
        case 11: norm_outflow = 0.3420f * norm_inflow + 0.0820f; break;
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
        case  1: norm_outflow = (norm_storage <= 1.0000f) ? 0.7697f * norm_storage + -0.3425f : 0.0000f * norm_storage + (0.7697f * 1.0000f + -0.3425f - 0.0000f * 1.0000f); break;
        case  2: norm_outflow = (norm_storage <= 0.6064f) ? 0.0476f * norm_storage + 0.0000f : 1.0630f * norm_storage + (0.0476f * 0.6064f + 0.0000f - 1.0630f * 0.6064f); break;
        case  3: norm_outflow = (norm_storage <= 0.7385f) ? 0.0402f * norm_storage + 0.0000f : 1.8508f * norm_storage + (0.0402f * 0.7385f + 0.0000f - 1.8508f * 0.7385f); break;
        case  4: norm_outflow = (norm_storage <= 0.8382f) ? 0.0261f * norm_storage + 0.0000f : 3.7791f * norm_storage + (0.0261f * 0.8382f + 0.0000f - 3.7791f * 0.8382f); break;
        case  5: norm_outflow = 1.2114f * norm_inflow + 0.0289f; break;
        case  6: norm_outflow = 1.1341f * norm_inflow + 0.0154f; break;
        case  7: norm_outflow = 0.9914f * norm_inflow + 0.0104f; break;
        case  8: norm_outflow = 0.5346f * norm_inflow + 0.0075f; break;
        case  9: norm_outflow = 2.0194f * norm_inflow + 0.0113f; break;
        case 10: norm_outflow = (norm_storage <= 0.8438f) ? 0.0000f * norm_storage + 0.0277f : 3.6373f * norm_storage + (0.0000f * 0.8438f + 0.0277f - 3.6373f * 0.8438f); break;
        case 11: norm_outflow = 0.3458f * norm_inflow + 0.0773f; break;
        case 12: norm_outflow = (norm_storage <= 1.0000f) ? 0.6659f * norm_storage + -0.2755f : 0.0000f * norm_storage + (0.6659f * 1.0000f + -0.2755f - 0.0000f * 1.0000f); break;
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
        case  1: norm_outflow = (norm_storage <= 1.0000f) ? 2.6520f * norm_storage + -1.5148f : 0.0000f * norm_storage + (2.6520f * 1.0000f + -1.5148f - 0.0000f * 1.0000f); break;
        case  2: norm_outflow = (norm_storage <= 1.0000f) ? 2.7950f * norm_storage + -1.6060f : 0.0000f * norm_storage + (2.7950f * 1.0000f + -1.6060f - 0.0000f * 1.0000f); break;
        case  3: norm_outflow = (norm_storage <= 1.0000f) ? 2.7193f * norm_storage + -1.5756f : 0.0000f * norm_storage + (2.7193f * 1.0000f + -1.5756f - 0.0000f * 1.0000f); break;
        case  4: norm_outflow = 0.6667f * norm_inflow + -0.0255f; break;
        case  5: norm_outflow = (norm_storage <= 1.0000f) ? 3.1852f * norm_storage + -2.0280f : 0.0000f * norm_storage + (3.1852f * 1.0000f + -2.0280f - 0.0000f * 1.0000f); break;
        case  6: norm_outflow = (norm_storage <= 0.6678f) ? 0.0843f * norm_storage + 0.0210f : 4.3233f * norm_storage + (0.0843f * 0.6678f + 0.0210f - 4.3233f * 0.6678f); break;
        case  7: norm_outflow = 0.7200f * norm_inflow + 0.0445f; break;
        case  8: norm_outflow = 0.5230f * norm_inflow + 0.0755f; break;
        case  9: norm_outflow = (norm_storage <= 0.6689f) ? 0.1000f * norm_storage + 0.0273f : 3.6997f * norm_storage + (0.1000f * 0.6689f + 0.0273f - 3.6997f * 0.6689f); break;
        case 10: norm_outflow = 0.4608f * norm_inflow + 0.0760f; break;
        case 11: norm_outflow = 0.6742f * norm_inflow + 0.0781f; break;
        case 12: norm_outflow = (norm_storage <= 1.0000f) ? 2.6334f * norm_storage + -1.5115f : 0.0000f * norm_storage + (2.6334f * 1.0000f + -1.5115f - 0.0000f * 1.0000f); break;
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
        case  1: norm_outflow = 0.6301f * norm_inflow + 0.0196f; break;
        case  2: norm_outflow = 0.8390f * norm_inflow + 0.0148f; break;
        case  3: norm_outflow = 0.7387f * norm_inflow + 0.0204f; break;
        case  4: norm_outflow = (norm_storage <= 0.8050f) ? 0.0268f * norm_storage + 0.0025f : 2.6014f * norm_storage + (0.0268f * 0.8050f + 0.0025f - 2.6014f * 0.8050f); break;
        case  5: norm_outflow = 1.0179f * norm_inflow + 0.0109f; break;
        case  6: norm_outflow = 0.7873f * norm_inflow + 0.0086f; break;
        case  7: norm_outflow = 0.8308f * norm_inflow + 0.0061f; break;
        case  8: norm_outflow = 0.1149f * norm_inflow + 0.0054f; break;
        case  9: norm_outflow = 0.6654f * norm_inflow + 0.0054f; break;
        case 10: norm_outflow = (norm_storage <= 0.7856f) ? 0.0085f * norm_storage + 0.0000f : 2.5000f * norm_storage + (0.0085f * 0.7856f + 0.0000f - 2.5000f * 0.7856f); break;
        case 11: norm_outflow = 0.6772f * norm_inflow + 0.0069f; break;
        case 12: norm_outflow = 0.7554f * norm_inflow + 0.0135f; break;
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
        case  1: norm_outflow = 0.4712f * norm_inflow + 0.1106f; break;
        case  2: norm_outflow = 0.7079f * norm_inflow + 0.0062f; break;
        case  3: norm_outflow = 0.6700f * norm_inflow + -0.0142f; break;
        case  4: norm_outflow = 0.5993f * norm_inflow + -0.0287f; break;
        case  5: norm_outflow = 0.7172f * norm_inflow + -0.0197f; break;
        case  6: norm_outflow = 0.7474f * norm_inflow + 0.0085f; break;
        case  7: norm_outflow = 0.6162f * norm_inflow + 0.0310f; break;
        case  8: norm_outflow = 0.4712f * norm_inflow + 0.0539f; break;
        case  9: norm_outflow = 0.3899f * norm_inflow + 0.0575f; break;
        case 10: norm_outflow = 0.4348f * norm_inflow + 0.0549f; break;
        case 11: norm_outflow = 0.5297f * norm_inflow + 0.0619f; break;
        case 12: norm_outflow = 0.6459f * norm_inflow + 0.0333f; break;
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
        case  2: norm_outflow = 0.9973f * norm_inflow + 0.1345f; break;
        case  3: norm_outflow = 0.5445f * norm_inflow + 0.1510f; break;
        case  4: norm_outflow = 0.3291f * norm_inflow + 0.1616f; break;
        case  5: norm_outflow = 0.4834f * norm_inflow + 0.1221f; break;
        case  6: norm_outflow = 1.2202f * norm_inflow + -0.0747f; break;
        case  7: norm_outflow = (norm_storage <= 0.9303f) ? 0.1000f * norm_storage + 0.0604f : 7.0566f * norm_storage + (0.1000f * 0.9303f + 0.0604f - 7.0566f * 0.9303f); break;
        case  8: norm_outflow = (norm_storage <= 0.8274f) ? 0.1000f * norm_storage + 0.0505f : 0.8653f * norm_storage + (0.1000f * 0.8274f + 0.0505f - 0.8653f * 0.8274f); break;
        case  9: norm_outflow = 0.4215f * norm_inflow + 0.0933f; break;
        case 10: norm_outflow = 0.5373f * norm_inflow + 0.0922f; break;
        case 11: norm_outflow = (norm_storage <= 1.0000f) ? 0.4846f * norm_storage + -0.2300f : 0.0000f * norm_storage + (0.4846f * 1.0000f + -0.2300f - 0.0000f * 1.0000f); break;
        case 12: norm_outflow = 0.9627f * norm_inflow + 0.1102f; break;
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
        case  1: norm_outflow = (norm_storage <= 0.6358f) ? 0.0000f * norm_storage + 0.0270f : 0.6529f * norm_storage + (0.0000f * 0.6358f + 0.0270f - 0.6529f * 0.6358f); break;
        case  2: norm_outflow = (norm_storage <= 0.6933f) ? 0.0398f * norm_storage + 0.0000f : 1.0381f * norm_storage + (0.0398f * 0.6933f + 0.0000f - 1.0381f * 0.6933f); break;
        case  3: norm_outflow = (norm_storage <= 1.0000f) ? 0.6020f * norm_storage + -0.4083f : 0.0000f * norm_storage + (0.6020f * 1.0000f + -0.4083f - 0.0000f * 1.0000f); break;
        case  4: norm_outflow = (norm_storage <= 1.0000f) ? 0.5437f * norm_storage + -0.4068f : 0.0000f * norm_storage + (0.5437f * 1.0000f + -0.4068f - 0.0000f * 1.0000f); break;
        case  5: norm_outflow = (norm_storage <= 1.0000f) ? 0.6048f * norm_storage + -0.4848f : 0.0000f * norm_storage + (0.6048f * 1.0000f + -0.4848f - 0.0000f * 1.0000f); break;
        case  6: norm_outflow = 0.9231f * norm_inflow + 0.0137f; break;
        case  7: norm_outflow = 1.3983f * norm_inflow + 0.0112f; break;
        case  8: norm_outflow = 0.5738f * norm_inflow + 0.0138f; break;
        case  9: norm_outflow = 0.1030f * norm_inflow + 0.0132f; break;
        case 10: norm_outflow = 0.4506f * norm_inflow + 0.0256f; break;
        case 11: norm_outflow = 0.1664f * norm_inflow + 0.0453f; break;
        case 12: norm_outflow = (norm_storage <= 0.7237f) ? 0.0824f * norm_storage + 0.0000f : 1.2524f * norm_storage + (0.0824f * 0.7237f + 0.0000f - 1.2524f * 0.7237f); break;
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
        case  1: norm_outflow = 0.3321f * norm_inflow + 0.1610f; break;
        case  2: norm_outflow = 0.6693f * norm_inflow + 0.0953f; break;
        case  3: norm_outflow = 0.8454f * norm_inflow + 0.0739f; break;
        case  4: norm_outflow = 0.9420f * norm_inflow + 0.0563f; break;
        case  5: norm_outflow = 0.7936f * norm_inflow + 0.0716f; break;
        case  6: norm_outflow = 1.1238f * norm_inflow + 0.0692f; break;
        case  7: norm_outflow = 1.1593f * norm_inflow + 0.0766f; break;
        case  8: norm_outflow = 1.4135f * norm_inflow + 0.0844f; break;
        case  9: norm_outflow = 0.8130f * norm_inflow + 0.0757f; break;
        case 10: norm_outflow = 0.6000f * norm_inflow + 0.0631f; break;
        case 11: norm_outflow = 0.3279f * norm_inflow + 0.0760f; break;
        case 12: norm_outflow = 0.3431f * norm_inflow + 0.1065f; break;
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

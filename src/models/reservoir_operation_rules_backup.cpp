#include "reservoir_operation_rules.hpp"

#include <stdexcept>
#include <string>

// ---- Per-reservoir rule functions ---- 
// rule_{GDW_ID} - Define the operation rule for reservoir with GDW ID {GDW_ID}
// default as run-of-river (i.e., outflow = inflow) if no rule is defined for a reservoir
// static float rule_21(float inflow_m3d, float storage_m3, int month) {
//     const float max_inflow_m3d = 513780883.0f;
//     const float max_outflow_m3d = 392186888.0f;
//     const float max_storage_m3 = 28330568640.0f;
//     const float norm_inflow = inflow_m3d / max_inflow_m3d;
//     const float norm_storage = storage_m3 / max_storage_m3;
//     float norm_outflow;

//     switch (month) {
//         case 1: norm_outflow = (norm_storage <= 1.0000f) ? 0.1861f * norm_storage - 0.0053f : 0.0000f * norm_storage + (0.1861f * 1.0000f - 0.0053f - 0.0000f * 1.0000f); break;
//         case 2: norm_outflow = 0.1929f * norm_inflow + 0.0855f; break;
//         case 3: norm_outflow = (norm_storage <= 0.9203f) ? 0.0769f * norm_storage + 0.0483f : 4.6324f * norm_storage + (0.0769f * 0.9203f + 0.0483f - 4.6324f * 0.9203f); break;
//         case 4: norm_outflow = (norm_storage <= 0.9414f) ? 0.0184f * norm_storage + 0.1065f : 6.9573f * norm_storage + (0.0184f * 0.9414f + 0.1065f - 6.9573f * 0.9414f); break;
//         case 5: norm_outflow = 0.4024f * norm_inflow + 0.0792f; break;
//         case 6: norm_outflow = 1.0278f * norm_inflow + 0.0160f; break;
//         case 7: norm_outflow = 1.1502f * norm_inflow + 0.0378f; break;
//         case 8: norm_outflow = 1.3243f * norm_inflow + 0.0492f; break;
//         case 9: norm_outflow = 1.2299f * norm_inflow + 0.0623f; break;
//         case 10: norm_outflow = 1.2823f * norm_inflow + 0.0364f; break;
//         case 11: norm_outflow = 1.4500f * norm_inflow + 0.0170f; break;
//         case 12: norm_outflow = (norm_storage <= 0.7534f) ? 0.0430f * norm_storage + 0.0706f : 0.7201f * norm_storage + (0.0430f * 0.7534f + 0.0706f - 0.7201f * 0.7534f); break;
//     }
//     return norm_outflow * max_outflow_m3d;
// }

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

// static float rule_104(float inflow_m3d, float storage_m3, int month) {
//     const float max_inflow_m3d = 383733958.0f;
//     const float max_outflow_m3d = 161229551.0f;
//     const float max_storage_m3 = 23458310589.0f;
//     const float norm_inflow = inflow_m3d / max_inflow_m3d;
//     const float norm_storage = storage_m3 / max_storage_m3;
//     float norm_outflow;

//     switch (month) {
//         case 1: norm_outflow = (norm_storage <= 1.0000f) ? 0.1633f * norm_storage + 0.0331f : 0.0000f * norm_storage + (0.1632f * 1.0000f + 0.0331f - 0.0000f * 1.0000f); break;
//         case 2: norm_outflow = (norm_storage <= 0.7812f) ? 0.0992f * norm_storage + 0.0679f : 0.9496f * norm_storage + (0.0992f * 0.7812f + 0.0679f - 0.9496f * 0.7812f); break;
//         case 3: norm_outflow = (norm_storage <= 1.0000f) ? 0.0856f * norm_storage + 0.0423f : 0.0000f * norm_storage + (0.0856f * 1.0000f + 0.0423f - 0.0000f * 1.0000f); break;
//         case 4: norm_outflow = 0.3445f * norm_inflow + 0.080f; break;
//         case 5: norm_outflow = (norm_storage <= 0.8486f) ? 0.0773f * norm_storage + 0.0694f : 1.4292f * norm_storage + (0.0773f * 0.8486f + 0.0694f - 1.4292f * 0.8486f); break;
//         case 6: norm_outflow = (norm_storage <= 0.9586f) ? 0.1000f * norm_storage + 0.0617f : 22.3466f * norm_storage + (0.1000f * 0.9586f + 0.0617f - 22.3466f * 0.9586f); break;
//         case 7: norm_outflow = (norm_storage <= 0.8752f) ? 0.1000f * norm_storage + 0.0514f : 2.0444f * norm_storage + (0.1000f * 0.8752f + 0.0514f - 2.0444f * 0.8752f); break;
//         case 8: norm_outflow = (norm_storage <= 0.8150f) ? 0.0589f * norm_storage + 0.0761f : 1.0617f * norm_storage + (0.0589f * 0.8150f + 0.0761f - 1.0617f * 0.8150f); break;
//         case 9: norm_outflow = (norm_storage <= 0.8010f) ? 0.0404f * norm_storage + 0.0672f : 1.3071f * norm_storage + (0.0404f * 0.8010f + 0.0672f - 1.3071f * 0.8010f); break;
//         case 10: norm_outflow = (norm_storage <= 0.8129f) ? 0.0570f * norm_storage + 0.0445f : 1.6196f * norm_storage + (0.0570f * 0.8129f + 0.0445f - 1.6196f * 0.8129f); break;
//         case 11: norm_outflow = (norm_storage <= 0.7880f) ? 0.0583f * norm_storage + 0.0501f : 1.1140f * norm_storage + (0.0583f * 0.7880f + 0.0501f - 1.1140f * 0.7880f); break;
//         case 12: norm_outflow = (norm_storage <= 1.0000f) ? 0.1260f * norm_storage + 0.0448f : 0.0000f * norm_storage + (0.1260f * 1.0000f + 0.0448f - 0.0000f * 1.0000f); break;
        
//     }
//     return norm_outflow * max_outflow_m3d;
// }

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


static float rule_2175(float inflow_m3d, float storage_m3, int month) {
    const float max_inflow_m3d = 513780883.0f;
    const float max_outflow_m3d = 392186888.0f;
    const float max_storage_m3 = 28330568640.0f;
    const float norm_inflow = inflow_m3d / max_inflow_m3d;
    const float norm_storage = storage_m3 / max_storage_m3; 
    float norm_outflow;

    switch (month) {
        case 1:  norm_outflow = 0.9392f * norm_inflow + 0.0018f; break;
        case 2:  norm_outflow = 0.9296f * norm_inflow + 0.0021f; break;
        case 3:  norm_outflow = 0.9399f * norm_inflow + 0.0017f; break;
        case 4:  norm_outflow = 0.9170f * norm_inflow + 0.0021f; break;
        case 5:  norm_outflow = 0.9959f * norm_inflow + 0.0002f; break;
        case 6:  norm_outflow = 0.9867f * norm_inflow + 0.0005f; break;
        case 7:  norm_outflow = 0.9367f * norm_inflow + 0.0020f; break;
        case 8:  norm_outflow = 0.8718f * norm_inflow + 0.0027f; break;
        case 9:  norm_outflow = 0.7875f * norm_inflow + 0.0039f; break;
        case 10: norm_outflow = 0.8544f * norm_inflow + 0.0027f; break;
        case 11: norm_outflow = 0.9502f * norm_inflow + 0.0013f; break;
        case 12: norm_outflow = 0.9518f * norm_inflow + 0.0012f; break;
    }
    return norm_outflow * max_outflow_m3d;
}

static float rule_2436(float inflow_m3d, float storage_m3, int month) {
    const float max_inflow_m3d = 36473559.8f;
    const float max_outflow_m3d = 10985152.4f;
    const float max_storage_m3 = 151835446.8f;
    const float norm_inflow = inflow_m3d / max_inflow_m3d;
    const float norm_storage = storage_m3 / max_storage_m3; 
    float norm_outflow;

    switch (month) {
        case 1: norm_outflow = (norm_storage <= 0.6f) ? 0.0575f * norm_storage + 0.0f : 2.4351f * norm_storage + (0.0575f * 0.6f + 0.0f - 2.4351f * 0.6f); break;
        case 2: norm_outflow = 0.9988f * norm_inflow - 0.0071f; break;
        // case 3: 
    }
    return norm_outflow * max_outflow_m3d;
}
//------------------------------------------------------------------------------


// ---- Dispatch based on reservoir GDW ID ----
float applyReservoirRule(int res_id, float inflow_m3d, float storage_m3, int month) {
    switch (res_id) {
        case 21: return rule_21(inflow_m3d, storage_m3, month);
        case 2175: return rule_2175(inflow_m3d, storage_m3, month);
        case 104: return rule_104(inflow_m3d, storage_m3, month);

        default:
            throw std::runtime_error(
                "No operation rule defined for reservoir ID: " + std::to_string(res_id) +
                ". Register a rule in reservoir_operation_rules.cpp.");
    }
}
//------------------------------------------------------------------------------


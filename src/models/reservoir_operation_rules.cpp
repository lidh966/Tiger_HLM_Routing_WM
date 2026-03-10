#include "reservoir_operation_rules.hpp"

#include <stdexcept>
#include <string>

// ---- Per-reservoir rule functions ---- 
// rule_{GDW_ID} - Define the operation rule for reservoir with GDW ID {GDW_ID}
// default as run-of-river (i.e., outflow = inflow) if no rule is defined for a reservoir
static float rule_2175(float inflow_m3d, float storage_m3, int month) {
    const float max_inflow_m3d = 361022865.0f;
    const float max_outflow_m3d = 359865170.0f;
    const float max_storage_m3 = 110961929.1f;
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
        case 1:  norm_outflow = (norm_storage <= 0.6f) ? 0.0575f * norm_storage + 0.0f : 2.4351f * norm_storage + (0.0575f * 0.6f + 0.0f - 2.4351f * 0.6f); break;
    }
    return norm_outflow * max_outflow_m3d;
}
//------------------------------------------------------------------------------


// ---- Dispatch based on reservoir GDW ID ----
float applyReservoirRule(int res_id, float inflow_m3d, float storage_m3, int month) {
    switch (res_id) {
        case 2175: return rule_2175(inflow_m3d, storage_m3, month);

        default:
            throw std::runtime_error(
                "No operation rule defined for reservoir ID: " + std::to_string(res_id) +
                ". Register a rule in reservoir_operation_rules.cpp.");
    }
}
//------------------------------------------------------------------------------


#include "reservoir_operation_rules.hpp"

#include <stdexcept>
#include <string>

// ---- Per-reservoir rule functions ---- 
// rule_{GDW_ID} - Define the operation rule for reservoir with GDW ID {GDW_ID}
// default as run-of-river (i.e., outflow = inflow) if no rule is defined for a reservoir

static float rule_3141592654(float inflow_m3d, float storage_m3, int month) {
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
//------------------------------------------------------------------------------


// ---- Dispatch based on reservoir GDW ID ----
float applyReservoirRule(int res_id, float inflow_m3d, float storage_m3, int month) {
    switch (res_id) {
        case 3141592654: return rule_3141592654(inflow_m3d, storage_m3, month);

        default:
            throw std::runtime_error(
                "No operation rule defined for reservoir ID: " + std::to_string(res_id) +
                ". Register a rule in reservoir_operation_rules.cpp.");
    }
}
//------------------------------------------------------------------------------


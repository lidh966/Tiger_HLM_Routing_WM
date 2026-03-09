#include "reservoir_operation_rules.hpp"

#include <stdexcept>
#include <string>

//------------------------------------------------------------------------------
// Per-reservoir rule functions
// Signature: float rule_<res_id>(float inflow_m3s, float storage_m3, int month)
//
// Add one function per reservoir and register it in applyReservoirRule() below.
//
// Example (placeholder — replace with real rule for reservoir 12345):
//
//   static float rule_12345(float inflow_m3s, float storage_m3, int month) {
//       // Simple target-release rule: release 80 % of inflow in wet season
//       if (month >= 5 && month <= 9) return 0.80f * inflow_m3s;
//       return 0.50f * inflow_m3s;
//   }
//------------------------------------------------------------------------------


//------------------------------------------------------------------------------
// Dispatch
//------------------------------------------------------------------------------

/**
 * @brief Routes to the correct per-reservoir rule based on res_id.
 * Throws std::runtime_error for any unregistered reservoir ID.
 */
float applyReservoirRule(int res_id, float inflow_m3s, float storage_m3, int month) {
    switch (res_id) {
        // Register each reservoir rule here, e.g.:
        // case 12345: return rule_12345(inflow_m3s, storage_m3, month);

        default:
            throw std::runtime_error(
                "No operation rule defined for reservoir ID: " + std::to_string(res_id) +
                ". Register a rule in reservoir_operation_rules.cpp.");
    }
}

#pragma once

#include <vector>
#include <unordered_map>
#include <stdexcept>
#include <string>

/**
 * @struct ReservoirState
 * @brief Holds the mutable runtime state for a single reservoir.
 *
 * One instance exists per unique res_id encountered in the node network.
 * Fields are populated at setup time (node indices) and updated each chunk
 * (storage, storage_series).
 *
 * Storage units: m³
 * Inflow / outflow units: m³/s  (consistent with river discharge in results)
 */
struct ReservoirState {
    int res_id = 0;    // GDW reservoir ID (0 if not associated with a reservoir)

    // Node topology (populated during setupModel)
    std::vector<size_t> inflow_node_indices;  // indices of all res_inflow_flag nodes
    size_t outflow_node_index = 0;            // index of the single res_outflow_flag node
    bool outflow_node_set = false;            // guard against duplicate outflow nodes

    // State (carried across chunks)
    float storage = 0.0f;                     // current storage at start of chunk (m³)

    // Output time series for the current chunk (sized to n_steps each chunk)
    std::vector<float> storage_series;
};

/**
 * @brief Map from GDW reservoir ID → ReservoirState.
 * Built once in setupModel and passed by non-const reference through the
 * routing functions so storage can be updated across chunks.
 */
using ReservoirStateMap = std::unordered_map<int, ReservoirState>;

/**
 * @brief Validates that every reservoir in the map has exactly one outflow node set.
 * Throws std::runtime_error on failure.
 */
inline void validateReservoirStates(const ReservoirStateMap& reservoir_states) {
    for (const auto& [id, state] : reservoir_states) {
        if (!state.outflow_node_set) {
            throw std::runtime_error(
                "Reservoir ID " + std::to_string(id) +
                " has no outflow node. Check res_outflow_flag in the parameters CSV.");
        }
        if (state.inflow_node_indices.empty()) {
            throw std::runtime_error(
                "Reservoir ID " + std::to_string(id) +
                " has no inflow nodes. Check res_inflow_flag in the parameters CSV.");
        }
    }
}

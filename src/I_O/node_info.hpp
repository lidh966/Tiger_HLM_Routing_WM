#pragma once

#include <vector>
#include <string>
#include <unordered_map>
#include <map>

/** 
 * @struct NodeInfo
 * @brief Structure to hold information about a node in the network.
 * 
 * This structure contains:
 * - index: Unique identifier for the node.
 * - stream_id: Identifier for the stream associated with the node.
 * - level: The level of the node in the hierarchy.
 * - parents: A vector of indices representing parent nodes.
 * - params: A vector of parameters associated with the node.
 * Below are added info for reservoir routing:
 * - res_id: GDW reservoir ID associated with this node (0 if none).
 * - res_inflow_flag: True if this node is an inflow link to a reservoir.
 * - res_outflow_flag: True if this node is the outflow link from a reservoir.
 * - res_within_flag: True if this node lies purely within a reservoir.
 */
struct NodeInfo {
    size_t index;
    int stream_id;
    size_t level;
    std::vector<size_t> parents;
    std::vector<double> params;

    // Reservoir routing info
    int res_id = 0;    // GDW reservoir ID (0 if not associated with a reservoir)
    bool res_inflow_flag = false;    // True if this node is an inflow link to a reservoir
    bool res_outflow_flag = false;   // True if this node is the outflow link from a reservoir
    bool res_within_flag = false;    // True if this node lies purely within a reservoir (not inflow or outflow)
};

// Function declaration
void read_node_levels(
    const std::string& filename,
    std::unordered_map<size_t, NodeInfo>& node_map,
    std::map<size_t, std::vector<size_t>>& level_groups
);

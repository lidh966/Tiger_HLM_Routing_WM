#pragma once

/**
 * @file reservoir_operation_rules.hpp
 * @brief Dispatch interface for per-reservoir operation rules.
 *
 * Each reservoir (identified by its GDW ID) maps to a rule function
 * with the signature:
 *
 *   float rule_<res_id>(float inflow_m3d, float storage_m3, int month);
 *
 * New reservoirs are registered by:
 *   1. Implementing the rule function in reservoir_operation_rules.cpp.
 *   2. Adding a case to the switch in applyReservoirRule().
 */

/**
 * @brief Compute the release (outflow) for a reservoir at a single time step.
 *
 * @param res_id      GDW reservoir identifier.
 * @param inflow_m3d  Total inflow to the reservoir at this time step (m³/day).
 * @param storage_m3  Reservoir storage at the start of this time step (m³).
 * @param month       Calendar month [1–12].
 * @return            Outflow/release in m³/day.
 *
 * @throws std::runtime_error if res_id has no registered rule.
 */
float applyReservoirRule(int res_id, float inflow_m3d, float storage_m3, int month);

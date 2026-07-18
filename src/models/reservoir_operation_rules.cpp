#include "reservoir_operation_rules.hpp"

#include <stdexcept>
#include <string>

// ---- Per-reservoir rule functions ---- 
// rule_{GDW_ID} - Define the operation rule for reservoir with GDW ID {GDW_ID}
// default as run-of-river (i.e., outflow = inflow) if no rule is defined for a reservoir

static float rule_20(float inflow_m3d, float storage_m3, int month) {
    const float max_inflow_m3d   = 462687812.0f;
    const float max_outflow_m3d  = 368454268.7f;
    const float max_storage_m3   = 29602227313.0f;
    const float norm_inflow  = inflow_m3d  / max_inflow_m3d;
    const float norm_storage = storage_m3  / max_storage_m3;
    float norm_outflow;

    switch (month) {
        case  1: norm_outflow = 0.7892f * norm_inflow + 0.0697f; break;
        case  2: norm_outflow = (norm_storage <= 0.8774f) ? 0.1444f * norm_storage + 0.0300f : 1.6019f * norm_storage + (0.1444f * 0.8774f + 0.0300f - 1.6019f * 0.8774f); break;
        case  3: norm_outflow = (norm_storage <= 0.8780f) ? 0.1433f * norm_storage + 0.0330f : 1.9295f * norm_storage + (0.1433f * 0.8780f + 0.0330f - 1.9295f * 0.8780f); break;
        case  4: norm_outflow = 0.7546f * norm_inflow + 0.0667f; break;
        case  5: norm_outflow = 0.8459f * norm_inflow + 0.0590f; break;
        case  6: norm_outflow = (norm_storage <= 0.8696f) ? 0.1590f * norm_storage + 0.0247f : 6.5474f * norm_storage + (0.1590f * 0.8696f + 0.0247f - 6.5474f * 0.8696f); break;
        case  7: norm_outflow = (norm_storage <= 0.8740f) ? 0.1397f * norm_storage + 0.0382f : 6.1183f * norm_storage + (0.1397f * 0.8740f + 0.0382f - 6.1183f * 0.8740f); break;
        case  8: norm_outflow = 1.0592f * norm_inflow + 0.0568f; break;
        case  9: norm_outflow = 0.9962f * norm_inflow + 0.0551f; break;
        case 10: norm_outflow = 0.9865f * norm_inflow + 0.0553f; break;
        case 11: norm_outflow = 0.9492f * norm_inflow + 0.0632f; break;
        case 12: norm_outflow = 0.8437f * norm_inflow + 0.0679f; break;
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
        case  1: norm_outflow = (norm_storage <= 0.8903f) ? 0.1520f * norm_storage + 0.0258f : 1.4634f * norm_storage + (0.1520f * 0.8903f + 0.0258f - 1.4634f * 0.8903f); break;
        case  2: norm_outflow = 0.9115f * norm_inflow + 0.0527f; break;
        case  3: norm_outflow = (norm_storage <= 0.8594f) ? 0.1242f * norm_storage + 0.0405f : 2.9615f * norm_storage + (0.1242f * 0.8594f + 0.0405f - 2.9615f * 0.8594f); break;
        case  4: norm_outflow = 0.9687f * norm_inflow + 0.0463f; break;
        case  5: norm_outflow = 0.9598f * norm_inflow + 0.0444f; break;
        case  6: norm_outflow = 1.0256f * norm_inflow + 0.0425f; break;
        case  7: norm_outflow = 1.0989f * norm_inflow + 0.0445f; break;
        case  8: norm_outflow = 1.1645f * norm_inflow + 0.0439f; break;
        case  9: norm_outflow = 1.1168f * norm_inflow + 0.0432f; break;
        case 10: norm_outflow = 1.1093f * norm_inflow + 0.0428f; break;
        case 11: norm_outflow = 1.0707f * norm_inflow + 0.0486f; break;
        case 12: norm_outflow = (norm_storage <= 0.8794f) ? 0.1352f * norm_storage + 0.0304f : 1.5743f * norm_storage + (0.1352f * 0.8794f + 0.0304f - 1.5743f * 0.8794f); break;
    }
    return norm_outflow * max_outflow_m3d;
}

static float rule_104(float inflow_m3d, float storage_m3, int month) {
    const float max_inflow_m3d   = 383733386.6f;
    const float max_outflow_m3d  = 161229311.6f;
    const float max_storage_m3   = 23458275644.0f;
    const float norm_inflow  = inflow_m3d  / max_inflow_m3d;
    const float norm_storage = storage_m3  / max_storage_m3;
    float norm_outflow;

    switch (month) {
        case  1: norm_outflow = (norm_storage <= 0.8954f) ? 0.1462f * norm_storage + 0.0256f : 1.6479f * norm_storage + (0.1462f * 0.8954f + 0.0256f - 1.6479f * 0.8954f); break;
        case  2: norm_outflow = (norm_storage <= 0.8870f) ? 0.1642f * norm_storage + 0.0214f : 2.1453f * norm_storage + (0.1642f * 0.8870f + 0.0214f - 2.1453f * 0.8870f); break;
        case  3: norm_outflow = (norm_storage <= 0.8931f) ? 0.1455f * norm_storage + 0.0368f : 1.2343f * norm_storage + (0.1455f * 0.8931f + 0.0368f - 1.2343f * 0.8931f); break;
        case  4: norm_outflow = (norm_storage <= 0.8717f) ? 0.1264f * norm_storage + 0.0509f : 2.6964f * norm_storage + (0.1264f * 0.8717f + 0.0509f - 2.6964f * 0.8717f); break;
        case  5: norm_outflow = (norm_storage <= 0.8710f) ? 0.1399f * norm_storage + 0.0499f : 3.9140f * norm_storage + (0.1399f * 0.8710f + 0.0499f - 3.9140f * 0.8710f); break;
        case  6: norm_outflow = (norm_storage <= 0.8794f) ? 0.1538f * norm_storage + 0.0388f : 6.7290f * norm_storage + (0.1538f * 0.8794f + 0.0388f - 6.7290f * 0.8794f); break;
        case  7: norm_outflow = (norm_storage <= 0.8671f) ? 0.1316f * norm_storage + 0.0622f : 3.2941f * norm_storage + (0.1316f * 0.8671f + 0.0622f - 3.2941f * 0.8671f); break;
        case  8: norm_outflow = (norm_storage <= 0.8561f) ? 0.1201f * norm_storage + 0.0607f : 2.7727f * norm_storage + (0.1201f * 0.8561f + 0.0607f - 2.7727f * 0.8561f); break;
        case  9: norm_outflow = (norm_storage <= 0.8498f) ? 0.1054f * norm_storage + 0.0568f : 2.3482f * norm_storage + (0.1054f * 0.8498f + 0.0568f - 2.3482f * 0.8498f); break;
        case 10: norm_outflow = (norm_storage <= 0.8441f) ? 0.1047f * norm_storage + 0.0503f : 2.5480f * norm_storage + (0.1047f * 0.8441f + 0.0503f - 2.5480f * 0.8441f); break;
        case 11: norm_outflow = (norm_storage <= 0.8727f) ? 0.1166f * norm_storage + 0.0407f : 1.3336f * norm_storage + (0.1166f * 0.8727f + 0.0407f - 1.3336f * 0.8727f); break;
        case 12: norm_outflow = (norm_storage <= 0.8884f) ? 0.1307f * norm_storage + 0.0322f : 1.7151f * norm_storage + (0.1307f * 0.8884f + 0.0322f - 1.7151f * 0.8884f); break;
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
        case  1: norm_outflow = 1.0457f * norm_inflow + 0.0115f; break;
        case  2: norm_outflow = 1.0656f * norm_inflow + 0.0108f; break;
        case  3: norm_outflow = 1.0298f * norm_inflow + 0.0093f; break;
        case  4: norm_outflow = 1.0296f * norm_inflow + 0.0096f; break;
        case  5: norm_outflow = 1.0310f * norm_inflow + 0.0107f; break;
        case  6: norm_outflow = 1.0483f * norm_inflow + 0.0122f; break;
        case  7: norm_outflow = 1.0429f * norm_inflow + 0.0131f; break;
        case  8: norm_outflow = 1.0043f * norm_inflow + 0.0098f; break;
        case  9: norm_outflow = 0.9790f * norm_inflow + 0.0089f; break;
        case 10: norm_outflow = 0.9980f * norm_inflow + 0.0081f; break;
        case 11: norm_outflow = 1.0159f * norm_inflow + 0.0108f; break;
        case 12: norm_outflow = 1.0145f * norm_inflow + 0.0110f; break;
    }
    return norm_outflow * max_outflow_m3d;
}

static float rule_119(float inflow_m3d, float storage_m3, int month) {
    const float max_inflow_m3d   = 86439926.6f;
    const float max_outflow_m3d  = 62925811.9f;
    const float max_storage_m3   = 2515047958.0f;
    const float norm_inflow  = inflow_m3d  / max_inflow_m3d;
    const float norm_storage = storage_m3  / max_storage_m3;
    float norm_outflow;

    switch (month) {
        case  1: norm_outflow = (norm_storage <= 0.9497f) ? 0.2844f * norm_storage + -0.0589f : 0.7234f * norm_storage + (0.2844f * 0.9497f + -0.0589f - 0.7234f * 0.9497f); break;
        case  2: norm_outflow = (norm_storage <= 0.9197f) ? 0.2550f * norm_storage + -0.0431f : 1.1139f * norm_storage + (0.2550f * 0.9197f + -0.0431f - 1.1139f * 0.9197f); break;
        case  3: norm_outflow = 0.9768f * norm_inflow + 0.0673f; break;
        case  4: norm_outflow = 0.9175f * norm_inflow + 0.0660f; break;
        case  5: norm_outflow = 0.9006f * norm_inflow + 0.0667f; break;
        case  6: norm_outflow = 0.9154f * norm_inflow + 0.0657f; break;
        case  7: norm_outflow = 0.9186f * norm_inflow + 0.0752f; break;
        case  8: norm_outflow = (norm_storage <= 0.9290f) ? 0.2257f * norm_storage + 0.0069f : 1.4176f * norm_storage + (0.2257f * 0.9290f + 0.0069f - 1.4176f * 0.9290f); break;
        case  9: norm_outflow = (norm_storage <= 0.9342f) ? 0.2349f * norm_storage + -0.0096f : 1.1509f * norm_storage + (0.2349f * 0.9342f + -0.0096f - 1.1509f * 0.9342f); break;
        case 10: norm_outflow = (norm_storage <= 0.9378f) ? 0.2526f * norm_storage + -0.0283f : 1.1175f * norm_storage + (0.2526f * 0.9378f + -0.0283f - 1.1175f * 0.9378f); break;
        case 11: norm_outflow = (norm_storage <= 0.9461f) ? 0.2799f * norm_storage + -0.0510f : 0.8644f * norm_storage + (0.2799f * 0.9461f + -0.0510f - 0.8644f * 0.9461f); break;
        case 12: norm_outflow = (norm_storage <= 0.9461f) ? 0.2819f * norm_storage + -0.0560f : 0.8957f * norm_storage + (0.2819f * 0.9461f + -0.0560f - 0.8957f * 0.9461f); break;
    }
    return norm_outflow * max_outflow_m3d;
}

static float rule_126(float inflow_m3d, float storage_m3, int month) {
    const float max_inflow_m3d   = 195388463.8f;
    const float max_outflow_m3d  = 181780590.4f;
    const float max_storage_m3   = 2247396490.0f;
    const float norm_inflow  = inflow_m3d  / max_inflow_m3d;
    const float norm_storage = storage_m3  / max_storage_m3;
    float norm_outflow;

    switch (month) {
        case  1: norm_outflow = 0.9763f * norm_inflow + 0.0300f; break;
        case  2: norm_outflow = 0.9765f * norm_inflow + 0.0285f; break;
        case  3: norm_outflow = 0.9622f * norm_inflow + 0.0228f; break;
        case  4: norm_outflow = 0.9861f * norm_inflow + 0.0208f; break;
        case  5: norm_outflow = 1.0126f * norm_inflow + 0.0200f; break;
        case  6: norm_outflow = 1.0458f * norm_inflow + 0.0189f; break;
        case  7: norm_outflow = 1.0542f * norm_inflow + 0.0190f; break;
        case  8: norm_outflow = 1.0746f * norm_inflow + 0.0181f; break;
        case  9: norm_outflow = 1.0387f * norm_inflow + 0.0189f; break;
        case 10: norm_outflow = 1.0244f * norm_inflow + 0.0197f; break;
        case 11: norm_outflow = 1.0177f * norm_inflow + 0.0271f; break;
        case 12: norm_outflow = 0.9834f * norm_inflow + 0.0284f; break;
    }
    return norm_outflow * max_outflow_m3d;
}

static float rule_136(float inflow_m3d, float storage_m3, int month) {
    const float max_inflow_m3d   = 28403798.5f;
    const float max_outflow_m3d  = 19399943.2f;
    const float max_storage_m3   = 2199541289.0f;
    const float norm_inflow  = inflow_m3d  / max_inflow_m3d;
    const float norm_storage = storage_m3  / max_storage_m3;
    float norm_outflow;

    switch (month) {
        case  1: norm_outflow = (norm_storage <= 0.8459f) ? 0.1224f * norm_storage + 0.0089f : 1.7979f * norm_storage + (0.1224f * 0.8459f + 0.0089f - 1.7979f * 0.8459f); break;
        case  2: norm_outflow = (norm_storage <= 0.8285f) ? 0.1090f * norm_storage + 0.0053f : 1.4988f * norm_storage + (0.1090f * 0.8285f + 0.0053f - 1.4988f * 0.8285f); break;
        case  3: norm_outflow = (norm_storage <= 0.8493f) ? 0.1358f * norm_storage + 0.0059f : 1.5025f * norm_storage + (0.1358f * 0.8493f + 0.0059f - 1.5025f * 0.8493f); break;
        case  4: norm_outflow = 0.7208f * norm_inflow + 0.0964f; break;
        case  5: norm_outflow = 0.6873f * norm_inflow + 0.0991f; break;
        case  6: norm_outflow = 0.6882f * norm_inflow + 0.1047f; break;
        case  7: norm_outflow = 0.6580f * norm_inflow + 0.1149f; break;
        case  8: norm_outflow = (norm_storage <= 0.8532f) ? 0.1525f * norm_storage + 0.0484f : 1.8411f * norm_storage + (0.1525f * 0.8532f + 0.0484f - 1.8411f * 0.8532f); break;
        case  9: norm_outflow = (norm_storage <= 0.8356f) ? 0.1340f * norm_storage + 0.0373f : 1.3003f * norm_storage + (0.1340f * 0.8356f + 0.0373f - 1.3003f * 0.8356f); break;
        case 10: norm_outflow = (norm_storage <= 0.8263f) ? 0.1242f * norm_storage + 0.0280f : 1.4146f * norm_storage + (0.1242f * 0.8263f + 0.0280f - 1.4146f * 0.8263f); break;
        case 11: norm_outflow = (norm_storage <= 0.8373f) ? 0.1222f * norm_storage + 0.0188f : 1.0952f * norm_storage + (0.1222f * 0.8373f + 0.0188f - 1.0952f * 0.8373f); break;
        case 12: norm_outflow = (norm_storage <= 0.8451f) ? 0.1157f * norm_storage + 0.0151f : 1.2553f * norm_storage + (0.1157f * 0.8451f + 0.0151f - 1.2553f * 0.8451f); break;
    }
    return norm_outflow * max_outflow_m3d;
}

static float rule_142(float inflow_m3d, float storage_m3, int month) {
    const float max_inflow_m3d   = 1088088954.0f;
    const float max_outflow_m3d  = 174012708.3f;
    const float max_storage_m3   = 6193533741.0f;
    const float norm_inflow  = inflow_m3d  / max_inflow_m3d;
    const float norm_storage = storage_m3  / max_storage_m3;
    float norm_outflow;

    switch (month) {
        case  1: norm_outflow = (norm_storage <= 0.9956f) ? 1.8875f * norm_storage + -0.4603f : 0.0288f * norm_storage + (1.8875f * 0.9956f + -0.4603f - 0.0288f * 0.9956f); break;
        case  2: norm_outflow = (norm_storage <= 0.9960f) ? 1.9017f * norm_storage + -0.4614f : 0.0280f * norm_storage + (1.9017f * 0.9960f + -0.4614f - 0.0280f * 0.9960f); break;
        case  3: norm_outflow = (norm_storage <= 0.9949f) ? 1.8297f * norm_storage + -0.4447f : 0.0361f * norm_storage + (1.8297f * 0.9949f + -0.4447f - 0.0361f * 0.9949f); break;
        case  4: norm_outflow = (norm_storage <= 0.9933f) ? 1.4246f * norm_storage + -0.3246f : 0.0733f * norm_storage + (1.4246f * 0.9933f + -0.3246f - 0.0733f * 0.9933f); break;
        case  5: norm_outflow = (norm_storage <= 0.9821f) ? 1.2711f * norm_storage + -0.2900f : 0.2732f * norm_storage + (1.2711f * 0.9821f + -0.2900f - 0.2732f * 0.9821f); break;
        case  6: norm_outflow = (norm_storage <= 0.9889f) ? 1.3234f * norm_storage + -0.2972f : 0.1593f * norm_storage + (1.3234f * 0.9889f + -0.2972f - 0.1593f * 0.9889f); break;
        case  7: norm_outflow = (norm_storage <= 0.9924f) ? 1.3203f * norm_storage + -0.2918f : 0.1031f * norm_storage + (1.3203f * 0.9924f + -0.2918f - 0.1031f * 0.9924f); break;
        case  8: norm_outflow = (norm_storage <= 0.9932f) ? 1.3392f * norm_storage + -0.2953f : 0.0531f * norm_storage + (1.3392f * 0.9932f + -0.2953f - 0.0531f * 0.9932f); break;
        case  9: norm_outflow = (norm_storage <= 0.9911f) ? 1.3503f * norm_storage + -0.2986f : 0.0498f * norm_storage + (1.3503f * 0.9911f + -0.2986f - 0.0498f * 0.9911f); break;
        case 10: norm_outflow = (norm_storage <= 0.9932f) ? 1.6029f * norm_storage + -0.3804f : 0.0453f * norm_storage + (1.6029f * 0.9932f + -0.3804f - 0.0453f * 0.9932f); break;
        case 11: norm_outflow = (norm_storage <= 0.9940f) ? 1.7369f * norm_storage + -0.4161f : 0.0381f * norm_storage + (1.7369f * 0.9940f + -0.4161f - 0.0381f * 0.9940f); break;
        case 12: norm_outflow = (norm_storage <= 0.9954f) ? 1.8577f * norm_storage + -0.4469f : 0.0423f * norm_storage + (1.8577f * 0.9954f + -0.4469f - 0.0423f * 0.9954f); break;
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
        case  1: norm_outflow = 1.5614f * norm_inflow + 0.0660f; break;
        case  2: norm_outflow = 1.4819f * norm_inflow + 0.0688f; break;
        case  3: norm_outflow = 1.4689f * norm_inflow + 0.0693f; break;
        case  4: norm_outflow = 1.4792f * norm_inflow + 0.0712f; break;
        case  5: norm_outflow = 1.5835f * norm_inflow + 0.0697f; break;
        case  6: norm_outflow = 1.6193f * norm_inflow + 0.0694f; break;
        case  7: norm_outflow = 1.5452f * norm_inflow + 0.0689f; break;
        case  8: norm_outflow = 1.3815f * norm_inflow + 0.0667f; break;
        case  9: norm_outflow = 1.3310f * norm_inflow + 0.0629f; break;
        case 10: norm_outflow = 1.3996f * norm_inflow + 0.0637f; break;
        case 11: norm_outflow = 1.5456f * norm_inflow + 0.0652f; break;
        case 12: norm_outflow = 1.5573f * norm_inflow + 0.0655f; break;
    }
    return norm_outflow * max_outflow_m3d;
}

static float rule_144(float inflow_m3d, float storage_m3, int month) {
    const float max_inflow_m3d   = 744623631.1f;
    const float max_outflow_m3d  = 645438637.2f;
    const float max_storage_m3   = 2288033858.0f;
    const float norm_inflow  = inflow_m3d  / max_inflow_m3d;
    const float norm_storage = storage_m3  / max_storage_m3;
    float norm_outflow;

    switch (month) {
        case  1: norm_outflow = 1.0247f * norm_inflow + 0.0134f; break;
        case  2: norm_outflow = 1.0264f * norm_inflow + 0.0133f; break;
        case  3: norm_outflow = 1.0294f * norm_inflow + 0.0135f; break;
        case  4: norm_outflow = 1.0548f * norm_inflow + 0.0136f; break;
        case  5: norm_outflow = 1.0481f * norm_inflow + 0.0139f; break;
        case  6: norm_outflow = 1.0667f * norm_inflow + 0.0142f; break;
        case  7: norm_outflow = 1.0551f * norm_inflow + 0.0141f; break;
        case  8: norm_outflow = 1.0387f * norm_inflow + 0.0144f; break;
        case  9: norm_outflow = 1.0050f * norm_inflow + 0.0139f; break;
        case 10: norm_outflow = 1.0135f * norm_inflow + 0.0134f; break;
        case 11: norm_outflow = 1.0247f * norm_inflow + 0.0128f; break;
        case 12: norm_outflow = 1.0413f * norm_inflow + 0.0125f; break;
    }
    return norm_outflow * max_outflow_m3d;
}

static float rule_145(float inflow_m3d, float storage_m3, int month) {
    const float max_inflow_m3d   = 1217305264.0f;
    const float max_outflow_m3d  = 1022575988.0f;
    const float max_storage_m3   = 3668196833.0f;
    const float norm_inflow  = inflow_m3d  / max_inflow_m3d;
    const float norm_storage = storage_m3  / max_storage_m3;
    float norm_outflow;

    switch (month) {
        case  1: norm_outflow = 1.1109f * norm_inflow + 0.0147f; break;
        case  2: norm_outflow = 1.1030f * norm_inflow + 0.0153f; break;
        case  3: norm_outflow = 1.1037f * norm_inflow + 0.0152f; break;
        case  4: norm_outflow = 1.1227f * norm_inflow + 0.0162f; break;
        case  5: norm_outflow = 1.1408f * norm_inflow + 0.0174f; break;
        case  6: norm_outflow = 1.1582f * norm_inflow + 0.0180f; break;
        case  7: norm_outflow = 1.1361f * norm_inflow + 0.0165f; break;
        case  8: norm_outflow = 1.0997f * norm_inflow + 0.0184f; break;
        case  9: norm_outflow = 1.0722f * norm_inflow + 0.0149f; break;
        case 10: norm_outflow = 1.0752f * norm_inflow + 0.0145f; break;
        case 11: norm_outflow = 1.1023f * norm_inflow + 0.0137f; break;
        case 12: norm_outflow = 1.1120f * norm_inflow + 0.0139f; break;
    }
    return norm_outflow * max_outflow_m3d;
}

static float rule_147(float inflow_m3d, float storage_m3, int month) {
    const float max_inflow_m3d   = 829099010.6f;
    const float max_outflow_m3d  = 145375558.3f;
    const float max_storage_m3   = 7239797380.0f;
    const float norm_inflow  = inflow_m3d  / max_inflow_m3d;
    const float norm_storage = storage_m3  / max_storage_m3;
    float norm_outflow;

    switch (month) {
        case  1: norm_outflow = (norm_storage <= 0.8645f) ? 0.3821f * norm_storage + -0.1082f : 1.1459f * norm_storage + (0.3821f * 0.8645f + -0.1082f - 1.1459f * 0.8645f); break;
        case  2: norm_outflow = (norm_storage <= 0.8467f) ? 0.3442f * norm_storage + -0.0921f : 1.2916f * norm_storage + (0.3442f * 0.8467f + -0.0921f - 1.2916f * 0.8467f); break;
        case  3: norm_outflow = (norm_storage <= 0.8222f) ? 0.2946f * norm_storage + -0.0709f : 2.2582f * norm_storage + (0.2946f * 0.8222f + -0.0709f - 2.2582f * 0.8222f); break;
        case  4: norm_outflow = (norm_storage <= 0.8223f) ? 0.2649f * norm_storage + -0.0536f : 2.3218f * norm_storage + (0.2649f * 0.8223f + -0.0536f - 2.3218f * 0.8223f); break;
        case  5: norm_outflow = (norm_storage <= 0.8232f) ? 0.2805f * norm_storage + -0.0717f : 3.0321f * norm_storage + (0.2805f * 0.8232f + -0.0717f - 3.0321f * 0.8232f); break;
        case  6: norm_outflow = (norm_storage <= 0.8465f) ? 0.3066f * norm_storage + -0.0806f : 2.3334f * norm_storage + (0.3066f * 0.8465f + -0.0806f - 2.3334f * 0.8465f); break;
        case  7: norm_outflow = (norm_storage <= 0.8604f) ? 0.3178f * norm_storage + -0.0890f : 2.3302f * norm_storage + (0.3178f * 0.8604f + -0.0890f - 2.3302f * 0.8604f); break;
        case  8: norm_outflow = (norm_storage <= 0.9107f) ? 0.3637f * norm_storage + -0.1096f : 1.0320f * norm_storage + (0.3637f * 0.9107f + -0.1096f - 1.0320f * 0.9107f); break;
        case  9: norm_outflow = (norm_storage <= 0.9427f) ? 0.4680f * norm_storage + -0.1594f : 0.4788f * norm_storage + (0.4680f * 0.9427f + -0.1594f - 0.4788f * 0.9427f); break;
        case 10: norm_outflow = (norm_storage <= 0.9488f) ? 0.4969f * norm_storage + -0.1749f : 0.3998f * norm_storage + (0.4969f * 0.9488f + -0.1749f - 0.3998f * 0.9488f); break;
        case 11: norm_outflow = (norm_storage <= 0.9338f) ? 0.4721f * norm_storage + -0.1608f : 0.5704f * norm_storage + (0.4721f * 0.9338f + -0.1608f - 0.5704f * 0.9338f); break;
        case 12: norm_outflow = (norm_storage <= 0.8559f) ? 0.3708f * norm_storage + -0.1057f : 1.6203f * norm_storage + (0.3708f * 0.8559f + -0.1057f - 1.6203f * 0.8559f); break;
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
        case  1: norm_outflow = (norm_storage <= 0.8053f) ? 0.2052f * norm_storage + -0.0560f : 1.5451f * norm_storage + (0.2052f * 0.8053f + -0.0560f - 1.5451f * 0.8053f); break;
        case  2: norm_outflow = (norm_storage <= 0.8005f) ? 0.2115f * norm_storage + -0.0623f : 1.5958f * norm_storage + (0.2115f * 0.8005f + -0.0623f - 1.5958f * 0.8005f); break;
        case  3: norm_outflow = (norm_storage <= 0.7816f) ? 0.2187f * norm_storage + -0.0722f : 2.0618f * norm_storage + (0.2187f * 0.7816f + -0.0722f - 2.0618f * 0.7816f); break;
        case  4: norm_outflow = (norm_storage <= 0.7958f) ? 0.2245f * norm_storage + -0.0693f : 3.0655f * norm_storage + (0.2245f * 0.7958f + -0.0693f - 3.0655f * 0.7958f); break;
        case  5: norm_outflow = (norm_storage <= 0.8115f) ? 0.2577f * norm_storage + -0.0886f : 3.5028f * norm_storage + (0.2577f * 0.8115f + -0.0886f - 3.5028f * 0.8115f); break;
        case  6: norm_outflow = (norm_storage <= 0.8290f) ? 0.2726f * norm_storage + -0.1076f : 2.3142f * norm_storage + (0.2726f * 0.8290f + -0.1076f - 2.3142f * 0.8290f); break;
        case  7: norm_outflow = (norm_storage <= 0.8329f) ? 0.2596f * norm_storage + -0.1003f : 2.2304f * norm_storage + (0.2596f * 0.8329f + -0.1003f - 2.2304f * 0.8329f); break;
        case  8: norm_outflow = (norm_storage <= 0.8320f) ? 0.1824f * norm_storage + -0.0491f : 1.5394f * norm_storage + (0.1824f * 0.8320f + -0.0491f - 1.5394f * 0.8320f); break;
        case  9: norm_outflow = (norm_storage <= 0.8028f) ? 0.1982f * norm_storage + -0.0604f : 2.1469f * norm_storage + (0.1982f * 0.8028f + -0.0604f - 2.1469f * 0.8028f); break;
        case 10: norm_outflow = (norm_storage <= 0.8002f) ? 0.1645f * norm_storage + -0.0459f : 2.0944f * norm_storage + (0.1645f * 0.8002f + -0.0459f - 2.0944f * 0.8002f); break;
        case 11: norm_outflow = (norm_storage <= 0.8045f) ? 0.2118f * norm_storage + -0.0679f : 1.9025f * norm_storage + (0.2118f * 0.8045f + -0.0679f - 1.9025f * 0.8045f); break;
        case 12: norm_outflow = (norm_storage <= 0.8002f) ? 0.2081f * norm_storage + -0.0597f : 1.7801f * norm_storage + (0.2081f * 0.8002f + -0.0597f - 1.7801f * 0.8002f); break;
    }
    return norm_outflow * max_outflow_m3d;
}

static float rule_150(float inflow_m3d, float storage_m3, int month) {
    const float max_inflow_m3d   = 637496205.2f;
    const float max_outflow_m3d  = 541574543.7f;
    const float max_storage_m3   = 2672111160.0f;
    const float norm_inflow  = inflow_m3d  / max_inflow_m3d;
    const float norm_storage = storage_m3  / max_storage_m3;
    float norm_outflow;

    switch (month) {
        case  1: norm_outflow = 0.8136f * norm_inflow + 0.0272f; break;
        case  2: norm_outflow = 0.8092f * norm_inflow + 0.0283f; break;
        case  3: norm_outflow = 0.7997f * norm_inflow + 0.0288f; break;
        case  4: norm_outflow = 0.8265f * norm_inflow + 0.0300f; break;
        case  5: norm_outflow = 0.8941f * norm_inflow + 0.0307f; break;
        case  6: norm_outflow = 0.9277f * norm_inflow + 0.0307f; break;
        case  7: norm_outflow = 0.8712f * norm_inflow + 0.0298f; break;
        case  8: norm_outflow = 0.8132f * norm_inflow + 0.0289f; break;
        case  9: norm_outflow = 0.7789f * norm_inflow + 0.0273f; break;
        case 10: norm_outflow = 0.7654f * norm_inflow + 0.0264f; break;
        case 11: norm_outflow = 0.7826f * norm_inflow + 0.0265f; break;
        case 12: norm_outflow = 0.8173f * norm_inflow + 0.0256f; break;
    }
    return norm_outflow * max_outflow_m3d;
}

static float rule_151(float inflow_m3d, float storage_m3, int month) {
    const float max_inflow_m3d   = 365269668.0f;
    const float max_outflow_m3d  = 157586546.6f;
    const float max_storage_m3   = 2176492729.0f;
    const float norm_inflow  = inflow_m3d  / max_inflow_m3d;
    const float norm_storage = storage_m3  / max_storage_m3;
    float norm_outflow;

    switch (month) {
        case  1: norm_outflow = (norm_storage <= 0.9973f) ? 0.7676f * norm_storage + -0.1368f : 0.0393f * norm_storage + (0.7676f * 0.9973f + -0.1368f - 0.0393f * 0.9973f); break;
        case  2: norm_outflow = (norm_storage <= 0.9979f) ? 0.8115f * norm_storage + -0.1485f : 0.0305f * norm_storage + (0.8115f * 0.9979f + -0.1485f - 0.0305f * 0.9979f); break;
        case  3: norm_outflow = (norm_storage <= 0.9991f) ? 0.7952f * norm_storage + -0.1591f : 0.0194f * norm_storage + (0.7952f * 0.9991f + -0.1591f - 0.0194f * 0.9991f); break;
        case  4: norm_outflow = (norm_storage <= 0.9984f) ? 0.7423f * norm_storage + -0.1336f : 0.0297f * norm_storage + (0.7423f * 0.9984f + -0.1336f - 0.0297f * 0.9984f); break;
        case  5: norm_outflow = (norm_storage <= 0.9815f) ? 0.6529f * norm_storage + -0.1145f : 0.4152f * norm_storage + (0.6529f * 0.9815f + -0.1145f - 0.4152f * 0.9815f); break;
        case  6: norm_outflow = (norm_storage <= 0.9959f) ? 0.7321f * norm_storage + -0.1385f : 0.0654f * norm_storage + (0.7321f * 0.9959f + -0.1385f - 0.0654f * 0.9959f); break;
        case  7: norm_outflow = (norm_storage <= 0.9984f) ? 0.7974f * norm_storage + -0.1670f : 0.0275f * norm_storage + (0.7974f * 0.9984f + -0.1670f - 0.0275f * 0.9984f); break;
        case  8: norm_outflow = (norm_storage <= 0.9980f) ? 0.8421f * norm_storage + -0.1791f : 0.0213f * norm_storage + (0.8421f * 0.9980f + -0.1791f - 0.0213f * 0.9980f); break;
        case  9: norm_outflow = (norm_storage <= 0.9979f) ? 0.8364f * norm_storage + -0.1744f : 0.0237f * norm_storage + (0.8364f * 0.9979f + -0.1744f - 0.0237f * 0.9979f); break;
        case 10: norm_outflow = (norm_storage <= 0.9980f) ? 0.8479f * norm_storage + -0.1820f : 0.0214f * norm_storage + (0.8479f * 0.9980f + -0.1820f - 0.0214f * 0.9980f); break;
        case 11: norm_outflow = (norm_storage <= 0.9978f) ? 0.7880f * norm_storage + -0.1573f : 0.0290f * norm_storage + (0.7880f * 0.9978f + -0.1573f - 0.0290f * 0.9978f); break;
        case 12: norm_outflow = (norm_storage <= 0.9980f) ? 0.8010f * norm_storage + -0.1466f : 0.0236f * norm_storage + (0.8010f * 0.9980f + -0.1466f - 0.0236f * 0.9980f); break;
    }
    return norm_outflow * max_outflow_m3d;
}

static float rule_152(float inflow_m3d, float storage_m3, int month) {
    const float max_inflow_m3d   = 562113758.5f;
    const float max_outflow_m3d  = 143562762.6f;
    const float max_storage_m3   = 6802358500.0f;
    const float norm_inflow  = inflow_m3d  / max_inflow_m3d;
    const float norm_storage = storage_m3  / max_storage_m3;
    float norm_outflow;

    switch (month) {
        case  1: norm_outflow = (norm_storage <= 0.9541f) ? 0.7670f * norm_storage + -0.3281f : 0.4603f * norm_storage + (0.7670f * 0.9541f + -0.3281f - 0.4603f * 0.9541f); break;
        case  2: norm_outflow = (norm_storage <= 0.9490f) ? 0.7636f * norm_storage + -0.3301f : 0.4973f * norm_storage + (0.7636f * 0.9490f + -0.3301f - 0.4973f * 0.9490f); break;
        case  3: norm_outflow = (norm_storage <= 0.9015f) ? 0.5527f * norm_storage + -0.2306f : 1.3100f * norm_storage + (0.5527f * 0.9015f + -0.2306f - 1.3100f * 0.9015f); break;
        case  4: norm_outflow = (norm_storage <= 0.8591f) ? 0.3483f * norm_storage + -0.1205f : 3.2498f * norm_storage + (0.3483f * 0.8591f + -0.1205f - 3.2498f * 0.8591f); break;
        case  5: norm_outflow = (norm_storage <= 0.8638f) ? 0.3377f * norm_storage + -0.1178f : 3.1524f * norm_storage + (0.3377f * 0.8638f + -0.1178f - 3.1524f * 0.8638f); break;
        case  6: norm_outflow = (norm_storage <= 0.9013f) ? 0.4147f * norm_storage + -0.1571f : 1.7917f * norm_storage + (0.4147f * 0.9013f + -0.1571f - 1.7917f * 0.9013f); break;
        case  7: norm_outflow = (norm_storage <= 0.9557f) ? 0.5344f * norm_storage + -0.2120f : 0.7222f * norm_storage + (0.5344f * 0.9557f + -0.2120f - 0.7222f * 0.9557f); break;
        case  8: norm_outflow = (norm_storage <= 0.9667f) ? 0.6043f * norm_storage + -0.2465f : 0.4311f * norm_storage + (0.6043f * 0.9667f + -0.2465f - 0.4311f * 0.9667f); break;
        case  9: norm_outflow = (norm_storage <= 0.9697f) ? 0.6510f * norm_storage + -0.2722f : 0.3208f * norm_storage + (0.6510f * 0.9697f + -0.2722f - 0.3208f * 0.9697f); break;
        case 10: norm_outflow = (norm_storage <= 0.9371f) ? 0.5795f * norm_storage + -0.2405f : 0.7309f * norm_storage + (0.5795f * 0.9371f + -0.2405f - 0.7309f * 0.9371f); break;
        case 11: norm_outflow = (norm_storage <= 0.9284f) ? 0.5585f * norm_storage + -0.2280f : 0.8704f * norm_storage + (0.5585f * 0.9284f + -0.2280f - 0.8704f * 0.9284f); break;
        case 12: norm_outflow = (norm_storage <= 0.9402f) ? 0.6880f * norm_storage + -0.2968f : 0.6427f * norm_storage + (0.6880f * 0.9402f + -0.2968f - 0.6427f * 0.9402f); break;
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
        case  1: norm_outflow = 1.0662f * norm_inflow + 0.0034f; break;
        case  2: norm_outflow = 1.0576f * norm_inflow + 0.0031f; break;
        case  3: norm_outflow = 1.0557f * norm_inflow + 0.0031f; break;
        case  4: norm_outflow = 1.0646f * norm_inflow + 0.0037f; break;
        case  5: norm_outflow = 1.0695f * norm_inflow + 0.0033f; break;
        case  6: norm_outflow = 1.0776f * norm_inflow + 0.0036f; break;
        case  7: norm_outflow = 1.0701f * norm_inflow + 0.0036f; break;
        case  8: norm_outflow = 1.0555f * norm_inflow + 0.0035f; break;
        case  9: norm_outflow = 1.0524f * norm_inflow + 0.0035f; break;
        case 10: norm_outflow = 1.0480f * norm_inflow + 0.0043f; break;
        case 11: norm_outflow = 1.0625f * norm_inflow + 0.0042f; break;
        case 12: norm_outflow = 1.0694f * norm_inflow + 0.0041f; break;
    }
    return norm_outflow * max_outflow_m3d;
}

static float rule_155(float inflow_m3d, float storage_m3, int month) {
    const float max_inflow_m3d   = 270343149.8f;
    const float max_outflow_m3d  = 25992447.2f;
    const float max_storage_m3   = 3465172192.0f;
    const float norm_inflow  = inflow_m3d  / max_inflow_m3d;
    const float norm_storage = storage_m3  / max_storage_m3;
    float norm_outflow;

    switch (month) {
        case  1: norm_outflow = (norm_storage <= 0.9138f) ? 1.0559f * norm_storage + -0.5681f : 1.1517f * norm_storage + (1.0559f * 0.9138f + -0.5681f - 1.1517f * 0.9138f); break;
        case  2: norm_outflow = (norm_storage <= 0.9123f) ? 1.0541f * norm_storage + -0.5687f : 1.1734f * norm_storage + (1.0541f * 0.9123f + -0.5687f - 1.1734f * 0.9123f); break;
        case  3: norm_outflow = (norm_storage <= 0.9302f) ? 1.0828f * norm_storage + -0.6079f : 1.4818f * norm_storage + (1.0828f * 0.9302f + -0.6079f - 1.4818f * 0.9302f); break;
        case  4: norm_outflow = (norm_storage <= 0.9291f) ? 1.0079f * norm_storage + -0.5656f : 2.1483f * norm_storage + (1.0079f * 0.9291f + -0.5656f - 2.1483f * 0.9291f); break;
        case  5: norm_outflow = (norm_storage <= 0.9308f) ? 1.0338f * norm_storage + -0.5886f : 2.0871f * norm_storage + (1.0338f * 0.9308f + -0.5886f - 2.0871f * 0.9308f); break;
        case  6: norm_outflow = (norm_storage <= 0.9066f) ? 0.8797f * norm_storage + -0.4558f : 1.4093f * norm_storage + (0.8797f * 0.9066f + -0.4558f - 1.4093f * 0.9066f); break;
        case  7: norm_outflow = (norm_storage <= 0.9108f) ? 0.9070f * norm_storage + -0.5023f : 1.7843f * norm_storage + (0.9070f * 0.9108f + -0.5023f - 1.7843f * 0.9108f); break;
        case  8: norm_outflow = (norm_storage <= 0.8819f) ? 0.7660f * norm_storage + -0.3999f : 1.6754f * norm_storage + (0.7660f * 0.8819f + -0.3999f - 1.6754f * 0.8819f); break;
        case  9: norm_outflow = (norm_storage <= 0.8756f) ? 0.7136f * norm_storage + -0.3705f : 1.6532f * norm_storage + (0.7136f * 0.8756f + -0.3705f - 1.6532f * 0.8756f); break;
        case 10: norm_outflow = (norm_storage <= 0.9057f) ? 0.9047f * norm_storage + -0.5024f : 1.7591f * norm_storage + (0.9047f * 0.9057f + -0.5024f - 1.7591f * 0.9057f); break;
        case 11: norm_outflow = (norm_storage <= 0.9204f) ? 1.0057f * norm_storage + -0.5647f : 1.6396f * norm_storage + (1.0057f * 0.9204f + -0.5647f - 1.6396f * 0.9204f); break;
        case 12: norm_outflow = (norm_storage <= 0.9265f) ? 1.1021f * norm_storage + -0.6183f : 1.3576f * norm_storage + (1.1021f * 0.9265f + -0.6183f - 1.3576f * 0.9265f); break;
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
        case  1: norm_outflow = 1.0736f * norm_inflow + 0.0066f; break;
        case  2: norm_outflow = 1.0780f * norm_inflow + 0.0070f; break;
        case  3: norm_outflow = 1.0737f * norm_inflow + 0.0040f; break;
        case  4: norm_outflow = 1.0786f * norm_inflow + 0.0038f; break;
        case  5: norm_outflow = 1.0780f * norm_inflow + 0.0037f; break;
        case  6: norm_outflow = 1.0749f * norm_inflow + 0.0035f; break;
        case  7: norm_outflow = 1.0734f * norm_inflow + 0.0036f; break;
        case  8: norm_outflow = 1.0732f * norm_inflow + 0.0029f; break;
        case  9: norm_outflow = 1.0657f * norm_inflow + 0.0036f; break;
        case 10: norm_outflow = 1.0724f * norm_inflow + 0.0035f; break;
        case 11: norm_outflow = 1.0764f * norm_inflow + 0.0040f; break;
        case 12: norm_outflow = 1.0748f * norm_inflow + 0.0045f; break;
    }
    return norm_outflow * max_outflow_m3d;
}

static float rule_158(float inflow_m3d, float storage_m3, int month) {
    const float max_inflow_m3d   = 717653468.2f;
    const float max_outflow_m3d  = 419715379.2f;
    const float max_storage_m3   = 4770873680.0f;
    const float norm_inflow  = inflow_m3d  / max_inflow_m3d;
    const float norm_storage = storage_m3  / max_storage_m3;
    float norm_outflow;

    switch (month) {
        case  1: norm_outflow = (norm_storage <= 0.9131f) ? 0.5562f * norm_storage + -0.2034f : 0.3973f * norm_storage + (0.5562f * 0.9131f + -0.2034f - 0.3973f * 0.9131f); break;
        case  2: norm_outflow = (norm_storage <= 0.9152f) ? 0.5686f * norm_storage + -0.2043f : 0.3925f * norm_storage + (0.5686f * 0.9152f + -0.2043f - 0.3925f * 0.9152f); break;
        case  3: norm_outflow = (norm_storage <= 0.8853f) ? 0.4711f * norm_storage + -0.1824f : 0.5344f * norm_storage + (0.4711f * 0.8853f + -0.1824f - 0.5344f * 0.8853f); break;
        case  4: norm_outflow = (norm_storage <= 0.9098f) ? 0.4687f * norm_storage + -0.1863f : 0.4884f * norm_storage + (0.4687f * 0.9098f + -0.1863f - 0.4884f * 0.9098f); break;
        case  5: norm_outflow = (norm_storage <= 0.9280f) ? 0.5485f * norm_storage + -0.1968f : 0.6868f * norm_storage + (0.5485f * 0.9280f + -0.1968f - 0.6868f * 0.9280f); break;
        case  6: norm_outflow = (norm_storage <= 0.9202f) ? 0.5121f * norm_storage + -0.1982f : 0.4868f * norm_storage + (0.5121f * 0.9202f + -0.1982f - 0.4868f * 0.9202f); break;
        case  7: norm_outflow = (norm_storage <= 0.9009f) ? 0.5025f * norm_storage + -0.1863f : 0.4589f * norm_storage + (0.5025f * 0.9009f + -0.1863f - 0.4589f * 0.9009f); break;
        case  8: norm_outflow = (norm_storage <= 0.8783f) ? 0.4338f * norm_storage + -0.1628f : 0.5451f * norm_storage + (0.4338f * 0.8783f + -0.1628f - 0.5451f * 0.8783f); break;
        case  9: norm_outflow = (norm_storage <= 0.8877f) ? 0.4062f * norm_storage + -0.1507f : 0.5785f * norm_storage + (0.4062f * 0.8877f + -0.1507f - 0.5785f * 0.8877f); break;
        case 10: norm_outflow = (norm_storage <= 0.8727f) ? 0.3895f * norm_storage + -0.1424f : 0.6498f * norm_storage + (0.3895f * 0.8727f + -0.1424f - 0.6498f * 0.8727f); break;
        case 11: norm_outflow = (norm_storage <= 0.8760f) ? 0.4422f * norm_storage + -0.1639f : 0.5719f * norm_storage + (0.4422f * 0.8760f + -0.1639f - 0.5719f * 0.8760f); break;
        case 12: norm_outflow = (norm_storage <= 0.9039f) ? 0.5134f * norm_storage + -0.1928f : 0.4366f * norm_storage + (0.5134f * 0.9039f + -0.1928f - 0.4366f * 0.9039f); break;
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
        case  1: norm_outflow = 1.0921f * norm_inflow + 0.0027f; break;
        case  2: norm_outflow = 1.0855f * norm_inflow + 0.0029f; break;
        case  3: norm_outflow = 1.0870f * norm_inflow + 0.0031f; break;
        case  4: norm_outflow = 1.0882f * norm_inflow + 0.0023f; break;
        case  5: norm_outflow = 1.0909f * norm_inflow + 0.0032f; break;
        case  6: norm_outflow = 1.0951f * norm_inflow + 0.0028f; break;
        case  7: norm_outflow = 1.0919f * norm_inflow + 0.0028f; break;
        case  8: norm_outflow = 1.0750f * norm_inflow + 0.0025f; break;
        case  9: norm_outflow = 1.0739f * norm_inflow + 0.0029f; break;
        case 10: norm_outflow = 1.0711f * norm_inflow + 0.0033f; break;
        case 11: norm_outflow = 1.0872f * norm_inflow + 0.0033f; break;
        case 12: norm_outflow = 1.0914f * norm_inflow + 0.0033f; break;
    }
    return norm_outflow * max_outflow_m3d;
}

static float rule_160(float inflow_m3d, float storage_m3, int month) {
    const float max_inflow_m3d   = 1079541553.0f;
    const float max_outflow_m3d  = 1073851565.0f;
    const float max_storage_m3   = 750077461.1f;
    const float norm_inflow  = inflow_m3d  / max_inflow_m3d;
    const float norm_storage = storage_m3  / max_storage_m3;
    float norm_outflow;

    switch (month) {
        case  1: norm_outflow = 1.0084f * norm_inflow + 0.0016f; break;
        case  2: norm_outflow = 1.0071f * norm_inflow + 0.0013f; break;
        case  3: norm_outflow = 1.0072f * norm_inflow + 0.0014f; break;
        case  4: norm_outflow = 1.0097f * norm_inflow + 0.0013f; break;
        case  5: norm_outflow = 1.0115f * norm_inflow + 0.0013f; break;
        case  6: norm_outflow = 1.0219f * norm_inflow + 0.0016f; break;
        case  7: norm_outflow = 1.0114f * norm_inflow + 0.0013f; break;
        case  8: norm_outflow = 1.0079f * norm_inflow + 0.0020f; break;
        case  9: norm_outflow = 1.0054f * norm_inflow + 0.0021f; break;
        case 10: norm_outflow = 1.0082f * norm_inflow + 0.0022f; break;
        case 11: norm_outflow = 1.0080f * norm_inflow + 0.0020f; break;
        case 12: norm_outflow = 1.0126f * norm_inflow + 0.0017f; break;
    }
    return norm_outflow * max_outflow_m3d;
}

static float rule_161(float inflow_m3d, float storage_m3, int month) {
    const float max_inflow_m3d   = 1029342561.0f;
    const float max_outflow_m3d  = 940823233.5f;
    const float max_storage_m3   = 976918627.0f;
    const float norm_inflow  = inflow_m3d  / max_inflow_m3d;
    const float norm_storage = storage_m3  / max_storage_m3;
    float norm_outflow;

    switch (month) {
        case  1: norm_outflow = 1.0768f * norm_inflow + 0.0034f; break;
        case  2: norm_outflow = 1.0750f * norm_inflow + 0.0033f; break;
        case  3: norm_outflow = 1.0740f * norm_inflow + 0.0034f; break;
        case  4: norm_outflow = 1.0781f * norm_inflow + 0.0035f; break;
        case  5: norm_outflow = 1.0822f * norm_inflow + 0.0039f; break;
        case  6: norm_outflow = 1.0830f * norm_inflow + 0.0045f; break;
        case  7: norm_outflow = 1.0872f * norm_inflow + 0.0043f; break;
        case  8: norm_outflow = 1.0773f * norm_inflow + 0.0042f; break;
        case  9: norm_outflow = 1.0712f * norm_inflow + 0.0039f; break;
        case 10: norm_outflow = 1.0737f * norm_inflow + 0.0036f; break;
        case 11: norm_outflow = 1.0771f * norm_inflow + 0.0037f; break;
        case 12: norm_outflow = 1.0750f * norm_inflow + 0.0039f; break;
    }
    return norm_outflow * max_outflow_m3d;
}

static float rule_162(float inflow_m3d, float storage_m3, int month) {
    const float max_inflow_m3d   = 349371193.0f;
    const float max_outflow_m3d  = 32801225.8f;
    const float max_storage_m3   = 3303090453.0f;
    const float norm_inflow  = inflow_m3d  / max_inflow_m3d;
    const float norm_storage = storage_m3  / max_storage_m3;
    float norm_outflow;

    switch (month) {
        case  1: norm_outflow = (norm_storage <= 0.8493f) ? 0.4469f * norm_storage + -0.2193f : 3.0250f * norm_storage + (0.4469f * 0.8493f + -0.2193f - 3.0250f * 0.8493f); break;
        case  2: norm_outflow = (norm_storage <= 0.8363f) ? 0.3831f * norm_storage + -0.1910f : 3.4578f * norm_storage + (0.3831f * 0.8363f + -0.1910f - 3.4578f * 0.8363f); break;
        case  3: norm_outflow = (norm_storage <= 0.8381f) ? 0.4472f * norm_storage + -0.2461f : 3.9901f * norm_storage + (0.4472f * 0.8381f + -0.2461f - 3.9901f * 0.8381f); break;
        case  4: norm_outflow = (norm_storage <= 0.8453f) ? 0.5237f * norm_storage + -0.3094f : 4.3027f * norm_storage + (0.5237f * 0.8453f + -0.3094f - 4.3027f * 0.8453f); break;
        case  5: norm_outflow = (norm_storage <= 0.8584f) ? 0.6902f * norm_storage + -0.4245f : 3.7008f * norm_storage + (0.6902f * 0.8584f + -0.4245f - 3.7008f * 0.8584f); break;
        case  6: norm_outflow = (norm_storage <= 0.8473f) ? 0.4155f * norm_storage + -0.2083f : 4.0351f * norm_storage + (0.4155f * 0.8473f + -0.2083f - 4.0351f * 0.8473f); break;
        case  7: norm_outflow = 0.8840f * norm_inflow + 0.0720f; break;
        case  8: norm_outflow = 0.7725f * norm_inflow + 0.0676f; break;
        case  9: norm_outflow = (norm_storage <= 0.8633f) ? 0.4237f * norm_storage + -0.2108f : 3.0935f * norm_storage + (0.4237f * 0.8633f + -0.2108f - 3.0935f * 0.8633f); break;
        case 10: norm_outflow = (norm_storage <= 0.8374f) ? 0.3400f * norm_storage + -0.1639f : 3.9809f * norm_storage + (0.3400f * 0.8374f + -0.1639f - 3.9809f * 0.8374f); break;
        case 11: norm_outflow = (norm_storage <= 0.8328f) ? 0.4068f * norm_storage + -0.2153f : 3.9946f * norm_storage + (0.4068f * 0.8328f + -0.2153f - 3.9946f * 0.8328f); break;
        case 12: norm_outflow = (norm_storage <= 0.8281f) ? 0.4102f * norm_storage + -0.2159f : 3.8383f * norm_storage + (0.4102f * 0.8281f + -0.2159f - 3.8383f * 0.8281f); break;
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
        case  1: norm_outflow = 1.0111f * norm_inflow + 0.0018f; break;
        case  2: norm_outflow = 1.0116f * norm_inflow + 0.0015f; break;
        case  3: norm_outflow = 1.0127f * norm_inflow + 0.0016f; break;
        case  4: norm_outflow = 1.0159f * norm_inflow + 0.0013f; break;
        case  5: norm_outflow = 1.0161f * norm_inflow + 0.0015f; break;
        case  6: norm_outflow = 1.0209f * norm_inflow + 0.0017f; break;
        case  7: norm_outflow = 1.0212f * norm_inflow + 0.0014f; break;
        case  8: norm_outflow = 1.0200f * norm_inflow + 0.0016f; break;
        case  9: norm_outflow = 1.0139f * norm_inflow + 0.0017f; break;
        case 10: norm_outflow = 1.0156f * norm_inflow + 0.0020f; break;
        case 11: norm_outflow = 1.0147f * norm_inflow + 0.0017f; break;
        case 12: norm_outflow = 1.0162f * norm_inflow + 0.0020f; break;
    }
    return norm_outflow * max_outflow_m3d;
}

static float rule_168(float inflow_m3d, float storage_m3, int month) {
    const float max_inflow_m3d   = 540145376.5f;
    const float max_outflow_m3d  = 171749638.2f;
    const float max_storage_m3   = 7239669098.0f;
    const float norm_inflow  = inflow_m3d  / max_inflow_m3d;
    const float norm_storage = storage_m3  / max_storage_m3;
    float norm_outflow;

    switch (month) {
        case  1: norm_outflow = (norm_storage <= 0.9968f) ? 1.4567f * norm_storage + -0.5121f : 0.0459f * norm_storage + (1.4567f * 0.9968f + -0.5121f - 0.0459f * 0.9968f); break;
        case  2: norm_outflow = (norm_storage <= 0.9974f) ? 1.4658f * norm_storage + -0.5123f : 0.0226f * norm_storage + (1.4658f * 0.9974f + -0.5123f - 0.0226f * 0.9974f); break;
        case  3: norm_outflow = (norm_storage <= 0.9949f) ? 1.5127f * norm_storage + -0.5437f : 0.0340f * norm_storage + (1.5127f * 0.9949f + -0.5437f - 0.0340f * 0.9949f); break;
        case  4: norm_outflow = (norm_storage <= 0.9951f) ? 1.5338f * norm_storage + -0.5589f : 0.0318f * norm_storage + (1.5338f * 0.9951f + -0.5589f - 0.0318f * 0.9951f); break;
        case  5: norm_outflow = (norm_storage <= 0.9878f) ? 1.3178f * norm_storage + -0.4678f : 0.1856f * norm_storage + (1.3178f * 0.9878f + -0.4678f - 0.1856f * 0.9878f); break;
        case  6: norm_outflow = (norm_storage <= 0.9902f) ? 1.3686f * norm_storage + -0.4927f : 0.1530f * norm_storage + (1.3686f * 0.9902f + -0.4927f - 0.1530f * 0.9902f); break;
        case  7: norm_outflow = (norm_storage <= 0.9900f) ? 1.3497f * norm_storage + -0.4772f : 0.1447f * norm_storage + (1.3497f * 0.9900f + -0.4772f - 0.1447f * 0.9900f); break;
        case  8: norm_outflow = (norm_storage <= 0.9925f) ? 1.3995f * norm_storage + -0.4977f : 0.0653f * norm_storage + (1.3995f * 0.9925f + -0.4977f - 0.0653f * 0.9925f); break;
        case  9: norm_outflow = (norm_storage <= 0.9846f) ? 1.3736f * norm_storage + -0.4959f : 0.1214f * norm_storage + (1.3736f * 0.9846f + -0.4959f - 0.1214f * 0.9846f); break;
        case 10: norm_outflow = (norm_storage <= 0.9822f) ? 1.2896f * norm_storage + -0.4467f : 0.1618f * norm_storage + (1.2896f * 0.9822f + -0.4467f - 0.1618f * 0.9822f); break;
        case 11: norm_outflow = (norm_storage <= 0.9912f) ? 1.3772f * norm_storage + -0.4866f : 0.0821f * norm_storage + (1.3772f * 0.9912f + -0.4866f - 0.0821f * 0.9912f); break;
        case 12: norm_outflow = (norm_storage <= 0.9966f) ? 1.4193f * norm_storage + -0.5112f : 0.0287f * norm_storage + (1.4193f * 0.9966f + -0.5112f - 0.0287f * 0.9966f); break;
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
        case  1: norm_outflow = (norm_storage <= 0.9908f) ? 0.5778f * norm_storage + -0.0128f : 0.1506f * norm_storage + (0.5778f * 0.9908f + -0.0128f - 0.1506f * 0.9908f); break;
        case  2: norm_outflow = (norm_storage <= 0.9850f) ? 0.5609f * norm_storage + -0.0125f : 0.2996f * norm_storage + (0.5609f * 0.9850f + -0.0125f - 0.2996f * 0.9850f); break;
        case  3: norm_outflow = (norm_storage <= 0.9882f) ? 0.5722f * norm_storage + -0.0180f : 0.2197f * norm_storage + (0.5722f * 0.9882f + -0.0180f - 0.2197f * 0.9882f); break;
        case  4: norm_outflow = (norm_storage <= 0.9785f) ? 0.5496f * norm_storage + -0.0299f : 0.5610f * norm_storage + (0.5496f * 0.9785f + -0.0299f - 0.5610f * 0.9785f); break;
        case  5: norm_outflow = (norm_storage <= 0.9882f) ? 0.6017f * norm_storage + -0.0485f : 0.3088f * norm_storage + (0.6017f * 0.9882f + -0.0485f - 0.3088f * 0.9882f); break;
        case  6: norm_outflow = (norm_storage <= 0.9907f) ? 0.6180f * norm_storage + -0.0659f : 0.1962f * norm_storage + (0.6180f * 0.9907f + -0.0659f - 0.1962f * 0.9907f); break;
        case  7: norm_outflow = (norm_storage <= 0.9892f) ? 0.6328f * norm_storage + -0.0736f : 0.2045f * norm_storage + (0.6328f * 0.9892f + -0.0736f - 0.2045f * 0.9892f); break;
        case  8: norm_outflow = (norm_storage <= 0.9903f) ? 0.7659f * norm_storage + -0.0932f : 0.1037f * norm_storage + (0.7659f * 0.9903f + -0.0932f - 0.1037f * 0.9903f); break;
        case  9: norm_outflow = (norm_storage <= 0.9904f) ? 0.7474f * norm_storage + -0.0813f : 0.1068f * norm_storage + (0.7474f * 0.9904f + -0.0813f - 0.1068f * 0.9904f); break;
        case 10: norm_outflow = (norm_storage <= 0.9890f) ? 0.7431f * norm_storage + -0.0827f : 0.1306f * norm_storage + (0.7431f * 0.9890f + -0.0827f - 0.1306f * 0.9890f); break;
        case 11: norm_outflow = (norm_storage <= 0.9913f) ? 0.5782f * norm_storage + -0.0270f : 0.1022f * norm_storage + (0.5782f * 0.9913f + -0.0270f - 0.1022f * 0.9913f); break;
        case 12: norm_outflow = (norm_storage <= 0.9788f) ? 0.5394f * norm_storage + -0.0145f : 0.4556f * norm_storage + (0.5394f * 0.9788f + -0.0145f - 0.4556f * 0.9788f); break;
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
        case  1: norm_outflow = (norm_storage <= 0.8614f) ? 0.0978f * norm_storage + 0.0087f : 3.6652f * norm_storage + (0.0978f * 0.8614f + 0.0087f - 3.6652f * 0.8614f); break;
        case  2: norm_outflow = (norm_storage <= 0.8237f) ? 0.1006f * norm_storage + 0.0029f : 5.0111f * norm_storage + (0.1006f * 0.8237f + 0.0029f - 5.0111f * 0.8237f); break;
        case  3: norm_outflow = (norm_storage <= 0.8275f) ? 0.1079f * norm_storage + 0.0051f : 4.6089f * norm_storage + (0.1079f * 0.8275f + 0.0051f - 4.6089f * 0.8275f); break;
        case  4: norm_outflow = 1.3262f * norm_inflow + 0.0617f; break;
        case  5: norm_outflow = 1.2582f * norm_inflow + 0.0721f; break;
        case  6: norm_outflow = (norm_storage <= 0.8654f) ? 0.1844f * norm_storage + 0.0052f : 3.5540f * norm_storage + (0.1844f * 0.8654f + 0.0052f - 3.5540f * 0.8654f); break;
        case  7: norm_outflow = 1.2132f * norm_inflow + 0.0841f; break;
        case  8: norm_outflow = (norm_storage <= 0.8912f) ? 0.1645f * norm_storage + 0.0325f : 1.1717f * norm_storage + (0.1645f * 0.8912f + 0.0325f - 1.1717f * 0.8912f); break;
        case  9: norm_outflow = 1.2919f * norm_inflow + 0.0602f; break;
        case 10: norm_outflow = (norm_storage <= 0.8675f) ? 0.1336f * norm_storage + 0.0196f : 1.4138f * norm_storage + (0.1336f * 0.8675f + 0.0196f - 1.4138f * 0.8675f); break;
        case 11: norm_outflow = (norm_storage <= 0.8817f) ? 0.1194f * norm_storage + 0.0188f : 1.3827f * norm_storage + (0.1194f * 0.8817f + 0.0188f - 1.3827f * 0.8817f); break;
        case 12: norm_outflow = (norm_storage <= 0.8823f) ? 0.1130f * norm_storage + 0.0181f : 1.8137f * norm_storage + (0.1130f * 0.8823f + 0.0181f - 1.8137f * 0.8823f); break;
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
        case  1: norm_outflow = 0.2673f * norm_inflow + 0.0393f; break;
        case  2: norm_outflow = 0.2804f * norm_inflow + 0.0405f; break;
        case  3: norm_outflow = 0.3193f * norm_inflow + 0.0675f; break;
        case  4: norm_outflow = 0.4689f * norm_inflow + 0.1079f; break;
        case  5: norm_outflow = 0.4474f * norm_inflow + 0.1242f; break;
        case  6: norm_outflow = 0.5215f * norm_inflow + 0.1281f; break;
        case  7: norm_outflow = 0.4557f * norm_inflow + 0.1371f; break;
        case  8: norm_outflow = 0.4639f * norm_inflow + 0.1274f; break;
        case  9: norm_outflow = 0.5082f * norm_inflow + 0.1045f; break;
        case 10: norm_outflow = 0.3345f * norm_inflow + 0.0633f; break;
        case 11: norm_outflow = 0.2772f * norm_inflow + 0.0475f; break;
        case 12: norm_outflow = 0.2804f * norm_inflow + 0.0439f; break;
    }
    return norm_outflow * max_outflow_m3d;
}

static float rule_493(float inflow_m3d, float storage_m3, int month) {
    const float max_inflow_m3d   = 46514715.5f;
    const float max_outflow_m3d  = 12959745.2f;
    const float max_storage_m3   = 1608282766.0f;
    const float norm_inflow  = inflow_m3d  / max_inflow_m3d;
    const float norm_storage = storage_m3  / max_storage_m3;
    float norm_outflow;

    switch (month) {
        case  1: norm_outflow = (norm_storage <= 0.8923f) ? 0.2829f * norm_storage + -0.0776f : 1.2492f * norm_storage + (0.2829f * 0.8923f + -0.0776f - 1.2492f * 0.8923f); break;
        case  2: norm_outflow = (norm_storage <= 0.8389f) ? 0.2261f * norm_storage + -0.0482f : 2.7317f * norm_storage + (0.2261f * 0.8389f + -0.0482f - 2.7317f * 0.8389f); break;
        case  3: norm_outflow = (norm_storage <= 0.8222f) ? 0.2194f * norm_storage + -0.0414f : 2.2915f * norm_storage + (0.2194f * 0.8222f + -0.0414f - 2.2915f * 0.8222f); break;
        case  4: norm_outflow = (norm_storage <= 0.8127f) ? 0.2273f * norm_storage + -0.0385f : 2.3252f * norm_storage + (0.2273f * 0.8127f + -0.0385f - 2.3252f * 0.8127f); break;
        case  5: norm_outflow = 1.1953f * norm_inflow + 0.0729f; break;
        case  6: norm_outflow = 1.1836f * norm_inflow + 0.0692f; break;
        case  7: norm_outflow = 1.3077f * norm_inflow + 0.0779f; break;
        case  8: norm_outflow = (norm_storage <= 0.8612f) ? 0.3563f * norm_storage + -0.0725f : 1.7458f * norm_storage + (0.3563f * 0.8612f + -0.0725f - 1.7458f * 0.8612f); break;
        case  9: norm_outflow = (norm_storage <= 0.8500f) ? 0.3202f * norm_storage + -0.0650f : 1.8147f * norm_storage + (0.3202f * 0.8500f + -0.0650f - 1.8147f * 0.8500f); break;
        case 10: norm_outflow = (norm_storage <= 0.8405f) ? 0.2699f * norm_storage + -0.0552f : 2.2518f * norm_storage + (0.2699f * 0.8405f + -0.0552f - 2.2518f * 0.8405f); break;
        case 11: norm_outflow = (norm_storage <= 0.8857f) ? 0.3051f * norm_storage + -0.0757f : 1.3091f * norm_storage + (0.3051f * 0.8857f + -0.0757f - 1.3091f * 0.8857f); break;
        case 12: norm_outflow = (norm_storage <= 0.8979f) ? 0.2986f * norm_storage + -0.0778f : 1.3460f * norm_storage + (0.2986f * 0.8979f + -0.0778f - 1.3460f * 0.8979f); break;
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
        case  1: norm_outflow = 3.5327f * norm_inflow + 0.1193f; break;
        case  2: norm_outflow = 3.5425f * norm_inflow + 0.1181f; break;
        case  3: norm_outflow = 3.4015f * norm_inflow + 0.1265f; break;
        case  4: norm_outflow = 3.0955f * norm_inflow + 0.1432f; break;
        case  5: norm_outflow = 3.0370f * norm_inflow + 0.1461f; break;
        case  6: norm_outflow = 3.0208f * norm_inflow + 0.1445f; break;
        case  7: norm_outflow = 3.0349f * norm_inflow + 0.1454f; break;
        case  8: norm_outflow = 3.0841f * norm_inflow + 0.1458f; break;
        case  9: norm_outflow = 3.2246f * norm_inflow + 0.1399f; break;
        case 10: norm_outflow = 3.2934f * norm_inflow + 0.1380f; break;
        case 11: norm_outflow = 3.4590f * norm_inflow + 0.1268f; break;
        case 12: norm_outflow = 3.5110f * norm_inflow + 0.1222f; break;
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
        case  1: norm_outflow = 1.2744f * norm_inflow + 0.0609f; break;
        case  2: norm_outflow = 1.2693f * norm_inflow + 0.0610f; break;
        case  3: norm_outflow = 1.0588f * norm_inflow + 0.0618f; break;
        case  4: norm_outflow = 1.0347f * norm_inflow + 0.0630f; break;
        case  5: norm_outflow = 1.0568f * norm_inflow + 0.0663f; break;
        case  6: norm_outflow = 1.1128f * norm_inflow + 0.0669f; break;
        case  7: norm_outflow = 1.0938f * norm_inflow + 0.0671f; break;
        case  8: norm_outflow = 1.0465f * norm_inflow + 0.0661f; break;
        case  9: norm_outflow = 1.0646f * norm_inflow + 0.0655f; break;
        case 10: norm_outflow = 1.0629f * norm_inflow + 0.0664f; break;
        case 11: norm_outflow = 1.1293f * norm_inflow + 0.0644f; break;
        case 12: norm_outflow = 1.1892f * norm_inflow + 0.0625f; break;
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
        case  1: norm_outflow = 1.3208f * norm_inflow + 0.0209f; break;
        case  2: norm_outflow = 1.3308f * norm_inflow + 0.0210f; break;
        case  3: norm_outflow = (norm_storage <= 0.8924f) ? 0.3954f * norm_storage + -0.1043f : 2.1968f * norm_storage + (0.3954f * 0.8924f + -0.1043f - 2.1968f * 0.8924f); break;
        case  4: norm_outflow = (norm_storage <= 0.8857f) ? 0.4241f * norm_storage + -0.1187f : 2.5822f * norm_storage + (0.4241f * 0.8857f + -0.1187f - 2.5822f * 0.8857f); break;
        case  5: norm_outflow = 1.5612f * norm_inflow + 0.0288f; break;
        case  6: norm_outflow = 1.5298f * norm_inflow + 0.0305f; break;
        case  7: norm_outflow = 1.4911f * norm_inflow + 0.0326f; break;
        case  8: norm_outflow = 1.5187f * norm_inflow + 0.0300f; break;
        case  9: norm_outflow = 1.4816f * norm_inflow + 0.0277f; break;
        case 10: norm_outflow = 1.4349f * norm_inflow + 0.0221f; break;
        case 11: norm_outflow = 1.4238f * norm_inflow + 0.0222f; break;
        case 12: norm_outflow = 1.3502f * norm_inflow + 0.0215f; break;
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
        case  1: norm_outflow = 2.8081f * norm_inflow + 0.0888f; break;
        case  2: norm_outflow = 2.6519f * norm_inflow + 0.0920f; break;
        case  3: norm_outflow = 2.4595f * norm_inflow + 0.1006f; break;
        case  4: norm_outflow = 2.1780f * norm_inflow + 0.1109f; break;
        case  5: norm_outflow = 2.1050f * norm_inflow + 0.1139f; break;
        case  6: norm_outflow = 2.0983f * norm_inflow + 0.1130f; break;
        case  7: norm_outflow = 2.1029f * norm_inflow + 0.1127f; break;
        case  8: norm_outflow = 2.1316f * norm_inflow + 0.1139f; break;
        case  9: norm_outflow = 2.2197f * norm_inflow + 0.1085f; break;
        case 10: norm_outflow = 2.3085f * norm_inflow + 0.1072f; break;
        case 11: norm_outflow = 2.5812f * norm_inflow + 0.0985f; break;
        case 12: norm_outflow = 2.6134f * norm_inflow + 0.0970f; break;
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
        case  1: norm_outflow = (norm_storage <= 0.9113f) ? 0.1700f * norm_storage + -0.0263f : 2.2685f * norm_storage + (0.1700f * 0.9113f + -0.0263f - 2.2685f * 0.9113f); break;
        case  2: norm_outflow = (norm_storage <= 0.8663f) ? 0.1829f * norm_storage + -0.0354f : 2.1919f * norm_storage + (0.1829f * 0.8663f + -0.0354f - 2.1919f * 0.8663f); break;
        case  3: norm_outflow = (norm_storage <= 0.8269f) ? 0.2049f * norm_storage + -0.0395f : 3.0822f * norm_storage + (0.2049f * 0.8269f + -0.0395f - 3.0822f * 0.8269f); break;
        case  4: norm_outflow = (norm_storage <= 0.8244f) ? 0.2184f * norm_storage + -0.0402f : 3.5699f * norm_storage + (0.2184f * 0.8244f + -0.0402f - 3.5699f * 0.8244f); break;
        case  5: norm_outflow = 1.8065f * norm_inflow + 0.0346f; break;
        case  6: norm_outflow = 1.8003f * norm_inflow + 0.0360f; break;
        case  7: norm_outflow = 1.8092f * norm_inflow + 0.0370f; break;
        case  8: norm_outflow = (norm_storage <= 0.8593f) ? 0.1826f * norm_storage + -0.0120f : 4.0851f * norm_storage + (0.1826f * 0.8593f + -0.0120f - 4.0851f * 0.8593f); break;
        case  9: norm_outflow = (norm_storage <= 0.8970f) ? 0.1965f * norm_storage + -0.0201f : 2.3950f * norm_storage + (0.1965f * 0.8970f + -0.0201f - 2.3950f * 0.8970f); break;
        case 10: norm_outflow = (norm_storage <= 0.8993f) ? 0.1766f * norm_storage + -0.0202f : 2.3616f * norm_storage + (0.1766f * 0.8993f + -0.0202f - 2.3616f * 0.8993f); break;
        case 11: norm_outflow = (norm_storage <= 0.9183f) ? 0.1521f * norm_storage + -0.0107f : 2.0113f * norm_storage + (0.1521f * 0.9183f + -0.0107f - 2.0113f * 0.9183f); break;
        case 12: norm_outflow = (norm_storage <= 0.9247f) ? 0.1481f * norm_storage + -0.0162f : 1.6401f * norm_storage + (0.1481f * 0.9247f + -0.0162f - 1.6401f * 0.9247f); break;
    }
    return norm_outflow * max_outflow_m3d;
}

static float rule_606(float inflow_m3d, float storage_m3, int month) {
    const float max_inflow_m3d   = 51392284.8f;
    const float max_outflow_m3d  = 37662110.6f;
    const float max_storage_m3   = 1536031675.0f;
    const float norm_inflow  = inflow_m3d  / max_inflow_m3d;
    const float norm_storage = storage_m3  / max_storage_m3;
    float norm_outflow;

    switch (month) {
        case  1: norm_outflow = 1.0741f * norm_inflow + 0.0484f; break;
        case  2: norm_outflow = 1.1269f * norm_inflow + 0.0402f; break;
        case  3: norm_outflow = 1.1435f * norm_inflow + 0.0433f; break;
        case  4: norm_outflow = 1.2022f * norm_inflow + 0.0322f; break;
        case  5: norm_outflow = 1.0448f * norm_inflow + 0.0520f; break;
        case  6: norm_outflow = 1.0476f * norm_inflow + 0.0538f; break;
        case  7: norm_outflow = 1.0273f * norm_inflow + 0.0691f; break;
        case  8: norm_outflow = 1.0437f * norm_inflow + 0.0657f; break;
        case  9: norm_outflow = (norm_storage <= 0.9161f) ? 0.2393f * norm_storage + -0.0078f : 0.9249f * norm_storage + (0.2393f * 0.9161f + -0.0078f - 0.9249f * 0.9161f); break;
        case 10: norm_outflow = (norm_storage <= 0.9206f) ? 0.2554f * norm_storage + -0.0187f : 1.1340f * norm_storage + (0.2554f * 0.9206f + -0.0187f - 1.1340f * 0.9206f); break;
        case 11: norm_outflow = 1.0589f * norm_inflow + 0.0514f; break;
        case 12: norm_outflow = 1.0602f * norm_inflow + 0.0508f; break;
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
        case  1: norm_outflow = 1.0171f * norm_inflow + 0.0108f; break;
        case  2: norm_outflow = 1.0363f * norm_inflow + 0.0111f; break;
        case  3: norm_outflow = 1.0147f * norm_inflow + 0.0108f; break;
        case  4: norm_outflow = 1.0963f * norm_inflow + 0.0117f; break;
        case  5: norm_outflow = 1.1037f * norm_inflow + 0.0118f; break;
        case  6: norm_outflow = 1.1059f * norm_inflow + 0.0136f; break;
        case  7: norm_outflow = 1.1206f * norm_inflow + 0.0127f; break;
        case  8: norm_outflow = 1.1093f * norm_inflow + 0.0115f; break;
        case  9: norm_outflow = 1.0431f * norm_inflow + 0.0125f; break;
        case 10: norm_outflow = 1.0151f * norm_inflow + 0.0133f; break;
        case 11: norm_outflow = 0.9460f * norm_inflow + 0.0121f; break;
        case 12: norm_outflow = 0.9135f * norm_inflow + 0.0116f; break;
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
        case  1: norm_outflow = (norm_storage <= 0.8445f) ? 0.1104f * norm_storage + 0.0042f : 1.0340f * norm_storage + (0.1104f * 0.8445f + 0.0042f - 1.0340f * 0.8445f); break;
        case  2: norm_outflow = (norm_storage <= 0.8133f) ? 0.1269f * norm_storage + -0.0004f : 1.5689f * norm_storage + (0.1269f * 0.8133f + -0.0004f - 1.5689f * 0.8133f); break;
        case  3: norm_outflow = 1.5616f * norm_inflow + 0.0291f; break;
        case  4: norm_outflow = 1.5251f * norm_inflow + 0.0375f; break;
        case  5: norm_outflow = (norm_storage <= 0.9033f) ? 0.1891f * norm_storage + 0.0541f : 1.1971f * norm_storage + (0.1891f * 0.9033f + 0.0541f - 1.1971f * 0.9033f); break;
        case  6: norm_outflow = (norm_storage <= 0.9127f) ? 0.2045f * norm_storage + 0.0644f : 1.4855f * norm_storage + (0.2045f * 0.9127f + 0.0644f - 1.4855f * 0.9127f); break;
        case  7: norm_outflow = 1.4715f * norm_inflow + 0.0757f; break;
        case  8: norm_outflow = 1.5600f * norm_inflow + 0.0654f; break;
        case  9: norm_outflow = (norm_storage <= 0.9069f) ? 0.2139f * norm_storage + 0.0306f : 0.7342f * norm_storage + (0.2139f * 0.9069f + 0.0306f - 0.7342f * 0.9069f); break;
        case 10: norm_outflow = (norm_storage <= 0.8661f) ? 0.1693f * norm_storage + 0.0189f : 1.0391f * norm_storage + (0.1693f * 0.8661f + 0.0189f - 1.0391f * 0.8661f); break;
        case 11: norm_outflow = (norm_storage <= 0.8508f) ? 0.1337f * norm_storage + 0.0148f : 1.1186f * norm_storage + (0.1337f * 0.8508f + 0.0148f - 1.1186f * 0.8508f); break;
        case 12: norm_outflow = 1.3097f * norm_inflow + 0.0179f; break;
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
        case  1: norm_outflow = 0.3007f * norm_inflow + 0.0450f; break;
        case  2: norm_outflow = 0.3090f * norm_inflow + 0.0463f; break;
        case  3: norm_outflow = (norm_storage <= 0.8592f) ? 0.1707f * norm_storage + -0.0031f : 1.4991f * norm_storage + (0.1707f * 0.8592f + -0.0031f - 1.4991f * 0.8592f); break;
        case  4: norm_outflow = 0.4051f * norm_inflow + 0.0896f; break;
        case  5: norm_outflow = (norm_storage <= 0.9123f) ? 0.2108f * norm_storage + 0.0125f : 1.6865f * norm_storage + (0.2108f * 0.9123f + 0.0125f - 1.6865f * 0.9123f); break;
        case  6: norm_outflow = 0.4523f * norm_inflow + 0.1022f; break;
        case  7: norm_outflow = (norm_storage <= 0.9290f) ? 0.1462f * norm_storage + 0.1179f : 0.8651f * norm_storage + (0.1462f * 0.9290f + 0.1179f - 0.8651f * 0.9290f); break;
        case  8: norm_outflow = 0.3670f * norm_inflow + 0.1131f; break;
        case  9: norm_outflow = (norm_storage <= 0.9361f) ? 0.2118f * norm_storage + 0.0615f : 0.5439f * norm_storage + (0.2118f * 0.9361f + 0.0615f - 0.5439f * 0.9361f); break;
        case 10: norm_outflow = 0.2678f * norm_inflow + 0.0650f; break;
        case 11: norm_outflow = 0.2943f * norm_inflow + 0.0521f; break;
        case 12: norm_outflow = 0.2787f * norm_inflow + 0.0488f; break;
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
        case  1: norm_outflow = 1.0531f * norm_inflow + 0.0137f; break;
        case  2: norm_outflow = 1.0526f * norm_inflow + 0.0130f; break;
        case  3: norm_outflow = 0.9377f * norm_inflow + 0.0302f; break;
        case  4: norm_outflow = 0.8666f * norm_inflow + 0.0492f; break;
        case  5: norm_outflow = 0.8848f * norm_inflow + 0.0689f; break;
        case  6: norm_outflow = 0.8979f * norm_inflow + 0.0807f; break;
        case  7: norm_outflow = 1.0819f * norm_inflow + 0.0722f; break;
        case  8: norm_outflow = (norm_storage <= 0.9795f) ? 0.2947f * norm_storage + 0.0598f : 0.5787f * norm_storage + (0.2947f * 0.9795f + 0.0598f - 0.5787f * 0.9795f); break;
        case  9: norm_outflow = (norm_storage <= 0.9787f) ? 0.3048f * norm_storage + 0.0446f : 0.4721f * norm_storage + (0.3048f * 0.9787f + 0.0446f - 0.4721f * 0.9787f); break;
        case 10: norm_outflow = 1.0462f * norm_inflow + 0.0208f; break;
        case 11: norm_outflow = 1.1069f * norm_inflow + 0.0194f; break;
        case 12: norm_outflow = 1.0644f * norm_inflow + 0.0155f; break;
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
        case  1: norm_outflow = (norm_storage <= 0.9651f) ? 0.1058f * norm_storage + 0.0230f : 0.5160f * norm_storage + (0.1058f * 0.9651f + 0.0230f - 0.5160f * 0.9651f); break;
        case  2: norm_outflow = (norm_storage <= 0.9537f) ? 0.1104f * norm_storage + 0.0227f : 0.4191f * norm_storage + (0.1104f * 0.9537f + 0.0227f - 0.4191f * 0.9537f); break;
        case  3: norm_outflow = 0.9802f * norm_inflow + 0.0869f; break;
        case  4: norm_outflow = 0.9158f * norm_inflow + 0.0833f; break;
        case  5: norm_outflow = 0.8282f * norm_inflow + 0.0921f; break;
        case  6: norm_outflow = 0.8538f * norm_inflow + 0.1007f; break;
        case  7: norm_outflow = 0.8618f * norm_inflow + 0.1104f; break;
        case  8: norm_outflow = 0.8416f * norm_inflow + 0.1047f; break;
        case  9: norm_outflow = (norm_storage <= 0.9665f) ? 0.1419f * norm_storage + 0.0466f : 0.3011f * norm_storage + (0.1419f * 0.9665f + 0.0466f - 0.3011f * 0.9665f); break;
        case 10: norm_outflow = (norm_storage <= 0.9605f) ? 0.1201f * norm_storage + 0.0294f : 0.3484f * norm_storage + (0.1201f * 0.9605f + 0.0294f - 0.3484f * 0.9605f); break;
        case 11: norm_outflow = (norm_storage <= 0.9666f) ? 0.1078f * norm_storage + 0.0266f : 0.3164f * norm_storage + (0.1078f * 0.9666f + 0.0266f - 0.3164f * 0.9666f); break;
        case 12: norm_outflow = (norm_storage <= 0.9609f) ? 0.1028f * norm_storage + 0.0243f : 0.5855f * norm_storage + (0.1028f * 0.9609f + 0.0243f - 0.5855f * 0.9609f); break;
    }
    return norm_outflow * max_outflow_m3d;
}

static float rule_694(float inflow_m3d, float storage_m3, int month) {
    const float max_inflow_m3d   = 49626808.9f;
    const float max_outflow_m3d  = 26149125.4f;
    const float max_storage_m3   = 1094259579.0f;
    const float norm_inflow  = inflow_m3d  / max_inflow_m3d;
    const float norm_storage = storage_m3  / max_storage_m3;
    float norm_outflow;

    switch (month) {
        case  1: norm_outflow = (norm_storage <= 0.9322f) ? 0.1855f * norm_storage + -0.0170f : 1.4162f * norm_storage + (0.1855f * 0.9322f + -0.0170f - 1.4162f * 0.9322f); break;
        case  2: norm_outflow = (norm_storage <= 0.8907f) ? 0.1623f * norm_storage + -0.0122f : 1.2543f * norm_storage + (0.1623f * 0.8907f + -0.0122f - 1.2543f * 0.8907f); break;
        case  3: norm_outflow = 1.0697f * norm_inflow + 0.0396f; break;
        case  4: norm_outflow = 1.0899f * norm_inflow + 0.0408f; break;
        case  5: norm_outflow = 1.0105f * norm_inflow + 0.0546f; break;
        case  6: norm_outflow = 0.9997f * norm_inflow + 0.0670f; break;
        case  7: norm_outflow = 1.0259f * norm_inflow + 0.0656f; break;
        case  8: norm_outflow = 1.0757f * norm_inflow + 0.0629f; break;
        case  9: norm_outflow = 0.9665f * norm_inflow + 0.0556f; break;
        case 10: norm_outflow = 0.8413f * norm_inflow + 0.0494f; break;
        case 11: norm_outflow = 0.9064f * norm_inflow + 0.0462f; break;
        case 12: norm_outflow = 0.9087f * norm_inflow + 0.0421f; break;
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
        case  1: norm_outflow = 0.9883f * norm_inflow + 0.0174f; break;
        case  2: norm_outflow = 1.1405f * norm_inflow + 0.0180f; break;
        case  3: norm_outflow = 1.1752f * norm_inflow + 0.0165f; break;
        case  4: norm_outflow = 1.1970f * norm_inflow + 0.0165f; break;
        case  5: norm_outflow = 1.1122f * norm_inflow + 0.0233f; break;
        case  6: norm_outflow = 1.1028f * norm_inflow + 0.0262f; break;
        case  7: norm_outflow = 1.0945f * norm_inflow + 0.0292f; break;
        case  8: norm_outflow = (norm_storage <= 0.9523f) ? 0.1213f * norm_storage + 0.0280f : 0.6195f * norm_storage + (0.1213f * 0.9523f + 0.0280f - 0.6195f * 0.9523f); break;
        case  9: norm_outflow = (norm_storage <= 0.9522f) ? 0.1205f * norm_storage + 0.0172f : 0.4413f * norm_storage + (0.1205f * 0.9522f + 0.0172f - 0.4413f * 0.9522f); break;
        case 10: norm_outflow = (norm_storage <= 0.9419f) ? 0.1157f * norm_storage + 0.0093f : 0.5336f * norm_storage + (0.1157f * 0.9419f + 0.0093f - 0.5336f * 0.9419f); break;
        case 11: norm_outflow = 1.0048f * norm_inflow + 0.0194f; break;
        case 12: norm_outflow = 0.9677f * norm_inflow + 0.0179f; break;
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
        case  1: norm_outflow = 0.4099f * norm_inflow + 0.0367f; break;
        case  2: norm_outflow = (norm_storage <= 0.8394f) ? 0.1088f * norm_storage + 0.0050f : 1.5138f * norm_storage + (0.1088f * 0.8394f + 0.0050f - 1.5138f * 0.8394f); break;
        case  3: norm_outflow = (norm_storage <= 0.8404f) ? 0.1294f * norm_storage + 0.0065f : 1.8067f * norm_storage + (0.1294f * 0.8404f + 0.0065f - 1.8067f * 0.8404f); break;
        case  4: norm_outflow = 0.4413f * norm_inflow + 0.0703f; break;
        case  5: norm_outflow = 0.4846f * norm_inflow + 0.0774f; break;
        case  6: norm_outflow = 0.5428f * norm_inflow + 0.0858f; break;
        case  7: norm_outflow = 0.5149f * norm_inflow + 0.0957f; break;
        case  8: norm_outflow = 0.4394f * norm_inflow + 0.0956f; break;
        case  9: norm_outflow = (norm_storage <= 0.9116f) ? 0.1711f * norm_storage + 0.0517f : 0.8261f * norm_storage + (0.1711f * 0.9116f + 0.0517f - 0.8261f * 0.9116f); break;
        case 10: norm_outflow = (norm_storage <= 0.8797f) ? 0.1300f * norm_storage + 0.0346f : 0.9211f * norm_storage + (0.1300f * 0.8797f + 0.0346f - 0.9211f * 0.8797f); break;
        case 11: norm_outflow = (norm_storage <= 0.9034f) ? 0.1066f * norm_storage + 0.0284f : 0.7971f * norm_storage + (0.1066f * 0.9034f + 0.0284f - 0.7971f * 0.9034f); break;
        case 12: norm_outflow = 0.4143f * norm_inflow + 0.0386f; break;
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
        case  1: norm_outflow = 1.0277f * norm_inflow + 0.0244f; break;
        case  2: norm_outflow = 0.9733f * norm_inflow + 0.0198f; break;
        case  3: norm_outflow = 0.9942f * norm_inflow + 0.0172f; break;
        case  4: norm_outflow = 1.0236f * norm_inflow + 0.0133f; break;
        case  5: norm_outflow = 1.0420f * norm_inflow + 0.0145f; break;
        case  6: norm_outflow = 1.0553f * norm_inflow + 0.0148f; break;
        case  7: norm_outflow = 1.0505f * norm_inflow + 0.0146f; break;
        case  8: norm_outflow = 1.0730f * norm_inflow + 0.0131f; break;
        case  9: norm_outflow = 1.0381f * norm_inflow + 0.0135f; break;
        case 10: norm_outflow = 1.0519f * norm_inflow + 0.0147f; break;
        case 11: norm_outflow = 0.9994f * norm_inflow + 0.0172f; break;
        case 12: norm_outflow = 0.9831f * norm_inflow + 0.0191f; break;
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
        case  1: norm_outflow = (norm_storage <= 0.9219f) ? 0.1360f * norm_storage + 0.0010f : 1.2662f * norm_storage + (0.1360f * 0.9219f + 0.0010f - 1.2662f * 0.9219f); break;
        case  2: norm_outflow = (norm_storage <= 0.8680f) ? 0.1288f * norm_storage + 0.0001f : 1.1648f * norm_storage + (0.1288f * 0.8680f + 0.0001f - 1.1648f * 0.8680f); break;
        case  3: norm_outflow = 1.0113f * norm_inflow + 0.0347f; break;
        case  4: norm_outflow = 0.9875f * norm_inflow + 0.0470f; break;
        case  5: norm_outflow = 0.9484f * norm_inflow + 0.0656f; break;
        case  6: norm_outflow = 0.9671f * norm_inflow + 0.0728f; break;
        case  7: norm_outflow = 0.9752f * norm_inflow + 0.0803f; break;
        case  8: norm_outflow = 1.0308f * norm_inflow + 0.0644f; break;
        case  9: norm_outflow = 1.0448f * norm_inflow + 0.0508f; break;
        case 10: norm_outflow = 0.7554f * norm_inflow + 0.0450f; break;
        case 11: norm_outflow = (norm_storage <= 0.9528f) ? 0.1249f * norm_storage + 0.0198f : 0.3745f * norm_storage + (0.1249f * 0.9528f + 0.0198f - 0.3745f * 0.9528f); break;
        case 12: norm_outflow = (norm_storage <= 0.9423f) ? 0.1132f * norm_storage + 0.0114f : 0.4389f * norm_storage + (0.1132f * 0.9423f + 0.0114f - 0.4389f * 0.9423f); break;
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
        case  1: norm_outflow = 0.5824f * norm_inflow + 0.0420f; break;
        case  2: norm_outflow = 0.6653f * norm_inflow + 0.0416f; break;
        case  3: norm_outflow = 0.9200f * norm_inflow + 0.0417f; break;
        case  4: norm_outflow = 0.9469f * norm_inflow + 0.0493f; break;
        case  5: norm_outflow = 0.9046f * norm_inflow + 0.0595f; break;
        case  6: norm_outflow = 0.9378f * norm_inflow + 0.0693f; break;
        case  7: norm_outflow = (norm_storage <= 0.9158f) ? 0.1743f * norm_storage + 0.0634f : 6.4172f * norm_storage + (0.1743f * 0.9158f + 0.0634f - 6.4172f * 0.9158f); break;
        case  8: norm_outflow = 0.8469f * norm_inflow + 0.0772f; break;
        case  9: norm_outflow = 0.9319f * norm_inflow + 0.0573f; break;
        case 10: norm_outflow = 0.7716f * norm_inflow + 0.0397f; break;
        case 11: norm_outflow = 0.5789f * norm_inflow + 0.0452f; break;
        case 12: norm_outflow = 0.5843f * norm_inflow + 0.0421f; break;
    }
    return norm_outflow * max_outflow_m3d;
}

static float rule_727(float inflow_m3d, float storage_m3, int month) {
    const float max_inflow_m3d   = 46981864.0f;
    const float max_outflow_m3d  = 35759186.6f;
    const float max_storage_m3   = 1245053743.0f;
    const float norm_inflow  = inflow_m3d  / max_inflow_m3d;
    const float norm_storage = storage_m3  / max_storage_m3;
    float norm_outflow;

    switch (month) {
        case  1: norm_outflow = (norm_storage <= 0.9647f) ? 0.0951f * norm_storage + 0.0079f : 0.3136f * norm_storage + (0.0951f * 0.9647f + 0.0079f - 0.3136f * 0.9647f); break;
        case  2: norm_outflow = (norm_storage <= 0.9334f) ? 0.0930f * norm_storage + 0.0082f : 0.6328f * norm_storage + (0.0930f * 0.9334f + 0.0082f - 0.6328f * 0.9334f); break;
        case  3: norm_outflow = (norm_storage <= 0.9325f) ? 0.1093f * norm_storage + 0.0127f : 0.6140f * norm_storage + (0.1093f * 0.9325f + 0.0127f - 0.6140f * 0.9325f); break;
        case  4: norm_outflow = 0.8223f * norm_inflow + 0.0484f; break;
        case  5: norm_outflow = 0.7215f * norm_inflow + 0.0629f; break;
        case  6: norm_outflow = 0.6818f * norm_inflow + 0.0777f; break;
        case  7: norm_outflow = 0.6953f * norm_inflow + 0.0860f; break;
        case  8: norm_outflow = 0.7038f * norm_inflow + 0.0859f; break;
        case  9: norm_outflow = (norm_storage <= 0.9755f) ? 0.1053f * norm_storage + 0.0344f : 0.1934f * norm_storage + (0.1053f * 0.9755f + 0.0344f - 0.1934f * 0.9755f); break;
        case 10: norm_outflow = (norm_storage <= 0.9654f) ? 0.0971f * norm_storage + 0.0219f : 0.3495f * norm_storage + (0.0971f * 0.9654f + 0.0219f - 0.3495f * 0.9654f); break;
        case 11: norm_outflow = (norm_storage <= 0.9731f) ? 0.0806f * norm_storage + 0.0185f : 0.1753f * norm_storage + (0.0806f * 0.9731f + 0.0185f - 0.1753f * 0.9731f); break;
        case 12: norm_outflow = (norm_storage <= 0.9695f) ? 0.0800f * norm_storage + 0.0125f : 0.2766f * norm_storage + (0.0800f * 0.9695f + 0.0125f - 0.2766f * 0.9695f); break;
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
        case  1: norm_outflow = 1.2046f * norm_inflow + 0.0196f; break;
        case  2: norm_outflow = 1.1943f * norm_inflow + 0.0185f; break;
        case  3: norm_outflow = 1.1279f * norm_inflow + 0.0226f; break;
        case  4: norm_outflow = (norm_storage <= 0.9969f) ? 0.7255f * norm_storage + -0.0550f : 0.0770f * norm_storage + (0.7255f * 0.9969f + -0.0550f - 0.0770f * 0.9969f); break;
        case  5: norm_outflow = 1.1097f * norm_inflow + 0.0318f; break;
        case  6: norm_outflow = (norm_storage <= 0.9910f) ? 0.6571f * norm_storage + -0.0469f : 0.1562f * norm_storage + (0.6571f * 0.9910f + -0.0469f - 0.1562f * 0.9910f); break;
        case  7: norm_outflow = (norm_storage <= 0.9967f) ? 0.7045f * norm_storage + -0.0518f : 0.0649f * norm_storage + (0.7045f * 0.9967f + -0.0518f - 0.0649f * 0.9967f); break;
        case  8: norm_outflow = (norm_storage <= 0.9966f) ? 0.8018f * norm_storage + -0.0733f : 0.0703f * norm_storage + (0.8018f * 0.9966f + -0.0733f - 0.0703f * 0.9966f); break;
        case  9: norm_outflow = 1.1482f * norm_inflow + 0.0263f; break;
        case 10: norm_outflow = 1.1448f * norm_inflow + 0.0262f; break;
        case 11: norm_outflow = 1.1824f * norm_inflow + 0.0244f; break;
        case 12: norm_outflow = 1.2109f * norm_inflow + 0.0195f; break;
    }
    return norm_outflow * max_outflow_m3d;
}

static float rule_747(float inflow_m3d, float storage_m3, int month) {
    const float max_inflow_m3d   = 356120863.1f;
    const float max_outflow_m3d  = 254443899.4f;
    const float max_storage_m3   = 2254427696.0f;
    const float norm_inflow  = inflow_m3d  / max_inflow_m3d;
    const float norm_storage = storage_m3  / max_storage_m3;
    float norm_outflow;

    switch (month) {
        case  1: norm_outflow = 0.8032f * norm_inflow + 0.0233f; break;
        case  2: norm_outflow = 0.8186f * norm_inflow + 0.0225f; break;
        case  3: norm_outflow = 0.8450f * norm_inflow + 0.0249f; break;
        case  4: norm_outflow = 0.9425f * norm_inflow + 0.0312f; break;
        case  5: norm_outflow = (norm_storage <= 0.9914f) ? 0.6222f * norm_storage + -0.0601f : 0.1391f * norm_storage + (0.6222f * 0.9914f + -0.0601f - 0.1391f * 0.9914f); break;
        case  6: norm_outflow = (norm_storage <= 0.9893f) ? 0.6351f * norm_storage + -0.0667f : 0.1976f * norm_storage + (0.6351f * 0.9893f + -0.0667f - 0.1976f * 0.9893f); break;
        case  7: norm_outflow = 1.0404f * norm_inflow + 0.0349f; break;
        case  8: norm_outflow = 1.0456f * norm_inflow + 0.0320f; break;
        case  9: norm_outflow = 1.0024f * norm_inflow + 0.0274f; break;
        case 10: norm_outflow = 0.9893f * norm_inflow + 0.0259f; break;
        case 11: norm_outflow = 0.9195f * norm_inflow + 0.0234f; break;
        case 12: norm_outflow = 0.8250f * norm_inflow + 0.0222f; break;
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
        case  1: norm_outflow = (norm_storage <= 0.9723f) ? 0.4193f * norm_storage + -0.1182f : 0.1263f * norm_storage + (0.4193f * 0.9723f + -0.1182f - 0.1263f * 0.9723f); break;
        case  2: norm_outflow = (norm_storage <= 0.9743f) ? 0.4505f * norm_storage + -0.1313f : 0.1081f * norm_storage + (0.4505f * 0.9743f + -0.1313f - 0.1081f * 0.9743f); break;
        case  3: norm_outflow = 1.1675f * norm_inflow + 0.0260f; break;
        case  4: norm_outflow = 1.1822f * norm_inflow + 0.0273f; break;
        case  5: norm_outflow = 1.1807f * norm_inflow + 0.0288f; break;
        case  6: norm_outflow = 1.1995f * norm_inflow + 0.0300f; break;
        case  7: norm_outflow = 1.2059f * norm_inflow + 0.0306f; break;
        case  8: norm_outflow = 1.1911f * norm_inflow + 0.0293f; break;
        case  9: norm_outflow = (norm_storage <= 0.9627f) ? 0.4692f * norm_storage + -0.1310f : 0.2345f * norm_storage + (0.4692f * 0.9627f + -0.1310f - 0.2345f * 0.9627f); break;
        case 10: norm_outflow = (norm_storage <= 0.9728f) ? 0.4160f * norm_storage + -0.1182f : 0.1361f * norm_storage + (0.4160f * 0.9728f + -0.1182f - 0.1361f * 0.9728f); break;
        case 11: norm_outflow = (norm_storage <= 0.9763f) ? 0.3967f * norm_storage + -0.1124f : 0.0995f * norm_storage + (0.3967f * 0.9763f + -0.1124f - 0.0995f * 0.9763f); break;
        case 12: norm_outflow = (norm_storage <= 0.9770f) ? 0.3995f * norm_storage + -0.1144f : 0.1220f * norm_storage + (0.3995f * 0.9770f + -0.1144f - 0.1220f * 0.9770f); break;
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
        case  1: norm_outflow = (norm_storage <= 1.0000f) ? 1.2637f * norm_storage + -0.0679f : 0.0035f * norm_storage + (1.2637f * 1.0000f + -0.0679f - 0.0035f * 1.0000f); break;
        case  2: norm_outflow = (norm_storage <= 0.9998f) ? 1.3079f * norm_storage + -0.0732f : 0.0061f * norm_storage + (1.3079f * 0.9998f + -0.0732f - 0.0061f * 0.9998f); break;
        case  3: norm_outflow = (norm_storage <= 0.9997f) ? 1.3040f * norm_storage + -0.0778f : 0.0073f * norm_storage + (1.3040f * 0.9997f + -0.0778f - 0.0073f * 0.9997f); break;
        case  4: norm_outflow = (norm_storage <= 0.9996f) ? 1.1229f * norm_storage + -0.0837f : 0.0104f * norm_storage + (1.1229f * 0.9996f + -0.0837f - 0.0104f * 0.9996f); break;
        case  5: norm_outflow = 1.1587f * norm_inflow + 0.0611f; break;
        case  6: norm_outflow = 1.2112f * norm_inflow + 0.0636f; break;
        case  7: norm_outflow = 1.2444f * norm_inflow + 0.0646f; break;
        case  8: norm_outflow = (norm_storage <= 0.9990f) ? 1.1912f * norm_storage + -0.1397f : 0.0172f * norm_storage + (1.1912f * 0.9990f + -0.1397f - 0.0172f * 0.9990f); break;
        case  9: norm_outflow = 1.3101f * norm_inflow + 0.0542f; break;
        case 10: norm_outflow = 1.3739f * norm_inflow + 0.0567f; break;
        case 11: norm_outflow = 1.2260f * norm_inflow + 0.0629f; break;
        case 12: norm_outflow = (norm_storage <= 0.9997f) ? 1.2525f * norm_storage + -0.0744f : 0.0039f * norm_storage + (1.2525f * 0.9997f + -0.0744f - 0.0039f * 0.9997f); break;
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
        case  1: norm_outflow = (norm_storage <= 0.8051f) ? 0.0971f * norm_storage + -0.0041f : 2.5128f * norm_storage + (0.0971f * 0.8051f + -0.0041f - 2.5128f * 0.8051f); break;
        case  2: norm_outflow = (norm_storage <= 0.7937f) ? 0.1042f * norm_storage + -0.0034f : 2.1452f * norm_storage + (0.1042f * 0.7937f + -0.0034f - 2.1452f * 0.7937f); break;
        case  3: norm_outflow = (norm_storage <= 0.7763f) ? 0.1094f * norm_storage + 0.0021f : 2.4229f * norm_storage + (0.1094f * 0.7763f + 0.0021f - 2.4229f * 0.7763f); break;
        case  4: norm_outflow = (norm_storage <= 0.8023f) ? 0.1480f * norm_storage + -0.0008f : 3.2039f * norm_storage + (0.1480f * 0.8023f + -0.0008f - 3.2039f * 0.8023f); break;
        case  5: norm_outflow = (norm_storage <= 0.8406f) ? 0.2661f * norm_storage + -0.0357f : 2.6121f * norm_storage + (0.2661f * 0.8406f + -0.0357f - 2.6121f * 0.8406f); break;
        case  6: norm_outflow = (norm_storage <= 0.8658f) ? 0.3261f * norm_storage + -0.0520f : 2.6482f * norm_storage + (0.3261f * 0.8658f + -0.0520f - 2.6482f * 0.8658f); break;
        case  7: norm_outflow = (norm_storage <= 0.8659f) ? 0.3122f * norm_storage + -0.0375f : 2.4254f * norm_storage + (0.3122f * 0.8659f + -0.0375f - 2.4254f * 0.8659f); break;
        case  8: norm_outflow = (norm_storage <= 0.8581f) ? 0.2770f * norm_storage + -0.0213f : 2.7841f * norm_storage + (0.2770f * 0.8581f + -0.0213f - 2.7841f * 0.8581f); break;
        case  9: norm_outflow = (norm_storage <= 0.8041f) ? 0.1414f * norm_storage + 0.0097f : 2.2328f * norm_storage + (0.1414f * 0.8041f + 0.0097f - 2.2328f * 0.8041f); break;
        case 10: norm_outflow = (norm_storage <= 0.7932f) ? 0.1248f * norm_storage + 0.0061f : 2.6830f * norm_storage + (0.1248f * 0.7932f + 0.0061f - 2.6830f * 0.7932f); break;
        case 11: norm_outflow = (norm_storage <= 0.7891f) ? 0.0946f * norm_storage + 0.0032f : 3.1637f * norm_storage + (0.0946f * 0.7891f + 0.0032f - 3.1637f * 0.7891f); break;
        case 12: norm_outflow = (norm_storage <= 0.7844f) ? 0.0855f * norm_storage + 0.0009f : 3.2523f * norm_storage + (0.0855f * 0.7844f + 0.0009f - 3.2523f * 0.7844f); break;
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
        case  1: norm_outflow = (norm_storage <= 0.9780f) ? 1.6604f * norm_storage + -0.5964f : 0.2709f * norm_storage + (1.6604f * 0.9780f + -0.5964f - 0.2709f * 0.9780f); break;
        case  2: norm_outflow = (norm_storage <= 0.9838f) ? 1.5867f * norm_storage + -0.5478f : 0.2246f * norm_storage + (1.5867f * 0.9838f + -0.5478f - 0.2246f * 0.9838f); break;
        case  3: norm_outflow = (norm_storage <= 0.9692f) ? 1.6764f * norm_storage + -0.6264f : 0.3872f * norm_storage + (1.6764f * 0.9692f + -0.6264f - 0.3872f * 0.9692f); break;
        case  4: norm_outflow = (norm_storage <= 0.9596f) ? 2.1721f * norm_storage + -0.9703f : 0.6237f * norm_storage + (2.1721f * 0.9596f + -0.9703f - 0.6237f * 0.9596f); break;
        case  5: norm_outflow = (norm_storage <= 0.9706f) ? 2.5635f * norm_storage + -1.2430f : 0.4813f * norm_storage + (2.5635f * 0.9706f + -1.2430f - 0.4813f * 0.9706f); break;
        case  6: norm_outflow = (norm_storage <= 0.9844f) ? 2.9571f * norm_storage + -1.5137f : 0.2516f * norm_storage + (2.9571f * 0.9844f + -1.5137f - 0.2516f * 0.9844f); break;
        case  7: norm_outflow = (norm_storage <= 0.9758f) ? 2.7130f * norm_storage + -1.3668f : 0.4142f * norm_storage + (2.7130f * 0.9758f + -1.3668f - 0.4142f * 0.9758f); break;
        case  8: norm_outflow = (norm_storage <= 0.9624f) ? 2.2878f * norm_storage + -1.0765f : 0.5932f * norm_storage + (2.2878f * 0.9624f + -1.0765f - 0.5932f * 0.9624f); break;
        case  9: norm_outflow = (norm_storage <= 0.9639f) ? 1.9176f * norm_storage + -0.8387f : 0.4835f * norm_storage + (1.9176f * 0.9639f + -0.8387f - 0.4835f * 0.9639f); break;
        case 10: norm_outflow = (norm_storage <= 0.9670f) ? 1.7707f * norm_storage + -0.7263f : 0.4871f * norm_storage + (1.7707f * 0.9670f + -0.7263f - 0.4871f * 0.9670f); break;
        case 11: norm_outflow = 1.4638f * norm_inflow + 0.0644f; break;
        case 12: norm_outflow = (norm_storage <= 0.9824f) ? 1.7013f * norm_storage + -0.6231f : 0.2312f * norm_storage + (1.7013f * 0.9824f + -0.6231f - 0.2312f * 0.9824f); break;
    }
    return norm_outflow * max_outflow_m3d;
}

static float rule_786(float inflow_m3d, float storage_m3, int month) {
    const float max_inflow_m3d   = 154488620.6f;
    const float max_outflow_m3d  = 126977300.7f;
    const float max_storage_m3   = 1306241752.0f;
    const float norm_inflow  = inflow_m3d  / max_inflow_m3d;
    const float norm_storage = storage_m3  / max_storage_m3;
    float norm_outflow;

    switch (month) {
        case  1: norm_outflow = (norm_storage <= 0.9857f) ? 0.6173f * norm_storage + -0.2302f : 0.1669f * norm_storage + (0.6173f * 0.9857f + -0.2302f - 0.1669f * 0.9857f); break;
        case  2: norm_outflow = (norm_storage <= 0.9845f) ? 0.6258f * norm_storage + -0.2344f : 0.1870f * norm_storage + (0.6258f * 0.9845f + -0.2344f - 0.1870f * 0.9845f); break;
        case  3: norm_outflow = (norm_storage <= 0.9842f) ? 0.6461f * norm_storage + -0.2396f : 0.2348f * norm_storage + (0.6461f * 0.9842f + -0.2396f - 0.2348f * 0.9842f); break;
        case  4: norm_outflow = (norm_storage <= 0.9552f) ? 0.5735f * norm_storage + -0.2336f : 1.0759f * norm_storage + (0.5735f * 0.9552f + -0.2336f - 1.0759f * 0.9552f); break;
        case  5: norm_outflow = (norm_storage <= 0.9507f) ? 0.6665f * norm_storage + -0.2899f : 1.3813f * norm_storage + (0.6665f * 0.9507f + -0.2899f - 1.3813f * 0.9507f); break;
        case  6: norm_outflow = (norm_storage <= 0.9463f) ? 0.5598f * norm_storage + -0.2228f : 1.7161f * norm_storage + (0.5598f * 0.9463f + -0.2228f - 1.7161f * 0.9463f); break;
        case  7: norm_outflow = (norm_storage <= 0.9295f) ? 0.4847f * norm_storage + -0.1878f : 1.9206f * norm_storage + (0.4847f * 0.9295f + -0.1878f - 1.9206f * 0.9295f); break;
        case  8: norm_outflow = (norm_storage <= 0.9515f) ? 0.5241f * norm_storage + -0.2024f : 1.0194f * norm_storage + (0.5241f * 0.9515f + -0.2024f - 1.0194f * 0.9515f); break;
        case  9: norm_outflow = (norm_storage <= 0.9488f) ? 0.5105f * norm_storage + -0.2002f : 0.8581f * norm_storage + (0.5105f * 0.9488f + -0.2002f - 0.8581f * 0.9488f); break;
        case 10: norm_outflow = (norm_storage <= 0.9741f) ? 0.5707f * norm_storage + -0.2111f : 0.3721f * norm_storage + (0.5707f * 0.9741f + -0.2111f - 0.3721f * 0.9741f); break;
        case 11: norm_outflow = (norm_storage <= 0.9740f) ? 0.5573f * norm_storage + -0.2023f : 0.3281f * norm_storage + (0.5573f * 0.9740f + -0.2023f - 0.3281f * 0.9740f); break;
        case 12: norm_outflow = (norm_storage <= 0.9787f) ? 0.5966f * norm_storage + -0.2202f : 0.3177f * norm_storage + (0.5966f * 0.9787f + -0.2202f - 0.3177f * 0.9787f); break;
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
        case  1: norm_outflow = (norm_storage <= 0.9951f) ? 1.6906f * norm_storage + -0.6057f : 0.0579f * norm_storage + (1.6906f * 0.9951f + -0.6057f - 0.0579f * 0.9951f); break;
        case  2: norm_outflow = (norm_storage <= 0.9942f) ? 1.5547f * norm_storage + -0.5541f : 0.0636f * norm_storage + (1.5547f * 0.9942f + -0.5541f - 0.0636f * 0.9942f); break;
        case  3: norm_outflow = (norm_storage <= 0.9948f) ? 1.6590f * norm_storage + -0.6095f : 0.0824f * norm_storage + (1.6590f * 0.9948f + -0.6095f - 0.0824f * 0.9948f); break;
        case  4: norm_outflow = (norm_storage <= 0.9951f) ? 1.7786f * norm_storage + -0.6743f : 0.0674f * norm_storage + (1.7786f * 0.9951f + -0.6743f - 0.0674f * 0.9951f); break;
        case  5: norm_outflow = (norm_storage <= 0.9952f) ? 2.0310f * norm_storage + -0.8137f : 0.0722f * norm_storage + (2.0310f * 0.9952f + -0.8137f - 0.0722f * 0.9952f); break;
        case  6: norm_outflow = (norm_storage <= 0.9959f) ? 2.6231f * norm_storage + -1.0913f : 0.0693f * norm_storage + (2.6231f * 0.9959f + -1.0913f - 0.0693f * 0.9959f); break;
        case  7: norm_outflow = (norm_storage <= 0.9961f) ? 3.0467f * norm_storage + -1.2227f : 0.0815f * norm_storage + (3.0467f * 0.9961f + -1.2227f - 0.0815f * 0.9961f); break;
        case  8: norm_outflow = 1.4734f * norm_inflow + 0.0318f; break;
        case  9: norm_outflow = (norm_storage <= 0.9953f) ? 2.4533f * norm_storage + -0.9279f : 0.0706f * norm_storage + (2.4533f * 0.9953f + -0.9279f - 0.0706f * 0.9953f); break;
        case 10: norm_outflow = 1.4806f * norm_inflow + 0.0339f; break;
        case 11: norm_outflow = 1.4674f * norm_inflow + 0.0367f; break;
        case 12: norm_outflow = (norm_storage <= 0.9964f) ? 2.1306f * norm_storage + -0.8069f : 0.0523f * norm_storage + (2.1306f * 0.9964f + -0.8069f - 0.0523f * 0.9964f); break;
    }
    return norm_outflow * max_outflow_m3d;
}

static float rule_790(float inflow_m3d, float storage_m3, int month) {
    const float max_inflow_m3d   = 119090104.8f;
    const float max_outflow_m3d  = 12235558.8f;
    const float max_storage_m3   = 1136408824.0f;
    const float norm_inflow  = inflow_m3d  / max_inflow_m3d;
    const float norm_storage = storage_m3  / max_storage_m3;
    float norm_outflow;

    switch (month) {
        case  1: norm_outflow = 3.1303f * norm_inflow + 0.0270f; break;
        case  2: norm_outflow = 2.6166f * norm_inflow + 0.0273f; break;
        case  3: norm_outflow = (norm_storage <= 0.9547f) ? 0.8444f * norm_storage + -0.1332f : 0.4898f * norm_storage + (0.8444f * 0.9547f + -0.1332f - 0.4898f * 0.9547f); break;
        case  4: norm_outflow = (norm_storage <= 0.9562f) ? 0.8413f * norm_storage + -0.1287f : 0.5696f * norm_storage + (0.8413f * 0.9562f + -0.1287f - 0.5696f * 0.9562f); break;
        case  5: norm_outflow = (norm_storage <= 0.9738f) ? 0.9428f * norm_storage + -0.1496f : 0.3248f * norm_storage + (0.9428f * 0.9738f + -0.1496f - 0.3248f * 0.9738f); break;
        case  6: norm_outflow = (norm_storage <= 0.9825f) ? 0.9855f * norm_storage + -0.1570f : 0.3443f * norm_storage + (0.9855f * 0.9825f + -0.1570f - 0.3443f * 0.9825f); break;
        case  7: norm_outflow = (norm_storage <= 0.9831f) ? 0.9678f * norm_storage + -0.1585f : 0.2350f * norm_storage + (0.9678f * 0.9831f + -0.1585f - 0.2350f * 0.9831f); break;
        case  8: norm_outflow = (norm_storage <= 0.9804f) ? 0.9661f * norm_storage + -0.1582f : 0.2642f * norm_storage + (0.9661f * 0.9804f + -0.1582f - 0.2642f * 0.9804f); break;
        case  9: norm_outflow = (norm_storage <= 0.9864f) ? 0.9930f * norm_storage + -0.1582f : 0.1345f * norm_storage + (0.9930f * 0.9864f + -0.1582f - 0.1345f * 0.9864f); break;
        case 10: norm_outflow = (norm_storage <= 0.9824f) ? 1.0072f * norm_storage + -0.1581f : 0.1836f * norm_storage + (1.0072f * 0.9824f + -0.1581f - 0.1836f * 0.9824f); break;
        case 11: norm_outflow = (norm_storage <= 0.9819f) ? 0.9482f * norm_storage + -0.1549f : 0.1264f * norm_storage + (0.9482f * 0.9819f + -0.1549f - 0.1264f * 0.9819f); break;
        case 12: norm_outflow = (norm_storage <= 0.9794f) ? 0.9439f * norm_storage + -0.1490f : 0.1647f * norm_storage + (0.9439f * 0.9794f + -0.1490f - 0.1647f * 0.9794f); break;
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
        case  1: norm_outflow = (norm_storage <= 0.9985f) ? 1.4136f * norm_storage + -0.3696f : 0.0227f * norm_storage + (1.4136f * 0.9985f + -0.3696f - 0.0227f * 0.9985f); break;
        case  2: norm_outflow = (norm_storage <= 0.9987f) ? 1.5390f * norm_storage + -0.4011f : 0.0135f * norm_storage + (1.5390f * 0.9987f + -0.4011f - 0.0135f * 0.9987f); break;
        case  3: norm_outflow = (norm_storage <= 0.9993f) ? 1.6377f * norm_storage + -0.4409f : 0.0124f * norm_storage + (1.6377f * 0.9993f + -0.4409f - 0.0124f * 0.9993f); break;
        case  4: norm_outflow = (norm_storage <= 0.9968f) ? 1.4555f * norm_storage + -0.3958f : 0.0649f * norm_storage + (1.4555f * 0.9968f + -0.3958f - 0.0649f * 0.9968f); break;
        case  5: norm_outflow = (norm_storage <= 0.9965f) ? 1.2844f * norm_storage + -0.3523f : 0.0671f * norm_storage + (1.2844f * 0.9965f + -0.3523f - 0.0671f * 0.9965f); break;
        case  6: norm_outflow = (norm_storage <= 0.9931f) ? 1.1414f * norm_storage + -0.3190f : 0.1697f * norm_storage + (1.1414f * 0.9931f + -0.3190f - 0.1697f * 0.9931f); break;
        case  7: norm_outflow = (norm_storage <= 0.9931f) ? 1.1201f * norm_storage + -0.3098f : 0.1289f * norm_storage + (1.1201f * 0.9931f + -0.3098f - 0.1289f * 0.9931f); break;
        case  8: norm_outflow = (norm_storage <= 0.9970f) ? 1.1400f * norm_storage + -0.3167f : 0.0285f * norm_storage + (1.1400f * 0.9970f + -0.3167f - 0.0285f * 0.9970f); break;
        case  9: norm_outflow = (norm_storage <= 0.9958f) ? 1.1322f * norm_storage + -0.3055f : 0.0379f * norm_storage + (1.1322f * 0.9958f + -0.3055f - 0.0379f * 0.9958f); break;
        case 10: norm_outflow = (norm_storage <= 0.9964f) ? 0.9993f * norm_storage + -0.2634f : 0.0285f * norm_storage + (0.9993f * 0.9964f + -0.2634f - 0.0285f * 0.9964f); break;
        case 11: norm_outflow = (norm_storage <= 0.9970f) ? 1.0233f * norm_storage + -0.2663f : 0.0248f * norm_storage + (1.0233f * 0.9970f + -0.2663f - 0.0248f * 0.9970f); break;
        case 12: norm_outflow = (norm_storage <= 0.9984f) ? 1.2474f * norm_storage + -0.3261f : 0.0191f * norm_storage + (1.2474f * 0.9984f + -0.3261f - 0.0191f * 0.9984f); break;
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
        case  1: norm_outflow = (norm_storage <= 0.7654f) ? 0.0924f * norm_storage + -0.0006f : 8.6118f * norm_storage + (0.0924f * 0.7654f + -0.0006f - 8.6118f * 0.7654f); break;
        case  2: norm_outflow = (norm_storage <= 0.7476f) ? 0.0965f * norm_storage + -0.0106f : 8.4307f * norm_storage + (0.0965f * 0.7476f + -0.0106f - 8.4307f * 0.7476f); break;
        case  3: norm_outflow = (norm_storage <= 0.7482f) ? 0.0965f * norm_storage + -0.0089f : 8.3318f * norm_storage + (0.0965f * 0.7482f + -0.0089f - 8.3318f * 0.7482f); break;
        case  4: norm_outflow = (norm_storage <= 0.7614f) ? 0.1232f * norm_storage + -0.0209f : 7.2500f * norm_storage + (0.1232f * 0.7614f + -0.0209f - 7.2500f * 0.7614f); break;
        case  5: norm_outflow = (norm_storage <= 0.8002f) ? 0.1543f * norm_storage + -0.0233f : 14.6074f * norm_storage + (0.1543f * 0.8002f + -0.0233f - 14.6074f * 0.8002f); break;
        case  6: norm_outflow = (norm_storage <= 0.7988f) ? 0.1473f * norm_storage + -0.0059f : 5.3535f * norm_storage + (0.1473f * 0.7988f + -0.0059f - 5.3535f * 0.7988f); break;
        case  7: norm_outflow = (norm_storage <= 0.8147f) ? 0.1726f * norm_storage + -0.0265f : 22.9279f * norm_storage + (0.1726f * 0.8147f + -0.0265f - 22.9279f * 0.8147f); break;
        case  8: norm_outflow = (norm_storage <= 0.8188f) ? 0.1563f * norm_storage + -0.0138f : 3.2145f * norm_storage + (0.1563f * 0.8188f + -0.0138f - 3.2145f * 0.8188f); break;
        case  9: norm_outflow = (norm_storage <= 0.8259f) ? 0.1365f * norm_storage + -0.0034f : 2.7493f * norm_storage + (0.1365f * 0.8259f + -0.0034f - 2.7493f * 0.8259f); break;
        case 10: norm_outflow = (norm_storage <= 0.8201f) ? 0.1363f * norm_storage + -0.0040f : 2.7725f * norm_storage + (0.1363f * 0.8201f + -0.0040f - 2.7725f * 0.8201f); break;
        case 11: norm_outflow = (norm_storage <= 0.7955f) ? 0.1087f * norm_storage + 0.0063f : 3.8795f * norm_storage + (0.1087f * 0.7955f + 0.0063f - 3.8795f * 0.7955f); break;
        case 12: norm_outflow = (norm_storage <= 0.7806f) ? 0.1004f * norm_storage + 0.0083f : 5.2445f * norm_storage + (0.1004f * 0.7806f + 0.0083f - 5.2445f * 0.7806f); break;
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
        case  1: norm_outflow = 0.5492f * norm_inflow + 0.0186f; break;
        case  2: norm_outflow = 0.5462f * norm_inflow + 0.0180f; break;
        case  3: norm_outflow = (norm_storage <= 0.8303f) ? 0.3323f * norm_storage + -0.1154f : 0.6663f * norm_storage + (0.3323f * 0.8303f + -0.1154f - 0.6663f * 0.8303f); break;
        case  4: norm_outflow = 0.6537f * norm_inflow + 0.0227f; break;
        case  5: norm_outflow = (norm_storage <= 0.8223f) ? 0.3816f * norm_storage + -0.1397f : 0.8583f * norm_storage + (0.3816f * 0.8223f + -0.1397f - 0.8583f * 0.8223f); break;
        case  6: norm_outflow = (norm_storage <= 0.8244f) ? 0.4324f * norm_storage + -0.1630f : 1.0843f * norm_storage + (0.4324f * 0.8244f + -0.1630f - 1.0843f * 0.8244f); break;
        case  7: norm_outflow = (norm_storage <= 0.8086f) ? 0.3505f * norm_storage + -0.1250f : 1.1717f * norm_storage + (0.3505f * 0.8086f + -0.1250f - 1.1717f * 0.8086f); break;
        case  8: norm_outflow = 0.6838f * norm_inflow + 0.0230f; break;
        case  9: norm_outflow = 0.6378f * norm_inflow + 0.0242f; break;
        case 10: norm_outflow = (norm_storage <= 0.8040f) ? 0.2801f * norm_storage + -0.0852f : 0.9525f * norm_storage + (0.2801f * 0.8040f + -0.0852f - 0.9525f * 0.8040f); break;
        case 11: norm_outflow = (norm_storage <= 0.8219f) ? 0.2911f * norm_storage + -0.0955f : 0.7395f * norm_storage + (0.2911f * 0.8219f + -0.0955f - 0.7395f * 0.8219f); break;
        case 12: norm_outflow = 0.5781f * norm_inflow + 0.0178f; break;
    }
    return norm_outflow * max_outflow_m3d;
}

static float rule_800(float inflow_m3d, float storage_m3, int month) {
    const float max_inflow_m3d   = 250605715.3f;
    const float max_outflow_m3d  = 145571337.9f;
    const float max_storage_m3   = 2896058088.0f;
    const float norm_inflow  = inflow_m3d  / max_inflow_m3d;
    const float norm_storage = storage_m3  / max_storage_m3;
    float norm_outflow;

    switch (month) {
        case  1: norm_outflow = 0.9605f * norm_inflow + 0.0290f; break;
        case  2: norm_outflow = 0.8778f * norm_inflow + 0.0277f; break;
        case  3: norm_outflow = (norm_storage <= 0.9908f) ? 0.5218f * norm_storage + -0.0559f : 0.1605f * norm_storage + (0.5218f * 0.9908f + -0.0559f - 0.1605f * 0.9908f); break;
        case  4: norm_outflow = (norm_storage <= 0.9907f) ? 0.5797f * norm_storage + -0.0751f : 0.1958f * norm_storage + (0.5797f * 0.9907f + -0.0751f - 0.1958f * 0.9907f); break;
        case  5: norm_outflow = (norm_storage <= 0.9870f) ? 0.6029f * norm_storage + -0.0812f : 0.3661f * norm_storage + (0.6029f * 0.9870f + -0.0812f - 0.3661f * 0.9870f); break;
        case  6: norm_outflow = (norm_storage <= 0.9847f) ? 0.6258f * norm_storage + -0.0886f : 0.4116f * norm_storage + (0.6258f * 0.9847f + -0.0886f - 0.4116f * 0.9847f); break;
        case  7: norm_outflow = (norm_storage <= 0.9839f) ? 0.6364f * norm_storage + -0.0973f : 0.2139f * norm_storage + (0.6364f * 0.9839f + -0.0973f - 0.2139f * 0.9839f); break;
        case  8: norm_outflow = (norm_storage <= 0.9853f) ? 0.6146f * norm_storage + -0.0895f : 0.2031f * norm_storage + (0.6146f * 0.9853f + -0.0895f - 0.2031f * 0.9853f); break;
        case  9: norm_outflow = (norm_storage <= 0.9889f) ? 0.5692f * norm_storage + -0.0774f : 0.1645f * norm_storage + (0.5692f * 0.9889f + -0.0774f - 0.1645f * 0.9889f); break;
        case 10: norm_outflow = (norm_storage <= 0.9861f) ? 0.5560f * norm_storage + -0.0789f : 0.1557f * norm_storage + (0.5560f * 0.9861f + -0.0789f - 0.1557f * 0.9861f); break;
        case 11: norm_outflow = (norm_storage <= 0.9874f) ? 0.5328f * norm_storage + -0.0722f : 0.1183f * norm_storage + (0.5328f * 0.9874f + -0.0722f - 0.1183f * 0.9874f); break;
        case 12: norm_outflow = (norm_storage <= 0.9881f) ? 0.5277f * norm_storage + -0.0655f : 0.1928f * norm_storage + (0.5277f * 0.9881f + -0.0655f - 0.1928f * 0.9881f); break;
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
        case  1: norm_outflow = (norm_storage <= 0.9964f) ? 0.8143f * norm_storage + -0.1739f : 0.0629f * norm_storage + (0.8143f * 0.9964f + -0.1739f - 0.0629f * 0.9964f); break;
        case  2: norm_outflow = (norm_storage <= 0.9970f) ? 0.8390f * norm_storage + -0.1822f : 0.0343f * norm_storage + (0.8390f * 0.9970f + -0.1822f - 0.0343f * 0.9970f); break;
        case  3: norm_outflow = (norm_storage <= 0.9978f) ? 0.9536f * norm_storage + -0.2167f : 0.0192f * norm_storage + (0.9536f * 0.9978f + -0.2167f - 0.0192f * 0.9978f); break;
        case  4: norm_outflow = (norm_storage <= 0.9970f) ? 0.9609f * norm_storage + -0.2211f : 0.0620f * norm_storage + (0.9609f * 0.9970f + -0.2211f - 0.0620f * 0.9970f); break;
        case  5: norm_outflow = (norm_storage <= 0.9962f) ? 0.9367f * norm_storage + -0.2215f : 0.0651f * norm_storage + (0.9367f * 0.9962f + -0.2215f - 0.0651f * 0.9962f); break;
        case  6: norm_outflow = (norm_storage <= 0.9971f) ? 0.9261f * norm_storage + -0.2166f : 0.0888f * norm_storage + (0.9261f * 0.9971f + -0.2166f - 0.0888f * 0.9971f); break;
        case  7: norm_outflow = (norm_storage <= 0.9984f) ? 0.9199f * norm_storage + -0.2126f : 0.0346f * norm_storage + (0.9199f * 0.9984f + -0.2126f - 0.0346f * 0.9984f); break;
        case  8: norm_outflow = (norm_storage <= 0.9989f) ? 0.9307f * norm_storage + -0.2152f : 0.0381f * norm_storage + (0.9307f * 0.9989f + -0.2152f - 0.0381f * 0.9989f); break;
        case  9: norm_outflow = (norm_storage <= 0.9976f) ? 0.9354f * norm_storage + -0.2190f : 0.0293f * norm_storage + (0.9354f * 0.9976f + -0.2190f - 0.0293f * 0.9976f); break;
        case 10: norm_outflow = (norm_storage <= 0.9975f) ? 0.9127f * norm_storage + -0.2140f : 0.0325f * norm_storage + (0.9127f * 0.9975f + -0.2140f - 0.0325f * 0.9975f); break;
        case 11: norm_outflow = (norm_storage <= 0.9972f) ? 0.8663f * norm_storage + -0.1914f : 0.0250f * norm_storage + (0.8663f * 0.9972f + -0.1914f - 0.0250f * 0.9972f); break;
        case 12: norm_outflow = (norm_storage <= 0.9974f) ? 0.8292f * norm_storage + -0.1783f : 0.0322f * norm_storage + (0.8292f * 0.9974f + -0.1783f - 0.0322f * 0.9974f); break;
    }
    return norm_outflow * max_outflow_m3d;
}

static float rule_803(float inflow_m3d, float storage_m3, int month) {
    const float max_inflow_m3d   = 111895269.0f;
    const float max_outflow_m3d  = 81470962.2f;
    const float max_storage_m3   = 1660618089.0f;
    const float norm_inflow  = inflow_m3d  / max_inflow_m3d;
    const float norm_storage = storage_m3  / max_storage_m3;
    float norm_outflow;

    switch (month) {
        case  1: norm_outflow = 0.7720f * norm_inflow + 0.0298f; break;
        case  2: norm_outflow = 0.7100f * norm_inflow + 0.0277f; break;
        case  3: norm_outflow = (norm_storage <= 0.9859f) ? 0.5566f * norm_storage + -0.0969f : 0.2331f * norm_storage + (0.5566f * 0.9859f + -0.0969f - 0.2331f * 0.9859f); break;
        case  4: norm_outflow = (norm_storage <= 0.9882f) ? 0.6280f * norm_storage + -0.1244f : 0.2021f * norm_storage + (0.6280f * 0.9882f + -0.1244f - 0.2021f * 0.9882f); break;
        case  5: norm_outflow = (norm_storage <= 0.9890f) ? 0.7145f * norm_storage + -0.1619f : 0.2398f * norm_storage + (0.7145f * 0.9890f + -0.1619f - 0.2398f * 0.9890f); break;
        case  6: norm_outflow = (norm_storage <= 0.9924f) ? 0.8208f * norm_storage + -0.2056f : 0.1541f * norm_storage + (0.8208f * 0.9924f + -0.2056f - 0.1541f * 0.9924f); break;
        case  7: norm_outflow = (norm_storage <= 0.9879f) ? 0.8095f * norm_storage + -0.1987f : 0.2092f * norm_storage + (0.8095f * 0.9879f + -0.1987f - 0.2092f * 0.9879f); break;
        case  8: norm_outflow = (norm_storage <= 0.9912f) ? 0.8286f * norm_storage + -0.2111f : 0.1647f * norm_storage + (0.8286f * 0.9912f + -0.2111f - 0.1647f * 0.9912f); break;
        case  9: norm_outflow = 0.8289f * norm_inflow + 0.0298f; break;
        case 10: norm_outflow = 0.8149f * norm_inflow + 0.0280f; break;
        case 11: norm_outflow = (norm_storage <= 0.9868f) ? 0.6462f * norm_storage + -0.1406f : 0.1555f * norm_storage + (0.6462f * 0.9868f + -0.1406f - 0.1555f * 0.9868f); break;
        case 12: norm_outflow = 0.7159f * norm_inflow + 0.0286f; break;
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
        case  1: norm_outflow = 1.0312f * norm_inflow + 0.0212f; break;
        case  2: norm_outflow = 1.0378f * norm_inflow + 0.0212f; break;
        case  3: norm_outflow = (norm_storage <= 0.9914f) ? 0.6861f * norm_storage + -0.2293f : 0.0388f * norm_storage + (0.6861f * 0.9914f + -0.2293f - 0.0388f * 0.9914f); break;
        case  4: norm_outflow = (norm_storage <= 0.9879f) ? 0.6821f * norm_storage + -0.2228f : 0.1061f * norm_storage + (0.6821f * 0.9879f + -0.2228f - 0.1061f * 0.9879f); break;
        case  5: norm_outflow = (norm_storage <= 0.9830f) ? 0.7024f * norm_storage + -0.2203f : 0.1317f * norm_storage + (0.7024f * 0.9830f + -0.2203f - 0.1317f * 0.9830f); break;
        case  6: norm_outflow = (norm_storage <= 0.9758f) ? 0.7096f * norm_storage + -0.2209f : 0.3091f * norm_storage + (0.7096f * 0.9758f + -0.2209f - 0.3091f * 0.9758f); break;
        case  7: norm_outflow = (norm_storage <= 0.9850f) ? 0.6709f * norm_storage + -0.2087f : 0.1006f * norm_storage + (0.6709f * 0.9850f + -0.2087f - 0.1006f * 0.9850f); break;
        case  8: norm_outflow = (norm_storage <= 0.9858f) ? 0.6691f * norm_storage + -0.2068f : 0.1228f * norm_storage + (0.6691f * 0.9858f + -0.2068f - 0.1228f * 0.9858f); break;
        case  9: norm_outflow = (norm_storage <= 0.9878f) ? 0.6547f * norm_storage + -0.2071f : 0.0928f * norm_storage + (0.6547f * 0.9878f + -0.2071f - 0.0928f * 0.9878f); break;
        case 10: norm_outflow = (norm_storage <= 0.9882f) ? 0.6277f * norm_storage + -0.1998f : 0.0914f * norm_storage + (0.6277f * 0.9882f + -0.1998f - 0.0914f * 0.9882f); break;
        case 11: norm_outflow = (norm_storage <= 0.9925f) ? 0.6090f * norm_storage + -0.2020f : 0.0339f * norm_storage + (0.6090f * 0.9925f + -0.2020f - 0.0339f * 0.9925f); break;
        case 12: norm_outflow = (norm_storage <= 0.9900f) ? 0.5998f * norm_storage + -0.2009f : 0.1022f * norm_storage + (0.5998f * 0.9900f + -0.2009f - 0.1022f * 0.9900f); break;
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
        case  1: norm_outflow = 0.5196f * norm_inflow + 0.0357f; break;
        case  2: norm_outflow = 0.5128f * norm_inflow + 0.0360f; break;
        case  3: norm_outflow = 0.4966f * norm_inflow + 0.0400f; break;
        case  4: norm_outflow = 0.5559f * norm_inflow + 0.0469f; break;
        case  5: norm_outflow = 0.6772f * norm_inflow + 0.0497f; break;
        case  6: norm_outflow = 0.7278f * norm_inflow + 0.0518f; break;
        case  7: norm_outflow = 0.8013f * norm_inflow + 0.0533f; break;
        case  8: norm_outflow = 0.6636f * norm_inflow + 0.0601f; break;
        case  9: norm_outflow = 0.5055f * norm_inflow + 0.0520f; break;
        case 10: norm_outflow = 0.4853f * norm_inflow + 0.0442f; break;
        case 11: norm_outflow = 0.5227f * norm_inflow + 0.0388f; break;
        case 12: norm_outflow = 0.5348f * norm_inflow + 0.0375f; break;
    }
    return norm_outflow * max_outflow_m3d;
}

static float rule_811(float inflow_m3d, float storage_m3, int month) {
    const float max_inflow_m3d   = 62817952.0f;
    const float max_outflow_m3d  = 7608837.3f;
    const float max_storage_m3   = 250601197.7f;
    const float norm_inflow  = inflow_m3d  / max_inflow_m3d;
    const float norm_storage = storage_m3  / max_storage_m3;
    float norm_outflow;

    switch (month) {
        case  1: norm_outflow = (norm_storage <= 0.9937f) ? 0.9495f * norm_storage + -0.2032f : 0.0503f * norm_storage + (0.9495f * 0.9937f + -0.2032f - 0.0503f * 0.9937f); break;
        case  2: norm_outflow = (norm_storage <= 0.9939f) ? 0.9803f * norm_storage + -0.2136f : 0.0490f * norm_storage + (0.9803f * 0.9939f + -0.2136f - 0.0490f * 0.9939f); break;
        case  3: norm_outflow = (norm_storage <= 0.9947f) ? 1.0370f * norm_storage + -0.2374f : 0.0332f * norm_storage + (1.0370f * 0.9947f + -0.2374f - 0.0332f * 0.9947f); break;
        case  4: norm_outflow = (norm_storage <= 0.9919f) ? 0.9788f * norm_storage + -0.2400f : 0.0807f * norm_storage + (0.9788f * 0.9919f + -0.2400f - 0.0807f * 0.9919f); break;
        case  5: norm_outflow = (norm_storage <= 0.9877f) ? 0.9687f * norm_storage + -0.2440f : 0.0891f * norm_storage + (0.9687f * 0.9877f + -0.2440f - 0.0891f * 0.9877f); break;
        case  6: norm_outflow = (norm_storage <= 0.9896f) ? 0.9924f * norm_storage + -0.2528f : 0.0954f * norm_storage + (0.9924f * 0.9896f + -0.2528f - 0.0954f * 0.9896f); break;
        case  7: norm_outflow = (norm_storage <= 0.9958f) ? 0.9789f * norm_storage + -0.2481f : 0.0354f * norm_storage + (0.9789f * 0.9958f + -0.2481f - 0.0354f * 0.9958f); break;
        case  8: norm_outflow = (norm_storage <= 0.9961f) ? 0.9847f * norm_storage + -0.2523f : 0.0578f * norm_storage + (0.9847f * 0.9961f + -0.2523f - 0.0578f * 0.9961f); break;
        case  9: norm_outflow = (norm_storage <= 0.9953f) ? 0.9472f * norm_storage + -0.2281f : 0.0432f * norm_storage + (0.9472f * 0.9953f + -0.2281f - 0.0432f * 0.9953f); break;
        case 10: norm_outflow = (norm_storage <= 0.9937f) ? 0.9299f * norm_storage + -0.2188f : 0.0637f * norm_storage + (0.9299f * 0.9937f + -0.2188f - 0.0637f * 0.9937f); break;
        case 11: norm_outflow = (norm_storage <= 0.9933f) ? 0.9859f * norm_storage + -0.2243f : 0.0534f * norm_storage + (0.9859f * 0.9933f + -0.2243f - 0.0534f * 0.9933f); break;
        case 12: norm_outflow = (norm_storage <= 0.9927f) ? 0.9938f * norm_storage + -0.2159f : 0.0666f * norm_storage + (0.9938f * 0.9927f + -0.2159f - 0.0666f * 0.9927f); break;
    }
    return norm_outflow * max_outflow_m3d;
}

static float rule_813(float inflow_m3d, float storage_m3, int month) {
    const float max_inflow_m3d   = 71707821.5f;
    const float max_outflow_m3d  = 16440969.2f;
    const float max_storage_m3   = 477813024.3f;
    const float norm_inflow  = inflow_m3d  / max_inflow_m3d;
    const float norm_storage = storage_m3  / max_storage_m3;
    float norm_outflow;

    switch (month) {
        case  1: norm_outflow = 1.7678f * norm_inflow + 0.0236f; break;
        case  2: norm_outflow = 1.6010f * norm_inflow + 0.0219f; break;
        case  3: norm_outflow = 1.4894f * norm_inflow + 0.0235f; break;
        case  4: norm_outflow = (norm_storage <= 0.9319f) ? 0.6662f * norm_storage + -0.0859f : 1.0290f * norm_storage + (0.6662f * 0.9319f + -0.0859f - 1.0290f * 0.9319f); break;
        case  5: norm_outflow = (norm_storage <= 0.9568f) ? 0.8439f * norm_storage + -0.1350f : 0.7451f * norm_storage + (0.8439f * 0.9568f + -0.1350f - 0.7451f * 0.9568f); break;
        case  6: norm_outflow = (norm_storage <= 0.9641f) ? 0.8527f * norm_storage + -0.1214f : 0.8685f * norm_storage + (0.8527f * 0.9641f + -0.1214f - 0.8685f * 0.9641f); break;
        case  7: norm_outflow = (norm_storage <= 0.9645f) ? 0.8408f * norm_storage + -0.1184f : 0.6358f * norm_storage + (0.8408f * 0.9645f + -0.1184f - 0.6358f * 0.9645f); break;
        case  8: norm_outflow = (norm_storage <= 0.9597f) ? 0.7918f * norm_storage + -0.1059f : 0.8313f * norm_storage + (0.7918f * 0.9597f + -0.1059f - 0.8313f * 0.9597f); break;
        case  9: norm_outflow = (norm_storage <= 0.9579f) ? 0.7200f * norm_storage + -0.0900f : 0.5645f * norm_storage + (0.7200f * 0.9579f + -0.0900f - 0.5645f * 0.9579f); break;
        case 10: norm_outflow = 1.5753f * norm_inflow + 0.0259f; break;
        case 11: norm_outflow = (norm_storage <= 0.9463f) ? 0.5864f * norm_storage + -0.0725f : 0.4757f * norm_storage + (0.5864f * 0.9463f + -0.0725f - 0.4757f * 0.9463f); break;
        case 12: norm_outflow = 1.7123f * norm_inflow + 0.0245f; break;
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
        case  1: norm_outflow = (norm_storage <= 0.9913f) ? 1.1107f * norm_storage + -0.4327f : 0.1491f * norm_storage + (1.1107f * 0.9913f + -0.4327f - 0.1491f * 0.9913f); break;
        case  2: norm_outflow = (norm_storage <= 0.9909f) ? 1.1319f * norm_storage + -0.4434f : 0.0974f * norm_storage + (1.1319f * 0.9909f + -0.4434f - 0.0974f * 0.9909f); break;
        case  3: norm_outflow = (norm_storage <= 0.9935f) ? 1.1938f * norm_storage + -0.4611f : 0.0689f * norm_storage + (1.1938f * 0.9935f + -0.4611f - 0.0689f * 0.9935f); break;
        case  4: norm_outflow = (norm_storage <= 0.9885f) ? 1.1784f * norm_storage + -0.4604f : 0.1417f * norm_storage + (1.1784f * 0.9885f + -0.4604f - 0.1417f * 0.9885f); break;
        case  5: norm_outflow = (norm_storage <= 0.9804f) ? 1.1524f * norm_storage + -0.4430f : 0.2125f * norm_storage + (1.1524f * 0.9804f + -0.4430f - 0.2125f * 0.9804f); break;
        case  6: norm_outflow = (norm_storage <= 0.9767f) ? 1.1632f * norm_storage + -0.4354f : 0.4268f * norm_storage + (1.1632f * 0.9767f + -0.4354f - 0.4268f * 0.9767f); break;
        case  7: norm_outflow = (norm_storage <= 0.9876f) ? 1.1850f * norm_storage + -0.4525f : 0.1059f * norm_storage + (1.1850f * 0.9876f + -0.4525f - 0.1059f * 0.9876f); break;
        case  8: norm_outflow = (norm_storage <= 0.9898f) ? 1.1453f * norm_storage + -0.4413f : 0.2108f * norm_storage + (1.1453f * 0.9898f + -0.4413f - 0.2108f * 0.9898f); break;
        case  9: norm_outflow = (norm_storage <= 0.9898f) ? 1.1398f * norm_storage + -0.4391f : 0.1446f * norm_storage + (1.1398f * 0.9898f + -0.4391f - 0.1446f * 0.9898f); break;
        case 10: norm_outflow = (norm_storage <= 0.9919f) ? 1.1079f * norm_storage + -0.4269f : 0.1141f * norm_storage + (1.1079f * 0.9919f + -0.4269f - 0.1141f * 0.9919f); break;
        case 11: norm_outflow = (norm_storage <= 0.9934f) ? 1.1244f * norm_storage + -0.4341f : 0.0683f * norm_storage + (1.1244f * 0.9934f + -0.4341f - 0.0683f * 0.9934f); break;
        case 12: norm_outflow = (norm_storage <= 0.9912f) ? 1.1032f * norm_storage + -0.4278f : 0.1751f * norm_storage + (1.1032f * 0.9912f + -0.4278f - 0.1751f * 0.9912f); break;
    }
    return norm_outflow * max_outflow_m3d;
}

static float rule_818(float inflow_m3d, float storage_m3, int month) {
    const float max_inflow_m3d   = 37751847.9f;
    const float max_outflow_m3d  = 9786302.2f;
    const float max_storage_m3   = 177854247.7f;
    const float norm_inflow  = inflow_m3d  / max_inflow_m3d;
    const float norm_storage = storage_m3  / max_storage_m3;
    float norm_outflow;

    switch (month) {
        case  1: norm_outflow = (norm_storage <= 0.7034f) ? 0.1122f * norm_storage + -0.0373f : 2.4659f * norm_storage + (0.1122f * 0.7034f + -0.0373f - 2.4659f * 0.7034f); break;
        case  2: norm_outflow = (norm_storage <= 0.7009f) ? 0.1276f * norm_storage + -0.0433f : 2.5228f * norm_storage + (0.1276f * 0.7009f + -0.0433f - 2.5228f * 0.7009f); break;
        case  3: norm_outflow = (norm_storage <= 0.6975f) ? 0.1146f * norm_storage + -0.0398f : 2.5457f * norm_storage + (0.1146f * 0.6975f + -0.0398f - 2.5457f * 0.6975f); break;
        case  4: norm_outflow = (norm_storage <= 0.7078f) ? 0.1437f * norm_storage + -0.0588f : 2.3899f * norm_storage + (0.1437f * 0.7078f + -0.0588f - 2.3899f * 0.7078f); break;
        case  5: norm_outflow = (norm_storage <= 0.7828f) ? 0.3380f * norm_storage + -0.1606f : 1.5801f * norm_storage + (0.3380f * 0.7828f + -0.1606f - 1.5801f * 0.7828f); break;
        case  6: norm_outflow = (norm_storage <= 0.7814f) ? 0.3357f * norm_storage + -0.1634f : 1.6568f * norm_storage + (0.3357f * 0.7814f + -0.1634f - 1.6568f * 0.7814f); break;
        case  7: norm_outflow = (norm_storage <= 0.7433f) ? 0.2524f * norm_storage + -0.1238f : 1.5407f * norm_storage + (0.2524f * 0.7433f + -0.1238f - 1.5407f * 0.7433f); break;
        case  8: norm_outflow = (norm_storage <= 0.7288f) ? 0.1873f * norm_storage + -0.0817f : 1.9373f * norm_storage + (0.1873f * 0.7288f + -0.0817f - 1.9373f * 0.7288f); break;
        case  9: norm_outflow = (norm_storage <= 0.7025f) ? 0.1297f * norm_storage + -0.0469f : 2.3241f * norm_storage + (0.1297f * 0.7025f + -0.0469f - 2.3241f * 0.7025f); break;
        case 10: norm_outflow = (norm_storage <= 0.7010f) ? 0.1298f * norm_storage + -0.0426f : 2.2774f * norm_storage + (0.1298f * 0.7010f + -0.0426f - 2.2774f * 0.7010f); break;
        case 11: norm_outflow = (norm_storage <= 0.6955f) ? 0.1102f * norm_storage + -0.0354f : 2.2344f * norm_storage + (0.1102f * 0.6955f + -0.0354f - 2.2344f * 0.6955f); break;
        case 12: norm_outflow = (norm_storage <= 0.7015f) ? 0.1213f * norm_storage + -0.0417f : 2.3556f * norm_storage + (0.1213f * 0.7015f + -0.0417f - 2.3556f * 0.7015f); break;
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
        case  1: norm_outflow = 0.4940f * norm_inflow + 0.0287f; break;
        case  2: norm_outflow = 0.5596f * norm_inflow + 0.0312f; break;
        case  3: norm_outflow = 0.7240f * norm_inflow + 0.0397f; break;
        case  4: norm_outflow = 0.8086f * norm_inflow + 0.0472f; break;
        case  5: norm_outflow = 0.8052f * norm_inflow + 0.0547f; break;
        case  6: norm_outflow = 0.8399f * norm_inflow + 0.0626f; break;
        case  7: norm_outflow = 0.8443f * norm_inflow + 0.0574f; break;
        case  8: norm_outflow = 0.8076f * norm_inflow + 0.0533f; break;
        case  9: norm_outflow = 0.8075f * norm_inflow + 0.0503f; break;
        case 10: norm_outflow = 0.6581f * norm_inflow + 0.0342f; break;
        case 11: norm_outflow = 0.5360f * norm_inflow + 0.0310f; break;
        case 12: norm_outflow = 0.5022f * norm_inflow + 0.0305f; break;
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
        case  1: norm_outflow = (norm_storage <= 0.9975f) ? 0.9187f * norm_storage + -0.0796f : 0.0249f * norm_storage + (0.9187f * 0.9975f + -0.0796f - 0.0249f * 0.9975f); break;
        case  2: norm_outflow = (norm_storage <= 0.9973f) ? 0.9483f * norm_storage + -0.0846f : 0.0213f * norm_storage + (0.9483f * 0.9973f + -0.0846f - 0.0213f * 0.9973f); break;
        case  3: norm_outflow = (norm_storage <= 0.9972f) ? 1.0100f * norm_storage + -0.0937f : 0.0217f * norm_storage + (1.0100f * 0.9972f + -0.0937f - 0.0217f * 0.9972f); break;
        case  4: norm_outflow = (norm_storage <= 0.9947f) ? 0.9426f * norm_storage + -0.0837f : 0.0717f * norm_storage + (0.9426f * 0.9947f + -0.0837f - 0.0717f * 0.9947f); break;
        case  5: norm_outflow = (norm_storage <= 0.9857f) ? 0.7942f * norm_storage + -0.0743f : 0.2406f * norm_storage + (0.7942f * 0.9857f + -0.0743f - 0.2406f * 0.9857f); break;
        case  6: norm_outflow = (norm_storage <= 0.9956f) ? 0.8495f * norm_storage + -0.0802f : 0.0790f * norm_storage + (0.8495f * 0.9956f + -0.0802f - 0.0790f * 0.9956f); break;
        case  7: norm_outflow = (norm_storage <= 0.9967f) ? 0.8617f * norm_storage + -0.0808f : 0.0518f * norm_storage + (0.8617f * 0.9967f + -0.0808f - 0.0518f * 0.9967f); break;
        case  8: norm_outflow = (norm_storage <= 0.9980f) ? 0.9137f * norm_storage + -0.0847f : 0.0225f * norm_storage + (0.9137f * 0.9980f + -0.0847f - 0.0225f * 0.9980f); break;
        case  9: norm_outflow = (norm_storage <= 0.9976f) ? 0.9211f * norm_storage + -0.0914f : 0.0507f * norm_storage + (0.9211f * 0.9976f + -0.0914f - 0.0507f * 0.9976f); break;
        case 10: norm_outflow = (norm_storage <= 0.9968f) ? 0.9235f * norm_storage + -0.0952f : 0.0398f * norm_storage + (0.9235f * 0.9968f + -0.0952f - 0.0398f * 0.9968f); break;
        case 11: norm_outflow = (norm_storage <= 0.9972f) ? 0.9386f * norm_storage + -0.0865f : 0.0217f * norm_storage + (0.9386f * 0.9972f + -0.0865f - 0.0217f * 0.9972f); break;
        case 12: norm_outflow = (norm_storage <= 0.9977f) ? 0.9355f * norm_storage + -0.0837f : 0.0242f * norm_storage + (0.9355f * 0.9977f + -0.0837f - 0.0242f * 0.9977f); break;
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
        case  1: norm_outflow = (norm_storage <= 0.9977f) ? 1.9540f * norm_storage + -0.5587f : 0.0391f * norm_storage + (1.9540f * 0.9977f + -0.5587f - 0.0391f * 0.9977f); break;
        case  2: norm_outflow = (norm_storage <= 0.9964f) ? 1.8981f * norm_storage + -0.5295f : 0.0561f * norm_storage + (1.8981f * 0.9964f + -0.5295f - 0.0561f * 0.9964f); break;
        case  3: norm_outflow = (norm_storage <= 0.9979f) ? 1.7306f * norm_storage + -0.4697f : 0.9322f * norm_storage + (1.7306f * 0.9979f + -0.4697f - 0.9322f * 0.9979f); break;
        case  4: norm_outflow = (norm_storage <= 0.9978f) ? 1.9011f * norm_storage + -0.5622f : 0.0336f * norm_storage + (1.9011f * 0.9978f + -0.5622f - 0.0336f * 0.9978f); break;
        case  5: norm_outflow = (norm_storage <= 0.9979f) ? 1.9844f * norm_storage + -0.6168f : 0.0270f * norm_storage + (1.9844f * 0.9979f + -0.6168f - 0.0270f * 0.9979f); break;
        case  6: norm_outflow = (norm_storage <= 0.9983f) ? 2.8968f * norm_storage + -1.0524f : 0.0213f * norm_storage + (2.8968f * 0.9983f + -1.0524f - 0.0213f * 0.9983f); break;
        case  7: norm_outflow = (norm_storage <= 0.9969f) ? 3.2101f * norm_storage + -1.1809f : 0.0624f * norm_storage + (3.2101f * 0.9969f + -1.1809f - 0.0624f * 0.9969f); break;
        case  8: norm_outflow = (norm_storage <= 0.9974f) ? 3.3165f * norm_storage + -1.2155f : 0.0506f * norm_storage + (3.3165f * 0.9974f + -1.2155f - 0.0506f * 0.9974f); break;
        case  9: norm_outflow = (norm_storage <= 0.9968f) ? 2.8225f * norm_storage + -0.9903f : 0.0463f * norm_storage + (2.8225f * 0.9968f + -0.9903f - 0.0463f * 0.9968f); break;
        case 10: norm_outflow = (norm_storage <= 0.9972f) ? 2.7792f * norm_storage + -0.9649f : 0.0424f * norm_storage + (2.7792f * 0.9972f + -0.9649f - 0.0424f * 0.9972f); break;
        case 11: norm_outflow = (norm_storage <= 0.9976f) ? 2.7182f * norm_storage + -0.9357f : 0.0401f * norm_storage + (2.7182f * 0.9976f + -0.9357f - 0.0401f * 0.9976f); break;
        case 12: norm_outflow = (norm_storage <= 0.9983f) ? 2.4780f * norm_storage + -0.8067f : 0.0370f * norm_storage + (2.4780f * 0.9983f + -0.8067f - 0.0370f * 0.9983f); break;
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
        case  1: norm_outflow = (norm_storage <= 0.8315f) ? 0.1102f * norm_storage + 0.0104f : 9.9035f * norm_storage + (0.1102f * 0.8315f + 0.0104f - 9.9035f * 0.8315f); break;
        case  2: norm_outflow = (norm_storage <= 0.8270f) ? 0.1190f * norm_storage + 0.0066f : 7.9722f * norm_storage + (0.1190f * 0.8270f + 0.0066f - 7.9722f * 0.8270f); break;
        case  3: norm_outflow = (norm_storage <= 0.8132f) ? 0.0991f * norm_storage + 0.0252f : 5.6818f * norm_storage + (0.0991f * 0.8132f + 0.0252f - 5.6818f * 0.8132f); break;
        case  4: norm_outflow = (norm_storage <= 0.8235f) ? 0.1075f * norm_storage + 0.0374f : 5.9627f * norm_storage + (0.1075f * 0.8235f + 0.0374f - 5.9627f * 0.8235f); break;
        case  5: norm_outflow = (norm_storage <= 0.8232f) ? 0.1105f * norm_storage + 0.0500f : 6.6426f * norm_storage + (0.1105f * 0.8232f + 0.0500f - 6.6426f * 0.8232f); break;
        case  6: norm_outflow = (norm_storage <= 0.8365f) ? 0.1248f * norm_storage + 0.0554f : 7.8989f * norm_storage + (0.1248f * 0.8365f + 0.0554f - 7.8989f * 0.8365f); break;
        case  7: norm_outflow = (norm_storage <= 0.8472f) ? 0.1315f * norm_storage + 0.0553f : 8.4430f * norm_storage + (0.1315f * 0.8472f + 0.0553f - 8.4430f * 0.8472f); break;
        case  8: norm_outflow = (norm_storage <= 0.8486f) ? 0.1341f * norm_storage + 0.0516f : 9.1602f * norm_storage + (0.1341f * 0.8486f + 0.0516f - 9.1602f * 0.8486f); break;
        case  9: norm_outflow = (norm_storage <= 0.8593f) ? 0.1239f * norm_storage + 0.0435f : 6.1438f * norm_storage + (0.1239f * 0.8593f + 0.0435f - 6.1438f * 0.8593f); break;
        case 10: norm_outflow = (norm_storage <= 0.8451f) ? 0.1033f * norm_storage + 0.0370f : 6.8471f * norm_storage + (0.1033f * 0.8451f + 0.0370f - 6.8471f * 0.8451f); break;
        case 11: norm_outflow = (norm_storage <= 0.8471f) ? 0.0858f * norm_storage + 0.0221f : 7.5410f * norm_storage + (0.0858f * 0.8471f + 0.0221f - 7.5410f * 0.8471f); break;
        case 12: norm_outflow = (norm_storage <= 0.8321f) ? 0.0955f * norm_storage + 0.0145f : 9.5130f * norm_storage + (0.0955f * 0.8321f + 0.0145f - 9.5130f * 0.8321f); break;
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
        case  1: norm_outflow = (norm_storage <= 0.8650f) ? 0.1615f * norm_storage + -0.0608f : 1.0527f * norm_storage + (0.1615f * 0.8650f + -0.0608f - 1.0527f * 0.8650f); break;
        case  2: norm_outflow = (norm_storage <= 0.8619f) ? 0.1645f * norm_storage + -0.0619f : 1.3106f * norm_storage + (0.1645f * 0.8619f + -0.0619f - 1.3106f * 0.8619f); break;
        case  3: norm_outflow = (norm_storage <= 0.8795f) ? 0.1980f * norm_storage + -0.0827f : 0.8910f * norm_storage + (0.1980f * 0.8795f + -0.0827f - 0.8910f * 0.8795f); break;
        case  4: norm_outflow = (norm_storage <= 0.8830f) ? 0.2810f * norm_storage + -0.1109f : 1.0657f * norm_storage + (0.2810f * 0.8830f + -0.1109f - 1.0657f * 0.8830f); break;
        case  5: norm_outflow = (norm_storage <= 0.8849f) ? 0.3080f * norm_storage + -0.1303f : 1.0510f * norm_storage + (0.3080f * 0.8849f + -0.1303f - 1.0510f * 0.8849f); break;
        case  6: norm_outflow = (norm_storage <= 0.8968f) ? 0.3220f * norm_storage + -0.1431f : 0.7842f * norm_storage + (0.3220f * 0.8968f + -0.1431f - 0.7842f * 0.8968f); break;
        case  7: norm_outflow = (norm_storage <= 0.8946f) ? 0.2288f * norm_storage + -0.0999f : 0.7566f * norm_storage + (0.2288f * 0.8946f + -0.0999f - 0.7566f * 0.8946f); break;
        case  8: norm_outflow = (norm_storage <= 0.8899f) ? 0.1889f * norm_storage + -0.0740f : 0.9493f * norm_storage + (0.1889f * 0.8899f + -0.0740f - 0.9493f * 0.8899f); break;
        case  9: norm_outflow = (norm_storage <= 0.8914f) ? 0.1863f * norm_storage + -0.0737f : 0.9190f * norm_storage + (0.1863f * 0.8914f + -0.0737f - 0.9190f * 0.8914f); break;
        case 10: norm_outflow = (norm_storage <= 0.8861f) ? 0.1806f * norm_storage + -0.0701f : 1.0018f * norm_storage + (0.1806f * 0.8861f + -0.0701f - 1.0018f * 0.8861f); break;
        case 11: norm_outflow = (norm_storage <= 0.8737f) ? 0.1872f * norm_storage + -0.0767f : 0.8443f * norm_storage + (0.1872f * 0.8737f + -0.0767f - 0.8443f * 0.8737f); break;
        case 12: norm_outflow = (norm_storage <= 0.8755f) ? 0.1640f * norm_storage + -0.0627f : 0.9495f * norm_storage + (0.1640f * 0.8755f + -0.0627f - 0.9495f * 0.8755f); break;
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
        case  1: norm_outflow = (norm_storage <= 0.9983f) ? 1.4617f * norm_storage + -0.2656f : 0.0187f * norm_storage + (1.4617f * 0.9983f + -0.2656f - 0.0187f * 0.9983f); break;
        case  2: norm_outflow = (norm_storage <= 0.9965f) ? 1.3684f * norm_storage + -0.2255f : 0.0315f * norm_storage + (1.3684f * 0.9965f + -0.2255f - 0.0315f * 0.9965f); break;
        case  3: norm_outflow = (norm_storage <= 0.9975f) ? 1.3176f * norm_storage + -0.2177f : 0.6710f * norm_storage + (1.3176f * 0.9975f + -0.2177f - 0.6710f * 0.9975f); break;
        case  4: norm_outflow = (norm_storage <= 0.9965f) ? 1.4180f * norm_storage + -0.2810f : 0.0663f * norm_storage + (1.4180f * 0.9965f + -0.2810f - 0.0663f * 0.9965f); break;
        case  5: norm_outflow = (norm_storage <= 0.9976f) ? 1.5882f * norm_storage + -0.3497f : 0.0102f * norm_storage + (1.5882f * 0.9976f + -0.3497f - 0.0102f * 0.9976f); break;
        case  6: norm_outflow = (norm_storage <= 0.9977f) ? 2.0487f * norm_storage + -0.5172f : 0.0314f * norm_storage + (2.0487f * 0.9977f + -0.5172f - 0.0314f * 0.9977f); break;
        case  7: norm_outflow = (norm_storage <= 0.9985f) ? 2.4232f * norm_storage + -0.6455f : 0.0107f * norm_storage + (2.4232f * 0.9985f + -0.6455f - 0.0107f * 0.9985f); break;
        case  8: norm_outflow = (norm_storage <= 0.9991f) ? 2.3379f * norm_storage + -0.5994f : 0.0106f * norm_storage + (2.3379f * 0.9991f + -0.5994f - 0.0106f * 0.9991f); break;
        case  9: norm_outflow = (norm_storage <= 0.9981f) ? 1.9322f * norm_storage + -0.4582f : 0.0196f * norm_storage + (1.9322f * 0.9981f + -0.4582f - 0.0196f * 0.9981f); break;
        case 10: norm_outflow = (norm_storage <= 0.9985f) ? 1.8676f * norm_storage + -0.4273f : 0.0153f * norm_storage + (1.8676f * 0.9985f + -0.4273f - 0.0153f * 0.9985f); break;
        case 11: norm_outflow = (norm_storage <= 0.9990f) ? 1.8069f * norm_storage + -0.4026f : 0.0094f * norm_storage + (1.8069f * 0.9990f + -0.4026f - 0.0094f * 0.9990f); break;
        case 12: norm_outflow = (norm_storage <= 0.9990f) ? 1.7129f * norm_storage + -0.3465f : 0.0165f * norm_storage + (1.7129f * 0.9990f + -0.3465f - 0.0165f * 0.9990f); break;
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
        case  1: norm_outflow = (norm_storage <= 0.9966f) ? 2.2845f * norm_storage + -0.9260f : 0.1055f * norm_storage + (2.2845f * 0.9966f + -0.9260f - 0.1055f * 0.9966f); break;
        case  2: norm_outflow = (norm_storage <= 0.9963f) ? 2.2655f * norm_storage + -0.9126f : 0.1084f * norm_storage + (2.2655f * 0.9963f + -0.9126f - 0.1084f * 0.9963f); break;
        case  3: norm_outflow = (norm_storage <= 0.9966f) ? 2.3099f * norm_storage + -0.9328f : 0.1071f * norm_storage + (2.3099f * 0.9966f + -0.9328f - 0.1071f * 0.9966f); break;
        case  4: norm_outflow = (norm_storage <= 0.9928f) ? 2.1453f * norm_storage + -0.8595f : 0.1831f * norm_storage + (2.1453f * 0.9928f + -0.8595f - 0.1831f * 0.9928f); break;
        case  5: norm_outflow = (norm_storage <= 0.9928f) ? 2.1492f * norm_storage + -0.8516f : 0.1498f * norm_storage + (2.1492f * 0.9928f + -0.8516f - 0.1498f * 0.9928f); break;
        case  6: norm_outflow = (norm_storage <= 0.9932f) ? 2.6505f * norm_storage + -1.1203f : 0.1501f * norm_storage + (2.6505f * 0.9932f + -1.1203f - 0.1501f * 0.9932f); break;
        case  7: norm_outflow = (norm_storage <= 0.9932f) ? 2.9208f * norm_storage + -1.2391f : 0.1555f * norm_storage + (2.9208f * 0.9932f + -1.2391f - 0.1555f * 0.9932f); break;
        case  8: norm_outflow = (norm_storage <= 0.9950f) ? 3.0059f * norm_storage + -1.2755f : 0.1412f * norm_storage + (3.0059f * 0.9950f + -1.2755f - 0.1412f * 0.9950f); break;
        case  9: norm_outflow = (norm_storage <= 0.9934f) ? 2.5823f * norm_storage + -1.0790f : 0.1368f * norm_storage + (2.5823f * 0.9934f + -1.0790f - 0.1368f * 0.9934f); break;
        case 10: norm_outflow = (norm_storage <= 0.9944f) ? 2.5534f * norm_storage + -1.0578f : 0.1345f * norm_storage + (2.5534f * 0.9944f + -1.0578f - 0.1345f * 0.9944f); break;
        case 11: norm_outflow = (norm_storage <= 0.9958f) ? 2.5949f * norm_storage + -1.0830f : 0.1172f * norm_storage + (2.5949f * 0.9958f + -1.0830f - 0.1172f * 0.9958f); break;
        case 12: norm_outflow = (norm_storage <= 0.9952f) ? 2.4920f * norm_storage + -1.0356f : 0.1239f * norm_storage + (2.4920f * 0.9952f + -1.0356f - 0.1239f * 0.9952f); break;
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
        case  1: norm_outflow = (norm_storage <= 0.7107f) ? 0.0861f * norm_storage + -0.0320f : 2.2951f * norm_storage + (0.0861f * 0.7107f + -0.0320f - 2.2951f * 0.7107f); break;
        case  2: norm_outflow = (norm_storage <= 0.7034f) ? 0.0972f * norm_storage + -0.0364f : 2.3095f * norm_storage + (0.0972f * 0.7034f + -0.0364f - 2.3095f * 0.7034f); break;
        case  3: norm_outflow = (norm_storage <= 0.7043f) ? 0.0995f * norm_storage + -0.0393f : 2.1418f * norm_storage + (0.0995f * 0.7043f + -0.0393f - 2.1418f * 0.7043f); break;
        case  4: norm_outflow = (norm_storage <= 0.7020f) ? 0.1109f * norm_storage + -0.0456f : 2.1446f * norm_storage + (0.1109f * 0.7020f + -0.0456f - 2.1446f * 0.7020f); break;
        case  5: norm_outflow = (norm_storage <= 0.7380f) ? 0.1961f * norm_storage + -0.0756f : 1.7609f * norm_storage + (0.1961f * 0.7380f + -0.0756f - 1.7609f * 0.7380f); break;
        case  6: norm_outflow = (norm_storage <= 0.7495f) ? 0.2227f * norm_storage + -0.0844f : 1.8390f * norm_storage + (0.2227f * 0.7495f + -0.0844f - 1.8390f * 0.7495f); break;
        case  7: norm_outflow = (norm_storage <= 0.7141f) ? 0.1341f * norm_storage + -0.0529f : 1.8434f * norm_storage + (0.1341f * 0.7141f + -0.0529f - 1.8434f * 0.7141f); break;
        case  8: norm_outflow = (norm_storage <= 0.7104f) ? 0.1164f * norm_storage + -0.0424f : 2.2437f * norm_storage + (0.1164f * 0.7104f + -0.0424f - 2.2437f * 0.7104f); break;
        case  9: norm_outflow = (norm_storage <= 0.7016f) ? 0.0813f * norm_storage + -0.0232f : 2.4064f * norm_storage + (0.0813f * 0.7016f + -0.0232f - 2.4064f * 0.7016f); break;
        case 10: norm_outflow = (norm_storage <= 0.6977f) ? 0.0723f * norm_storage + -0.0224f : 2.4249f * norm_storage + (0.0723f * 0.6977f + -0.0224f - 2.4249f * 0.6977f); break;
        case 11: norm_outflow = (norm_storage <= 0.7010f) ? 0.0767f * norm_storage + -0.0257f : 2.2132f * norm_storage + (0.0767f * 0.7010f + -0.0257f - 2.2132f * 0.7010f); break;
        case 12: norm_outflow = (norm_storage <= 0.7050f) ? 0.0908f * norm_storage + -0.0347f : 2.2562f * norm_storage + (0.0908f * 0.7050f + -0.0347f - 2.2562f * 0.7050f); break;
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
        case  1: norm_outflow = (norm_storage <= 0.9517f) ? 1.3589f * norm_storage + -0.6341f : 0.4446f * norm_storage + (1.3589f * 0.9517f + -0.6341f - 0.4446f * 0.9517f); break;
        case  2: norm_outflow = (norm_storage <= 0.9520f) ? 1.3873f * norm_storage + -0.6505f : 0.4479f * norm_storage + (1.3873f * 0.9520f + -0.6505f - 0.4479f * 0.9520f); break;
        case  3: norm_outflow = (norm_storage <= 0.9529f) ? 1.3938f * norm_storage + -0.6557f : 0.4676f * norm_storage + (1.3938f * 0.9529f + -0.6557f - 0.4676f * 0.9529f); break;
        case  4: norm_outflow = (norm_storage <= 0.9399f) ? 1.2907f * norm_storage + -0.6146f : 0.8156f * norm_storage + (1.2907f * 0.9399f + -0.6146f - 0.8156f * 0.9399f); break;
        case  5: norm_outflow = (norm_storage <= 0.9399f) ? 1.2520f * norm_storage + -0.5985f : 0.8291f * norm_storage + (1.2520f * 0.9399f + -0.5985f - 0.8291f * 0.9399f); break;
        case  6: norm_outflow = (norm_storage <= 0.9380f) ? 1.2701f * norm_storage + -0.6095f : 0.7848f * norm_storage + (1.2701f * 0.9380f + -0.6095f - 0.7848f * 0.9380f); break;
        case  7: norm_outflow = (norm_storage <= 0.8716f) ? 0.8640f * norm_storage + -0.3841f : 1.4756f * norm_storage + (0.8640f * 0.8716f + -0.3841f - 1.4756f * 0.8716f); break;
        case  8: norm_outflow = (norm_storage <= 0.8862f) ? 0.9502f * norm_storage + -0.4231f : 1.1316f * norm_storage + (0.9502f * 0.8862f + -0.4231f - 1.1316f * 0.8862f); break;
        case  9: norm_outflow = (norm_storage <= 0.8756f) ? 0.8793f * norm_storage + -0.3916f : 1.3169f * norm_storage + (0.8793f * 0.8756f + -0.3916f - 1.3169f * 0.8756f); break;
        case 10: norm_outflow = (norm_storage <= 0.8719f) ? 0.8620f * norm_storage + -0.3864f : 1.3049f * norm_storage + (0.8620f * 0.8719f + -0.3864f - 1.3049f * 0.8719f); break;
        case 11: norm_outflow = (norm_storage <= 0.8830f) ? 0.9350f * norm_storage + -0.4228f : 1.1216f * norm_storage + (0.9350f * 0.8830f + -0.4228f - 1.1216f * 0.8830f); break;
        case 12: norm_outflow = (norm_storage <= 0.9426f) ? 1.3222f * norm_storage + -0.6181f : 0.5662f * norm_storage + (1.3222f * 0.9426f + -0.6181f - 0.5662f * 0.9426f); break;
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
        case  1: norm_outflow = (norm_storage <= 0.9960f) ? 1.1132f * norm_storage + -0.1382f : 0.0327f * norm_storage + (1.1132f * 0.9960f + -0.1382f - 0.0327f * 0.9960f); break;
        case  2: norm_outflow = (norm_storage <= 0.9956f) ? 1.0853f * norm_storage + -0.1304f : 0.0366f * norm_storage + (1.0853f * 0.9956f + -0.1304f - 0.0366f * 0.9956f); break;
        case  3: norm_outflow = (norm_storage <= 0.9945f) ? 1.0475f * norm_storage + -0.1296f : 0.0508f * norm_storage + (1.0475f * 0.9945f + -0.1296f - 0.0508f * 0.9945f); break;
        case  4: norm_outflow = (norm_storage <= 0.9953f) ? 1.1735f * norm_storage + -0.1920f : 0.0312f * norm_storage + (1.1735f * 0.9953f + -0.1920f - 0.0312f * 0.9953f); break;
        case  5: norm_outflow = (norm_storage <= 0.9961f) ? 1.3235f * norm_storage + -0.2604f : 0.0369f * norm_storage + (1.3235f * 0.9961f + -0.2604f - 0.0369f * 0.9961f); break;
        case  6: norm_outflow = (norm_storage <= 0.9970f) ? 2.0117f * norm_storage + -0.5459f : 0.0280f * norm_storage + (2.0117f * 0.9970f + -0.5459f - 0.0280f * 0.9970f); break;
        case  7: norm_outflow = (norm_storage <= 0.9958f) ? 2.3698f * norm_storage + -0.6724f : 0.0377f * norm_storage + (2.3698f * 0.9958f + -0.6724f - 0.0377f * 0.9958f); break;
        case  8: norm_outflow = 1.2322f * norm_inflow + 0.0500f; break;
        case  9: norm_outflow = 1.0864f * norm_inflow + 0.0555f; break;
        case 10: norm_outflow = 1.1524f * norm_inflow + 0.0622f; break;
        case 11: norm_outflow = (norm_storage <= 0.9961f) ? 1.5685f * norm_storage + -0.3402f : 0.0376f * norm_storage + (1.5685f * 0.9961f + -0.3402f - 0.0376f * 0.9961f); break;
        case 12: norm_outflow = (norm_storage <= 0.9949f) ? 1.3648f * norm_storage + -0.2584f : 0.0376f * norm_storage + (1.3648f * 0.9949f + -0.2584f - 0.0376f * 0.9949f); break;
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
        case  1: norm_outflow = (norm_storage <= 0.9781f) ? 0.3672f * norm_storage + -0.0572f : 0.1238f * norm_storage + (0.3672f * 0.9781f + -0.0572f - 0.1238f * 0.9781f); break;
        case  2: norm_outflow = (norm_storage <= 0.9801f) ? 0.3784f * norm_storage + -0.0580f : 0.1131f * norm_storage + (0.3784f * 0.9801f + -0.0580f - 0.1131f * 0.9801f); break;
        case  3: norm_outflow = (norm_storage <= 0.9849f) ? 0.4167f * norm_storage + -0.0638f : 0.0663f * norm_storage + (0.4167f * 0.9849f + -0.0638f - 0.0663f * 0.9849f); break;
        case  4: norm_outflow = (norm_storage <= 0.9826f) ? 0.4506f * norm_storage + -0.0686f : 0.0807f * norm_storage + (0.4506f * 0.9826f + -0.0686f - 0.0807f * 0.9826f); break;
        case  5: norm_outflow = (norm_storage <= 0.9656f) ? 0.4395f * norm_storage + -0.0768f : 0.2795f * norm_storage + (0.4395f * 0.9656f + -0.0768f - 0.2795f * 0.9656f); break;
        case  6: norm_outflow = (norm_storage <= 0.9566f) ? 0.4759f * norm_storage + -0.0947f : 0.5119f * norm_storage + (0.4759f * 0.9566f + -0.0947f - 0.5119f * 0.9566f); break;
        case  7: norm_outflow = (norm_storage <= 0.9755f) ? 0.4469f * norm_storage + -0.0670f : 0.1152f * norm_storage + (0.4469f * 0.9755f + -0.0670f - 0.1152f * 0.9755f); break;
        case  8: norm_outflow = (norm_storage <= 0.9783f) ? 0.4563f * norm_storage + -0.0692f : 0.1140f * norm_storage + (0.4563f * 0.9783f + -0.0692f - 0.1140f * 0.9783f); break;
        case  9: norm_outflow = (norm_storage <= 0.9780f) ? 0.4430f * norm_storage + -0.0692f : 0.1301f * norm_storage + (0.4430f * 0.9780f + -0.0692f - 0.1301f * 0.9780f); break;
        case 10: norm_outflow = (norm_storage <= 0.9755f) ? 0.4323f * norm_storage + -0.0663f : 0.1665f * norm_storage + (0.4323f * 0.9755f + -0.0663f - 0.1665f * 0.9755f); break;
        case 11: norm_outflow = (norm_storage <= 0.9828f) ? 0.3788f * norm_storage + -0.0583f : 0.0504f * norm_storage + (0.3788f * 0.9828f + -0.0583f - 0.0504f * 0.9828f); break;
        case 12: norm_outflow = (norm_storage <= 0.9811f) ? 0.3669f * norm_storage + -0.0572f : 0.0739f * norm_storage + (0.3669f * 0.9811f + -0.0572f - 0.0739f * 0.9811f); break;
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
        case  1: norm_outflow = (norm_storage <= 0.9987f) ? 1.4555f * norm_storage + -0.3766f : 0.0121f * norm_storage + (1.4555f * 0.9987f + -0.3766f - 0.0121f * 0.9987f); break;
        case  2: norm_outflow = (norm_storage <= 0.9972f) ? 1.4400f * norm_storage + -0.3692f : 0.0344f * norm_storage + (1.4400f * 0.9972f + -0.3692f - 0.0344f * 0.9972f); break;
        case  3: norm_outflow = (norm_storage <= 0.9982f) ? 1.4097f * norm_storage + -0.3677f : 0.0132f * norm_storage + (1.4097f * 0.9982f + -0.3677f - 0.0132f * 0.9982f); break;
        case  4: norm_outflow = (norm_storage <= 0.9989f) ? 1.5389f * norm_storage + -0.4440f : 0.0060f * norm_storage + (1.5389f * 0.9989f + -0.4440f - 0.0060f * 0.9989f); break;
        case  5: norm_outflow = (norm_storage <= 0.9984f) ? 1.5772f * norm_storage + -0.4747f : 0.0256f * norm_storage + (1.5772f * 0.9984f + -0.4747f - 0.0256f * 0.9984f); break;
        case  6: norm_outflow = (norm_storage <= 0.9973f) ? 2.0936f * norm_storage + -0.7142f : 0.0465f * norm_storage + (2.0936f * 0.9973f + -0.7142f - 0.0465f * 0.9973f); break;
        case  7: norm_outflow = (norm_storage <= 0.9952f) ? 2.6144f * norm_storage + -0.9447f : 0.0662f * norm_storage + (2.6144f * 0.9952f + -0.9447f - 0.0662f * 0.9952f); break;
        case  8: norm_outflow = (norm_storage <= 0.9962f) ? 2.7049f * norm_storage + -0.9739f : 0.0523f * norm_storage + (2.7049f * 0.9962f + -0.9739f - 0.0523f * 0.9962f); break;
        case  9: norm_outflow = (norm_storage <= 0.9953f) ? 2.3643f * norm_storage + -0.8163f : 0.0496f * norm_storage + (2.3643f * 0.9953f + -0.8163f - 0.0496f * 0.9953f); break;
        case 10: norm_outflow = 1.2279f * norm_inflow + 0.0699f; break;
        case 11: norm_outflow = 1.1255f * norm_inflow + 0.0720f; break;
        case 12: norm_outflow = (norm_storage <= 0.9965f) ? 1.6860f * norm_storage + -0.4905f : 0.0325f * norm_storage + (1.6860f * 0.9965f + -0.4905f - 0.0325f * 0.9965f); break;
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
        case  1: norm_outflow = 0.6681f * norm_inflow + 0.0401f; break;
        case  2: norm_outflow = 0.6867f * norm_inflow + 0.0385f; break;
        case  3: norm_outflow = 0.7389f * norm_inflow + 0.0371f; break;
        case  4: norm_outflow = 0.7682f * norm_inflow + 0.0373f; break;
        case  5: norm_outflow = 0.7898f * norm_inflow + 0.0391f; break;
        case  6: norm_outflow = 0.7942f * norm_inflow + 0.0393f; break;
        case  7: norm_outflow = 0.7629f * norm_inflow + 0.0381f; break;
        case  8: norm_outflow = 0.6129f * norm_inflow + 0.0379f; break;
        case  9: norm_outflow = 0.5644f * norm_inflow + 0.0365f; break;
        case 10: norm_outflow = 0.5809f * norm_inflow + 0.0362f; break;
        case 11: norm_outflow = 0.5818f * norm_inflow + 0.0375f; break;
        case 12: norm_outflow = 0.7200f * norm_inflow + 0.0392f; break;
    }
    return norm_outflow * max_outflow_m3d;
}

static float rule_852(float inflow_m3d, float storage_m3, int month) {
    const float max_inflow_m3d   = 309668021.3f;
    const float max_outflow_m3d  = 62632401.2f;
    const float max_storage_m3   = 935770967.6f;
    const float norm_inflow  = inflow_m3d  / max_inflow_m3d;
    const float norm_storage = storage_m3  / max_storage_m3;
    float norm_outflow;

    switch (month) {
        case  1: norm_outflow = (norm_storage <= 0.9994f) ? 0.8653f * norm_storage + -0.0708f : 0.0118f * norm_storage + (0.8653f * 0.9994f + -0.0708f - 0.0118f * 0.9994f); break;
        case  2: norm_outflow = (norm_storage <= 0.9994f) ? 0.9104f * norm_storage + -0.0798f : 0.0096f * norm_storage + (0.9104f * 0.9994f + -0.0798f - 0.0096f * 0.9994f); break;
        case  3: norm_outflow = (norm_storage <= 0.9990f) ? 0.7795f * norm_storage + -0.0630f : 0.1929f * norm_storage + (0.7795f * 0.9990f + -0.0630f - 0.1929f * 0.9990f); break;
        case  4: norm_outflow = (norm_storage <= 0.9887f) ? 0.6864f * norm_storage + -0.0530f : 0.2017f * norm_storage + (0.6864f * 0.9887f + -0.0530f - 0.2017f * 0.9887f); break;
        case  5: norm_outflow = (norm_storage <= 0.9902f) ? 0.7023f * norm_storage + -0.0637f : 0.1830f * norm_storage + (0.7023f * 0.9902f + -0.0637f - 0.1830f * 0.9902f); break;
        case  6: norm_outflow = (norm_storage <= 0.9987f) ? 0.9188f * norm_storage + -0.1012f : 0.0633f * norm_storage + (0.9188f * 0.9987f + -0.1012f - 0.0633f * 0.9987f); break;
        case  7: norm_outflow = (norm_storage <= 0.9987f) ? 0.9483f * norm_storage + -0.1102f : 0.0168f * norm_storage + (0.9483f * 0.9987f + -0.1102f - 0.0168f * 0.9987f); break;
        case  8: norm_outflow = (norm_storage <= 0.9988f) ? 1.0049f * norm_storage + -0.1236f : 0.0124f * norm_storage + (1.0049f * 0.9988f + -0.1236f - 0.0124f * 0.9988f); break;
        case  9: norm_outflow = (norm_storage <= 0.9985f) ? 0.9796f * norm_storage + -0.1112f : 0.0190f * norm_storage + (0.9796f * 0.9985f + -0.1112f - 0.0190f * 0.9985f); break;
        case 10: norm_outflow = (norm_storage <= 0.9984f) ? 0.9161f * norm_storage + -0.0957f : 0.0209f * norm_storage + (0.9161f * 0.9984f + -0.0957f - 0.0209f * 0.9984f); break;
        case 11: norm_outflow = (norm_storage <= 0.9971f) ? 0.7203f * norm_storage + -0.0526f : 0.0297f * norm_storage + (0.7203f * 0.9971f + -0.0526f - 0.0297f * 0.9971f); break;
        case 12: norm_outflow = (norm_storage <= 0.9986f) ? 0.8132f * norm_storage + -0.0627f : 0.0233f * norm_storage + (0.8132f * 0.9986f + -0.0627f - 0.0233f * 0.9986f); break;
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
        case  1: norm_outflow = (norm_storage <= 0.9968f) ? 1.2776f * norm_storage + -0.1683f : 0.0286f * norm_storage + (1.2776f * 0.9968f + -0.1683f - 0.0286f * 0.9968f); break;
        case  2: norm_outflow = (norm_storage <= 0.9950f) ? 1.1717f * norm_storage + -0.1266f : 0.0495f * norm_storage + (1.1717f * 0.9950f + -0.1266f - 0.0495f * 0.9950f); break;
        case  3: norm_outflow = (norm_storage <= 0.9975f) ? 1.2081f * norm_storage + -0.1439f : 0.0484f * norm_storage + (1.2081f * 0.9975f + -0.1439f - 0.0484f * 0.9975f); break;
        case  4: norm_outflow = (norm_storage <= 0.9992f) ? 1.3108f * norm_storage + -0.2161f : 0.0083f * norm_storage + (1.3108f * 0.9992f + -0.2161f - 0.0083f * 0.9992f); break;
        case  5: norm_outflow = (norm_storage <= 0.9979f) ? 1.2938f * norm_storage + -0.2336f : 0.0239f * norm_storage + (1.2938f * 0.9979f + -0.2336f - 0.0239f * 0.9979f); break;
        case  6: norm_outflow = (norm_storage <= 0.9959f) ? 1.6027f * norm_storage + -0.3633f : 0.0543f * norm_storage + (1.6027f * 0.9959f + -0.3633f - 0.0543f * 0.9959f); break;
        case  7: norm_outflow = (norm_storage <= 0.9917f) ? 1.9335f * norm_storage + -0.5177f : 0.0997f * norm_storage + (1.9335f * 0.9917f + -0.5177f - 0.0997f * 0.9917f); break;
        case  8: norm_outflow = (norm_storage <= 0.9936f) ? 2.0700f * norm_storage + -0.5747f : 0.0667f * norm_storage + (2.0700f * 0.9936f + -0.5747f - 0.0667f * 0.9936f); break;
        case  9: norm_outflow = (norm_storage <= 0.9928f) ? 1.9364f * norm_storage + -0.5115f : 0.0759f * norm_storage + (1.9364f * 0.9928f + -0.5115f - 0.0759f * 0.9928f); break;
        case 10: norm_outflow = 1.6841f * norm_inflow + 0.0926f; break;
        case 11: norm_outflow = 1.4447f * norm_inflow + 0.1000f; break;
        case 12: norm_outflow = (norm_storage <= 0.9959f) ? 1.4372f * norm_storage + -0.2336f : 0.0463f * norm_storage + (1.4372f * 0.9959f + -0.2336f - 0.0463f * 0.9959f); break;
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
        case  1: norm_outflow = (norm_storage <= 0.9652f) ? 0.2038f * norm_storage + -0.0276f : 0.5939f * norm_storage + (0.2038f * 0.9652f + -0.0276f - 0.5939f * 0.9652f); break;
        case  2: norm_outflow = (norm_storage <= 0.9639f) ? 0.2189f * norm_storage + -0.0331f : 0.6312f * norm_storage + (0.2189f * 0.9639f + -0.0331f - 0.6312f * 0.9639f); break;
        case  3: norm_outflow = (norm_storage <= 0.9665f) ? 0.2135f * norm_storage + -0.0329f : 0.5704f * norm_storage + (0.2135f * 0.9665f + -0.0329f - 0.5704f * 0.9665f); break;
        case  4: norm_outflow = (norm_storage <= 0.9641f) ? 0.2568f * norm_storage + -0.0530f : 0.5945f * norm_storage + (0.2568f * 0.9641f + -0.0530f - 0.5945f * 0.9641f); break;
        case  5: norm_outflow = (norm_storage <= 0.9652f) ? 0.3486f * norm_storage + -0.0747f : 0.6952f * norm_storage + (0.3486f * 0.9652f + -0.0747f - 0.6952f * 0.9652f); break;
        case  6: norm_outflow = (norm_storage <= 0.9687f) ? 0.3462f * norm_storage + -0.0890f : 0.6225f * norm_storage + (0.3462f * 0.9687f + -0.0890f - 0.6225f * 0.9687f); break;
        case  7: norm_outflow = (norm_storage <= 0.9629f) ? 0.2600f * norm_storage + -0.0688f : 0.7137f * norm_storage + (0.2600f * 0.9629f + -0.0688f - 0.7137f * 0.9629f); break;
        case  8: norm_outflow = (norm_storage <= 0.9577f) ? 0.2276f * norm_storage + -0.0561f : 0.9043f * norm_storage + (0.2276f * 0.9577f + -0.0561f - 0.9043f * 0.9577f); break;
        case  9: norm_outflow = (norm_storage <= 0.9588f) ? 0.2096f * norm_storage + -0.0513f : 0.9017f * norm_storage + (0.2096f * 0.9588f + -0.0513f - 0.9017f * 0.9588f); break;
        case 10: norm_outflow = (norm_storage <= 0.9500f) ? 0.2320f * norm_storage + -0.0567f : 1.1836f * norm_storage + (0.2320f * 0.9500f + -0.0567f - 1.1836f * 0.9500f); break;
        case 11: norm_outflow = (norm_storage <= 0.9639f) ? 0.2134f * norm_storage + -0.0402f : 0.6896f * norm_storage + (0.2134f * 0.9639f + -0.0402f - 0.6896f * 0.9639f); break;
        case 12: norm_outflow = (norm_storage <= 0.9661f) ? 0.2213f * norm_storage + -0.0361f : 0.6007f * norm_storage + (0.2213f * 0.9661f + -0.0361f - 0.6007f * 0.9661f); break;
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
        case  1: norm_outflow = 1.0865f * norm_inflow + 0.0215f; break;
        case  2: norm_outflow = (norm_storage <= 0.9782f) ? 1.0422f * norm_storage + -0.2082f : 0.2735f * norm_storage + (1.0422f * 0.9782f + -0.2082f - 0.2735f * 0.9782f); break;
        case  3: norm_outflow = (norm_storage <= 0.9783f) ? 1.1323f * norm_storage + -0.2284f : 0.2737f * norm_storage + (1.1323f * 0.9783f + -0.2284f - 0.2737f * 0.9783f); break;
        case  4: norm_outflow = (norm_storage <= 0.9777f) ? 1.1966f * norm_storage + -0.2450f : 0.2426f * norm_storage + (1.1966f * 0.9777f + -0.2450f - 0.2426f * 0.9777f); break;
        case  5: norm_outflow = (norm_storage <= 0.9733f) ? 1.1811f * norm_storage + -0.2939f : 0.5897f * norm_storage + (1.1811f * 0.9733f + -0.2939f - 0.5897f * 0.9733f); break;
        case  6: norm_outflow = (norm_storage <= 0.9742f) ? 1.1678f * norm_storage + -0.2911f : 0.6711f * norm_storage + (1.1678f * 0.9742f + -0.2911f - 0.6711f * 0.9742f); break;
        case  7: norm_outflow = (norm_storage <= 0.9745f) ? 1.1420f * norm_storage + -0.2355f : 0.3228f * norm_storage + (1.1420f * 0.9745f + -0.2355f - 0.3228f * 0.9745f); break;
        case  8: norm_outflow = (norm_storage <= 0.9722f) ? 1.0783f * norm_storage + -0.2266f : 0.4761f * norm_storage + (1.0783f * 0.9722f + -0.2266f - 0.4761f * 0.9722f); break;
        case  9: norm_outflow = (norm_storage <= 0.9768f) ? 1.0689f * norm_storage + -0.2047f : 0.2673f * norm_storage + (1.0689f * 0.9768f + -0.2047f - 0.2673f * 0.9768f); break;
        case 10: norm_outflow = (norm_storage <= 0.9738f) ? 1.0248f * norm_storage + -0.1960f : 0.3303f * norm_storage + (1.0248f * 0.9738f + -0.1960f - 0.3303f * 0.9738f); break;
        case 11: norm_outflow = (norm_storage <= 0.9756f) ? 1.0010f * norm_storage + -0.1869f : 0.2879f * norm_storage + (1.0010f * 0.9756f + -0.1869f - 0.2879f * 0.9756f); break;
        case 12: norm_outflow = 1.1258f * norm_inflow + 0.0210f; break;
    }
    return norm_outflow * max_outflow_m3d;
}

static float rule_858(float inflow_m3d, float storage_m3, int month) {
    const float max_inflow_m3d   = 361806933.0f;
    const float max_outflow_m3d  = 256988571.3f;
    const float max_storage_m3   = 1669559585.0f;
    const float norm_inflow  = inflow_m3d  / max_inflow_m3d;
    const float norm_storage = storage_m3  / max_storage_m3;
    float norm_outflow;

    switch (month) {
        case  1: norm_outflow = 0.7734f * norm_inflow + 0.0177f; break;
        case  2: norm_outflow = 0.8033f * norm_inflow + 0.0162f; break;
        case  3: norm_outflow = 0.8749f * norm_inflow + 0.0160f; break;
        case  4: norm_outflow = 0.9439f * norm_inflow + 0.0187f; break;
        case  5: norm_outflow = (norm_storage <= 0.9284f) ? 0.4972f * norm_storage + -0.1265f : 1.1390f * norm_storage + (0.4972f * 0.9284f + -0.1265f - 1.1390f * 0.9284f); break;
        case  6: norm_outflow = (norm_storage <= 0.9423f) ? 0.5095f * norm_storage + -0.1270f : 0.8385f * norm_storage + (0.5095f * 0.9423f + -0.1270f - 0.8385f * 0.9423f); break;
        case  7: norm_outflow = (norm_storage <= 0.9440f) ? 0.5220f * norm_storage + -0.1211f : 0.6620f * norm_storage + (0.5220f * 0.9440f + -0.1211f - 0.6620f * 0.9440f); break;
        case  8: norm_outflow = 1.0714f * norm_inflow + 0.0199f; break;
        case  9: norm_outflow = 0.9724f * norm_inflow + 0.0188f; break;
        case 10: norm_outflow = 1.0119f * norm_inflow + 0.0194f; break;
        case 11: norm_outflow = 0.8756f * norm_inflow + 0.0183f; break;
        case 12: norm_outflow = 0.7768f * norm_inflow + 0.0185f; break;
    }
    return norm_outflow * max_outflow_m3d;
}

static float rule_862(float inflow_m3d, float storage_m3, int month) {
    const float max_inflow_m3d   = 161199172.2f;
    const float max_outflow_m3d  = 24999063.0f;
    const float max_storage_m3   = 1998869018.0f;
    const float norm_inflow  = inflow_m3d  / max_inflow_m3d;
    const float norm_storage = storage_m3  / max_storage_m3;
    float norm_outflow;

    switch (month) {
        case  1: norm_outflow = (norm_storage <= 0.9130f) ? 0.6956f * norm_storage + -0.3550f : 1.6368f * norm_storage + (0.6956f * 0.9130f + -0.3550f - 1.6368f * 0.9130f); break;
        case  2: norm_outflow = (norm_storage <= 0.8987f) ? 0.6646f * norm_storage + -0.3414f : 2.0374f * norm_storage + (0.6646f * 0.8987f + -0.3414f - 2.0374f * 0.8987f); break;
        case  3: norm_outflow = (norm_storage <= 0.8780f) ? 0.5822f * norm_storage + -0.2900f : 2.8246f * norm_storage + (0.5822f * 0.8780f + -0.2900f - 2.8246f * 0.8780f); break;
        case  4: norm_outflow = (norm_storage <= 0.8643f) ? 0.4989f * norm_storage + -0.2454f : 3.6803f * norm_storage + (0.4989f * 0.8643f + -0.2454f - 3.6803f * 0.8643f); break;
        case  5: norm_outflow = (norm_storage <= 0.8727f) ? 0.5344f * norm_storage + -0.2707f : 3.7494f * norm_storage + (0.5344f * 0.8727f + -0.2707f - 3.7494f * 0.8727f); break;
        case  6: norm_outflow = (norm_storage <= 0.8696f) ? 0.4828f * norm_storage + -0.2281f : 4.0678f * norm_storage + (0.4828f * 0.8696f + -0.2281f - 4.0678f * 0.8696f); break;
        case  7: norm_outflow = 0.7158f * norm_inflow + 0.0762f; break;
        case  8: norm_outflow = 0.6001f * norm_inflow + 0.0714f; break;
        case  9: norm_outflow = (norm_storage <= 0.9462f) ? 0.6001f * norm_storage + -0.2707f : 0.9433f * norm_storage + (0.6001f * 0.9462f + -0.2707f - 0.9433f * 0.9462f); break;
        case 10: norm_outflow = (norm_storage <= 0.9562f) ? 0.6428f * norm_storage + -0.2860f : 0.7911f * norm_storage + (0.6428f * 0.9562f + -0.2860f - 0.7911f * 0.9562f); break;
        case 11: norm_outflow = (norm_storage <= 0.9428f) ? 0.6369f * norm_storage + -0.2963f : 0.8422f * norm_storage + (0.6369f * 0.9428f + -0.2963f - 0.8422f * 0.9428f); break;
        case 12: norm_outflow = (norm_storage <= 0.8922f) ? 0.6475f * norm_storage + -0.3214f : 2.4768f * norm_storage + (0.6475f * 0.8922f + -0.3214f - 2.4768f * 0.8922f); break;
    }
    return norm_outflow * max_outflow_m3d;
}

static float rule_863(float inflow_m3d, float storage_m3, int month) {
    const float max_inflow_m3d   = 28790813.9f;
    const float max_outflow_m3d  = 11002292.8f;
    const float max_storage_m3   = 447970332.5f;
    const float norm_inflow  = inflow_m3d  / max_inflow_m3d;
    const float norm_storage = storage_m3  / max_storage_m3;
    float norm_outflow;

    switch (month) {
        case  1: norm_outflow = 2.0799f * norm_inflow + 0.0408f; break;
        case  2: norm_outflow = 2.1010f * norm_inflow + 0.0385f; break;
        case  3: norm_outflow = 2.0870f * norm_inflow + 0.0374f; break;
        case  4: norm_outflow = 2.1494f * norm_inflow + 0.0330f; break;
        case  5: norm_outflow = 2.2252f * norm_inflow + 0.0320f; break;
        case  6: norm_outflow = 2.3474f * norm_inflow + 0.0368f; break;
        case  7: norm_outflow = 2.3674f * norm_inflow + 0.0392f; break;
        case  8: norm_outflow = 2.4176f * norm_inflow + 0.0432f; break;
        case  9: norm_outflow = 2.4715f * norm_inflow + 0.0459f; break;
        case 10: norm_outflow = 2.4191f * norm_inflow + 0.0453f; break;
        case 11: norm_outflow = 2.3278f * norm_inflow + 0.0461f; break;
        case 12: norm_outflow = 2.2427f * norm_inflow + 0.0436f; break;
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
        case  1: norm_outflow = 1.1639f * norm_inflow + 0.0023f; break;
        case  2: norm_outflow = 1.1666f * norm_inflow + 0.0009f; break;
        case  3: norm_outflow = 1.1608f * norm_inflow + 0.0008f; break;
        case  4: norm_outflow = 1.1730f * norm_inflow + -0.0001f; break;
        case  5: norm_outflow = 1.1730f * norm_inflow + 0.0019f; break;
        case  6: norm_outflow = 1.1860f * norm_inflow + 0.0036f; break;
        case  7: norm_outflow = 1.1884f * norm_inflow + 0.0052f; break;
        case  8: norm_outflow = 1.2167f * norm_inflow + 0.0047f; break;
        case  9: norm_outflow = 1.1963f * norm_inflow + 0.0059f; break;
        case 10: norm_outflow = 1.1618f * norm_inflow + 0.0061f; break;
        case 11: norm_outflow = 1.1742f * norm_inflow + 0.0056f; break;
        case 12: norm_outflow = 1.1663f * norm_inflow + 0.0052f; break;
    }
    return norm_outflow * max_outflow_m3d;
}

static float rule_867(float inflow_m3d, float storage_m3, int month) {
    const float max_inflow_m3d   = 280906802.5f;
    const float max_outflow_m3d  = 211702408.6f;
    const float max_storage_m3   = 2493487221.0f;
    const float norm_inflow  = inflow_m3d  / max_inflow_m3d;
    const float norm_storage = storage_m3  / max_storage_m3;
    float norm_outflow;

    switch (month) {
        case  1: norm_outflow = (norm_storage <= 0.9268f) ? 0.2560f * norm_storage + -0.1052f : 1.8588f * norm_storage + (0.2560f * 0.9268f + -0.1052f - 1.8588f * 0.9268f); break;
        case  2: norm_outflow = (norm_storage <= 0.9299f) ? 0.2708f * norm_storage + -0.1031f : 1.5582f * norm_storage + (0.2708f * 0.9299f + -0.1031f - 1.5582f * 0.9299f); break;
        case  3: norm_outflow = (norm_storage <= 0.9207f) ? 0.2534f * norm_storage + -0.1108f : 3.0858f * norm_storage + (0.2534f * 0.9207f + -0.1108f - 3.0858f * 0.9207f); break;
        case  4: norm_outflow = (norm_storage <= 0.8978f) ? 0.3035f * norm_storage + -0.1320f : 5.7263f * norm_storage + (0.3035f * 0.8978f + -0.1320f - 5.7263f * 0.8978f); break;
        case  5: norm_outflow = 0.8832f * norm_inflow + 0.0589f; break;
        case  6: norm_outflow = 0.8757f * norm_inflow + 0.0592f; break;
        case  7: norm_outflow = 0.8630f * norm_inflow + 0.0591f; break;
        case  8: norm_outflow = (norm_storage <= 0.9234f) ? 0.2166f * norm_storage + -0.0711f : 2.2632f * norm_storage + (0.2166f * 0.9234f + -0.0711f - 2.2632f * 0.9234f); break;
        case  9: norm_outflow = (norm_storage <= 0.9220f) ? 0.2322f * norm_storage + -0.0953f : 2.6022f * norm_storage + (0.2322f * 0.9220f + -0.0953f - 2.6022f * 0.9220f); break;
        case 10: norm_outflow = (norm_storage <= 0.9273f) ? 0.2135f * norm_storage + -0.0879f : 2.1964f * norm_storage + (0.2135f * 0.9273f + -0.0879f - 2.1964f * 0.9273f); break;
        case 11: norm_outflow = (norm_storage <= 0.9268f) ? 0.2120f * norm_storage + -0.0868f : 2.3455f * norm_storage + (0.2120f * 0.9268f + -0.0868f - 2.3455f * 0.9268f); break;
        case 12: norm_outflow = (norm_storage <= 0.9058f) ? 0.2369f * norm_storage + -0.0915f : 3.0466f * norm_storage + (0.2369f * 0.9058f + -0.0915f - 3.0466f * 0.9058f); break;
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
        case  1: norm_outflow = (norm_storage <= 0.7798f) ? 0.1510f * norm_storage + -0.0495f : 3.6467f * norm_storage + (0.1510f * 0.7798f + -0.0495f - 3.6467f * 0.7798f); break;
        case  2: norm_outflow = (norm_storage <= 0.7809f) ? 0.1536f * norm_storage + -0.0489f : 3.7698f * norm_storage + (0.1536f * 0.7809f + -0.0489f - 3.7698f * 0.7809f); break;
        case  3: norm_outflow = (norm_storage <= 0.7817f) ? 0.1571f * norm_storage + -0.0511f : 3.4887f * norm_storage + (0.1571f * 0.7817f + -0.0511f - 3.4887f * 0.7817f); break;
        case  4: norm_outflow = (norm_storage <= 0.7865f) ? 0.1903f * norm_storage + -0.0736f : 3.4634f * norm_storage + (0.1903f * 0.7865f + -0.0736f - 3.4634f * 0.7865f); break;
        case  5: norm_outflow = (norm_storage <= 0.8155f) ? 0.2767f * norm_storage + -0.1162f : 5.8104f * norm_storage + (0.2767f * 0.8155f + -0.1162f - 5.8104f * 0.8155f); break;
        case  6: norm_outflow = (norm_storage <= 0.8162f) ? 0.2819f * norm_storage + -0.1138f : 5.8626f * norm_storage + (0.2819f * 0.8162f + -0.1138f - 5.8626f * 0.8162f); break;
        case  7: norm_outflow = (norm_storage <= 0.7848f) ? 0.1838f * norm_storage + -0.0677f : 3.0318f * norm_storage + (0.1838f * 0.7848f + -0.0677f - 3.0318f * 0.7848f); break;
        case  8: norm_outflow = (norm_storage <= 0.7827f) ? 0.1629f * norm_storage + -0.0528f : 3.2496f * norm_storage + (0.1629f * 0.7827f + -0.0528f - 3.2496f * 0.7827f); break;
        case  9: norm_outflow = (norm_storage <= 0.7801f) ? 0.1760f * norm_storage + -0.0643f : 3.0687f * norm_storage + (0.1760f * 0.7801f + -0.0643f - 3.0687f * 0.7801f); break;
        case 10: norm_outflow = (norm_storage <= 0.7790f) ? 0.1592f * norm_storage + -0.0527f : 3.3895f * norm_storage + (0.1592f * 0.7790f + -0.0527f - 3.3895f * 0.7790f); break;
        case 11: norm_outflow = (norm_storage <= 0.7808f) ? 0.1478f * norm_storage + -0.0481f : 3.4699f * norm_storage + (0.1478f * 0.7808f + -0.0481f - 3.4699f * 0.7808f); break;
        case 12: norm_outflow = (norm_storage <= 0.7815f) ? 0.1509f * norm_storage + -0.0490f : 3.5605f * norm_storage + (0.1509f * 0.7815f + -0.0490f - 3.5605f * 0.7815f); break;
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
        case  1: norm_outflow = 2.5916f * norm_inflow + 0.0486f; break;
        case  2: norm_outflow = 2.5849f * norm_inflow + 0.0468f; break;
        case  3: norm_outflow = 2.5910f * norm_inflow + 0.0465f; break;
        case  4: norm_outflow = 2.7596f * norm_inflow + 0.0425f; break;
        case  5: norm_outflow = 2.7882f * norm_inflow + 0.0433f; break;
        case  6: norm_outflow = 2.8995f * norm_inflow + 0.0466f; break;
        case  7: norm_outflow = 2.8798f * norm_inflow + 0.0479f; break;
        case  8: norm_outflow = 2.9718f * norm_inflow + 0.0509f; break;
        case  9: norm_outflow = 2.8512f * norm_inflow + 0.0535f; break;
        case 10: norm_outflow = 2.8663f * norm_inflow + 0.0527f; break;
        case 11: norm_outflow = 2.7976f * norm_inflow + 0.0534f; break;
        case 12: norm_outflow = 2.8402f * norm_inflow + 0.0497f; break;
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
        case  1: norm_outflow = 1.0439f * norm_inflow + 0.0039f; break;
        case  2: norm_outflow = 1.0478f * norm_inflow + 0.0037f; break;
        case  3: norm_outflow = 1.0471f * norm_inflow + 0.0036f; break;
        case  4: norm_outflow = 1.0431f * norm_inflow + 0.0035f; break;
        case  5: norm_outflow = 1.0468f * norm_inflow + 0.0035f; break;
        case  6: norm_outflow = 1.0506f * norm_inflow + 0.0041f; break;
        case  7: norm_outflow = 1.0452f * norm_inflow + 0.0037f; break;
        case  8: norm_outflow = 1.0269f * norm_inflow + 0.0044f; break;
        case  9: norm_outflow = 1.0291f * norm_inflow + 0.0044f; break;
        case 10: norm_outflow = 1.0250f * norm_inflow + 0.0045f; break;
        case 11: norm_outflow = 1.0376f * norm_inflow + 0.0040f; break;
        case 12: norm_outflow = 1.0460f * norm_inflow + 0.0036f; break;
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
        case  1: norm_outflow = 1.0225f * norm_inflow + 0.0059f; break;
        case  2: norm_outflow = 1.0254f * norm_inflow + 0.0058f; break;
        case  3: norm_outflow = 1.0265f * norm_inflow + 0.0053f; break;
        case  4: norm_outflow = 1.0254f * norm_inflow + 0.0052f; break;
        case  5: norm_outflow = 1.0288f * norm_inflow + 0.0053f; break;
        case  6: norm_outflow = 1.0318f * norm_inflow + 0.0062f; break;
        case  7: norm_outflow = 1.0230f * norm_inflow + 0.0057f; break;
        case  8: norm_outflow = 1.0029f * norm_inflow + 0.0057f; break;
        case  9: norm_outflow = 1.0032f * norm_inflow + 0.0058f; break;
        case 10: norm_outflow = 1.0019f * norm_inflow + 0.0059f; break;
        case 11: norm_outflow = 1.0131f * norm_inflow + 0.0054f; break;
        case 12: norm_outflow = 1.0267f * norm_inflow + 0.0050f; break;
    }
    return norm_outflow * max_outflow_m3d;
}

static float rule_874(float inflow_m3d, float storage_m3, int month) {
    const float max_inflow_m3d   = 516685216.2f;
    const float max_outflow_m3d  = 140785895.0f;
    const float max_storage_m3   = 2501491273.0f;
    const float norm_inflow  = inflow_m3d  / max_inflow_m3d;
    const float norm_storage = storage_m3  / max_storage_m3;
    float norm_outflow;

    switch (month) {
        case  1: norm_outflow = (norm_storage <= 0.9498f) ? 0.4119f * norm_storage + -0.1816f : 0.9032f * norm_storage + (0.4119f * 0.9498f + -0.1816f - 0.9032f * 0.9498f); break;
        case  2: norm_outflow = (norm_storage <= 0.9525f) ? 0.4174f * norm_storage + -0.1865f : 1.1065f * norm_storage + (0.4174f * 0.9525f + -0.1865f - 1.1065f * 0.9525f); break;
        case  3: norm_outflow = (norm_storage <= 0.9250f) ? 0.3707f * norm_storage + -0.1740f : 2.7281f * norm_storage + (0.3707f * 0.9250f + -0.1740f - 2.7281f * 0.9250f); break;
        case  4: norm_outflow = (norm_storage <= 0.8862f) ? 0.2507f * norm_storage + -0.1000f : 7.7900f * norm_storage + (0.2507f * 0.8862f + -0.1000f - 7.7900f * 0.8862f); break;
        case  5: norm_outflow = (norm_storage <= 0.8916f) ? 0.2696f * norm_storage + -0.1118f : 7.1022f * norm_storage + (0.2696f * 0.8916f + -0.1118f - 7.1022f * 0.8916f); break;
        case  6: norm_outflow = (norm_storage <= 0.9398f) ? 0.3057f * norm_storage + -0.1249f : 1.3575f * norm_storage + (0.3057f * 0.9398f + -0.1249f - 1.3575f * 0.9398f); break;
        case  7: norm_outflow = (norm_storage <= 0.9400f) ? 0.2602f * norm_storage + -0.1021f : 1.7417f * norm_storage + (0.2602f * 0.9400f + -0.1021f - 1.7417f * 0.9400f); break;
        case  8: norm_outflow = (norm_storage <= 0.9639f) ? 0.2626f * norm_storage + -0.1018f : 0.6770f * norm_storage + (0.2626f * 0.9639f + -0.1018f - 0.6770f * 0.9639f); break;
        case  9: norm_outflow = (norm_storage <= 0.9540f) ? 0.2807f * norm_storage + -0.1164f : 0.5499f * norm_storage + (0.2807f * 0.9540f + -0.1164f - 0.5499f * 0.9540f); break;
        case 10: norm_outflow = (norm_storage <= 0.9397f) ? 0.2752f * norm_storage + -0.1167f : 1.0336f * norm_storage + (0.2752f * 0.9397f + -0.1167f - 1.0336f * 0.9397f); break;
        case 11: norm_outflow = (norm_storage <= 0.9379f) ? 0.3273f * norm_storage + -0.1449f : 1.3434f * norm_storage + (0.3273f * 0.9379f + -0.1449f - 1.3434f * 0.9379f); break;
        case 12: norm_outflow = (norm_storage <= 0.9064f) ? 0.2926f * norm_storage + -0.1273f : 1.2306f * norm_storage + (0.2926f * 0.9064f + -0.1273f - 1.2306f * 0.9064f); break;
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
        case  1: norm_outflow = 0.9412f * norm_inflow + 0.0100f; break;
        case  2: norm_outflow = 0.9441f * norm_inflow + 0.0096f; break;
        case  3: norm_outflow = 0.9335f * norm_inflow + 0.0089f; break;
        case  4: norm_outflow = 0.9274f * norm_inflow + 0.0097f; break;
        case  5: norm_outflow = 0.9600f * norm_inflow + 0.0103f; break;
        case  6: norm_outflow = 0.9639f * norm_inflow + 0.0110f; break;
        case  7: norm_outflow = 0.9539f * norm_inflow + 0.0105f; break;
        case  8: norm_outflow = 0.9366f * norm_inflow + 0.0094f; break;
        case  9: norm_outflow = 0.9315f * norm_inflow + 0.0083f; break;
        case 10: norm_outflow = 0.9229f * norm_inflow + 0.0077f; break;
        case 11: norm_outflow = 0.9314f * norm_inflow + 0.0078f; break;
        case 12: norm_outflow = 0.9360f * norm_inflow + 0.0082f; break;
    }
    return norm_outflow * max_outflow_m3d;
}

static float rule_877(float inflow_m3d, float storage_m3, int month) {
    const float max_inflow_m3d   = 113839743.2f;
    const float max_outflow_m3d  = 65086154.6f;
    const float max_storage_m3   = 1497120932.0f;
    const float norm_inflow  = inflow_m3d  / max_inflow_m3d;
    const float norm_storage = storage_m3  / max_storage_m3;
    float norm_outflow;

    switch (month) {
        case  1: norm_outflow = 1.2605f * norm_inflow + 0.0435f; break;
        case  2: norm_outflow = (norm_storage <= 0.7834f) ? 0.1970f * norm_storage + -0.0202f : 4.2175f * norm_storage + (0.1970f * 0.7834f + -0.0202f - 4.2175f * 0.7834f); break;
        case  3: norm_outflow = 1.2442f * norm_inflow + 0.0388f; break;
        case  4: norm_outflow = (norm_storage <= 0.7982f) ? 0.1830f * norm_storage + -0.0271f : 5.3153f * norm_storage + (0.1830f * 0.7982f + -0.0271f - 5.3153f * 0.7982f); break;
        case  5: norm_outflow = 1.3064f * norm_inflow + 0.0401f; break;
        case  6: norm_outflow = 1.3643f * norm_inflow + 0.0416f; break;
        case  7: norm_outflow = 1.4034f * norm_inflow + 0.0424f; break;
        case  8: norm_outflow = 1.4689f * norm_inflow + 0.0413f; break;
        case  9: norm_outflow = 1.4443f * norm_inflow + 0.0416f; break;
        case 10: norm_outflow = 1.4792f * norm_inflow + 0.0407f; break;
        case 11: norm_outflow = 1.3909f * norm_inflow + 0.0445f; break;
        case 12: norm_outflow = 1.3117f * norm_inflow + 0.0451f; break;
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
        case  1: norm_outflow = 1.4975f * norm_inflow + -0.0020f; break;
        case  2: norm_outflow = 1.4840f * norm_inflow + -0.0034f; break;
        case  3: norm_outflow = 1.4722f * norm_inflow + -0.0037f; break;
        case  4: norm_outflow = 1.4777f * norm_inflow + -0.0044f; break;
        case  5: norm_outflow = 1.5370f * norm_inflow + -0.0036f; break;
        case  6: norm_outflow = 1.6398f * norm_inflow + 0.0001f; break;
        case  7: norm_outflow = 1.6555f * norm_inflow + -0.0000f; break;
        case  8: norm_outflow = 1.7452f * norm_inflow + -0.0012f; break;
        case  9: norm_outflow = 1.7213f * norm_inflow + -0.0006f; break;
        case 10: norm_outflow = 1.7147f * norm_inflow + 0.0004f; break;
        case 11: norm_outflow = 1.7072f * norm_inflow + -0.0012f; break;
        case 12: norm_outflow = 1.5665f * norm_inflow + -0.0000f; break;
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
        case  1: norm_outflow = (norm_storage <= 0.8889f) ? 1.3116f * norm_storage + -0.5321f : 1.1697f * norm_storage + (1.3116f * 0.8889f + -0.5321f - 1.1697f * 0.8889f); break;
        case  2: norm_outflow = (norm_storage <= 0.9004f) ? 1.3528f * norm_storage + -0.5519f : 1.0011f * norm_storage + (1.3528f * 0.9004f + -0.5519f - 1.0011f * 0.9004f); break;
        case  3: norm_outflow = (norm_storage <= 0.9085f) ? 1.3852f * norm_storage + -0.5734f : 0.9239f * norm_storage + (1.3852f * 0.9085f + -0.5734f - 0.9239f * 0.9085f); break;
        case  4: norm_outflow = (norm_storage <= 0.9021f) ? 1.3475f * norm_storage + -0.5690f : 1.0232f * norm_storage + (1.3475f * 0.9021f + -0.5690f - 1.0232f * 0.9021f); break;
        case  5: norm_outflow = (norm_storage <= 0.9023f) ? 1.3614f * norm_storage + -0.5825f : 1.0618f * norm_storage + (1.3614f * 0.9023f + -0.5825f - 1.0618f * 0.9023f); break;
        case  6: norm_outflow = (norm_storage <= 0.8487f) ? 1.0761f * norm_storage + -0.4420f : 1.7145f * norm_storage + (1.0761f * 0.8487f + -0.4420f - 1.7145f * 0.8487f); break;
        case  7: norm_outflow = (norm_storage <= 0.8285f) ? 1.0233f * norm_storage + -0.3997f : 1.9514f * norm_storage + (1.0233f * 0.8285f + -0.3997f - 1.9514f * 0.8285f); break;
        case  8: norm_outflow = (norm_storage <= 0.8053f) ? 0.8547f * norm_storage + -0.3286f : 2.2606f * norm_storage + (0.8547f * 0.8053f + -0.3286f - 2.2606f * 0.8053f); break;
        case  9: norm_outflow = (norm_storage <= 0.8102f) ? 0.8669f * norm_storage + -0.3322f : 2.1508f * norm_storage + (0.8669f * 0.8102f + -0.3322f - 2.1508f * 0.8102f); break;
        case 10: norm_outflow = (norm_storage <= 0.8218f) ? 0.9052f * norm_storage + -0.3415f : 1.9285f * norm_storage + (0.9052f * 0.8218f + -0.3415f - 1.9285f * 0.8218f); break;
        case 11: norm_outflow = (norm_storage <= 0.8242f) ? 0.9384f * norm_storage + -0.3595f : 1.9628f * norm_storage + (0.9384f * 0.8242f + -0.3595f - 1.9628f * 0.8242f); break;
        case 12: norm_outflow = (norm_storage <= 0.8878f) ? 1.2995f * norm_storage + -0.5241f : 1.1815f * norm_storage + (1.2995f * 0.8878f + -0.5241f - 1.1815f * 0.8878f); break;
    }
    return norm_outflow * max_outflow_m3d;
}

static float rule_880(float inflow_m3d, float storage_m3, int month) {
    const float max_inflow_m3d   = 745343886.5f;
    const float max_outflow_m3d  = 665589145.6f;
    const float max_storage_m3   = 2146698019.0f;
    const float norm_inflow  = inflow_m3d  / max_inflow_m3d;
    const float norm_storage = storage_m3  / max_storage_m3;
    float norm_outflow;

    switch (month) {
        case  1: norm_outflow = 0.7411f * norm_inflow + 0.0158f; break;
        case  2: norm_outflow = 0.7427f * norm_inflow + 0.0150f; break;
        case  3: norm_outflow = 0.7870f * norm_inflow + 0.0170f; break;
        case  4: norm_outflow = 0.8055f * norm_inflow + 0.0200f; break;
        case  5: norm_outflow = 0.8536f * norm_inflow + 0.0224f; break;
        case  6: norm_outflow = 0.8627f * norm_inflow + 0.0225f; break;
        case  7: norm_outflow = 0.8720f * norm_inflow + 0.0192f; break;
        case  8: norm_outflow = 0.8650f * norm_inflow + 0.0167f; break;
        case  9: norm_outflow = 0.8362f * norm_inflow + 0.0172f; break;
        case 10: norm_outflow = 0.8374f * norm_inflow + 0.0167f; break;
        case 11: norm_outflow = 0.8065f * norm_inflow + 0.0155f; break;
        case 12: norm_outflow = 0.7288f * norm_inflow + 0.0154f; break;
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
        case  1: norm_outflow = 0.8181f * norm_inflow + 0.0245f; break;
        case  2: norm_outflow = 0.8038f * norm_inflow + 0.0241f; break;
        case  3: norm_outflow = 0.7965f * norm_inflow + 0.0255f; break;
        case  4: norm_outflow = (norm_storage <= 0.8301f) ? 0.2481f * norm_storage + -0.0342f : 2.2780f * norm_storage + (0.2481f * 0.8301f + -0.0342f - 2.2780f * 0.8301f); break;
        case  5: norm_outflow = 0.8506f * norm_inflow + 0.0304f; break;
        case  6: norm_outflow = 0.8720f * norm_inflow + 0.0328f; break;
        case  7: norm_outflow = (norm_storage <= 0.8481f) ? 0.2379f * norm_storage + -0.0133f : 1.8529f * norm_storage + (0.2379f * 0.8481f + -0.0133f - 1.8529f * 0.8481f); break;
        case  8: norm_outflow = 0.8246f * norm_inflow + 0.0273f; break;
        case  9: norm_outflow = 0.7698f * norm_inflow + 0.0262f; break;
        case 10: norm_outflow = 0.7898f * norm_inflow + 0.0226f; break;
        case 11: norm_outflow = (norm_storage <= 0.8236f) ? 0.1751f * norm_storage + -0.0194f : 1.3954f * norm_storage + (0.1751f * 0.8236f + -0.0194f - 1.3954f * 0.8236f); break;
        case 12: norm_outflow = (norm_storage <= 0.8208f) ? 0.1650f * norm_storage + -0.0241f : 1.4875f * norm_storage + (0.1650f * 0.8208f + -0.0241f - 1.4875f * 0.8208f); break;
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
        case  1: norm_outflow = 1.2361f * norm_inflow + 0.0173f; break;
        case  2: norm_outflow = 1.2311f * norm_inflow + 0.0167f; break;
        case  3: norm_outflow = 1.2081f * norm_inflow + 0.0167f; break;
        case  4: norm_outflow = 1.2420f * norm_inflow + 0.0154f; break;
        case  5: norm_outflow = 1.2773f * norm_inflow + 0.0156f; break;
        case  6: norm_outflow = 1.3053f * norm_inflow + 0.0197f; break;
        case  7: norm_outflow = 1.3246f * norm_inflow + 0.0191f; break;
        case  8: norm_outflow = 1.3312f * norm_inflow + 0.0182f; break;
        case  9: norm_outflow = 1.2920f * norm_inflow + 0.0182f; break;
        case 10: norm_outflow = 1.2841f * norm_inflow + 0.0175f; break;
        case 11: norm_outflow = 1.3076f * norm_inflow + 0.0181f; break;
        case 12: norm_outflow = 1.2638f * norm_inflow + 0.0190f; break;
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
        case  1: norm_outflow = 1.0171f * norm_inflow + -0.0003f; break;
        case  2: norm_outflow = 1.0142f * norm_inflow + -0.0003f; break;
        case  3: norm_outflow = 1.0138f * norm_inflow + -0.0003f; break;
        case  4: norm_outflow = 1.0165f * norm_inflow + -0.0002f; break;
        case  5: norm_outflow = 1.0167f * norm_inflow + 0.0000f; break;
        case  6: norm_outflow = 1.0234f * norm_inflow + 0.0004f; break;
        case  7: norm_outflow = 1.0192f * norm_inflow + -0.0003f; break;
        case  8: norm_outflow = 1.0121f * norm_inflow + 0.0003f; break;
        case  9: norm_outflow = 1.0077f * norm_inflow + -0.0000f; break;
        case 10: norm_outflow = 1.0120f * norm_inflow + 0.0010f; break;
        case 11: norm_outflow = 1.0156f * norm_inflow + -0.0003f; break;
        case 12: norm_outflow = 1.0151f * norm_inflow + -0.0001f; break;
    }
    return norm_outflow * max_outflow_m3d;
}

static float rule_887(float inflow_m3d, float storage_m3, int month) {
    const float max_inflow_m3d   = 564840709.0f;
    const float max_outflow_m3d  = 543810674.8f;
    const float max_storage_m3   = 1579337801.0f;
    const float norm_inflow  = inflow_m3d  / max_inflow_m3d;
    const float norm_storage = storage_m3  / max_storage_m3;
    float norm_outflow;

    switch (month) {
        case  1: norm_outflow = 0.9317f * norm_inflow + 0.0183f; break;
        case  2: norm_outflow = 0.9244f * norm_inflow + 0.0184f; break;
        case  3: norm_outflow = (norm_storage <= 0.9773f) ? 0.6775f * norm_storage + -0.1766f : 0.2901f * norm_storage + (0.6775f * 0.9773f + -0.1766f - 0.2901f * 0.9773f); break;
        case  4: norm_outflow = 0.8828f * norm_inflow + 0.0206f; break;
        case  5: norm_outflow = 0.9089f * norm_inflow + 0.0213f; break;
        case  6: norm_outflow = 0.9283f * norm_inflow + 0.0225f; break;
        case  7: norm_outflow = (norm_storage <= 0.9818f) ? 0.6341f * norm_storage + -0.1646f : 0.2585f * norm_storage + (0.6341f * 0.9818f + -0.1646f - 0.2585f * 0.9818f); break;
        case  8: norm_outflow = 0.8946f * norm_inflow + 0.0201f; break;
        case  9: norm_outflow = 0.8825f * norm_inflow + 0.0169f; break;
        case 10: norm_outflow = (norm_storage <= 0.9781f) ? 0.6783f * norm_storage + -0.1788f : 0.2710f * norm_storage + (0.6783f * 0.9781f + -0.1788f - 0.2710f * 0.9781f); break;
        case 11: norm_outflow = (norm_storage <= 0.9858f) ? 0.7438f * norm_storage + -0.2112f : 0.1953f * norm_storage + (0.7438f * 0.9858f + -0.2112f - 0.1953f * 0.9858f); break;
        case 12: norm_outflow = (norm_storage <= 0.9880f) ? 0.8118f * norm_storage + -0.2305f : 0.1942f * norm_storage + (0.8118f * 0.9880f + -0.2305f - 0.1942f * 0.9880f); break;
    }
    return norm_outflow * max_outflow_m3d;
}

static float rule_897(float inflow_m3d, float storage_m3, int month) {
    const float max_inflow_m3d   = 346548356.9f;
    const float max_outflow_m3d  = 85630236.0f;
    const float max_storage_m3   = 1490460756.0f;
    const float norm_inflow  = inflow_m3d  / max_inflow_m3d;
    const float norm_storage = storage_m3  / max_storage_m3;
    float norm_outflow;

    switch (month) {
        case  1: norm_outflow = (norm_storage <= 0.9658f) ? 0.6771f * norm_storage + -0.2878f : 0.2794f * norm_storage + (0.6771f * 0.9658f + -0.2878f - 0.2794f * 0.9658f); break;
        case  2: norm_outflow = (norm_storage <= 0.9628f) ? 0.6557f * norm_storage + -0.2777f : 0.3882f * norm_storage + (0.6557f * 0.9628f + -0.2777f - 0.3882f * 0.9628f); break;
        case  3: norm_outflow = (norm_storage <= 0.9402f) ? 0.5872f * norm_storage + -0.2614f : 0.6347f * norm_storage + (0.5872f * 0.9402f + -0.2614f - 0.6347f * 0.9402f); break;
        case  4: norm_outflow = (norm_storage <= 0.9417f) ? 0.6433f * norm_storage + -0.2888f : 1.2422f * norm_storage + (0.6433f * 0.9417f + -0.2888f - 1.2422f * 0.9417f); break;
        case  5: norm_outflow = (norm_storage <= 0.9343f) ? 0.6631f * norm_storage + -0.3024f : 1.8673f * norm_storage + (0.6631f * 0.9343f + -0.3024f - 1.8673f * 0.9343f); break;
        case  6: norm_outflow = (norm_storage <= 0.9445f) ? 0.6013f * norm_storage + -0.2714f : 1.2114f * norm_storage + (0.6013f * 0.9445f + -0.2714f - 1.2114f * 0.9445f); break;
        case  7: norm_outflow = (norm_storage <= 0.9506f) ? 0.5856f * norm_storage + -0.2514f : 0.6354f * norm_storage + (0.5856f * 0.9506f + -0.2514f - 0.6354f * 0.9506f); break;
        case  8: norm_outflow = (norm_storage <= 0.9516f) ? 0.5597f * norm_storage + -0.2429f : 0.4904f * norm_storage + (0.5597f * 0.9516f + -0.2429f - 0.4904f * 0.9516f); break;
        case  9: norm_outflow = (norm_storage <= 0.9458f) ? 0.5477f * norm_storage + -0.2439f : 0.7162f * norm_storage + (0.5477f * 0.9458f + -0.2439f - 0.7162f * 0.9458f); break;
        case 10: norm_outflow = (norm_storage <= 0.9413f) ? 0.5489f * norm_storage + -0.2437f : 0.7034f * norm_storage + (0.5489f * 0.9413f + -0.2437f - 0.7034f * 0.9413f); break;
        case 11: norm_outflow = (norm_storage <= 0.9286f) ? 0.5714f * norm_storage + -0.2524f : 0.5225f * norm_storage + (0.5714f * 0.9286f + -0.2524f - 0.5225f * 0.9286f); break;
        case 12: norm_outflow = (norm_storage <= 0.9561f) ? 0.6885f * norm_storage + -0.3006f : 0.4239f * norm_storage + (0.6885f * 0.9561f + -0.3006f - 0.4239f * 0.9561f); break;
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
        case  1: norm_outflow = 0.9002f * norm_inflow + 0.0144f; break;
        case  2: norm_outflow = 0.9074f * norm_inflow + 0.0135f; break;
        case  3: norm_outflow = 0.9079f * norm_inflow + 0.0139f; break;
        case  4: norm_outflow = 0.9366f * norm_inflow + 0.0113f; break;
        case  5: norm_outflow = 0.9660f * norm_inflow + 0.0127f; break;
        case  6: norm_outflow = 0.9739f * norm_inflow + 0.0141f; break;
        case  7: norm_outflow = 0.9508f * norm_inflow + 0.0140f; break;
        case  8: norm_outflow = 0.9210f * norm_inflow + 0.0153f; break;
        case  9: norm_outflow = 0.8839f * norm_inflow + 0.0157f; break;
        case 10: norm_outflow = 0.8931f * norm_inflow + 0.0159f; break;
        case 11: norm_outflow = 0.8939f * norm_inflow + 0.0153f; break;
        case 12: norm_outflow = 0.8896f * norm_inflow + 0.0156f; break;
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
        case  1: norm_outflow = 1.2528f * norm_inflow + 0.0194f; break;
        case  2: norm_outflow = 1.2871f * norm_inflow + 0.0143f; break;
        case  3: norm_outflow = 1.2751f * norm_inflow + 0.0132f; break;
        case  4: norm_outflow = 1.3293f * norm_inflow + 0.0074f; break;
        case  5: norm_outflow = 1.3364f * norm_inflow + 0.0107f; break;
        case  6: norm_outflow = 1.3552f * norm_inflow + 0.0154f; break;
        case  7: norm_outflow = 1.3576f * norm_inflow + 0.0167f; break;
        case  8: norm_outflow = 1.4230f * norm_inflow + 0.0198f; break;
        case  9: norm_outflow = 1.3451f * norm_inflow + 0.0218f; break;
        case 10: norm_outflow = 1.3616f * norm_inflow + 0.0237f; break;
        case 11: norm_outflow = 1.3121f * norm_inflow + 0.0225f; break;
        case 12: norm_outflow = 1.2743f * norm_inflow + 0.0217f; break;
    }
    return norm_outflow * max_outflow_m3d;
}

static float rule_905(float inflow_m3d, float storage_m3, int month) {
    const float max_inflow_m3d   = 1055861593.0f;
    const float max_outflow_m3d  = 1065239594.0f;
    const float max_storage_m3   = 630545108.2f;
    const float norm_inflow  = inflow_m3d  / max_inflow_m3d;
    const float norm_storage = storage_m3  / max_storage_m3;
    float norm_outflow;

    switch (month) {
        case  1: norm_outflow = 0.9955f * norm_inflow + 0.0014f; break;
        case  2: norm_outflow = 0.9933f * norm_inflow + 0.0015f; break;
        case  3: norm_outflow = 0.9936f * norm_inflow + 0.0014f; break;
        case  4: norm_outflow = 0.9948f * norm_inflow + 0.0017f; break;
        case  5: norm_outflow = 0.9987f * norm_inflow + 0.0018f; break;
        case  6: norm_outflow = 0.9999f * norm_inflow + 0.0023f; break;
        case  7: norm_outflow = 0.9959f * norm_inflow + 0.0021f; break;
        case  8: norm_outflow = 0.9919f * norm_inflow + 0.0024f; break;
        case  9: norm_outflow = 0.9888f * norm_inflow + 0.0019f; break;
        case 10: norm_outflow = 0.9898f * norm_inflow + 0.0015f; break;
        case 11: norm_outflow = 0.9929f * norm_inflow + 0.0010f; break;
        case 12: norm_outflow = 0.9948f * norm_inflow + 0.0011f; break;
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
        case  1: norm_outflow = 1.2322f * norm_inflow + 0.0271f; break;
        case  2: norm_outflow = 1.2282f * norm_inflow + 0.0254f; break;
        case  3: norm_outflow = 1.2088f * norm_inflow + 0.0236f; break;
        case  4: norm_outflow = 1.2631f * norm_inflow + 0.0215f; break;
        case  5: norm_outflow = 1.3092f * norm_inflow + 0.0228f; break;
        case  6: norm_outflow = 1.3701f * norm_inflow + 0.0241f; break;
        case  7: norm_outflow = 1.4110f * norm_inflow + 0.0236f; break;
        case  8: norm_outflow = 1.4936f * norm_inflow + 0.0242f; break;
        case  9: norm_outflow = 1.3769f * norm_inflow + 0.0262f; break;
        case 10: norm_outflow = 1.4720f * norm_inflow + 0.0302f; break;
        case 11: norm_outflow = 1.3737f * norm_inflow + 0.0293f; break;
        case 12: norm_outflow = 1.2712f * norm_inflow + 0.0291f; break;
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
        case  1: norm_outflow = 1.4840f * norm_inflow + 0.0193f; break;
        case  2: norm_outflow = 1.4650f * norm_inflow + 0.0170f; break;
        case  3: norm_outflow = 1.4681f * norm_inflow + 0.0165f; break;
        case  4: norm_outflow = 1.5224f * norm_inflow + 0.0122f; break;
        case  5: norm_outflow = 1.5617f * norm_inflow + 0.0130f; break;
        case  6: norm_outflow = 1.5863f * norm_inflow + 0.0150f; break;
        case  7: norm_outflow = 1.5955f * norm_inflow + 0.0153f; break;
        case  8: norm_outflow = 1.7034f * norm_inflow + 0.0183f; break;
        case  9: norm_outflow = 1.6491f * norm_inflow + 0.0220f; break;
        case 10: norm_outflow = 1.6399f * norm_inflow + 0.0223f; break;
        case 11: norm_outflow = 1.5265f * norm_inflow + 0.0208f; break;
        case 12: norm_outflow = 1.5187f * norm_inflow + 0.0212f; break;
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
        case  1: norm_outflow = (norm_storage <= 0.9980f) ? 0.6363f * norm_storage + -0.0240f : 0.0106f * norm_storage + (0.6363f * 0.9980f + -0.0240f - 0.0106f * 0.9980f); break;
        case  2: norm_outflow = (norm_storage <= 0.9962f) ? 0.6489f * norm_storage + -0.0266f : 0.0311f * norm_storage + (0.6489f * 0.9962f + -0.0266f - 0.0311f * 0.9962f); break;
        case  3: norm_outflow = (norm_storage <= 0.9967f) ? 0.5205f * norm_storage + -0.0133f : 0.0203f * norm_storage + (0.5205f * 0.9967f + -0.0133f - 0.0203f * 0.9967f); break;
        case  4: norm_outflow = (norm_storage <= 0.9966f) ? 0.5180f * norm_storage + -0.0161f : 0.0155f * norm_storage + (0.5180f * 0.9966f + -0.0161f - 0.0155f * 0.9966f); break;
        case  5: norm_outflow = (norm_storage <= 0.9952f) ? 0.5336f * norm_storage + -0.0268f : 0.0378f * norm_storage + (0.5336f * 0.9952f + -0.0268f - 0.0378f * 0.9952f); break;
        case  6: norm_outflow = (norm_storage <= 0.9957f) ? 0.5950f * norm_storage + -0.0386f : 0.0921f * norm_storage + (0.5950f * 0.9957f + -0.0386f - 0.0921f * 0.9957f); break;
        case  7: norm_outflow = (norm_storage <= 0.9977f) ? 0.7128f * norm_storage + -0.0555f : 0.0199f * norm_storage + (0.7128f * 0.9977f + -0.0555f - 0.0199f * 0.9977f); break;
        case  8: norm_outflow = (norm_storage <= 0.9966f) ? 0.7482f * norm_storage + -0.0648f : 0.0295f * norm_storage + (0.7482f * 0.9966f + -0.0648f - 0.0295f * 0.9966f); break;
        case  9: norm_outflow = (norm_storage <= 0.9976f) ? 0.7080f * norm_storage + -0.0591f : 0.0246f * norm_storage + (0.7080f * 0.9976f + -0.0591f - 0.0246f * 0.9976f); break;
        case 10: norm_outflow = (norm_storage <= 0.9968f) ? 0.6263f * norm_storage + -0.0476f : 0.0298f * norm_storage + (0.6263f * 0.9968f + -0.0476f - 0.0298f * 0.9968f); break;
        case 11: norm_outflow = (norm_storage <= 0.9956f) ? 0.5270f * norm_storage + -0.0223f : 0.0197f * norm_storage + (0.5270f * 0.9956f + -0.0223f - 0.0197f * 0.9956f); break;
        case 12: norm_outflow = (norm_storage <= 0.9974f) ? 0.5424f * norm_storage + -0.0185f : 0.0201f * norm_storage + (0.5424f * 0.9974f + -0.0185f - 0.0201f * 0.9974f); break;
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
        case  1: norm_outflow = 1.6384f * norm_inflow + 0.0217f; break;
        case  2: norm_outflow = 1.5994f * norm_inflow + 0.0205f; break;
        case  3: norm_outflow = 1.5687f * norm_inflow + 0.0194f; break;
        case  4: norm_outflow = 1.5970f * norm_inflow + 0.0182f; break;
        case  5: norm_outflow = 1.6847f * norm_inflow + 0.0220f; break;
        case  6: norm_outflow = 1.6919f * norm_inflow + 0.0226f; break;
        case  7: norm_outflow = 1.7044f * norm_inflow + 0.0240f; break;
        case  8: norm_outflow = 1.7422f * norm_inflow + 0.0270f; break;
        case  9: norm_outflow = 1.6896f * norm_inflow + 0.0280f; break;
        case 10: norm_outflow = 1.7145f * norm_inflow + 0.0294f; break;
        case 11: norm_outflow = 1.7074f * norm_inflow + 0.0272f; break;
        case 12: norm_outflow = 1.6902f * norm_inflow + 0.0244f; break;
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
        case  1: norm_outflow = 0.9975f * norm_inflow + 0.0009f; break;
        case  2: norm_outflow = 1.0015f * norm_inflow + 0.0009f; break;
        case  3: norm_outflow = 0.9994f * norm_inflow + 0.0011f; break;
        case  4: norm_outflow = 1.0014f * norm_inflow + 0.0011f; break;
        case  5: norm_outflow = 1.0011f * norm_inflow + 0.0013f; break;
        case  6: norm_outflow = 1.0035f * norm_inflow + 0.0014f; break;
        case  7: norm_outflow = 1.0030f * norm_inflow + 0.0009f; break;
        case  8: norm_outflow = 0.9972f * norm_inflow + 0.0012f; break;
        case  9: norm_outflow = 0.9970f * norm_inflow + 0.0009f; break;
        case 10: norm_outflow = 0.9945f * norm_inflow + 0.0015f; break;
        case 11: norm_outflow = 0.9959f * norm_inflow + 0.0007f; break;
        case 12: norm_outflow = 1.0002f * norm_inflow + 0.0010f; break;
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
        case  1: norm_outflow = (norm_storage <= 0.9953f) ? 0.5656f * norm_storage + -0.0388f : 0.0576f * norm_storage + (0.5656f * 0.9953f + -0.0388f - 0.0576f * 0.9953f); break;
        case  2: norm_outflow = (norm_storage <= 0.9964f) ? 0.5853f * norm_storage + -0.0441f : 0.0436f * norm_storage + (0.5853f * 0.9964f + -0.0441f - 0.0436f * 0.9964f); break;
        case  3: norm_outflow = (norm_storage <= 0.9973f) ? 0.5432f * norm_storage + -0.0311f : 0.0371f * norm_storage + (0.5432f * 0.9973f + -0.0311f - 0.0371f * 0.9973f); break;
        case  4: norm_outflow = (norm_storage <= 0.9930f) ? 0.5160f * norm_storage + -0.0270f : 0.0659f * norm_storage + (0.5160f * 0.9930f + -0.0270f - 0.0659f * 0.9930f); break;
        case  5: norm_outflow = (norm_storage <= 0.9837f) ? 0.4732f * norm_storage + -0.0216f : 0.3406f * norm_storage + (0.4732f * 0.9837f + -0.0216f - 0.3406f * 0.9837f); break;
        case  6: norm_outflow = (norm_storage <= 0.9947f) ? 0.5063f * norm_storage + -0.0294f : 0.0648f * norm_storage + (0.5063f * 0.9947f + -0.0294f - 0.0648f * 0.9947f); break;
        case  7: norm_outflow = (norm_storage <= 0.9980f) ? 0.5756f * norm_storage + -0.0422f : 0.0319f * norm_storage + (0.5756f * 0.9980f + -0.0422f - 0.0319f * 0.9980f); break;
        case  8: norm_outflow = (norm_storage <= 0.9952f) ? 0.6390f * norm_storage + -0.0586f : 0.0570f * norm_storage + (0.6390f * 0.9952f + -0.0586f - 0.0570f * 0.9952f); break;
        case  9: norm_outflow = (norm_storage <= 0.9964f) ? 0.6276f * norm_storage + -0.0538f : 0.0516f * norm_storage + (0.6276f * 0.9964f + -0.0538f - 0.0516f * 0.9964f); break;
        case 10: norm_outflow = (norm_storage <= 0.9958f) ? 0.6052f * norm_storage + -0.0481f : 0.0619f * norm_storage + (0.6052f * 0.9958f + -0.0481f - 0.0619f * 0.9958f); break;
        case 11: norm_outflow = (norm_storage <= 0.9965f) ? 0.5964f * norm_storage + -0.0424f : 0.0605f * norm_storage + (0.5964f * 0.9965f + -0.0424f - 0.0605f * 0.9965f); break;
        case 12: norm_outflow = (norm_storage <= 0.9970f) ? 0.5837f * norm_storage + -0.0375f : 0.0472f * norm_storage + (0.5837f * 0.9970f + -0.0375f - 0.0472f * 0.9970f); break;
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
        case  1: norm_outflow = (norm_storage <= 0.8533f) ? 0.1057f * norm_storage + -0.0101f : 1.4980f * norm_storage + (0.1057f * 0.8533f + -0.0101f - 1.4980f * 0.8533f); break;
        case  2: norm_outflow = (norm_storage <= 0.8288f) ? 0.1207f * norm_storage + -0.0126f : 1.9683f * norm_storage + (0.1207f * 0.8288f + -0.0126f - 1.9683f * 0.8288f); break;
        case  3: norm_outflow = (norm_storage <= 0.8278f) ? 0.1324f * norm_storage + -0.0086f : 2.4710f * norm_storage + (0.1324f * 0.8278f + -0.0086f - 2.4710f * 0.8278f); break;
        case  4: norm_outflow = (norm_storage <= 0.8315f) ? 0.1362f * norm_storage + -0.0144f : 3.1239f * norm_storage + (0.1362f * 0.8315f + -0.0144f - 3.1239f * 0.8315f); break;
        case  5: norm_outflow = (norm_storage <= 0.8477f) ? 0.2025f * norm_storage + -0.0258f : 3.1314f * norm_storage + (0.2025f * 0.8477f + -0.0258f - 3.1314f * 0.8477f); break;
        case  6: norm_outflow = (norm_storage <= 0.8596f) ? 0.2386f * norm_storage + -0.0339f : 2.8772f * norm_storage + (0.2386f * 0.8596f + -0.0339f - 2.8772f * 0.8596f); break;
        case  7: norm_outflow = (norm_storage <= 0.8685f) ? 0.1399f * norm_storage + 0.0082f : 2.3541f * norm_storage + (0.1399f * 0.8685f + 0.0082f - 2.3541f * 0.8685f); break;
        case  8: norm_outflow = (norm_storage <= 0.8556f) ? 0.1462f * norm_storage + -0.0058f : 3.2918f * norm_storage + (0.1462f * 0.8556f + -0.0058f - 3.2918f * 0.8556f); break;
        case  9: norm_outflow = (norm_storage <= 0.8554f) ? 0.1440f * norm_storage + -0.0049f : 2.7360f * norm_storage + (0.1440f * 0.8554f + -0.0049f - 2.7360f * 0.8554f); break;
        case 10: norm_outflow = (norm_storage <= 0.8524f) ? 0.1241f * norm_storage + -0.0059f : 2.5995f * norm_storage + (0.1241f * 0.8524f + -0.0059f - 2.5995f * 0.8524f); break;
        case 11: norm_outflow = (norm_storage <= 0.8587f) ? 0.1051f * norm_storage + 0.0007f : 1.5052f * norm_storage + (0.1051f * 0.8587f + 0.0007f - 1.5052f * 0.8587f); break;
        case 12: norm_outflow = (norm_storage <= 0.8591f) ? 0.1062f * norm_storage + -0.0072f : 1.2994f * norm_storage + (0.1062f * 0.8591f + -0.0072f - 1.2994f * 0.8591f); break;
    }
    return norm_outflow * max_outflow_m3d;
}

static float rule_923(float inflow_m3d, float storage_m3, int month) {
    const float max_inflow_m3d   = 1042763887.0f;
    const float max_outflow_m3d  = 1041825889.0f;
    const float max_storage_m3   = 398834163.3f;
    const float norm_inflow  = inflow_m3d  / max_inflow_m3d;
    const float norm_storage = storage_m3  / max_storage_m3;
    float norm_outflow;

    switch (month) {
        case  1: norm_outflow = 1.0060f * norm_inflow + 0.0024f; break;
        case  2: norm_outflow = 1.0058f * norm_inflow + 0.0025f; break;
        case  3: norm_outflow = 1.0060f * norm_inflow + 0.0024f; break;
        case  4: norm_outflow = 1.0040f * norm_inflow + 0.0020f; break;
        case  5: norm_outflow = 0.9998f * norm_inflow + 0.0027f; break;
        case  6: norm_outflow = 1.0012f * norm_inflow + 0.0034f; break;
        case  7: norm_outflow = 0.9993f * norm_inflow + 0.0030f; break;
        case  8: norm_outflow = 0.9960f * norm_inflow + 0.0034f; break;
        case  9: norm_outflow = 0.9974f * norm_inflow + 0.0037f; break;
        case 10: norm_outflow = 0.9990f * norm_inflow + 0.0034f; break;
        case 11: norm_outflow = 1.0002f * norm_inflow + 0.0030f; break;
        case 12: norm_outflow = 1.0057f * norm_inflow + 0.0028f; break;
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
        case  1: norm_outflow = 1.0649f * norm_inflow + 0.0218f; break;
        case  2: norm_outflow = 1.0343f * norm_inflow + 0.0200f; break;
        case  3: norm_outflow = 1.0475f * norm_inflow + 0.0183f; break;
        case  4: norm_outflow = 1.1064f * norm_inflow + 0.0166f; break;
        case  5: norm_outflow = 1.1781f * norm_inflow + 0.0160f; break;
        case  6: norm_outflow = (norm_storage <= 0.9205f) ? 1.0732f * norm_storage + -0.2976f : 0.4078f * norm_storage + (1.0732f * 0.9205f + -0.2976f - 0.4078f * 0.9205f); break;
        case  7: norm_outflow = 1.1589f * norm_inflow + 0.0174f; break;
        case  8: norm_outflow = 1.1698f * norm_inflow + 0.0168f; break;
        case  9: norm_outflow = 1.1378f * norm_inflow + 0.0199f; break;
        case 10: norm_outflow = 1.1874f * norm_inflow + 0.0227f; break;
        case 11: norm_outflow = 1.1112f * norm_inflow + 0.0244f; break;
        case 12: norm_outflow = (norm_storage <= 0.9121f) ? 0.8204f * norm_storage + -0.1443f : 0.4679f * norm_storage + (0.8204f * 0.9121f + -0.1443f - 0.4679f * 0.9121f); break;
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
        case  1: norm_outflow = (norm_storage <= 0.7361f) ? 0.1137f * norm_storage + -0.0300f : 4.8961f * norm_storage + (0.1137f * 0.7361f + -0.0300f - 4.8961f * 0.7361f); break;
        case  2: norm_outflow = (norm_storage <= 0.7414f) ? 0.1241f * norm_storage + -0.0376f : 4.5211f * norm_storage + (0.1241f * 0.7414f + -0.0376f - 4.5211f * 0.7414f); break;
        case  3: norm_outflow = (norm_storage <= 0.7292f) ? 0.1202f * norm_storage + -0.0358f : 4.4002f * norm_storage + (0.1202f * 0.7292f + -0.0358f - 4.4002f * 0.7292f); break;
        case  4: norm_outflow = (norm_storage <= 0.7273f) ? 0.1316f * norm_storage + -0.0417f : 5.4944f * norm_storage + (0.1316f * 0.7273f + -0.0417f - 5.4944f * 0.7273f); break;
        case  5: norm_outflow = (norm_storage <= 0.7677f) ? 0.1773f * norm_storage + -0.0551f : 29.0850f * norm_storage + (0.1773f * 0.7677f + -0.0551f - 29.0850f * 0.7677f); break;
        case  6: norm_outflow = (norm_storage <= 0.7603f) ? 0.1678f * norm_storage + -0.0443f : 22.2849f * norm_storage + (0.1678f * 0.7603f + -0.0443f - 22.2849f * 0.7603f); break;
        case  7: norm_outflow = (norm_storage <= 0.7337f) ? 0.1060f * norm_storage + -0.0079f : 4.9067f * norm_storage + (0.1060f * 0.7337f + -0.0079f - 4.9067f * 0.7337f); break;
        case  8: norm_outflow = (norm_storage <= 0.7261f) ? 0.1110f * norm_storage + -0.0145f : 3.4029f * norm_storage + (0.1110f * 0.7261f + -0.0145f - 3.4029f * 0.7261f); break;
        case  9: norm_outflow = (norm_storage <= 0.7280f) ? 0.1101f * norm_storage + -0.0158f : 3.0418f * norm_storage + (0.1101f * 0.7280f + -0.0158f - 3.0418f * 0.7280f); break;
        case 10: norm_outflow = (norm_storage <= 0.7294f) ? 0.1132f * norm_storage + -0.0193f : 3.0983f * norm_storage + (0.1132f * 0.7294f + -0.0193f - 3.0983f * 0.7294f); break;
        case 11: norm_outflow = (norm_storage <= 0.7307f) ? 0.0998f * norm_storage + -0.0160f : 2.7554f * norm_storage + (0.0998f * 0.7307f + -0.0160f - 2.7554f * 0.7307f); break;
        case 12: norm_outflow = (norm_storage <= 0.7340f) ? 0.0997f * norm_storage + -0.0170f : 3.0871f * norm_storage + (0.0997f * 0.7340f + -0.0170f - 3.0871f * 0.7340f); break;
    }
    return norm_outflow * max_outflow_m3d;
}

static float rule_939(float inflow_m3d, float storage_m3, int month) {
    const float max_inflow_m3d   = 173393719.5f;
    const float max_outflow_m3d  = 22097455.8f;
    const float max_storage_m3   = 1082519317.0f;
    const float norm_inflow  = inflow_m3d  / max_inflow_m3d;
    const float norm_storage = storage_m3  / max_storage_m3;
    float norm_outflow;

    switch (month) {
        case  1: norm_outflow = (norm_storage <= 0.8169f) ? 0.4421f * norm_storage + -0.2320f : 3.4638f * norm_storage + (0.4421f * 0.8169f + -0.2320f - 3.4638f * 0.8169f); break;
        case  2: norm_outflow = (norm_storage <= 0.8197f) ? 0.4670f * norm_storage + -0.2567f : 3.4707f * norm_storage + (0.4670f * 0.8197f + -0.2567f - 3.4707f * 0.8197f); break;
        case  3: norm_outflow = (norm_storage <= 0.8550f) ? 0.7366f * norm_storage + -0.4450f : 3.4882f * norm_storage + (0.7366f * 0.8550f + -0.4450f - 3.4882f * 0.8550f); break;
        case  4: norm_outflow = (norm_storage <= 0.8562f) ? 0.7318f * norm_storage + -0.4489f : 4.1792f * norm_storage + (0.7318f * 0.8562f + -0.4489f - 4.1792f * 0.8562f); break;
        case  5: norm_outflow = (norm_storage <= 0.8733f) ? 0.9208f * norm_storage + -0.5774f : 3.6406f * norm_storage + (0.9208f * 0.8733f + -0.5774f - 3.6406f * 0.8733f); break;
        case  6: norm_outflow = (norm_storage <= 0.8260f) ? 0.4179f * norm_storage + -0.2208f : 4.4904f * norm_storage + (0.4179f * 0.8260f + -0.2208f - 4.4904f * 0.8260f); break;
        case  7: norm_outflow = (norm_storage <= 0.8264f) ? 0.3979f * norm_storage + -0.2086f : 4.4183f * norm_storage + (0.3979f * 0.8264f + -0.2086f - 4.4183f * 0.8264f); break;
        case  8: norm_outflow = 1.1494f * norm_inflow + 0.0412f; break;
        case  9: norm_outflow = (norm_storage <= 0.8176f) ? 0.3091f * norm_storage + -0.1487f : 4.4780f * norm_storage + (0.3091f * 0.8176f + -0.1487f - 4.4780f * 0.8176f); break;
        case 10: norm_outflow = (norm_storage <= 0.8221f) ? 0.3710f * norm_storage + -0.1891f : 5.5478f * norm_storage + (0.3710f * 0.8221f + -0.1891f - 5.5478f * 0.8221f); break;
        case 11: norm_outflow = (norm_storage <= 0.8321f) ? 0.4608f * norm_storage + -0.2411f : 3.5834f * norm_storage + (0.4608f * 0.8321f + -0.2411f - 3.5834f * 0.8321f); break;
        case 12: norm_outflow = (norm_storage <= 0.8324f) ? 0.5692f * norm_storage + -0.3197f : 3.8701f * norm_storage + (0.5692f * 0.8324f + -0.3197f - 3.8701f * 0.8324f); break;
    }
    return norm_outflow * max_outflow_m3d;
}

static float rule_944(float inflow_m3d, float storage_m3, int month) {
    const float max_inflow_m3d   = 173393719.5f;
    const float max_outflow_m3d  = 22097455.8f;
    const float max_storage_m3   = 1082519317.0f;
    const float norm_inflow  = inflow_m3d  / max_inflow_m3d;
    const float norm_storage = storage_m3  / max_storage_m3;
    float norm_outflow;

    switch (month) {
        case  1: norm_outflow = (norm_storage <= 0.8404f) ? 0.5229f * norm_storage + -0.2527f : 2.9634f * norm_storage + (0.5229f * 0.8404f + -0.2527f - 2.9634f * 0.8404f); break;
        case  2: norm_outflow = (norm_storage <= 0.8368f) ? 0.5208f * norm_storage + -0.2545f : 3.0385f * norm_storage + (0.5208f * 0.8368f + -0.2545f - 3.0385f * 0.8368f); break;
        case  3: norm_outflow = (norm_storage <= 0.8678f) ? 0.7734f * norm_storage + -0.4207f : 2.6873f * norm_storage + (0.7734f * 0.8678f + -0.4207f - 2.6873f * 0.8678f); break;
        case  4: norm_outflow = (norm_storage <= 0.8627f) ? 0.7854f * norm_storage + -0.4365f : 2.9987f * norm_storage + (0.7854f * 0.8627f + -0.4365f - 2.9987f * 0.8627f); break;
        case  5: norm_outflow = (norm_storage <= 0.8788f) ? 0.9473f * norm_storage + -0.5411f : 2.6447f * norm_storage + (0.9473f * 0.8788f + -0.5411f - 2.6447f * 0.8788f); break;
        case  6: norm_outflow = (norm_storage <= 0.8407f) ? 0.5394f * norm_storage + -0.2518f : 3.7030f * norm_storage + (0.5394f * 0.8407f + -0.2518f - 3.7030f * 0.8407f); break;
        case  7: norm_outflow = (norm_storage <= 0.8503f) ? 0.6064f * norm_storage + -0.2951f : 3.4672f * norm_storage + (0.6064f * 0.8503f + -0.2951f - 3.4672f * 0.8503f); break;
        case  8: norm_outflow = 0.9624f * norm_inflow + 0.0379f; break;
        case  9: norm_outflow = (norm_storage <= 0.8367f) ? 0.4309f * norm_storage + -0.1935f : 3.6696f * norm_storage + (0.4309f * 0.8367f + -0.1935f - 3.6696f * 0.8367f); break;
        case 10: norm_outflow = (norm_storage <= 0.8408f) ? 0.4690f * norm_storage + -0.2142f : 4.5028f * norm_storage + (0.4690f * 0.8408f + -0.2142f - 4.5028f * 0.8408f); break;
        case 11: norm_outflow = (norm_storage <= 0.8515f) ? 0.5717f * norm_storage + -0.2733f : 3.0595f * norm_storage + (0.5717f * 0.8515f + -0.2733f - 3.0595f * 0.8515f); break;
        case 12: norm_outflow = (norm_storage <= 0.8465f) ? 0.6106f * norm_storage + -0.3154f : 2.9763f * norm_storage + (0.6106f * 0.8465f + -0.3154f - 2.9763f * 0.8465f); break;
    }
    return norm_outflow * max_outflow_m3d;
}

static float rule_945(float inflow_m3d, float storage_m3, int month) {
    const float max_inflow_m3d   = 197194510.5f;
    const float max_outflow_m3d  = 73118436.0f;
    const float max_storage_m3   = 1695240639.0f;
    const float norm_inflow  = inflow_m3d  / max_inflow_m3d;
    const float norm_storage = storage_m3  / max_storage_m3;
    float norm_outflow;

    switch (month) {
        case  1: norm_outflow = (norm_storage <= 0.8811f) ? 0.4042f * norm_storage + -0.1788f : 0.9388f * norm_storage + (0.4042f * 0.8811f + -0.1788f - 0.9388f * 0.8811f); break;
        case  2: norm_outflow = (norm_storage <= 0.8731f) ? 0.3828f * norm_storage + -0.1756f : 0.9353f * norm_storage + (0.3828f * 0.8731f + -0.1756f - 0.9353f * 0.8731f); break;
        case  3: norm_outflow = (norm_storage <= 0.8784f) ? 0.4411f * norm_storage + -0.2166f : 1.1491f * norm_storage + (0.4411f * 0.8784f + -0.2166f - 1.1491f * 0.8784f); break;
        case  4: norm_outflow = (norm_storage <= 0.8904f) ? 0.5145f * norm_storage + -0.2627f : 1.4666f * norm_storage + (0.5145f * 0.8904f + -0.2627f - 1.4666f * 0.8904f); break;
        case  5: norm_outflow = (norm_storage <= 0.8966f) ? 0.5842f * norm_storage + -0.3105f : 1.3636f * norm_storage + (0.5842f * 0.8966f + -0.3105f - 1.3636f * 0.8966f); break;
        case  6: norm_outflow = (norm_storage <= 0.8873f) ? 0.4601f * norm_storage + -0.2145f : 1.3300f * norm_storage + (0.4601f * 0.8873f + -0.2145f - 1.3300f * 0.8873f); break;
        case  7: norm_outflow = (norm_storage <= 0.8685f) ? 0.3825f * norm_storage + -0.1796f : 1.4263f * norm_storage + (0.3825f * 0.8685f + -0.1796f - 1.4263f * 0.8685f); break;
        case  8: norm_outflow = (norm_storage <= 0.9092f) ? 0.3889f * norm_storage + -0.1590f : 0.6708f * norm_storage + (0.3889f * 0.9092f + -0.1590f - 0.6708f * 0.9092f); break;
        case  9: norm_outflow = (norm_storage <= 0.8887f) ? 0.3503f * norm_storage + -0.1610f : 1.0226f * norm_storage + (0.3503f * 0.8887f + -0.1610f - 1.0226f * 0.8887f); break;
        case 10: norm_outflow = (norm_storage <= 0.8475f) ? 0.3122f * norm_storage + -0.1386f : 2.0294f * norm_storage + (0.3122f * 0.8475f + -0.1386f - 2.0294f * 0.8475f); break;
        case 11: norm_outflow = (norm_storage <= 0.8484f) ? 0.3365f * norm_storage + -0.1576f : 1.0220f * norm_storage + (0.3365f * 0.8484f + -0.1576f - 1.0220f * 0.8484f); break;
        case 12: norm_outflow = (norm_storage <= 0.8507f) ? 0.3914f * norm_storage + -0.1848f : 1.2731f * norm_storage + (0.3914f * 0.8507f + -0.1848f - 1.2731f * 0.8507f); break;
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
        case  1: norm_outflow = (norm_storage <= 0.9848f) ? 0.9186f * norm_storage + -0.0885f : 0.0941f * norm_storage + (0.9186f * 0.9848f + -0.0885f - 0.0941f * 0.9848f); break;
        case  2: norm_outflow = (norm_storage <= 0.9843f) ? 0.9291f * norm_storage + -0.0909f : 0.1153f * norm_storage + (0.9291f * 0.9843f + -0.0909f - 0.1153f * 0.9843f); break;
        case  3: norm_outflow = (norm_storage <= 0.9820f) ? 0.8896f * norm_storage + -0.0733f : 0.1440f * norm_storage + (0.8896f * 0.9820f + -0.0733f - 0.1440f * 0.9820f); break;
        case  4: norm_outflow = (norm_storage <= 0.9764f) ? 0.8397f * norm_storage + -0.0711f : 0.3608f * norm_storage + (0.8397f * 0.9764f + -0.0711f - 0.3608f * 0.9764f); break;
        case  5: norm_outflow = (norm_storage <= 0.9708f) ? 0.8036f * norm_storage + -0.0897f : 0.3650f * norm_storage + (0.8036f * 0.9708f + -0.0897f - 0.3650f * 0.9708f); break;
        case  6: norm_outflow = (norm_storage <= 0.9744f) ? 0.8841f * norm_storage + -0.1169f : 0.4400f * norm_storage + (0.8841f * 0.9744f + -0.1169f - 0.4400f * 0.9744f); break;
        case  7: norm_outflow = (norm_storage <= 0.9827f) ? 0.9489f * norm_storage + -0.1114f : 0.1233f * norm_storage + (0.9489f * 0.9827f + -0.1114f - 0.1233f * 0.9827f); break;
        case  8: norm_outflow = (norm_storage <= 0.9819f) ? 0.8933f * norm_storage + -0.1092f : 0.1330f * norm_storage + (0.8933f * 0.9819f + -0.1092f - 0.1330f * 0.9819f); break;
        case  9: norm_outflow = (norm_storage <= 0.9793f) ? 0.9122f * norm_storage + -0.0920f : 0.1516f * norm_storage + (0.9122f * 0.9793f + -0.0920f - 0.1516f * 0.9793f); break;
        case 10: norm_outflow = (norm_storage <= 0.9757f) ? 0.8704f * norm_storage + -0.0813f : 0.3278f * norm_storage + (0.8704f * 0.9757f + -0.0813f - 0.3278f * 0.9757f); break;
        case 11: norm_outflow = (norm_storage <= 0.9804f) ? 0.9543f * norm_storage + -0.0880f : 0.1190f * norm_storage + (0.9543f * 0.9804f + -0.0880f - 0.1190f * 0.9804f); break;
        case 12: norm_outflow = (norm_storage <= 0.9808f) ? 0.8860f * norm_storage + -0.0680f : 0.1350f * norm_storage + (0.8860f * 0.9808f + -0.0680f - 0.1350f * 0.9808f); break;
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
        case  1: norm_outflow = (norm_storage <= 0.9968f) ? 0.5773f * norm_storage + -0.0618f : 0.0719f * norm_storage + (0.5773f * 0.9968f + -0.0618f - 0.0719f * 0.9968f); break;
        case  2: norm_outflow = (norm_storage <= 0.9975f) ? 0.6044f * norm_storage + -0.0668f : 0.0639f * norm_storage + (0.6044f * 0.9975f + -0.0668f - 0.0639f * 0.9975f); break;
        case  3: norm_outflow = (norm_storage <= 0.9948f) ? 0.5788f * norm_storage + -0.0564f : 0.1022f * norm_storage + (0.5788f * 0.9948f + -0.0564f - 0.1022f * 0.9948f); break;
        case  4: norm_outflow = (norm_storage <= 0.9945f) ? 0.5789f * norm_storage + -0.0606f : 0.1040f * norm_storage + (0.5789f * 0.9945f + -0.0606f - 0.1040f * 0.9945f); break;
        case  5: norm_outflow = (norm_storage <= 0.9611f) ? 0.4859f * norm_storage + -0.0527f : 0.8664f * norm_storage + (0.4859f * 0.9611f + -0.0527f - 0.8664f * 0.9611f); break;
        case  6: norm_outflow = (norm_storage <= 0.9921f) ? 0.5740f * norm_storage + -0.0744f : 0.1722f * norm_storage + (0.5740f * 0.9921f + -0.0744f - 0.1722f * 0.9921f); break;
        case  7: norm_outflow = (norm_storage <= 0.9927f) ? 0.5517f * norm_storage + -0.0721f : 0.1106f * norm_storage + (0.5517f * 0.9927f + -0.0721f - 0.1106f * 0.9927f); break;
        case  8: norm_outflow = (norm_storage <= 0.9924f) ? 0.5889f * norm_storage + -0.0783f : 0.0898f * norm_storage + (0.5889f * 0.9924f + -0.0783f - 0.0898f * 0.9924f); break;
        case  9: norm_outflow = (norm_storage <= 0.9938f) ? 0.5818f * norm_storage + -0.0680f : 0.0839f * norm_storage + (0.5818f * 0.9938f + -0.0680f - 0.0839f * 0.9938f); break;
        case 10: norm_outflow = (norm_storage <= 0.9900f) ? 0.5408f * norm_storage + -0.0557f : 0.1662f * norm_storage + (0.5408f * 0.9900f + -0.0557f - 0.1662f * 0.9900f); break;
        case 11: norm_outflow = (norm_storage <= 0.9940f) ? 0.5621f * norm_storage + -0.0586f : 0.1068f * norm_storage + (0.5621f * 0.9940f + -0.0586f - 0.1068f * 0.9940f); break;
        case 12: norm_outflow = (norm_storage <= 0.9944f) ? 0.5666f * norm_storage + -0.0566f : 0.1108f * norm_storage + (0.5666f * 0.9944f + -0.0566f - 0.1108f * 0.9944f); break;
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
        case  1: norm_outflow = (norm_storage <= 0.7108f) ? 0.1957f * norm_storage + -0.0652f : 1.3877f * norm_storage + (0.1957f * 0.7108f + -0.0652f - 1.3877f * 0.7108f); break;
        case  2: norm_outflow = (norm_storage <= 0.7187f) ? 0.2164f * norm_storage + -0.0737f : 1.3510f * norm_storage + (0.2164f * 0.7187f + -0.0737f - 1.3510f * 0.7187f); break;
        case  3: norm_outflow = (norm_storage <= 0.7105f) ? 0.2048f * norm_storage + -0.0699f : 1.4625f * norm_storage + (0.2048f * 0.7105f + -0.0699f - 1.4625f * 0.7105f); break;
        case  4: norm_outflow = (norm_storage <= 0.7148f) ? 0.2135f * norm_storage + -0.0733f : 1.4922f * norm_storage + (0.2135f * 0.7148f + -0.0733f - 1.4922f * 0.7148f); break;
        case  5: norm_outflow = (norm_storage <= 0.7474f) ? 0.2694f * norm_storage + -0.1077f : 2.8802f * norm_storage + (0.2694f * 0.7474f + -0.1077f - 2.8802f * 0.7474f); break;
        case  6: norm_outflow = (norm_storage <= 0.7400f) ? 0.2724f * norm_storage + -0.0957f : 2.1318f * norm_storage + (0.2724f * 0.7400f + -0.0957f - 2.1318f * 0.7400f); break;
        case  7: norm_outflow = (norm_storage <= 0.7118f) ? 0.1982f * norm_storage + -0.0590f : 1.6473f * norm_storage + (0.1982f * 0.7118f + -0.0590f - 1.6473f * 0.7118f); break;
        case  8: norm_outflow = (norm_storage <= 0.7185f) ? 0.2057f * norm_storage + -0.0641f : 1.3866f * norm_storage + (0.2057f * 0.7185f + -0.0641f - 1.3866f * 0.7185f); break;
        case  9: norm_outflow = (norm_storage <= 0.7082f) ? 0.1859f * norm_storage + -0.0558f : 1.6375f * norm_storage + (0.1859f * 0.7082f + -0.0558f - 1.6375f * 0.7082f); break;
        case 10: norm_outflow = (norm_storage <= 0.7272f) ? 0.2258f * norm_storage + -0.0764f : 2.5596f * norm_storage + (0.2258f * 0.7272f + -0.0764f - 2.5596f * 0.7272f); break;
        case 11: norm_outflow = (norm_storage <= 0.6963f) ? 0.1722f * norm_storage + -0.0527f : 1.5552f * norm_storage + (0.1722f * 0.6963f + -0.0527f - 1.5552f * 0.6963f); break;
        case 12: norm_outflow = (norm_storage <= 0.7022f) ? 0.1918f * norm_storage + -0.0599f : 1.6497f * norm_storage + (0.1918f * 0.7022f + -0.0599f - 1.6497f * 0.7022f); break;
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
        case  1: norm_outflow = 0.5780f * norm_inflow + 0.0126f; break;
        case  2: norm_outflow = 0.6167f * norm_inflow + 0.0130f; break;
        case  3: norm_outflow = (norm_storage <= 0.8281f) ? 0.1616f * norm_storage + -0.0615f : 4.5904f * norm_storage + (0.1616f * 0.8281f + -0.0615f - 4.5904f * 0.8281f); break;
        case  4: norm_outflow = (norm_storage <= 0.8308f) ? 0.1719f * norm_storage + -0.0660f : 4.6762f * norm_storage + (0.1719f * 0.8308f + -0.0660f - 4.6762f * 0.8308f); break;
        case  5: norm_outflow = (norm_storage <= 0.8399f) ? 0.2052f * norm_storage + -0.0906f : 4.7577f * norm_storage + (0.2052f * 0.8399f + -0.0906f - 4.7577f * 0.8399f); break;
        case  6: norm_outflow = (norm_storage <= 0.8415f) ? 0.2269f * norm_storage + -0.1018f : 4.6810f * norm_storage + (0.2269f * 0.8415f + -0.1018f - 4.6810f * 0.8415f); break;
        case  7: norm_outflow = (norm_storage <= 0.8269f) ? 0.1767f * norm_storage + -0.0685f : 4.5372f * norm_storage + (0.1767f * 0.8269f + -0.0685f - 4.5372f * 0.8269f); break;
        case  8: norm_outflow = 0.6624f * norm_inflow + 0.0162f; break;
        case  9: norm_outflow = 0.6358f * norm_inflow + 0.0159f; break;
        case 10: norm_outflow = 0.5926f * norm_inflow + 0.0162f; break;
        case 11: norm_outflow = 0.5692f * norm_inflow + 0.0125f; break;
        case 12: norm_outflow = 0.5967f * norm_inflow + 0.0127f; break;
    }
    return norm_outflow * max_outflow_m3d;
}

static float rule_956(float inflow_m3d, float storage_m3, int month) {
    const float max_inflow_m3d   = 208273334.3f;
    const float max_outflow_m3d  = 145630118.7f;
    const float max_storage_m3   = 1839842733.0f;
    const float norm_inflow  = inflow_m3d  / max_inflow_m3d;
    const float norm_storage = storage_m3  / max_storage_m3;
    float norm_outflow;

    switch (month) {
        case  1: norm_outflow = 1.0332f * norm_inflow + 0.0269f; break;
        case  2: norm_outflow = 1.0271f * norm_inflow + 0.0277f; break;
        case  3: norm_outflow = 1.0294f * norm_inflow + 0.0264f; break;
        case  4: norm_outflow = 1.0467f * norm_inflow + 0.0265f; break;
        case  5: norm_outflow = 1.0412f * norm_inflow + 0.0273f; break;
        case  6: norm_outflow = 1.0615f * norm_inflow + 0.0285f; break;
        case  7: norm_outflow = 1.0821f * norm_inflow + 0.0268f; break;
        case  8: norm_outflow = 1.0958f * norm_inflow + 0.0249f; break;
        case  9: norm_outflow = 1.0492f * norm_inflow + 0.0258f; break;
        case 10: norm_outflow = 1.0704f * norm_inflow + 0.0283f; break;
        case 11: norm_outflow = 1.0504f * norm_inflow + 0.0300f; break;
        case 12: norm_outflow = 1.0189f * norm_inflow + 0.0292f; break;
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
        case  1: norm_outflow = 0.7573f * norm_inflow + 0.0102f; break;
        case  2: norm_outflow = 0.7877f * norm_inflow + 0.0100f; break;
        case  3: norm_outflow = 0.8682f * norm_inflow + 0.0132f; break;
        case  4: norm_outflow = 0.8674f * norm_inflow + 0.0145f; break;
        case  5: norm_outflow = 0.8734f * norm_inflow + 0.0183f; break;
        case  6: norm_outflow = 0.8681f * norm_inflow + 0.0185f; break;
        case  7: norm_outflow = 0.7748f * norm_inflow + 0.0168f; break;
        case  8: norm_outflow = 0.7201f * norm_inflow + 0.0160f; break;
        case  9: norm_outflow = 0.7136f * norm_inflow + 0.0167f; break;
        case 10: norm_outflow = 0.6912f * norm_inflow + 0.0132f; break;
        case 11: norm_outflow = 0.7263f * norm_inflow + 0.0097f; break;
        case 12: norm_outflow = 0.7591f * norm_inflow + 0.0098f; break;
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
        case  1: norm_outflow = 0.9958f * norm_inflow + 0.0146f; break;
        case  2: norm_outflow = 1.0292f * norm_inflow + 0.0157f; break;
        case  3: norm_outflow = 1.0364f * norm_inflow + 0.0156f; break;
        case  4: norm_outflow = 1.0321f * norm_inflow + 0.0164f; break;
        case  5: norm_outflow = 1.0245f * norm_inflow + 0.0176f; break;
        case  6: norm_outflow = 1.0089f * norm_inflow + 0.0182f; break;
        case  7: norm_outflow = 0.9907f * norm_inflow + 0.0182f; break;
        case  8: norm_outflow = 0.9598f * norm_inflow + 0.0170f; break;
        case  9: norm_outflow = 0.9271f * norm_inflow + 0.0152f; break;
        case 10: norm_outflow = 0.9828f * norm_inflow + 0.0167f; break;
        case 11: norm_outflow = 0.9897f * norm_inflow + 0.0153f; break;
        case 12: norm_outflow = 1.0308f * norm_inflow + 0.0155f; break;
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
        case  1: norm_outflow = (norm_storage <= 0.9815f) ? 0.5552f * norm_storage + -0.1646f : 0.1122f * norm_storage + (0.5552f * 0.9815f + -0.1646f - 0.1122f * 0.9815f); break;
        case  2: norm_outflow = (norm_storage <= 0.9807f) ? 0.5688f * norm_storage + -0.1699f : 0.1122f * norm_storage + (0.5688f * 0.9807f + -0.1699f - 0.1122f * 0.9807f); break;
        case  3: norm_outflow = (norm_storage <= 0.9685f) ? 0.5324f * norm_storage + -0.1557f : 1.2322f * norm_storage + (0.5324f * 0.9685f + -0.1557f - 1.2322f * 0.9685f); break;
        case  4: norm_outflow = (norm_storage <= 0.9816f) ? 0.5617f * norm_storage + -0.1685f : 0.1109f * norm_storage + (0.5617f * 0.9816f + -0.1685f - 0.1109f * 0.9816f); break;
        case  5: norm_outflow = (norm_storage <= 0.9720f) ? 0.5418f * norm_storage + -0.1595f : 1.7093f * norm_storage + (0.5418f * 0.9720f + -0.1595f - 1.7093f * 0.9720f); break;
        case  6: norm_outflow = (norm_storage <= 0.9677f) ? 0.5448f * norm_storage + -0.1667f : 0.5524f * norm_storage + (0.5448f * 0.9677f + -0.1667f - 0.5524f * 0.9677f); break;
        case  7: norm_outflow = (norm_storage <= 0.9675f) ? 0.5054f * norm_storage + -0.1465f : 0.1550f * norm_storage + (0.5054f * 0.9675f + -0.1465f - 0.1550f * 0.9675f); break;
        case  8: norm_outflow = (norm_storage <= 0.9661f) ? 0.4727f * norm_storage + -0.1364f : 0.1581f * norm_storage + (0.4727f * 0.9661f + -0.1364f - 0.1581f * 0.9661f); break;
        case  9: norm_outflow = (norm_storage <= 0.9659f) ? 0.5006f * norm_storage + -0.1468f : 0.2119f * norm_storage + (0.5006f * 0.9659f + -0.1468f - 0.2119f * 0.9659f); break;
        case 10: norm_outflow = (norm_storage <= 0.9669f) ? 0.4733f * norm_storage + -0.1368f : 0.6078f * norm_storage + (0.4733f * 0.9669f + -0.1368f - 0.6078f * 0.9669f); break;
        case 11: norm_outflow = (norm_storage <= 0.9707f) ? 0.4977f * norm_storage + -0.1441f : 0.2177f * norm_storage + (0.4977f * 0.9707f + -0.1441f - 0.2177f * 0.9707f); break;
        case 12: norm_outflow = (norm_storage <= 0.9716f) ? 0.5003f * norm_storage + -0.1424f : 0.5196f * norm_storage + (0.5003f * 0.9716f + -0.1424f - 0.5196f * 0.9716f); break;
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
        case  1: norm_outflow = (norm_storage <= 0.9873f) ? 1.5658f * norm_storage + -0.6152f : 0.8883f * norm_storage + (1.5658f * 0.9873f + -0.6152f - 0.8883f * 0.9873f); break;
        case  2: norm_outflow = 1.1194f * norm_inflow + 0.0289f; break;
        case  3: norm_outflow = (norm_storage <= 0.9867f) ? 1.5760f * norm_storage + -0.6167f : 0.2525f * norm_storage + (1.5760f * 0.9867f + -0.6167f - 0.2525f * 0.9867f); break;
        case  4: norm_outflow = (norm_storage <= 0.9861f) ? 1.5649f * norm_storage + -0.6147f : 0.2721f * norm_storage + (1.5649f * 0.9861f + -0.6147f - 0.2721f * 0.9861f); break;
        case  5: norm_outflow = (norm_storage <= 0.9848f) ? 1.5794f * norm_storage + -0.6544f : 0.2738f * norm_storage + (1.5794f * 0.9848f + -0.6544f - 0.2738f * 0.9848f); break;
        case  6: norm_outflow = 1.1334f * norm_inflow + 0.0277f; break;
        case  7: norm_outflow = 1.1214f * norm_inflow + 0.0242f; break;
        case  8: norm_outflow = (norm_storage <= 0.9786f) ? 1.1829f * norm_storage + -0.4565f : 0.3267f * norm_storage + (1.1829f * 0.9786f + -0.4565f - 0.3267f * 0.9786f); break;
        case  9: norm_outflow = (norm_storage <= 0.9822f) ? 1.2590f * norm_storage + -0.5011f : 0.2950f * norm_storage + (1.2590f * 0.9822f + -0.5011f - 0.2950f * 0.9822f); break;
        case 10: norm_outflow = (norm_storage <= 0.9830f) ? 1.3773f * norm_storage + -0.5443f : 0.3903f * norm_storage + (1.3773f * 0.9830f + -0.5443f - 0.3903f * 0.9830f); break;
        case 11: norm_outflow = 1.1352f * norm_inflow + 0.0272f; break;
        case 12: norm_outflow = 1.1326f * norm_inflow + 0.0294f; break;
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
        case  1: norm_outflow = 0.3117f * norm_inflow + 0.0153f; break;
        case  2: norm_outflow = 0.3346f * norm_inflow + 0.0159f; break;
        case  3: norm_outflow = 0.6630f * norm_inflow + 0.0401f; break;
        case  4: norm_outflow = 0.9796f * norm_inflow + 0.0654f; break;
        case  5: norm_outflow = 1.1472f * norm_inflow + 0.0781f; break;
        case  6: norm_outflow = 1.3362f * norm_inflow + 0.0802f; break;
        case  7: norm_outflow = 1.3301f * norm_inflow + 0.0948f; break;
        case  8: norm_outflow = 1.2561f * norm_inflow + 0.0903f; break;
        case  9: norm_outflow = 1.1843f * norm_inflow + 0.0734f; break;
        case 10: norm_outflow = 0.6534f * norm_inflow + 0.0382f; break;
        case 11: norm_outflow = 0.4290f * norm_inflow + 0.0244f; break;
        case 12: norm_outflow = 0.3835f * norm_inflow + 0.0208f; break;
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
        case  1: norm_outflow = 0.9674f * norm_inflow + 0.0121f; break;
        case  2: norm_outflow = 0.9394f * norm_inflow + 0.0104f; break;
        case  3: norm_outflow = 0.9652f * norm_inflow + 0.0179f; break;
        case  4: norm_outflow = 0.9708f * norm_inflow + 0.0211f; break;
        case  5: norm_outflow = 0.9854f * norm_inflow + 0.0278f; break;
        case  6: norm_outflow = 1.0161f * norm_inflow + 0.0314f; break;
        case  7: norm_outflow = 1.0010f * norm_inflow + 0.0459f; break;
        case  8: norm_outflow = 1.0140f * norm_inflow + 0.0402f; break;
        case  9: norm_outflow = 1.0594f * norm_inflow + 0.0324f; break;
        case 10: norm_outflow = 0.8323f * norm_inflow + 0.0184f; break;
        case 11: norm_outflow = 0.8261f * norm_inflow + 0.0152f; break;
        case 12: norm_outflow = 0.9178f * norm_inflow + 0.0109f; break;
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
        case  1: norm_outflow = 4.0931f * norm_inflow + 0.0359f; break;
        case  2: norm_outflow = 3.9621f * norm_inflow + 0.0369f; break;
        case  3: norm_outflow = (norm_storage <= 0.9714f) ? 0.8038f * norm_storage + -0.1020f : 0.2947f * norm_storage + (0.8038f * 0.9714f + -0.1020f - 0.2947f * 0.9714f); break;
        case  4: norm_outflow = (norm_storage <= 0.9720f) ? 0.8734f * norm_storage + -0.1293f : 0.2993f * norm_storage + (0.8734f * 0.9720f + -0.1293f - 0.2993f * 0.9720f); break;
        case  5: norm_outflow = (norm_storage <= 0.9743f) ? 0.9400f * norm_storage + -0.1762f : 0.2944f * norm_storage + (0.9400f * 0.9743f + -0.1762f - 0.2944f * 0.9743f); break;
        case  6: norm_outflow = 3.3907f * norm_inflow + 0.0498f; break;
        case  7: norm_outflow = 3.4143f * norm_inflow + 0.0505f; break;
        case  8: norm_outflow = 3.4405f * norm_inflow + 0.0487f; break;
        case  9: norm_outflow = (norm_storage <= 0.9763f) ? 1.1364f * norm_storage + -0.1897f : 0.2537f * norm_storage + (1.1364f * 0.9763f + -0.1897f - 0.2537f * 0.9763f); break;
        case 10: norm_outflow = (norm_storage <= 0.9766f) ? 1.1521f * norm_storage + -0.1824f : 0.1650f * norm_storage + (1.1521f * 0.9766f + -0.1824f - 0.1650f * 0.9766f); break;
        case 11: norm_outflow = 4.1541f * norm_inflow + 0.0377f; break;
        case 12: norm_outflow = 4.1573f * norm_inflow + 0.0363f; break;
    }
    return norm_outflow * max_outflow_m3d;
}

static float rule_2232(float inflow_m3d, float storage_m3, int month) {
    const float max_inflow_m3d   = 34943239.2f;
    const float max_outflow_m3d  = 4421584.6f;
    const float max_storage_m3   = 274555379.3f;
    const float norm_inflow  = inflow_m3d  / max_inflow_m3d;
    const float norm_storage = storage_m3  / max_storage_m3;
    float norm_outflow;

    switch (month) {
        case  1: norm_outflow = 1.7158f * norm_inflow + 0.0162f; break;
        case  2: norm_outflow = 1.6096f * norm_inflow + 0.0164f; break;
        case  3: norm_outflow = 1.4819f * norm_inflow + 0.0156f; break;
        case  4: norm_outflow = (norm_storage <= 0.9480f) ? 0.9816f * norm_storage + -0.1226f : 0.7156f * norm_storage + (0.9816f * 0.9480f + -0.1226f - 0.7156f * 0.9480f); break;
        case  5: norm_outflow = (norm_storage <= 0.9710f) ? 1.1864f * norm_storage + -0.1799f : 0.4822f * norm_storage + (1.1864f * 0.9710f + -0.1799f - 0.4822f * 0.9710f); break;
        case  6: norm_outflow = (norm_storage <= 0.9734f) ? 1.2543f * norm_storage + -0.2179f : 0.6244f * norm_storage + (1.2543f * 0.9734f + -0.2179f - 0.6244f * 0.9734f); break;
        case  7: norm_outflow = (norm_storage <= 0.9756f) ? 1.2334f * norm_storage + -0.1973f : 0.4650f * norm_storage + (1.2334f * 0.9756f + -0.1973f - 0.4650f * 0.9756f); break;
        case  8: norm_outflow = (norm_storage <= 0.9838f) ? 1.2159f * norm_storage + -0.1468f : 0.2365f * norm_storage + (1.2159f * 0.9838f + -0.1468f - 0.2365f * 0.9838f); break;
        case  9: norm_outflow = (norm_storage <= 0.9829f) ? 1.2323f * norm_storage + -0.1499f : 0.1996f * norm_storage + (1.2323f * 0.9829f + -0.1499f - 0.1996f * 0.9829f); break;
        case 10: norm_outflow = (norm_storage <= 0.9815f) ? 1.2257f * norm_storage + -0.1500f : 0.1768f * norm_storage + (1.2257f * 0.9815f + -0.1500f - 0.1768f * 0.9815f); break;
        case 11: norm_outflow = 1.9229f * norm_inflow + 0.0192f; break;
        case 12: norm_outflow = 1.8074f * norm_inflow + 0.0174f; break;
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
        case  1: norm_outflow = 0.7267f * norm_inflow + 0.0080f; break;
        case  2: norm_outflow = 0.7830f * norm_inflow + 0.0082f; break;
        case  3: norm_outflow = 0.9859f * norm_inflow + 0.0084f; break;
        case  4: norm_outflow = 1.0277f * norm_inflow + 0.0088f; break;
        case  5: norm_outflow = 1.0950f * norm_inflow + 0.0109f; break;
        case  6: norm_outflow = 1.1026f * norm_inflow + 0.0146f; break;
        case  7: norm_outflow = 1.0876f * norm_inflow + 0.0155f; break;
        case  8: norm_outflow = 1.0208f * norm_inflow + 0.0148f; break;
        case  9: norm_outflow = (norm_storage <= 0.9398f) ? 0.2647f * norm_storage + -0.0045f : 0.8418f * norm_storage + (0.2647f * 0.9398f + -0.0045f - 0.8418f * 0.9398f); break;
        case 10: norm_outflow = 0.8955f * norm_inflow + 0.0083f; break;
        case 11: norm_outflow = 0.8620f * norm_inflow + 0.0090f; break;
        case 12: norm_outflow = 0.7270f * norm_inflow + 0.0081f; break;
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
        case  1: norm_outflow = 1.2445f * norm_inflow + 0.0097f; break;
        case  2: norm_outflow = 1.2361f * norm_inflow + 0.0090f; break;
        case  3: norm_outflow = 1.1990f * norm_inflow + 0.0093f; break;
        case  4: norm_outflow = 1.2650f * norm_inflow + 0.0097f; break;
        case  5: norm_outflow = 1.2877f * norm_inflow + 0.0113f; break;
        case  6: norm_outflow = 1.2856f * norm_inflow + 0.0126f; break;
        case  7: norm_outflow = 1.2928f * norm_inflow + 0.0125f; break;
        case  8: norm_outflow = 1.3045f * norm_inflow + 0.0107f; break;
        case  9: norm_outflow = 1.2393f * norm_inflow + 0.0105f; break;
        case 10: norm_outflow = 1.2269f * norm_inflow + 0.0110f; break;
        case 11: norm_outflow = 1.1967f * norm_inflow + 0.0102f; break;
        case 12: norm_outflow = 1.2148f * norm_inflow + 0.0095f; break;
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
        case  1: norm_outflow = 1.4937f * norm_inflow + 0.0281f; break;
        case  2: norm_outflow = 1.5493f * norm_inflow + 0.0270f; break;
        case  3: norm_outflow = 1.5542f * norm_inflow + 0.0301f; break;
        case  4: norm_outflow = 1.5471f * norm_inflow + 0.0319f; break;
        case  5: norm_outflow = (norm_storage <= 0.8680f) ? 0.1340f * norm_storage + 0.0185f : 6.3972f * norm_storage + (0.1340f * 0.8680f + 0.0185f - 6.3972f * 0.8680f); break;
        case  6: norm_outflow = (norm_storage <= 0.8808f) ? 0.1360f * norm_storage + 0.0284f : 6.0041f * norm_storage + (0.1360f * 0.8808f + 0.0284f - 6.0041f * 0.8808f); break;
        case  7: norm_outflow = 1.4737f * norm_inflow + 0.0437f; break;
        case  8: norm_outflow = 1.5123f * norm_inflow + 0.0404f; break;
        case  9: norm_outflow = 1.4856f * norm_inflow + 0.0383f; break;
        case 10: norm_outflow = 1.4734f * norm_inflow + 0.0328f; break;
        case 11: norm_outflow = 1.5279f * norm_inflow + 0.0287f; break;
        case 12: norm_outflow = 1.5205f * norm_inflow + 0.0282f; break;
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
        case  1: norm_outflow = 1.1754f * norm_inflow + 0.0351f; break;
        case  2: norm_outflow = 1.1819f * norm_inflow + 0.0370f; break;
        case  3: norm_outflow = 1.1587f * norm_inflow + 0.0460f; break;
        case  4: norm_outflow = 1.1469f * norm_inflow + 0.0534f; break;
        case  5: norm_outflow = 1.1697f * norm_inflow + 0.0546f; break;
        case  6: norm_outflow = 1.2127f * norm_inflow + 0.0599f; break;
        case  7: norm_outflow = 1.2312f * norm_inflow + 0.0610f; break;
        case  8: norm_outflow = 1.1944f * norm_inflow + 0.0627f; break;
        case  9: norm_outflow = 1.1796f * norm_inflow + 0.0554f; break;
        case 10: norm_outflow = 1.1139f * norm_inflow + 0.0420f; break;
        case 11: norm_outflow = 1.1936f * norm_inflow + 0.0376f; break;
        case 12: norm_outflow = 1.1843f * norm_inflow + 0.0350f; break;
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
        case  1: norm_outflow = 0.1328f * norm_inflow + 0.0190f; break;
        case  2: norm_outflow = 0.1570f * norm_inflow + 0.0199f; break;
        case  3: norm_outflow = 0.3220f * norm_inflow + 0.0524f; break;
        case  4: norm_outflow = 0.6202f * norm_inflow + 0.1010f; break;
        case  5: norm_outflow = 0.7095f * norm_inflow + 0.1199f; break;
        case  6: norm_outflow = 0.7645f * norm_inflow + 0.1440f; break;
        case  7: norm_outflow = 0.6641f * norm_inflow + 0.1450f; break;
        case  8: norm_outflow = 0.6067f * norm_inflow + 0.1213f; break;
        case  9: norm_outflow = 0.7378f * norm_inflow + 0.0982f; break;
        case 10: norm_outflow = 0.3022f * norm_inflow + 0.0427f; break;
        case 11: norm_outflow = 0.1692f * norm_inflow + 0.0291f; break;
        case 12: norm_outflow = 0.1629f * norm_inflow + 0.0262f; break;
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
        case  1: norm_outflow = 0.8802f * norm_inflow + 0.0238f; break;
        case  2: norm_outflow = 0.9415f * norm_inflow + 0.0215f; break;
        case  3: norm_outflow = 1.0909f * norm_inflow + 0.0150f; break;
        case  4: norm_outflow = 1.1070f * norm_inflow + 0.0143f; break;
        case  5: norm_outflow = 1.1111f * norm_inflow + 0.0182f; break;
        case  6: norm_outflow = 1.1322f * norm_inflow + 0.0220f; break;
        case  7: norm_outflow = 1.1308f * norm_inflow + 0.0242f; break;
        case  8: norm_outflow = 1.1105f * norm_inflow + 0.0265f; break;
        case  9: norm_outflow = 1.0869f * norm_inflow + 0.0222f; break;
        case 10: norm_outflow = 0.9154f * norm_inflow + 0.0239f; break;
        case 11: norm_outflow = 0.8778f * norm_inflow + 0.0247f; break;
        case 12: norm_outflow = 0.8893f * norm_inflow + 0.0242f; break;
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
        case  1: norm_outflow = 0.2509f * norm_inflow + 0.0163f; break;
        case  2: norm_outflow = 0.2844f * norm_inflow + 0.0178f; break;
        case  3: norm_outflow = 0.6308f * norm_inflow + 0.0461f; break;
        case  4: norm_outflow = 0.9643f * norm_inflow + 0.0747f; break;
        case  5: norm_outflow = 1.0450f * norm_inflow + 0.0975f; break;
        case  6: norm_outflow = 1.1068f * norm_inflow + 0.0981f; break;
        case  7: norm_outflow = 1.0581f * norm_inflow + 0.1056f; break;
        case  8: norm_outflow = 1.0523f * norm_inflow + 0.0906f; break;
        case  9: norm_outflow = 1.0237f * norm_inflow + 0.0754f; break;
        case 10: norm_outflow = 0.5411f * norm_inflow + 0.0386f; break;
        case 11: norm_outflow = 0.2863f * norm_inflow + 0.0225f; break;
        case 12: norm_outflow = 0.2611f * norm_inflow + 0.0188f; break;
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
        case  1: norm_outflow = (norm_storage <= 0.9399f) ? 1.1417f * norm_storage + -0.7706f : 0.7050f * norm_storage + (1.1417f * 0.9399f + -0.7706f - 0.7050f * 0.9399f); break;
        case  2: norm_outflow = (norm_storage <= 0.9429f) ? 1.2306f * norm_storage + -0.8281f : 0.6529f * norm_storage + (1.2306f * 0.9429f + -0.8281f - 0.6529f * 0.9429f); break;
        case  3: norm_outflow = (norm_storage <= 0.9366f) ? 1.2880f * norm_storage + -0.8749f : 0.7482f * norm_storage + (1.2880f * 0.9366f + -0.8749f - 0.7482f * 0.9366f); break;
        case  4: norm_outflow = (norm_storage <= 0.9231f) ? 1.2820f * norm_storage + -0.8725f : 0.9586f * norm_storage + (1.2820f * 0.9231f + -0.8725f - 0.9586f * 0.9231f); break;
        case  5: norm_outflow = (norm_storage <= 0.9149f) ? 1.3136f * norm_storage + -0.8534f : 2.4464f * norm_storage + (1.3136f * 0.9149f + -0.8534f - 2.4464f * 0.9149f); break;
        case  6: norm_outflow = (norm_storage <= 0.9219f) ? 1.4424f * norm_storage + -0.9322f : 3.8657f * norm_storage + (1.4424f * 0.9219f + -0.9322f - 3.8657f * 0.9219f); break;
        case  7: norm_outflow = (norm_storage <= 0.8856f) ? 1.0253f * norm_storage + -0.6705f : 1.3362f * norm_storage + (1.0253f * 0.8856f + -0.6705f - 1.3362f * 0.8856f); break;
        case  8: norm_outflow = (norm_storage <= 0.8585f) ? 0.8341f * norm_storage + -0.5407f : 1.7368f * norm_storage + (0.8341f * 0.8585f + -0.5407f - 1.7368f * 0.8585f); break;
        case  9: norm_outflow = (norm_storage <= 0.8772f) ? 0.8386f * norm_storage + -0.5562f : 1.5175f * norm_storage + (0.8386f * 0.8772f + -0.5562f - 1.5175f * 0.8772f); break;
        case 10: norm_outflow = (norm_storage <= 0.8950f) ? 0.8698f * norm_storage + -0.5739f : 1.1943f * norm_storage + (0.8698f * 0.8950f + -0.5739f - 1.1943f * 0.8950f); break;
        case 11: norm_outflow = (norm_storage <= 0.9155f) ? 0.9757f * norm_storage + -0.6522f : 0.9423f * norm_storage + (0.9757f * 0.9155f + -0.6522f - 0.9423f * 0.9155f); break;
        case 12: norm_outflow = (norm_storage <= 0.9306f) ? 1.0867f * norm_storage + -0.7322f : 0.7952f * norm_storage + (1.0867f * 0.9306f + -0.7322f - 0.7952f * 0.9306f); break;
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
        case  1: norm_outflow = 0.9111f * norm_inflow + 0.0211f; break;
        case  2: norm_outflow = 0.9809f * norm_inflow + 0.0197f; break;
        case  3: norm_outflow = 1.0373f * norm_inflow + 0.0243f; break;
        case  4: norm_outflow = 1.0410f * norm_inflow + 0.0303f; break;
        case  5: norm_outflow = 1.0379f * norm_inflow + 0.0316f; break;
        case  6: norm_outflow = 1.0728f * norm_inflow + 0.0330f; break;
        case  7: norm_outflow = 1.0608f * norm_inflow + 0.0344f; break;
        case  8: norm_outflow = 1.0545f * norm_inflow + 0.0329f; break;
        case  9: norm_outflow = 1.0916f * norm_inflow + 0.0294f; break;
        case 10: norm_outflow = 1.0051f * norm_inflow + 0.0188f; break;
        case 11: norm_outflow = 0.9927f * norm_inflow + 0.0196f; break;
        case 12: norm_outflow = 0.9521f * norm_inflow + 0.0206f; break;
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
        case  1: norm_outflow = 1.2183f * norm_inflow + 0.0301f; break;
        case  2: norm_outflow = 1.2352f * norm_inflow + 0.0263f; break;
        case  3: norm_outflow = 1.2460f * norm_inflow + 0.0280f; break;
        case  4: norm_outflow = 1.2943f * norm_inflow + 0.0313f; break;
        case  5: norm_outflow = (norm_storage <= 0.9901f) ? 1.2162f * norm_storage + -0.1367f : 1.8048f * norm_storage + (1.2162f * 0.9901f + -0.1367f - 1.8048f * 0.9901f); break;
        case  6: norm_outflow = (norm_storage <= 0.9899f) ? 1.2339f * norm_storage + -0.1410f : 0.1335f * norm_storage + (1.2339f * 0.9899f + -0.1410f - 0.1335f * 0.9899f); break;
        case  7: norm_outflow = (norm_storage <= 0.9916f) ? 1.2569f * norm_storage + -0.1431f : 0.1227f * norm_storage + (1.2569f * 0.9916f + -0.1431f - 0.1227f * 0.9916f); break;
        case  8: norm_outflow = (norm_storage <= 0.9918f) ? 1.3917f * norm_storage + -0.1609f : 0.1393f * norm_storage + (1.3917f * 0.9918f + -0.1609f - 0.1393f * 0.9918f); break;
        case  9: norm_outflow = (norm_storage <= 0.9919f) ? 1.5785f * norm_storage + -0.1677f : 0.1329f * norm_storage + (1.5785f * 0.9919f + -0.1677f - 0.1329f * 0.9919f); break;
        case 10: norm_outflow = (norm_storage <= 0.9927f) ? 1.5758f * norm_storage + -0.1492f : 0.1247f * norm_storage + (1.5758f * 0.9927f + -0.1492f - 0.1247f * 0.9927f); break;
        case 11: norm_outflow = 1.2478f * norm_inflow + 0.0368f; break;
        case 12: norm_outflow = (norm_storage <= 0.9951f) ? 1.6494f * norm_storage + -0.1404f : 0.0925f * norm_storage + (1.6494f * 0.9951f + -0.1404f - 0.0925f * 0.9951f); break;
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
        case  1: norm_outflow = (norm_storage <= 0.9992f) ? 0.8379f * norm_storage + -0.0529f : 0.0179f * norm_storage + (0.8379f * 0.9992f + -0.0529f - 0.0179f * 0.9992f); break;
        case  2: norm_outflow = (norm_storage <= 0.9992f) ? 0.9020f * norm_storage + -0.0576f : 0.0207f * norm_storage + (0.9020f * 0.9992f + -0.0576f - 0.0207f * 0.9992f); break;
        case  3: norm_outflow = (norm_storage <= 0.9991f) ? 0.8784f * norm_storage + -0.0582f : 0.0207f * norm_storage + (0.8784f * 0.9991f + -0.0582f - 0.0207f * 0.9991f); break;
        case  4: norm_outflow = (norm_storage <= 0.9992f) ? 0.7313f * norm_storage + -0.0623f : 0.0235f * norm_storage + (0.7313f * 0.9992f + -0.0623f - 0.0235f * 0.9992f); break;
        case  5: norm_outflow = (norm_storage <= 0.9977f) ? 0.6712f * norm_storage + -0.0656f : 0.0166f * norm_storage + (0.6712f * 0.9977f + -0.0656f - 0.0166f * 0.9977f); break;
        case  6: norm_outflow = (norm_storage <= 0.9968f) ? 0.6853f * norm_storage + -0.0814f : 0.0228f * norm_storage + (0.6853f * 0.9968f + -0.0814f - 0.0228f * 0.9968f); break;
        case  7: norm_outflow = (norm_storage <= 0.9985f) ? 0.7233f * norm_storage + -0.0852f : 0.0103f * norm_storage + (0.7233f * 0.9985f + -0.0852f - 0.0103f * 0.9985f); break;
        case  8: norm_outflow = (norm_storage <= 0.9981f) ? 0.7916f * norm_storage + -0.0995f : 0.0276f * norm_storage + (0.7916f * 0.9981f + -0.0995f - 0.0276f * 0.9981f); break;
        case  9: norm_outflow = (norm_storage <= 0.9988f) ? 0.8659f * norm_storage + -0.0995f : 0.0204f * norm_storage + (0.8659f * 0.9988f + -0.0995f - 0.0204f * 0.9988f); break;
        case 10: norm_outflow = (norm_storage <= 0.9985f) ? 0.8417f * norm_storage + -0.0882f : 0.0244f * norm_storage + (0.8417f * 0.9985f + -0.0882f - 0.0244f * 0.9985f); break;
        case 11: norm_outflow = (norm_storage <= 0.9986f) ? 0.7673f * norm_storage + -0.0706f : 0.0214f * norm_storage + (0.7673f * 0.9986f + -0.0706f - 0.0214f * 0.9986f); break;
        case 12: norm_outflow = (norm_storage <= 0.9990f) ? 0.8682f * norm_storage + -0.0626f : 0.0165f * norm_storage + (0.8682f * 0.9990f + -0.0626f - 0.0165f * 0.9990f); break;
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
        case  1: norm_outflow = 0.7618f * norm_inflow + 0.0173f; break;
        case  2: norm_outflow = 0.8080f * norm_inflow + 0.0162f; break;
        case  3: norm_outflow = 0.8394f * norm_inflow + 0.0202f; break;
        case  4: norm_outflow = 0.8333f * norm_inflow + 0.0265f; break;
        case  5: norm_outflow = 0.8399f * norm_inflow + 0.0314f; break;
        case  6: norm_outflow = 0.9009f * norm_inflow + 0.0348f; break;
        case  7: norm_outflow = 0.8527f * norm_inflow + 0.0337f; break;
        case  8: norm_outflow = 0.8356f * norm_inflow + 0.0321f; break;
        case  9: norm_outflow = 0.9026f * norm_inflow + 0.0264f; break;
        case 10: norm_outflow = 0.8295f * norm_inflow + 0.0171f; break;
        case 11: norm_outflow = 0.8285f * norm_inflow + 0.0166f; break;
        case 12: norm_outflow = 0.8107f * norm_inflow + 0.0154f; break;
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
        case  1: norm_outflow = 1.2195f * norm_inflow + 0.0316f; break;
        case  2: norm_outflow = 1.2463f * norm_inflow + 0.0306f; break;
        case  3: norm_outflow = 1.2495f * norm_inflow + 0.0340f; break;
        case  4: norm_outflow = 1.2644f * norm_inflow + 0.0341f; break;
        case  5: norm_outflow = 1.2616f * norm_inflow + 0.0354f; break;
        case  6: norm_outflow = 1.2658f * norm_inflow + 0.0355f; break;
        case  7: norm_outflow = 1.2917f * norm_inflow + 0.0344f; break;
        case  8: norm_outflow = 1.2883f * norm_inflow + 0.0321f; break;
        case  9: norm_outflow = 1.2718f * norm_inflow + 0.0315f; break;
        case 10: norm_outflow = 1.2626f * norm_inflow + 0.0294f; break;
        case 11: norm_outflow = 1.2534f * norm_inflow + 0.0296f; break;
        case 12: norm_outflow = 1.2245f * norm_inflow + 0.0306f; break;
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
        case  1: norm_outflow = (norm_storage <= 0.9933f) ? 1.6096f * norm_storage + -0.4023f : 0.0764f * norm_storage + (1.6096f * 0.9933f + -0.4023f - 0.0764f * 0.9933f); break;
        case  2: norm_outflow = (norm_storage <= 0.9924f) ? 1.4480f * norm_storage + -0.3399f : 0.0958f * norm_storage + (1.4480f * 0.9924f + -0.3399f - 0.0958f * 0.9924f); break;
        case  3: norm_outflow = (norm_storage <= 0.9869f) ? 1.5753f * norm_storage + -0.4132f : 0.1689f * norm_storage + (1.5753f * 0.9869f + -0.4132f - 0.1689f * 0.9869f); break;
        case  4: norm_outflow = (norm_storage <= 0.9801f) ? 1.8173f * norm_storage + -0.5484f : 0.2417f * norm_storage + (1.8173f * 0.9801f + -0.5484f - 0.2417f * 0.9801f); break;
        case  5: norm_outflow = (norm_storage <= 0.9860f) ? 2.1294f * norm_storage + -0.7321f : 0.1618f * norm_storage + (2.1294f * 0.9860f + -0.7321f - 0.1618f * 0.9860f); break;
        case  6: norm_outflow = (norm_storage <= 0.9915f) ? 2.3816f * norm_storage + -0.9004f : 0.0721f * norm_storage + (2.3816f * 0.9915f + -0.9004f - 0.0721f * 0.9915f); break;
        case  7: norm_outflow = (norm_storage <= 0.9889f) ? 2.1688f * norm_storage + -0.7653f : 0.1226f * norm_storage + (2.1688f * 0.9889f + -0.7653f - 0.1226f * 0.9889f); break;
        case  8: norm_outflow = (norm_storage <= 0.9794f) ? 1.8618f * norm_storage + -0.6012f : 0.3006f * norm_storage + (1.8618f * 0.9794f + -0.6012f - 0.3006f * 0.9794f); break;
        case  9: norm_outflow = 1.8263f * norm_inflow + 0.0391f; break;
        case 10: norm_outflow = 1.8898f * norm_inflow + 0.0438f; break;
        case 11: norm_outflow = 1.8715f * norm_inflow + 0.0494f; break;
        case 12: norm_outflow = (norm_storage <= 0.9911f) ? 1.6807f * norm_storage + -0.4317f : 0.1035f * norm_storage + (1.6807f * 0.9911f + -0.4317f - 0.1035f * 0.9911f); break;
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
        case  1: norm_outflow = (norm_storage <= 0.9825f) ? 0.8441f * norm_storage + -0.2320f : 0.1937f * norm_storage + (0.8441f * 0.9825f + -0.2320f - 0.1937f * 0.9825f); break;
        case  2: norm_outflow = (norm_storage <= 0.9778f) ? 0.8501f * norm_storage + -0.2506f : 0.2681f * norm_storage + (0.8501f * 0.9778f + -0.2506f - 0.2681f * 0.9778f); break;
        case  3: norm_outflow = (norm_storage <= 0.9489f) ? 1.1131f * norm_storage + -0.4410f : 0.5896f * norm_storage + (1.1131f * 0.9489f + -0.4410f - 0.5896f * 0.9489f); break;
        case  4: norm_outflow = (norm_storage <= 0.9280f) ? 1.6124f * norm_storage + -0.7763f : 1.0054f * norm_storage + (1.6124f * 0.9280f + -0.7763f - 1.0054f * 0.9280f); break;
        case  5: norm_outflow = (norm_storage <= 0.9592f) ? 2.1980f * norm_storage + -1.1450f : 0.5826f * norm_storage + (2.1980f * 0.9592f + -1.1450f - 0.5826f * 0.9592f); break;
        case  6: norm_outflow = (norm_storage <= 0.9839f) ? 2.7895f * norm_storage + -1.4821f : 0.2259f * norm_storage + (2.7895f * 0.9839f + -1.4821f - 0.2259f * 0.9839f); break;
        case  7: norm_outflow = (norm_storage <= 0.9720f) ? 2.4982f * norm_storage + -1.3360f : 0.4077f * norm_storage + (2.4982f * 0.9720f + -1.3360f - 0.4077f * 0.9720f); break;
        case  8: norm_outflow = (norm_storage <= 0.8997f) ? 1.6100f * norm_storage + -0.8425f : 1.4771f * norm_storage + (1.6100f * 0.8997f + -0.8425f - 1.4771f * 0.8997f); break;
        case  9: norm_outflow = (norm_storage <= 0.9049f) ? 1.3532f * norm_storage + -0.6877f : 1.2702f * norm_storage + (1.3532f * 0.9049f + -0.6877f - 1.2702f * 0.9049f); break;
        case 10: norm_outflow = (norm_storage <= 0.8847f) ? 1.0266f * norm_storage + -0.4749f : 1.6385f * norm_storage + (1.0266f * 0.8847f + -0.4749f - 1.6385f * 0.8847f); break;
        case 11: norm_outflow = (norm_storage <= 0.9699f) ? 0.8101f * norm_storage + -0.2483f : 0.3693f * norm_storage + (0.8101f * 0.9699f + -0.2483f - 0.3693f * 0.9699f); break;
        case 12: norm_outflow = (norm_storage <= 0.9770f) ? 0.8658f * norm_storage + -0.2520f : 0.2698f * norm_storage + (0.8658f * 0.9770f + -0.2520f - 0.2698f * 0.9770f); break;
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
        case  1: norm_outflow = (norm_storage <= 0.8944f) ? 0.9399f * norm_storage + -0.3969f : 1.6518f * norm_storage + (0.9399f * 0.8944f + -0.3969f - 1.6518f * 0.8944f); break;
        case  2: norm_outflow = 1.4757f * norm_inflow + 0.0571f; break;
        case  3: norm_outflow = (norm_storage <= 0.8399f) ? 0.9186f * norm_storage + -0.4503f : 2.2286f * norm_storage + (0.9186f * 0.8399f + -0.4503f - 2.2286f * 0.8399f); break;
        case  4: norm_outflow = (norm_storage <= 0.8252f) ? 1.1146f * norm_storage + -0.6143f : 2.8428f * norm_storage + (1.1146f * 0.8252f + -0.6143f - 2.8428f * 0.8252f); break;
        case  5: norm_outflow = (norm_storage <= 0.8615f) ? 1.6350f * norm_storage + -0.9696f : 2.3510f * norm_storage + (1.6350f * 0.8615f + -0.9696f - 2.3510f * 0.8615f); break;
        case  6: norm_outflow = (norm_storage <= 0.9175f) ? 2.4475f * norm_storage + -1.4614f : 1.4785f * norm_storage + (2.4475f * 0.9175f + -1.4614f - 1.4785f * 0.9175f); break;
        case  7: norm_outflow = (norm_storage <= 0.8791f) ? 1.8177f * norm_storage + -1.1067f : 2.1554f * norm_storage + (1.8177f * 0.8791f + -1.1067f - 2.1554f * 0.8791f); break;
        case  8: norm_outflow = (norm_storage <= 0.8278f) ? 1.0726f * norm_storage + -0.6148f : 2.8469f * norm_storage + (1.0726f * 0.8278f + -0.6148f - 2.8469f * 0.8278f); break;
        case  9: norm_outflow = (norm_storage <= 0.8333f) ? 0.9532f * norm_storage + -0.5213f : 2.5096f * norm_storage + (0.9532f * 0.8333f + -0.5213f - 2.5096f * 0.8333f); break;
        case 10: norm_outflow = (norm_storage <= 0.8256f) ? 0.8542f * norm_storage + -0.4423f : 2.7845f * norm_storage + (0.8542f * 0.8256f + -0.4423f - 2.7845f * 0.8256f); break;
        case 11: norm_outflow = 1.6391f * norm_inflow + 0.0747f; break;
        case 12: norm_outflow = (norm_storage <= 0.8951f) ? 0.9833f * norm_storage + -0.4365f : 1.7011f * norm_storage + (0.9833f * 0.8951f + -0.4365f - 1.7011f * 0.8951f); break;
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
        case  1: norm_outflow = (norm_storage <= 0.9412f) ? 1.0307f * norm_storage + -0.3951f : 0.9175f * norm_storage + (1.0307f * 0.9412f + -0.3951f - 0.9175f * 0.9412f); break;
        case  2: norm_outflow = (norm_storage <= 0.9377f) ? 0.9957f * norm_storage + -0.3844f : 0.9712f * norm_storage + (0.9957f * 0.9377f + -0.3844f - 0.9712f * 0.9377f); break;
        case  3: norm_outflow = (norm_storage <= 0.9025f) ? 1.2033f * norm_storage + -0.5542f : 1.3479f * norm_storage + (1.2033f * 0.9025f + -0.5542f - 1.3479f * 0.9025f); break;
        case  4: norm_outflow = (norm_storage <= 0.8833f) ? 1.4484f * norm_storage + -0.7459f : 1.8021f * norm_storage + (1.4484f * 0.8833f + -0.7459f - 1.8021f * 0.8833f); break;
        case  5: norm_outflow = (norm_storage <= 0.9255f) ? 2.1611f * norm_storage + -1.2176f : 1.1932f * norm_storage + (2.1611f * 0.9255f + -1.2176f - 1.1932f * 0.9255f); break;
        case  6: norm_outflow = (norm_storage <= 0.9518f) ? 2.6821f * norm_storage + -1.5201f : 0.7980f * norm_storage + (2.6821f * 0.9518f + -1.5201f - 0.7980f * 0.9518f); break;
        case  7: norm_outflow = (norm_storage <= 0.9176f) ? 2.1650f * norm_storage + -1.2441f : 1.3909f * norm_storage + (2.1650f * 0.9176f + -1.2441f - 1.3909f * 0.9176f); break;
        case  8: norm_outflow = (norm_storage <= 0.8393f) ? 1.2404f * norm_storage + -0.6895f : 2.6270f * norm_storage + (1.2404f * 0.8393f + -0.6895f - 2.6270f * 0.8393f); break;
        case  9: norm_outflow = (norm_storage <= 0.8515f) ? 1.1297f * norm_storage + -0.6061f : 2.2723f * norm_storage + (1.1297f * 0.8515f + -0.6061f - 2.2723f * 0.8515f); break;
        case 10: norm_outflow = (norm_storage <= 0.8405f) ? 0.9002f * norm_storage + -0.4420f : 2.5724f * norm_storage + (0.9002f * 0.8405f + -0.4420f - 2.5724f * 0.8405f); break;
        case 11: norm_outflow = 1.5235f * norm_inflow + 0.0677f; break;
        case 12: norm_outflow = (norm_storage <= 0.9342f) ? 1.0379f * norm_storage + -0.4100f : 1.0253f * norm_storage + (1.0379f * 0.9342f + -0.4100f - 1.0253f * 0.9342f); break;
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
        case  1: norm_outflow = (norm_storage <= 0.9190f) ? 1.2302f * norm_storage + -0.4456f : 1.0599f * norm_storage + (1.2302f * 0.9190f + -0.4456f - 1.0599f * 0.9190f); break;
        case  2: norm_outflow = (norm_storage <= 0.9393f) ? 1.1949f * norm_storage + -0.4157f : 0.8386f * norm_storage + (1.1949f * 0.9393f + -0.4157f - 0.8386f * 0.9393f); break;
        case  3: norm_outflow = (norm_storage <= 0.8641f) ? 1.1193f * norm_storage + -0.4399f : 1.7486f * norm_storage + (1.1193f * 0.8641f + -0.4399f - 1.7486f * 0.8641f); break;
        case  4: norm_outflow = (norm_storage <= 0.8468f) ? 1.2633f * norm_storage + -0.5671f : 2.1210f * norm_storage + (1.2633f * 0.8468f + -0.5671f - 2.1210f * 0.8468f); break;
        case  5: norm_outflow = (norm_storage <= 0.8833f) ? 1.8069f * norm_storage + -0.9108f : 1.6173f * norm_storage + (1.8069f * 0.8833f + -0.9108f - 1.6173f * 0.8833f); break;
        case  6: norm_outflow = (norm_storage <= 0.9452f) ? 2.6773f * norm_storage + -1.4233f : 0.7429f * norm_storage + (2.6773f * 0.9452f + -1.4233f - 0.7429f * 0.9452f); break;
        case  7: norm_outflow = (norm_storage <= 0.9130f) ? 2.1623f * norm_storage + -1.1535f : 1.2242f * norm_storage + (2.1623f * 0.9130f + -1.1535f - 1.2242f * 0.9130f); break;
        case  8: norm_outflow = (norm_storage <= 0.8707f) ? 1.5276f * norm_storage + -0.7805f : 1.8896f * norm_storage + (1.5276f * 0.8707f + -0.7805f - 1.8896f * 0.8707f); break;
        case  9: norm_outflow = (norm_storage <= 0.8944f) ? 1.4874f * norm_storage + -0.7402f : 1.4559f * norm_storage + (1.4874f * 0.8944f + -0.7402f - 1.4559f * 0.8944f); break;
        case 10: norm_outflow = (norm_storage <= 0.9157f) ? 1.4928f * norm_storage + -0.6994f : 1.2692f * norm_storage + (1.4928f * 0.9157f + -0.6994f - 1.2692f * 0.9157f); break;
        case 11: norm_outflow = 1.8763f * norm_inflow + 0.0684f; break;
        case 12: norm_outflow = (norm_storage <= 0.9427f) ? 1.4009f * norm_storage + -0.5398f : 0.7821f * norm_storage + (1.4009f * 0.9427f + -0.5398f - 0.7821f * 0.9427f); break;
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
        case  1: norm_outflow = (norm_storage <= 0.9971f) ? 0.5884f * norm_storage + -0.0389f : 0.0335f * norm_storage + (0.5884f * 0.9971f + -0.0389f - 0.0335f * 0.9971f); break;
        case  2: norm_outflow = 0.7384f * norm_inflow + 0.0434f; break;
        case  3: norm_outflow = 0.7821f * norm_inflow + 0.0491f; break;
        case  4: norm_outflow = 0.8542f * norm_inflow + 0.0504f; break;
        case  5: norm_outflow = 0.8783f * norm_inflow + 0.0522f; break;
        case  6: norm_outflow = 0.9388f * norm_inflow + 0.0522f; break;
        case  7: norm_outflow = 0.9391f * norm_inflow + 0.0520f; break;
        case  8: norm_outflow = 0.9488f * norm_inflow + 0.0495f; break;
        case  9: norm_outflow = 0.8279f * norm_inflow + 0.0474f; break;
        case 10: norm_outflow = 0.8071f * norm_inflow + 0.0468f; break;
        case 11: norm_outflow = 0.8085f * norm_inflow + 0.0495f; break;
        case 12: norm_outflow = (norm_storage <= 0.9972f) ? 0.6064f * norm_storage + -0.0433f : 0.0308f * norm_storage + (0.6064f * 0.9972f + -0.0433f - 0.0308f * 0.9972f); break;
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
        case  1: norm_outflow = (norm_storage <= 0.9839f) ? 0.9240f * norm_storage + -0.1833f : 0.1993f * norm_storage + (0.9240f * 0.9839f + -0.1833f - 0.1993f * 0.9839f); break;
        case  2: norm_outflow = (norm_storage <= 0.9775f) ? 0.9339f * norm_storage + -0.2061f : 0.2964f * norm_storage + (0.9339f * 0.9775f + -0.2061f - 0.2964f * 0.9775f); break;
        case  3: norm_outflow = (norm_storage <= 0.9599f) ? 1.0756f * norm_storage + -0.2873f : 0.5011f * norm_storage + (1.0756f * 0.9599f + -0.2873f - 0.5011f * 0.9599f); break;
        case  4: norm_outflow = (norm_storage <= 0.9454f) ? 1.4807f * norm_storage + -0.5199f : 0.7258f * norm_storage + (1.4807f * 0.9454f + -0.5199f - 0.7258f * 0.9454f); break;
        case  5: norm_outflow = (norm_storage <= 0.9617f) ? 1.9764f * norm_storage + -0.7957f : 0.4554f * norm_storage + (1.9764f * 0.9617f + -0.7957f - 0.4554f * 0.9617f); break;
        case  6: norm_outflow = (norm_storage <= 0.9794f) ? 2.5166f * norm_storage + -1.1253f : 0.2540f * norm_storage + (2.5166f * 0.9794f + -1.1253f - 0.2540f * 0.9794f); break;
        case  7: norm_outflow = (norm_storage <= 0.9643f) ? 2.1709f * norm_storage + -0.9022f : 0.4798f * norm_storage + (2.1709f * 0.9643f + -0.9022f - 0.4798f * 0.9643f); break;
        case  8: norm_outflow = 1.3989f * norm_inflow + 0.0446f; break;
        case  9: norm_outflow = 1.3268f * norm_inflow + 0.0456f; break;
        case 10: norm_outflow = 1.4262f * norm_inflow + 0.0492f; break;
        case 11: norm_outflow = (norm_storage <= 0.9706f) ? 0.9211f * norm_storage + -0.2100f : 0.3992f * norm_storage + (0.9211f * 0.9706f + -0.2100f - 0.3992f * 0.9706f); break;
        case 12: norm_outflow = (norm_storage <= 0.9803f) ? 0.9511f * norm_storage + -0.1956f : 0.2487f * norm_storage + (0.9511f * 0.9803f + -0.1956f - 0.2487f * 0.9803f); break;
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
        case  1: norm_outflow = 1.0052f * norm_inflow + 0.0687f; break;
        case  2: norm_outflow = 0.9997f * norm_inflow + 0.0684f; break;
        case  3: norm_outflow = 0.8729f * norm_inflow + 0.0836f; break;
        case  4: norm_outflow = 0.8196f * norm_inflow + 0.0888f; break;
        case  5: norm_outflow = 0.8576f * norm_inflow + 0.0973f; break;
        case  6: norm_outflow = 0.8816f * norm_inflow + 0.1099f; break;
        case  7: norm_outflow = 0.9143f * norm_inflow + 0.1068f; break;
        case  8: norm_outflow = 0.8580f * norm_inflow + 0.1048f; break;
        case  9: norm_outflow = 0.8639f * norm_inflow + 0.0956f; break;
        case 10: norm_outflow = 0.9170f * norm_inflow + 0.0800f; break;
        case 11: norm_outflow = 0.9786f * norm_inflow + 0.0739f; break;
        case 12: norm_outflow = 1.0182f * norm_inflow + 0.0725f; break;
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
        case  1: norm_outflow = (norm_storage <= 0.9587f) ? 0.6268f * norm_storage + -0.2562f : 0.2993f * norm_storage + (0.6268f * 0.9587f + -0.2562f - 0.2993f * 0.9587f); break;
        case  2: norm_outflow = (norm_storage <= 0.9638f) ? 0.6614f * norm_storage + -0.2709f : 0.2406f * norm_storage + (0.6614f * 0.9638f + -0.2709f - 0.2406f * 0.9638f); break;
        case  3: norm_outflow = (norm_storage <= 0.9611f) ? 0.7260f * norm_storage + -0.2995f : 0.2475f * norm_storage + (0.7260f * 0.9611f + -0.2995f - 0.2475f * 0.9611f); break;
        case  4: norm_outflow = (norm_storage <= 0.9374f) ? 0.8607f * norm_storage + -0.3776f : 0.4800f * norm_storage + (0.8607f * 0.9374f + -0.3776f - 0.4800f * 0.9374f); break;
        case  5: norm_outflow = (norm_storage <= 0.9337f) ? 0.9116f * norm_storage + -0.4032f : 0.6961f * norm_storage + (0.9116f * 0.9337f + -0.4032f - 0.6961f * 0.9337f); break;
        case  6: norm_outflow = (norm_storage <= 0.9263f) ? 0.9012f * norm_storage + -0.3986f : 0.9085f * norm_storage + (0.9012f * 0.9263f + -0.3986f - 0.9085f * 0.9263f); break;
        case  7: norm_outflow = (norm_storage <= 0.9297f) ? 0.8527f * norm_storage + -0.3634f : 0.5467f * norm_storage + (0.8527f * 0.9297f + -0.3634f - 0.5467f * 0.9297f); break;
        case  8: norm_outflow = (norm_storage <= 0.9017f) ? 0.6527f * norm_storage + -0.2575f : 0.9272f * norm_storage + (0.6527f * 0.9017f + -0.2575f - 0.9272f * 0.9017f); break;
        case  9: norm_outflow = (norm_storage <= 0.8917f) ? 0.6171f * norm_storage + -0.2425f : 1.0652f * norm_storage + (0.6171f * 0.8917f + -0.2425f - 1.0652f * 0.8917f); break;
        case 10: norm_outflow = (norm_storage <= 0.9169f) ? 0.6013f * norm_storage + -0.2260f : 0.6898f * norm_storage + (0.6013f * 0.9169f + -0.2260f - 0.6898f * 0.9169f); break;
        case 11: norm_outflow = (norm_storage <= 0.9524f) ? 0.6156f * norm_storage + -0.2286f : 0.3509f * norm_storage + (0.6156f * 0.9524f + -0.2286f - 0.3509f * 0.9524f); break;
        case 12: norm_outflow = (norm_storage <= 0.9573f) ? 0.6183f * norm_storage + -0.2406f : 0.3167f * norm_storage + (0.6183f * 0.9573f + -0.2406f - 0.3167f * 0.9573f); break;
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
        case  1: norm_outflow = (norm_storage <= 0.9917f) ? 1.0972f * norm_storage + -0.1565f : 0.0363f * norm_storage + (1.0972f * 0.9917f + -0.1565f - 0.0363f * 0.9917f); break;
        case  2: norm_outflow = (norm_storage <= 0.9907f) ? 1.0848f * norm_storage + -0.1378f : 0.0521f * norm_storage + (1.0848f * 0.9907f + -0.1378f - 0.0521f * 0.9907f); break;
        case  3: norm_outflow = (norm_storage <= 0.9928f) ? 1.0886f * norm_storage + -0.1849f : 0.0341f * norm_storage + (1.0886f * 0.9928f + -0.1849f - 0.0341f * 0.9928f); break;
        case  4: norm_outflow = (norm_storage <= 0.9869f) ? 1.0100f * norm_storage + -0.2033f : 0.0506f * norm_storage + (1.0100f * 0.9869f + -0.2033f - 0.0506f * 0.9869f); break;
        case  5: norm_outflow = (norm_storage <= 0.9893f) ? 1.1056f * norm_storage + -0.2605f : 0.2001f * norm_storage + (1.1056f * 0.9893f + -0.2605f - 0.2001f * 0.9893f); break;
        case  6: norm_outflow = (norm_storage <= 0.9802f) ? 1.1302f * norm_storage + -0.2831f : 0.2447f * norm_storage + (1.1302f * 0.9802f + -0.2831f - 0.2447f * 0.9802f); break;
        case  7: norm_outflow = (norm_storage <= 0.9923f) ? 1.2425f * norm_storage + -0.3176f : 0.1897f * norm_storage + (1.2425f * 0.9923f + -0.3176f - 0.1897f * 0.9923f); break;
        case  8: norm_outflow = (norm_storage <= 0.9951f) ? 1.3250f * norm_storage + -0.3015f : 0.0327f * norm_storage + (1.3250f * 0.9951f + -0.3015f - 0.0327f * 0.9951f); break;
        case  9: norm_outflow = (norm_storage <= 0.9933f) ? 1.2726f * norm_storage + -0.2718f : 0.0430f * norm_storage + (1.2726f * 0.9933f + -0.2718f - 0.0430f * 0.9933f); break;
        case 10: norm_outflow = 1.1683f * norm_inflow + 0.0572f; break;
        case 11: norm_outflow = 1.1566f * norm_inflow + 0.0628f; break;
        case 12: norm_outflow = (norm_storage <= 0.9931f) ? 1.1857f * norm_storage + -0.1748f : 0.0357f * norm_storage + (1.1857f * 0.9931f + -0.1748f - 0.0357f * 0.9931f); break;
    }
    return norm_outflow * max_outflow_m3d;
}

static float rule_2789(float inflow_m3d, float storage_m3, int month) {
    const float max_inflow_m3d   = 5789168.9f;
    const float max_outflow_m3d  = 907719.6f;
    const float max_storage_m3   = 24724983.2f;
    const float norm_inflow  = inflow_m3d  / max_inflow_m3d;
    const float norm_storage = storage_m3  / max_storage_m3;
    float norm_outflow;

    switch (month) {
        case  1: norm_outflow = 2.9475f * norm_inflow + 0.0232f; break;
        case  2: norm_outflow = 2.8798f * norm_inflow + 0.0234f; break;
        case  3: norm_outflow = 2.7396f * norm_inflow + 0.0266f; break;
        case  4: norm_outflow = 2.6900f * norm_inflow + 0.0302f; break;
        case  5: norm_outflow = 2.6875f * norm_inflow + 0.0322f; break;
        case  6: norm_outflow = 2.6761f * norm_inflow + 0.0330f; break;
        case  7: norm_outflow = (norm_storage <= 0.8119f) ? 0.1699f * norm_storage + -0.0198f : 2.4792f * norm_storage + (0.1699f * 0.8119f + -0.0198f - 2.4792f * 0.8119f); break;
        case  8: norm_outflow = (norm_storage <= 0.8041f) ? 0.1594f * norm_storage + -0.0220f : 2.9116f * norm_storage + (0.1594f * 0.8041f + -0.0220f - 2.9116f * 0.8041f); break;
        case  9: norm_outflow = (norm_storage <= 0.8005f) ? 0.1443f * norm_storage + -0.0196f : 2.9001f * norm_storage + (0.1443f * 0.8005f + -0.0196f - 2.9001f * 0.8005f); break;
        case 10: norm_outflow = (norm_storage <= 0.8017f) ? 0.1503f * norm_storage + -0.0264f : 2.6952f * norm_storage + (0.1503f * 0.8017f + -0.0264f - 2.6952f * 0.8017f); break;
        case 11: norm_outflow = 2.8574f * norm_inflow + 0.0236f; break;
        case 12: norm_outflow = 2.9402f * norm_inflow + 0.0227f; break;
    }
    return norm_outflow * max_outflow_m3d;
}

static float rule_2794(float inflow_m3d, float storage_m3, int month) {
    const float max_inflow_m3d   = 10683079.1f;
    const float max_outflow_m3d  = 324691.5f;
    const float max_storage_m3   = 57356943.4f;
    const float norm_inflow  = inflow_m3d  / max_inflow_m3d;
    const float norm_storage = storage_m3  / max_storage_m3;
    float norm_outflow;

    switch (month) {
        case  1: norm_outflow = (norm_storage <= 0.8968f) ? 0.1130f * norm_storage + 0.0069f : 5.3774f * norm_storage + (0.1130f * 0.8968f + 0.0069f - 5.3774f * 0.8968f); break;
        case  2: norm_outflow = (norm_storage <= 0.8825f) ? 0.1122f * norm_storage + 0.0076f : 4.6549f * norm_storage + (0.1122f * 0.8825f + 0.0076f - 4.6549f * 0.8825f); break;
        case  3: norm_outflow = (norm_storage <= 0.8539f) ? 0.1129f * norm_storage + 0.0099f : 5.5783f * norm_storage + (0.1129f * 0.8539f + 0.0099f - 5.5783f * 0.8539f); break;
        case  4: norm_outflow = (norm_storage <= 0.8579f) ? 0.1142f * norm_storage + 0.0220f : 6.8771f * norm_storage + (0.1142f * 0.8579f + 0.0220f - 6.8771f * 0.8579f); break;
        case  5: norm_outflow = (norm_storage <= 0.8678f) ? 0.1168f * norm_storage + 0.0297f : 9.2310f * norm_storage + (0.1168f * 0.8678f + 0.0297f - 9.2310f * 0.8678f); break;
        case  6: norm_outflow = (norm_storage <= 0.8794f) ? 0.1337f * norm_storage + 0.0302f : 10.0207f * norm_storage + (0.1337f * 0.8794f + 0.0302f - 10.0207f * 0.8794f); break;
        case  7: norm_outflow = (norm_storage <= 0.8804f) ? 0.1638f * norm_storage + 0.0238f : 9.2734f * norm_storage + (0.1638f * 0.8804f + 0.0238f - 9.2734f * 0.8804f); break;
        case  8: norm_outflow = (norm_storage <= 0.8784f) ? 0.1099f * norm_storage + 0.0394f : 10.5315f * norm_storage + (0.1099f * 0.8784f + 0.0394f - 10.5315f * 0.8784f); break;
        case  9: norm_outflow = (norm_storage <= 0.9237f) ? 0.1365f * norm_storage + 0.0197f : 4.3976f * norm_storage + (0.1365f * 0.9237f + 0.0197f - 4.3976f * 0.9237f); break;
        case 10: norm_outflow = 1.0828f * norm_inflow + 0.0310f; break;
        case 11: norm_outflow = 1.2534f * norm_inflow + 0.0311f; break;
        case 12: norm_outflow = 1.2700f * norm_inflow + 0.0291f; break;
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
        case  1: norm_outflow = 1.0179f * norm_inflow + 0.0228f; break;
        case  2: norm_outflow = 1.0229f * norm_inflow + 0.0177f; break;
        case  3: norm_outflow = 1.0810f * norm_inflow + 0.0145f; break;
        case  4: norm_outflow = 1.1001f * norm_inflow + 0.0186f; break;
        case  5: norm_outflow = 1.1401f * norm_inflow + 0.0247f; break;
        case  6: norm_outflow = 1.1098f * norm_inflow + 0.0270f; break;
        case  7: norm_outflow = 1.1321f * norm_inflow + 0.0274f; break;
        case  8: norm_outflow = 1.1287f * norm_inflow + 0.0248f; break;
        case  9: norm_outflow = 1.0888f * norm_inflow + 0.0218f; break;
        case 10: norm_outflow = 1.0645f * norm_inflow + 0.0180f; break;
        case 11: norm_outflow = 1.1017f * norm_inflow + 0.0174f; break;
        case 12: norm_outflow = 1.0916f * norm_inflow + 0.0194f; break;
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
        case  1: norm_outflow = (norm_storage <= 0.9829f) ? 2.1195f * norm_storage + -1.0337f : 0.3145f * norm_storage + (2.1195f * 0.9829f + -1.0337f - 0.3145f * 0.9829f); break;
        case  2: norm_outflow = (norm_storage <= 0.9784f) ? 2.0613f * norm_storage + -0.9976f : 0.3544f * norm_storage + (2.0613f * 0.9784f + -0.9976f - 0.3544f * 0.9784f); break;
        case  3: norm_outflow = (norm_storage <= 0.9852f) ? 2.1559f * norm_storage + -1.0656f : 0.2528f * norm_storage + (2.1559f * 0.9852f + -1.0656f - 0.2528f * 0.9852f); break;
        case  4: norm_outflow = (norm_storage <= 0.9778f) ? 2.1125f * norm_storage + -1.0546f : 0.4046f * norm_storage + (2.1125f * 0.9778f + -1.0546f - 0.4046f * 0.9778f); break;
        case  5: norm_outflow = (norm_storage <= 0.9665f) ? 2.0473f * norm_storage + -1.0341f : 0.6354f * norm_storage + (2.0473f * 0.9665f + -1.0341f - 0.6354f * 0.9665f); break;
        case  6: norm_outflow = (norm_storage <= 0.9717f) ? 2.1459f * norm_storage + -1.0939f : 0.5263f * norm_storage + (2.1459f * 0.9717f + -1.0939f - 0.5263f * 0.9717f); break;
        case  7: norm_outflow = (norm_storage <= 0.9531f) ? 1.8808f * norm_storage + -0.9537f : 0.9561f * norm_storage + (1.8808f * 0.9531f + -0.9537f - 0.9561f * 0.9531f); break;
        case  8: norm_outflow = (norm_storage <= 0.9622f) ? 1.8156f * norm_storage + -0.9078f : 0.6529f * norm_storage + (1.8156f * 0.9622f + -0.9078f - 0.6529f * 0.9622f); break;
        case  9: norm_outflow = (norm_storage <= 0.9615f) ? 1.7989f * norm_storage + -0.8964f : 0.6484f * norm_storage + (1.7989f * 0.9615f + -0.8964f - 0.6484f * 0.9615f); break;
        case 10: norm_outflow = 1.2752f * norm_inflow + 0.0236f; break;
        case 11: norm_outflow = 1.2922f * norm_inflow + 0.0281f; break;
        case 12: norm_outflow = (norm_storage <= 0.9788f) ? 2.0279f * norm_storage + -0.9853f : 0.3958f * norm_storage + (2.0279f * 0.9788f + -0.9853f - 0.3958f * 0.9788f); break;
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
        case  1: norm_outflow = (norm_storage <= 0.9959f) ? 1.0543f * norm_storage + -0.0967f : 0.0426f * norm_storage + (1.0543f * 0.9959f + -0.0967f - 0.0426f * 0.9959f); break;
        case  2: norm_outflow = (norm_storage <= 0.9934f) ? 1.0092f * norm_storage + -0.0936f : 0.0835f * norm_storage + (1.0092f * 0.9934f + -0.0936f - 0.0835f * 0.9934f); break;
        case  3: norm_outflow = (norm_storage <= 0.9965f) ? 1.0679f * norm_storage + -0.1015f : 0.0401f * norm_storage + (1.0679f * 0.9965f + -0.1015f - 0.0401f * 0.9965f); break;
        case  4: norm_outflow = (norm_storage <= 0.9940f) ? 1.0375f * norm_storage + -0.1198f : 0.0443f * norm_storage + (1.0375f * 0.9940f + -0.1198f - 0.0443f * 0.9940f); break;
        case  5: norm_outflow = (norm_storage <= 0.9974f) ? 1.1832f * norm_storage + -0.1863f : 0.0165f * norm_storage + (1.1832f * 0.9974f + -0.1863f - 0.0165f * 0.9974f); break;
        case  6: norm_outflow = (norm_storage <= 0.9953f) ? 1.4340f * norm_storage + -0.2816f : 0.0218f * norm_storage + (1.4340f * 0.9953f + -0.2816f - 0.0218f * 0.9953f); break;
        case  7: norm_outflow = (norm_storage <= 0.9974f) ? 1.8550f * norm_storage + -0.4351f : 0.0183f * norm_storage + (1.8550f * 0.9974f + -0.4351f - 0.0183f * 0.9974f); break;
        case  8: norm_outflow = (norm_storage <= 0.9968f) ? 1.8013f * norm_storage + -0.3898f : 0.0285f * norm_storage + (1.8013f * 0.9968f + -0.3898f - 0.0285f * 0.9968f); break;
        case  9: norm_outflow = (norm_storage <= 0.9975f) ? 1.5710f * norm_storage + -0.3070f : 0.0216f * norm_storage + (1.5710f * 0.9975f + -0.3070f - 0.0216f * 0.9975f); break;
        case 10: norm_outflow = (norm_storage <= 0.9974f) ? 1.5154f * norm_storage + -0.2820f : 0.0219f * norm_storage + (1.5154f * 0.9974f + -0.2820f - 0.0219f * 0.9974f); break;
        case 11: norm_outflow = (norm_storage <= 0.9979f) ? 1.3592f * norm_storage + -0.2287f : 0.0172f * norm_storage + (1.3592f * 0.9979f + -0.2287f - 0.0172f * 0.9979f); break;
        case 12: norm_outflow = (norm_storage <= 0.9966f) ? 1.2170f * norm_storage + -0.1663f : 0.0284f * norm_storage + (1.2170f * 0.9966f + -0.1663f - 0.0284f * 0.9966f); break;
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
        case  1: norm_outflow = 0.5854f * norm_inflow + 0.0280f; break;
        case  2: norm_outflow = 0.5888f * norm_inflow + 0.0297f; break;
        case  3: norm_outflow = 0.5805f * norm_inflow + 0.0295f; break;
        case  4: norm_outflow = 0.6388f * norm_inflow + 0.0326f; break;
        case  5: norm_outflow = 0.7503f * norm_inflow + 0.0312f; break;
        case  6: norm_outflow = 0.7717f * norm_inflow + 0.0351f; break;
        case  7: norm_outflow = 0.7924f * norm_inflow + 0.0391f; break;
        case  8: norm_outflow = 0.7063f * norm_inflow + 0.0411f; break;
        case  9: norm_outflow = 0.6106f * norm_inflow + 0.0393f; break;
        case 10: norm_outflow = 0.5862f * norm_inflow + 0.0345f; break;
        case 11: norm_outflow = 0.5906f * norm_inflow + 0.0306f; break;
        case 12: norm_outflow = 0.5999f * norm_inflow + 0.0271f; break;
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
        case  1: norm_outflow = (norm_storage <= 0.9811f) ? 1.5866f * norm_storage + -0.5452f : 0.2257f * norm_storage + (1.5866f * 0.9811f + -0.5452f - 0.2257f * 0.9811f); break;
        case  2: norm_outflow = (norm_storage <= 0.9707f) ? 1.4899f * norm_storage + -0.5146f : 0.3616f * norm_storage + (1.4899f * 0.9707f + -0.5146f - 0.3616f * 0.9707f); break;
        case  3: norm_outflow = (norm_storage <= 0.9631f) ? 1.4899f * norm_storage + -0.5212f : 0.3848f * norm_storage + (1.4899f * 0.9631f + -0.5212f - 0.3848f * 0.9631f); break;
        case  4: norm_outflow = (norm_storage <= 0.9618f) ? 1.5679f * norm_storage + -0.5631f : 0.4091f * norm_storage + (1.5679f * 0.9618f + -0.5631f - 0.4091f * 0.9618f); break;
        case  5: norm_outflow = (norm_storage <= 0.9663f) ? 1.6477f * norm_storage + -0.6022f : 0.4814f * norm_storage + (1.6477f * 0.9663f + -0.6022f - 0.4814f * 0.9663f); break;
        case  6: norm_outflow = (norm_storage <= 0.9745f) ? 2.1710f * norm_storage + -0.8491f : 0.3186f * norm_storage + (2.1710f * 0.9745f + -0.8491f - 0.3186f * 0.9745f); break;
        case  7: norm_outflow = (norm_storage <= 0.9743f) ? 2.2392f * norm_storage + -0.8737f : 0.3325f * norm_storage + (2.2392f * 0.9743f + -0.8737f - 0.3325f * 0.9743f); break;
        case  8: norm_outflow = (norm_storage <= 0.9893f) ? 2.1836f * norm_storage + -0.8198f : 0.1262f * norm_storage + (2.1836f * 0.9893f + -0.8198f - 0.1262f * 0.9893f); break;
        case  9: norm_outflow = (norm_storage <= 0.9900f) ? 2.0118f * norm_storage + -0.7447f : 0.1187f * norm_storage + (2.0118f * 0.9900f + -0.7447f - 0.1187f * 0.9900f); break;
        case 10: norm_outflow = (norm_storage <= 0.9904f) ? 1.9961f * norm_storage + -0.7372f : 0.1160f * norm_storage + (1.9961f * 0.9904f + -0.7372f - 0.1160f * 0.9904f); break;
        case 11: norm_outflow = (norm_storage <= 0.9907f) ? 2.0240f * norm_storage + -0.7501f : 0.1076f * norm_storage + (2.0240f * 0.9907f + -0.7501f - 0.1076f * 0.9907f); break;
        case 12: norm_outflow = (norm_storage <= 0.9810f) ? 1.9465f * norm_storage + -0.7104f : 0.2384f * norm_storage + (1.9465f * 0.9810f + -0.7104f - 0.2384f * 0.9810f); break;
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
        case  1: norm_outflow = 1.3534f * norm_inflow + 0.0220f; break;
        case  2: norm_outflow = 1.3402f * norm_inflow + 0.0206f; break;
        case  3: norm_outflow = 1.3287f * norm_inflow + 0.0218f; break;
        case  4: norm_outflow = 1.2680f * norm_inflow + 0.0207f; break;
        case  5: norm_outflow = 1.2708f * norm_inflow + 0.0208f; break;
        case  6: norm_outflow = 1.2896f * norm_inflow + 0.0219f; break;
        case  7: norm_outflow = 1.2772f * norm_inflow + 0.0212f; break;
        case  8: norm_outflow = 1.2701f * norm_inflow + 0.0201f; break;
        case  9: norm_outflow = 1.2324f * norm_inflow + 0.0208f; break;
        case 10: norm_outflow = 1.2712f * norm_inflow + 0.0245f; break;
        case 11: norm_outflow = 1.3372f * norm_inflow + 0.0250f; break;
        case 12: norm_outflow = 1.3466f * norm_inflow + 0.0232f; break;
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
        case  1: norm_outflow = 0.5915f * norm_inflow + 0.0315f; break;
        case  2: norm_outflow = 0.5812f * norm_inflow + 0.0322f; break;
        case  3: norm_outflow = 0.6491f * norm_inflow + 0.0366f; break;
        case  4: norm_outflow = 0.8171f * norm_inflow + 0.0415f; break;
        case  5: norm_outflow = 1.1399f * norm_inflow + 0.0461f; break;
        case  6: norm_outflow = 1.1815f * norm_inflow + 0.0506f; break;
        case  7: norm_outflow = 1.2405f * norm_inflow + 0.0471f; break;
        case  8: norm_outflow = 1.0275f * norm_inflow + 0.0455f; break;
        case  9: norm_outflow = 0.8614f * norm_inflow + 0.0400f; break;
        case 10: norm_outflow = 0.7305f * norm_inflow + 0.0351f; break;
        case 11: norm_outflow = 0.6377f * norm_inflow + 0.0325f; break;
        case 12: norm_outflow = 0.6366f * norm_inflow + 0.0321f; break;
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
        case  1: norm_outflow = (norm_storage <= 0.9203f) ? 0.2274f * norm_storage + -0.0273f : 1.1927f * norm_storage + (0.2274f * 0.9203f + -0.0273f - 1.1927f * 0.9203f); break;
        case  2: norm_outflow = 0.3358f * norm_inflow + 0.0485f; break;
        case  3: norm_outflow = 0.3416f * norm_inflow + 0.0513f; break;
        case  4: norm_outflow = 0.4238f * norm_inflow + 0.0538f; break;
        case  5: norm_outflow = 0.5931f * norm_inflow + 0.0515f; break;
        case  6: norm_outflow = 0.6323f * norm_inflow + 0.0526f; break;
        case  7: norm_outflow = 0.6734f * norm_inflow + 0.0557f; break;
        case  8: norm_outflow = 0.5225f * norm_inflow + 0.0619f; break;
        case  9: norm_outflow = 0.3959f * norm_inflow + 0.0582f; break;
        case 10: norm_outflow = 0.3540f * norm_inflow + 0.0570f; break;
        case 11: norm_outflow = 0.3659f * norm_inflow + 0.0520f; break;
        case 12: norm_outflow = (norm_storage <= 0.9268f) ? 0.2326f * norm_storage + -0.0258f : 1.0162f * norm_storage + (0.2326f * 0.9268f + -0.0258f - 1.0162f * 0.9268f); break;
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
        case  1: norm_outflow = (norm_storage <= 0.6419f) ? 0.0800f * norm_storage + -0.0319f : 6.3832f * norm_storage + (0.0800f * 0.6419f + -0.0319f - 6.3832f * 0.6419f); break;
        case  2: norm_outflow = (norm_storage <= 0.6388f) ? 0.0808f * norm_storage + -0.0318f : 6.3143f * norm_storage + (0.0808f * 0.6388f + -0.0318f - 6.3143f * 0.6388f); break;
        case  3: norm_outflow = (norm_storage <= 0.6383f) ? 0.0930f * norm_storage + -0.0382f : 6.2570f * norm_storage + (0.0930f * 0.6383f + -0.0382f - 6.2570f * 0.6383f); break;
        case  4: norm_outflow = (norm_storage <= 0.6435f) ? 0.1374f * norm_storage + -0.0633f : 6.0207f * norm_storage + (0.1374f * 0.6435f + -0.0633f - 6.0207f * 0.6435f); break;
        case  5: norm_outflow = (norm_storage <= 0.6619f) ? 0.2101f * norm_storage + -0.0976f : 6.2798f * norm_storage + (0.2101f * 0.6619f + -0.0976f - 6.2798f * 0.6619f); break;
        case  6: norm_outflow = (norm_storage <= 0.6608f) ? 0.2016f * norm_storage + -0.0914f : 6.0370f * norm_storage + (0.2016f * 0.6608f + -0.0914f - 6.0370f * 0.6608f); break;
        case  7: norm_outflow = (norm_storage <= 0.6550f) ? 0.1901f * norm_storage + -0.0874f : 5.8875f * norm_storage + (0.1901f * 0.6550f + -0.0874f - 5.8875f * 0.6550f); break;
        case  8: norm_outflow = (norm_storage <= 0.6397f) ? 0.0877f * norm_storage + -0.0334f : 5.9219f * norm_storage + (0.0877f * 0.6397f + -0.0334f - 5.9219f * 0.6397f); break;
        case  9: norm_outflow = (norm_storage <= 0.6387f) ? 0.0822f * norm_storage + -0.0296f : 5.9866f * norm_storage + (0.0822f * 0.6387f + -0.0296f - 5.9866f * 0.6387f); break;
        case 10: norm_outflow = (norm_storage <= 0.6322f) ? 0.0483f * norm_storage + -0.0132f : 5.9881f * norm_storage + (0.0483f * 0.6322f + -0.0132f - 5.9881f * 0.6322f); break;
        case 11: norm_outflow = (norm_storage <= 0.6380f) ? 0.0545f * norm_storage + -0.0143f : 6.0501f * norm_storage + (0.0545f * 0.6380f + -0.0143f - 6.0501f * 0.6380f); break;
        case 12: norm_outflow = (norm_storage <= 0.6364f) ? 0.0572f * norm_storage + -0.0178f : 6.2378f * norm_storage + (0.0572f * 0.6364f + -0.0178f - 6.2378f * 0.6364f); break;
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
        case  1: norm_outflow = (norm_storage <= 0.9896f) ? 1.7254f * norm_storage + -0.3086f : 0.1185f * norm_storage + (1.7254f * 0.9896f + -0.3086f - 0.1185f * 0.9896f); break;
        case  2: norm_outflow = (norm_storage <= 0.9914f) ? 1.6606f * norm_storage + -0.2764f : 0.0855f * norm_storage + (1.6606f * 0.9914f + -0.2764f - 0.0855f * 0.9914f); break;
        case  3: norm_outflow = (norm_storage <= 0.9898f) ? 1.7011f * norm_storage + -0.3415f : 0.0779f * norm_storage + (1.7011f * 0.9898f + -0.3415f - 0.0779f * 0.9898f); break;
        case  4: norm_outflow = (norm_storage <= 0.9887f) ? 1.7152f * norm_storage + -0.3752f : 0.1212f * norm_storage + (1.7152f * 0.9887f + -0.3752f - 0.1212f * 0.9887f); break;
        case  5: norm_outflow = (norm_storage <= 0.9790f) ? 2.1391f * norm_storage + -0.7070f : 0.1957f * norm_storage + (2.1391f * 0.9790f + -0.7070f - 0.1957f * 0.9790f); break;
        case  6: norm_outflow = (norm_storage <= 0.9730f) ? 2.2133f * norm_storage + -0.7893f : 0.3153f * norm_storage + (2.2133f * 0.9730f + -0.7893f - 0.3153f * 0.9730f); break;
        case  7: norm_outflow = (norm_storage <= 0.9684f) ? 2.0478f * norm_storage + -0.6845f : 0.4137f * norm_storage + (2.0478f * 0.9684f + -0.6845f - 0.4137f * 0.9684f); break;
        case  8: norm_outflow = (norm_storage <= 0.9833f) ? 1.8576f * norm_storage + -0.5003f : 0.2199f * norm_storage + (1.8576f * 0.9833f + -0.5003f - 0.2199f * 0.9833f); break;
        case  9: norm_outflow = (norm_storage <= 0.9814f) ? 1.7245f * norm_storage + -0.4287f : 0.2387f * norm_storage + (1.7245f * 0.9814f + -0.4287f - 0.2387f * 0.9814f); break;
        case 10: norm_outflow = (norm_storage <= 0.9808f) ? 1.7284f * norm_storage + -0.3982f : 0.2603f * norm_storage + (1.7284f * 0.9808f + -0.3982f - 0.2603f * 0.9808f); break;
        case 11: norm_outflow = 1.2691f * norm_inflow + 0.0385f; break;
        case 12: norm_outflow = (norm_storage <= 0.9900f) ? 1.9135f * norm_storage + -0.3921f : 0.1343f * norm_storage + (1.9135f * 0.9900f + -0.3921f - 0.1343f * 0.9900f); break;
    }
    return norm_outflow * max_outflow_m3d;
}

static float rule_2893(float inflow_m3d, float storage_m3, int month) {
    const float max_inflow_m3d   = 45730844.1f;
    const float max_outflow_m3d  = 7608823.5f;
    const float max_storage_m3   = 178147816.0f;
    const float norm_inflow  = inflow_m3d  / max_inflow_m3d;
    const float norm_storage = storage_m3  / max_storage_m3;
    float norm_outflow;

    switch (month) {
        case  1: norm_outflow = (norm_storage <= 0.9799f) ? 0.5882f * norm_storage + -0.1576f : 0.6166f * norm_storage + (0.5882f * 0.9799f + -0.1576f - 0.6166f * 0.9799f); break;
        case  2: norm_outflow = (norm_storage <= 0.9818f) ? 0.6212f * norm_storage + -0.1734f : 0.5424f * norm_storage + (0.6212f * 0.9818f + -0.1734f - 0.5424f * 0.9818f); break;
        case  3: norm_outflow = (norm_storage <= 0.9843f) ? 0.7228f * norm_storage + -0.2106f : 0.5094f * norm_storage + (0.7228f * 0.9843f + -0.2106f - 0.5094f * 0.9843f); break;
        case  4: norm_outflow = (norm_storage <= 0.9819f) ? 0.8275f * norm_storage + -0.2504f : 0.6965f * norm_storage + (0.8275f * 0.9819f + -0.2504f - 0.6965f * 0.9819f); break;
        case  5: norm_outflow = (norm_storage <= 0.9569f) ? 0.8439f * norm_storage + -0.2713f : 7.2099f * norm_storage + (0.8439f * 0.9569f + -0.2713f - 7.2099f * 0.9569f); break;
        case  6: norm_outflow = (norm_storage <= 0.9646f) ? 0.9124f * norm_storage + -0.3058f : 6.5158f * norm_storage + (0.9124f * 0.9646f + -0.3058f - 6.5158f * 0.9646f); break;
        case  7: norm_outflow = (norm_storage <= 0.9713f) ? 0.8772f * norm_storage + -0.2730f : 3.6672f * norm_storage + (0.8772f * 0.9713f + -0.2730f - 3.6672f * 0.9713f); break;
        case  8: norm_outflow = (norm_storage <= 0.9689f) ? 0.8503f * norm_storage + -0.2527f : 0.9650f * norm_storage + (0.8503f * 0.9689f + -0.2527f - 0.9650f * 0.9689f); break;
        case  9: norm_outflow = (norm_storage <= 0.9838f) ? 0.7839f * norm_storage + -0.2258f : 0.2888f * norm_storage + (0.7839f * 0.9838f + -0.2258f - 0.2888f * 0.9838f); break;
        case 10: norm_outflow = (norm_storage <= 0.9876f) ? 0.6903f * norm_storage + -0.1927f : 0.2075f * norm_storage + (0.6903f * 0.9876f + -0.1927f - 0.2075f * 0.9876f); break;
        case 11: norm_outflow = (norm_storage <= 0.9864f) ? 0.6307f * norm_storage + -0.1742f : 0.2780f * norm_storage + (0.6307f * 0.9864f + -0.1742f - 0.2780f * 0.9864f); break;
        case 12: norm_outflow = (norm_storage <= 0.9834f) ? 0.6027f * norm_storage + -0.1631f : 0.4030f * norm_storage + (0.6027f * 0.9834f + -0.1631f - 0.4030f * 0.9834f); break;
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
        case  1: norm_outflow = 1.8786f * norm_inflow + 0.0571f; break;
        case  2: norm_outflow = 1.8425f * norm_inflow + 0.0550f; break;
        case  3: norm_outflow = 1.8376f * norm_inflow + 0.0536f; break;
        case  4: norm_outflow = 1.8957f * norm_inflow + 0.0500f; break;
        case  5: norm_outflow = 1.9289f * norm_inflow + 0.0477f; break;
        case  6: norm_outflow = 1.9770f * norm_inflow + 0.0446f; break;
        case  7: norm_outflow = 2.0010f * norm_inflow + 0.0436f; break;
        case  8: norm_outflow = 2.1198f * norm_inflow + 0.0419f; break;
        case  9: norm_outflow = 2.0716f * norm_inflow + 0.0443f; break;
        case 10: norm_outflow = 2.0801f * norm_inflow + 0.0486f; break;
        case 11: norm_outflow = 1.9254f * norm_inflow + 0.0532f; break;
        case 12: norm_outflow = 1.9115f * norm_inflow + 0.0540f; break;
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
        case  1: norm_outflow = 2.0884f * norm_inflow + 0.0553f; break;
        case  2: norm_outflow = 2.0506f * norm_inflow + 0.0550f; break;
        case  3: norm_outflow = 1.9682f * norm_inflow + 0.0534f; break;
        case  4: norm_outflow = 2.0916f * norm_inflow + 0.0511f; break;
        case  5: norm_outflow = 2.0669f * norm_inflow + 0.0457f; break;
        case  6: norm_outflow = 2.1142f * norm_inflow + 0.0459f; break;
        case  7: norm_outflow = 2.0947f * norm_inflow + 0.0420f; break;
        case  8: norm_outflow = 2.1913f * norm_inflow + 0.0446f; break;
        case  9: norm_outflow = 2.0752f * norm_inflow + 0.0451f; break;
        case 10: norm_outflow = 2.1601f * norm_inflow + 0.0490f; break;
        case 11: norm_outflow = 2.1640f * norm_inflow + 0.0519f; break;
        case 12: norm_outflow = 2.0578f * norm_inflow + 0.0538f; break;
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
        case  1: norm_outflow = (norm_storage <= 0.9952f) ? 1.6923f * norm_storage + -0.3626f : 0.0228f * norm_storage + (1.6923f * 0.9952f + -0.3626f - 0.0228f * 0.9952f); break;
        case  2: norm_outflow = (norm_storage <= 0.9938f) ? 1.5454f * norm_storage + -0.3235f : 0.0304f * norm_storage + (1.5454f * 0.9938f + -0.3235f - 0.0304f * 0.9938f); break;
        case  3: norm_outflow = (norm_storage <= 0.9924f) ? 1.4948f * norm_storage + -0.3302f : 0.0308f * norm_storage + (1.4948f * 0.9924f + -0.3302f - 0.0308f * 0.9924f); break;
        case  4: norm_outflow = (norm_storage <= 0.9928f) ? 1.5940f * norm_storage + -0.3813f : 0.0296f * norm_storage + (1.5940f * 0.9928f + -0.3813f - 0.0296f * 0.9928f); break;
        case  5: norm_outflow = (norm_storage <= 0.9868f) ? 1.7531f * norm_storage + -0.4979f : 0.0642f * norm_storage + (1.7531f * 0.9868f + -0.4979f - 0.0642f * 0.9868f); break;
        case  6: norm_outflow = (norm_storage <= 0.9910f) ? 1.9916f * norm_storage + -0.5967f : 0.0486f * norm_storage + (1.9916f * 0.9910f + -0.5967f - 0.0486f * 0.9910f); break;
        case  7: norm_outflow = 1.6997f * norm_inflow + 0.0295f; break;
        case  8: norm_outflow = 1.7371f * norm_inflow + 0.0300f; break;
        case  9: norm_outflow = (norm_storage <= 0.9948f) ? 1.7489f * norm_storage + -0.4419f : 0.0340f * norm_storage + (1.7489f * 0.9948f + -0.4419f - 0.0340f * 0.9948f); break;
        case 10: norm_outflow = 1.5978f * norm_inflow + 0.0399f; break;
        case 11: norm_outflow = 1.5620f * norm_inflow + 0.0458f; break;
        case 12: norm_outflow = (norm_storage <= 0.9944f) ? 1.9483f * norm_storage + -0.4551f : 0.0480f * norm_storage + (1.9483f * 0.9944f + -0.4551f - 0.0480f * 0.9944f); break;
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
        case  1: norm_outflow = 3.1353f * norm_inflow + 0.0509f; break;
        case  2: norm_outflow = 3.1479f * norm_inflow + 0.0482f; break;
        case  3: norm_outflow = 3.1899f * norm_inflow + 0.0464f; break;
        case  4: norm_outflow = 3.2097f * norm_inflow + 0.0449f; break;
        case  5: norm_outflow = 3.2402f * norm_inflow + 0.0434f; break;
        case  6: norm_outflow = 3.2116f * norm_inflow + 0.0443f; break;
        case  7: norm_outflow = 3.2211f * norm_inflow + 0.0455f; break;
        case  8: norm_outflow = 3.2967f * norm_inflow + 0.0450f; break;
        case  9: norm_outflow = 3.2150f * norm_inflow + 0.0490f; break;
        case 10: norm_outflow = 3.1664f * norm_inflow + 0.0504f; break;
        case 11: norm_outflow = 3.0695f * norm_inflow + 0.0533f; break;
        case 12: norm_outflow = 3.1312f * norm_inflow + 0.0516f; break;
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
        case  1: norm_outflow = 1.3311f * norm_inflow + 0.0460f; break;
        case  2: norm_outflow = (norm_storage <= 0.9903f) ? 1.7480f * norm_storage + -0.4597f : 0.1195f * norm_storage + (1.7480f * 0.9903f + -0.4597f - 0.1195f * 0.9903f); break;
        case  3: norm_outflow = (norm_storage <= 0.9892f) ? 1.7877f * norm_storage + -0.5138f : 0.1123f * norm_storage + (1.7877f * 0.9892f + -0.5138f - 0.1123f * 0.9892f); break;
        case  4: norm_outflow = 1.3616f * norm_inflow + 0.0332f; break;
        case  5: norm_outflow = (norm_storage <= 0.9827f) ? 2.3280f * norm_storage + -0.8742f : 0.2239f * norm_storage + (2.3280f * 0.9827f + -0.8742f - 0.2239f * 0.9827f); break;
        case  6: norm_outflow = 1.4190f * norm_inflow + 0.0301f; break;
        case  7: norm_outflow = 1.4221f * norm_inflow + 0.0293f; break;
        case  8: norm_outflow = 1.4169f * norm_inflow + 0.0307f; break;
        case  9: norm_outflow = 1.2677f * norm_inflow + 0.0343f; break;
        case 10: norm_outflow = 1.3692f * norm_inflow + 0.0399f; break;
        case 11: norm_outflow = 1.3163f * norm_inflow + 0.0472f; break;
        case 12: norm_outflow = 1.3247f * norm_inflow + 0.0432f; break;
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
        case  1: norm_outflow = 1.8033f * norm_inflow + 0.0450f; break;
        case  2: norm_outflow = 1.7924f * norm_inflow + 0.0440f; break;
        case  3: norm_outflow = (norm_storage <= 0.9875f) ? 1.7029f * norm_storage + -0.4052f : 0.1787f * norm_storage + (1.7029f * 0.9875f + -0.4052f - 0.1787f * 0.9875f); break;
        case  4: norm_outflow = (norm_storage <= 0.9866f) ? 1.7975f * norm_storage + -0.4696f : 0.1783f * norm_storage + (1.7975f * 0.9866f + -0.4696f - 0.1783f * 0.9866f); break;
        case  5: norm_outflow = (norm_storage <= 0.9882f) ? 2.2161f * norm_storage + -0.7556f : 0.1484f * norm_storage + (2.2161f * 0.9882f + -0.7556f - 0.1484f * 0.9882f); break;
        case  6: norm_outflow = 1.9203f * norm_inflow + 0.0310f; break;
        case  7: norm_outflow = 1.9195f * norm_inflow + 0.0283f; break;
        case  8: norm_outflow = 2.0063f * norm_inflow + 0.0288f; break;
        case  9: norm_outflow = 1.7640f * norm_inflow + 0.0344f; break;
        case 10: norm_outflow = 1.8484f * norm_inflow + 0.0379f; break;
        case 11: norm_outflow = 1.8157f * norm_inflow + 0.0424f; break;
        case 12: norm_outflow = 1.8565f * norm_inflow + 0.0441f; break;
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
        case  1: norm_outflow = (norm_storage <= 0.8975f) ? 2.1544f * norm_storage + -1.1495f : 2.4173f * norm_storage + (2.1544f * 0.8975f + -1.1495f - 2.4173f * 0.8975f); break;
        case  2: norm_outflow = (norm_storage <= 0.8996f) ? 2.2123f * norm_storage + -1.1854f : 2.3698f * norm_storage + (2.2123f * 0.8996f + -1.1854f - 2.3698f * 0.8996f); break;
        case  3: norm_outflow = (norm_storage <= 0.8989f) ? 2.3635f * norm_storage + -1.2910f : 2.4520f * norm_storage + (2.3635f * 0.8989f + -1.2910f - 2.4520f * 0.8989f); break;
        case  4: norm_outflow = (norm_storage <= 0.8888f) ? 2.3388f * norm_storage + -1.2911f : 2.6669f * norm_storage + (2.3388f * 0.8888f + -1.2911f - 2.6669f * 0.8888f); break;
        case  5: norm_outflow = (norm_storage <= 0.9066f) ? 2.5954f * norm_storage + -1.4519f : 2.2114f * norm_storage + (2.5954f * 0.9066f + -1.4519f - 2.2114f * 0.9066f); break;
        case  6: norm_outflow = (norm_storage <= 0.9055f) ? 2.6023f * norm_storage + -1.4683f : 2.3153f * norm_storage + (2.6023f * 0.9055f + -1.4683f - 2.3153f * 0.9055f); break;
        case  7: norm_outflow = (norm_storage <= 0.8654f) ? 2.0067f * norm_storage + -1.1055f : 3.1802f * norm_storage + (2.0067f * 0.8654f + -1.1055f - 3.1802f * 0.8654f); break;
        case  8: norm_outflow = (norm_storage <= 0.8423f) ? 1.6936f * norm_storage + -0.9354f : 3.6706f * norm_storage + (1.6936f * 0.8423f + -0.9354f - 3.6706f * 0.8423f); break;
        case  9: norm_outflow = (norm_storage <= 0.8589f) ? 1.7254f * norm_storage + -0.9336f : 3.2574f * norm_storage + (1.7254f * 0.8589f + -0.9336f - 3.2574f * 0.8589f); break;
        case 10: norm_outflow = (norm_storage <= 0.8513f) ? 1.5607f * norm_storage + -0.8214f : 3.3708f * norm_storage + (1.5607f * 0.8513f + -0.8214f - 3.3708f * 0.8513f); break;
        case 11: norm_outflow = 1.5245f * norm_inflow + 0.0494f; break;
        case 12: norm_outflow = (norm_storage <= 0.8723f) ? 2.0226f * norm_storage + -1.0950f : 3.1402f * norm_storage + (2.0226f * 0.8723f + -1.0950f - 3.1402f * 0.8723f); break;
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
        case  1: norm_outflow = (norm_storage <= 0.9966f) ? 0.4961f * norm_storage + -0.0408f : 0.0375f * norm_storage + (0.4961f * 0.9966f + -0.0408f - 0.0375f * 0.9966f); break;
        case  2: norm_outflow = (norm_storage <= 0.9961f) ? 0.5205f * norm_storage + -0.0436f : 0.0418f * norm_storage + (0.5205f * 0.9961f + -0.0436f - 0.0418f * 0.9961f); break;
        case  3: norm_outflow = (norm_storage <= 0.9968f) ? 0.5711f * norm_storage + -0.0578f : 0.0262f * norm_storage + (0.5711f * 0.9968f + -0.0578f - 0.0262f * 0.9968f); break;
        case  4: norm_outflow = (norm_storage <= 0.9955f) ? 0.5288f * norm_storage + -0.0438f : 0.0346f * norm_storage + (0.5288f * 0.9955f + -0.0438f - 0.0346f * 0.9955f); break;
        case  5: norm_outflow = (norm_storage <= 0.9824f) ? 0.4650f * norm_storage + -0.0379f : 0.2913f * norm_storage + (0.4650f * 0.9824f + -0.0379f - 0.2913f * 0.9824f); break;
        case  6: norm_outflow = (norm_storage <= 0.9859f) ? 0.4761f * norm_storage + -0.0410f : 0.1720f * norm_storage + (0.4761f * 0.9859f + -0.0410f - 0.1720f * 0.9859f); break;
        case  7: norm_outflow = (norm_storage <= 0.9945f) ? 0.5085f * norm_storage + -0.0481f : 0.0328f * norm_storage + (0.5085f * 0.9945f + -0.0481f - 0.0328f * 0.9945f); break;
        case  8: norm_outflow = (norm_storage <= 0.9944f) ? 0.5565f * norm_storage + -0.0584f : 0.0384f * norm_storage + (0.5565f * 0.9944f + -0.0584f - 0.0384f * 0.9944f); break;
        case  9: norm_outflow = (norm_storage <= 0.9961f) ? 0.5549f * norm_storage + -0.0569f : 0.0302f * norm_storage + (0.5549f * 0.9961f + -0.0569f - 0.0302f * 0.9961f); break;
        case 10: norm_outflow = (norm_storage <= 0.9948f) ? 0.5547f * norm_storage + -0.0581f : 0.0598f * norm_storage + (0.5547f * 0.9948f + -0.0581f - 0.0598f * 0.9948f); break;
        case 11: norm_outflow = (norm_storage <= 0.9967f) ? 0.5287f * norm_storage + -0.0522f : 0.0253f * norm_storage + (0.5287f * 0.9967f + -0.0522f - 0.0253f * 0.9967f); break;
        case 12: norm_outflow = (norm_storage <= 0.9968f) ? 0.5239f * norm_storage + -0.0471f : 0.0332f * norm_storage + (0.5239f * 0.9968f + -0.0471f - 0.0332f * 0.9968f); break;
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
        case  1: norm_outflow = 1.8204f * norm_inflow + 0.0450f; break;
        case  2: norm_outflow = 1.7710f * norm_inflow + 0.0443f; break;
        case  3: norm_outflow = 1.7434f * norm_inflow + 0.0411f; break;
        case  4: norm_outflow = (norm_storage <= 0.9875f) ? 1.5098f * norm_storage + -0.3703f : 0.0859f * norm_storage + (1.5098f * 0.9875f + -0.3703f - 0.0859f * 0.9875f); break;
        case  5: norm_outflow = (norm_storage <= 0.9892f) ? 1.7909f * norm_storage + -0.5450f : 0.0539f * norm_storage + (1.7909f * 0.9892f + -0.5450f - 0.0539f * 0.9892f); break;
        case  6: norm_outflow = (norm_storage <= 0.9842f) ? 1.7890f * norm_storage + -0.5621f : 0.0808f * norm_storage + (1.7890f * 0.9842f + -0.5621f - 0.0808f * 0.9842f); break;
        case  7: norm_outflow = 1.9076f * norm_inflow + 0.0285f; break;
        case  8: norm_outflow = 1.9476f * norm_inflow + 0.0276f; break;
        case  9: norm_outflow = 1.7602f * norm_inflow + 0.0338f; break;
        case 10: norm_outflow = 1.8199f * norm_inflow + 0.0364f; break;
        case 11: norm_outflow = 1.8407f * norm_inflow + 0.0414f; break;
        case 12: norm_outflow = 1.8453f * norm_inflow + 0.0421f; break;
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
        case  1: norm_outflow = (norm_storage <= 0.9980f) ? 1.3527f * norm_storage + -0.1119f : 0.0221f * norm_storage + (1.3527f * 0.9980f + -0.1119f - 0.0221f * 0.9980f); break;
        case  2: norm_outflow = (norm_storage <= 0.9978f) ? 1.4004f * norm_storage + -0.1189f : 0.0271f * norm_storage + (1.4004f * 0.9978f + -0.1189f - 0.0271f * 0.9978f); break;
        case  3: norm_outflow = (norm_storage <= 0.9987f) ? 1.4390f * norm_storage + -0.1388f : 0.0222f * norm_storage + (1.4390f * 0.9987f + -0.1388f - 0.0222f * 0.9987f); break;
        case  4: norm_outflow = (norm_storage <= 0.9953f) ? 1.3511f * norm_storage + -0.1433f : 0.0459f * norm_storage + (1.3511f * 0.9953f + -0.1433f - 0.0459f * 0.9953f); break;
        case  5: norm_outflow = (norm_storage <= 0.9886f) ? 1.0649f * norm_storage + -0.1108f : 0.0984f * norm_storage + (1.0649f * 0.9886f + -0.1108f - 0.0984f * 0.9886f); break;
        case  6: norm_outflow = (norm_storage <= 0.9877f) ? 1.0312f * norm_storage + -0.1152f : 0.1126f * norm_storage + (1.0312f * 0.9877f + -0.1152f - 0.1126f * 0.9877f); break;
        case  7: norm_outflow = (norm_storage <= 0.9970f) ? 1.2279f * norm_storage + -0.1590f : 0.0220f * norm_storage + (1.2279f * 0.9970f + -0.1590f - 0.0220f * 0.9970f); break;
        case  8: norm_outflow = (norm_storage <= 0.9962f) ? 1.3089f * norm_storage + -0.1569f : 0.0369f * norm_storage + (1.3089f * 0.9962f + -0.1569f - 0.0369f * 0.9962f); break;
        case  9: norm_outflow = (norm_storage <= 0.9967f) ? 1.3115f * norm_storage + -0.1477f : 0.0413f * norm_storage + (1.3115f * 0.9967f + -0.1477f - 0.0413f * 0.9967f); break;
        case 10: norm_outflow = (norm_storage <= 0.9947f) ? 1.2614f * norm_storage + -0.1262f : 0.0736f * norm_storage + (1.2614f * 0.9947f + -0.1262f - 0.0736f * 0.9947f); break;
        case 11: norm_outflow = (norm_storage <= 0.9982f) ? 1.3294f * norm_storage + -0.1243f : 0.0133f * norm_storage + (1.3294f * 0.9982f + -0.1243f - 0.0133f * 0.9982f); break;
        case 12: norm_outflow = (norm_storage <= 0.9990f) ? 1.3702f * norm_storage + -0.1209f : 0.0142f * norm_storage + (1.3702f * 0.9990f + -0.1209f - 0.0142f * 0.9990f); break;
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
        case  1: norm_outflow = 1.9446f * norm_inflow + 0.0583f; break;
        case  2: norm_outflow = 1.9096f * norm_inflow + 0.0560f; break;
        case  3: norm_outflow = 1.8982f * norm_inflow + 0.0564f; break;
        case  4: norm_outflow = 1.9194f * norm_inflow + 0.0540f; break;
        case  5: norm_outflow = 1.9478f * norm_inflow + 0.0532f; break;
        case  6: norm_outflow = 1.9914f * norm_inflow + 0.0501f; break;
        case  7: norm_outflow = 2.0094f * norm_inflow + 0.0494f; break;
        case  8: norm_outflow = 2.2063f * norm_inflow + 0.0442f; break;
        case  9: norm_outflow = 2.1408f * norm_inflow + 0.0455f; break;
        case 10: norm_outflow = 2.1012f * norm_inflow + 0.0479f; break;
        case 11: norm_outflow = 1.9680f * norm_inflow + 0.0533f; break;
        case 12: norm_outflow = 1.9806f * norm_inflow + 0.0553f; break;
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
        case  1: norm_outflow = 1.0175f * norm_inflow + 0.0342f; break;
        case  2: norm_outflow = 1.0963f * norm_inflow + 0.0315f; break;
        case  3: norm_outflow = 1.0240f * norm_inflow + 0.0320f; break;
        case  4: norm_outflow = 1.0465f * norm_inflow + 0.0305f; break;
        case  5: norm_outflow = 0.9473f * norm_inflow + 0.0324f; break;
        case  6: norm_outflow = 0.9999f * norm_inflow + 0.0328f; break;
        case  7: norm_outflow = 0.9315f * norm_inflow + 0.0314f; break;
        case  8: norm_outflow = 1.0552f * norm_inflow + 0.0311f; break;
        case  9: norm_outflow = 0.9785f * norm_inflow + 0.0304f; break;
        case 10: norm_outflow = 1.1150f * norm_inflow + 0.0303f; break;
        case 11: norm_outflow = 1.0490f * norm_inflow + 0.0321f; break;
        case 12: norm_outflow = 1.0420f * norm_inflow + 0.0341f; break;
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
        case  1: norm_outflow = (norm_storage <= 0.9959f) ? 1.7409f * norm_storage + -0.2501f : 0.0466f * norm_storage + (1.7409f * 0.9959f + -0.2501f - 0.0466f * 0.9959f); break;
        case  2: norm_outflow = (norm_storage <= 0.9937f) ? 1.5466f * norm_storage + -0.1959f : 0.0639f * norm_storage + (1.5466f * 0.9937f + -0.1959f - 0.0639f * 0.9937f); break;
        case  3: norm_outflow = (norm_storage <= 0.9938f) ? 1.5360f * norm_storage + -0.2057f : 0.0499f * norm_storage + (1.5360f * 0.9938f + -0.2057f - 0.0499f * 0.9938f); break;
        case  4: norm_outflow = (norm_storage <= 0.9946f) ? 1.5767f * norm_storage + -0.2345f : 0.0667f * norm_storage + (1.5767f * 0.9946f + -0.2345f - 0.0667f * 0.9946f); break;
        case  5: norm_outflow = (norm_storage <= 0.9946f) ? 1.8408f * norm_storage + -0.3821f : 0.0845f * norm_storage + (1.8408f * 0.9946f + -0.3821f - 0.0845f * 0.9946f); break;
        case  6: norm_outflow = (norm_storage <= 0.9930f) ? 2.1457f * norm_storage + -0.4864f : 0.0955f * norm_storage + (2.1457f * 0.9930f + -0.4864f - 0.0955f * 0.9930f); break;
        case  7: norm_outflow = (norm_storage <= 0.9911f) ? 2.3268f * norm_storage + -0.5392f : 0.1039f * norm_storage + (2.3268f * 0.9911f + -0.5392f - 0.1039f * 0.9911f); break;
        case  8: norm_outflow = 1.8031f * norm_inflow + 0.0325f; break;
        case  9: norm_outflow = 1.5314f * norm_inflow + 0.0353f; break;
        case 10: norm_outflow = 1.5785f * norm_inflow + 0.0386f; break;
        case 11: norm_outflow = 1.5302f * norm_inflow + 0.0425f; break;
        case 12: norm_outflow = (norm_storage <= 0.9944f) ? 1.9366f * norm_storage + -0.3274f : 0.0520f * norm_storage + (1.9366f * 0.9944f + -0.3274f - 0.0520f * 0.9944f); break;
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
        case  1: norm_outflow = (norm_storage <= 0.6522f) ? 0.0718f * norm_storage + -0.0283f : 6.5499f * norm_storage + (0.0718f * 0.6522f + -0.0283f - 6.5499f * 0.6522f); break;
        case  2: norm_outflow = (norm_storage <= 0.6511f) ? 0.0714f * norm_storage + -0.0275f : 6.5578f * norm_storage + (0.0714f * 0.6511f + -0.0275f - 6.5578f * 0.6511f); break;
        case  3: norm_outflow = (norm_storage <= 0.6467f) ? 0.0661f * norm_storage + -0.0241f : 6.5062f * norm_storage + (0.0661f * 0.6467f + -0.0241f - 6.5062f * 0.6467f); break;
        case  4: norm_outflow = (norm_storage <= 0.6578f) ? 0.1127f * norm_storage + -0.0440f : 6.5455f * norm_storage + (0.1127f * 0.6578f + -0.0440f - 6.5455f * 0.6578f); break;
        case  5: norm_outflow = (norm_storage <= 0.6736f) ? 0.1601f * norm_storage + -0.0633f : 6.6420f * norm_storage + (0.1601f * 0.6736f + -0.0633f - 6.6420f * 0.6736f); break;
        case  6: norm_outflow = (norm_storage <= 0.6751f) ? 0.1851f * norm_storage + -0.0779f : 6.2651f * norm_storage + (0.1851f * 0.6751f + -0.0779f - 6.2651f * 0.6751f); break;
        case  7: norm_outflow = (norm_storage <= 0.6598f) ? 0.1388f * norm_storage + -0.0611f : 5.9618f * norm_storage + (0.1388f * 0.6598f + -0.0611f - 5.9618f * 0.6598f); break;
        case  8: norm_outflow = (norm_storage <= 0.6547f) ? 0.0947f * norm_storage + -0.0359f : 5.9912f * norm_storage + (0.0947f * 0.6547f + -0.0359f - 5.9912f * 0.6547f); break;
        case  9: norm_outflow = (norm_storage <= 0.6541f) ? 0.0853f * norm_storage + -0.0312f : 6.0869f * norm_storage + (0.0853f * 0.6541f + -0.0312f - 6.0869f * 0.6541f); break;
        case 10: norm_outflow = (norm_storage <= 0.6533f) ? 0.0875f * norm_storage + -0.0336f : 5.9621f * norm_storage + (0.0875f * 0.6533f + -0.0336f - 5.9621f * 0.6533f); break;
        case 11: norm_outflow = (norm_storage <= 0.6501f) ? 0.0649f * norm_storage + -0.0252f : 6.2600f * norm_storage + (0.0649f * 0.6501f + -0.0252f - 6.2600f * 0.6501f); break;
        case 12: norm_outflow = (norm_storage <= 0.6505f) ? 0.0632f * norm_storage + -0.0242f : 6.4181f * norm_storage + (0.0632f * 0.6505f + -0.0242f - 6.4181f * 0.6505f); break;
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
        case  1: norm_outflow = 1.3612f * norm_inflow + 0.0422f; break;
        case  2: norm_outflow = 1.3543f * norm_inflow + 0.0406f; break;
        case  3: norm_outflow = 1.3804f * norm_inflow + 0.0381f; break;
        case  4: norm_outflow = 1.4908f * norm_inflow + 0.0341f; break;
        case  5: norm_outflow = 1.5308f * norm_inflow + 0.0344f; break;
        case  6: norm_outflow = 1.5854f * norm_inflow + 0.0354f; break;
        case  7: norm_outflow = 1.5812f * norm_inflow + 0.0355f; break;
        case  8: norm_outflow = 1.5931f * norm_inflow + 0.0355f; break;
        case  9: norm_outflow = 1.4827f * norm_inflow + 0.0386f; break;
        case 10: norm_outflow = 1.4656f * norm_inflow + 0.0389f; break;
        case 11: norm_outflow = 1.4664f * norm_inflow + 0.0412f; break;
        case 12: norm_outflow = 1.4119f * norm_inflow + 0.0413f; break;
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
        case  1: norm_outflow = (norm_storage <= 0.8954f) ? 1.3844f * norm_storage + -0.5984f : 1.4887f * norm_storage + (1.3844f * 0.8954f + -0.5984f - 1.4887f * 0.8954f); break;
        case  2: norm_outflow = (norm_storage <= 0.8954f) ? 1.3691f * norm_storage + -0.5919f : 1.4615f * norm_storage + (1.3691f * 0.8954f + -0.5919f - 1.4615f * 0.8954f); break;
        case  3: norm_outflow = (norm_storage <= 0.8861f) ? 1.3611f * norm_storage + -0.6020f : 1.6953f * norm_storage + (1.3611f * 0.8861f + -0.6020f - 1.6953f * 0.8861f); break;
        case  4: norm_outflow = (norm_storage <= 0.8744f) ? 1.3665f * norm_storage + -0.6362f : 1.8349f * norm_storage + (1.3665f * 0.8744f + -0.6362f - 1.8349f * 0.8744f); break;
        case  5: norm_outflow = (norm_storage <= 0.8609f) ? 1.4972f * norm_storage + -0.7467f : 2.1248f * norm_storage + (1.4972f * 0.8609f + -0.7467f - 2.1248f * 0.8609f); break;
        case  6: norm_outflow = (norm_storage <= 0.8809f) ? 1.8889f * norm_storage + -0.9944f : 1.8885f * norm_storage + (1.8889f * 0.8809f + -0.9944f - 1.8885f * 0.8809f); break;
        case  7: norm_outflow = (norm_storage <= 0.8223f) ? 1.2501f * norm_storage + -0.6289f : 3.0499f * norm_storage + (1.2501f * 0.8223f + -0.6289f - 3.0499f * 0.8223f); break;
        case  8: norm_outflow = (norm_storage <= 0.7924f) ? 0.9142f * norm_storage + -0.4474f : 3.4393f * norm_storage + (0.9142f * 0.7924f + -0.4474f - 3.4393f * 0.7924f); break;
        case  9: norm_outflow = (norm_storage <= 0.7877f) ? 0.7709f * norm_storage + -0.3629f : 3.3716f * norm_storage + (0.7709f * 0.7877f + -0.3629f - 3.3716f * 0.7877f); break;
        case 10: norm_outflow = (norm_storage <= 0.8022f) ? 0.7319f * norm_storage + -0.3230f : 3.1071f * norm_storage + (0.7319f * 0.8022f + -0.3230f - 3.1071f * 0.8022f); break;
        case 11: norm_outflow = 1.4183f * norm_inflow + 0.0510f; break;
        case 12: norm_outflow = (norm_storage <= 0.8800f) ? 1.4063f * norm_storage + -0.6320f : 1.8510f * norm_storage + (1.4063f * 0.8800f + -0.6320f - 1.8510f * 0.8800f); break;
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
        case  1: norm_outflow = 0.6461f * norm_inflow + 0.0287f; break;
        case  2: norm_outflow = 0.6500f * norm_inflow + 0.0303f; break;
        case  3: norm_outflow = 0.5993f * norm_inflow + 0.0368f; break;
        case  4: norm_outflow = 0.7222f * norm_inflow + 0.0462f; break;
        case  5: norm_outflow = 0.7265f * norm_inflow + 0.0518f; break;
        case  6: norm_outflow = 0.7569f * norm_inflow + 0.0544f; break;
        case  7: norm_outflow = 0.8119f * norm_inflow + 0.0559f; break;
        case  8: norm_outflow = 0.8294f * norm_inflow + 0.0518f; break;
        case  9: norm_outflow = 0.7208f * norm_inflow + 0.0474f; break;
        case 10: norm_outflow = 0.5903f * norm_inflow + 0.0354f; break;
        case 11: norm_outflow = 0.5829f * norm_inflow + 0.0319f; break;
        case 12: norm_outflow = 0.5940f * norm_inflow + 0.0285f; break;
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
        case  1: norm_outflow = (norm_storage <= 0.9968f) ? 1.2303f * norm_storage + -0.0091f : 0.0252f * norm_storage + (1.2303f * 0.9968f + -0.0091f - 0.0252f * 0.9968f); break;
        case  2: norm_outflow = (norm_storage <= 0.9970f) ? 1.2849f * norm_storage + -0.0078f : 0.0293f * norm_storage + (1.2849f * 0.9970f + -0.0078f - 0.0293f * 0.9970f); break;
        case  3: norm_outflow = (norm_storage <= 0.9960f) ? 1.1863f * norm_storage + 0.0061f : 0.0351f * norm_storage + (1.1863f * 0.9960f + 0.0061f - 0.0351f * 0.9960f); break;
        case  4: norm_outflow = (norm_storage <= 0.9934f) ? 1.0632f * norm_storage + -0.0389f : 0.0724f * norm_storage + (1.0632f * 0.9934f + -0.0389f - 0.0724f * 0.9934f); break;
        case  5: norm_outflow = (norm_storage <= 0.9944f) ? 1.1160f * norm_storage + -0.0726f : 0.0471f * norm_storage + (1.1160f * 0.9944f + -0.0726f - 0.0471f * 0.9944f); break;
        case  6: norm_outflow = (norm_storage <= 0.9901f) ? 1.2487f * norm_storage + -0.0767f : 0.1442f * norm_storage + (1.2487f * 0.9901f + -0.0767f - 0.1442f * 0.9901f); break;
        case  7: norm_outflow = (norm_storage <= 0.9913f) ? 1.4168f * norm_storage + -0.1409f : 0.0990f * norm_storage + (1.4168f * 0.9913f + -0.1409f - 0.0990f * 0.9913f); break;
        case  8: norm_outflow = (norm_storage <= 0.9916f) ? 1.4787f * norm_storage + -0.1505f : 0.0896f * norm_storage + (1.4787f * 0.9916f + -0.1505f - 0.0896f * 0.9916f); break;
        case  9: norm_outflow = (norm_storage <= 0.9907f) ? 1.3927f * norm_storage + -0.1199f : 0.1041f * norm_storage + (1.3927f * 0.9907f + -0.1199f - 0.1041f * 0.9907f); break;
        case 10: norm_outflow = (norm_storage <= 0.9928f) ? 1.4413f * norm_storage + -0.1175f : 0.0772f * norm_storage + (1.4413f * 0.9928f + -0.1175f - 0.0772f * 0.9928f); break;
        case 11: norm_outflow = (norm_storage <= 0.9923f) ? 1.2385f * norm_storage + -0.0818f : 0.0843f * norm_storage + (1.2385f * 0.9923f + -0.0818f - 0.0843f * 0.9923f); break;
        case 12: norm_outflow = (norm_storage <= 0.9958f) ? 1.2311f * norm_storage + -0.0059f : 0.0392f * norm_storage + (1.2311f * 0.9958f + -0.0059f - 0.0392f * 0.9958f); break;
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
        case  1: norm_outflow = 1.4052f * norm_inflow + 0.0212f; break;
        case  2: norm_outflow = 1.3288f * norm_inflow + 0.0214f; break;
        case  3: norm_outflow = 1.2931f * norm_inflow + 0.0228f; break;
        case  4: norm_outflow = 1.2727f * norm_inflow + 0.0233f; break;
        case  5: norm_outflow = (norm_storage <= 0.9098f) ? 0.5625f * norm_storage + -0.1690f : 1.3971f * norm_storage + (0.5625f * 0.9098f + -0.1690f - 1.3971f * 0.9098f); break;
        case  6: norm_outflow = (norm_storage <= 0.9213f) ? 0.6421f * norm_storage + -0.1982f : 1.4239f * norm_storage + (0.6421f * 0.9213f + -0.1982f - 1.4239f * 0.9213f); break;
        case  7: norm_outflow = 1.3244f * norm_inflow + 0.0264f; break;
        case  8: norm_outflow = 1.3130f * norm_inflow + 0.0245f; break;
        case  9: norm_outflow = (norm_storage <= 0.9004f) ? 0.3942f * norm_storage + -0.0925f : 0.9630f * norm_storage + (0.3942f * 0.9004f + -0.0925f - 0.9630f * 0.9004f); break;
        case 10: norm_outflow = (norm_storage <= 0.9108f) ? 0.4104f * norm_storage + -0.0999f : 1.1264f * norm_storage + (0.4104f * 0.9108f + -0.0999f - 1.1264f * 0.9108f); break;
        case 11: norm_outflow = (norm_storage <= 0.9202f) ? 0.3299f * norm_storage + -0.0779f : 0.7462f * norm_storage + (0.3299f * 0.9202f + -0.0779f - 0.7462f * 0.9202f); break;
        case 12: norm_outflow = 1.3986f * norm_inflow + 0.0210f; break;
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
        case  1: norm_outflow = 0.9524f * norm_inflow + 0.0091f; break;
        case  2: norm_outflow = 0.9538f * norm_inflow + 0.0094f; break;
        case  3: norm_outflow = 0.9226f * norm_inflow + 0.0104f; break;
        case  4: norm_outflow = 0.9548f * norm_inflow + 0.0104f; break;
        case  5: norm_outflow = 0.9813f * norm_inflow + 0.0109f; break;
        case  6: norm_outflow = 0.9990f * norm_inflow + 0.0133f; break;
        case  7: norm_outflow = 0.9480f * norm_inflow + 0.0115f; break;
        case  8: norm_outflow = 0.9061f * norm_inflow + 0.0124f; break;
        case  9: norm_outflow = 0.8879f * norm_inflow + 0.0126f; break;
        case 10: norm_outflow = 0.8908f * norm_inflow + 0.0110f; break;
        case 11: norm_outflow = 0.8985f * norm_inflow + 0.0112f; break;
        case 12: norm_outflow = 0.9481f * norm_inflow + 0.0113f; break;
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
        case  1: norm_outflow = 0.9929f * norm_inflow + 0.0021f; break;
        case  2: norm_outflow = 0.9953f * norm_inflow + 0.0022f; break;
        case  3: norm_outflow = 0.9982f * norm_inflow + 0.0024f; break;
        case  4: norm_outflow = 0.9968f * norm_inflow + 0.0020f; break;
        case  5: norm_outflow = 1.0120f * norm_inflow + 0.0026f; break;
        case  6: norm_outflow = 1.0318f * norm_inflow + 0.0041f; break;
        case  7: norm_outflow = 1.0126f * norm_inflow + 0.0033f; break;
        case  8: norm_outflow = 0.9967f * norm_inflow + 0.0030f; break;
        case  9: norm_outflow = 0.9937f * norm_inflow + 0.0029f; break;
        case 10: norm_outflow = 0.9938f * norm_inflow + 0.0036f; break;
        case 11: norm_outflow = 0.9890f * norm_inflow + 0.0033f; break;
        case 12: norm_outflow = 0.9917f * norm_inflow + 0.0033f; break;
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
        case  1: norm_outflow = 0.9389f * norm_inflow + 0.0050f; break;
        case  2: norm_outflow = 0.9300f * norm_inflow + 0.0048f; break;
        case  3: norm_outflow = 0.9427f * norm_inflow + 0.0042f; break;
        case  4: norm_outflow = 0.9642f * norm_inflow + 0.0039f; break;
        case  5: norm_outflow = 0.9860f * norm_inflow + 0.0044f; break;
        case  6: norm_outflow = 0.9975f * norm_inflow + 0.0051f; break;
        case  7: norm_outflow = 0.9832f * norm_inflow + 0.0047f; break;
        case  8: norm_outflow = 0.9674f * norm_inflow + 0.0045f; break;
        case  9: norm_outflow = 0.9414f * norm_inflow + 0.0046f; break;
        case 10: norm_outflow = 0.9394f * norm_inflow + 0.0039f; break;
        case 11: norm_outflow = 0.9266f * norm_inflow + 0.0051f; break;
        case 12: norm_outflow = 0.9238f * norm_inflow + 0.0046f; break;
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
        case  1: norm_outflow = 0.9480f * norm_inflow + 0.0045f; break;
        case  2: norm_outflow = 0.9482f * norm_inflow + 0.0046f; break;
        case  3: norm_outflow = 0.9543f * norm_inflow + 0.0043f; break;
        case  4: norm_outflow = 0.9673f * norm_inflow + 0.0043f; break;
        case  5: norm_outflow = 0.9778f * norm_inflow + 0.0050f; break;
        case  6: norm_outflow = 1.0103f * norm_inflow + 0.0066f; break;
        case  7: norm_outflow = 0.9801f * norm_inflow + 0.0056f; break;
        case  8: norm_outflow = 0.9643f * norm_inflow + 0.0062f; break;
        case  9: norm_outflow = 0.9543f * norm_inflow + 0.0066f; break;
        case 10: norm_outflow = 0.9433f * norm_inflow + 0.0069f; break;
        case 11: norm_outflow = 0.9481f * norm_inflow + 0.0053f; break;
        case 12: norm_outflow = 0.9526f * norm_inflow + 0.0053f; break;
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
        case  1: norm_outflow = 1.0289f * norm_inflow + 0.0039f; break;
        case  2: norm_outflow = 1.0301f * norm_inflow + 0.0042f; break;
        case  3: norm_outflow = 1.0335f * norm_inflow + 0.0038f; break;
        case  4: norm_outflow = 1.0391f * norm_inflow + 0.0035f; break;
        case  5: norm_outflow = 1.0508f * norm_inflow + 0.0042f; break;
        case  6: norm_outflow = 1.0610f * norm_inflow + 0.0050f; break;
        case  7: norm_outflow = 1.0555f * norm_inflow + 0.0045f; break;
        case  8: norm_outflow = 1.0270f * norm_inflow + 0.0049f; break;
        case  9: norm_outflow = 1.0358f * norm_inflow + 0.0047f; break;
        case 10: norm_outflow = 1.0257f * norm_inflow + 0.0063f; break;
        case 11: norm_outflow = 1.0290f * norm_inflow + 0.0047f; break;
        case 12: norm_outflow = 1.0338f * norm_inflow + 0.0049f; break;
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
        case  1: norm_outflow = 2.1980f * norm_inflow + 0.0228f; break;
        case  2: norm_outflow = 2.1785f * norm_inflow + 0.0214f; break;
        case  3: norm_outflow = 2.1756f * norm_inflow + 0.0207f; break;
        case  4: norm_outflow = 2.2092f * norm_inflow + 0.0188f; break;
        case  5: norm_outflow = 2.2850f * norm_inflow + 0.0192f; break;
        case  6: norm_outflow = 2.3773f * norm_inflow + 0.0212f; break;
        case  7: norm_outflow = 2.3918f * norm_inflow + 0.0225f; break;
        case  8: norm_outflow = 2.5006f * norm_inflow + 0.0248f; break;
        case  9: norm_outflow = 2.4595f * norm_inflow + 0.0274f; break;
        case 10: norm_outflow = 2.4286f * norm_inflow + 0.0292f; break;
        case 11: norm_outflow = 2.3936f * norm_inflow + 0.0265f; break;
        case 12: norm_outflow = 2.3449f * norm_inflow + 0.0256f; break;
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
        case  1: norm_outflow = (norm_storage <= 0.9980f) ? 0.6152f * norm_storage + -0.0193f : 0.0218f * norm_storage + (0.6152f * 0.9980f + -0.0193f - 0.0218f * 0.9980f); break;
        case  2: norm_outflow = (norm_storage <= 0.9978f) ? 0.5932f * norm_storage + -0.0162f : 0.0340f * norm_storage + (0.5932f * 0.9978f + -0.0162f - 0.0340f * 0.9978f); break;
        case  3: norm_outflow = (norm_storage <= 0.9977f) ? 0.5222f * norm_storage + -0.0047f : 0.0146f * norm_storage + (0.5222f * 0.9977f + -0.0047f - 0.0146f * 0.9977f); break;
        case  4: norm_outflow = (norm_storage <= 0.9951f) ? 0.5186f * norm_storage + -0.0042f : 0.0356f * norm_storage + (0.5186f * 0.9951f + -0.0042f - 0.0356f * 0.9951f); break;
        case  5: norm_outflow = (norm_storage <= 0.9843f) ? 0.4691f * norm_storage + -0.0094f : 0.2716f * norm_storage + (0.4691f * 0.9843f + -0.0094f - 0.2716f * 0.9843f); break;
        case  6: norm_outflow = (norm_storage <= 0.9980f) ? 0.5605f * norm_storage + -0.0250f : 0.0132f * norm_storage + (0.5605f * 0.9980f + -0.0250f - 0.0132f * 0.9980f); break;
        case  7: norm_outflow = (norm_storage <= 0.9986f) ? 0.6364f * norm_storage + -0.0394f : 0.0065f * norm_storage + (0.6364f * 0.9986f + -0.0394f - 0.0065f * 0.9986f); break;
        case  8: norm_outflow = (norm_storage <= 0.9992f) ? 0.7667f * norm_storage + -0.0602f : 0.0196f * norm_storage + (0.7667f * 0.9992f + -0.0602f - 0.0196f * 0.9992f); break;
        case  9: norm_outflow = (norm_storage <= 0.9988f) ? 0.6447f * norm_storage + -0.0368f : 0.0114f * norm_storage + (0.6447f * 0.9988f + -0.0368f - 0.0114f * 0.9988f); break;
        case 10: norm_outflow = (norm_storage <= 0.9985f) ? 0.6000f * norm_storage + -0.0277f : 0.0193f * norm_storage + (0.6000f * 0.9985f + -0.0277f - 0.0193f * 0.9985f); break;
        case 11: norm_outflow = (norm_storage <= 0.9968f) ? 0.5532f * norm_storage + -0.0122f : 0.0402f * norm_storage + (0.5532f * 0.9968f + -0.0122f - 0.0402f * 0.9968f); break;
        case 12: norm_outflow = (norm_storage <= 0.9975f) ? 0.5426f * norm_storage + -0.0058f : 0.0370f * norm_storage + (0.5426f * 0.9975f + -0.0058f - 0.0370f * 0.9975f); break;
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
        case  1: norm_outflow = 1.1283f * norm_inflow + 0.0084f; break;
        case  2: norm_outflow = 1.1222f * norm_inflow + 0.0075f; break;
        case  3: norm_outflow = 1.1305f * norm_inflow + 0.0068f; break;
        case  4: norm_outflow = 1.1906f * norm_inflow + 0.0041f; break;
        case  5: norm_outflow = 1.2369f * norm_inflow + 0.0056f; break;
        case  6: norm_outflow = 1.2485f * norm_inflow + 0.0092f; break;
        case  7: norm_outflow = 1.2359f * norm_inflow + 0.0088f; break;
        case  8: norm_outflow = 1.2034f * norm_inflow + 0.0105f; break;
        case  9: norm_outflow = 1.1680f * norm_inflow + 0.0135f; break;
        case 10: norm_outflow = 1.1475f * norm_inflow + 0.0156f; break;
        case 11: norm_outflow = 1.1394f * norm_inflow + 0.0126f; break;
        case 12: norm_outflow = 1.1412f * norm_inflow + 0.0103f; break;
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
        case  1: norm_outflow = 1.2174f * norm_inflow + 0.0227f; break;
        case  2: norm_outflow = 1.1906f * norm_inflow + 0.0214f; break;
        case  3: norm_outflow = 1.2063f * norm_inflow + 0.0195f; break;
        case  4: norm_outflow = 1.2202f * norm_inflow + 0.0173f; break;
        case  5: norm_outflow = 1.2933f * norm_inflow + 0.0167f; break;
        case  6: norm_outflow = 1.3533f * norm_inflow + 0.0181f; break;
        case  7: norm_outflow = 1.2925f * norm_inflow + 0.0171f; break;
        case  8: norm_outflow = 1.3178f * norm_inflow + 0.0172f; break;
        case  9: norm_outflow = 1.3671f * norm_inflow + 0.0207f; break;
        case 10: norm_outflow = 1.3752f * norm_inflow + 0.0222f; break;
        case 11: norm_outflow = 1.2870f * norm_inflow + 0.0242f; break;
        case 12: norm_outflow = 1.1999f * norm_inflow + 0.0234f; break;
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
        case  1: norm_outflow = 1.0581f * norm_inflow + 0.0164f; break;
        case  2: norm_outflow = 1.0578f * norm_inflow + 0.0144f; break;
        case  3: norm_outflow = 1.0717f * norm_inflow + 0.0124f; break;
        case  4: norm_outflow = 1.0926f * norm_inflow + 0.0112f; break;
        case  5: norm_outflow = 1.1240f * norm_inflow + 0.0114f; break;
        case  6: norm_outflow = 1.1711f * norm_inflow + 0.0131f; break;
        case  7: norm_outflow = 1.0860f * norm_inflow + 0.0135f; break;
        case  8: norm_outflow = 1.0855f * norm_inflow + 0.0132f; break;
        case  9: norm_outflow = 1.1036f * norm_inflow + 0.0146f; break;
        case 10: norm_outflow = 1.1001f * norm_inflow + 0.0177f; break;
        case 11: norm_outflow = 1.0633f * norm_inflow + 0.0198f; break;
        case 12: norm_outflow = 1.0740f * norm_inflow + 0.0177f; break;
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
        case  1: norm_outflow = (norm_storage <= 0.9982f) ? 2.1101f * norm_storage + -0.3461f : 0.0266f * norm_storage + (2.1101f * 0.9982f + -0.3461f - 0.0266f * 0.9982f); break;
        case  2: norm_outflow = (norm_storage <= 0.9971f) ? 1.8679f * norm_storage + -0.2803f : 0.0271f * norm_storage + (1.8679f * 0.9971f + -0.2803f - 0.0271f * 0.9971f); break;
        case  3: norm_outflow = (norm_storage <= 0.9965f) ? 1.6495f * norm_storage + -0.2256f : 0.0365f * norm_storage + (1.6495f * 0.9965f + -0.2256f - 0.0365f * 0.9965f); break;
        case  4: norm_outflow = (norm_storage <= 0.9967f) ? 1.6840f * norm_storage + -0.2513f : 0.0515f * norm_storage + (1.6840f * 0.9967f + -0.2513f - 0.0515f * 0.9967f); break;
        case  5: norm_outflow = (norm_storage <= 0.9980f) ? 1.9011f * norm_storage + -0.3508f : 0.0275f * norm_storage + (1.9011f * 0.9980f + -0.3508f - 0.0275f * 0.9980f); break;
        case  6: norm_outflow = (norm_storage <= 0.9988f) ? 2.7524f * norm_storage + -0.6164f : 0.0310f * norm_storage + (2.7524f * 0.9988f + -0.6164f - 0.0310f * 0.9988f); break;
        case  7: norm_outflow = (norm_storage <= 0.9988f) ? 3.2202f * norm_storage + -0.7471f : 0.0083f * norm_storage + (3.2202f * 0.9988f + -0.7471f - 0.0083f * 0.9988f); break;
        case  8: norm_outflow = (norm_storage <= 0.9989f) ? 3.1914f * norm_storage + -0.7091f : 0.0115f * norm_storage + (3.1914f * 0.9989f + -0.7091f - 0.0115f * 0.9989f); break;
        case  9: norm_outflow = (norm_storage <= 0.9991f) ? 2.9801f * norm_storage + -0.6118f : 0.0118f * norm_storage + (2.9801f * 0.9991f + -0.6118f - 0.0118f * 0.9991f); break;
        case 10: norm_outflow = (norm_storage <= 0.9988f) ? 2.7638f * norm_storage + -0.5522f : 0.0125f * norm_storage + (2.7638f * 0.9988f + -0.5522f - 0.0125f * 0.9988f); break;
        case 11: norm_outflow = (norm_storage <= 0.9987f) ? 2.7185f * norm_storage + -0.5280f : 0.0565f * norm_storage + (2.7185f * 0.9987f + -0.5280f - 0.0565f * 0.9987f); break;
        case 12: norm_outflow = (norm_storage <= 0.9965f) ? 2.2569f * norm_storage + -0.3805f : 0.0307f * norm_storage + (2.2569f * 0.9965f + -0.3805f - 0.0307f * 0.9965f); break;
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
        case  1: norm_outflow = (norm_storage <= 0.9960f) ? 1.7734f * norm_storage + -0.4153f : 0.0730f * norm_storage + (1.7734f * 0.9960f + -0.4153f - 0.0730f * 0.9960f); break;
        case  2: norm_outflow = (norm_storage <= 0.9935f) ? 1.6793f * norm_storage + -0.3976f : 0.1027f * norm_storage + (1.6793f * 0.9935f + -0.3976f - 0.1027f * 0.9935f); break;
        case  3: norm_outflow = (norm_storage <= 0.9959f) ? 1.5329f * norm_storage + -0.3459f : 0.1269f * norm_storage + (1.5329f * 0.9959f + -0.3459f - 0.1269f * 0.9959f); break;
        case  4: norm_outflow = (norm_storage <= 0.9935f) ? 1.5109f * norm_storage + -0.3456f : 0.1455f * norm_storage + (1.5109f * 0.9935f + -0.3456f - 0.1455f * 0.9935f); break;
        case  5: norm_outflow = (norm_storage <= 0.9924f) ? 1.5963f * norm_storage + -0.4000f : 0.1274f * norm_storage + (1.5963f * 0.9924f + -0.4000f - 0.1274f * 0.9924f); break;
        case  6: norm_outflow = (norm_storage <= 0.9941f) ? 2.3175f * norm_storage + -0.7236f : 0.1415f * norm_storage + (2.3175f * 0.9941f + -0.7236f - 0.1415f * 0.9941f); break;
        case  7: norm_outflow = (norm_storage <= 0.9939f) ? 2.4261f * norm_storage + -0.7068f : 0.0803f * norm_storage + (2.4261f * 0.9939f + -0.7068f - 0.0803f * 0.9939f); break;
        case  8: norm_outflow = (norm_storage <= 0.9902f) ? 2.4518f * norm_storage + -0.7044f : 0.1519f * norm_storage + (2.4518f * 0.9902f + -0.7044f - 0.1519f * 0.9902f); break;
        case  9: norm_outflow = (norm_storage <= 0.9931f) ? 2.3155f * norm_storage + -0.6293f : 0.1088f * norm_storage + (2.3155f * 0.9931f + -0.6293f - 0.1088f * 0.9931f); break;
        case 10: norm_outflow = (norm_storage <= 0.9933f) ? 2.0654f * norm_storage + -0.5337f : 0.0995f * norm_storage + (2.0654f * 0.9933f + -0.5337f - 0.0995f * 0.9933f); break;
        case 11: norm_outflow = (norm_storage <= 0.9964f) ? 2.0681f * norm_storage + -0.5305f : 0.0572f * norm_storage + (2.0681f * 0.9964f + -0.5305f - 0.0572f * 0.9964f); break;
        case 12: norm_outflow = (norm_storage <= 0.9898f) ? 1.6851f * norm_storage + -0.3854f : 0.1885f * norm_storage + (1.6851f * 0.9898f + -0.3854f - 0.1885f * 0.9898f); break;
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
        case  1: norm_outflow = (norm_storage <= 0.9896f) ? 1.4471f * norm_storage + -0.2703f : 0.1094f * norm_storage + (1.4471f * 0.9896f + -0.2703f - 0.1094f * 0.9896f); break;
        case  2: norm_outflow = (norm_storage <= 0.9876f) ? 1.3859f * norm_storage + -0.2548f : 0.1678f * norm_storage + (1.3859f * 0.9876f + -0.2548f - 0.1678f * 0.9876f); break;
        case  3: norm_outflow = (norm_storage <= 0.9880f) ? 1.3162f * norm_storage + -0.2531f : 0.3051f * norm_storage + (1.3162f * 0.9880f + -0.2531f - 0.3051f * 0.9880f); break;
        case  4: norm_outflow = (norm_storage <= 0.9886f) ? 1.3085f * norm_storage + -0.2566f : 0.2062f * norm_storage + (1.3085f * 0.9886f + -0.2566f - 0.2062f * 0.9886f); break;
        case  5: norm_outflow = (norm_storage <= 0.9870f) ? 1.3277f * norm_storage + -0.2738f : 0.2203f * norm_storage + (1.3277f * 0.9870f + -0.2738f - 0.2203f * 0.9870f); break;
        case  6: norm_outflow = (norm_storage <= 0.9817f) ? 1.4876f * norm_storage + -0.3441f : 0.4184f * norm_storage + (1.4876f * 0.9817f + -0.3441f - 0.4184f * 0.9817f); break;
        case  7: norm_outflow = (norm_storage <= 0.9889f) ? 1.7455f * norm_storage + -0.3836f : 0.1029f * norm_storage + (1.7455f * 0.9889f + -0.3836f - 0.1029f * 0.9889f); break;
        case  8: norm_outflow = (norm_storage <= 0.9839f) ? 1.6287f * norm_storage + -0.3577f : 0.1469f * norm_storage + (1.6287f * 0.9839f + -0.3577f - 0.1469f * 0.9839f); break;
        case  9: norm_outflow = (norm_storage <= 0.9853f) ? 1.5556f * norm_storage + -0.3190f : 0.2200f * norm_storage + (1.5556f * 0.9853f + -0.3190f - 0.2200f * 0.9853f); break;
        case 10: norm_outflow = (norm_storage <= 0.9841f) ? 1.4585f * norm_storage + -0.3003f : 0.4363f * norm_storage + (1.4585f * 0.9841f + -0.3003f - 0.4363f * 0.9841f); break;
        case 11: norm_outflow = (norm_storage <= 0.9899f) ? 1.5395f * norm_storage + -0.3179f : 0.2010f * norm_storage + (1.5395f * 0.9899f + -0.3179f - 0.2010f * 0.9899f); break;
        case 12: norm_outflow = (norm_storage <= 0.9808f) ? 1.3255f * norm_storage + -0.2592f : 0.3269f * norm_storage + (1.3255f * 0.9808f + -0.2592f - 0.3269f * 0.9808f); break;
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
        case  1: norm_outflow = 0.8769f * norm_inflow + 0.0058f; break;
        case  2: norm_outflow = 0.8937f * norm_inflow + 0.0055f; break;
        case  3: norm_outflow = 0.8984f * norm_inflow + 0.0121f; break;
        case  4: norm_outflow = 0.9033f * norm_inflow + 0.0169f; break;
        case  5: norm_outflow = 0.9310f * norm_inflow + 0.0264f; break;
        case  6: norm_outflow = 0.9657f * norm_inflow + 0.0312f; break;
        case  7: norm_outflow = 1.0263f * norm_inflow + 0.0380f; break;
        case  8: norm_outflow = 1.0020f * norm_inflow + 0.0354f; break;
        case  9: norm_outflow = 0.9617f * norm_inflow + 0.0257f; break;
        case 10: norm_outflow = 0.8557f * norm_inflow + 0.0108f; break;
        case 11: norm_outflow = 0.8558f * norm_inflow + 0.0076f; break;
        case 12: norm_outflow = 0.8931f * norm_inflow + 0.0066f; break;
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
        case  1: norm_outflow = 0.7929f * norm_inflow + 0.0149f; break;
        case  2: norm_outflow = 0.8551f * norm_inflow + 0.0153f; break;
        case  3: norm_outflow = 0.8659f * norm_inflow + 0.0257f; break;
        case  4: norm_outflow = 0.8028f * norm_inflow + 0.0346f; break;
        case  5: norm_outflow = 0.8562f * norm_inflow + 0.0426f; break;
        case  6: norm_outflow = 0.9183f * norm_inflow + 0.0494f; break;
        case  7: norm_outflow = 0.9426f * norm_inflow + 0.0564f; break;
        case  8: norm_outflow = (norm_storage <= 0.9851f) ? 0.1745f * norm_storage + 0.0788f : 0.5748f * norm_storage + (0.1745f * 0.9851f + 0.0788f - 0.5748f * 0.9851f); break;
        case  9: norm_outflow = (norm_storage <= 0.9814f) ? 0.1967f * norm_storage + 0.0347f : 0.2503f * norm_storage + (0.1967f * 0.9814f + 0.0347f - 0.2503f * 0.9814f); break;
        case 10: norm_outflow = 0.8032f * norm_inflow + 0.0233f; break;
        case 11: norm_outflow = 0.7998f * norm_inflow + 0.0186f; break;
        case 12: norm_outflow = 0.8495f * norm_inflow + 0.0162f; break;
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
        case  1: norm_outflow = 0.5313f * norm_inflow + 0.0250f; break;
        case  2: norm_outflow = 0.5232f * norm_inflow + 0.0267f; break;
        case  3: norm_outflow = 0.5664f * norm_inflow + 0.0308f; break;
        case  4: norm_outflow = 0.6231f * norm_inflow + 0.0382f; break;
        case  5: norm_outflow = 0.7218f * norm_inflow + 0.0432f; break;
        case  6: norm_outflow = 0.7813f * norm_inflow + 0.0476f; break;
        case  7: norm_outflow = 0.7953f * norm_inflow + 0.0476f; break;
        case  8: norm_outflow = 0.7209f * norm_inflow + 0.0471f; break;
        case  9: norm_outflow = 0.6777f * norm_inflow + 0.0421f; break;
        case 10: norm_outflow = 0.5437f * norm_inflow + 0.0321f; break;
        case 11: norm_outflow = 0.5195f * norm_inflow + 0.0282f; break;
        case 12: norm_outflow = 0.5313f * norm_inflow + 0.0261f; break;
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
        case  1: norm_outflow = 0.9932f * norm_inflow + 0.0060f; break;
        case  2: norm_outflow = 1.0027f * norm_inflow + 0.0046f; break;
        case  3: norm_outflow = 0.9908f * norm_inflow + 0.0034f; break;
        case  4: norm_outflow = 0.9904f * norm_inflow + 0.0031f; break;
        case  5: norm_outflow = 0.9932f * norm_inflow + 0.0041f; break;
        case  6: norm_outflow = 1.0129f * norm_inflow + 0.0046f; break;
        case  7: norm_outflow = 0.9975f * norm_inflow + 0.0037f; break;
        case  8: norm_outflow = 0.9906f * norm_inflow + 0.0048f; break;
        case  9: norm_outflow = 0.9866f * norm_inflow + 0.0045f; break;
        case 10: norm_outflow = 0.9712f * norm_inflow + 0.0038f; break;
        case 11: norm_outflow = 0.9841f * norm_inflow + 0.0039f; break;
        case 12: norm_outflow = 0.9911f * norm_inflow + 0.0044f; break;
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
        case  1: norm_outflow = 1.0880f * norm_inflow + 0.0081f; break;
        case  2: norm_outflow = 1.1933f * norm_inflow + 0.0089f; break;
        case  3: norm_outflow = 1.0861f * norm_inflow + 0.0073f; break;
        case  4: norm_outflow = 1.0574f * norm_inflow + 0.0089f; break;
        case  5: norm_outflow = 1.0624f * norm_inflow + 0.0093f; break;
        case  6: norm_outflow = 1.0667f * norm_inflow + 0.0090f; break;
        case  7: norm_outflow = 1.0726f * norm_inflow + 0.0095f; break;
        case  8: norm_outflow = 1.0585f * norm_inflow + 0.0085f; break;
        case  9: norm_outflow = 1.0492f * norm_inflow + 0.0073f; break;
        case 10: norm_outflow = 1.0610f * norm_inflow + 0.0074f; break;
        case 11: norm_outflow = 1.0565f * norm_inflow + 0.0076f; break;
        case 12: norm_outflow = 1.0936f * norm_inflow + 0.0081f; break;
    }
    return norm_outflow * max_outflow_m3d;
}

//------------------------------------------------------------------------------


// ---- Dispatch based on reservoir GDW ID ----
float applyReservoirRule(int res_id, float inflow_m3d, float storage_m3, int month) {
    switch (res_id) {
        case 20: return rule_20(inflow_m3d, storage_m3, month);
        case 21: return rule_21(inflow_m3d, storage_m3, month);
        case 104: return rule_104(inflow_m3d, storage_m3, month);
        case 116: return rule_116(inflow_m3d, storage_m3, month);
        case 119: return rule_119(inflow_m3d, storage_m3, month);
        case 126: return rule_126(inflow_m3d, storage_m3, month);
        case 136: return rule_136(inflow_m3d, storage_m3, month);
        case 142: return rule_142(inflow_m3d, storage_m3, month);
        case 143: return rule_143(inflow_m3d, storage_m3, month);
        case 144: return rule_144(inflow_m3d, storage_m3, month);
        case 145: return rule_145(inflow_m3d, storage_m3, month);
        case 147: return rule_147(inflow_m3d, storage_m3, month);
        case 148: return rule_148(inflow_m3d, storage_m3, month);
        case 150: return rule_150(inflow_m3d, storage_m3, month);
        case 151: return rule_151(inflow_m3d, storage_m3, month);
        case 152: return rule_152(inflow_m3d, storage_m3, month);
        case 154: return rule_154(inflow_m3d, storage_m3, month);
        case 155: return rule_155(inflow_m3d, storage_m3, month);
        case 157: return rule_157(inflow_m3d, storage_m3, month);
        case 158: return rule_158(inflow_m3d, storage_m3, month);
        case 159: return rule_159(inflow_m3d, storage_m3, month);
        case 160: return rule_160(inflow_m3d, storage_m3, month);
        case 161: return rule_161(inflow_m3d, storage_m3, month);
        case 162: return rule_162(inflow_m3d, storage_m3, month);
        case 163: return rule_163(inflow_m3d, storage_m3, month);
        case 168: return rule_168(inflow_m3d, storage_m3, month);
        case 169: return rule_169(inflow_m3d, storage_m3, month);
        case 487: return rule_487(inflow_m3d, storage_m3, month);
        case 488: return rule_488(inflow_m3d, storage_m3, month);
        case 493: return rule_493(inflow_m3d, storage_m3, month);
        case 536: return rule_536(inflow_m3d, storage_m3, month);
        case 539: return rule_539(inflow_m3d, storage_m3, month);
        case 544: return rule_544(inflow_m3d, storage_m3, month);
        case 555: return rule_555(inflow_m3d, storage_m3, month);
        case 585: return rule_585(inflow_m3d, storage_m3, month);
        case 606: return rule_606(inflow_m3d, storage_m3, month);
        case 621: return rule_621(inflow_m3d, storage_m3, month);
        case 624: return rule_624(inflow_m3d, storage_m3, month);
        case 640: return rule_640(inflow_m3d, storage_m3, month);
        case 642: return rule_642(inflow_m3d, storage_m3, month);
        case 651: return rule_651(inflow_m3d, storage_m3, month);
        case 694: return rule_694(inflow_m3d, storage_m3, month);
        case 698: return rule_698(inflow_m3d, storage_m3, month);
        case 704: return rule_704(inflow_m3d, storage_m3, month);
        case 713: return rule_713(inflow_m3d, storage_m3, month);
        case 720: return rule_720(inflow_m3d, storage_m3, month);
        case 721: return rule_721(inflow_m3d, storage_m3, month);
        case 727: return rule_727(inflow_m3d, storage_m3, month);
        case 740: return rule_740(inflow_m3d, storage_m3, month);
        case 747: return rule_747(inflow_m3d, storage_m3, month);
        case 756: return rule_756(inflow_m3d, storage_m3, month);
        case 758: return rule_758(inflow_m3d, storage_m3, month);
        case 775: return rule_775(inflow_m3d, storage_m3, month);
        case 777: return rule_777(inflow_m3d, storage_m3, month);
        case 786: return rule_786(inflow_m3d, storage_m3, month);
        case 788: return rule_788(inflow_m3d, storage_m3, month);
        case 790: return rule_790(inflow_m3d, storage_m3, month);
        case 794: return rule_794(inflow_m3d, storage_m3, month);
        case 795: return rule_795(inflow_m3d, storage_m3, month);
        case 796: return rule_796(inflow_m3d, storage_m3, month);
        case 800: return rule_800(inflow_m3d, storage_m3, month);
        case 801: return rule_801(inflow_m3d, storage_m3, month);
        case 803: return rule_803(inflow_m3d, storage_m3, month);
        case 806: return rule_806(inflow_m3d, storage_m3, month);
        case 807: return rule_807(inflow_m3d, storage_m3, month);
        case 811: return rule_811(inflow_m3d, storage_m3, month);
        case 813: return rule_813(inflow_m3d, storage_m3, month);
        case 814: return rule_814(inflow_m3d, storage_m3, month);
        case 818: return rule_818(inflow_m3d, storage_m3, month);
        case 821: return rule_821(inflow_m3d, storage_m3, month);
        case 822: return rule_822(inflow_m3d, storage_m3, month);
        case 827: return rule_827(inflow_m3d, storage_m3, month);
        case 828: return rule_828(inflow_m3d, storage_m3, month);
        case 829: return rule_829(inflow_m3d, storage_m3, month);
        case 831: return rule_831(inflow_m3d, storage_m3, month);
        case 833: return rule_833(inflow_m3d, storage_m3, month);
        case 834: return rule_834(inflow_m3d, storage_m3, month);
        case 838: return rule_838(inflow_m3d, storage_m3, month);
        case 843: return rule_843(inflow_m3d, storage_m3, month);
        case 844: return rule_844(inflow_m3d, storage_m3, month);
        case 845: return rule_845(inflow_m3d, storage_m3, month);
        case 851: return rule_851(inflow_m3d, storage_m3, month);
        case 852: return rule_852(inflow_m3d, storage_m3, month);
        case 853: return rule_853(inflow_m3d, storage_m3, month);
        case 854: return rule_854(inflow_m3d, storage_m3, month);
        case 857: return rule_857(inflow_m3d, storage_m3, month);
        case 858: return rule_858(inflow_m3d, storage_m3, month);
        case 862: return rule_862(inflow_m3d, storage_m3, month);
        case 863: return rule_863(inflow_m3d, storage_m3, month);
        case 866: return rule_866(inflow_m3d, storage_m3, month);
        case 867: return rule_867(inflow_m3d, storage_m3, month);
        case 869: return rule_869(inflow_m3d, storage_m3, month);
        case 870: return rule_870(inflow_m3d, storage_m3, month);
        case 872: return rule_872(inflow_m3d, storage_m3, month);
        case 873: return rule_873(inflow_m3d, storage_m3, month);
        case 874: return rule_874(inflow_m3d, storage_m3, month);
        case 876: return rule_876(inflow_m3d, storage_m3, month);
        case 877: return rule_877(inflow_m3d, storage_m3, month);
        case 878: return rule_878(inflow_m3d, storage_m3, month);
        case 879: return rule_879(inflow_m3d, storage_m3, month);
        case 880: return rule_880(inflow_m3d, storage_m3, month);
        case 883: return rule_883(inflow_m3d, storage_m3, month);
        case 884: return rule_884(inflow_m3d, storage_m3, month);
        case 886: return rule_886(inflow_m3d, storage_m3, month);
        case 887: return rule_887(inflow_m3d, storage_m3, month);
        case 897: return rule_897(inflow_m3d, storage_m3, month);
        case 899: return rule_899(inflow_m3d, storage_m3, month);
        case 900: return rule_900(inflow_m3d, storage_m3, month);
        case 905: return rule_905(inflow_m3d, storage_m3, month);
        case 909: return rule_909(inflow_m3d, storage_m3, month);
        case 911: return rule_911(inflow_m3d, storage_m3, month);
        case 912: return rule_912(inflow_m3d, storage_m3, month);
        case 915: return rule_915(inflow_m3d, storage_m3, month);
        case 916: return rule_916(inflow_m3d, storage_m3, month);
        case 919: return rule_919(inflow_m3d, storage_m3, month);
        case 920: return rule_920(inflow_m3d, storage_m3, month);
        case 923: return rule_923(inflow_m3d, storage_m3, month);
        case 928: return rule_928(inflow_m3d, storage_m3, month);
        case 938: return rule_938(inflow_m3d, storage_m3, month);
        case 939: return rule_939(inflow_m3d, storage_m3, month);
        case 944: return rule_944(inflow_m3d, storage_m3, month);
        case 945: return rule_945(inflow_m3d, storage_m3, month);
        case 946: return rule_946(inflow_m3d, storage_m3, month);
        case 948: return rule_948(inflow_m3d, storage_m3, month);
        case 950: return rule_950(inflow_m3d, storage_m3, month);
        case 954: return rule_954(inflow_m3d, storage_m3, month);
        case 956: return rule_956(inflow_m3d, storage_m3, month);
        case 958: return rule_958(inflow_m3d, storage_m3, month);
        case 962: return rule_962(inflow_m3d, storage_m3, month);
        case 986: return rule_986(inflow_m3d, storage_m3, month);
        case 989: return rule_989(inflow_m3d, storage_m3, month);
        case 2194: return rule_2194(inflow_m3d, storage_m3, month);
        case 2197: return rule_2197(inflow_m3d, storage_m3, month);
        case 2229: return rule_2229(inflow_m3d, storage_m3, month);
        case 2232: return rule_2232(inflow_m3d, storage_m3, month);
        case 2236: return rule_2236(inflow_m3d, storage_m3, month);
        case 2345: return rule_2345(inflow_m3d, storage_m3, month);
        case 2429: return rule_2429(inflow_m3d, storage_m3, month);
        case 2432: return rule_2432(inflow_m3d, storage_m3, month);
        case 2483: return rule_2483(inflow_m3d, storage_m3, month);
        case 2525: return rule_2525(inflow_m3d, storage_m3, month);
        case 2560: return rule_2560(inflow_m3d, storage_m3, month);
        case 2646: return rule_2646(inflow_m3d, storage_m3, month);
        case 2650: return rule_2650(inflow_m3d, storage_m3, month);
        case 2664: return rule_2664(inflow_m3d, storage_m3, month);
        case 2666: return rule_2666(inflow_m3d, storage_m3, month);
        case 2682: return rule_2682(inflow_m3d, storage_m3, month);
        case 2684: return rule_2684(inflow_m3d, storage_m3, month);
        case 2694: return rule_2694(inflow_m3d, storage_m3, month);
        case 2708: return rule_2708(inflow_m3d, storage_m3, month);
        case 2731: return rule_2731(inflow_m3d, storage_m3, month);
        case 2741: return rule_2741(inflow_m3d, storage_m3, month);
        case 2744: return rule_2744(inflow_m3d, storage_m3, month);
        case 2764: return rule_2764(inflow_m3d, storage_m3, month);
        case 2767: return rule_2767(inflow_m3d, storage_m3, month);
        case 2768: return rule_2768(inflow_m3d, storage_m3, month);
        case 2785: return rule_2785(inflow_m3d, storage_m3, month);
        case 2787: return rule_2787(inflow_m3d, storage_m3, month);
        case 2789: return rule_2789(inflow_m3d, storage_m3, month);
        case 2794: return rule_2794(inflow_m3d, storage_m3, month);
        case 2800: return rule_2800(inflow_m3d, storage_m3, month);
        case 2801: return rule_2801(inflow_m3d, storage_m3, month);
        case 2806: return rule_2806(inflow_m3d, storage_m3, month);
        case 2838: return rule_2838(inflow_m3d, storage_m3, month);
        case 2862: return rule_2862(inflow_m3d, storage_m3, month);
        case 2863: return rule_2863(inflow_m3d, storage_m3, month);
        case 2867: return rule_2867(inflow_m3d, storage_m3, month);
        case 2870: return rule_2870(inflow_m3d, storage_m3, month);
        case 2873: return rule_2873(inflow_m3d, storage_m3, month);
        case 2879: return rule_2879(inflow_m3d, storage_m3, month);
        case 2893: return rule_2893(inflow_m3d, storage_m3, month);
        case 2894: return rule_2894(inflow_m3d, storage_m3, month);
        case 2912: return rule_2912(inflow_m3d, storage_m3, month);
        case 2916: return rule_2916(inflow_m3d, storage_m3, month);
        case 2918: return rule_2918(inflow_m3d, storage_m3, month);
        case 2926: return rule_2926(inflow_m3d, storage_m3, month);
        case 2927: return rule_2927(inflow_m3d, storage_m3, month);
        case 2948: return rule_2948(inflow_m3d, storage_m3, month);
        case 2956: return rule_2956(inflow_m3d, storage_m3, month);
        case 2957: return rule_2957(inflow_m3d, storage_m3, month);
        case 2963: return rule_2963(inflow_m3d, storage_m3, month);
        case 2969: return rule_2969(inflow_m3d, storage_m3, month);
        case 2978: return rule_2978(inflow_m3d, storage_m3, month);
        case 2989: return rule_2989(inflow_m3d, storage_m3, month);
        case 2995: return rule_2995(inflow_m3d, storage_m3, month);
        case 2999: return rule_2999(inflow_m3d, storage_m3, month);
        case 3000: return rule_3000(inflow_m3d, storage_m3, month);
        case 3009: return rule_3009(inflow_m3d, storage_m3, month);
        case 3010: return rule_3010(inflow_m3d, storage_m3, month);
        case 3029: return rule_3029(inflow_m3d, storage_m3, month);
        case 3035: return rule_3035(inflow_m3d, storage_m3, month);
        case 3054: return rule_3054(inflow_m3d, storage_m3, month);
        case 3072: return rule_3072(inflow_m3d, storage_m3, month);
        case 3094: return rule_3094(inflow_m3d, storage_m3, month);
        case 3100: return rule_3100(inflow_m3d, storage_m3, month);
        case 3111: return rule_3111(inflow_m3d, storage_m3, month);
        case 3112: return rule_3112(inflow_m3d, storage_m3, month);
        case 3115: return rule_3115(inflow_m3d, storage_m3, month);
        case 3143: return rule_3143(inflow_m3d, storage_m3, month);
        case 3152: return rule_3152(inflow_m3d, storage_m3, month);
        case 3156: return rule_3156(inflow_m3d, storage_m3, month);
        case 3158: return rule_3158(inflow_m3d, storage_m3, month);
        case 3159: return rule_3159(inflow_m3d, storage_m3, month);
        case 5560: return rule_5560(inflow_m3d, storage_m3, month);
        case 5587: return rule_5587(inflow_m3d, storage_m3, month);
        case 5620: return rule_5620(inflow_m3d, storage_m3, month);
        case 5663: return rule_5663(inflow_m3d, storage_m3, month);
        case 6853: return rule_6853(inflow_m3d, storage_m3, month);

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
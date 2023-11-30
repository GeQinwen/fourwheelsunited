//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: fourwheelscontroller_data.cpp
//
// Code generated for Simulink model 'fourwheelscontroller'.
//
// Model version                  : 1.2
// Simulink Coder version         : 23.2 (R2023b) 01-Aug-2023
// C/C++ source code generated on : Wed Nov 29 21:20:23 2023
//
// Target selection: ert.tlc
// Embedded hardware selection: Generic->Unspecified (assume 32-bit Generic)
// Code generation objectives: Unspecified
// Validation result: Not run
//
#include "fourwheelscontroller.h"

// Block parameters (default storage)
P_fourwheelscontroller_T fourwheelscontroller_P = {
  // Mask Parameter: g1slow_D
  //  Referenced by: '<S37>/Derivative Gain'

  0.0,

  // Mask Parameter: g2fast_D
  //  Referenced by: '<S85>/Derivative Gain'

  0.0,

  // Mask Parameter: g2fast_I
  //  Referenced by: '<S88>/Integral Gain'

  0.0,

  // Mask Parameter: g1slow_I
  //  Referenced by: '<S40>/Integral Gain'

  0.0,

  // Mask Parameter: g1slow_InitialConditionForFilte
  //  Referenced by: '<S38>/Filter'

  0.0,

  // Mask Parameter: g2fast_InitialConditionForFilte
  //  Referenced by: '<S86>/Filter'

  0.0,

  // Mask Parameter: g1slow_InitialConditionForInteg
  //  Referenced by: '<S43>/Integrator'

  0.0,

  // Mask Parameter: g2fast_InitialConditionForInteg
  //  Referenced by: '<S91>/Integrator'

  0.0,

  // Mask Parameter: g2fast_Kb
  //  Referenced by: '<S84>/Kb'

  1.0,

  // Mask Parameter: g1slow_Kb
  //  Referenced by: '<S36>/Kb'

  1.0,

  // Mask Parameter: g1slow_LowerSaturationLimit
  //  Referenced by: '<S50>/Saturation'

  -0.25,

  // Mask Parameter: g2fast_LowerSaturationLimit
  //  Referenced by: '<S98>/Saturation'

  -3.0,

  // Mask Parameter: g1slow_N
  //  Referenced by: '<S46>/Filter Coefficient'

  100.0,

  // Mask Parameter: g2fast_N
  //  Referenced by: '<S94>/Filter Coefficient'

  100.0,

  // Mask Parameter: g1slow_P
  //  Referenced by: '<S48>/Proportional Gain'

  0.01,

  // Mask Parameter: g2fast_P
  //  Referenced by: '<S96>/Proportional Gain'

  0.2,

  // Mask Parameter: g1slow_UpperSaturationLimit
  //  Referenced by: '<S50>/Saturation'

  0.2,

  // Mask Parameter: g2fast_UpperSaturationLimit
  //  Referenced by: '<S98>/Saturation'

  1.5,

  // Computed Parameter: Constant_Value
  //  Referenced by: '<S1>/Constant'

  {
    0.0                                // Data
  },

  // Computed Parameter: Out1_Y0
  //  Referenced by: '<S10>/Out1'

  {
    0.0                                // Data
  },

  // Computed Parameter: Constant_Value_m
  //  Referenced by: '<S6>/Constant'

  {
    0.0                                // Data
  },

  // Computed Parameter: Out1_Y0_h
  //  Referenced by: '<S11>/Out1'

  {
    0.0                                // Data
  },

  // Computed Parameter: Constant_Value_o
  //  Referenced by: '<S7>/Constant'

  {
    0.0                                // Data
  },

  // Expression: 4
  //  Referenced by: '<Root>/Constant'

  4.0,

  // Expression: 1
  //  Referenced by: '<Root>/Gain'

  1.0
};

//
// File trailer for generated code.
//
// [EOF]
//

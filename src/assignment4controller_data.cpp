//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: assignment4controller_data.cpp
//
// Code generated for Simulink model 'assignment4controller'.
//
// Model version                  : 8.51
// Simulink Coder version         : 23.2 (R2023b) 01-Aug-2023
// C/C++ source code generated on : Thu Nov 16 12:17:12 2023
//
// Target selection: ert.tlc
// Embedded hardware selection: Generic->Unspecified (assume 32-bit Generic)
// Code generation objectives: Unspecified
// Validation result: Not run
//
#include "assignment4controller.h"

// Block parameters (default storage)
P_assignment4controller_T assignment4controller_P = {
  // Mask Parameter: g1slow_D
  //  Referenced by: '<S39>/Derivative Gain'

  0.0,

  // Mask Parameter: g2fast_D
  //  Referenced by: '<S87>/Derivative Gain'

  0.0,

  // Mask Parameter: g2fast_I
  //  Referenced by: '<S90>/Integral Gain'

  0.0,

  // Mask Parameter: g1slow_I
  //  Referenced by: '<S42>/Integral Gain'

  0.0,

  // Mask Parameter: g1slow_InitialConditionForFilte
  //  Referenced by: '<S40>/Filter'

  0.0,

  // Mask Parameter: g2fast_InitialConditionForFilte
  //  Referenced by: '<S88>/Filter'

  0.0,

  // Mask Parameter: g1slow_InitialConditionForInteg
  //  Referenced by: '<S45>/Integrator'

  0.0,

  // Mask Parameter: g2fast_InitialConditionForInteg
  //  Referenced by: '<S93>/Integrator'

  0.0,

  // Mask Parameter: g2fast_Kb
  //  Referenced by: '<S86>/Kb'

  1.0,

  // Mask Parameter: g1slow_Kb
  //  Referenced by: '<S38>/Kb'

  1.0,

  // Mask Parameter: g1slow_LowerSaturationLimit
  //  Referenced by: '<S52>/Saturation'

  -0.25,

  // Mask Parameter: g2fast_LowerSaturationLimit
  //  Referenced by: '<S100>/Saturation'

  -3.0,

  // Mask Parameter: g1slow_N
  //  Referenced by: '<S48>/Filter Coefficient'

  100.0,

  // Mask Parameter: g2fast_N
  //  Referenced by: '<S96>/Filter Coefficient'

  100.0,

  // Mask Parameter: g1slow_P
  //  Referenced by: '<S50>/Proportional Gain'

  0.05,

  // Mask Parameter: g2fast_P
  //  Referenced by: '<S98>/Proportional Gain'

  2.0,

  // Mask Parameter: g1slow_UpperSaturationLimit
  //  Referenced by: '<S52>/Saturation'

  0.2,

  // Mask Parameter: g2fast_UpperSaturationLimit
  //  Referenced by: '<S100>/Saturation'

  1.5,

  // Computed Parameter: Constant_Value
  //  Referenced by: '<S1>/Constant'

  {
    0.0                                // Data
  },

  // Computed Parameter: Out1_Y0
  //  Referenced by: '<S11>/Out1'

  {
    0.0                                // Data
  },

  // Computed Parameter: Constant_Value_k
  //  Referenced by: '<S6>/Constant'

  {
    0.0                                // Data
  },

  // Computed Parameter: Out1_Y0_l
  //  Referenced by: '<S12>/Out1'

  {
    0.0                                // Data
  },

  // Computed Parameter: Constant_Value_f
  //  Referenced by: '<S7>/Constant'

  {
    0.0                                // Data
  },

  // Computed Parameter: Out1_Y0_e
  //  Referenced by: '<S13>/Out1'

  {
    0.0                                // Data
  },

  // Computed Parameter: Constant_Value_p
  //  Referenced by: '<S8>/Constant'

  {
    0.0                                // Data
  },

  // Expression: 4
  //  Referenced by: '<Root>/Constant'

  4.0,

  // Expression: 0.7
  //  Referenced by: '<Root>/Gain'

  0.7
};

//
// File trailer for generated code.
//
// [EOF]
//

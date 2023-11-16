//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: assignment4controller_data.cpp
//
// Code generated for Simulink model 'assignment4controller'.
//
// Model version                  : 1.1
// Simulink Coder version         : 23.2 (R2023b) 01-Aug-2023
// C/C++ source code generated on : Wed Nov 15 20:58:56 2023
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
  //  Referenced by: '<S46>/Derivative Gain'

  0.0,

  // Mask Parameter: g2fast_D
  //  Referenced by: '<S94>/Derivative Gain'

  0.0,

  // Mask Parameter: g3emergency_D
  //  Referenced by: '<S142>/Derivative Gain'

  0.0,

  // Mask Parameter: g3emergency_I
  //  Referenced by: '<S145>/Integral Gain'

  3.0,

  // Mask Parameter: g2fast_I
  //  Referenced by: '<S97>/Integral Gain'

  2.0,

  // Mask Parameter: g1slow_I
  //  Referenced by: '<S49>/Integral Gain'

  1.5,

  // Mask Parameter: g1slow_InitialConditionForFilte
  //  Referenced by: '<S47>/Filter'

  0.0,

  // Mask Parameter: g2fast_InitialConditionForFilte
  //  Referenced by: '<S95>/Filter'

  0.0,

  // Mask Parameter: g3emergency_InitialConditionFor
  //  Referenced by: '<S143>/Filter'

  0.0,

  // Mask Parameter: g1slow_InitialConditionForInteg
  //  Referenced by: '<S52>/Integrator'

  0.0,

  // Mask Parameter: g2fast_InitialConditionForInteg
  //  Referenced by: '<S100>/Integrator'

  0.0,

  // Mask Parameter: g3emergency_InitialConditionF_l
  //  Referenced by: '<S148>/Integrator'

  0.0,

  // Mask Parameter: g3emergency_Kb
  //  Referenced by: '<S141>/Kb'

  1.0,

  // Mask Parameter: g2fast_Kb
  //  Referenced by: '<S93>/Kb'

  1.0,

  // Mask Parameter: g1slow_Kb
  //  Referenced by: '<S45>/Kb'

  1.0,

  // Mask Parameter: g1slow_LowerSaturationLimit
  //  Referenced by: '<S59>/Saturation'

  -3.0,

  // Mask Parameter: g2fast_LowerSaturationLimit
  //  Referenced by: '<S107>/Saturation'

  -3.0,

  // Mask Parameter: g3emergency_LowerSaturationLimi
  //  Referenced by: '<S155>/Saturation'

  -3.0,

  // Mask Parameter: g1slow_N
  //  Referenced by: '<S55>/Filter Coefficient'

  100.0,

  // Mask Parameter: g2fast_N
  //  Referenced by: '<S103>/Filter Coefficient'

  100.0,

  // Mask Parameter: g3emergency_N
  //  Referenced by: '<S151>/Filter Coefficient'

  100.0,

  // Mask Parameter: g1slow_P
  //  Referenced by: '<S57>/Proportional Gain'

  1.5,

  // Mask Parameter: g2fast_P
  //  Referenced by: '<S105>/Proportional Gain'

  2.0,

  // Mask Parameter: g3emergency_P
  //  Referenced by: '<S153>/Proportional Gain'

  3.0,

  // Mask Parameter: g1slow_UpperSaturationLimit
  //  Referenced by: '<S59>/Saturation'

  1.5,

  // Mask Parameter: g2fast_UpperSaturationLimit
  //  Referenced by: '<S107>/Saturation'

  1.5,

  // Mask Parameter: g3emergency_UpperSaturationLimi
  //  Referenced by: '<S155>/Saturation'

  1.5,

  // Mask Parameter: DeadMansSwitch1_stepSize
  //  Referenced by: '<Root>/Dead Man's Switch1'

  0.05,

  // Mask Parameter: DeadMansSwitch_stepSize
  //  Referenced by: '<Root>/Dead Man's Switch'

  0.05,

  // Mask Parameter: DeadMansSwitch2_stepSize
  //  Referenced by: '<Root>/Dead Man's Switch2'

  0.05,

  // Mask Parameter: DeadMansSwitch1_timeout
  //  Referenced by: '<Root>/Dead Man's Switch1'

  0.4,

  // Mask Parameter: DeadMansSwitch_timeout
  //  Referenced by: '<Root>/Dead Man's Switch'

  0.4,

  // Mask Parameter: DeadMansSwitch2_timeout
  //  Referenced by: '<Root>/Dead Man's Switch2'

  0.4,

  // Computed Parameter: Constant_Value
  //  Referenced by: '<S1>/Constant'

  {
    0.0                                // Data
  },

  // Computed Parameter: Out1_Y0
  //  Referenced by: '<S18>/Out1'

  {
    0.0                                // Data
  },

  // Computed Parameter: Constant_Value_e
  //  Referenced by: '<S9>/Constant'

  {
    0.0                                // Data
  },

  // Computed Parameter: Out1_Y0_g
  //  Referenced by: '<S19>/Out1'

  {
    0.0                                // Data
  },

  // Computed Parameter: Constant_Value_k
  //  Referenced by: '<S10>/Constant'

  {
    0.0                                // Data
  },

  // Computed Parameter: Out1_Y0_h
  //  Referenced by: '<S20>/Out1'

  {
    0.0                                // Data
  },

  // Computed Parameter: Constant_Value_o
  //  Referenced by: '<S11>/Constant'

  {
    0.0                                // Data
  },

  // Computed Parameter: TransferFcn_A
  //  Referenced by: '<Root>/Transfer Fcn'

  -1.0,

  // Computed Parameter: TransferFcn_C
  //  Referenced by: '<Root>/Transfer Fcn'

  3.0,

  // Expression: 0.7
  //  Referenced by: '<Root>/Gain'

  0.7,

  // Expression: 10
  //  Referenced by: '<Root>/Constant'

  10.0,

  // Expression: true
  //  Referenced by: '<Root>/Constant2'

  true,

  // Expression: true
  //  Referenced by: '<Root>/Constant1'

  true,

  // Expression: true
  //  Referenced by: '<Root>/Constant3'

  true
};

//
// File trailer for generated code.
//
// [EOF]
//

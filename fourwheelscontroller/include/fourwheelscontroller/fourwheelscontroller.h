//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: fourwheelscontroller.h
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
#ifndef RTW_HEADER_fourwheelscontroller_h_
#define RTW_HEADER_fourwheelscontroller_h_
#include "rtwtypes.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#include "slros_initialize.h"
#include "fourwheelscontroller_types.h"
#include <string.h>
#include <stddef.h>

// Macros for accessing real-time model data structure
#ifndef rtmGetContStateDisabled
#define rtmGetContStateDisabled(rtm)   ((rtm)->contStateDisabled)
#endif

#ifndef rtmSetContStateDisabled
#define rtmSetContStateDisabled(rtm, val) ((rtm)->contStateDisabled = (val))
#endif

#ifndef rtmGetContStates
#define rtmGetContStates(rtm)          ((rtm)->contStates)
#endif

#ifndef rtmSetContStates
#define rtmSetContStates(rtm, val)     ((rtm)->contStates = (val))
#endif

#ifndef rtmGetContTimeOutputInconsistentWithStateAtMajorStepFlag
#define rtmGetContTimeOutputInconsistentWithStateAtMajorStepFlag(rtm) ((rtm)->CTOutputIncnstWithState)
#endif

#ifndef rtmSetContTimeOutputInconsistentWithStateAtMajorStepFlag
#define rtmSetContTimeOutputInconsistentWithStateAtMajorStepFlag(rtm, val) ((rtm)->CTOutputIncnstWithState = (val))
#endif

#ifndef rtmGetDerivCacheNeedsReset
#define rtmGetDerivCacheNeedsReset(rtm) ((rtm)->derivCacheNeedsReset)
#endif

#ifndef rtmSetDerivCacheNeedsReset
#define rtmSetDerivCacheNeedsReset(rtm, val) ((rtm)->derivCacheNeedsReset = (val))
#endif

#ifndef rtmGetIntgData
#define rtmGetIntgData(rtm)            ((rtm)->intgData)
#endif

#ifndef rtmSetIntgData
#define rtmSetIntgData(rtm, val)       ((rtm)->intgData = (val))
#endif

#ifndef rtmGetOdeF
#define rtmGetOdeF(rtm)                ((rtm)->odeF)
#endif

#ifndef rtmSetOdeF
#define rtmSetOdeF(rtm, val)           ((rtm)->odeF = (val))
#endif

#ifndef rtmGetOdeY
#define rtmGetOdeY(rtm)                ((rtm)->odeY)
#endif

#ifndef rtmSetOdeY
#define rtmSetOdeY(rtm, val)           ((rtm)->odeY = (val))
#endif

#ifndef rtmGetPeriodicContStateIndices
#define rtmGetPeriodicContStateIndices(rtm) ((rtm)->periodicContStateIndices)
#endif

#ifndef rtmSetPeriodicContStateIndices
#define rtmSetPeriodicContStateIndices(rtm, val) ((rtm)->periodicContStateIndices = (val))
#endif

#ifndef rtmGetPeriodicContStateRanges
#define rtmGetPeriodicContStateRanges(rtm) ((rtm)->periodicContStateRanges)
#endif

#ifndef rtmSetPeriodicContStateRanges
#define rtmSetPeriodicContStateRanges(rtm, val) ((rtm)->periodicContStateRanges = (val))
#endif

#ifndef rtmGetZCCacheNeedsReset
#define rtmGetZCCacheNeedsReset(rtm)   ((rtm)->zCCacheNeedsReset)
#endif

#ifndef rtmSetZCCacheNeedsReset
#define rtmSetZCCacheNeedsReset(rtm, val) ((rtm)->zCCacheNeedsReset = (val))
#endif

#ifndef rtmGetdX
#define rtmGetdX(rtm)                  ((rtm)->derivs)
#endif

#ifndef rtmSetdX
#define rtmSetdX(rtm, val)             ((rtm)->derivs = (val))
#endif

#ifndef rtmGetErrorStatus
#define rtmGetErrorStatus(rtm)         ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
#define rtmSetErrorStatus(rtm, val)    ((rtm)->errorStatus = (val))
#endif

#ifndef rtmGetStopRequested
#define rtmGetStopRequested(rtm)       ((rtm)->Timing.stopRequestedFlag)
#endif

#ifndef rtmSetStopRequested
#define rtmSetStopRequested(rtm, val)  ((rtm)->Timing.stopRequestedFlag = (val))
#endif

#ifndef rtmGetStopRequestedPtr
#define rtmGetStopRequestedPtr(rtm)    (&((rtm)->Timing.stopRequestedFlag))
#endif

#ifndef rtmGetT
#define rtmGetT(rtm)                   (rtmGetTPtr((rtm))[0])
#endif

#ifndef rtmGetTPtr
#define rtmGetTPtr(rtm)                ((rtm)->Timing.t)
#endif

#ifndef rtmGetTStart
#define rtmGetTStart(rtm)              ((rtm)->Timing.tStart)
#endif

// Block signals (default storage)
struct B_fourwheelscontroller_T {
  real_T ProportionalGain;             // '<S48>/Proportional Gain'
  real_T DerivativeGain;               // '<S37>/Derivative Gain'
  real_T FilterCoefficient;            // '<S46>/Filter Coefficient'
  real_T ProportionalGain_l;           // '<S96>/Proportional Gain'
  real_T DerivativeGain_l;             // '<S85>/Derivative Gain'
  real_T FilterCoefficient_j;          // '<S94>/Filter Coefficient'
  real_T IntegralGain;                 // '<S88>/Integral Gain'
  real_T SumI4;                        // '<S84>/SumI4'
  real_T IntegralGain_g;               // '<S40>/Integral Gain'
  real_T SumI4_f;                      // '<S36>/SumI4'
  SL_Bus_fourwheelscontroller_std_msgs_Float64 In1;// '<S11>/In1'
  SL_Bus_fourwheelscontroller_std_msgs_Float64 In1_p;// '<S10>/In1'
  SL_Bus_fourwheelscontroller_std_msgs_Float64 b_varargout_2;
};

// Block states (default storage) for system '<Root>'
struct DW_fourwheelscontroller_T {
  ros_slroscpp_internal_block_P_T obj; // '<S5>/SinkBlock'
  ros_slroscpp_internal_block_S_T obj_e;// '<S7>/SourceBlock'
  ros_slroscpp_internal_block_S_T obj_o;// '<S6>/SourceBlock'
};

// Continuous states (default storage)
struct X_fourwheelscontroller_T {
  real_T Integrator_CSTATE;            // '<S43>/Integrator'
  real_T Filter_CSTATE;                // '<S38>/Filter'
  real_T Integrator_CSTATE_k;          // '<S91>/Integrator'
  real_T Filter_CSTATE_i;              // '<S86>/Filter'
};

// State derivatives (default storage)
struct XDot_fourwheelscontroller_T {
  real_T Integrator_CSTATE;            // '<S43>/Integrator'
  real_T Filter_CSTATE;                // '<S38>/Filter'
  real_T Integrator_CSTATE_k;          // '<S91>/Integrator'
  real_T Filter_CSTATE_i;              // '<S86>/Filter'
};

// State disabled
struct XDis_fourwheelscontroller_T {
  boolean_T Integrator_CSTATE;         // '<S43>/Integrator'
  boolean_T Filter_CSTATE;             // '<S38>/Filter'
  boolean_T Integrator_CSTATE_k;       // '<S91>/Integrator'
  boolean_T Filter_CSTATE_i;           // '<S86>/Filter'
};

#ifndef ODE3_INTG
#define ODE3_INTG

// ODE3 Integration Data
struct ODE3_IntgData {
  real_T *y;                           // output
  real_T *f[3];                        // derivatives
};

#endif

// Parameters (default storage)
struct P_fourwheelscontroller_T_ {
  real_T g1slow_D;                     // Mask Parameter: g1slow_D
                                          //  Referenced by: '<S37>/Derivative Gain'

  real_T g2fast_D;                     // Mask Parameter: g2fast_D
                                          //  Referenced by: '<S85>/Derivative Gain'

  real_T g2fast_I;                     // Mask Parameter: g2fast_I
                                          //  Referenced by: '<S88>/Integral Gain'

  real_T g1slow_I;                     // Mask Parameter: g1slow_I
                                          //  Referenced by: '<S40>/Integral Gain'

  real_T g1slow_InitialConditionForFilte;
                              // Mask Parameter: g1slow_InitialConditionForFilte
                                 //  Referenced by: '<S38>/Filter'

  real_T g2fast_InitialConditionForFilte;
                              // Mask Parameter: g2fast_InitialConditionForFilte
                                 //  Referenced by: '<S86>/Filter'

  real_T g1slow_InitialConditionForInteg;
                              // Mask Parameter: g1slow_InitialConditionForInteg
                                 //  Referenced by: '<S43>/Integrator'

  real_T g2fast_InitialConditionForInteg;
                              // Mask Parameter: g2fast_InitialConditionForInteg
                                 //  Referenced by: '<S91>/Integrator'

  real_T g2fast_Kb;                    // Mask Parameter: g2fast_Kb
                                          //  Referenced by: '<S84>/Kb'

  real_T g1slow_Kb;                    // Mask Parameter: g1slow_Kb
                                          //  Referenced by: '<S36>/Kb'

  real_T g1slow_LowerSaturationLimit;
                                  // Mask Parameter: g1slow_LowerSaturationLimit
                                     //  Referenced by: '<S50>/Saturation'

  real_T g2fast_LowerSaturationLimit;
                                  // Mask Parameter: g2fast_LowerSaturationLimit
                                     //  Referenced by: '<S98>/Saturation'

  real_T g1slow_N;                     // Mask Parameter: g1slow_N
                                          //  Referenced by: '<S46>/Filter Coefficient'

  real_T g2fast_N;                     // Mask Parameter: g2fast_N
                                          //  Referenced by: '<S94>/Filter Coefficient'

  real_T g1slow_P;                     // Mask Parameter: g1slow_P
                                          //  Referenced by: '<S48>/Proportional Gain'

  real_T g2fast_P;                     // Mask Parameter: g2fast_P
                                          //  Referenced by: '<S96>/Proportional Gain'

  real_T g1slow_UpperSaturationLimit;
                                  // Mask Parameter: g1slow_UpperSaturationLimit
                                     //  Referenced by: '<S50>/Saturation'

  real_T g2fast_UpperSaturationLimit;
                                  // Mask Parameter: g2fast_UpperSaturationLimit
                                     //  Referenced by: '<S98>/Saturation'

  SL_Bus_fourwheelscontroller_std_msgs_Float64 Constant_Value;// Computed Parameter: Constant_Value
                                                                 //  Referenced by: '<S1>/Constant'

  SL_Bus_fourwheelscontroller_std_msgs_Float64 Out1_Y0;// Computed Parameter: Out1_Y0
                                                          //  Referenced by: '<S10>/Out1'

  SL_Bus_fourwheelscontroller_std_msgs_Float64 Constant_Value_m;// Computed Parameter: Constant_Value_m
                                                                   //  Referenced by: '<S6>/Constant'

  SL_Bus_fourwheelscontroller_std_msgs_Float64 Out1_Y0_h;// Computed Parameter: Out1_Y0_h
                                                            //  Referenced by: '<S11>/Out1'

  SL_Bus_fourwheelscontroller_std_msgs_Float64 Constant_Value_o;// Computed Parameter: Constant_Value_o
                                                                   //  Referenced by: '<S7>/Constant'

  real_T Constant_Value_e;             // Expression: 4
                                          //  Referenced by: '<Root>/Constant'

  real_T Gain_Gain;                    // Expression: 1
                                          //  Referenced by: '<Root>/Gain'

};

// Real-time Model Data Structure
struct tag_RTM_fourwheelscontroller_T {
  const char_T *errorStatus;
  RTWSolverInfo solverInfo;
  X_fourwheelscontroller_T *contStates;
  int_T *periodicContStateIndices;
  real_T *periodicContStateRanges;
  real_T *derivs;
  XDis_fourwheelscontroller_T *contStateDisabled;
  boolean_T zCCacheNeedsReset;
  boolean_T derivCacheNeedsReset;
  boolean_T CTOutputIncnstWithState;
  real_T odeY[4];
  real_T odeF[3][4];
  ODE3_IntgData intgData;

  //
  //  Sizes:
  //  The following substructure contains sizes information
  //  for many of the model attributes such as inputs, outputs,
  //  dwork, sample times, etc.

  struct {
    int_T numContStates;
    int_T numPeriodicContStates;
    int_T numSampTimes;
  } Sizes;

  //
  //  Timing:
  //  The following substructure contains information regarding
  //  the timing information for the model.

  struct {
    uint32_T clockTick0;
    time_T stepSize0;
    uint32_T clockTick1;
    time_T tStart;
    SimTimeStep simTimeStep;
    boolean_T stopRequestedFlag;
    time_T *t;
    time_T tArray[2];
  } Timing;
};

// Block parameters (default storage)
#ifdef __cplusplus

extern "C"
{

#endif

  extern P_fourwheelscontroller_T fourwheelscontroller_P;

#ifdef __cplusplus

}

#endif

// Block signals (default storage)
#ifdef __cplusplus

extern "C"
{

#endif

  extern struct B_fourwheelscontroller_T fourwheelscontroller_B;

#ifdef __cplusplus

}

#endif

// Continuous states (default storage)
extern X_fourwheelscontroller_T fourwheelscontroller_X;

// Disabled states (default storage)
extern XDis_fourwheelscontroller_T fourwheelscontroller_XDis;

// Block states (default storage)
extern struct DW_fourwheelscontroller_T fourwheelscontroller_DW;

#ifdef __cplusplus

extern "C"
{

#endif

  // Model entry point functions
  extern void fourwheelscontroller_initialize(void);
  extern void fourwheelscontroller_step(void);
  extern void fourwheelscontroller_terminate(void);

#ifdef __cplusplus

}

#endif

// Real-time Model object
#ifdef __cplusplus

extern "C"
{

#endif

  extern RT_MODEL_fourwheelscontroller_T *const fourwheelscontroller_M;

#ifdef __cplusplus

}

#endif

extern volatile boolean_T stopRequested;
extern volatile boolean_T runModel;

//-
//  The generated code includes comments that allow you to trace directly
//  back to the appropriate location in the model.  The basic format
//  is <system>/block_name, where system is the system number (uniquely
//  assigned by Simulink) and block_name is the name of the block.
//
//  Use the MATLAB hilite_system command to trace the generated code back
//  to the model.  For example,
//
//  hilite_system('<S3>')    - opens system 3
//  hilite_system('<S3>/Kp') - opens and selects block Kp which resides in S3
//
//  Here is the system hierarchy for this model
//
//  '<Root>' : 'fourwheelscontroller'
//  '<S1>'   : 'fourwheelscontroller/Blank Message'
//  '<S2>'   : 'fourwheelscontroller/MATLAB Function'
//  '<S3>'   : 'fourwheelscontroller/MATLAB Function1'
//  '<S4>'   : 'fourwheelscontroller/MATLAB Function2'
//  '<S5>'   : 'fourwheelscontroller/Publish'
//  '<S6>'   : 'fourwheelscontroller/Subscribe'
//  '<S7>'   : 'fourwheelscontroller/Subscribe1'
//  '<S8>'   : 'fourwheelscontroller/g1 (slow)'
//  '<S9>'   : 'fourwheelscontroller/g2 (fast)'
//  '<S10>'  : 'fourwheelscontroller/Subscribe/Enabled Subsystem'
//  '<S11>'  : 'fourwheelscontroller/Subscribe1/Enabled Subsystem'
//  '<S12>'  : 'fourwheelscontroller/g1 (slow)/Anti-windup'
//  '<S13>'  : 'fourwheelscontroller/g1 (slow)/D Gain'
//  '<S14>'  : 'fourwheelscontroller/g1 (slow)/Filter'
//  '<S15>'  : 'fourwheelscontroller/g1 (slow)/Filter ICs'
//  '<S16>'  : 'fourwheelscontroller/g1 (slow)/I Gain'
//  '<S17>'  : 'fourwheelscontroller/g1 (slow)/Ideal P Gain'
//  '<S18>'  : 'fourwheelscontroller/g1 (slow)/Ideal P Gain Fdbk'
//  '<S19>'  : 'fourwheelscontroller/g1 (slow)/Integrator'
//  '<S20>'  : 'fourwheelscontroller/g1 (slow)/Integrator ICs'
//  '<S21>'  : 'fourwheelscontroller/g1 (slow)/N Copy'
//  '<S22>'  : 'fourwheelscontroller/g1 (slow)/N Gain'
//  '<S23>'  : 'fourwheelscontroller/g1 (slow)/P Copy'
//  '<S24>'  : 'fourwheelscontroller/g1 (slow)/Parallel P Gain'
//  '<S25>'  : 'fourwheelscontroller/g1 (slow)/Reset Signal'
//  '<S26>'  : 'fourwheelscontroller/g1 (slow)/Saturation'
//  '<S27>'  : 'fourwheelscontroller/g1 (slow)/Saturation Fdbk'
//  '<S28>'  : 'fourwheelscontroller/g1 (slow)/Sum'
//  '<S29>'  : 'fourwheelscontroller/g1 (slow)/Sum Fdbk'
//  '<S30>'  : 'fourwheelscontroller/g1 (slow)/Tracking Mode'
//  '<S31>'  : 'fourwheelscontroller/g1 (slow)/Tracking Mode Sum'
//  '<S32>'  : 'fourwheelscontroller/g1 (slow)/Tsamp - Integral'
//  '<S33>'  : 'fourwheelscontroller/g1 (slow)/Tsamp - Ngain'
//  '<S34>'  : 'fourwheelscontroller/g1 (slow)/postSat Signal'
//  '<S35>'  : 'fourwheelscontroller/g1 (slow)/preSat Signal'
//  '<S36>'  : 'fourwheelscontroller/g1 (slow)/Anti-windup/Back Calculation'
//  '<S37>'  : 'fourwheelscontroller/g1 (slow)/D Gain/Internal Parameters'
//  '<S38>'  : 'fourwheelscontroller/g1 (slow)/Filter/Cont. Filter'
//  '<S39>'  : 'fourwheelscontroller/g1 (slow)/Filter ICs/Internal IC - Filter'
//  '<S40>'  : 'fourwheelscontroller/g1 (slow)/I Gain/Internal Parameters'
//  '<S41>'  : 'fourwheelscontroller/g1 (slow)/Ideal P Gain/Passthrough'
//  '<S42>'  : 'fourwheelscontroller/g1 (slow)/Ideal P Gain Fdbk/Disabled'
//  '<S43>'  : 'fourwheelscontroller/g1 (slow)/Integrator/Continuous'
//  '<S44>'  : 'fourwheelscontroller/g1 (slow)/Integrator ICs/Internal IC'
//  '<S45>'  : 'fourwheelscontroller/g1 (slow)/N Copy/Disabled'
//  '<S46>'  : 'fourwheelscontroller/g1 (slow)/N Gain/Internal Parameters'
//  '<S47>'  : 'fourwheelscontroller/g1 (slow)/P Copy/Disabled'
//  '<S48>'  : 'fourwheelscontroller/g1 (slow)/Parallel P Gain/Internal Parameters'
//  '<S49>'  : 'fourwheelscontroller/g1 (slow)/Reset Signal/Disabled'
//  '<S50>'  : 'fourwheelscontroller/g1 (slow)/Saturation/Enabled'
//  '<S51>'  : 'fourwheelscontroller/g1 (slow)/Saturation Fdbk/Disabled'
//  '<S52>'  : 'fourwheelscontroller/g1 (slow)/Sum/Sum_PID'
//  '<S53>'  : 'fourwheelscontroller/g1 (slow)/Sum Fdbk/Disabled'
//  '<S54>'  : 'fourwheelscontroller/g1 (slow)/Tracking Mode/Disabled'
//  '<S55>'  : 'fourwheelscontroller/g1 (slow)/Tracking Mode Sum/Passthrough'
//  '<S56>'  : 'fourwheelscontroller/g1 (slow)/Tsamp - Integral/TsSignalSpecification'
//  '<S57>'  : 'fourwheelscontroller/g1 (slow)/Tsamp - Ngain/Passthrough'
//  '<S58>'  : 'fourwheelscontroller/g1 (slow)/postSat Signal/Forward_Path'
//  '<S59>'  : 'fourwheelscontroller/g1 (slow)/preSat Signal/Forward_Path'
//  '<S60>'  : 'fourwheelscontroller/g2 (fast)/Anti-windup'
//  '<S61>'  : 'fourwheelscontroller/g2 (fast)/D Gain'
//  '<S62>'  : 'fourwheelscontroller/g2 (fast)/Filter'
//  '<S63>'  : 'fourwheelscontroller/g2 (fast)/Filter ICs'
//  '<S64>'  : 'fourwheelscontroller/g2 (fast)/I Gain'
//  '<S65>'  : 'fourwheelscontroller/g2 (fast)/Ideal P Gain'
//  '<S66>'  : 'fourwheelscontroller/g2 (fast)/Ideal P Gain Fdbk'
//  '<S67>'  : 'fourwheelscontroller/g2 (fast)/Integrator'
//  '<S68>'  : 'fourwheelscontroller/g2 (fast)/Integrator ICs'
//  '<S69>'  : 'fourwheelscontroller/g2 (fast)/N Copy'
//  '<S70>'  : 'fourwheelscontroller/g2 (fast)/N Gain'
//  '<S71>'  : 'fourwheelscontroller/g2 (fast)/P Copy'
//  '<S72>'  : 'fourwheelscontroller/g2 (fast)/Parallel P Gain'
//  '<S73>'  : 'fourwheelscontroller/g2 (fast)/Reset Signal'
//  '<S74>'  : 'fourwheelscontroller/g2 (fast)/Saturation'
//  '<S75>'  : 'fourwheelscontroller/g2 (fast)/Saturation Fdbk'
//  '<S76>'  : 'fourwheelscontroller/g2 (fast)/Sum'
//  '<S77>'  : 'fourwheelscontroller/g2 (fast)/Sum Fdbk'
//  '<S78>'  : 'fourwheelscontroller/g2 (fast)/Tracking Mode'
//  '<S79>'  : 'fourwheelscontroller/g2 (fast)/Tracking Mode Sum'
//  '<S80>'  : 'fourwheelscontroller/g2 (fast)/Tsamp - Integral'
//  '<S81>'  : 'fourwheelscontroller/g2 (fast)/Tsamp - Ngain'
//  '<S82>'  : 'fourwheelscontroller/g2 (fast)/postSat Signal'
//  '<S83>'  : 'fourwheelscontroller/g2 (fast)/preSat Signal'
//  '<S84>'  : 'fourwheelscontroller/g2 (fast)/Anti-windup/Back Calculation'
//  '<S85>'  : 'fourwheelscontroller/g2 (fast)/D Gain/Internal Parameters'
//  '<S86>'  : 'fourwheelscontroller/g2 (fast)/Filter/Cont. Filter'
//  '<S87>'  : 'fourwheelscontroller/g2 (fast)/Filter ICs/Internal IC - Filter'
//  '<S88>'  : 'fourwheelscontroller/g2 (fast)/I Gain/Internal Parameters'
//  '<S89>'  : 'fourwheelscontroller/g2 (fast)/Ideal P Gain/Passthrough'
//  '<S90>'  : 'fourwheelscontroller/g2 (fast)/Ideal P Gain Fdbk/Disabled'
//  '<S91>'  : 'fourwheelscontroller/g2 (fast)/Integrator/Continuous'
//  '<S92>'  : 'fourwheelscontroller/g2 (fast)/Integrator ICs/Internal IC'
//  '<S93>'  : 'fourwheelscontroller/g2 (fast)/N Copy/Disabled'
//  '<S94>'  : 'fourwheelscontroller/g2 (fast)/N Gain/Internal Parameters'
//  '<S95>'  : 'fourwheelscontroller/g2 (fast)/P Copy/Disabled'
//  '<S96>'  : 'fourwheelscontroller/g2 (fast)/Parallel P Gain/Internal Parameters'
//  '<S97>'  : 'fourwheelscontroller/g2 (fast)/Reset Signal/Disabled'
//  '<S98>'  : 'fourwheelscontroller/g2 (fast)/Saturation/Enabled'
//  '<S99>'  : 'fourwheelscontroller/g2 (fast)/Saturation Fdbk/Disabled'
//  '<S100>' : 'fourwheelscontroller/g2 (fast)/Sum/Sum_PID'
//  '<S101>' : 'fourwheelscontroller/g2 (fast)/Sum Fdbk/Disabled'
//  '<S102>' : 'fourwheelscontroller/g2 (fast)/Tracking Mode/Disabled'
//  '<S103>' : 'fourwheelscontroller/g2 (fast)/Tracking Mode Sum/Passthrough'
//  '<S104>' : 'fourwheelscontroller/g2 (fast)/Tsamp - Integral/TsSignalSpecification'
//  '<S105>' : 'fourwheelscontroller/g2 (fast)/Tsamp - Ngain/Passthrough'
//  '<S106>' : 'fourwheelscontroller/g2 (fast)/postSat Signal/Forward_Path'
//  '<S107>' : 'fourwheelscontroller/g2 (fast)/preSat Signal/Forward_Path'

#endif                                 // RTW_HEADER_fourwheelscontroller_h_

//
// File trailer for generated code.
//
// [EOF]
//

//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: assignment4controller.h
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
#ifndef RTW_HEADER_assignment4controller_h_
#define RTW_HEADER_assignment4controller_h_
#include "rtwtypes.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#include "slros_initialize.h"
#include "assignment4controller_types.h"
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
struct B_assignment4controller_T {
  real_T ProportionalGain;             // '<S50>/Proportional Gain'
  real_T DerivativeGain;               // '<S39>/Derivative Gain'
  real_T FilterCoefficient;            // '<S48>/Filter Coefficient'
  real_T ProportionalGain_f;           // '<S98>/Proportional Gain'
  real_T DerivativeGain_c;             // '<S87>/Derivative Gain'
  real_T FilterCoefficient_o;          // '<S96>/Filter Coefficient'
  real_T IntegralGain;                 // '<S90>/Integral Gain'
  real_T SumI4;                        // '<S86>/SumI4'
  real_T IntegralGain_i;               // '<S42>/Integral Gain'
  real_T SumI4_d;                      // '<S38>/SumI4'
  real_T y;                            // '<Root>/MATLAB Function2'
  SL_Bus_assignment4controller_std_msgs_Float64 In1;// '<S13>/In1'
  SL_Bus_assignment4controller_std_msgs_Float64 In1_b;// '<S11>/In1'
  SL_Bus_assignment4controller_std_msgs_Float64 b_varargout_2;
};

// Block states (default storage) for system '<Root>'
struct DW_assignment4controller_T {
  ros_slroscpp_internal_block_P_T obj; // '<S5>/SinkBlock'
  ros_slroscpp_internal_block_S_T obj_c;// '<S8>/SourceBlock'
  ros_slroscpp_internal_block_S_T obj_i;// '<S7>/SourceBlock'
  ros_slroscpp_internal_block_S_T obj_f;// '<S6>/SourceBlock'
};

// Continuous states (default storage)
struct X_assignment4controller_T {
  real_T Integrator_CSTATE;            // '<S45>/Integrator'
  real_T Filter_CSTATE;                // '<S40>/Filter'
  real_T Integrator_CSTATE_k;          // '<S93>/Integrator'
  real_T Filter_CSTATE_n;              // '<S88>/Filter'
};

// State derivatives (default storage)
struct XDot_assignment4controller_T {
  real_T Integrator_CSTATE;            // '<S45>/Integrator'
  real_T Filter_CSTATE;                // '<S40>/Filter'
  real_T Integrator_CSTATE_k;          // '<S93>/Integrator'
  real_T Filter_CSTATE_n;              // '<S88>/Filter'
};

// State disabled
struct XDis_assignment4controller_T {
  boolean_T Integrator_CSTATE;         // '<S45>/Integrator'
  boolean_T Filter_CSTATE;             // '<S40>/Filter'
  boolean_T Integrator_CSTATE_k;       // '<S93>/Integrator'
  boolean_T Filter_CSTATE_n;           // '<S88>/Filter'
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
struct P_assignment4controller_T_ {
  real_T g1slow_D;                     // Mask Parameter: g1slow_D
                                          //  Referenced by: '<S39>/Derivative Gain'

  real_T g2fast_D;                     // Mask Parameter: g2fast_D
                                          //  Referenced by: '<S87>/Derivative Gain'

  real_T g2fast_I;                     // Mask Parameter: g2fast_I
                                          //  Referenced by: '<S90>/Integral Gain'

  real_T g1slow_I;                     // Mask Parameter: g1slow_I
                                          //  Referenced by: '<S42>/Integral Gain'

  real_T g1slow_InitialConditionForFilte;
                              // Mask Parameter: g1slow_InitialConditionForFilte
                                 //  Referenced by: '<S40>/Filter'

  real_T g2fast_InitialConditionForFilte;
                              // Mask Parameter: g2fast_InitialConditionForFilte
                                 //  Referenced by: '<S88>/Filter'

  real_T g1slow_InitialConditionForInteg;
                              // Mask Parameter: g1slow_InitialConditionForInteg
                                 //  Referenced by: '<S45>/Integrator'

  real_T g2fast_InitialConditionForInteg;
                              // Mask Parameter: g2fast_InitialConditionForInteg
                                 //  Referenced by: '<S93>/Integrator'

  real_T g2fast_Kb;                    // Mask Parameter: g2fast_Kb
                                          //  Referenced by: '<S86>/Kb'

  real_T g1slow_Kb;                    // Mask Parameter: g1slow_Kb
                                          //  Referenced by: '<S38>/Kb'

  real_T g1slow_LowerSaturationLimit;
                                  // Mask Parameter: g1slow_LowerSaturationLimit
                                     //  Referenced by: '<S52>/Saturation'

  real_T g2fast_LowerSaturationLimit;
                                  // Mask Parameter: g2fast_LowerSaturationLimit
                                     //  Referenced by: '<S100>/Saturation'

  real_T g1slow_N;                     // Mask Parameter: g1slow_N
                                          //  Referenced by: '<S48>/Filter Coefficient'

  real_T g2fast_N;                     // Mask Parameter: g2fast_N
                                          //  Referenced by: '<S96>/Filter Coefficient'

  real_T g1slow_P;                     // Mask Parameter: g1slow_P
                                          //  Referenced by: '<S50>/Proportional Gain'

  real_T g2fast_P;                     // Mask Parameter: g2fast_P
                                          //  Referenced by: '<S98>/Proportional Gain'

  real_T g1slow_UpperSaturationLimit;
                                  // Mask Parameter: g1slow_UpperSaturationLimit
                                     //  Referenced by: '<S52>/Saturation'

  real_T g2fast_UpperSaturationLimit;
                                  // Mask Parameter: g2fast_UpperSaturationLimit
                                     //  Referenced by: '<S100>/Saturation'

  SL_Bus_assignment4controller_std_msgs_Float64 Constant_Value;// Computed Parameter: Constant_Value
                                                                  //  Referenced by: '<S1>/Constant'

  SL_Bus_assignment4controller_std_msgs_Float64 Out1_Y0;// Computed Parameter: Out1_Y0
                                                           //  Referenced by: '<S11>/Out1'

  SL_Bus_assignment4controller_std_msgs_Float64 Constant_Value_k;// Computed Parameter: Constant_Value_k
                                                                    //  Referenced by: '<S6>/Constant'

  SL_Bus_assignment4controller_std_msgs_Float64 Out1_Y0_l;// Computed Parameter: Out1_Y0_l
                                                             //  Referenced by: '<S12>/Out1'

  SL_Bus_assignment4controller_std_msgs_Float64 Constant_Value_f;// Computed Parameter: Constant_Value_f
                                                                    //  Referenced by: '<S7>/Constant'

  SL_Bus_assignment4controller_std_msgs_Float64 Out1_Y0_e;// Computed Parameter: Out1_Y0_e
                                                             //  Referenced by: '<S13>/Out1'

  SL_Bus_assignment4controller_std_msgs_Float64 Constant_Value_p;// Computed Parameter: Constant_Value_p
                                                                    //  Referenced by: '<S8>/Constant'

  real_T Constant_Value_ko;            // Expression: 4
                                          //  Referenced by: '<Root>/Constant'

  real_T Gain_Gain;                    // Expression: 0.7
                                          //  Referenced by: '<Root>/Gain'

};

// Real-time Model Data Structure
struct tag_RTM_assignment4controller_T {
  const char_T *errorStatus;
  RTWSolverInfo solverInfo;
  X_assignment4controller_T *contStates;
  int_T *periodicContStateIndices;
  real_T *periodicContStateRanges;
  real_T *derivs;
  XDis_assignment4controller_T *contStateDisabled;
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

  extern P_assignment4controller_T assignment4controller_P;

#ifdef __cplusplus

}

#endif

// Block signals (default storage)
#ifdef __cplusplus

extern "C"
{

#endif

  extern struct B_assignment4controller_T assignment4controller_B;

#ifdef __cplusplus

}

#endif

// Continuous states (default storage)
extern X_assignment4controller_T assignment4controller_X;

// Disabled states (default storage)
extern XDis_assignment4controller_T assignment4controller_XDis;

// Block states (default storage)
extern struct DW_assignment4controller_T assignment4controller_DW;

#ifdef __cplusplus

extern "C"
{

#endif

  // Model entry point functions
  extern void assignment4controller_initialize(void);
  extern void assignment4controller_step(void);
  extern void assignment4controller_terminate(void);

#ifdef __cplusplus

}

#endif

// Real-time Model object
#ifdef __cplusplus

extern "C"
{

#endif

  extern RT_MODEL_assignment4controlle_T *const assignment4controller_M;

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
//  '<Root>' : 'assignment4controller'
//  '<S1>'   : 'assignment4controller/Blank Message'
//  '<S2>'   : 'assignment4controller/MATLAB Function'
//  '<S3>'   : 'assignment4controller/MATLAB Function1'
//  '<S4>'   : 'assignment4controller/MATLAB Function2'
//  '<S5>'   : 'assignment4controller/Publish'
//  '<S6>'   : 'assignment4controller/Subscribe'
//  '<S7>'   : 'assignment4controller/Subscribe1'
//  '<S8>'   : 'assignment4controller/Subscribe2'
//  '<S9>'   : 'assignment4controller/g1 (slow)'
//  '<S10>'  : 'assignment4controller/g2 (fast)'
//  '<S11>'  : 'assignment4controller/Subscribe/Enabled Subsystem'
//  '<S12>'  : 'assignment4controller/Subscribe1/Enabled Subsystem'
//  '<S13>'  : 'assignment4controller/Subscribe2/Enabled Subsystem'
//  '<S14>'  : 'assignment4controller/g1 (slow)/Anti-windup'
//  '<S15>'  : 'assignment4controller/g1 (slow)/D Gain'
//  '<S16>'  : 'assignment4controller/g1 (slow)/Filter'
//  '<S17>'  : 'assignment4controller/g1 (slow)/Filter ICs'
//  '<S18>'  : 'assignment4controller/g1 (slow)/I Gain'
//  '<S19>'  : 'assignment4controller/g1 (slow)/Ideal P Gain'
//  '<S20>'  : 'assignment4controller/g1 (slow)/Ideal P Gain Fdbk'
//  '<S21>'  : 'assignment4controller/g1 (slow)/Integrator'
//  '<S22>'  : 'assignment4controller/g1 (slow)/Integrator ICs'
//  '<S23>'  : 'assignment4controller/g1 (slow)/N Copy'
//  '<S24>'  : 'assignment4controller/g1 (slow)/N Gain'
//  '<S25>'  : 'assignment4controller/g1 (slow)/P Copy'
//  '<S26>'  : 'assignment4controller/g1 (slow)/Parallel P Gain'
//  '<S27>'  : 'assignment4controller/g1 (slow)/Reset Signal'
//  '<S28>'  : 'assignment4controller/g1 (slow)/Saturation'
//  '<S29>'  : 'assignment4controller/g1 (slow)/Saturation Fdbk'
//  '<S30>'  : 'assignment4controller/g1 (slow)/Sum'
//  '<S31>'  : 'assignment4controller/g1 (slow)/Sum Fdbk'
//  '<S32>'  : 'assignment4controller/g1 (slow)/Tracking Mode'
//  '<S33>'  : 'assignment4controller/g1 (slow)/Tracking Mode Sum'
//  '<S34>'  : 'assignment4controller/g1 (slow)/Tsamp - Integral'
//  '<S35>'  : 'assignment4controller/g1 (slow)/Tsamp - Ngain'
//  '<S36>'  : 'assignment4controller/g1 (slow)/postSat Signal'
//  '<S37>'  : 'assignment4controller/g1 (slow)/preSat Signal'
//  '<S38>'  : 'assignment4controller/g1 (slow)/Anti-windup/Back Calculation'
//  '<S39>'  : 'assignment4controller/g1 (slow)/D Gain/Internal Parameters'
//  '<S40>'  : 'assignment4controller/g1 (slow)/Filter/Cont. Filter'
//  '<S41>'  : 'assignment4controller/g1 (slow)/Filter ICs/Internal IC - Filter'
//  '<S42>'  : 'assignment4controller/g1 (slow)/I Gain/Internal Parameters'
//  '<S43>'  : 'assignment4controller/g1 (slow)/Ideal P Gain/Passthrough'
//  '<S44>'  : 'assignment4controller/g1 (slow)/Ideal P Gain Fdbk/Disabled'
//  '<S45>'  : 'assignment4controller/g1 (slow)/Integrator/Continuous'
//  '<S46>'  : 'assignment4controller/g1 (slow)/Integrator ICs/Internal IC'
//  '<S47>'  : 'assignment4controller/g1 (slow)/N Copy/Disabled'
//  '<S48>'  : 'assignment4controller/g1 (slow)/N Gain/Internal Parameters'
//  '<S49>'  : 'assignment4controller/g1 (slow)/P Copy/Disabled'
//  '<S50>'  : 'assignment4controller/g1 (slow)/Parallel P Gain/Internal Parameters'
//  '<S51>'  : 'assignment4controller/g1 (slow)/Reset Signal/Disabled'
//  '<S52>'  : 'assignment4controller/g1 (slow)/Saturation/Enabled'
//  '<S53>'  : 'assignment4controller/g1 (slow)/Saturation Fdbk/Disabled'
//  '<S54>'  : 'assignment4controller/g1 (slow)/Sum/Sum_PID'
//  '<S55>'  : 'assignment4controller/g1 (slow)/Sum Fdbk/Disabled'
//  '<S56>'  : 'assignment4controller/g1 (slow)/Tracking Mode/Disabled'
//  '<S57>'  : 'assignment4controller/g1 (slow)/Tracking Mode Sum/Passthrough'
//  '<S58>'  : 'assignment4controller/g1 (slow)/Tsamp - Integral/TsSignalSpecification'
//  '<S59>'  : 'assignment4controller/g1 (slow)/Tsamp - Ngain/Passthrough'
//  '<S60>'  : 'assignment4controller/g1 (slow)/postSat Signal/Forward_Path'
//  '<S61>'  : 'assignment4controller/g1 (slow)/preSat Signal/Forward_Path'
//  '<S62>'  : 'assignment4controller/g2 (fast)/Anti-windup'
//  '<S63>'  : 'assignment4controller/g2 (fast)/D Gain'
//  '<S64>'  : 'assignment4controller/g2 (fast)/Filter'
//  '<S65>'  : 'assignment4controller/g2 (fast)/Filter ICs'
//  '<S66>'  : 'assignment4controller/g2 (fast)/I Gain'
//  '<S67>'  : 'assignment4controller/g2 (fast)/Ideal P Gain'
//  '<S68>'  : 'assignment4controller/g2 (fast)/Ideal P Gain Fdbk'
//  '<S69>'  : 'assignment4controller/g2 (fast)/Integrator'
//  '<S70>'  : 'assignment4controller/g2 (fast)/Integrator ICs'
//  '<S71>'  : 'assignment4controller/g2 (fast)/N Copy'
//  '<S72>'  : 'assignment4controller/g2 (fast)/N Gain'
//  '<S73>'  : 'assignment4controller/g2 (fast)/P Copy'
//  '<S74>'  : 'assignment4controller/g2 (fast)/Parallel P Gain'
//  '<S75>'  : 'assignment4controller/g2 (fast)/Reset Signal'
//  '<S76>'  : 'assignment4controller/g2 (fast)/Saturation'
//  '<S77>'  : 'assignment4controller/g2 (fast)/Saturation Fdbk'
//  '<S78>'  : 'assignment4controller/g2 (fast)/Sum'
//  '<S79>'  : 'assignment4controller/g2 (fast)/Sum Fdbk'
//  '<S80>'  : 'assignment4controller/g2 (fast)/Tracking Mode'
//  '<S81>'  : 'assignment4controller/g2 (fast)/Tracking Mode Sum'
//  '<S82>'  : 'assignment4controller/g2 (fast)/Tsamp - Integral'
//  '<S83>'  : 'assignment4controller/g2 (fast)/Tsamp - Ngain'
//  '<S84>'  : 'assignment4controller/g2 (fast)/postSat Signal'
//  '<S85>'  : 'assignment4controller/g2 (fast)/preSat Signal'
//  '<S86>'  : 'assignment4controller/g2 (fast)/Anti-windup/Back Calculation'
//  '<S87>'  : 'assignment4controller/g2 (fast)/D Gain/Internal Parameters'
//  '<S88>'  : 'assignment4controller/g2 (fast)/Filter/Cont. Filter'
//  '<S89>'  : 'assignment4controller/g2 (fast)/Filter ICs/Internal IC - Filter'
//  '<S90>'  : 'assignment4controller/g2 (fast)/I Gain/Internal Parameters'
//  '<S91>'  : 'assignment4controller/g2 (fast)/Ideal P Gain/Passthrough'
//  '<S92>'  : 'assignment4controller/g2 (fast)/Ideal P Gain Fdbk/Disabled'
//  '<S93>'  : 'assignment4controller/g2 (fast)/Integrator/Continuous'
//  '<S94>'  : 'assignment4controller/g2 (fast)/Integrator ICs/Internal IC'
//  '<S95>'  : 'assignment4controller/g2 (fast)/N Copy/Disabled'
//  '<S96>'  : 'assignment4controller/g2 (fast)/N Gain/Internal Parameters'
//  '<S97>'  : 'assignment4controller/g2 (fast)/P Copy/Disabled'
//  '<S98>'  : 'assignment4controller/g2 (fast)/Parallel P Gain/Internal Parameters'
//  '<S99>'  : 'assignment4controller/g2 (fast)/Reset Signal/Disabled'
//  '<S100>' : 'assignment4controller/g2 (fast)/Saturation/Enabled'
//  '<S101>' : 'assignment4controller/g2 (fast)/Saturation Fdbk/Disabled'
//  '<S102>' : 'assignment4controller/g2 (fast)/Sum/Sum_PID'
//  '<S103>' : 'assignment4controller/g2 (fast)/Sum Fdbk/Disabled'
//  '<S104>' : 'assignment4controller/g2 (fast)/Tracking Mode/Disabled'
//  '<S105>' : 'assignment4controller/g2 (fast)/Tracking Mode Sum/Passthrough'
//  '<S106>' : 'assignment4controller/g2 (fast)/Tsamp - Integral/TsSignalSpecification'
//  '<S107>' : 'assignment4controller/g2 (fast)/Tsamp - Ngain/Passthrough'
//  '<S108>' : 'assignment4controller/g2 (fast)/postSat Signal/Forward_Path'
//  '<S109>' : 'assignment4controller/g2 (fast)/preSat Signal/Forward_Path'

#endif                                 // RTW_HEADER_assignment4controller_h_

//
// File trailer for generated code.
//
// [EOF]
//

//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: assignment4controller.h
//
// Code generated for Simulink model 'assignment4controller'.
//
// Model version                  : 1.2
// Simulink Coder version         : 23.2 (R2023b) 01-Aug-2023
// C/C++ source code generated on : Wed Nov 15 14:19:27 2023
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

// Block states (default storage) for system '<Root>/Dead Man's Switch'
struct DW_DeadMansSwitch_assignment4_T {
  real_T sinceLastMsg;                 // '<S2>/timeout set to 0 output'
  boolean_T sinceLastMsg_not_empty;    // '<S2>/timeout set to 0 output'
};

// Block signals (default storage)
struct B_assignment4controller_T {
  real_T FilterCoefficient;            // '<S55>/Filter Coefficient'
  real_T FilterCoefficient_i;          // '<S103>/Filter Coefficient'
  real_T FilterCoefficient_g;          // '<S151>/Filter Coefficient'
  real_T SumI4;                        // '<S141>/SumI4'
  real_T SumI4_n;                      // '<S93>/SumI4'
  real_T SumI4_p;                      // '<S45>/SumI4'
  real_T y;                            // '<Root>/MATLAB Function2'
  real_T y_c;                          // '<Root>/MATLAB Function'
  real_T Sum_n;                        // '<S109>/Sum'
  real_T Sum_c;                        // '<S157>/Sum'
  SL_Bus_assignment4controller_std_msgs_Float64 In1;// '<S20>/In1'
  SL_Bus_assignment4controller_std_msgs_Float64 In1_i;// '<S19>/In1'
  SL_Bus_assignment4controller_std_msgs_Float64 In1_b;// '<S18>/In1'
  SL_Bus_assignment4controller_std_msgs_Float64 b_varargout_2;
};

// Block states (default storage) for system '<Root>'
struct DW_assignment4controller_T {
  ros_slroscpp_internal_block_P_T obj; // '<S8>/SinkBlock'
  ros_slroscpp_internal_block_S_T obj_f;// '<S11>/SourceBlock'
  ros_slroscpp_internal_block_S_T obj_l;// '<S10>/SourceBlock'
  ros_slroscpp_internal_block_S_T obj_m;// '<S9>/SourceBlock'
  DW_DeadMansSwitch_assignment4_T DeadMansSwitch2;// '<Root>/Dead Man's Switch2' 
  DW_DeadMansSwitch_assignment4_T DeadMansSwitch1;// '<Root>/Dead Man's Switch1' 
  DW_DeadMansSwitch_assignment4_T DeadMansSwitch;// '<Root>/Dead Man's Switch'
};

// Continuous states (default storage)
struct X_assignment4controller_T {
  real_T TransferFcn_CSTATE;           // '<Root>/Transfer Fcn'
  real_T Integrator_CSTATE;            // '<S52>/Integrator'
  real_T Filter_CSTATE;                // '<S47>/Filter'
  real_T Integrator_CSTATE_p;          // '<S100>/Integrator'
  real_T Filter_CSTATE_h;              // '<S95>/Filter'
  real_T Integrator_CSTATE_g;          // '<S148>/Integrator'
  real_T Filter_CSTATE_d;              // '<S143>/Filter'
};

// State derivatives (default storage)
struct XDot_assignment4controller_T {
  real_T TransferFcn_CSTATE;           // '<Root>/Transfer Fcn'
  real_T Integrator_CSTATE;            // '<S52>/Integrator'
  real_T Filter_CSTATE;                // '<S47>/Filter'
  real_T Integrator_CSTATE_p;          // '<S100>/Integrator'
  real_T Filter_CSTATE_h;              // '<S95>/Filter'
  real_T Integrator_CSTATE_g;          // '<S148>/Integrator'
  real_T Filter_CSTATE_d;              // '<S143>/Filter'
};

// State disabled
struct XDis_assignment4controller_T {
  boolean_T TransferFcn_CSTATE;        // '<Root>/Transfer Fcn'
  boolean_T Integrator_CSTATE;         // '<S52>/Integrator'
  boolean_T Filter_CSTATE;             // '<S47>/Filter'
  boolean_T Integrator_CSTATE_p;       // '<S100>/Integrator'
  boolean_T Filter_CSTATE_h;           // '<S95>/Filter'
  boolean_T Integrator_CSTATE_g;       // '<S148>/Integrator'
  boolean_T Filter_CSTATE_d;           // '<S143>/Filter'
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
                                          //  Referenced by: '<S46>/Derivative Gain'

  real_T g2fast_D;                     // Mask Parameter: g2fast_D
                                          //  Referenced by: '<S94>/Derivative Gain'

  real_T g3emergency_D;                // Mask Parameter: g3emergency_D
                                          //  Referenced by: '<S142>/Derivative Gain'

  real_T g3emergency_I;                // Mask Parameter: g3emergency_I
                                          //  Referenced by: '<S145>/Integral Gain'

  real_T g2fast_I;                     // Mask Parameter: g2fast_I
                                          //  Referenced by: '<S97>/Integral Gain'

  real_T g1slow_I;                     // Mask Parameter: g1slow_I
                                          //  Referenced by: '<S49>/Integral Gain'

  real_T g1slow_InitialConditionForFilte;
                              // Mask Parameter: g1slow_InitialConditionForFilte
                                 //  Referenced by: '<S47>/Filter'

  real_T g2fast_InitialConditionForFilte;
                              // Mask Parameter: g2fast_InitialConditionForFilte
                                 //  Referenced by: '<S95>/Filter'

  real_T g3emergency_InitialConditionFor;
                              // Mask Parameter: g3emergency_InitialConditionFor
                                 //  Referenced by: '<S143>/Filter'

  real_T g1slow_InitialConditionForInteg;
                              // Mask Parameter: g1slow_InitialConditionForInteg
                                 //  Referenced by: '<S52>/Integrator'

  real_T g2fast_InitialConditionForInteg;
                              // Mask Parameter: g2fast_InitialConditionForInteg
                                 //  Referenced by: '<S100>/Integrator'

  real_T g3emergency_InitialConditionF_l;
                              // Mask Parameter: g3emergency_InitialConditionF_l
                                 //  Referenced by: '<S148>/Integrator'

  real_T g3emergency_Kb;               // Mask Parameter: g3emergency_Kb
                                          //  Referenced by: '<S141>/Kb'

  real_T g2fast_Kb;                    // Mask Parameter: g2fast_Kb
                                          //  Referenced by: '<S93>/Kb'

  real_T g1slow_Kb;                    // Mask Parameter: g1slow_Kb
                                          //  Referenced by: '<S45>/Kb'

  real_T g1slow_LowerSaturationLimit;
                                  // Mask Parameter: g1slow_LowerSaturationLimit
                                     //  Referenced by: '<S59>/Saturation'

  real_T g2fast_LowerSaturationLimit;
                                  // Mask Parameter: g2fast_LowerSaturationLimit
                                     //  Referenced by: '<S107>/Saturation'

  real_T g3emergency_LowerSaturationLimi;
                              // Mask Parameter: g3emergency_LowerSaturationLimi
                                 //  Referenced by: '<S155>/Saturation'

  real_T g1slow_N;                     // Mask Parameter: g1slow_N
                                          //  Referenced by: '<S55>/Filter Coefficient'

  real_T g2fast_N;                     // Mask Parameter: g2fast_N
                                          //  Referenced by: '<S103>/Filter Coefficient'

  real_T g3emergency_N;                // Mask Parameter: g3emergency_N
                                          //  Referenced by: '<S151>/Filter Coefficient'

  real_T g1slow_P;                     // Mask Parameter: g1slow_P
                                          //  Referenced by: '<S57>/Proportional Gain'

  real_T g2fast_P;                     // Mask Parameter: g2fast_P
                                          //  Referenced by: '<S105>/Proportional Gain'

  real_T g3emergency_P;                // Mask Parameter: g3emergency_P
                                          //  Referenced by: '<S153>/Proportional Gain'

  real_T g1slow_UpperSaturationLimit;
                                  // Mask Parameter: g1slow_UpperSaturationLimit
                                     //  Referenced by: '<S59>/Saturation'

  real_T g2fast_UpperSaturationLimit;
                                  // Mask Parameter: g2fast_UpperSaturationLimit
                                     //  Referenced by: '<S107>/Saturation'

  real_T g3emergency_UpperSaturationLimi;
                              // Mask Parameter: g3emergency_UpperSaturationLimi
                                 //  Referenced by: '<S155>/Saturation'

  real_T DeadMansSwitch1_stepSize;   // Mask Parameter: DeadMansSwitch1_stepSize
                                        //  Referenced by: '<Root>/Dead Man's Switch1'

  real_T DeadMansSwitch_stepSize;     // Mask Parameter: DeadMansSwitch_stepSize
                                         //  Referenced by: '<Root>/Dead Man's Switch'

  real_T DeadMansSwitch2_stepSize;   // Mask Parameter: DeadMansSwitch2_stepSize
                                        //  Referenced by: '<Root>/Dead Man's Switch2'

  real_T DeadMansSwitch1_timeout;     // Mask Parameter: DeadMansSwitch1_timeout
                                         //  Referenced by: '<Root>/Dead Man's Switch1'

  real_T DeadMansSwitch_timeout;       // Mask Parameter: DeadMansSwitch_timeout
                                          //  Referenced by: '<Root>/Dead Man's Switch'

  real_T DeadMansSwitch2_timeout;     // Mask Parameter: DeadMansSwitch2_timeout
                                         //  Referenced by: '<Root>/Dead Man's Switch2'

  SL_Bus_assignment4controller_std_msgs_Float64 Constant_Value;// Computed Parameter: Constant_Value
                                                                  //  Referenced by: '<S1>/Constant'

  SL_Bus_assignment4controller_std_msgs_Float64 Out1_Y0;// Computed Parameter: Out1_Y0
                                                           //  Referenced by: '<S18>/Out1'

  SL_Bus_assignment4controller_std_msgs_Float64 Constant_Value_o;// Computed Parameter: Constant_Value_o
                                                                    //  Referenced by: '<S9>/Constant'

  SL_Bus_assignment4controller_std_msgs_Float64 Out1_Y0_j;// Computed Parameter: Out1_Y0_j
                                                             //  Referenced by: '<S19>/Out1'

  SL_Bus_assignment4controller_std_msgs_Float64 Constant_Value_p;// Computed Parameter: Constant_Value_p
                                                                    //  Referenced by: '<S10>/Constant'

  SL_Bus_assignment4controller_std_msgs_Float64 Out1_Y0_c;// Computed Parameter: Out1_Y0_c
                                                             //  Referenced by: '<S20>/Out1'

  SL_Bus_assignment4controller_std_msgs_Float64 Constant_Value_g;// Computed Parameter: Constant_Value_g
                                                                    //  Referenced by: '<S11>/Constant'

  real_T TransferFcn_A;                // Computed Parameter: TransferFcn_A
                                          //  Referenced by: '<Root>/Transfer Fcn'

  real_T TransferFcn_C;                // Computed Parameter: TransferFcn_C
                                          //  Referenced by: '<Root>/Transfer Fcn'

  real_T Gain_Gain;                    // Expression: 0.7
                                          //  Referenced by: '<Root>/Gain'

  real_T Constant_Value_d;             // Expression: 10
                                          //  Referenced by: '<Root>/Constant'

  boolean_T Constant2_Value;           // Expression: true
                                          //  Referenced by: '<Root>/Constant2'

  boolean_T Constant1_Value;           // Expression: true
                                          //  Referenced by: '<Root>/Constant1'

  boolean_T Constant3_Value;           // Expression: true
                                          //  Referenced by: '<Root>/Constant3'

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
  real_T odeY[7];
  real_T odeF[3][7];
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
//  '<S2>'   : 'assignment4controller/Dead Man's Switch'
//  '<S3>'   : 'assignment4controller/Dead Man's Switch1'
//  '<S4>'   : 'assignment4controller/Dead Man's Switch2'
//  '<S5>'   : 'assignment4controller/MATLAB Function'
//  '<S6>'   : 'assignment4controller/MATLAB Function1'
//  '<S7>'   : 'assignment4controller/MATLAB Function2'
//  '<S8>'   : 'assignment4controller/Publish'
//  '<S9>'   : 'assignment4controller/Subscribe'
//  '<S10>'  : 'assignment4controller/Subscribe1'
//  '<S11>'  : 'assignment4controller/Subscribe2'
//  '<S12>'  : 'assignment4controller/g1 (slow)'
//  '<S13>'  : 'assignment4controller/g2 (fast)'
//  '<S14>'  : 'assignment4controller/g3 (emergency)'
//  '<S15>'  : 'assignment4controller/Dead Man's Switch/timeout set to 0 output'
//  '<S16>'  : 'assignment4controller/Dead Man's Switch1/timeout set to 0 output'
//  '<S17>'  : 'assignment4controller/Dead Man's Switch2/timeout set to 0 output'
//  '<S18>'  : 'assignment4controller/Subscribe/Enabled Subsystem'
//  '<S19>'  : 'assignment4controller/Subscribe1/Enabled Subsystem'
//  '<S20>'  : 'assignment4controller/Subscribe2/Enabled Subsystem'
//  '<S21>'  : 'assignment4controller/g1 (slow)/Anti-windup'
//  '<S22>'  : 'assignment4controller/g1 (slow)/D Gain'
//  '<S23>'  : 'assignment4controller/g1 (slow)/Filter'
//  '<S24>'  : 'assignment4controller/g1 (slow)/Filter ICs'
//  '<S25>'  : 'assignment4controller/g1 (slow)/I Gain'
//  '<S26>'  : 'assignment4controller/g1 (slow)/Ideal P Gain'
//  '<S27>'  : 'assignment4controller/g1 (slow)/Ideal P Gain Fdbk'
//  '<S28>'  : 'assignment4controller/g1 (slow)/Integrator'
//  '<S29>'  : 'assignment4controller/g1 (slow)/Integrator ICs'
//  '<S30>'  : 'assignment4controller/g1 (slow)/N Copy'
//  '<S31>'  : 'assignment4controller/g1 (slow)/N Gain'
//  '<S32>'  : 'assignment4controller/g1 (slow)/P Copy'
//  '<S33>'  : 'assignment4controller/g1 (slow)/Parallel P Gain'
//  '<S34>'  : 'assignment4controller/g1 (slow)/Reset Signal'
//  '<S35>'  : 'assignment4controller/g1 (slow)/Saturation'
//  '<S36>'  : 'assignment4controller/g1 (slow)/Saturation Fdbk'
//  '<S37>'  : 'assignment4controller/g1 (slow)/Sum'
//  '<S38>'  : 'assignment4controller/g1 (slow)/Sum Fdbk'
//  '<S39>'  : 'assignment4controller/g1 (slow)/Tracking Mode'
//  '<S40>'  : 'assignment4controller/g1 (slow)/Tracking Mode Sum'
//  '<S41>'  : 'assignment4controller/g1 (slow)/Tsamp - Integral'
//  '<S42>'  : 'assignment4controller/g1 (slow)/Tsamp - Ngain'
//  '<S43>'  : 'assignment4controller/g1 (slow)/postSat Signal'
//  '<S44>'  : 'assignment4controller/g1 (slow)/preSat Signal'
//  '<S45>'  : 'assignment4controller/g1 (slow)/Anti-windup/Back Calculation'
//  '<S46>'  : 'assignment4controller/g1 (slow)/D Gain/Internal Parameters'
//  '<S47>'  : 'assignment4controller/g1 (slow)/Filter/Cont. Filter'
//  '<S48>'  : 'assignment4controller/g1 (slow)/Filter ICs/Internal IC - Filter'
//  '<S49>'  : 'assignment4controller/g1 (slow)/I Gain/Internal Parameters'
//  '<S50>'  : 'assignment4controller/g1 (slow)/Ideal P Gain/Passthrough'
//  '<S51>'  : 'assignment4controller/g1 (slow)/Ideal P Gain Fdbk/Disabled'
//  '<S52>'  : 'assignment4controller/g1 (slow)/Integrator/Continuous'
//  '<S53>'  : 'assignment4controller/g1 (slow)/Integrator ICs/Internal IC'
//  '<S54>'  : 'assignment4controller/g1 (slow)/N Copy/Disabled'
//  '<S55>'  : 'assignment4controller/g1 (slow)/N Gain/Internal Parameters'
//  '<S56>'  : 'assignment4controller/g1 (slow)/P Copy/Disabled'
//  '<S57>'  : 'assignment4controller/g1 (slow)/Parallel P Gain/Internal Parameters'
//  '<S58>'  : 'assignment4controller/g1 (slow)/Reset Signal/Disabled'
//  '<S59>'  : 'assignment4controller/g1 (slow)/Saturation/Enabled'
//  '<S60>'  : 'assignment4controller/g1 (slow)/Saturation Fdbk/Disabled'
//  '<S61>'  : 'assignment4controller/g1 (slow)/Sum/Sum_PID'
//  '<S62>'  : 'assignment4controller/g1 (slow)/Sum Fdbk/Disabled'
//  '<S63>'  : 'assignment4controller/g1 (slow)/Tracking Mode/Disabled'
//  '<S64>'  : 'assignment4controller/g1 (slow)/Tracking Mode Sum/Passthrough'
//  '<S65>'  : 'assignment4controller/g1 (slow)/Tsamp - Integral/TsSignalSpecification'
//  '<S66>'  : 'assignment4controller/g1 (slow)/Tsamp - Ngain/Passthrough'
//  '<S67>'  : 'assignment4controller/g1 (slow)/postSat Signal/Forward_Path'
//  '<S68>'  : 'assignment4controller/g1 (slow)/preSat Signal/Forward_Path'
//  '<S69>'  : 'assignment4controller/g2 (fast)/Anti-windup'
//  '<S70>'  : 'assignment4controller/g2 (fast)/D Gain'
//  '<S71>'  : 'assignment4controller/g2 (fast)/Filter'
//  '<S72>'  : 'assignment4controller/g2 (fast)/Filter ICs'
//  '<S73>'  : 'assignment4controller/g2 (fast)/I Gain'
//  '<S74>'  : 'assignment4controller/g2 (fast)/Ideal P Gain'
//  '<S75>'  : 'assignment4controller/g2 (fast)/Ideal P Gain Fdbk'
//  '<S76>'  : 'assignment4controller/g2 (fast)/Integrator'
//  '<S77>'  : 'assignment4controller/g2 (fast)/Integrator ICs'
//  '<S78>'  : 'assignment4controller/g2 (fast)/N Copy'
//  '<S79>'  : 'assignment4controller/g2 (fast)/N Gain'
//  '<S80>'  : 'assignment4controller/g2 (fast)/P Copy'
//  '<S81>'  : 'assignment4controller/g2 (fast)/Parallel P Gain'
//  '<S82>'  : 'assignment4controller/g2 (fast)/Reset Signal'
//  '<S83>'  : 'assignment4controller/g2 (fast)/Saturation'
//  '<S84>'  : 'assignment4controller/g2 (fast)/Saturation Fdbk'
//  '<S85>'  : 'assignment4controller/g2 (fast)/Sum'
//  '<S86>'  : 'assignment4controller/g2 (fast)/Sum Fdbk'
//  '<S87>'  : 'assignment4controller/g2 (fast)/Tracking Mode'
//  '<S88>'  : 'assignment4controller/g2 (fast)/Tracking Mode Sum'
//  '<S89>'  : 'assignment4controller/g2 (fast)/Tsamp - Integral'
//  '<S90>'  : 'assignment4controller/g2 (fast)/Tsamp - Ngain'
//  '<S91>'  : 'assignment4controller/g2 (fast)/postSat Signal'
//  '<S92>'  : 'assignment4controller/g2 (fast)/preSat Signal'
//  '<S93>'  : 'assignment4controller/g2 (fast)/Anti-windup/Back Calculation'
//  '<S94>'  : 'assignment4controller/g2 (fast)/D Gain/Internal Parameters'
//  '<S95>'  : 'assignment4controller/g2 (fast)/Filter/Cont. Filter'
//  '<S96>'  : 'assignment4controller/g2 (fast)/Filter ICs/Internal IC - Filter'
//  '<S97>'  : 'assignment4controller/g2 (fast)/I Gain/Internal Parameters'
//  '<S98>'  : 'assignment4controller/g2 (fast)/Ideal P Gain/Passthrough'
//  '<S99>'  : 'assignment4controller/g2 (fast)/Ideal P Gain Fdbk/Disabled'
//  '<S100>' : 'assignment4controller/g2 (fast)/Integrator/Continuous'
//  '<S101>' : 'assignment4controller/g2 (fast)/Integrator ICs/Internal IC'
//  '<S102>' : 'assignment4controller/g2 (fast)/N Copy/Disabled'
//  '<S103>' : 'assignment4controller/g2 (fast)/N Gain/Internal Parameters'
//  '<S104>' : 'assignment4controller/g2 (fast)/P Copy/Disabled'
//  '<S105>' : 'assignment4controller/g2 (fast)/Parallel P Gain/Internal Parameters'
//  '<S106>' : 'assignment4controller/g2 (fast)/Reset Signal/Disabled'
//  '<S107>' : 'assignment4controller/g2 (fast)/Saturation/Enabled'
//  '<S108>' : 'assignment4controller/g2 (fast)/Saturation Fdbk/Disabled'
//  '<S109>' : 'assignment4controller/g2 (fast)/Sum/Sum_PID'
//  '<S110>' : 'assignment4controller/g2 (fast)/Sum Fdbk/Disabled'
//  '<S111>' : 'assignment4controller/g2 (fast)/Tracking Mode/Disabled'
//  '<S112>' : 'assignment4controller/g2 (fast)/Tracking Mode Sum/Passthrough'
//  '<S113>' : 'assignment4controller/g2 (fast)/Tsamp - Integral/TsSignalSpecification'
//  '<S114>' : 'assignment4controller/g2 (fast)/Tsamp - Ngain/Passthrough'
//  '<S115>' : 'assignment4controller/g2 (fast)/postSat Signal/Forward_Path'
//  '<S116>' : 'assignment4controller/g2 (fast)/preSat Signal/Forward_Path'
//  '<S117>' : 'assignment4controller/g3 (emergency)/Anti-windup'
//  '<S118>' : 'assignment4controller/g3 (emergency)/D Gain'
//  '<S119>' : 'assignment4controller/g3 (emergency)/Filter'
//  '<S120>' : 'assignment4controller/g3 (emergency)/Filter ICs'
//  '<S121>' : 'assignment4controller/g3 (emergency)/I Gain'
//  '<S122>' : 'assignment4controller/g3 (emergency)/Ideal P Gain'
//  '<S123>' : 'assignment4controller/g3 (emergency)/Ideal P Gain Fdbk'
//  '<S124>' : 'assignment4controller/g3 (emergency)/Integrator'
//  '<S125>' : 'assignment4controller/g3 (emergency)/Integrator ICs'
//  '<S126>' : 'assignment4controller/g3 (emergency)/N Copy'
//  '<S127>' : 'assignment4controller/g3 (emergency)/N Gain'
//  '<S128>' : 'assignment4controller/g3 (emergency)/P Copy'
//  '<S129>' : 'assignment4controller/g3 (emergency)/Parallel P Gain'
//  '<S130>' : 'assignment4controller/g3 (emergency)/Reset Signal'
//  '<S131>' : 'assignment4controller/g3 (emergency)/Saturation'
//  '<S132>' : 'assignment4controller/g3 (emergency)/Saturation Fdbk'
//  '<S133>' : 'assignment4controller/g3 (emergency)/Sum'
//  '<S134>' : 'assignment4controller/g3 (emergency)/Sum Fdbk'
//  '<S135>' : 'assignment4controller/g3 (emergency)/Tracking Mode'
//  '<S136>' : 'assignment4controller/g3 (emergency)/Tracking Mode Sum'
//  '<S137>' : 'assignment4controller/g3 (emergency)/Tsamp - Integral'
//  '<S138>' : 'assignment4controller/g3 (emergency)/Tsamp - Ngain'
//  '<S139>' : 'assignment4controller/g3 (emergency)/postSat Signal'
//  '<S140>' : 'assignment4controller/g3 (emergency)/preSat Signal'
//  '<S141>' : 'assignment4controller/g3 (emergency)/Anti-windup/Back Calculation'
//  '<S142>' : 'assignment4controller/g3 (emergency)/D Gain/Internal Parameters'
//  '<S143>' : 'assignment4controller/g3 (emergency)/Filter/Cont. Filter'
//  '<S144>' : 'assignment4controller/g3 (emergency)/Filter ICs/Internal IC - Filter'
//  '<S145>' : 'assignment4controller/g3 (emergency)/I Gain/Internal Parameters'
//  '<S146>' : 'assignment4controller/g3 (emergency)/Ideal P Gain/Passthrough'
//  '<S147>' : 'assignment4controller/g3 (emergency)/Ideal P Gain Fdbk/Disabled'
//  '<S148>' : 'assignment4controller/g3 (emergency)/Integrator/Continuous'
//  '<S149>' : 'assignment4controller/g3 (emergency)/Integrator ICs/Internal IC'
//  '<S150>' : 'assignment4controller/g3 (emergency)/N Copy/Disabled'
//  '<S151>' : 'assignment4controller/g3 (emergency)/N Gain/Internal Parameters'
//  '<S152>' : 'assignment4controller/g3 (emergency)/P Copy/Disabled'
//  '<S153>' : 'assignment4controller/g3 (emergency)/Parallel P Gain/Internal Parameters'
//  '<S154>' : 'assignment4controller/g3 (emergency)/Reset Signal/Disabled'
//  '<S155>' : 'assignment4controller/g3 (emergency)/Saturation/Enabled'
//  '<S156>' : 'assignment4controller/g3 (emergency)/Saturation Fdbk/Disabled'
//  '<S157>' : 'assignment4controller/g3 (emergency)/Sum/Sum_PID'
//  '<S158>' : 'assignment4controller/g3 (emergency)/Sum Fdbk/Disabled'
//  '<S159>' : 'assignment4controller/g3 (emergency)/Tracking Mode/Disabled'
//  '<S160>' : 'assignment4controller/g3 (emergency)/Tracking Mode Sum/Passthrough'
//  '<S161>' : 'assignment4controller/g3 (emergency)/Tsamp - Integral/TsSignalSpecification'
//  '<S162>' : 'assignment4controller/g3 (emergency)/Tsamp - Ngain/Passthrough'
//  '<S163>' : 'assignment4controller/g3 (emergency)/postSat Signal/Forward_Path'
//  '<S164>' : 'assignment4controller/g3 (emergency)/preSat Signal/Forward_Path'

#endif                                 // RTW_HEADER_assignment4controller_h_

//
// File trailer for generated code.
//
// [EOF]
//

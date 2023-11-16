//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: assignment4controller_private.h
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
#ifndef RTW_HEADER_assignment4controller_private_h_
#define RTW_HEADER_assignment4controller_private_h_
#include "rtwtypes.h"
#include "assignment4controller.h"
#include "assignment4controller_types.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"

// Private macros used by the generated code to access rtModel
#ifndef rtmIsMajorTimeStep
#define rtmIsMajorTimeStep(rtm)        (((rtm)->Timing.simTimeStep) == MAJOR_TIME_STEP)
#endif

#ifndef rtmIsMinorTimeStep
#define rtmIsMinorTimeStep(rtm)        (((rtm)->Timing.simTimeStep) == MINOR_TIME_STEP)
#endif

#ifndef rtmSetTPtr
#define rtmSetTPtr(rtm, val)           ((rtm)->Timing.t = (val))
#endif

extern void assignment4contr_DeadMansSwitch(boolean_T rtu_IsNew, real_T
  rtu_value, real_T *rty_safeValue, boolean_T *rty_timedOut, real_T rtp_stepSize,
  real_T rtp_timeout, DW_DeadMansSwitch_assignment4_T *localDW);

// private model entry point functions
extern void assignment4controller_derivatives(void);

#endif                           // RTW_HEADER_assignment4controller_private_h_

//
// File trailer for generated code.
//
// [EOF]
//

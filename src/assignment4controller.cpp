//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: assignment4controller.cpp
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
#include "rtwtypes.h"
#include "assignment4controller_private.h"
#include <math.h>
#include "assignment4controller_types.h"

// Block signals (default storage)
B_assignment4controller_T assignment4controller_B;

// Continuous states
X_assignment4controller_T assignment4controller_X;

// Disabled State Vector
XDis_assignment4controller_T assignment4controller_XDis;

// Block states (default storage)
DW_assignment4controller_T assignment4controller_DW;

// Real-time model
RT_MODEL_assignment4controlle_T assignment4controller_M_ =
  RT_MODEL_assignment4controlle_T();
RT_MODEL_assignment4controlle_T *const assignment4controller_M =
  &assignment4controller_M_;

//
// This function updates continuous states using the ODE3 fixed-step
// solver algorithm
//
static void rt_ertODEUpdateContinuousStates(RTWSolverInfo *si )
{
  // Solver Matrices
  static const real_T rt_ODE3_A[3] = {
    1.0/2.0, 3.0/4.0, 1.0
  };

  static const real_T rt_ODE3_B[3][3] = {
    { 1.0/2.0, 0.0, 0.0 },

    { 0.0, 3.0/4.0, 0.0 },

    { 2.0/9.0, 1.0/3.0, 4.0/9.0 }
  };

  time_T t = rtsiGetT(si);
  time_T tnew = rtsiGetSolverStopTime(si);
  time_T h = rtsiGetStepSize(si);
  real_T *x = rtsiGetContStates(si);
  ODE3_IntgData *id = static_cast<ODE3_IntgData *>(rtsiGetSolverData(si));
  real_T *y = id->y;
  real_T *f0 = id->f[0];
  real_T *f1 = id->f[1];
  real_T *f2 = id->f[2];
  real_T hB[3];
  int_T i;
  int_T nXc = 7;
  rtsiSetSimTimeStep(si,MINOR_TIME_STEP);

  // Save the state values at time t in y, we'll use x as ynew.
  (void) memcpy(y, x,
                static_cast<uint_T>(nXc)*sizeof(real_T));

  // Assumes that rtsiSetT and ModelOutputs are up-to-date
  // f0 = f(t,y)
  rtsiSetdX(si, f0);
  assignment4controller_derivatives();

  // f(:,2) = feval(odefile, t + hA(1), y + f*hB(:,1), args(:)(*));
  hB[0] = h * rt_ODE3_B[0][0];
  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0]);
  }

  rtsiSetT(si, t + h*rt_ODE3_A[0]);
  rtsiSetdX(si, f1);
  assignment4controller_step();
  assignment4controller_derivatives();

  // f(:,3) = feval(odefile, t + hA(2), y + f*hB(:,2), args(:)(*));
  for (i = 0; i <= 1; i++) {
    hB[i] = h * rt_ODE3_B[1][i];
  }

  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0] + f1[i]*hB[1]);
  }

  rtsiSetT(si, t + h*rt_ODE3_A[1]);
  rtsiSetdX(si, f2);
  assignment4controller_step();
  assignment4controller_derivatives();

  // tnew = t + hA(3);
  // ynew = y + f*hB(:,3);
  for (i = 0; i <= 2; i++) {
    hB[i] = h * rt_ODE3_B[2][i];
  }

  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0] + f1[i]*hB[1] + f2[i]*hB[2]);
  }

  rtsiSetT(si, tnew);
  rtsiSetSimTimeStep(si,MAJOR_TIME_STEP);
}

//
// Output and update for atomic system:
//    '<Root>/Dead Man's Switch'
//    '<Root>/Dead Man's Switch1'
//    '<Root>/Dead Man's Switch2'
//
void assignment4contr_DeadMansSwitch(boolean_T rtu_IsNew, real_T rtu_value,
  real_T *rty_safeValue, boolean_T *rty_timedOut, real_T rtp_stepSize, real_T
  rtp_timeout, DW_DeadMansSwitch_assignment4_T *localDW)
{
  boolean_T timedOut;

  // MATLAB Function: '<S2>/timeout set to 0 output' incorporates:
  //   Constant: '<S2>/Simulate step size'
  //   Constant: '<S2>/Timeout in seconds'

  if (!localDW->sinceLastMsg_not_empty) {
    localDW->sinceLastMsg = rtp_timeout / rtp_stepSize + 1.0;
    localDW->sinceLastMsg_not_empty = true;
  }

  *rty_safeValue = 0.0;
  if (rtu_IsNew) {
    localDW->sinceLastMsg = 0.0;
  } else {
    localDW->sinceLastMsg++;
  }

  timedOut = !(localDW->sinceLastMsg < rtp_timeout / rtp_stepSize);
  if (!timedOut) {
    *rty_safeValue = rtu_value;
  }

  *rty_timedOut = timedOut;

  // End of MATLAB Function: '<S2>/timeout set to 0 output'
}

// Model step function
void assignment4controller_step(void)
{
  SL_Bus_assignment4controller_std_msgs_Float64 rtb_BusAssignment;
  real_T rtb_Saturation_k;
  real_T rtb_Saturation_o;
  real_T rtb_safeValue;
  real_T rtb_safeValue_g;
  real_T rtb_safeValue_p;
  real_T tmp;
  boolean_T rtb_timedOut_o;
  if (rtmIsMajorTimeStep(assignment4controller_M)) {
    // set solver stop time
    rtsiSetSolverStopTime(&assignment4controller_M->solverInfo,
                          ((assignment4controller_M->Timing.clockTick0+1)*
      assignment4controller_M->Timing.stepSize0));
  }                                    // end MajorTimeStep

  // Update absolute time of base rate at minor time step
  if (rtmIsMinorTimeStep(assignment4controller_M)) {
    assignment4controller_M->Timing.t[0] = rtsiGetT
      (&assignment4controller_M->solverInfo);
  }

  if (rtmIsMajorTimeStep(assignment4controller_M)) {
    // Outputs for Atomic SubSystem: '<Root>/Subscribe'
    // MATLABSystem: '<S9>/SourceBlock'
    rtb_timedOut_o = Sub_assignment4controller_50.getLatestMessage
      (&assignment4controller_B.b_varargout_2);

    // Outputs for Enabled SubSystem: '<S9>/Enabled Subsystem' incorporates:
    //   EnablePort: '<S18>/Enable'

    // Start for MATLABSystem: '<S9>/SourceBlock'
    if (rtb_timedOut_o) {
      // SignalConversion generated from: '<S18>/In1'
      assignment4controller_B.In1_d = assignment4controller_B.b_varargout_2;
    }

    // End of Start for MATLABSystem: '<S9>/SourceBlock'
    // End of Outputs for SubSystem: '<S9>/Enabled Subsystem'
    // End of Outputs for SubSystem: '<Root>/Subscribe'

    // Outputs for Atomic SubSystem: '<Root>/Dead Man's Switch1'
    // Outputs for Atomic SubSystem: '<Root>/Dead Man's Switch1'
    // Constant: '<Root>/Constant2'
    assignment4contr_DeadMansSwitch(assignment4controller_P.Constant2_Value,
      assignment4controller_B.In1_d.Data, &rtb_safeValue_p, &rtb_timedOut_o,
      assignment4controller_P.DeadMansSwitch1_stepSize,
      assignment4controller_P.DeadMansSwitch1_timeout,
      &assignment4controller_DW.DeadMansSwitch1);

    // End of Outputs for SubSystem: '<Root>/Dead Man's Switch1'
    // End of Outputs for SubSystem: '<Root>/Dead Man's Switch1'

    // Outputs for Atomic SubSystem: '<Root>/Subscribe2'
    // MATLABSystem: '<S11>/SourceBlock'
    rtb_timedOut_o = Sub_assignment4controller_52.getLatestMessage
      (&assignment4controller_B.b_varargout_2);

    // Outputs for Enabled SubSystem: '<S11>/Enabled Subsystem' incorporates:
    //   EnablePort: '<S20>/Enable'

    // Start for MATLABSystem: '<S11>/SourceBlock'
    if (rtb_timedOut_o) {
      // SignalConversion generated from: '<S20>/In1'
      assignment4controller_B.In1 = assignment4controller_B.b_varargout_2;
    }

    // End of Start for MATLABSystem: '<S11>/SourceBlock'
    // End of Outputs for SubSystem: '<S11>/Enabled Subsystem'
    // End of Outputs for SubSystem: '<Root>/Subscribe2'

    // Outputs for Atomic SubSystem: '<Root>/Dead Man's Switch'
    // Outputs for Atomic SubSystem: '<Root>/Dead Man's Switch'
    // Constant: '<Root>/Constant1'
    assignment4contr_DeadMansSwitch(assignment4controller_P.Constant1_Value,
      assignment4controller_B.In1.Data, &rtb_safeValue_g, &rtb_timedOut_o,
      assignment4controller_P.DeadMansSwitch_stepSize,
      assignment4controller_P.DeadMansSwitch_timeout,
      &assignment4controller_DW.DeadMansSwitch);

    // End of Outputs for SubSystem: '<Root>/Dead Man's Switch'
    // End of Outputs for SubSystem: '<Root>/Dead Man's Switch'

    // Outputs for Atomic SubSystem: '<Root>/Subscribe1'
    // MATLABSystem: '<S10>/SourceBlock'
    rtb_timedOut_o = Sub_assignment4controller_51.getLatestMessage
      (&assignment4controller_B.b_varargout_2);

    // Outputs for Enabled SubSystem: '<S10>/Enabled Subsystem' incorporates:
    //   EnablePort: '<S19>/Enable'

    // Start for MATLABSystem: '<S10>/SourceBlock'
    if (rtb_timedOut_o) {
      // SignalConversion generated from: '<S19>/In1'
      assignment4controller_B.In1_m = assignment4controller_B.b_varargout_2;
    }

    // End of Start for MATLABSystem: '<S10>/SourceBlock'
    // End of Outputs for SubSystem: '<S10>/Enabled Subsystem'
    // End of Outputs for SubSystem: '<Root>/Subscribe1'

    // Outputs for Atomic SubSystem: '<Root>/Dead Man's Switch2'
    // Outputs for Atomic SubSystem: '<Root>/Dead Man's Switch2'
    // Constant: '<Root>/Constant3'
    assignment4contr_DeadMansSwitch(assignment4controller_P.Constant3_Value,
      assignment4controller_B.In1_m.Data, &rtb_safeValue, &rtb_timedOut_o,
      assignment4controller_P.DeadMansSwitch2_stepSize,
      assignment4controller_P.DeadMansSwitch2_timeout,
      &assignment4controller_DW.DeadMansSwitch2);

    // End of Outputs for SubSystem: '<Root>/Dead Man's Switch2'
    // End of Outputs for SubSystem: '<Root>/Dead Man's Switch2'

    // MATLAB Function: '<Root>/MATLAB Function2'
    if (fabs(rtb_safeValue_p) < 1.0E-6) {
      rtb_safeValue_p = 1.0E-6;
    }

    if (fabs(rtb_safeValue) < 1.0E-6) {
      rtb_safeValue = 1.0E-6;
    }

    if (rtb_safeValue < 0.1) {
      assignment4controller_B.y = rtb_safeValue_g / rtb_safeValue_p;
    } else {
      assignment4controller_B.y = rtb_safeValue_g / rtb_safeValue;
    }

    // End of MATLAB Function: '<Root>/MATLAB Function2'
  }

  // TransferFcn: '<Root>/Transfer Fcn'
  rtb_safeValue_p = assignment4controller_P.TransferFcn_C *
    assignment4controller_X.TransferFcn_CSTATE;

  // Gain: '<S55>/Filter Coefficient' incorporates:
  //   Gain: '<S46>/Derivative Gain'
  //   Integrator: '<S47>/Filter'
  //   Sum: '<S47>/SumD'

  assignment4controller_B.FilterCoefficient = (assignment4controller_P.g1slow_D *
    rtb_safeValue_p - assignment4controller_X.Filter_CSTATE) *
    assignment4controller_P.g1slow_N;

  // Sum: '<S61>/Sum' incorporates:
  //   Gain: '<S57>/Proportional Gain'
  //   Integrator: '<S52>/Integrator'

  rtb_safeValue_g = (assignment4controller_P.g1slow_P * rtb_safeValue_p +
                     assignment4controller_X.Integrator_CSTATE) +
    assignment4controller_B.FilterCoefficient;

  // Saturate: '<S59>/Saturation'
  if (rtb_safeValue_g > assignment4controller_P.g1slow_UpperSaturationLimit) {
    rtb_safeValue = assignment4controller_P.g1slow_UpperSaturationLimit;
  } else if (rtb_safeValue_g <
             assignment4controller_P.g1slow_LowerSaturationLimit) {
    rtb_safeValue = assignment4controller_P.g1slow_LowerSaturationLimit;
  } else {
    rtb_safeValue = rtb_safeValue_g;
  }

  // End of Saturate: '<S59>/Saturation'

  // Gain: '<S103>/Filter Coefficient' incorporates:
  //   Gain: '<S94>/Derivative Gain'
  //   Integrator: '<S95>/Filter'
  //   Sum: '<S95>/SumD'

  assignment4controller_B.FilterCoefficient_d =
    (assignment4controller_P.g2fast_D * rtb_safeValue_p -
     assignment4controller_X.Filter_CSTATE_j) * assignment4controller_P.g2fast_N;

  // Sum: '<S109>/Sum' incorporates:
  //   Gain: '<S105>/Proportional Gain'
  //   Integrator: '<S100>/Integrator'

  assignment4controller_B.Sum_b = (assignment4controller_P.g2fast_P *
    rtb_safeValue_p + assignment4controller_X.Integrator_CSTATE_j) +
    assignment4controller_B.FilterCoefficient_d;

  // Saturate: '<S107>/Saturation'
  if (assignment4controller_B.Sum_b >
      assignment4controller_P.g2fast_UpperSaturationLimit) {
    rtb_Saturation_k = assignment4controller_P.g2fast_UpperSaturationLimit;
  } else if (assignment4controller_B.Sum_b <
             assignment4controller_P.g2fast_LowerSaturationLimit) {
    rtb_Saturation_k = assignment4controller_P.g2fast_LowerSaturationLimit;
  } else {
    rtb_Saturation_k = assignment4controller_B.Sum_b;
  }

  // End of Saturate: '<S107>/Saturation'

  // Gain: '<S151>/Filter Coefficient' incorporates:
  //   Gain: '<S142>/Derivative Gain'
  //   Integrator: '<S143>/Filter'
  //   Sum: '<S143>/SumD'

  assignment4controller_B.FilterCoefficient_p =
    (assignment4controller_P.g3emergency_D * rtb_safeValue_p -
     assignment4controller_X.Filter_CSTATE_b) *
    assignment4controller_P.g3emergency_N;

  // Sum: '<S157>/Sum' incorporates:
  //   Gain: '<S153>/Proportional Gain'
  //   Integrator: '<S148>/Integrator'

  assignment4controller_B.Sum_c = (assignment4controller_P.g3emergency_P *
    rtb_safeValue_p + assignment4controller_X.Integrator_CSTATE_jp) +
    assignment4controller_B.FilterCoefficient_p;

  // Saturate: '<S155>/Saturation'
  if (assignment4controller_B.Sum_c >
      assignment4controller_P.g3emergency_UpperSaturationLimi) {
    rtb_Saturation_o = assignment4controller_P.g3emergency_UpperSaturationLimi;
  } else if (assignment4controller_B.Sum_c <
             assignment4controller_P.g3emergency_LowerSaturationLimi) {
    rtb_Saturation_o = assignment4controller_P.g3emergency_LowerSaturationLimi;
  } else {
    rtb_Saturation_o = assignment4controller_B.Sum_c;
  }

  // End of Saturate: '<S155>/Saturation'

  // MATLAB Function: '<Root>/MATLAB Function1'
  if (assignment4controller_B.y > 10.0) {
    tmp = rtb_safeValue;
  } else if (assignment4controller_B.y > 5.0) {
    tmp = rtb_Saturation_k;
  } else {
    tmp = rtb_Saturation_o;
  }

  // BusAssignment: '<Root>/Bus Assignment' incorporates:
  //   Gain: '<Root>/Gain'
  //   MATLAB Function: '<Root>/MATLAB Function1'

  rtb_BusAssignment.Data = assignment4controller_P.Gain_Gain * tmp;

  // Outputs for Atomic SubSystem: '<Root>/Publish'
  // MATLABSystem: '<S8>/SinkBlock'
  Pub_assignment4controller_55.publish(&rtb_BusAssignment);

  // End of Outputs for SubSystem: '<Root>/Publish'

  // Sum: '<S141>/SumI4' incorporates:
  //   Gain: '<S141>/Kb'
  //   Gain: '<S145>/Integral Gain'
  //   Sum: '<S141>/SumI2'

  assignment4controller_B.SumI4 = (rtb_Saturation_o -
    assignment4controller_B.Sum_c) * assignment4controller_P.g3emergency_Kb +
    assignment4controller_P.g3emergency_I * rtb_safeValue_p;

  // Sum: '<S93>/SumI4' incorporates:
  //   Gain: '<S93>/Kb'
  //   Gain: '<S97>/Integral Gain'
  //   Sum: '<S93>/SumI2'

  assignment4controller_B.SumI4_b = (rtb_Saturation_k -
    assignment4controller_B.Sum_b) * assignment4controller_P.g2fast_Kb +
    assignment4controller_P.g2fast_I * rtb_safeValue_p;

  // Sum: '<S45>/SumI4' incorporates:
  //   Gain: '<S45>/Kb'
  //   Gain: '<S49>/Integral Gain'
  //   Sum: '<S45>/SumI2'

  assignment4controller_B.SumI4_h = (rtb_safeValue - rtb_safeValue_g) *
    assignment4controller_P.g1slow_Kb + assignment4controller_P.g1slow_I *
    rtb_safeValue_p;
  if (rtmIsMajorTimeStep(assignment4controller_M)) {
    // MATLAB Function: '<Root>/MATLAB Function' incorporates:
    //   Constant: '<Root>/Constant'

    assignment4controller_B.y_n = assignment4controller_B.y -
      assignment4controller_P.Constant_Value_a;
  }

  if (rtmIsMajorTimeStep(assignment4controller_M)) {
    rt_ertODEUpdateContinuousStates(&assignment4controller_M->solverInfo);

    // Update absolute time for base rate
    // The "clockTick0" counts the number of times the code of this task has
    //  been executed. The absolute time is the multiplication of "clockTick0"
    //  and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
    //  overflow during the application lifespan selected.

    ++assignment4controller_M->Timing.clockTick0;
    assignment4controller_M->Timing.t[0] = rtsiGetSolverStopTime
      (&assignment4controller_M->solverInfo);

    {
      // Update absolute timer for sample time: [0.2s, 0.0s]
      // The "clockTick1" counts the number of times the code of this task has
      //  been executed. The resolution of this integer timer is 0.2, which is the step size
      //  of the task. Size of "clockTick1" ensures timer will not overflow during the
      //  application lifespan selected.

      assignment4controller_M->Timing.clockTick1++;
    }
  }                                    // end MajorTimeStep
}

// Derivatives for root system: '<Root>'
void assignment4controller_derivatives(void)
{
  XDot_assignment4controller_T *_rtXdot;
  _rtXdot = ((XDot_assignment4controller_T *) assignment4controller_M->derivs);

  // Derivatives for TransferFcn: '<Root>/Transfer Fcn'
  _rtXdot->TransferFcn_CSTATE = assignment4controller_P.TransferFcn_A *
    assignment4controller_X.TransferFcn_CSTATE;
  _rtXdot->TransferFcn_CSTATE += assignment4controller_B.y_n;

  // Derivatives for Integrator: '<S52>/Integrator'
  _rtXdot->Integrator_CSTATE = assignment4controller_B.SumI4_h;

  // Derivatives for Integrator: '<S47>/Filter'
  _rtXdot->Filter_CSTATE = assignment4controller_B.FilterCoefficient;

  // Derivatives for Integrator: '<S100>/Integrator'
  _rtXdot->Integrator_CSTATE_j = assignment4controller_B.SumI4_b;

  // Derivatives for Integrator: '<S95>/Filter'
  _rtXdot->Filter_CSTATE_j = assignment4controller_B.FilterCoefficient_d;

  // Derivatives for Integrator: '<S148>/Integrator'
  _rtXdot->Integrator_CSTATE_jp = assignment4controller_B.SumI4;

  // Derivatives for Integrator: '<S143>/Filter'
  _rtXdot->Filter_CSTATE_b = assignment4controller_B.FilterCoefficient_p;
}

// Model initialize function
void assignment4controller_initialize(void)
{
  // Registration code
  {
    // Setup solver object
    rtsiSetSimTimeStepPtr(&assignment4controller_M->solverInfo,
                          &assignment4controller_M->Timing.simTimeStep);
    rtsiSetTPtr(&assignment4controller_M->solverInfo, &rtmGetTPtr
                (assignment4controller_M));
    rtsiSetStepSizePtr(&assignment4controller_M->solverInfo,
                       &assignment4controller_M->Timing.stepSize0);
    rtsiSetdXPtr(&assignment4controller_M->solverInfo,
                 &assignment4controller_M->derivs);
    rtsiSetContStatesPtr(&assignment4controller_M->solverInfo, (real_T **)
                         &assignment4controller_M->contStates);
    rtsiSetNumContStatesPtr(&assignment4controller_M->solverInfo,
      &assignment4controller_M->Sizes.numContStates);
    rtsiSetNumPeriodicContStatesPtr(&assignment4controller_M->solverInfo,
      &assignment4controller_M->Sizes.numPeriodicContStates);
    rtsiSetPeriodicContStateIndicesPtr(&assignment4controller_M->solverInfo,
      &assignment4controller_M->periodicContStateIndices);
    rtsiSetPeriodicContStateRangesPtr(&assignment4controller_M->solverInfo,
      &assignment4controller_M->periodicContStateRanges);
    rtsiSetContStateDisabledPtr(&assignment4controller_M->solverInfo, (boolean_T**)
      &assignment4controller_M->contStateDisabled);
    rtsiSetErrorStatusPtr(&assignment4controller_M->solverInfo,
                          (&rtmGetErrorStatus(assignment4controller_M)));
    rtsiSetRTModelPtr(&assignment4controller_M->solverInfo,
                      assignment4controller_M);
  }

  rtsiSetSimTimeStep(&assignment4controller_M->solverInfo, MAJOR_TIME_STEP);
  assignment4controller_M->intgData.y = assignment4controller_M->odeY;
  assignment4controller_M->intgData.f[0] = assignment4controller_M->odeF[0];
  assignment4controller_M->intgData.f[1] = assignment4controller_M->odeF[1];
  assignment4controller_M->intgData.f[2] = assignment4controller_M->odeF[2];
  assignment4controller_M->contStates = ((X_assignment4controller_T *)
    &assignment4controller_X);
  assignment4controller_M->contStateDisabled = ((XDis_assignment4controller_T *)
    &assignment4controller_XDis);
  assignment4controller_M->Timing.tStart = (0.0);
  rtsiSetSolverData(&assignment4controller_M->solverInfo, static_cast<void *>
                    (&assignment4controller_M->intgData));
  rtsiSetIsMinorTimeStepWithModeChange(&assignment4controller_M->solverInfo,
    false);
  rtsiSetSolverName(&assignment4controller_M->solverInfo,"ode3");
  rtmSetTPtr(assignment4controller_M, &assignment4controller_M->Timing.tArray[0]);
  assignment4controller_M->Timing.stepSize0 = 0.2;

  {
    int32_T i;
    char_T b_zeroDelimTopic[17];
    char_T b_zeroDelimTopic_2[15];
    char_T b_zeroDelimTopic_0[11];
    char_T b_zeroDelimTopic_1[9];
    static const char_T b_zeroDelimTopic_3[17] = "/car/state/vel_x";
    static const char_T b_zeroDelimTopic_4[11] = "/lead_dist";
    static const char_T b_zeroDelimTopic_5[9] = "/rel_vel";
    static const char_T b_zeroDelimTopic_6[15] = "/cmd_accel_sim";

    // InitializeConditions for TransferFcn: '<Root>/Transfer Fcn'
    assignment4controller_X.TransferFcn_CSTATE = 0.0;

    // InitializeConditions for Integrator: '<S52>/Integrator'
    assignment4controller_X.Integrator_CSTATE =
      assignment4controller_P.g1slow_InitialConditionForInteg;

    // InitializeConditions for Integrator: '<S47>/Filter'
    assignment4controller_X.Filter_CSTATE =
      assignment4controller_P.g1slow_InitialConditionForFilte;

    // InitializeConditions for Integrator: '<S100>/Integrator'
    assignment4controller_X.Integrator_CSTATE_j =
      assignment4controller_P.g2fast_InitialConditionForInteg;

    // InitializeConditions for Integrator: '<S95>/Filter'
    assignment4controller_X.Filter_CSTATE_j =
      assignment4controller_P.g2fast_InitialConditionForFilte;

    // InitializeConditions for Integrator: '<S148>/Integrator'
    assignment4controller_X.Integrator_CSTATE_jp =
      assignment4controller_P.g3emergency_InitialConditionF_l;

    // InitializeConditions for Integrator: '<S143>/Filter'
    assignment4controller_X.Filter_CSTATE_b =
      assignment4controller_P.g3emergency_InitialConditionFor;

    // SystemInitialize for Atomic SubSystem: '<Root>/Subscribe'
    // SystemInitialize for Enabled SubSystem: '<S9>/Enabled Subsystem'
    // SystemInitialize for SignalConversion generated from: '<S18>/In1' incorporates:
    //   Outport: '<S18>/Out1'

    assignment4controller_B.In1_d = assignment4controller_P.Out1_Y0;

    // End of SystemInitialize for SubSystem: '<S9>/Enabled Subsystem'

    // Start for MATLABSystem: '<S9>/SourceBlock'
    assignment4controller_DW.obj_k.matlabCodegenIsDeleted = false;
    assignment4controller_DW.obj_k.isInitialized = 1;
    for (i = 0; i < 17; i++) {
      b_zeroDelimTopic[i] = b_zeroDelimTopic_3[i];
    }

    Sub_assignment4controller_50.createSubscriber(&b_zeroDelimTopic[0], 1);
    assignment4controller_DW.obj_k.isSetupComplete = true;

    // End of Start for MATLABSystem: '<S9>/SourceBlock'
    // End of SystemInitialize for SubSystem: '<Root>/Subscribe'

    // SystemInitialize for Atomic SubSystem: '<Root>/Subscribe2'
    // SystemInitialize for Enabled SubSystem: '<S11>/Enabled Subsystem'
    // SystemInitialize for SignalConversion generated from: '<S20>/In1' incorporates:
    //   Outport: '<S20>/Out1'

    assignment4controller_B.In1 = assignment4controller_P.Out1_Y0_h;

    // End of SystemInitialize for SubSystem: '<S11>/Enabled Subsystem'

    // Start for MATLABSystem: '<S11>/SourceBlock'
    assignment4controller_DW.obj_e.matlabCodegenIsDeleted = false;
    assignment4controller_DW.obj_e.isInitialized = 1;
    for (i = 0; i < 11; i++) {
      b_zeroDelimTopic_0[i] = b_zeroDelimTopic_4[i];
    }

    Sub_assignment4controller_52.createSubscriber(&b_zeroDelimTopic_0[0], 1);
    assignment4controller_DW.obj_e.isSetupComplete = true;

    // End of Start for MATLABSystem: '<S11>/SourceBlock'
    // End of SystemInitialize for SubSystem: '<Root>/Subscribe2'

    // SystemInitialize for Atomic SubSystem: '<Root>/Subscribe1'
    // SystemInitialize for Enabled SubSystem: '<S10>/Enabled Subsystem'
    // SystemInitialize for SignalConversion generated from: '<S19>/In1' incorporates:
    //   Outport: '<S19>/Out1'

    assignment4controller_B.In1_m = assignment4controller_P.Out1_Y0_g;

    // End of SystemInitialize for SubSystem: '<S10>/Enabled Subsystem'

    // Start for MATLABSystem: '<S10>/SourceBlock'
    assignment4controller_DW.obj_j.matlabCodegenIsDeleted = false;
    assignment4controller_DW.obj_j.isInitialized = 1;
    for (i = 0; i < 9; i++) {
      b_zeroDelimTopic_1[i] = b_zeroDelimTopic_5[i];
    }

    Sub_assignment4controller_51.createSubscriber(&b_zeroDelimTopic_1[0], 1);
    assignment4controller_DW.obj_j.isSetupComplete = true;

    // End of Start for MATLABSystem: '<S10>/SourceBlock'
    // End of SystemInitialize for SubSystem: '<Root>/Subscribe1'

    // SystemInitialize for Atomic SubSystem: '<Root>/Publish'
    // Start for MATLABSystem: '<S8>/SinkBlock'
    assignment4controller_DW.obj.matlabCodegenIsDeleted = false;
    assignment4controller_DW.obj.isInitialized = 1;
    for (i = 0; i < 15; i++) {
      b_zeroDelimTopic_2[i] = b_zeroDelimTopic_6[i];
    }

    Pub_assignment4controller_55.createPublisher(&b_zeroDelimTopic_2[0], 1);
    assignment4controller_DW.obj.isSetupComplete = true;

    // End of Start for MATLABSystem: '<S8>/SinkBlock'
    // End of SystemInitialize for SubSystem: '<Root>/Publish'
  }
}

// Model terminate function
void assignment4controller_terminate(void)
{
  // Terminate for Atomic SubSystem: '<Root>/Subscribe'
  // Terminate for MATLABSystem: '<S9>/SourceBlock'
  if (!assignment4controller_DW.obj_k.matlabCodegenIsDeleted) {
    assignment4controller_DW.obj_k.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S9>/SourceBlock'
  // End of Terminate for SubSystem: '<Root>/Subscribe'

  // Terminate for Atomic SubSystem: '<Root>/Subscribe2'
  // Terminate for MATLABSystem: '<S11>/SourceBlock'
  if (!assignment4controller_DW.obj_e.matlabCodegenIsDeleted) {
    assignment4controller_DW.obj_e.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S11>/SourceBlock'
  // End of Terminate for SubSystem: '<Root>/Subscribe2'

  // Terminate for Atomic SubSystem: '<Root>/Subscribe1'
  // Terminate for MATLABSystem: '<S10>/SourceBlock'
  if (!assignment4controller_DW.obj_j.matlabCodegenIsDeleted) {
    assignment4controller_DW.obj_j.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S10>/SourceBlock'
  // End of Terminate for SubSystem: '<Root>/Subscribe1'

  // Terminate for Atomic SubSystem: '<Root>/Publish'
  // Terminate for MATLABSystem: '<S8>/SinkBlock'
  if (!assignment4controller_DW.obj.matlabCodegenIsDeleted) {
    assignment4controller_DW.obj.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S8>/SinkBlock'
  // End of Terminate for SubSystem: '<Root>/Publish'
}

//
// File trailer for generated code.
//
// [EOF]
//

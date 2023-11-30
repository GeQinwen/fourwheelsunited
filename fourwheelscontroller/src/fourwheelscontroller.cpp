//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: fourwheelscontroller.cpp
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
#include "rtwtypes.h"
#include "fourwheelscontroller_types.h"
#include "fourwheelscontroller_private.h"

// Block signals (default storage)
B_fourwheelscontroller_T fourwheelscontroller_B;

// Continuous states
X_fourwheelscontroller_T fourwheelscontroller_X;

// Disabled State Vector
XDis_fourwheelscontroller_T fourwheelscontroller_XDis;

// Block states (default storage)
DW_fourwheelscontroller_T fourwheelscontroller_DW;

// Real-time model
RT_MODEL_fourwheelscontroller_T fourwheelscontroller_M_ =
  RT_MODEL_fourwheelscontroller_T();
RT_MODEL_fourwheelscontroller_T *const fourwheelscontroller_M =
  &fourwheelscontroller_M_;

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
  int_T nXc = 4;
  rtsiSetSimTimeStep(si,MINOR_TIME_STEP);

  // Save the state values at time t in y, we'll use x as ynew.
  (void) memcpy(y, x,
                static_cast<uint_T>(nXc)*sizeof(real_T));

  // Assumes that rtsiSetT and ModelOutputs are up-to-date
  // f0 = f(t,y)
  rtsiSetdX(si, f0);
  fourwheelscontroller_derivatives();

  // f(:,2) = feval(odefile, t + hA(1), y + f*hB(:,1), args(:)(*));
  hB[0] = h * rt_ODE3_B[0][0];
  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0]);
  }

  rtsiSetT(si, t + h*rt_ODE3_A[0]);
  rtsiSetdX(si, f1);
  fourwheelscontroller_step();
  fourwheelscontroller_derivatives();

  // f(:,3) = feval(odefile, t + hA(2), y + f*hB(:,2), args(:)(*));
  for (i = 0; i <= 1; i++) {
    hB[i] = h * rt_ODE3_B[1][i];
  }

  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0] + f1[i]*hB[1]);
  }

  rtsiSetT(si, t + h*rt_ODE3_A[1]);
  rtsiSetdX(si, f2);
  fourwheelscontroller_step();
  fourwheelscontroller_derivatives();

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

// Model step function
void fourwheelscontroller_step(void)
{
  SL_Bus_fourwheelscontroller_std_msgs_Float64 rtb_BusAssignment;
  real_T rtb_Saturation;
  real_T rtb_Saturation_k;
  real_T rtb_Sum;
  real_T rtb_Sum_a;
  real_T rtb_y_m;
  real_T tmp;
  boolean_T b_varargout_1;
  if (rtmIsMajorTimeStep(fourwheelscontroller_M)) {
    // set solver stop time
    rtsiSetSolverStopTime(&fourwheelscontroller_M->solverInfo,
                          ((fourwheelscontroller_M->Timing.clockTick0+1)*
      fourwheelscontroller_M->Timing.stepSize0));
  }                                    // end MajorTimeStep

  // Update absolute time of base rate at minor time step
  if (rtmIsMinorTimeStep(fourwheelscontroller_M)) {
    fourwheelscontroller_M->Timing.t[0] = rtsiGetT
      (&fourwheelscontroller_M->solverInfo);
  }

  if (rtmIsMajorTimeStep(fourwheelscontroller_M)) {
    // Outputs for Atomic SubSystem: '<Root>/Subscribe'
    // MATLABSystem: '<S6>/SourceBlock'
    b_varargout_1 = Sub_fourwheelscontroller_11.getLatestMessage
      (&fourwheelscontroller_B.b_varargout_2);

    // Outputs for Enabled SubSystem: '<S6>/Enabled Subsystem' incorporates:
    //   EnablePort: '<S10>/Enable'

    // Start for MATLABSystem: '<S6>/SourceBlock'
    if (b_varargout_1) {
      // SignalConversion generated from: '<S10>/In1'
      fourwheelscontroller_B.In1_p = fourwheelscontroller_B.b_varargout_2;
    }

    // End of Start for MATLABSystem: '<S6>/SourceBlock'
    // End of Outputs for SubSystem: '<S6>/Enabled Subsystem'
    // End of Outputs for SubSystem: '<Root>/Subscribe'

    // Outputs for Atomic SubSystem: '<Root>/Subscribe1'
    // MATLABSystem: '<S7>/SourceBlock'
    b_varargout_1 = Sub_fourwheelscontroller_12.getLatestMessage
      (&fourwheelscontroller_B.b_varargout_2);

    // Outputs for Enabled SubSystem: '<S7>/Enabled Subsystem' incorporates:
    //   EnablePort: '<S11>/Enable'

    // Start for MATLABSystem: '<S7>/SourceBlock'
    if (b_varargout_1) {
      // SignalConversion generated from: '<S11>/In1'
      fourwheelscontroller_B.In1 = fourwheelscontroller_B.b_varargout_2;
    }

    // End of Start for MATLABSystem: '<S7>/SourceBlock'
    // End of Outputs for SubSystem: '<S7>/Enabled Subsystem'
    // End of Outputs for SubSystem: '<Root>/Subscribe1'

    // MATLAB Function: '<Root>/MATLAB Function' incorporates:
    //   Constant: '<Root>/Constant'
    //   MATLAB Function: '<Root>/MATLAB Function2'

    rtb_y_m = fourwheelscontroller_B.In1_p.Data -
      fourwheelscontroller_P.Constant_Value_e * fourwheelscontroller_B.In1.Data;

    // Gain: '<S48>/Proportional Gain'
    fourwheelscontroller_B.ProportionalGain = fourwheelscontroller_P.g1slow_P *
      rtb_y_m;

    // Gain: '<S37>/Derivative Gain'
    fourwheelscontroller_B.DerivativeGain = fourwheelscontroller_P.g1slow_D *
      rtb_y_m;
  }

  // Gain: '<S46>/Filter Coefficient' incorporates:
  //   Integrator: '<S38>/Filter'
  //   Sum: '<S38>/SumD'

  fourwheelscontroller_B.FilterCoefficient =
    (fourwheelscontroller_B.DerivativeGain -
     fourwheelscontroller_X.Filter_CSTATE) * fourwheelscontroller_P.g1slow_N;

  // Sum: '<S52>/Sum' incorporates:
  //   Integrator: '<S43>/Integrator'

  rtb_Sum = (fourwheelscontroller_B.ProportionalGain +
             fourwheelscontroller_X.Integrator_CSTATE) +
    fourwheelscontroller_B.FilterCoefficient;

  // Saturate: '<S50>/Saturation'
  if (rtb_Sum > fourwheelscontroller_P.g1slow_UpperSaturationLimit) {
    rtb_Saturation = fourwheelscontroller_P.g1slow_UpperSaturationLimit;
  } else if (rtb_Sum < fourwheelscontroller_P.g1slow_LowerSaturationLimit) {
    rtb_Saturation = fourwheelscontroller_P.g1slow_LowerSaturationLimit;
  } else {
    rtb_Saturation = rtb_Sum;
  }

  // End of Saturate: '<S50>/Saturation'
  if (rtmIsMajorTimeStep(fourwheelscontroller_M)) {
    // Gain: '<S96>/Proportional Gain'
    fourwheelscontroller_B.ProportionalGain_l = fourwheelscontroller_P.g2fast_P *
      rtb_y_m;

    // Gain: '<S85>/Derivative Gain'
    fourwheelscontroller_B.DerivativeGain_l = fourwheelscontroller_P.g2fast_D *
      rtb_y_m;
  }

  // Gain: '<S94>/Filter Coefficient' incorporates:
  //   Integrator: '<S86>/Filter'
  //   Sum: '<S86>/SumD'

  fourwheelscontroller_B.FilterCoefficient_j =
    (fourwheelscontroller_B.DerivativeGain_l -
     fourwheelscontroller_X.Filter_CSTATE_i) * fourwheelscontroller_P.g2fast_N;

  // Sum: '<S100>/Sum' incorporates:
  //   Integrator: '<S91>/Integrator'

  rtb_Sum_a = (fourwheelscontroller_B.ProportionalGain_l +
               fourwheelscontroller_X.Integrator_CSTATE_k) +
    fourwheelscontroller_B.FilterCoefficient_j;

  // Saturate: '<S98>/Saturation'
  if (rtb_Sum_a > fourwheelscontroller_P.g2fast_UpperSaturationLimit) {
    rtb_Saturation_k = fourwheelscontroller_P.g2fast_UpperSaturationLimit;
  } else if (rtb_Sum_a < fourwheelscontroller_P.g2fast_LowerSaturationLimit) {
    rtb_Saturation_k = fourwheelscontroller_P.g2fast_LowerSaturationLimit;
  } else {
    rtb_Saturation_k = rtb_Sum_a;
  }

  // End of Saturate: '<S98>/Saturation'

  // MATLAB Function: '<Root>/MATLAB Function1' incorporates:
  //   Constant: '<Root>/Constant'

  if (fourwheelscontroller_B.In1_p.Data > fourwheelscontroller_B.In1.Data *
      fourwheelscontroller_P.Constant_Value_e) {
    tmp = rtb_Saturation;
  } else {
    tmp = rtb_Saturation_k;
  }

  // BusAssignment: '<Root>/Bus Assignment' incorporates:
  //   Gain: '<Root>/Gain'
  //   MATLAB Function: '<Root>/MATLAB Function1'

  rtb_BusAssignment.Data = fourwheelscontroller_P.Gain_Gain * tmp;

  // Outputs for Atomic SubSystem: '<Root>/Publish'
  // MATLABSystem: '<S5>/SinkBlock'
  Pub_fourwheelscontroller_10.publish(&rtb_BusAssignment);

  // End of Outputs for SubSystem: '<Root>/Publish'
  if (rtmIsMajorTimeStep(fourwheelscontroller_M)) {
    // Gain: '<S88>/Integral Gain'
    fourwheelscontroller_B.IntegralGain = fourwheelscontroller_P.g2fast_I *
      rtb_y_m;

    // Gain: '<S40>/Integral Gain'
    fourwheelscontroller_B.IntegralGain_g = fourwheelscontroller_P.g1slow_I *
      rtb_y_m;
  }

  // Sum: '<S84>/SumI4' incorporates:
  //   Gain: '<S84>/Kb'
  //   Sum: '<S84>/SumI2'

  fourwheelscontroller_B.SumI4 = (rtb_Saturation_k - rtb_Sum_a) *
    fourwheelscontroller_P.g2fast_Kb + fourwheelscontroller_B.IntegralGain;

  // Sum: '<S36>/SumI4' incorporates:
  //   Gain: '<S36>/Kb'
  //   Sum: '<S36>/SumI2'

  fourwheelscontroller_B.SumI4_f = (rtb_Saturation - rtb_Sum) *
    fourwheelscontroller_P.g1slow_Kb + fourwheelscontroller_B.IntegralGain_g;
  if (rtmIsMajorTimeStep(fourwheelscontroller_M)) {
    rt_ertODEUpdateContinuousStates(&fourwheelscontroller_M->solverInfo);

    // Update absolute time for base rate
    // The "clockTick0" counts the number of times the code of this task has
    //  been executed. The absolute time is the multiplication of "clockTick0"
    //  and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
    //  overflow during the application lifespan selected.

    ++fourwheelscontroller_M->Timing.clockTick0;
    fourwheelscontroller_M->Timing.t[0] = rtsiGetSolverStopTime
      (&fourwheelscontroller_M->solverInfo);

    {
      // Update absolute timer for sample time: [0.2s, 0.0s]
      // The "clockTick1" counts the number of times the code of this task has
      //  been executed. The resolution of this integer timer is 0.2, which is the step size
      //  of the task. Size of "clockTick1" ensures timer will not overflow during the
      //  application lifespan selected.

      fourwheelscontroller_M->Timing.clockTick1++;
    }
  }                                    // end MajorTimeStep
}

// Derivatives for root system: '<Root>'
void fourwheelscontroller_derivatives(void)
{
  XDot_fourwheelscontroller_T *_rtXdot;
  _rtXdot = ((XDot_fourwheelscontroller_T *) fourwheelscontroller_M->derivs);

  // Derivatives for Integrator: '<S43>/Integrator'
  _rtXdot->Integrator_CSTATE = fourwheelscontroller_B.SumI4_f;

  // Derivatives for Integrator: '<S38>/Filter'
  _rtXdot->Filter_CSTATE = fourwheelscontroller_B.FilterCoefficient;

  // Derivatives for Integrator: '<S91>/Integrator'
  _rtXdot->Integrator_CSTATE_k = fourwheelscontroller_B.SumI4;

  // Derivatives for Integrator: '<S86>/Filter'
  _rtXdot->Filter_CSTATE_i = fourwheelscontroller_B.FilterCoefficient_j;
}

// Model initialize function
void fourwheelscontroller_initialize(void)
{
  // Registration code
  {
    // Setup solver object
    rtsiSetSimTimeStepPtr(&fourwheelscontroller_M->solverInfo,
                          &fourwheelscontroller_M->Timing.simTimeStep);
    rtsiSetTPtr(&fourwheelscontroller_M->solverInfo, &rtmGetTPtr
                (fourwheelscontroller_M));
    rtsiSetStepSizePtr(&fourwheelscontroller_M->solverInfo,
                       &fourwheelscontroller_M->Timing.stepSize0);
    rtsiSetdXPtr(&fourwheelscontroller_M->solverInfo,
                 &fourwheelscontroller_M->derivs);
    rtsiSetContStatesPtr(&fourwheelscontroller_M->solverInfo, (real_T **)
                         &fourwheelscontroller_M->contStates);
    rtsiSetNumContStatesPtr(&fourwheelscontroller_M->solverInfo,
      &fourwheelscontroller_M->Sizes.numContStates);
    rtsiSetNumPeriodicContStatesPtr(&fourwheelscontroller_M->solverInfo,
      &fourwheelscontroller_M->Sizes.numPeriodicContStates);
    rtsiSetPeriodicContStateIndicesPtr(&fourwheelscontroller_M->solverInfo,
      &fourwheelscontroller_M->periodicContStateIndices);
    rtsiSetPeriodicContStateRangesPtr(&fourwheelscontroller_M->solverInfo,
      &fourwheelscontroller_M->periodicContStateRanges);
    rtsiSetContStateDisabledPtr(&fourwheelscontroller_M->solverInfo, (boolean_T**)
      &fourwheelscontroller_M->contStateDisabled);
    rtsiSetErrorStatusPtr(&fourwheelscontroller_M->solverInfo,
                          (&rtmGetErrorStatus(fourwheelscontroller_M)));
    rtsiSetRTModelPtr(&fourwheelscontroller_M->solverInfo,
                      fourwheelscontroller_M);
  }

  rtsiSetSimTimeStep(&fourwheelscontroller_M->solverInfo, MAJOR_TIME_STEP);
  fourwheelscontroller_M->intgData.y = fourwheelscontroller_M->odeY;
  fourwheelscontroller_M->intgData.f[0] = fourwheelscontroller_M->odeF[0];
  fourwheelscontroller_M->intgData.f[1] = fourwheelscontroller_M->odeF[1];
  fourwheelscontroller_M->intgData.f[2] = fourwheelscontroller_M->odeF[2];
  fourwheelscontroller_M->contStates = ((X_fourwheelscontroller_T *)
    &fourwheelscontroller_X);
  fourwheelscontroller_M->contStateDisabled = ((XDis_fourwheelscontroller_T *)
    &fourwheelscontroller_XDis);
  fourwheelscontroller_M->Timing.tStart = (0.0);
  rtsiSetSolverData(&fourwheelscontroller_M->solverInfo, static_cast<void *>
                    (&fourwheelscontroller_M->intgData));
  rtsiSetIsMinorTimeStepWithModeChange(&fourwheelscontroller_M->solverInfo,
    false);
  rtsiSetSolverName(&fourwheelscontroller_M->solverInfo,"ode3");
  rtmSetTPtr(fourwheelscontroller_M, &fourwheelscontroller_M->Timing.tArray[0]);
  fourwheelscontroller_M->Timing.stepSize0 = 0.2;

  {
    int32_T i;
    char_T b_zeroDelimTopic[17];
    char_T b_zeroDelimTopic_1[15];
    char_T b_zeroDelimTopic_0[11];
    static const char_T b_zeroDelimTopic_2[17] = "/car/state/vel_x";
    static const char_T b_zeroDelimTopic_3[11] = "/lead_dist";
    static const char_T b_zeroDelimTopic_4[15] = "/cmd_accel_sim";

    // InitializeConditions for Integrator: '<S43>/Integrator'
    fourwheelscontroller_X.Integrator_CSTATE =
      fourwheelscontroller_P.g1slow_InitialConditionForInteg;

    // InitializeConditions for Integrator: '<S38>/Filter'
    fourwheelscontroller_X.Filter_CSTATE =
      fourwheelscontroller_P.g1slow_InitialConditionForFilte;

    // InitializeConditions for Integrator: '<S91>/Integrator'
    fourwheelscontroller_X.Integrator_CSTATE_k =
      fourwheelscontroller_P.g2fast_InitialConditionForInteg;

    // InitializeConditions for Integrator: '<S86>/Filter'
    fourwheelscontroller_X.Filter_CSTATE_i =
      fourwheelscontroller_P.g2fast_InitialConditionForFilte;

    // SystemInitialize for Atomic SubSystem: '<Root>/Subscribe'
    // SystemInitialize for Enabled SubSystem: '<S6>/Enabled Subsystem'
    // SystemInitialize for SignalConversion generated from: '<S10>/In1' incorporates:
    //   Outport: '<S10>/Out1'

    fourwheelscontroller_B.In1_p = fourwheelscontroller_P.Out1_Y0;

    // End of SystemInitialize for SubSystem: '<S6>/Enabled Subsystem'

    // Start for MATLABSystem: '<S6>/SourceBlock'
    fourwheelscontroller_DW.obj_o.matlabCodegenIsDeleted = false;
    fourwheelscontroller_DW.obj_o.isInitialized = 1;
    for (i = 0; i < 17; i++) {
      b_zeroDelimTopic[i] = b_zeroDelimTopic_2[i];
    }

    Sub_fourwheelscontroller_11.createSubscriber(&b_zeroDelimTopic[0], 1);
    fourwheelscontroller_DW.obj_o.isSetupComplete = true;

    // End of Start for MATLABSystem: '<S6>/SourceBlock'
    // End of SystemInitialize for SubSystem: '<Root>/Subscribe'

    // SystemInitialize for Atomic SubSystem: '<Root>/Subscribe1'
    // SystemInitialize for Enabled SubSystem: '<S7>/Enabled Subsystem'
    // SystemInitialize for SignalConversion generated from: '<S11>/In1' incorporates:
    //   Outport: '<S11>/Out1'

    fourwheelscontroller_B.In1 = fourwheelscontroller_P.Out1_Y0_h;

    // End of SystemInitialize for SubSystem: '<S7>/Enabled Subsystem'

    // Start for MATLABSystem: '<S7>/SourceBlock'
    fourwheelscontroller_DW.obj_e.matlabCodegenIsDeleted = false;
    fourwheelscontroller_DW.obj_e.isInitialized = 1;
    for (i = 0; i < 11; i++) {
      b_zeroDelimTopic_0[i] = b_zeroDelimTopic_3[i];
    }

    Sub_fourwheelscontroller_12.createSubscriber(&b_zeroDelimTopic_0[0], 1);
    fourwheelscontroller_DW.obj_e.isSetupComplete = true;

    // End of Start for MATLABSystem: '<S7>/SourceBlock'
    // End of SystemInitialize for SubSystem: '<Root>/Subscribe1'

    // SystemInitialize for Atomic SubSystem: '<Root>/Publish'
    // Start for MATLABSystem: '<S5>/SinkBlock'
    fourwheelscontroller_DW.obj.matlabCodegenIsDeleted = false;
    fourwheelscontroller_DW.obj.isInitialized = 1;
    for (i = 0; i < 15; i++) {
      b_zeroDelimTopic_1[i] = b_zeroDelimTopic_4[i];
    }

    Pub_fourwheelscontroller_10.createPublisher(&b_zeroDelimTopic_1[0], 1);
    fourwheelscontroller_DW.obj.isSetupComplete = true;

    // End of Start for MATLABSystem: '<S5>/SinkBlock'
    // End of SystemInitialize for SubSystem: '<Root>/Publish'
  }
}

// Model terminate function
void fourwheelscontroller_terminate(void)
{
  // Terminate for Atomic SubSystem: '<Root>/Subscribe'
  // Terminate for MATLABSystem: '<S6>/SourceBlock'
  if (!fourwheelscontroller_DW.obj_o.matlabCodegenIsDeleted) {
    fourwheelscontroller_DW.obj_o.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S6>/SourceBlock'
  // End of Terminate for SubSystem: '<Root>/Subscribe'

  // Terminate for Atomic SubSystem: '<Root>/Subscribe1'
  // Terminate for MATLABSystem: '<S7>/SourceBlock'
  if (!fourwheelscontroller_DW.obj_e.matlabCodegenIsDeleted) {
    fourwheelscontroller_DW.obj_e.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S7>/SourceBlock'
  // End of Terminate for SubSystem: '<Root>/Subscribe1'

  // Terminate for Atomic SubSystem: '<Root>/Publish'
  // Terminate for MATLABSystem: '<S5>/SinkBlock'
  if (!fourwheelscontroller_DW.obj.matlabCodegenIsDeleted) {
    fourwheelscontroller_DW.obj.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S5>/SinkBlock'
  // End of Terminate for SubSystem: '<Root>/Publish'
}

//
// File trailer for generated code.
//
// [EOF]
//

//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: assignment4controller.cpp
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
#include "rtwtypes.h"
#include "assignment4controller_types.h"
#include "assignment4controller_private.h"

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
  int_T nXc = 4;
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

// Model step function
void assignment4controller_step(void)
{
  SL_Bus_assignment4controller_std_msgs_Float64 rtb_BusAssignment;
  real_T rtb_Saturation;
  real_T rtb_Saturation_e;
  real_T rtb_Sum;
  real_T rtb_Sum_i;
  real_T rtb_y_n;
  real_T tmp;
  boolean_T b_varargout_1;
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
    // MATLABSystem: '<S6>/SourceBlock'
    b_varargout_1 = Sub_assignment4controller_207.getLatestMessage
      (&assignment4controller_B.b_varargout_2);

    // Outputs for Enabled SubSystem: '<S6>/Enabled Subsystem' incorporates:
    //   EnablePort: '<S11>/Enable'

    // Start for MATLABSystem: '<S6>/SourceBlock'
    if (b_varargout_1) {
      // SignalConversion generated from: '<S11>/In1'
      assignment4controller_B.In1_b = assignment4controller_B.b_varargout_2;
    }

    // End of Start for MATLABSystem: '<S6>/SourceBlock'
    // End of Outputs for SubSystem: '<S6>/Enabled Subsystem'
    // End of Outputs for SubSystem: '<Root>/Subscribe'

    // Outputs for Atomic SubSystem: '<Root>/Subscribe2'
    // MATLABSystem: '<S8>/SourceBlock'
    b_varargout_1 = Sub_assignment4controller_209.getLatestMessage
      (&assignment4controller_B.b_varargout_2);

    // Outputs for Enabled SubSystem: '<S8>/Enabled Subsystem' incorporates:
    //   EnablePort: '<S13>/Enable'

    // Start for MATLABSystem: '<S8>/SourceBlock'
    if (b_varargout_1) {
      // SignalConversion generated from: '<S13>/In1'
      assignment4controller_B.In1 = assignment4controller_B.b_varargout_2;
    }

    // End of Start for MATLABSystem: '<S8>/SourceBlock'
    // End of Outputs for SubSystem: '<S8>/Enabled Subsystem'
    // End of Outputs for SubSystem: '<Root>/Subscribe2'

    // Outputs for Atomic SubSystem: '<Root>/Subscribe1'
    // MATLABSystem: '<S7>/SourceBlock'
    Sub_assignment4controller_208.getLatestMessage
      (&assignment4controller_B.b_varargout_2);

    // End of Outputs for SubSystem: '<Root>/Subscribe1'

    // MATLAB Function: '<Root>/MATLAB Function2'
    if (assignment4controller_B.In1_b.Data > 1.0) {
      assignment4controller_B.y = assignment4controller_B.In1.Data /
        assignment4controller_B.In1_b.Data;
    } else {
      assignment4controller_B.y = assignment4controller_B.In1.Data;
    }

    // End of MATLAB Function: '<Root>/MATLAB Function2'

    // MATLAB Function: '<Root>/MATLAB Function' incorporates:
    //   Constant: '<Root>/Constant'

    rtb_y_n = assignment4controller_B.y -
      assignment4controller_P.Constant_Value_ko;

    // Gain: '<S50>/Proportional Gain'
    assignment4controller_B.ProportionalGain = assignment4controller_P.g1slow_P *
      rtb_y_n;

    // Gain: '<S39>/Derivative Gain'
    assignment4controller_B.DerivativeGain = assignment4controller_P.g1slow_D *
      rtb_y_n;
  }

  // Gain: '<S48>/Filter Coefficient' incorporates:
  //   Integrator: '<S40>/Filter'
  //   Sum: '<S40>/SumD'

  assignment4controller_B.FilterCoefficient =
    (assignment4controller_B.DerivativeGain -
     assignment4controller_X.Filter_CSTATE) * assignment4controller_P.g1slow_N;

  // Sum: '<S54>/Sum' incorporates:
  //   Integrator: '<S45>/Integrator'

  rtb_Sum = (assignment4controller_B.ProportionalGain +
             assignment4controller_X.Integrator_CSTATE) +
    assignment4controller_B.FilterCoefficient;

  // Saturate: '<S52>/Saturation'
  if (rtb_Sum > assignment4controller_P.g1slow_UpperSaturationLimit) {
    rtb_Saturation = assignment4controller_P.g1slow_UpperSaturationLimit;
  } else if (rtb_Sum < assignment4controller_P.g1slow_LowerSaturationLimit) {
    rtb_Saturation = assignment4controller_P.g1slow_LowerSaturationLimit;
  } else {
    rtb_Saturation = rtb_Sum;
  }

  // End of Saturate: '<S52>/Saturation'
  if (rtmIsMajorTimeStep(assignment4controller_M)) {
    // Gain: '<S98>/Proportional Gain'
    assignment4controller_B.ProportionalGain_f =
      assignment4controller_P.g2fast_P * rtb_y_n;

    // Gain: '<S87>/Derivative Gain'
    assignment4controller_B.DerivativeGain_c = assignment4controller_P.g2fast_D *
      rtb_y_n;
  }

  // Gain: '<S96>/Filter Coefficient' incorporates:
  //   Integrator: '<S88>/Filter'
  //   Sum: '<S88>/SumD'

  assignment4controller_B.FilterCoefficient_o =
    (assignment4controller_B.DerivativeGain_c -
     assignment4controller_X.Filter_CSTATE_n) * assignment4controller_P.g2fast_N;

  // Sum: '<S102>/Sum' incorporates:
  //   Integrator: '<S93>/Integrator'

  rtb_Sum_i = (assignment4controller_B.ProportionalGain_f +
               assignment4controller_X.Integrator_CSTATE_k) +
    assignment4controller_B.FilterCoefficient_o;

  // Saturate: '<S100>/Saturation'
  if (rtb_Sum_i > assignment4controller_P.g2fast_UpperSaturationLimit) {
    rtb_Saturation_e = assignment4controller_P.g2fast_UpperSaturationLimit;
  } else if (rtb_Sum_i < assignment4controller_P.g2fast_LowerSaturationLimit) {
    rtb_Saturation_e = assignment4controller_P.g2fast_LowerSaturationLimit;
  } else {
    rtb_Saturation_e = rtb_Sum_i;
  }

  // End of Saturate: '<S100>/Saturation'

  // MATLAB Function: '<Root>/MATLAB Function1'
  if (assignment4controller_B.y > 7.0) {
    tmp = rtb_Saturation;
  } else {
    tmp = rtb_Saturation_e;
  }

  // BusAssignment: '<Root>/Bus Assignment' incorporates:
  //   Gain: '<Root>/Gain'
  //   MATLAB Function: '<Root>/MATLAB Function1'

  rtb_BusAssignment.Data = assignment4controller_P.Gain_Gain * tmp;

  // Outputs for Atomic SubSystem: '<Root>/Publish'
  // MATLABSystem: '<S5>/SinkBlock'
  Pub_assignment4controller_212.publish(&rtb_BusAssignment);

  // End of Outputs for SubSystem: '<Root>/Publish'
  if (rtmIsMajorTimeStep(assignment4controller_M)) {
    // Gain: '<S90>/Integral Gain'
    assignment4controller_B.IntegralGain = assignment4controller_P.g2fast_I *
      rtb_y_n;

    // Gain: '<S42>/Integral Gain'
    assignment4controller_B.IntegralGain_i = assignment4controller_P.g1slow_I *
      rtb_y_n;
  }

  // Sum: '<S86>/SumI4' incorporates:
  //   Gain: '<S86>/Kb'
  //   Sum: '<S86>/SumI2'

  assignment4controller_B.SumI4 = (rtb_Saturation_e - rtb_Sum_i) *
    assignment4controller_P.g2fast_Kb + assignment4controller_B.IntegralGain;

  // Sum: '<S38>/SumI4' incorporates:
  //   Gain: '<S38>/Kb'
  //   Sum: '<S38>/SumI2'

  assignment4controller_B.SumI4_d = (rtb_Saturation - rtb_Sum) *
    assignment4controller_P.g1slow_Kb + assignment4controller_B.IntegralGain_i;
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
      // Update absolute timer for sample time: [0.05s, 0.0s]
      // The "clockTick1" counts the number of times the code of this task has
      //  been executed. The resolution of this integer timer is 0.05, which is the step size
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

  // Derivatives for Integrator: '<S45>/Integrator'
  _rtXdot->Integrator_CSTATE = assignment4controller_B.SumI4_d;

  // Derivatives for Integrator: '<S40>/Filter'
  _rtXdot->Filter_CSTATE = assignment4controller_B.FilterCoefficient;

  // Derivatives for Integrator: '<S93>/Integrator'
  _rtXdot->Integrator_CSTATE_k = assignment4controller_B.SumI4;

  // Derivatives for Integrator: '<S88>/Filter'
  _rtXdot->Filter_CSTATE_n = assignment4controller_B.FilterCoefficient_o;
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
  assignment4controller_M->Timing.stepSize0 = 0.05;

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

    // InitializeConditions for Integrator: '<S45>/Integrator'
    assignment4controller_X.Integrator_CSTATE =
      assignment4controller_P.g1slow_InitialConditionForInteg;

    // InitializeConditions for Integrator: '<S40>/Filter'
    assignment4controller_X.Filter_CSTATE =
      assignment4controller_P.g1slow_InitialConditionForFilte;

    // InitializeConditions for Integrator: '<S93>/Integrator'
    assignment4controller_X.Integrator_CSTATE_k =
      assignment4controller_P.g2fast_InitialConditionForInteg;

    // InitializeConditions for Integrator: '<S88>/Filter'
    assignment4controller_X.Filter_CSTATE_n =
      assignment4controller_P.g2fast_InitialConditionForFilte;

    // SystemInitialize for Atomic SubSystem: '<Root>/Subscribe'
    // SystemInitialize for Enabled SubSystem: '<S6>/Enabled Subsystem'
    // SystemInitialize for SignalConversion generated from: '<S11>/In1' incorporates:
    //   Outport: '<S11>/Out1'

    assignment4controller_B.In1_b = assignment4controller_P.Out1_Y0;

    // End of SystemInitialize for SubSystem: '<S6>/Enabled Subsystem'

    // Start for MATLABSystem: '<S6>/SourceBlock'
    assignment4controller_DW.obj_f.matlabCodegenIsDeleted = false;
    assignment4controller_DW.obj_f.isInitialized = 1;
    for (i = 0; i < 17; i++) {
      b_zeroDelimTopic[i] = b_zeroDelimTopic_3[i];
    }

    Sub_assignment4controller_207.createSubscriber(&b_zeroDelimTopic[0], 1);
    assignment4controller_DW.obj_f.isSetupComplete = true;

    // End of Start for MATLABSystem: '<S6>/SourceBlock'
    // End of SystemInitialize for SubSystem: '<Root>/Subscribe'

    // SystemInitialize for Atomic SubSystem: '<Root>/Subscribe2'
    // SystemInitialize for Enabled SubSystem: '<S8>/Enabled Subsystem'
    // SystemInitialize for SignalConversion generated from: '<S13>/In1' incorporates:
    //   Outport: '<S13>/Out1'

    assignment4controller_B.In1 = assignment4controller_P.Out1_Y0_e;

    // End of SystemInitialize for SubSystem: '<S8>/Enabled Subsystem'

    // Start for MATLABSystem: '<S8>/SourceBlock'
    assignment4controller_DW.obj_c.matlabCodegenIsDeleted = false;
    assignment4controller_DW.obj_c.isInitialized = 1;
    for (i = 0; i < 11; i++) {
      b_zeroDelimTopic_0[i] = b_zeroDelimTopic_4[i];
    }

    Sub_assignment4controller_209.createSubscriber(&b_zeroDelimTopic_0[0], 1);
    assignment4controller_DW.obj_c.isSetupComplete = true;

    // End of Start for MATLABSystem: '<S8>/SourceBlock'
    // End of SystemInitialize for SubSystem: '<Root>/Subscribe2'

    // SystemInitialize for Atomic SubSystem: '<Root>/Subscribe1'
    // Start for MATLABSystem: '<S7>/SourceBlock'
    assignment4controller_DW.obj_i.matlabCodegenIsDeleted = false;
    assignment4controller_DW.obj_i.isInitialized = 1;
    for (i = 0; i < 9; i++) {
      b_zeroDelimTopic_1[i] = b_zeroDelimTopic_5[i];
    }

    Sub_assignment4controller_208.createSubscriber(&b_zeroDelimTopic_1[0], 1);
    assignment4controller_DW.obj_i.isSetupComplete = true;

    // End of Start for MATLABSystem: '<S7>/SourceBlock'
    // End of SystemInitialize for SubSystem: '<Root>/Subscribe1'

    // SystemInitialize for Atomic SubSystem: '<Root>/Publish'
    // Start for MATLABSystem: '<S5>/SinkBlock'
    assignment4controller_DW.obj.matlabCodegenIsDeleted = false;
    assignment4controller_DW.obj.isInitialized = 1;
    for (i = 0; i < 15; i++) {
      b_zeroDelimTopic_2[i] = b_zeroDelimTopic_6[i];
    }

    Pub_assignment4controller_212.createPublisher(&b_zeroDelimTopic_2[0], 1);
    assignment4controller_DW.obj.isSetupComplete = true;

    // End of Start for MATLABSystem: '<S5>/SinkBlock'
    // End of SystemInitialize for SubSystem: '<Root>/Publish'
  }
}

// Model terminate function
void assignment4controller_terminate(void)
{
  // Terminate for Atomic SubSystem: '<Root>/Subscribe'
  // Terminate for MATLABSystem: '<S6>/SourceBlock'
  if (!assignment4controller_DW.obj_f.matlabCodegenIsDeleted) {
    assignment4controller_DW.obj_f.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S6>/SourceBlock'
  // End of Terminate for SubSystem: '<Root>/Subscribe'

  // Terminate for Atomic SubSystem: '<Root>/Subscribe2'
  // Terminate for MATLABSystem: '<S8>/SourceBlock'
  if (!assignment4controller_DW.obj_c.matlabCodegenIsDeleted) {
    assignment4controller_DW.obj_c.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S8>/SourceBlock'
  // End of Terminate for SubSystem: '<Root>/Subscribe2'

  // Terminate for Atomic SubSystem: '<Root>/Subscribe1'
  // Terminate for MATLABSystem: '<S7>/SourceBlock'
  if (!assignment4controller_DW.obj_i.matlabCodegenIsDeleted) {
    assignment4controller_DW.obj_i.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S7>/SourceBlock'
  // End of Terminate for SubSystem: '<Root>/Subscribe1'

  // Terminate for Atomic SubSystem: '<Root>/Publish'
  // Terminate for MATLABSystem: '<S5>/SinkBlock'
  if (!assignment4controller_DW.obj.matlabCodegenIsDeleted) {
    assignment4controller_DW.obj.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S5>/SinkBlock'
  // End of Terminate for SubSystem: '<Root>/Publish'
}

//
// File trailer for generated code.
//
// [EOF]
//

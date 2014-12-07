/* Include files */

#include <stddef.h>
#include "blas.h"
#include "untitled2_sfun.h"
#include "c5_untitled2.h"
#include "mwmathutil.h"
#define CHARTINSTANCE_CHARTNUMBER      (chartInstance->chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER   (chartInstance->instanceNumber)
#include "untitled2_sfun_debug_macros.h"
#define _SF_MEX_LISTEN_FOR_CTRL_C(S)   sf_mex_listen_for_ctrl_c(sfGlobalDebugInstanceStruct,S);

/* Type Definitions */

/* Named Constants */
#define CALL_EVENT                     (-1)

/* Variable Declarations */

/* Variable Definitions */
static real_T _sfTime_;
static const char * c5_debug_family_names[21] = { "k1", "U1", "k2", "U2", "k3",
  "U3", "k4", "U4", "ddd", "Theta_bo", "Theta_wb", "nargin", "nargout", "NOISE",
  "ui", "U0", "h", "x", "x_next", "U", "Theta_wo" };

static const char * c5_b_debug_family_names[127] = { "L", "delta_max",
  "Ddelta_max", "n_max", "delta_c", "n_c", "u", "v", "p", "r", "phi", "psi",
  "delta", "n", "m", "mx", "my", "Ix", "alphay", "lx", "ly", "Iz", "Jx", "Jz",
  "xG", "B", "dF", "g", "dA", "d", "nabla", "KM", "KB", "AR", "Delta", "D", "GM",
  "rho", "t", "T", "W", "Xuu", "Xvr", "Xrr", "Xphiphi", "Xvv", "Kv", "Kr", "Kp",
  "Kphi", "Kvvv", "Krrr", "Kvvr", "Kvrr", "Kvvphi", "Kvphiphi", "Krrphi",
  "Krphiphi", "Yv", "Yr", "Yp", "Yphi", "Yvvv", "Yrrr", "Yvvr", "Yvrr", "Yvvphi",
  "Yvphiphi", "Yrrphi", "Yrphiphi", "Nv", "Nr", "Np", "Nphi", "Nvvv", "Nrrr",
  "Nvvr", "Nvrr", "Nvvphi", "Nvphiphi", "Nrrphi", "Nrphiphi", "kk", "epsilon",
  "xR", "wp", "tau", "xp", "cpv", "cpr", "ga", "cRr", "cRrrr", "cRrrv", "cRX",
  "aH", "zR", "xH", "m11", "m22", "m32", "m42", "m33", "m44", "delta_dot", "Tm",
  "n_dot", "vR", "uP", "J", "KT", "uR", "alphaR", "FN", "X", "Y", "K", "N",
  "detM", "nargin", "nargout", "x", "ui", "U0", "NOISE", "xdot", "U" };

/* Function Declarations */
static void initialize_c5_untitled2(SFc5_untitled2InstanceStruct *chartInstance);
static void initialize_params_c5_untitled2(SFc5_untitled2InstanceStruct
  *chartInstance);
static void enable_c5_untitled2(SFc5_untitled2InstanceStruct *chartInstance);
static void disable_c5_untitled2(SFc5_untitled2InstanceStruct *chartInstance);
static void c5_update_debugger_state_c5_untitled2(SFc5_untitled2InstanceStruct
  *chartInstance);
static const mxArray *get_sim_state_c5_untitled2(SFc5_untitled2InstanceStruct
  *chartInstance);
static void set_sim_state_c5_untitled2(SFc5_untitled2InstanceStruct
  *chartInstance, const mxArray *c5_st);
static void finalize_c5_untitled2(SFc5_untitled2InstanceStruct *chartInstance);
static void sf_gateway_c5_untitled2(SFc5_untitled2InstanceStruct *chartInstance);
static void c5_chartstep_c5_untitled2(SFc5_untitled2InstanceStruct
  *chartInstance);
static void initSimStructsc5_untitled2(SFc5_untitled2InstanceStruct
  *chartInstance);
static void c5_container(SFc5_untitled2InstanceStruct *chartInstance, real_T
  c5_x[10], real_T c5_ui, real_T c5_b_U0, real_T c5_NOISE[2], real_T c5_xdot[10],
  real_T *c5_U);
static void init_script_number_translation(uint32_T c5_machineNumber, uint32_T
  c5_chartNumber, uint32_T c5_instanceNumber);
static const mxArray *c5_sf_marshallOut(void *chartInstanceVoid, void *c5_inData);
static real_T c5_emlrt_marshallIn(SFc5_untitled2InstanceStruct *chartInstance,
  const mxArray *c5_Theta_wo, const char_T *c5_identifier);
static real_T c5_b_emlrt_marshallIn(SFc5_untitled2InstanceStruct *chartInstance,
  const mxArray *c5_u, const emlrtMsgIdentifier *c5_parentId);
static void c5_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c5_mxArrayInData, const char_T *c5_varName, void *c5_outData);
static const mxArray *c5_b_sf_marshallOut(void *chartInstanceVoid, void
  *c5_inData);
static void c5_c_emlrt_marshallIn(SFc5_untitled2InstanceStruct *chartInstance,
  const mxArray *c5_x_next, const char_T *c5_identifier, real_T c5_y[10]);
static void c5_d_emlrt_marshallIn(SFc5_untitled2InstanceStruct *chartInstance,
  const mxArray *c5_u, const emlrtMsgIdentifier *c5_parentId, real_T c5_y[10]);
static void c5_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c5_mxArrayInData, const char_T *c5_varName, void *c5_outData);
static const mxArray *c5_c_sf_marshallOut(void *chartInstanceVoid, void
  *c5_inData);
static void c5_e_emlrt_marshallIn(SFc5_untitled2InstanceStruct *chartInstance,
  const mxArray *c5_u, const emlrtMsgIdentifier *c5_parentId, real_T c5_y[2]);
static void c5_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c5_mxArrayInData, const char_T *c5_varName, void *c5_outData);
static void c5_info_helper(const mxArray **c5_info);
static const mxArray *c5_emlrt_marshallOut(const char * c5_u);
static const mxArray *c5_b_emlrt_marshallOut(const uint32_T c5_u);
static real_T c5_mpower(SFc5_untitled2InstanceStruct *chartInstance, real_T c5_a);
static void c5_eml_scalar_eg(SFc5_untitled2InstanceStruct *chartInstance);
static real_T c5_sqrt(SFc5_untitled2InstanceStruct *chartInstance, real_T c5_x);
static void c5_eml_error(SFc5_untitled2InstanceStruct *chartInstance);
static real_T c5_abs(SFc5_untitled2InstanceStruct *chartInstance, real_T c5_x);
static real_T c5_sign(SFc5_untitled2InstanceStruct *chartInstance, real_T c5_x);
static real_T c5_b_mpower(SFc5_untitled2InstanceStruct *chartInstance, real_T
  c5_a);
static const mxArray *c5_d_sf_marshallOut(void *chartInstanceVoid, void
  *c5_inData);
static int32_T c5_f_emlrt_marshallIn(SFc5_untitled2InstanceStruct *chartInstance,
  const mxArray *c5_u, const emlrtMsgIdentifier *c5_parentId);
static void c5_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c5_mxArrayInData, const char_T *c5_varName, void *c5_outData);
static uint8_T c5_g_emlrt_marshallIn(SFc5_untitled2InstanceStruct *chartInstance,
  const mxArray *c5_b_is_active_c5_untitled2, const char_T *c5_identifier);
static uint8_T c5_h_emlrt_marshallIn(SFc5_untitled2InstanceStruct *chartInstance,
  const mxArray *c5_u, const emlrtMsgIdentifier *c5_parentId);
static void c5_b_sqrt(SFc5_untitled2InstanceStruct *chartInstance, real_T *c5_x);
static void c5_b_sign(SFc5_untitled2InstanceStruct *chartInstance, real_T *c5_x);
static void init_dsm_address_info(SFc5_untitled2InstanceStruct *chartInstance);

/* Function Definitions */
static void initialize_c5_untitled2(SFc5_untitled2InstanceStruct *chartInstance)
{
  chartInstance->c5_sfEvent = CALL_EVENT;
  _sfTime_ = sf_get_time(chartInstance->S);
  chartInstance->c5_is_active_c5_untitled2 = 0U;
}

static void initialize_params_c5_untitled2(SFc5_untitled2InstanceStruct
  *chartInstance)
{
  real_T c5_d0;
  real_T c5_d1;
  sf_mex_import_named("U0", sf_mex_get_sfun_param(chartInstance->S, 0, 0),
                      &c5_d0, 0, 0, 0U, 0, 0U, 0);
  chartInstance->c5_U0 = c5_d0;
  sf_mex_import_named("h", sf_mex_get_sfun_param(chartInstance->S, 1, 0), &c5_d1,
                      0, 0, 0U, 0, 0U, 0);
  chartInstance->c5_h = c5_d1;
}

static void enable_c5_untitled2(SFc5_untitled2InstanceStruct *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void disable_c5_untitled2(SFc5_untitled2InstanceStruct *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void c5_update_debugger_state_c5_untitled2(SFc5_untitled2InstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static const mxArray *get_sim_state_c5_untitled2(SFc5_untitled2InstanceStruct
  *chartInstance)
{
  const mxArray *c5_st;
  const mxArray *c5_y = NULL;
  real_T c5_hoistedGlobal;
  real_T c5_u;
  const mxArray *c5_b_y = NULL;
  real_T c5_b_hoistedGlobal;
  real_T c5_b_u;
  const mxArray *c5_c_y = NULL;
  int32_T c5_i0;
  real_T c5_c_u[10];
  const mxArray *c5_d_y = NULL;
  uint8_T c5_c_hoistedGlobal;
  uint8_T c5_d_u;
  const mxArray *c5_e_y = NULL;
  real_T *c5_Theta_wo;
  real_T *c5_U;
  real_T (*c5_x_next)[10];
  c5_Theta_wo = (real_T *)ssGetOutputPortSignal(chartInstance->S, 3);
  c5_U = (real_T *)ssGetOutputPortSignal(chartInstance->S, 2);
  c5_x_next = (real_T (*)[10])ssGetOutputPortSignal(chartInstance->S, 1);
  c5_st = NULL;
  c5_st = NULL;
  c5_y = NULL;
  sf_mex_assign(&c5_y, sf_mex_createcellmatrix(4, 1), false);
  c5_hoistedGlobal = *c5_Theta_wo;
  c5_u = c5_hoistedGlobal;
  c5_b_y = NULL;
  sf_mex_assign(&c5_b_y, sf_mex_create("y", &c5_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c5_y, 0, c5_b_y);
  c5_b_hoistedGlobal = *c5_U;
  c5_b_u = c5_b_hoistedGlobal;
  c5_c_y = NULL;
  sf_mex_assign(&c5_c_y, sf_mex_create("y", &c5_b_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c5_y, 1, c5_c_y);
  for (c5_i0 = 0; c5_i0 < 10; c5_i0++) {
    c5_c_u[c5_i0] = (*c5_x_next)[c5_i0];
  }

  c5_d_y = NULL;
  sf_mex_assign(&c5_d_y, sf_mex_create("y", c5_c_u, 0, 0U, 1U, 0U, 1, 10), false);
  sf_mex_setcell(c5_y, 2, c5_d_y);
  c5_c_hoistedGlobal = chartInstance->c5_is_active_c5_untitled2;
  c5_d_u = c5_c_hoistedGlobal;
  c5_e_y = NULL;
  sf_mex_assign(&c5_e_y, sf_mex_create("y", &c5_d_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c5_y, 3, c5_e_y);
  sf_mex_assign(&c5_st, c5_y, false);
  return c5_st;
}

static void set_sim_state_c5_untitled2(SFc5_untitled2InstanceStruct
  *chartInstance, const mxArray *c5_st)
{
  const mxArray *c5_u;
  real_T c5_dv0[10];
  int32_T c5_i1;
  real_T *c5_Theta_wo;
  real_T *c5_U;
  real_T (*c5_x_next)[10];
  c5_Theta_wo = (real_T *)ssGetOutputPortSignal(chartInstance->S, 3);
  c5_U = (real_T *)ssGetOutputPortSignal(chartInstance->S, 2);
  c5_x_next = (real_T (*)[10])ssGetOutputPortSignal(chartInstance->S, 1);
  chartInstance->c5_doneDoubleBufferReInit = true;
  c5_u = sf_mex_dup(c5_st);
  *c5_Theta_wo = c5_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell
    (c5_u, 0)), "Theta_wo");
  *c5_U = c5_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c5_u, 1)),
    "U");
  c5_c_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c5_u, 2)),
                        "x_next", c5_dv0);
  for (c5_i1 = 0; c5_i1 < 10; c5_i1++) {
    (*c5_x_next)[c5_i1] = c5_dv0[c5_i1];
  }

  chartInstance->c5_is_active_c5_untitled2 = c5_g_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c5_u, 3)), "is_active_c5_untitled2");
  sf_mex_destroy(&c5_u);
  c5_update_debugger_state_c5_untitled2(chartInstance);
  sf_mex_destroy(&c5_st);
}

static void finalize_c5_untitled2(SFc5_untitled2InstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void sf_gateway_c5_untitled2(SFc5_untitled2InstanceStruct *chartInstance)
{
  int32_T c5_i2;
  int32_T c5_i3;
  int32_T c5_i4;
  real_T *c5_ui;
  real_T *c5_U;
  real_T *c5_Theta_wo;
  real_T (*c5_x)[10];
  real_T (*c5_x_next)[10];
  real_T (*c5_NOISE)[2];
  c5_x = (real_T (*)[10])ssGetInputPortSignal(chartInstance->S, 2);
  c5_Theta_wo = (real_T *)ssGetOutputPortSignal(chartInstance->S, 3);
  c5_U = (real_T *)ssGetOutputPortSignal(chartInstance->S, 2);
  c5_ui = (real_T *)ssGetInputPortSignal(chartInstance->S, 1);
  c5_x_next = (real_T (*)[10])ssGetOutputPortSignal(chartInstance->S, 1);
  c5_NOISE = (real_T (*)[2])ssGetInputPortSignal(chartInstance->S, 0);
  _SFD_SYMBOL_SCOPE_PUSH(0U, 0U);
  _sfTime_ = sf_get_time(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 4U, chartInstance->c5_sfEvent);
  for (c5_i2 = 0; c5_i2 < 2; c5_i2++) {
    _SFD_DATA_RANGE_CHECK((*c5_NOISE)[c5_i2], 0U);
  }

  chartInstance->c5_sfEvent = CALL_EVENT;
  c5_chartstep_c5_untitled2(chartInstance);
  _SFD_SYMBOL_SCOPE_POP();
  _SFD_CHECK_FOR_STATE_INCONSISTENCY(_untitled2MachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
  for (c5_i3 = 0; c5_i3 < 10; c5_i3++) {
    _SFD_DATA_RANGE_CHECK((*c5_x_next)[c5_i3], 1U);
  }

  _SFD_DATA_RANGE_CHECK(*c5_ui, 2U);
  _SFD_DATA_RANGE_CHECK(*c5_U, 3U);
  _SFD_DATA_RANGE_CHECK(*c5_Theta_wo, 4U);
  _SFD_DATA_RANGE_CHECK(chartInstance->c5_U0, 5U);
  _SFD_DATA_RANGE_CHECK(chartInstance->c5_h, 6U);
  for (c5_i4 = 0; c5_i4 < 10; c5_i4++) {
    _SFD_DATA_RANGE_CHECK((*c5_x)[c5_i4], 7U);
  }
}

static void c5_chartstep_c5_untitled2(SFc5_untitled2InstanceStruct
  *chartInstance)
{
  real_T c5_hoistedGlobal;
  real_T c5_b_hoistedGlobal;
  real_T c5_c_hoistedGlobal;
  int32_T c5_i5;
  real_T c5_NOISE[2];
  real_T c5_ui;
  real_T c5_b_U0;
  real_T c5_b_h;
  int32_T c5_i6;
  real_T c5_x[10];
  uint32_T c5_debug_family_var_map[21];
  real_T c5_k1[10];
  real_T c5_U1;
  real_T c5_k2[10];
  real_T c5_U2;
  real_T c5_k3[10];
  real_T c5_U3;
  real_T c5_k4[10];
  real_T c5_U4;
  real_T c5_ddd[10];
  real_T c5_Theta_bo;
  real_T c5_Theta_wb;
  real_T c5_nargin = 5.0;
  real_T c5_nargout = 3.0;
  real_T c5_x_next[10];
  real_T c5_U;
  real_T c5_Theta_wo;
  int32_T c5_i7;
  real_T c5_b_x[10];
  int32_T c5_i8;
  real_T c5_b_NOISE[2];
  real_T c5_b_U1;
  real_T c5_b_k1[10];
  int32_T c5_i9;
  real_T c5_A;
  real_T c5_c_x;
  real_T c5_d_x;
  real_T c5_e_x;
  real_T c5_y;
  real_T c5_a;
  int32_T c5_i10;
  int32_T c5_i11;
  int32_T c5_i12;
  real_T c5_f_x[10];
  int32_T c5_i13;
  real_T c5_c_NOISE[2];
  real_T c5_b_U2;
  int32_T c5_i14;
  real_T c5_b_A;
  real_T c5_g_x;
  real_T c5_h_x;
  real_T c5_i_x;
  real_T c5_b_y;
  real_T c5_b_a;
  int32_T c5_i15;
  int32_T c5_i16;
  int32_T c5_i17;
  real_T c5_j_x[10];
  int32_T c5_i18;
  real_T c5_d_NOISE[2];
  real_T c5_b_U3;
  int32_T c5_i19;
  real_T c5_c_a;
  int32_T c5_i20;
  int32_T c5_i21;
  int32_T c5_i22;
  real_T c5_k_x[10];
  int32_T c5_i23;
  real_T c5_e_NOISE[2];
  real_T c5_b_U4;
  int32_T c5_i24;
  int32_T c5_i25;
  int32_T c5_i26;
  int32_T c5_i27;
  real_T c5_b[10];
  int32_T c5_i28;
  real_T c5_d_a;
  int32_T c5_i29;
  int32_T c5_i30;
  int32_T c5_i31;
  int32_T c5_i32;
  int32_T c5_i33;
  int32_T c5_i34;
  int32_T c5_i35;
  int32_T c5_i36;
  int32_T c5_i37;
  int32_T c5_i38;
  int32_T c5_i39;
  real_T c5_u[10];
  const mxArray *c5_c_y = NULL;
  real_T c5_c_A;
  real_T c5_l_x;
  real_T c5_m_x;
  real_T c5_n_x;
  real_T c5_d_A;
  real_T c5_B;
  real_T c5_o_x;
  real_T c5_d_y;
  real_T c5_p_x;
  real_T c5_e_y;
  real_T c5_q_x;
  real_T c5_f_y;
  real_T c5_g_y;
  real_T c5_r_x;
  real_T c5_s_x;
  real_T c5_e_A;
  real_T c5_b_B;
  real_T c5_t_x;
  real_T c5_h_y;
  real_T c5_u_x;
  real_T c5_i_y;
  real_T c5_v_x;
  real_T c5_j_y;
  real_T c5_k_y;
  real_T c5_w_x;
  real_T c5_x_x;
  int32_T c5_i40;
  real_T *c5_b_Theta_wo;
  real_T *c5_b_U;
  real_T *c5_b_ui;
  real_T (*c5_b_x_next)[10];
  real_T (*c5_y_x)[10];
  real_T (*c5_f_NOISE)[2];
  c5_y_x = (real_T (*)[10])ssGetInputPortSignal(chartInstance->S, 2);
  c5_b_Theta_wo = (real_T *)ssGetOutputPortSignal(chartInstance->S, 3);
  c5_b_U = (real_T *)ssGetOutputPortSignal(chartInstance->S, 2);
  c5_b_ui = (real_T *)ssGetInputPortSignal(chartInstance->S, 1);
  c5_b_x_next = (real_T (*)[10])ssGetOutputPortSignal(chartInstance->S, 1);
  c5_f_NOISE = (real_T (*)[2])ssGetInputPortSignal(chartInstance->S, 0);
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 4U, chartInstance->c5_sfEvent);
  c5_hoistedGlobal = *c5_b_ui;
  c5_b_hoistedGlobal = chartInstance->c5_U0;
  c5_c_hoistedGlobal = chartInstance->c5_h;
  for (c5_i5 = 0; c5_i5 < 2; c5_i5++) {
    c5_NOISE[c5_i5] = (*c5_f_NOISE)[c5_i5];
  }

  c5_ui = c5_hoistedGlobal;
  c5_b_U0 = c5_b_hoistedGlobal;
  c5_b_h = c5_c_hoistedGlobal;
  for (c5_i6 = 0; c5_i6 < 10; c5_i6++) {
    c5_x[c5_i6] = (*c5_y_x)[c5_i6];
  }

  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 21U, 21U, c5_debug_family_names,
    c5_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c5_k1, 0U, c5_b_sf_marshallOut,
    c5_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c5_U1, 1U, c5_sf_marshallOut,
    c5_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c5_k2, 2U, c5_b_sf_marshallOut,
    c5_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c5_U2, 3U, c5_sf_marshallOut,
    c5_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c5_k3, 4U, c5_b_sf_marshallOut,
    c5_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c5_U3, 5U, c5_sf_marshallOut,
    c5_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c5_k4, 6U, c5_b_sf_marshallOut,
    c5_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c5_U4, 7U, c5_sf_marshallOut,
    c5_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c5_ddd, 8U, c5_b_sf_marshallOut,
    c5_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c5_Theta_bo, 9U, c5_sf_marshallOut,
    c5_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c5_Theta_wb, 10U, c5_sf_marshallOut,
    c5_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c5_nargin, 11U, c5_sf_marshallOut,
    c5_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c5_nargout, 12U, c5_sf_marshallOut,
    c5_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c5_NOISE, 13U, c5_c_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c5_ui, 14U, c5_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c5_b_U0, 15U, c5_sf_marshallOut,
    c5_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c5_b_h, 16U, c5_sf_marshallOut,
    c5_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c5_x, 17U, c5_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c5_x_next, 18U, c5_b_sf_marshallOut,
    c5_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c5_U, 19U, c5_sf_marshallOut,
    c5_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c5_Theta_wo, 20U, c5_sf_marshallOut,
    c5_sf_marshallIn);
  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, 18);
  for (c5_i7 = 0; c5_i7 < 10; c5_i7++) {
    c5_b_x[c5_i7] = c5_x[c5_i7];
  }

  for (c5_i8 = 0; c5_i8 < 2; c5_i8++) {
    c5_b_NOISE[c5_i8] = c5_NOISE[c5_i8];
  }

  c5_container(chartInstance, c5_b_x, c5_ui, c5_b_U0, c5_b_NOISE, c5_b_k1,
               &c5_b_U1);
  for (c5_i9 = 0; c5_i9 < 10; c5_i9++) {
    c5_k1[c5_i9] = c5_b_k1[c5_i9];
  }

  c5_U1 = c5_b_U1;
  _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, 19);
  c5_A = c5_b_h;
  c5_c_x = c5_A;
  c5_d_x = c5_c_x;
  c5_e_x = c5_d_x;
  c5_y = c5_e_x / 2.0;
  c5_a = c5_y;
  for (c5_i10 = 0; c5_i10 < 10; c5_i10++) {
    c5_b_k1[c5_i10] = c5_k1[c5_i10];
  }

  for (c5_i11 = 0; c5_i11 < 10; c5_i11++) {
    c5_b_k1[c5_i11] *= c5_a;
  }

  for (c5_i12 = 0; c5_i12 < 10; c5_i12++) {
    c5_f_x[c5_i12] = c5_x[c5_i12] + c5_b_k1[c5_i12];
  }

  for (c5_i13 = 0; c5_i13 < 2; c5_i13++) {
    c5_c_NOISE[c5_i13] = c5_NOISE[c5_i13];
  }

  c5_container(chartInstance, c5_f_x, c5_ui, c5_b_U0, c5_c_NOISE, c5_b_k1,
               &c5_b_U2);
  for (c5_i14 = 0; c5_i14 < 10; c5_i14++) {
    c5_k2[c5_i14] = c5_b_k1[c5_i14];
  }

  c5_U2 = c5_b_U2;
  _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, 20);
  c5_b_A = c5_b_h;
  c5_g_x = c5_b_A;
  c5_h_x = c5_g_x;
  c5_i_x = c5_h_x;
  c5_b_y = c5_i_x / 2.0;
  c5_b_a = c5_b_y;
  for (c5_i15 = 0; c5_i15 < 10; c5_i15++) {
    c5_b_k1[c5_i15] = c5_k2[c5_i15];
  }

  for (c5_i16 = 0; c5_i16 < 10; c5_i16++) {
    c5_b_k1[c5_i16] *= c5_b_a;
  }

  for (c5_i17 = 0; c5_i17 < 10; c5_i17++) {
    c5_j_x[c5_i17] = c5_x[c5_i17] + c5_b_k1[c5_i17];
  }

  for (c5_i18 = 0; c5_i18 < 2; c5_i18++) {
    c5_d_NOISE[c5_i18] = c5_NOISE[c5_i18];
  }

  c5_container(chartInstance, c5_j_x, c5_ui, c5_b_U0, c5_d_NOISE, c5_b_k1,
               &c5_b_U3);
  for (c5_i19 = 0; c5_i19 < 10; c5_i19++) {
    c5_k3[c5_i19] = c5_b_k1[c5_i19];
  }

  c5_U3 = c5_b_U3;
  _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, 21);
  c5_c_a = c5_b_h;
  for (c5_i20 = 0; c5_i20 < 10; c5_i20++) {
    c5_b_k1[c5_i20] = c5_k3[c5_i20];
  }

  for (c5_i21 = 0; c5_i21 < 10; c5_i21++) {
    c5_b_k1[c5_i21] *= c5_c_a;
  }

  for (c5_i22 = 0; c5_i22 < 10; c5_i22++) {
    c5_k_x[c5_i22] = c5_x[c5_i22] + c5_b_k1[c5_i22];
  }

  for (c5_i23 = 0; c5_i23 < 2; c5_i23++) {
    c5_e_NOISE[c5_i23] = c5_NOISE[c5_i23];
  }

  c5_container(chartInstance, c5_k_x, c5_ui, c5_b_U0, c5_e_NOISE, c5_b_k1,
               &c5_b_U4);
  for (c5_i24 = 0; c5_i24 < 10; c5_i24++) {
    c5_k4[c5_i24] = c5_b_k1[c5_i24];
  }

  c5_U4 = c5_b_U4;
  _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, 22);
  for (c5_i25 = 0; c5_i25 < 10; c5_i25++) {
    c5_b_k1[c5_i25] = c5_k2[c5_i25];
  }

  for (c5_i26 = 0; c5_i26 < 10; c5_i26++) {
    c5_b_k1[c5_i26] *= 2.0;
  }

  for (c5_i27 = 0; c5_i27 < 10; c5_i27++) {
    c5_b[c5_i27] = c5_k3[c5_i27];
  }

  for (c5_i28 = 0; c5_i28 < 10; c5_i28++) {
    c5_b[c5_i28] *= 2.0;
  }

  c5_d_a = c5_b_h;
  for (c5_i29 = 0; c5_i29 < 10; c5_i29++) {
    c5_b_k1[c5_i29] = ((c5_k1[c5_i29] + c5_b_k1[c5_i29]) + c5_b[c5_i29]) +
      c5_k4[c5_i29];
  }

  for (c5_i30 = 0; c5_i30 < 10; c5_i30++) {
    c5_b_k1[c5_i30] *= c5_d_a;
  }

  for (c5_i31 = 0; c5_i31 < 10; c5_i31++) {
    c5_b_k1[c5_i31] /= 6.0;
  }

  for (c5_i32 = 0; c5_i32 < 10; c5_i32++) {
    c5_x_next[c5_i32] = c5_x[c5_i32] + c5_b_k1[c5_i32];
  }

  _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, 23);
  for (c5_i33 = 0; c5_i33 < 10; c5_i33++) {
    c5_b_k1[c5_i33] = c5_k2[c5_i33];
  }

  for (c5_i34 = 0; c5_i34 < 10; c5_i34++) {
    c5_b_k1[c5_i34] *= 2.0;
  }

  for (c5_i35 = 0; c5_i35 < 10; c5_i35++) {
    c5_b[c5_i35] = c5_k3[c5_i35];
  }

  for (c5_i36 = 0; c5_i36 < 10; c5_i36++) {
    c5_b[c5_i36] *= 2.0;
  }

  for (c5_i37 = 0; c5_i37 < 10; c5_i37++) {
    c5_b_k1[c5_i37] = ((c5_k1[c5_i37] + c5_b_k1[c5_i37]) + c5_b[c5_i37]) +
      c5_k4[c5_i37];
  }

  for (c5_i38 = 0; c5_i38 < 10; c5_i38++) {
    c5_ddd[c5_i38] = c5_b_k1[c5_i38] / 6.0;
  }

  sf_mex_printf("%s =\\n", "ddd");
  for (c5_i39 = 0; c5_i39 < 10; c5_i39++) {
    c5_u[c5_i39] = c5_ddd[c5_i39];
  }

  c5_c_y = NULL;
  sf_mex_assign(&c5_c_y, sf_mex_create("y", c5_u, 0, 0U, 1U, 0U, 1, 10), false);
  sf_mex_call_debug(sfGlobalDebugInstanceStruct, "disp", 0U, 1U, 14, c5_c_y);
  _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, 24);
  c5_c_A = ((c5_U1 + 2.0 * c5_U2) + 2.0 * c5_U3) + c5_U4;
  c5_l_x = c5_c_A;
  c5_m_x = c5_l_x;
  c5_n_x = c5_m_x;
  c5_U = c5_n_x / 6.0;
  _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, 25);
  c5_Theta_bo = c5_x_next[5];
  _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, 26);
  c5_d_A = c5_x_next[1];
  c5_B = c5_U;
  c5_o_x = c5_d_A;
  c5_d_y = c5_B;
  c5_p_x = c5_o_x;
  c5_e_y = c5_d_y;
  c5_q_x = c5_p_x;
  c5_f_y = c5_e_y;
  c5_g_y = c5_q_x / c5_f_y;
  c5_r_x = c5_g_y;
  c5_Theta_wb = c5_r_x;
  c5_s_x = c5_Theta_wb;
  c5_Theta_wb = c5_s_x;
  c5_Theta_wb = muDoubleScalarAtan(c5_Theta_wb);
  _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, 27);
  c5_e_A = c5_x_next[1];
  c5_b_B = c5_U;
  c5_t_x = c5_e_A;
  c5_h_y = c5_b_B;
  c5_u_x = c5_t_x;
  c5_i_y = c5_h_y;
  c5_v_x = c5_u_x;
  c5_j_y = c5_i_y;
  c5_k_y = c5_v_x / c5_j_y;
  c5_w_x = c5_k_y;
  c5_x_x = c5_w_x;
  c5_x_x = muDoubleScalarAtan(c5_x_x);
  c5_Theta_wo = c5_x_x + c5_Theta_bo;
  _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, -27);
  _SFD_SYMBOL_SCOPE_POP();
  for (c5_i40 = 0; c5_i40 < 10; c5_i40++) {
    (*c5_b_x_next)[c5_i40] = c5_x_next[c5_i40];
  }

  *c5_b_U = c5_U;
  *c5_b_Theta_wo = c5_Theta_wo;
  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 4U, chartInstance->c5_sfEvent);
}

static void initSimStructsc5_untitled2(SFc5_untitled2InstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void c5_container(SFc5_untitled2InstanceStruct *chartInstance, real_T
  c5_x[10], real_T c5_ui, real_T c5_b_U0, real_T c5_NOISE[2], real_T c5_xdot[10],
  real_T *c5_U)
{
  uint32_T c5_debug_family_var_map[127];
  real_T c5_L;
  real_T c5_delta_max;
  real_T c5_Ddelta_max;
  real_T c5_n_max;
  real_T c5_delta_c;
  real_T c5_n_c;
  real_T c5_u;
  real_T c5_v;
  real_T c5_p;
  real_T c5_r;
  real_T c5_phi;
  real_T c5_psi;
  real_T c5_delta;
  real_T c5_n;
  real_T c5_m;
  real_T c5_mx;
  real_T c5_my;
  real_T c5_Ix;
  real_T c5_alphay;
  real_T c5_lx;
  real_T c5_ly;
  real_T c5_Iz;
  real_T c5_Jx;
  real_T c5_Jz;
  real_T c5_xG;
  real_T c5_B;
  real_T c5_dF;
  real_T c5_g;
  real_T c5_dA;
  real_T c5_d;
  real_T c5_nabla;
  real_T c5_KM;
  real_T c5_KB;
  real_T c5_AR;
  real_T c5_Delta;
  real_T c5_D;
  real_T c5_GM;
  real_T c5_rho;
  real_T c5_t;
  real_T c5_T;
  real_T c5_W;
  real_T c5_Xuu;
  real_T c5_Xvr;
  real_T c5_Xrr;
  real_T c5_Xphiphi;
  real_T c5_Xvv;
  real_T c5_Kv;
  real_T c5_Kr;
  real_T c5_Kp;
  real_T c5_Kphi;
  real_T c5_Kvvv;
  real_T c5_Krrr;
  real_T c5_Kvvr;
  real_T c5_Kvrr;
  real_T c5_Kvvphi;
  real_T c5_Kvphiphi;
  real_T c5_Krrphi;
  real_T c5_Krphiphi;
  real_T c5_Yv;
  real_T c5_Yr;
  real_T c5_Yp;
  real_T c5_Yphi;
  real_T c5_Yvvv;
  real_T c5_Yrrr;
  real_T c5_Yvvr;
  real_T c5_Yvrr;
  real_T c5_Yvvphi;
  real_T c5_Yvphiphi;
  real_T c5_Yrrphi;
  real_T c5_Yrphiphi;
  real_T c5_Nv;
  real_T c5_Nr;
  real_T c5_Np;
  real_T c5_Nphi;
  real_T c5_Nvvv;
  real_T c5_Nrrr;
  real_T c5_Nvvr;
  real_T c5_Nvrr;
  real_T c5_Nvvphi;
  real_T c5_Nvphiphi;
  real_T c5_Nrrphi;
  real_T c5_Nrphiphi;
  real_T c5_kk;
  real_T c5_epsilon;
  real_T c5_xR;
  real_T c5_wp;
  real_T c5_tau;
  real_T c5_xp;
  real_T c5_cpv;
  real_T c5_cpr;
  real_T c5_ga;
  real_T c5_cRr;
  real_T c5_cRrrr;
  real_T c5_cRrrv;
  real_T c5_cRX;
  real_T c5_aH;
  real_T c5_zR;
  real_T c5_xH;
  real_T c5_m11;
  real_T c5_m22;
  real_T c5_m32;
  real_T c5_m42;
  real_T c5_m33;
  real_T c5_m44;
  real_T c5_delta_dot;
  real_T c5_Tm;
  real_T c5_n_dot;
  real_T c5_vR;
  real_T c5_uP;
  real_T c5_J;
  real_T c5_KT;
  real_T c5_uR;
  real_T c5_alphaR;
  real_T c5_FN;
  real_T c5_X;
  real_T c5_Y;
  real_T c5_K;
  real_T c5_N;
  real_T c5_detM;
  real_T c5_nargin = 4.0;
  real_T c5_nargout = 2.0;
  int32_T c5_i41;
  static char_T c5_varargin_1[42] = { 'T', 'h', 'e', ' ', 's', 'h', 'i', 'p',
    ' ', 'm', 'u', 's', 't', ' ', 'h', 'a', 'v', 'e', ' ', 's', 'p', 'e', 'e',
    'd', ' ', 'g', 'r', 'e', 'a', 't', 'e', 'r', ' ', 't', 'h', 'a', 'n', ' ',
    'z', 'e', 'r', 'o' };

  char_T c5_b_u[42];
  const mxArray *c5_y = NULL;
  int32_T c5_i42;
  static char_T c5_b_varargin_1[43] = { 'T', 'h', 'e', ' ', 'p', 'r', 'o', 'p',
    'e', 'l', 'l', 'e', 'r', ' ', 'r', 'p', 'm', ' ', 'm', 'u', 's', 't', ' ',
    'b', 'e', ' ', 'g', 'r', 'e', 'a', 't', 'e', 'r', ' ', 't', 'h', 'a', 'n',
    ' ', 'z', 'e', 'r', 'o' };

  char_T c5_c_u[43];
  const mxArray *c5_b_y = NULL;
  real_T c5_A;
  real_T c5_b_B;
  real_T c5_b_x;
  real_T c5_c_y;
  real_T c5_c_x;
  real_T c5_d_y;
  real_T c5_d_x;
  real_T c5_e_y;
  real_T c5_b_A;
  real_T c5_c_B;
  real_T c5_e_x;
  real_T c5_f_y;
  real_T c5_f_x;
  real_T c5_g_y;
  real_T c5_g_x;
  real_T c5_h_y;
  real_T c5_c_A;
  real_T c5_d_B;
  real_T c5_h_x;
  real_T c5_i_y;
  real_T c5_i_x;
  real_T c5_j_y;
  real_T c5_j_x;
  real_T c5_k_y;
  real_T c5_d_A;
  real_T c5_e_B;
  real_T c5_k_x;
  real_T c5_l_y;
  real_T c5_l_x;
  real_T c5_m_y;
  real_T c5_m_x;
  real_T c5_n_y;
  real_T c5_e_A;
  real_T c5_n_x;
  real_T c5_o_x;
  real_T c5_p_x;
  real_T c5_o_y;
  real_T c5_f_A;
  real_T c5_f_B;
  real_T c5_q_x;
  real_T c5_p_y;
  real_T c5_r_x;
  real_T c5_q_y;
  real_T c5_s_x;
  real_T c5_r_y;
  real_T c5_g_A;
  real_T c5_t_x;
  real_T c5_u_x;
  real_T c5_v_x;
  real_T c5_s_y;
  real_T c5_g_B;
  real_T c5_t_y;
  real_T c5_u_y;
  real_T c5_v_y;
  real_T c5_d2;
  real_T c5_h_A;
  real_T c5_w_x;
  real_T c5_x_x;
  real_T c5_y_x;
  real_T c5_d3;
  real_T c5_i_A;
  real_T c5_ab_x;
  real_T c5_bb_x;
  real_T c5_cb_x;
  real_T c5_j_A;
  real_T c5_db_x;
  real_T c5_eb_x;
  real_T c5_fb_x;
  real_T c5_k_A;
  real_T c5_gb_x;
  real_T c5_hb_x;
  real_T c5_ib_x;
  real_T c5_d4;
  real_T c5_l_A;
  real_T c5_jb_x;
  real_T c5_kb_x;
  real_T c5_lb_x;
  real_T c5_h_B;
  real_T c5_w_y;
  real_T c5_x_y;
  real_T c5_y_y;
  real_T c5_i_B;
  real_T c5_ab_y;
  real_T c5_bb_y;
  real_T c5_cb_y;
  real_T c5_db_y;
  real_T c5_mb_x;
  real_T c5_nb_x;
  real_T c5_m_A;
  real_T c5_j_B;
  real_T c5_ob_x;
  real_T c5_eb_y;
  real_T c5_pb_x;
  real_T c5_fb_y;
  real_T c5_qb_x;
  real_T c5_gb_y;
  real_T c5_n_A;
  real_T c5_k_B;
  real_T c5_rb_x;
  real_T c5_hb_y;
  real_T c5_sb_x;
  real_T c5_ib_y;
  real_T c5_tb_x;
  real_T c5_jb_y;
  real_T c5_kb_y;
  real_T c5_d5;
  real_T c5_o_A;
  real_T c5_l_B;
  real_T c5_ub_x;
  real_T c5_lb_y;
  real_T c5_vb_x;
  real_T c5_mb_y;
  real_T c5_wb_x;
  real_T c5_nb_y;
  real_T c5_ob_y;
  real_T c5_xb_x;
  real_T c5_yb_x;
  real_T c5_ac_x;
  real_T c5_bc_x;
  real_T c5_m_B;
  real_T c5_pb_y;
  real_T c5_qb_y;
  real_T c5_rb_y;
  real_T c5_sb_y;
  real_T c5_cc_x;
  real_T c5_dc_x;
  real_T c5_ec_x;
  real_T c5_fc_x;
  real_T c5_gc_x;
  real_T c5_hc_x;
  real_T c5_ic_x;
  real_T c5_jc_x;
  real_T c5_p_A;
  real_T c5_kc_x;
  real_T c5_lc_x;
  real_T c5_mc_x;
  real_T c5_tb_y;
  real_T c5_q_A;
  real_T c5_nc_x;
  real_T c5_oc_x;
  real_T c5_pc_x;
  real_T c5_ub_y;
  real_T c5_r_A;
  real_T c5_qc_x;
  real_T c5_rc_x;
  real_T c5_sc_x;
  real_T c5_vb_y;
  real_T c5_s_A;
  real_T c5_tc_x;
  real_T c5_uc_x;
  real_T c5_vc_x;
  real_T c5_wb_y;
  real_T c5_t_A;
  real_T c5_wc_x;
  real_T c5_xc_x;
  real_T c5_yc_x;
  real_T c5_xb_y;
  real_T c5_u_A;
  real_T c5_ad_x;
  real_T c5_bd_x;
  real_T c5_cd_x;
  real_T c5_yb_y;
  real_T c5_dd_x;
  real_T c5_ed_x;
  real_T c5_fd_x;
  real_T c5_gd_x;
  real_T c5_hd_x;
  real_T c5_id_x;
  real_T c5_jd_x;
  real_T c5_kd_x;
  real_T c5_ld_x;
  real_T c5_md_x;
  real_T c5_nd_x;
  real_T c5_od_x;
  real_T c5_pd_x;
  real_T c5_qd_x;
  real_T c5_v_A;
  real_T c5_rd_x;
  real_T c5_sd_x;
  real_T c5_td_x;
  real_T c5_ac_y;
  real_T c5_w_A;
  real_T c5_ud_x;
  real_T c5_vd_x;
  real_T c5_wd_x;
  real_T c5_bc_y;
  real_T c5_x_A;
  real_T c5_xd_x;
  real_T c5_yd_x;
  real_T c5_ae_x;
  real_T c5_cc_y;
  real_T c5_y_A;
  real_T c5_be_x;
  real_T c5_ce_x;
  real_T c5_de_x;
  real_T c5_dc_y;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 127U, 127U, c5_b_debug_family_names,
    c5_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c5_L, 0U, c5_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c5_delta_max, 1U, c5_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c5_Ddelta_max, 2U, c5_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c5_n_max, 3U, c5_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c5_delta_c, 4U, c5_sf_marshallOut,
    c5_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c5_n_c, 5U, c5_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c5_u, 6U, c5_sf_marshallOut,
    c5_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c5_v, 7U, c5_sf_marshallOut,
    c5_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c5_p, 8U, c5_sf_marshallOut,
    c5_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c5_r, 9U, c5_sf_marshallOut,
    c5_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c5_phi, 10U, c5_sf_marshallOut,
    c5_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c5_psi, 11U, c5_sf_marshallOut,
    c5_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c5_delta, 12U, c5_sf_marshallOut,
    c5_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c5_n, 13U, c5_sf_marshallOut,
    c5_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c5_m, 14U, c5_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c5_mx, 15U, c5_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c5_my, 16U, c5_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c5_Ix, 17U, c5_sf_marshallOut,
    c5_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c5_alphay, 18U, c5_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c5_lx, 19U, c5_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c5_ly, 20U, c5_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c5_Iz, 21U, c5_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c5_Jx, 22U, c5_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c5_Jz, 23U, c5_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c5_xG, 24U, c5_sf_marshallOut,
    c5_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c5_B, 25U, c5_sf_marshallOut,
    c5_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c5_dF, 26U, c5_sf_marshallOut,
    c5_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c5_g, 27U, c5_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c5_dA, 28U, c5_sf_marshallOut,
    c5_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c5_d, 29U, c5_sf_marshallOut,
    c5_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c5_nabla, 30U, c5_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c5_KM, 31U, c5_sf_marshallOut,
    c5_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c5_KB, 32U, c5_sf_marshallOut,
    c5_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c5_AR, 33U, c5_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c5_Delta, 34U, c5_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c5_D, 35U, c5_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c5_GM, 36U, c5_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c5_rho, 37U, c5_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c5_t, 38U, c5_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c5_T, 39U, c5_sf_marshallOut,
    c5_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c5_W, 40U, c5_sf_marshallOut,
    c5_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c5_Xuu, 41U, c5_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c5_Xvr, 42U, c5_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c5_Xrr, 43U, c5_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c5_Xphiphi, 44U, c5_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c5_Xvv, 45U, c5_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c5_Kv, 46U, c5_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c5_Kr, 47U, c5_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c5_Kp, 48U, c5_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c5_Kphi, 49U, c5_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c5_Kvvv, 50U, c5_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c5_Krrr, 51U, c5_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c5_Kvvr, 52U, c5_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c5_Kvrr, 53U, c5_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c5_Kvvphi, 54U, c5_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c5_Kvphiphi, 55U, c5_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c5_Krrphi, 56U, c5_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c5_Krphiphi, 57U, c5_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c5_Yv, 58U, c5_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c5_Yr, 59U, c5_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c5_Yp, 60U, c5_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c5_Yphi, 61U, c5_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c5_Yvvv, 62U, c5_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c5_Yrrr, 63U, c5_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c5_Yvvr, 64U, c5_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c5_Yvrr, 65U, c5_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c5_Yvvphi, 66U, c5_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c5_Yvphiphi, 67U, c5_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c5_Yrrphi, 68U, c5_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c5_Yrphiphi, 69U, c5_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c5_Nv, 70U, c5_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c5_Nr, 71U, c5_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c5_Np, 72U, c5_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c5_Nphi, 73U, c5_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c5_Nvvv, 74U, c5_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c5_Nrrr, 75U, c5_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c5_Nvvr, 76U, c5_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c5_Nvrr, 77U, c5_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c5_Nvvphi, 78U, c5_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c5_Nvphiphi, 79U, c5_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c5_Nrrphi, 80U, c5_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c5_Nrphiphi, 81U, c5_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c5_kk, 82U, c5_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c5_epsilon, 83U, c5_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c5_xR, 84U, c5_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c5_wp, 85U, c5_sf_marshallOut,
    c5_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c5_tau, 86U, c5_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c5_xp, 87U, c5_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c5_cpv, 88U, c5_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c5_cpr, 89U, c5_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c5_ga, 90U, c5_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c5_cRr, 91U, c5_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c5_cRrrr, 92U, c5_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c5_cRrrv, 93U, c5_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c5_cRX, 94U, c5_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c5_aH, 95U, c5_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c5_zR, 96U, c5_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c5_xH, 97U, c5_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c5_m11, 98U, c5_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c5_m22, 99U, c5_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c5_m32, 100U, c5_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c5_m42, 101U, c5_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c5_m33, 102U, c5_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c5_m44, 103U, c5_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c5_delta_dot, 104U, c5_sf_marshallOut,
    c5_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c5_Tm, 105U, c5_sf_marshallOut,
    c5_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c5_n_dot, 106U, c5_sf_marshallOut,
    c5_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c5_vR, 107U, c5_sf_marshallOut,
    c5_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c5_uP, 108U, c5_sf_marshallOut,
    c5_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c5_J, 109U, c5_sf_marshallOut,
    c5_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c5_KT, 110U, c5_sf_marshallOut,
    c5_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c5_uR, 111U, c5_sf_marshallOut,
    c5_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c5_alphaR, 112U, c5_sf_marshallOut,
    c5_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c5_FN, 113U, c5_sf_marshallOut,
    c5_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c5_X, 114U, c5_sf_marshallOut,
    c5_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c5_Y, 115U, c5_sf_marshallOut,
    c5_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c5_K, 116U, c5_sf_marshallOut,
    c5_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c5_N, 117U, c5_sf_marshallOut,
    c5_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c5_detM, 118U, c5_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c5_nargin, 119U, c5_sf_marshallOut,
    c5_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c5_nargout, 120U, c5_sf_marshallOut,
    c5_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c5_x, 121U, c5_b_sf_marshallOut,
    c5_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c5_ui, 122U, c5_sf_marshallOut,
    c5_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c5_b_U0, 123U, c5_sf_marshallOut,
    c5_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c5_NOISE, 124U, c5_c_sf_marshallOut,
    c5_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c5_xdot, 125U, c5_b_sf_marshallOut,
    c5_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c5_U, 126U, c5_sf_marshallOut,
    c5_sf_marshallIn);
  CV_SCRIPT_FCN(0, 0);
  _SFD_SCRIPT_CALL(0U, chartInstance->c5_sfEvent, 6);
  c5_b_U0 = 0.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c5_sfEvent, 57);
  CV_SCRIPT_IF(0, 0, false);
  _SFD_SCRIPT_CALL(0U, chartInstance->c5_sfEvent, 58);
  CV_SCRIPT_IF(0, 1, false);
  _SFD_SCRIPT_CALL(0U, chartInstance->c5_sfEvent, 61);
  c5_L = 175.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c5_sfEvent, 62);
  *c5_U = c5_mpower(chartInstance, c5_x[0]) + c5_mpower(chartInstance, c5_x[1]);
  c5_b_sqrt(chartInstance, c5_U);
  _SFD_SCRIPT_CALL(0U, chartInstance->c5_sfEvent, 65);
  if (CV_SCRIPT_IF(0, 2, *c5_U <= 0.0)) {
    _SFD_SCRIPT_CALL(0U, chartInstance->c5_sfEvent, 65);
    for (c5_i41 = 0; c5_i41 < 42; c5_i41++) {
      c5_b_u[c5_i41] = c5_varargin_1[c5_i41];
    }

    c5_y = NULL;
    sf_mex_assign(&c5_y, sf_mex_create("y", c5_b_u, 10, 0U, 1U, 0U, 2, 1, 42),
                  false);
    sf_mex_call_debug(sfGlobalDebugInstanceStruct, "error", 0U, 1U, 14, c5_y);
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c5_sfEvent, 66);
  if (CV_SCRIPT_IF(0, 3, c5_x[9] <= 0.0)) {
    _SFD_SCRIPT_CALL(0U, chartInstance->c5_sfEvent, 66);
    for (c5_i42 = 0; c5_i42 < 43; c5_i42++) {
      c5_c_u[c5_i42] = c5_b_varargin_1[c5_i42];
    }

    c5_b_y = NULL;
    sf_mex_assign(&c5_b_y, sf_mex_create("y", c5_c_u, 10, 0U, 1U, 0U, 2, 1, 43),
                  false);
    sf_mex_call_debug(sfGlobalDebugInstanceStruct, "error", 0U, 1U, 14, c5_b_y);
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c5_sfEvent, 68);
  c5_delta_max = 20.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c5_sfEvent, 69);
  c5_Ddelta_max = 5.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c5_sfEvent, 70);
  c5_n_max = 160.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c5_sfEvent, 73);
  c5_delta_c = c5_ui;
  _SFD_SCRIPT_CALL(0U, chartInstance->c5_sfEvent, 74);
  c5_n_c = 70.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c5_sfEvent, 77);
  c5_A = c5_x[0];
  c5_b_B = *c5_U;
  c5_b_x = c5_A;
  c5_c_y = c5_b_B;
  c5_c_x = c5_b_x;
  c5_d_y = c5_c_y;
  c5_d_x = c5_c_x;
  c5_e_y = c5_d_y;
  c5_u = c5_d_x / c5_e_y;
  _SFD_SCRIPT_CALL(0U, chartInstance->c5_sfEvent, 77);
  c5_b_A = c5_x[1];
  c5_c_B = *c5_U;
  c5_e_x = c5_b_A;
  c5_f_y = c5_c_B;
  c5_f_x = c5_e_x;
  c5_g_y = c5_f_y;
  c5_g_x = c5_f_x;
  c5_h_y = c5_g_y;
  c5_v = c5_g_x / c5_h_y;
  _SFD_SCRIPT_CALL(0U, chartInstance->c5_sfEvent, 78);
  c5_c_A = c5_x[6] * 175.0;
  c5_d_B = *c5_U;
  c5_h_x = c5_c_A;
  c5_i_y = c5_d_B;
  c5_i_x = c5_h_x;
  c5_j_y = c5_i_y;
  c5_j_x = c5_i_x;
  c5_k_y = c5_j_y;
  c5_p = c5_j_x / c5_k_y;
  _SFD_SCRIPT_CALL(0U, chartInstance->c5_sfEvent, 78);
  c5_d_A = c5_x[2] * 175.0;
  c5_e_B = *c5_U;
  c5_k_x = c5_d_A;
  c5_l_y = c5_e_B;
  c5_l_x = c5_k_x;
  c5_m_y = c5_l_y;
  c5_m_x = c5_l_x;
  c5_n_y = c5_m_y;
  c5_r = c5_m_x / c5_n_y;
  _SFD_SCRIPT_CALL(0U, chartInstance->c5_sfEvent, 79);
  c5_phi = c5_x[7];
  _SFD_SCRIPT_CALL(0U, chartInstance->c5_sfEvent, 79);
  c5_psi = c5_x[5];
  _SFD_SCRIPT_CALL(0U, chartInstance->c5_sfEvent, 80);
  c5_delta = c5_x[8];
  _SFD_SCRIPT_CALL(0U, chartInstance->c5_sfEvent, 80);
  c5_e_A = c5_x[9];
  c5_n_x = c5_e_A;
  c5_o_x = c5_n_x;
  c5_p_x = c5_o_x;
  c5_o_y = c5_p_x / 60.0;
  c5_f_A = c5_o_y * 175.0;
  c5_f_B = *c5_U;
  c5_q_x = c5_f_A;
  c5_p_y = c5_f_B;
  c5_r_x = c5_q_x;
  c5_q_y = c5_p_y;
  c5_s_x = c5_r_x;
  c5_r_y = c5_q_y;
  c5_n = c5_s_x / c5_r_y;
  _SFD_SCRIPT_CALL(0U, chartInstance->c5_sfEvent, 83);
  c5_m = 0.00792;
  _SFD_SCRIPT_CALL(0U, chartInstance->c5_sfEvent, 83);
  c5_mx = 0.000238;
  _SFD_SCRIPT_CALL(0U, chartInstance->c5_sfEvent, 83);
  c5_my = 0.007049;
  _SFD_SCRIPT_CALL(0U, chartInstance->c5_sfEvent, 84);
  c5_Ix = 1.76E-5;
  _SFD_SCRIPT_CALL(0U, chartInstance->c5_sfEvent, 84);
  c5_alphay = 0.05;
  _SFD_SCRIPT_CALL(0U, chartInstance->c5_sfEvent, 84);
  c5_lx = 0.0313;
  _SFD_SCRIPT_CALL(0U, chartInstance->c5_sfEvent, 85);
  c5_ly = 0.0313;
  _SFD_SCRIPT_CALL(0U, chartInstance->c5_sfEvent, 85);
  c5_Ix = 1.76E-5;
  _SFD_SCRIPT_CALL(0U, chartInstance->c5_sfEvent, 85);
  c5_Iz = 0.000456;
  _SFD_SCRIPT_CALL(0U, chartInstance->c5_sfEvent, 86);
  c5_Jx = 3.4E-6;
  _SFD_SCRIPT_CALL(0U, chartInstance->c5_sfEvent, 86);
  c5_Jz = 0.000419;
  _SFD_SCRIPT_CALL(0U, chartInstance->c5_sfEvent, 86);
  c5_xG = 0.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c5_sfEvent, 88);
  c5_B = 25.4;
  _SFD_SCRIPT_CALL(0U, chartInstance->c5_sfEvent, 88);
  c5_dF = 8.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c5_sfEvent, 88);
  c5_g = 9.81;
  _SFD_SCRIPT_CALL(0U, chartInstance->c5_sfEvent, 89);
  c5_dA = 9.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c5_sfEvent, 89);
  c5_d = 8.5;
  _SFD_SCRIPT_CALL(0U, chartInstance->c5_sfEvent, 89);
  c5_nabla = 21222.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c5_sfEvent, 90);
  c5_KM = 10.39;
  _SFD_SCRIPT_CALL(0U, chartInstance->c5_sfEvent, 90);
  c5_KB = 4.6154;
  _SFD_SCRIPT_CALL(0U, chartInstance->c5_sfEvent, 90);
  c5_AR = 33.0376;
  _SFD_SCRIPT_CALL(0U, chartInstance->c5_sfEvent, 91);
  c5_Delta = 1.8219;
  _SFD_SCRIPT_CALL(0U, chartInstance->c5_sfEvent, 91);
  c5_D = 6.533;
  _SFD_SCRIPT_CALL(0U, chartInstance->c5_sfEvent, 91);
  c5_GM = 0.0017142857142857142;
  _SFD_SCRIPT_CALL(0U, chartInstance->c5_sfEvent, 92);
  c5_rho = 1025.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c5_sfEvent, 92);
  c5_t = 0.175;
  _SFD_SCRIPT_CALL(0U, chartInstance->c5_sfEvent, 92);
  c5_T = 0.0005;
  _SFD_SCRIPT_CALL(0U, chartInstance->c5_sfEvent, 94);
  c5_g_A = 3.1390625E+7 * c5_mpower(chartInstance, *c5_U);
  c5_t_x = c5_g_A;
  c5_u_x = c5_t_x;
  c5_v_x = c5_u_x;
  c5_s_y = c5_v_x / 2.0;
  c5_g_B = c5_s_y;
  c5_t_y = c5_g_B;
  c5_u_y = c5_t_y;
  c5_v_y = c5_u_y;
  c5_W = 2.133925155E+8 / c5_v_y;
  _SFD_SCRIPT_CALL(0U, chartInstance->c5_sfEvent, 96);
  c5_Xuu = -0.0004226;
  _SFD_SCRIPT_CALL(0U, chartInstance->c5_sfEvent, 96);
  c5_Xvr = -0.00311;
  _SFD_SCRIPT_CALL(0U, chartInstance->c5_sfEvent, 96);
  c5_Xrr = 0.0002;
  _SFD_SCRIPT_CALL(0U, chartInstance->c5_sfEvent, 97);
  c5_Xphiphi = -0.0002;
  _SFD_SCRIPT_CALL(0U, chartInstance->c5_sfEvent, 97);
  c5_Xvv = -0.00386;
  _SFD_SCRIPT_CALL(0U, chartInstance->c5_sfEvent, 99);
  c5_Kv = 0.0003026;
  _SFD_SCRIPT_CALL(0U, chartInstance->c5_sfEvent, 99);
  c5_Kr = -6.3E-5;
  _SFD_SCRIPT_CALL(0U, chartInstance->c5_sfEvent, 99);
  c5_Kp = -7.5E-6;
  _SFD_SCRIPT_CALL(0U, chartInstance->c5_sfEvent, 100);
  c5_Kphi = -2.1E-5;
  _SFD_SCRIPT_CALL(0U, chartInstance->c5_sfEvent, 100);
  c5_Kvvv = 0.002843;
  _SFD_SCRIPT_CALL(0U, chartInstance->c5_sfEvent, 100);
  c5_Krrr = -4.62E-5;
  _SFD_SCRIPT_CALL(0U, chartInstance->c5_sfEvent, 101);
  c5_Kvvr = -0.000588;
  _SFD_SCRIPT_CALL(0U, chartInstance->c5_sfEvent, 101);
  c5_Kvrr = 0.0010565;
  _SFD_SCRIPT_CALL(0U, chartInstance->c5_sfEvent, 101);
  c5_Kvvphi = -0.0012012;
  _SFD_SCRIPT_CALL(0U, chartInstance->c5_sfEvent, 102);
  c5_Kvphiphi = -7.93E-5;
  _SFD_SCRIPT_CALL(0U, chartInstance->c5_sfEvent, 102);
  c5_Krrphi = -0.000243;
  _SFD_SCRIPT_CALL(0U, chartInstance->c5_sfEvent, 102);
  c5_Krphiphi = 3.569E-5;
  _SFD_SCRIPT_CALL(0U, chartInstance->c5_sfEvent, 104);
  c5_Yv = -0.0116;
  _SFD_SCRIPT_CALL(0U, chartInstance->c5_sfEvent, 104);
  c5_Yr = 0.00242;
  _SFD_SCRIPT_CALL(0U, chartInstance->c5_sfEvent, 104);
  c5_Yp = 0.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c5_sfEvent, 105);
  c5_Yphi = -6.3E-5;
  _SFD_SCRIPT_CALL(0U, chartInstance->c5_sfEvent, 105);
  c5_Yvvv = -0.109;
  _SFD_SCRIPT_CALL(0U, chartInstance->c5_sfEvent, 105);
  c5_Yrrr = 0.00177;
  _SFD_SCRIPT_CALL(0U, chartInstance->c5_sfEvent, 106);
  c5_Yvvr = 0.0214;
  _SFD_SCRIPT_CALL(0U, chartInstance->c5_sfEvent, 106);
  c5_Yvrr = -0.0405;
  _SFD_SCRIPT_CALL(0U, chartInstance->c5_sfEvent, 106);
  c5_Yvvphi = 0.04605;
  _SFD_SCRIPT_CALL(0U, chartInstance->c5_sfEvent, 107);
  c5_Yvphiphi = 0.00304;
  _SFD_SCRIPT_CALL(0U, chartInstance->c5_sfEvent, 107);
  c5_Yrrphi = 0.009325;
  _SFD_SCRIPT_CALL(0U, chartInstance->c5_sfEvent, 107);
  c5_Yrphiphi = -0.001368;
  _SFD_SCRIPT_CALL(0U, chartInstance->c5_sfEvent, 109);
  c5_Nv = -0.0038545;
  _SFD_SCRIPT_CALL(0U, chartInstance->c5_sfEvent, 109);
  c5_Nr = -0.00222;
  _SFD_SCRIPT_CALL(0U, chartInstance->c5_sfEvent, 109);
  c5_Np = 0.000213;
  _SFD_SCRIPT_CALL(0U, chartInstance->c5_sfEvent, 110);
  c5_Nphi = -0.0001424;
  _SFD_SCRIPT_CALL(0U, chartInstance->c5_sfEvent, 110);
  c5_Nvvv = 0.001492;
  _SFD_SCRIPT_CALL(0U, chartInstance->c5_sfEvent, 110);
  c5_Nrrr = -0.00229;
  _SFD_SCRIPT_CALL(0U, chartInstance->c5_sfEvent, 111);
  c5_Nvvr = -0.0424;
  _SFD_SCRIPT_CALL(0U, chartInstance->c5_sfEvent, 111);
  c5_Nvrr = 0.00156;
  _SFD_SCRIPT_CALL(0U, chartInstance->c5_sfEvent, 111);
  c5_Nvvphi = -0.019058;
  _SFD_SCRIPT_CALL(0U, chartInstance->c5_sfEvent, 112);
  c5_Nvphiphi = -0.0053766;
  _SFD_SCRIPT_CALL(0U, chartInstance->c5_sfEvent, 112);
  c5_Nrrphi = -0.0038592;
  _SFD_SCRIPT_CALL(0U, chartInstance->c5_sfEvent, 112);
  c5_Nrphiphi = 0.0024195;
  _SFD_SCRIPT_CALL(0U, chartInstance->c5_sfEvent, 114);
  c5_kk = 0.631;
  _SFD_SCRIPT_CALL(0U, chartInstance->c5_sfEvent, 114);
  c5_epsilon = 0.921;
  _SFD_SCRIPT_CALL(0U, chartInstance->c5_sfEvent, 114);
  c5_xR = -0.5;
  _SFD_SCRIPT_CALL(0U, chartInstance->c5_sfEvent, 115);
  c5_wp = 0.184;
  _SFD_SCRIPT_CALL(0U, chartInstance->c5_sfEvent, 115);
  c5_tau = 1.09;
  _SFD_SCRIPT_CALL(0U, chartInstance->c5_sfEvent, 115);
  c5_xp = -0.526;
  _SFD_SCRIPT_CALL(0U, chartInstance->c5_sfEvent, 116);
  c5_cpv = 0.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c5_sfEvent, 116);
  c5_cpr = 0.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c5_sfEvent, 116);
  c5_ga = 0.088;
  _SFD_SCRIPT_CALL(0U, chartInstance->c5_sfEvent, 117);
  c5_cRr = -0.156;
  _SFD_SCRIPT_CALL(0U, chartInstance->c5_sfEvent, 117);
  c5_cRrrr = -0.275;
  _SFD_SCRIPT_CALL(0U, chartInstance->c5_sfEvent, 117);
  c5_cRrrv = 1.96;
  _SFD_SCRIPT_CALL(0U, chartInstance->c5_sfEvent, 118);
  c5_cRX = 0.71;
  _SFD_SCRIPT_CALL(0U, chartInstance->c5_sfEvent, 118);
  c5_aH = 0.237;
  _SFD_SCRIPT_CALL(0U, chartInstance->c5_sfEvent, 118);
  c5_zR = 0.033;
  _SFD_SCRIPT_CALL(0U, chartInstance->c5_sfEvent, 119);
  c5_xH = -0.48;
  _SFD_SCRIPT_CALL(0U, chartInstance->c5_sfEvent, 122);
  c5_m11 = 0.008158;
  _SFD_SCRIPT_CALL(0U, chartInstance->c5_sfEvent, 123);
  c5_m22 = 0.014969;
  _SFD_SCRIPT_CALL(0U, chartInstance->c5_sfEvent, 124);
  c5_m32 = -0.0002206337;
  _SFD_SCRIPT_CALL(0U, chartInstance->c5_sfEvent, 125);
  c5_m42 = 0.00035245000000000003;
  _SFD_SCRIPT_CALL(0U, chartInstance->c5_sfEvent, 126);
  c5_m33 = 2.1000000000000002E-5;
  _SFD_SCRIPT_CALL(0U, chartInstance->c5_sfEvent, MAX_int8_T);
  c5_m44 = 0.000875;
  _SFD_SCRIPT_CALL(0U, chartInstance->c5_sfEvent, 130U);
  if (CV_SCRIPT_IF(0, 4, c5_abs(chartInstance, c5_delta_c) >= 0.3490658503988659))
  {
    _SFD_SCRIPT_CALL(0U, chartInstance->c5_sfEvent, 131U);
    c5_d2 = c5_delta_c;
    c5_b_sign(chartInstance, &c5_d2);
    c5_h_A = c5_d2 * 20.0 * 3.1415926535897931;
    c5_w_x = c5_h_A;
    c5_x_x = c5_w_x;
    c5_y_x = c5_x_x;
    c5_delta_c = c5_y_x / 180.0;
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c5_sfEvent, 134U);
  c5_delta_dot = c5_delta_c - c5_delta;
  _SFD_SCRIPT_CALL(0U, chartInstance->c5_sfEvent, 135U);
  if (CV_SCRIPT_IF(0, 5, c5_abs(chartInstance, c5_delta_dot) >=
                   0.087266462599716474)) {
    _SFD_SCRIPT_CALL(0U, chartInstance->c5_sfEvent, 136U);
    c5_d3 = c5_delta_dot;
    c5_b_sign(chartInstance, &c5_d3);
    c5_i_A = c5_d3 * 5.0 * 3.1415926535897931;
    c5_ab_x = c5_i_A;
    c5_bb_x = c5_ab_x;
    c5_cb_x = c5_bb_x;
    c5_delta_dot = c5_cb_x / 180.0;
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c5_sfEvent, 140U);
  c5_j_A = 70.0 * *c5_U;
  c5_db_x = c5_j_A;
  c5_eb_x = c5_db_x;
  c5_fb_x = c5_eb_x;
  c5_n_c = c5_fb_x / 175.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c5_sfEvent, 141U);
  c5_k_A = c5_n * *c5_U;
  c5_gb_x = c5_k_A;
  c5_hb_x = c5_gb_x;
  c5_ib_x = c5_hb_x;
  c5_n = c5_ib_x / 175.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c5_sfEvent, 142U);
  if (CV_SCRIPT_IF(0, 6, c5_abs(chartInstance, c5_n_c) >= 2.6666666666666665)) {
    _SFD_SCRIPT_CALL(0U, chartInstance->c5_sfEvent, 143U);
    c5_d4 = c5_n_c;
    c5_b_sign(chartInstance, &c5_d4);
    c5_l_A = c5_d4 * 160.0;
    c5_jb_x = c5_l_A;
    c5_kb_x = c5_jb_x;
    c5_lb_x = c5_kb_x;
    c5_n_c = c5_lb_x / 60.0;
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c5_sfEvent, 146U);
  if (CV_SCRIPT_IF(0, 7, c5_n > 0.3)) {
    _SFD_SCRIPT_CALL(0U, chartInstance->c5_sfEvent, 146U);
    c5_h_B = c5_n;
    c5_w_y = c5_h_B;
    c5_x_y = c5_w_y;
    c5_y_y = c5_x_y;
    c5_Tm = 5.65 / c5_y_y;
  } else {
    _SFD_SCRIPT_CALL(0U, chartInstance->c5_sfEvent, 146U);
    c5_Tm = 18.83;
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c5_sfEvent, 147U);
  c5_i_B = c5_Tm;
  c5_ab_y = c5_i_B;
  c5_bb_y = c5_ab_y;
  c5_cb_y = c5_bb_y;
  c5_db_y = 1.0 / c5_cb_y;
  c5_n_dot = c5_db_y * (c5_n_c - c5_n) * 60.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c5_sfEvent, 150U);
  c5_vR = ((0.088 * c5_v + -0.156 * c5_r) + -0.275 * c5_b_mpower(chartInstance,
            c5_r)) + 1.96 * c5_mpower(chartInstance, c5_r) * c5_v;
  _SFD_SCRIPT_CALL(0U, chartInstance->c5_sfEvent, 151U);
  c5_mb_x = c5_v;
  c5_nb_x = c5_mb_x;
  c5_nb_x = muDoubleScalarCos(c5_nb_x);
  c5_uP = c5_nb_x * ((1.0 - c5_wp) + 1.09 * ((c5_mpower(chartInstance, c5_v +
    -0.526 * c5_r) + 0.0 * c5_v) + 0.0 * c5_r));
  _SFD_SCRIPT_CALL(0U, chartInstance->c5_sfEvent, 152U);
  c5_m_A = c5_uP * *c5_U;
  c5_j_B = c5_n * 6.533;
  c5_ob_x = c5_m_A;
  c5_eb_y = c5_j_B;
  c5_pb_x = c5_ob_x;
  c5_fb_y = c5_eb_y;
  c5_qb_x = c5_pb_x;
  c5_gb_y = c5_fb_y;
  c5_J = c5_qb_x / c5_gb_y;
  _SFD_SCRIPT_CALL(0U, chartInstance->c5_sfEvent, 153U);
  c5_KT = 0.527 - 0.455 * c5_J;
  _SFD_SCRIPT_CALL(0U, chartInstance->c5_sfEvent, 154U);
  c5_n_A = 5.048 * c5_KT;
  c5_k_B = 3.1415926535897931 * c5_mpower(chartInstance, c5_J);
  c5_rb_x = c5_n_A;
  c5_hb_y = c5_k_B;
  c5_sb_x = c5_rb_x;
  c5_ib_y = c5_hb_y;
  c5_tb_x = c5_sb_x;
  c5_jb_y = c5_ib_y;
  c5_kb_y = c5_tb_x / c5_jb_y;
  c5_d5 = 1.0 + c5_kb_y;
  c5_b_sqrt(chartInstance, &c5_d5);
  c5_uR = c5_uP * 0.921 * c5_d5;
  _SFD_SCRIPT_CALL(0U, chartInstance->c5_sfEvent, 155U);
  c5_o_A = c5_vR;
  c5_l_B = c5_uR;
  c5_ub_x = c5_o_A;
  c5_lb_y = c5_l_B;
  c5_vb_x = c5_ub_x;
  c5_mb_y = c5_lb_y;
  c5_wb_x = c5_vb_x;
  c5_nb_y = c5_mb_y;
  c5_ob_y = c5_wb_x / c5_nb_y;
  c5_xb_x = c5_ob_y;
  c5_yb_x = c5_xb_x;
  c5_yb_x = muDoubleScalarAtan(c5_yb_x);
  c5_alphaR = c5_delta + c5_yb_x;
  _SFD_SCRIPT_CALL(0U, chartInstance->c5_sfEvent, 156U);
  c5_ac_x = c5_alphaR;
  c5_bc_x = c5_ac_x;
  c5_bc_x = muDoubleScalarSin(c5_bc_x);
  c5_FN = -0.0029588319514859181 * (c5_mpower(chartInstance, c5_uR) + c5_mpower
    (chartInstance, c5_vR)) * c5_bc_x;
  _SFD_SCRIPT_CALL(0U, chartInstance->c5_sfEvent, 157U);
  c5_m_B = c5_mpower(chartInstance, *c5_U) * 30625.0 * 1025.0;
  c5_pb_y = c5_m_B;
  c5_qb_y = c5_pb_y;
  c5_rb_y = c5_qb_y;
  c5_sb_y = 3.7342594939482389E+6 / c5_rb_y;
  c5_T = c5_sb_y * c5_KT * c5_n * c5_abs(chartInstance, c5_n);
  _SFD_SCRIPT_CALL(0U, chartInstance->c5_sfEvent, 160U);
  c5_cc_x = c5_delta;
  c5_dc_x = c5_cc_x;
  c5_dc_x = muDoubleScalarSin(c5_dc_x);
  c5_X = ((((((-0.0004226 * c5_mpower(chartInstance, c5_u) + 0.825 * c5_T)
              + -0.00311 * c5_v * c5_r) + -0.00386 * c5_mpower(chartInstance,
              c5_v)) + 0.0002 * c5_mpower(chartInstance, c5_r)) + -0.0002 *
           c5_mpower(chartInstance, c5_phi)) + 0.71 * c5_FN * c5_dc_x) +
    0.014969 * c5_v * c5_r;
  _SFD_SCRIPT_CALL(0U, chartInstance->c5_sfEvent, 163U);
  c5_ec_x = c5_delta;
  c5_fc_x = c5_ec_x;
  c5_fc_x = muDoubleScalarCos(c5_fc_x);
  c5_Y = ((((((((((((-0.0116 * c5_v + 0.00242 * c5_r) + 0.0 * c5_p) + -6.3E-5 *
                   c5_phi) + -0.109 * c5_b_mpower(chartInstance, c5_v)) +
                 0.00177 * c5_b_mpower(chartInstance, c5_r)) + 0.0214 *
                c5_mpower(chartInstance, c5_v) * c5_r) + -0.0405 * c5_v *
               c5_mpower(chartInstance, c5_r)) + 0.04605 * c5_mpower
              (chartInstance, c5_v) * c5_phi) + 0.00304 * c5_v * c5_mpower
             (chartInstance, c5_phi)) + 0.009325 * c5_mpower(chartInstance, c5_r)
            * c5_phi) + -0.001368 * c5_r * c5_mpower(chartInstance, c5_phi)) +
          1.237 * c5_FN * c5_fc_x) - 0.008158 * c5_u * c5_r;
  _SFD_SCRIPT_CALL(0U, chartInstance->c5_sfEvent, 167U);
  c5_gc_x = c5_delta;
  c5_hc_x = c5_gc_x;
  c5_hc_x = muDoubleScalarCos(c5_hc_x);
  c5_K = ((((((((((((((0.0003026 * c5_v + -6.3E-5 * c5_r) + -7.5E-6 * c5_p) +
                     -2.1E-5 * c5_phi) + 0.002843 * c5_b_mpower(chartInstance,
    c5_v)) + -4.62E-5 * c5_b_mpower(chartInstance, c5_r)) + -0.000588 *
                  c5_mpower(chartInstance, c5_v) * c5_r) + 0.0010565 * c5_v *
                 c5_mpower(chartInstance, c5_r)) + -0.0012012 * c5_mpower
                (chartInstance, c5_v) * c5_phi) + -7.93E-5 * c5_v * c5_mpower
               (chartInstance, c5_phi)) + -0.000243 * c5_mpower(chartInstance,
    c5_r) * c5_phi) + 3.569E-5 * c5_r * c5_mpower(chartInstance, c5_phi)) -
            0.040821 * c5_FN * c5_hc_x) + 7.449400000000001E-6 * c5_u * c5_r) -
          c5_W * 0.0017142857142857142 * c5_phi) + c5_NOISE[1];
  _SFD_SCRIPT_CALL(0U, chartInstance->c5_sfEvent, 171U);
  c5_ic_x = c5_delta;
  c5_jc_x = c5_ic_x;
  c5_jc_x = muDoubleScalarCos(c5_jc_x);
  c5_N = ((((((((((((-0.0038545 * c5_v + -0.00222 * c5_r) + 0.000213 * c5_p) +
                   -0.0001424 * c5_phi) + 0.001492 * c5_b_mpower(chartInstance,
    c5_v)) + -0.00229 * c5_b_mpower(chartInstance, c5_r)) + -0.0424 * c5_mpower
                (chartInstance, c5_v) * c5_r) + 0.00156 * c5_v * c5_mpower
               (chartInstance, c5_r)) + -0.019058 * c5_mpower(chartInstance,
    c5_v) * c5_phi) + -0.0053766 * c5_v * c5_mpower(chartInstance, c5_phi)) +
            -0.0038592 * c5_mpower(chartInstance, c5_r) * c5_phi) + 0.0024195 *
           c5_r * c5_mpower(chartInstance, c5_phi)) + -0.61376 * c5_FN * c5_jc_x)
    + c5_NOISE[0];
  _SFD_SCRIPT_CALL(0U, chartInstance->c5_sfEvent, 176U);
  c5_detM = 2.2985240806877131E-10;
  _SFD_SCRIPT_CALL(0U, chartInstance->c5_sfEvent, 178U);
  c5_p_A = c5_mpower(chartInstance, *c5_U);
  c5_kc_x = c5_p_A;
  c5_lc_x = c5_kc_x;
  c5_mc_x = c5_lc_x;
  c5_tb_y = c5_mc_x / 175.0;
  c5_q_A = c5_X * c5_tb_y;
  c5_nc_x = c5_q_A;
  c5_oc_x = c5_nc_x;
  c5_pc_x = c5_oc_x;
  c5_ub_y = c5_pc_x / 0.008158;
  c5_r_A = (-1.8375E-8 * c5_Y + -1.930544875E-7 * c5_K) + 7.4014500000000016E-9 *
    c5_N;
  c5_qc_x = c5_r_A;
  c5_rc_x = c5_qc_x;
  c5_sc_x = c5_rc_x;
  c5_vb_y = c5_sc_x / 2.2985240806877131E-10;
  c5_s_A = c5_mpower(chartInstance, *c5_U);
  c5_tc_x = c5_s_A;
  c5_uc_x = c5_tc_x;
  c5_vc_x = c5_uc_x;
  c5_wb_y = c5_vc_x / 175.0;
  c5_t_A = ((-7.4014500000000016E-9 * c5_Y + -7.7762347565E-8 * c5_K) + c5_N *
            0.014969 * 2.1000000000000002E-5) - c5_N * 4.867922957569E-8;
  c5_wc_x = c5_t_A;
  c5_xc_x = c5_wc_x;
  c5_yc_x = c5_xc_x;
  c5_xb_y = c5_yc_x / 2.2985240806877131E-10;
  c5_u_A = c5_mpower(chartInstance, *c5_U);
  c5_ad_x = c5_u_A;
  c5_bd_x = c5_ad_x;
  c5_cd_x = c5_bd_x;
  c5_yb_y = c5_cd_x / 30625.0;
  c5_dd_x = c5_psi;
  c5_ed_x = c5_dd_x;
  c5_ed_x = muDoubleScalarCos(c5_ed_x);
  c5_fd_x = c5_psi;
  c5_gd_x = c5_fd_x;
  c5_gd_x = muDoubleScalarSin(c5_gd_x);
  c5_hd_x = c5_phi;
  c5_id_x = c5_hd_x;
  c5_id_x = muDoubleScalarCos(c5_id_x);
  c5_jd_x = c5_psi;
  c5_kd_x = c5_jd_x;
  c5_kd_x = muDoubleScalarSin(c5_kd_x);
  c5_ld_x = c5_psi;
  c5_md_x = c5_ld_x;
  c5_md_x = muDoubleScalarCos(c5_md_x);
  c5_nd_x = c5_phi;
  c5_od_x = c5_nd_x;
  c5_od_x = muDoubleScalarCos(c5_od_x);
  c5_pd_x = c5_phi;
  c5_qd_x = c5_pd_x;
  c5_qd_x = muDoubleScalarCos(c5_qd_x);
  c5_v_A = *c5_U;
  c5_rd_x = c5_v_A;
  c5_sd_x = c5_rd_x;
  c5_td_x = c5_sd_x;
  c5_ac_y = c5_td_x / 175.0;
  c5_w_A = ((1.930544875E-7 * c5_Y + c5_K * 0.014969 * 0.000875) - c5_K *
            1.2422100250000002E-7) + -7.7762347565E-8 * c5_N;
  c5_ud_x = c5_w_A;
  c5_vd_x = c5_ud_x;
  c5_wd_x = c5_vd_x;
  c5_bc_y = c5_wd_x / 2.2985240806877131E-10;
  c5_x_A = c5_mpower(chartInstance, *c5_U);
  c5_xd_x = c5_x_A;
  c5_yd_x = c5_xd_x;
  c5_ae_x = c5_yd_x;
  c5_cc_y = c5_ae_x / 30625.0;
  c5_y_A = *c5_U;
  c5_be_x = c5_y_A;
  c5_ce_x = c5_be_x;
  c5_de_x = c5_ce_x;
  c5_dc_y = c5_de_x / 175.0;
  c5_xdot[0] = c5_ub_y;
  c5_xdot[1] = -c5_vb_y * c5_wb_y;
  c5_xdot[2] = c5_xb_y * c5_yb_y;
  c5_xdot[3] = (c5_ed_x * c5_u - c5_gd_x * c5_id_x * c5_v) * *c5_U;
  c5_xdot[4] = (c5_kd_x * c5_u + c5_md_x * c5_od_x * c5_v) * *c5_U;
  c5_xdot[5] = c5_qd_x * c5_r * c5_ac_y;
  c5_xdot[6] = c5_bc_y * c5_cc_y;
  c5_xdot[7] = c5_p * c5_dc_y;
  c5_xdot[8] = c5_delta_dot;
  c5_xdot[9] = 0.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c5_sfEvent, -178);
  _SFD_SYMBOL_SCOPE_POP();
}

static void init_script_number_translation(uint32_T c5_machineNumber, uint32_T
  c5_chartNumber, uint32_T c5_instanceNumber)
{
  (void)c5_machineNumber;
  _SFD_SCRIPT_TRANSLATION(c5_chartNumber, c5_instanceNumber, 0U,
    sf_debug_get_script_id(
    "/Users/dittoyi/DittoyiWorkSystem/scholar/OnGoingWork/PathFollowingRRS/line/container.m"));
}

static const mxArray *c5_sf_marshallOut(void *chartInstanceVoid, void *c5_inData)
{
  const mxArray *c5_mxArrayOutData = NULL;
  real_T c5_u;
  const mxArray *c5_y = NULL;
  SFc5_untitled2InstanceStruct *chartInstance;
  chartInstance = (SFc5_untitled2InstanceStruct *)chartInstanceVoid;
  c5_mxArrayOutData = NULL;
  c5_u = *(real_T *)c5_inData;
  c5_y = NULL;
  sf_mex_assign(&c5_y, sf_mex_create("y", &c5_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c5_mxArrayOutData, c5_y, false);
  return c5_mxArrayOutData;
}

static real_T c5_emlrt_marshallIn(SFc5_untitled2InstanceStruct *chartInstance,
  const mxArray *c5_Theta_wo, const char_T *c5_identifier)
{
  real_T c5_y;
  emlrtMsgIdentifier c5_thisId;
  c5_thisId.fIdentifier = c5_identifier;
  c5_thisId.fParent = NULL;
  c5_y = c5_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c5_Theta_wo),
    &c5_thisId);
  sf_mex_destroy(&c5_Theta_wo);
  return c5_y;
}

static real_T c5_b_emlrt_marshallIn(SFc5_untitled2InstanceStruct *chartInstance,
  const mxArray *c5_u, const emlrtMsgIdentifier *c5_parentId)
{
  real_T c5_y;
  real_T c5_d6;
  (void)chartInstance;
  sf_mex_import(c5_parentId, sf_mex_dup(c5_u), &c5_d6, 1, 0, 0U, 0, 0U, 0);
  c5_y = c5_d6;
  sf_mex_destroy(&c5_u);
  return c5_y;
}

static void c5_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c5_mxArrayInData, const char_T *c5_varName, void *c5_outData)
{
  const mxArray *c5_Theta_wo;
  const char_T *c5_identifier;
  emlrtMsgIdentifier c5_thisId;
  real_T c5_y;
  SFc5_untitled2InstanceStruct *chartInstance;
  chartInstance = (SFc5_untitled2InstanceStruct *)chartInstanceVoid;
  c5_Theta_wo = sf_mex_dup(c5_mxArrayInData);
  c5_identifier = c5_varName;
  c5_thisId.fIdentifier = c5_identifier;
  c5_thisId.fParent = NULL;
  c5_y = c5_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c5_Theta_wo),
    &c5_thisId);
  sf_mex_destroy(&c5_Theta_wo);
  *(real_T *)c5_outData = c5_y;
  sf_mex_destroy(&c5_mxArrayInData);
}

static const mxArray *c5_b_sf_marshallOut(void *chartInstanceVoid, void
  *c5_inData)
{
  const mxArray *c5_mxArrayOutData = NULL;
  int32_T c5_i43;
  real_T c5_b_inData[10];
  int32_T c5_i44;
  real_T c5_u[10];
  const mxArray *c5_y = NULL;
  SFc5_untitled2InstanceStruct *chartInstance;
  chartInstance = (SFc5_untitled2InstanceStruct *)chartInstanceVoid;
  c5_mxArrayOutData = NULL;
  for (c5_i43 = 0; c5_i43 < 10; c5_i43++) {
    c5_b_inData[c5_i43] = (*(real_T (*)[10])c5_inData)[c5_i43];
  }

  for (c5_i44 = 0; c5_i44 < 10; c5_i44++) {
    c5_u[c5_i44] = c5_b_inData[c5_i44];
  }

  c5_y = NULL;
  sf_mex_assign(&c5_y, sf_mex_create("y", c5_u, 0, 0U, 1U, 0U, 1, 10), false);
  sf_mex_assign(&c5_mxArrayOutData, c5_y, false);
  return c5_mxArrayOutData;
}

static void c5_c_emlrt_marshallIn(SFc5_untitled2InstanceStruct *chartInstance,
  const mxArray *c5_x_next, const char_T *c5_identifier, real_T c5_y[10])
{
  emlrtMsgIdentifier c5_thisId;
  c5_thisId.fIdentifier = c5_identifier;
  c5_thisId.fParent = NULL;
  c5_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c5_x_next), &c5_thisId, c5_y);
  sf_mex_destroy(&c5_x_next);
}

static void c5_d_emlrt_marshallIn(SFc5_untitled2InstanceStruct *chartInstance,
  const mxArray *c5_u, const emlrtMsgIdentifier *c5_parentId, real_T c5_y[10])
{
  real_T c5_dv1[10];
  int32_T c5_i45;
  (void)chartInstance;
  sf_mex_import(c5_parentId, sf_mex_dup(c5_u), c5_dv1, 1, 0, 0U, 1, 0U, 1, 10);
  for (c5_i45 = 0; c5_i45 < 10; c5_i45++) {
    c5_y[c5_i45] = c5_dv1[c5_i45];
  }

  sf_mex_destroy(&c5_u);
}

static void c5_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c5_mxArrayInData, const char_T *c5_varName, void *c5_outData)
{
  const mxArray *c5_x_next;
  const char_T *c5_identifier;
  emlrtMsgIdentifier c5_thisId;
  real_T c5_y[10];
  int32_T c5_i46;
  SFc5_untitled2InstanceStruct *chartInstance;
  chartInstance = (SFc5_untitled2InstanceStruct *)chartInstanceVoid;
  c5_x_next = sf_mex_dup(c5_mxArrayInData);
  c5_identifier = c5_varName;
  c5_thisId.fIdentifier = c5_identifier;
  c5_thisId.fParent = NULL;
  c5_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c5_x_next), &c5_thisId, c5_y);
  sf_mex_destroy(&c5_x_next);
  for (c5_i46 = 0; c5_i46 < 10; c5_i46++) {
    (*(real_T (*)[10])c5_outData)[c5_i46] = c5_y[c5_i46];
  }

  sf_mex_destroy(&c5_mxArrayInData);
}

static const mxArray *c5_c_sf_marshallOut(void *chartInstanceVoid, void
  *c5_inData)
{
  const mxArray *c5_mxArrayOutData = NULL;
  int32_T c5_i47;
  real_T c5_b_inData[2];
  int32_T c5_i48;
  real_T c5_u[2];
  const mxArray *c5_y = NULL;
  SFc5_untitled2InstanceStruct *chartInstance;
  chartInstance = (SFc5_untitled2InstanceStruct *)chartInstanceVoid;
  c5_mxArrayOutData = NULL;
  for (c5_i47 = 0; c5_i47 < 2; c5_i47++) {
    c5_b_inData[c5_i47] = (*(real_T (*)[2])c5_inData)[c5_i47];
  }

  for (c5_i48 = 0; c5_i48 < 2; c5_i48++) {
    c5_u[c5_i48] = c5_b_inData[c5_i48];
  }

  c5_y = NULL;
  sf_mex_assign(&c5_y, sf_mex_create("y", c5_u, 0, 0U, 1U, 0U, 1, 2), false);
  sf_mex_assign(&c5_mxArrayOutData, c5_y, false);
  return c5_mxArrayOutData;
}

static void c5_e_emlrt_marshallIn(SFc5_untitled2InstanceStruct *chartInstance,
  const mxArray *c5_u, const emlrtMsgIdentifier *c5_parentId, real_T c5_y[2])
{
  real_T c5_dv2[2];
  int32_T c5_i49;
  (void)chartInstance;
  sf_mex_import(c5_parentId, sf_mex_dup(c5_u), c5_dv2, 1, 0, 0U, 1, 0U, 1, 2);
  for (c5_i49 = 0; c5_i49 < 2; c5_i49++) {
    c5_y[c5_i49] = c5_dv2[c5_i49];
  }

  sf_mex_destroy(&c5_u);
}

static void c5_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c5_mxArrayInData, const char_T *c5_varName, void *c5_outData)
{
  const mxArray *c5_NOISE;
  const char_T *c5_identifier;
  emlrtMsgIdentifier c5_thisId;
  real_T c5_y[2];
  int32_T c5_i50;
  SFc5_untitled2InstanceStruct *chartInstance;
  chartInstance = (SFc5_untitled2InstanceStruct *)chartInstanceVoid;
  c5_NOISE = sf_mex_dup(c5_mxArrayInData);
  c5_identifier = c5_varName;
  c5_thisId.fIdentifier = c5_identifier;
  c5_thisId.fParent = NULL;
  c5_e_emlrt_marshallIn(chartInstance, sf_mex_dup(c5_NOISE), &c5_thisId, c5_y);
  sf_mex_destroy(&c5_NOISE);
  for (c5_i50 = 0; c5_i50 < 2; c5_i50++) {
    (*(real_T (*)[2])c5_outData)[c5_i50] = c5_y[c5_i50];
  }

  sf_mex_destroy(&c5_mxArrayInData);
}

const mxArray *sf_c5_untitled2_get_eml_resolved_functions_info(void)
{
  const mxArray *c5_nameCaptureInfo = NULL;
  c5_nameCaptureInfo = NULL;
  sf_mex_assign(&c5_nameCaptureInfo, sf_mex_createstruct("structure", 2, 42, 1),
                false);
  c5_info_helper(&c5_nameCaptureInfo);
  sf_mex_emlrtNameCapturePostProcessR2012a(&c5_nameCaptureInfo);
  return c5_nameCaptureInfo;
}

static void c5_info_helper(const mxArray **c5_info)
{
  const mxArray *c5_rhs0 = NULL;
  const mxArray *c5_lhs0 = NULL;
  const mxArray *c5_rhs1 = NULL;
  const mxArray *c5_lhs1 = NULL;
  const mxArray *c5_rhs2 = NULL;
  const mxArray *c5_lhs2 = NULL;
  const mxArray *c5_rhs3 = NULL;
  const mxArray *c5_lhs3 = NULL;
  const mxArray *c5_rhs4 = NULL;
  const mxArray *c5_lhs4 = NULL;
  const mxArray *c5_rhs5 = NULL;
  const mxArray *c5_lhs5 = NULL;
  const mxArray *c5_rhs6 = NULL;
  const mxArray *c5_lhs6 = NULL;
  const mxArray *c5_rhs7 = NULL;
  const mxArray *c5_lhs7 = NULL;
  const mxArray *c5_rhs8 = NULL;
  const mxArray *c5_lhs8 = NULL;
  const mxArray *c5_rhs9 = NULL;
  const mxArray *c5_lhs9 = NULL;
  const mxArray *c5_rhs10 = NULL;
  const mxArray *c5_lhs10 = NULL;
  const mxArray *c5_rhs11 = NULL;
  const mxArray *c5_lhs11 = NULL;
  const mxArray *c5_rhs12 = NULL;
  const mxArray *c5_lhs12 = NULL;
  const mxArray *c5_rhs13 = NULL;
  const mxArray *c5_lhs13 = NULL;
  const mxArray *c5_rhs14 = NULL;
  const mxArray *c5_lhs14 = NULL;
  const mxArray *c5_rhs15 = NULL;
  const mxArray *c5_lhs15 = NULL;
  const mxArray *c5_rhs16 = NULL;
  const mxArray *c5_lhs16 = NULL;
  const mxArray *c5_rhs17 = NULL;
  const mxArray *c5_lhs17 = NULL;
  const mxArray *c5_rhs18 = NULL;
  const mxArray *c5_lhs18 = NULL;
  const mxArray *c5_rhs19 = NULL;
  const mxArray *c5_lhs19 = NULL;
  const mxArray *c5_rhs20 = NULL;
  const mxArray *c5_lhs20 = NULL;
  const mxArray *c5_rhs21 = NULL;
  const mxArray *c5_lhs21 = NULL;
  const mxArray *c5_rhs22 = NULL;
  const mxArray *c5_lhs22 = NULL;
  const mxArray *c5_rhs23 = NULL;
  const mxArray *c5_lhs23 = NULL;
  const mxArray *c5_rhs24 = NULL;
  const mxArray *c5_lhs24 = NULL;
  const mxArray *c5_rhs25 = NULL;
  const mxArray *c5_lhs25 = NULL;
  const mxArray *c5_rhs26 = NULL;
  const mxArray *c5_lhs26 = NULL;
  const mxArray *c5_rhs27 = NULL;
  const mxArray *c5_lhs27 = NULL;
  const mxArray *c5_rhs28 = NULL;
  const mxArray *c5_lhs28 = NULL;
  const mxArray *c5_rhs29 = NULL;
  const mxArray *c5_lhs29 = NULL;
  const mxArray *c5_rhs30 = NULL;
  const mxArray *c5_lhs30 = NULL;
  const mxArray *c5_rhs31 = NULL;
  const mxArray *c5_lhs31 = NULL;
  const mxArray *c5_rhs32 = NULL;
  const mxArray *c5_lhs32 = NULL;
  const mxArray *c5_rhs33 = NULL;
  const mxArray *c5_lhs33 = NULL;
  const mxArray *c5_rhs34 = NULL;
  const mxArray *c5_lhs34 = NULL;
  const mxArray *c5_rhs35 = NULL;
  const mxArray *c5_lhs35 = NULL;
  const mxArray *c5_rhs36 = NULL;
  const mxArray *c5_lhs36 = NULL;
  const mxArray *c5_rhs37 = NULL;
  const mxArray *c5_lhs37 = NULL;
  const mxArray *c5_rhs38 = NULL;
  const mxArray *c5_lhs38 = NULL;
  const mxArray *c5_rhs39 = NULL;
  const mxArray *c5_lhs39 = NULL;
  const mxArray *c5_rhs40 = NULL;
  const mxArray *c5_lhs40 = NULL;
  const mxArray *c5_rhs41 = NULL;
  const mxArray *c5_lhs41 = NULL;
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(""), "context", "context", 0);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut("container"), "name", "name", 0);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 0);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[E]/Users/dittoyi/DittoyiWorkSystem/scholar/OnGoingWork/PathFollowingRRS/line/container.m"),
                  "resolved", "resolved", 0);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(1417941816U), "fileTimeLo",
                  "fileTimeLo", 0);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 0);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 0);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 0);
  sf_mex_assign(&c5_rhs0, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c5_lhs0, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_rhs0), "rhs", "rhs", 0);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_lhs0), "lhs", "lhs", 0);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[E]/Users/dittoyi/DittoyiWorkSystem/scholar/OnGoingWork/PathFollowingRRS/line/container.m"),
                  "context", "context", 1);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut("length"), "name", "name", 1);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 1);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/length.m"), "resolved",
                  "resolved", 1);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(1303124606U), "fileTimeLo",
                  "fileTimeLo", 1);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 1);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 1);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 1);
  sf_mex_assign(&c5_rhs1, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c5_lhs1, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_rhs1), "rhs", "rhs", 1);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_lhs1), "lhs", "lhs", 1);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[E]/Users/dittoyi/DittoyiWorkSystem/scholar/OnGoingWork/PathFollowingRRS/line/container.m"),
                  "context", "context", 2);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut("mpower"), "name", "name", 2);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 2);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mpower.m"), "resolved",
                  "resolved", 2);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(1363688678U), "fileTimeLo",
                  "fileTimeLo", 2);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 2);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 2);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 2);
  sf_mex_assign(&c5_rhs2, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c5_lhs2, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_rhs2), "rhs", "rhs", 2);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_lhs2), "lhs", "lhs", 2);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mpower.m"), "context",
                  "context", 3);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 3);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 3);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 3);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(1363689356U), "fileTimeLo",
                  "fileTimeLo", 3);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 3);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 3);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 3);
  sf_mex_assign(&c5_rhs3, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c5_lhs3, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_rhs3), "rhs", "rhs", 3);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_lhs3), "lhs", "lhs", 3);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mpower.m"), "context",
                  "context", 4);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut("ismatrix"), "name", "name", 4);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 4);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/ismatrix.m"), "resolved",
                  "resolved", 4);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(1331279658U), "fileTimeLo",
                  "fileTimeLo", 4);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 4);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 4);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 4);
  sf_mex_assign(&c5_rhs4, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c5_lhs4, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_rhs4), "rhs", "rhs", 4);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_lhs4), "lhs", "lhs", 4);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mpower.m"), "context",
                  "context", 5);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut("power"), "name", "name", 5);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 5);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m"), "resolved",
                  "resolved", 5);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(1363688680U), "fileTimeLo",
                  "fileTimeLo", 5);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 5);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 5);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 5);
  sf_mex_assign(&c5_rhs5, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c5_lhs5, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_rhs5), "rhs", "rhs", 5);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_lhs5), "lhs", "lhs", 5);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m"), "context",
                  "context", 6);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 6);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 6);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 6);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(1363689356U), "fileTimeLo",
                  "fileTimeLo", 6);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 6);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 6);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 6);
  sf_mex_assign(&c5_rhs6, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c5_lhs6, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_rhs6), "rhs", "rhs", 6);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_lhs6), "lhs", "lhs", 6);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m!fltpower"), "context",
                  "context", 7);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut("eml_scalar_eg"), "name",
                  "name", 7);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 7);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m"), "resolved",
                  "resolved", 7);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(1375959088U), "fileTimeLo",
                  "fileTimeLo", 7);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 7);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 7);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 7);
  sf_mex_assign(&c5_rhs7, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c5_lhs7, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_rhs7), "rhs", "rhs", 7);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_lhs7), "lhs", "lhs", 7);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m"), "context",
                  "context", 8);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut("coder.internal.scalarEg"),
                  "name", "name", 8);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 8);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/scalarEg.p"),
                  "resolved", "resolved", 8);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(1389282720U), "fileTimeLo",
                  "fileTimeLo", 8);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 8);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 8);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 8);
  sf_mex_assign(&c5_rhs8, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c5_lhs8, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_rhs8), "rhs", "rhs", 8);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_lhs8), "lhs", "lhs", 8);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m!fltpower"), "context",
                  "context", 9);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut("eml_scalexp_alloc"), "name",
                  "name", 9);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 9);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalexp_alloc.m"),
                  "resolved", "resolved", 9);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(1375959088U), "fileTimeLo",
                  "fileTimeLo", 9);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 9);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 9);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 9);
  sf_mex_assign(&c5_rhs9, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c5_lhs9, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_rhs9), "rhs", "rhs", 9);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_lhs9), "lhs", "lhs", 9);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalexp_alloc.m"),
                  "context", "context", 10);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut("coder.internal.scalexpAlloc"),
                  "name", "name", 10);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 10);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/scalexpAlloc.p"),
                  "resolved", "resolved", 10);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(1389282720U), "fileTimeLo",
                  "fileTimeLo", 10);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 10);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 10);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 10);
  sf_mex_assign(&c5_rhs10, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c5_lhs10, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_rhs10), "rhs", "rhs",
                  10);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_lhs10), "lhs", "lhs",
                  10);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m!fltpower"), "context",
                  "context", 11);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut("floor"), "name", "name", 11);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 11);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/floor.m"), "resolved",
                  "resolved", 11);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(1363688654U), "fileTimeLo",
                  "fileTimeLo", 11);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 11);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 11);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 11);
  sf_mex_assign(&c5_rhs11, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c5_lhs11, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_rhs11), "rhs", "rhs",
                  11);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_lhs11), "lhs", "lhs",
                  11);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/floor.m"), "context",
                  "context", 12);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 12);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 12);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 12);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(1363689356U), "fileTimeLo",
                  "fileTimeLo", 12);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 12);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 12);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 12);
  sf_mex_assign(&c5_rhs12, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c5_lhs12, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_rhs12), "rhs", "rhs",
                  12);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_lhs12), "lhs", "lhs",
                  12);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/floor.m"), "context",
                  "context", 13);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut("eml_scalar_floor"), "name",
                  "name", 13);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 13);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_floor.m"),
                  "resolved", "resolved", 13);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(1286797126U), "fileTimeLo",
                  "fileTimeLo", 13);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 13);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 13);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 13);
  sf_mex_assign(&c5_rhs13, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c5_lhs13, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_rhs13), "rhs", "rhs",
                  13);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_lhs13), "lhs", "lhs",
                  13);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m!scalar_float_power"),
                  "context", "context", 14);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut("eml_scalar_eg"), "name",
                  "name", 14);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 14);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m"), "resolved",
                  "resolved", 14);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(1375959088U), "fileTimeLo",
                  "fileTimeLo", 14);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 14);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 14);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 14);
  sf_mex_assign(&c5_rhs14, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c5_lhs14, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_rhs14), "rhs", "rhs",
                  14);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_lhs14), "lhs", "lhs",
                  14);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[E]/Users/dittoyi/DittoyiWorkSystem/scholar/OnGoingWork/PathFollowingRRS/line/container.m"),
                  "context", "context", 15);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut("sqrt"), "name", "name", 15);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 15);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/sqrt.m"), "resolved",
                  "resolved", 15);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(1343808786U), "fileTimeLo",
                  "fileTimeLo", 15);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 15);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 15);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 15);
  sf_mex_assign(&c5_rhs15, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c5_lhs15, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_rhs15), "rhs", "rhs",
                  15);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_lhs15), "lhs", "lhs",
                  15);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/sqrt.m"), "context",
                  "context", 16);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut("eml_error"), "name", "name",
                  16);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 16);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_error.m"), "resolved",
                  "resolved", 16);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(1343808758U), "fileTimeLo",
                  "fileTimeLo", 16);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 16);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 16);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 16);
  sf_mex_assign(&c5_rhs16, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c5_lhs16, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_rhs16), "rhs", "rhs",
                  16);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_lhs16), "lhs", "lhs",
                  16);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/sqrt.m"), "context",
                  "context", 17);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut("eml_scalar_sqrt"), "name",
                  "name", 17);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 17);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_sqrt.m"),
                  "resolved", "resolved", 17);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(1286797138U), "fileTimeLo",
                  "fileTimeLo", 17);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 17);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 17);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 17);
  sf_mex_assign(&c5_rhs17, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c5_lhs17, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_rhs17), "rhs", "rhs",
                  17);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_lhs17), "lhs", "lhs",
                  17);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[E]/Users/dittoyi/DittoyiWorkSystem/scholar/OnGoingWork/PathFollowingRRS/line/container.m"),
                  "context", "context", 18);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut("error"), "name", "name", 18);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 18);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/lang/error.m"), "resolved",
                  "resolved", 18);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(1319708366U), "fileTimeLo",
                  "fileTimeLo", 18);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 18);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 18);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 18);
  sf_mex_assign(&c5_rhs18, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c5_lhs18, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_rhs18), "rhs", "rhs",
                  18);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_lhs18), "lhs", "lhs",
                  18);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[E]/Users/dittoyi/DittoyiWorkSystem/scholar/OnGoingWork/PathFollowingRRS/line/container.m"),
                  "context", "context", 19);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut("mrdivide"), "name", "name", 19);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 19);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p"), "resolved",
                  "resolved", 19);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(1388434896U), "fileTimeLo",
                  "fileTimeLo", 19);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 19);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(1369988286U), "mFileTimeLo",
                  "mFileTimeLo", 19);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 19);
  sf_mex_assign(&c5_rhs19, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c5_lhs19, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_rhs19), "rhs", "rhs",
                  19);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_lhs19), "lhs", "lhs",
                  19);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p"), "context",
                  "context", 20);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut("coder.internal.assert"),
                  "name", "name", 20);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 20);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/assert.m"),
                  "resolved", "resolved", 20);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(1363689356U), "fileTimeLo",
                  "fileTimeLo", 20);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 20);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 20);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 20);
  sf_mex_assign(&c5_rhs20, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c5_lhs20, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_rhs20), "rhs", "rhs",
                  20);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_lhs20), "lhs", "lhs",
                  20);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p"), "context",
                  "context", 21);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut("rdivide"), "name", "name", 21);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 21);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m"), "resolved",
                  "resolved", 21);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(1363688680U), "fileTimeLo",
                  "fileTimeLo", 21);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 21);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 21);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 21);
  sf_mex_assign(&c5_rhs21, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c5_lhs21, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_rhs21), "rhs", "rhs",
                  21);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_lhs21), "lhs", "lhs",
                  21);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m"), "context",
                  "context", 22);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 22);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 22);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 22);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(1363689356U), "fileTimeLo",
                  "fileTimeLo", 22);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 22);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 22);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 22);
  sf_mex_assign(&c5_rhs22, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c5_lhs22, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_rhs22), "rhs", "rhs",
                  22);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_lhs22), "lhs", "lhs",
                  22);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m"), "context",
                  "context", 23);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut("eml_scalexp_compatible"),
                  "name", "name", 23);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 23);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalexp_compatible.m"),
                  "resolved", "resolved", 23);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(1286797196U), "fileTimeLo",
                  "fileTimeLo", 23);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 23);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 23);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 23);
  sf_mex_assign(&c5_rhs23, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c5_lhs23, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_rhs23), "rhs", "rhs",
                  23);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_lhs23), "lhs", "lhs",
                  23);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m"), "context",
                  "context", 24);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut("eml_div"), "name", "name", 24);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 24);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_div.m"), "resolved",
                  "resolved", 24);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(1375959088U), "fileTimeLo",
                  "fileTimeLo", 24);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 24);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 24);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 24);
  sf_mex_assign(&c5_rhs24, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c5_lhs24, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_rhs24), "rhs", "rhs",
                  24);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_lhs24), "lhs", "lhs",
                  24);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_div.m"), "context",
                  "context", 25);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut("coder.internal.div"), "name",
                  "name", 25);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 25);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/div.p"), "resolved",
                  "resolved", 25);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(1389282720U), "fileTimeLo",
                  "fileTimeLo", 25);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 25);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 25);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 25);
  sf_mex_assign(&c5_rhs25, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c5_lhs25, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_rhs25), "rhs", "rhs",
                  25);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_lhs25), "lhs", "lhs",
                  25);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[E]/Users/dittoyi/DittoyiWorkSystem/scholar/OnGoingWork/PathFollowingRRS/line/container.m"),
                  "context", "context", 26);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut("abs"), "name", "name", 26);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 26);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m"), "resolved",
                  "resolved", 26);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(1363688652U), "fileTimeLo",
                  "fileTimeLo", 26);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 26);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 26);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 26);
  sf_mex_assign(&c5_rhs26, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c5_lhs26, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_rhs26), "rhs", "rhs",
                  26);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_lhs26), "lhs", "lhs",
                  26);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m"), "context",
                  "context", 27);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 27);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 27);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 27);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(1363689356U), "fileTimeLo",
                  "fileTimeLo", 27);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 27);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 27);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 27);
  sf_mex_assign(&c5_rhs27, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c5_lhs27, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_rhs27), "rhs", "rhs",
                  27);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_lhs27), "lhs", "lhs",
                  27);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m"), "context",
                  "context", 28);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut("eml_scalar_abs"), "name",
                  "name", 28);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 28);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_abs.m"),
                  "resolved", "resolved", 28);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(1286797112U), "fileTimeLo",
                  "fileTimeLo", 28);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 28);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 28);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 28);
  sf_mex_assign(&c5_rhs28, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c5_lhs28, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_rhs28), "rhs", "rhs",
                  28);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_lhs28), "lhs", "lhs",
                  28);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[E]/Users/dittoyi/DittoyiWorkSystem/scholar/OnGoingWork/PathFollowingRRS/line/container.m"),
                  "context", "context", 29);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut("sign"), "name", "name", 29);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 29);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/sign.m"), "resolved",
                  "resolved", 29);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(1363688656U), "fileTimeLo",
                  "fileTimeLo", 29);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 29);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 29);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 29);
  sf_mex_assign(&c5_rhs29, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c5_lhs29, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_rhs29), "rhs", "rhs",
                  29);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_lhs29), "lhs", "lhs",
                  29);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/sign.m"), "context",
                  "context", 30);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 30);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 30);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 30);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(1363689356U), "fileTimeLo",
                  "fileTimeLo", 30);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 30);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 30);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 30);
  sf_mex_assign(&c5_rhs30, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c5_lhs30, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_rhs30), "rhs", "rhs",
                  30);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_lhs30), "lhs", "lhs",
                  30);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/sign.m"), "context",
                  "context", 31);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut("eml_scalar_sign"), "name",
                  "name", 31);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 31);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_sign.m"),
                  "resolved", "resolved", 31);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(1356516294U), "fileTimeLo",
                  "fileTimeLo", 31);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 31);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 31);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 31);
  sf_mex_assign(&c5_rhs31, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c5_lhs31, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_rhs31), "rhs", "rhs",
                  31);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_lhs31), "lhs", "lhs",
                  31);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[E]/Users/dittoyi/DittoyiWorkSystem/scholar/OnGoingWork/PathFollowingRRS/line/container.m"),
                  "context", "context", 32);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut("cos"), "name", "name", 32);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 32);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/cos.m"), "resolved",
                  "resolved", 32);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(1343808772U), "fileTimeLo",
                  "fileTimeLo", 32);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 32);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 32);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 32);
  sf_mex_assign(&c5_rhs32, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c5_lhs32, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_rhs32), "rhs", "rhs",
                  32);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_lhs32), "lhs", "lhs",
                  32);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/cos.m"), "context",
                  "context", 33);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut("eml_scalar_cos"), "name",
                  "name", 33);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 33);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_cos.m"),
                  "resolved", "resolved", 33);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(1286797122U), "fileTimeLo",
                  "fileTimeLo", 33);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 33);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 33);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 33);
  sf_mex_assign(&c5_rhs33, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c5_lhs33, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_rhs33), "rhs", "rhs",
                  33);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_lhs33), "lhs", "lhs",
                  33);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[E]/Users/dittoyi/DittoyiWorkSystem/scholar/OnGoingWork/PathFollowingRRS/line/container.m"),
                  "context", "context", 34);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut("atan"), "name", "name", 34);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 34);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/atan.m"), "resolved",
                  "resolved", 34);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(1343808772U), "fileTimeLo",
                  "fileTimeLo", 34);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 34);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 34);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 34);
  sf_mex_assign(&c5_rhs34, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c5_lhs34, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_rhs34), "rhs", "rhs",
                  34);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_lhs34), "lhs", "lhs",
                  34);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/atan.m"), "context",
                  "context", 35);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut("eml_scalar_atan"), "name",
                  "name", 35);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 35);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_atan.m"),
                  "resolved", "resolved", 35);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(1286797118U), "fileTimeLo",
                  "fileTimeLo", 35);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 35);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 35);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 35);
  sf_mex_assign(&c5_rhs35, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c5_lhs35, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_rhs35), "rhs", "rhs",
                  35);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_lhs35), "lhs", "lhs",
                  35);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[E]/Users/dittoyi/DittoyiWorkSystem/scholar/OnGoingWork/PathFollowingRRS/line/container.m"),
                  "context", "context", 36);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut("sin"), "name", "name", 36);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 36);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/sin.m"), "resolved",
                  "resolved", 36);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(1343808786U), "fileTimeLo",
                  "fileTimeLo", 36);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 36);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 36);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 36);
  sf_mex_assign(&c5_rhs36, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c5_lhs36, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_rhs36), "rhs", "rhs",
                  36);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_lhs36), "lhs", "lhs",
                  36);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/sin.m"), "context",
                  "context", 37);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut("eml_scalar_sin"), "name",
                  "name", 37);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 37);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_sin.m"),
                  "resolved", "resolved", 37);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(1286797136U), "fileTimeLo",
                  "fileTimeLo", 37);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 37);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 37);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 37);
  sf_mex_assign(&c5_rhs37, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c5_lhs37, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_rhs37), "rhs", "rhs",
                  37);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_lhs37), "lhs", "lhs",
                  37);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(""), "context", "context", 38);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut("mrdivide"), "name", "name", 38);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 38);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p"), "resolved",
                  "resolved", 38);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(1388434896U), "fileTimeLo",
                  "fileTimeLo", 38);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 38);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(1369988286U), "mFileTimeLo",
                  "mFileTimeLo", 38);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 38);
  sf_mex_assign(&c5_rhs38, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c5_lhs38, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_rhs38), "rhs", "rhs",
                  38);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_lhs38), "lhs", "lhs",
                  38);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(""), "context", "context", 39);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut("eml_mtimes_helper"), "name",
                  "name", 39);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 39);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/eml_mtimes_helper.m"),
                  "resolved", "resolved", 39);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(1383852094U), "fileTimeLo",
                  "fileTimeLo", 39);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 39);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 39);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 39);
  sf_mex_assign(&c5_rhs39, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c5_lhs39, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_rhs39), "rhs", "rhs",
                  39);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_lhs39), "lhs", "lhs",
                  39);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/eml_mtimes_helper.m!common_checks"),
                  "context", "context", 40);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 40);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 40);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 40);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(1363689356U), "fileTimeLo",
                  "fileTimeLo", 40);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 40);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 40);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 40);
  sf_mex_assign(&c5_rhs40, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c5_lhs40, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_rhs40), "rhs", "rhs",
                  40);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_lhs40), "lhs", "lhs",
                  40);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(""), "context", "context", 41);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut("atan"), "name", "name", 41);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 41);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/atan.m"), "resolved",
                  "resolved", 41);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(1343808772U), "fileTimeLo",
                  "fileTimeLo", 41);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 41);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 41);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 41);
  sf_mex_assign(&c5_rhs41, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c5_lhs41, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_rhs41), "rhs", "rhs",
                  41);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_lhs41), "lhs", "lhs",
                  41);
  sf_mex_destroy(&c5_rhs0);
  sf_mex_destroy(&c5_lhs0);
  sf_mex_destroy(&c5_rhs1);
  sf_mex_destroy(&c5_lhs1);
  sf_mex_destroy(&c5_rhs2);
  sf_mex_destroy(&c5_lhs2);
  sf_mex_destroy(&c5_rhs3);
  sf_mex_destroy(&c5_lhs3);
  sf_mex_destroy(&c5_rhs4);
  sf_mex_destroy(&c5_lhs4);
  sf_mex_destroy(&c5_rhs5);
  sf_mex_destroy(&c5_lhs5);
  sf_mex_destroy(&c5_rhs6);
  sf_mex_destroy(&c5_lhs6);
  sf_mex_destroy(&c5_rhs7);
  sf_mex_destroy(&c5_lhs7);
  sf_mex_destroy(&c5_rhs8);
  sf_mex_destroy(&c5_lhs8);
  sf_mex_destroy(&c5_rhs9);
  sf_mex_destroy(&c5_lhs9);
  sf_mex_destroy(&c5_rhs10);
  sf_mex_destroy(&c5_lhs10);
  sf_mex_destroy(&c5_rhs11);
  sf_mex_destroy(&c5_lhs11);
  sf_mex_destroy(&c5_rhs12);
  sf_mex_destroy(&c5_lhs12);
  sf_mex_destroy(&c5_rhs13);
  sf_mex_destroy(&c5_lhs13);
  sf_mex_destroy(&c5_rhs14);
  sf_mex_destroy(&c5_lhs14);
  sf_mex_destroy(&c5_rhs15);
  sf_mex_destroy(&c5_lhs15);
  sf_mex_destroy(&c5_rhs16);
  sf_mex_destroy(&c5_lhs16);
  sf_mex_destroy(&c5_rhs17);
  sf_mex_destroy(&c5_lhs17);
  sf_mex_destroy(&c5_rhs18);
  sf_mex_destroy(&c5_lhs18);
  sf_mex_destroy(&c5_rhs19);
  sf_mex_destroy(&c5_lhs19);
  sf_mex_destroy(&c5_rhs20);
  sf_mex_destroy(&c5_lhs20);
  sf_mex_destroy(&c5_rhs21);
  sf_mex_destroy(&c5_lhs21);
  sf_mex_destroy(&c5_rhs22);
  sf_mex_destroy(&c5_lhs22);
  sf_mex_destroy(&c5_rhs23);
  sf_mex_destroy(&c5_lhs23);
  sf_mex_destroy(&c5_rhs24);
  sf_mex_destroy(&c5_lhs24);
  sf_mex_destroy(&c5_rhs25);
  sf_mex_destroy(&c5_lhs25);
  sf_mex_destroy(&c5_rhs26);
  sf_mex_destroy(&c5_lhs26);
  sf_mex_destroy(&c5_rhs27);
  sf_mex_destroy(&c5_lhs27);
  sf_mex_destroy(&c5_rhs28);
  sf_mex_destroy(&c5_lhs28);
  sf_mex_destroy(&c5_rhs29);
  sf_mex_destroy(&c5_lhs29);
  sf_mex_destroy(&c5_rhs30);
  sf_mex_destroy(&c5_lhs30);
  sf_mex_destroy(&c5_rhs31);
  sf_mex_destroy(&c5_lhs31);
  sf_mex_destroy(&c5_rhs32);
  sf_mex_destroy(&c5_lhs32);
  sf_mex_destroy(&c5_rhs33);
  sf_mex_destroy(&c5_lhs33);
  sf_mex_destroy(&c5_rhs34);
  sf_mex_destroy(&c5_lhs34);
  sf_mex_destroy(&c5_rhs35);
  sf_mex_destroy(&c5_lhs35);
  sf_mex_destroy(&c5_rhs36);
  sf_mex_destroy(&c5_lhs36);
  sf_mex_destroy(&c5_rhs37);
  sf_mex_destroy(&c5_lhs37);
  sf_mex_destroy(&c5_rhs38);
  sf_mex_destroy(&c5_lhs38);
  sf_mex_destroy(&c5_rhs39);
  sf_mex_destroy(&c5_lhs39);
  sf_mex_destroy(&c5_rhs40);
  sf_mex_destroy(&c5_lhs40);
  sf_mex_destroy(&c5_rhs41);
  sf_mex_destroy(&c5_lhs41);
}

static const mxArray *c5_emlrt_marshallOut(const char * c5_u)
{
  const mxArray *c5_y = NULL;
  c5_y = NULL;
  sf_mex_assign(&c5_y, sf_mex_create("y", c5_u, 15, 0U, 0U, 0U, 2, 1, strlen
    (c5_u)), false);
  return c5_y;
}

static const mxArray *c5_b_emlrt_marshallOut(const uint32_T c5_u)
{
  const mxArray *c5_y = NULL;
  c5_y = NULL;
  sf_mex_assign(&c5_y, sf_mex_create("y", &c5_u, 7, 0U, 0U, 0U, 0), false);
  return c5_y;
}

static real_T c5_mpower(SFc5_untitled2InstanceStruct *chartInstance, real_T c5_a)
{
  real_T c5_b_a;
  real_T c5_c_a;
  real_T c5_ak;
  real_T c5_d_a;
  c5_b_a = c5_a;
  c5_c_a = c5_b_a;
  c5_eml_scalar_eg(chartInstance);
  c5_ak = c5_c_a;
  c5_d_a = c5_ak;
  c5_eml_scalar_eg(chartInstance);
  return c5_d_a * c5_d_a;
}

static void c5_eml_scalar_eg(SFc5_untitled2InstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static real_T c5_sqrt(SFc5_untitled2InstanceStruct *chartInstance, real_T c5_x)
{
  real_T c5_b_x;
  c5_b_x = c5_x;
  c5_b_sqrt(chartInstance, &c5_b_x);
  return c5_b_x;
}

static void c5_eml_error(SFc5_untitled2InstanceStruct *chartInstance)
{
  int32_T c5_i51;
  static char_T c5_cv0[30] = { 'C', 'o', 'd', 'e', 'r', ':', 't', 'o', 'o', 'l',
    'b', 'o', 'x', ':', 'E', 'l', 'F', 'u', 'n', 'D', 'o', 'm', 'a', 'i', 'n',
    'E', 'r', 'r', 'o', 'r' };

  char_T c5_u[30];
  const mxArray *c5_y = NULL;
  int32_T c5_i52;
  static char_T c5_cv1[4] = { 's', 'q', 'r', 't' };

  char_T c5_b_u[4];
  const mxArray *c5_b_y = NULL;
  (void)chartInstance;
  for (c5_i51 = 0; c5_i51 < 30; c5_i51++) {
    c5_u[c5_i51] = c5_cv0[c5_i51];
  }

  c5_y = NULL;
  sf_mex_assign(&c5_y, sf_mex_create("y", c5_u, 10, 0U, 1U, 0U, 2, 1, 30), false);
  for (c5_i52 = 0; c5_i52 < 4; c5_i52++) {
    c5_b_u[c5_i52] = c5_cv1[c5_i52];
  }

  c5_b_y = NULL;
  sf_mex_assign(&c5_b_y, sf_mex_create("y", c5_b_u, 10, 0U, 1U, 0U, 2, 1, 4),
                false);
  sf_mex_call_debug(sfGlobalDebugInstanceStruct, "error", 0U, 1U, 14,
                    sf_mex_call_debug(sfGlobalDebugInstanceStruct, "message", 1U,
    2U, 14, c5_y, 14, c5_b_y));
}

static real_T c5_abs(SFc5_untitled2InstanceStruct *chartInstance, real_T c5_x)
{
  real_T c5_b_x;
  (void)chartInstance;
  c5_b_x = c5_x;
  return muDoubleScalarAbs(c5_b_x);
}

static real_T c5_sign(SFc5_untitled2InstanceStruct *chartInstance, real_T c5_x)
{
  real_T c5_b_x;
  c5_b_x = c5_x;
  c5_b_sign(chartInstance, &c5_b_x);
  return c5_b_x;
}

static real_T c5_b_mpower(SFc5_untitled2InstanceStruct *chartInstance, real_T
  c5_a)
{
  real_T c5_b_a;
  real_T c5_c_a;
  real_T c5_ak;
  real_T c5_d_a;
  real_T c5_ar;
  c5_b_a = c5_a;
  c5_c_a = c5_b_a;
  c5_eml_scalar_eg(chartInstance);
  c5_ak = c5_c_a;
  c5_d_a = c5_ak;
  c5_eml_scalar_eg(chartInstance);
  c5_ar = c5_d_a;
  return muDoubleScalarPower(c5_ar, 3.0);
}

static const mxArray *c5_d_sf_marshallOut(void *chartInstanceVoid, void
  *c5_inData)
{
  const mxArray *c5_mxArrayOutData = NULL;
  int32_T c5_u;
  const mxArray *c5_y = NULL;
  SFc5_untitled2InstanceStruct *chartInstance;
  chartInstance = (SFc5_untitled2InstanceStruct *)chartInstanceVoid;
  c5_mxArrayOutData = NULL;
  c5_u = *(int32_T *)c5_inData;
  c5_y = NULL;
  sf_mex_assign(&c5_y, sf_mex_create("y", &c5_u, 6, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c5_mxArrayOutData, c5_y, false);
  return c5_mxArrayOutData;
}

static int32_T c5_f_emlrt_marshallIn(SFc5_untitled2InstanceStruct *chartInstance,
  const mxArray *c5_u, const emlrtMsgIdentifier *c5_parentId)
{
  int32_T c5_y;
  int32_T c5_i53;
  (void)chartInstance;
  sf_mex_import(c5_parentId, sf_mex_dup(c5_u), &c5_i53, 1, 6, 0U, 0, 0U, 0);
  c5_y = c5_i53;
  sf_mex_destroy(&c5_u);
  return c5_y;
}

static void c5_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c5_mxArrayInData, const char_T *c5_varName, void *c5_outData)
{
  const mxArray *c5_b_sfEvent;
  const char_T *c5_identifier;
  emlrtMsgIdentifier c5_thisId;
  int32_T c5_y;
  SFc5_untitled2InstanceStruct *chartInstance;
  chartInstance = (SFc5_untitled2InstanceStruct *)chartInstanceVoid;
  c5_b_sfEvent = sf_mex_dup(c5_mxArrayInData);
  c5_identifier = c5_varName;
  c5_thisId.fIdentifier = c5_identifier;
  c5_thisId.fParent = NULL;
  c5_y = c5_f_emlrt_marshallIn(chartInstance, sf_mex_dup(c5_b_sfEvent),
    &c5_thisId);
  sf_mex_destroy(&c5_b_sfEvent);
  *(int32_T *)c5_outData = c5_y;
  sf_mex_destroy(&c5_mxArrayInData);
}

static uint8_T c5_g_emlrt_marshallIn(SFc5_untitled2InstanceStruct *chartInstance,
  const mxArray *c5_b_is_active_c5_untitled2, const char_T *c5_identifier)
{
  uint8_T c5_y;
  emlrtMsgIdentifier c5_thisId;
  c5_thisId.fIdentifier = c5_identifier;
  c5_thisId.fParent = NULL;
  c5_y = c5_h_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c5_b_is_active_c5_untitled2), &c5_thisId);
  sf_mex_destroy(&c5_b_is_active_c5_untitled2);
  return c5_y;
}

static uint8_T c5_h_emlrt_marshallIn(SFc5_untitled2InstanceStruct *chartInstance,
  const mxArray *c5_u, const emlrtMsgIdentifier *c5_parentId)
{
  uint8_T c5_y;
  uint8_T c5_u0;
  (void)chartInstance;
  sf_mex_import(c5_parentId, sf_mex_dup(c5_u), &c5_u0, 1, 3, 0U, 0, 0U, 0);
  c5_y = c5_u0;
  sf_mex_destroy(&c5_u);
  return c5_y;
}

static void c5_b_sqrt(SFc5_untitled2InstanceStruct *chartInstance, real_T *c5_x)
{
  if (*c5_x < 0.0) {
    c5_eml_error(chartInstance);
  }

  *c5_x = muDoubleScalarSqrt(*c5_x);
}

static void c5_b_sign(SFc5_untitled2InstanceStruct *chartInstance, real_T *c5_x)
{
  (void)chartInstance;
  *c5_x = muDoubleScalarSign(*c5_x);
}

static void init_dsm_address_info(SFc5_untitled2InstanceStruct *chartInstance)
{
  (void)chartInstance;
}

/* SFunction Glue Code */
#ifdef utFree
#undef utFree
#endif

#ifdef utMalloc
#undef utMalloc
#endif

#ifdef __cplusplus

extern "C" void *utMalloc(size_t size);
extern "C" void utFree(void*);

#else

extern void *utMalloc(size_t size);
extern void utFree(void*);

#endif

void sf_c5_untitled2_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(1221949514U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(3376946139U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(217238082U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(654061693U);
}

mxArray *sf_c5_untitled2_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1,1,5,
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateString("Z1yGcNBgvCfzDaUZjxLGJ");
    mxSetField(mxAutoinheritanceInfo,0,"checksum",mxChecksum);
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,3,3,dataFields);

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(2);
      pr[1] = (double)(1);
      mxSetField(mxData,0,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,0,"type",mxType);
    }

    mxSetField(mxData,0,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,1,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,1,"type",mxType);
    }

    mxSetField(mxData,1,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(10);
      pr[1] = (double)(1);
      mxSetField(mxData,2,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,2,"type",mxType);
    }

    mxSetField(mxData,2,"complexity",mxCreateDoubleScalar(0));
    mxSetField(mxAutoinheritanceInfo,0,"inputs",mxData);
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,2,3,dataFields);

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,0,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,0,"type",mxType);
    }

    mxSetField(mxData,0,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,1,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,1,"type",mxType);
    }

    mxSetField(mxData,1,"complexity",mxCreateDoubleScalar(0));
    mxSetField(mxAutoinheritanceInfo,0,"parameters",mxData);
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,3,3,dataFields);

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(10);
      pr[1] = (double)(1);
      mxSetField(mxData,0,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,0,"type",mxType);
    }

    mxSetField(mxData,0,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,1,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,1,"type",mxType);
    }

    mxSetField(mxData,1,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,2,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,2,"type",mxType);
    }

    mxSetField(mxData,2,"complexity",mxCreateDoubleScalar(0));
    mxSetField(mxAutoinheritanceInfo,0,"outputs",mxData);
  }

  {
    mxSetField(mxAutoinheritanceInfo,0,"locals",mxCreateDoubleMatrix(0,0,mxREAL));
  }

  return(mxAutoinheritanceInfo);
}

mxArray *sf_c5_untitled2_third_party_uses_info(void)
{
  mxArray * mxcell3p = mxCreateCellMatrix(1,0);
  return(mxcell3p);
}

mxArray *sf_c5_untitled2_updateBuildInfo_args_info(void)
{
  mxArray *mxBIArgs = mxCreateCellMatrix(1,0);
  return mxBIArgs;
}

static const mxArray *sf_get_sim_state_info_c5_untitled2(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x4'type','srcId','name','auxInfo'{{M[1],M[9],T\"Theta_wo\",},{M[1],M[7],T\"U\",},{M[1],M[5],T\"x_next\",},{M[8],M[0],T\"is_active_c5_untitled2\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 4, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c5_untitled2_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc5_untitled2InstanceStruct *chartInstance;
    ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
    ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
    chartInstance = (SFc5_untitled2InstanceStruct *) chartInfo->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (sfGlobalDebugInstanceStruct,
           _untitled2MachineNumber_,
           5,
           1,
           1,
           0,
           8,
           0,
           0,
           0,
           0,
           1,
           &(chartInstance->chartNumber),
           &(chartInstance->instanceNumber),
           (void *)S);

        /* Each instance must initialize ist own list of scripts */
        init_script_number_translation(_untitled2MachineNumber_,
          chartInstance->chartNumber,chartInstance->instanceNumber);
        if (chartAlreadyPresent==0) {
          /* this is the first instance */
          sf_debug_set_chart_disable_implicit_casting
            (sfGlobalDebugInstanceStruct,_untitled2MachineNumber_,
             chartInstance->chartNumber,1);
          sf_debug_set_chart_event_thresholds(sfGlobalDebugInstanceStruct,
            _untitled2MachineNumber_,
            chartInstance->chartNumber,
            0,
            0,
            0);
          _SFD_SET_DATA_PROPS(0,1,1,0,"NOISE");
          _SFD_SET_DATA_PROPS(1,2,0,1,"x_next");
          _SFD_SET_DATA_PROPS(2,1,1,0,"ui");
          _SFD_SET_DATA_PROPS(3,2,0,1,"U");
          _SFD_SET_DATA_PROPS(4,2,0,1,"Theta_wo");
          _SFD_SET_DATA_PROPS(5,10,0,0,"U0");
          _SFD_SET_DATA_PROPS(6,10,0,0,"h");
          _SFD_SET_DATA_PROPS(7,1,1,0,"x");
          _SFD_STATE_INFO(0,0,2);
          _SFD_CH_SUBSTATE_COUNT(0);
          _SFD_CH_SUBSTATE_DECOMP(0);
        }

        _SFD_CV_INIT_CHART(0,0,0,0);

        {
          _SFD_CV_INIT_STATE(0,0,0,0,0,0,NULL,NULL);
        }

        _SFD_CV_INIT_TRANS(0,0,NULL,NULL,0,NULL);

        /* Initialization of MATLAB Function Model Coverage */
        _SFD_CV_INIT_EML(0,1,1,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_FCN(0,0,"eML_blk_kernel",0,-1,880);
        _SFD_CV_INIT_SCRIPT(0,1,8,0,0,0,0,0,0,0);
        _SFD_CV_INIT_SCRIPT_FCN(0,0,"container",0,-1,7343);
        _SFD_CV_INIT_SCRIPT_IF(0,0,2279,2299,-1,2346);
        _SFD_CV_INIT_SCRIPT_IF(0,1,2347,2367,-1,2414);
        _SFD_CV_INIT_SCRIPT_IF(0,2,2566,2575,-1,2631);
        _SFD_CV_INIT_SCRIPT_IF(0,3,2632,2645,-1,2702);
        _SFD_CV_INIT_SCRIPT_IF(0,4,5010,5045,-1,5095);
        _SFD_CV_INIT_SCRIPT_IF(0,5,5126,5164,-1,5219);
        _SFD_CV_INIT_SCRIPT_IF(0,6,5290,5313,-1,5347);
        _SFD_CV_INIT_SCRIPT_IF(0,7,5349,5359,5370,5387);

        {
          unsigned int dimVector[1];
          dimVector[0]= 2;
          _SFD_SET_DATA_COMPILED_PROPS(0,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c5_c_sf_marshallOut,(MexInFcnForType)NULL);
        }

        {
          unsigned int dimVector[1];
          dimVector[0]= 10;
          _SFD_SET_DATA_COMPILED_PROPS(1,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c5_b_sf_marshallOut,(MexInFcnForType)
            c5_b_sf_marshallIn);
        }

        _SFD_SET_DATA_COMPILED_PROPS(2,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c5_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(3,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c5_sf_marshallOut,(MexInFcnForType)c5_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(4,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c5_sf_marshallOut,(MexInFcnForType)c5_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(5,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c5_sf_marshallOut,(MexInFcnForType)c5_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(6,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c5_sf_marshallOut,(MexInFcnForType)c5_sf_marshallIn);

        {
          unsigned int dimVector[1];
          dimVector[0]= 10;
          _SFD_SET_DATA_COMPILED_PROPS(7,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c5_b_sf_marshallOut,(MexInFcnForType)NULL);
        }

        {
          real_T *c5_ui;
          real_T *c5_U;
          real_T *c5_Theta_wo;
          real_T (*c5_NOISE)[2];
          real_T (*c5_x_next)[10];
          real_T (*c5_x)[10];
          c5_x = (real_T (*)[10])ssGetInputPortSignal(chartInstance->S, 2);
          c5_Theta_wo = (real_T *)ssGetOutputPortSignal(chartInstance->S, 3);
          c5_U = (real_T *)ssGetOutputPortSignal(chartInstance->S, 2);
          c5_ui = (real_T *)ssGetInputPortSignal(chartInstance->S, 1);
          c5_x_next = (real_T (*)[10])ssGetOutputPortSignal(chartInstance->S, 1);
          c5_NOISE = (real_T (*)[2])ssGetInputPortSignal(chartInstance->S, 0);
          _SFD_SET_DATA_VALUE_PTR(0U, *c5_NOISE);
          _SFD_SET_DATA_VALUE_PTR(1U, *c5_x_next);
          _SFD_SET_DATA_VALUE_PTR(2U, c5_ui);
          _SFD_SET_DATA_VALUE_PTR(3U, c5_U);
          _SFD_SET_DATA_VALUE_PTR(4U, c5_Theta_wo);
          _SFD_SET_DATA_VALUE_PTR(5U, &chartInstance->c5_U0);
          _SFD_SET_DATA_VALUE_PTR(6U, &chartInstance->c5_h);
          _SFD_SET_DATA_VALUE_PTR(7U, *c5_x);
        }
      }
    } else {
      sf_debug_reset_current_state_configuration(sfGlobalDebugInstanceStruct,
        _untitled2MachineNumber_,chartInstance->chartNumber,
        chartInstance->instanceNumber);
    }
  }
}

static const char* sf_get_instance_specialization(void)
{
  return "sLhQqjFmWPu2K9ns3hdoCB";
}

static void sf_opaque_initialize_c5_untitled2(void *chartInstanceVar)
{
  chart_debug_initialization(((SFc5_untitled2InstanceStruct*) chartInstanceVar
    )->S,0);
  initialize_params_c5_untitled2((SFc5_untitled2InstanceStruct*)
    chartInstanceVar);
  initialize_c5_untitled2((SFc5_untitled2InstanceStruct*) chartInstanceVar);
}

static void sf_opaque_enable_c5_untitled2(void *chartInstanceVar)
{
  enable_c5_untitled2((SFc5_untitled2InstanceStruct*) chartInstanceVar);
}

static void sf_opaque_disable_c5_untitled2(void *chartInstanceVar)
{
  disable_c5_untitled2((SFc5_untitled2InstanceStruct*) chartInstanceVar);
}

static void sf_opaque_gateway_c5_untitled2(void *chartInstanceVar)
{
  sf_gateway_c5_untitled2((SFc5_untitled2InstanceStruct*) chartInstanceVar);
}

extern const mxArray* sf_internal_get_sim_state_c5_untitled2(SimStruct* S)
{
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
  ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_raw2high");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = (mxArray*) get_sim_state_c5_untitled2((SFc5_untitled2InstanceStruct*)
    chartInfo->chartInstance);         /* raw sim ctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c5_untitled2();/* state var info */
  mxError = sf_mex_call_matlab(1, plhs, 4, prhs, "sfprivate");
  mxDestroyArray(prhs[0]);
  mxDestroyArray(prhs[1]);
  mxDestroyArray(prhs[2]);
  mxDestroyArray(prhs[3]);
  if (mxError || plhs[0] == NULL) {
    sf_mex_error_message("Stateflow Internal Error: \nError calling 'chart_simctx_raw2high'.\n");
  }

  return plhs[0];
}

extern void sf_internal_set_sim_state_c5_untitled2(SimStruct* S, const mxArray
  *st)
{
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
  ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[3];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_high2raw");
  prhs[1] = mxDuplicateArray(st);      /* high level simctx */
  prhs[2] = (mxArray*) sf_get_sim_state_info_c5_untitled2();/* state var info */
  mxError = sf_mex_call_matlab(1, plhs, 3, prhs, "sfprivate");
  mxDestroyArray(prhs[0]);
  mxDestroyArray(prhs[1]);
  mxDestroyArray(prhs[2]);
  if (mxError || plhs[0] == NULL) {
    sf_mex_error_message("Stateflow Internal Error: \nError calling 'chart_simctx_high2raw'.\n");
  }

  set_sim_state_c5_untitled2((SFc5_untitled2InstanceStruct*)
    chartInfo->chartInstance, mxDuplicateArray(plhs[0]));
  mxDestroyArray(plhs[0]);
}

static const mxArray* sf_opaque_get_sim_state_c5_untitled2(SimStruct* S)
{
  return sf_internal_get_sim_state_c5_untitled2(S);
}

static void sf_opaque_set_sim_state_c5_untitled2(SimStruct* S, const mxArray *st)
{
  sf_internal_set_sim_state_c5_untitled2(S, st);
}

static void sf_opaque_terminate_c5_untitled2(void *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc5_untitled2InstanceStruct*) chartInstanceVar)->S;
    ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
      unload_untitled2_optimization_info();
    }

    finalize_c5_untitled2((SFc5_untitled2InstanceStruct*) chartInstanceVar);
    utFree((void *)chartInstanceVar);
    if (crtInfo != NULL) {
      utFree((void *)crtInfo);
    }

    ssSetUserData(S,NULL);
  }
}

static void sf_opaque_init_subchart_simstructs(void *chartInstanceVar)
{
  initSimStructsc5_untitled2((SFc5_untitled2InstanceStruct*) chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c5_untitled2(SimStruct *S)
{
  int i;
  for (i=0;i<ssGetNumRunTimeParams(S);i++) {
    if (ssGetSFcnParamTunable(S,i)) {
      ssUpdateDlgParamAsRunTimeParam(S,i);
    }
  }

  if (sf_machine_global_initializer_called()) {
    ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
    ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
    initialize_params_c5_untitled2((SFc5_untitled2InstanceStruct*)
      (chartInfo->chartInstance));
  }
}

static void mdlSetWorkWidths_c5_untitled2(SimStruct *S)
{
  /* Actual parameters from chart:
     U0 h
   */
  const char_T *rtParamNames[] = { "U0", "h" };

  ssSetNumRunTimeParams(S,ssGetSFcnParamsCount(S));

  /* registration for U0*/
  ssRegDlgParamAsRunTimeParam(S, 0, 0, rtParamNames[0], SS_DOUBLE);

  /* registration for h*/
  ssRegDlgParamAsRunTimeParam(S, 1, 1, rtParamNames[1], SS_DOUBLE);
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    mxArray *infoStruct = load_untitled2_optimization_info();
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable(sf_get_instance_specialization(),infoStruct,5);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop(sf_get_instance_specialization(),
                infoStruct,5,"RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop
      (sf_get_instance_specialization(),infoStruct,5,
       "gatewayCannotBeInlinedMultipleTimes"));
    sf_update_buildInfo(sf_get_instance_specialization(),infoStruct,5);
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 1, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 2, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,sf_get_instance_specialization(),
        infoStruct,5,3);
      sf_mark_chart_reusable_outputs(S,sf_get_instance_specialization(),
        infoStruct,5,3);
    }

    {
      unsigned int outPortIdx;
      for (outPortIdx=1; outPortIdx<=3; ++outPortIdx) {
        ssSetOutputPortOptimizeInIR(S, outPortIdx, 1U);
      }
    }

    {
      unsigned int inPortIdx;
      for (inPortIdx=0; inPortIdx < 3; ++inPortIdx) {
        ssSetInputPortOptimizeInIR(S, inPortIdx, 1U);
      }
    }

    sf_set_rtw_dwork_info(S,sf_get_instance_specialization(),infoStruct,5);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(2684232185U));
  ssSetChecksum1(S,(2769574693U));
  ssSetChecksum2(S,(3193246708U));
  ssSetChecksum3(S,(2453730938U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
  ssSupportsMultipleExecInstances(S,1);
}

static void mdlRTW_c5_untitled2(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c5_untitled2(SimStruct *S)
{
  SFc5_untitled2InstanceStruct *chartInstance;
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)utMalloc(sizeof
    (ChartRunTimeInfo));
  chartInstance = (SFc5_untitled2InstanceStruct *)utMalloc(sizeof
    (SFc5_untitled2InstanceStruct));
  memset(chartInstance, 0, sizeof(SFc5_untitled2InstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway = sf_opaque_gateway_c5_untitled2;
  chartInstance->chartInfo.initializeChart = sf_opaque_initialize_c5_untitled2;
  chartInstance->chartInfo.terminateChart = sf_opaque_terminate_c5_untitled2;
  chartInstance->chartInfo.enableChart = sf_opaque_enable_c5_untitled2;
  chartInstance->chartInfo.disableChart = sf_opaque_disable_c5_untitled2;
  chartInstance->chartInfo.getSimState = sf_opaque_get_sim_state_c5_untitled2;
  chartInstance->chartInfo.setSimState = sf_opaque_set_sim_state_c5_untitled2;
  chartInstance->chartInfo.getSimStateInfo = sf_get_sim_state_info_c5_untitled2;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c5_untitled2;
  chartInstance->chartInfo.mdlStart = mdlStart_c5_untitled2;
  chartInstance->chartInfo.mdlSetWorkWidths = mdlSetWorkWidths_c5_untitled2;
  chartInstance->chartInfo.extModeExec = NULL;
  chartInstance->chartInfo.restoreLastMajorStepConfiguration = NULL;
  chartInstance->chartInfo.restoreBeforeLastMajorStepConfiguration = NULL;
  chartInstance->chartInfo.storeCurrentConfiguration = NULL;
  chartInstance->chartInfo.debugInstance = sfGlobalDebugInstanceStruct;
  chartInstance->S = S;
  crtInfo->instanceInfo = (&(chartInstance->chartInfo));
  crtInfo->isJITEnabled = false;
  ssSetUserData(S,(void *)(crtInfo));  /* register the chart instance with simstruct */
  init_dsm_address_info(chartInstance);
  if (!sim_mode_is_rtw_gen(S)) {
  }

  sf_opaque_init_subchart_simstructs(chartInstance->chartInfo.chartInstance);
  chart_debug_initialization(S,1);
}

void c5_untitled2_method_dispatcher(SimStruct *S, int_T method, void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c5_untitled2(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c5_untitled2(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c5_untitled2(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c5_untitled2_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}

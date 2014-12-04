/* Include files */

#include "blascompat32.h"
#include "test_sfun.h"
#include "c5_test.h"
#include "mwmathutil.h"
#define CHARTINSTANCE_CHARTNUMBER      (chartInstance->chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER   (chartInstance->instanceNumber)
#include "test_sfun_debug_macros.h"

/* Type Definitions */

/* Named Constants */
#define CALL_EVENT                     (-1)

/* Variable Declarations */

/* Variable Definitions */
static const char * c5_debug_family_names[21] = { "k1", "U1", "k2", "U2", "k3",
  "U3", "k4", "U4", "ddd", "Theta_bo", "Theta_wb", "nargin", "nargout", "NOISE",
  "ui", "U0", "h", "x", "x_next", "U", "Theta_wo" };

static const char * c5_b_debug_family_names[75] = { "L", "delta_c", "u", "v",
  "r", "psi", "delta", "delta_max", "Ddelta_max", "m", "Iz", "xG", "Xudot",
  "Yvdot", "Nvdot", "Xu", "Yrdot", "Nrdot", "Xuu", "Yv", "Nv", "Xuuu", "Yr",
  "Nr", "Xvv", "Yvvv", "Nvvv", "Xrr", "Yvvr", "Nvvr", "Xdd", "Yvu", "Nvu",
  "Xudd", "Yru", "Nru", "Xrv", "Yd", "Nd", "Xvd", "Yddd", "Nddd", "Xuvd", "Yud",
  "Nud", "Yuud", "Nuud", "Yvdd", "Nvdd", "Yvvd", "Nvvd", "Y0", "N0", "Y0u",
  "N0u", "Y0uu", "N0uu", "m11", "m22", "m23", "m32", "m33", "delta_dot", "X",
  "Y", "N", "detM22", "nargin", "nargout", "x", "ui", "U0", "NOISE", "xdot", "U"
};

/* Function Declarations */
static void initialize_c5_test(SFc5_testInstanceStruct *chartInstance);
static void initialize_params_c5_test(SFc5_testInstanceStruct *chartInstance);
static void enable_c5_test(SFc5_testInstanceStruct *chartInstance);
static void disable_c5_test(SFc5_testInstanceStruct *chartInstance);
static void c5_update_debugger_state_c5_test(SFc5_testInstanceStruct
  *chartInstance);
static const mxArray *get_sim_state_c5_test(SFc5_testInstanceStruct
  *chartInstance);
static void set_sim_state_c5_test(SFc5_testInstanceStruct *chartInstance, const
  mxArray *c5_st);
static void finalize_c5_test(SFc5_testInstanceStruct *chartInstance);
static void sf_c5_test(SFc5_testInstanceStruct *chartInstance);
static void initSimStructsc5_test(SFc5_testInstanceStruct *chartInstance);
static void init_script_number_translation(uint32_T c5_machineNumber, uint32_T
  c5_chartNumber);
static const mxArray *c5_sf_marshallOut(void *chartInstanceVoid, void *c5_inData);
static real_T c5_emlrt_marshallIn(SFc5_testInstanceStruct *chartInstance, const
  mxArray *c5_Theta_wo, const char_T *c5_identifier);
static real_T c5_b_emlrt_marshallIn(SFc5_testInstanceStruct *chartInstance,
  const mxArray *c5_u, const emlrtMsgIdentifier *c5_parentId);
static void c5_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c5_mxArrayInData, const char_T *c5_varName, void *c5_outData);
static const mxArray *c5_b_sf_marshallOut(void *chartInstanceVoid, void
  *c5_inData);
static void c5_c_emlrt_marshallIn(SFc5_testInstanceStruct *chartInstance, const
  mxArray *c5_x_next, const char_T *c5_identifier, real_T c5_y[7]);
static void c5_d_emlrt_marshallIn(SFc5_testInstanceStruct *chartInstance, const
  mxArray *c5_u, const emlrtMsgIdentifier *c5_parentId, real_T c5_y[7]);
static void c5_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c5_mxArrayInData, const char_T *c5_varName, void *c5_outData);
static void c5_info_helper(c5_ResolvedFunctionInfo c5_info[23]);
static void c5_mariner(SFc5_testInstanceStruct *chartInstance, real_T c5_x[7],
  real_T c5_ui, real_T c5_b_U0, real_T c5_NOISE, real_T c5_xdot[7], real_T *c5_U);
static real_T c5_mpower(SFc5_testInstanceStruct *chartInstance, real_T c5_a);
static void c5_eml_scalar_eg(SFc5_testInstanceStruct *chartInstance);
static real_T c5_sqrt(SFc5_testInstanceStruct *chartInstance, real_T c5_x);
static void c5_eml_error(SFc5_testInstanceStruct *chartInstance);
static real_T c5_b_mpower(SFc5_testInstanceStruct *chartInstance, real_T c5_a);
static const mxArray *c5_c_sf_marshallOut(void *chartInstanceVoid, void
  *c5_inData);
static int32_T c5_e_emlrt_marshallIn(SFc5_testInstanceStruct *chartInstance,
  const mxArray *c5_u, const emlrtMsgIdentifier *c5_parentId);
static void c5_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c5_mxArrayInData, const char_T *c5_varName, void *c5_outData);
static uint8_T c5_f_emlrt_marshallIn(SFc5_testInstanceStruct *chartInstance,
  const mxArray *c5_b_is_active_c5_test, const char_T *c5_identifier);
static uint8_T c5_g_emlrt_marshallIn(SFc5_testInstanceStruct *chartInstance,
  const mxArray *c5_u, const emlrtMsgIdentifier *c5_parentId);
static void c5_b_sqrt(SFc5_testInstanceStruct *chartInstance, real_T *c5_x);
static void init_dsm_address_info(SFc5_testInstanceStruct *chartInstance);

/* Function Definitions */
static void initialize_c5_test(SFc5_testInstanceStruct *chartInstance)
{
  chartInstance->c5_sfEvent = CALL_EVENT;
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  chartInstance->c5_is_active_c5_test = 0U;
}

static void initialize_params_c5_test(SFc5_testInstanceStruct *chartInstance)
{
  real_T c5_d0;
  real_T c5_d1;
  sf_set_error_prefix_string(
    "Error evaluating data 'U0' in the parent workspace.\n");
  sf_mex_import_named("U0", sf_mex_get_sfun_param(chartInstance->S, 0, 0),
                      &c5_d0, 0, 0, 0U, 0, 0U, 0);
  chartInstance->c5_U0 = c5_d0;
  sf_set_error_prefix_string("Stateflow Runtime Error (chart): ");
  sf_set_error_prefix_string(
    "Error evaluating data 'h' in the parent workspace.\n");
  sf_mex_import_named("h", sf_mex_get_sfun_param(chartInstance->S, 1, 0), &c5_d1,
                      0, 0, 0U, 0, 0U, 0);
  chartInstance->c5_h = c5_d1;
  sf_set_error_prefix_string("Stateflow Runtime Error (chart): ");
}

static void enable_c5_test(SFc5_testInstanceStruct *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void disable_c5_test(SFc5_testInstanceStruct *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void c5_update_debugger_state_c5_test(SFc5_testInstanceStruct
  *chartInstance)
{
}

static const mxArray *get_sim_state_c5_test(SFc5_testInstanceStruct
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
  real_T c5_c_u[7];
  const mxArray *c5_d_y = NULL;
  uint8_T c5_c_hoistedGlobal;
  uint8_T c5_d_u;
  const mxArray *c5_e_y = NULL;
  real_T *c5_Theta_wo;
  real_T *c5_U;
  real_T (*c5_x_next)[7];
  c5_Theta_wo = (real_T *)ssGetOutputPortSignal(chartInstance->S, 3);
  c5_U = (real_T *)ssGetOutputPortSignal(chartInstance->S, 2);
  c5_x_next = (real_T (*)[7])ssGetOutputPortSignal(chartInstance->S, 1);
  c5_st = NULL;
  c5_st = NULL;
  c5_y = NULL;
  sf_mex_assign(&c5_y, sf_mex_createcellarray(4), FALSE);
  c5_hoistedGlobal = *c5_Theta_wo;
  c5_u = c5_hoistedGlobal;
  c5_b_y = NULL;
  sf_mex_assign(&c5_b_y, sf_mex_create("y", &c5_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c5_y, 0, c5_b_y);
  c5_b_hoistedGlobal = *c5_U;
  c5_b_u = c5_b_hoistedGlobal;
  c5_c_y = NULL;
  sf_mex_assign(&c5_c_y, sf_mex_create("y", &c5_b_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c5_y, 1, c5_c_y);
  for (c5_i0 = 0; c5_i0 < 7; c5_i0++) {
    c5_c_u[c5_i0] = (*c5_x_next)[c5_i0];
  }

  c5_d_y = NULL;
  sf_mex_assign(&c5_d_y, sf_mex_create("y", c5_c_u, 0, 0U, 1U, 0U, 1, 7), FALSE);
  sf_mex_setcell(c5_y, 2, c5_d_y);
  c5_c_hoistedGlobal = chartInstance->c5_is_active_c5_test;
  c5_d_u = c5_c_hoistedGlobal;
  c5_e_y = NULL;
  sf_mex_assign(&c5_e_y, sf_mex_create("y", &c5_d_u, 3, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c5_y, 3, c5_e_y);
  sf_mex_assign(&c5_st, c5_y, FALSE);
  return c5_st;
}

static void set_sim_state_c5_test(SFc5_testInstanceStruct *chartInstance, const
  mxArray *c5_st)
{
  const mxArray *c5_u;
  real_T c5_dv0[7];
  int32_T c5_i1;
  real_T *c5_Theta_wo;
  real_T *c5_U;
  real_T (*c5_x_next)[7];
  c5_Theta_wo = (real_T *)ssGetOutputPortSignal(chartInstance->S, 3);
  c5_U = (real_T *)ssGetOutputPortSignal(chartInstance->S, 2);
  c5_x_next = (real_T (*)[7])ssGetOutputPortSignal(chartInstance->S, 1);
  chartInstance->c5_doneDoubleBufferReInit = TRUE;
  c5_u = sf_mex_dup(c5_st);
  *c5_Theta_wo = c5_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell
    (c5_u, 0)), "Theta_wo");
  *c5_U = c5_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c5_u, 1)),
    "U");
  c5_c_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c5_u, 2)),
                        "x_next", c5_dv0);
  for (c5_i1 = 0; c5_i1 < 7; c5_i1++) {
    (*c5_x_next)[c5_i1] = c5_dv0[c5_i1];
  }

  chartInstance->c5_is_active_c5_test = c5_f_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c5_u, 3)), "is_active_c5_test");
  sf_mex_destroy(&c5_u);
  c5_update_debugger_state_c5_test(chartInstance);
  sf_mex_destroy(&c5_st);
}

static void finalize_c5_test(SFc5_testInstanceStruct *chartInstance)
{
}

static void sf_c5_test(SFc5_testInstanceStruct *chartInstance)
{
  int32_T c5_i2;
  int32_T c5_i3;
  real_T c5_hoistedGlobal;
  real_T c5_b_hoistedGlobal;
  real_T c5_c_hoistedGlobal;
  real_T c5_d_hoistedGlobal;
  real_T c5_NOISE;
  real_T c5_ui;
  real_T c5_b_U0;
  real_T c5_b_h;
  int32_T c5_i4;
  real_T c5_x[7];
  uint32_T c5_debug_family_var_map[21];
  real_T c5_k1[7];
  real_T c5_U1;
  real_T c5_k2[7];
  real_T c5_U2;
  real_T c5_k3[7];
  real_T c5_U3;
  real_T c5_k4[7];
  real_T c5_U4;
  real_T c5_ddd[7];
  real_T c5_Theta_bo;
  real_T c5_Theta_wb;
  real_T c5_nargin = 5.0;
  real_T c5_nargout = 3.0;
  real_T c5_x_next[7];
  real_T c5_U;
  real_T c5_Theta_wo;
  int32_T c5_i5;
  real_T c5_b_x[7];
  real_T c5_b_U1;
  real_T c5_b_k1[7];
  int32_T c5_i6;
  real_T c5_A;
  real_T c5_c_x;
  real_T c5_d_x;
  real_T c5_y;
  real_T c5_a;
  int32_T c5_i7;
  int32_T c5_i8;
  int32_T c5_i9;
  real_T c5_e_x[7];
  real_T c5_b_U2;
  int32_T c5_i10;
  real_T c5_b_A;
  real_T c5_f_x;
  real_T c5_g_x;
  real_T c5_b_y;
  real_T c5_b_a;
  int32_T c5_i11;
  int32_T c5_i12;
  int32_T c5_i13;
  real_T c5_h_x[7];
  real_T c5_b_U3;
  int32_T c5_i14;
  real_T c5_c_a;
  int32_T c5_i15;
  int32_T c5_i16;
  int32_T c5_i17;
  real_T c5_i_x[7];
  real_T c5_b_U4;
  int32_T c5_i18;
  int32_T c5_i19;
  int32_T c5_i20;
  int32_T c5_i21;
  real_T c5_b[7];
  int32_T c5_i22;
  real_T c5_d_a;
  int32_T c5_i23;
  int32_T c5_i24;
  int32_T c5_i25;
  int32_T c5_i26;
  int32_T c5_i27;
  int32_T c5_i28;
  int32_T c5_i29;
  int32_T c5_i30;
  int32_T c5_i31;
  int32_T c5_i32;
  int32_T c5_i33;
  real_T c5_u[7];
  const mxArray *c5_c_y = NULL;
  real_T c5_b_b;
  real_T c5_d_y;
  real_T c5_c_b;
  real_T c5_e_y;
  real_T c5_c_A;
  real_T c5_j_x;
  real_T c5_k_x;
  real_T c5_d_A;
  real_T c5_B;
  real_T c5_l_x;
  real_T c5_f_y;
  real_T c5_m_x;
  real_T c5_g_y;
  real_T c5_h_y;
  real_T c5_n_x;
  real_T c5_o_x;
  real_T c5_e_A;
  real_T c5_b_B;
  real_T c5_p_x;
  real_T c5_i_y;
  real_T c5_q_x;
  real_T c5_j_y;
  real_T c5_k_y;
  real_T c5_r_x;
  real_T c5_s_x;
  int32_T c5_i34;
  real_T *c5_b_Theta_wo;
  real_T *c5_b_U;
  real_T *c5_b_ui;
  real_T *c5_b_NOISE;
  real_T (*c5_b_x_next)[7];
  real_T (*c5_t_x)[7];
  c5_t_x = (real_T (*)[7])ssGetInputPortSignal(chartInstance->S, 2);
  c5_b_Theta_wo = (real_T *)ssGetOutputPortSignal(chartInstance->S, 3);
  c5_b_U = (real_T *)ssGetOutputPortSignal(chartInstance->S, 2);
  c5_b_ui = (real_T *)ssGetInputPortSignal(chartInstance->S, 1);
  c5_b_x_next = (real_T (*)[7])ssGetOutputPortSignal(chartInstance->S, 1);
  c5_b_NOISE = (real_T *)ssGetInputPortSignal(chartInstance->S, 0);
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 4U, chartInstance->c5_sfEvent);
  _SFD_DATA_RANGE_CHECK(*c5_b_NOISE, 0U);
  for (c5_i2 = 0; c5_i2 < 7; c5_i2++) {
    _SFD_DATA_RANGE_CHECK((*c5_b_x_next)[c5_i2], 1U);
  }

  _SFD_DATA_RANGE_CHECK(*c5_b_ui, 2U);
  _SFD_DATA_RANGE_CHECK(*c5_b_U, 3U);
  _SFD_DATA_RANGE_CHECK(*c5_b_Theta_wo, 4U);
  _SFD_DATA_RANGE_CHECK(chartInstance->c5_U0, 5U);
  _SFD_DATA_RANGE_CHECK(chartInstance->c5_h, 6U);
  for (c5_i3 = 0; c5_i3 < 7; c5_i3++) {
    _SFD_DATA_RANGE_CHECK((*c5_t_x)[c5_i3], 7U);
  }

  chartInstance->c5_sfEvent = CALL_EVENT;
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 4U, chartInstance->c5_sfEvent);
  c5_hoistedGlobal = *c5_b_NOISE;
  c5_b_hoistedGlobal = *c5_b_ui;
  c5_c_hoistedGlobal = chartInstance->c5_U0;
  c5_d_hoistedGlobal = chartInstance->c5_h;
  c5_NOISE = c5_hoistedGlobal;
  c5_ui = c5_b_hoistedGlobal;
  c5_b_U0 = c5_c_hoistedGlobal;
  c5_b_h = c5_d_hoistedGlobal;
  for (c5_i4 = 0; c5_i4 < 7; c5_i4++) {
    c5_x[c5_i4] = (*c5_t_x)[c5_i4];
  }

  sf_debug_symbol_scope_push_eml(0U, 21U, 21U, c5_debug_family_names,
    c5_debug_family_var_map);
  sf_debug_symbol_scope_add_eml_importable(c5_k1, 0U, c5_b_sf_marshallOut,
    c5_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c5_U1, 1U, c5_sf_marshallOut,
    c5_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(c5_k2, 2U, c5_b_sf_marshallOut,
    c5_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c5_U2, 3U, c5_sf_marshallOut,
    c5_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(c5_k3, 4U, c5_b_sf_marshallOut,
    c5_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c5_U3, 5U, c5_sf_marshallOut,
    c5_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(c5_k4, 6U, c5_b_sf_marshallOut,
    c5_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c5_U4, 7U, c5_sf_marshallOut,
    c5_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(c5_ddd, 8U, c5_b_sf_marshallOut,
    c5_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c5_Theta_bo, 9U, c5_sf_marshallOut,
    c5_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c5_Theta_wb, 10U, c5_sf_marshallOut,
    c5_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c5_nargin, 11U, c5_sf_marshallOut,
    c5_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c5_nargout, 12U, c5_sf_marshallOut,
    c5_sf_marshallIn);
  sf_debug_symbol_scope_add_eml(&c5_NOISE, 13U, c5_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c5_ui, 14U, c5_sf_marshallOut);
  sf_debug_symbol_scope_add_eml_importable(&c5_b_U0, 15U, c5_sf_marshallOut,
    c5_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c5_b_h, 16U, c5_sf_marshallOut,
    c5_sf_marshallIn);
  sf_debug_symbol_scope_add_eml(c5_x, 17U, c5_b_sf_marshallOut);
  sf_debug_symbol_scope_add_eml_importable(c5_x_next, 18U, c5_b_sf_marshallOut,
    c5_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c5_U, 19U, c5_sf_marshallOut,
    c5_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c5_Theta_wo, 20U, c5_sf_marshallOut,
    c5_sf_marshallIn);
  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, 18);
  for (c5_i5 = 0; c5_i5 < 7; c5_i5++) {
    c5_b_x[c5_i5] = c5_x[c5_i5];
  }

  c5_mariner(chartInstance, c5_b_x, c5_ui, c5_b_U0, c5_NOISE, c5_b_k1, &c5_b_U1);
  for (c5_i6 = 0; c5_i6 < 7; c5_i6++) {
    c5_k1[c5_i6] = c5_b_k1[c5_i6];
  }

  c5_U1 = c5_b_U1;
  _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, 19);
  c5_A = c5_b_h;
  c5_c_x = c5_A;
  c5_d_x = c5_c_x;
  c5_y = c5_d_x / 2.0;
  c5_a = c5_y;
  for (c5_i7 = 0; c5_i7 < 7; c5_i7++) {
    c5_b_k1[c5_i7] = c5_k1[c5_i7];
  }

  for (c5_i8 = 0; c5_i8 < 7; c5_i8++) {
    c5_b_k1[c5_i8] *= c5_a;
  }

  for (c5_i9 = 0; c5_i9 < 7; c5_i9++) {
    c5_e_x[c5_i9] = c5_x[c5_i9] + c5_b_k1[c5_i9];
  }

  c5_mariner(chartInstance, c5_e_x, c5_ui, c5_b_U0, c5_NOISE, c5_b_k1, &c5_b_U2);
  for (c5_i10 = 0; c5_i10 < 7; c5_i10++) {
    c5_k2[c5_i10] = c5_b_k1[c5_i10];
  }

  c5_U2 = c5_b_U2;
  _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, 20);
  c5_b_A = c5_b_h;
  c5_f_x = c5_b_A;
  c5_g_x = c5_f_x;
  c5_b_y = c5_g_x / 2.0;
  c5_b_a = c5_b_y;
  for (c5_i11 = 0; c5_i11 < 7; c5_i11++) {
    c5_b_k1[c5_i11] = c5_k2[c5_i11];
  }

  for (c5_i12 = 0; c5_i12 < 7; c5_i12++) {
    c5_b_k1[c5_i12] *= c5_b_a;
  }

  for (c5_i13 = 0; c5_i13 < 7; c5_i13++) {
    c5_h_x[c5_i13] = c5_x[c5_i13] + c5_b_k1[c5_i13];
  }

  c5_mariner(chartInstance, c5_h_x, c5_ui, c5_b_U0, c5_NOISE, c5_b_k1, &c5_b_U3);
  for (c5_i14 = 0; c5_i14 < 7; c5_i14++) {
    c5_k3[c5_i14] = c5_b_k1[c5_i14];
  }

  c5_U3 = c5_b_U3;
  _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, 21);
  c5_c_a = c5_b_h;
  for (c5_i15 = 0; c5_i15 < 7; c5_i15++) {
    c5_b_k1[c5_i15] = c5_k3[c5_i15];
  }

  for (c5_i16 = 0; c5_i16 < 7; c5_i16++) {
    c5_b_k1[c5_i16] *= c5_c_a;
  }

  for (c5_i17 = 0; c5_i17 < 7; c5_i17++) {
    c5_i_x[c5_i17] = c5_x[c5_i17] + c5_b_k1[c5_i17];
  }

  c5_mariner(chartInstance, c5_i_x, c5_ui, c5_b_U0, c5_NOISE, c5_b_k1, &c5_b_U4);
  for (c5_i18 = 0; c5_i18 < 7; c5_i18++) {
    c5_k4[c5_i18] = c5_b_k1[c5_i18];
  }

  c5_U4 = c5_b_U4;
  _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, 22);
  for (c5_i19 = 0; c5_i19 < 7; c5_i19++) {
    c5_b_k1[c5_i19] = c5_k2[c5_i19];
  }

  for (c5_i20 = 0; c5_i20 < 7; c5_i20++) {
    c5_b_k1[c5_i20] *= 2.0;
  }

  for (c5_i21 = 0; c5_i21 < 7; c5_i21++) {
    c5_b[c5_i21] = c5_k3[c5_i21];
  }

  for (c5_i22 = 0; c5_i22 < 7; c5_i22++) {
    c5_b[c5_i22] *= 2.0;
  }

  c5_d_a = c5_b_h;
  for (c5_i23 = 0; c5_i23 < 7; c5_i23++) {
    c5_b_k1[c5_i23] = ((c5_k1[c5_i23] + c5_b_k1[c5_i23]) + c5_b[c5_i23]) +
      c5_k4[c5_i23];
  }

  for (c5_i24 = 0; c5_i24 < 7; c5_i24++) {
    c5_b_k1[c5_i24] *= c5_d_a;
  }

  for (c5_i25 = 0; c5_i25 < 7; c5_i25++) {
    c5_b_k1[c5_i25] /= 6.0;
  }

  for (c5_i26 = 0; c5_i26 < 7; c5_i26++) {
    c5_x_next[c5_i26] = c5_x[c5_i26] + c5_b_k1[c5_i26];
  }

  _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, 23);
  for (c5_i27 = 0; c5_i27 < 7; c5_i27++) {
    c5_b_k1[c5_i27] = c5_k2[c5_i27];
  }

  for (c5_i28 = 0; c5_i28 < 7; c5_i28++) {
    c5_b_k1[c5_i28] *= 2.0;
  }

  for (c5_i29 = 0; c5_i29 < 7; c5_i29++) {
    c5_b[c5_i29] = c5_k3[c5_i29];
  }

  for (c5_i30 = 0; c5_i30 < 7; c5_i30++) {
    c5_b[c5_i30] *= 2.0;
  }

  for (c5_i31 = 0; c5_i31 < 7; c5_i31++) {
    c5_b_k1[c5_i31] = ((c5_k1[c5_i31] + c5_b_k1[c5_i31]) + c5_b[c5_i31]) +
      c5_k4[c5_i31];
  }

  for (c5_i32 = 0; c5_i32 < 7; c5_i32++) {
    c5_ddd[c5_i32] = c5_b_k1[c5_i32] / 6.0;
  }

  sf_mex_printf("%s =\\n", "ddd");
  for (c5_i33 = 0; c5_i33 < 7; c5_i33++) {
    c5_u[c5_i33] = c5_ddd[c5_i33];
  }

  c5_c_y = NULL;
  sf_mex_assign(&c5_c_y, sf_mex_create("y", c5_u, 0, 0U, 1U, 0U, 1, 7), FALSE);
  sf_mex_call_debug("disp", 0U, 1U, 14, c5_c_y);
  _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, 24);
  c5_b_b = c5_U2;
  c5_d_y = 2.0 * c5_b_b;
  c5_c_b = c5_U3;
  c5_e_y = 2.0 * c5_c_b;
  c5_c_A = ((c5_U1 + c5_d_y) + c5_e_y) + c5_U4;
  c5_j_x = c5_c_A;
  c5_k_x = c5_j_x;
  c5_U = c5_k_x / 6.0;
  _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, 25);
  c5_Theta_bo = c5_x_next[5];
  _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, 26);
  c5_d_A = c5_x_next[1];
  c5_B = c5_U;
  c5_l_x = c5_d_A;
  c5_f_y = c5_B;
  c5_m_x = c5_l_x;
  c5_g_y = c5_f_y;
  c5_h_y = c5_m_x / c5_g_y;
  c5_n_x = c5_h_y;
  c5_Theta_wb = c5_n_x;
  c5_o_x = c5_Theta_wb;
  c5_Theta_wb = c5_o_x;
  c5_Theta_wb = muDoubleScalarAtan(c5_Theta_wb);
  _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, 27);
  c5_e_A = c5_x_next[1];
  c5_b_B = c5_U;
  c5_p_x = c5_e_A;
  c5_i_y = c5_b_B;
  c5_q_x = c5_p_x;
  c5_j_y = c5_i_y;
  c5_k_y = c5_q_x / c5_j_y;
  c5_r_x = c5_k_y;
  c5_s_x = c5_r_x;
  c5_s_x = muDoubleScalarAtan(c5_s_x);
  c5_Theta_wo = c5_s_x + c5_Theta_bo;
  _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, -27);
  sf_debug_symbol_scope_pop();
  for (c5_i34 = 0; c5_i34 < 7; c5_i34++) {
    (*c5_b_x_next)[c5_i34] = c5_x_next[c5_i34];
  }

  *c5_b_U = c5_U;
  *c5_b_Theta_wo = c5_Theta_wo;
  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 4U, chartInstance->c5_sfEvent);
  sf_debug_check_for_state_inconsistency(_testMachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
}

static void initSimStructsc5_test(SFc5_testInstanceStruct *chartInstance)
{
}

static void init_script_number_translation(uint32_T c5_machineNumber, uint32_T
  c5_chartNumber)
{
  _SFD_SCRIPT_TRANSLATION(c5_chartNumber, 0U, sf_debug_get_script_id(
    "/Users/dittoyi/Desktop/L1Adaptive/Code/1216/RoseLine/mariner.m"));
}

static const mxArray *c5_sf_marshallOut(void *chartInstanceVoid, void *c5_inData)
{
  const mxArray *c5_mxArrayOutData = NULL;
  real_T c5_u;
  const mxArray *c5_y = NULL;
  SFc5_testInstanceStruct *chartInstance;
  chartInstance = (SFc5_testInstanceStruct *)chartInstanceVoid;
  c5_mxArrayOutData = NULL;
  c5_u = *(real_T *)c5_inData;
  c5_y = NULL;
  sf_mex_assign(&c5_y, sf_mex_create("y", &c5_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c5_mxArrayOutData, c5_y, FALSE);
  return c5_mxArrayOutData;
}

static real_T c5_emlrt_marshallIn(SFc5_testInstanceStruct *chartInstance, const
  mxArray *c5_Theta_wo, const char_T *c5_identifier)
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

static real_T c5_b_emlrt_marshallIn(SFc5_testInstanceStruct *chartInstance,
  const mxArray *c5_u, const emlrtMsgIdentifier *c5_parentId)
{
  real_T c5_y;
  real_T c5_d2;
  sf_mex_import(c5_parentId, sf_mex_dup(c5_u), &c5_d2, 1, 0, 0U, 0, 0U, 0);
  c5_y = c5_d2;
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
  SFc5_testInstanceStruct *chartInstance;
  chartInstance = (SFc5_testInstanceStruct *)chartInstanceVoid;
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
  int32_T c5_i35;
  real_T c5_b_inData[7];
  int32_T c5_i36;
  real_T c5_u[7];
  const mxArray *c5_y = NULL;
  SFc5_testInstanceStruct *chartInstance;
  chartInstance = (SFc5_testInstanceStruct *)chartInstanceVoid;
  c5_mxArrayOutData = NULL;
  for (c5_i35 = 0; c5_i35 < 7; c5_i35++) {
    c5_b_inData[c5_i35] = (*(real_T (*)[7])c5_inData)[c5_i35];
  }

  for (c5_i36 = 0; c5_i36 < 7; c5_i36++) {
    c5_u[c5_i36] = c5_b_inData[c5_i36];
  }

  c5_y = NULL;
  sf_mex_assign(&c5_y, sf_mex_create("y", c5_u, 0, 0U, 1U, 0U, 1, 7), FALSE);
  sf_mex_assign(&c5_mxArrayOutData, c5_y, FALSE);
  return c5_mxArrayOutData;
}

static void c5_c_emlrt_marshallIn(SFc5_testInstanceStruct *chartInstance, const
  mxArray *c5_x_next, const char_T *c5_identifier, real_T c5_y[7])
{
  emlrtMsgIdentifier c5_thisId;
  c5_thisId.fIdentifier = c5_identifier;
  c5_thisId.fParent = NULL;
  c5_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c5_x_next), &c5_thisId, c5_y);
  sf_mex_destroy(&c5_x_next);
}

static void c5_d_emlrt_marshallIn(SFc5_testInstanceStruct *chartInstance, const
  mxArray *c5_u, const emlrtMsgIdentifier *c5_parentId, real_T c5_y[7])
{
  real_T c5_dv1[7];
  int32_T c5_i37;
  sf_mex_import(c5_parentId, sf_mex_dup(c5_u), c5_dv1, 1, 0, 0U, 1, 0U, 1, 7);
  for (c5_i37 = 0; c5_i37 < 7; c5_i37++) {
    c5_y[c5_i37] = c5_dv1[c5_i37];
  }

  sf_mex_destroy(&c5_u);
}

static void c5_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c5_mxArrayInData, const char_T *c5_varName, void *c5_outData)
{
  const mxArray *c5_x_next;
  const char_T *c5_identifier;
  emlrtMsgIdentifier c5_thisId;
  real_T c5_y[7];
  int32_T c5_i38;
  SFc5_testInstanceStruct *chartInstance;
  chartInstance = (SFc5_testInstanceStruct *)chartInstanceVoid;
  c5_x_next = sf_mex_dup(c5_mxArrayInData);
  c5_identifier = c5_varName;
  c5_thisId.fIdentifier = c5_identifier;
  c5_thisId.fParent = NULL;
  c5_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c5_x_next), &c5_thisId, c5_y);
  sf_mex_destroy(&c5_x_next);
  for (c5_i38 = 0; c5_i38 < 7; c5_i38++) {
    (*(real_T (*)[7])c5_outData)[c5_i38] = c5_y[c5_i38];
  }

  sf_mex_destroy(&c5_mxArrayInData);
}

const mxArray *sf_c5_test_get_eml_resolved_functions_info(void)
{
  const mxArray *c5_nameCaptureInfo;
  c5_ResolvedFunctionInfo c5_info[23];
  const mxArray *c5_m0 = NULL;
  int32_T c5_i39;
  c5_ResolvedFunctionInfo *c5_r0;
  c5_nameCaptureInfo = NULL;
  c5_nameCaptureInfo = NULL;
  c5_info_helper(c5_info);
  sf_mex_assign(&c5_m0, sf_mex_createstruct("nameCaptureInfo", 1, 23), FALSE);
  for (c5_i39 = 0; c5_i39 < 23; c5_i39++) {
    c5_r0 = &c5_info[c5_i39];
    sf_mex_addfield(c5_m0, sf_mex_create("nameCaptureInfo", c5_r0->context, 15,
      0U, 0U, 0U, 2, 1, strlen(c5_r0->context)), "context", "nameCaptureInfo",
                    c5_i39);
    sf_mex_addfield(c5_m0, sf_mex_create("nameCaptureInfo", c5_r0->name, 15, 0U,
      0U, 0U, 2, 1, strlen(c5_r0->name)), "name", "nameCaptureInfo", c5_i39);
    sf_mex_addfield(c5_m0, sf_mex_create("nameCaptureInfo", c5_r0->dominantType,
      15, 0U, 0U, 0U, 2, 1, strlen(c5_r0->dominantType)), "dominantType",
                    "nameCaptureInfo", c5_i39);
    sf_mex_addfield(c5_m0, sf_mex_create("nameCaptureInfo", c5_r0->resolved, 15,
      0U, 0U, 0U, 2, 1, strlen(c5_r0->resolved)), "resolved", "nameCaptureInfo",
                    c5_i39);
    sf_mex_addfield(c5_m0, sf_mex_create("nameCaptureInfo", &c5_r0->fileTimeLo,
      7, 0U, 0U, 0U, 0), "fileTimeLo", "nameCaptureInfo", c5_i39);
    sf_mex_addfield(c5_m0, sf_mex_create("nameCaptureInfo", &c5_r0->fileTimeHi,
      7, 0U, 0U, 0U, 0), "fileTimeHi", "nameCaptureInfo", c5_i39);
    sf_mex_addfield(c5_m0, sf_mex_create("nameCaptureInfo", &c5_r0->mFileTimeLo,
      7, 0U, 0U, 0U, 0), "mFileTimeLo", "nameCaptureInfo", c5_i39);
    sf_mex_addfield(c5_m0, sf_mex_create("nameCaptureInfo", &c5_r0->mFileTimeHi,
      7, 0U, 0U, 0U, 0), "mFileTimeHi", "nameCaptureInfo", c5_i39);
  }

  sf_mex_assign(&c5_nameCaptureInfo, c5_m0, FALSE);
  sf_mex_emlrtNameCapturePostProcessR2012a(&c5_nameCaptureInfo);
  return c5_nameCaptureInfo;
}

static void c5_info_helper(c5_ResolvedFunctionInfo c5_info[23])
{
  c5_info[0].context = "";
  c5_info[0].name = "mariner";
  c5_info[0].dominantType = "double";
  c5_info[0].resolved =
    "[E]/Users/dittoyi/Desktop/L1Adaptive/Code/1216/RoseLine/mariner.m";
  c5_info[0].fileTimeLo = 1387186620U;
  c5_info[0].fileTimeHi = 0U;
  c5_info[0].mFileTimeLo = 0U;
  c5_info[0].mFileTimeHi = 0U;
  c5_info[1].context =
    "[E]/Users/dittoyi/Desktop/L1Adaptive/Code/1216/RoseLine/mariner.m";
  c5_info[1].name = "length";
  c5_info[1].dominantType = "double";
  c5_info[1].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/length.m";
  c5_info[1].fileTimeLo = 1303124606U;
  c5_info[1].fileTimeHi = 0U;
  c5_info[1].mFileTimeLo = 0U;
  c5_info[1].mFileTimeHi = 0U;
  c5_info[2].context =
    "[E]/Users/dittoyi/Desktop/L1Adaptive/Code/1216/RoseLine/mariner.m";
  c5_info[2].name = "mpower";
  c5_info[2].dominantType = "double";
  c5_info[2].resolved = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mpower.m";
  c5_info[2].fileTimeLo = 1286797242U;
  c5_info[2].fileTimeHi = 0U;
  c5_info[2].mFileTimeLo = 0U;
  c5_info[2].mFileTimeHi = 0U;
  c5_info[3].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mpower.m";
  c5_info[3].name = "power";
  c5_info[3].dominantType = "double";
  c5_info[3].resolved = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m";
  c5_info[3].fileTimeLo = 1336500496U;
  c5_info[3].fileTimeHi = 0U;
  c5_info[3].mFileTimeLo = 0U;
  c5_info[3].mFileTimeHi = 0U;
  c5_info[4].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m!fltpower";
  c5_info[4].name = "eml_scalar_eg";
  c5_info[4].dominantType = "double";
  c5_info[4].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m";
  c5_info[4].fileTimeLo = 1286797196U;
  c5_info[4].fileTimeHi = 0U;
  c5_info[4].mFileTimeLo = 0U;
  c5_info[4].mFileTimeHi = 0U;
  c5_info[5].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m!fltpower";
  c5_info[5].name = "eml_scalexp_alloc";
  c5_info[5].dominantType = "double";
  c5_info[5].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalexp_alloc.m";
  c5_info[5].fileTimeLo = 1330583234U;
  c5_info[5].fileTimeHi = 0U;
  c5_info[5].mFileTimeLo = 0U;
  c5_info[5].mFileTimeHi = 0U;
  c5_info[6].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m!fltpower";
  c5_info[6].name = "floor";
  c5_info[6].dominantType = "double";
  c5_info[6].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/floor.m";
  c5_info[6].fileTimeLo = 1286797142U;
  c5_info[6].fileTimeHi = 0U;
  c5_info[6].mFileTimeLo = 0U;
  c5_info[6].mFileTimeHi = 0U;
  c5_info[7].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/floor.m";
  c5_info[7].name = "eml_scalar_floor";
  c5_info[7].dominantType = "double";
  c5_info[7].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_floor.m";
  c5_info[7].fileTimeLo = 1286797126U;
  c5_info[7].fileTimeHi = 0U;
  c5_info[7].mFileTimeLo = 0U;
  c5_info[7].mFileTimeHi = 0U;
  c5_info[8].context =
    "[E]/Users/dittoyi/Desktop/L1Adaptive/Code/1216/RoseLine/mariner.m";
  c5_info[8].name = "sqrt";
  c5_info[8].dominantType = "double";
  c5_info[8].resolved = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/sqrt.m";
  c5_info[8].fileTimeLo = 1286797152U;
  c5_info[8].fileTimeHi = 0U;
  c5_info[8].mFileTimeLo = 0U;
  c5_info[8].mFileTimeHi = 0U;
  c5_info[9].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/sqrt.m";
  c5_info[9].name = "eml_error";
  c5_info[9].dominantType = "char";
  c5_info[9].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_error.m";
  c5_info[9].fileTimeLo = 1305296400U;
  c5_info[9].fileTimeHi = 0U;
  c5_info[9].mFileTimeLo = 0U;
  c5_info[9].mFileTimeHi = 0U;
  c5_info[10].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/sqrt.m";
  c5_info[10].name = "eml_scalar_sqrt";
  c5_info[10].dominantType = "double";
  c5_info[10].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_sqrt.m";
  c5_info[10].fileTimeLo = 1286797138U;
  c5_info[10].fileTimeHi = 0U;
  c5_info[10].mFileTimeLo = 0U;
  c5_info[10].mFileTimeHi = 0U;
  c5_info[11].context =
    "[E]/Users/dittoyi/Desktop/L1Adaptive/Code/1216/RoseLine/mariner.m";
  c5_info[11].name = "mrdivide";
  c5_info[11].dominantType = "double";
  c5_info[11].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p";
  c5_info[11].fileTimeLo = 1342789344U;
  c5_info[11].fileTimeHi = 0U;
  c5_info[11].mFileTimeLo = 1319708366U;
  c5_info[11].mFileTimeHi = 0U;
  c5_info[12].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p";
  c5_info[12].name = "rdivide";
  c5_info[12].dominantType = "double";
  c5_info[12].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m";
  c5_info[12].fileTimeLo = 1286797244U;
  c5_info[12].fileTimeHi = 0U;
  c5_info[12].mFileTimeLo = 0U;
  c5_info[12].mFileTimeHi = 0U;
  c5_info[13].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m";
  c5_info[13].name = "eml_div";
  c5_info[13].dominantType = "double";
  c5_info[13].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_div.m";
  c5_info[13].fileTimeLo = 1313326210U;
  c5_info[13].fileTimeHi = 0U;
  c5_info[13].mFileTimeLo = 0U;
  c5_info[13].mFileTimeHi = 0U;
  c5_info[14].context =
    "[E]/Users/dittoyi/Desktop/L1Adaptive/Code/1216/RoseLine/mariner.m";
  c5_info[14].name = "mtimes";
  c5_info[14].dominantType = "double";
  c5_info[14].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c5_info[14].fileTimeLo = 1289494492U;
  c5_info[14].fileTimeHi = 0U;
  c5_info[14].mFileTimeLo = 0U;
  c5_info[14].mFileTimeHi = 0U;
  c5_info[15].context =
    "[E]/Users/dittoyi/Desktop/L1Adaptive/Code/1216/RoseLine/mariner.m";
  c5_info[15].name = "cos";
  c5_info[15].dominantType = "double";
  c5_info[15].resolved = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/cos.m";
  c5_info[15].fileTimeLo = 1286797106U;
  c5_info[15].fileTimeHi = 0U;
  c5_info[15].mFileTimeLo = 0U;
  c5_info[15].mFileTimeHi = 0U;
  c5_info[16].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/cos.m";
  c5_info[16].name = "eml_scalar_cos";
  c5_info[16].dominantType = "double";
  c5_info[16].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_cos.m";
  c5_info[16].fileTimeLo = 1286797122U;
  c5_info[16].fileTimeHi = 0U;
  c5_info[16].mFileTimeLo = 0U;
  c5_info[16].mFileTimeHi = 0U;
  c5_info[17].context =
    "[E]/Users/dittoyi/Desktop/L1Adaptive/Code/1216/RoseLine/mariner.m";
  c5_info[17].name = "sin";
  c5_info[17].dominantType = "double";
  c5_info[17].resolved = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/sin.m";
  c5_info[17].fileTimeLo = 1286797150U;
  c5_info[17].fileTimeHi = 0U;
  c5_info[17].mFileTimeLo = 0U;
  c5_info[17].mFileTimeHi = 0U;
  c5_info[18].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/sin.m";
  c5_info[18].name = "eml_scalar_sin";
  c5_info[18].dominantType = "double";
  c5_info[18].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_sin.m";
  c5_info[18].fileTimeLo = 1286797136U;
  c5_info[18].fileTimeHi = 0U;
  c5_info[18].mFileTimeLo = 0U;
  c5_info[18].mFileTimeHi = 0U;
  c5_info[19].context = "";
  c5_info[19].name = "mrdivide";
  c5_info[19].dominantType = "double";
  c5_info[19].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p";
  c5_info[19].fileTimeLo = 1342789344U;
  c5_info[19].fileTimeHi = 0U;
  c5_info[19].mFileTimeLo = 1319708366U;
  c5_info[19].mFileTimeHi = 0U;
  c5_info[20].context = "";
  c5_info[20].name = "mtimes";
  c5_info[20].dominantType = "double";
  c5_info[20].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c5_info[20].fileTimeLo = 1289494492U;
  c5_info[20].fileTimeHi = 0U;
  c5_info[20].mFileTimeLo = 0U;
  c5_info[20].mFileTimeHi = 0U;
  c5_info[21].context = "";
  c5_info[21].name = "atan";
  c5_info[21].dominantType = "double";
  c5_info[21].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/atan.m";
  c5_info[21].fileTimeLo = 1305296398U;
  c5_info[21].fileTimeHi = 0U;
  c5_info[21].mFileTimeLo = 0U;
  c5_info[21].mFileTimeHi = 0U;
  c5_info[22].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/atan.m";
  c5_info[22].name = "eml_scalar_atan";
  c5_info[22].dominantType = "double";
  c5_info[22].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_atan.m";
  c5_info[22].fileTimeLo = 1286797118U;
  c5_info[22].fileTimeHi = 0U;
  c5_info[22].mFileTimeLo = 0U;
  c5_info[22].mFileTimeHi = 0U;
}

static void c5_mariner(SFc5_testInstanceStruct *chartInstance, real_T c5_x[7],
  real_T c5_ui, real_T c5_b_U0, real_T c5_NOISE, real_T c5_xdot[7], real_T *c5_U)
{
  uint32_T c5_debug_family_var_map[75];
  real_T c5_L;
  real_T c5_delta_c;
  real_T c5_u;
  real_T c5_v;
  real_T c5_r;
  real_T c5_psi;
  real_T c5_delta;
  real_T c5_delta_max;
  real_T c5_Ddelta_max;
  real_T c5_m;
  real_T c5_Iz;
  real_T c5_xG;
  real_T c5_Xudot;
  real_T c5_Yvdot;
  real_T c5_Nvdot;
  real_T c5_Xu;
  real_T c5_Yrdot;
  real_T c5_Nrdot;
  real_T c5_Xuu;
  real_T c5_Yv;
  real_T c5_Nv;
  real_T c5_Xuuu;
  real_T c5_Yr;
  real_T c5_Nr;
  real_T c5_Xvv;
  real_T c5_Yvvv;
  real_T c5_Nvvv;
  real_T c5_Xrr;
  real_T c5_Yvvr;
  real_T c5_Nvvr;
  real_T c5_Xdd;
  real_T c5_Yvu;
  real_T c5_Nvu;
  real_T c5_Xudd;
  real_T c5_Yru;
  real_T c5_Nru;
  real_T c5_Xrv;
  real_T c5_Yd;
  real_T c5_Nd;
  real_T c5_Xvd;
  real_T c5_Yddd;
  real_T c5_Nddd;
  real_T c5_Xuvd;
  real_T c5_Yud;
  real_T c5_Nud;
  real_T c5_Yuud;
  real_T c5_Nuud;
  real_T c5_Yvdd;
  real_T c5_Nvdd;
  real_T c5_Yvvd;
  real_T c5_Nvvd;
  real_T c5_Y0;
  real_T c5_N0;
  real_T c5_Y0u;
  real_T c5_N0u;
  real_T c5_Y0uu;
  real_T c5_N0uu;
  real_T c5_m11;
  real_T c5_m22;
  real_T c5_m23;
  real_T c5_m32;
  real_T c5_m33;
  real_T c5_delta_dot;
  real_T c5_X;
  real_T c5_Y;
  real_T c5_N;
  real_T c5_detM22;
  real_T c5_nargin = 4.0;
  real_T c5_nargout = 2.0;
  real_T c5_A;
  real_T c5_B;
  real_T c5_b_x;
  real_T c5_y;
  real_T c5_c_x;
  real_T c5_b_y;
  real_T c5_b_A;
  real_T c5_b_B;
  real_T c5_d_x;
  real_T c5_c_y;
  real_T c5_e_x;
  real_T c5_d_y;
  real_T c5_a;
  real_T c5_e_y;
  real_T c5_c_A;
  real_T c5_c_B;
  real_T c5_f_x;
  real_T c5_f_y;
  real_T c5_g_x;
  real_T c5_g_y;
  real_T c5_b;
  real_T c5_h_y;
  real_T c5_b_b;
  real_T c5_i_y;
  real_T c5_c_b;
  real_T c5_j_y;
  real_T c5_d_b;
  real_T c5_k_y;
  real_T c5_e_b;
  real_T c5_l_y;
  real_T c5_f_b;
  real_T c5_m_y;
  real_T c5_b_a;
  real_T c5_g_b;
  real_T c5_n_y;
  real_T c5_h_b;
  real_T c5_o_y;
  real_T c5_i_b;
  real_T c5_p_y;
  real_T c5_c_a;
  real_T c5_j_b;
  real_T c5_q_y;
  real_T c5_k_b;
  real_T c5_r_y;
  real_T c5_d_a;
  real_T c5_l_b;
  real_T c5_s_y;
  real_T c5_m_b;
  real_T c5_t_y;
  real_T c5_e_a;
  real_T c5_n_b;
  real_T c5_u_y;
  real_T c5_f_a;
  real_T c5_o_b;
  real_T c5_v_y;
  real_T c5_p_b;
  real_T c5_w_y;
  real_T c5_q_b;
  real_T c5_x_y;
  real_T c5_r_b;
  real_T c5_y_y;
  real_T c5_s_b;
  real_T c5_ab_y;
  real_T c5_g_a;
  real_T c5_t_b;
  real_T c5_bb_y;
  real_T c5_u_b;
  real_T c5_cb_y;
  real_T c5_h_a;
  real_T c5_v_b;
  real_T c5_db_y;
  real_T c5_w_b;
  real_T c5_eb_y;
  real_T c5_i_a;
  real_T c5_x_b;
  real_T c5_fb_y;
  real_T c5_y_b;
  real_T c5_gb_y;
  real_T c5_ab_b;
  real_T c5_hb_y;
  real_T c5_bb_b;
  real_T c5_ib_y;
  real_T c5_j_a;
  real_T c5_cb_b;
  real_T c5_jb_y;
  real_T c5_db_b;
  real_T c5_kb_y;
  real_T c5_k_a;
  real_T c5_eb_b;
  real_T c5_lb_y;
  real_T c5_fb_b;
  real_T c5_mb_y;
  real_T c5_l_a;
  real_T c5_gb_b;
  real_T c5_nb_y;
  real_T c5_hb_b;
  real_T c5_ob_y;
  real_T c5_m_a;
  real_T c5_ib_b;
  real_T c5_pb_y;
  real_T c5_jb_b;
  real_T c5_qb_y;
  real_T c5_kb_b;
  real_T c5_rb_y;
  real_T c5_lb_b;
  real_T c5_sb_y;
  real_T c5_mb_b;
  real_T c5_tb_y;
  real_T c5_n_a;
  real_T c5_nb_b;
  real_T c5_ub_y;
  real_T c5_ob_b;
  real_T c5_vb_y;
  real_T c5_o_a;
  real_T c5_pb_b;
  real_T c5_wb_y;
  real_T c5_qb_b;
  real_T c5_xb_y;
  real_T c5_p_a;
  real_T c5_rb_b;
  real_T c5_yb_y;
  real_T c5_sb_b;
  real_T c5_ac_y;
  real_T c5_tb_b;
  real_T c5_bc_y;
  real_T c5_ub_b;
  real_T c5_cc_y;
  real_T c5_q_a;
  real_T c5_vb_b;
  real_T c5_dc_y;
  real_T c5_wb_b;
  real_T c5_ec_y;
  real_T c5_r_a;
  real_T c5_xb_b;
  real_T c5_fc_y;
  real_T c5_yb_b;
  real_T c5_gc_y;
  real_T c5_s_a;
  real_T c5_ac_b;
  real_T c5_hc_y;
  real_T c5_bc_b;
  real_T c5_ic_y;
  real_T c5_t_a;
  real_T c5_cc_b;
  real_T c5_jc_y;
  real_T c5_d_A;
  real_T c5_h_x;
  real_T c5_i_x;
  real_T c5_kc_y;
  real_T c5_u_a;
  real_T c5_dc_b;
  real_T c5_lc_y;
  real_T c5_e_A;
  real_T c5_j_x;
  real_T c5_k_x;
  real_T c5_mc_y;
  real_T c5_ec_b;
  real_T c5_nc_y;
  real_T c5_fc_b;
  real_T c5_oc_y;
  real_T c5_f_A;
  real_T c5_l_x;
  real_T c5_m_x;
  real_T c5_pc_y;
  real_T c5_v_a;
  real_T c5_gc_b;
  real_T c5_qc_y;
  real_T c5_g_A;
  real_T c5_n_x;
  real_T c5_o_x;
  real_T c5_rc_y;
  real_T c5_hc_b;
  real_T c5_sc_y;
  real_T c5_ic_b;
  real_T c5_tc_y;
  real_T c5_h_A;
  real_T c5_p_x;
  real_T c5_q_x;
  real_T c5_uc_y;
  real_T c5_w_a;
  real_T c5_jc_b;
  real_T c5_vc_y;
  real_T c5_i_A;
  real_T c5_r_x;
  real_T c5_s_x;
  real_T c5_wc_y;
  real_T c5_t_x;
  real_T c5_u_x;
  real_T c5_j_A;
  real_T c5_d_B;
  real_T c5_v_x;
  real_T c5_xc_y;
  real_T c5_w_x;
  real_T c5_yc_y;
  real_T c5_ad_y;
  real_T c5_x_a;
  real_T c5_kc_b;
  real_T c5_bd_y;
  real_T c5_x_x;
  real_T c5_y_x;
  real_T c5_y_a;
  real_T c5_lc_b;
  real_T c5_cd_y;
  real_T c5_ab_a;
  real_T c5_mc_b;
  real_T c5_dd_y;
  real_T c5_ab_x;
  real_T c5_bb_x;
  real_T c5_k_A;
  real_T c5_e_B;
  real_T c5_cb_x;
  real_T c5_ed_y;
  real_T c5_db_x;
  real_T c5_fd_y;
  real_T c5_gd_y;
  real_T c5_bb_a;
  real_T c5_nc_b;
  real_T c5_hd_y;
  real_T c5_eb_x;
  real_T c5_fb_x;
  real_T c5_cb_a;
  real_T c5_oc_b;
  real_T c5_id_y;
  real_T c5_db_a;
  real_T c5_pc_b;
  real_T c5_jd_y;
  real_T c5_l_A;
  real_T c5_gb_x;
  real_T c5_hb_x;
  real_T c5_kd_y;
  real_T c5_eb_a;
  real_T c5_qc_b;
  real_T c5_ld_y;
  sf_debug_symbol_scope_push_eml(0U, 75U, 75U, c5_b_debug_family_names,
    c5_debug_family_var_map);
  sf_debug_symbol_scope_add_eml(&c5_L, 0U, c5_sf_marshallOut);
  sf_debug_symbol_scope_add_eml_importable(&c5_delta_c, 1U, c5_sf_marshallOut,
    c5_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c5_u, 2U, c5_sf_marshallOut,
    c5_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c5_v, 3U, c5_sf_marshallOut,
    c5_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c5_r, 4U, c5_sf_marshallOut,
    c5_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c5_psi, 5U, c5_sf_marshallOut,
    c5_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c5_delta, 6U, c5_sf_marshallOut,
    c5_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c5_delta_max, 7U, c5_sf_marshallOut,
    c5_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c5_Ddelta_max, 8U, c5_sf_marshallOut,
    c5_sf_marshallIn);
  sf_debug_symbol_scope_add_eml(&c5_m, 9U, c5_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c5_Iz, 10U, c5_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c5_xG, 11U, c5_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c5_Xudot, 12U, c5_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c5_Yvdot, 13U, c5_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c5_Nvdot, 14U, c5_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c5_Xu, 15U, c5_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c5_Yrdot, 16U, c5_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c5_Nrdot, 17U, c5_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c5_Xuu, 18U, c5_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c5_Yv, 19U, c5_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c5_Nv, 20U, c5_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c5_Xuuu, 21U, c5_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c5_Yr, 22U, c5_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c5_Nr, 23U, c5_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c5_Xvv, 24U, c5_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c5_Yvvv, 25U, c5_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c5_Nvvv, 26U, c5_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c5_Xrr, 27U, c5_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c5_Yvvr, 28U, c5_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c5_Nvvr, 29U, c5_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c5_Xdd, 30U, c5_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c5_Yvu, 31U, c5_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c5_Nvu, 32U, c5_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c5_Xudd, 33U, c5_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c5_Yru, 34U, c5_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c5_Nru, 35U, c5_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c5_Xrv, 36U, c5_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c5_Yd, 37U, c5_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c5_Nd, 38U, c5_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c5_Xvd, 39U, c5_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c5_Yddd, 40U, c5_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c5_Nddd, 41U, c5_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c5_Xuvd, 42U, c5_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c5_Yud, 43U, c5_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c5_Nud, 44U, c5_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c5_Yuud, 45U, c5_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c5_Nuud, 46U, c5_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c5_Yvdd, 47U, c5_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c5_Nvdd, 48U, c5_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c5_Yvvd, 49U, c5_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c5_Nvvd, 50U, c5_sf_marshallOut);
  sf_debug_symbol_scope_add_eml_importable(&c5_Y0, 51U, c5_sf_marshallOut,
    c5_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c5_N0, 52U, c5_sf_marshallOut,
    c5_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c5_Y0u, 53U, c5_sf_marshallOut,
    c5_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c5_N0u, 54U, c5_sf_marshallOut,
    c5_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c5_Y0uu, 55U, c5_sf_marshallOut,
    c5_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c5_N0uu, 56U, c5_sf_marshallOut,
    c5_sf_marshallIn);
  sf_debug_symbol_scope_add_eml(&c5_m11, 57U, c5_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c5_m22, 58U, c5_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c5_m23, 59U, c5_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c5_m32, 60U, c5_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c5_m33, 61U, c5_sf_marshallOut);
  sf_debug_symbol_scope_add_eml_importable(&c5_delta_dot, 62U, c5_sf_marshallOut,
    c5_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c5_X, 63U, c5_sf_marshallOut,
    c5_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c5_Y, 64U, c5_sf_marshallOut,
    c5_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c5_N, 65U, c5_sf_marshallOut,
    c5_sf_marshallIn);
  sf_debug_symbol_scope_add_eml(&c5_detM22, 66U, c5_sf_marshallOut);
  sf_debug_symbol_scope_add_eml_importable(&c5_nargin, 67U, c5_sf_marshallOut,
    c5_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c5_nargout, 68U, c5_sf_marshallOut,
    c5_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(c5_x, 69U, c5_b_sf_marshallOut,
    c5_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c5_ui, 70U, c5_sf_marshallOut,
    c5_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c5_b_U0, 71U, c5_sf_marshallOut,
    c5_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c5_NOISE, 72U, c5_sf_marshallOut,
    c5_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(c5_xdot, 73U, c5_b_sf_marshallOut,
    c5_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(c5_U, 74U, c5_sf_marshallOut,
    c5_sf_marshallIn);
  CV_SCRIPT_FCN(0, 0);
  _SFD_SCRIPT_CALL(0U, chartInstance->c5_sfEvent, 53);
  CV_SCRIPT_IF(0, 0, FALSE);
  _SFD_SCRIPT_CALL(0U, chartInstance->c5_sfEvent, 54);
  CV_SCRIPT_IF(0, 1, FALSE);
  _SFD_SCRIPT_CALL(0U, chartInstance->c5_sfEvent, 55);
  CV_SCRIPT_IF(0, 2, FALSE);
  _SFD_SCRIPT_CALL(0U, chartInstance->c5_sfEvent, 58);
  c5_L = 160.93;
  _SFD_SCRIPT_CALL(0U, chartInstance->c5_sfEvent, 59);
  *c5_U = c5_mpower(chartInstance, c5_b_U0 + c5_x[0]) + c5_mpower(chartInstance,
    c5_x[1]);
  c5_b_sqrt(chartInstance, c5_U);
  _SFD_SCRIPT_CALL(0U, chartInstance->c5_sfEvent, 62);
  c5_delta_c = -c5_ui;
  _SFD_SCRIPT_CALL(0U, chartInstance->c5_sfEvent, 64);
  c5_A = c5_x[0];
  c5_B = *c5_U;
  c5_b_x = c5_A;
  c5_y = c5_B;
  c5_c_x = c5_b_x;
  c5_b_y = c5_y;
  c5_u = c5_c_x / c5_b_y;
  _SFD_SCRIPT_CALL(0U, chartInstance->c5_sfEvent, 65);
  c5_b_A = c5_x[1];
  c5_b_B = *c5_U;
  c5_d_x = c5_b_A;
  c5_c_y = c5_b_B;
  c5_e_x = c5_d_x;
  c5_d_y = c5_c_y;
  c5_v = c5_e_x / c5_d_y;
  _SFD_SCRIPT_CALL(0U, chartInstance->c5_sfEvent, 66);
  c5_a = c5_x[2];
  c5_e_y = c5_a * 160.93;
  c5_c_A = c5_e_y;
  c5_c_B = *c5_U;
  c5_f_x = c5_c_A;
  c5_f_y = c5_c_B;
  c5_g_x = c5_f_x;
  c5_g_y = c5_f_y;
  c5_r = c5_g_x / c5_g_y;
  _SFD_SCRIPT_CALL(0U, chartInstance->c5_sfEvent, 67);
  c5_psi = c5_x[5];
  _SFD_SCRIPT_CALL(0U, chartInstance->c5_sfEvent, 68);
  c5_delta = c5_x[6];
  _SFD_SCRIPT_CALL(0U, chartInstance->c5_sfEvent, 71);
  c5_delta_max = 40.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c5_sfEvent, 72);
  c5_Ddelta_max = 5.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c5_sfEvent, 74);
  c5_m = 0.00798;
  _SFD_SCRIPT_CALL(0U, chartInstance->c5_sfEvent, 75);
  c5_Iz = 0.000392;
  _SFD_SCRIPT_CALL(0U, chartInstance->c5_sfEvent, 76);
  c5_xG = -0.023;
  _SFD_SCRIPT_CALL(0U, chartInstance->c5_sfEvent, 78);
  c5_Xudot = -0.00042;
  _SFD_SCRIPT_CALL(0U, chartInstance->c5_sfEvent, 78);
  c5_Yvdot = -0.00748;
  _SFD_SCRIPT_CALL(0U, chartInstance->c5_sfEvent, 78);
  c5_Nvdot = 4.646E-5;
  _SFD_SCRIPT_CALL(0U, chartInstance->c5_sfEvent, 79);
  c5_Xu = -0.00184;
  _SFD_SCRIPT_CALL(0U, chartInstance->c5_sfEvent, 79);
  c5_Yrdot = -9.354E-5;
  _SFD_SCRIPT_CALL(0U, chartInstance->c5_sfEvent, 79);
  c5_Nrdot = -0.000438;
  _SFD_SCRIPT_CALL(0U, chartInstance->c5_sfEvent, 80);
  c5_Xuu = -0.0011;
  _SFD_SCRIPT_CALL(0U, chartInstance->c5_sfEvent, 80);
  c5_Yv = -0.0116;
  _SFD_SCRIPT_CALL(0U, chartInstance->c5_sfEvent, 80);
  c5_Nv = -0.00264;
  _SFD_SCRIPT_CALL(0U, chartInstance->c5_sfEvent, 81);
  c5_Xuuu = -0.00215;
  _SFD_SCRIPT_CALL(0U, chartInstance->c5_sfEvent, 81);
  c5_Yr = -0.00499;
  _SFD_SCRIPT_CALL(0U, chartInstance->c5_sfEvent, 81);
  c5_Nr = -0.00166;
  _SFD_SCRIPT_CALL(0U, chartInstance->c5_sfEvent, 82);
  c5_Xvv = -0.00899;
  _SFD_SCRIPT_CALL(0U, chartInstance->c5_sfEvent, 82);
  c5_Yvvv = -0.08078;
  _SFD_SCRIPT_CALL(0U, chartInstance->c5_sfEvent, 82);
  c5_Nvvv = 0.01636;
  _SFD_SCRIPT_CALL(0U, chartInstance->c5_sfEvent, 83);
  c5_Xrr = 0.00018;
  _SFD_SCRIPT_CALL(0U, chartInstance->c5_sfEvent, 83);
  c5_Yvvr = 0.15356;
  _SFD_SCRIPT_CALL(0U, chartInstance->c5_sfEvent, 83);
  c5_Nvvr = -0.05483;
  _SFD_SCRIPT_CALL(0U, chartInstance->c5_sfEvent, 84);
  c5_Xdd = -0.00095;
  _SFD_SCRIPT_CALL(0U, chartInstance->c5_sfEvent, 84);
  c5_Yvu = -0.0116;
  _SFD_SCRIPT_CALL(0U, chartInstance->c5_sfEvent, 84);
  c5_Nvu = -0.00264;
  _SFD_SCRIPT_CALL(0U, chartInstance->c5_sfEvent, 85);
  c5_Xudd = -0.0019;
  _SFD_SCRIPT_CALL(0U, chartInstance->c5_sfEvent, 85);
  c5_Yru = -0.00499;
  _SFD_SCRIPT_CALL(0U, chartInstance->c5_sfEvent, 85);
  c5_Nru = -0.00166;
  _SFD_SCRIPT_CALL(0U, chartInstance->c5_sfEvent, 86);
  c5_Xrv = 0.00798;
  _SFD_SCRIPT_CALL(0U, chartInstance->c5_sfEvent, 86);
  c5_Yd = 0.00278;
  _SFD_SCRIPT_CALL(0U, chartInstance->c5_sfEvent, 86);
  c5_Nd = -0.00139;
  _SFD_SCRIPT_CALL(0U, chartInstance->c5_sfEvent, 87);
  c5_Xvd = 0.00093;
  _SFD_SCRIPT_CALL(0U, chartInstance->c5_sfEvent, 87);
  c5_Yddd = -0.0009;
  _SFD_SCRIPT_CALL(0U, chartInstance->c5_sfEvent, 87);
  c5_Nddd = 0.00045;
  _SFD_SCRIPT_CALL(0U, chartInstance->c5_sfEvent, 88);
  c5_Xuvd = 0.00093;
  _SFD_SCRIPT_CALL(0U, chartInstance->c5_sfEvent, 88);
  c5_Yud = 0.00556;
  _SFD_SCRIPT_CALL(0U, chartInstance->c5_sfEvent, 88);
  c5_Nud = -0.00278;
  _SFD_SCRIPT_CALL(0U, chartInstance->c5_sfEvent, 89);
  c5_Yuud = 0.00278;
  _SFD_SCRIPT_CALL(0U, chartInstance->c5_sfEvent, 89);
  c5_Nuud = -0.00139;
  _SFD_SCRIPT_CALL(0U, chartInstance->c5_sfEvent, 90);
  c5_Yvdd = -4.0E-5;
  _SFD_SCRIPT_CALL(0U, chartInstance->c5_sfEvent, 90);
  c5_Nvdd = 0.00013;
  _SFD_SCRIPT_CALL(0U, chartInstance->c5_sfEvent, 91);
  c5_Yvvd = 0.0119;
  _SFD_SCRIPT_CALL(0U, chartInstance->c5_sfEvent, 91);
  c5_Nvvd = -0.00489;
  _SFD_SCRIPT_CALL(0U, chartInstance->c5_sfEvent, 92);
  c5_Y0 = 0.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c5_sfEvent, 94);
  c5_N0 = 0.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c5_sfEvent, 95);
  c5_Y0u = -8.0E-5;
  _SFD_SCRIPT_CALL(0U, chartInstance->c5_sfEvent, 95);
  c5_N0u = 6.0E-5;
  _SFD_SCRIPT_CALL(0U, chartInstance->c5_sfEvent, 96);
  c5_Y0uu = -4.0E-5;
  _SFD_SCRIPT_CALL(0U, chartInstance->c5_sfEvent, 96);
  c5_N0uu = 3.0E-5;
  _SFD_SCRIPT_CALL(0U, chartInstance->c5_sfEvent, 99);
  c5_m11 = 0.0084;
  _SFD_SCRIPT_CALL(0U, chartInstance->c5_sfEvent, 100);
  c5_m22 = 0.015459999999999998;
  _SFD_SCRIPT_CALL(0U, chartInstance->c5_sfEvent, 101);
  c5_m23 = -8.9999999999999965E-5;
  _SFD_SCRIPT_CALL(0U, chartInstance->c5_sfEvent, 102);
  c5_m32 = -0.00022999999999999995;
  _SFD_SCRIPT_CALL(0U, chartInstance->c5_sfEvent, 103);
  c5_m33 = 0.00083;
  _SFD_SCRIPT_CALL(0U, chartInstance->c5_sfEvent, 113);
  c5_delta_dot = 0.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c5_sfEvent, 114);
  c5_delta = c5_delta_c;
  _SFD_SCRIPT_CALL(0U, chartInstance->c5_sfEvent, 118);
  c5_b = c5_u;
  c5_h_y = -0.00184 * c5_b;
  c5_b_b = c5_mpower(chartInstance, c5_u);
  c5_i_y = -0.0011 * c5_b_b;
  c5_c_b = c5_b_mpower(chartInstance, c5_u);
  c5_j_y = -0.00215 * c5_c_b;
  c5_d_b = c5_mpower(chartInstance, c5_v);
  c5_k_y = -0.00899 * c5_d_b;
  c5_e_b = c5_mpower(chartInstance, c5_r);
  c5_l_y = 0.00018 * c5_e_b;
  c5_f_b = c5_r;
  c5_m_y = 0.00798 * c5_f_b;
  c5_b_a = c5_m_y;
  c5_g_b = c5_v;
  c5_n_y = c5_b_a * c5_g_b;
  c5_h_b = c5_mpower(chartInstance, c5_delta);
  c5_o_y = -0.00095 * c5_h_b;
  c5_i_b = c5_u;
  c5_p_y = -0.0019 * c5_i_b;
  c5_c_a = c5_p_y;
  c5_j_b = c5_mpower(chartInstance, c5_delta);
  c5_q_y = c5_c_a * c5_j_b;
  c5_k_b = c5_v;
  c5_r_y = 0.00093 * c5_k_b;
  c5_d_a = c5_r_y;
  c5_l_b = c5_delta;
  c5_s_y = c5_d_a * c5_l_b;
  c5_m_b = c5_u;
  c5_t_y = 0.00093 * c5_m_b;
  c5_e_a = c5_t_y;
  c5_n_b = c5_v;
  c5_u_y = c5_e_a * c5_n_b;
  c5_f_a = c5_u_y;
  c5_o_b = c5_delta;
  c5_v_y = c5_f_a * c5_o_b;
  c5_X = ((((((((c5_h_y + c5_i_y) + c5_j_y) + c5_k_y) + c5_l_y) + c5_n_y) +
            c5_o_y) + c5_q_y) + c5_s_y) + c5_v_y;
  _SFD_SCRIPT_CALL(0U, chartInstance->c5_sfEvent, 121);
  c5_p_b = c5_v;
  c5_w_y = -0.0116 * c5_p_b;
  c5_q_b = c5_r;
  c5_x_y = -0.00499 * c5_q_b;
  c5_r_b = c5_b_mpower(chartInstance, c5_v);
  c5_y_y = -0.08078 * c5_r_b;
  c5_s_b = c5_mpower(chartInstance, c5_v);
  c5_ab_y = 0.15356 * c5_s_b;
  c5_g_a = c5_ab_y;
  c5_t_b = c5_r;
  c5_bb_y = c5_g_a * c5_t_b;
  c5_u_b = c5_v;
  c5_cb_y = -0.0116 * c5_u_b;
  c5_h_a = c5_cb_y;
  c5_v_b = c5_u;
  c5_db_y = c5_h_a * c5_v_b;
  c5_w_b = c5_r;
  c5_eb_y = -0.00499 * c5_w_b;
  c5_i_a = c5_eb_y;
  c5_x_b = c5_u;
  c5_fb_y = c5_i_a * c5_x_b;
  c5_y_b = c5_delta;
  c5_gb_y = 0.00278 * c5_y_b;
  c5_ab_b = c5_b_mpower(chartInstance, c5_delta);
  c5_hb_y = -0.0009 * c5_ab_b;
  c5_bb_b = c5_u;
  c5_ib_y = 0.00556 * c5_bb_b;
  c5_j_a = c5_ib_y;
  c5_cb_b = c5_delta;
  c5_jb_y = c5_j_a * c5_cb_b;
  c5_db_b = c5_mpower(chartInstance, c5_u);
  c5_kb_y = 0.00278 * c5_db_b;
  c5_k_a = c5_kb_y;
  c5_eb_b = c5_delta;
  c5_lb_y = c5_k_a * c5_eb_b;
  c5_fb_b = c5_v;
  c5_mb_y = -4.0E-5 * c5_fb_b;
  c5_l_a = c5_mb_y;
  c5_gb_b = c5_mpower(chartInstance, c5_delta);
  c5_nb_y = c5_l_a * c5_gb_b;
  c5_hb_b = c5_mpower(chartInstance, c5_v);
  c5_ob_y = 0.0119 * c5_hb_b;
  c5_m_a = c5_ob_y;
  c5_ib_b = c5_delta;
  c5_pb_y = c5_m_a * c5_ib_b;
  c5_Y = ((((((((((c5_w_y + c5_x_y) + c5_y_y) + c5_bb_y) + c5_db_y) + c5_fb_y) +
              c5_gb_y) + c5_hb_y) + c5_jb_y) + c5_lb_y) + c5_nb_y) + c5_pb_y;
  _SFD_SCRIPT_CALL(0U, chartInstance->c5_sfEvent, 125);
  c5_jb_b = c5_v;
  c5_qb_y = -0.00264 * c5_jb_b;
  c5_kb_b = c5_r;
  c5_rb_y = -0.00166 * c5_kb_b;
  c5_lb_b = c5_b_mpower(chartInstance, c5_v);
  c5_sb_y = 0.01636 * c5_lb_b;
  c5_mb_b = c5_mpower(chartInstance, c5_v);
  c5_tb_y = -0.05483 * c5_mb_b;
  c5_n_a = c5_tb_y;
  c5_nb_b = c5_r;
  c5_ub_y = c5_n_a * c5_nb_b;
  c5_ob_b = c5_v;
  c5_vb_y = -0.00264 * c5_ob_b;
  c5_o_a = c5_vb_y;
  c5_pb_b = c5_u;
  c5_wb_y = c5_o_a * c5_pb_b;
  c5_qb_b = c5_r;
  c5_xb_y = -0.00166 * c5_qb_b;
  c5_p_a = c5_xb_y;
  c5_rb_b = c5_u;
  c5_yb_y = c5_p_a * c5_rb_b;
  c5_sb_b = c5_delta;
  c5_ac_y = -0.00139 * c5_sb_b;
  c5_tb_b = c5_b_mpower(chartInstance, c5_delta);
  c5_bc_y = 0.00045 * c5_tb_b;
  c5_ub_b = c5_u;
  c5_cc_y = -0.00278 * c5_ub_b;
  c5_q_a = c5_cc_y;
  c5_vb_b = c5_delta;
  c5_dc_y = c5_q_a * c5_vb_b;
  c5_wb_b = c5_mpower(chartInstance, c5_u);
  c5_ec_y = -0.00139 * c5_wb_b;
  c5_r_a = c5_ec_y;
  c5_xb_b = c5_delta;
  c5_fc_y = c5_r_a * c5_xb_b;
  c5_yb_b = c5_v;
  c5_gc_y = 0.00013 * c5_yb_b;
  c5_s_a = c5_gc_y;
  c5_ac_b = c5_mpower(chartInstance, c5_delta);
  c5_hc_y = c5_s_a * c5_ac_b;
  c5_bc_b = c5_mpower(chartInstance, c5_v);
  c5_ic_y = -0.00489 * c5_bc_b;
  c5_t_a = c5_ic_y;
  c5_cc_b = c5_delta;
  c5_jc_y = c5_t_a * c5_cc_b;
  c5_N = (((((((((((c5_qb_y + c5_rb_y) + c5_sb_y) + c5_ub_y) + c5_wb_y) +
                c5_yb_y) + c5_ac_y) + c5_bc_y) + c5_dc_y) + c5_fc_y) + c5_hc_y)
          + c5_jc_y) + c5_NOISE;
  _SFD_SCRIPT_CALL(0U, chartInstance->c5_sfEvent, 130U);
  c5_detM22 = 1.2811099999999998E-5;
  _SFD_SCRIPT_CALL(0U, chartInstance->c5_sfEvent, 138U);
  c5_d_A = c5_mpower(chartInstance, *c5_U);
  c5_h_x = c5_d_A;
  c5_i_x = c5_h_x;
  c5_kc_y = c5_i_x / 160.93;
  c5_u_a = c5_X;
  c5_dc_b = c5_kc_y;
  c5_lc_y = c5_u_a * c5_dc_b;
  c5_e_A = c5_lc_y;
  c5_j_x = c5_e_A;
  c5_k_x = c5_j_x;
  c5_mc_y = c5_k_x / 0.0084;
  c5_ec_b = c5_Y;
  c5_nc_y = -0.00083 * c5_ec_b;
  c5_fc_b = c5_N;
  c5_oc_y = -8.9999999999999965E-5 * c5_fc_b;
  c5_f_A = c5_mpower(chartInstance, *c5_U);
  c5_l_x = c5_f_A;
  c5_m_x = c5_l_x;
  c5_pc_y = c5_m_x / 160.93;
  c5_v_a = -(c5_nc_y + c5_oc_y);
  c5_gc_b = c5_pc_y;
  c5_qc_y = c5_v_a * c5_gc_b;
  c5_g_A = c5_qc_y;
  c5_n_x = c5_g_A;
  c5_o_x = c5_n_x;
  c5_rc_y = c5_o_x / 1.2811099999999998E-5;
  c5_hc_b = c5_Y;
  c5_sc_y = 0.00022999999999999995 * c5_hc_b;
  c5_ic_b = c5_N;
  c5_tc_y = 0.015459999999999998 * c5_ic_b;
  c5_h_A = c5_mpower(chartInstance, *c5_U);
  c5_p_x = c5_h_A;
  c5_q_x = c5_p_x;
  c5_uc_y = c5_q_x / 25898.464900000003;
  c5_w_a = c5_sc_y + c5_tc_y;
  c5_jc_b = c5_uc_y;
  c5_vc_y = c5_w_a * c5_jc_b;
  c5_i_A = c5_vc_y;
  c5_r_x = c5_i_A;
  c5_s_x = c5_r_x;
  c5_wc_y = c5_s_x / 1.2811099999999998E-5;
  c5_t_x = c5_psi;
  c5_u_x = c5_t_x;
  c5_u_x = muDoubleScalarCos(c5_u_x);
  c5_j_A = c5_b_U0;
  c5_d_B = *c5_U;
  c5_v_x = c5_j_A;
  c5_xc_y = c5_d_B;
  c5_w_x = c5_v_x;
  c5_yc_y = c5_xc_y;
  c5_ad_y = c5_w_x / c5_yc_y;
  c5_x_a = c5_u_x;
  c5_kc_b = c5_ad_y + c5_u;
  c5_bd_y = c5_x_a * c5_kc_b;
  c5_x_x = c5_psi;
  c5_y_x = c5_x_x;
  c5_y_x = muDoubleScalarSin(c5_y_x);
  c5_y_a = c5_y_x;
  c5_lc_b = c5_v;
  c5_cd_y = c5_y_a * c5_lc_b;
  c5_ab_a = c5_bd_y - c5_cd_y;
  c5_mc_b = *c5_U;
  c5_dd_y = c5_ab_a * c5_mc_b;
  c5_ab_x = c5_psi;
  c5_bb_x = c5_ab_x;
  c5_bb_x = muDoubleScalarSin(c5_bb_x);
  c5_k_A = c5_b_U0;
  c5_e_B = *c5_U;
  c5_cb_x = c5_k_A;
  c5_ed_y = c5_e_B;
  c5_db_x = c5_cb_x;
  c5_fd_y = c5_ed_y;
  c5_gd_y = c5_db_x / c5_fd_y;
  c5_bb_a = c5_bb_x;
  c5_nc_b = c5_gd_y + c5_u;
  c5_hd_y = c5_bb_a * c5_nc_b;
  c5_eb_x = c5_psi;
  c5_fb_x = c5_eb_x;
  c5_fb_x = muDoubleScalarCos(c5_fb_x);
  c5_cb_a = c5_fb_x;
  c5_oc_b = c5_v;
  c5_id_y = c5_cb_a * c5_oc_b;
  c5_db_a = c5_hd_y + c5_id_y;
  c5_pc_b = *c5_U;
  c5_jd_y = c5_db_a * c5_pc_b;
  c5_l_A = *c5_U;
  c5_gb_x = c5_l_A;
  c5_hb_x = c5_gb_x;
  c5_kd_y = c5_hb_x / 160.93;
  c5_eb_a = c5_r;
  c5_qc_b = c5_kd_y;
  c5_ld_y = c5_eb_a * c5_qc_b;
  c5_xdot[0] = c5_mc_y;
  c5_xdot[1] = c5_rc_y;
  c5_xdot[2] = c5_wc_y;
  c5_xdot[3] = c5_dd_y;
  c5_xdot[4] = c5_jd_y;
  c5_xdot[5] = c5_ld_y;
  c5_xdot[6] = c5_delta_dot;
  _SFD_SCRIPT_CALL(0U, chartInstance->c5_sfEvent, -138);
  sf_debug_symbol_scope_pop();
}

static real_T c5_mpower(SFc5_testInstanceStruct *chartInstance, real_T c5_a)
{
  real_T c5_b_a;
  real_T c5_c_a;
  real_T c5_ak;
  c5_b_a = c5_a;
  c5_c_a = c5_b_a;
  c5_eml_scalar_eg(chartInstance);
  c5_ak = c5_c_a;
  return muDoubleScalarPower(c5_ak, 2.0);
}

static void c5_eml_scalar_eg(SFc5_testInstanceStruct *chartInstance)
{
}

static real_T c5_sqrt(SFc5_testInstanceStruct *chartInstance, real_T c5_x)
{
  real_T c5_b_x;
  c5_b_x = c5_x;
  c5_b_sqrt(chartInstance, &c5_b_x);
  return c5_b_x;
}

static void c5_eml_error(SFc5_testInstanceStruct *chartInstance)
{
  int32_T c5_i40;
  static char_T c5_varargin_1[30] = { 'C', 'o', 'd', 'e', 'r', ':', 't', 'o',
    'o', 'l', 'b', 'o', 'x', ':', 's', 'q', 'r', 't', '_', 'd', 'o', 'm', 'a',
    'i', 'n', 'E', 'r', 'r', 'o', 'r' };

  char_T c5_u[30];
  const mxArray *c5_y = NULL;
  for (c5_i40 = 0; c5_i40 < 30; c5_i40++) {
    c5_u[c5_i40] = c5_varargin_1[c5_i40];
  }

  c5_y = NULL;
  sf_mex_assign(&c5_y, sf_mex_create("y", c5_u, 10, 0U, 1U, 0U, 2, 1, 30), FALSE);
  sf_mex_call_debug("error", 0U, 1U, 14, sf_mex_call_debug("message", 1U, 1U, 14,
    c5_y));
}

static real_T c5_b_mpower(SFc5_testInstanceStruct *chartInstance, real_T c5_a)
{
  real_T c5_b_a;
  real_T c5_c_a;
  real_T c5_ak;
  c5_b_a = c5_a;
  c5_c_a = c5_b_a;
  c5_eml_scalar_eg(chartInstance);
  c5_ak = c5_c_a;
  return muDoubleScalarPower(c5_ak, 3.0);
}

static const mxArray *c5_c_sf_marshallOut(void *chartInstanceVoid, void
  *c5_inData)
{
  const mxArray *c5_mxArrayOutData = NULL;
  int32_T c5_u;
  const mxArray *c5_y = NULL;
  SFc5_testInstanceStruct *chartInstance;
  chartInstance = (SFc5_testInstanceStruct *)chartInstanceVoid;
  c5_mxArrayOutData = NULL;
  c5_u = *(int32_T *)c5_inData;
  c5_y = NULL;
  sf_mex_assign(&c5_y, sf_mex_create("y", &c5_u, 6, 0U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c5_mxArrayOutData, c5_y, FALSE);
  return c5_mxArrayOutData;
}

static int32_T c5_e_emlrt_marshallIn(SFc5_testInstanceStruct *chartInstance,
  const mxArray *c5_u, const emlrtMsgIdentifier *c5_parentId)
{
  int32_T c5_y;
  int32_T c5_i41;
  sf_mex_import(c5_parentId, sf_mex_dup(c5_u), &c5_i41, 1, 6, 0U, 0, 0U, 0);
  c5_y = c5_i41;
  sf_mex_destroy(&c5_u);
  return c5_y;
}

static void c5_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c5_mxArrayInData, const char_T *c5_varName, void *c5_outData)
{
  const mxArray *c5_b_sfEvent;
  const char_T *c5_identifier;
  emlrtMsgIdentifier c5_thisId;
  int32_T c5_y;
  SFc5_testInstanceStruct *chartInstance;
  chartInstance = (SFc5_testInstanceStruct *)chartInstanceVoid;
  c5_b_sfEvent = sf_mex_dup(c5_mxArrayInData);
  c5_identifier = c5_varName;
  c5_thisId.fIdentifier = c5_identifier;
  c5_thisId.fParent = NULL;
  c5_y = c5_e_emlrt_marshallIn(chartInstance, sf_mex_dup(c5_b_sfEvent),
    &c5_thisId);
  sf_mex_destroy(&c5_b_sfEvent);
  *(int32_T *)c5_outData = c5_y;
  sf_mex_destroy(&c5_mxArrayInData);
}

static uint8_T c5_f_emlrt_marshallIn(SFc5_testInstanceStruct *chartInstance,
  const mxArray *c5_b_is_active_c5_test, const char_T *c5_identifier)
{
  uint8_T c5_y;
  emlrtMsgIdentifier c5_thisId;
  c5_thisId.fIdentifier = c5_identifier;
  c5_thisId.fParent = NULL;
  c5_y = c5_g_emlrt_marshallIn(chartInstance, sf_mex_dup(c5_b_is_active_c5_test),
    &c5_thisId);
  sf_mex_destroy(&c5_b_is_active_c5_test);
  return c5_y;
}

static uint8_T c5_g_emlrt_marshallIn(SFc5_testInstanceStruct *chartInstance,
  const mxArray *c5_u, const emlrtMsgIdentifier *c5_parentId)
{
  uint8_T c5_y;
  uint8_T c5_u0;
  sf_mex_import(c5_parentId, sf_mex_dup(c5_u), &c5_u0, 1, 3, 0U, 0, 0U, 0);
  c5_y = c5_u0;
  sf_mex_destroy(&c5_u);
  return c5_y;
}

static void c5_b_sqrt(SFc5_testInstanceStruct *chartInstance, real_T *c5_x)
{
  if (*c5_x < 0.0) {
    c5_eml_error(chartInstance);
  }

  *c5_x = muDoubleScalarSqrt(*c5_x);
}

static void init_dsm_address_info(SFc5_testInstanceStruct *chartInstance)
{
}

/* SFunction Glue Code */
void sf_c5_test_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(1405131891U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(2575658541U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(3926913883U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(146813091U);
}

mxArray *sf_c5_test_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1,1,5,
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateString("LY13EmZuzuxBKGUwdKXLrE");
    mxSetField(mxAutoinheritanceInfo,0,"checksum",mxChecksum);
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,3,3,dataFields);

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

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(7);
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
      pr[0] = (double)(7);
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

static const mxArray *sf_get_sim_state_info_c5_test(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x4'type','srcId','name','auxInfo'{{M[1],M[9],T\"Theta_wo\",},{M[1],M[7],T\"U\",},{M[1],M[5],T\"x_next\",},{M[8],M[0],T\"is_active_c5_test\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 4, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c5_test_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc5_testInstanceStruct *chartInstance;
    chartInstance = (SFc5_testInstanceStruct *) ((ChartInfoStruct *)
      (ssGetUserData(S)))->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart(_testMachineNumber_,
          5,
          1,
          1,
          8,
          0,
          0,
          0,
          0,
          1,
          &(chartInstance->chartNumber),
          &(chartInstance->instanceNumber),
          ssGetPath(S),
          (void *)S);
        if (chartAlreadyPresent==0) {
          /* this is the first instance */
          init_script_number_translation(_testMachineNumber_,
            chartInstance->chartNumber);
          sf_debug_set_chart_disable_implicit_casting(_testMachineNumber_,
            chartInstance->chartNumber,1);
          sf_debug_set_chart_event_thresholds(_testMachineNumber_,
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
        _SFD_CV_INIT_EML_FCN(0,0,"eML_blk_kernel",0,-1,872);
        _SFD_CV_INIT_SCRIPT(0,1,3,0,0,0,0,0,0,0);
        _SFD_CV_INIT_SCRIPT_FCN(0,0,"mariner",0,-1,5785);
        _SFD_CV_INIT_SCRIPT_IF(0,0,2401,2421,-1,2468);
        _SFD_CV_INIT_SCRIPT_IF(0,1,2469,2489,-1,2530);
        _SFD_CV_INIT_SCRIPT_IF(0,2,2531,2543,-1,2561);
        _SFD_TRANS_COV_WTS(0,0,0,1,0);
        if (chartAlreadyPresent==0) {
          _SFD_TRANS_COV_MAPS(0,
                              0,NULL,NULL,
                              0,NULL,NULL,
                              1,NULL,NULL,
                              0,NULL,NULL);
        }

        _SFD_SET_DATA_COMPILED_PROPS(0,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c5_sf_marshallOut,(MexInFcnForType)NULL);

        {
          unsigned int dimVector[1];
          dimVector[0]= 7;
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
          dimVector[0]= 7;
          _SFD_SET_DATA_COMPILED_PROPS(7,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c5_b_sf_marshallOut,(MexInFcnForType)NULL);
        }

        {
          real_T *c5_NOISE;
          real_T *c5_ui;
          real_T *c5_U;
          real_T *c5_Theta_wo;
          real_T (*c5_x_next)[7];
          real_T (*c5_x)[7];
          c5_x = (real_T (*)[7])ssGetInputPortSignal(chartInstance->S, 2);
          c5_Theta_wo = (real_T *)ssGetOutputPortSignal(chartInstance->S, 3);
          c5_U = (real_T *)ssGetOutputPortSignal(chartInstance->S, 2);
          c5_ui = (real_T *)ssGetInputPortSignal(chartInstance->S, 1);
          c5_x_next = (real_T (*)[7])ssGetOutputPortSignal(chartInstance->S, 1);
          c5_NOISE = (real_T *)ssGetInputPortSignal(chartInstance->S, 0);
          _SFD_SET_DATA_VALUE_PTR(0U, c5_NOISE);
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
      sf_debug_reset_current_state_configuration(_testMachineNumber_,
        chartInstance->chartNumber,chartInstance->instanceNumber);
    }
  }
}

static const char* sf_get_instance_specialization()
{
  return "lpez2Q6NJOZMoFgTGisvQE";
}

static void sf_opaque_initialize_c5_test(void *chartInstanceVar)
{
  chart_debug_initialization(((SFc5_testInstanceStruct*) chartInstanceVar)->S,0);
  initialize_params_c5_test((SFc5_testInstanceStruct*) chartInstanceVar);
  initialize_c5_test((SFc5_testInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_enable_c5_test(void *chartInstanceVar)
{
  enable_c5_test((SFc5_testInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_disable_c5_test(void *chartInstanceVar)
{
  disable_c5_test((SFc5_testInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_gateway_c5_test(void *chartInstanceVar)
{
  sf_c5_test((SFc5_testInstanceStruct*) chartInstanceVar);
}

extern const mxArray* sf_internal_get_sim_state_c5_test(SimStruct* S)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_raw2high");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = (mxArray*) get_sim_state_c5_test((SFc5_testInstanceStruct*)
    chartInfo->chartInstance);         /* raw sim ctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c5_test();/* state var info */
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

extern void sf_internal_set_sim_state_c5_test(SimStruct* S, const mxArray *st)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_high2raw");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = mxDuplicateArray(st);      /* high level simctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c5_test();/* state var info */
  mxError = sf_mex_call_matlab(1, plhs, 4, prhs, "sfprivate");
  mxDestroyArray(prhs[0]);
  mxDestroyArray(prhs[1]);
  mxDestroyArray(prhs[2]);
  mxDestroyArray(prhs[3]);
  if (mxError || plhs[0] == NULL) {
    sf_mex_error_message("Stateflow Internal Error: \nError calling 'chart_simctx_high2raw'.\n");
  }

  set_sim_state_c5_test((SFc5_testInstanceStruct*)chartInfo->chartInstance,
                        mxDuplicateArray(plhs[0]));
  mxDestroyArray(plhs[0]);
}

static const mxArray* sf_opaque_get_sim_state_c5_test(SimStruct* S)
{
  return sf_internal_get_sim_state_c5_test(S);
}

static void sf_opaque_set_sim_state_c5_test(SimStruct* S, const mxArray *st)
{
  sf_internal_set_sim_state_c5_test(S, st);
}

static void sf_opaque_terminate_c5_test(void *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc5_testInstanceStruct*) chartInstanceVar)->S;
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
    }

    finalize_c5_test((SFc5_testInstanceStruct*) chartInstanceVar);
    free((void *)chartInstanceVar);
    ssSetUserData(S,NULL);
  }

  unload_test_optimization_info();
}

static void sf_opaque_init_subchart_simstructs(void *chartInstanceVar)
{
  initSimStructsc5_test((SFc5_testInstanceStruct*) chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c5_test(SimStruct *S)
{
  int i;
  for (i=0;i<ssGetNumRunTimeParams(S);i++) {
    if (ssGetSFcnParamTunable(S,i)) {
      ssUpdateDlgParamAsRunTimeParam(S,i);
    }
  }

  if (sf_machine_global_initializer_called()) {
    initialize_params_c5_test((SFc5_testInstanceStruct*)(((ChartInfoStruct *)
      ssGetUserData(S))->chartInstance));
  }
}

static void mdlSetWorkWidths_c5_test(SimStruct *S)
{
  /* Actual parameters from chart:
     U0 h
   */
  const char_T *rtParamNames[] = { "p1", "p2" };

  ssSetNumRunTimeParams(S,ssGetSFcnParamsCount(S));

  /* registration for U0*/
  ssRegDlgParamAsRunTimeParam(S, 0, 0, rtParamNames[0], SS_DOUBLE);

  /* registration for h*/
  ssRegDlgParamAsRunTimeParam(S, 1, 1, rtParamNames[1], SS_DOUBLE);
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    mxArray *infoStruct = load_test_optimization_info();
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable(S,sf_get_instance_specialization(),infoStruct,
      5);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop(S,sf_get_instance_specialization(),
                infoStruct,5,"RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop(S,
      sf_get_instance_specialization(),infoStruct,5,
      "gatewayCannotBeInlinedMultipleTimes"));
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 1, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 2, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,sf_get_instance_specialization(),
        infoStruct,5,3);
      sf_mark_chart_reusable_outputs(S,sf_get_instance_specialization(),
        infoStruct,5,3);
    }

    sf_set_rtw_dwork_info(S,sf_get_instance_specialization(),infoStruct,5);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(4220367607U));
  ssSetChecksum1(S,(13115750U));
  ssSetChecksum2(S,(3209136066U));
  ssSetChecksum3(S,(2974261319U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
  ssSupportsMultipleExecInstances(S,1);
}

static void mdlRTW_c5_test(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c5_test(SimStruct *S)
{
  SFc5_testInstanceStruct *chartInstance;
  chartInstance = (SFc5_testInstanceStruct *)malloc(sizeof
    (SFc5_testInstanceStruct));
  memset(chartInstance, 0, sizeof(SFc5_testInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway = sf_opaque_gateway_c5_test;
  chartInstance->chartInfo.initializeChart = sf_opaque_initialize_c5_test;
  chartInstance->chartInfo.terminateChart = sf_opaque_terminate_c5_test;
  chartInstance->chartInfo.enableChart = sf_opaque_enable_c5_test;
  chartInstance->chartInfo.disableChart = sf_opaque_disable_c5_test;
  chartInstance->chartInfo.getSimState = sf_opaque_get_sim_state_c5_test;
  chartInstance->chartInfo.setSimState = sf_opaque_set_sim_state_c5_test;
  chartInstance->chartInfo.getSimStateInfo = sf_get_sim_state_info_c5_test;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c5_test;
  chartInstance->chartInfo.mdlStart = mdlStart_c5_test;
  chartInstance->chartInfo.mdlSetWorkWidths = mdlSetWorkWidths_c5_test;
  chartInstance->chartInfo.extModeExec = NULL;
  chartInstance->chartInfo.restoreLastMajorStepConfiguration = NULL;
  chartInstance->chartInfo.restoreBeforeLastMajorStepConfiguration = NULL;
  chartInstance->chartInfo.storeCurrentConfiguration = NULL;
  chartInstance->S = S;
  ssSetUserData(S,(void *)(&(chartInstance->chartInfo)));/* register the chart instance with simstruct */
  init_dsm_address_info(chartInstance);
  if (!sim_mode_is_rtw_gen(S)) {
  }

  sf_opaque_init_subchart_simstructs(chartInstance->chartInfo.chartInstance);
  chart_debug_initialization(S,1);
}

void c5_test_method_dispatcher(SimStruct *S, int_T method, void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c5_test(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c5_test(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c5_test(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c5_test_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}

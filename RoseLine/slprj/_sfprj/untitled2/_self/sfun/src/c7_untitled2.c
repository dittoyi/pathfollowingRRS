/* Include files */

#include <stddef.h>
#include "blas.h"
#include "untitled2_sfun.h"
#include "c7_untitled2.h"
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
static const char * c7_debug_family_names[15] = { "Theta_wp_c_dot", "nargin",
  "nargout", "Theta_wp", "Theta_wp_c", "Theta_po", "U", "Dis_PS_p", "c1", "c2",
  "k1", "h", "r_des", "Theta_wp_c_last", "Theta_po_last" };

/* Function Declarations */
static void initialize_c7_untitled2(SFc7_untitled2InstanceStruct *chartInstance);
static void initialize_params_c7_untitled2(SFc7_untitled2InstanceStruct
  *chartInstance);
static void enable_c7_untitled2(SFc7_untitled2InstanceStruct *chartInstance);
static void disable_c7_untitled2(SFc7_untitled2InstanceStruct *chartInstance);
static void c7_update_debugger_state_c7_untitled2(SFc7_untitled2InstanceStruct
  *chartInstance);
static const mxArray *get_sim_state_c7_untitled2(SFc7_untitled2InstanceStruct
  *chartInstance);
static void set_sim_state_c7_untitled2(SFc7_untitled2InstanceStruct
  *chartInstance, const mxArray *c7_st);
static void finalize_c7_untitled2(SFc7_untitled2InstanceStruct *chartInstance);
static void sf_gateway_c7_untitled2(SFc7_untitled2InstanceStruct *chartInstance);
static void initSimStructsc7_untitled2(SFc7_untitled2InstanceStruct
  *chartInstance);
static void init_script_number_translation(uint32_T c7_machineNumber, uint32_T
  c7_chartNumber, uint32_T c7_instanceNumber);
static const mxArray *c7_sf_marshallOut(void *chartInstanceVoid, void *c7_inData);
static real_T c7_emlrt_marshallIn(SFc7_untitled2InstanceStruct *chartInstance,
  const mxArray *c7_b_Theta_po_last, const char_T *c7_identifier);
static real_T c7_b_emlrt_marshallIn(SFc7_untitled2InstanceStruct *chartInstance,
  const mxArray *c7_u, const emlrtMsgIdentifier *c7_parentId);
static void c7_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c7_mxArrayInData, const char_T *c7_varName, void *c7_outData);
static const mxArray *c7_b_sf_marshallOut(void *chartInstanceVoid, void
  *c7_inData);
static real_T c7_c_emlrt_marshallIn(SFc7_untitled2InstanceStruct *chartInstance,
  const mxArray *c7_b_Theta_wp_c_last, const char_T *c7_identifier);
static real_T c7_d_emlrt_marshallIn(SFc7_untitled2InstanceStruct *chartInstance,
  const mxArray *c7_u, const emlrtMsgIdentifier *c7_parentId);
static void c7_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c7_mxArrayInData, const char_T *c7_varName, void *c7_outData);
static const mxArray *c7_c_sf_marshallOut(void *chartInstanceVoid, void
  *c7_inData);
static real_T c7_e_emlrt_marshallIn(SFc7_untitled2InstanceStruct *chartInstance,
  const mxArray *c7_r_des, const char_T *c7_identifier);
static real_T c7_f_emlrt_marshallIn(SFc7_untitled2InstanceStruct *chartInstance,
  const mxArray *c7_u, const emlrtMsgIdentifier *c7_parentId);
static void c7_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c7_mxArrayInData, const char_T *c7_varName, void *c7_outData);
static const mxArray *c7_d_sf_marshallOut(void *chartInstanceVoid, void
  *c7_inData);
static void c7_info_helper(const mxArray **c7_info);
static const mxArray *c7_emlrt_marshallOut(const char * c7_u);
static const mxArray *c7_b_emlrt_marshallOut(const uint32_T c7_u);
static const mxArray *c7_e_sf_marshallOut(void *chartInstanceVoid, void
  *c7_inData);
static int32_T c7_g_emlrt_marshallIn(SFc7_untitled2InstanceStruct *chartInstance,
  const mxArray *c7_u, const emlrtMsgIdentifier *c7_parentId);
static void c7_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c7_mxArrayInData, const char_T *c7_varName, void *c7_outData);
static uint8_T c7_h_emlrt_marshallIn(SFc7_untitled2InstanceStruct *chartInstance,
  const mxArray *c7_b_is_active_c7_untitled2, const char_T *c7_identifier);
static uint8_T c7_i_emlrt_marshallIn(SFc7_untitled2InstanceStruct *chartInstance,
  const mxArray *c7_u, const emlrtMsgIdentifier *c7_parentId);
static void init_dsm_address_info(SFc7_untitled2InstanceStruct *chartInstance);

/* Function Definitions */
static void initialize_c7_untitled2(SFc7_untitled2InstanceStruct *chartInstance)
{
  chartInstance->c7_sfEvent = CALL_EVENT;
  _sfTime_ = sf_get_time(chartInstance->S);
  chartInstance->c7_Theta_wp_c_last_not_empty = false;
  chartInstance->c7_Theta_po_last_not_empty = false;
  chartInstance->c7_is_active_c7_untitled2 = 0U;
}

static void initialize_params_c7_untitled2(SFc7_untitled2InstanceStruct
  *chartInstance)
{
  real_T c7_d0;
  real_T c7_d1;
  real_T c7_d2;
  real_T c7_d3;
  sf_mex_import_named("c1", sf_mex_get_sfun_param(chartInstance->S, 0, 0),
                      &c7_d0, 0, 0, 0U, 0, 0U, 0);
  chartInstance->c7_c1 = c7_d0;
  sf_mex_import_named("c2", sf_mex_get_sfun_param(chartInstance->S, 1, 0),
                      &c7_d1, 0, 0, 0U, 0, 0U, 0);
  chartInstance->c7_c2 = c7_d1;
  sf_mex_import_named("k1", sf_mex_get_sfun_param(chartInstance->S, 3, 0),
                      &c7_d2, 0, 0, 0U, 0, 0U, 0);
  chartInstance->c7_k1 = c7_d2;
  sf_mex_import_named("h", sf_mex_get_sfun_param(chartInstance->S, 2, 0), &c7_d3,
                      0, 0, 0U, 0, 0U, 0);
  chartInstance->c7_h = c7_d3;
}

static void enable_c7_untitled2(SFc7_untitled2InstanceStruct *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void disable_c7_untitled2(SFc7_untitled2InstanceStruct *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void c7_update_debugger_state_c7_untitled2(SFc7_untitled2InstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static const mxArray *get_sim_state_c7_untitled2(SFc7_untitled2InstanceStruct
  *chartInstance)
{
  const mxArray *c7_st;
  const mxArray *c7_y = NULL;
  real_T c7_hoistedGlobal;
  real_T c7_u;
  const mxArray *c7_b_y = NULL;
  real_T c7_b_hoistedGlobal;
  real_T c7_b_u;
  const mxArray *c7_c_y = NULL;
  real_T c7_c_hoistedGlobal;
  real_T c7_c_u;
  const mxArray *c7_d_y = NULL;
  uint8_T c7_d_hoistedGlobal;
  uint8_T c7_d_u;
  const mxArray *c7_e_y = NULL;
  real_T *c7_r_des;
  c7_r_des = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c7_st = NULL;
  c7_st = NULL;
  c7_y = NULL;
  sf_mex_assign(&c7_y, sf_mex_createcellmatrix(4, 1), false);
  c7_hoistedGlobal = *c7_r_des;
  c7_u = c7_hoistedGlobal;
  c7_b_y = NULL;
  sf_mex_assign(&c7_b_y, sf_mex_create("y", &c7_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c7_y, 0, c7_b_y);
  c7_b_hoistedGlobal = chartInstance->c7_Theta_po_last;
  c7_b_u = c7_b_hoistedGlobal;
  c7_c_y = NULL;
  if (!chartInstance->c7_Theta_po_last_not_empty) {
    sf_mex_assign(&c7_c_y, sf_mex_create("y", NULL, 0, 0U, 1U, 0U, 2, 0, 0),
                  false);
  } else {
    sf_mex_assign(&c7_c_y, sf_mex_create("y", &c7_b_u, 0, 0U, 0U, 0U, 0), false);
  }

  sf_mex_setcell(c7_y, 1, c7_c_y);
  c7_c_hoistedGlobal = chartInstance->c7_Theta_wp_c_last;
  c7_c_u = c7_c_hoistedGlobal;
  c7_d_y = NULL;
  if (!chartInstance->c7_Theta_wp_c_last_not_empty) {
    sf_mex_assign(&c7_d_y, sf_mex_create("y", NULL, 0, 0U, 1U, 0U, 2, 0, 0),
                  false);
  } else {
    sf_mex_assign(&c7_d_y, sf_mex_create("y", &c7_c_u, 0, 0U, 0U, 0U, 0), false);
  }

  sf_mex_setcell(c7_y, 2, c7_d_y);
  c7_d_hoistedGlobal = chartInstance->c7_is_active_c7_untitled2;
  c7_d_u = c7_d_hoistedGlobal;
  c7_e_y = NULL;
  sf_mex_assign(&c7_e_y, sf_mex_create("y", &c7_d_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c7_y, 3, c7_e_y);
  sf_mex_assign(&c7_st, c7_y, false);
  return c7_st;
}

static void set_sim_state_c7_untitled2(SFc7_untitled2InstanceStruct
  *chartInstance, const mxArray *c7_st)
{
  const mxArray *c7_u;
  real_T *c7_r_des;
  c7_r_des = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  chartInstance->c7_doneDoubleBufferReInit = true;
  c7_u = sf_mex_dup(c7_st);
  *c7_r_des = c7_e_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell
    (c7_u, 0)), "r_des");
  chartInstance->c7_Theta_po_last = c7_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c7_u, 1)), "Theta_po_last");
  chartInstance->c7_Theta_wp_c_last = c7_c_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c7_u, 2)), "Theta_wp_c_last");
  chartInstance->c7_is_active_c7_untitled2 = c7_h_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c7_u, 3)), "is_active_c7_untitled2");
  sf_mex_destroy(&c7_u);
  c7_update_debugger_state_c7_untitled2(chartInstance);
  sf_mex_destroy(&c7_st);
}

static void finalize_c7_untitled2(SFc7_untitled2InstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void sf_gateway_c7_untitled2(SFc7_untitled2InstanceStruct *chartInstance)
{
  real_T c7_hoistedGlobal;
  real_T c7_b_hoistedGlobal;
  real_T c7_c_hoistedGlobal;
  real_T c7_d_hoistedGlobal;
  real_T c7_e_hoistedGlobal;
  real_T c7_f_hoistedGlobal;
  real_T c7_g_hoistedGlobal;
  real_T c7_h_hoistedGlobal;
  real_T c7_Theta_wp;
  real_T c7_Theta_wp_c;
  real_T c7_Theta_po;
  real_T c7_U;
  int32_T c7_i0;
  real_T c7_Dis_PS_p[2];
  real_T c7_b_c1;
  real_T c7_b_c2;
  real_T c7_b_k1;
  real_T c7_b_h;
  uint32_T c7_debug_family_var_map[15];
  real_T c7_Theta_wp_c_dot;
  real_T c7_nargin = 9.0;
  real_T c7_nargout = 1.0;
  real_T c7_r_des;
  real_T c7_i_hoistedGlobal;
  real_T c7_A;
  real_T c7_B;
  real_T c7_x;
  real_T c7_y;
  real_T c7_b_x;
  real_T c7_b_y;
  real_T c7_c_x;
  real_T c7_c_y;
  real_T c7_d_x;
  real_T c7_e_x;
  real_T c7_d_y;
  real_T c7_b_A;
  real_T c7_b_B;
  real_T c7_f_x;
  real_T c7_e_y;
  real_T c7_g_x;
  real_T c7_f_y;
  real_T c7_h_x;
  real_T c7_g_y;
  real_T c7_h_y;
  real_T c7_i_x;
  real_T c7_j_x;
  real_T c7_k_x;
  real_T c7_l_x;
  real_T c7_c_A;
  real_T c7_c_B;
  real_T c7_m_x;
  real_T c7_i_y;
  real_T c7_n_x;
  real_T c7_j_y;
  real_T c7_o_x;
  real_T c7_k_y;
  real_T c7_l_y;
  int32_T c7_i1;
  real_T *c7_b_U;
  real_T *c7_b_Theta_po;
  real_T *c7_b_Theta_wp_c;
  real_T *c7_b_Theta_wp;
  real_T *c7_b_r_des;
  real_T (*c7_b_Dis_PS_p)[2];
  c7_b_Dis_PS_p = (real_T (*)[2])ssGetInputPortSignal(chartInstance->S, 4);
  c7_b_U = (real_T *)ssGetInputPortSignal(chartInstance->S, 3);
  c7_b_Theta_po = (real_T *)ssGetInputPortSignal(chartInstance->S, 2);
  c7_b_Theta_wp_c = (real_T *)ssGetInputPortSignal(chartInstance->S, 1);
  c7_b_r_des = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c7_b_Theta_wp = (real_T *)ssGetInputPortSignal(chartInstance->S, 0);
  _SFD_SYMBOL_SCOPE_PUSH(0U, 0U);
  _sfTime_ = sf_get_time(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 6U, chartInstance->c7_sfEvent);
  _SFD_DATA_RANGE_CHECK(*c7_b_Theta_wp, 0U);
  chartInstance->c7_sfEvent = CALL_EVENT;
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 6U, chartInstance->c7_sfEvent);
  c7_hoistedGlobal = *c7_b_Theta_wp;
  c7_b_hoistedGlobal = *c7_b_Theta_wp_c;
  c7_c_hoistedGlobal = *c7_b_Theta_po;
  c7_d_hoistedGlobal = *c7_b_U;
  c7_e_hoistedGlobal = chartInstance->c7_c1;
  c7_f_hoistedGlobal = chartInstance->c7_c2;
  c7_g_hoistedGlobal = chartInstance->c7_k1;
  c7_h_hoistedGlobal = chartInstance->c7_h;
  c7_Theta_wp = c7_hoistedGlobal;
  c7_Theta_wp_c = c7_b_hoistedGlobal;
  c7_Theta_po = c7_c_hoistedGlobal;
  c7_U = c7_d_hoistedGlobal;
  for (c7_i0 = 0; c7_i0 < 2; c7_i0++) {
    c7_Dis_PS_p[c7_i0] = (*c7_b_Dis_PS_p)[c7_i0];
  }

  c7_b_c1 = c7_e_hoistedGlobal;
  c7_b_c2 = c7_f_hoistedGlobal;
  c7_b_k1 = c7_g_hoistedGlobal;
  c7_b_h = c7_h_hoistedGlobal;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 15U, 15U, c7_debug_family_names,
    c7_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c7_Theta_wp_c_dot, 0U,
    c7_c_sf_marshallOut, c7_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c7_nargin, 1U, c7_c_sf_marshallOut,
    c7_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c7_nargout, 2U, c7_c_sf_marshallOut,
    c7_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c7_Theta_wp, 3U, c7_c_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c7_Theta_wp_c, 4U, c7_c_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c7_Theta_po, 5U, c7_c_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c7_U, 6U, c7_c_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(c7_Dis_PS_p, 7U, c7_d_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c7_b_c1, 8U, c7_c_sf_marshallOut,
    c7_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c7_b_c2, 9U, c7_c_sf_marshallOut,
    c7_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c7_b_k1, 10U, c7_c_sf_marshallOut,
    c7_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c7_b_h, 11U, c7_c_sf_marshallOut,
    c7_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c7_r_des, 12U, c7_c_sf_marshallOut,
    c7_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&chartInstance->c7_Theta_wp_c_last, 13U,
    c7_b_sf_marshallOut, c7_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&chartInstance->c7_Theta_po_last, 14U,
    c7_sf_marshallOut, c7_sf_marshallIn);
  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(0U, chartInstance->c7_sfEvent, 3);
  _SFD_EML_CALL(0U, chartInstance->c7_sfEvent, 4);
  if (CV_EML_IF(0, 1, 0, !chartInstance->c7_Theta_wp_c_last_not_empty)) {
    _SFD_EML_CALL(0U, chartInstance->c7_sfEvent, 5);
    chartInstance->c7_Theta_wp_c_last = 0.0;
    chartInstance->c7_Theta_wp_c_last_not_empty = true;
  }

  _SFD_EML_CALL(0U, chartInstance->c7_sfEvent, 7);
  c7_i_hoistedGlobal = chartInstance->c7_Theta_wp_c_last;
  c7_A = 0.0 * (c7_Theta_wp_c - c7_i_hoistedGlobal);
  c7_B = c7_b_h;
  c7_x = c7_A;
  c7_y = c7_B;
  c7_b_x = c7_x;
  c7_b_y = c7_y;
  c7_c_x = c7_b_x;
  c7_c_y = c7_b_y;
  c7_Theta_wp_c_dot = c7_c_x / c7_c_y;
  _SFD_EML_CALL(0U, chartInstance->c7_sfEvent, 9);
  _SFD_EML_CALL(0U, chartInstance->c7_sfEvent, 10);
  if (CV_EML_IF(0, 1, 1, !chartInstance->c7_Theta_po_last_not_empty)) {
    _SFD_EML_CALL(0U, chartInstance->c7_sfEvent, 11);
    chartInstance->c7_Theta_po_last = 0.0;
    chartInstance->c7_Theta_po_last_not_empty = true;
  }

  _SFD_EML_CALL(0U, chartInstance->c7_sfEvent, 15);
  c7_d_x = c7_Theta_wp - c7_Theta_wp_c;
  c7_e_x = c7_d_x;
  c7_d_y = muDoubleScalarAbs(c7_e_x);
  if (CV_EML_IF(0, 1, 2, c7_d_y < 0.01)) {
    _SFD_EML_CALL(0U, chartInstance->c7_sfEvent, 16);
    c7_b_A = c7_b_c1 * c7_U * c7_Dis_PS_p[1];
    c7_b_B = c7_b_c2;
    c7_f_x = c7_b_A;
    c7_e_y = c7_b_B;
    c7_g_x = c7_f_x;
    c7_f_y = c7_e_y;
    c7_h_x = c7_g_x;
    c7_g_y = c7_f_y;
    c7_h_y = c7_h_x / c7_g_y;
    c7_r_des = (c7_Theta_wp_c_dot - c7_b_k1 * (c7_Theta_wp - c7_Theta_wp_c)) -
      c7_h_y;
  } else {
    _SFD_EML_CALL(0U, chartInstance->c7_sfEvent, 18);
    c7_i_x = c7_Theta_wp;
    c7_j_x = c7_i_x;
    c7_j_x = muDoubleScalarSin(c7_j_x);
    c7_k_x = c7_Theta_wp_c;
    c7_l_x = c7_k_x;
    c7_l_x = muDoubleScalarSin(c7_l_x);
    c7_c_A = c7_b_c1 * c7_U * c7_Dis_PS_p[1] * (c7_j_x - c7_l_x);
    c7_c_B = c7_b_c2 * (c7_Theta_wp - c7_Theta_wp_c);
    c7_m_x = c7_c_A;
    c7_i_y = c7_c_B;
    c7_n_x = c7_m_x;
    c7_j_y = c7_i_y;
    c7_o_x = c7_n_x;
    c7_k_y = c7_j_y;
    c7_l_y = c7_o_x / c7_k_y;
    c7_r_des = (c7_Theta_wp_c_dot - c7_b_k1 * (c7_Theta_wp - c7_Theta_wp_c)) -
      c7_l_y;
  }

  _SFD_EML_CALL(0U, chartInstance->c7_sfEvent, 22);
  chartInstance->c7_Theta_po_last = c7_Theta_po;
  _SFD_EML_CALL(0U, chartInstance->c7_sfEvent, 23);
  chartInstance->c7_Theta_wp_c_last = c7_Theta_wp_c;
  _SFD_EML_CALL(0U, chartInstance->c7_sfEvent, -23);
  _SFD_SYMBOL_SCOPE_POP();
  *c7_b_r_des = c7_r_des;
  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 6U, chartInstance->c7_sfEvent);
  _SFD_SYMBOL_SCOPE_POP();
  _SFD_CHECK_FOR_STATE_INCONSISTENCY(_untitled2MachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
  _SFD_DATA_RANGE_CHECK(*c7_b_r_des, 1U);
  _SFD_DATA_RANGE_CHECK(*c7_b_Theta_wp_c, 2U);
  _SFD_DATA_RANGE_CHECK(*c7_b_Theta_po, 3U);
  _SFD_DATA_RANGE_CHECK(*c7_b_U, 4U);
  for (c7_i1 = 0; c7_i1 < 2; c7_i1++) {
    _SFD_DATA_RANGE_CHECK((*c7_b_Dis_PS_p)[c7_i1], 5U);
  }

  _SFD_DATA_RANGE_CHECK(chartInstance->c7_c1, 6U);
  _SFD_DATA_RANGE_CHECK(chartInstance->c7_c2, 7U);
  _SFD_DATA_RANGE_CHECK(chartInstance->c7_k1, 8U);
  _SFD_DATA_RANGE_CHECK(chartInstance->c7_h, 9U);
}

static void initSimStructsc7_untitled2(SFc7_untitled2InstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void init_script_number_translation(uint32_T c7_machineNumber, uint32_T
  c7_chartNumber, uint32_T c7_instanceNumber)
{
  (void)c7_machineNumber;
  (void)c7_chartNumber;
  (void)c7_instanceNumber;
}

static const mxArray *c7_sf_marshallOut(void *chartInstanceVoid, void *c7_inData)
{
  const mxArray *c7_mxArrayOutData = NULL;
  real_T c7_u;
  const mxArray *c7_y = NULL;
  SFc7_untitled2InstanceStruct *chartInstance;
  chartInstance = (SFc7_untitled2InstanceStruct *)chartInstanceVoid;
  c7_mxArrayOutData = NULL;
  c7_u = *(real_T *)c7_inData;
  c7_y = NULL;
  if (!chartInstance->c7_Theta_po_last_not_empty) {
    sf_mex_assign(&c7_y, sf_mex_create("y", NULL, 0, 0U, 1U, 0U, 2, 0, 0), false);
  } else {
    sf_mex_assign(&c7_y, sf_mex_create("y", &c7_u, 0, 0U, 0U, 0U, 0), false);
  }

  sf_mex_assign(&c7_mxArrayOutData, c7_y, false);
  return c7_mxArrayOutData;
}

static real_T c7_emlrt_marshallIn(SFc7_untitled2InstanceStruct *chartInstance,
  const mxArray *c7_b_Theta_po_last, const char_T *c7_identifier)
{
  real_T c7_y;
  emlrtMsgIdentifier c7_thisId;
  c7_thisId.fIdentifier = c7_identifier;
  c7_thisId.fParent = NULL;
  c7_y = c7_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c7_b_Theta_po_last),
    &c7_thisId);
  sf_mex_destroy(&c7_b_Theta_po_last);
  return c7_y;
}

static real_T c7_b_emlrt_marshallIn(SFc7_untitled2InstanceStruct *chartInstance,
  const mxArray *c7_u, const emlrtMsgIdentifier *c7_parentId)
{
  real_T c7_y;
  real_T c7_d4;
  if (mxIsEmpty(c7_u)) {
    chartInstance->c7_Theta_po_last_not_empty = false;
  } else {
    chartInstance->c7_Theta_po_last_not_empty = true;
    sf_mex_import(c7_parentId, sf_mex_dup(c7_u), &c7_d4, 1, 0, 0U, 0, 0U, 0);
    c7_y = c7_d4;
  }

  sf_mex_destroy(&c7_u);
  return c7_y;
}

static void c7_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c7_mxArrayInData, const char_T *c7_varName, void *c7_outData)
{
  const mxArray *c7_b_Theta_po_last;
  const char_T *c7_identifier;
  emlrtMsgIdentifier c7_thisId;
  real_T c7_y;
  SFc7_untitled2InstanceStruct *chartInstance;
  chartInstance = (SFc7_untitled2InstanceStruct *)chartInstanceVoid;
  c7_b_Theta_po_last = sf_mex_dup(c7_mxArrayInData);
  c7_identifier = c7_varName;
  c7_thisId.fIdentifier = c7_identifier;
  c7_thisId.fParent = NULL;
  c7_y = c7_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c7_b_Theta_po_last),
    &c7_thisId);
  sf_mex_destroy(&c7_b_Theta_po_last);
  *(real_T *)c7_outData = c7_y;
  sf_mex_destroy(&c7_mxArrayInData);
}

static const mxArray *c7_b_sf_marshallOut(void *chartInstanceVoid, void
  *c7_inData)
{
  const mxArray *c7_mxArrayOutData = NULL;
  real_T c7_u;
  const mxArray *c7_y = NULL;
  SFc7_untitled2InstanceStruct *chartInstance;
  chartInstance = (SFc7_untitled2InstanceStruct *)chartInstanceVoid;
  c7_mxArrayOutData = NULL;
  c7_u = *(real_T *)c7_inData;
  c7_y = NULL;
  if (!chartInstance->c7_Theta_wp_c_last_not_empty) {
    sf_mex_assign(&c7_y, sf_mex_create("y", NULL, 0, 0U, 1U, 0U, 2, 0, 0), false);
  } else {
    sf_mex_assign(&c7_y, sf_mex_create("y", &c7_u, 0, 0U, 0U, 0U, 0), false);
  }

  sf_mex_assign(&c7_mxArrayOutData, c7_y, false);
  return c7_mxArrayOutData;
}

static real_T c7_c_emlrt_marshallIn(SFc7_untitled2InstanceStruct *chartInstance,
  const mxArray *c7_b_Theta_wp_c_last, const char_T *c7_identifier)
{
  real_T c7_y;
  emlrtMsgIdentifier c7_thisId;
  c7_thisId.fIdentifier = c7_identifier;
  c7_thisId.fParent = NULL;
  c7_y = c7_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c7_b_Theta_wp_c_last),
    &c7_thisId);
  sf_mex_destroy(&c7_b_Theta_wp_c_last);
  return c7_y;
}

static real_T c7_d_emlrt_marshallIn(SFc7_untitled2InstanceStruct *chartInstance,
  const mxArray *c7_u, const emlrtMsgIdentifier *c7_parentId)
{
  real_T c7_y;
  real_T c7_d5;
  if (mxIsEmpty(c7_u)) {
    chartInstance->c7_Theta_wp_c_last_not_empty = false;
  } else {
    chartInstance->c7_Theta_wp_c_last_not_empty = true;
    sf_mex_import(c7_parentId, sf_mex_dup(c7_u), &c7_d5, 1, 0, 0U, 0, 0U, 0);
    c7_y = c7_d5;
  }

  sf_mex_destroy(&c7_u);
  return c7_y;
}

static void c7_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c7_mxArrayInData, const char_T *c7_varName, void *c7_outData)
{
  const mxArray *c7_b_Theta_wp_c_last;
  const char_T *c7_identifier;
  emlrtMsgIdentifier c7_thisId;
  real_T c7_y;
  SFc7_untitled2InstanceStruct *chartInstance;
  chartInstance = (SFc7_untitled2InstanceStruct *)chartInstanceVoid;
  c7_b_Theta_wp_c_last = sf_mex_dup(c7_mxArrayInData);
  c7_identifier = c7_varName;
  c7_thisId.fIdentifier = c7_identifier;
  c7_thisId.fParent = NULL;
  c7_y = c7_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c7_b_Theta_wp_c_last),
    &c7_thisId);
  sf_mex_destroy(&c7_b_Theta_wp_c_last);
  *(real_T *)c7_outData = c7_y;
  sf_mex_destroy(&c7_mxArrayInData);
}

static const mxArray *c7_c_sf_marshallOut(void *chartInstanceVoid, void
  *c7_inData)
{
  const mxArray *c7_mxArrayOutData = NULL;
  real_T c7_u;
  const mxArray *c7_y = NULL;
  SFc7_untitled2InstanceStruct *chartInstance;
  chartInstance = (SFc7_untitled2InstanceStruct *)chartInstanceVoid;
  c7_mxArrayOutData = NULL;
  c7_u = *(real_T *)c7_inData;
  c7_y = NULL;
  sf_mex_assign(&c7_y, sf_mex_create("y", &c7_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c7_mxArrayOutData, c7_y, false);
  return c7_mxArrayOutData;
}

static real_T c7_e_emlrt_marshallIn(SFc7_untitled2InstanceStruct *chartInstance,
  const mxArray *c7_r_des, const char_T *c7_identifier)
{
  real_T c7_y;
  emlrtMsgIdentifier c7_thisId;
  c7_thisId.fIdentifier = c7_identifier;
  c7_thisId.fParent = NULL;
  c7_y = c7_f_emlrt_marshallIn(chartInstance, sf_mex_dup(c7_r_des), &c7_thisId);
  sf_mex_destroy(&c7_r_des);
  return c7_y;
}

static real_T c7_f_emlrt_marshallIn(SFc7_untitled2InstanceStruct *chartInstance,
  const mxArray *c7_u, const emlrtMsgIdentifier *c7_parentId)
{
  real_T c7_y;
  real_T c7_d6;
  (void)chartInstance;
  sf_mex_import(c7_parentId, sf_mex_dup(c7_u), &c7_d6, 1, 0, 0U, 0, 0U, 0);
  c7_y = c7_d6;
  sf_mex_destroy(&c7_u);
  return c7_y;
}

static void c7_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c7_mxArrayInData, const char_T *c7_varName, void *c7_outData)
{
  const mxArray *c7_r_des;
  const char_T *c7_identifier;
  emlrtMsgIdentifier c7_thisId;
  real_T c7_y;
  SFc7_untitled2InstanceStruct *chartInstance;
  chartInstance = (SFc7_untitled2InstanceStruct *)chartInstanceVoid;
  c7_r_des = sf_mex_dup(c7_mxArrayInData);
  c7_identifier = c7_varName;
  c7_thisId.fIdentifier = c7_identifier;
  c7_thisId.fParent = NULL;
  c7_y = c7_f_emlrt_marshallIn(chartInstance, sf_mex_dup(c7_r_des), &c7_thisId);
  sf_mex_destroy(&c7_r_des);
  *(real_T *)c7_outData = c7_y;
  sf_mex_destroy(&c7_mxArrayInData);
}

static const mxArray *c7_d_sf_marshallOut(void *chartInstanceVoid, void
  *c7_inData)
{
  const mxArray *c7_mxArrayOutData = NULL;
  int32_T c7_i2;
  real_T c7_b_inData[2];
  int32_T c7_i3;
  real_T c7_u[2];
  const mxArray *c7_y = NULL;
  SFc7_untitled2InstanceStruct *chartInstance;
  chartInstance = (SFc7_untitled2InstanceStruct *)chartInstanceVoid;
  c7_mxArrayOutData = NULL;
  for (c7_i2 = 0; c7_i2 < 2; c7_i2++) {
    c7_b_inData[c7_i2] = (*(real_T (*)[2])c7_inData)[c7_i2];
  }

  for (c7_i3 = 0; c7_i3 < 2; c7_i3++) {
    c7_u[c7_i3] = c7_b_inData[c7_i3];
  }

  c7_y = NULL;
  sf_mex_assign(&c7_y, sf_mex_create("y", c7_u, 0, 0U, 1U, 0U, 1, 2), false);
  sf_mex_assign(&c7_mxArrayOutData, c7_y, false);
  return c7_mxArrayOutData;
}

const mxArray *sf_c7_untitled2_get_eml_resolved_functions_info(void)
{
  const mxArray *c7_nameCaptureInfo = NULL;
  c7_nameCaptureInfo = NULL;
  sf_mex_assign(&c7_nameCaptureInfo, sf_mex_createstruct("structure", 2, 12, 1),
                false);
  c7_info_helper(&c7_nameCaptureInfo);
  sf_mex_emlrtNameCapturePostProcessR2012a(&c7_nameCaptureInfo);
  return c7_nameCaptureInfo;
}

static void c7_info_helper(const mxArray **c7_info)
{
  const mxArray *c7_rhs0 = NULL;
  const mxArray *c7_lhs0 = NULL;
  const mxArray *c7_rhs1 = NULL;
  const mxArray *c7_lhs1 = NULL;
  const mxArray *c7_rhs2 = NULL;
  const mxArray *c7_lhs2 = NULL;
  const mxArray *c7_rhs3 = NULL;
  const mxArray *c7_lhs3 = NULL;
  const mxArray *c7_rhs4 = NULL;
  const mxArray *c7_lhs4 = NULL;
  const mxArray *c7_rhs5 = NULL;
  const mxArray *c7_lhs5 = NULL;
  const mxArray *c7_rhs6 = NULL;
  const mxArray *c7_lhs6 = NULL;
  const mxArray *c7_rhs7 = NULL;
  const mxArray *c7_lhs7 = NULL;
  const mxArray *c7_rhs8 = NULL;
  const mxArray *c7_lhs8 = NULL;
  const mxArray *c7_rhs9 = NULL;
  const mxArray *c7_lhs9 = NULL;
  const mxArray *c7_rhs10 = NULL;
  const mxArray *c7_lhs10 = NULL;
  const mxArray *c7_rhs11 = NULL;
  const mxArray *c7_lhs11 = NULL;
  sf_mex_addfield(*c7_info, c7_emlrt_marshallOut(""), "context", "context", 0);
  sf_mex_addfield(*c7_info, c7_emlrt_marshallOut("mrdivide"), "name", "name", 0);
  sf_mex_addfield(*c7_info, c7_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 0);
  sf_mex_addfield(*c7_info, c7_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p"), "resolved",
                  "resolved", 0);
  sf_mex_addfield(*c7_info, c7_b_emlrt_marshallOut(1388434896U), "fileTimeLo",
                  "fileTimeLo", 0);
  sf_mex_addfield(*c7_info, c7_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 0);
  sf_mex_addfield(*c7_info, c7_b_emlrt_marshallOut(1369988286U), "mFileTimeLo",
                  "mFileTimeLo", 0);
  sf_mex_addfield(*c7_info, c7_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 0);
  sf_mex_assign(&c7_rhs0, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c7_lhs0, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c7_info, sf_mex_duplicatearraysafe(&c7_rhs0), "rhs", "rhs", 0);
  sf_mex_addfield(*c7_info, sf_mex_duplicatearraysafe(&c7_lhs0), "lhs", "lhs", 0);
  sf_mex_addfield(*c7_info, c7_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p"), "context",
                  "context", 1);
  sf_mex_addfield(*c7_info, c7_emlrt_marshallOut("coder.internal.assert"),
                  "name", "name", 1);
  sf_mex_addfield(*c7_info, c7_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 1);
  sf_mex_addfield(*c7_info, c7_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/assert.m"),
                  "resolved", "resolved", 1);
  sf_mex_addfield(*c7_info, c7_b_emlrt_marshallOut(1363689356U), "fileTimeLo",
                  "fileTimeLo", 1);
  sf_mex_addfield(*c7_info, c7_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 1);
  sf_mex_addfield(*c7_info, c7_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 1);
  sf_mex_addfield(*c7_info, c7_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 1);
  sf_mex_assign(&c7_rhs1, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c7_lhs1, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c7_info, sf_mex_duplicatearraysafe(&c7_rhs1), "rhs", "rhs", 1);
  sf_mex_addfield(*c7_info, sf_mex_duplicatearraysafe(&c7_lhs1), "lhs", "lhs", 1);
  sf_mex_addfield(*c7_info, c7_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p"), "context",
                  "context", 2);
  sf_mex_addfield(*c7_info, c7_emlrt_marshallOut("rdivide"), "name", "name", 2);
  sf_mex_addfield(*c7_info, c7_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 2);
  sf_mex_addfield(*c7_info, c7_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m"), "resolved",
                  "resolved", 2);
  sf_mex_addfield(*c7_info, c7_b_emlrt_marshallOut(1363688680U), "fileTimeLo",
                  "fileTimeLo", 2);
  sf_mex_addfield(*c7_info, c7_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 2);
  sf_mex_addfield(*c7_info, c7_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 2);
  sf_mex_addfield(*c7_info, c7_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 2);
  sf_mex_assign(&c7_rhs2, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c7_lhs2, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c7_info, sf_mex_duplicatearraysafe(&c7_rhs2), "rhs", "rhs", 2);
  sf_mex_addfield(*c7_info, sf_mex_duplicatearraysafe(&c7_lhs2), "lhs", "lhs", 2);
  sf_mex_addfield(*c7_info, c7_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m"), "context",
                  "context", 3);
  sf_mex_addfield(*c7_info, c7_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 3);
  sf_mex_addfield(*c7_info, c7_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 3);
  sf_mex_addfield(*c7_info, c7_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 3);
  sf_mex_addfield(*c7_info, c7_b_emlrt_marshallOut(1363689356U), "fileTimeLo",
                  "fileTimeLo", 3);
  sf_mex_addfield(*c7_info, c7_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 3);
  sf_mex_addfield(*c7_info, c7_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 3);
  sf_mex_addfield(*c7_info, c7_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 3);
  sf_mex_assign(&c7_rhs3, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c7_lhs3, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c7_info, sf_mex_duplicatearraysafe(&c7_rhs3), "rhs", "rhs", 3);
  sf_mex_addfield(*c7_info, sf_mex_duplicatearraysafe(&c7_lhs3), "lhs", "lhs", 3);
  sf_mex_addfield(*c7_info, c7_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m"), "context",
                  "context", 4);
  sf_mex_addfield(*c7_info, c7_emlrt_marshallOut("eml_scalexp_compatible"),
                  "name", "name", 4);
  sf_mex_addfield(*c7_info, c7_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 4);
  sf_mex_addfield(*c7_info, c7_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalexp_compatible.m"),
                  "resolved", "resolved", 4);
  sf_mex_addfield(*c7_info, c7_b_emlrt_marshallOut(1286797196U), "fileTimeLo",
                  "fileTimeLo", 4);
  sf_mex_addfield(*c7_info, c7_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 4);
  sf_mex_addfield(*c7_info, c7_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 4);
  sf_mex_addfield(*c7_info, c7_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 4);
  sf_mex_assign(&c7_rhs4, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c7_lhs4, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c7_info, sf_mex_duplicatearraysafe(&c7_rhs4), "rhs", "rhs", 4);
  sf_mex_addfield(*c7_info, sf_mex_duplicatearraysafe(&c7_lhs4), "lhs", "lhs", 4);
  sf_mex_addfield(*c7_info, c7_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m"), "context",
                  "context", 5);
  sf_mex_addfield(*c7_info, c7_emlrt_marshallOut("eml_div"), "name", "name", 5);
  sf_mex_addfield(*c7_info, c7_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 5);
  sf_mex_addfield(*c7_info, c7_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_div.m"), "resolved",
                  "resolved", 5);
  sf_mex_addfield(*c7_info, c7_b_emlrt_marshallOut(1375959088U), "fileTimeLo",
                  "fileTimeLo", 5);
  sf_mex_addfield(*c7_info, c7_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 5);
  sf_mex_addfield(*c7_info, c7_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 5);
  sf_mex_addfield(*c7_info, c7_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 5);
  sf_mex_assign(&c7_rhs5, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c7_lhs5, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c7_info, sf_mex_duplicatearraysafe(&c7_rhs5), "rhs", "rhs", 5);
  sf_mex_addfield(*c7_info, sf_mex_duplicatearraysafe(&c7_lhs5), "lhs", "lhs", 5);
  sf_mex_addfield(*c7_info, c7_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_div.m"), "context",
                  "context", 6);
  sf_mex_addfield(*c7_info, c7_emlrt_marshallOut("coder.internal.div"), "name",
                  "name", 6);
  sf_mex_addfield(*c7_info, c7_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 6);
  sf_mex_addfield(*c7_info, c7_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/div.p"), "resolved",
                  "resolved", 6);
  sf_mex_addfield(*c7_info, c7_b_emlrt_marshallOut(1389282720U), "fileTimeLo",
                  "fileTimeLo", 6);
  sf_mex_addfield(*c7_info, c7_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 6);
  sf_mex_addfield(*c7_info, c7_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 6);
  sf_mex_addfield(*c7_info, c7_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 6);
  sf_mex_assign(&c7_rhs6, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c7_lhs6, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c7_info, sf_mex_duplicatearraysafe(&c7_rhs6), "rhs", "rhs", 6);
  sf_mex_addfield(*c7_info, sf_mex_duplicatearraysafe(&c7_lhs6), "lhs", "lhs", 6);
  sf_mex_addfield(*c7_info, c7_emlrt_marshallOut(""), "context", "context", 7);
  sf_mex_addfield(*c7_info, c7_emlrt_marshallOut("abs"), "name", "name", 7);
  sf_mex_addfield(*c7_info, c7_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 7);
  sf_mex_addfield(*c7_info, c7_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m"), "resolved",
                  "resolved", 7);
  sf_mex_addfield(*c7_info, c7_b_emlrt_marshallOut(1363688652U), "fileTimeLo",
                  "fileTimeLo", 7);
  sf_mex_addfield(*c7_info, c7_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 7);
  sf_mex_addfield(*c7_info, c7_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 7);
  sf_mex_addfield(*c7_info, c7_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 7);
  sf_mex_assign(&c7_rhs7, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c7_lhs7, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c7_info, sf_mex_duplicatearraysafe(&c7_rhs7), "rhs", "rhs", 7);
  sf_mex_addfield(*c7_info, sf_mex_duplicatearraysafe(&c7_lhs7), "lhs", "lhs", 7);
  sf_mex_addfield(*c7_info, c7_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m"), "context",
                  "context", 8);
  sf_mex_addfield(*c7_info, c7_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 8);
  sf_mex_addfield(*c7_info, c7_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 8);
  sf_mex_addfield(*c7_info, c7_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 8);
  sf_mex_addfield(*c7_info, c7_b_emlrt_marshallOut(1363689356U), "fileTimeLo",
                  "fileTimeLo", 8);
  sf_mex_addfield(*c7_info, c7_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 8);
  sf_mex_addfield(*c7_info, c7_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 8);
  sf_mex_addfield(*c7_info, c7_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 8);
  sf_mex_assign(&c7_rhs8, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c7_lhs8, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c7_info, sf_mex_duplicatearraysafe(&c7_rhs8), "rhs", "rhs", 8);
  sf_mex_addfield(*c7_info, sf_mex_duplicatearraysafe(&c7_lhs8), "lhs", "lhs", 8);
  sf_mex_addfield(*c7_info, c7_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m"), "context",
                  "context", 9);
  sf_mex_addfield(*c7_info, c7_emlrt_marshallOut("eml_scalar_abs"), "name",
                  "name", 9);
  sf_mex_addfield(*c7_info, c7_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 9);
  sf_mex_addfield(*c7_info, c7_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_abs.m"),
                  "resolved", "resolved", 9);
  sf_mex_addfield(*c7_info, c7_b_emlrt_marshallOut(1286797112U), "fileTimeLo",
                  "fileTimeLo", 9);
  sf_mex_addfield(*c7_info, c7_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 9);
  sf_mex_addfield(*c7_info, c7_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 9);
  sf_mex_addfield(*c7_info, c7_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 9);
  sf_mex_assign(&c7_rhs9, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c7_lhs9, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c7_info, sf_mex_duplicatearraysafe(&c7_rhs9), "rhs", "rhs", 9);
  sf_mex_addfield(*c7_info, sf_mex_duplicatearraysafe(&c7_lhs9), "lhs", "lhs", 9);
  sf_mex_addfield(*c7_info, c7_emlrt_marshallOut(""), "context", "context", 10);
  sf_mex_addfield(*c7_info, c7_emlrt_marshallOut("sin"), "name", "name", 10);
  sf_mex_addfield(*c7_info, c7_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 10);
  sf_mex_addfield(*c7_info, c7_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/sin.m"), "resolved",
                  "resolved", 10);
  sf_mex_addfield(*c7_info, c7_b_emlrt_marshallOut(1343808786U), "fileTimeLo",
                  "fileTimeLo", 10);
  sf_mex_addfield(*c7_info, c7_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 10);
  sf_mex_addfield(*c7_info, c7_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 10);
  sf_mex_addfield(*c7_info, c7_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 10);
  sf_mex_assign(&c7_rhs10, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c7_lhs10, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c7_info, sf_mex_duplicatearraysafe(&c7_rhs10), "rhs", "rhs",
                  10);
  sf_mex_addfield(*c7_info, sf_mex_duplicatearraysafe(&c7_lhs10), "lhs", "lhs",
                  10);
  sf_mex_addfield(*c7_info, c7_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/sin.m"), "context",
                  "context", 11);
  sf_mex_addfield(*c7_info, c7_emlrt_marshallOut("eml_scalar_sin"), "name",
                  "name", 11);
  sf_mex_addfield(*c7_info, c7_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 11);
  sf_mex_addfield(*c7_info, c7_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_sin.m"),
                  "resolved", "resolved", 11);
  sf_mex_addfield(*c7_info, c7_b_emlrt_marshallOut(1286797136U), "fileTimeLo",
                  "fileTimeLo", 11);
  sf_mex_addfield(*c7_info, c7_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 11);
  sf_mex_addfield(*c7_info, c7_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 11);
  sf_mex_addfield(*c7_info, c7_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 11);
  sf_mex_assign(&c7_rhs11, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c7_lhs11, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c7_info, sf_mex_duplicatearraysafe(&c7_rhs11), "rhs", "rhs",
                  11);
  sf_mex_addfield(*c7_info, sf_mex_duplicatearraysafe(&c7_lhs11), "lhs", "lhs",
                  11);
  sf_mex_destroy(&c7_rhs0);
  sf_mex_destroy(&c7_lhs0);
  sf_mex_destroy(&c7_rhs1);
  sf_mex_destroy(&c7_lhs1);
  sf_mex_destroy(&c7_rhs2);
  sf_mex_destroy(&c7_lhs2);
  sf_mex_destroy(&c7_rhs3);
  sf_mex_destroy(&c7_lhs3);
  sf_mex_destroy(&c7_rhs4);
  sf_mex_destroy(&c7_lhs4);
  sf_mex_destroy(&c7_rhs5);
  sf_mex_destroy(&c7_lhs5);
  sf_mex_destroy(&c7_rhs6);
  sf_mex_destroy(&c7_lhs6);
  sf_mex_destroy(&c7_rhs7);
  sf_mex_destroy(&c7_lhs7);
  sf_mex_destroy(&c7_rhs8);
  sf_mex_destroy(&c7_lhs8);
  sf_mex_destroy(&c7_rhs9);
  sf_mex_destroy(&c7_lhs9);
  sf_mex_destroy(&c7_rhs10);
  sf_mex_destroy(&c7_lhs10);
  sf_mex_destroy(&c7_rhs11);
  sf_mex_destroy(&c7_lhs11);
}

static const mxArray *c7_emlrt_marshallOut(const char * c7_u)
{
  const mxArray *c7_y = NULL;
  c7_y = NULL;
  sf_mex_assign(&c7_y, sf_mex_create("y", c7_u, 15, 0U, 0U, 0U, 2, 1, strlen
    (c7_u)), false);
  return c7_y;
}

static const mxArray *c7_b_emlrt_marshallOut(const uint32_T c7_u)
{
  const mxArray *c7_y = NULL;
  c7_y = NULL;
  sf_mex_assign(&c7_y, sf_mex_create("y", &c7_u, 7, 0U, 0U, 0U, 0), false);
  return c7_y;
}

static const mxArray *c7_e_sf_marshallOut(void *chartInstanceVoid, void
  *c7_inData)
{
  const mxArray *c7_mxArrayOutData = NULL;
  int32_T c7_u;
  const mxArray *c7_y = NULL;
  SFc7_untitled2InstanceStruct *chartInstance;
  chartInstance = (SFc7_untitled2InstanceStruct *)chartInstanceVoid;
  c7_mxArrayOutData = NULL;
  c7_u = *(int32_T *)c7_inData;
  c7_y = NULL;
  sf_mex_assign(&c7_y, sf_mex_create("y", &c7_u, 6, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c7_mxArrayOutData, c7_y, false);
  return c7_mxArrayOutData;
}

static int32_T c7_g_emlrt_marshallIn(SFc7_untitled2InstanceStruct *chartInstance,
  const mxArray *c7_u, const emlrtMsgIdentifier *c7_parentId)
{
  int32_T c7_y;
  int32_T c7_i4;
  (void)chartInstance;
  sf_mex_import(c7_parentId, sf_mex_dup(c7_u), &c7_i4, 1, 6, 0U, 0, 0U, 0);
  c7_y = c7_i4;
  sf_mex_destroy(&c7_u);
  return c7_y;
}

static void c7_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c7_mxArrayInData, const char_T *c7_varName, void *c7_outData)
{
  const mxArray *c7_b_sfEvent;
  const char_T *c7_identifier;
  emlrtMsgIdentifier c7_thisId;
  int32_T c7_y;
  SFc7_untitled2InstanceStruct *chartInstance;
  chartInstance = (SFc7_untitled2InstanceStruct *)chartInstanceVoid;
  c7_b_sfEvent = sf_mex_dup(c7_mxArrayInData);
  c7_identifier = c7_varName;
  c7_thisId.fIdentifier = c7_identifier;
  c7_thisId.fParent = NULL;
  c7_y = c7_g_emlrt_marshallIn(chartInstance, sf_mex_dup(c7_b_sfEvent),
    &c7_thisId);
  sf_mex_destroy(&c7_b_sfEvent);
  *(int32_T *)c7_outData = c7_y;
  sf_mex_destroy(&c7_mxArrayInData);
}

static uint8_T c7_h_emlrt_marshallIn(SFc7_untitled2InstanceStruct *chartInstance,
  const mxArray *c7_b_is_active_c7_untitled2, const char_T *c7_identifier)
{
  uint8_T c7_y;
  emlrtMsgIdentifier c7_thisId;
  c7_thisId.fIdentifier = c7_identifier;
  c7_thisId.fParent = NULL;
  c7_y = c7_i_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c7_b_is_active_c7_untitled2), &c7_thisId);
  sf_mex_destroy(&c7_b_is_active_c7_untitled2);
  return c7_y;
}

static uint8_T c7_i_emlrt_marshallIn(SFc7_untitled2InstanceStruct *chartInstance,
  const mxArray *c7_u, const emlrtMsgIdentifier *c7_parentId)
{
  uint8_T c7_y;
  uint8_T c7_u0;
  (void)chartInstance;
  sf_mex_import(c7_parentId, sf_mex_dup(c7_u), &c7_u0, 1, 3, 0U, 0, 0U, 0);
  c7_y = c7_u0;
  sf_mex_destroy(&c7_u);
  return c7_y;
}

static void init_dsm_address_info(SFc7_untitled2InstanceStruct *chartInstance)
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

void sf_c7_untitled2_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(679185418U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(232419201U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(431381456U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(4076590365U);
}

mxArray *sf_c7_untitled2_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1,1,5,
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateString("ENnVICnyYd57Hgz82cAAt");
    mxSetField(mxAutoinheritanceInfo,0,"checksum",mxChecksum);
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,5,3,dataFields);

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

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,3,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,3,"type",mxType);
    }

    mxSetField(mxData,3,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(2);
      pr[1] = (double)(1);
      mxSetField(mxData,4,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,4,"type",mxType);
    }

    mxSetField(mxData,4,"complexity",mxCreateDoubleScalar(0));
    mxSetField(mxAutoinheritanceInfo,0,"inputs",mxData);
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,4,3,dataFields);

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

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,3,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,3,"type",mxType);
    }

    mxSetField(mxData,3,"complexity",mxCreateDoubleScalar(0));
    mxSetField(mxAutoinheritanceInfo,0,"parameters",mxData);
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,1,3,dataFields);

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
    mxSetField(mxAutoinheritanceInfo,0,"outputs",mxData);
  }

  {
    mxSetField(mxAutoinheritanceInfo,0,"locals",mxCreateDoubleMatrix(0,0,mxREAL));
  }

  return(mxAutoinheritanceInfo);
}

mxArray *sf_c7_untitled2_third_party_uses_info(void)
{
  mxArray * mxcell3p = mxCreateCellMatrix(1,0);
  return(mxcell3p);
}

mxArray *sf_c7_untitled2_updateBuildInfo_args_info(void)
{
  mxArray *mxBIArgs = mxCreateCellMatrix(1,0);
  return mxBIArgs;
}

static const mxArray *sf_get_sim_state_info_c7_untitled2(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x4'type','srcId','name','auxInfo'{{M[1],M[5],T\"r_des\",},{M[4],M[0],T\"Theta_po_last\",S'l','i','p'{{M1x2[244 257],M[0],}}},{M[4],M[0],T\"Theta_wp_c_last\",S'l','i','p'{{M1x2[111 126],M[0],}}},{M[8],M[0],T\"is_active_c7_untitled2\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 4, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c7_untitled2_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc7_untitled2InstanceStruct *chartInstance;
    ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
    ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
    chartInstance = (SFc7_untitled2InstanceStruct *) chartInfo->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (sfGlobalDebugInstanceStruct,
           _untitled2MachineNumber_,
           7,
           1,
           1,
           0,
           10,
           0,
           0,
           0,
           0,
           0,
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
          _SFD_SET_DATA_PROPS(0,1,1,0,"Theta_wp");
          _SFD_SET_DATA_PROPS(1,2,0,1,"r_des");
          _SFD_SET_DATA_PROPS(2,1,1,0,"Theta_wp_c");
          _SFD_SET_DATA_PROPS(3,1,1,0,"Theta_po");
          _SFD_SET_DATA_PROPS(4,1,1,0,"U");
          _SFD_SET_DATA_PROPS(5,1,1,0,"Dis_PS_p");
          _SFD_SET_DATA_PROPS(6,10,0,0,"c1");
          _SFD_SET_DATA_PROPS(7,10,0,0,"c2");
          _SFD_SET_DATA_PROPS(8,10,0,0,"k1");
          _SFD_SET_DATA_PROPS(9,10,0,0,"h");
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
        _SFD_CV_INIT_EML(0,1,1,3,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_FCN(0,0,"eML_blk_kernel",0,-1,658);
        _SFD_CV_INIT_EML_IF(0,1,0,128,155,-1,182);
        _SFD_CV_INIT_EML_IF(0,1,1,259,284,-1,309);
        _SFD_CV_INIT_EML_IF(0,1,2,352,384,456,587);
        _SFD_SET_DATA_COMPILED_PROPS(0,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c7_c_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(1,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c7_c_sf_marshallOut,(MexInFcnForType)c7_c_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(2,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c7_c_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(3,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c7_c_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(4,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c7_c_sf_marshallOut,(MexInFcnForType)NULL);

        {
          unsigned int dimVector[1];
          dimVector[0]= 2;
          _SFD_SET_DATA_COMPILED_PROPS(5,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c7_d_sf_marshallOut,(MexInFcnForType)NULL);
        }

        _SFD_SET_DATA_COMPILED_PROPS(6,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c7_c_sf_marshallOut,(MexInFcnForType)c7_c_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(7,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c7_c_sf_marshallOut,(MexInFcnForType)c7_c_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(8,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c7_c_sf_marshallOut,(MexInFcnForType)c7_c_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(9,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c7_c_sf_marshallOut,(MexInFcnForType)c7_c_sf_marshallIn);

        {
          real_T *c7_Theta_wp;
          real_T *c7_r_des;
          real_T *c7_Theta_wp_c;
          real_T *c7_Theta_po;
          real_T *c7_U;
          real_T (*c7_Dis_PS_p)[2];
          c7_Dis_PS_p = (real_T (*)[2])ssGetInputPortSignal(chartInstance->S, 4);
          c7_U = (real_T *)ssGetInputPortSignal(chartInstance->S, 3);
          c7_Theta_po = (real_T *)ssGetInputPortSignal(chartInstance->S, 2);
          c7_Theta_wp_c = (real_T *)ssGetInputPortSignal(chartInstance->S, 1);
          c7_r_des = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
          c7_Theta_wp = (real_T *)ssGetInputPortSignal(chartInstance->S, 0);
          _SFD_SET_DATA_VALUE_PTR(0U, c7_Theta_wp);
          _SFD_SET_DATA_VALUE_PTR(1U, c7_r_des);
          _SFD_SET_DATA_VALUE_PTR(2U, c7_Theta_wp_c);
          _SFD_SET_DATA_VALUE_PTR(3U, c7_Theta_po);
          _SFD_SET_DATA_VALUE_PTR(4U, c7_U);
          _SFD_SET_DATA_VALUE_PTR(5U, *c7_Dis_PS_p);
          _SFD_SET_DATA_VALUE_PTR(6U, &chartInstance->c7_c1);
          _SFD_SET_DATA_VALUE_PTR(7U, &chartInstance->c7_c2);
          _SFD_SET_DATA_VALUE_PTR(8U, &chartInstance->c7_k1);
          _SFD_SET_DATA_VALUE_PTR(9U, &chartInstance->c7_h);
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
  return "RWdYnOnaRHWVoGnzVDr7e";
}

static void sf_opaque_initialize_c7_untitled2(void *chartInstanceVar)
{
  chart_debug_initialization(((SFc7_untitled2InstanceStruct*) chartInstanceVar
    )->S,0);
  initialize_params_c7_untitled2((SFc7_untitled2InstanceStruct*)
    chartInstanceVar);
  initialize_c7_untitled2((SFc7_untitled2InstanceStruct*) chartInstanceVar);
}

static void sf_opaque_enable_c7_untitled2(void *chartInstanceVar)
{
  enable_c7_untitled2((SFc7_untitled2InstanceStruct*) chartInstanceVar);
}

static void sf_opaque_disable_c7_untitled2(void *chartInstanceVar)
{
  disable_c7_untitled2((SFc7_untitled2InstanceStruct*) chartInstanceVar);
}

static void sf_opaque_gateway_c7_untitled2(void *chartInstanceVar)
{
  sf_gateway_c7_untitled2((SFc7_untitled2InstanceStruct*) chartInstanceVar);
}

extern const mxArray* sf_internal_get_sim_state_c7_untitled2(SimStruct* S)
{
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
  ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_raw2high");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = (mxArray*) get_sim_state_c7_untitled2((SFc7_untitled2InstanceStruct*)
    chartInfo->chartInstance);         /* raw sim ctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c7_untitled2();/* state var info */
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

extern void sf_internal_set_sim_state_c7_untitled2(SimStruct* S, const mxArray
  *st)
{
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
  ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[3];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_high2raw");
  prhs[1] = mxDuplicateArray(st);      /* high level simctx */
  prhs[2] = (mxArray*) sf_get_sim_state_info_c7_untitled2();/* state var info */
  mxError = sf_mex_call_matlab(1, plhs, 3, prhs, "sfprivate");
  mxDestroyArray(prhs[0]);
  mxDestroyArray(prhs[1]);
  mxDestroyArray(prhs[2]);
  if (mxError || plhs[0] == NULL) {
    sf_mex_error_message("Stateflow Internal Error: \nError calling 'chart_simctx_high2raw'.\n");
  }

  set_sim_state_c7_untitled2((SFc7_untitled2InstanceStruct*)
    chartInfo->chartInstance, mxDuplicateArray(plhs[0]));
  mxDestroyArray(plhs[0]);
}

static const mxArray* sf_opaque_get_sim_state_c7_untitled2(SimStruct* S)
{
  return sf_internal_get_sim_state_c7_untitled2(S);
}

static void sf_opaque_set_sim_state_c7_untitled2(SimStruct* S, const mxArray *st)
{
  sf_internal_set_sim_state_c7_untitled2(S, st);
}

static void sf_opaque_terminate_c7_untitled2(void *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc7_untitled2InstanceStruct*) chartInstanceVar)->S;
    ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
      unload_untitled2_optimization_info();
    }

    finalize_c7_untitled2((SFc7_untitled2InstanceStruct*) chartInstanceVar);
    utFree((void *)chartInstanceVar);
    if (crtInfo != NULL) {
      utFree((void *)crtInfo);
    }

    ssSetUserData(S,NULL);
  }
}

static void sf_opaque_init_subchart_simstructs(void *chartInstanceVar)
{
  initSimStructsc7_untitled2((SFc7_untitled2InstanceStruct*) chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c7_untitled2(SimStruct *S)
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
    initialize_params_c7_untitled2((SFc7_untitled2InstanceStruct*)
      (chartInfo->chartInstance));
  }
}

static void mdlSetWorkWidths_c7_untitled2(SimStruct *S)
{
  /* Actual parameters from chart:
     c1 c2 h k1
   */
  const char_T *rtParamNames[] = { "c1", "c2", "h", "k1" };

  ssSetNumRunTimeParams(S,ssGetSFcnParamsCount(S));

  /* registration for c1*/
  ssRegDlgParamAsRunTimeParam(S, 0, 0, rtParamNames[0], SS_DOUBLE);

  /* registration for c2*/
  ssRegDlgParamAsRunTimeParam(S, 1, 1, rtParamNames[1], SS_DOUBLE);

  /* registration for h*/
  ssRegDlgParamAsRunTimeParam(S, 2, 2, rtParamNames[2], SS_DOUBLE);

  /* registration for k1*/
  ssRegDlgParamAsRunTimeParam(S, 3, 3, rtParamNames[3], SS_DOUBLE);
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    mxArray *infoStruct = load_untitled2_optimization_info();
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable(sf_get_instance_specialization(),infoStruct,7);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop(sf_get_instance_specialization(),
                infoStruct,7,"RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop
      (sf_get_instance_specialization(),infoStruct,7,
       "gatewayCannotBeInlinedMultipleTimes"));
    sf_update_buildInfo(sf_get_instance_specialization(),infoStruct,7);
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 1, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 2, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 3, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 4, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,sf_get_instance_specialization(),
        infoStruct,7,5);
      sf_mark_chart_reusable_outputs(S,sf_get_instance_specialization(),
        infoStruct,7,1);
    }

    {
      unsigned int outPortIdx;
      for (outPortIdx=1; outPortIdx<=1; ++outPortIdx) {
        ssSetOutputPortOptimizeInIR(S, outPortIdx, 1U);
      }
    }

    {
      unsigned int inPortIdx;
      for (inPortIdx=0; inPortIdx < 5; ++inPortIdx) {
        ssSetInputPortOptimizeInIR(S, inPortIdx, 1U);
      }
    }

    sf_set_rtw_dwork_info(S,sf_get_instance_specialization(),infoStruct,7);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(328786837U));
  ssSetChecksum1(S,(191821801U));
  ssSetChecksum2(S,(3024860151U));
  ssSetChecksum3(S,(4137031521U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
  ssSupportsMultipleExecInstances(S,1);
}

static void mdlRTW_c7_untitled2(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c7_untitled2(SimStruct *S)
{
  SFc7_untitled2InstanceStruct *chartInstance;
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)utMalloc(sizeof
    (ChartRunTimeInfo));
  chartInstance = (SFc7_untitled2InstanceStruct *)utMalloc(sizeof
    (SFc7_untitled2InstanceStruct));
  memset(chartInstance, 0, sizeof(SFc7_untitled2InstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway = sf_opaque_gateway_c7_untitled2;
  chartInstance->chartInfo.initializeChart = sf_opaque_initialize_c7_untitled2;
  chartInstance->chartInfo.terminateChart = sf_opaque_terminate_c7_untitled2;
  chartInstance->chartInfo.enableChart = sf_opaque_enable_c7_untitled2;
  chartInstance->chartInfo.disableChart = sf_opaque_disable_c7_untitled2;
  chartInstance->chartInfo.getSimState = sf_opaque_get_sim_state_c7_untitled2;
  chartInstance->chartInfo.setSimState = sf_opaque_set_sim_state_c7_untitled2;
  chartInstance->chartInfo.getSimStateInfo = sf_get_sim_state_info_c7_untitled2;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c7_untitled2;
  chartInstance->chartInfo.mdlStart = mdlStart_c7_untitled2;
  chartInstance->chartInfo.mdlSetWorkWidths = mdlSetWorkWidths_c7_untitled2;
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

void c7_untitled2_method_dispatcher(SimStruct *S, int_T method, void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c7_untitled2(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c7_untitled2(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c7_untitled2(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c7_untitled2_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}

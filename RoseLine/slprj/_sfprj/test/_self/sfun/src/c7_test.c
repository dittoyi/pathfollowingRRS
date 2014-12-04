/* Include files */

#include "blascompat32.h"
#include "test_sfun.h"
#include "c7_test.h"
#include "mwmathutil.h"
#define CHARTINSTANCE_CHARTNUMBER      (chartInstance->chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER   (chartInstance->instanceNumber)
#include "test_sfun_debug_macros.h"

/* Type Definitions */

/* Named Constants */
#define CALL_EVENT                     (-1)

/* Variable Declarations */

/* Variable Definitions */
static const char * c7_debug_family_names[15] = { "Theta_wp_c_dot", "nargin",
  "nargout", "Theta_wp", "Theta_wp_c", "Theta_po", "U", "Dis_PS_p", "c1", "c2",
  "k1", "h", "r_des", "Theta_wp_c_last", "Theta_po_last" };

/* Function Declarations */
static void initialize_c7_test(SFc7_testInstanceStruct *chartInstance);
static void initialize_params_c7_test(SFc7_testInstanceStruct *chartInstance);
static void enable_c7_test(SFc7_testInstanceStruct *chartInstance);
static void disable_c7_test(SFc7_testInstanceStruct *chartInstance);
static void c7_update_debugger_state_c7_test(SFc7_testInstanceStruct
  *chartInstance);
static const mxArray *get_sim_state_c7_test(SFc7_testInstanceStruct
  *chartInstance);
static void set_sim_state_c7_test(SFc7_testInstanceStruct *chartInstance, const
  mxArray *c7_st);
static void finalize_c7_test(SFc7_testInstanceStruct *chartInstance);
static void sf_c7_test(SFc7_testInstanceStruct *chartInstance);
static void initSimStructsc7_test(SFc7_testInstanceStruct *chartInstance);
static void init_script_number_translation(uint32_T c7_machineNumber, uint32_T
  c7_chartNumber);
static const mxArray *c7_sf_marshallOut(void *chartInstanceVoid, void *c7_inData);
static real_T c7_emlrt_marshallIn(SFc7_testInstanceStruct *chartInstance, const
  mxArray *c7_b_Theta_po_last, const char_T *c7_identifier);
static real_T c7_b_emlrt_marshallIn(SFc7_testInstanceStruct *chartInstance,
  const mxArray *c7_u, const emlrtMsgIdentifier *c7_parentId);
static void c7_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c7_mxArrayInData, const char_T *c7_varName, void *c7_outData);
static const mxArray *c7_b_sf_marshallOut(void *chartInstanceVoid, void
  *c7_inData);
static real_T c7_c_emlrt_marshallIn(SFc7_testInstanceStruct *chartInstance,
  const mxArray *c7_b_Theta_wp_c_last, const char_T *c7_identifier);
static real_T c7_d_emlrt_marshallIn(SFc7_testInstanceStruct *chartInstance,
  const mxArray *c7_u, const emlrtMsgIdentifier *c7_parentId);
static void c7_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c7_mxArrayInData, const char_T *c7_varName, void *c7_outData);
static const mxArray *c7_c_sf_marshallOut(void *chartInstanceVoid, void
  *c7_inData);
static real_T c7_e_emlrt_marshallIn(SFc7_testInstanceStruct *chartInstance,
  const mxArray *c7_r_des, const char_T *c7_identifier);
static real_T c7_f_emlrt_marshallIn(SFc7_testInstanceStruct *chartInstance,
  const mxArray *c7_u, const emlrtMsgIdentifier *c7_parentId);
static void c7_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c7_mxArrayInData, const char_T *c7_varName, void *c7_outData);
static const mxArray *c7_d_sf_marshallOut(void *chartInstanceVoid, void
  *c7_inData);
static const mxArray *c7_e_sf_marshallOut(void *chartInstanceVoid, void
  *c7_inData);
static int32_T c7_g_emlrt_marshallIn(SFc7_testInstanceStruct *chartInstance,
  const mxArray *c7_u, const emlrtMsgIdentifier *c7_parentId);
static void c7_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c7_mxArrayInData, const char_T *c7_varName, void *c7_outData);
static uint8_T c7_h_emlrt_marshallIn(SFc7_testInstanceStruct *chartInstance,
  const mxArray *c7_b_is_active_c7_test, const char_T *c7_identifier);
static uint8_T c7_i_emlrt_marshallIn(SFc7_testInstanceStruct *chartInstance,
  const mxArray *c7_u, const emlrtMsgIdentifier *c7_parentId);
static void init_dsm_address_info(SFc7_testInstanceStruct *chartInstance);

/* Function Definitions */
static void initialize_c7_test(SFc7_testInstanceStruct *chartInstance)
{
  chartInstance->c7_sfEvent = CALL_EVENT;
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  chartInstance->c7_Theta_wp_c_last_not_empty = FALSE;
  chartInstance->c7_Theta_po_last_not_empty = FALSE;
  chartInstance->c7_is_active_c7_test = 0U;
}

static void initialize_params_c7_test(SFc7_testInstanceStruct *chartInstance)
{
  real_T c7_d0;
  real_T c7_d1;
  real_T c7_d2;
  real_T c7_d3;
  sf_set_error_prefix_string(
    "Error evaluating data 'c1' in the parent workspace.\n");
  sf_mex_import_named("c1", sf_mex_get_sfun_param(chartInstance->S, 0, 0),
                      &c7_d0, 0, 0, 0U, 0, 0U, 0);
  chartInstance->c7_c1 = c7_d0;
  sf_set_error_prefix_string("Stateflow Runtime Error (chart): ");
  sf_set_error_prefix_string(
    "Error evaluating data 'c2' in the parent workspace.\n");
  sf_mex_import_named("c2", sf_mex_get_sfun_param(chartInstance->S, 1, 0),
                      &c7_d1, 0, 0, 0U, 0, 0U, 0);
  chartInstance->c7_c2 = c7_d1;
  sf_set_error_prefix_string("Stateflow Runtime Error (chart): ");
  sf_set_error_prefix_string(
    "Error evaluating data 'k1' in the parent workspace.\n");
  sf_mex_import_named("k1", sf_mex_get_sfun_param(chartInstance->S, 3, 0),
                      &c7_d2, 0, 0, 0U, 0, 0U, 0);
  chartInstance->c7_k1 = c7_d2;
  sf_set_error_prefix_string("Stateflow Runtime Error (chart): ");
  sf_set_error_prefix_string(
    "Error evaluating data 'h' in the parent workspace.\n");
  sf_mex_import_named("h", sf_mex_get_sfun_param(chartInstance->S, 2, 0), &c7_d3,
                      0, 0, 0U, 0, 0U, 0);
  chartInstance->c7_h = c7_d3;
  sf_set_error_prefix_string("Stateflow Runtime Error (chart): ");
}

static void enable_c7_test(SFc7_testInstanceStruct *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void disable_c7_test(SFc7_testInstanceStruct *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void c7_update_debugger_state_c7_test(SFc7_testInstanceStruct
  *chartInstance)
{
}

static const mxArray *get_sim_state_c7_test(SFc7_testInstanceStruct
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
  sf_mex_assign(&c7_y, sf_mex_createcellarray(4), FALSE);
  c7_hoistedGlobal = *c7_r_des;
  c7_u = c7_hoistedGlobal;
  c7_b_y = NULL;
  sf_mex_assign(&c7_b_y, sf_mex_create("y", &c7_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c7_y, 0, c7_b_y);
  c7_b_hoistedGlobal = chartInstance->c7_Theta_po_last;
  c7_b_u = c7_b_hoistedGlobal;
  c7_c_y = NULL;
  if (!chartInstance->c7_Theta_po_last_not_empty) {
    sf_mex_assign(&c7_c_y, sf_mex_create("y", NULL, 0, 0U, 1U, 0U, 2, 0, 0),
                  FALSE);
  } else {
    sf_mex_assign(&c7_c_y, sf_mex_create("y", &c7_b_u, 0, 0U, 0U, 0U, 0), FALSE);
  }

  sf_mex_setcell(c7_y, 1, c7_c_y);
  c7_c_hoistedGlobal = chartInstance->c7_Theta_wp_c_last;
  c7_c_u = c7_c_hoistedGlobal;
  c7_d_y = NULL;
  if (!chartInstance->c7_Theta_wp_c_last_not_empty) {
    sf_mex_assign(&c7_d_y, sf_mex_create("y", NULL, 0, 0U, 1U, 0U, 2, 0, 0),
                  FALSE);
  } else {
    sf_mex_assign(&c7_d_y, sf_mex_create("y", &c7_c_u, 0, 0U, 0U, 0U, 0), FALSE);
  }

  sf_mex_setcell(c7_y, 2, c7_d_y);
  c7_d_hoistedGlobal = chartInstance->c7_is_active_c7_test;
  c7_d_u = c7_d_hoistedGlobal;
  c7_e_y = NULL;
  sf_mex_assign(&c7_e_y, sf_mex_create("y", &c7_d_u, 3, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c7_y, 3, c7_e_y);
  sf_mex_assign(&c7_st, c7_y, FALSE);
  return c7_st;
}

static void set_sim_state_c7_test(SFc7_testInstanceStruct *chartInstance, const
  mxArray *c7_st)
{
  const mxArray *c7_u;
  real_T *c7_r_des;
  c7_r_des = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  chartInstance->c7_doneDoubleBufferReInit = TRUE;
  c7_u = sf_mex_dup(c7_st);
  *c7_r_des = c7_e_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell
    (c7_u, 0)), "r_des");
  chartInstance->c7_Theta_po_last = c7_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c7_u, 1)), "Theta_po_last");
  chartInstance->c7_Theta_wp_c_last = c7_c_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c7_u, 2)), "Theta_wp_c_last");
  chartInstance->c7_is_active_c7_test = c7_h_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c7_u, 3)), "is_active_c7_test");
  sf_mex_destroy(&c7_u);
  c7_update_debugger_state_c7_test(chartInstance);
  sf_mex_destroy(&c7_st);
}

static void finalize_c7_test(SFc7_testInstanceStruct *chartInstance)
{
}

static void sf_c7_test(SFc7_testInstanceStruct *chartInstance)
{
  int32_T c7_i0;
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
  int32_T c7_i1;
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
  real_T c7_b;
  real_T c7_y;
  real_T c7_A;
  real_T c7_B;
  real_T c7_x;
  real_T c7_b_y;
  real_T c7_b_x;
  real_T c7_c_y;
  real_T c7_c_x;
  real_T c7_d_x;
  real_T c7_d_y;
  real_T c7_a;
  real_T c7_b_b;
  real_T c7_e_y;
  real_T c7_b_a;
  real_T c7_c_b;
  real_T c7_f_y;
  real_T c7_c_a;
  real_T c7_d_b;
  real_T c7_g_y;
  real_T c7_b_A;
  real_T c7_b_B;
  real_T c7_e_x;
  real_T c7_h_y;
  real_T c7_f_x;
  real_T c7_i_y;
  real_T c7_j_y;
  real_T c7_d_a;
  real_T c7_e_b;
  real_T c7_k_y;
  real_T c7_e_a;
  real_T c7_f_b;
  real_T c7_l_y;
  real_T c7_f_a;
  real_T c7_g_b;
  real_T c7_m_y;
  real_T c7_g_x;
  real_T c7_h_x;
  real_T c7_i_x;
  real_T c7_j_x;
  real_T c7_g_a;
  real_T c7_h_b;
  real_T c7_n_y;
  real_T c7_h_a;
  real_T c7_i_b;
  real_T c7_o_y;
  real_T c7_c_A;
  real_T c7_c_B;
  real_T c7_k_x;
  real_T c7_p_y;
  real_T c7_l_x;
  real_T c7_q_y;
  real_T c7_r_y;
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
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 6U, chartInstance->c7_sfEvent);
  _SFD_DATA_RANGE_CHECK(*c7_b_Theta_wp, 0U);
  _SFD_DATA_RANGE_CHECK(*c7_b_r_des, 1U);
  _SFD_DATA_RANGE_CHECK(*c7_b_Theta_wp_c, 2U);
  _SFD_DATA_RANGE_CHECK(*c7_b_Theta_po, 3U);
  _SFD_DATA_RANGE_CHECK(*c7_b_U, 4U);
  for (c7_i0 = 0; c7_i0 < 2; c7_i0++) {
    _SFD_DATA_RANGE_CHECK((*c7_b_Dis_PS_p)[c7_i0], 5U);
  }

  _SFD_DATA_RANGE_CHECK(chartInstance->c7_c1, 6U);
  _SFD_DATA_RANGE_CHECK(chartInstance->c7_c2, 7U);
  _SFD_DATA_RANGE_CHECK(chartInstance->c7_k1, 8U);
  _SFD_DATA_RANGE_CHECK(chartInstance->c7_h, 9U);
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
  for (c7_i1 = 0; c7_i1 < 2; c7_i1++) {
    c7_Dis_PS_p[c7_i1] = (*c7_b_Dis_PS_p)[c7_i1];
  }

  c7_b_c1 = c7_e_hoistedGlobal;
  c7_b_c2 = c7_f_hoistedGlobal;
  c7_b_k1 = c7_g_hoistedGlobal;
  c7_b_h = c7_h_hoistedGlobal;
  sf_debug_symbol_scope_push_eml(0U, 15U, 15U, c7_debug_family_names,
    c7_debug_family_var_map);
  sf_debug_symbol_scope_add_eml_importable(&c7_Theta_wp_c_dot, 0U,
    c7_c_sf_marshallOut, c7_c_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c7_nargin, 1U, c7_c_sf_marshallOut,
    c7_c_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c7_nargout, 2U, c7_c_sf_marshallOut,
    c7_c_sf_marshallIn);
  sf_debug_symbol_scope_add_eml(&c7_Theta_wp, 3U, c7_c_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c7_Theta_wp_c, 4U, c7_c_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c7_Theta_po, 5U, c7_c_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c7_U, 6U, c7_c_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(c7_Dis_PS_p, 7U, c7_d_sf_marshallOut);
  sf_debug_symbol_scope_add_eml_importable(&c7_b_c1, 8U, c7_c_sf_marshallOut,
    c7_c_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c7_b_c2, 9U, c7_c_sf_marshallOut,
    c7_c_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c7_b_k1, 10U, c7_c_sf_marshallOut,
    c7_c_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c7_b_h, 11U, c7_c_sf_marshallOut,
    c7_c_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c7_r_des, 12U, c7_c_sf_marshallOut,
    c7_c_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&chartInstance->c7_Theta_wp_c_last,
    13U, c7_b_sf_marshallOut, c7_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&chartInstance->c7_Theta_po_last, 14U,
    c7_sf_marshallOut, c7_sf_marshallIn);
  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(0U, chartInstance->c7_sfEvent, 3);
  _SFD_EML_CALL(0U, chartInstance->c7_sfEvent, 4);
  if (CV_EML_IF(0, 1, 0, !chartInstance->c7_Theta_wp_c_last_not_empty)) {
    _SFD_EML_CALL(0U, chartInstance->c7_sfEvent, 5);
    chartInstance->c7_Theta_wp_c_last = 0.0;
    chartInstance->c7_Theta_wp_c_last_not_empty = TRUE;
  }

  _SFD_EML_CALL(0U, chartInstance->c7_sfEvent, 7);
  c7_i_hoistedGlobal = chartInstance->c7_Theta_wp_c_last;
  c7_b = c7_Theta_wp_c - c7_i_hoistedGlobal;
  c7_y = 0.0 * c7_b;
  c7_A = c7_y;
  c7_B = c7_b_h;
  c7_x = c7_A;
  c7_b_y = c7_B;
  c7_b_x = c7_x;
  c7_c_y = c7_b_y;
  c7_Theta_wp_c_dot = c7_b_x / c7_c_y;
  _SFD_EML_CALL(0U, chartInstance->c7_sfEvent, 9);
  _SFD_EML_CALL(0U, chartInstance->c7_sfEvent, 10);
  if (CV_EML_IF(0, 1, 1, !chartInstance->c7_Theta_po_last_not_empty)) {
    _SFD_EML_CALL(0U, chartInstance->c7_sfEvent, 11);
    chartInstance->c7_Theta_po_last = 0.0;
    chartInstance->c7_Theta_po_last_not_empty = TRUE;
  }

  _SFD_EML_CALL(0U, chartInstance->c7_sfEvent, 15);
  c7_c_x = c7_Theta_wp - c7_Theta_wp_c;
  c7_d_x = c7_c_x;
  c7_d_y = muDoubleScalarAbs(c7_d_x);
  if (CV_EML_IF(0, 1, 2, c7_d_y < 0.01)) {
    _SFD_EML_CALL(0U, chartInstance->c7_sfEvent, 16);
    c7_a = c7_b_k1;
    c7_b_b = c7_Theta_wp - c7_Theta_wp_c;
    c7_e_y = c7_a * c7_b_b;
    c7_b_a = c7_b_c1;
    c7_c_b = c7_U;
    c7_f_y = c7_b_a * c7_c_b;
    c7_c_a = c7_f_y;
    c7_d_b = c7_Dis_PS_p[1];
    c7_g_y = c7_c_a * c7_d_b;
    c7_b_A = c7_g_y;
    c7_b_B = c7_b_c2;
    c7_e_x = c7_b_A;
    c7_h_y = c7_b_B;
    c7_f_x = c7_e_x;
    c7_i_y = c7_h_y;
    c7_j_y = c7_f_x / c7_i_y;
    c7_r_des = (c7_Theta_wp_c_dot - c7_e_y) - c7_j_y;
  } else {
    _SFD_EML_CALL(0U, chartInstance->c7_sfEvent, 18);
    c7_d_a = c7_b_k1;
    c7_e_b = c7_Theta_wp - c7_Theta_wp_c;
    c7_k_y = c7_d_a * c7_e_b;
    c7_e_a = c7_b_c1;
    c7_f_b = c7_U;
    c7_l_y = c7_e_a * c7_f_b;
    c7_f_a = c7_l_y;
    c7_g_b = c7_Dis_PS_p[1];
    c7_m_y = c7_f_a * c7_g_b;
    c7_g_x = c7_Theta_wp;
    c7_h_x = c7_g_x;
    c7_h_x = muDoubleScalarSin(c7_h_x);
    c7_i_x = c7_Theta_wp_c;
    c7_j_x = c7_i_x;
    c7_j_x = muDoubleScalarSin(c7_j_x);
    c7_g_a = c7_m_y;
    c7_h_b = c7_h_x - c7_j_x;
    c7_n_y = c7_g_a * c7_h_b;
    c7_h_a = c7_b_c2;
    c7_i_b = c7_Theta_wp - c7_Theta_wp_c;
    c7_o_y = c7_h_a * c7_i_b;
    c7_c_A = c7_n_y;
    c7_c_B = c7_o_y;
    c7_k_x = c7_c_A;
    c7_p_y = c7_c_B;
    c7_l_x = c7_k_x;
    c7_q_y = c7_p_y;
    c7_r_y = c7_l_x / c7_q_y;
    c7_r_des = (c7_Theta_wp_c_dot - c7_k_y) - c7_r_y;
  }

  _SFD_EML_CALL(0U, chartInstance->c7_sfEvent, 22);
  chartInstance->c7_Theta_po_last = c7_Theta_po;
  _SFD_EML_CALL(0U, chartInstance->c7_sfEvent, 23);
  chartInstance->c7_Theta_wp_c_last = c7_Theta_wp_c;
  _SFD_EML_CALL(0U, chartInstance->c7_sfEvent, -23);
  sf_debug_symbol_scope_pop();
  *c7_b_r_des = c7_r_des;
  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 6U, chartInstance->c7_sfEvent);
  sf_debug_check_for_state_inconsistency(_testMachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
}

static void initSimStructsc7_test(SFc7_testInstanceStruct *chartInstance)
{
}

static void init_script_number_translation(uint32_T c7_machineNumber, uint32_T
  c7_chartNumber)
{
}

static const mxArray *c7_sf_marshallOut(void *chartInstanceVoid, void *c7_inData)
{
  const mxArray *c7_mxArrayOutData = NULL;
  real_T c7_u;
  const mxArray *c7_y = NULL;
  SFc7_testInstanceStruct *chartInstance;
  chartInstance = (SFc7_testInstanceStruct *)chartInstanceVoid;
  c7_mxArrayOutData = NULL;
  c7_u = *(real_T *)c7_inData;
  c7_y = NULL;
  if (!chartInstance->c7_Theta_po_last_not_empty) {
    sf_mex_assign(&c7_y, sf_mex_create("y", NULL, 0, 0U, 1U, 0U, 2, 0, 0), FALSE);
  } else {
    sf_mex_assign(&c7_y, sf_mex_create("y", &c7_u, 0, 0U, 0U, 0U, 0), FALSE);
  }

  sf_mex_assign(&c7_mxArrayOutData, c7_y, FALSE);
  return c7_mxArrayOutData;
}

static real_T c7_emlrt_marshallIn(SFc7_testInstanceStruct *chartInstance, const
  mxArray *c7_b_Theta_po_last, const char_T *c7_identifier)
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

static real_T c7_b_emlrt_marshallIn(SFc7_testInstanceStruct *chartInstance,
  const mxArray *c7_u, const emlrtMsgIdentifier *c7_parentId)
{
  real_T c7_y;
  real_T c7_d4;
  if (mxIsEmpty(c7_u)) {
    chartInstance->c7_Theta_po_last_not_empty = FALSE;
  } else {
    chartInstance->c7_Theta_po_last_not_empty = TRUE;
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
  SFc7_testInstanceStruct *chartInstance;
  chartInstance = (SFc7_testInstanceStruct *)chartInstanceVoid;
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
  SFc7_testInstanceStruct *chartInstance;
  chartInstance = (SFc7_testInstanceStruct *)chartInstanceVoid;
  c7_mxArrayOutData = NULL;
  c7_u = *(real_T *)c7_inData;
  c7_y = NULL;
  if (!chartInstance->c7_Theta_wp_c_last_not_empty) {
    sf_mex_assign(&c7_y, sf_mex_create("y", NULL, 0, 0U, 1U, 0U, 2, 0, 0), FALSE);
  } else {
    sf_mex_assign(&c7_y, sf_mex_create("y", &c7_u, 0, 0U, 0U, 0U, 0), FALSE);
  }

  sf_mex_assign(&c7_mxArrayOutData, c7_y, FALSE);
  return c7_mxArrayOutData;
}

static real_T c7_c_emlrt_marshallIn(SFc7_testInstanceStruct *chartInstance,
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

static real_T c7_d_emlrt_marshallIn(SFc7_testInstanceStruct *chartInstance,
  const mxArray *c7_u, const emlrtMsgIdentifier *c7_parentId)
{
  real_T c7_y;
  real_T c7_d5;
  if (mxIsEmpty(c7_u)) {
    chartInstance->c7_Theta_wp_c_last_not_empty = FALSE;
  } else {
    chartInstance->c7_Theta_wp_c_last_not_empty = TRUE;
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
  SFc7_testInstanceStruct *chartInstance;
  chartInstance = (SFc7_testInstanceStruct *)chartInstanceVoid;
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
  SFc7_testInstanceStruct *chartInstance;
  chartInstance = (SFc7_testInstanceStruct *)chartInstanceVoid;
  c7_mxArrayOutData = NULL;
  c7_u = *(real_T *)c7_inData;
  c7_y = NULL;
  sf_mex_assign(&c7_y, sf_mex_create("y", &c7_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c7_mxArrayOutData, c7_y, FALSE);
  return c7_mxArrayOutData;
}

static real_T c7_e_emlrt_marshallIn(SFc7_testInstanceStruct *chartInstance,
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

static real_T c7_f_emlrt_marshallIn(SFc7_testInstanceStruct *chartInstance,
  const mxArray *c7_u, const emlrtMsgIdentifier *c7_parentId)
{
  real_T c7_y;
  real_T c7_d6;
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
  SFc7_testInstanceStruct *chartInstance;
  chartInstance = (SFc7_testInstanceStruct *)chartInstanceVoid;
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
  SFc7_testInstanceStruct *chartInstance;
  chartInstance = (SFc7_testInstanceStruct *)chartInstanceVoid;
  c7_mxArrayOutData = NULL;
  for (c7_i2 = 0; c7_i2 < 2; c7_i2++) {
    c7_b_inData[c7_i2] = (*(real_T (*)[2])c7_inData)[c7_i2];
  }

  for (c7_i3 = 0; c7_i3 < 2; c7_i3++) {
    c7_u[c7_i3] = c7_b_inData[c7_i3];
  }

  c7_y = NULL;
  sf_mex_assign(&c7_y, sf_mex_create("y", c7_u, 0, 0U, 1U, 0U, 1, 2), FALSE);
  sf_mex_assign(&c7_mxArrayOutData, c7_y, FALSE);
  return c7_mxArrayOutData;
}

const mxArray *sf_c7_test_get_eml_resolved_functions_info(void)
{
  const mxArray *c7_nameCaptureInfo;
  c7_ResolvedFunctionInfo c7_info[8];
  c7_ResolvedFunctionInfo (*c7_b_info)[8];
  const mxArray *c7_m0 = NULL;
  int32_T c7_i4;
  c7_ResolvedFunctionInfo *c7_r0;
  c7_nameCaptureInfo = NULL;
  c7_nameCaptureInfo = NULL;
  c7_b_info = (c7_ResolvedFunctionInfo (*)[8])c7_info;
  (*c7_b_info)[0].context = "";
  (*c7_b_info)[0].name = "mtimes";
  (*c7_b_info)[0].dominantType = "double";
  (*c7_b_info)[0].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  (*c7_b_info)[0].fileTimeLo = 1289494492U;
  (*c7_b_info)[0].fileTimeHi = 0U;
  (*c7_b_info)[0].mFileTimeLo = 0U;
  (*c7_b_info)[0].mFileTimeHi = 0U;
  (*c7_b_info)[1].context = "";
  (*c7_b_info)[1].name = "mrdivide";
  (*c7_b_info)[1].dominantType = "double";
  (*c7_b_info)[1].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p";
  (*c7_b_info)[1].fileTimeLo = 1342789344U;
  (*c7_b_info)[1].fileTimeHi = 0U;
  (*c7_b_info)[1].mFileTimeLo = 1319708366U;
  (*c7_b_info)[1].mFileTimeHi = 0U;
  (*c7_b_info)[2].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p";
  (*c7_b_info)[2].name = "rdivide";
  (*c7_b_info)[2].dominantType = "double";
  (*c7_b_info)[2].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m";
  (*c7_b_info)[2].fileTimeLo = 1286797244U;
  (*c7_b_info)[2].fileTimeHi = 0U;
  (*c7_b_info)[2].mFileTimeLo = 0U;
  (*c7_b_info)[2].mFileTimeHi = 0U;
  (*c7_b_info)[3].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m";
  (*c7_b_info)[3].name = "eml_div";
  (*c7_b_info)[3].dominantType = "double";
  (*c7_b_info)[3].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_div.m";
  (*c7_b_info)[3].fileTimeLo = 1313326210U;
  (*c7_b_info)[3].fileTimeHi = 0U;
  (*c7_b_info)[3].mFileTimeLo = 0U;
  (*c7_b_info)[3].mFileTimeHi = 0U;
  (*c7_b_info)[4].context = "";
  (*c7_b_info)[4].name = "abs";
  (*c7_b_info)[4].dominantType = "double";
  (*c7_b_info)[4].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m";
  (*c7_b_info)[4].fileTimeLo = 1286797094U;
  (*c7_b_info)[4].fileTimeHi = 0U;
  (*c7_b_info)[4].mFileTimeLo = 0U;
  (*c7_b_info)[4].mFileTimeHi = 0U;
  (*c7_b_info)[5].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m";
  (*c7_b_info)[5].name = "eml_scalar_abs";
  (*c7_b_info)[5].dominantType = "double";
  (*c7_b_info)[5].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_abs.m";
  (*c7_b_info)[5].fileTimeLo = 1286797112U;
  (*c7_b_info)[5].fileTimeHi = 0U;
  (*c7_b_info)[5].mFileTimeLo = 0U;
  (*c7_b_info)[5].mFileTimeHi = 0U;
  (*c7_b_info)[6].context = "";
  (*c7_b_info)[6].name = "sin";
  (*c7_b_info)[6].dominantType = "double";
  (*c7_b_info)[6].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/sin.m";
  (*c7_b_info)[6].fileTimeLo = 1286797150U;
  (*c7_b_info)[6].fileTimeHi = 0U;
  (*c7_b_info)[6].mFileTimeLo = 0U;
  (*c7_b_info)[6].mFileTimeHi = 0U;
  (*c7_b_info)[7].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/sin.m";
  (*c7_b_info)[7].name = "eml_scalar_sin";
  (*c7_b_info)[7].dominantType = "double";
  (*c7_b_info)[7].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_sin.m";
  (*c7_b_info)[7].fileTimeLo = 1286797136U;
  (*c7_b_info)[7].fileTimeHi = 0U;
  (*c7_b_info)[7].mFileTimeLo = 0U;
  (*c7_b_info)[7].mFileTimeHi = 0U;
  sf_mex_assign(&c7_m0, sf_mex_createstruct("nameCaptureInfo", 1, 8), FALSE);
  for (c7_i4 = 0; c7_i4 < 8; c7_i4++) {
    c7_r0 = &c7_info[c7_i4];
    sf_mex_addfield(c7_m0, sf_mex_create("nameCaptureInfo", c7_r0->context, 15,
      0U, 0U, 0U, 2, 1, strlen(c7_r0->context)), "context", "nameCaptureInfo",
                    c7_i4);
    sf_mex_addfield(c7_m0, sf_mex_create("nameCaptureInfo", c7_r0->name, 15, 0U,
      0U, 0U, 2, 1, strlen(c7_r0->name)), "name", "nameCaptureInfo", c7_i4);
    sf_mex_addfield(c7_m0, sf_mex_create("nameCaptureInfo", c7_r0->dominantType,
      15, 0U, 0U, 0U, 2, 1, strlen(c7_r0->dominantType)), "dominantType",
                    "nameCaptureInfo", c7_i4);
    sf_mex_addfield(c7_m0, sf_mex_create("nameCaptureInfo", c7_r0->resolved, 15,
      0U, 0U, 0U, 2, 1, strlen(c7_r0->resolved)), "resolved", "nameCaptureInfo",
                    c7_i4);
    sf_mex_addfield(c7_m0, sf_mex_create("nameCaptureInfo", &c7_r0->fileTimeLo,
      7, 0U, 0U, 0U, 0), "fileTimeLo", "nameCaptureInfo", c7_i4);
    sf_mex_addfield(c7_m0, sf_mex_create("nameCaptureInfo", &c7_r0->fileTimeHi,
      7, 0U, 0U, 0U, 0), "fileTimeHi", "nameCaptureInfo", c7_i4);
    sf_mex_addfield(c7_m0, sf_mex_create("nameCaptureInfo", &c7_r0->mFileTimeLo,
      7, 0U, 0U, 0U, 0), "mFileTimeLo", "nameCaptureInfo", c7_i4);
    sf_mex_addfield(c7_m0, sf_mex_create("nameCaptureInfo", &c7_r0->mFileTimeHi,
      7, 0U, 0U, 0U, 0), "mFileTimeHi", "nameCaptureInfo", c7_i4);
  }

  sf_mex_assign(&c7_nameCaptureInfo, c7_m0, FALSE);
  sf_mex_emlrtNameCapturePostProcessR2012a(&c7_nameCaptureInfo);
  return c7_nameCaptureInfo;
}

static const mxArray *c7_e_sf_marshallOut(void *chartInstanceVoid, void
  *c7_inData)
{
  const mxArray *c7_mxArrayOutData = NULL;
  int32_T c7_u;
  const mxArray *c7_y = NULL;
  SFc7_testInstanceStruct *chartInstance;
  chartInstance = (SFc7_testInstanceStruct *)chartInstanceVoid;
  c7_mxArrayOutData = NULL;
  c7_u = *(int32_T *)c7_inData;
  c7_y = NULL;
  sf_mex_assign(&c7_y, sf_mex_create("y", &c7_u, 6, 0U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c7_mxArrayOutData, c7_y, FALSE);
  return c7_mxArrayOutData;
}

static int32_T c7_g_emlrt_marshallIn(SFc7_testInstanceStruct *chartInstance,
  const mxArray *c7_u, const emlrtMsgIdentifier *c7_parentId)
{
  int32_T c7_y;
  int32_T c7_i5;
  sf_mex_import(c7_parentId, sf_mex_dup(c7_u), &c7_i5, 1, 6, 0U, 0, 0U, 0);
  c7_y = c7_i5;
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
  SFc7_testInstanceStruct *chartInstance;
  chartInstance = (SFc7_testInstanceStruct *)chartInstanceVoid;
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

static uint8_T c7_h_emlrt_marshallIn(SFc7_testInstanceStruct *chartInstance,
  const mxArray *c7_b_is_active_c7_test, const char_T *c7_identifier)
{
  uint8_T c7_y;
  emlrtMsgIdentifier c7_thisId;
  c7_thisId.fIdentifier = c7_identifier;
  c7_thisId.fParent = NULL;
  c7_y = c7_i_emlrt_marshallIn(chartInstance, sf_mex_dup(c7_b_is_active_c7_test),
    &c7_thisId);
  sf_mex_destroy(&c7_b_is_active_c7_test);
  return c7_y;
}

static uint8_T c7_i_emlrt_marshallIn(SFc7_testInstanceStruct *chartInstance,
  const mxArray *c7_u, const emlrtMsgIdentifier *c7_parentId)
{
  uint8_T c7_y;
  uint8_T c7_u0;
  sf_mex_import(c7_parentId, sf_mex_dup(c7_u), &c7_u0, 1, 3, 0U, 0, 0U, 0);
  c7_y = c7_u0;
  sf_mex_destroy(&c7_u);
  return c7_y;
}

static void init_dsm_address_info(SFc7_testInstanceStruct *chartInstance)
{
}

/* SFunction Glue Code */
void sf_c7_test_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(1148973973U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(4213366360U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(2952035625U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(562944854U);
}

mxArray *sf_c7_test_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1,1,5,
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateString("G2oombp4kVN4sXDGagYUY");
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

static const mxArray *sf_get_sim_state_info_c7_test(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x4'type','srcId','name','auxInfo'{{M[1],M[5],T\"r_des\",},{M[4],M[0],T\"Theta_po_last\",S'l','i','p'{{M1x2[244 257],M[0],}}},{M[4],M[0],T\"Theta_wp_c_last\",S'l','i','p'{{M1x2[111 126],M[0],}}},{M[8],M[0],T\"is_active_c7_test\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 4, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c7_test_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc7_testInstanceStruct *chartInstance;
    chartInstance = (SFc7_testInstanceStruct *) ((ChartInfoStruct *)
      (ssGetUserData(S)))->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart(_testMachineNumber_,
          7,
          1,
          1,
          10,
          0,
          0,
          0,
          0,
          0,
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
        _SFD_TRANS_COV_WTS(0,0,0,1,0);
        if (chartAlreadyPresent==0) {
          _SFD_TRANS_COV_MAPS(0,
                              0,NULL,NULL,
                              0,NULL,NULL,
                              1,NULL,NULL,
                              0,NULL,NULL);
        }

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
      sf_debug_reset_current_state_configuration(_testMachineNumber_,
        chartInstance->chartNumber,chartInstance->instanceNumber);
    }
  }
}

static const char* sf_get_instance_specialization()
{
  return "XUNWO3ESrHGtIvms8Oul8B";
}

static void sf_opaque_initialize_c7_test(void *chartInstanceVar)
{
  chart_debug_initialization(((SFc7_testInstanceStruct*) chartInstanceVar)->S,0);
  initialize_params_c7_test((SFc7_testInstanceStruct*) chartInstanceVar);
  initialize_c7_test((SFc7_testInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_enable_c7_test(void *chartInstanceVar)
{
  enable_c7_test((SFc7_testInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_disable_c7_test(void *chartInstanceVar)
{
  disable_c7_test((SFc7_testInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_gateway_c7_test(void *chartInstanceVar)
{
  sf_c7_test((SFc7_testInstanceStruct*) chartInstanceVar);
}

extern const mxArray* sf_internal_get_sim_state_c7_test(SimStruct* S)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_raw2high");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = (mxArray*) get_sim_state_c7_test((SFc7_testInstanceStruct*)
    chartInfo->chartInstance);         /* raw sim ctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c7_test();/* state var info */
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

extern void sf_internal_set_sim_state_c7_test(SimStruct* S, const mxArray *st)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_high2raw");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = mxDuplicateArray(st);      /* high level simctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c7_test();/* state var info */
  mxError = sf_mex_call_matlab(1, plhs, 4, prhs, "sfprivate");
  mxDestroyArray(prhs[0]);
  mxDestroyArray(prhs[1]);
  mxDestroyArray(prhs[2]);
  mxDestroyArray(prhs[3]);
  if (mxError || plhs[0] == NULL) {
    sf_mex_error_message("Stateflow Internal Error: \nError calling 'chart_simctx_high2raw'.\n");
  }

  set_sim_state_c7_test((SFc7_testInstanceStruct*)chartInfo->chartInstance,
                        mxDuplicateArray(plhs[0]));
  mxDestroyArray(plhs[0]);
}

static const mxArray* sf_opaque_get_sim_state_c7_test(SimStruct* S)
{
  return sf_internal_get_sim_state_c7_test(S);
}

static void sf_opaque_set_sim_state_c7_test(SimStruct* S, const mxArray *st)
{
  sf_internal_set_sim_state_c7_test(S, st);
}

static void sf_opaque_terminate_c7_test(void *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc7_testInstanceStruct*) chartInstanceVar)->S;
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
    }

    finalize_c7_test((SFc7_testInstanceStruct*) chartInstanceVar);
    free((void *)chartInstanceVar);
    ssSetUserData(S,NULL);
  }

  unload_test_optimization_info();
}

static void sf_opaque_init_subchart_simstructs(void *chartInstanceVar)
{
  initSimStructsc7_test((SFc7_testInstanceStruct*) chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c7_test(SimStruct *S)
{
  int i;
  for (i=0;i<ssGetNumRunTimeParams(S);i++) {
    if (ssGetSFcnParamTunable(S,i)) {
      ssUpdateDlgParamAsRunTimeParam(S,i);
    }
  }

  if (sf_machine_global_initializer_called()) {
    initialize_params_c7_test((SFc7_testInstanceStruct*)(((ChartInfoStruct *)
      ssGetUserData(S))->chartInstance));
  }
}

static void mdlSetWorkWidths_c7_test(SimStruct *S)
{
  /* Actual parameters from chart:
     c1 c2 h k1
   */
  const char_T *rtParamNames[] = { "p1", "p2", "p3", "p4" };

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
    mxArray *infoStruct = load_test_optimization_info();
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable(S,sf_get_instance_specialization(),infoStruct,
      7);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop(S,sf_get_instance_specialization(),
                infoStruct,7,"RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop(S,
      sf_get_instance_specialization(),infoStruct,7,
      "gatewayCannotBeInlinedMultipleTimes"));
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

    sf_set_rtw_dwork_info(S,sf_get_instance_specialization(),infoStruct,7);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(1397171694U));
  ssSetChecksum1(S,(1522921894U));
  ssSetChecksum2(S,(1229939597U));
  ssSetChecksum3(S,(1118024257U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
  ssSupportsMultipleExecInstances(S,1);
}

static void mdlRTW_c7_test(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c7_test(SimStruct *S)
{
  SFc7_testInstanceStruct *chartInstance;
  chartInstance = (SFc7_testInstanceStruct *)malloc(sizeof
    (SFc7_testInstanceStruct));
  memset(chartInstance, 0, sizeof(SFc7_testInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway = sf_opaque_gateway_c7_test;
  chartInstance->chartInfo.initializeChart = sf_opaque_initialize_c7_test;
  chartInstance->chartInfo.terminateChart = sf_opaque_terminate_c7_test;
  chartInstance->chartInfo.enableChart = sf_opaque_enable_c7_test;
  chartInstance->chartInfo.disableChart = sf_opaque_disable_c7_test;
  chartInstance->chartInfo.getSimState = sf_opaque_get_sim_state_c7_test;
  chartInstance->chartInfo.setSimState = sf_opaque_set_sim_state_c7_test;
  chartInstance->chartInfo.getSimStateInfo = sf_get_sim_state_info_c7_test;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c7_test;
  chartInstance->chartInfo.mdlStart = mdlStart_c7_test;
  chartInstance->chartInfo.mdlSetWorkWidths = mdlSetWorkWidths_c7_test;
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

void c7_test_method_dispatcher(SimStruct *S, int_T method, void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c7_test(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c7_test(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c7_test(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c7_test_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}

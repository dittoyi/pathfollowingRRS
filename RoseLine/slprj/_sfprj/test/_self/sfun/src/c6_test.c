/* Include files */

#include "blascompat32.h"
#include "test_sfun.h"
#include "c6_test.h"
#include "mwmathutil.h"
#define CHARTINSTANCE_CHARTNUMBER      (chartInstance->chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER   (chartInstance->instanceNumber)
#include "test_sfun_debug_macros.h"

/* Type Definitions */

/* Named Constants */
#define CALL_EVENT                     (-1)

/* Variable Declarations */

/* Variable Definitions */
static const char * c6_debug_family_names[13] = { "Dis_Ship_o", "nargin",
  "nargout", "U", "x", "Dis_Path_o", "Theta_wp", "R_po", "r_c", "gama", "m_dot",
  "Dis_PS_p", "e" };

/* Function Declarations */
static void initialize_c6_test(SFc6_testInstanceStruct *chartInstance);
static void initialize_params_c6_test(SFc6_testInstanceStruct *chartInstance);
static void enable_c6_test(SFc6_testInstanceStruct *chartInstance);
static void disable_c6_test(SFc6_testInstanceStruct *chartInstance);
static void c6_update_debugger_state_c6_test(SFc6_testInstanceStruct
  *chartInstance);
static const mxArray *get_sim_state_c6_test(SFc6_testInstanceStruct
  *chartInstance);
static void set_sim_state_c6_test(SFc6_testInstanceStruct *chartInstance, const
  mxArray *c6_st);
static void finalize_c6_test(SFc6_testInstanceStruct *chartInstance);
static void sf_c6_test(SFc6_testInstanceStruct *chartInstance);
static void c6_chartstep_c6_test(SFc6_testInstanceStruct *chartInstance);
static void initSimStructsc6_test(SFc6_testInstanceStruct *chartInstance);
static void init_script_number_translation(uint32_T c6_machineNumber, uint32_T
  c6_chartNumber);
static const mxArray *c6_sf_marshallOut(void *chartInstanceVoid, void *c6_inData);
static real_T c6_emlrt_marshallIn(SFc6_testInstanceStruct *chartInstance, const
  mxArray *c6_e, const char_T *c6_identifier);
static real_T c6_b_emlrt_marshallIn(SFc6_testInstanceStruct *chartInstance,
  const mxArray *c6_u, const emlrtMsgIdentifier *c6_parentId);
static void c6_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c6_mxArrayInData, const char_T *c6_varName, void *c6_outData);
static const mxArray *c6_b_sf_marshallOut(void *chartInstanceVoid, void
  *c6_inData);
static void c6_c_emlrt_marshallIn(SFc6_testInstanceStruct *chartInstance, const
  mxArray *c6_Dis_PS_p, const char_T *c6_identifier, real_T c6_y[2]);
static void c6_d_emlrt_marshallIn(SFc6_testInstanceStruct *chartInstance, const
  mxArray *c6_u, const emlrtMsgIdentifier *c6_parentId, real_T c6_y[2]);
static void c6_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c6_mxArrayInData, const char_T *c6_varName, void *c6_outData);
static const mxArray *c6_c_sf_marshallOut(void *chartInstanceVoid, void
  *c6_inData);
static const mxArray *c6_d_sf_marshallOut(void *chartInstanceVoid, void
  *c6_inData);
static void c6_info_helper(c6_ResolvedFunctionInfo c6_info[14]);
static void c6_eml_scalar_eg(SFc6_testInstanceStruct *chartInstance);
static const mxArray *c6_e_sf_marshallOut(void *chartInstanceVoid, void
  *c6_inData);
static int32_T c6_e_emlrt_marshallIn(SFc6_testInstanceStruct *chartInstance,
  const mxArray *c6_u, const emlrtMsgIdentifier *c6_parentId);
static void c6_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c6_mxArrayInData, const char_T *c6_varName, void *c6_outData);
static uint8_T c6_f_emlrt_marshallIn(SFc6_testInstanceStruct *chartInstance,
  const mxArray *c6_b_is_active_c6_test, const char_T *c6_identifier);
static uint8_T c6_g_emlrt_marshallIn(SFc6_testInstanceStruct *chartInstance,
  const mxArray *c6_u, const emlrtMsgIdentifier *c6_parentId);
static void init_dsm_address_info(SFc6_testInstanceStruct *chartInstance);

/* Function Definitions */
static void initialize_c6_test(SFc6_testInstanceStruct *chartInstance)
{
  chartInstance->c6_sfEvent = CALL_EVENT;
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  chartInstance->c6_is_active_c6_test = 0U;
}

static void initialize_params_c6_test(SFc6_testInstanceStruct *chartInstance)
{
  real_T c6_d0;
  sf_set_error_prefix_string(
    "Error evaluating data 'gama' in the parent workspace.\n");
  sf_mex_import_named("gama", sf_mex_get_sfun_param(chartInstance->S, 0, 0),
                      &c6_d0, 0, 0, 0U, 0, 0U, 0);
  chartInstance->c6_gama = c6_d0;
  sf_set_error_prefix_string("Stateflow Runtime Error (chart): ");
}

static void enable_c6_test(SFc6_testInstanceStruct *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void disable_c6_test(SFc6_testInstanceStruct *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void c6_update_debugger_state_c6_test(SFc6_testInstanceStruct
  *chartInstance)
{
}

static const mxArray *get_sim_state_c6_test(SFc6_testInstanceStruct
  *chartInstance)
{
  const mxArray *c6_st;
  const mxArray *c6_y = NULL;
  int32_T c6_i0;
  real_T c6_u[2];
  const mxArray *c6_b_y = NULL;
  real_T c6_hoistedGlobal;
  real_T c6_b_u;
  const mxArray *c6_c_y = NULL;
  real_T c6_b_hoistedGlobal;
  real_T c6_c_u;
  const mxArray *c6_d_y = NULL;
  uint8_T c6_c_hoistedGlobal;
  uint8_T c6_d_u;
  const mxArray *c6_e_y = NULL;
  real_T *c6_e;
  real_T *c6_m_dot;
  real_T (*c6_Dis_PS_p)[2];
  c6_e = (real_T *)ssGetOutputPortSignal(chartInstance->S, 3);
  c6_Dis_PS_p = (real_T (*)[2])ssGetOutputPortSignal(chartInstance->S, 2);
  c6_m_dot = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c6_st = NULL;
  c6_st = NULL;
  c6_y = NULL;
  sf_mex_assign(&c6_y, sf_mex_createcellarray(4), FALSE);
  for (c6_i0 = 0; c6_i0 < 2; c6_i0++) {
    c6_u[c6_i0] = (*c6_Dis_PS_p)[c6_i0];
  }

  c6_b_y = NULL;
  sf_mex_assign(&c6_b_y, sf_mex_create("y", c6_u, 0, 0U, 1U, 0U, 1, 2), FALSE);
  sf_mex_setcell(c6_y, 0, c6_b_y);
  c6_hoistedGlobal = *c6_e;
  c6_b_u = c6_hoistedGlobal;
  c6_c_y = NULL;
  sf_mex_assign(&c6_c_y, sf_mex_create("y", &c6_b_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c6_y, 1, c6_c_y);
  c6_b_hoistedGlobal = *c6_m_dot;
  c6_c_u = c6_b_hoistedGlobal;
  c6_d_y = NULL;
  sf_mex_assign(&c6_d_y, sf_mex_create("y", &c6_c_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c6_y, 2, c6_d_y);
  c6_c_hoistedGlobal = chartInstance->c6_is_active_c6_test;
  c6_d_u = c6_c_hoistedGlobal;
  c6_e_y = NULL;
  sf_mex_assign(&c6_e_y, sf_mex_create("y", &c6_d_u, 3, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c6_y, 3, c6_e_y);
  sf_mex_assign(&c6_st, c6_y, FALSE);
  return c6_st;
}

static void set_sim_state_c6_test(SFc6_testInstanceStruct *chartInstance, const
  mxArray *c6_st)
{
  const mxArray *c6_u;
  real_T c6_dv0[2];
  int32_T c6_i1;
  real_T *c6_e;
  real_T *c6_m_dot;
  real_T (*c6_Dis_PS_p)[2];
  c6_e = (real_T *)ssGetOutputPortSignal(chartInstance->S, 3);
  c6_Dis_PS_p = (real_T (*)[2])ssGetOutputPortSignal(chartInstance->S, 2);
  c6_m_dot = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  chartInstance->c6_doneDoubleBufferReInit = TRUE;
  c6_u = sf_mex_dup(c6_st);
  c6_c_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c6_u, 0)),
                        "Dis_PS_p", c6_dv0);
  for (c6_i1 = 0; c6_i1 < 2; c6_i1++) {
    (*c6_Dis_PS_p)[c6_i1] = c6_dv0[c6_i1];
  }

  *c6_e = c6_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c6_u, 1)),
    "e");
  *c6_m_dot = c6_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c6_u,
    2)), "m_dot");
  chartInstance->c6_is_active_c6_test = c6_f_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c6_u, 3)), "is_active_c6_test");
  sf_mex_destroy(&c6_u);
  c6_update_debugger_state_c6_test(chartInstance);
  sf_mex_destroy(&c6_st);
}

static void finalize_c6_test(SFc6_testInstanceStruct *chartInstance)
{
}

static void sf_c6_test(SFc6_testInstanceStruct *chartInstance)
{
  int32_T c6_i2;
  int32_T c6_i3;
  int32_T c6_i4;
  int32_T c6_i5;
  real_T *c6_U;
  real_T *c6_m_dot;
  real_T *c6_Theta_wp;
  real_T *c6_r_c;
  real_T *c6_e;
  real_T (*c6_Dis_PS_p)[2];
  real_T (*c6_R_po)[4];
  real_T (*c6_Dis_Path_o)[2];
  real_T (*c6_x)[7];
  c6_e = (real_T *)ssGetOutputPortSignal(chartInstance->S, 3);
  c6_Dis_PS_p = (real_T (*)[2])ssGetOutputPortSignal(chartInstance->S, 2);
  c6_r_c = (real_T *)ssGetInputPortSignal(chartInstance->S, 5);
  c6_R_po = (real_T (*)[4])ssGetInputPortSignal(chartInstance->S, 4);
  c6_Theta_wp = (real_T *)ssGetInputPortSignal(chartInstance->S, 3);
  c6_Dis_Path_o = (real_T (*)[2])ssGetInputPortSignal(chartInstance->S, 2);
  c6_x = (real_T (*)[7])ssGetInputPortSignal(chartInstance->S, 1);
  c6_m_dot = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c6_U = (real_T *)ssGetInputPortSignal(chartInstance->S, 0);
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 5U, chartInstance->c6_sfEvent);
  _SFD_DATA_RANGE_CHECK(*c6_U, 0U);
  _SFD_DATA_RANGE_CHECK(*c6_m_dot, 1U);
  for (c6_i2 = 0; c6_i2 < 7; c6_i2++) {
    _SFD_DATA_RANGE_CHECK((*c6_x)[c6_i2], 2U);
  }

  for (c6_i3 = 0; c6_i3 < 2; c6_i3++) {
    _SFD_DATA_RANGE_CHECK((*c6_Dis_Path_o)[c6_i3], 3U);
  }

  _SFD_DATA_RANGE_CHECK(*c6_Theta_wp, 4U);
  for (c6_i4 = 0; c6_i4 < 4; c6_i4++) {
    _SFD_DATA_RANGE_CHECK((*c6_R_po)[c6_i4], 5U);
  }

  _SFD_DATA_RANGE_CHECK(*c6_r_c, 6U);
  _SFD_DATA_RANGE_CHECK(chartInstance->c6_gama, 7U);
  for (c6_i5 = 0; c6_i5 < 2; c6_i5++) {
    _SFD_DATA_RANGE_CHECK((*c6_Dis_PS_p)[c6_i5], 8U);
  }

  _SFD_DATA_RANGE_CHECK(*c6_e, 9U);
  chartInstance->c6_sfEvent = CALL_EVENT;
  c6_chartstep_c6_test(chartInstance);
  sf_debug_check_for_state_inconsistency(_testMachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
}

static void c6_chartstep_c6_test(SFc6_testInstanceStruct *chartInstance)
{
  real_T c6_hoistedGlobal;
  real_T c6_b_hoistedGlobal;
  real_T c6_c_hoistedGlobal;
  real_T c6_d_hoistedGlobal;
  real_T c6_U;
  int32_T c6_i6;
  real_T c6_x[7];
  int32_T c6_i7;
  real_T c6_Dis_Path_o[2];
  real_T c6_Theta_wp;
  int32_T c6_i8;
  real_T c6_R_po[4];
  real_T c6_r_c;
  real_T c6_b_gama;
  uint32_T c6_debug_family_var_map[13];
  real_T c6_Dis_Ship_o[2];
  real_T c6_nargin = 7.0;
  real_T c6_nargout = 3.0;
  real_T c6_m_dot;
  real_T c6_Dis_PS_p[2];
  real_T c6_e;
  real_T c6_b_x[2];
  int32_T c6_i9;
  int32_T c6_i10;
  real_T c6_a[4];
  int32_T c6_i11;
  real_T c6_b[2];
  int32_T c6_i12;
  int32_T c6_i13;
  int32_T c6_i14;
  real_T c6_C[2];
  int32_T c6_i15;
  int32_T c6_i16;
  int32_T c6_i17;
  int32_T c6_i18;
  int32_T c6_i19;
  int32_T c6_i20;
  real_T c6_c_x;
  real_T c6_d_x;
  real_T c6_b_a;
  real_T c6_b_b;
  real_T c6_y;
  real_T c6_c_a;
  real_T c6_c_b;
  real_T c6_b_y;
  real_T c6_A;
  real_T c6_B;
  real_T c6_e_x;
  real_T c6_c_y;
  real_T c6_f_x;
  real_T c6_d_y;
  int32_T c6_i21;
  real_T *c6_b_U;
  real_T *c6_b_Theta_wp;
  real_T *c6_b_r_c;
  real_T *c6_b_m_dot;
  real_T *c6_b_e;
  real_T (*c6_b_Dis_PS_p)[2];
  real_T (*c6_b_R_po)[4];
  real_T (*c6_b_Dis_Path_o)[2];
  real_T (*c6_g_x)[7];
  c6_b_e = (real_T *)ssGetOutputPortSignal(chartInstance->S, 3);
  c6_b_Dis_PS_p = (real_T (*)[2])ssGetOutputPortSignal(chartInstance->S, 2);
  c6_b_r_c = (real_T *)ssGetInputPortSignal(chartInstance->S, 5);
  c6_b_R_po = (real_T (*)[4])ssGetInputPortSignal(chartInstance->S, 4);
  c6_b_Theta_wp = (real_T *)ssGetInputPortSignal(chartInstance->S, 3);
  c6_b_Dis_Path_o = (real_T (*)[2])ssGetInputPortSignal(chartInstance->S, 2);
  c6_g_x = (real_T (*)[7])ssGetInputPortSignal(chartInstance->S, 1);
  c6_b_m_dot = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c6_b_U = (real_T *)ssGetInputPortSignal(chartInstance->S, 0);
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 5U, chartInstance->c6_sfEvent);
  c6_hoistedGlobal = *c6_b_U;
  c6_b_hoistedGlobal = *c6_b_Theta_wp;
  c6_c_hoistedGlobal = *c6_b_r_c;
  c6_d_hoistedGlobal = chartInstance->c6_gama;
  c6_U = c6_hoistedGlobal;
  for (c6_i6 = 0; c6_i6 < 7; c6_i6++) {
    c6_x[c6_i6] = (*c6_g_x)[c6_i6];
  }

  for (c6_i7 = 0; c6_i7 < 2; c6_i7++) {
    c6_Dis_Path_o[c6_i7] = (*c6_b_Dis_Path_o)[c6_i7];
  }

  c6_Theta_wp = c6_b_hoistedGlobal;
  for (c6_i8 = 0; c6_i8 < 4; c6_i8++) {
    c6_R_po[c6_i8] = (*c6_b_R_po)[c6_i8];
  }

  c6_r_c = c6_c_hoistedGlobal;
  c6_b_gama = c6_d_hoistedGlobal;
  sf_debug_symbol_scope_push_eml(0U, 13U, 13U, c6_debug_family_names,
    c6_debug_family_var_map);
  sf_debug_symbol_scope_add_eml_importable(c6_Dis_Ship_o, 0U,
    c6_b_sf_marshallOut, c6_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c6_nargin, 1U, c6_sf_marshallOut,
    c6_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c6_nargout, 2U, c6_sf_marshallOut,
    c6_sf_marshallIn);
  sf_debug_symbol_scope_add_eml(&c6_U, 3U, c6_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(c6_x, 4U, c6_d_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(c6_Dis_Path_o, 5U, c6_b_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c6_Theta_wp, 6U, c6_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(c6_R_po, 7U, c6_c_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c6_r_c, 8U, c6_sf_marshallOut);
  sf_debug_symbol_scope_add_eml_importable(&c6_b_gama, 9U, c6_sf_marshallOut,
    c6_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c6_m_dot, 10U, c6_sf_marshallOut,
    c6_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(c6_Dis_PS_p, 11U, c6_b_sf_marshallOut,
    c6_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c6_e, 12U, c6_sf_marshallOut,
    c6_sf_marshallIn);
  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(0U, chartInstance->c6_sfEvent, 3);
  c6_b_x[0] = c6_x[3];
  c6_b_x[1] = c6_x[4];
  for (c6_i9 = 0; c6_i9 < 2; c6_i9++) {
    c6_Dis_Ship_o[c6_i9] = c6_b_x[c6_i9];
  }

  _SFD_EML_CALL(0U, chartInstance->c6_sfEvent, 5);
  for (c6_i10 = 0; c6_i10 < 4; c6_i10++) {
    c6_a[c6_i10] = c6_R_po[c6_i10];
  }

  for (c6_i11 = 0; c6_i11 < 2; c6_i11++) {
    c6_b[c6_i11] = c6_Dis_Ship_o[c6_i11] - c6_Dis_Path_o[c6_i11];
  }

  c6_eml_scalar_eg(chartInstance);
  c6_eml_scalar_eg(chartInstance);
  for (c6_i12 = 0; c6_i12 < 2; c6_i12++) {
    c6_Dis_PS_p[c6_i12] = 0.0;
  }

  for (c6_i13 = 0; c6_i13 < 2; c6_i13++) {
    c6_Dis_PS_p[c6_i13] = 0.0;
  }

  for (c6_i14 = 0; c6_i14 < 2; c6_i14++) {
    c6_C[c6_i14] = c6_Dis_PS_p[c6_i14];
  }

  for (c6_i15 = 0; c6_i15 < 2; c6_i15++) {
    c6_Dis_PS_p[c6_i15] = c6_C[c6_i15];
  }

  for (c6_i16 = 0; c6_i16 < 2; c6_i16++) {
    c6_C[c6_i16] = c6_Dis_PS_p[c6_i16];
  }

  for (c6_i17 = 0; c6_i17 < 2; c6_i17++) {
    c6_Dis_PS_p[c6_i17] = c6_C[c6_i17];
  }

  for (c6_i18 = 0; c6_i18 < 2; c6_i18++) {
    c6_Dis_PS_p[c6_i18] = 0.0;
    c6_i19 = 0;
    for (c6_i20 = 0; c6_i20 < 2; c6_i20++) {
      c6_Dis_PS_p[c6_i18] += c6_a[c6_i19 + c6_i18] * c6_b[c6_i20];
      c6_i19 += 2;
    }
  }

  _SFD_EML_CALL(0U, chartInstance->c6_sfEvent, 6);
  c6_e = c6_Dis_PS_p[1];
  _SFD_EML_CALL(0U, chartInstance->c6_sfEvent, 7);
  c6_c_x = c6_Theta_wp;
  c6_d_x = c6_c_x;
  c6_d_x = muDoubleScalarCos(c6_d_x);
  c6_b_a = c6_U;
  c6_b_b = c6_d_x;
  c6_y = c6_b_a * c6_b_b;
  c6_c_a = c6_b_gama;
  c6_c_b = c6_Dis_PS_p[0];
  c6_b_y = c6_c_a * c6_c_b;
  c6_A = c6_y + c6_b_y;
  c6_B = c6_r_c;
  c6_e_x = c6_A;
  c6_c_y = c6_B;
  c6_f_x = c6_e_x;
  c6_d_y = c6_c_y;
  c6_m_dot = c6_f_x / c6_d_y;
  _SFD_EML_CALL(0U, chartInstance->c6_sfEvent, -7);
  sf_debug_symbol_scope_pop();
  *c6_b_m_dot = c6_m_dot;
  for (c6_i21 = 0; c6_i21 < 2; c6_i21++) {
    (*c6_b_Dis_PS_p)[c6_i21] = c6_Dis_PS_p[c6_i21];
  }

  *c6_b_e = c6_e;
  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 5U, chartInstance->c6_sfEvent);
}

static void initSimStructsc6_test(SFc6_testInstanceStruct *chartInstance)
{
}

static void init_script_number_translation(uint32_T c6_machineNumber, uint32_T
  c6_chartNumber)
{
}

static const mxArray *c6_sf_marshallOut(void *chartInstanceVoid, void *c6_inData)
{
  const mxArray *c6_mxArrayOutData = NULL;
  real_T c6_u;
  const mxArray *c6_y = NULL;
  SFc6_testInstanceStruct *chartInstance;
  chartInstance = (SFc6_testInstanceStruct *)chartInstanceVoid;
  c6_mxArrayOutData = NULL;
  c6_u = *(real_T *)c6_inData;
  c6_y = NULL;
  sf_mex_assign(&c6_y, sf_mex_create("y", &c6_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c6_mxArrayOutData, c6_y, FALSE);
  return c6_mxArrayOutData;
}

static real_T c6_emlrt_marshallIn(SFc6_testInstanceStruct *chartInstance, const
  mxArray *c6_e, const char_T *c6_identifier)
{
  real_T c6_y;
  emlrtMsgIdentifier c6_thisId;
  c6_thisId.fIdentifier = c6_identifier;
  c6_thisId.fParent = NULL;
  c6_y = c6_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c6_e), &c6_thisId);
  sf_mex_destroy(&c6_e);
  return c6_y;
}

static real_T c6_b_emlrt_marshallIn(SFc6_testInstanceStruct *chartInstance,
  const mxArray *c6_u, const emlrtMsgIdentifier *c6_parentId)
{
  real_T c6_y;
  real_T c6_d1;
  sf_mex_import(c6_parentId, sf_mex_dup(c6_u), &c6_d1, 1, 0, 0U, 0, 0U, 0);
  c6_y = c6_d1;
  sf_mex_destroy(&c6_u);
  return c6_y;
}

static void c6_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c6_mxArrayInData, const char_T *c6_varName, void *c6_outData)
{
  const mxArray *c6_e;
  const char_T *c6_identifier;
  emlrtMsgIdentifier c6_thisId;
  real_T c6_y;
  SFc6_testInstanceStruct *chartInstance;
  chartInstance = (SFc6_testInstanceStruct *)chartInstanceVoid;
  c6_e = sf_mex_dup(c6_mxArrayInData);
  c6_identifier = c6_varName;
  c6_thisId.fIdentifier = c6_identifier;
  c6_thisId.fParent = NULL;
  c6_y = c6_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c6_e), &c6_thisId);
  sf_mex_destroy(&c6_e);
  *(real_T *)c6_outData = c6_y;
  sf_mex_destroy(&c6_mxArrayInData);
}

static const mxArray *c6_b_sf_marshallOut(void *chartInstanceVoid, void
  *c6_inData)
{
  const mxArray *c6_mxArrayOutData = NULL;
  int32_T c6_i22;
  real_T c6_b_inData[2];
  int32_T c6_i23;
  real_T c6_u[2];
  const mxArray *c6_y = NULL;
  SFc6_testInstanceStruct *chartInstance;
  chartInstance = (SFc6_testInstanceStruct *)chartInstanceVoid;
  c6_mxArrayOutData = NULL;
  for (c6_i22 = 0; c6_i22 < 2; c6_i22++) {
    c6_b_inData[c6_i22] = (*(real_T (*)[2])c6_inData)[c6_i22];
  }

  for (c6_i23 = 0; c6_i23 < 2; c6_i23++) {
    c6_u[c6_i23] = c6_b_inData[c6_i23];
  }

  c6_y = NULL;
  sf_mex_assign(&c6_y, sf_mex_create("y", c6_u, 0, 0U, 1U, 0U, 1, 2), FALSE);
  sf_mex_assign(&c6_mxArrayOutData, c6_y, FALSE);
  return c6_mxArrayOutData;
}

static void c6_c_emlrt_marshallIn(SFc6_testInstanceStruct *chartInstance, const
  mxArray *c6_Dis_PS_p, const char_T *c6_identifier, real_T c6_y[2])
{
  emlrtMsgIdentifier c6_thisId;
  c6_thisId.fIdentifier = c6_identifier;
  c6_thisId.fParent = NULL;
  c6_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c6_Dis_PS_p), &c6_thisId, c6_y);
  sf_mex_destroy(&c6_Dis_PS_p);
}

static void c6_d_emlrt_marshallIn(SFc6_testInstanceStruct *chartInstance, const
  mxArray *c6_u, const emlrtMsgIdentifier *c6_parentId, real_T c6_y[2])
{
  real_T c6_dv1[2];
  int32_T c6_i24;
  sf_mex_import(c6_parentId, sf_mex_dup(c6_u), c6_dv1, 1, 0, 0U, 1, 0U, 1, 2);
  for (c6_i24 = 0; c6_i24 < 2; c6_i24++) {
    c6_y[c6_i24] = c6_dv1[c6_i24];
  }

  sf_mex_destroy(&c6_u);
}

static void c6_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c6_mxArrayInData, const char_T *c6_varName, void *c6_outData)
{
  const mxArray *c6_Dis_PS_p;
  const char_T *c6_identifier;
  emlrtMsgIdentifier c6_thisId;
  real_T c6_y[2];
  int32_T c6_i25;
  SFc6_testInstanceStruct *chartInstance;
  chartInstance = (SFc6_testInstanceStruct *)chartInstanceVoid;
  c6_Dis_PS_p = sf_mex_dup(c6_mxArrayInData);
  c6_identifier = c6_varName;
  c6_thisId.fIdentifier = c6_identifier;
  c6_thisId.fParent = NULL;
  c6_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c6_Dis_PS_p), &c6_thisId, c6_y);
  sf_mex_destroy(&c6_Dis_PS_p);
  for (c6_i25 = 0; c6_i25 < 2; c6_i25++) {
    (*(real_T (*)[2])c6_outData)[c6_i25] = c6_y[c6_i25];
  }

  sf_mex_destroy(&c6_mxArrayInData);
}

static const mxArray *c6_c_sf_marshallOut(void *chartInstanceVoid, void
  *c6_inData)
{
  const mxArray *c6_mxArrayOutData = NULL;
  int32_T c6_i26;
  int32_T c6_i27;
  int32_T c6_i28;
  real_T c6_b_inData[4];
  int32_T c6_i29;
  int32_T c6_i30;
  int32_T c6_i31;
  real_T c6_u[4];
  const mxArray *c6_y = NULL;
  SFc6_testInstanceStruct *chartInstance;
  chartInstance = (SFc6_testInstanceStruct *)chartInstanceVoid;
  c6_mxArrayOutData = NULL;
  c6_i26 = 0;
  for (c6_i27 = 0; c6_i27 < 2; c6_i27++) {
    for (c6_i28 = 0; c6_i28 < 2; c6_i28++) {
      c6_b_inData[c6_i28 + c6_i26] = (*(real_T (*)[4])c6_inData)[c6_i28 + c6_i26];
    }

    c6_i26 += 2;
  }

  c6_i29 = 0;
  for (c6_i30 = 0; c6_i30 < 2; c6_i30++) {
    for (c6_i31 = 0; c6_i31 < 2; c6_i31++) {
      c6_u[c6_i31 + c6_i29] = c6_b_inData[c6_i31 + c6_i29];
    }

    c6_i29 += 2;
  }

  c6_y = NULL;
  sf_mex_assign(&c6_y, sf_mex_create("y", c6_u, 0, 0U, 1U, 0U, 2, 2, 2), FALSE);
  sf_mex_assign(&c6_mxArrayOutData, c6_y, FALSE);
  return c6_mxArrayOutData;
}

static const mxArray *c6_d_sf_marshallOut(void *chartInstanceVoid, void
  *c6_inData)
{
  const mxArray *c6_mxArrayOutData = NULL;
  int32_T c6_i32;
  real_T c6_b_inData[7];
  int32_T c6_i33;
  real_T c6_u[7];
  const mxArray *c6_y = NULL;
  SFc6_testInstanceStruct *chartInstance;
  chartInstance = (SFc6_testInstanceStruct *)chartInstanceVoid;
  c6_mxArrayOutData = NULL;
  for (c6_i32 = 0; c6_i32 < 7; c6_i32++) {
    c6_b_inData[c6_i32] = (*(real_T (*)[7])c6_inData)[c6_i32];
  }

  for (c6_i33 = 0; c6_i33 < 7; c6_i33++) {
    c6_u[c6_i33] = c6_b_inData[c6_i33];
  }

  c6_y = NULL;
  sf_mex_assign(&c6_y, sf_mex_create("y", c6_u, 0, 0U, 1U, 0U, 1, 7), FALSE);
  sf_mex_assign(&c6_mxArrayOutData, c6_y, FALSE);
  return c6_mxArrayOutData;
}

const mxArray *sf_c6_test_get_eml_resolved_functions_info(void)
{
  const mxArray *c6_nameCaptureInfo;
  c6_ResolvedFunctionInfo c6_info[14];
  const mxArray *c6_m0 = NULL;
  int32_T c6_i34;
  c6_ResolvedFunctionInfo *c6_r0;
  c6_nameCaptureInfo = NULL;
  c6_nameCaptureInfo = NULL;
  c6_info_helper(c6_info);
  sf_mex_assign(&c6_m0, sf_mex_createstruct("nameCaptureInfo", 1, 14), FALSE);
  for (c6_i34 = 0; c6_i34 < 14; c6_i34++) {
    c6_r0 = &c6_info[c6_i34];
    sf_mex_addfield(c6_m0, sf_mex_create("nameCaptureInfo", c6_r0->context, 15,
      0U, 0U, 0U, 2, 1, strlen(c6_r0->context)), "context", "nameCaptureInfo",
                    c6_i34);
    sf_mex_addfield(c6_m0, sf_mex_create("nameCaptureInfo", c6_r0->name, 15, 0U,
      0U, 0U, 2, 1, strlen(c6_r0->name)), "name", "nameCaptureInfo", c6_i34);
    sf_mex_addfield(c6_m0, sf_mex_create("nameCaptureInfo", c6_r0->dominantType,
      15, 0U, 0U, 0U, 2, 1, strlen(c6_r0->dominantType)), "dominantType",
                    "nameCaptureInfo", c6_i34);
    sf_mex_addfield(c6_m0, sf_mex_create("nameCaptureInfo", c6_r0->resolved, 15,
      0U, 0U, 0U, 2, 1, strlen(c6_r0->resolved)), "resolved", "nameCaptureInfo",
                    c6_i34);
    sf_mex_addfield(c6_m0, sf_mex_create("nameCaptureInfo", &c6_r0->fileTimeLo,
      7, 0U, 0U, 0U, 0), "fileTimeLo", "nameCaptureInfo", c6_i34);
    sf_mex_addfield(c6_m0, sf_mex_create("nameCaptureInfo", &c6_r0->fileTimeHi,
      7, 0U, 0U, 0U, 0), "fileTimeHi", "nameCaptureInfo", c6_i34);
    sf_mex_addfield(c6_m0, sf_mex_create("nameCaptureInfo", &c6_r0->mFileTimeLo,
      7, 0U, 0U, 0U, 0), "mFileTimeLo", "nameCaptureInfo", c6_i34);
    sf_mex_addfield(c6_m0, sf_mex_create("nameCaptureInfo", &c6_r0->mFileTimeHi,
      7, 0U, 0U, 0U, 0), "mFileTimeHi", "nameCaptureInfo", c6_i34);
  }

  sf_mex_assign(&c6_nameCaptureInfo, c6_m0, FALSE);
  sf_mex_emlrtNameCapturePostProcessR2012a(&c6_nameCaptureInfo);
  return c6_nameCaptureInfo;
}

static void c6_info_helper(c6_ResolvedFunctionInfo c6_info[14])
{
  c6_info[0].context = "";
  c6_info[0].name = "mtimes";
  c6_info[0].dominantType = "double";
  c6_info[0].resolved = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c6_info[0].fileTimeLo = 1289494492U;
  c6_info[0].fileTimeHi = 0U;
  c6_info[0].mFileTimeLo = 0U;
  c6_info[0].mFileTimeHi = 0U;
  c6_info[1].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c6_info[1].name = "eml_index_class";
  c6_info[1].dominantType = "";
  c6_info[1].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c6_info[1].fileTimeLo = 1323145378U;
  c6_info[1].fileTimeHi = 0U;
  c6_info[1].mFileTimeLo = 0U;
  c6_info[1].mFileTimeHi = 0U;
  c6_info[2].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c6_info[2].name = "eml_scalar_eg";
  c6_info[2].dominantType = "double";
  c6_info[2].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m";
  c6_info[2].fileTimeLo = 1286797196U;
  c6_info[2].fileTimeHi = 0U;
  c6_info[2].mFileTimeLo = 0U;
  c6_info[2].mFileTimeHi = 0U;
  c6_info[3].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c6_info[3].name = "eml_xgemm";
  c6_info[3].dominantType = "char";
  c6_info[3].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xgemm.m";
  c6_info[3].fileTimeLo = 1299051572U;
  c6_info[3].fileTimeHi = 0U;
  c6_info[3].mFileTimeLo = 0U;
  c6_info[3].mFileTimeHi = 0U;
  c6_info[4].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xgemm.m";
  c6_info[4].name = "eml_blas_inline";
  c6_info[4].dominantType = "";
  c6_info[4].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_blas_inline.m";
  c6_info[4].fileTimeLo = 1299051568U;
  c6_info[4].fileTimeHi = 0U;
  c6_info[4].mFileTimeLo = 0U;
  c6_info[4].mFileTimeHi = 0U;
  c6_info[5].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xgemm.m!below_threshold";
  c6_info[5].name = "mtimes";
  c6_info[5].dominantType = "double";
  c6_info[5].resolved = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c6_info[5].fileTimeLo = 1289494492U;
  c6_info[5].fileTimeHi = 0U;
  c6_info[5].mFileTimeLo = 0U;
  c6_info[5].mFileTimeHi = 0U;
  c6_info[6].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xgemm.m";
  c6_info[6].name = "eml_index_class";
  c6_info[6].dominantType = "";
  c6_info[6].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c6_info[6].fileTimeLo = 1323145378U;
  c6_info[6].fileTimeHi = 0U;
  c6_info[6].mFileTimeLo = 0U;
  c6_info[6].mFileTimeHi = 0U;
  c6_info[7].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xgemm.m";
  c6_info[7].name = "eml_scalar_eg";
  c6_info[7].dominantType = "double";
  c6_info[7].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m";
  c6_info[7].fileTimeLo = 1286797196U;
  c6_info[7].fileTimeHi = 0U;
  c6_info[7].mFileTimeLo = 0U;
  c6_info[7].mFileTimeHi = 0U;
  c6_info[8].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xgemm.m";
  c6_info[8].name = "eml_refblas_xgemm";
  c6_info[8].dominantType = "char";
  c6_info[8].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xgemm.m";
  c6_info[8].fileTimeLo = 1299051574U;
  c6_info[8].fileTimeHi = 0U;
  c6_info[8].mFileTimeLo = 0U;
  c6_info[8].mFileTimeHi = 0U;
  c6_info[9].context = "";
  c6_info[9].name = "cos";
  c6_info[9].dominantType = "double";
  c6_info[9].resolved = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/cos.m";
  c6_info[9].fileTimeLo = 1286797106U;
  c6_info[9].fileTimeHi = 0U;
  c6_info[9].mFileTimeLo = 0U;
  c6_info[9].mFileTimeHi = 0U;
  c6_info[10].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/cos.m";
  c6_info[10].name = "eml_scalar_cos";
  c6_info[10].dominantType = "double";
  c6_info[10].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_cos.m";
  c6_info[10].fileTimeLo = 1286797122U;
  c6_info[10].fileTimeHi = 0U;
  c6_info[10].mFileTimeLo = 0U;
  c6_info[10].mFileTimeHi = 0U;
  c6_info[11].context = "";
  c6_info[11].name = "mrdivide";
  c6_info[11].dominantType = "double";
  c6_info[11].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p";
  c6_info[11].fileTimeLo = 1342789344U;
  c6_info[11].fileTimeHi = 0U;
  c6_info[11].mFileTimeLo = 1319708366U;
  c6_info[11].mFileTimeHi = 0U;
  c6_info[12].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p";
  c6_info[12].name = "rdivide";
  c6_info[12].dominantType = "double";
  c6_info[12].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m";
  c6_info[12].fileTimeLo = 1286797244U;
  c6_info[12].fileTimeHi = 0U;
  c6_info[12].mFileTimeLo = 0U;
  c6_info[12].mFileTimeHi = 0U;
  c6_info[13].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m";
  c6_info[13].name = "eml_div";
  c6_info[13].dominantType = "double";
  c6_info[13].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_div.m";
  c6_info[13].fileTimeLo = 1313326210U;
  c6_info[13].fileTimeHi = 0U;
  c6_info[13].mFileTimeLo = 0U;
  c6_info[13].mFileTimeHi = 0U;
}

static void c6_eml_scalar_eg(SFc6_testInstanceStruct *chartInstance)
{
}

static const mxArray *c6_e_sf_marshallOut(void *chartInstanceVoid, void
  *c6_inData)
{
  const mxArray *c6_mxArrayOutData = NULL;
  int32_T c6_u;
  const mxArray *c6_y = NULL;
  SFc6_testInstanceStruct *chartInstance;
  chartInstance = (SFc6_testInstanceStruct *)chartInstanceVoid;
  c6_mxArrayOutData = NULL;
  c6_u = *(int32_T *)c6_inData;
  c6_y = NULL;
  sf_mex_assign(&c6_y, sf_mex_create("y", &c6_u, 6, 0U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c6_mxArrayOutData, c6_y, FALSE);
  return c6_mxArrayOutData;
}

static int32_T c6_e_emlrt_marshallIn(SFc6_testInstanceStruct *chartInstance,
  const mxArray *c6_u, const emlrtMsgIdentifier *c6_parentId)
{
  int32_T c6_y;
  int32_T c6_i35;
  sf_mex_import(c6_parentId, sf_mex_dup(c6_u), &c6_i35, 1, 6, 0U, 0, 0U, 0);
  c6_y = c6_i35;
  sf_mex_destroy(&c6_u);
  return c6_y;
}

static void c6_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c6_mxArrayInData, const char_T *c6_varName, void *c6_outData)
{
  const mxArray *c6_b_sfEvent;
  const char_T *c6_identifier;
  emlrtMsgIdentifier c6_thisId;
  int32_T c6_y;
  SFc6_testInstanceStruct *chartInstance;
  chartInstance = (SFc6_testInstanceStruct *)chartInstanceVoid;
  c6_b_sfEvent = sf_mex_dup(c6_mxArrayInData);
  c6_identifier = c6_varName;
  c6_thisId.fIdentifier = c6_identifier;
  c6_thisId.fParent = NULL;
  c6_y = c6_e_emlrt_marshallIn(chartInstance, sf_mex_dup(c6_b_sfEvent),
    &c6_thisId);
  sf_mex_destroy(&c6_b_sfEvent);
  *(int32_T *)c6_outData = c6_y;
  sf_mex_destroy(&c6_mxArrayInData);
}

static uint8_T c6_f_emlrt_marshallIn(SFc6_testInstanceStruct *chartInstance,
  const mxArray *c6_b_is_active_c6_test, const char_T *c6_identifier)
{
  uint8_T c6_y;
  emlrtMsgIdentifier c6_thisId;
  c6_thisId.fIdentifier = c6_identifier;
  c6_thisId.fParent = NULL;
  c6_y = c6_g_emlrt_marshallIn(chartInstance, sf_mex_dup(c6_b_is_active_c6_test),
    &c6_thisId);
  sf_mex_destroy(&c6_b_is_active_c6_test);
  return c6_y;
}

static uint8_T c6_g_emlrt_marshallIn(SFc6_testInstanceStruct *chartInstance,
  const mxArray *c6_u, const emlrtMsgIdentifier *c6_parentId)
{
  uint8_T c6_y;
  uint8_T c6_u0;
  sf_mex_import(c6_parentId, sf_mex_dup(c6_u), &c6_u0, 1, 3, 0U, 0, 0U, 0);
  c6_y = c6_u0;
  sf_mex_destroy(&c6_u);
  return c6_y;
}

static void init_dsm_address_info(SFc6_testInstanceStruct *chartInstance)
{
}

/* SFunction Glue Code */
void sf_c6_test_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(2276061796U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(1999690239U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(1717522795U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(2258715683U);
}

mxArray *sf_c6_test_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1,1,5,
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateString("q0s7aRqXVxRJ3MajF6p9eB");
    mxSetField(mxAutoinheritanceInfo,0,"checksum",mxChecksum);
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,6,3,dataFields);

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
      pr[0] = (double)(7);
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
      pr[0] = (double)(2);
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
      pr[1] = (double)(2);
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

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,5,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,5,"type",mxType);
    }

    mxSetField(mxData,5,"complexity",mxCreateDoubleScalar(0));
    mxSetField(mxAutoinheritanceInfo,0,"inputs",mxData);
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
    mxSetField(mxAutoinheritanceInfo,0,"parameters",mxData);
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
      pr[0] = (double)(2);
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

static const mxArray *sf_get_sim_state_info_c6_test(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x4'type','srcId','name','auxInfo'{{M[1],M[12],T\"Dis_PS_p\",},{M[1],M[13],T\"e\",},{M[1],M[5],T\"m_dot\",},{M[8],M[0],T\"is_active_c6_test\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 4, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c6_test_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc6_testInstanceStruct *chartInstance;
    chartInstance = (SFc6_testInstanceStruct *) ((ChartInfoStruct *)
      (ssGetUserData(S)))->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart(_testMachineNumber_,
          6,
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
          _SFD_SET_DATA_PROPS(0,1,1,0,"U");
          _SFD_SET_DATA_PROPS(1,2,0,1,"m_dot");
          _SFD_SET_DATA_PROPS(2,1,1,0,"x");
          _SFD_SET_DATA_PROPS(3,1,1,0,"Dis_Path_o");
          _SFD_SET_DATA_PROPS(4,1,1,0,"Theta_wp");
          _SFD_SET_DATA_PROPS(5,1,1,0,"R_po");
          _SFD_SET_DATA_PROPS(6,1,1,0,"r_c");
          _SFD_SET_DATA_PROPS(7,10,0,0,"gama");
          _SFD_SET_DATA_PROPS(8,2,0,1,"Dis_PS_p");
          _SFD_SET_DATA_PROPS(9,2,0,1,"e");
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
        _SFD_CV_INIT_EML_FCN(0,0,"eML_blk_kernel",0,-1,268);
        _SFD_TRANS_COV_WTS(0,0,0,1,0);
        if (chartAlreadyPresent==0) {
          _SFD_TRANS_COV_MAPS(0,
                              0,NULL,NULL,
                              0,NULL,NULL,
                              1,NULL,NULL,
                              0,NULL,NULL);
        }

        _SFD_SET_DATA_COMPILED_PROPS(0,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c6_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(1,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c6_sf_marshallOut,(MexInFcnForType)c6_sf_marshallIn);

        {
          unsigned int dimVector[1];
          dimVector[0]= 7;
          _SFD_SET_DATA_COMPILED_PROPS(2,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c6_d_sf_marshallOut,(MexInFcnForType)NULL);
        }

        {
          unsigned int dimVector[1];
          dimVector[0]= 2;
          _SFD_SET_DATA_COMPILED_PROPS(3,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c6_b_sf_marshallOut,(MexInFcnForType)NULL);
        }

        _SFD_SET_DATA_COMPILED_PROPS(4,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c6_sf_marshallOut,(MexInFcnForType)NULL);

        {
          unsigned int dimVector[2];
          dimVector[0]= 2;
          dimVector[1]= 2;
          _SFD_SET_DATA_COMPILED_PROPS(5,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c6_c_sf_marshallOut,(MexInFcnForType)NULL);
        }

        _SFD_SET_DATA_COMPILED_PROPS(6,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c6_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(7,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c6_sf_marshallOut,(MexInFcnForType)c6_sf_marshallIn);

        {
          unsigned int dimVector[1];
          dimVector[0]= 2;
          _SFD_SET_DATA_COMPILED_PROPS(8,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c6_b_sf_marshallOut,(MexInFcnForType)
            c6_b_sf_marshallIn);
        }

        _SFD_SET_DATA_COMPILED_PROPS(9,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c6_sf_marshallOut,(MexInFcnForType)c6_sf_marshallIn);

        {
          real_T *c6_U;
          real_T *c6_m_dot;
          real_T *c6_Theta_wp;
          real_T *c6_r_c;
          real_T *c6_e;
          real_T (*c6_x)[7];
          real_T (*c6_Dis_Path_o)[2];
          real_T (*c6_R_po)[4];
          real_T (*c6_Dis_PS_p)[2];
          c6_e = (real_T *)ssGetOutputPortSignal(chartInstance->S, 3);
          c6_Dis_PS_p = (real_T (*)[2])ssGetOutputPortSignal(chartInstance->S, 2);
          c6_r_c = (real_T *)ssGetInputPortSignal(chartInstance->S, 5);
          c6_R_po = (real_T (*)[4])ssGetInputPortSignal(chartInstance->S, 4);
          c6_Theta_wp = (real_T *)ssGetInputPortSignal(chartInstance->S, 3);
          c6_Dis_Path_o = (real_T (*)[2])ssGetInputPortSignal(chartInstance->S,
            2);
          c6_x = (real_T (*)[7])ssGetInputPortSignal(chartInstance->S, 1);
          c6_m_dot = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
          c6_U = (real_T *)ssGetInputPortSignal(chartInstance->S, 0);
          _SFD_SET_DATA_VALUE_PTR(0U, c6_U);
          _SFD_SET_DATA_VALUE_PTR(1U, c6_m_dot);
          _SFD_SET_DATA_VALUE_PTR(2U, *c6_x);
          _SFD_SET_DATA_VALUE_PTR(3U, *c6_Dis_Path_o);
          _SFD_SET_DATA_VALUE_PTR(4U, c6_Theta_wp);
          _SFD_SET_DATA_VALUE_PTR(5U, *c6_R_po);
          _SFD_SET_DATA_VALUE_PTR(6U, c6_r_c);
          _SFD_SET_DATA_VALUE_PTR(7U, &chartInstance->c6_gama);
          _SFD_SET_DATA_VALUE_PTR(8U, *c6_Dis_PS_p);
          _SFD_SET_DATA_VALUE_PTR(9U, c6_e);
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
  return "zirMbfisLSI18AJyu2I58C";
}

static void sf_opaque_initialize_c6_test(void *chartInstanceVar)
{
  chart_debug_initialization(((SFc6_testInstanceStruct*) chartInstanceVar)->S,0);
  initialize_params_c6_test((SFc6_testInstanceStruct*) chartInstanceVar);
  initialize_c6_test((SFc6_testInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_enable_c6_test(void *chartInstanceVar)
{
  enable_c6_test((SFc6_testInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_disable_c6_test(void *chartInstanceVar)
{
  disable_c6_test((SFc6_testInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_gateway_c6_test(void *chartInstanceVar)
{
  sf_c6_test((SFc6_testInstanceStruct*) chartInstanceVar);
}

extern const mxArray* sf_internal_get_sim_state_c6_test(SimStruct* S)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_raw2high");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = (mxArray*) get_sim_state_c6_test((SFc6_testInstanceStruct*)
    chartInfo->chartInstance);         /* raw sim ctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c6_test();/* state var info */
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

extern void sf_internal_set_sim_state_c6_test(SimStruct* S, const mxArray *st)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_high2raw");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = mxDuplicateArray(st);      /* high level simctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c6_test();/* state var info */
  mxError = sf_mex_call_matlab(1, plhs, 4, prhs, "sfprivate");
  mxDestroyArray(prhs[0]);
  mxDestroyArray(prhs[1]);
  mxDestroyArray(prhs[2]);
  mxDestroyArray(prhs[3]);
  if (mxError || plhs[0] == NULL) {
    sf_mex_error_message("Stateflow Internal Error: \nError calling 'chart_simctx_high2raw'.\n");
  }

  set_sim_state_c6_test((SFc6_testInstanceStruct*)chartInfo->chartInstance,
                        mxDuplicateArray(plhs[0]));
  mxDestroyArray(plhs[0]);
}

static const mxArray* sf_opaque_get_sim_state_c6_test(SimStruct* S)
{
  return sf_internal_get_sim_state_c6_test(S);
}

static void sf_opaque_set_sim_state_c6_test(SimStruct* S, const mxArray *st)
{
  sf_internal_set_sim_state_c6_test(S, st);
}

static void sf_opaque_terminate_c6_test(void *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc6_testInstanceStruct*) chartInstanceVar)->S;
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
    }

    finalize_c6_test((SFc6_testInstanceStruct*) chartInstanceVar);
    free((void *)chartInstanceVar);
    ssSetUserData(S,NULL);
  }

  unload_test_optimization_info();
}

static void sf_opaque_init_subchart_simstructs(void *chartInstanceVar)
{
  initSimStructsc6_test((SFc6_testInstanceStruct*) chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c6_test(SimStruct *S)
{
  int i;
  for (i=0;i<ssGetNumRunTimeParams(S);i++) {
    if (ssGetSFcnParamTunable(S,i)) {
      ssUpdateDlgParamAsRunTimeParam(S,i);
    }
  }

  if (sf_machine_global_initializer_called()) {
    initialize_params_c6_test((SFc6_testInstanceStruct*)(((ChartInfoStruct *)
      ssGetUserData(S))->chartInstance));
  }
}

static void mdlSetWorkWidths_c6_test(SimStruct *S)
{
  /* Actual parameters from chart:
     gama
   */
  const char_T *rtParamNames[] = { "p1" };

  ssSetNumRunTimeParams(S,ssGetSFcnParamsCount(S));

  /* registration for gama*/
  ssRegDlgParamAsRunTimeParam(S, 0, 0, rtParamNames[0], SS_DOUBLE);
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    mxArray *infoStruct = load_test_optimization_info();
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable(S,sf_get_instance_specialization(),infoStruct,
      6);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop(S,sf_get_instance_specialization(),
                infoStruct,6,"RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop(S,
      sf_get_instance_specialization(),infoStruct,6,
      "gatewayCannotBeInlinedMultipleTimes"));
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 1, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 2, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 3, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 4, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 5, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,sf_get_instance_specialization(),
        infoStruct,6,6);
      sf_mark_chart_reusable_outputs(S,sf_get_instance_specialization(),
        infoStruct,6,3);
    }

    sf_set_rtw_dwork_info(S,sf_get_instance_specialization(),infoStruct,6);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(3431848106U));
  ssSetChecksum1(S,(1194850041U));
  ssSetChecksum2(S,(612629021U));
  ssSetChecksum3(S,(1436174498U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
  ssSupportsMultipleExecInstances(S,1);
}

static void mdlRTW_c6_test(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c6_test(SimStruct *S)
{
  SFc6_testInstanceStruct *chartInstance;
  chartInstance = (SFc6_testInstanceStruct *)malloc(sizeof
    (SFc6_testInstanceStruct));
  memset(chartInstance, 0, sizeof(SFc6_testInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway = sf_opaque_gateway_c6_test;
  chartInstance->chartInfo.initializeChart = sf_opaque_initialize_c6_test;
  chartInstance->chartInfo.terminateChart = sf_opaque_terminate_c6_test;
  chartInstance->chartInfo.enableChart = sf_opaque_enable_c6_test;
  chartInstance->chartInfo.disableChart = sf_opaque_disable_c6_test;
  chartInstance->chartInfo.getSimState = sf_opaque_get_sim_state_c6_test;
  chartInstance->chartInfo.setSimState = sf_opaque_set_sim_state_c6_test;
  chartInstance->chartInfo.getSimStateInfo = sf_get_sim_state_info_c6_test;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c6_test;
  chartInstance->chartInfo.mdlStart = mdlStart_c6_test;
  chartInstance->chartInfo.mdlSetWorkWidths = mdlSetWorkWidths_c6_test;
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

void c6_test_method_dispatcher(SimStruct *S, int_T method, void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c6_test(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c6_test(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c6_test(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c6_test_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}

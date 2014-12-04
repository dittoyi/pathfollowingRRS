/* Include files */

#include "blascompat32.h"
#include "test_sfun.h"
#include "c3_test.h"
#include "mwmathutil.h"
#define CHARTINSTANCE_CHARTNUMBER      (chartInstance->chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER   (chartInstance->instanceNumber)
#include "test_sfun_debug_macros.h"

/* Type Definitions */

/* Named Constants */
#define CALL_EVENT                     (-1)

/* Variable Declarations */

/* Variable Definitions */
static const char * c3_debug_family_names[9] = { "Dis_Ship_o", "nargin",
  "nargout", "x", "Dis_Path_o", "R_po", "Delta_e", "Theta_wp_c", "Dis_PS_p" };

/* Function Declarations */
static void initialize_c3_test(SFc3_testInstanceStruct *chartInstance);
static void initialize_params_c3_test(SFc3_testInstanceStruct *chartInstance);
static void enable_c3_test(SFc3_testInstanceStruct *chartInstance);
static void disable_c3_test(SFc3_testInstanceStruct *chartInstance);
static void c3_update_debugger_state_c3_test(SFc3_testInstanceStruct
  *chartInstance);
static const mxArray *get_sim_state_c3_test(SFc3_testInstanceStruct
  *chartInstance);
static void set_sim_state_c3_test(SFc3_testInstanceStruct *chartInstance, const
  mxArray *c3_st);
static void finalize_c3_test(SFc3_testInstanceStruct *chartInstance);
static void sf_c3_test(SFc3_testInstanceStruct *chartInstance);
static void c3_chartstep_c3_test(SFc3_testInstanceStruct *chartInstance);
static void initSimStructsc3_test(SFc3_testInstanceStruct *chartInstance);
static void init_script_number_translation(uint32_T c3_machineNumber, uint32_T
  c3_chartNumber);
static const mxArray *c3_sf_marshallOut(void *chartInstanceVoid, void *c3_inData);
static void c3_emlrt_marshallIn(SFc3_testInstanceStruct *chartInstance, const
  mxArray *c3_Dis_PS_p, const char_T *c3_identifier, real_T c3_y[2]);
static void c3_b_emlrt_marshallIn(SFc3_testInstanceStruct *chartInstance, const
  mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId, real_T c3_y[2]);
static void c3_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, void *c3_outData);
static const mxArray *c3_b_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData);
static real_T c3_c_emlrt_marshallIn(SFc3_testInstanceStruct *chartInstance,
  const mxArray *c3_Theta_wp_c, const char_T *c3_identifier);
static real_T c3_d_emlrt_marshallIn(SFc3_testInstanceStruct *chartInstance,
  const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId);
static void c3_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, void *c3_outData);
static const mxArray *c3_c_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData);
static const mxArray *c3_d_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData);
static void c3_info_helper(c3_ResolvedFunctionInfo c3_info[14]);
static void c3_eml_scalar_eg(SFc3_testInstanceStruct *chartInstance);
static const mxArray *c3_e_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData);
static int32_T c3_e_emlrt_marshallIn(SFc3_testInstanceStruct *chartInstance,
  const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId);
static void c3_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, void *c3_outData);
static uint8_T c3_f_emlrt_marshallIn(SFc3_testInstanceStruct *chartInstance,
  const mxArray *c3_b_is_active_c3_test, const char_T *c3_identifier);
static uint8_T c3_g_emlrt_marshallIn(SFc3_testInstanceStruct *chartInstance,
  const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId);
static void init_dsm_address_info(SFc3_testInstanceStruct *chartInstance);

/* Function Definitions */
static void initialize_c3_test(SFc3_testInstanceStruct *chartInstance)
{
  chartInstance->c3_sfEvent = CALL_EVENT;
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  chartInstance->c3_is_active_c3_test = 0U;
}

static void initialize_params_c3_test(SFc3_testInstanceStruct *chartInstance)
{
  real_T c3_d0;
  sf_set_error_prefix_string(
    "Error evaluating data 'Delta_e' in the parent workspace.\n");
  sf_mex_import_named("Delta_e", sf_mex_get_sfun_param(chartInstance->S, 0, 0),
                      &c3_d0, 0, 0, 0U, 0, 0U, 0);
  chartInstance->c3_Delta_e = c3_d0;
  sf_set_error_prefix_string("Stateflow Runtime Error (chart): ");
}

static void enable_c3_test(SFc3_testInstanceStruct *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void disable_c3_test(SFc3_testInstanceStruct *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void c3_update_debugger_state_c3_test(SFc3_testInstanceStruct
  *chartInstance)
{
}

static const mxArray *get_sim_state_c3_test(SFc3_testInstanceStruct
  *chartInstance)
{
  const mxArray *c3_st;
  const mxArray *c3_y = NULL;
  int32_T c3_i0;
  real_T c3_u[2];
  const mxArray *c3_b_y = NULL;
  real_T c3_hoistedGlobal;
  real_T c3_b_u;
  const mxArray *c3_c_y = NULL;
  uint8_T c3_b_hoistedGlobal;
  uint8_T c3_c_u;
  const mxArray *c3_d_y = NULL;
  real_T *c3_Theta_wp_c;
  real_T (*c3_Dis_PS_p)[2];
  c3_Dis_PS_p = (real_T (*)[2])ssGetOutputPortSignal(chartInstance->S, 2);
  c3_Theta_wp_c = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c3_st = NULL;
  c3_st = NULL;
  c3_y = NULL;
  sf_mex_assign(&c3_y, sf_mex_createcellarray(3), FALSE);
  for (c3_i0 = 0; c3_i0 < 2; c3_i0++) {
    c3_u[c3_i0] = (*c3_Dis_PS_p)[c3_i0];
  }

  c3_b_y = NULL;
  sf_mex_assign(&c3_b_y, sf_mex_create("y", c3_u, 0, 0U, 1U, 0U, 1, 2), FALSE);
  sf_mex_setcell(c3_y, 0, c3_b_y);
  c3_hoistedGlobal = *c3_Theta_wp_c;
  c3_b_u = c3_hoistedGlobal;
  c3_c_y = NULL;
  sf_mex_assign(&c3_c_y, sf_mex_create("y", &c3_b_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c3_y, 1, c3_c_y);
  c3_b_hoistedGlobal = chartInstance->c3_is_active_c3_test;
  c3_c_u = c3_b_hoistedGlobal;
  c3_d_y = NULL;
  sf_mex_assign(&c3_d_y, sf_mex_create("y", &c3_c_u, 3, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c3_y, 2, c3_d_y);
  sf_mex_assign(&c3_st, c3_y, FALSE);
  return c3_st;
}

static void set_sim_state_c3_test(SFc3_testInstanceStruct *chartInstance, const
  mxArray *c3_st)
{
  const mxArray *c3_u;
  real_T c3_dv0[2];
  int32_T c3_i1;
  real_T *c3_Theta_wp_c;
  real_T (*c3_Dis_PS_p)[2];
  c3_Dis_PS_p = (real_T (*)[2])ssGetOutputPortSignal(chartInstance->S, 2);
  c3_Theta_wp_c = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  chartInstance->c3_doneDoubleBufferReInit = TRUE;
  c3_u = sf_mex_dup(c3_st);
  c3_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c3_u, 0)),
                      "Dis_PS_p", c3_dv0);
  for (c3_i1 = 0; c3_i1 < 2; c3_i1++) {
    (*c3_Dis_PS_p)[c3_i1] = c3_dv0[c3_i1];
  }

  *c3_Theta_wp_c = c3_c_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c3_u, 1)), "Theta_wp_c");
  chartInstance->c3_is_active_c3_test = c3_f_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c3_u, 2)), "is_active_c3_test");
  sf_mex_destroy(&c3_u);
  c3_update_debugger_state_c3_test(chartInstance);
  sf_mex_destroy(&c3_st);
}

static void finalize_c3_test(SFc3_testInstanceStruct *chartInstance)
{
}

static void sf_c3_test(SFc3_testInstanceStruct *chartInstance)
{
  int32_T c3_i2;
  int32_T c3_i3;
  int32_T c3_i4;
  int32_T c3_i5;
  real_T *c3_Theta_wp_c;
  real_T (*c3_Dis_PS_p)[2];
  real_T (*c3_R_po)[4];
  real_T (*c3_Dis_Path_o)[2];
  real_T (*c3_x)[7];
  c3_Dis_PS_p = (real_T (*)[2])ssGetOutputPortSignal(chartInstance->S, 2);
  c3_R_po = (real_T (*)[4])ssGetInputPortSignal(chartInstance->S, 2);
  c3_Theta_wp_c = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c3_Dis_Path_o = (real_T (*)[2])ssGetInputPortSignal(chartInstance->S, 1);
  c3_x = (real_T (*)[7])ssGetInputPortSignal(chartInstance->S, 0);
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 2U, chartInstance->c3_sfEvent);
  for (c3_i2 = 0; c3_i2 < 7; c3_i2++) {
    _SFD_DATA_RANGE_CHECK((*c3_x)[c3_i2], 0U);
  }

  for (c3_i3 = 0; c3_i3 < 2; c3_i3++) {
    _SFD_DATA_RANGE_CHECK((*c3_Dis_Path_o)[c3_i3], 1U);
  }

  _SFD_DATA_RANGE_CHECK(*c3_Theta_wp_c, 2U);
  for (c3_i4 = 0; c3_i4 < 4; c3_i4++) {
    _SFD_DATA_RANGE_CHECK((*c3_R_po)[c3_i4], 3U);
  }

  for (c3_i5 = 0; c3_i5 < 2; c3_i5++) {
    _SFD_DATA_RANGE_CHECK((*c3_Dis_PS_p)[c3_i5], 4U);
  }

  _SFD_DATA_RANGE_CHECK(chartInstance->c3_Delta_e, 5U);
  chartInstance->c3_sfEvent = CALL_EVENT;
  c3_chartstep_c3_test(chartInstance);
  sf_debug_check_for_state_inconsistency(_testMachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
}

static void c3_chartstep_c3_test(SFc3_testInstanceStruct *chartInstance)
{
  real_T c3_hoistedGlobal;
  int32_T c3_i6;
  real_T c3_x[7];
  int32_T c3_i7;
  real_T c3_Dis_Path_o[2];
  int32_T c3_i8;
  real_T c3_R_po[4];
  real_T c3_b_Delta_e;
  uint32_T c3_debug_family_var_map[9];
  real_T c3_Dis_Ship_o[2];
  real_T c3_nargin = 4.0;
  real_T c3_nargout = 2.0;
  real_T c3_Theta_wp_c;
  real_T c3_Dis_PS_p[2];
  real_T c3_b_x[2];
  int32_T c3_i9;
  int32_T c3_i10;
  real_T c3_a[4];
  int32_T c3_i11;
  real_T c3_b[2];
  int32_T c3_i12;
  int32_T c3_i13;
  int32_T c3_i14;
  real_T c3_C[2];
  int32_T c3_i15;
  int32_T c3_i16;
  int32_T c3_i17;
  int32_T c3_i18;
  int32_T c3_i19;
  int32_T c3_i20;
  int32_T c3_i21;
  real_T c3_u[2];
  const mxArray *c3_y = NULL;
  real_T c3_A;
  real_T c3_B;
  real_T c3_c_x;
  real_T c3_b_y;
  real_T c3_d_x;
  real_T c3_c_y;
  real_T c3_d_y;
  real_T c3_e_x;
  real_T c3_f_x;
  int32_T c3_i22;
  real_T *c3_b_Theta_wp_c;
  real_T (*c3_b_Dis_PS_p)[2];
  real_T (*c3_b_R_po)[4];
  real_T (*c3_b_Dis_Path_o)[2];
  real_T (*c3_g_x)[7];
  c3_b_Dis_PS_p = (real_T (*)[2])ssGetOutputPortSignal(chartInstance->S, 2);
  c3_b_R_po = (real_T (*)[4])ssGetInputPortSignal(chartInstance->S, 2);
  c3_b_Theta_wp_c = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c3_b_Dis_Path_o = (real_T (*)[2])ssGetInputPortSignal(chartInstance->S, 1);
  c3_g_x = (real_T (*)[7])ssGetInputPortSignal(chartInstance->S, 0);
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 2U, chartInstance->c3_sfEvent);
  c3_hoistedGlobal = chartInstance->c3_Delta_e;
  for (c3_i6 = 0; c3_i6 < 7; c3_i6++) {
    c3_x[c3_i6] = (*c3_g_x)[c3_i6];
  }

  for (c3_i7 = 0; c3_i7 < 2; c3_i7++) {
    c3_Dis_Path_o[c3_i7] = (*c3_b_Dis_Path_o)[c3_i7];
  }

  for (c3_i8 = 0; c3_i8 < 4; c3_i8++) {
    c3_R_po[c3_i8] = (*c3_b_R_po)[c3_i8];
  }

  c3_b_Delta_e = c3_hoistedGlobal;
  sf_debug_symbol_scope_push_eml(0U, 9U, 9U, c3_debug_family_names,
    c3_debug_family_var_map);
  sf_debug_symbol_scope_add_eml_importable(c3_Dis_Ship_o, 0U, c3_sf_marshallOut,
    c3_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c3_nargin, 1U, c3_b_sf_marshallOut,
    c3_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c3_nargout, 2U, c3_b_sf_marshallOut,
    c3_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml(c3_x, 3U, c3_d_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(c3_Dis_Path_o, 4U, c3_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(c3_R_po, 5U, c3_c_sf_marshallOut);
  sf_debug_symbol_scope_add_eml_importable(&c3_b_Delta_e, 6U,
    c3_b_sf_marshallOut, c3_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c3_Theta_wp_c, 7U,
    c3_b_sf_marshallOut, c3_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(c3_Dis_PS_p, 8U, c3_sf_marshallOut,
    c3_sf_marshallIn);
  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 3);
  c3_b_x[0] = c3_x[3];
  c3_b_x[1] = c3_x[4];
  for (c3_i9 = 0; c3_i9 < 2; c3_i9++) {
    c3_Dis_Ship_o[c3_i9] = c3_b_x[c3_i9];
  }

  _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 5);
  for (c3_i10 = 0; c3_i10 < 4; c3_i10++) {
    c3_a[c3_i10] = c3_R_po[c3_i10];
  }

  for (c3_i11 = 0; c3_i11 < 2; c3_i11++) {
    c3_b[c3_i11] = c3_Dis_Ship_o[c3_i11] - c3_Dis_Path_o[c3_i11];
  }

  c3_eml_scalar_eg(chartInstance);
  c3_eml_scalar_eg(chartInstance);
  for (c3_i12 = 0; c3_i12 < 2; c3_i12++) {
    c3_Dis_PS_p[c3_i12] = 0.0;
  }

  for (c3_i13 = 0; c3_i13 < 2; c3_i13++) {
    c3_Dis_PS_p[c3_i13] = 0.0;
  }

  for (c3_i14 = 0; c3_i14 < 2; c3_i14++) {
    c3_C[c3_i14] = c3_Dis_PS_p[c3_i14];
  }

  for (c3_i15 = 0; c3_i15 < 2; c3_i15++) {
    c3_Dis_PS_p[c3_i15] = c3_C[c3_i15];
  }

  for (c3_i16 = 0; c3_i16 < 2; c3_i16++) {
    c3_C[c3_i16] = c3_Dis_PS_p[c3_i16];
  }

  for (c3_i17 = 0; c3_i17 < 2; c3_i17++) {
    c3_Dis_PS_p[c3_i17] = c3_C[c3_i17];
  }

  for (c3_i18 = 0; c3_i18 < 2; c3_i18++) {
    c3_Dis_PS_p[c3_i18] = 0.0;
    c3_i19 = 0;
    for (c3_i20 = 0; c3_i20 < 2; c3_i20++) {
      c3_Dis_PS_p[c3_i18] += c3_a[c3_i19 + c3_i18] * c3_b[c3_i20];
      c3_i19 += 2;
    }
  }

  sf_mex_printf("%s =\\n", "Dis_PS_p");
  for (c3_i21 = 0; c3_i21 < 2; c3_i21++) {
    c3_u[c3_i21] = c3_Dis_PS_p[c3_i21];
  }

  c3_y = NULL;
  sf_mex_assign(&c3_y, sf_mex_create("y", c3_u, 0, 0U, 1U, 0U, 1, 2), FALSE);
  sf_mex_call_debug("disp", 0U, 1U, 14, c3_y);
  _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 6);
  c3_A = -c3_Dis_PS_p[1];
  c3_B = c3_b_Delta_e;
  c3_c_x = c3_A;
  c3_b_y = c3_B;
  c3_d_x = c3_c_x;
  c3_c_y = c3_b_y;
  c3_d_y = c3_d_x / c3_c_y;
  c3_e_x = c3_d_y;
  c3_Theta_wp_c = c3_e_x;
  c3_f_x = c3_Theta_wp_c;
  c3_Theta_wp_c = c3_f_x;
  c3_Theta_wp_c = muDoubleScalarAtan(c3_Theta_wp_c);
  _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, -6);
  sf_debug_symbol_scope_pop();
  *c3_b_Theta_wp_c = c3_Theta_wp_c;
  for (c3_i22 = 0; c3_i22 < 2; c3_i22++) {
    (*c3_b_Dis_PS_p)[c3_i22] = c3_Dis_PS_p[c3_i22];
  }

  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 2U, chartInstance->c3_sfEvent);
}

static void initSimStructsc3_test(SFc3_testInstanceStruct *chartInstance)
{
}

static void init_script_number_translation(uint32_T c3_machineNumber, uint32_T
  c3_chartNumber)
{
}

static const mxArray *c3_sf_marshallOut(void *chartInstanceVoid, void *c3_inData)
{
  const mxArray *c3_mxArrayOutData = NULL;
  int32_T c3_i23;
  real_T c3_b_inData[2];
  int32_T c3_i24;
  real_T c3_u[2];
  const mxArray *c3_y = NULL;
  SFc3_testInstanceStruct *chartInstance;
  chartInstance = (SFc3_testInstanceStruct *)chartInstanceVoid;
  c3_mxArrayOutData = NULL;
  for (c3_i23 = 0; c3_i23 < 2; c3_i23++) {
    c3_b_inData[c3_i23] = (*(real_T (*)[2])c3_inData)[c3_i23];
  }

  for (c3_i24 = 0; c3_i24 < 2; c3_i24++) {
    c3_u[c3_i24] = c3_b_inData[c3_i24];
  }

  c3_y = NULL;
  sf_mex_assign(&c3_y, sf_mex_create("y", c3_u, 0, 0U, 1U, 0U, 1, 2), FALSE);
  sf_mex_assign(&c3_mxArrayOutData, c3_y, FALSE);
  return c3_mxArrayOutData;
}

static void c3_emlrt_marshallIn(SFc3_testInstanceStruct *chartInstance, const
  mxArray *c3_Dis_PS_p, const char_T *c3_identifier, real_T c3_y[2])
{
  emlrtMsgIdentifier c3_thisId;
  c3_thisId.fIdentifier = c3_identifier;
  c3_thisId.fParent = NULL;
  c3_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c3_Dis_PS_p), &c3_thisId, c3_y);
  sf_mex_destroy(&c3_Dis_PS_p);
}

static void c3_b_emlrt_marshallIn(SFc3_testInstanceStruct *chartInstance, const
  mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId, real_T c3_y[2])
{
  real_T c3_dv1[2];
  int32_T c3_i25;
  sf_mex_import(c3_parentId, sf_mex_dup(c3_u), c3_dv1, 1, 0, 0U, 1, 0U, 1, 2);
  for (c3_i25 = 0; c3_i25 < 2; c3_i25++) {
    c3_y[c3_i25] = c3_dv1[c3_i25];
  }

  sf_mex_destroy(&c3_u);
}

static void c3_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, void *c3_outData)
{
  const mxArray *c3_Dis_PS_p;
  const char_T *c3_identifier;
  emlrtMsgIdentifier c3_thisId;
  real_T c3_y[2];
  int32_T c3_i26;
  SFc3_testInstanceStruct *chartInstance;
  chartInstance = (SFc3_testInstanceStruct *)chartInstanceVoid;
  c3_Dis_PS_p = sf_mex_dup(c3_mxArrayInData);
  c3_identifier = c3_varName;
  c3_thisId.fIdentifier = c3_identifier;
  c3_thisId.fParent = NULL;
  c3_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c3_Dis_PS_p), &c3_thisId, c3_y);
  sf_mex_destroy(&c3_Dis_PS_p);
  for (c3_i26 = 0; c3_i26 < 2; c3_i26++) {
    (*(real_T (*)[2])c3_outData)[c3_i26] = c3_y[c3_i26];
  }

  sf_mex_destroy(&c3_mxArrayInData);
}

static const mxArray *c3_b_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData)
{
  const mxArray *c3_mxArrayOutData = NULL;
  real_T c3_u;
  const mxArray *c3_y = NULL;
  SFc3_testInstanceStruct *chartInstance;
  chartInstance = (SFc3_testInstanceStruct *)chartInstanceVoid;
  c3_mxArrayOutData = NULL;
  c3_u = *(real_T *)c3_inData;
  c3_y = NULL;
  sf_mex_assign(&c3_y, sf_mex_create("y", &c3_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c3_mxArrayOutData, c3_y, FALSE);
  return c3_mxArrayOutData;
}

static real_T c3_c_emlrt_marshallIn(SFc3_testInstanceStruct *chartInstance,
  const mxArray *c3_Theta_wp_c, const char_T *c3_identifier)
{
  real_T c3_y;
  emlrtMsgIdentifier c3_thisId;
  c3_thisId.fIdentifier = c3_identifier;
  c3_thisId.fParent = NULL;
  c3_y = c3_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c3_Theta_wp_c),
    &c3_thisId);
  sf_mex_destroy(&c3_Theta_wp_c);
  return c3_y;
}

static real_T c3_d_emlrt_marshallIn(SFc3_testInstanceStruct *chartInstance,
  const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId)
{
  real_T c3_y;
  real_T c3_d1;
  sf_mex_import(c3_parentId, sf_mex_dup(c3_u), &c3_d1, 1, 0, 0U, 0, 0U, 0);
  c3_y = c3_d1;
  sf_mex_destroy(&c3_u);
  return c3_y;
}

static void c3_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, void *c3_outData)
{
  const mxArray *c3_Theta_wp_c;
  const char_T *c3_identifier;
  emlrtMsgIdentifier c3_thisId;
  real_T c3_y;
  SFc3_testInstanceStruct *chartInstance;
  chartInstance = (SFc3_testInstanceStruct *)chartInstanceVoid;
  c3_Theta_wp_c = sf_mex_dup(c3_mxArrayInData);
  c3_identifier = c3_varName;
  c3_thisId.fIdentifier = c3_identifier;
  c3_thisId.fParent = NULL;
  c3_y = c3_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c3_Theta_wp_c),
    &c3_thisId);
  sf_mex_destroy(&c3_Theta_wp_c);
  *(real_T *)c3_outData = c3_y;
  sf_mex_destroy(&c3_mxArrayInData);
}

static const mxArray *c3_c_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData)
{
  const mxArray *c3_mxArrayOutData = NULL;
  int32_T c3_i27;
  int32_T c3_i28;
  int32_T c3_i29;
  real_T c3_b_inData[4];
  int32_T c3_i30;
  int32_T c3_i31;
  int32_T c3_i32;
  real_T c3_u[4];
  const mxArray *c3_y = NULL;
  SFc3_testInstanceStruct *chartInstance;
  chartInstance = (SFc3_testInstanceStruct *)chartInstanceVoid;
  c3_mxArrayOutData = NULL;
  c3_i27 = 0;
  for (c3_i28 = 0; c3_i28 < 2; c3_i28++) {
    for (c3_i29 = 0; c3_i29 < 2; c3_i29++) {
      c3_b_inData[c3_i29 + c3_i27] = (*(real_T (*)[4])c3_inData)[c3_i29 + c3_i27];
    }

    c3_i27 += 2;
  }

  c3_i30 = 0;
  for (c3_i31 = 0; c3_i31 < 2; c3_i31++) {
    for (c3_i32 = 0; c3_i32 < 2; c3_i32++) {
      c3_u[c3_i32 + c3_i30] = c3_b_inData[c3_i32 + c3_i30];
    }

    c3_i30 += 2;
  }

  c3_y = NULL;
  sf_mex_assign(&c3_y, sf_mex_create("y", c3_u, 0, 0U, 1U, 0U, 2, 2, 2), FALSE);
  sf_mex_assign(&c3_mxArrayOutData, c3_y, FALSE);
  return c3_mxArrayOutData;
}

static const mxArray *c3_d_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData)
{
  const mxArray *c3_mxArrayOutData = NULL;
  int32_T c3_i33;
  real_T c3_b_inData[7];
  int32_T c3_i34;
  real_T c3_u[7];
  const mxArray *c3_y = NULL;
  SFc3_testInstanceStruct *chartInstance;
  chartInstance = (SFc3_testInstanceStruct *)chartInstanceVoid;
  c3_mxArrayOutData = NULL;
  for (c3_i33 = 0; c3_i33 < 7; c3_i33++) {
    c3_b_inData[c3_i33] = (*(real_T (*)[7])c3_inData)[c3_i33];
  }

  for (c3_i34 = 0; c3_i34 < 7; c3_i34++) {
    c3_u[c3_i34] = c3_b_inData[c3_i34];
  }

  c3_y = NULL;
  sf_mex_assign(&c3_y, sf_mex_create("y", c3_u, 0, 0U, 1U, 0U, 1, 7), FALSE);
  sf_mex_assign(&c3_mxArrayOutData, c3_y, FALSE);
  return c3_mxArrayOutData;
}

const mxArray *sf_c3_test_get_eml_resolved_functions_info(void)
{
  const mxArray *c3_nameCaptureInfo;
  c3_ResolvedFunctionInfo c3_info[14];
  const mxArray *c3_m0 = NULL;
  int32_T c3_i35;
  c3_ResolvedFunctionInfo *c3_r0;
  c3_nameCaptureInfo = NULL;
  c3_nameCaptureInfo = NULL;
  c3_info_helper(c3_info);
  sf_mex_assign(&c3_m0, sf_mex_createstruct("nameCaptureInfo", 1, 14), FALSE);
  for (c3_i35 = 0; c3_i35 < 14; c3_i35++) {
    c3_r0 = &c3_info[c3_i35];
    sf_mex_addfield(c3_m0, sf_mex_create("nameCaptureInfo", c3_r0->context, 15,
      0U, 0U, 0U, 2, 1, strlen(c3_r0->context)), "context", "nameCaptureInfo",
                    c3_i35);
    sf_mex_addfield(c3_m0, sf_mex_create("nameCaptureInfo", c3_r0->name, 15, 0U,
      0U, 0U, 2, 1, strlen(c3_r0->name)), "name", "nameCaptureInfo", c3_i35);
    sf_mex_addfield(c3_m0, sf_mex_create("nameCaptureInfo", c3_r0->dominantType,
      15, 0U, 0U, 0U, 2, 1, strlen(c3_r0->dominantType)), "dominantType",
                    "nameCaptureInfo", c3_i35);
    sf_mex_addfield(c3_m0, sf_mex_create("nameCaptureInfo", c3_r0->resolved, 15,
      0U, 0U, 0U, 2, 1, strlen(c3_r0->resolved)), "resolved", "nameCaptureInfo",
                    c3_i35);
    sf_mex_addfield(c3_m0, sf_mex_create("nameCaptureInfo", &c3_r0->fileTimeLo,
      7, 0U, 0U, 0U, 0), "fileTimeLo", "nameCaptureInfo", c3_i35);
    sf_mex_addfield(c3_m0, sf_mex_create("nameCaptureInfo", &c3_r0->fileTimeHi,
      7, 0U, 0U, 0U, 0), "fileTimeHi", "nameCaptureInfo", c3_i35);
    sf_mex_addfield(c3_m0, sf_mex_create("nameCaptureInfo", &c3_r0->mFileTimeLo,
      7, 0U, 0U, 0U, 0), "mFileTimeLo", "nameCaptureInfo", c3_i35);
    sf_mex_addfield(c3_m0, sf_mex_create("nameCaptureInfo", &c3_r0->mFileTimeHi,
      7, 0U, 0U, 0U, 0), "mFileTimeHi", "nameCaptureInfo", c3_i35);
  }

  sf_mex_assign(&c3_nameCaptureInfo, c3_m0, FALSE);
  sf_mex_emlrtNameCapturePostProcessR2012a(&c3_nameCaptureInfo);
  return c3_nameCaptureInfo;
}

static void c3_info_helper(c3_ResolvedFunctionInfo c3_info[14])
{
  c3_info[0].context = "";
  c3_info[0].name = "mtimes";
  c3_info[0].dominantType = "double";
  c3_info[0].resolved = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c3_info[0].fileTimeLo = 1289494492U;
  c3_info[0].fileTimeHi = 0U;
  c3_info[0].mFileTimeLo = 0U;
  c3_info[0].mFileTimeHi = 0U;
  c3_info[1].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c3_info[1].name = "eml_index_class";
  c3_info[1].dominantType = "";
  c3_info[1].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c3_info[1].fileTimeLo = 1323145378U;
  c3_info[1].fileTimeHi = 0U;
  c3_info[1].mFileTimeLo = 0U;
  c3_info[1].mFileTimeHi = 0U;
  c3_info[2].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c3_info[2].name = "eml_scalar_eg";
  c3_info[2].dominantType = "double";
  c3_info[2].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m";
  c3_info[2].fileTimeLo = 1286797196U;
  c3_info[2].fileTimeHi = 0U;
  c3_info[2].mFileTimeLo = 0U;
  c3_info[2].mFileTimeHi = 0U;
  c3_info[3].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c3_info[3].name = "eml_xgemm";
  c3_info[3].dominantType = "char";
  c3_info[3].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xgemm.m";
  c3_info[3].fileTimeLo = 1299051572U;
  c3_info[3].fileTimeHi = 0U;
  c3_info[3].mFileTimeLo = 0U;
  c3_info[3].mFileTimeHi = 0U;
  c3_info[4].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xgemm.m";
  c3_info[4].name = "eml_blas_inline";
  c3_info[4].dominantType = "";
  c3_info[4].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_blas_inline.m";
  c3_info[4].fileTimeLo = 1299051568U;
  c3_info[4].fileTimeHi = 0U;
  c3_info[4].mFileTimeLo = 0U;
  c3_info[4].mFileTimeHi = 0U;
  c3_info[5].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xgemm.m!below_threshold";
  c3_info[5].name = "mtimes";
  c3_info[5].dominantType = "double";
  c3_info[5].resolved = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c3_info[5].fileTimeLo = 1289494492U;
  c3_info[5].fileTimeHi = 0U;
  c3_info[5].mFileTimeLo = 0U;
  c3_info[5].mFileTimeHi = 0U;
  c3_info[6].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xgemm.m";
  c3_info[6].name = "eml_index_class";
  c3_info[6].dominantType = "";
  c3_info[6].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c3_info[6].fileTimeLo = 1323145378U;
  c3_info[6].fileTimeHi = 0U;
  c3_info[6].mFileTimeLo = 0U;
  c3_info[6].mFileTimeHi = 0U;
  c3_info[7].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xgemm.m";
  c3_info[7].name = "eml_scalar_eg";
  c3_info[7].dominantType = "double";
  c3_info[7].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m";
  c3_info[7].fileTimeLo = 1286797196U;
  c3_info[7].fileTimeHi = 0U;
  c3_info[7].mFileTimeLo = 0U;
  c3_info[7].mFileTimeHi = 0U;
  c3_info[8].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xgemm.m";
  c3_info[8].name = "eml_refblas_xgemm";
  c3_info[8].dominantType = "char";
  c3_info[8].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xgemm.m";
  c3_info[8].fileTimeLo = 1299051574U;
  c3_info[8].fileTimeHi = 0U;
  c3_info[8].mFileTimeLo = 0U;
  c3_info[8].mFileTimeHi = 0U;
  c3_info[9].context = "";
  c3_info[9].name = "mrdivide";
  c3_info[9].dominantType = "double";
  c3_info[9].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p";
  c3_info[9].fileTimeLo = 1342789344U;
  c3_info[9].fileTimeHi = 0U;
  c3_info[9].mFileTimeLo = 1319708366U;
  c3_info[9].mFileTimeHi = 0U;
  c3_info[10].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p";
  c3_info[10].name = "rdivide";
  c3_info[10].dominantType = "double";
  c3_info[10].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m";
  c3_info[10].fileTimeLo = 1286797244U;
  c3_info[10].fileTimeHi = 0U;
  c3_info[10].mFileTimeLo = 0U;
  c3_info[10].mFileTimeHi = 0U;
  c3_info[11].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m";
  c3_info[11].name = "eml_div";
  c3_info[11].dominantType = "double";
  c3_info[11].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_div.m";
  c3_info[11].fileTimeLo = 1313326210U;
  c3_info[11].fileTimeHi = 0U;
  c3_info[11].mFileTimeLo = 0U;
  c3_info[11].mFileTimeHi = 0U;
  c3_info[12].context = "";
  c3_info[12].name = "atan";
  c3_info[12].dominantType = "double";
  c3_info[12].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/atan.m";
  c3_info[12].fileTimeLo = 1305296398U;
  c3_info[12].fileTimeHi = 0U;
  c3_info[12].mFileTimeLo = 0U;
  c3_info[12].mFileTimeHi = 0U;
  c3_info[13].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/atan.m";
  c3_info[13].name = "eml_scalar_atan";
  c3_info[13].dominantType = "double";
  c3_info[13].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_atan.m";
  c3_info[13].fileTimeLo = 1286797118U;
  c3_info[13].fileTimeHi = 0U;
  c3_info[13].mFileTimeLo = 0U;
  c3_info[13].mFileTimeHi = 0U;
}

static void c3_eml_scalar_eg(SFc3_testInstanceStruct *chartInstance)
{
}

static const mxArray *c3_e_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData)
{
  const mxArray *c3_mxArrayOutData = NULL;
  int32_T c3_u;
  const mxArray *c3_y = NULL;
  SFc3_testInstanceStruct *chartInstance;
  chartInstance = (SFc3_testInstanceStruct *)chartInstanceVoid;
  c3_mxArrayOutData = NULL;
  c3_u = *(int32_T *)c3_inData;
  c3_y = NULL;
  sf_mex_assign(&c3_y, sf_mex_create("y", &c3_u, 6, 0U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c3_mxArrayOutData, c3_y, FALSE);
  return c3_mxArrayOutData;
}

static int32_T c3_e_emlrt_marshallIn(SFc3_testInstanceStruct *chartInstance,
  const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId)
{
  int32_T c3_y;
  int32_T c3_i36;
  sf_mex_import(c3_parentId, sf_mex_dup(c3_u), &c3_i36, 1, 6, 0U, 0, 0U, 0);
  c3_y = c3_i36;
  sf_mex_destroy(&c3_u);
  return c3_y;
}

static void c3_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, void *c3_outData)
{
  const mxArray *c3_b_sfEvent;
  const char_T *c3_identifier;
  emlrtMsgIdentifier c3_thisId;
  int32_T c3_y;
  SFc3_testInstanceStruct *chartInstance;
  chartInstance = (SFc3_testInstanceStruct *)chartInstanceVoid;
  c3_b_sfEvent = sf_mex_dup(c3_mxArrayInData);
  c3_identifier = c3_varName;
  c3_thisId.fIdentifier = c3_identifier;
  c3_thisId.fParent = NULL;
  c3_y = c3_e_emlrt_marshallIn(chartInstance, sf_mex_dup(c3_b_sfEvent),
    &c3_thisId);
  sf_mex_destroy(&c3_b_sfEvent);
  *(int32_T *)c3_outData = c3_y;
  sf_mex_destroy(&c3_mxArrayInData);
}

static uint8_T c3_f_emlrt_marshallIn(SFc3_testInstanceStruct *chartInstance,
  const mxArray *c3_b_is_active_c3_test, const char_T *c3_identifier)
{
  uint8_T c3_y;
  emlrtMsgIdentifier c3_thisId;
  c3_thisId.fIdentifier = c3_identifier;
  c3_thisId.fParent = NULL;
  c3_y = c3_g_emlrt_marshallIn(chartInstance, sf_mex_dup(c3_b_is_active_c3_test),
    &c3_thisId);
  sf_mex_destroy(&c3_b_is_active_c3_test);
  return c3_y;
}

static uint8_T c3_g_emlrt_marshallIn(SFc3_testInstanceStruct *chartInstance,
  const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId)
{
  uint8_T c3_y;
  uint8_T c3_u0;
  sf_mex_import(c3_parentId, sf_mex_dup(c3_u), &c3_u0, 1, 3, 0U, 0, 0U, 0);
  c3_y = c3_u0;
  sf_mex_destroy(&c3_u);
  return c3_y;
}

static void init_dsm_address_info(SFc3_testInstanceStruct *chartInstance)
{
}

/* SFunction Glue Code */
void sf_c3_test_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(2071759302U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(4165852903U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(3990835312U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(3042528114U);
}

mxArray *sf_c3_test_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1,1,5,
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateString("Yg8CWJuMFyLJIfAsy1LNGH");
    mxSetField(mxAutoinheritanceInfo,0,"checksum",mxChecksum);
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
      pr[0] = (double)(2);
      pr[1] = (double)(2);
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
    mxSetField(mxAutoinheritanceInfo,0,"outputs",mxData);
  }

  {
    mxSetField(mxAutoinheritanceInfo,0,"locals",mxCreateDoubleMatrix(0,0,mxREAL));
  }

  return(mxAutoinheritanceInfo);
}

static const mxArray *sf_get_sim_state_info_c3_test(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x3'type','srcId','name','auxInfo'{{M[1],M[10],T\"Dis_PS_p\",},{M[1],M[5],T\"Theta_wp_c\",},{M[8],M[0],T\"is_active_c3_test\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 3, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c3_test_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc3_testInstanceStruct *chartInstance;
    chartInstance = (SFc3_testInstanceStruct *) ((ChartInfoStruct *)
      (ssGetUserData(S)))->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart(_testMachineNumber_,
          3,
          1,
          1,
          6,
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
          _SFD_SET_DATA_PROPS(0,1,1,0,"x");
          _SFD_SET_DATA_PROPS(1,1,1,0,"Dis_Path_o");
          _SFD_SET_DATA_PROPS(2,2,0,1,"Theta_wp_c");
          _SFD_SET_DATA_PROPS(3,1,1,0,"R_po");
          _SFD_SET_DATA_PROPS(4,2,0,1,"Dis_PS_p");
          _SFD_SET_DATA_PROPS(5,10,0,0,"Delta_e");
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
        _SFD_CV_INIT_EML_FCN(0,0,"eML_blk_kernel",0,-1,249);
        _SFD_TRANS_COV_WTS(0,0,0,1,0);
        if (chartAlreadyPresent==0) {
          _SFD_TRANS_COV_MAPS(0,
                              0,NULL,NULL,
                              0,NULL,NULL,
                              1,NULL,NULL,
                              0,NULL,NULL);
        }

        {
          unsigned int dimVector[1];
          dimVector[0]= 7;
          _SFD_SET_DATA_COMPILED_PROPS(0,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c3_d_sf_marshallOut,(MexInFcnForType)NULL);
        }

        {
          unsigned int dimVector[1];
          dimVector[0]= 2;
          _SFD_SET_DATA_COMPILED_PROPS(1,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c3_sf_marshallOut,(MexInFcnForType)NULL);
        }

        _SFD_SET_DATA_COMPILED_PROPS(2,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c3_b_sf_marshallOut,(MexInFcnForType)c3_b_sf_marshallIn);

        {
          unsigned int dimVector[2];
          dimVector[0]= 2;
          dimVector[1]= 2;
          _SFD_SET_DATA_COMPILED_PROPS(3,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c3_c_sf_marshallOut,(MexInFcnForType)NULL);
        }

        {
          unsigned int dimVector[1];
          dimVector[0]= 2;
          _SFD_SET_DATA_COMPILED_PROPS(4,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c3_sf_marshallOut,(MexInFcnForType)
            c3_sf_marshallIn);
        }

        _SFD_SET_DATA_COMPILED_PROPS(5,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c3_b_sf_marshallOut,(MexInFcnForType)c3_b_sf_marshallIn);

        {
          real_T *c3_Theta_wp_c;
          real_T (*c3_x)[7];
          real_T (*c3_Dis_Path_o)[2];
          real_T (*c3_R_po)[4];
          real_T (*c3_Dis_PS_p)[2];
          c3_Dis_PS_p = (real_T (*)[2])ssGetOutputPortSignal(chartInstance->S, 2);
          c3_R_po = (real_T (*)[4])ssGetInputPortSignal(chartInstance->S, 2);
          c3_Theta_wp_c = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
          c3_Dis_Path_o = (real_T (*)[2])ssGetInputPortSignal(chartInstance->S,
            1);
          c3_x = (real_T (*)[7])ssGetInputPortSignal(chartInstance->S, 0);
          _SFD_SET_DATA_VALUE_PTR(0U, *c3_x);
          _SFD_SET_DATA_VALUE_PTR(1U, *c3_Dis_Path_o);
          _SFD_SET_DATA_VALUE_PTR(2U, c3_Theta_wp_c);
          _SFD_SET_DATA_VALUE_PTR(3U, *c3_R_po);
          _SFD_SET_DATA_VALUE_PTR(4U, *c3_Dis_PS_p);
          _SFD_SET_DATA_VALUE_PTR(5U, &chartInstance->c3_Delta_e);
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
  return "uCBFUDUKSRule8d3dniZED";
}

static void sf_opaque_initialize_c3_test(void *chartInstanceVar)
{
  chart_debug_initialization(((SFc3_testInstanceStruct*) chartInstanceVar)->S,0);
  initialize_params_c3_test((SFc3_testInstanceStruct*) chartInstanceVar);
  initialize_c3_test((SFc3_testInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_enable_c3_test(void *chartInstanceVar)
{
  enable_c3_test((SFc3_testInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_disable_c3_test(void *chartInstanceVar)
{
  disable_c3_test((SFc3_testInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_gateway_c3_test(void *chartInstanceVar)
{
  sf_c3_test((SFc3_testInstanceStruct*) chartInstanceVar);
}

extern const mxArray* sf_internal_get_sim_state_c3_test(SimStruct* S)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_raw2high");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = (mxArray*) get_sim_state_c3_test((SFc3_testInstanceStruct*)
    chartInfo->chartInstance);         /* raw sim ctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c3_test();/* state var info */
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

extern void sf_internal_set_sim_state_c3_test(SimStruct* S, const mxArray *st)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_high2raw");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = mxDuplicateArray(st);      /* high level simctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c3_test();/* state var info */
  mxError = sf_mex_call_matlab(1, plhs, 4, prhs, "sfprivate");
  mxDestroyArray(prhs[0]);
  mxDestroyArray(prhs[1]);
  mxDestroyArray(prhs[2]);
  mxDestroyArray(prhs[3]);
  if (mxError || plhs[0] == NULL) {
    sf_mex_error_message("Stateflow Internal Error: \nError calling 'chart_simctx_high2raw'.\n");
  }

  set_sim_state_c3_test((SFc3_testInstanceStruct*)chartInfo->chartInstance,
                        mxDuplicateArray(plhs[0]));
  mxDestroyArray(plhs[0]);
}

static const mxArray* sf_opaque_get_sim_state_c3_test(SimStruct* S)
{
  return sf_internal_get_sim_state_c3_test(S);
}

static void sf_opaque_set_sim_state_c3_test(SimStruct* S, const mxArray *st)
{
  sf_internal_set_sim_state_c3_test(S, st);
}

static void sf_opaque_terminate_c3_test(void *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc3_testInstanceStruct*) chartInstanceVar)->S;
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
    }

    finalize_c3_test((SFc3_testInstanceStruct*) chartInstanceVar);
    free((void *)chartInstanceVar);
    ssSetUserData(S,NULL);
  }

  unload_test_optimization_info();
}

static void sf_opaque_init_subchart_simstructs(void *chartInstanceVar)
{
  initSimStructsc3_test((SFc3_testInstanceStruct*) chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c3_test(SimStruct *S)
{
  int i;
  for (i=0;i<ssGetNumRunTimeParams(S);i++) {
    if (ssGetSFcnParamTunable(S,i)) {
      ssUpdateDlgParamAsRunTimeParam(S,i);
    }
  }

  if (sf_machine_global_initializer_called()) {
    initialize_params_c3_test((SFc3_testInstanceStruct*)(((ChartInfoStruct *)
      ssGetUserData(S))->chartInstance));
  }
}

static void mdlSetWorkWidths_c3_test(SimStruct *S)
{
  /* Actual parameters from chart:
     Delta_e
   */
  const char_T *rtParamNames[] = { "p1" };

  ssSetNumRunTimeParams(S,ssGetSFcnParamsCount(S));

  /* registration for Delta_e*/
  ssRegDlgParamAsRunTimeParam(S, 0, 0, rtParamNames[0], SS_DOUBLE);
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    mxArray *infoStruct = load_test_optimization_info();
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable(S,sf_get_instance_specialization(),infoStruct,
      3);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop(S,sf_get_instance_specialization(),
                infoStruct,3,"RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop(S,
      sf_get_instance_specialization(),infoStruct,3,
      "gatewayCannotBeInlinedMultipleTimes"));
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 1, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 2, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,sf_get_instance_specialization(),
        infoStruct,3,3);
      sf_mark_chart_reusable_outputs(S,sf_get_instance_specialization(),
        infoStruct,3,2);
    }

    sf_set_rtw_dwork_info(S,sf_get_instance_specialization(),infoStruct,3);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(3327135314U));
  ssSetChecksum1(S,(2624438668U));
  ssSetChecksum2(S,(3393410308U));
  ssSetChecksum3(S,(904698409U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
  ssSupportsMultipleExecInstances(S,1);
}

static void mdlRTW_c3_test(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c3_test(SimStruct *S)
{
  SFc3_testInstanceStruct *chartInstance;
  chartInstance = (SFc3_testInstanceStruct *)malloc(sizeof
    (SFc3_testInstanceStruct));
  memset(chartInstance, 0, sizeof(SFc3_testInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway = sf_opaque_gateway_c3_test;
  chartInstance->chartInfo.initializeChart = sf_opaque_initialize_c3_test;
  chartInstance->chartInfo.terminateChart = sf_opaque_terminate_c3_test;
  chartInstance->chartInfo.enableChart = sf_opaque_enable_c3_test;
  chartInstance->chartInfo.disableChart = sf_opaque_disable_c3_test;
  chartInstance->chartInfo.getSimState = sf_opaque_get_sim_state_c3_test;
  chartInstance->chartInfo.setSimState = sf_opaque_set_sim_state_c3_test;
  chartInstance->chartInfo.getSimStateInfo = sf_get_sim_state_info_c3_test;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c3_test;
  chartInstance->chartInfo.mdlStart = mdlStart_c3_test;
  chartInstance->chartInfo.mdlSetWorkWidths = mdlSetWorkWidths_c3_test;
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

void c3_test_method_dispatcher(SimStruct *S, int_T method, void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c3_test(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c3_test(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c3_test(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c3_test_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}

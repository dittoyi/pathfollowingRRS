/* Include files */

#include "blascompat32.h"
#include "test_sfun.h"
#include "c12_test.h"
#include "mwmathutil.h"
#define CHARTINSTANCE_CHARTNUMBER      (chartInstance->chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER   (chartInstance->instanceNumber)
#include "test_sfun_debug_macros.h"

/* Type Definitions */

/* Named Constants */
#define CALL_EVENT                     (-1)

/* Variable Declarations */

/* Variable Definitions */
static const char * c12_debug_family_names[7] = { "we", "we2", "nargin",
  "nargout", "Theta_wo", "Theta_po", "y" };

/* Function Declarations */
static void initialize_c12_test(SFc12_testInstanceStruct *chartInstance);
static void initialize_params_c12_test(SFc12_testInstanceStruct *chartInstance);
static void enable_c12_test(SFc12_testInstanceStruct *chartInstance);
static void disable_c12_test(SFc12_testInstanceStruct *chartInstance);
static void c12_update_debugger_state_c12_test(SFc12_testInstanceStruct
  *chartInstance);
static const mxArray *get_sim_state_c12_test(SFc12_testInstanceStruct
  *chartInstance);
static void set_sim_state_c12_test(SFc12_testInstanceStruct *chartInstance,
  const mxArray *c12_st);
static void finalize_c12_test(SFc12_testInstanceStruct *chartInstance);
static void sf_c12_test(SFc12_testInstanceStruct *chartInstance);
static void initSimStructsc12_test(SFc12_testInstanceStruct *chartInstance);
static void init_script_number_translation(uint32_T c12_machineNumber, uint32_T
  c12_chartNumber);
static const mxArray *c12_sf_marshallOut(void *chartInstanceVoid, void
  *c12_inData);
static real_T c12_emlrt_marshallIn(SFc12_testInstanceStruct *chartInstance,
  const mxArray *c12_y, const char_T *c12_identifier);
static real_T c12_b_emlrt_marshallIn(SFc12_testInstanceStruct *chartInstance,
  const mxArray *c12_u, const emlrtMsgIdentifier *c12_parentId);
static void c12_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c12_mxArrayInData, const char_T *c12_varName, void *c12_outData);
static void c12_info_helper(c12_ResolvedFunctionInfo c12_info[20]);
static void c12_eml_scalar_eg(SFc12_testInstanceStruct *chartInstance);
static const mxArray *c12_b_sf_marshallOut(void *chartInstanceVoid, void
  *c12_inData);
static int32_T c12_c_emlrt_marshallIn(SFc12_testInstanceStruct *chartInstance,
  const mxArray *c12_u, const emlrtMsgIdentifier *c12_parentId);
static void c12_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c12_mxArrayInData, const char_T *c12_varName, void *c12_outData);
static uint8_T c12_d_emlrt_marshallIn(SFc12_testInstanceStruct *chartInstance,
  const mxArray *c12_b_is_active_c12_test, const char_T *c12_identifier);
static uint8_T c12_e_emlrt_marshallIn(SFc12_testInstanceStruct *chartInstance,
  const mxArray *c12_u, const emlrtMsgIdentifier *c12_parentId);
static void init_dsm_address_info(SFc12_testInstanceStruct *chartInstance);

/* Function Definitions */
static void initialize_c12_test(SFc12_testInstanceStruct *chartInstance)
{
  chartInstance->c12_sfEvent = CALL_EVENT;
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  chartInstance->c12_is_active_c12_test = 0U;
}

static void initialize_params_c12_test(SFc12_testInstanceStruct *chartInstance)
{
}

static void enable_c12_test(SFc12_testInstanceStruct *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void disable_c12_test(SFc12_testInstanceStruct *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void c12_update_debugger_state_c12_test(SFc12_testInstanceStruct
  *chartInstance)
{
}

static const mxArray *get_sim_state_c12_test(SFc12_testInstanceStruct
  *chartInstance)
{
  const mxArray *c12_st;
  const mxArray *c12_y = NULL;
  real_T c12_hoistedGlobal;
  real_T c12_u;
  const mxArray *c12_b_y = NULL;
  uint8_T c12_b_hoistedGlobal;
  uint8_T c12_b_u;
  const mxArray *c12_c_y = NULL;
  real_T *c12_d_y;
  c12_d_y = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c12_st = NULL;
  c12_st = NULL;
  c12_y = NULL;
  sf_mex_assign(&c12_y, sf_mex_createcellarray(2), FALSE);
  c12_hoistedGlobal = *c12_d_y;
  c12_u = c12_hoistedGlobal;
  c12_b_y = NULL;
  sf_mex_assign(&c12_b_y, sf_mex_create("y", &c12_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c12_y, 0, c12_b_y);
  c12_b_hoistedGlobal = chartInstance->c12_is_active_c12_test;
  c12_b_u = c12_b_hoistedGlobal;
  c12_c_y = NULL;
  sf_mex_assign(&c12_c_y, sf_mex_create("y", &c12_b_u, 3, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c12_y, 1, c12_c_y);
  sf_mex_assign(&c12_st, c12_y, FALSE);
  return c12_st;
}

static void set_sim_state_c12_test(SFc12_testInstanceStruct *chartInstance,
  const mxArray *c12_st)
{
  const mxArray *c12_u;
  real_T *c12_y;
  c12_y = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  chartInstance->c12_doneDoubleBufferReInit = TRUE;
  c12_u = sf_mex_dup(c12_st);
  *c12_y = c12_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c12_u,
    0)), "y");
  chartInstance->c12_is_active_c12_test = c12_d_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c12_u, 1)), "is_active_c12_test");
  sf_mex_destroy(&c12_u);
  c12_update_debugger_state_c12_test(chartInstance);
  sf_mex_destroy(&c12_st);
}

static void finalize_c12_test(SFc12_testInstanceStruct *chartInstance)
{
}

static void sf_c12_test(SFc12_testInstanceStruct *chartInstance)
{
  real_T c12_hoistedGlobal;
  real_T c12_b_hoistedGlobal;
  real_T c12_Theta_wo;
  real_T c12_Theta_po;
  uint32_T c12_debug_family_var_map[7];
  real_T c12_we;
  real_T c12_we2;
  real_T c12_nargin = 2.0;
  real_T c12_nargout = 1.0;
  real_T c12_y;
  real_T c12_x;
  real_T c12_b_x;
  real_T c12_c_x;
  real_T c12_d_x;
  real_T c12_b_y;
  real_T c12_a;
  real_T c12_c_y;
  real_T c12_A;
  real_T c12_e_x;
  real_T c12_f_x;
  real_T c12_d_y;
  real_T c12_g_x;
  real_T c12_xk;
  real_T c12_h_x;
  real_T c12_i_x;
  real_T c12_j_x;
  real_T c12_r;
  real_T c12_b_a;
  real_T c12_b;
  real_T c12_e_y;
  real_T c12_b_A;
  real_T c12_k_x;
  real_T c12_l_x;
  real_T c12_f_y;
  real_T c12_c_a;
  real_T c12_m_x;
  real_T c12_n_x;
  real_T c12_c_A;
  real_T c12_o_x;
  real_T c12_p_x;
  real_T c12_g_y;
  real_T c12_d_a;
  real_T c12_b_b;
  real_T c12_h_y;
  real_T c12_q_x;
  real_T c12_r_x;
  real_T c12_d_A;
  real_T c12_s_x;
  real_T c12_t_x;
  real_T c12_i_y;
  real_T c12_e_a;
  real_T c12_c_b;
  real_T c12_j_y;
  real_T *c12_b_Theta_po;
  real_T *c12_b_Theta_wo;
  real_T *c12_k_y;
  c12_b_Theta_po = (real_T *)ssGetInputPortSignal(chartInstance->S, 1);
  c12_k_y = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c12_b_Theta_wo = (real_T *)ssGetInputPortSignal(chartInstance->S, 0);
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 11U, chartInstance->c12_sfEvent);
  _SFD_DATA_RANGE_CHECK(*c12_b_Theta_wo, 0U);
  _SFD_DATA_RANGE_CHECK(*c12_k_y, 1U);
  _SFD_DATA_RANGE_CHECK(*c12_b_Theta_po, 2U);
  chartInstance->c12_sfEvent = CALL_EVENT;
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 11U, chartInstance->c12_sfEvent);
  c12_hoistedGlobal = *c12_b_Theta_wo;
  c12_b_hoistedGlobal = *c12_b_Theta_po;
  c12_Theta_wo = c12_hoistedGlobal;
  c12_Theta_po = c12_b_hoistedGlobal;
  sf_debug_symbol_scope_push_eml(0U, 7U, 7U, c12_debug_family_names,
    c12_debug_family_var_map);
  sf_debug_symbol_scope_add_eml_importable(&c12_we, 0U, c12_sf_marshallOut,
    c12_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c12_we2, 1U, c12_sf_marshallOut,
    c12_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c12_nargin, 2U, c12_sf_marshallOut,
    c12_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c12_nargout, 3U, c12_sf_marshallOut,
    c12_sf_marshallIn);
  sf_debug_symbol_scope_add_eml(&c12_Theta_wo, 4U, c12_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c12_Theta_po, 5U, c12_sf_marshallOut);
  sf_debug_symbol_scope_add_eml_importable(&c12_y, 6U, c12_sf_marshallOut,
    c12_sf_marshallIn);
  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(0U, chartInstance->c12_sfEvent, 3);
  c12_x = c12_Theta_wo;
  c12_b_x = c12_x;
  c12_b_x = muDoubleScalarSign(c12_b_x);
  c12_c_x = c12_Theta_wo;
  c12_d_x = c12_c_x;
  c12_b_y = muDoubleScalarAbs(c12_d_x);
  c12_a = c12_b_y;
  c12_c_y = c12_a * 180.0;
  c12_A = c12_c_y;
  c12_e_x = c12_A;
  c12_f_x = c12_e_x;
  c12_d_y = c12_f_x / 3.1415926535897931;
  c12_g_x = c12_d_y;
  c12_eml_scalar_eg(chartInstance);
  c12_xk = c12_g_x;
  c12_h_x = c12_xk;
  c12_eml_scalar_eg(chartInstance);
  c12_i_x = c12_h_x / 360.0;
  c12_j_x = c12_i_x;
  c12_j_x = muDoubleScalarFloor(c12_j_x);
  c12_r = c12_h_x - c12_j_x * 360.0;
  c12_b_a = c12_b_x;
  c12_b = c12_r;
  c12_e_y = c12_b_a * c12_b;
  c12_b_A = c12_e_y;
  c12_k_x = c12_b_A;
  c12_l_x = c12_k_x;
  c12_f_y = c12_l_x / 180.0;
  c12_c_a = c12_f_y;
  c12_we = c12_c_a * 3.1415926535897931;
  _SFD_EML_CALL(0U, chartInstance->c12_sfEvent, 4);
  c12_we2 = c12_we - 6.2831853071795862;
  _SFD_EML_CALL(0U, chartInstance->c12_sfEvent, 5);
  c12_m_x = c12_Theta_po;
  c12_n_x = c12_m_x;
  c12_n_x = muDoubleScalarSign(c12_n_x);
  c12_c_A = 1.0 + c12_n_x;
  c12_o_x = c12_c_A;
  c12_p_x = c12_o_x;
  c12_g_y = c12_p_x / 2.0;
  c12_d_a = c12_g_y;
  c12_b_b = c12_we;
  c12_h_y = c12_d_a * c12_b_b;
  c12_q_x = c12_Theta_po;
  c12_r_x = c12_q_x;
  c12_r_x = muDoubleScalarSign(c12_r_x);
  c12_d_A = 1.0 - c12_r_x;
  c12_s_x = c12_d_A;
  c12_t_x = c12_s_x;
  c12_i_y = c12_t_x / 2.0;
  c12_e_a = c12_i_y;
  c12_c_b = c12_we2;
  c12_j_y = c12_e_a * c12_c_b;
  c12_y = c12_h_y + c12_j_y;
  _SFD_EML_CALL(0U, chartInstance->c12_sfEvent, -5);
  sf_debug_symbol_scope_pop();
  *c12_k_y = c12_y;
  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 11U, chartInstance->c12_sfEvent);
  sf_debug_check_for_state_inconsistency(_testMachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
}

static void initSimStructsc12_test(SFc12_testInstanceStruct *chartInstance)
{
}

static void init_script_number_translation(uint32_T c12_machineNumber, uint32_T
  c12_chartNumber)
{
}

static const mxArray *c12_sf_marshallOut(void *chartInstanceVoid, void
  *c12_inData)
{
  const mxArray *c12_mxArrayOutData = NULL;
  real_T c12_u;
  const mxArray *c12_y = NULL;
  SFc12_testInstanceStruct *chartInstance;
  chartInstance = (SFc12_testInstanceStruct *)chartInstanceVoid;
  c12_mxArrayOutData = NULL;
  c12_u = *(real_T *)c12_inData;
  c12_y = NULL;
  sf_mex_assign(&c12_y, sf_mex_create("y", &c12_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c12_mxArrayOutData, c12_y, FALSE);
  return c12_mxArrayOutData;
}

static real_T c12_emlrt_marshallIn(SFc12_testInstanceStruct *chartInstance,
  const mxArray *c12_y, const char_T *c12_identifier)
{
  real_T c12_b_y;
  emlrtMsgIdentifier c12_thisId;
  c12_thisId.fIdentifier = c12_identifier;
  c12_thisId.fParent = NULL;
  c12_b_y = c12_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c12_y), &c12_thisId);
  sf_mex_destroy(&c12_y);
  return c12_b_y;
}

static real_T c12_b_emlrt_marshallIn(SFc12_testInstanceStruct *chartInstance,
  const mxArray *c12_u, const emlrtMsgIdentifier *c12_parentId)
{
  real_T c12_y;
  real_T c12_d0;
  sf_mex_import(c12_parentId, sf_mex_dup(c12_u), &c12_d0, 1, 0, 0U, 0, 0U, 0);
  c12_y = c12_d0;
  sf_mex_destroy(&c12_u);
  return c12_y;
}

static void c12_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c12_mxArrayInData, const char_T *c12_varName, void *c12_outData)
{
  const mxArray *c12_y;
  const char_T *c12_identifier;
  emlrtMsgIdentifier c12_thisId;
  real_T c12_b_y;
  SFc12_testInstanceStruct *chartInstance;
  chartInstance = (SFc12_testInstanceStruct *)chartInstanceVoid;
  c12_y = sf_mex_dup(c12_mxArrayInData);
  c12_identifier = c12_varName;
  c12_thisId.fIdentifier = c12_identifier;
  c12_thisId.fParent = NULL;
  c12_b_y = c12_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c12_y), &c12_thisId);
  sf_mex_destroy(&c12_y);
  *(real_T *)c12_outData = c12_b_y;
  sf_mex_destroy(&c12_mxArrayInData);
}

const mxArray *sf_c12_test_get_eml_resolved_functions_info(void)
{
  const mxArray *c12_nameCaptureInfo;
  c12_ResolvedFunctionInfo c12_info[20];
  const mxArray *c12_m0 = NULL;
  int32_T c12_i0;
  c12_ResolvedFunctionInfo *c12_r0;
  c12_nameCaptureInfo = NULL;
  c12_nameCaptureInfo = NULL;
  c12_info_helper(c12_info);
  sf_mex_assign(&c12_m0, sf_mex_createstruct("nameCaptureInfo", 1, 20), FALSE);
  for (c12_i0 = 0; c12_i0 < 20; c12_i0++) {
    c12_r0 = &c12_info[c12_i0];
    sf_mex_addfield(c12_m0, sf_mex_create("nameCaptureInfo", c12_r0->context, 15,
      0U, 0U, 0U, 2, 1, strlen(c12_r0->context)), "context", "nameCaptureInfo",
                    c12_i0);
    sf_mex_addfield(c12_m0, sf_mex_create("nameCaptureInfo", c12_r0->name, 15,
      0U, 0U, 0U, 2, 1, strlen(c12_r0->name)), "name", "nameCaptureInfo", c12_i0);
    sf_mex_addfield(c12_m0, sf_mex_create("nameCaptureInfo",
      c12_r0->dominantType, 15, 0U, 0U, 0U, 2, 1, strlen(c12_r0->dominantType)),
                    "dominantType", "nameCaptureInfo", c12_i0);
    sf_mex_addfield(c12_m0, sf_mex_create("nameCaptureInfo", c12_r0->resolved,
      15, 0U, 0U, 0U, 2, 1, strlen(c12_r0->resolved)), "resolved",
                    "nameCaptureInfo", c12_i0);
    sf_mex_addfield(c12_m0, sf_mex_create("nameCaptureInfo", &c12_r0->fileTimeLo,
      7, 0U, 0U, 0U, 0), "fileTimeLo", "nameCaptureInfo", c12_i0);
    sf_mex_addfield(c12_m0, sf_mex_create("nameCaptureInfo", &c12_r0->fileTimeHi,
      7, 0U, 0U, 0U, 0), "fileTimeHi", "nameCaptureInfo", c12_i0);
    sf_mex_addfield(c12_m0, sf_mex_create("nameCaptureInfo",
      &c12_r0->mFileTimeLo, 7, 0U, 0U, 0U, 0), "mFileTimeLo", "nameCaptureInfo",
                    c12_i0);
    sf_mex_addfield(c12_m0, sf_mex_create("nameCaptureInfo",
      &c12_r0->mFileTimeHi, 7, 0U, 0U, 0U, 0), "mFileTimeHi", "nameCaptureInfo",
                    c12_i0);
  }

  sf_mex_assign(&c12_nameCaptureInfo, c12_m0, FALSE);
  sf_mex_emlrtNameCapturePostProcessR2012a(&c12_nameCaptureInfo);
  return c12_nameCaptureInfo;
}

static void c12_info_helper(c12_ResolvedFunctionInfo c12_info[20])
{
  c12_info[0].context = "";
  c12_info[0].name = "sign";
  c12_info[0].dominantType = "double";
  c12_info[0].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/sign.m";
  c12_info[0].fileTimeLo = 1286797150U;
  c12_info[0].fileTimeHi = 0U;
  c12_info[0].mFileTimeLo = 0U;
  c12_info[0].mFileTimeHi = 0U;
  c12_info[1].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/sign.m";
  c12_info[1].name = "eml_scalar_sign";
  c12_info[1].dominantType = "double";
  c12_info[1].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_sign.m";
  c12_info[1].fileTimeLo = 1307629638U;
  c12_info[1].fileTimeHi = 0U;
  c12_info[1].mFileTimeLo = 0U;
  c12_info[1].mFileTimeHi = 0U;
  c12_info[2].context = "";
  c12_info[2].name = "abs";
  c12_info[2].dominantType = "double";
  c12_info[2].resolved = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m";
  c12_info[2].fileTimeLo = 1286797094U;
  c12_info[2].fileTimeHi = 0U;
  c12_info[2].mFileTimeLo = 0U;
  c12_info[2].mFileTimeHi = 0U;
  c12_info[3].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m";
  c12_info[3].name = "eml_scalar_abs";
  c12_info[3].dominantType = "double";
  c12_info[3].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_abs.m";
  c12_info[3].fileTimeLo = 1286797112U;
  c12_info[3].fileTimeHi = 0U;
  c12_info[3].mFileTimeLo = 0U;
  c12_info[3].mFileTimeHi = 0U;
  c12_info[4].context = "";
  c12_info[4].name = "mtimes";
  c12_info[4].dominantType = "double";
  c12_info[4].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c12_info[4].fileTimeLo = 1289494492U;
  c12_info[4].fileTimeHi = 0U;
  c12_info[4].mFileTimeLo = 0U;
  c12_info[4].mFileTimeHi = 0U;
  c12_info[5].context = "";
  c12_info[5].name = "mrdivide";
  c12_info[5].dominantType = "double";
  c12_info[5].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p";
  c12_info[5].fileTimeLo = 1342789344U;
  c12_info[5].fileTimeHi = 0U;
  c12_info[5].mFileTimeLo = 1319708366U;
  c12_info[5].mFileTimeHi = 0U;
  c12_info[6].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p";
  c12_info[6].name = "rdivide";
  c12_info[6].dominantType = "double";
  c12_info[6].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m";
  c12_info[6].fileTimeLo = 1286797244U;
  c12_info[6].fileTimeHi = 0U;
  c12_info[6].mFileTimeLo = 0U;
  c12_info[6].mFileTimeHi = 0U;
  c12_info[7].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m";
  c12_info[7].name = "eml_div";
  c12_info[7].dominantType = "double";
  c12_info[7].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_div.m";
  c12_info[7].fileTimeLo = 1313326210U;
  c12_info[7].fileTimeHi = 0U;
  c12_info[7].mFileTimeLo = 0U;
  c12_info[7].mFileTimeHi = 0U;
  c12_info[8].context = "";
  c12_info[8].name = "mod";
  c12_info[8].dominantType = "double";
  c12_info[8].resolved = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/mod.m";
  c12_info[8].fileTimeLo = 1326702796U;
  c12_info[8].fileTimeHi = 0U;
  c12_info[8].mFileTimeLo = 0U;
  c12_info[8].mFileTimeHi = 0U;
  c12_info[9].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/mod.m";
  c12_info[9].name = "eml_scalar_eg";
  c12_info[9].dominantType = "double";
  c12_info[9].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m";
  c12_info[9].fileTimeLo = 1286797196U;
  c12_info[9].fileTimeHi = 0U;
  c12_info[9].mFileTimeLo = 0U;
  c12_info[9].mFileTimeHi = 0U;
  c12_info[10].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/mod.m";
  c12_info[10].name = "eml_scalexp_alloc";
  c12_info[10].dominantType = "double";
  c12_info[10].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalexp_alloc.m";
  c12_info[10].fileTimeLo = 1330583234U;
  c12_info[10].fileTimeHi = 0U;
  c12_info[10].mFileTimeLo = 0U;
  c12_info[10].mFileTimeHi = 0U;
  c12_info[11].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/mod.m!floatmod";
  c12_info[11].name = "eml_scalar_eg";
  c12_info[11].dominantType = "double";
  c12_info[11].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m";
  c12_info[11].fileTimeLo = 1286797196U;
  c12_info[11].fileTimeHi = 0U;
  c12_info[11].mFileTimeLo = 0U;
  c12_info[11].mFileTimeHi = 0U;
  c12_info[12].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/mod.m!floatmod";
  c12_info[12].name = "eml_scalar_floor";
  c12_info[12].dominantType = "double";
  c12_info[12].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_floor.m";
  c12_info[12].fileTimeLo = 1286797126U;
  c12_info[12].fileTimeHi = 0U;
  c12_info[12].mFileTimeLo = 0U;
  c12_info[12].mFileTimeHi = 0U;
  c12_info[13].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/mod.m!floatmod";
  c12_info[13].name = "eml_scalar_round";
  c12_info[13].dominantType = "double";
  c12_info[13].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_round.m";
  c12_info[13].fileTimeLo = 1307629638U;
  c12_info[13].fileTimeHi = 0U;
  c12_info[13].mFileTimeLo = 0U;
  c12_info[13].mFileTimeHi = 0U;
  c12_info[14].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/mod.m!floatmod";
  c12_info[14].name = "eml_scalar_abs";
  c12_info[14].dominantType = "double";
  c12_info[14].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_abs.m";
  c12_info[14].fileTimeLo = 1286797112U;
  c12_info[14].fileTimeHi = 0U;
  c12_info[14].mFileTimeLo = 0U;
  c12_info[14].mFileTimeHi = 0U;
  c12_info[15].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/mod.m!floatmod";
  c12_info[15].name = "eps";
  c12_info[15].dominantType = "char";
  c12_info[15].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/eps.m";
  c12_info[15].fileTimeLo = 1326702796U;
  c12_info[15].fileTimeHi = 0U;
  c12_info[15].mFileTimeLo = 0U;
  c12_info[15].mFileTimeHi = 0U;
  c12_info[16].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/eps.m";
  c12_info[16].name = "eml_is_float_class";
  c12_info[16].dominantType = "char";
  c12_info[16].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_is_float_class.m";
  c12_info[16].fileTimeLo = 1286797182U;
  c12_info[16].fileTimeHi = 0U;
  c12_info[16].mFileTimeLo = 0U;
  c12_info[16].mFileTimeHi = 0U;
  c12_info[17].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/eps.m";
  c12_info[17].name = "eml_eps";
  c12_info[17].dominantType = "char";
  c12_info[17].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_eps.m";
  c12_info[17].fileTimeLo = 1326702796U;
  c12_info[17].fileTimeHi = 0U;
  c12_info[17].mFileTimeLo = 0U;
  c12_info[17].mFileTimeHi = 0U;
  c12_info[18].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_eps.m";
  c12_info[18].name = "eml_float_model";
  c12_info[18].dominantType = "char";
  c12_info[18].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_float_model.m";
  c12_info[18].fileTimeLo = 1326702796U;
  c12_info[18].fileTimeHi = 0U;
  c12_info[18].mFileTimeLo = 0U;
  c12_info[18].mFileTimeHi = 0U;
  c12_info[19].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/mod.m!floatmod";
  c12_info[19].name = "mtimes";
  c12_info[19].dominantType = "double";
  c12_info[19].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c12_info[19].fileTimeLo = 1289494492U;
  c12_info[19].fileTimeHi = 0U;
  c12_info[19].mFileTimeLo = 0U;
  c12_info[19].mFileTimeHi = 0U;
}

static void c12_eml_scalar_eg(SFc12_testInstanceStruct *chartInstance)
{
}

static const mxArray *c12_b_sf_marshallOut(void *chartInstanceVoid, void
  *c12_inData)
{
  const mxArray *c12_mxArrayOutData = NULL;
  int32_T c12_u;
  const mxArray *c12_y = NULL;
  SFc12_testInstanceStruct *chartInstance;
  chartInstance = (SFc12_testInstanceStruct *)chartInstanceVoid;
  c12_mxArrayOutData = NULL;
  c12_u = *(int32_T *)c12_inData;
  c12_y = NULL;
  sf_mex_assign(&c12_y, sf_mex_create("y", &c12_u, 6, 0U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c12_mxArrayOutData, c12_y, FALSE);
  return c12_mxArrayOutData;
}

static int32_T c12_c_emlrt_marshallIn(SFc12_testInstanceStruct *chartInstance,
  const mxArray *c12_u, const emlrtMsgIdentifier *c12_parentId)
{
  int32_T c12_y;
  int32_T c12_i1;
  sf_mex_import(c12_parentId, sf_mex_dup(c12_u), &c12_i1, 1, 6, 0U, 0, 0U, 0);
  c12_y = c12_i1;
  sf_mex_destroy(&c12_u);
  return c12_y;
}

static void c12_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c12_mxArrayInData, const char_T *c12_varName, void *c12_outData)
{
  const mxArray *c12_b_sfEvent;
  const char_T *c12_identifier;
  emlrtMsgIdentifier c12_thisId;
  int32_T c12_y;
  SFc12_testInstanceStruct *chartInstance;
  chartInstance = (SFc12_testInstanceStruct *)chartInstanceVoid;
  c12_b_sfEvent = sf_mex_dup(c12_mxArrayInData);
  c12_identifier = c12_varName;
  c12_thisId.fIdentifier = c12_identifier;
  c12_thisId.fParent = NULL;
  c12_y = c12_c_emlrt_marshallIn(chartInstance, sf_mex_dup(c12_b_sfEvent),
    &c12_thisId);
  sf_mex_destroy(&c12_b_sfEvent);
  *(int32_T *)c12_outData = c12_y;
  sf_mex_destroy(&c12_mxArrayInData);
}

static uint8_T c12_d_emlrt_marshallIn(SFc12_testInstanceStruct *chartInstance,
  const mxArray *c12_b_is_active_c12_test, const char_T *c12_identifier)
{
  uint8_T c12_y;
  emlrtMsgIdentifier c12_thisId;
  c12_thisId.fIdentifier = c12_identifier;
  c12_thisId.fParent = NULL;
  c12_y = c12_e_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c12_b_is_active_c12_test), &c12_thisId);
  sf_mex_destroy(&c12_b_is_active_c12_test);
  return c12_y;
}

static uint8_T c12_e_emlrt_marshallIn(SFc12_testInstanceStruct *chartInstance,
  const mxArray *c12_u, const emlrtMsgIdentifier *c12_parentId)
{
  uint8_T c12_y;
  uint8_T c12_u0;
  sf_mex_import(c12_parentId, sf_mex_dup(c12_u), &c12_u0, 1, 3, 0U, 0, 0U, 0);
  c12_y = c12_u0;
  sf_mex_destroy(&c12_u);
  return c12_y;
}

static void init_dsm_address_info(SFc12_testInstanceStruct *chartInstance)
{
}

/* SFunction Glue Code */
void sf_c12_test_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(1112873634U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(4176081632U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(2995293904U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(3128124319U);
}

mxArray *sf_c12_test_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1,1,5,
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateString("xXtzJiDIbcZiA5XiGFEooD");
    mxSetField(mxAutoinheritanceInfo,0,"checksum",mxChecksum);
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
    mxSetField(mxAutoinheritanceInfo,0,"inputs",mxData);
  }

  {
    mxSetField(mxAutoinheritanceInfo,0,"parameters",mxCreateDoubleMatrix(0,0,
                mxREAL));
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

static const mxArray *sf_get_sim_state_info_c12_test(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x2'type','srcId','name','auxInfo'{{M[1],M[5],T\"y\",},{M[8],M[0],T\"is_active_c12_test\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 2, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c12_test_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc12_testInstanceStruct *chartInstance;
    chartInstance = (SFc12_testInstanceStruct *) ((ChartInfoStruct *)
      (ssGetUserData(S)))->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart(_testMachineNumber_,
          12,
          1,
          1,
          3,
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
          _SFD_SET_DATA_PROPS(0,1,1,0,"Theta_wo");
          _SFD_SET_DATA_PROPS(1,2,0,1,"y");
          _SFD_SET_DATA_PROPS(2,1,1,0,"Theta_po");
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
        _SFD_CV_INIT_EML_FCN(0,0,"eML_blk_kernel",0,-1,276);
        _SFD_TRANS_COV_WTS(0,0,0,1,0);
        if (chartAlreadyPresent==0) {
          _SFD_TRANS_COV_MAPS(0,
                              0,NULL,NULL,
                              0,NULL,NULL,
                              1,NULL,NULL,
                              0,NULL,NULL);
        }

        _SFD_SET_DATA_COMPILED_PROPS(0,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c12_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(1,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c12_sf_marshallOut,(MexInFcnForType)c12_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(2,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c12_sf_marshallOut,(MexInFcnForType)NULL);

        {
          real_T *c12_Theta_wo;
          real_T *c12_y;
          real_T *c12_Theta_po;
          c12_Theta_po = (real_T *)ssGetInputPortSignal(chartInstance->S, 1);
          c12_y = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
          c12_Theta_wo = (real_T *)ssGetInputPortSignal(chartInstance->S, 0);
          _SFD_SET_DATA_VALUE_PTR(0U, c12_Theta_wo);
          _SFD_SET_DATA_VALUE_PTR(1U, c12_y);
          _SFD_SET_DATA_VALUE_PTR(2U, c12_Theta_po);
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
  return "GejD9FjTlhZYBBJ0hV27rD";
}

static void sf_opaque_initialize_c12_test(void *chartInstanceVar)
{
  chart_debug_initialization(((SFc12_testInstanceStruct*) chartInstanceVar)->S,0);
  initialize_params_c12_test((SFc12_testInstanceStruct*) chartInstanceVar);
  initialize_c12_test((SFc12_testInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_enable_c12_test(void *chartInstanceVar)
{
  enable_c12_test((SFc12_testInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_disable_c12_test(void *chartInstanceVar)
{
  disable_c12_test((SFc12_testInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_gateway_c12_test(void *chartInstanceVar)
{
  sf_c12_test((SFc12_testInstanceStruct*) chartInstanceVar);
}

extern const mxArray* sf_internal_get_sim_state_c12_test(SimStruct* S)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_raw2high");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = (mxArray*) get_sim_state_c12_test((SFc12_testInstanceStruct*)
    chartInfo->chartInstance);         /* raw sim ctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c12_test();/* state var info */
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

extern void sf_internal_set_sim_state_c12_test(SimStruct* S, const mxArray *st)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_high2raw");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = mxDuplicateArray(st);      /* high level simctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c12_test();/* state var info */
  mxError = sf_mex_call_matlab(1, plhs, 4, prhs, "sfprivate");
  mxDestroyArray(prhs[0]);
  mxDestroyArray(prhs[1]);
  mxDestroyArray(prhs[2]);
  mxDestroyArray(prhs[3]);
  if (mxError || plhs[0] == NULL) {
    sf_mex_error_message("Stateflow Internal Error: \nError calling 'chart_simctx_high2raw'.\n");
  }

  set_sim_state_c12_test((SFc12_testInstanceStruct*)chartInfo->chartInstance,
    mxDuplicateArray(plhs[0]));
  mxDestroyArray(plhs[0]);
}

static const mxArray* sf_opaque_get_sim_state_c12_test(SimStruct* S)
{
  return sf_internal_get_sim_state_c12_test(S);
}

static void sf_opaque_set_sim_state_c12_test(SimStruct* S, const mxArray *st)
{
  sf_internal_set_sim_state_c12_test(S, st);
}

static void sf_opaque_terminate_c12_test(void *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc12_testInstanceStruct*) chartInstanceVar)->S;
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
    }

    finalize_c12_test((SFc12_testInstanceStruct*) chartInstanceVar);
    free((void *)chartInstanceVar);
    ssSetUserData(S,NULL);
  }

  unload_test_optimization_info();
}

static void sf_opaque_init_subchart_simstructs(void *chartInstanceVar)
{
  initSimStructsc12_test((SFc12_testInstanceStruct*) chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c12_test(SimStruct *S)
{
  int i;
  for (i=0;i<ssGetNumRunTimeParams(S);i++) {
    if (ssGetSFcnParamTunable(S,i)) {
      ssUpdateDlgParamAsRunTimeParam(S,i);
    }
  }

  if (sf_machine_global_initializer_called()) {
    initialize_params_c12_test((SFc12_testInstanceStruct*)(((ChartInfoStruct *)
      ssGetUserData(S))->chartInstance));
  }
}

static void mdlSetWorkWidths_c12_test(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    mxArray *infoStruct = load_test_optimization_info();
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable(S,sf_get_instance_specialization(),infoStruct,
      12);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop(S,sf_get_instance_specialization(),
                infoStruct,12,"RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop(S,
      sf_get_instance_specialization(),infoStruct,12,
      "gatewayCannotBeInlinedMultipleTimes"));
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 1, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,sf_get_instance_specialization(),
        infoStruct,12,2);
      sf_mark_chart_reusable_outputs(S,sf_get_instance_specialization(),
        infoStruct,12,1);
    }

    sf_set_rtw_dwork_info(S,sf_get_instance_specialization(),infoStruct,12);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(3667223951U));
  ssSetChecksum1(S,(1315910162U));
  ssSetChecksum2(S,(2301670990U));
  ssSetChecksum3(S,(3163739505U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
  ssSupportsMultipleExecInstances(S,1);
}

static void mdlRTW_c12_test(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c12_test(SimStruct *S)
{
  SFc12_testInstanceStruct *chartInstance;
  chartInstance = (SFc12_testInstanceStruct *)malloc(sizeof
    (SFc12_testInstanceStruct));
  memset(chartInstance, 0, sizeof(SFc12_testInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway = sf_opaque_gateway_c12_test;
  chartInstance->chartInfo.initializeChart = sf_opaque_initialize_c12_test;
  chartInstance->chartInfo.terminateChart = sf_opaque_terminate_c12_test;
  chartInstance->chartInfo.enableChart = sf_opaque_enable_c12_test;
  chartInstance->chartInfo.disableChart = sf_opaque_disable_c12_test;
  chartInstance->chartInfo.getSimState = sf_opaque_get_sim_state_c12_test;
  chartInstance->chartInfo.setSimState = sf_opaque_set_sim_state_c12_test;
  chartInstance->chartInfo.getSimStateInfo = sf_get_sim_state_info_c12_test;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c12_test;
  chartInstance->chartInfo.mdlStart = mdlStart_c12_test;
  chartInstance->chartInfo.mdlSetWorkWidths = mdlSetWorkWidths_c12_test;
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

void c12_test_method_dispatcher(SimStruct *S, int_T method, void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c12_test(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c12_test(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c12_test(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c12_test_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}

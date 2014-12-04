/* Include files */

#include "blascompat32.h"
#include "untitled_sfun.h"
#include "c10_untitled.h"
#include "mwmathutil.h"
#define CHARTINSTANCE_CHARTNUMBER      (chartInstance->chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER   (chartInstance->instanceNumber)
#include "untitled_sfun_debug_macros.h"

/* Type Definitions */

/* Named Constants */
#define CALL_EVENT                     (-1)

/* Variable Declarations */

/* Variable Definitions */
static const char * c10_debug_family_names[10] = { "e_theta", "Theta_max",
  "f_theta", "Delta_f", "Delta_f_norm", "nargin", "nargout", "Theta", "y",
  "Theta_hat_dot" };

/* Function Declarations */
static void initialize_c10_untitled(SFc10_untitledInstanceStruct *chartInstance);
static void initialize_params_c10_untitled(SFc10_untitledInstanceStruct
  *chartInstance);
static void enable_c10_untitled(SFc10_untitledInstanceStruct *chartInstance);
static void disable_c10_untitled(SFc10_untitledInstanceStruct *chartInstance);
static void c10_update_debugger_state_c10_untitled(SFc10_untitledInstanceStruct *
  chartInstance);
static const mxArray *get_sim_state_c10_untitled(SFc10_untitledInstanceStruct
  *chartInstance);
static void set_sim_state_c10_untitled(SFc10_untitledInstanceStruct
  *chartInstance, const mxArray *c10_st);
static void finalize_c10_untitled(SFc10_untitledInstanceStruct *chartInstance);
static void sf_c10_untitled(SFc10_untitledInstanceStruct *chartInstance);
static void initSimStructsc10_untitled(SFc10_untitledInstanceStruct
  *chartInstance);
static void init_script_number_translation(uint32_T c10_machineNumber, uint32_T
  c10_chartNumber);
static const mxArray *c10_sf_marshallOut(void *chartInstanceVoid, void
  *c10_inData);
static real_T c10_emlrt_marshallIn(SFc10_untitledInstanceStruct *chartInstance,
  const mxArray *c10_Theta_hat_dot, const char_T *c10_identifier);
static real_T c10_b_emlrt_marshallIn(SFc10_untitledInstanceStruct *chartInstance,
  const mxArray *c10_u, const emlrtMsgIdentifier *c10_parentId);
static void c10_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c10_mxArrayInData, const char_T *c10_varName, void *c10_outData);
static void c10_info_helper(c10_ResolvedFunctionInfo c10_info[13]);
static const mxArray *c10_b_sf_marshallOut(void *chartInstanceVoid, void
  *c10_inData);
static int32_T c10_c_emlrt_marshallIn(SFc10_untitledInstanceStruct
  *chartInstance, const mxArray *c10_u, const emlrtMsgIdentifier *c10_parentId);
static void c10_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c10_mxArrayInData, const char_T *c10_varName, void *c10_outData);
static uint8_T c10_d_emlrt_marshallIn(SFc10_untitledInstanceStruct
  *chartInstance, const mxArray *c10_b_is_active_c10_untitled, const char_T
  *c10_identifier);
static uint8_T c10_e_emlrt_marshallIn(SFc10_untitledInstanceStruct
  *chartInstance, const mxArray *c10_u, const emlrtMsgIdentifier *c10_parentId);
static void init_dsm_address_info(SFc10_untitledInstanceStruct *chartInstance);

/* Function Definitions */
static void initialize_c10_untitled(SFc10_untitledInstanceStruct *chartInstance)
{
  chartInstance->c10_sfEvent = CALL_EVENT;
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  chartInstance->c10_is_active_c10_untitled = 0U;
}

static void initialize_params_c10_untitled(SFc10_untitledInstanceStruct
  *chartInstance)
{
}

static void enable_c10_untitled(SFc10_untitledInstanceStruct *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void disable_c10_untitled(SFc10_untitledInstanceStruct *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void c10_update_debugger_state_c10_untitled(SFc10_untitledInstanceStruct *
  chartInstance)
{
}

static const mxArray *get_sim_state_c10_untitled(SFc10_untitledInstanceStruct
  *chartInstance)
{
  const mxArray *c10_st;
  const mxArray *c10_y = NULL;
  real_T c10_hoistedGlobal;
  real_T c10_u;
  const mxArray *c10_b_y = NULL;
  uint8_T c10_b_hoistedGlobal;
  uint8_T c10_b_u;
  const mxArray *c10_c_y = NULL;
  real_T *c10_Theta_hat_dot;
  c10_Theta_hat_dot = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c10_st = NULL;
  c10_st = NULL;
  c10_y = NULL;
  sf_mex_assign(&c10_y, sf_mex_createcellarray(2), FALSE);
  c10_hoistedGlobal = *c10_Theta_hat_dot;
  c10_u = c10_hoistedGlobal;
  c10_b_y = NULL;
  sf_mex_assign(&c10_b_y, sf_mex_create("y", &c10_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c10_y, 0, c10_b_y);
  c10_b_hoistedGlobal = chartInstance->c10_is_active_c10_untitled;
  c10_b_u = c10_b_hoistedGlobal;
  c10_c_y = NULL;
  sf_mex_assign(&c10_c_y, sf_mex_create("y", &c10_b_u, 3, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c10_y, 1, c10_c_y);
  sf_mex_assign(&c10_st, c10_y, FALSE);
  return c10_st;
}

static void set_sim_state_c10_untitled(SFc10_untitledInstanceStruct
  *chartInstance, const mxArray *c10_st)
{
  const mxArray *c10_u;
  real_T *c10_Theta_hat_dot;
  c10_Theta_hat_dot = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  chartInstance->c10_doneDoubleBufferReInit = TRUE;
  c10_u = sf_mex_dup(c10_st);
  *c10_Theta_hat_dot = c10_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c10_u, 0)), "Theta_hat_dot");
  chartInstance->c10_is_active_c10_untitled = c10_d_emlrt_marshallIn
    (chartInstance, sf_mex_dup(sf_mex_getcell(c10_u, 1)),
     "is_active_c10_untitled");
  sf_mex_destroy(&c10_u);
  c10_update_debugger_state_c10_untitled(chartInstance);
  sf_mex_destroy(&c10_st);
}

static void finalize_c10_untitled(SFc10_untitledInstanceStruct *chartInstance)
{
}

static void sf_c10_untitled(SFc10_untitledInstanceStruct *chartInstance)
{
  real_T c10_hoistedGlobal;
  real_T c10_b_hoistedGlobal;
  real_T c10_Theta;
  real_T c10_y;
  uint32_T c10_debug_family_var_map[10];
  real_T c10_e_theta;
  real_T c10_Theta_max;
  real_T c10_f_theta;
  real_T c10_Delta_f;
  real_T c10_Delta_f_norm;
  real_T c10_nargin = 2.0;
  real_T c10_nargout = 1.0;
  real_T c10_Theta_hat_dot;
  real_T c10_b;
  real_T c10_b_y;
  real_T c10_a;
  real_T c10_b_b;
  real_T c10_c_y;
  real_T c10_A;
  real_T c10_x;
  real_T c10_b_x;
  real_T c10_c_b;
  real_T c10_c_x;
  real_T c10_d_x;
  real_T c10_e_x;
  real_T c10_d_y;
  real_T c10_b_A;
  real_T c10_B;
  real_T c10_f_x;
  real_T c10_e_y;
  real_T c10_g_x;
  real_T c10_f_y;
  real_T c10_b_a;
  real_T c10_d_b;
  real_T c10_g_y;
  boolean_T c10_b0;
  real_T c10_c_a;
  real_T c10_e_b;
  real_T c10_h_y;
  boolean_T c10_b1;
  boolean_T c10_u;
  const mxArray *c10_i_y = NULL;
  real_T c10_d_a;
  real_T c10_f_b;
  real_T c10_j_y;
  real_T c10_e_a;
  real_T c10_g_b;
  real_T c10_k_y;
  real_T c10_f_a;
  real_T c10_h_b;
  real_T c10_l_y;
  real_T *c10_m_y;
  real_T *c10_b_Theta;
  real_T *c10_b_Theta_hat_dot;
  boolean_T guard1 = FALSE;
  c10_m_y = (real_T *)ssGetInputPortSignal(chartInstance->S, 1);
  c10_b_Theta_hat_dot = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c10_b_Theta = (real_T *)ssGetInputPortSignal(chartInstance->S, 0);
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 0U, chartInstance->c10_sfEvent);
  _SFD_DATA_RANGE_CHECK(*c10_b_Theta, 0U);
  _SFD_DATA_RANGE_CHECK(*c10_b_Theta_hat_dot, 1U);
  _SFD_DATA_RANGE_CHECK(*c10_m_y, 2U);
  chartInstance->c10_sfEvent = CALL_EVENT;
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 0U, chartInstance->c10_sfEvent);
  c10_hoistedGlobal = *c10_b_Theta;
  c10_b_hoistedGlobal = *c10_m_y;
  c10_Theta = c10_hoistedGlobal;
  c10_y = c10_b_hoistedGlobal;
  sf_debug_symbol_scope_push_eml(0U, 10U, 10U, c10_debug_family_names,
    c10_debug_family_var_map);
  sf_debug_symbol_scope_add_eml(&c10_e_theta, 0U, c10_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c10_Theta_max, 1U, c10_sf_marshallOut);
  sf_debug_symbol_scope_add_eml_importable(&c10_f_theta, 2U, c10_sf_marshallOut,
    c10_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c10_Delta_f, 3U, c10_sf_marshallOut,
    c10_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c10_Delta_f_norm, 4U,
    c10_sf_marshallOut, c10_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c10_nargin, 5U, c10_sf_marshallOut,
    c10_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c10_nargout, 6U, c10_sf_marshallOut,
    c10_sf_marshallIn);
  sf_debug_symbol_scope_add_eml(&c10_Theta, 7U, c10_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c10_y, 8U, c10_sf_marshallOut);
  sf_debug_symbol_scope_add_eml_importable(&c10_Theta_hat_dot, 9U,
    c10_sf_marshallOut, c10_sf_marshallIn);
  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(0U, chartInstance->c10_sfEvent, 3);
  c10_e_theta = 0.5;
  _SFD_EML_CALL(0U, chartInstance->c10_sfEvent, 3);
  c10_Theta_max = 20.0;
  _SFD_EML_CALL(0U, chartInstance->c10_sfEvent, 4);
  c10_b = c10_Theta;
  c10_b_y = 1.5 * c10_b;
  c10_a = c10_b_y;
  c10_b_b = c10_Theta;
  c10_c_y = c10_a * c10_b_b;
  c10_A = c10_c_y - 400.0;
  c10_x = c10_A;
  c10_b_x = c10_x;
  c10_f_theta = c10_b_x / 200.0;
  _SFD_EML_CALL(0U, chartInstance->c10_sfEvent, 5);
  c10_c_b = c10_Theta;
  c10_Delta_f = 0.015 * c10_c_b;
  _SFD_EML_CALL(0U, chartInstance->c10_sfEvent, 7);
  c10_c_x = c10_Delta_f;
  c10_d_x = c10_c_x;
  c10_e_x = c10_d_x;
  c10_d_y = muDoubleScalarAbs(c10_e_x);
  c10_b_A = c10_Delta_f;
  c10_B = c10_d_y;
  c10_f_x = c10_b_A;
  c10_e_y = c10_B;
  c10_g_x = c10_f_x;
  c10_f_y = c10_e_y;
  c10_Delta_f_norm = c10_g_x / c10_f_y;
  _SFD_EML_CALL(0U, chartInstance->c10_sfEvent, 9);
  if (CV_EML_IF(0, 1, 0, c10_f_theta < 0.0)) {
    _SFD_EML_CALL(0U, chartInstance->c10_sfEvent, 10);
    c10_Theta_hat_dot = c10_y;
  } else {
    _SFD_EML_CALL(0U, chartInstance->c10_sfEvent, 11);
    guard1 = FALSE;
    if (CV_EML_COND(0, 1, 0, c10_f_theta >= 0.0)) {
      c10_b_a = c10_Delta_f;
      c10_d_b = c10_y;
      c10_g_y = c10_b_a * c10_d_b;
      if (CV_EML_COND(0, 1, 1, c10_g_y <= 0.0)) {
        CV_EML_MCDC(0, 1, 0, TRUE);
        CV_EML_IF(0, 1, 1, TRUE);
        _SFD_EML_CALL(0U, chartInstance->c10_sfEvent, 12);
        c10_Theta_hat_dot = c10_y;
      } else {
        guard1 = TRUE;
      }
    } else {
      guard1 = TRUE;
    }

    if (guard1 == TRUE) {
      CV_EML_MCDC(0, 1, 0, FALSE);
      CV_EML_IF(0, 1, 1, FALSE);
      _SFD_EML_CALL(0U, chartInstance->c10_sfEvent, 13);
      c10_b0 = (c10_f_theta >= 0.0);
      c10_c_a = c10_Delta_f;
      c10_e_b = c10_y;
      c10_h_y = c10_c_a * c10_e_b;
      c10_b1 = (c10_h_y > 0.0);
      sf_mex_printf("%s =\\n", "ans");
      c10_u = (c10_b0 && c10_b1);
      c10_i_y = NULL;
      sf_mex_assign(&c10_i_y, sf_mex_create("y", &c10_u, 11, 0U, 0U, 0U, 0),
                    FALSE);
      sf_mex_call_debug("disp", 0U, 1U, 14, c10_i_y);
      _SFD_EML_CALL(0U, chartInstance->c10_sfEvent, 14);
      c10_d_a = c10_Delta_f_norm;
      c10_f_b = c10_y;
      c10_j_y = c10_d_a * c10_f_b;
      c10_e_a = c10_Delta_f_norm;
      c10_g_b = c10_j_y;
      c10_k_y = c10_e_a * c10_g_b;
      c10_f_a = c10_k_y;
      c10_h_b = c10_f_theta;
      c10_l_y = c10_f_a * c10_h_b;
      c10_Theta_hat_dot = c10_y - c10_l_y;
    }
  }

  _SFD_EML_CALL(0U, chartInstance->c10_sfEvent, -14);
  sf_debug_symbol_scope_pop();
  *c10_b_Theta_hat_dot = c10_Theta_hat_dot;
  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 0U, chartInstance->c10_sfEvent);
  sf_debug_check_for_state_inconsistency(_untitledMachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
}

static void initSimStructsc10_untitled(SFc10_untitledInstanceStruct
  *chartInstance)
{
}

static void init_script_number_translation(uint32_T c10_machineNumber, uint32_T
  c10_chartNumber)
{
}

static const mxArray *c10_sf_marshallOut(void *chartInstanceVoid, void
  *c10_inData)
{
  const mxArray *c10_mxArrayOutData = NULL;
  real_T c10_u;
  const mxArray *c10_y = NULL;
  SFc10_untitledInstanceStruct *chartInstance;
  chartInstance = (SFc10_untitledInstanceStruct *)chartInstanceVoid;
  c10_mxArrayOutData = NULL;
  c10_u = *(real_T *)c10_inData;
  c10_y = NULL;
  sf_mex_assign(&c10_y, sf_mex_create("y", &c10_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c10_mxArrayOutData, c10_y, FALSE);
  return c10_mxArrayOutData;
}

static real_T c10_emlrt_marshallIn(SFc10_untitledInstanceStruct *chartInstance,
  const mxArray *c10_Theta_hat_dot, const char_T *c10_identifier)
{
  real_T c10_y;
  emlrtMsgIdentifier c10_thisId;
  c10_thisId.fIdentifier = c10_identifier;
  c10_thisId.fParent = NULL;
  c10_y = c10_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c10_Theta_hat_dot),
    &c10_thisId);
  sf_mex_destroy(&c10_Theta_hat_dot);
  return c10_y;
}

static real_T c10_b_emlrt_marshallIn(SFc10_untitledInstanceStruct *chartInstance,
  const mxArray *c10_u, const emlrtMsgIdentifier *c10_parentId)
{
  real_T c10_y;
  real_T c10_d0;
  sf_mex_import(c10_parentId, sf_mex_dup(c10_u), &c10_d0, 1, 0, 0U, 0, 0U, 0);
  c10_y = c10_d0;
  sf_mex_destroy(&c10_u);
  return c10_y;
}

static void c10_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c10_mxArrayInData, const char_T *c10_varName, void *c10_outData)
{
  const mxArray *c10_Theta_hat_dot;
  const char_T *c10_identifier;
  emlrtMsgIdentifier c10_thisId;
  real_T c10_y;
  SFc10_untitledInstanceStruct *chartInstance;
  chartInstance = (SFc10_untitledInstanceStruct *)chartInstanceVoid;
  c10_Theta_hat_dot = sf_mex_dup(c10_mxArrayInData);
  c10_identifier = c10_varName;
  c10_thisId.fIdentifier = c10_identifier;
  c10_thisId.fParent = NULL;
  c10_y = c10_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c10_Theta_hat_dot),
    &c10_thisId);
  sf_mex_destroy(&c10_Theta_hat_dot);
  *(real_T *)c10_outData = c10_y;
  sf_mex_destroy(&c10_mxArrayInData);
}

const mxArray *sf_c10_untitled_get_eml_resolved_functions_info(void)
{
  const mxArray *c10_nameCaptureInfo;
  c10_ResolvedFunctionInfo c10_info[13];
  const mxArray *c10_m0 = NULL;
  int32_T c10_i0;
  c10_ResolvedFunctionInfo *c10_r0;
  c10_nameCaptureInfo = NULL;
  c10_nameCaptureInfo = NULL;
  c10_info_helper(c10_info);
  sf_mex_assign(&c10_m0, sf_mex_createstruct("nameCaptureInfo", 1, 13), FALSE);
  for (c10_i0 = 0; c10_i0 < 13; c10_i0++) {
    c10_r0 = &c10_info[c10_i0];
    sf_mex_addfield(c10_m0, sf_mex_create("nameCaptureInfo", c10_r0->context, 15,
      0U, 0U, 0U, 2, 1, strlen(c10_r0->context)), "context", "nameCaptureInfo",
                    c10_i0);
    sf_mex_addfield(c10_m0, sf_mex_create("nameCaptureInfo", c10_r0->name, 15,
      0U, 0U, 0U, 2, 1, strlen(c10_r0->name)), "name", "nameCaptureInfo", c10_i0);
    sf_mex_addfield(c10_m0, sf_mex_create("nameCaptureInfo",
      c10_r0->dominantType, 15, 0U, 0U, 0U, 2, 1, strlen(c10_r0->dominantType)),
                    "dominantType", "nameCaptureInfo", c10_i0);
    sf_mex_addfield(c10_m0, sf_mex_create("nameCaptureInfo", c10_r0->resolved,
      15, 0U, 0U, 0U, 2, 1, strlen(c10_r0->resolved)), "resolved",
                    "nameCaptureInfo", c10_i0);
    sf_mex_addfield(c10_m0, sf_mex_create("nameCaptureInfo", &c10_r0->fileTimeLo,
      7, 0U, 0U, 0U, 0), "fileTimeLo", "nameCaptureInfo", c10_i0);
    sf_mex_addfield(c10_m0, sf_mex_create("nameCaptureInfo", &c10_r0->fileTimeHi,
      7, 0U, 0U, 0U, 0), "fileTimeHi", "nameCaptureInfo", c10_i0);
    sf_mex_addfield(c10_m0, sf_mex_create("nameCaptureInfo",
      &c10_r0->mFileTimeLo, 7, 0U, 0U, 0U, 0), "mFileTimeLo", "nameCaptureInfo",
                    c10_i0);
    sf_mex_addfield(c10_m0, sf_mex_create("nameCaptureInfo",
      &c10_r0->mFileTimeHi, 7, 0U, 0U, 0U, 0), "mFileTimeHi", "nameCaptureInfo",
                    c10_i0);
  }

  sf_mex_assign(&c10_nameCaptureInfo, c10_m0, FALSE);
  sf_mex_emlrtNameCapturePostProcessR2012a(&c10_nameCaptureInfo);
  return c10_nameCaptureInfo;
}

static void c10_info_helper(c10_ResolvedFunctionInfo c10_info[13])
{
  c10_info[0].context = "";
  c10_info[0].name = "mtimes";
  c10_info[0].dominantType = "double";
  c10_info[0].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c10_info[0].fileTimeLo = 1289494492U;
  c10_info[0].fileTimeHi = 0U;
  c10_info[0].mFileTimeLo = 0U;
  c10_info[0].mFileTimeHi = 0U;
  c10_info[1].context = "";
  c10_info[1].name = "mpower";
  c10_info[1].dominantType = "double";
  c10_info[1].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mpower.m";
  c10_info[1].fileTimeLo = 1286797242U;
  c10_info[1].fileTimeHi = 0U;
  c10_info[1].mFileTimeLo = 0U;
  c10_info[1].mFileTimeHi = 0U;
  c10_info[2].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mpower.m";
  c10_info[2].name = "power";
  c10_info[2].dominantType = "double";
  c10_info[2].resolved = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m";
  c10_info[2].fileTimeLo = 1336500496U;
  c10_info[2].fileTimeHi = 0U;
  c10_info[2].mFileTimeLo = 0U;
  c10_info[2].mFileTimeHi = 0U;
  c10_info[3].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m!fltpower";
  c10_info[3].name = "eml_scalar_eg";
  c10_info[3].dominantType = "double";
  c10_info[3].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m";
  c10_info[3].fileTimeLo = 1286797196U;
  c10_info[3].fileTimeHi = 0U;
  c10_info[3].mFileTimeLo = 0U;
  c10_info[3].mFileTimeHi = 0U;
  c10_info[4].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m!fltpower";
  c10_info[4].name = "eml_scalexp_alloc";
  c10_info[4].dominantType = "double";
  c10_info[4].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalexp_alloc.m";
  c10_info[4].fileTimeLo = 1330583234U;
  c10_info[4].fileTimeHi = 0U;
  c10_info[4].mFileTimeLo = 0U;
  c10_info[4].mFileTimeHi = 0U;
  c10_info[5].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m!fltpower";
  c10_info[5].name = "floor";
  c10_info[5].dominantType = "double";
  c10_info[5].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/floor.m";
  c10_info[5].fileTimeLo = 1286797142U;
  c10_info[5].fileTimeHi = 0U;
  c10_info[5].mFileTimeLo = 0U;
  c10_info[5].mFileTimeHi = 0U;
  c10_info[6].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/floor.m";
  c10_info[6].name = "eml_scalar_floor";
  c10_info[6].dominantType = "double";
  c10_info[6].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_floor.m";
  c10_info[6].fileTimeLo = 1286797126U;
  c10_info[6].fileTimeHi = 0U;
  c10_info[6].mFileTimeLo = 0U;
  c10_info[6].mFileTimeHi = 0U;
  c10_info[7].context = "";
  c10_info[7].name = "mrdivide";
  c10_info[7].dominantType = "double";
  c10_info[7].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p";
  c10_info[7].fileTimeLo = 1342789344U;
  c10_info[7].fileTimeHi = 0U;
  c10_info[7].mFileTimeLo = 1319708366U;
  c10_info[7].mFileTimeHi = 0U;
  c10_info[8].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p";
  c10_info[8].name = "rdivide";
  c10_info[8].dominantType = "double";
  c10_info[8].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m";
  c10_info[8].fileTimeLo = 1286797244U;
  c10_info[8].fileTimeHi = 0U;
  c10_info[8].mFileTimeLo = 0U;
  c10_info[8].mFileTimeHi = 0U;
  c10_info[9].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m";
  c10_info[9].name = "eml_div";
  c10_info[9].dominantType = "double";
  c10_info[9].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_div.m";
  c10_info[9].fileTimeLo = 1313326210U;
  c10_info[9].fileTimeHi = 0U;
  c10_info[9].mFileTimeLo = 0U;
  c10_info[9].mFileTimeHi = 0U;
  c10_info[10].context = "";
  c10_info[10].name = "norm";
  c10_info[10].dominantType = "double";
  c10_info[10].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/matfun/norm.m";
  c10_info[10].fileTimeLo = 1336500494U;
  c10_info[10].fileTimeHi = 0U;
  c10_info[10].mFileTimeLo = 0U;
  c10_info[10].mFileTimeHi = 0U;
  c10_info[11].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/matfun/norm.m";
  c10_info[11].name = "abs";
  c10_info[11].dominantType = "double";
  c10_info[11].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m";
  c10_info[11].fileTimeLo = 1286797094U;
  c10_info[11].fileTimeHi = 0U;
  c10_info[11].mFileTimeLo = 0U;
  c10_info[11].mFileTimeHi = 0U;
  c10_info[12].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m";
  c10_info[12].name = "eml_scalar_abs";
  c10_info[12].dominantType = "double";
  c10_info[12].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_abs.m";
  c10_info[12].fileTimeLo = 1286797112U;
  c10_info[12].fileTimeHi = 0U;
  c10_info[12].mFileTimeLo = 0U;
  c10_info[12].mFileTimeHi = 0U;
}

static const mxArray *c10_b_sf_marshallOut(void *chartInstanceVoid, void
  *c10_inData)
{
  const mxArray *c10_mxArrayOutData = NULL;
  int32_T c10_u;
  const mxArray *c10_y = NULL;
  SFc10_untitledInstanceStruct *chartInstance;
  chartInstance = (SFc10_untitledInstanceStruct *)chartInstanceVoid;
  c10_mxArrayOutData = NULL;
  c10_u = *(int32_T *)c10_inData;
  c10_y = NULL;
  sf_mex_assign(&c10_y, sf_mex_create("y", &c10_u, 6, 0U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c10_mxArrayOutData, c10_y, FALSE);
  return c10_mxArrayOutData;
}

static int32_T c10_c_emlrt_marshallIn(SFc10_untitledInstanceStruct
  *chartInstance, const mxArray *c10_u, const emlrtMsgIdentifier *c10_parentId)
{
  int32_T c10_y;
  int32_T c10_i1;
  sf_mex_import(c10_parentId, sf_mex_dup(c10_u), &c10_i1, 1, 6, 0U, 0, 0U, 0);
  c10_y = c10_i1;
  sf_mex_destroy(&c10_u);
  return c10_y;
}

static void c10_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c10_mxArrayInData, const char_T *c10_varName, void *c10_outData)
{
  const mxArray *c10_b_sfEvent;
  const char_T *c10_identifier;
  emlrtMsgIdentifier c10_thisId;
  int32_T c10_y;
  SFc10_untitledInstanceStruct *chartInstance;
  chartInstance = (SFc10_untitledInstanceStruct *)chartInstanceVoid;
  c10_b_sfEvent = sf_mex_dup(c10_mxArrayInData);
  c10_identifier = c10_varName;
  c10_thisId.fIdentifier = c10_identifier;
  c10_thisId.fParent = NULL;
  c10_y = c10_c_emlrt_marshallIn(chartInstance, sf_mex_dup(c10_b_sfEvent),
    &c10_thisId);
  sf_mex_destroy(&c10_b_sfEvent);
  *(int32_T *)c10_outData = c10_y;
  sf_mex_destroy(&c10_mxArrayInData);
}

static uint8_T c10_d_emlrt_marshallIn(SFc10_untitledInstanceStruct
  *chartInstance, const mxArray *c10_b_is_active_c10_untitled, const char_T
  *c10_identifier)
{
  uint8_T c10_y;
  emlrtMsgIdentifier c10_thisId;
  c10_thisId.fIdentifier = c10_identifier;
  c10_thisId.fParent = NULL;
  c10_y = c10_e_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c10_b_is_active_c10_untitled), &c10_thisId);
  sf_mex_destroy(&c10_b_is_active_c10_untitled);
  return c10_y;
}

static uint8_T c10_e_emlrt_marshallIn(SFc10_untitledInstanceStruct
  *chartInstance, const mxArray *c10_u, const emlrtMsgIdentifier *c10_parentId)
{
  uint8_T c10_y;
  uint8_T c10_u0;
  sf_mex_import(c10_parentId, sf_mex_dup(c10_u), &c10_u0, 1, 3, 0U, 0, 0U, 0);
  c10_y = c10_u0;
  sf_mex_destroy(&c10_u);
  return c10_y;
}

static void init_dsm_address_info(SFc10_untitledInstanceStruct *chartInstance)
{
}

/* SFunction Glue Code */
void sf_c10_untitled_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(3322820237U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(2315089908U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(2170479784U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(2977031302U);
}

mxArray *sf_c10_untitled_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1,1,5,
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateString("vM5WWPPnqXzDeRlYwteqKE");
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

static const mxArray *sf_get_sim_state_info_c10_untitled(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x2'type','srcId','name','auxInfo'{{M[1],M[4],T\"Theta_hat_dot\",},{M[8],M[0],T\"is_active_c10_untitled\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 2, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c10_untitled_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc10_untitledInstanceStruct *chartInstance;
    chartInstance = (SFc10_untitledInstanceStruct *) ((ChartInfoStruct *)
      (ssGetUserData(S)))->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart(_untitledMachineNumber_,
          10,
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
          init_script_number_translation(_untitledMachineNumber_,
            chartInstance->chartNumber);
          sf_debug_set_chart_disable_implicit_casting(_untitledMachineNumber_,
            chartInstance->chartNumber,1);
          sf_debug_set_chart_event_thresholds(_untitledMachineNumber_,
            chartInstance->chartNumber,
            0,
            0,
            0);
          _SFD_SET_DATA_PROPS(0,1,1,0,"Theta");
          _SFD_SET_DATA_PROPS(1,2,0,1,"Theta_hat_dot");
          _SFD_SET_DATA_PROPS(2,1,1,0,"y");
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
        _SFD_CV_INIT_EML(0,1,1,2,0,0,0,0,0,2,1);
        _SFD_CV_INIT_EML_FCN(0,0,"eML_blk_kernel",0,-1,457);
        _SFD_CV_INIT_EML_IF(0,1,0,268,282,304,457);
        _SFD_CV_INIT_EML_IF(0,1,1,304,339,361,457);

        {
          static int condStart[] = { 312, 325 };

          static int condEnd[] = { 322, 338 };

          static int pfixExpr[] = { 0, 1, -3 };

          _SFD_CV_INIT_EML_MCDC(0,1,0,312,338,2,0,&(condStart[0]),&(condEnd[0]),
                                3,&(pfixExpr[0]));
        }

        _SFD_TRANS_COV_WTS(0,0,0,1,0);
        if (chartAlreadyPresent==0) {
          _SFD_TRANS_COV_MAPS(0,
                              0,NULL,NULL,
                              0,NULL,NULL,
                              1,NULL,NULL,
                              0,NULL,NULL);
        }

        _SFD_SET_DATA_COMPILED_PROPS(0,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c10_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(1,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c10_sf_marshallOut,(MexInFcnForType)c10_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(2,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c10_sf_marshallOut,(MexInFcnForType)NULL);

        {
          real_T *c10_Theta;
          real_T *c10_Theta_hat_dot;
          real_T *c10_y;
          c10_y = (real_T *)ssGetInputPortSignal(chartInstance->S, 1);
          c10_Theta_hat_dot = (real_T *)ssGetOutputPortSignal(chartInstance->S,
            1);
          c10_Theta = (real_T *)ssGetInputPortSignal(chartInstance->S, 0);
          _SFD_SET_DATA_VALUE_PTR(0U, c10_Theta);
          _SFD_SET_DATA_VALUE_PTR(1U, c10_Theta_hat_dot);
          _SFD_SET_DATA_VALUE_PTR(2U, c10_y);
        }
      }
    } else {
      sf_debug_reset_current_state_configuration(_untitledMachineNumber_,
        chartInstance->chartNumber,chartInstance->instanceNumber);
    }
  }
}

static const char* sf_get_instance_specialization()
{
  return "Pw4gKbsFo7XoNsc2ceNF2E";
}

static void sf_opaque_initialize_c10_untitled(void *chartInstanceVar)
{
  chart_debug_initialization(((SFc10_untitledInstanceStruct*) chartInstanceVar
    )->S,0);
  initialize_params_c10_untitled((SFc10_untitledInstanceStruct*)
    chartInstanceVar);
  initialize_c10_untitled((SFc10_untitledInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_enable_c10_untitled(void *chartInstanceVar)
{
  enable_c10_untitled((SFc10_untitledInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_disable_c10_untitled(void *chartInstanceVar)
{
  disable_c10_untitled((SFc10_untitledInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_gateway_c10_untitled(void *chartInstanceVar)
{
  sf_c10_untitled((SFc10_untitledInstanceStruct*) chartInstanceVar);
}

extern const mxArray* sf_internal_get_sim_state_c10_untitled(SimStruct* S)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_raw2high");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = (mxArray*) get_sim_state_c10_untitled((SFc10_untitledInstanceStruct*)
    chartInfo->chartInstance);         /* raw sim ctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c10_untitled();/* state var info */
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

extern void sf_internal_set_sim_state_c10_untitled(SimStruct* S, const mxArray
  *st)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_high2raw");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = mxDuplicateArray(st);      /* high level simctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c10_untitled();/* state var info */
  mxError = sf_mex_call_matlab(1, plhs, 4, prhs, "sfprivate");
  mxDestroyArray(prhs[0]);
  mxDestroyArray(prhs[1]);
  mxDestroyArray(prhs[2]);
  mxDestroyArray(prhs[3]);
  if (mxError || plhs[0] == NULL) {
    sf_mex_error_message("Stateflow Internal Error: \nError calling 'chart_simctx_high2raw'.\n");
  }

  set_sim_state_c10_untitled((SFc10_untitledInstanceStruct*)
    chartInfo->chartInstance, mxDuplicateArray(plhs[0]));
  mxDestroyArray(plhs[0]);
}

static const mxArray* sf_opaque_get_sim_state_c10_untitled(SimStruct* S)
{
  return sf_internal_get_sim_state_c10_untitled(S);
}

static void sf_opaque_set_sim_state_c10_untitled(SimStruct* S, const mxArray *st)
{
  sf_internal_set_sim_state_c10_untitled(S, st);
}

static void sf_opaque_terminate_c10_untitled(void *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc10_untitledInstanceStruct*) chartInstanceVar)->S;
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
    }

    finalize_c10_untitled((SFc10_untitledInstanceStruct*) chartInstanceVar);
    free((void *)chartInstanceVar);
    ssSetUserData(S,NULL);
  }

  unload_untitled_optimization_info();
}

static void sf_opaque_init_subchart_simstructs(void *chartInstanceVar)
{
  initSimStructsc10_untitled((SFc10_untitledInstanceStruct*) chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c10_untitled(SimStruct *S)
{
  int i;
  for (i=0;i<ssGetNumRunTimeParams(S);i++) {
    if (ssGetSFcnParamTunable(S,i)) {
      ssUpdateDlgParamAsRunTimeParam(S,i);
    }
  }

  if (sf_machine_global_initializer_called()) {
    initialize_params_c10_untitled((SFc10_untitledInstanceStruct*)
      (((ChartInfoStruct *)ssGetUserData(S))->chartInstance));
  }
}

static void mdlSetWorkWidths_c10_untitled(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    mxArray *infoStruct = load_untitled_optimization_info();
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable(S,sf_get_instance_specialization(),infoStruct,
      10);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop(S,sf_get_instance_specialization(),
                infoStruct,10,"RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop(S,
      sf_get_instance_specialization(),infoStruct,10,
      "gatewayCannotBeInlinedMultipleTimes"));
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 1, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,sf_get_instance_specialization(),
        infoStruct,10,2);
      sf_mark_chart_reusable_outputs(S,sf_get_instance_specialization(),
        infoStruct,10,1);
    }

    sf_set_rtw_dwork_info(S,sf_get_instance_specialization(),infoStruct,10);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(1615231901U));
  ssSetChecksum1(S,(1868920515U));
  ssSetChecksum2(S,(1314299188U));
  ssSetChecksum3(S,(2391690536U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
  ssSupportsMultipleExecInstances(S,1);
}

static void mdlRTW_c10_untitled(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c10_untitled(SimStruct *S)
{
  SFc10_untitledInstanceStruct *chartInstance;
  chartInstance = (SFc10_untitledInstanceStruct *)malloc(sizeof
    (SFc10_untitledInstanceStruct));
  memset(chartInstance, 0, sizeof(SFc10_untitledInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway = sf_opaque_gateway_c10_untitled;
  chartInstance->chartInfo.initializeChart = sf_opaque_initialize_c10_untitled;
  chartInstance->chartInfo.terminateChart = sf_opaque_terminate_c10_untitled;
  chartInstance->chartInfo.enableChart = sf_opaque_enable_c10_untitled;
  chartInstance->chartInfo.disableChart = sf_opaque_disable_c10_untitled;
  chartInstance->chartInfo.getSimState = sf_opaque_get_sim_state_c10_untitled;
  chartInstance->chartInfo.setSimState = sf_opaque_set_sim_state_c10_untitled;
  chartInstance->chartInfo.getSimStateInfo = sf_get_sim_state_info_c10_untitled;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c10_untitled;
  chartInstance->chartInfo.mdlStart = mdlStart_c10_untitled;
  chartInstance->chartInfo.mdlSetWorkWidths = mdlSetWorkWidths_c10_untitled;
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

void c10_untitled_method_dispatcher(SimStruct *S, int_T method, void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c10_untitled(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c10_untitled(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c10_untitled(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c10_untitled_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}

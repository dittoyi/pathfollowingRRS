/* Include files */

#include "blascompat32.h"
#include "test_sfun.h"
#include "c8_test.h"
#define CHARTINSTANCE_CHARTNUMBER      (chartInstance->chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER   (chartInstance->instanceNumber)
#include "test_sfun_debug_macros.h"

/* Type Definitions */

/* Named Constants */
#define CALL_EVENT                     (-1)

/* Variable Declarations */

/* Variable Definitions */
static const char * c8_debug_family_names[6] = { "nargin", "nargout", "m_dot",
  "h", "m", "m_last" };

/* Function Declarations */
static void initialize_c8_test(SFc8_testInstanceStruct *chartInstance);
static void initialize_params_c8_test(SFc8_testInstanceStruct *chartInstance);
static void enable_c8_test(SFc8_testInstanceStruct *chartInstance);
static void disable_c8_test(SFc8_testInstanceStruct *chartInstance);
static void c8_update_debugger_state_c8_test(SFc8_testInstanceStruct
  *chartInstance);
static const mxArray *get_sim_state_c8_test(SFc8_testInstanceStruct
  *chartInstance);
static void set_sim_state_c8_test(SFc8_testInstanceStruct *chartInstance, const
  mxArray *c8_st);
static void finalize_c8_test(SFc8_testInstanceStruct *chartInstance);
static void sf_c8_test(SFc8_testInstanceStruct *chartInstance);
static void initSimStructsc8_test(SFc8_testInstanceStruct *chartInstance);
static void init_script_number_translation(uint32_T c8_machineNumber, uint32_T
  c8_chartNumber);
static const mxArray *c8_sf_marshallOut(void *chartInstanceVoid, void *c8_inData);
static real_T c8_emlrt_marshallIn(SFc8_testInstanceStruct *chartInstance, const
  mxArray *c8_b_m_last, const char_T *c8_identifier);
static real_T c8_b_emlrt_marshallIn(SFc8_testInstanceStruct *chartInstance,
  const mxArray *c8_u, const emlrtMsgIdentifier *c8_parentId);
static void c8_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c8_mxArrayInData, const char_T *c8_varName, void *c8_outData);
static const mxArray *c8_b_sf_marshallOut(void *chartInstanceVoid, void
  *c8_inData);
static real_T c8_c_emlrt_marshallIn(SFc8_testInstanceStruct *chartInstance,
  const mxArray *c8_m, const char_T *c8_identifier);
static real_T c8_d_emlrt_marshallIn(SFc8_testInstanceStruct *chartInstance,
  const mxArray *c8_u, const emlrtMsgIdentifier *c8_parentId);
static void c8_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c8_mxArrayInData, const char_T *c8_varName, void *c8_outData);
static const mxArray *c8_c_sf_marshallOut(void *chartInstanceVoid, void
  *c8_inData);
static int32_T c8_e_emlrt_marshallIn(SFc8_testInstanceStruct *chartInstance,
  const mxArray *c8_u, const emlrtMsgIdentifier *c8_parentId);
static void c8_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c8_mxArrayInData, const char_T *c8_varName, void *c8_outData);
static uint8_T c8_f_emlrt_marshallIn(SFc8_testInstanceStruct *chartInstance,
  const mxArray *c8_b_is_active_c8_test, const char_T *c8_identifier);
static uint8_T c8_g_emlrt_marshallIn(SFc8_testInstanceStruct *chartInstance,
  const mxArray *c8_u, const emlrtMsgIdentifier *c8_parentId);
static void init_dsm_address_info(SFc8_testInstanceStruct *chartInstance);

/* Function Definitions */
static void initialize_c8_test(SFc8_testInstanceStruct *chartInstance)
{
  chartInstance->c8_sfEvent = CALL_EVENT;
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  chartInstance->c8_m_last_not_empty = FALSE;
  chartInstance->c8_is_active_c8_test = 0U;
}

static void initialize_params_c8_test(SFc8_testInstanceStruct *chartInstance)
{
  real_T c8_d0;
  sf_set_error_prefix_string(
    "Error evaluating data 'h' in the parent workspace.\n");
  sf_mex_import_named("h", sf_mex_get_sfun_param(chartInstance->S, 0, 0), &c8_d0,
                      0, 0, 0U, 0, 0U, 0);
  chartInstance->c8_h = c8_d0;
  sf_set_error_prefix_string("Stateflow Runtime Error (chart): ");
}

static void enable_c8_test(SFc8_testInstanceStruct *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void disable_c8_test(SFc8_testInstanceStruct *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void c8_update_debugger_state_c8_test(SFc8_testInstanceStruct
  *chartInstance)
{
}

static const mxArray *get_sim_state_c8_test(SFc8_testInstanceStruct
  *chartInstance)
{
  const mxArray *c8_st;
  const mxArray *c8_y = NULL;
  real_T c8_hoistedGlobal;
  real_T c8_u;
  const mxArray *c8_b_y = NULL;
  real_T c8_b_hoistedGlobal;
  real_T c8_b_u;
  const mxArray *c8_c_y = NULL;
  uint8_T c8_c_hoistedGlobal;
  uint8_T c8_c_u;
  const mxArray *c8_d_y = NULL;
  real_T *c8_m;
  c8_m = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c8_st = NULL;
  c8_st = NULL;
  c8_y = NULL;
  sf_mex_assign(&c8_y, sf_mex_createcellarray(3), FALSE);
  c8_hoistedGlobal = *c8_m;
  c8_u = c8_hoistedGlobal;
  c8_b_y = NULL;
  sf_mex_assign(&c8_b_y, sf_mex_create("y", &c8_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c8_y, 0, c8_b_y);
  c8_b_hoistedGlobal = chartInstance->c8_m_last;
  c8_b_u = c8_b_hoistedGlobal;
  c8_c_y = NULL;
  if (!chartInstance->c8_m_last_not_empty) {
    sf_mex_assign(&c8_c_y, sf_mex_create("y", NULL, 0, 0U, 1U, 0U, 2, 0, 0),
                  FALSE);
  } else {
    sf_mex_assign(&c8_c_y, sf_mex_create("y", &c8_b_u, 0, 0U, 0U, 0U, 0), FALSE);
  }

  sf_mex_setcell(c8_y, 1, c8_c_y);
  c8_c_hoistedGlobal = chartInstance->c8_is_active_c8_test;
  c8_c_u = c8_c_hoistedGlobal;
  c8_d_y = NULL;
  sf_mex_assign(&c8_d_y, sf_mex_create("y", &c8_c_u, 3, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c8_y, 2, c8_d_y);
  sf_mex_assign(&c8_st, c8_y, FALSE);
  return c8_st;
}

static void set_sim_state_c8_test(SFc8_testInstanceStruct *chartInstance, const
  mxArray *c8_st)
{
  const mxArray *c8_u;
  real_T *c8_m;
  c8_m = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  chartInstance->c8_doneDoubleBufferReInit = TRUE;
  c8_u = sf_mex_dup(c8_st);
  *c8_m = c8_c_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c8_u, 0)),
    "m");
  chartInstance->c8_m_last = c8_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c8_u, 1)), "m_last");
  chartInstance->c8_is_active_c8_test = c8_f_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c8_u, 2)), "is_active_c8_test");
  sf_mex_destroy(&c8_u);
  c8_update_debugger_state_c8_test(chartInstance);
  sf_mex_destroy(&c8_st);
}

static void finalize_c8_test(SFc8_testInstanceStruct *chartInstance)
{
}

static void sf_c8_test(SFc8_testInstanceStruct *chartInstance)
{
  real_T c8_hoistedGlobal;
  real_T c8_b_hoistedGlobal;
  real_T c8_m_dot;
  real_T c8_b_h;
  uint32_T c8_debug_family_var_map[6];
  real_T c8_nargin = 2.0;
  real_T c8_nargout = 1.0;
  real_T c8_m;
  real_T c8_c_hoistedGlobal;
  real_T c8_a;
  real_T c8_b;
  real_T c8_y;
  real_T *c8_b_m_dot;
  real_T *c8_b_m;
  c8_b_m = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c8_b_m_dot = (real_T *)ssGetInputPortSignal(chartInstance->S, 0);
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 7U, chartInstance->c8_sfEvent);
  _SFD_DATA_RANGE_CHECK(*c8_b_m_dot, 0U);
  _SFD_DATA_RANGE_CHECK(*c8_b_m, 1U);
  _SFD_DATA_RANGE_CHECK(chartInstance->c8_h, 2U);
  chartInstance->c8_sfEvent = CALL_EVENT;
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 7U, chartInstance->c8_sfEvent);
  c8_hoistedGlobal = *c8_b_m_dot;
  c8_b_hoistedGlobal = chartInstance->c8_h;
  c8_m_dot = c8_hoistedGlobal;
  c8_b_h = c8_b_hoistedGlobal;
  sf_debug_symbol_scope_push_eml(0U, 6U, 6U, c8_debug_family_names,
    c8_debug_family_var_map);
  sf_debug_symbol_scope_add_eml_importable(&c8_nargin, 0U, c8_b_sf_marshallOut,
    c8_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c8_nargout, 1U, c8_b_sf_marshallOut,
    c8_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml(&c8_m_dot, 2U, c8_b_sf_marshallOut);
  sf_debug_symbol_scope_add_eml_importable(&c8_b_h, 3U, c8_b_sf_marshallOut,
    c8_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c8_m, 4U, c8_b_sf_marshallOut,
    c8_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&chartInstance->c8_m_last, 5U,
    c8_sf_marshallOut, c8_sf_marshallIn);
  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(0U, chartInstance->c8_sfEvent, 4);
  _SFD_EML_CALL(0U, chartInstance->c8_sfEvent, 5);
  if (CV_EML_IF(0, 1, 0, !chartInstance->c8_m_last_not_empty)) {
    _SFD_EML_CALL(0U, chartInstance->c8_sfEvent, 6);
    chartInstance->c8_m_last = 0.0;
    chartInstance->c8_m_last_not_empty = TRUE;
  }

  _SFD_EML_CALL(0U, chartInstance->c8_sfEvent, 8);
  c8_c_hoistedGlobal = chartInstance->c8_m_last;
  c8_a = c8_b_h;
  c8_b = c8_m_dot;
  c8_y = c8_a * c8_b;
  c8_m = c8_c_hoistedGlobal + c8_y;
  _SFD_EML_CALL(0U, chartInstance->c8_sfEvent, 9);
  chartInstance->c8_m_last = c8_m;
  _SFD_EML_CALL(0U, chartInstance->c8_sfEvent, -9);
  sf_debug_symbol_scope_pop();
  *c8_b_m = c8_m;
  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 7U, chartInstance->c8_sfEvent);
  sf_debug_check_for_state_inconsistency(_testMachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
}

static void initSimStructsc8_test(SFc8_testInstanceStruct *chartInstance)
{
}

static void init_script_number_translation(uint32_T c8_machineNumber, uint32_T
  c8_chartNumber)
{
}

static const mxArray *c8_sf_marshallOut(void *chartInstanceVoid, void *c8_inData)
{
  const mxArray *c8_mxArrayOutData = NULL;
  real_T c8_u;
  const mxArray *c8_y = NULL;
  SFc8_testInstanceStruct *chartInstance;
  chartInstance = (SFc8_testInstanceStruct *)chartInstanceVoid;
  c8_mxArrayOutData = NULL;
  c8_u = *(real_T *)c8_inData;
  c8_y = NULL;
  if (!chartInstance->c8_m_last_not_empty) {
    sf_mex_assign(&c8_y, sf_mex_create("y", NULL, 0, 0U, 1U, 0U, 2, 0, 0), FALSE);
  } else {
    sf_mex_assign(&c8_y, sf_mex_create("y", &c8_u, 0, 0U, 0U, 0U, 0), FALSE);
  }

  sf_mex_assign(&c8_mxArrayOutData, c8_y, FALSE);
  return c8_mxArrayOutData;
}

static real_T c8_emlrt_marshallIn(SFc8_testInstanceStruct *chartInstance, const
  mxArray *c8_b_m_last, const char_T *c8_identifier)
{
  real_T c8_y;
  emlrtMsgIdentifier c8_thisId;
  c8_thisId.fIdentifier = c8_identifier;
  c8_thisId.fParent = NULL;
  c8_y = c8_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c8_b_m_last),
    &c8_thisId);
  sf_mex_destroy(&c8_b_m_last);
  return c8_y;
}

static real_T c8_b_emlrt_marshallIn(SFc8_testInstanceStruct *chartInstance,
  const mxArray *c8_u, const emlrtMsgIdentifier *c8_parentId)
{
  real_T c8_y;
  real_T c8_d1;
  if (mxIsEmpty(c8_u)) {
    chartInstance->c8_m_last_not_empty = FALSE;
  } else {
    chartInstance->c8_m_last_not_empty = TRUE;
    sf_mex_import(c8_parentId, sf_mex_dup(c8_u), &c8_d1, 1, 0, 0U, 0, 0U, 0);
    c8_y = c8_d1;
  }

  sf_mex_destroy(&c8_u);
  return c8_y;
}

static void c8_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c8_mxArrayInData, const char_T *c8_varName, void *c8_outData)
{
  const mxArray *c8_b_m_last;
  const char_T *c8_identifier;
  emlrtMsgIdentifier c8_thisId;
  real_T c8_y;
  SFc8_testInstanceStruct *chartInstance;
  chartInstance = (SFc8_testInstanceStruct *)chartInstanceVoid;
  c8_b_m_last = sf_mex_dup(c8_mxArrayInData);
  c8_identifier = c8_varName;
  c8_thisId.fIdentifier = c8_identifier;
  c8_thisId.fParent = NULL;
  c8_y = c8_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c8_b_m_last),
    &c8_thisId);
  sf_mex_destroy(&c8_b_m_last);
  *(real_T *)c8_outData = c8_y;
  sf_mex_destroy(&c8_mxArrayInData);
}

static const mxArray *c8_b_sf_marshallOut(void *chartInstanceVoid, void
  *c8_inData)
{
  const mxArray *c8_mxArrayOutData = NULL;
  real_T c8_u;
  const mxArray *c8_y = NULL;
  SFc8_testInstanceStruct *chartInstance;
  chartInstance = (SFc8_testInstanceStruct *)chartInstanceVoid;
  c8_mxArrayOutData = NULL;
  c8_u = *(real_T *)c8_inData;
  c8_y = NULL;
  sf_mex_assign(&c8_y, sf_mex_create("y", &c8_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c8_mxArrayOutData, c8_y, FALSE);
  return c8_mxArrayOutData;
}

static real_T c8_c_emlrt_marshallIn(SFc8_testInstanceStruct *chartInstance,
  const mxArray *c8_m, const char_T *c8_identifier)
{
  real_T c8_y;
  emlrtMsgIdentifier c8_thisId;
  c8_thisId.fIdentifier = c8_identifier;
  c8_thisId.fParent = NULL;
  c8_y = c8_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c8_m), &c8_thisId);
  sf_mex_destroy(&c8_m);
  return c8_y;
}

static real_T c8_d_emlrt_marshallIn(SFc8_testInstanceStruct *chartInstance,
  const mxArray *c8_u, const emlrtMsgIdentifier *c8_parentId)
{
  real_T c8_y;
  real_T c8_d2;
  sf_mex_import(c8_parentId, sf_mex_dup(c8_u), &c8_d2, 1, 0, 0U, 0, 0U, 0);
  c8_y = c8_d2;
  sf_mex_destroy(&c8_u);
  return c8_y;
}

static void c8_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c8_mxArrayInData, const char_T *c8_varName, void *c8_outData)
{
  const mxArray *c8_m;
  const char_T *c8_identifier;
  emlrtMsgIdentifier c8_thisId;
  real_T c8_y;
  SFc8_testInstanceStruct *chartInstance;
  chartInstance = (SFc8_testInstanceStruct *)chartInstanceVoid;
  c8_m = sf_mex_dup(c8_mxArrayInData);
  c8_identifier = c8_varName;
  c8_thisId.fIdentifier = c8_identifier;
  c8_thisId.fParent = NULL;
  c8_y = c8_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c8_m), &c8_thisId);
  sf_mex_destroy(&c8_m);
  *(real_T *)c8_outData = c8_y;
  sf_mex_destroy(&c8_mxArrayInData);
}

const mxArray *sf_c8_test_get_eml_resolved_functions_info(void)
{
  const mxArray *c8_nameCaptureInfo;
  c8_ResolvedFunctionInfo c8_info[1];
  c8_ResolvedFunctionInfo (*c8_b_info)[1];
  const mxArray *c8_m0 = NULL;
  int32_T c8_i0;
  c8_ResolvedFunctionInfo *c8_r0;
  c8_nameCaptureInfo = NULL;
  c8_nameCaptureInfo = NULL;
  c8_b_info = (c8_ResolvedFunctionInfo (*)[1])c8_info;
  (*c8_b_info)[0].context = "";
  (*c8_b_info)[0].name = "mtimes";
  (*c8_b_info)[0].dominantType = "double";
  (*c8_b_info)[0].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  (*c8_b_info)[0].fileTimeLo = 1289494492U;
  (*c8_b_info)[0].fileTimeHi = 0U;
  (*c8_b_info)[0].mFileTimeLo = 0U;
  (*c8_b_info)[0].mFileTimeHi = 0U;
  sf_mex_assign(&c8_m0, sf_mex_createstruct("nameCaptureInfo", 1, 1), FALSE);
  for (c8_i0 = 0; c8_i0 < 1; c8_i0++) {
    c8_r0 = &c8_info[c8_i0];
    sf_mex_addfield(c8_m0, sf_mex_create("nameCaptureInfo", c8_r0->context, 15,
      0U, 0U, 0U, 2, 1, strlen(c8_r0->context)), "context", "nameCaptureInfo",
                    c8_i0);
    sf_mex_addfield(c8_m0, sf_mex_create("nameCaptureInfo", c8_r0->name, 15, 0U,
      0U, 0U, 2, 1, strlen(c8_r0->name)), "name", "nameCaptureInfo", c8_i0);
    sf_mex_addfield(c8_m0, sf_mex_create("nameCaptureInfo", c8_r0->dominantType,
      15, 0U, 0U, 0U, 2, 1, strlen(c8_r0->dominantType)), "dominantType",
                    "nameCaptureInfo", c8_i0);
    sf_mex_addfield(c8_m0, sf_mex_create("nameCaptureInfo", c8_r0->resolved, 15,
      0U, 0U, 0U, 2, 1, strlen(c8_r0->resolved)), "resolved", "nameCaptureInfo",
                    c8_i0);
    sf_mex_addfield(c8_m0, sf_mex_create("nameCaptureInfo", &c8_r0->fileTimeLo,
      7, 0U, 0U, 0U, 0), "fileTimeLo", "nameCaptureInfo", c8_i0);
    sf_mex_addfield(c8_m0, sf_mex_create("nameCaptureInfo", &c8_r0->fileTimeHi,
      7, 0U, 0U, 0U, 0), "fileTimeHi", "nameCaptureInfo", c8_i0);
    sf_mex_addfield(c8_m0, sf_mex_create("nameCaptureInfo", &c8_r0->mFileTimeLo,
      7, 0U, 0U, 0U, 0), "mFileTimeLo", "nameCaptureInfo", c8_i0);
    sf_mex_addfield(c8_m0, sf_mex_create("nameCaptureInfo", &c8_r0->mFileTimeHi,
      7, 0U, 0U, 0U, 0), "mFileTimeHi", "nameCaptureInfo", c8_i0);
  }

  sf_mex_assign(&c8_nameCaptureInfo, c8_m0, FALSE);
  sf_mex_emlrtNameCapturePostProcessR2012a(&c8_nameCaptureInfo);
  return c8_nameCaptureInfo;
}

static const mxArray *c8_c_sf_marshallOut(void *chartInstanceVoid, void
  *c8_inData)
{
  const mxArray *c8_mxArrayOutData = NULL;
  int32_T c8_u;
  const mxArray *c8_y = NULL;
  SFc8_testInstanceStruct *chartInstance;
  chartInstance = (SFc8_testInstanceStruct *)chartInstanceVoid;
  c8_mxArrayOutData = NULL;
  c8_u = *(int32_T *)c8_inData;
  c8_y = NULL;
  sf_mex_assign(&c8_y, sf_mex_create("y", &c8_u, 6, 0U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c8_mxArrayOutData, c8_y, FALSE);
  return c8_mxArrayOutData;
}

static int32_T c8_e_emlrt_marshallIn(SFc8_testInstanceStruct *chartInstance,
  const mxArray *c8_u, const emlrtMsgIdentifier *c8_parentId)
{
  int32_T c8_y;
  int32_T c8_i1;
  sf_mex_import(c8_parentId, sf_mex_dup(c8_u), &c8_i1, 1, 6, 0U, 0, 0U, 0);
  c8_y = c8_i1;
  sf_mex_destroy(&c8_u);
  return c8_y;
}

static void c8_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c8_mxArrayInData, const char_T *c8_varName, void *c8_outData)
{
  const mxArray *c8_b_sfEvent;
  const char_T *c8_identifier;
  emlrtMsgIdentifier c8_thisId;
  int32_T c8_y;
  SFc8_testInstanceStruct *chartInstance;
  chartInstance = (SFc8_testInstanceStruct *)chartInstanceVoid;
  c8_b_sfEvent = sf_mex_dup(c8_mxArrayInData);
  c8_identifier = c8_varName;
  c8_thisId.fIdentifier = c8_identifier;
  c8_thisId.fParent = NULL;
  c8_y = c8_e_emlrt_marshallIn(chartInstance, sf_mex_dup(c8_b_sfEvent),
    &c8_thisId);
  sf_mex_destroy(&c8_b_sfEvent);
  *(int32_T *)c8_outData = c8_y;
  sf_mex_destroy(&c8_mxArrayInData);
}

static uint8_T c8_f_emlrt_marshallIn(SFc8_testInstanceStruct *chartInstance,
  const mxArray *c8_b_is_active_c8_test, const char_T *c8_identifier)
{
  uint8_T c8_y;
  emlrtMsgIdentifier c8_thisId;
  c8_thisId.fIdentifier = c8_identifier;
  c8_thisId.fParent = NULL;
  c8_y = c8_g_emlrt_marshallIn(chartInstance, sf_mex_dup(c8_b_is_active_c8_test),
    &c8_thisId);
  sf_mex_destroy(&c8_b_is_active_c8_test);
  return c8_y;
}

static uint8_T c8_g_emlrt_marshallIn(SFc8_testInstanceStruct *chartInstance,
  const mxArray *c8_u, const emlrtMsgIdentifier *c8_parentId)
{
  uint8_T c8_y;
  uint8_T c8_u0;
  sf_mex_import(c8_parentId, sf_mex_dup(c8_u), &c8_u0, 1, 3, 0U, 0, 0U, 0);
  c8_y = c8_u0;
  sf_mex_destroy(&c8_u);
  return c8_y;
}

static void init_dsm_address_info(SFc8_testInstanceStruct *chartInstance)
{
}

/* SFunction Glue Code */
void sf_c8_test_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(223002177U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(3973936808U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(2967282982U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(3715370516U);
}

mxArray *sf_c8_test_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1,1,5,
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateString("6oGaNLWpm923PuWSM6HOC");
    mxSetField(mxAutoinheritanceInfo,0,"checksum",mxChecksum);
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

static const mxArray *sf_get_sim_state_info_c8_test(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x3'type','srcId','name','auxInfo'{{M[1],M[5],T\"m\",},{M[4],M[0],T\"m_last\",S'l','i','p'{{M1x2[58 64],M[0],}}},{M[8],M[0],T\"is_active_c8_test\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 3, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c8_test_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc8_testInstanceStruct *chartInstance;
    chartInstance = (SFc8_testInstanceStruct *) ((ChartInfoStruct *)
      (ssGetUserData(S)))->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart(_testMachineNumber_,
          8,
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
          _SFD_SET_DATA_PROPS(0,1,1,0,"m_dot");
          _SFD_SET_DATA_PROPS(1,2,0,1,"m");
          _SFD_SET_DATA_PROPS(2,10,0,0,"h");
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
        _SFD_CV_INIT_EML(0,1,1,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_FCN(0,0,"eML_blk_kernel",0,-1,132);
        _SFD_CV_INIT_EML_IF(0,1,0,66,84,-1,102);
        _SFD_TRANS_COV_WTS(0,0,0,1,0);
        if (chartAlreadyPresent==0) {
          _SFD_TRANS_COV_MAPS(0,
                              0,NULL,NULL,
                              0,NULL,NULL,
                              1,NULL,NULL,
                              0,NULL,NULL);
        }

        _SFD_SET_DATA_COMPILED_PROPS(0,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c8_b_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(1,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c8_b_sf_marshallOut,(MexInFcnForType)c8_b_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(2,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c8_b_sf_marshallOut,(MexInFcnForType)c8_b_sf_marshallIn);

        {
          real_T *c8_m_dot;
          real_T *c8_m;
          c8_m = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
          c8_m_dot = (real_T *)ssGetInputPortSignal(chartInstance->S, 0);
          _SFD_SET_DATA_VALUE_PTR(0U, c8_m_dot);
          _SFD_SET_DATA_VALUE_PTR(1U, c8_m);
          _SFD_SET_DATA_VALUE_PTR(2U, &chartInstance->c8_h);
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
  return "k87Wg10ViI6joazs5yiCHH";
}

static void sf_opaque_initialize_c8_test(void *chartInstanceVar)
{
  chart_debug_initialization(((SFc8_testInstanceStruct*) chartInstanceVar)->S,0);
  initialize_params_c8_test((SFc8_testInstanceStruct*) chartInstanceVar);
  initialize_c8_test((SFc8_testInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_enable_c8_test(void *chartInstanceVar)
{
  enable_c8_test((SFc8_testInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_disable_c8_test(void *chartInstanceVar)
{
  disable_c8_test((SFc8_testInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_gateway_c8_test(void *chartInstanceVar)
{
  sf_c8_test((SFc8_testInstanceStruct*) chartInstanceVar);
}

extern const mxArray* sf_internal_get_sim_state_c8_test(SimStruct* S)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_raw2high");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = (mxArray*) get_sim_state_c8_test((SFc8_testInstanceStruct*)
    chartInfo->chartInstance);         /* raw sim ctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c8_test();/* state var info */
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

extern void sf_internal_set_sim_state_c8_test(SimStruct* S, const mxArray *st)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_high2raw");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = mxDuplicateArray(st);      /* high level simctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c8_test();/* state var info */
  mxError = sf_mex_call_matlab(1, plhs, 4, prhs, "sfprivate");
  mxDestroyArray(prhs[0]);
  mxDestroyArray(prhs[1]);
  mxDestroyArray(prhs[2]);
  mxDestroyArray(prhs[3]);
  if (mxError || plhs[0] == NULL) {
    sf_mex_error_message("Stateflow Internal Error: \nError calling 'chart_simctx_high2raw'.\n");
  }

  set_sim_state_c8_test((SFc8_testInstanceStruct*)chartInfo->chartInstance,
                        mxDuplicateArray(plhs[0]));
  mxDestroyArray(plhs[0]);
}

static const mxArray* sf_opaque_get_sim_state_c8_test(SimStruct* S)
{
  return sf_internal_get_sim_state_c8_test(S);
}

static void sf_opaque_set_sim_state_c8_test(SimStruct* S, const mxArray *st)
{
  sf_internal_set_sim_state_c8_test(S, st);
}

static void sf_opaque_terminate_c8_test(void *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc8_testInstanceStruct*) chartInstanceVar)->S;
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
    }

    finalize_c8_test((SFc8_testInstanceStruct*) chartInstanceVar);
    free((void *)chartInstanceVar);
    ssSetUserData(S,NULL);
  }

  unload_test_optimization_info();
}

static void sf_opaque_init_subchart_simstructs(void *chartInstanceVar)
{
  initSimStructsc8_test((SFc8_testInstanceStruct*) chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c8_test(SimStruct *S)
{
  int i;
  for (i=0;i<ssGetNumRunTimeParams(S);i++) {
    if (ssGetSFcnParamTunable(S,i)) {
      ssUpdateDlgParamAsRunTimeParam(S,i);
    }
  }

  if (sf_machine_global_initializer_called()) {
    initialize_params_c8_test((SFc8_testInstanceStruct*)(((ChartInfoStruct *)
      ssGetUserData(S))->chartInstance));
  }
}

static void mdlSetWorkWidths_c8_test(SimStruct *S)
{
  /* Actual parameters from chart:
     h
   */
  const char_T *rtParamNames[] = { "p1" };

  ssSetNumRunTimeParams(S,ssGetSFcnParamsCount(S));

  /* registration for h*/
  ssRegDlgParamAsRunTimeParam(S, 0, 0, rtParamNames[0], SS_DOUBLE);
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    mxArray *infoStruct = load_test_optimization_info();
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable(S,sf_get_instance_specialization(),infoStruct,
      8);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop(S,sf_get_instance_specialization(),
                infoStruct,8,"RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop(S,
      sf_get_instance_specialization(),infoStruct,8,
      "gatewayCannotBeInlinedMultipleTimes"));
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,sf_get_instance_specialization(),
        infoStruct,8,1);
      sf_mark_chart_reusable_outputs(S,sf_get_instance_specialization(),
        infoStruct,8,1);
    }

    sf_set_rtw_dwork_info(S,sf_get_instance_specialization(),infoStruct,8);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(1895180520U));
  ssSetChecksum1(S,(3240160944U));
  ssSetChecksum2(S,(1735152811U));
  ssSetChecksum3(S,(2060233260U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
  ssSupportsMultipleExecInstances(S,1);
}

static void mdlRTW_c8_test(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c8_test(SimStruct *S)
{
  SFc8_testInstanceStruct *chartInstance;
  chartInstance = (SFc8_testInstanceStruct *)malloc(sizeof
    (SFc8_testInstanceStruct));
  memset(chartInstance, 0, sizeof(SFc8_testInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway = sf_opaque_gateway_c8_test;
  chartInstance->chartInfo.initializeChart = sf_opaque_initialize_c8_test;
  chartInstance->chartInfo.terminateChart = sf_opaque_terminate_c8_test;
  chartInstance->chartInfo.enableChart = sf_opaque_enable_c8_test;
  chartInstance->chartInfo.disableChart = sf_opaque_disable_c8_test;
  chartInstance->chartInfo.getSimState = sf_opaque_get_sim_state_c8_test;
  chartInstance->chartInfo.setSimState = sf_opaque_set_sim_state_c8_test;
  chartInstance->chartInfo.getSimStateInfo = sf_get_sim_state_info_c8_test;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c8_test;
  chartInstance->chartInfo.mdlStart = mdlStart_c8_test;
  chartInstance->chartInfo.mdlSetWorkWidths = mdlSetWorkWidths_c8_test;
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

void c8_test_method_dispatcher(SimStruct *S, int_T method, void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c8_test(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c8_test(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c8_test(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c8_test_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}

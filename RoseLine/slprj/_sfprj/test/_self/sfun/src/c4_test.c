/* Include files */

#include "blascompat32.h"
#include "test_sfun.h"
#include "c4_test.h"
#include "mwmathutil.h"
#define CHARTINSTANCE_CHARTNUMBER      (chartInstance->chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER   (chartInstance->instanceNumber)
#include "test_sfun_debug_macros.h"

/* Type Definitions */

/* Named Constants */
#define CALL_EVENT                     (-1)

/* Variable Declarations */

/* Variable Definitions */
static const char * c4_debug_family_names[12] = { "ww", "x", "y", "x_dot",
  "y_dot", "nargin", "nargout", "m", "Dis_Path_o", "R_po", "r_c", "Theta_po" };

/* Function Declarations */
static void initialize_c4_test(SFc4_testInstanceStruct *chartInstance);
static void initialize_params_c4_test(SFc4_testInstanceStruct *chartInstance);
static void enable_c4_test(SFc4_testInstanceStruct *chartInstance);
static void disable_c4_test(SFc4_testInstanceStruct *chartInstance);
static void c4_update_debugger_state_c4_test(SFc4_testInstanceStruct
  *chartInstance);
static const mxArray *get_sim_state_c4_test(SFc4_testInstanceStruct
  *chartInstance);
static void set_sim_state_c4_test(SFc4_testInstanceStruct *chartInstance, const
  mxArray *c4_st);
static void finalize_c4_test(SFc4_testInstanceStruct *chartInstance);
static void sf_c4_test(SFc4_testInstanceStruct *chartInstance);
static void c4_chartstep_c4_test(SFc4_testInstanceStruct *chartInstance);
static void initSimStructsc4_test(SFc4_testInstanceStruct *chartInstance);
static void init_script_number_translation(uint32_T c4_machineNumber, uint32_T
  c4_chartNumber);
static const mxArray *c4_sf_marshallOut(void *chartInstanceVoid, void *c4_inData);
static real_T c4_emlrt_marshallIn(SFc4_testInstanceStruct *chartInstance, const
  mxArray *c4_Theta_po, const char_T *c4_identifier);
static real_T c4_b_emlrt_marshallIn(SFc4_testInstanceStruct *chartInstance,
  const mxArray *c4_u, const emlrtMsgIdentifier *c4_parentId);
static void c4_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c4_mxArrayInData, const char_T *c4_varName, void *c4_outData);
static const mxArray *c4_b_sf_marshallOut(void *chartInstanceVoid, void
  *c4_inData);
static void c4_c_emlrt_marshallIn(SFc4_testInstanceStruct *chartInstance, const
  mxArray *c4_R_po, const char_T *c4_identifier, real_T c4_y[4]);
static void c4_d_emlrt_marshallIn(SFc4_testInstanceStruct *chartInstance, const
  mxArray *c4_u, const emlrtMsgIdentifier *c4_parentId, real_T c4_y[4]);
static void c4_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c4_mxArrayInData, const char_T *c4_varName, void *c4_outData);
static const mxArray *c4_c_sf_marshallOut(void *chartInstanceVoid, void
  *c4_inData);
static void c4_e_emlrt_marshallIn(SFc4_testInstanceStruct *chartInstance, const
  mxArray *c4_Dis_Path_o, const char_T *c4_identifier, real_T c4_y[2]);
static void c4_f_emlrt_marshallIn(SFc4_testInstanceStruct *chartInstance, const
  mxArray *c4_u, const emlrtMsgIdentifier *c4_parentId, real_T c4_y[2]);
static void c4_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c4_mxArrayInData, const char_T *c4_varName, void *c4_outData);
static void c4_info_helper(c4_ResolvedFunctionInfo c4_info[23]);
static real_T c4_mpower(SFc4_testInstanceStruct *chartInstance, real_T c4_a);
static void c4_eml_error(SFc4_testInstanceStruct *chartInstance);
static const mxArray *c4_d_sf_marshallOut(void *chartInstanceVoid, void
  *c4_inData);
static int32_T c4_g_emlrt_marshallIn(SFc4_testInstanceStruct *chartInstance,
  const mxArray *c4_u, const emlrtMsgIdentifier *c4_parentId);
static void c4_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c4_mxArrayInData, const char_T *c4_varName, void *c4_outData);
static uint8_T c4_h_emlrt_marshallIn(SFc4_testInstanceStruct *chartInstance,
  const mxArray *c4_b_is_active_c4_test, const char_T *c4_identifier);
static uint8_T c4_i_emlrt_marshallIn(SFc4_testInstanceStruct *chartInstance,
  const mxArray *c4_u, const emlrtMsgIdentifier *c4_parentId);
static void init_dsm_address_info(SFc4_testInstanceStruct *chartInstance);

/* Function Definitions */
static void initialize_c4_test(SFc4_testInstanceStruct *chartInstance)
{
  chartInstance->c4_sfEvent = CALL_EVENT;
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  chartInstance->c4_is_active_c4_test = 0U;
}

static void initialize_params_c4_test(SFc4_testInstanceStruct *chartInstance)
{
}

static void enable_c4_test(SFc4_testInstanceStruct *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void disable_c4_test(SFc4_testInstanceStruct *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void c4_update_debugger_state_c4_test(SFc4_testInstanceStruct
  *chartInstance)
{
}

static const mxArray *get_sim_state_c4_test(SFc4_testInstanceStruct
  *chartInstance)
{
  const mxArray *c4_st;
  const mxArray *c4_y = NULL;
  int32_T c4_i0;
  real_T c4_u[2];
  const mxArray *c4_b_y = NULL;
  int32_T c4_i1;
  real_T c4_b_u[4];
  const mxArray *c4_c_y = NULL;
  real_T c4_hoistedGlobal;
  real_T c4_c_u;
  const mxArray *c4_d_y = NULL;
  real_T c4_b_hoistedGlobal;
  real_T c4_d_u;
  const mxArray *c4_e_y = NULL;
  uint8_T c4_c_hoistedGlobal;
  uint8_T c4_e_u;
  const mxArray *c4_f_y = NULL;
  real_T *c4_Theta_po;
  real_T *c4_r_c;
  real_T (*c4_R_po)[4];
  real_T (*c4_Dis_Path_o)[2];
  c4_Theta_po = (real_T *)ssGetOutputPortSignal(chartInstance->S, 4);
  c4_r_c = (real_T *)ssGetOutputPortSignal(chartInstance->S, 3);
  c4_R_po = (real_T (*)[4])ssGetOutputPortSignal(chartInstance->S, 2);
  c4_Dis_Path_o = (real_T (*)[2])ssGetOutputPortSignal(chartInstance->S, 1);
  c4_st = NULL;
  c4_st = NULL;
  c4_y = NULL;
  sf_mex_assign(&c4_y, sf_mex_createcellarray(5), FALSE);
  for (c4_i0 = 0; c4_i0 < 2; c4_i0++) {
    c4_u[c4_i0] = (*c4_Dis_Path_o)[c4_i0];
  }

  c4_b_y = NULL;
  sf_mex_assign(&c4_b_y, sf_mex_create("y", c4_u, 0, 0U, 1U, 0U, 1, 2), FALSE);
  sf_mex_setcell(c4_y, 0, c4_b_y);
  for (c4_i1 = 0; c4_i1 < 4; c4_i1++) {
    c4_b_u[c4_i1] = (*c4_R_po)[c4_i1];
  }

  c4_c_y = NULL;
  sf_mex_assign(&c4_c_y, sf_mex_create("y", c4_b_u, 0, 0U, 1U, 0U, 2, 2, 2),
                FALSE);
  sf_mex_setcell(c4_y, 1, c4_c_y);
  c4_hoistedGlobal = *c4_Theta_po;
  c4_c_u = c4_hoistedGlobal;
  c4_d_y = NULL;
  sf_mex_assign(&c4_d_y, sf_mex_create("y", &c4_c_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c4_y, 2, c4_d_y);
  c4_b_hoistedGlobal = *c4_r_c;
  c4_d_u = c4_b_hoistedGlobal;
  c4_e_y = NULL;
  sf_mex_assign(&c4_e_y, sf_mex_create("y", &c4_d_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c4_y, 3, c4_e_y);
  c4_c_hoistedGlobal = chartInstance->c4_is_active_c4_test;
  c4_e_u = c4_c_hoistedGlobal;
  c4_f_y = NULL;
  sf_mex_assign(&c4_f_y, sf_mex_create("y", &c4_e_u, 3, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c4_y, 4, c4_f_y);
  sf_mex_assign(&c4_st, c4_y, FALSE);
  return c4_st;
}

static void set_sim_state_c4_test(SFc4_testInstanceStruct *chartInstance, const
  mxArray *c4_st)
{
  const mxArray *c4_u;
  real_T c4_dv0[2];
  int32_T c4_i2;
  real_T c4_dv1[4];
  int32_T c4_i3;
  real_T *c4_Theta_po;
  real_T *c4_r_c;
  real_T (*c4_Dis_Path_o)[2];
  real_T (*c4_R_po)[4];
  c4_Theta_po = (real_T *)ssGetOutputPortSignal(chartInstance->S, 4);
  c4_r_c = (real_T *)ssGetOutputPortSignal(chartInstance->S, 3);
  c4_R_po = (real_T (*)[4])ssGetOutputPortSignal(chartInstance->S, 2);
  c4_Dis_Path_o = (real_T (*)[2])ssGetOutputPortSignal(chartInstance->S, 1);
  chartInstance->c4_doneDoubleBufferReInit = TRUE;
  c4_u = sf_mex_dup(c4_st);
  c4_e_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c4_u, 0)),
                        "Dis_Path_o", c4_dv0);
  for (c4_i2 = 0; c4_i2 < 2; c4_i2++) {
    (*c4_Dis_Path_o)[c4_i2] = c4_dv0[c4_i2];
  }

  c4_c_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c4_u, 1)),
                        "R_po", c4_dv1);
  for (c4_i3 = 0; c4_i3 < 4; c4_i3++) {
    (*c4_R_po)[c4_i3] = c4_dv1[c4_i3];
  }

  *c4_Theta_po = c4_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell
    (c4_u, 2)), "Theta_po");
  *c4_r_c = c4_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c4_u, 3)),
    "r_c");
  chartInstance->c4_is_active_c4_test = c4_h_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c4_u, 4)), "is_active_c4_test");
  sf_mex_destroy(&c4_u);
  c4_update_debugger_state_c4_test(chartInstance);
  sf_mex_destroy(&c4_st);
}

static void finalize_c4_test(SFc4_testInstanceStruct *chartInstance)
{
}

static void sf_c4_test(SFc4_testInstanceStruct *chartInstance)
{
  int32_T c4_i4;
  int32_T c4_i5;
  real_T *c4_m;
  real_T *c4_r_c;
  real_T *c4_Theta_po;
  real_T (*c4_R_po)[4];
  real_T (*c4_Dis_Path_o)[2];
  c4_Theta_po = (real_T *)ssGetOutputPortSignal(chartInstance->S, 4);
  c4_r_c = (real_T *)ssGetOutputPortSignal(chartInstance->S, 3);
  c4_R_po = (real_T (*)[4])ssGetOutputPortSignal(chartInstance->S, 2);
  c4_Dis_Path_o = (real_T (*)[2])ssGetOutputPortSignal(chartInstance->S, 1);
  c4_m = (real_T *)ssGetInputPortSignal(chartInstance->S, 0);
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 3U, chartInstance->c4_sfEvent);
  _SFD_DATA_RANGE_CHECK(*c4_m, 0U);
  for (c4_i4 = 0; c4_i4 < 2; c4_i4++) {
    _SFD_DATA_RANGE_CHECK((*c4_Dis_Path_o)[c4_i4], 1U);
  }

  for (c4_i5 = 0; c4_i5 < 4; c4_i5++) {
    _SFD_DATA_RANGE_CHECK((*c4_R_po)[c4_i5], 2U);
  }

  _SFD_DATA_RANGE_CHECK(*c4_r_c, 3U);
  _SFD_DATA_RANGE_CHECK(*c4_Theta_po, 4U);
  chartInstance->c4_sfEvent = CALL_EVENT;
  c4_chartstep_c4_test(chartInstance);
  sf_debug_check_for_state_inconsistency(_testMachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
}

static void c4_chartstep_c4_test(SFc4_testInstanceStruct *chartInstance)
{
  real_T c4_hoistedGlobal;
  real_T c4_m;
  uint32_T c4_debug_family_var_map[12];
  real_T c4_ww;
  real_T c4_x;
  real_T c4_y;
  real_T c4_x_dot;
  real_T c4_y_dot;
  real_T c4_nargin = 1.0;
  real_T c4_nargout = 4.0;
  real_T c4_Dis_Path_o[2];
  real_T c4_R_po[4];
  real_T c4_r_c;
  real_T c4_Theta_po;
  real_T c4_b;
  real_T c4_b_y;
  real_T c4_b_x;
  real_T c4_c_x;
  real_T c4_b_b;
  real_T c4_c_y;
  real_T c4_c_b;
  real_T c4_d_y;
  real_T c4_d_x;
  real_T c4_e_x;
  real_T c4_a;
  real_T c4_d_b;
  real_T c4_e_b;
  real_T c4_e_y;
  real_T c4_f_x;
  real_T c4_g_x;
  real_T c4_f_b;
  real_T c4_f_y;
  real_T c4_g_b;
  real_T c4_g_y;
  real_T c4_h_x;
  real_T c4_i_x;
  real_T c4_b_a;
  real_T c4_h_b;
  real_T c4_i_b;
  real_T c4_h_y;
  real_T c4_j_x;
  real_T c4_k_x;
  real_T c4_j_b;
  real_T c4_i_y;
  real_T c4_k_b;
  real_T c4_j_y;
  real_T c4_l_x;
  real_T c4_m_x;
  real_T c4_c_a;
  real_T c4_l_b;
  real_T c4_k_y;
  real_T c4_m_b;
  real_T c4_l_y;
  real_T c4_n_x;
  real_T c4_o_x;
  real_T c4_n_b;
  real_T c4_m_y;
  real_T c4_o_b;
  real_T c4_n_y;
  real_T c4_p_x;
  real_T c4_q_x;
  real_T c4_d_a;
  real_T c4_p_b;
  real_T c4_o_y;
  real_T c4_q_b;
  real_T c4_p_y;
  real_T c4_r_x;
  real_T c4_s_x;
  real_T c4_r_b;
  real_T c4_q_y;
  real_T c4_s_b;
  real_T c4_r_y;
  real_T c4_t_x;
  real_T c4_u_x;
  real_T c4_e_a;
  real_T c4_t_b;
  real_T c4_s_y;
  real_T c4_u_b;
  real_T c4_t_y;
  real_T c4_v_x;
  real_T c4_w_x;
  real_T c4_v_b;
  real_T c4_u_y;
  real_T c4_w_b;
  real_T c4_v_y;
  real_T c4_x_x;
  real_T c4_y_x;
  real_T c4_f_a;
  real_T c4_x_b;
  real_T c4_w_y;
  real_T c4_ab_x[2];
  int32_T c4_i6;
  real_T c4_bb_x;
  real_T c4_cb_x;
  real_T c4_A;
  real_T c4_B;
  real_T c4_db_x;
  real_T c4_x_y;
  real_T c4_eb_x;
  real_T c4_y_y;
  real_T c4_ab_y;
  real_T c4_fb_x;
  real_T c4_gb_x;
  real_T c4_b_A;
  real_T c4_b_B;
  real_T c4_hb_x;
  real_T c4_bb_y;
  real_T c4_ib_x;
  real_T c4_cb_y;
  real_T c4_db_y;
  real_T c4_jb_x;
  real_T c4_kb_x;
  real_T c4_c_A;
  real_T c4_c_B;
  real_T c4_lb_x;
  real_T c4_eb_y;
  real_T c4_mb_x;
  real_T c4_fb_y;
  real_T c4_gb_y;
  real_T c4_nb_x;
  real_T c4_ob_x;
  real_T c4_d_A;
  real_T c4_d_B;
  real_T c4_pb_x;
  real_T c4_hb_y;
  real_T c4_qb_x;
  real_T c4_ib_y;
  real_T c4_jb_y;
  real_T c4_rb_x;
  real_T c4_sb_x;
  real_T c4_tb_x;
  real_T c4_ub_x;
  real_T c4_kb_y;
  real_T c4_vb_x;
  real_T c4_wb_x;
  real_T c4_e_A;
  real_T c4_xb_x;
  real_T c4_yb_x;
  real_T c4_lb_y;
  real_T c4_ac_x;
  real_T c4_bc_x;
  real_T c4_g_a;
  real_T c4_y_b;
  real_T c4_mb_y;
  real_T c4_cc_x;
  real_T c4_dc_x;
  real_T c4_h_a;
  real_T c4_ab_b;
  real_T c4_nb_y;
  real_T c4_i_a;
  real_T c4_ob_y;
  real_T c4_f_A;
  real_T c4_ec_x;
  real_T c4_fc_x;
  real_T c4_pb_y;
  real_T c4_g_A;
  real_T c4_e_B;
  real_T c4_gc_x;
  real_T c4_qb_y;
  real_T c4_hc_x;
  real_T c4_rb_y;
  real_T c4_sb_y;
  real_T c4_ic_x;
  real_T c4_jc_x;
  int32_T c4_i7;
  int32_T c4_i8;
  real_T *c4_b_Theta_po;
  real_T *c4_b_r_c;
  real_T *c4_b_m;
  real_T (*c4_b_Dis_Path_o)[2];
  real_T (*c4_b_R_po)[4];
  c4_b_Theta_po = (real_T *)ssGetOutputPortSignal(chartInstance->S, 4);
  c4_b_r_c = (real_T *)ssGetOutputPortSignal(chartInstance->S, 3);
  c4_b_R_po = (real_T (*)[4])ssGetOutputPortSignal(chartInstance->S, 2);
  c4_b_Dis_Path_o = (real_T (*)[2])ssGetOutputPortSignal(chartInstance->S, 1);
  c4_b_m = (real_T *)ssGetInputPortSignal(chartInstance->S, 0);
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 3U, chartInstance->c4_sfEvent);
  c4_hoistedGlobal = *c4_b_m;
  c4_m = c4_hoistedGlobal;
  sf_debug_symbol_scope_push_eml(0U, 12U, 12U, c4_debug_family_names,
    c4_debug_family_var_map);
  sf_debug_symbol_scope_add_eml(&c4_ww, 0U, c4_sf_marshallOut);
  sf_debug_symbol_scope_add_eml_importable(&c4_x, 1U, c4_sf_marshallOut,
    c4_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c4_y, 2U, c4_sf_marshallOut,
    c4_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c4_x_dot, 3U, c4_sf_marshallOut,
    c4_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c4_y_dot, 4U, c4_sf_marshallOut,
    c4_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c4_nargin, 5U, c4_sf_marshallOut,
    c4_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c4_nargout, 6U, c4_sf_marshallOut,
    c4_sf_marshallIn);
  sf_debug_symbol_scope_add_eml(&c4_m, 7U, c4_sf_marshallOut);
  sf_debug_symbol_scope_add_eml_importable(c4_Dis_Path_o, 8U,
    c4_c_sf_marshallOut, c4_c_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(c4_R_po, 9U, c4_b_sf_marshallOut,
    c4_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c4_r_c, 10U, c4_sf_marshallOut,
    c4_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c4_Theta_po, 11U, c4_sf_marshallOut,
    c4_sf_marshallIn);
  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, 5);
  c4_ww = 0.3;
  _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, 6);
  c4_b = c4_m;
  c4_b_y = 0.01 * c4_b;
  c4_b_x = c4_b_y;
  c4_c_x = c4_b_x;
  c4_c_x = muDoubleScalarSin(c4_c_x);
  c4_b_b = c4_c_x;
  c4_c_y = 7000.0 * c4_b_b;
  c4_c_b = c4_m;
  c4_d_y = 0.0033333333333333335 * c4_c_b;
  c4_d_x = c4_d_y;
  c4_e_x = c4_d_x;
  c4_e_x = muDoubleScalarCos(c4_e_x);
  c4_a = c4_c_y;
  c4_d_b = c4_e_x;
  c4_x = c4_a * c4_d_b;
  _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, 7);
  c4_e_b = c4_m;
  c4_e_y = 0.01 * c4_e_b;
  c4_f_x = c4_e_y;
  c4_g_x = c4_f_x;
  c4_g_x = muDoubleScalarSin(c4_g_x);
  c4_f_b = c4_g_x;
  c4_f_y = 7000.0 * c4_f_b;
  c4_g_b = c4_m;
  c4_g_y = 0.0033333333333333335 * c4_g_b;
  c4_h_x = c4_g_y;
  c4_i_x = c4_h_x;
  c4_i_x = muDoubleScalarSin(c4_i_x);
  c4_b_a = c4_f_y;
  c4_h_b = c4_i_x;
  c4_y = c4_b_a * c4_h_b;
  _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, 8);
  c4_i_b = c4_m;
  c4_h_y = 0.01 * c4_i_b;
  c4_j_x = c4_h_y;
  c4_k_x = c4_j_x;
  c4_k_x = muDoubleScalarCos(c4_k_x);
  c4_j_b = c4_k_x;
  c4_i_y = 70.0 * c4_j_b;
  c4_k_b = c4_m;
  c4_j_y = 0.0033333333333333335 * c4_k_b;
  c4_l_x = c4_j_y;
  c4_m_x = c4_l_x;
  c4_m_x = muDoubleScalarCos(c4_m_x);
  c4_c_a = c4_i_y;
  c4_l_b = c4_m_x;
  c4_k_y = c4_c_a * c4_l_b;
  c4_m_b = c4_m;
  c4_l_y = 0.01 * c4_m_b;
  c4_n_x = c4_l_y;
  c4_o_x = c4_n_x;
  c4_o_x = muDoubleScalarSin(c4_o_x);
  c4_n_b = c4_o_x;
  c4_m_y = 23.333333333333336 * c4_n_b;
  c4_o_b = c4_m;
  c4_n_y = 0.0033333333333333335 * c4_o_b;
  c4_p_x = c4_n_y;
  c4_q_x = c4_p_x;
  c4_q_x = muDoubleScalarSin(c4_q_x);
  c4_d_a = c4_m_y;
  c4_p_b = c4_q_x;
  c4_o_y = c4_d_a * c4_p_b;
  c4_x_dot = c4_k_y - c4_o_y;
  _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, 9);
  c4_q_b = c4_m;
  c4_p_y = 0.01 * c4_q_b;
  c4_r_x = c4_p_y;
  c4_s_x = c4_r_x;
  c4_s_x = muDoubleScalarCos(c4_s_x);
  c4_r_b = c4_s_x;
  c4_q_y = 70.0 * c4_r_b;
  c4_s_b = c4_m;
  c4_r_y = 0.0033333333333333335 * c4_s_b;
  c4_t_x = c4_r_y;
  c4_u_x = c4_t_x;
  c4_u_x = muDoubleScalarSin(c4_u_x);
  c4_e_a = c4_q_y;
  c4_t_b = c4_u_x;
  c4_s_y = c4_e_a * c4_t_b;
  c4_u_b = c4_m;
  c4_t_y = 0.01 * c4_u_b;
  c4_v_x = c4_t_y;
  c4_w_x = c4_v_x;
  c4_w_x = muDoubleScalarSin(c4_w_x);
  c4_v_b = c4_w_x;
  c4_u_y = 23.333333333333336 * c4_v_b;
  c4_w_b = c4_m;
  c4_v_y = 0.0033333333333333335 * c4_w_b;
  c4_x_x = c4_v_y;
  c4_y_x = c4_x_x;
  c4_y_x = muDoubleScalarCos(c4_y_x);
  c4_f_a = c4_u_y;
  c4_x_b = c4_y_x;
  c4_w_y = c4_f_a * c4_x_b;
  c4_y_dot = c4_s_y + c4_w_y;
  _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, 20);
  c4_ab_x[0] = c4_x;
  c4_ab_x[1] = c4_y;
  for (c4_i6 = 0; c4_i6 < 2; c4_i6++) {
    c4_Dis_Path_o[c4_i6] = c4_ab_x[c4_i6];
  }

  _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, 21);
  c4_bb_x = c4_mpower(chartInstance, c4_x_dot) + c4_mpower(chartInstance,
    c4_y_dot);
  c4_cb_x = c4_bb_x;
  if (c4_cb_x < 0.0) {
    c4_eml_error(chartInstance);
  }

  c4_cb_x = muDoubleScalarSqrt(c4_cb_x);
  c4_A = c4_x_dot;
  c4_B = c4_cb_x;
  c4_db_x = c4_A;
  c4_x_y = c4_B;
  c4_eb_x = c4_db_x;
  c4_y_y = c4_x_y;
  c4_ab_y = c4_eb_x / c4_y_y;
  c4_fb_x = c4_mpower(chartInstance, c4_x_dot) + c4_mpower(chartInstance,
    c4_y_dot);
  c4_gb_x = c4_fb_x;
  if (c4_gb_x < 0.0) {
    c4_eml_error(chartInstance);
  }

  c4_gb_x = muDoubleScalarSqrt(c4_gb_x);
  c4_b_A = c4_y_dot;
  c4_b_B = c4_gb_x;
  c4_hb_x = c4_b_A;
  c4_bb_y = c4_b_B;
  c4_ib_x = c4_hb_x;
  c4_cb_y = c4_bb_y;
  c4_db_y = c4_ib_x / c4_cb_y;
  c4_jb_x = c4_mpower(chartInstance, c4_x_dot) + c4_mpower(chartInstance,
    c4_y_dot);
  c4_kb_x = c4_jb_x;
  if (c4_kb_x < 0.0) {
    c4_eml_error(chartInstance);
  }

  c4_kb_x = muDoubleScalarSqrt(c4_kb_x);
  c4_c_A = -c4_y_dot;
  c4_c_B = c4_kb_x;
  c4_lb_x = c4_c_A;
  c4_eb_y = c4_c_B;
  c4_mb_x = c4_lb_x;
  c4_fb_y = c4_eb_y;
  c4_gb_y = c4_mb_x / c4_fb_y;
  c4_nb_x = c4_mpower(chartInstance, c4_x_dot) + c4_mpower(chartInstance,
    c4_y_dot);
  c4_ob_x = c4_nb_x;
  if (c4_ob_x < 0.0) {
    c4_eml_error(chartInstance);
  }

  c4_ob_x = muDoubleScalarSqrt(c4_ob_x);
  c4_d_A = c4_x_dot;
  c4_d_B = c4_ob_x;
  c4_pb_x = c4_d_A;
  c4_hb_y = c4_d_B;
  c4_qb_x = c4_pb_x;
  c4_ib_y = c4_hb_y;
  c4_jb_y = c4_qb_x / c4_ib_y;
  c4_R_po[0] = c4_ab_y;
  c4_R_po[2] = c4_db_y;
  c4_R_po[1] = c4_gb_y;
  c4_R_po[3] = c4_jb_y;
  _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, 22);
  c4_rb_x = c4_mpower(chartInstance, c4_x_dot) + c4_mpower(chartInstance,
    c4_y_dot);
  c4_r_c = c4_rb_x;
  if (c4_r_c < 0.0) {
    c4_eml_error(chartInstance);
  }

  c4_sb_x = c4_r_c;
  c4_r_c = c4_sb_x;
  c4_r_c = muDoubleScalarSqrt(c4_r_c);
  _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, 24);
  c4_tb_x = c4_y_dot;
  c4_ub_x = c4_tb_x;
  c4_kb_y = muDoubleScalarAbs(c4_ub_x);
  c4_vb_x = c4_kb_y;
  c4_wb_x = c4_vb_x;
  c4_wb_x = muDoubleScalarSign(c4_wb_x);
  c4_e_A = 1.0 + c4_wb_x;
  c4_xb_x = c4_e_A;
  c4_yb_x = c4_xb_x;
  c4_lb_y = c4_yb_x / 2.0;
  c4_ac_x = c4_x_dot;
  c4_bc_x = c4_ac_x;
  c4_bc_x = muDoubleScalarSign(c4_bc_x);
  c4_g_a = c4_lb_y;
  c4_y_b = 1.0 - c4_bc_x;
  c4_mb_y = c4_g_a * c4_y_b;
  c4_cc_x = c4_y_dot;
  c4_dc_x = c4_cc_x;
  c4_dc_x = muDoubleScalarSign(c4_dc_x);
  c4_h_a = c4_mb_y;
  c4_ab_b = c4_dc_x;
  c4_nb_y = c4_h_a * c4_ab_b;
  c4_i_a = c4_nb_y;
  c4_ob_y = c4_i_a * 3.1415926535897931;
  c4_f_A = c4_ob_y;
  c4_ec_x = c4_f_A;
  c4_fc_x = c4_ec_x;
  c4_pb_y = c4_fc_x / 2.0;
  c4_g_A = c4_y_dot;
  c4_e_B = c4_x_dot;
  c4_gc_x = c4_g_A;
  c4_qb_y = c4_e_B;
  c4_hc_x = c4_gc_x;
  c4_rb_y = c4_qb_y;
  c4_sb_y = c4_hc_x / c4_rb_y;
  c4_ic_x = c4_sb_y;
  c4_jc_x = c4_ic_x;
  c4_jc_x = muDoubleScalarAtan(c4_jc_x);
  c4_Theta_po = c4_pb_y + c4_jc_x;
  _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, -24);
  sf_debug_symbol_scope_pop();
  for (c4_i7 = 0; c4_i7 < 2; c4_i7++) {
    (*c4_b_Dis_Path_o)[c4_i7] = c4_Dis_Path_o[c4_i7];
  }

  for (c4_i8 = 0; c4_i8 < 4; c4_i8++) {
    (*c4_b_R_po)[c4_i8] = c4_R_po[c4_i8];
  }

  *c4_b_r_c = c4_r_c;
  *c4_b_Theta_po = c4_Theta_po;
  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 3U, chartInstance->c4_sfEvent);
}

static void initSimStructsc4_test(SFc4_testInstanceStruct *chartInstance)
{
}

static void init_script_number_translation(uint32_T c4_machineNumber, uint32_T
  c4_chartNumber)
{
}

static const mxArray *c4_sf_marshallOut(void *chartInstanceVoid, void *c4_inData)
{
  const mxArray *c4_mxArrayOutData = NULL;
  real_T c4_u;
  const mxArray *c4_y = NULL;
  SFc4_testInstanceStruct *chartInstance;
  chartInstance = (SFc4_testInstanceStruct *)chartInstanceVoid;
  c4_mxArrayOutData = NULL;
  c4_u = *(real_T *)c4_inData;
  c4_y = NULL;
  sf_mex_assign(&c4_y, sf_mex_create("y", &c4_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c4_mxArrayOutData, c4_y, FALSE);
  return c4_mxArrayOutData;
}

static real_T c4_emlrt_marshallIn(SFc4_testInstanceStruct *chartInstance, const
  mxArray *c4_Theta_po, const char_T *c4_identifier)
{
  real_T c4_y;
  emlrtMsgIdentifier c4_thisId;
  c4_thisId.fIdentifier = c4_identifier;
  c4_thisId.fParent = NULL;
  c4_y = c4_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c4_Theta_po),
    &c4_thisId);
  sf_mex_destroy(&c4_Theta_po);
  return c4_y;
}

static real_T c4_b_emlrt_marshallIn(SFc4_testInstanceStruct *chartInstance,
  const mxArray *c4_u, const emlrtMsgIdentifier *c4_parentId)
{
  real_T c4_y;
  real_T c4_d0;
  sf_mex_import(c4_parentId, sf_mex_dup(c4_u), &c4_d0, 1, 0, 0U, 0, 0U, 0);
  c4_y = c4_d0;
  sf_mex_destroy(&c4_u);
  return c4_y;
}

static void c4_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c4_mxArrayInData, const char_T *c4_varName, void *c4_outData)
{
  const mxArray *c4_Theta_po;
  const char_T *c4_identifier;
  emlrtMsgIdentifier c4_thisId;
  real_T c4_y;
  SFc4_testInstanceStruct *chartInstance;
  chartInstance = (SFc4_testInstanceStruct *)chartInstanceVoid;
  c4_Theta_po = sf_mex_dup(c4_mxArrayInData);
  c4_identifier = c4_varName;
  c4_thisId.fIdentifier = c4_identifier;
  c4_thisId.fParent = NULL;
  c4_y = c4_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c4_Theta_po),
    &c4_thisId);
  sf_mex_destroy(&c4_Theta_po);
  *(real_T *)c4_outData = c4_y;
  sf_mex_destroy(&c4_mxArrayInData);
}

static const mxArray *c4_b_sf_marshallOut(void *chartInstanceVoid, void
  *c4_inData)
{
  const mxArray *c4_mxArrayOutData = NULL;
  int32_T c4_i9;
  int32_T c4_i10;
  int32_T c4_i11;
  real_T c4_b_inData[4];
  int32_T c4_i12;
  int32_T c4_i13;
  int32_T c4_i14;
  real_T c4_u[4];
  const mxArray *c4_y = NULL;
  SFc4_testInstanceStruct *chartInstance;
  chartInstance = (SFc4_testInstanceStruct *)chartInstanceVoid;
  c4_mxArrayOutData = NULL;
  c4_i9 = 0;
  for (c4_i10 = 0; c4_i10 < 2; c4_i10++) {
    for (c4_i11 = 0; c4_i11 < 2; c4_i11++) {
      c4_b_inData[c4_i11 + c4_i9] = (*(real_T (*)[4])c4_inData)[c4_i11 + c4_i9];
    }

    c4_i9 += 2;
  }

  c4_i12 = 0;
  for (c4_i13 = 0; c4_i13 < 2; c4_i13++) {
    for (c4_i14 = 0; c4_i14 < 2; c4_i14++) {
      c4_u[c4_i14 + c4_i12] = c4_b_inData[c4_i14 + c4_i12];
    }

    c4_i12 += 2;
  }

  c4_y = NULL;
  sf_mex_assign(&c4_y, sf_mex_create("y", c4_u, 0, 0U, 1U, 0U, 2, 2, 2), FALSE);
  sf_mex_assign(&c4_mxArrayOutData, c4_y, FALSE);
  return c4_mxArrayOutData;
}

static void c4_c_emlrt_marshallIn(SFc4_testInstanceStruct *chartInstance, const
  mxArray *c4_R_po, const char_T *c4_identifier, real_T c4_y[4])
{
  emlrtMsgIdentifier c4_thisId;
  c4_thisId.fIdentifier = c4_identifier;
  c4_thisId.fParent = NULL;
  c4_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c4_R_po), &c4_thisId, c4_y);
  sf_mex_destroy(&c4_R_po);
}

static void c4_d_emlrt_marshallIn(SFc4_testInstanceStruct *chartInstance, const
  mxArray *c4_u, const emlrtMsgIdentifier *c4_parentId, real_T c4_y[4])
{
  real_T c4_dv2[4];
  int32_T c4_i15;
  sf_mex_import(c4_parentId, sf_mex_dup(c4_u), c4_dv2, 1, 0, 0U, 1, 0U, 2, 2, 2);
  for (c4_i15 = 0; c4_i15 < 4; c4_i15++) {
    c4_y[c4_i15] = c4_dv2[c4_i15];
  }

  sf_mex_destroy(&c4_u);
}

static void c4_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c4_mxArrayInData, const char_T *c4_varName, void *c4_outData)
{
  const mxArray *c4_R_po;
  const char_T *c4_identifier;
  emlrtMsgIdentifier c4_thisId;
  real_T c4_y[4];
  int32_T c4_i16;
  int32_T c4_i17;
  int32_T c4_i18;
  SFc4_testInstanceStruct *chartInstance;
  chartInstance = (SFc4_testInstanceStruct *)chartInstanceVoid;
  c4_R_po = sf_mex_dup(c4_mxArrayInData);
  c4_identifier = c4_varName;
  c4_thisId.fIdentifier = c4_identifier;
  c4_thisId.fParent = NULL;
  c4_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c4_R_po), &c4_thisId, c4_y);
  sf_mex_destroy(&c4_R_po);
  c4_i16 = 0;
  for (c4_i17 = 0; c4_i17 < 2; c4_i17++) {
    for (c4_i18 = 0; c4_i18 < 2; c4_i18++) {
      (*(real_T (*)[4])c4_outData)[c4_i18 + c4_i16] = c4_y[c4_i18 + c4_i16];
    }

    c4_i16 += 2;
  }

  sf_mex_destroy(&c4_mxArrayInData);
}

static const mxArray *c4_c_sf_marshallOut(void *chartInstanceVoid, void
  *c4_inData)
{
  const mxArray *c4_mxArrayOutData = NULL;
  int32_T c4_i19;
  real_T c4_b_inData[2];
  int32_T c4_i20;
  real_T c4_u[2];
  const mxArray *c4_y = NULL;
  SFc4_testInstanceStruct *chartInstance;
  chartInstance = (SFc4_testInstanceStruct *)chartInstanceVoid;
  c4_mxArrayOutData = NULL;
  for (c4_i19 = 0; c4_i19 < 2; c4_i19++) {
    c4_b_inData[c4_i19] = (*(real_T (*)[2])c4_inData)[c4_i19];
  }

  for (c4_i20 = 0; c4_i20 < 2; c4_i20++) {
    c4_u[c4_i20] = c4_b_inData[c4_i20];
  }

  c4_y = NULL;
  sf_mex_assign(&c4_y, sf_mex_create("y", c4_u, 0, 0U, 1U, 0U, 1, 2), FALSE);
  sf_mex_assign(&c4_mxArrayOutData, c4_y, FALSE);
  return c4_mxArrayOutData;
}

static void c4_e_emlrt_marshallIn(SFc4_testInstanceStruct *chartInstance, const
  mxArray *c4_Dis_Path_o, const char_T *c4_identifier, real_T c4_y[2])
{
  emlrtMsgIdentifier c4_thisId;
  c4_thisId.fIdentifier = c4_identifier;
  c4_thisId.fParent = NULL;
  c4_f_emlrt_marshallIn(chartInstance, sf_mex_dup(c4_Dis_Path_o), &c4_thisId,
                        c4_y);
  sf_mex_destroy(&c4_Dis_Path_o);
}

static void c4_f_emlrt_marshallIn(SFc4_testInstanceStruct *chartInstance, const
  mxArray *c4_u, const emlrtMsgIdentifier *c4_parentId, real_T c4_y[2])
{
  real_T c4_dv3[2];
  int32_T c4_i21;
  sf_mex_import(c4_parentId, sf_mex_dup(c4_u), c4_dv3, 1, 0, 0U, 1, 0U, 1, 2);
  for (c4_i21 = 0; c4_i21 < 2; c4_i21++) {
    c4_y[c4_i21] = c4_dv3[c4_i21];
  }

  sf_mex_destroy(&c4_u);
}

static void c4_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c4_mxArrayInData, const char_T *c4_varName, void *c4_outData)
{
  const mxArray *c4_Dis_Path_o;
  const char_T *c4_identifier;
  emlrtMsgIdentifier c4_thisId;
  real_T c4_y[2];
  int32_T c4_i22;
  SFc4_testInstanceStruct *chartInstance;
  chartInstance = (SFc4_testInstanceStruct *)chartInstanceVoid;
  c4_Dis_Path_o = sf_mex_dup(c4_mxArrayInData);
  c4_identifier = c4_varName;
  c4_thisId.fIdentifier = c4_identifier;
  c4_thisId.fParent = NULL;
  c4_f_emlrt_marshallIn(chartInstance, sf_mex_dup(c4_Dis_Path_o), &c4_thisId,
                        c4_y);
  sf_mex_destroy(&c4_Dis_Path_o);
  for (c4_i22 = 0; c4_i22 < 2; c4_i22++) {
    (*(real_T (*)[2])c4_outData)[c4_i22] = c4_y[c4_i22];
  }

  sf_mex_destroy(&c4_mxArrayInData);
}

const mxArray *sf_c4_test_get_eml_resolved_functions_info(void)
{
  const mxArray *c4_nameCaptureInfo;
  c4_ResolvedFunctionInfo c4_info[23];
  const mxArray *c4_m0 = NULL;
  int32_T c4_i23;
  c4_ResolvedFunctionInfo *c4_r0;
  c4_nameCaptureInfo = NULL;
  c4_nameCaptureInfo = NULL;
  c4_info_helper(c4_info);
  sf_mex_assign(&c4_m0, sf_mex_createstruct("nameCaptureInfo", 1, 23), FALSE);
  for (c4_i23 = 0; c4_i23 < 23; c4_i23++) {
    c4_r0 = &c4_info[c4_i23];
    sf_mex_addfield(c4_m0, sf_mex_create("nameCaptureInfo", c4_r0->context, 15,
      0U, 0U, 0U, 2, 1, strlen(c4_r0->context)), "context", "nameCaptureInfo",
                    c4_i23);
    sf_mex_addfield(c4_m0, sf_mex_create("nameCaptureInfo", c4_r0->name, 15, 0U,
      0U, 0U, 2, 1, strlen(c4_r0->name)), "name", "nameCaptureInfo", c4_i23);
    sf_mex_addfield(c4_m0, sf_mex_create("nameCaptureInfo", c4_r0->dominantType,
      15, 0U, 0U, 0U, 2, 1, strlen(c4_r0->dominantType)), "dominantType",
                    "nameCaptureInfo", c4_i23);
    sf_mex_addfield(c4_m0, sf_mex_create("nameCaptureInfo", c4_r0->resolved, 15,
      0U, 0U, 0U, 2, 1, strlen(c4_r0->resolved)), "resolved", "nameCaptureInfo",
                    c4_i23);
    sf_mex_addfield(c4_m0, sf_mex_create("nameCaptureInfo", &c4_r0->fileTimeLo,
      7, 0U, 0U, 0U, 0), "fileTimeLo", "nameCaptureInfo", c4_i23);
    sf_mex_addfield(c4_m0, sf_mex_create("nameCaptureInfo", &c4_r0->fileTimeHi,
      7, 0U, 0U, 0U, 0), "fileTimeHi", "nameCaptureInfo", c4_i23);
    sf_mex_addfield(c4_m0, sf_mex_create("nameCaptureInfo", &c4_r0->mFileTimeLo,
      7, 0U, 0U, 0U, 0), "mFileTimeLo", "nameCaptureInfo", c4_i23);
    sf_mex_addfield(c4_m0, sf_mex_create("nameCaptureInfo", &c4_r0->mFileTimeHi,
      7, 0U, 0U, 0U, 0), "mFileTimeHi", "nameCaptureInfo", c4_i23);
  }

  sf_mex_assign(&c4_nameCaptureInfo, c4_m0, FALSE);
  sf_mex_emlrtNameCapturePostProcessR2012a(&c4_nameCaptureInfo);
  return c4_nameCaptureInfo;
}

static void c4_info_helper(c4_ResolvedFunctionInfo c4_info[23])
{
  c4_info[0].context = "";
  c4_info[0].name = "mrdivide";
  c4_info[0].dominantType = "double";
  c4_info[0].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p";
  c4_info[0].fileTimeLo = 1342789344U;
  c4_info[0].fileTimeHi = 0U;
  c4_info[0].mFileTimeLo = 1319708366U;
  c4_info[0].mFileTimeHi = 0U;
  c4_info[1].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p";
  c4_info[1].name = "rdivide";
  c4_info[1].dominantType = "double";
  c4_info[1].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m";
  c4_info[1].fileTimeLo = 1286797244U;
  c4_info[1].fileTimeHi = 0U;
  c4_info[1].mFileTimeLo = 0U;
  c4_info[1].mFileTimeHi = 0U;
  c4_info[2].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m";
  c4_info[2].name = "eml_div";
  c4_info[2].dominantType = "double";
  c4_info[2].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_div.m";
  c4_info[2].fileTimeLo = 1313326210U;
  c4_info[2].fileTimeHi = 0U;
  c4_info[2].mFileTimeLo = 0U;
  c4_info[2].mFileTimeHi = 0U;
  c4_info[3].context = "";
  c4_info[3].name = "mtimes";
  c4_info[3].dominantType = "double";
  c4_info[3].resolved = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c4_info[3].fileTimeLo = 1289494492U;
  c4_info[3].fileTimeHi = 0U;
  c4_info[3].mFileTimeLo = 0U;
  c4_info[3].mFileTimeHi = 0U;
  c4_info[4].context = "";
  c4_info[4].name = "sin";
  c4_info[4].dominantType = "double";
  c4_info[4].resolved = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/sin.m";
  c4_info[4].fileTimeLo = 1286797150U;
  c4_info[4].fileTimeHi = 0U;
  c4_info[4].mFileTimeLo = 0U;
  c4_info[4].mFileTimeHi = 0U;
  c4_info[5].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/sin.m";
  c4_info[5].name = "eml_scalar_sin";
  c4_info[5].dominantType = "double";
  c4_info[5].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_sin.m";
  c4_info[5].fileTimeLo = 1286797136U;
  c4_info[5].fileTimeHi = 0U;
  c4_info[5].mFileTimeLo = 0U;
  c4_info[5].mFileTimeHi = 0U;
  c4_info[6].context = "";
  c4_info[6].name = "cos";
  c4_info[6].dominantType = "double";
  c4_info[6].resolved = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/cos.m";
  c4_info[6].fileTimeLo = 1286797106U;
  c4_info[6].fileTimeHi = 0U;
  c4_info[6].mFileTimeLo = 0U;
  c4_info[6].mFileTimeHi = 0U;
  c4_info[7].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/cos.m";
  c4_info[7].name = "eml_scalar_cos";
  c4_info[7].dominantType = "double";
  c4_info[7].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_cos.m";
  c4_info[7].fileTimeLo = 1286797122U;
  c4_info[7].fileTimeHi = 0U;
  c4_info[7].mFileTimeLo = 0U;
  c4_info[7].mFileTimeHi = 0U;
  c4_info[8].context = "";
  c4_info[8].name = "mpower";
  c4_info[8].dominantType = "double";
  c4_info[8].resolved = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mpower.m";
  c4_info[8].fileTimeLo = 1286797242U;
  c4_info[8].fileTimeHi = 0U;
  c4_info[8].mFileTimeLo = 0U;
  c4_info[8].mFileTimeHi = 0U;
  c4_info[9].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mpower.m";
  c4_info[9].name = "power";
  c4_info[9].dominantType = "double";
  c4_info[9].resolved = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m";
  c4_info[9].fileTimeLo = 1336500496U;
  c4_info[9].fileTimeHi = 0U;
  c4_info[9].mFileTimeLo = 0U;
  c4_info[9].mFileTimeHi = 0U;
  c4_info[10].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m!fltpower";
  c4_info[10].name = "eml_scalar_eg";
  c4_info[10].dominantType = "double";
  c4_info[10].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m";
  c4_info[10].fileTimeLo = 1286797196U;
  c4_info[10].fileTimeHi = 0U;
  c4_info[10].mFileTimeLo = 0U;
  c4_info[10].mFileTimeHi = 0U;
  c4_info[11].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m!fltpower";
  c4_info[11].name = "eml_scalexp_alloc";
  c4_info[11].dominantType = "double";
  c4_info[11].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalexp_alloc.m";
  c4_info[11].fileTimeLo = 1330583234U;
  c4_info[11].fileTimeHi = 0U;
  c4_info[11].mFileTimeLo = 0U;
  c4_info[11].mFileTimeHi = 0U;
  c4_info[12].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m!fltpower";
  c4_info[12].name = "floor";
  c4_info[12].dominantType = "double";
  c4_info[12].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/floor.m";
  c4_info[12].fileTimeLo = 1286797142U;
  c4_info[12].fileTimeHi = 0U;
  c4_info[12].mFileTimeLo = 0U;
  c4_info[12].mFileTimeHi = 0U;
  c4_info[13].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/floor.m";
  c4_info[13].name = "eml_scalar_floor";
  c4_info[13].dominantType = "double";
  c4_info[13].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_floor.m";
  c4_info[13].fileTimeLo = 1286797126U;
  c4_info[13].fileTimeHi = 0U;
  c4_info[13].mFileTimeLo = 0U;
  c4_info[13].mFileTimeHi = 0U;
  c4_info[14].context = "";
  c4_info[14].name = "sqrt";
  c4_info[14].dominantType = "double";
  c4_info[14].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/sqrt.m";
  c4_info[14].fileTimeLo = 1286797152U;
  c4_info[14].fileTimeHi = 0U;
  c4_info[14].mFileTimeLo = 0U;
  c4_info[14].mFileTimeHi = 0U;
  c4_info[15].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/sqrt.m";
  c4_info[15].name = "eml_error";
  c4_info[15].dominantType = "char";
  c4_info[15].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_error.m";
  c4_info[15].fileTimeLo = 1305296400U;
  c4_info[15].fileTimeHi = 0U;
  c4_info[15].mFileTimeLo = 0U;
  c4_info[15].mFileTimeHi = 0U;
  c4_info[16].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/sqrt.m";
  c4_info[16].name = "eml_scalar_sqrt";
  c4_info[16].dominantType = "double";
  c4_info[16].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_sqrt.m";
  c4_info[16].fileTimeLo = 1286797138U;
  c4_info[16].fileTimeHi = 0U;
  c4_info[16].mFileTimeLo = 0U;
  c4_info[16].mFileTimeHi = 0U;
  c4_info[17].context = "";
  c4_info[17].name = "abs";
  c4_info[17].dominantType = "double";
  c4_info[17].resolved = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m";
  c4_info[17].fileTimeLo = 1286797094U;
  c4_info[17].fileTimeHi = 0U;
  c4_info[17].mFileTimeLo = 0U;
  c4_info[17].mFileTimeHi = 0U;
  c4_info[18].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m";
  c4_info[18].name = "eml_scalar_abs";
  c4_info[18].dominantType = "double";
  c4_info[18].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_abs.m";
  c4_info[18].fileTimeLo = 1286797112U;
  c4_info[18].fileTimeHi = 0U;
  c4_info[18].mFileTimeLo = 0U;
  c4_info[18].mFileTimeHi = 0U;
  c4_info[19].context = "";
  c4_info[19].name = "sign";
  c4_info[19].dominantType = "double";
  c4_info[19].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/sign.m";
  c4_info[19].fileTimeLo = 1286797150U;
  c4_info[19].fileTimeHi = 0U;
  c4_info[19].mFileTimeLo = 0U;
  c4_info[19].mFileTimeHi = 0U;
  c4_info[20].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/sign.m";
  c4_info[20].name = "eml_scalar_sign";
  c4_info[20].dominantType = "double";
  c4_info[20].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_sign.m";
  c4_info[20].fileTimeLo = 1307629638U;
  c4_info[20].fileTimeHi = 0U;
  c4_info[20].mFileTimeLo = 0U;
  c4_info[20].mFileTimeHi = 0U;
  c4_info[21].context = "";
  c4_info[21].name = "atan";
  c4_info[21].dominantType = "double";
  c4_info[21].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/atan.m";
  c4_info[21].fileTimeLo = 1305296398U;
  c4_info[21].fileTimeHi = 0U;
  c4_info[21].mFileTimeLo = 0U;
  c4_info[21].mFileTimeHi = 0U;
  c4_info[22].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/atan.m";
  c4_info[22].name = "eml_scalar_atan";
  c4_info[22].dominantType = "double";
  c4_info[22].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_atan.m";
  c4_info[22].fileTimeLo = 1286797118U;
  c4_info[22].fileTimeHi = 0U;
  c4_info[22].mFileTimeLo = 0U;
  c4_info[22].mFileTimeHi = 0U;
}

static real_T c4_mpower(SFc4_testInstanceStruct *chartInstance, real_T c4_a)
{
  real_T c4_b_a;
  real_T c4_c_a;
  real_T c4_ak;
  c4_b_a = c4_a;
  c4_c_a = c4_b_a;
  c4_ak = c4_c_a;
  return muDoubleScalarPower(c4_ak, 2.0);
}

static void c4_eml_error(SFc4_testInstanceStruct *chartInstance)
{
  int32_T c4_i24;
  static char_T c4_varargin_1[30] = { 'C', 'o', 'd', 'e', 'r', ':', 't', 'o',
    'o', 'l', 'b', 'o', 'x', ':', 's', 'q', 'r', 't', '_', 'd', 'o', 'm', 'a',
    'i', 'n', 'E', 'r', 'r', 'o', 'r' };

  char_T c4_u[30];
  const mxArray *c4_y = NULL;
  for (c4_i24 = 0; c4_i24 < 30; c4_i24++) {
    c4_u[c4_i24] = c4_varargin_1[c4_i24];
  }

  c4_y = NULL;
  sf_mex_assign(&c4_y, sf_mex_create("y", c4_u, 10, 0U, 1U, 0U, 2, 1, 30), FALSE);
  sf_mex_call_debug("error", 0U, 1U, 14, sf_mex_call_debug("message", 1U, 1U, 14,
    c4_y));
}

static const mxArray *c4_d_sf_marshallOut(void *chartInstanceVoid, void
  *c4_inData)
{
  const mxArray *c4_mxArrayOutData = NULL;
  int32_T c4_u;
  const mxArray *c4_y = NULL;
  SFc4_testInstanceStruct *chartInstance;
  chartInstance = (SFc4_testInstanceStruct *)chartInstanceVoid;
  c4_mxArrayOutData = NULL;
  c4_u = *(int32_T *)c4_inData;
  c4_y = NULL;
  sf_mex_assign(&c4_y, sf_mex_create("y", &c4_u, 6, 0U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c4_mxArrayOutData, c4_y, FALSE);
  return c4_mxArrayOutData;
}

static int32_T c4_g_emlrt_marshallIn(SFc4_testInstanceStruct *chartInstance,
  const mxArray *c4_u, const emlrtMsgIdentifier *c4_parentId)
{
  int32_T c4_y;
  int32_T c4_i25;
  sf_mex_import(c4_parentId, sf_mex_dup(c4_u), &c4_i25, 1, 6, 0U, 0, 0U, 0);
  c4_y = c4_i25;
  sf_mex_destroy(&c4_u);
  return c4_y;
}

static void c4_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c4_mxArrayInData, const char_T *c4_varName, void *c4_outData)
{
  const mxArray *c4_b_sfEvent;
  const char_T *c4_identifier;
  emlrtMsgIdentifier c4_thisId;
  int32_T c4_y;
  SFc4_testInstanceStruct *chartInstance;
  chartInstance = (SFc4_testInstanceStruct *)chartInstanceVoid;
  c4_b_sfEvent = sf_mex_dup(c4_mxArrayInData);
  c4_identifier = c4_varName;
  c4_thisId.fIdentifier = c4_identifier;
  c4_thisId.fParent = NULL;
  c4_y = c4_g_emlrt_marshallIn(chartInstance, sf_mex_dup(c4_b_sfEvent),
    &c4_thisId);
  sf_mex_destroy(&c4_b_sfEvent);
  *(int32_T *)c4_outData = c4_y;
  sf_mex_destroy(&c4_mxArrayInData);
}

static uint8_T c4_h_emlrt_marshallIn(SFc4_testInstanceStruct *chartInstance,
  const mxArray *c4_b_is_active_c4_test, const char_T *c4_identifier)
{
  uint8_T c4_y;
  emlrtMsgIdentifier c4_thisId;
  c4_thisId.fIdentifier = c4_identifier;
  c4_thisId.fParent = NULL;
  c4_y = c4_i_emlrt_marshallIn(chartInstance, sf_mex_dup(c4_b_is_active_c4_test),
    &c4_thisId);
  sf_mex_destroy(&c4_b_is_active_c4_test);
  return c4_y;
}

static uint8_T c4_i_emlrt_marshallIn(SFc4_testInstanceStruct *chartInstance,
  const mxArray *c4_u, const emlrtMsgIdentifier *c4_parentId)
{
  uint8_T c4_y;
  uint8_T c4_u0;
  sf_mex_import(c4_parentId, sf_mex_dup(c4_u), &c4_u0, 1, 3, 0U, 0, 0U, 0);
  c4_y = c4_u0;
  sf_mex_destroy(&c4_u);
  return c4_y;
}

static void init_dsm_address_info(SFc4_testInstanceStruct *chartInstance)
{
}

/* SFunction Glue Code */
void sf_c4_test_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(1031194400U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(538878304U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(1388906341U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(2564023751U);
}

mxArray *sf_c4_test_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1,1,5,
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateString("QJ6RWZAcqbdKceSekMpb1D");
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
    mxSetField(mxAutoinheritanceInfo,0,"parameters",mxCreateDoubleMatrix(0,0,
                mxREAL));
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,4,3,dataFields);

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
      pr[0] = (double)(2);
      pr[1] = (double)(2);
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
    mxSetField(mxAutoinheritanceInfo,0,"outputs",mxData);
  }

  {
    mxSetField(mxAutoinheritanceInfo,0,"locals",mxCreateDoubleMatrix(0,0,mxREAL));
  }

  return(mxAutoinheritanceInfo);
}

static const mxArray *sf_get_sim_state_info_c4_test(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x5'type','srcId','name','auxInfo'{{M[1],M[5],T\"Dis_Path_o\",},{M[1],M[6],T\"R_po\",},{M[1],M[10],T\"Theta_po\",},{M[1],M[9],T\"r_c\",},{M[8],M[0],T\"is_active_c4_test\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 5, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c4_test_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc4_testInstanceStruct *chartInstance;
    chartInstance = (SFc4_testInstanceStruct *) ((ChartInfoStruct *)
      (ssGetUserData(S)))->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart(_testMachineNumber_,
          4,
          1,
          1,
          5,
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
          _SFD_SET_DATA_PROPS(0,1,1,0,"m");
          _SFD_SET_DATA_PROPS(1,2,0,1,"Dis_Path_o");
          _SFD_SET_DATA_PROPS(2,2,0,1,"R_po");
          _SFD_SET_DATA_PROPS(3,2,0,1,"r_c");
          _SFD_SET_DATA_PROPS(4,2,0,1,"Theta_po");
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
        _SFD_CV_INIT_EML_FCN(0,0,"eML_blk_kernel",0,-1,1099);
        _SFD_TRANS_COV_WTS(0,0,0,1,0);
        if (chartAlreadyPresent==0) {
          _SFD_TRANS_COV_MAPS(0,
                              0,NULL,NULL,
                              0,NULL,NULL,
                              1,NULL,NULL,
                              0,NULL,NULL);
        }

        _SFD_SET_DATA_COMPILED_PROPS(0,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c4_sf_marshallOut,(MexInFcnForType)NULL);

        {
          unsigned int dimVector[1];
          dimVector[0]= 2;
          _SFD_SET_DATA_COMPILED_PROPS(1,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c4_c_sf_marshallOut,(MexInFcnForType)
            c4_c_sf_marshallIn);
        }

        {
          unsigned int dimVector[2];
          dimVector[0]= 2;
          dimVector[1]= 2;
          _SFD_SET_DATA_COMPILED_PROPS(2,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c4_b_sf_marshallOut,(MexInFcnForType)
            c4_b_sf_marshallIn);
        }

        _SFD_SET_DATA_COMPILED_PROPS(3,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c4_sf_marshallOut,(MexInFcnForType)c4_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(4,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c4_sf_marshallOut,(MexInFcnForType)c4_sf_marshallIn);

        {
          real_T *c4_m;
          real_T *c4_r_c;
          real_T *c4_Theta_po;
          real_T (*c4_Dis_Path_o)[2];
          real_T (*c4_R_po)[4];
          c4_Theta_po = (real_T *)ssGetOutputPortSignal(chartInstance->S, 4);
          c4_r_c = (real_T *)ssGetOutputPortSignal(chartInstance->S, 3);
          c4_R_po = (real_T (*)[4])ssGetOutputPortSignal(chartInstance->S, 2);
          c4_Dis_Path_o = (real_T (*)[2])ssGetOutputPortSignal(chartInstance->S,
            1);
          c4_m = (real_T *)ssGetInputPortSignal(chartInstance->S, 0);
          _SFD_SET_DATA_VALUE_PTR(0U, c4_m);
          _SFD_SET_DATA_VALUE_PTR(1U, *c4_Dis_Path_o);
          _SFD_SET_DATA_VALUE_PTR(2U, *c4_R_po);
          _SFD_SET_DATA_VALUE_PTR(3U, c4_r_c);
          _SFD_SET_DATA_VALUE_PTR(4U, c4_Theta_po);
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
  return "xYBWUV5oglICsUHhDdy7bC";
}

static void sf_opaque_initialize_c4_test(void *chartInstanceVar)
{
  chart_debug_initialization(((SFc4_testInstanceStruct*) chartInstanceVar)->S,0);
  initialize_params_c4_test((SFc4_testInstanceStruct*) chartInstanceVar);
  initialize_c4_test((SFc4_testInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_enable_c4_test(void *chartInstanceVar)
{
  enable_c4_test((SFc4_testInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_disable_c4_test(void *chartInstanceVar)
{
  disable_c4_test((SFc4_testInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_gateway_c4_test(void *chartInstanceVar)
{
  sf_c4_test((SFc4_testInstanceStruct*) chartInstanceVar);
}

extern const mxArray* sf_internal_get_sim_state_c4_test(SimStruct* S)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_raw2high");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = (mxArray*) get_sim_state_c4_test((SFc4_testInstanceStruct*)
    chartInfo->chartInstance);         /* raw sim ctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c4_test();/* state var info */
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

extern void sf_internal_set_sim_state_c4_test(SimStruct* S, const mxArray *st)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_high2raw");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = mxDuplicateArray(st);      /* high level simctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c4_test();/* state var info */
  mxError = sf_mex_call_matlab(1, plhs, 4, prhs, "sfprivate");
  mxDestroyArray(prhs[0]);
  mxDestroyArray(prhs[1]);
  mxDestroyArray(prhs[2]);
  mxDestroyArray(prhs[3]);
  if (mxError || plhs[0] == NULL) {
    sf_mex_error_message("Stateflow Internal Error: \nError calling 'chart_simctx_high2raw'.\n");
  }

  set_sim_state_c4_test((SFc4_testInstanceStruct*)chartInfo->chartInstance,
                        mxDuplicateArray(plhs[0]));
  mxDestroyArray(plhs[0]);
}

static const mxArray* sf_opaque_get_sim_state_c4_test(SimStruct* S)
{
  return sf_internal_get_sim_state_c4_test(S);
}

static void sf_opaque_set_sim_state_c4_test(SimStruct* S, const mxArray *st)
{
  sf_internal_set_sim_state_c4_test(S, st);
}

static void sf_opaque_terminate_c4_test(void *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc4_testInstanceStruct*) chartInstanceVar)->S;
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
    }

    finalize_c4_test((SFc4_testInstanceStruct*) chartInstanceVar);
    free((void *)chartInstanceVar);
    ssSetUserData(S,NULL);
  }

  unload_test_optimization_info();
}

static void sf_opaque_init_subchart_simstructs(void *chartInstanceVar)
{
  initSimStructsc4_test((SFc4_testInstanceStruct*) chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c4_test(SimStruct *S)
{
  int i;
  for (i=0;i<ssGetNumRunTimeParams(S);i++) {
    if (ssGetSFcnParamTunable(S,i)) {
      ssUpdateDlgParamAsRunTimeParam(S,i);
    }
  }

  if (sf_machine_global_initializer_called()) {
    initialize_params_c4_test((SFc4_testInstanceStruct*)(((ChartInfoStruct *)
      ssGetUserData(S))->chartInstance));
  }
}

static void mdlSetWorkWidths_c4_test(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    mxArray *infoStruct = load_test_optimization_info();
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable(S,sf_get_instance_specialization(),infoStruct,
      4);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop(S,sf_get_instance_specialization(),
                infoStruct,4,"RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop(S,
      sf_get_instance_specialization(),infoStruct,4,
      "gatewayCannotBeInlinedMultipleTimes"));
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,sf_get_instance_specialization(),
        infoStruct,4,1);
      sf_mark_chart_reusable_outputs(S,sf_get_instance_specialization(),
        infoStruct,4,4);
    }

    sf_set_rtw_dwork_info(S,sf_get_instance_specialization(),infoStruct,4);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(3590232662U));
  ssSetChecksum1(S,(1759577786U));
  ssSetChecksum2(S,(3742088396U));
  ssSetChecksum3(S,(3785769079U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
  ssSupportsMultipleExecInstances(S,1);
}

static void mdlRTW_c4_test(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c4_test(SimStruct *S)
{
  SFc4_testInstanceStruct *chartInstance;
  chartInstance = (SFc4_testInstanceStruct *)malloc(sizeof
    (SFc4_testInstanceStruct));
  memset(chartInstance, 0, sizeof(SFc4_testInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway = sf_opaque_gateway_c4_test;
  chartInstance->chartInfo.initializeChart = sf_opaque_initialize_c4_test;
  chartInstance->chartInfo.terminateChart = sf_opaque_terminate_c4_test;
  chartInstance->chartInfo.enableChart = sf_opaque_enable_c4_test;
  chartInstance->chartInfo.disableChart = sf_opaque_disable_c4_test;
  chartInstance->chartInfo.getSimState = sf_opaque_get_sim_state_c4_test;
  chartInstance->chartInfo.setSimState = sf_opaque_set_sim_state_c4_test;
  chartInstance->chartInfo.getSimStateInfo = sf_get_sim_state_info_c4_test;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c4_test;
  chartInstance->chartInfo.mdlStart = mdlStart_c4_test;
  chartInstance->chartInfo.mdlSetWorkWidths = mdlSetWorkWidths_c4_test;
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

void c4_test_method_dispatcher(SimStruct *S, int_T method, void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c4_test(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c4_test(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c4_test(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c4_test_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}

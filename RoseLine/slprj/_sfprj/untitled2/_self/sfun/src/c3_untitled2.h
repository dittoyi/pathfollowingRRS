#ifndef __c3_untitled2_h__
#define __c3_untitled2_h__

/* Include files */
#include "sf_runtime/sfc_sf.h"
#include "sf_runtime/sfc_mex.h"
#include "rtwtypes.h"
#include "multiword_types.h"

/* Type Definitions */
#ifndef typedef_SFc3_untitled2InstanceStruct
#define typedef_SFc3_untitled2InstanceStruct

typedef struct {
  SimStruct *S;
  ChartInfoStruct chartInfo;
  uint32_T chartNumber;
  uint32_T instanceNumber;
  int32_T c3_sfEvent;
  boolean_T c3_isStable;
  boolean_T c3_doneDoubleBufferReInit;
  uint8_T c3_is_active_c3_untitled2;
  real_T c3_Delta_e;
} SFc3_untitled2InstanceStruct;

#endif                                 /*typedef_SFc3_untitled2InstanceStruct*/

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */

/* Function Declarations */
extern const mxArray *sf_c3_untitled2_get_eml_resolved_functions_info(void);

/* Function Definitions */
extern void sf_c3_untitled2_get_check_sum(mxArray *plhs[]);
extern void c3_untitled2_method_dispatcher(SimStruct *S, int_T method, void
  *data);

#endif

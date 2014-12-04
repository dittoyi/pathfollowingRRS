/* Include files */

#include "untitled2_sfun.h"
#include "untitled2_sfun_debug_macros.h"
#include "c1_untitled2.h"
#include "c2_untitled2.h"
#include "c3_untitled2.h"
#include "c4_untitled2.h"
#include "c5_untitled2.h"
#include "c6_untitled2.h"
#include "c7_untitled2.h"
#include "c8_untitled2.h"
#include "c9_untitled2.h"
#include "c10_untitled2.h"
#include "c11_untitled2.h"
#include "c12_untitled2.h"
#include "c14_untitled2.h"

/* Type Definitions */

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */
uint32_T _untitled2MachineNumber_;

/* Function Declarations */

/* Function Definitions */
void untitled2_initializer(void)
{
}

void untitled2_terminator(void)
{
}

/* SFunction Glue Code */
unsigned int sf_untitled2_method_dispatcher(SimStruct *simstructPtr, unsigned
  int chartFileNumber, const char* specsCksum, int_T method, void *data)
{
  if (chartFileNumber==1) {
    c1_untitled2_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==2) {
    c2_untitled2_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==3) {
    c3_untitled2_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==4) {
    c4_untitled2_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==5) {
    c5_untitled2_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==6) {
    c6_untitled2_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==7) {
    c7_untitled2_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==8) {
    c8_untitled2_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==9) {
    c9_untitled2_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==10) {
    c10_untitled2_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==11) {
    c11_untitled2_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==12) {
    c12_untitled2_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==14) {
    c14_untitled2_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  return 0;
}

unsigned int sf_untitled2_process_check_sum_call( int nlhs, mxArray * plhs[],
  int nrhs, const mxArray * prhs[] )
{

#ifdef MATLAB_MEX_FILE

  char commandName[20];
  if (nrhs<1 || !mxIsChar(prhs[0]) )
    return 0;

  /* Possible call to get the checksum */
  mxGetString(prhs[0], commandName,sizeof(commandName)/sizeof(char));
  commandName[(sizeof(commandName)/sizeof(char)-1)] = '\0';
  if (strcmp(commandName,"sf_get_check_sum"))
    return 0;
  plhs[0] = mxCreateDoubleMatrix( 1,4,mxREAL);
  if (nrhs>1 && mxIsChar(prhs[1])) {
    mxGetString(prhs[1], commandName,sizeof(commandName)/sizeof(char));
    commandName[(sizeof(commandName)/sizeof(char)-1)] = '\0';
    if (!strcmp(commandName,"machine")) {
      ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(4159782896U);
      ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(1134380111U);
      ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(1474746038U);
      ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(3810505079U);
    } else if (!strcmp(commandName,"exportedFcn")) {
      ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(0U);
      ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(0U);
      ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(0U);
      ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(0U);
    } else if (!strcmp(commandName,"makefile")) {
      ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(1061362906U);
      ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(3824498440U);
      ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(405987906U);
      ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(606552494U);
    } else if (nrhs==3 && !strcmp(commandName,"chart")) {
      unsigned int chartFileNumber;
      chartFileNumber = (unsigned int)mxGetScalar(prhs[2]);
      switch (chartFileNumber) {
       case 1:
        {
          extern void sf_c1_untitled2_get_check_sum(mxArray *plhs[]);
          sf_c1_untitled2_get_check_sum(plhs);
          break;
        }

       case 2:
        {
          extern void sf_c2_untitled2_get_check_sum(mxArray *plhs[]);
          sf_c2_untitled2_get_check_sum(plhs);
          break;
        }

       case 3:
        {
          extern void sf_c3_untitled2_get_check_sum(mxArray *plhs[]);
          sf_c3_untitled2_get_check_sum(plhs);
          break;
        }

       case 4:
        {
          extern void sf_c4_untitled2_get_check_sum(mxArray *plhs[]);
          sf_c4_untitled2_get_check_sum(plhs);
          break;
        }

       case 5:
        {
          extern void sf_c5_untitled2_get_check_sum(mxArray *plhs[]);
          sf_c5_untitled2_get_check_sum(plhs);
          break;
        }

       case 6:
        {
          extern void sf_c6_untitled2_get_check_sum(mxArray *plhs[]);
          sf_c6_untitled2_get_check_sum(plhs);
          break;
        }

       case 7:
        {
          extern void sf_c7_untitled2_get_check_sum(mxArray *plhs[]);
          sf_c7_untitled2_get_check_sum(plhs);
          break;
        }

       case 8:
        {
          extern void sf_c8_untitled2_get_check_sum(mxArray *plhs[]);
          sf_c8_untitled2_get_check_sum(plhs);
          break;
        }

       case 9:
        {
          extern void sf_c9_untitled2_get_check_sum(mxArray *plhs[]);
          sf_c9_untitled2_get_check_sum(plhs);
          break;
        }

       case 10:
        {
          extern void sf_c10_untitled2_get_check_sum(mxArray *plhs[]);
          sf_c10_untitled2_get_check_sum(plhs);
          break;
        }

       case 11:
        {
          extern void sf_c11_untitled2_get_check_sum(mxArray *plhs[]);
          sf_c11_untitled2_get_check_sum(plhs);
          break;
        }

       case 12:
        {
          extern void sf_c12_untitled2_get_check_sum(mxArray *plhs[]);
          sf_c12_untitled2_get_check_sum(plhs);
          break;
        }

       case 14:
        {
          extern void sf_c14_untitled2_get_check_sum(mxArray *plhs[]);
          sf_c14_untitled2_get_check_sum(plhs);
          break;
        }

       default:
        ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(0.0);
        ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(0.0);
        ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(0.0);
        ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(0.0);
      }
    } else if (!strcmp(commandName,"target")) {
      ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(2083502392U);
      ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(1110276785U);
      ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(3258378658U);
      ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(3926592909U);
    } else {
      return 0;
    }
  } else {
    ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(809997689U);
    ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(3556951895U);
    ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(1498379422U);
    ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(2513093470U);
  }

  return 1;

#else

  return 0;

#endif

}

unsigned int sf_untitled2_autoinheritance_info( int nlhs, mxArray * plhs[], int
  nrhs, const mxArray * prhs[] )
{

#ifdef MATLAB_MEX_FILE

  char commandName[32];
  char aiChksum[64];
  if (nrhs<3 || !mxIsChar(prhs[0]) )
    return 0;

  /* Possible call to get the autoinheritance_info */
  mxGetString(prhs[0], commandName,sizeof(commandName)/sizeof(char));
  commandName[(sizeof(commandName)/sizeof(char)-1)] = '\0';
  if (strcmp(commandName,"get_autoinheritance_info"))
    return 0;
  mxGetString(prhs[2], aiChksum,sizeof(aiChksum)/sizeof(char));
  aiChksum[(sizeof(aiChksum)/sizeof(char)-1)] = '\0';

  {
    unsigned int chartFileNumber;
    chartFileNumber = (unsigned int)mxGetScalar(prhs[1]);
    switch (chartFileNumber) {
     case 1:
      {
        if (strcmp(aiChksum, "tk7wWGjDtQlRMOUxvpI3H") == 0) {
          extern mxArray *sf_c1_untitled2_get_autoinheritance_info(void);
          plhs[0] = sf_c1_untitled2_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 2:
      {
        if (strcmp(aiChksum, "Nz5ZgTSeFFkh9w1RiagHzC") == 0) {
          extern mxArray *sf_c2_untitled2_get_autoinheritance_info(void);
          plhs[0] = sf_c2_untitled2_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 3:
      {
        if (strcmp(aiChksum, "JakmV7zAiC6R5umEP1USYG") == 0) {
          extern mxArray *sf_c3_untitled2_get_autoinheritance_info(void);
          plhs[0] = sf_c3_untitled2_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 4:
      {
        if (strcmp(aiChksum, "J2hus6UYRiE5ecnyw96zRC") == 0) {
          extern mxArray *sf_c4_untitled2_get_autoinheritance_info(void);
          plhs[0] = sf_c4_untitled2_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 5:
      {
        if (strcmp(aiChksum, "ZqEzTLizhaedTIRysFcE4D") == 0) {
          extern mxArray *sf_c5_untitled2_get_autoinheritance_info(void);
          plhs[0] = sf_c5_untitled2_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 6:
      {
        if (strcmp(aiChksum, "LTKy2x7pUQm9qG4bVeFZSH") == 0) {
          extern mxArray *sf_c6_untitled2_get_autoinheritance_info(void);
          plhs[0] = sf_c6_untitled2_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 7:
      {
        if (strcmp(aiChksum, "ENnVICnyYd57Hgz82cAAt") == 0) {
          extern mxArray *sf_c7_untitled2_get_autoinheritance_info(void);
          plhs[0] = sf_c7_untitled2_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 8:
      {
        if (strcmp(aiChksum, "WUtwiQcHREKxH67t1IEFPC") == 0) {
          extern mxArray *sf_c8_untitled2_get_autoinheritance_info(void);
          plhs[0] = sf_c8_untitled2_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 9:
      {
        if (strcmp(aiChksum, "rid4KzVBVKzhx1i670YSJB") == 0) {
          extern mxArray *sf_c9_untitled2_get_autoinheritance_info(void);
          plhs[0] = sf_c9_untitled2_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 10:
      {
        if (strcmp(aiChksum, "ruUv7ZL7L6eXCPqQ0ZzP5B") == 0) {
          extern mxArray *sf_c10_untitled2_get_autoinheritance_info(void);
          plhs[0] = sf_c10_untitled2_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 11:
      {
        if (strcmp(aiChksum, "cnt8sg5RaFslYaI731f2G") == 0) {
          extern mxArray *sf_c11_untitled2_get_autoinheritance_info(void);
          plhs[0] = sf_c11_untitled2_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 12:
      {
        if (strcmp(aiChksum, "NPHDwYXqccmI902jmXNOJD") == 0) {
          extern mxArray *sf_c12_untitled2_get_autoinheritance_info(void);
          plhs[0] = sf_c12_untitled2_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 14:
      {
        if (strcmp(aiChksum, "Kb0ljZDtarQY41NOKPOp0F") == 0) {
          extern mxArray *sf_c14_untitled2_get_autoinheritance_info(void);
          plhs[0] = sf_c14_untitled2_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     default:
      plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
    }
  }

  return 1;

#else

  return 0;

#endif

}

unsigned int sf_untitled2_get_eml_resolved_functions_info( int nlhs, mxArray *
  plhs[], int nrhs, const mxArray * prhs[] )
{

#ifdef MATLAB_MEX_FILE

  char commandName[64];
  if (nrhs<2 || !mxIsChar(prhs[0]))
    return 0;

  /* Possible call to get the get_eml_resolved_functions_info */
  mxGetString(prhs[0], commandName,sizeof(commandName)/sizeof(char));
  commandName[(sizeof(commandName)/sizeof(char)-1)] = '\0';
  if (strcmp(commandName,"get_eml_resolved_functions_info"))
    return 0;

  {
    unsigned int chartFileNumber;
    chartFileNumber = (unsigned int)mxGetScalar(prhs[1]);
    switch (chartFileNumber) {
     case 1:
      {
        extern const mxArray *sf_c1_untitled2_get_eml_resolved_functions_info
          (void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c1_untitled2_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 2:
      {
        extern const mxArray *sf_c2_untitled2_get_eml_resolved_functions_info
          (void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c2_untitled2_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 3:
      {
        extern const mxArray *sf_c3_untitled2_get_eml_resolved_functions_info
          (void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c3_untitled2_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 4:
      {
        extern const mxArray *sf_c4_untitled2_get_eml_resolved_functions_info
          (void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c4_untitled2_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 5:
      {
        extern const mxArray *sf_c5_untitled2_get_eml_resolved_functions_info
          (void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c5_untitled2_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 6:
      {
        extern const mxArray *sf_c6_untitled2_get_eml_resolved_functions_info
          (void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c6_untitled2_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 7:
      {
        extern const mxArray *sf_c7_untitled2_get_eml_resolved_functions_info
          (void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c7_untitled2_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 8:
      {
        extern const mxArray *sf_c8_untitled2_get_eml_resolved_functions_info
          (void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c8_untitled2_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 9:
      {
        extern const mxArray *sf_c9_untitled2_get_eml_resolved_functions_info
          (void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c9_untitled2_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 10:
      {
        extern const mxArray *sf_c10_untitled2_get_eml_resolved_functions_info
          (void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c10_untitled2_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 11:
      {
        extern const mxArray *sf_c11_untitled2_get_eml_resolved_functions_info
          (void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c11_untitled2_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 12:
      {
        extern const mxArray *sf_c12_untitled2_get_eml_resolved_functions_info
          (void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c12_untitled2_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 14:
      {
        extern const mxArray *sf_c14_untitled2_get_eml_resolved_functions_info
          (void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c14_untitled2_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     default:
      plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
    }
  }

  return 1;

#else

  return 0;

#endif

}

unsigned int sf_untitled2_third_party_uses_info( int nlhs, mxArray * plhs[], int
  nrhs, const mxArray * prhs[] )
{
  char commandName[64];
  char tpChksum[64];
  if (nrhs<3 || !mxIsChar(prhs[0]))
    return 0;

  /* Possible call to get the third_party_uses_info */
  mxGetString(prhs[0], commandName,sizeof(commandName)/sizeof(char));
  commandName[(sizeof(commandName)/sizeof(char)-1)] = '\0';
  mxGetString(prhs[2], tpChksum,sizeof(tpChksum)/sizeof(char));
  tpChksum[(sizeof(tpChksum)/sizeof(char)-1)] = '\0';
  if (strcmp(commandName,"get_third_party_uses_info"))
    return 0;

  {
    unsigned int chartFileNumber;
    chartFileNumber = (unsigned int)mxGetScalar(prhs[1]);
    switch (chartFileNumber) {
     case 1:
      {
        if (strcmp(tpChksum, "ZKG0Ma4HOCVACaYn4ApLUE") == 0) {
          extern mxArray *sf_c1_untitled2_third_party_uses_info(void);
          plhs[0] = sf_c1_untitled2_third_party_uses_info();
          break;
        }
      }

     case 2:
      {
        if (strcmp(tpChksum, "WdnEe8bBkgftP4fW4agX7C") == 0) {
          extern mxArray *sf_c2_untitled2_third_party_uses_info(void);
          plhs[0] = sf_c2_untitled2_third_party_uses_info();
          break;
        }
      }

     case 3:
      {
        if (strcmp(tpChksum, "bqAfJHNMWG3f6CSqpglrDE") == 0) {
          extern mxArray *sf_c3_untitled2_third_party_uses_info(void);
          plhs[0] = sf_c3_untitled2_third_party_uses_info();
          break;
        }
      }

     case 4:
      {
        if (strcmp(tpChksum, "DuVCbSrMi1czR0FoDVFeX") == 0) {
          extern mxArray *sf_c4_untitled2_third_party_uses_info(void);
          plhs[0] = sf_c4_untitled2_third_party_uses_info();
          break;
        }
      }

     case 5:
      {
        if (strcmp(tpChksum, "gUaPhH2UREQFOyQqhd721F") == 0) {
          extern mxArray *sf_c5_untitled2_third_party_uses_info(void);
          plhs[0] = sf_c5_untitled2_third_party_uses_info();
          break;
        }
      }

     case 6:
      {
        if (strcmp(tpChksum, "8D8CprwVtqj5tlBW5AGzNC") == 0) {
          extern mxArray *sf_c6_untitled2_third_party_uses_info(void);
          plhs[0] = sf_c6_untitled2_third_party_uses_info();
          break;
        }
      }

     case 7:
      {
        if (strcmp(tpChksum, "RWdYnOnaRHWVoGnzVDr7e") == 0) {
          extern mxArray *sf_c7_untitled2_third_party_uses_info(void);
          plhs[0] = sf_c7_untitled2_third_party_uses_info();
          break;
        }
      }

     case 8:
      {
        if (strcmp(tpChksum, "5ViGpA5JT14m5ZWvDXspQG") == 0) {
          extern mxArray *sf_c8_untitled2_third_party_uses_info(void);
          plhs[0] = sf_c8_untitled2_third_party_uses_info();
          break;
        }
      }

     case 9:
      {
        if (strcmp(tpChksum, "fE5lRebjdDQO7T62B6bjxE") == 0) {
          extern mxArray *sf_c9_untitled2_third_party_uses_info(void);
          plhs[0] = sf_c9_untitled2_third_party_uses_info();
          break;
        }
      }

     case 10:
      {
        if (strcmp(tpChksum, "5Pxhs1sqPplXzWULOjc6xC") == 0) {
          extern mxArray *sf_c10_untitled2_third_party_uses_info(void);
          plhs[0] = sf_c10_untitled2_third_party_uses_info();
          break;
        }
      }

     case 11:
      {
        if (strcmp(tpChksum, "efzjEfChVvLxpyxsQGJNbE") == 0) {
          extern mxArray *sf_c11_untitled2_third_party_uses_info(void);
          plhs[0] = sf_c11_untitled2_third_party_uses_info();
          break;
        }
      }

     case 12:
      {
        if (strcmp(tpChksum, "26zOi9EMAEoF52QYPpcfd") == 0) {
          extern mxArray *sf_c12_untitled2_third_party_uses_info(void);
          plhs[0] = sf_c12_untitled2_third_party_uses_info();
          break;
        }
      }

     case 14:
      {
        if (strcmp(tpChksum, "A9DuzYjzXDMUOVe0AYeaiE") == 0) {
          extern mxArray *sf_c14_untitled2_third_party_uses_info(void);
          plhs[0] = sf_c14_untitled2_third_party_uses_info();
          break;
        }
      }

     default:
      plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
    }
  }

  return 1;
}

unsigned int sf_untitled2_updateBuildInfo_args_info( int nlhs, mxArray * plhs[],
  int nrhs, const mxArray * prhs[] )
{
  char commandName[64];
  char tpChksum[64];
  if (nrhs<3 || !mxIsChar(prhs[0]))
    return 0;

  /* Possible call to get the updateBuildInfo_args_info */
  mxGetString(prhs[0], commandName,sizeof(commandName)/sizeof(char));
  commandName[(sizeof(commandName)/sizeof(char)-1)] = '\0';
  mxGetString(prhs[2], tpChksum,sizeof(tpChksum)/sizeof(char));
  tpChksum[(sizeof(tpChksum)/sizeof(char)-1)] = '\0';
  if (strcmp(commandName,"get_updateBuildInfo_args_info"))
    return 0;

  {
    unsigned int chartFileNumber;
    chartFileNumber = (unsigned int)mxGetScalar(prhs[1]);
    switch (chartFileNumber) {
     case 1:
      {
        if (strcmp(tpChksum, "ZKG0Ma4HOCVACaYn4ApLUE") == 0) {
          extern mxArray *sf_c1_untitled2_updateBuildInfo_args_info(void);
          plhs[0] = sf_c1_untitled2_updateBuildInfo_args_info();
          break;
        }
      }

     case 2:
      {
        if (strcmp(tpChksum, "WdnEe8bBkgftP4fW4agX7C") == 0) {
          extern mxArray *sf_c2_untitled2_updateBuildInfo_args_info(void);
          plhs[0] = sf_c2_untitled2_updateBuildInfo_args_info();
          break;
        }
      }

     case 3:
      {
        if (strcmp(tpChksum, "bqAfJHNMWG3f6CSqpglrDE") == 0) {
          extern mxArray *sf_c3_untitled2_updateBuildInfo_args_info(void);
          plhs[0] = sf_c3_untitled2_updateBuildInfo_args_info();
          break;
        }
      }

     case 4:
      {
        if (strcmp(tpChksum, "DuVCbSrMi1czR0FoDVFeX") == 0) {
          extern mxArray *sf_c4_untitled2_updateBuildInfo_args_info(void);
          plhs[0] = sf_c4_untitled2_updateBuildInfo_args_info();
          break;
        }
      }

     case 5:
      {
        if (strcmp(tpChksum, "gUaPhH2UREQFOyQqhd721F") == 0) {
          extern mxArray *sf_c5_untitled2_updateBuildInfo_args_info(void);
          plhs[0] = sf_c5_untitled2_updateBuildInfo_args_info();
          break;
        }
      }

     case 6:
      {
        if (strcmp(tpChksum, "8D8CprwVtqj5tlBW5AGzNC") == 0) {
          extern mxArray *sf_c6_untitled2_updateBuildInfo_args_info(void);
          plhs[0] = sf_c6_untitled2_updateBuildInfo_args_info();
          break;
        }
      }

     case 7:
      {
        if (strcmp(tpChksum, "RWdYnOnaRHWVoGnzVDr7e") == 0) {
          extern mxArray *sf_c7_untitled2_updateBuildInfo_args_info(void);
          plhs[0] = sf_c7_untitled2_updateBuildInfo_args_info();
          break;
        }
      }

     case 8:
      {
        if (strcmp(tpChksum, "5ViGpA5JT14m5ZWvDXspQG") == 0) {
          extern mxArray *sf_c8_untitled2_updateBuildInfo_args_info(void);
          plhs[0] = sf_c8_untitled2_updateBuildInfo_args_info();
          break;
        }
      }

     case 9:
      {
        if (strcmp(tpChksum, "fE5lRebjdDQO7T62B6bjxE") == 0) {
          extern mxArray *sf_c9_untitled2_updateBuildInfo_args_info(void);
          plhs[0] = sf_c9_untitled2_updateBuildInfo_args_info();
          break;
        }
      }

     case 10:
      {
        if (strcmp(tpChksum, "5Pxhs1sqPplXzWULOjc6xC") == 0) {
          extern mxArray *sf_c10_untitled2_updateBuildInfo_args_info(void);
          plhs[0] = sf_c10_untitled2_updateBuildInfo_args_info();
          break;
        }
      }

     case 11:
      {
        if (strcmp(tpChksum, "efzjEfChVvLxpyxsQGJNbE") == 0) {
          extern mxArray *sf_c11_untitled2_updateBuildInfo_args_info(void);
          plhs[0] = sf_c11_untitled2_updateBuildInfo_args_info();
          break;
        }
      }

     case 12:
      {
        if (strcmp(tpChksum, "26zOi9EMAEoF52QYPpcfd") == 0) {
          extern mxArray *sf_c12_untitled2_updateBuildInfo_args_info(void);
          plhs[0] = sf_c12_untitled2_updateBuildInfo_args_info();
          break;
        }
      }

     case 14:
      {
        if (strcmp(tpChksum, "A9DuzYjzXDMUOVe0AYeaiE") == 0) {
          extern mxArray *sf_c14_untitled2_updateBuildInfo_args_info(void);
          plhs[0] = sf_c14_untitled2_updateBuildInfo_args_info();
          break;
        }
      }

     default:
      plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
    }
  }

  return 1;
}

void untitled2_debug_initialize(struct SfDebugInstanceStruct* debugInstance)
{
  _untitled2MachineNumber_ = sf_debug_initialize_machine(debugInstance,
    "untitled2","sfun",0,13,0,0,0);
  sf_debug_set_machine_event_thresholds(debugInstance,_untitled2MachineNumber_,0,
    0);
  sf_debug_set_machine_data_thresholds(debugInstance,_untitled2MachineNumber_,0);
}

void untitled2_register_exported_symbols(SimStruct* S)
{
}

static mxArray* sRtwOptimizationInfoStruct= NULL;
mxArray* load_untitled2_optimization_info(void)
{
  if (sRtwOptimizationInfoStruct==NULL) {
    sRtwOptimizationInfoStruct = sf_load_rtw_optimization_info("untitled2",
      "untitled2");
    mexMakeArrayPersistent(sRtwOptimizationInfoStruct);
  }

  return(sRtwOptimizationInfoStruct);
}

void unload_untitled2_optimization_info(void)
{
  if (sRtwOptimizationInfoStruct!=NULL) {
    mxDestroyArray(sRtwOptimizationInfoStruct);
    sRtwOptimizationInfoStruct = NULL;
  }
}

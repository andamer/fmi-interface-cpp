/* Algebraic */
#include "FmiTest_Model_model.h"

#ifdef __cplusplus
extern "C" {
#endif


/* forwarded equations */
extern void FmiTest_Model_eqFunction_15(DATA* data, threadData_t *threadData);
extern void FmiTest_Model_eqFunction_17(DATA* data, threadData_t *threadData);

static void functionAlg_system0(DATA *data, threadData_t *threadData)
{
    FmiTest_Model_eqFunction_15(data, threadData);

    FmiTest_Model_eqFunction_17(data, threadData);
}
/* for continuous time variables */
int FmiTest_Model_functionAlgebraics(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH

#if !defined(OMC_MINIMAL_RUNTIME)
  if (measure_time_flag) rt_tick(SIM_TIMER_ALGEBRAICS);
#endif
  data->simulationInfo->callStatistics.functionAlgebraics++;

  functionAlg_system0(data, threadData);

  FmiTest_Model_function_savePreSynchronous(data, threadData);
  
#if !defined(OMC_MINIMAL_RUNTIME)
  if (measure_time_flag) rt_accumulate(SIM_TIMER_ALGEBRAICS);
#endif

  TRACE_POP
  return 0;
}

#ifdef __cplusplus
}
#endif

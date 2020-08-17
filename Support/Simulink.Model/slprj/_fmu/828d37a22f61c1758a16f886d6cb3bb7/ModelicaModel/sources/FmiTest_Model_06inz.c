/* Initialization */
#include "FmiTest_Model_model.h"
#include "FmiTest_Model_11mix.h"
#include "FmiTest_Model_12jac.h"
#if defined(__cplusplus)
extern "C" {
#endif

void FmiTest_Model_functionInitialEquations_0(DATA *data, threadData_t *threadData);

/*
equation index: 1
type: SIMPLE_ASSIGN
adaptor.y1 = 0.0
*/
void FmiTest_Model_eqFunction_1(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1};
  data->localData[0]->realVars[4] /* adaptor.y1 variable */ = 0.0;
  TRACE_POP
}

/*
equation index: 2
type: SIMPLE_ASSIGN
adaptor.y2 = 0.0
*/
void FmiTest_Model_eqFunction_2(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,2};
  data->localData[0]->realVars[5] /* adaptor.y2 variable */ = 0.0;
  TRACE_POP
}

/*
equation index: 3
type: SIMPLE_ASSIGN
adaptor.u1 = 0.0
*/
void FmiTest_Model_eqFunction_3(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,3};
  data->localData[0]->realVars[2] /* adaptor.u1 variable */ = 0.0;
  TRACE_POP
}

/*
equation index: 4
type: SIMPLE_ASSIGN
adaptor.u2 = 0.0
*/
void FmiTest_Model_eqFunction_4(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,4};
  data->localData[0]->realVars[3] /* adaptor.u2 variable */ = 0.0;
  TRACE_POP
}

/*
equation index: 5
type: SIMPLE_ASSIGN
gnd.p.i = 0.0
*/
void FmiTest_Model_eqFunction_5(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,5};
  data->localData[0]->realVars[6] /* gnd.p.i variable */ = 0.0;
  TRACE_POP
}

/*
equation index: 6
type: SIMPLE_ASSIGN
c.v = $START.c.v
*/
void FmiTest_Model_eqFunction_6(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,6};
  data->localData[0]->realVars[0] /* c.v STATE(1) */ = data->modelData->realVarsData[0].attribute /* c.v STATE(1) */.start;
  TRACE_POP
}

/*
equation index: 7
type: SIMPLE_ASSIGN
r.R_actual = r.R * (1.0 + r.alpha * (r.T - r.T_ref))
*/
void FmiTest_Model_eqFunction_7(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,7};
  data->localData[0]->realVars[10] /* r.R_actual variable */ = (data->simulationInfo->realParameter[1] /* r.R PARAM */) * (1.0 + (data->simulationInfo->realParameter[5] /* r.alpha PARAM */) * (data->simulationInfo->realParameter[2] /* r.T PARAM */ - data->simulationInfo->realParameter[4] /* r.T_ref PARAM */));
  TRACE_POP
}
extern void FmiTest_Model_eqFunction_13(DATA *data, threadData_t *threadData);

extern void FmiTest_Model_eqFunction_14(DATA *data, threadData_t *threadData);

extern void FmiTest_Model_eqFunction_15(DATA *data, threadData_t *threadData);

extern void FmiTest_Model_eqFunction_16(DATA *data, threadData_t *threadData);


/*
equation index: 12
type: SIMPLE_ASSIGN
gnd.p.v = 0.0
*/
void FmiTest_Model_eqFunction_12(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,12};
  data->localData[0]->realVars[7] /* gnd.p.v variable */ = 0.0;
  TRACE_POP
}
OMC_DISABLE_OPT
void FmiTest_Model_functionInitialEquations_0(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  FmiTest_Model_eqFunction_1(data, threadData);
  FmiTest_Model_eqFunction_2(data, threadData);
  FmiTest_Model_eqFunction_3(data, threadData);
  FmiTest_Model_eqFunction_4(data, threadData);
  FmiTest_Model_eqFunction_5(data, threadData);
  FmiTest_Model_eqFunction_6(data, threadData);
  FmiTest_Model_eqFunction_7(data, threadData);
  FmiTest_Model_eqFunction_13(data, threadData);
  FmiTest_Model_eqFunction_14(data, threadData);
  FmiTest_Model_eqFunction_15(data, threadData);
  FmiTest_Model_eqFunction_16(data, threadData);
  FmiTest_Model_eqFunction_12(data, threadData);
  TRACE_POP
}


int FmiTest_Model_functionInitialEquations(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH

  data->simulationInfo->discreteCall = 1;
  FmiTest_Model_functionInitialEquations_0(data, threadData);
  data->simulationInfo->discreteCall = 0;
  
  TRACE_POP
  return 0;
}


int FmiTest_Model_functionInitialEquations_lambda0(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH

  data->simulationInfo->discreteCall = 1;
  data->simulationInfo->discreteCall = 0;
  
  TRACE_POP
  return 0;
}
int FmiTest_Model_functionRemovedInitialEquations(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int *equationIndexes = NULL;
  double res = 0.0;

  
  TRACE_POP
  return 0;
}


#if defined(__cplusplus)
}
#endif


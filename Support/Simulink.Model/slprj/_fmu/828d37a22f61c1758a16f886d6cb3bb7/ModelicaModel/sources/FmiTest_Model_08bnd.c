/* update bound parameters and variable attributes (start, nominal, min, max) */
#include "FmiTest_Model_model.h"
#if defined(__cplusplus)
extern "C" {
#endif

OMC_DISABLE_OPT
int FmiTest_Model_updateBoundVariableAttributes(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  /* min ******************************************************** */
  
  infoStreamPrint(LOG_INIT, 1, "updating min-values");
  if (ACTIVE_STREAM(LOG_INIT)) messageClose(LOG_INIT);
  
  /* max ******************************************************** */
  
  infoStreamPrint(LOG_INIT, 1, "updating max-values");
  if (ACTIVE_STREAM(LOG_INIT)) messageClose(LOG_INIT);
  
  /* nominal **************************************************** */
  
  infoStreamPrint(LOG_INIT, 1, "updating nominal-values");
  if (ACTIVE_STREAM(LOG_INIT)) messageClose(LOG_INIT);
  
  /* start ****************************************************** */
  infoStreamPrint(LOG_INIT, 1, "updating primary start-values");
  if (ACTIVE_STREAM(LOG_INIT)) messageClose(LOG_INIT);
  
  TRACE_POP
  return 0;
}

void FmiTest_Model_updateBoundParameters_0(DATA *data, threadData_t *threadData);

/*
equation index: 18
type: SIMPLE_ASSIGN
r.T = r.T_ref
*/
OMC_DISABLE_OPT
static void FmiTest_Model_eqFunction_18(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,18};
  data->simulationInfo->realParameter[2] /* r.T PARAM */ = data->simulationInfo->realParameter[4] /* r.T_ref PARAM */;
  TRACE_POP
}

/*
equation index: 19
type: SIMPLE_ASSIGN
r.T_heatPort = r.T
*/
OMC_DISABLE_OPT
static void FmiTest_Model_eqFunction_19(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,19};
  data->simulationInfo->realParameter[3] /* r.T_heatPort PARAM */ = data->simulationInfo->realParameter[2] /* r.T PARAM */;
  TRACE_POP
}

/*
equation index: 21
type: SIMPLE_ASSIGN
adaptor.Name_fder2 = "d2i"
*/
OMC_DISABLE_OPT
static void FmiTest_Model_eqFunction_21(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,21};
  data->simulationInfo->stringParameter[2] /* adaptor.Name_fder2 PARAM */ = _OMC_LIT2;
  TRACE_POP
}

/*
equation index: 22
type: SIMPLE_ASSIGN
adaptor.Name_fder = "di"
*/
OMC_DISABLE_OPT
static void FmiTest_Model_eqFunction_22(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,22};
  data->simulationInfo->stringParameter[1] /* adaptor.Name_fder PARAM */ = _OMC_LIT3;
  TRACE_POP
}

/*
equation index: 23
type: SIMPLE_ASSIGN
adaptor.Name_f = "i"
*/
OMC_DISABLE_OPT
static void FmiTest_Model_eqFunction_23(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,23};
  data->simulationInfo->stringParameter[0] /* adaptor.Name_f PARAM */ = _OMC_LIT4;
  TRACE_POP
}

/*
equation index: 24
type: SIMPLE_ASSIGN
adaptor.Name_pder2 = "d2v"
*/
OMC_DISABLE_OPT
static void FmiTest_Model_eqFunction_24(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,24};
  data->simulationInfo->stringParameter[5] /* adaptor.Name_pder2 PARAM */ = _OMC_LIT5;
  TRACE_POP
}

/*
equation index: 25
type: SIMPLE_ASSIGN
adaptor.Name_pder = "dv"
*/
OMC_DISABLE_OPT
static void FmiTest_Model_eqFunction_25(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,25};
  data->simulationInfo->stringParameter[4] /* adaptor.Name_pder PARAM */ = _OMC_LIT6;
  TRACE_POP
}

/*
equation index: 26
type: SIMPLE_ASSIGN
adaptor.Name_p = "v"
*/
OMC_DISABLE_OPT
static void FmiTest_Model_eqFunction_26(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,26};
  data->simulationInfo->stringParameter[3] /* adaptor.Name_p PARAM */ = _OMC_LIT7;
  TRACE_POP
}
extern void FmiTest_Model_eqFunction_12(DATA *data, threadData_t *threadData);

extern void FmiTest_Model_eqFunction_7(DATA *data, threadData_t *threadData);

extern void FmiTest_Model_eqFunction_5(DATA *data, threadData_t *threadData);

extern void FmiTest_Model_eqFunction_4(DATA *data, threadData_t *threadData);

extern void FmiTest_Model_eqFunction_3(DATA *data, threadData_t *threadData);

extern void FmiTest_Model_eqFunction_2(DATA *data, threadData_t *threadData);

extern void FmiTest_Model_eqFunction_1(DATA *data, threadData_t *threadData);


/*
equation index: 38
type: ALGORITHM

  assert(r.T_ref >= 0.0, "Variable violating min constraint: 0.0 <= r.T_ref, has value: " + String(r.T_ref, "g"));
*/
OMC_DISABLE_OPT
static void FmiTest_Model_eqFunction_38(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,38};
  modelica_boolean tmp0;
  static const MMC_DEFSTRINGLIT(tmp1,62,"Variable violating min constraint: 0.0 <= r.T_ref, has value: ");
  modelica_string tmp2;
  static int tmp3 = 0;
  modelica_metatype tmpMeta[1] __attribute__((unused)) = {0};
  if(!tmp3)
  {
    tmp0 = GreaterEq(data->simulationInfo->realParameter[4] /* r.T_ref PARAM */,0.0);
    if(!tmp0)
    {
      tmp2 = modelica_real_to_modelica_string_format(data->simulationInfo->realParameter[4] /* r.T_ref PARAM */, (modelica_string) mmc_strings_len1[103]);
      tmpMeta[0] = stringAppend(MMC_REFSTRINGLIT(tmp1),tmp2);
      {
        FILE_INFO info = {"/usr/lib/omlibrary/Modelica 3.2.3/Electrical/Analog/Basic.mo",39,5,39,66,1};
        omc_assert_warning(info, "The following assertion has been violated %sat time %f\nr.T_ref >= 0.0", initial() ? "during initialization " : "", data->localData[0]->timeValue);
        omc_assert_warning_withEquationIndexes(info, equationIndexes, MMC_STRINGDATA(tmpMeta[0]));
      }
      tmp3 = 1;
    }
  }
  TRACE_POP
}

/*
equation index: 39
type: ALGORITHM

  assert(r.T >= 0.0, "Variable violating min constraint: 0.0 <= r.T, has value: " + String(r.T, "g"));
*/
OMC_DISABLE_OPT
static void FmiTest_Model_eqFunction_39(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,39};
  modelica_boolean tmp4;
  static const MMC_DEFSTRINGLIT(tmp5,58,"Variable violating min constraint: 0.0 <= r.T, has value: ");
  modelica_string tmp6;
  static int tmp7 = 0;
  modelica_metatype tmpMeta[1] __attribute__((unused)) = {0};
  if(!tmp7)
  {
    tmp4 = GreaterEq(data->simulationInfo->realParameter[2] /* r.T PARAM */,0.0);
    if(!tmp4)
    {
      tmp6 = modelica_real_to_modelica_string_format(data->simulationInfo->realParameter[2] /* r.T PARAM */, (modelica_string) mmc_strings_len1[103]);
      tmpMeta[0] = stringAppend(MMC_REFSTRINGLIT(tmp5),tmp6);
      {
        FILE_INFO info = {"/usr/lib/omlibrary/Modelica 3.2.3/Electrical/Analog/Interfaces.mo",306,5,307,99,1};
        omc_assert_warning(info, "The following assertion has been violated %sat time %f\nr.T >= 0.0", initial() ? "during initialization " : "", data->localData[0]->timeValue);
        omc_assert_warning_withEquationIndexes(info, equationIndexes, MMC_STRINGDATA(tmpMeta[0]));
      }
      tmp7 = 1;
    }
  }
  TRACE_POP
}

/*
equation index: 40
type: ALGORITHM

  assert(r.T_heatPort >= 0.0, "Variable violating min constraint: 0.0 <= r.T_heatPort, has value: " + String(r.T_heatPort, "g"));
*/
OMC_DISABLE_OPT
static void FmiTest_Model_eqFunction_40(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,40};
  modelica_boolean tmp8;
  static const MMC_DEFSTRINGLIT(tmp9,67,"Variable violating min constraint: 0.0 <= r.T_heatPort, has value: ");
  modelica_string tmp10;
  static int tmp11 = 0;
  modelica_metatype tmpMeta[1] __attribute__((unused)) = {0};
  if(!tmp11)
  {
    tmp8 = GreaterEq(data->simulationInfo->realParameter[3] /* r.T_heatPort PARAM */,0.0);
    if(!tmp8)
    {
      tmp10 = modelica_real_to_modelica_string_format(data->simulationInfo->realParameter[3] /* r.T_heatPort PARAM */, (modelica_string) mmc_strings_len1[103]);
      tmpMeta[0] = stringAppend(MMC_REFSTRINGLIT(tmp9),tmp10);
      {
        FILE_INFO info = {"/usr/lib/omlibrary/Modelica 3.2.3/Electrical/Analog/Interfaces.mo",313,5,313,56,1};
        omc_assert_warning(info, "The following assertion has been violated %sat time %f\nr.T_heatPort >= 0.0", initial() ? "during initialization " : "", data->localData[0]->timeValue);
        omc_assert_warning_withEquationIndexes(info, equationIndexes, MMC_STRINGDATA(tmpMeta[0]));
      }
      tmp11 = 1;
    }
  }
  TRACE_POP
}

/*
equation index: 41
type: ALGORITHM

  assert(c.C >= 0.0, "Variable violating min constraint: 0.0 <= c.C, has value: " + String(c.C, "g"));
*/
OMC_DISABLE_OPT
static void FmiTest_Model_eqFunction_41(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,41};
  modelica_boolean tmp12;
  static const MMC_DEFSTRINGLIT(tmp13,58,"Variable violating min constraint: 0.0 <= c.C, has value: ");
  modelica_string tmp14;
  static int tmp15 = 0;
  modelica_metatype tmpMeta[1] __attribute__((unused)) = {0};
  if(!tmp15)
  {
    tmp12 = GreaterEq(data->simulationInfo->realParameter[0] /* c.C PARAM */,0.0);
    if(!tmp12)
    {
      tmp14 = modelica_real_to_modelica_string_format(data->simulationInfo->realParameter[0] /* c.C PARAM */, (modelica_string) mmc_strings_len1[103]);
      tmpMeta[0] = stringAppend(MMC_REFSTRINGLIT(tmp13),tmp14);
      {
        FILE_INFO info = {"/usr/lib/omlibrary/Modelica 3.2.3/Electrical/Analog/Basic.mo",224,5,224,54,1};
        omc_assert_warning(info, "The following assertion has been violated %sat time %f\nc.C >= 0.0", initial() ? "during initialization " : "", data->localData[0]->timeValue);
        omc_assert_warning_withEquationIndexes(info, equationIndexes, MMC_STRINGDATA(tmpMeta[0]));
      }
      tmp15 = 1;
    }
  }
  TRACE_POP
}
OMC_DISABLE_OPT
void FmiTest_Model_updateBoundParameters_0(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  FmiTest_Model_eqFunction_18(data, threadData);
  FmiTest_Model_eqFunction_19(data, threadData);
  FmiTest_Model_eqFunction_21(data, threadData);
  FmiTest_Model_eqFunction_22(data, threadData);
  FmiTest_Model_eqFunction_23(data, threadData);
  FmiTest_Model_eqFunction_24(data, threadData);
  FmiTest_Model_eqFunction_25(data, threadData);
  FmiTest_Model_eqFunction_26(data, threadData);
  FmiTest_Model_eqFunction_12(data, threadData);
  FmiTest_Model_eqFunction_7(data, threadData);
  FmiTest_Model_eqFunction_5(data, threadData);
  FmiTest_Model_eqFunction_4(data, threadData);
  FmiTest_Model_eqFunction_3(data, threadData);
  FmiTest_Model_eqFunction_2(data, threadData);
  FmiTest_Model_eqFunction_1(data, threadData);
  FmiTest_Model_eqFunction_38(data, threadData);
  FmiTest_Model_eqFunction_39(data, threadData);
  FmiTest_Model_eqFunction_40(data, threadData);
  FmiTest_Model_eqFunction_41(data, threadData);
  TRACE_POP
}
OMC_DISABLE_OPT
int FmiTest_Model_updateBoundParameters(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  data->simulationInfo->booleanParameter[0] /* adaptor.use_fder PARAM */ = 0;
  data->modelData->booleanParameterData[0].time_unvarying = 1;
  data->simulationInfo->booleanParameter[1] /* adaptor.use_fder2 PARAM */ = 0;
  data->modelData->booleanParameterData[1].time_unvarying = 1;
  data->simulationInfo->booleanParameter[2] /* adaptor.use_pder PARAM */ = 0;
  data->modelData->booleanParameterData[2].time_unvarying = 1;
  data->simulationInfo->booleanParameter[3] /* adaptor.use_pder2 PARAM */ = 0;
  data->modelData->booleanParameterData[3].time_unvarying = 1;
  data->simulationInfo->booleanParameter[4] /* r.useHeatPort PARAM */ = 0;
  data->modelData->booleanParameterData[4].time_unvarying = 1;
  FmiTest_Model_updateBoundParameters_0(data, threadData);
  TRACE_POP
  return 0;
}

#if defined(__cplusplus)
}
#endif


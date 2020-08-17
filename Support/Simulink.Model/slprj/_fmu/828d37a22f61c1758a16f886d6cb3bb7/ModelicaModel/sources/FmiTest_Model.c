/* Main Simulation File */

#if defined(__cplusplus)
extern "C" {
#endif

#include "FmiTest_Model_model.h"
#include "simulation/solver/events.h"


/* dummy VARINFO and FILEINFO */
const FILE_INFO dummyFILE_INFO = omc_dummyFileInfo;
const VAR_INFO dummyVAR_INFO = omc_dummyVarInfo;

int FmiTest_Model_input_function(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH

  data->localData[0]->realVars[12] /* v variable */ = data->simulationInfo->inputVars[0];
  
  TRACE_POP
  return 0;
}

int FmiTest_Model_input_function_init(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH

  data->simulationInfo->inputVars[0] = data->modelData->realVarsData[12].attribute.start;
  
  TRACE_POP
  return 0;
}

int FmiTest_Model_input_function_updateStartValues(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH

  data->modelData->realVarsData[12].attribute.start = data->simulationInfo->inputVars[0];
  
  TRACE_POP
  return 0;
}

int FmiTest_Model_inputNames(DATA *data, char ** names){
  TRACE_PUSH

  names[0] = (char *) data->modelData->realVarsData[12].info.name;
  
  TRACE_POP
  return 0;
}

int FmiTest_Model_data_function(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH

  TRACE_POP
  return 0;
}

int FmiTest_Model_output_function(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH

  data->simulationInfo->outputVars[0] = data->localData[0]->realVars[8] /* i variable */;
  
  TRACE_POP
  return 0;
}

int FmiTest_Model_setc_function(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH

  
  TRACE_POP
  return 0;
}


/*
equation index: 13
type: SIMPLE_ASSIGN
r.v = v - c.v
*/
void FmiTest_Model_eqFunction_13(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,13};
  data->localData[0]->realVars[11] /* r.v variable */ = data->localData[0]->realVars[12] /* v variable */ - data->localData[0]->realVars[0] /* c.v STATE(1) */;
  TRACE_POP
}
/*
equation index: 14
type: SIMPLE_ASSIGN
i = r.v / r.R_actual
*/
void FmiTest_Model_eqFunction_14(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,14};
  data->localData[0]->realVars[8] /* i variable */ = DIVISION_SIM(data->localData[0]->realVars[11] /* r.v variable */,data->localData[0]->realVars[10] /* r.R_actual variable */,"r.R_actual",equationIndexes);
  TRACE_POP
}
/*
equation index: 15
type: SIMPLE_ASSIGN
r.LossPower = r.v * i
*/
void FmiTest_Model_eqFunction_15(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,15};
  data->localData[0]->realVars[9] /* r.LossPower variable */ = (data->localData[0]->realVars[11] /* r.v variable */) * (data->localData[0]->realVars[8] /* i variable */);
  TRACE_POP
}
/*
equation index: 16
type: SIMPLE_ASSIGN
$DER.c.v = i / c.C
*/
void FmiTest_Model_eqFunction_16(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,16};
  data->localData[0]->realVars[1] /* der(c.v) STATE_DER */ = DIVISION_SIM(data->localData[0]->realVars[8] /* i variable */,data->simulationInfo->realParameter[0] /* c.C PARAM */,"c.C",equationIndexes);
  TRACE_POP
}
/*
equation index: 17
type: ALGORITHM

  assert(1.0 + r.alpha * (r.T - r.T_ref) >= 1e-15, "Temperature outside scope of model!");
*/
void FmiTest_Model_eqFunction_17(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,17};
  modelica_boolean tmp0;
  static const MMC_DEFSTRINGLIT(tmp1,35,"Temperature outside scope of model!");
  static int tmp2 = 0;
  {
    tmp0 = GreaterEq(1.0 + (data->simulationInfo->realParameter[5] /* r.alpha PARAM */) * (data->simulationInfo->realParameter[2] /* r.T PARAM */ - data->simulationInfo->realParameter[4] /* r.T_ref PARAM */),1e-15);
    if(!tmp0)
    {
      {
        FILE_INFO info = {"/usr/lib/omlibrary/Modelica 3.2.3/Electrical/Analog/Basic.mo",49,5,50,45,1};
        omc_assert_warning(info, "The following assertion has been violated %sat time %f\n1.0 + r.alpha * (r.T - r.T_ref) >= 1e-15", initial() ? "during initialization " : "", data->localData[0]->timeValue);
        omc_assert_withEquationIndexes(threadData, info, equationIndexes, MMC_STRINGDATA(MMC_REFSTRINGLIT(tmp1)));
      }
    }
  }
  TRACE_POP
}

OMC_DISABLE_OPT
int FmiTest_Model_functionDAE(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  int equationIndexes[1] = {0};
#if !defined(OMC_MINIMAL_RUNTIME)
  if (measure_time_flag) rt_tick(SIM_TIMER_DAE);
#endif

  data->simulationInfo->needToIterate = 0;
  data->simulationInfo->discreteCall = 1;
  FmiTest_Model_functionLocalKnownVars(data, threadData);
  FmiTest_Model_eqFunction_13(data, threadData);

  FmiTest_Model_eqFunction_14(data, threadData);

  FmiTest_Model_eqFunction_15(data, threadData);

  FmiTest_Model_eqFunction_16(data, threadData);

  FmiTest_Model_eqFunction_17(data, threadData);
  data->simulationInfo->discreteCall = 0;
  
#if !defined(OMC_MINIMAL_RUNTIME)
  if (measure_time_flag) rt_accumulate(SIM_TIMER_DAE);
#endif
  TRACE_POP
  return 0;
}


int FmiTest_Model_functionLocalKnownVars(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH

  
  TRACE_POP
  return 0;
}


/* forwarded equations */
extern void FmiTest_Model_eqFunction_13(DATA* data, threadData_t *threadData);
extern void FmiTest_Model_eqFunction_14(DATA* data, threadData_t *threadData);
extern void FmiTest_Model_eqFunction_16(DATA* data, threadData_t *threadData);

static void functionODE_system0(DATA *data, threadData_t *threadData)
{
    FmiTest_Model_eqFunction_13(data, threadData);

    FmiTest_Model_eqFunction_14(data, threadData);

    FmiTest_Model_eqFunction_16(data, threadData);
}

int FmiTest_Model_functionODE(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
#if !defined(OMC_MINIMAL_RUNTIME)
  if (measure_time_flag) rt_tick(SIM_TIMER_FUNCTION_ODE);
#endif

  
  data->simulationInfo->callStatistics.functionODE++;
  
  FmiTest_Model_functionLocalKnownVars(data, threadData);
  functionODE_system0(data, threadData);

#if !defined(OMC_MINIMAL_RUNTIME)
  if (measure_time_flag) rt_accumulate(SIM_TIMER_FUNCTION_ODE);
#endif

  TRACE_POP
  return 0;
}

/* forward the main in the simulation runtime */
extern int _main_SimulationRuntime(int argc, char**argv, DATA *data, threadData_t *threadData);

#include "FmiTest_Model_12jac.h"
#include "FmiTest_Model_13opt.h"

struct OpenModelicaGeneratedFunctionCallbacks FmiTest_Model_callback = {
   NULL,
   NULL,
   NULL,
   FmiTest_Model_callExternalObjectDestructors,
   NULL,
   NULL,
   NULL,
   #if !defined(OMC_NO_STATESELECTION)
   FmiTest_Model_initializeStateSets,
   #else
   NULL,
   #endif
   FmiTest_Model_initializeDAEmodeData,
   FmiTest_Model_functionODE,
   FmiTest_Model_functionAlgebraics,
   FmiTest_Model_functionDAE,
   FmiTest_Model_functionLocalKnownVars,
   FmiTest_Model_input_function,
   FmiTest_Model_input_function_init,
   FmiTest_Model_input_function_updateStartValues,
   FmiTest_Model_data_function,
   FmiTest_Model_output_function,
   FmiTest_Model_setc_function,
   FmiTest_Model_function_storeDelayed,
   FmiTest_Model_updateBoundVariableAttributes,
   FmiTest_Model_functionInitialEquations,
   1, /* useHomotopy - 0: local homotopy (equidistant lambda), 1: global homotopy (equidistant lambda), 2: new global homotopy approach (adaptive lambda), 3: new local homotopy approach (adaptive lambda)*/
   FmiTest_Model_functionInitialEquations_lambda0,
   FmiTest_Model_functionRemovedInitialEquations,
   FmiTest_Model_updateBoundParameters,
   FmiTest_Model_checkForAsserts,
   FmiTest_Model_function_ZeroCrossingsEquations,
   FmiTest_Model_function_ZeroCrossings,
   FmiTest_Model_function_updateRelations,
   FmiTest_Model_zeroCrossingDescription,
   FmiTest_Model_relationDescription,
   FmiTest_Model_function_initSample,
   FmiTest_Model_INDEX_JAC_A,
   FmiTest_Model_INDEX_JAC_B,
   FmiTest_Model_INDEX_JAC_C,
   FmiTest_Model_INDEX_JAC_D,
   FmiTest_Model_INDEX_JAC_F,
   FmiTest_Model_initialAnalyticJacobianA,
   FmiTest_Model_initialAnalyticJacobianB,
   FmiTest_Model_initialAnalyticJacobianC,
   FmiTest_Model_initialAnalyticJacobianD,
   FmiTest_Model_initialAnalyticJacobianF,
   FmiTest_Model_functionJacA_column,
   FmiTest_Model_functionJacB_column,
   FmiTest_Model_functionJacC_column,
   FmiTest_Model_functionJacD_column,
   FmiTest_Model_functionJacF_column,
   FmiTest_Model_linear_model_frame,
   FmiTest_Model_linear_model_datarecovery_frame,
   FmiTest_Model_mayer,
   FmiTest_Model_lagrange,
   FmiTest_Model_pickUpBoundsForInputsInOptimization,
   FmiTest_Model_setInputData,
   FmiTest_Model_getTimeGrid,
   FmiTest_Model_symbolicInlineSystem,
   FmiTest_Model_function_initSynchronous,
   FmiTest_Model_function_updateSynchronous,
   FmiTest_Model_function_equationsSynchronous,
   FmiTest_Model_inputNames,
   FmiTest_Model_read_input_fmu,
   NULL,
   NULL,
   -1

};

#define _OMC_LIT_RESOURCE_0_name_data "Complex"
#define _OMC_LIT_RESOURCE_0_dir_data "/usr/lib/omlibrary"
static const MMC_DEFSTRINGLIT(_OMC_LIT_RESOURCE_0_name,7,_OMC_LIT_RESOURCE_0_name_data);
static const MMC_DEFSTRINGLIT(_OMC_LIT_RESOURCE_0_dir,18,_OMC_LIT_RESOURCE_0_dir_data);

#define _OMC_LIT_RESOURCE_1_name_data "FmiTest"
#define _OMC_LIT_RESOURCE_1_dir_data "/home/ubuntu/Scrivania/fmi-interface-cpp"
static const MMC_DEFSTRINGLIT(_OMC_LIT_RESOURCE_1_name,7,_OMC_LIT_RESOURCE_1_name_data);
static const MMC_DEFSTRINGLIT(_OMC_LIT_RESOURCE_1_dir,40,_OMC_LIT_RESOURCE_1_dir_data);

#define _OMC_LIT_RESOURCE_2_name_data "Modelica"
#define _OMC_LIT_RESOURCE_2_dir_data "/usr/lib/omlibrary/Modelica 3.2.3"
static const MMC_DEFSTRINGLIT(_OMC_LIT_RESOURCE_2_name,8,_OMC_LIT_RESOURCE_2_name_data);
static const MMC_DEFSTRINGLIT(_OMC_LIT_RESOURCE_2_dir,33,_OMC_LIT_RESOURCE_2_dir_data);

#define _OMC_LIT_RESOURCE_3_name_data "ModelicaServices"
#define _OMC_LIT_RESOURCE_3_dir_data "/usr/lib/omlibrary/ModelicaServices 3.2.3"
static const MMC_DEFSTRINGLIT(_OMC_LIT_RESOURCE_3_name,16,_OMC_LIT_RESOURCE_3_name_data);
static const MMC_DEFSTRINGLIT(_OMC_LIT_RESOURCE_3_dir,41,_OMC_LIT_RESOURCE_3_dir_data);

static const MMC_DEFSTRUCTLIT(_OMC_LIT_RESOURCES,8,MMC_ARRAY_TAG) {MMC_REFSTRINGLIT(_OMC_LIT_RESOURCE_0_name), MMC_REFSTRINGLIT(_OMC_LIT_RESOURCE_0_dir), MMC_REFSTRINGLIT(_OMC_LIT_RESOURCE_1_name), MMC_REFSTRINGLIT(_OMC_LIT_RESOURCE_1_dir), MMC_REFSTRINGLIT(_OMC_LIT_RESOURCE_2_name), MMC_REFSTRINGLIT(_OMC_LIT_RESOURCE_2_dir), MMC_REFSTRINGLIT(_OMC_LIT_RESOURCE_3_name), MMC_REFSTRINGLIT(_OMC_LIT_RESOURCE_3_dir)}};
void FmiTest_Model_setupDataStruc(DATA *data, threadData_t *threadData)
{
  assertStreamPrint(threadData,0!=data, "Error while initialize Data");
  threadData->localRoots[LOCAL_ROOT_SIMULATION_DATA] = data;
  data->callback = &FmiTest_Model_callback;
  OpenModelica_updateUriMapping(threadData, MMC_REFSTRUCTLIT(_OMC_LIT_RESOURCES));
  data->modelData->modelName = "FmiTest.Model";
  data->modelData->modelFilePrefix = "FmiTest_Model";
  data->modelData->resultFileName = NULL;
  data->modelData->modelDir = "/home/ubuntu/Scrivania/fmi-interface-cpp";
  data->modelData->modelGUID = "{ba983c87-41d4-434d-afd7-e5eb2473f538}";
  data->modelData->initXMLData = NULL;
  data->modelData->modelDataXml.infoXMLData = NULL;
  data->modelData->runTestsuite = 0;
  
  data->modelData->nStates = 1;
  data->modelData->nVariablesReal = 13;
  data->modelData->nDiscreteReal = 0;
  data->modelData->nVariablesInteger = 0;
  data->modelData->nVariablesBoolean = 0;
  data->modelData->nVariablesString = 0;
  data->modelData->nParametersReal = 6;
  data->modelData->nParametersInteger = 0;
  data->modelData->nParametersBoolean = 5;
  data->modelData->nParametersString = 6;
  data->modelData->nInputVars = 1;
  data->modelData->nOutputVars = 1;
  
  data->modelData->nAliasReal = 21;
  data->modelData->nAliasInteger = 0;
  data->modelData->nAliasBoolean = 0;
  data->modelData->nAliasString = 0;
  
  data->modelData->nZeroCrossings = 0;
  data->modelData->nSamples = 0;
  data->modelData->nRelations = 0;
  data->modelData->nMathEvents = 0;
  data->modelData->nExtObjs = 0;
  
  GC_asprintf(&data->modelData->modelDataXml.fileName, "%s/FmiTest_Model_info.json", data->modelData->resourcesDir);
  data->modelData->modelDataXml.modelInfoXmlLength = 0;
  data->modelData->modelDataXml.nFunctions = 0;
  data->modelData->modelDataXml.nProfileBlocks = 0;
  data->modelData->modelDataXml.nEquations = 42;
  data->modelData->nMixedSystems = 0;
  data->modelData->nLinearSystems = 0;
  data->modelData->nNonLinearSystems = 0;
  data->modelData->nStateSets = 0;
  data->modelData->nJacobians = 5;
  data->modelData->nOptimizeConstraints = 0;
  data->modelData->nOptimizeFinalConstraints = 0;
  
  data->modelData->nDelayExpressions = 0;
  
  data->modelData->nClocks = 0;
  data->modelData->nSubClocks = 0;
  
  data->modelData->nSensitivityVars = 0;
  data->modelData->nSensitivityParamVars = 0;
  data->modelData->nSetcVars = 0;
  data->modelData->ndataReconVars = 0;
  data->modelData->linearizationDumpLanguage =
  OMC_LINEARIZE_DUMP_LANGUAGE_MODELICA;
}

static int rml_execution_failed()
{
  fflush(NULL);
  fprintf(stderr, "Execution failed!\n");
  fflush(NULL);
  return 1;
}


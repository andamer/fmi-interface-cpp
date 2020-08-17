// define class name and unique id
#define MODEL_IDENTIFIER FmiTest_Model
#define MODEL_GUID "{ba983c87-41d4-434d-afd7-e5eb2473f538}"

// include fmu header files, typedefs and macros
#include <stdio.h>
#include <string.h>
#include <assert.h>
#include "openmodelica.h"
#include "openmodelica_func.h"
#include "simulation_data.h"
#include "util/omc_error.h"
#include "FmiTest_Model_functions.h"
#include "simulation/solver/initialization/initialization.h"
#include "simulation/solver/events.h"
#include "fmi-export/fmu2_model_interface.h"
#include "fmi-export/fmu_read_flags.h"

#ifdef __cplusplus
extern "C" {
#endif

void setStartValues(ModelInstance *comp);
void setDefaultStartValues(ModelInstance *comp);
void eventUpdate(ModelInstance* comp, fmi2EventInfo* eventInfo);
fmi2Real getReal(ModelInstance* comp, const fmi2ValueReference vr);
fmi2Status setReal(ModelInstance* comp, const fmi2ValueReference vr, const fmi2Real value);
fmi2Integer getInteger(ModelInstance* comp, const fmi2ValueReference vr);
fmi2Status setInteger(ModelInstance* comp, const fmi2ValueReference vr, const fmi2Integer value);
fmi2Boolean getBoolean(ModelInstance* comp, const fmi2ValueReference vr);
fmi2Status setBoolean(ModelInstance* comp, const fmi2ValueReference vr, const fmi2Boolean value);
fmi2String getString(ModelInstance* comp, const fmi2ValueReference vr);
fmi2Status setString(ModelInstance* comp, const fmi2ValueReference vr, fmi2String value);
fmi2Status setExternalFunction(ModelInstance* c, const fmi2ValueReference vr, const void* value);
fmi2ValueReference mapInputReference2InputNumber(const fmi2ValueReference vr);
fmi2ValueReference mapOutputReference2OutputNumber(const fmi2ValueReference vr);

// define model size
#define NUMBER_OF_STATES 1
#define NUMBER_OF_EVENT_INDICATORS 0
#define NUMBER_OF_REALS 40
#define NUMBER_OF_INTEGERS 0
#define NUMBER_OF_STRINGS 6
#define NUMBER_OF_BOOLEANS 5
#define NUMBER_OF_EXTERNALFUNCTIONS 0

// define initial state vector as vector of value references
#define STATES { 0 }
#define STATESDERIVATIVES { 1 }


// implementation of the Model Exchange functions
extern void FmiTest_Model_setupDataStruc(DATA *data, threadData_t *threadData);
#define fmu2_model_interface_setupDataStruc FmiTest_Model_setupDataStruc
#include "fmi-export/fmu2_model_interface.c.inc"
#include "fmi-export/fmu_read_flags.c.inc"

// Set values for all variables that define a start value
OMC_DISABLE_OPT
void setDefaultStartValues(ModelInstance *comp) {
  comp->fmuData->modelData->realVarsData[0].attribute.start = 0.0;
  comp->fmuData->modelData->realVarsData[1].attribute.start = 0;
  comp->fmuData->modelData->realVarsData[2].attribute.start = 0.0;
  comp->fmuData->modelData->realVarsData[3].attribute.start = 0.0;
  comp->fmuData->modelData->realVarsData[4].attribute.start = 0.0;
  comp->fmuData->modelData->realVarsData[5].attribute.start = 0.0;
  comp->fmuData->modelData->realVarsData[6].attribute.start = 0.0;
  comp->fmuData->modelData->realVarsData[7].attribute.start = 0.0;
  comp->fmuData->modelData->realVarsData[8].attribute.start = 0;
  comp->fmuData->modelData->realVarsData[9].attribute.start = 0;
  comp->fmuData->modelData->realVarsData[10].attribute.start = 0.0;
  comp->fmuData->modelData->realVarsData[11].attribute.start = 0;
  comp->fmuData->modelData->realVarsData[12].attribute.start = 0.0;
  comp->fmuData->modelData->realParameterData[0].attribute.start = 0.0001;
  comp->fmuData->modelData->realParameterData[1].attribute.start = 1000.0;
  comp->fmuData->modelData->realParameterData[2].attribute.start = 0;
  comp->fmuData->modelData->realParameterData[3].attribute.start = 0;
  comp->fmuData->modelData->realParameterData[4].attribute.start = 300.15;
  comp->fmuData->modelData->realParameterData[5].attribute.start = 0.0;
  comp->fmuData->modelData->booleanParameterData[0].attribute.start = 0;
  comp->fmuData->modelData->booleanParameterData[1].attribute.start = 0;
  comp->fmuData->modelData->booleanParameterData[2].attribute.start = 0;
  comp->fmuData->modelData->booleanParameterData[3].attribute.start = 0;
  comp->fmuData->modelData->booleanParameterData[4].attribute.start = 0;
  comp->fmuData->modelData->stringParameterData[0].attribute.start = mmc_mk_scon("");
  comp->fmuData->modelData->stringParameterData[1].attribute.start = mmc_mk_scon("");
  comp->fmuData->modelData->stringParameterData[2].attribute.start = mmc_mk_scon("");
  comp->fmuData->modelData->stringParameterData[3].attribute.start = mmc_mk_scon("");
  comp->fmuData->modelData->stringParameterData[4].attribute.start = mmc_mk_scon("");
  comp->fmuData->modelData->stringParameterData[5].attribute.start = mmc_mk_scon("");
}
// Set values for all variables that define a start value
OMC_DISABLE_OPT
void setStartValues(ModelInstance *comp) {
  comp->fmuData->modelData->realVarsData[0].attribute.start =  comp->fmuData->localData[0]->realVars[0];
  comp->fmuData->modelData->realVarsData[1].attribute.start =  comp->fmuData->localData[0]->realVars[1];
  comp->fmuData->modelData->realVarsData[2].attribute.start =  comp->fmuData->localData[0]->realVars[2];
  comp->fmuData->modelData->realVarsData[3].attribute.start =  comp->fmuData->localData[0]->realVars[3];
  comp->fmuData->modelData->realVarsData[4].attribute.start =  comp->fmuData->localData[0]->realVars[4];
  comp->fmuData->modelData->realVarsData[5].attribute.start =  comp->fmuData->localData[0]->realVars[5];
  comp->fmuData->modelData->realVarsData[6].attribute.start =  comp->fmuData->localData[0]->realVars[6];
  comp->fmuData->modelData->realVarsData[7].attribute.start =  comp->fmuData->localData[0]->realVars[7];
  comp->fmuData->modelData->realVarsData[8].attribute.start =  comp->fmuData->localData[0]->realVars[8];
  comp->fmuData->modelData->realVarsData[9].attribute.start =  comp->fmuData->localData[0]->realVars[9];
  comp->fmuData->modelData->realVarsData[10].attribute.start =  comp->fmuData->localData[0]->realVars[10];
  comp->fmuData->modelData->realVarsData[11].attribute.start =  comp->fmuData->localData[0]->realVars[11];
  comp->fmuData->modelData->realVarsData[12].attribute.start =  comp->fmuData->localData[0]->realVars[12];
  comp->fmuData->modelData->realParameterData[0].attribute.start = comp->fmuData->simulationInfo->realParameter[0];
  comp->fmuData->modelData->realParameterData[1].attribute.start = comp->fmuData->simulationInfo->realParameter[1];
  comp->fmuData->modelData->realParameterData[2].attribute.start = comp->fmuData->simulationInfo->realParameter[2];
  comp->fmuData->modelData->realParameterData[3].attribute.start = comp->fmuData->simulationInfo->realParameter[3];
  comp->fmuData->modelData->realParameterData[4].attribute.start = comp->fmuData->simulationInfo->realParameter[4];
  comp->fmuData->modelData->realParameterData[5].attribute.start = comp->fmuData->simulationInfo->realParameter[5];
  comp->fmuData->modelData->booleanParameterData[0].attribute.start = comp->fmuData->simulationInfo->booleanParameter[0];
  comp->fmuData->modelData->booleanParameterData[1].attribute.start = comp->fmuData->simulationInfo->booleanParameter[1];
  comp->fmuData->modelData->booleanParameterData[2].attribute.start = comp->fmuData->simulationInfo->booleanParameter[2];
  comp->fmuData->modelData->booleanParameterData[3].attribute.start = comp->fmuData->simulationInfo->booleanParameter[3];
  comp->fmuData->modelData->booleanParameterData[4].attribute.start = comp->fmuData->simulationInfo->booleanParameter[4];
  comp->fmuData->modelData->stringParameterData[0].attribute.start = comp->fmuData->simulationInfo->stringParameter[0];
  comp->fmuData->modelData->stringParameterData[1].attribute.start = comp->fmuData->simulationInfo->stringParameter[1];
  comp->fmuData->modelData->stringParameterData[2].attribute.start = comp->fmuData->simulationInfo->stringParameter[2];
  comp->fmuData->modelData->stringParameterData[3].attribute.start = comp->fmuData->simulationInfo->stringParameter[3];
  comp->fmuData->modelData->stringParameterData[4].attribute.start = comp->fmuData->simulationInfo->stringParameter[4];
  comp->fmuData->modelData->stringParameterData[5].attribute.start = comp->fmuData->simulationInfo->stringParameter[5];
}

// Used to set the next time event, if any.
void eventUpdate(ModelInstance* comp, fmi2EventInfo* eventInfo) {
}

static const int realAliasIndexes[21] = {
  8, 8, -9, 12, 8, 7, -9, 12, 12, 12, -9, 8, -9, 7, 8, 0, 8, -9, 0, 8,
  12
};

fmi2Real getReal(ModelInstance* comp, const fmi2ValueReference vr) {
  if (vr < 13) {
    return comp->fmuData->localData[0]->realVars[vr];
  }
  if (vr < 19) {
    return comp->fmuData->simulationInfo->realParameter[vr-13];
  }
  if (vr < 40) {
    int ix = realAliasIndexes[vr-19];
    return ix>=0 ? getReal(comp, ix) : -getReal(comp, -(ix+1));
  }
  return NAN;
}

fmi2Status setReal(ModelInstance* comp, const fmi2ValueReference vr, const fmi2Real value) {
  if (vr < 13) {
    comp->fmuData->localData[0]->realVars[vr] = value;
    return fmi2OK;
  }
  if (vr < 19) {
    comp->fmuData->simulationInfo->realParameter[vr-13] = value;
    return fmi2OK;
  }
  if (vr < 40) {
    int ix = realAliasIndexes[vr-19];
    return ix >= 0 ? setReal(comp, ix, value) : setReal(comp, -(ix+1), -value);
  }
  return fmi2Error;
}

fmi2Integer getInteger(ModelInstance* comp, const fmi2ValueReference vr) {
  if (vr < 0) {
    return comp->fmuData->localData[0]->integerVars[vr];
  }
  if (vr < 0) {
    return comp->fmuData->simulationInfo->integerParameter[vr-0];
  }
  return 0;
}

fmi2Status setInteger(ModelInstance* comp, const fmi2ValueReference vr, const fmi2Integer value) {
  if (vr < 0) {
    comp->fmuData->localData[0]->integerVars[vr] = value;
    return fmi2OK;
  }
  if (vr < 0) {
    comp->fmuData->simulationInfo->integerParameter[vr-0] = value;
    return fmi2OK;
  }
  return fmi2Error;
}
fmi2Boolean getBoolean(ModelInstance* comp, const fmi2ValueReference vr) {
  switch (vr) {
    case 0 : return comp->fmuData->simulationInfo->booleanParameter[0]; break;
    case 1 : return comp->fmuData->simulationInfo->booleanParameter[1]; break;
    case 2 : return comp->fmuData->simulationInfo->booleanParameter[2]; break;
    case 3 : return comp->fmuData->simulationInfo->booleanParameter[3]; break;
    case 4 : return comp->fmuData->simulationInfo->booleanParameter[4]; break;
    default:
      return fmi2False;
  }
}

fmi2Status setBoolean(ModelInstance* comp, const fmi2ValueReference vr, const fmi2Boolean value) {
  switch (vr) {
    case 0 : comp->fmuData->simulationInfo->booleanParameter[0] = value; break;
    case 1 : comp->fmuData->simulationInfo->booleanParameter[1] = value; break;
    case 2 : comp->fmuData->simulationInfo->booleanParameter[2] = value; break;
    case 3 : comp->fmuData->simulationInfo->booleanParameter[3] = value; break;
    case 4 : comp->fmuData->simulationInfo->booleanParameter[4] = value; break;
    default:
      return fmi2Error;
  }
  return fmi2OK;
}

fmi2String getString(ModelInstance* comp, const fmi2ValueReference vr) {
  switch (vr) {
    case 0 : return MMC_STRINGDATA(comp->fmuData->simulationInfo->stringParameter[0]); break;
    case 1 : return MMC_STRINGDATA(comp->fmuData->simulationInfo->stringParameter[1]); break;
    case 2 : return MMC_STRINGDATA(comp->fmuData->simulationInfo->stringParameter[2]); break;
    case 3 : return MMC_STRINGDATA(comp->fmuData->simulationInfo->stringParameter[3]); break;
    case 4 : return MMC_STRINGDATA(comp->fmuData->simulationInfo->stringParameter[4]); break;
    case 5 : return MMC_STRINGDATA(comp->fmuData->simulationInfo->stringParameter[5]); break;
    default:
      return "";
  }
}

fmi2Status setString(ModelInstance* comp, const fmi2ValueReference vr, fmi2String value) {
  switch (vr) {
    case 0 : comp->fmuData->simulationInfo->stringParameter[0] = mmc_mk_scon(value); break;
    case 1 : comp->fmuData->simulationInfo->stringParameter[1] = mmc_mk_scon(value); break;
    case 2 : comp->fmuData->simulationInfo->stringParameter[2] = mmc_mk_scon(value); break;
    case 3 : comp->fmuData->simulationInfo->stringParameter[3] = mmc_mk_scon(value); break;
    case 4 : comp->fmuData->simulationInfo->stringParameter[4] = mmc_mk_scon(value); break;
    case 5 : comp->fmuData->simulationInfo->stringParameter[5] = mmc_mk_scon(value); break;
    default:
      return fmi2Error;
  }
  return fmi2OK;
}

fmi2Status setExternalFunction(ModelInstance* c, const fmi2ValueReference vr, const void* value){
  switch (vr) {
    default:
      return fmi2Error;
  }
  return fmi2OK;
}

/* function maps input references to a input index used in partialDerivatives */
fmi2ValueReference mapInputReference2InputNumber(const fmi2ValueReference vr) {
    switch (vr) {
      case 12: return 0; break;
      default:
        return -1;
    }
}
/* function maps output references to a input index used in partialDerivatives */
fmi2ValueReference mapOutputReference2OutputNumber(const fmi2ValueReference vr) {
    switch (vr) {
      case 8: return 0; break;
      default:
        return -1;
    }
}

#ifdef __cplusplus
}
#endif


#if defined(__cplusplus)
  extern "C" {
#endif
  int FmiTest_Model_mayer(DATA* data, modelica_real** res, short*);
  int FmiTest_Model_lagrange(DATA* data, modelica_real** res, short *, short *);
  int FmiTest_Model_pickUpBoundsForInputsInOptimization(DATA* data, modelica_real* min, modelica_real* max, modelica_real*nominal, modelica_boolean *useNominal, char ** name, modelica_real * start, modelica_real * startTimeOpt);
  int FmiTest_Model_setInputData(DATA *data, const modelica_boolean file);
  int FmiTest_Model_getTimeGrid(DATA *data, modelica_integer * nsi, modelica_real**t);
#if defined(__cplusplus)
}
#endif
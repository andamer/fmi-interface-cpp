/* Linearization */
#include "FmiTest_Model_model.h"
#if defined(__cplusplus)
extern "C" {
#endif
const char *FmiTest_Model_linear_model_frame()
{
  return "model linear_FmiTest_Model\n  parameter Integer n = 1 \"number of states\";\n  parameter Integer m = 1 \"number of inputs\";\n  parameter Integer p = 1 \"number of outputs\";\n"
  "\n"
  "  parameter Real x0[n] = %s;\n"
  "  parameter Real u0[m] = %s;\n"
  "\n"
  "  parameter Real A[n, n] =\n\t[%s];\n\n"
  "  parameter Real B[n, m] =\n\t[%s];\n\n"
  "  parameter Real C[p, n] =\n\t[%s];\n\n"
  "  parameter Real D[p, m] =\n\t[%s];\n\n"
  "\n"
  "  Real x[n](start=x0);\n"
  "  input Real u[m](start=u0);\n"
  "  output Real y[p];\n"
  "\n"
  "  Real 'x_c.v' = x[1];\n"
  "  Real 'u_v' = u[1];\n"
  "  Real 'y_i' = y[1];\n"
  "equation\n  der(x) = A * x + B * u;\n  y = C * x + D * u;\nend linear_FmiTest_Model;\n";
}
const char *FmiTest_Model_linear_model_datarecovery_frame()
{
  return "model linear_FmiTest_Model\n  parameter Integer n = 1 \"number of states\";\n  parameter Integer m = 1 \"number of inputs\";\n  parameter Integer p = 1 \"number of outputs\";\n  parameter Integer nz = 11 \"data recovery variables\";\n"
  "\n"
  "  parameter Real x0[1] = %s;\n"
  "  parameter Real u0[1] = %s;\n"
  "  parameter Real z0[11] = %s;\n"
  "\n"
  "  parameter Real A[n, n] =\n\t[%s];\n\n"
  "  parameter Real B[n, m] =\n\t[%s];\n\n"
  "  parameter Real C[p, n] =\n\t[%s];\n\n"
  "  parameter Real D[p, m] =\n\t[%s];\n\n"
  "  parameter Real Cz[nz, n] =\n\t[%s];\n\n"
  "  parameter Real Dz[nz, m] =\n\t[%s];\n\n"
  "\n"
  "  Real x[n](start=x0);\n"
  "  input Real u[m](start=u0);\n"
  "  output Real y[p];\n"
  "  output Real z[nz];\n"
  "\n"
  "  Real 'x_c.v' = x[1];\n"
  "  Real 'u_v' = u[1];\n"
  "  Real 'y_i' = y[1];\n"
  "  Real 'z_adaptor.u1' = z[1];\n""  Real 'z_adaptor.u2' = z[2];\n""  Real 'z_adaptor.y1' = z[3];\n""  Real 'z_adaptor.y2' = z[4];\n""  Real 'z_gnd.p.i' = z[5];\n""  Real 'z_gnd.p.v' = z[6];\n""  Real 'z_i' = z[7];\n""  Real 'z_r.LossPower' = z[8];\n""  Real 'z_r.R_actual' = z[9];\n""  Real 'z_r.v' = z[10];\n""  Real 'z_v' = z[11];\n"
  "equation\n  der(x) = A * x + B * u;\n  y = C * x + D * u;\n  z = Cz * x + Dz * u;\nend linear_FmiTest_Model;\n";
}
#if defined(__cplusplus)
}
#endif


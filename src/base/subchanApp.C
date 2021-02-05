#include "subchanApp.h"
#include "Moose.h"
#include "AppFactory.h"
#include "ModulesApp.h"
#include "MooseSyntax.h"

InputParameters
subchanApp::validParams()
{
  InputParameters params = MooseApp::validParams();

  // Do not use legacy DirichletBC, that is, set DirichletBC default for preset = true
  params.set<bool>("use_legacy_dirichlet_bc") = false;

  return params;
}

subchanApp::subchanApp(InputParameters parameters) : MooseApp(parameters)
{
  subchanApp::registerAll(_factory, _action_factory, _syntax);
}

subchanApp::~subchanApp() {}

void
subchanApp::registerAll(Factory & f, ActionFactory & af, Syntax & s)
{
  ModulesApp::registerAll(f, af, s);
  Registry::registerObjectsTo(f, {"subchanApp"});
  Registry::registerActionsTo(af, {"subchanApp"});

  /* register custom execute flags, action syntax, etc. here */
}

void
subchanApp::registerApps()
{
  registerApp(subchanApp);
}

/***************************************************************************************************
 *********************** Dynamic Library Entry Points - DO NOT MODIFY ******************************
 **************************************************************************************************/
extern "C" void
subchanApp__registerAll(Factory & f, ActionFactory & af, Syntax & s)
{
  subchanApp::registerAll(f, af, s);
}
extern "C" void
subchanApp__registerApps()
{
  subchanApp::registerApps();
}

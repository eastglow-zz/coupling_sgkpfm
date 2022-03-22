#include "coupling_sgkpfmApp.h"
#include "Moose.h"
#include "AppFactory.h"
#include "ModulesApp.h"
#include "MooseSyntax.h"

InputParameters
coupling_sgkpfmApp::validParams()
{
  InputParameters params = MooseApp::validParams();

  // Do not use legacy material output, i.e., output properties on INITIAL as well as TIMESTEP_END
  params.set<bool>("use_legacy_material_output") = false;

  return params;
}

coupling_sgkpfmApp::coupling_sgkpfmApp(InputParameters parameters) : MooseApp(parameters)
{
  coupling_sgkpfmApp::registerAll(_factory, _action_factory, _syntax);
}

coupling_sgkpfmApp::~coupling_sgkpfmApp() {}

void
coupling_sgkpfmApp::registerAll(Factory & f, ActionFactory & af, Syntax & syntax)
{
  ModulesApp::registerAll(f, af, syntax);
  Registry::registerObjectsTo(f, {"coupling_sgkpfmApp"});
  Registry::registerActionsTo(af, {"coupling_sgkpfmApp"});

  /* register custom execute flags, action syntax, etc. here */
}

void
coupling_sgkpfmApp::registerApps()
{
  registerApp(coupling_sgkpfmApp);
}

/***************************************************************************************************
 *********************** Dynamic Library Entry Points - DO NOT MODIFY ******************************
 **************************************************************************************************/
extern "C" void
coupling_sgkpfmApp__registerAll(Factory & f, ActionFactory & af, Syntax & s)
{
  coupling_sgkpfmApp::registerAll(f, af, s);
}
extern "C" void
coupling_sgkpfmApp__registerApps()
{
  coupling_sgkpfmApp::registerApps();
}

//* This file is part of the MOOSE framework
//* https://www.mooseframework.org
//*
//* All rights reserved, see COPYRIGHT for full restrictions
//* https://github.com/idaholab/moose/blob/master/COPYRIGHT
//*
//* Licensed under LGPL 2.1, please see LICENSE for details
//* https://www.gnu.org/licenses/lgpl-2.1.html
#include "coupling_sgkpfmTestApp.h"
#include "coupling_sgkpfmApp.h"
#include "Moose.h"
#include "AppFactory.h"
#include "MooseSyntax.h"
#include "ModulesApp.h"

InputParameters
coupling_sgkpfmTestApp::validParams()
{
  InputParameters params = coupling_sgkpfmApp::validParams();
  return params;
}

coupling_sgkpfmTestApp::coupling_sgkpfmTestApp(InputParameters parameters) : MooseApp(parameters)
{
  coupling_sgkpfmTestApp::registerAll(
      _factory, _action_factory, _syntax, getParam<bool>("allow_test_objects"));
}

coupling_sgkpfmTestApp::~coupling_sgkpfmTestApp() {}

void
coupling_sgkpfmTestApp::registerAll(Factory & f, ActionFactory & af, Syntax & s, bool use_test_objs)
{
  coupling_sgkpfmApp::registerAll(f, af, s);
  if (use_test_objs)
  {
    Registry::registerObjectsTo(f, {"coupling_sgkpfmTestApp"});
    Registry::registerActionsTo(af, {"coupling_sgkpfmTestApp"});
  }
}

void
coupling_sgkpfmTestApp::registerApps()
{
  registerApp(coupling_sgkpfmApp);
  registerApp(coupling_sgkpfmTestApp);
}

/***************************************************************************************************
 *********************** Dynamic Library Entry Points - DO NOT MODIFY ******************************
 **************************************************************************************************/
// External entry point for dynamic application loading
extern "C" void
coupling_sgkpfmTestApp__registerAll(Factory & f, ActionFactory & af, Syntax & s)
{
  coupling_sgkpfmTestApp::registerAll(f, af, s);
}
extern "C" void
coupling_sgkpfmTestApp__registerApps()
{
  coupling_sgkpfmTestApp::registerApps();
}

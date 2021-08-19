#include "MyProject1App.h"
#include "Moose.h"
#include "AppFactory.h"
#include "ModulesApp.h"
#include "MooseSyntax.h"

InputParameters
MyProject1App::validParams()
{
  InputParameters params = MooseApp::validParams();

  // Do not use legacy DirichletBC, that is, set DirichletBC default for preset = true
  params.set<bool>("use_legacy_dirichlet_bc") = false;

  return params;
}

MyProject1App::MyProject1App(InputParameters parameters) : MooseApp(parameters)
{
  MyProject1App::registerAll(_factory, _action_factory, _syntax);
}

MyProject1App::~MyProject1App() {}

void
MyProject1App::registerAll(Factory & f, ActionFactory & af, Syntax & s)
{
  ModulesApp::registerAll(f, af, s);
  Registry::registerObjectsTo(f, {"MyProject1App"});
  Registry::registerActionsTo(af, {"MyProject1App"});

  /* register custom execute flags, action syntax, etc. here */
}

void
MyProject1App::registerApps()
{
  registerApp(MyProject1App);
}

/***************************************************************************************************
 *********************** Dynamic Library Entry Points - DO NOT MODIFY ******************************
 **************************************************************************************************/
extern "C" void
MyProject1App__registerAll(Factory & f, ActionFactory & af, Syntax & s)
{
  MyProject1App::registerAll(f, af, s);
}
extern "C" void
MyProject1App__registerApps()
{
  MyProject1App::registerApps();
}

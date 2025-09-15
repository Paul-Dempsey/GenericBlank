#include "plugin.hpp"

Plugin * pluginInstance{nullptr};

// The "init" function must be present.
// Called by Rack when it loads the plugin.
void init(Plugin * p)
{
	pluginInstance = p;

	// Register all models here so that Rack knows what to
	// load and display in the module browser.
	p->addModel(modelBlank);

	// Other plugin initialization may go here. But a better strategy is to
	// do other initialization on-demand in the module constructor.
}

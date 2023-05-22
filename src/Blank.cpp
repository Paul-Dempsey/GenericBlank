#include "plugin.hpp"

struct BlankModule : Module
{

};

struct BlankModuleWidget : ModuleWidget
{
    BlankModuleWidget(BlankModule *module)
    {
        setModule(module);
		setPanel(createPanel(asset::plugin(pluginInstance, "res/Blank.svg")));

        // add standard rack screws
		addChild(createWidget<ScrewSilver>(Vec(RACK_GRID_WIDTH, 0)));
		addChild(createWidget<ScrewSilver>(Vec(box.size.x - 2 * RACK_GRID_WIDTH, 0)));
		addChild(createWidget<ScrewSilver>(Vec(RACK_GRID_WIDTH, RACK_GRID_HEIGHT - RACK_GRID_WIDTH)));
		addChild(createWidget<ScrewSilver>(Vec(box.size.x - 2 * RACK_GRID_WIDTH, RACK_GRID_HEIGHT - RACK_GRID_WIDTH)));
    }

};

Model *modelBlank = createModel<BlankModule, BlankModuleWidget>("blank");

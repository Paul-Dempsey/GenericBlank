#include "plugin.hpp"

struct BlankModule : Module
{
    // A module with inputs, outputs, parameters (knobs and switches),
    // and/or lights will define enums to identify each one:
    //
    //enum Params {
    //    // your params
    //    NUM_PARAMS // last one counts how many
    //};
    //enum Inputs {
    //    // your inputs
    //    NUM_INPUTS
    //};
    //enum Outputs {
    //    // your outputs
    //    NUM_OUTPUTS
    //};
    //enum Lights {
    //    // your lights
    //    NUM_LIGHTS
    //};

    // To make this module more than a blanking plate, configure inputs and outputs
    // in the Module constructor
    //
    //BlankModule()
    //{
    //    config(Params::NUM_PARAMS, Inputs::NUM_INPUTS, Outputs::NUM_OUTPUTS, Lights::NUM_LIGHTS);
    //
    // Configure each param, input, output, and light:
    //    configParam(Params::some_param, minValue, maxValue, defaultValue, "name", "unit");
    //    configInput(Inputs::some_input, "input name");
    //    configOutput(Outputs::some_output, "output name");
    //    configLight(Lights::some_light, "light_name");
    //
    //}

    // Save and restore configuration and settings by overriding dataToJson/dataFromJson

    //json_t* dataToJson() override
    //{
    //    auto root = json_object(); //create container
    //    // json_object_set_new(root, "flag", json_boolean(some_bool));
    //    // json_object_set_new(root, "number", json_real(some_float);
    //    return root;
    //}

    //void dataFromJson(json_t* root) override
    //{
    //    auto j = json_object_get(root, "flag");
    //    if (j) {
    //        some_bool = json_is_true(j);
    //    }
    //    j = json_object_get(root, "number");
    //    if (j) {
    //        some_float = json_number_value(j);
    //    }
    //}

    // To save precious CPU, many modules will process parameter changes at
    // a slower rate than the audio rate.
    //
    // This example shows a simple parameter update rate of 1/64th the sample rate.
    // You can use a ::rack::dsp::timer to update relative to clock time, rather
    // than change based on sample rate.
    //
    //const int PARAM_INTERVAL = 64;
    //void processParams()
    //{
    //    // process parameters here
    //}

    // To process inputs and outputs, override process()
    //
    //void process(const ProcessArgs& args) override
    //{
    //    // Process params every PARAM_INTERVAL samples
    //    if (0 == ((args.frame + getId()) % PARAM_INTERVAL)) {
    //        processParams();
    //    }

    //    // Read inputs

    //    // Produce output
    //}

};

struct BlankModuleWidget : ModuleWidget
{
    BlankModuleWidget(BlankModule *module)
    {
        setModule(module);
        setPanel(createPanel(asset::plugin(pluginInstance, "res/Blank.svg"), asset::plugin(pluginInstance, "res/Blank-dark.svg")));

        // Standard VCV Rack screws
        addChild(createWidget<ThemedScrew>(Vec(RACK_GRID_WIDTH, 0)));
        addChild(createWidget<ThemedScrew>(Vec(box.size.x - 2 * RACK_GRID_WIDTH, 0)));
        addChild(createWidget<ThemedScrew>(Vec(RACK_GRID_WIDTH, RACK_GRID_HEIGHT - RACK_GRID_WIDTH)));
        addChild(createWidget<ThemedScrew>(Vec(box.size.x - 2 * RACK_GRID_WIDTH, RACK_GRID_HEIGHT - RACK_GRID_WIDTH)));
    }

    // Add options to your module's menu here
    //void appendContextMenu(Menu *menu) override
    //{
    //}
};

// The required model for each module is referenced by plugin.h and plugin.cpp
// The pattern for each module is:
//     Model *modelSomething = createModel<SomethingModule, SomethingModuleWidget>("slug-something");
Model *modelBlank = createModel<BlankModule, BlankModuleWidget>("blank");

#include <SFML-Book/Configuration.hpp>

namespace book
{
    sfutils::ResourceManager<sf::Texture,int> Configuration::textures;
    sfutils::ResourceManager<sfutils::Animation,int> Configuration::animations;
    sfutils::ActionMap<int> Configuration::gui_inputs;

    void Configuration::initialize()
    {
        initTextures();
        initAnimations();
        initInputs();
    }

    void Configuration::initTextures()
    {
        textures.load(TexMain,"media/skins/main.png");
        textures.load(TexEye,"media/skins/eye.png");
    }


    void Configuration::initAnimations()
    {
        animations.load(AnimMain,&textures.get(TexMain)).addFramesLine(5,1,0);
        animations.load(AnimEyeLeft,&textures.get(TexEye)).addFramesLine(4,2,0);
        animations.load(AnimEyeRight,&textures.get(TexEye)).addFramesLine(4,2,1);
    }

    void Configuration::initInputs()
    {
        gui_inputs.map(GuiInputs::Escape,sfutils::Action(sf::Keyboard::Escape,sfutils::Action::Type::Pressed));
    }
}

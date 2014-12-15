#include <SFML-Book/gui/VLayout.hpp>

#include <SFML-Book/gui/Widget.hpp>

namespace book
{
    namespace gui
    {
        VLayout::VLayout(Widget* parent) : Layout(parent)
        {
        }

        VLayout::~VLayout()
        {
            for(Widget* widget : _widgets)
            {
                if(widget->_parent == this)
                    delete widget;
            }
        }
        
        void VLayout::add(Widget* widget)
        {
            widget->_parent = this;
            _widgets.emplace_back(widget);
            updateShape();
        }

        Widget* VLayout::at(unsigned int index)const
        {
            return _widgets.at(index);
        }

        sf::Vector2f VLayout::getSize()const
        {
            float max_x = 0;
            float y = 0;
            for(Widget* widget : _widgets)
            {
                sf::Vector2f size = widget->getSize();
                if(size.x > max_x)
                    max_x = size.x;
                y+= 5 + size.y;
            }
            return sf::Vector2f(max_x,y+5);
        }

        bool VLayout::processEvent(const sf::Event& event,const sf::Vector2f& parent_pos)
        {
            bool res = false;
            for(Widget* widget : _widgets)
            {
                if(widget->processEvent(event,parent_pos))
                {
                    res = true;
                    break;
                }
            }

            return res;
        }

        void VLayout::processEvents(const sf::Vector2f& parent_pos)
        {
            for(Widget* widget : _widgets)
                widget->processEvents(parent_pos);
        }

        void VLayout::updateShape()
        {
            float max_x = (_parent?_parent->getSize().x:0);
            for(Widget* widget : _widgets)
            {
                sf::Vector2f size = widget->getSize();
                float widget_x = size.x;

                if(widget_x > max_x)
                    max_x = widget_x;
            }



            float pos_y = 5;
            if(_parent)
                pos_y = (_parent->getSize().y - getSize().y)/2.f;

            for(Widget* widget : _widgets)
            {
                sf::Vector2f size = widget->getSize();
                widget->setPosition((max_x-size.x)/2.0,pos_y);
                pos_y += size.y + 5;
            }

        }

        void VLayout::draw(sf::RenderTarget& target, sf::RenderStates states) const
        {
            for(Widget* widget : _widgets)
                target.draw(*widget,states);
        }

    }
}
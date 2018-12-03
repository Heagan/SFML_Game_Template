#ifndef OBSERVER_HPP
#define OBSERVER_HPP

class Observer
{
    public:
        virtual ~Observer()
        {};

        virtual void Notify(const Message & l_message) = 0;
};

#endif